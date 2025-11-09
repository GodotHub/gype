# scripts/generate_ts_declarations.py
import functools
import re
from pathlib import Path

# 假设这些工具函数按原样存在
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

    leading_underscores = ""
    while snake_str.startswith('_'):
        leading_underscores += '_'
        snake_str = snake_str[1:]

    if not snake_str:
        return leading_underscores

    components = snake_str.split('_')
    camel_case_str = components[0] + ''.join(x.title() for x in components[1:])

    return leading_underscores + camel_case_str


def ts_get_import_path(dep_name: str, builtin_class_names) -> str:
    if dep_name in builtin_class_names:
        # [小改进] 确保内置类型的文件名也使用 snake_case
        return f"@godot/builtins/{camel_to_snake(dep_name)}"
    else:
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
    'break', 'case', 'catch', 'class', 'const', 'continue', 'debugger',
    'default', 'delete', 'do', 'else', 'enum', 'export', 'extends', 'false',
    'finally', 'for', 'function', 'if', 'import', 'in', 'instanceof', 'new',
    'null', 'return', 'super', 'switch', 'this', 'throw', 'true', 'try',
    'typeof', 'var', 'void', 'while', 'with', 'implements', 'interface', 'let',
    'package', 'private', 'protected', 'public', 'static', 'yield', 'any',
    'boolean', 'constructor', 'declare', 'get', 'module', 'require', 'number',
    'set', 'string', 'symbol', 'type', 'from', 'of',
}

BUILTIN_TYPES_TO_SKIP = {'Nil', 'bool', 'int', 'float'}

OPERATOR_NAME_MAP = {
    '+': 'add', '-': 'subtract', '*': 'multiply', '/': 'divide', '%': 'module',
    '**': 'power', '==': 'equals', '!=': 'not_equals', '<': 'less', '<=': 'less_equal',
    '>': 'greater', '>=': 'greater_equal', 'unary+': 'positive', 'unary-': 'negate',
    '~': 'bitwise_not', '&': 'bitwise_and', '|': 'bitwise_or', '^': 'bitwise_xor',
    '<<': 'shift_left', '>>': 'shift_right', 'in': 'in_op',
}


def ts_get_property_type(prop: dict, cls: dict) -> str:
    """
    智能地确定类属性的正确 TypeScript 类型。
    它优先从 setter 方法的参数中获取类型，如果找不到，则回退到属性的 'type' 字段，
    并对该字段进行清理。
    """
    setter_name = prop.get('setter')
    if not setter_name:
        setter_name = f"set_{prop['name']}"

    for method in cls.get('methods', []):
        if method['name'] == setter_name:
            args = method.get('arguments', [])
            if len(args) == 1:
                return args[0]['type']

    # --- [BUG FIX 1: 核心修复] ---
    # 回退逻辑：如果找不到 setter，使用属性自身的类型，但必须进行清理。
    prop_type_str = prop.get('type', 'any')

    # 如果类型是逗号分隔的列表（例如 "Texture2D,-AnimatedTexture,..."），
    # 只取第一个类型，它通常是基类。
    if ',' in prop_type_str:
        prop_type_str = prop_type_str.split(',')[0]

    return prop_type_str


def ts_get_operator_name(op_symbol: str) -> str:
    return OPERATOR_NAME_MAP.get(op_symbol, f"op_{op_symbol.replace('=', '_eq')}")


def ts_set_type(type_name: str) -> str:
    """将 GDExtension 类型转换为 TypeScript 类型。"""
    if not type_name: return 'any'
    if '*' in type_name or '&' in type_name: return 'any'
    if type_name in ('float', 'int', 'int32_t', 'int64_t', 'double'): return 'number'
    if type_name == 'bool': return 'boolean'
    if type_name == 'void': return 'void'
    if type_name == 'Nil' or type_name == 'Variant': return 'any'
    if type_name in ('Object', 'String', 'Array'): return ts_get_class_name(type_name)
    if type_name.startswith('typedarray:'):
        inner_type = ts_set_type(type_name.split(':')[1])
        return f'Array<{inner_type}>'
    if type_name.startswith(('enum::', 'bitfield::')): return 'number'
    return type_name


def ts_connect_args(args: list) -> str:
    """生成 TypeScript 函数的参数列表字符串。"""
    if not args: return ''

    arg_strings = []
    for arg in args:
        original_name = arg.get('name', 'arg').replace('p_', '')

        # --- [BUG FIX 2: 修复参数命名风格] ---
        # 将参数名转换为 camelCase，以符合 TS/JS 编码规范
        arg_name = snake_to_camel(original_name)
        # arg_name = original_name # <-- 注释或删除此行

        if arg_name in TS_RESERVED_WORDS:
            arg_name = f'_{arg_name}'

        arg_type = ts_set_type(arg.get('type', 'any'))

        if arg_type == "GDString" or arg_type == "StringName":
            arg_type = "GDString | StringName | string"
        elif arg_type == 'NodePath':
            arg_type = "NodePath | GDString | string"

        default_value = arg.get("default_value", None)

        if default_value:
            if default_value[0] == "&":
                default_value = default_value.removeprefix("&")
            arg_strings.append(f"{arg_name}: {arg_type} = {default_value}")
        else:
            arg_strings.append(f"{arg_name}: {arg_type}")

    return ', '.join(arg_strings)


def ts_process_vararg(is_vararg: bool, args: list) -> str:
    prefix = ', ' if args else ''
    return f"{prefix}...args: any[]" if is_vararg else ""


