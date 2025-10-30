# scripts/generate_ts_declarations.py
import functools
import re
from pathlib import Path

# 复用你项目中的工具函数
from utils.file_utils import templates_dir as TEMPLATES_ROOT, generated_dir as GENERATED_ROOT
from utils.generation_utils import (
    load_api_data,
    setup_jinja_env,
    generate_files_from_template,
    generate_main_registration_file,
    sort_classes_by_inheritance,
    camel_to_snake
)

def snake_to_camel(snake_str: str) -> str:
    """
    将蛇形命名 (snake_case) 转换为驼峰命名 (camelCase)。
    例如：'get_ok_button' -> 'getOkButton'
           'ok_button_text' -> 'okButtonText'
           '_internal' -> '_internal'
    """
    if not snake_str:
        return ""
    
    # 处理可能存在的前导下划线
    leading_underscores = ""
    while snake_str.startswith('_'):
        leading_underscores += '_'
        snake_str = snake_str[1:]

    if not snake_str:
        return leading_underscores

    components = snake_str.split('_')
    # 将第一个部分保持小写，之后的所有部分首字母大写
    camel_case_str = components[0] + ''.join(x.title() for x in components[1:])
    
    return leading_underscores + camel_case_str

def ts_get_import_path(dep_name: str, builtin_class_names) -> str:
    if dep_name in builtin_class_names:
        return f"@godot/builtins/{camel_to_snake(dep_name)}"
    else:
        # 假设任何不是内置类的依赖都是引擎类
        return f"@godot/classes/{camel_to_snake(dep_name)}"

def ts_get_class_name(original_name: str) -> str:
    """获取一个类在 TypeScript 中最终的名称，处理重命名。"""
    if original_name == 'Object':
        return 'GodotObject'
    if original_name == 'String':
        return 'GDString'
    if original_name == 'Array':
        return 'GDArray'
    return original_name

TS_RESERVED_WORDS = {
    # Standard JS/TS Keywords
    'break', 'case', 'catch', 'class', 'const', 'continue', 'debugger',
    'default', 'delete', 'do', 'else', 'enum', 'export', 'extends', 'false',
    'finally', 'for', 'function', 'if', 'import', 'in', 'instanceof', 'new',
    'null', 'return', 'super', 'switch', 'this', 'throw', 'true', 'try',
    'typeof', 'var', 'void', 'while', 'with',
    # Strict mode / Future reserved words
    'implements', 'interface', 'let', 'package', 'private', 'protected',
    'public', 'static', 'yield',
    # Contextual keywords that are often problematic as identifiers
    'any', 'boolean', 'constructor', 'declare', 'get', 'module', 'require',
    'number', 'set', 'string', 'symbol', 'type', 'from', 'of',
}

BUILTIN_TYPES_TO_SKIP = {
    'Nil',    # 映射到 null
    'bool',   # 映射到 boolean
    'int',    # 映射到 number
    'float',  # 映射到 number
    'String', # 映射到 string
}

OPERATOR_NAME_MAP = {
    '+': 'add',
    '-': 'subtract',
    '*': 'multiply',
    '/': 'divide',
    '%': 'module',
    '**': 'power',
    '==': 'equals',
    '!=': 'not_equals',
    '<': 'less',
    '<=': 'less_equal',
    '>': 'greater',
    '>=': 'greater_equal',
    'unary+': 'positive',
    'unary-': 'negate',
    '~': 'bitwise_not',
    '&': 'bitwise_and',
    '|': 'bitwise_or',
    '^': 'bitwise_xor',
    '<<': 'shift_left',
    '>>': 'shift_right',
    'in': 'in_op',  # 'in' 是 JS/TS 关键字，需要重命名
}

def ts_get_property_type(prop: dict, cls: dict) -> str:
    """
    Intelligently determines the correct type for a class property.

    It prioritizes the type from the setter method's argument, as this is the
    most reliable source (e.g., 'Material' instead of 'BaseMaterial3D,ShaderMaterial').
    If no setter is found, it falls back to the property's 'type' field.
    """
    setter_name = prop.get('setter')
    # If the 'setter' field is not in the JSON, construct it from the property name
    if not setter_name:
        setter_name = f"set_{prop['name']}"

    for method in cls.get('methods', []):
        # Find the matching setter method
        if method['name'] == setter_name:
            # A valid setter should have exactly one argument
            args = method.get('arguments', [])
            if len(args) == 1:
                # This is our source of truth!
                return args[0]['type']

    # Fallback: If no setter was found, use the property's own type.
    # This is less reliable but necessary for read-only properties or other edge cases.
    return prop.get('type', 'any')