def ts_set_return(return_info: any) -> str:
    return_type_str = None
    if isinstance(return_info, dict):
        return_type_str = return_info.get('type')
    elif isinstance(return_info, str):
        return_type_str = return_info
    if not return_type_str or return_type_str.lower() == 'void':
        return ': void'

    # [改进] 确保返回类型也处理逗号分隔的情况
    if ',' in return_type_str:
        return_type_str = return_type_str.split(',')[0]

    return f": {ts_set_type(return_type_str)}"


def collect_ts_dependencies(cls: dict, all_classes: list, all_builtin_classes: list) -> list:
    deps = set()
    all_class_names = {ts_get_class_name(c['name']) for c in all_classes}
    all_builtin_names = {ts_get_class_name(c['name']) for c in all_builtin_classes}

    def add_dep(type_name: str):
        if not type_name: return
        if type_name.startswith('typedarray:'): type_name = type_name.split(':')[1]

        # [改进] 在添加依赖前，清理逗号分隔的类型
        if ',' in type_name: type_name = type_name.split(',')[0]

        clean_name = type_name.replace('*', '').replace('&', '').replace('const ', '').strip().split('::')[-1]

        if clean_name == 'StringName': deps.add('GDString')

        final_name = ts_get_class_name(clean_name)
        current_class_name = ts_get_class_name(cls['name'])

        if (final_name == current_class_name or
                final_name in ('Variant', 'Nil', 'void', 'bool', 'int', 'float', 'number', 'any', 'boolean')):
            return

        if final_name in all_class_names or final_name in all_builtin_names:
            deps.add(final_name)

    if cls.get('inherits'): add_dep(cls['inherits'])
    for ctr in cls.get('constructors', []):
        for arg in ctr.get('arguments', []): add_dep(arg['type'])
    for member in cls.get('members', []): add_dep(member['type'])
    for prop in cls.get('properties', []): add_dep(prop['type'])
    for method in cls.get('methods', []):
        if 'return_value' in method:
            add_dep(method['return_value']['type'])
        elif 'return_type' in method:
            add_dep(method['return_type'])
        for arg in method.get('arguments', []): add_dep(arg['type'])
    for op in cls.get('operators', []):
        add_dep(op['return_type'])
        if op.get('right_type'): add_dep(op['right_type'])
    for signal in cls.get('signals', []):
        deps.add('Signal')
        for arg in signal.get('arguments', []): add_dep(arg['type'])

    # --- [BUG FIX 3: 移除错误的依赖过滤] ---
    # 下面这行代码错误地过滤掉了所有内置类型的依赖（如 Vector3, Color），导致 import 语句缺失。
    # deps = filter(lambda dep: dep not in all_builtin_names, deps) # <-- 必须删除或注释掉此行

    return sorted(list(deps))


def main():
    print("Starting TypeScript declaration file generation...")

    ts_template_dir = TEMPLATES_ROOT / 'dts'
    output_root_dir = GENERATED_ROOT / 'example' / 'addons' / 'gype' / 'godot'
    output_classes_dir = output_root_dir / 'classes'
    output_builtins_dir = output_root_dir / 'builtins'

    api_data = load_api_data()
    all_classes = api_data.get('classes', [])
    utility_functions = api_data.get('utility_functions', [])
    singletons = api_data.get('singletons', [])

    ts_engine_classes = []
    for cls in all_classes:
        cls_copy = cls.copy()
        cls_copy['name'] = ts_get_class_name(cls['name'])
        # 继承关系也需要重命名
        if 'inherits' in cls_copy:
            cls_copy['inherits'] = ts_get_class_name(cls_copy['inherits'])
        ts_engine_classes.append(cls_copy)

    sorted_ts_engine_classes = sort_classes_by_inheritance(ts_engine_classes)

    all_builtin_classes_raw = api_data.get('builtin_classes', [])
    all_builtin_classes = [
        b_cls for b_cls in all_builtin_classes_raw
        if b_cls['name'] not in BUILTIN_TYPES_TO_SKIP
    ]

    ts_builtin_classes = []
    for b_cls in all_builtin_classes:
        b_cls_copy = b_cls.copy()
        b_cls_copy['name'] = ts_get_class_name(b_cls['name'])
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

    print("\nGenerating .d.ts for engine classes...")
    for cls in sorted_ts_engine_classes:
        # 注意：这里传递原始的、未重命名的类列表给依赖收集器，因为它内部会处理重命名
        dependencies = collect_ts_dependencies(cls, ts_engine_classes, ts_builtin_classes)
        generate_files_from_template(
            items=[cls],
            template_path='class.d.ts.jinja',
            output_dir=output_classes_dir,
            file_name_format=f'{camel_to_snake(cls["name"])}.d.ts',
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
            file_name_format=f'{camel_to_snake(b_cls["name"])}.d.ts',
            jinja_env=env,
            dependency=dependencies
        )

    print("\nGenerating globals.d.ts for UtilityFunctions...")
    generate_main_registration_file(
        items=utility_functions,
        template_path='utility.d.ts.jinja',
        output_path=output_root_dir / 'globals.d.ts',
        jinja_env=env,
        context_key='utility_functions',  # 确保上下文键正确
        utility_functions=utility_functions  # 传递两次以防万一
    )

    # --- [BUG FIX 4: 移除重复的调用] ---
    # 下面的代码块是多余的，并且错误地覆盖了 globals.d.ts。
    # print("\nGenerating main index.d.ts...")
    # generate_main_registration_file(...)

    print("\n✅ TypeScript declaration file generation complete!")
    print(f"Output located in: {output_root_dir.resolve()}")


if __name__ == "__main__":
    main()