def ts_get_operator_name(op_symbol: str) -> str:
    # ... (这部分保持不变) ...
    return OPERATOR_NAME_MAP.get(op_symbol, f"op_{op_symbol.replace('=', '_eq')}")

def ts_set_type(type_name: str) -> str:
    """将 GDExtension 类型转换为 TypeScript 类型。"""
    if not type_name:
        return 'any'
    
    # [新增] 处理 C++ 指针和引用类型，直接映射为 any
    if '*' in type_name or '&' in type_name:
        return 'any'
    
    if type_name in ('float', 'int', 'int32_t', 'int64_t', 'float', 'double'):
        return 'number'
    if type_name == 'bool':
        return 'boolean'
    if type_name == 'void':
        return 'void'
    if type_name == 'Nil' or type_name == 'Variant':
        return 'any'
    
    # 使用新的辅助函数来保持一致性
    if type_name in ('Object', 'String', 'Array'):
        return ts_get_class_name(type_name)
    
    if type_name.startswith('typedarray:'):
        inner_type = ts_set_type(type_name.split(':')[1])
        return f'Array<{inner_type}>'

    if type_name.startswith(('enum::', 'bitfield::')):
        return 'number'

    return type_name

def ts_connect_args(args: list) -> str:
    """
    生成 TypeScript 函数的参数列表字符串。
    此函数现在会:
    1. 将参数名从 snake_case 转换为 camelCase。
    2. 处理与 TypeScript/JavaScript 关键字的冲突。
    """
    if not args:
        return ''

    arg_strings = []
    for arg in args:
        # 1. 移除 Godot 常用的 'p_' 前缀
        original_name = arg.get('name', 'arg').replace('p_', '')
        
        # 2. 将参数名转换为 camelCase
        # arg_name = snake_to_camel(original_name)
        arg_name = original_name

        # 3. 检查并处理关键字冲突
        if arg_name in TS_RESERVED_WORDS:
            arg_name = f'_{arg_name}'
            
        arg_type = ts_set_type(arg.get('type', 'any'))
        
        # 处理特殊的可联合类型，提高易用性
        if arg_type == "GDString" or arg_type == "StringName":
            arg_type = "GDString | StringName | string"
        elif arg_type == 'NodePath':
            arg_type = "NodePath | GDString | string"

        arg_strings.append(f"{arg_name}: {arg_type}")

    return ', '.join(arg_strings)

def ts_process_vararg(is_vararg: bool, args: list) -> str:
    # ... (这部分保持不变) ...
    prefix = ', ' if args else ''
    return f"{prefix}...args: any[]" if is_vararg else ""

def ts_set_return(return_info: any) -> str:
    # ... (这部分保持不变) ...
    return_type_str = None
    if isinstance(return_info, dict):
        return_type_str = return_info.get('type')
    elif isinstance(return_info, str):
        return_type_str = return_info
    if not return_type_str or return_type_str.lower() == 'void':
        return ': void'
    return f": {ts_set_type(return_type_str)}"

def collect_ts_dependencies(cls: dict, all_classes: list, all_builtin_classes: list) -> list:
    deps = set()
    # 使用 ts_get_class_name 来获取所有可能的依赖项的最终名称
    all_class_names = {ts_get_class_name(c['name']) for c in all_classes}
    all_builtin_names = {ts_get_class_name(c['name']) for c in all_builtin_classes}

    def add_dep(type_name: str):
        if not type_name:
            return
        
        if type_name.startswith('typedarray:'):
            type_name = type_name.split(':')[1]

        clean_name = type_name.replace('*', '').replace('&', '').replace('const ', '').strip().split('::')[-1]
        
        if clean_name == 'StringName':
            deps.add('GDString') # StringName 依然隐含依赖 GDString
        
        # 使用 ts_get_class_name 来规范化依赖名称
        final_name = ts_get_class_name(clean_name)

        current_class_name = ts_get_class_name(cls['name'])
        if (final_name == current_class_name or 
            final_name in ('Variant', 'Nil', 'void', 'bool', 'int', 'float', 'number', 'any', 'boolean')):
            return
        
        if final_name in all_class_names or final_name in all_builtin_names:
            deps.add(final_name)

    # ... (依赖收集的其余部分保持不变) ...
    if cls.get('inherits'): add_dep(cls['inherits'])
    for ctr in cls.get('constructors', []):
        for arg in ctr.get('arguments', []): add_dep(arg['type'])
    for member in cls.get('members', []): add_dep(member['type'])
    for prop in cls.get('properties', []): add_dep(prop['type'])
    for method in cls.get('methods', []):
        if 'return_value' in method: add_dep(method['return_value']['type'])
        elif 'return_type' in method: add_dep(method['return_type'])
        for arg in method.get('arguments', []): add_dep(arg['type'])
    for op in cls.get('operators', []):
        add_dep(op['return_type'])
        if op.get('right_type'): add_dep(op['right_type'])
    for signal in cls.get('signals', []):
        deps.add('Signal')
        for arg in signal.get('arguments', []): add_dep(arg['type'])

    return sorted(list(deps))


def main():
    """为 Godot API 生成 TypeScript 声明文件 (.d.ts)。"""
    print("Starting TypeScript declaration file generation...")

    ts_template_dir = TEMPLATES_ROOT / 'dts'
    output_root_dir = GENERATED_ROOT / 'example' / 'addons' / 'gype' / 'godot'
    output_classes_dir = output_root_dir / 'classes'
    output_builtins_dir = output_root_dir / 'builtins'

    api_data = load_api_data()
    all_classes = api_data.get('classes', [])
    all_builtin_classes = api_data.get('builtin_classes', [])
    utility_functions = api_data.get('utility_functions', [])
    singletons = api_data.get('singletons', [])
    
    # --- [修改 2] 预处理类列表，将名称更新为最终的 TS 名称 ---
    # 这样做可以简化后续所有步骤，包括文件名生成和模板渲染
    
    # 创建新的引擎类列表，其中 'Object' 被重命名为 'GodotObject'
    ts_engine_classes = []
    for cls in all_classes:
        cls_copy = cls.copy()
        cls_copy['name'] = ts_get_class_name(cls['name'])
        ts_engine_classes.append(cls_copy)
    
    sorted_ts_engine_classes = sort_classes_by_inheritance(ts_engine_classes)

    all_builtin_classes_raw = api_data.get('builtin_classes', [])
    all_builtin_classes = [
        b_cls for b_cls in all_builtin_classes_raw
        if b_cls['name'] not in BUILTIN_TYPES_TO_SKIP
    ]

    # 现在，对 *过滤后* 的列表进行重命名处理
    ts_builtin_classes = []
    for b_cls in all_builtin_classes:
        b_cls_copy = b_cls.copy()
        b_cls_copy['name'] = ts_get_class_name(b_cls['name']) # 例如 'Array' -> 'GDArray'
        ts_builtin_classes.append(b_cls_copy)


    ts_builtin_class_names = {b_cls['name'] for b_cls in ts_builtin_classes}
    bound_get_import_path = functools.partial(ts_get_import_path, builtin_class_names=ts_builtin_class_names)

    ts_helpers = {
        'set_type': ts_set_type,
        'connect_args': ts_connect_args,
        'process_vararg': ts_process_vararg,
        'set_return': ts_set_return,
        'get_operator_name': ts_get_operator_name,
        'get_import_path': bound_get_import_path,
        'get_class_name': ts_get_class_name,
        'snake_to_camel': snake_to_camel,
        'get_property_type': ts_get_property_type
    }

    env = setup_jinja_env(ts_template_dir, custom_globals=ts_helpers)
    # 不再需要全局的 camel_to_snake
    
    # --- [修改 3] 更新文件生成逻辑 ---

    print("\nGenerating .d.ts for engine classes...")
    for cls in sorted_ts_engine_classes:
        dependencies = collect_ts_dependencies(cls, ts_engine_classes, ts_builtin_classes)
        generate_files_from_template(
            items=[cls],
            template_path='class.d.ts.jinja',
            output_dir=output_classes_dir,
            file_name_format=f'{camel_to_snake(cls['name'])}.d.ts', # <-- 使用 CamelCase 文件名
            jinja_env=env,
            dependency=dependencies,
            singletons=singletons
        )
    
    print("\nGenerating .d.ts for built-in types...")
    for b_cls in ts_builtin_classes:
        dependencies = collect_ts_dependencies(b_cls, [], ts_builtin_classes)
        generate_files_from_template(
            items=[b_cls],
            template_path='builtin.d.ts.jinja',
            output_dir=output_builtins_dir,
            file_name_format=f'{camel_to_snake(b_cls['name'])}.d.ts',
            jinja_env=env,
            dependency=dependencies
        )

    print("\nGenerating globals.d.ts for UtilityFunctions...")
    generate_main_registration_file(
        items=utility_functions,
        template_path='utility.d.ts.jinja',
        output_path=output_root_dir / 'globals.d.ts',
        jinja_env=env,
        context_key='utility_functions'
    )
    
    print("\nGenerating main index.d.ts...")
    generate_main_registration_file(
        items=utility_functions,
        template_path='utility.d.ts.jinja',
        output_path=output_root_dir / 'globals.d.ts',
        jinja_env=env,
        utility_functions=utility_functions
    )

    print("\n✅ TypeScript declaration file generation complete!")
    print(f"Output located in: {output_root_dir.resolve()}")

if __name__ == "__main__":
    main()