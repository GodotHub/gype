# scripts/utils/jinja_helpers.py
import re


# --- 核心辅助函数 ---
def camel_to_snake(name: str) -> str:
    """将驼峰命名转换为蛇形命名。"""
    name = re.sub("(.)([A-Z][a-z]+)", r"\1_\2", name)
    name = re.sub("([a-z0-9])([A-Z])", r"\1_\2", name)
    return name.replace("2_D", "2d").replace("3_D", "3d").lower()


def is_pod_type(type_name: str) -> bool:
    """检查类型是否为 POD (Plain Old Data) 类型。"""
    pod_types = {
        "void", "bool", "real_t", "float", "double",
        "int", "int8_t", "uint8_t", "int16_t", "uint16_t",
        "int32_t", "int64_t", "uint32_t", "uint64_t", "Nil",
    }
    return type_name in pod_types


# --- 你提供的其他辅助函数可以放在这里 ---
# 例如 connect_mutable_args, get_method_call_expression 等
# 为了简洁，这里只放最核心的几个

def put_args(arguments):
    """
    【已实现】
    生成用于C++函数调用的参数列表字符串。
    例如，对于一个有两个参数的构造函数，此函数会生成 "v0, v1"。
    这些变量名 (v0, v1) 对应于在构造函数包装器中从JS参数 (argv) 解包出来的C++变量。
    
    :param arguments: 来自 extension_api.json 的参数列表。
    :return: 一个逗号分隔的参数名字符串，如 "v0, v1, v2"，如果无参数则返回空字符串。
    """
    if not arguments:
        return ''

    # 使用列表推导式为每个参数生成一个 'v' + 索引 的变量名
    arg_names = [f"v{i}" for i, _ in enumerate(arguments)]

    return ", ".join(arg_names)


def connect_mutable_args(arguments: list, all_class_names: set) -> str:
    arg_strings = []
    if arguments:
        for arg in arguments:
            arg_type = arg['type']
            if arg_type == 'float':
                arg_type = 'double'
            arg_name = f"p_{arg['name']}"

            if is_pod_type(arg_type):
                # 1. POD 类型: 按值传递
                arg_strings.append(f"{arg_type} {arg_name}")
            elif arg_type in all_class_names:
                # 2. 引擎类 (继承自 Object): 按指针传递
                arg_strings.append(f"{arg_type} *{arg_name}")
            else:
                # 3. 内置结构体 (Vector2, String, etc.): 按 const 引用传递
                arg_strings.append(f"const {arg_type}& {arg_name}")

    # 4. 为可变参数部分追加 vector
    arg_strings.append("const std::vector<Variant>& p_args")

    return ", ".join(arg_strings)


def has_vararg_method(clazz):
    for method in clazz.get('methods', []):
        if method['is_vararg']:
            return True
    return False


# ---给内置类使用 (IMPLEMENTED FUNCTIONS)
# =================================================================

def put_args(arguments):
    if not arguments:
        return ''

    # 使用列表推导式为每个参数生成一个 'v' + 索引 的变量名
    arg_names = [f"v{i}" for i, _ in enumerate(arguments)]

    return ", ".join(arg_names)


def variant_type_cond(arguments):
    if not arguments:
        return ''

    conditions = []
    for i, arg in enumerate(arguments):
        ltype = arg['type']
        if ltype == 'float':
            ltype = 'double'
        if arg['type'] != 'Variant':
            condition = f'(VariantAdapter::can_cast(argv[{i}],Variant::Type::{camel_to_snake(arg['type']).upper()}))'
        conditions.append(condition)

    # 将所有条件用 '&&' 连接，并在开头加上 '&&' 以简化模板中的if语句
    return '&&' + '&&'.join(conditions)


# =================================================================
# ---ts声明使用

def is_number(arg_type):
    return arg_type == 'float' or arg_type == 'int'


def is_bool(arg_type):
    return arg_type == 'bool'


def connect_args(args):
    def mapper(arg):
        arg_name = '_' + arg.get('name', '')
        arg_type = arg.get('type', '')
        default_value = arg.get('default_value', None)
        arg_type = set_type(arg_type)
        if arg_type == "String" or arg_type == "StringName":
            ret = arg_name + ": " + "GDString | StringName | string"
        elif arg_type == 'NodePath':
            ret = arg_name + ": " + "GDString | NodePath | string"
        else:
            ret = arg_name + ': ' + arg_type
        if default_value:
            if isinstance(default_value, str) and default_value[0] == '&':
                ret += ' = ' + default_value.removeprefix('&')
            else:
                ret += ' = ' + default_value
        return ret

    if args:
        return ', '.join(list(map(mapper, args)))
    return ''


def set_return(arg_type):
    if arg_type and arg_type.find(',') != -1:
        arg_type = arg_type.split(',')[0]
    if arg_type:
        return ': ' + set_type(arg_type)
    return ': void'


def set_type(type):
    if is_number(type):
        return 'number'
    elif is_bool(type):
        return 'boolean'
    elif is_enum(type):
        return 'number'
    elif type.find('typedarray:') != -1:
        return 'GDArray'
    elif type == 'Array':
        return 'GDArray'
    elif type == 'Variant':
        return 'any'
    elif type == 'Object':
        return 'GodotObject'
    else:
        return type


def get_const_suffix(method):
    """如果方法是 const，则返回 '_const' 后缀，否则返回空字符串。"""
    return '_const' if method.get('is_const') else ''


def get_arg_count(method):
    """安全地获取方法的参数数量。"""
    args = method.get('arguments')
    return len(args) if args else 0


def get_method_call_expression(method, class_name):
    method_name = method['name']
    has_return = method.get('return_type') or method.get('return_value')

    # 1. 处理 VarArg 方法
    if method.get('is_vararg'):
        has_fixed_args = get_arg_count(method) > 0
        if has_return:
            if has_fixed_args:
                # 有固定参数，有返回值
                return f'return call_builtin_free_opaque_vararg_method_ret<{class_name}>(&js_{method_name}, ctx, this_val, argc, argv);'
            else:
                # 无固定参数，有返回值
                return f'return call_builtin_free_opaque_no_fixed_vararg_method_ret<{class_name}>(&js_{method_name}, ctx, this_val, argc, argv);'
        else:  # 无返回值
            if has_fixed_args:
                # 有固定参数，无返回值
                return f'return call_builtin_free_opaque_vararg_method_no_ret<{class_name}>(&js_{method_name}, ctx, this_val, argc, argv);'
            else:
                # 无固定参数，无返回值
                return f'return call_builtin_free_opaque_no_fixed_vararg_method_no_ret<{class_name}>(&js_{method_name}, ctx, this_val, argc, argv);'

    # 2. 处理静态方法
    elif method.get('is_static'):
        if has_return:
            return f'return call_builtin_static_method_ret(&{class_name}::{method_name}, ctx, this_val, argc, argv);'
        else:
            return (f'call_builtin_static_method_no_ret(&{class_name}::{method_name}, ctx, this_val, argc, argv);\n'
                    '    return JS_UNDEFINED;')

    # 3. 处理普通实例方法
    else:
        const_suffix = get_const_suffix(method)
        if has_return:
            return f'return call_builtin{const_suffix}_method_ret(&{class_name}::{method_name}, ctx, this_val, argc, argv);'
        else:
            return (
                f'call_builtin{const_suffix}_method_no_ret(&{class_name}::{method_name}, ctx, this_val, argc, argv);\n'
                '    return JS_UNDEFINED;')


def get_proxy_method_call_expression(method, class_name):
    method_name = method['name']
    has_return = method.get('return_type') or method.get('return_value')
    code = f'void *opaque = JS_GetOpaque(this_val, classes["{class_name}Proxy"]);\n'
    code += f'    ObjectProxy<{class_name}> *proxy = reinterpret_cast<ObjectProxy<{class_name}> *>(opaque);\n'
    code += f'    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);\n'
    code += f'    this_val = VariantAdapter(wrapped);\n'
    # 1. 处理 VarArg 方法
    if method.get('is_vararg'):
        has_fixed_args = get_arg_count(method) > 0
        if has_return:
            if has_fixed_args:
                # 有固定参数，有返回值
                code += f'JSValue ret = call_builtin_free_opaque_vararg_method_ret<{class_name}>(&js_{method_name}, ctx, this_val, argc, argv);\n'
                return code + f'JS_FreeValue(ctx, this_val);\n    return ret;'
            else:
                # 无固定参数，有返回值
                code += f'JSValue ret = call_builtin_free_opaque_no_fixed_vararg_method_ret<{class_name}>(&js_{method_name}, ctx, this_val, argc, argv);\n'
                return code + f'JS_FreeValue(ctx, this_val);\n    return ret;'
        else:  # 无返回值
            if has_fixed_args:
                # 有固定参数，无返回值
                code = f'call_builtin_free_opaque_vararg_method_no_ret<{class_name}>(&js_{method_name}, ctx, this_val, argc, argv);\n'
                return code + f'JS_FreeValue(ctx, this_val);\n    return JS_UNDEFINED;'
            else:
                # 无固定参数，无返回值
                code = f'call_builtin_free_opaque_no_fixed_vararg_method_no_ret<{class_name}>(&js_{method_name}, ctx, this_val, argc, argv);\n'
                return code + f'JS_FreeValue(ctx, this_val);\n    return JS_UNDEFINED;'

    # 2. 处理静态方法
    elif method.get('is_static'):
        if has_return:
            return f'return call_builtin_static_method_ret(&{class_name}::{method_name}, ctx, this_val, argc, argv);'
        else:
            return (f'call_builtin_static_method_no_ret(&{class_name}::{method_name}, ctx, this_val, argc, argv);\n'
                    '    return JS_UNDEFINED;')

    # 3. 处理普通实例方法
    else:
        const_suffix = get_const_suffix(method)
        if has_return:
            code += f'    JSValue ret = call_builtin{const_suffix}_method_ret(&{class_name}::{method_name}, ctx, this_val, argc, argv);\n'
            code += f'    JS_FreeValue(ctx, this_val);\n'
            code += f'    return ret;'
            return code
        else:
            return (
                f'call_builtin{const_suffix}_method_no_ret(&{class_name}::{method_name}, ctx, this_val, argc, argv);\n'
                '    return JS_UNDEFINED;')


def get_property_accessor_expression(member, access_type):
    """为属性生成 getter 或 setter 的 C++ 表达式。"""
    member_name = member['name']

    if access_type == 'get':
        getter = member.get('getter_name')
        member_type = member['type']
        if member_type == 'float':
            member_type = 'double'
        if getter:
            return f'return VariantAdapter(val.{getter}());'
        else:
            return f'return VariantAdapter(val.{member_name});'

    elif access_type == 'set':
        setter = member.get('setter_name')
        member_type = member['type']
        if member_type == 'float':
            member_type = 'double'
        if setter:
            return f'val.{setter}(VariantAdapter(*argv)).get();'
        else:
            return f'val.{member_name} = VariantAdapter(*argv).get();'

    return "// Invalid access type"


def get_property_proxy_accessor_expression(class_name, member, access_type):
    """为属性生成 getter 或 setter 的 C++ 表达式。"""
    member_name = member['name']
    code = f'void *opaque = JS_GetOpaque(this_val, classes["{class_name}Proxy"]);\n'
    code += f'    ObjectProxy<{class_name}> *proxy = reinterpret_cast<ObjectProxy<{class_name}> *>(opaque);\n'
    if access_type == 'get':
        getter = member.get('getter_name')
        member_type = member['type']
        if member_type == 'float':
            member_type = 'double'
        code += f'    {class_name} ret = proxy->getter();\n'
        if getter:
            code += f'    return VariantAdapter(ret.{getter}());'
            return code
        else:
            code += f'    return VariantAdapter(ret.{member_name});'
            return code
    elif access_type == 'set':
        member_type = member['type']
        if member_type == 'float':
            member_type = 'double'
        code += f'    VariantAdapter {member_name}(argv[0]);\n'
        code += f'    {class_name} wrapped = proxy->getter();\n'
        code += f'    wrapped.{member_name} = {member_name}.get();\n'
        code += f'    proxy->setter(wrapped);'
        return code
    return "// Invalid access type"


def collect_method_dependencies(methods: list, all_classes: list, all_builtin_classes: list) -> tuple:
    """
    从方法列表中收集引擎类和内置(Variant)类型的依赖项。
    返回一个包含两个已排序列表的元组: (class_dependencies, variant_dependencies)。
    """
    class_deps = set()
    variant_deps = set()

    all_class_names = {c['name'] for c in all_classes}
    all_builtin_names = {c['name'] for c in all_builtin_classes}

    def add_dependency(type_name: str):
        if not type_name: return
        # 清理类型名, 去除指针/引用, 处理 typedarray::
        clean_name = type_name.replace('*', '').replace('&', '').strip().split('::')[-1]

        if is_pod_type(clean_name) or clean_name.startswith(('enum', 'bitfield')):
            return

        if clean_name in all_class_names:
            class_deps.add(camel_to_snake(clean_name))
        elif clean_name in all_builtin_names:
            variant_deps.add(camel_to_snake(clean_name))

    for method in methods:
        if method.get('return_value'):
            add_dependency(method['return_value']['type'])
        for arg in method.get('arguments', []):
            add_dependency(arg['type'])

    return sorted(list(class_deps)), sorted(list(variant_deps))


def collect_builtin_dependencies(cls, all_builtin_classes):
    """
    为内置类收集所有非POD、非当前类的类型依赖，用于生成 #include。
    返回蛇形命名的依赖列表。
    """
    dependencies = set()
    all_builtin_names = {c['name'] for c in all_builtin_classes}

    def add_if_valid_dependency(type_name: str):
        if not type_name: return
        clean_name = type_name.replace('*', '').replace('&', '').strip()

        if (clean_name and
                clean_name != cls['name'] and
                clean_name in all_builtin_names and
                not is_pod_type(clean_name)):
            dependencies.add(clean_name)

    # 遍历方法
    for method in cls.get('methods', []):
        if method.get('return_type'):
            add_if_valid_dependency(method['return_type'])
        for arg in method.get('arguments', []):
            add_if_valid_dependency(arg['type'])

    # 遍历属性/成员
    for member in cls.get('members', []):
        add_if_valid_dependency(member['type'])

    return sorted([camel_to_snake(d) for d in dependencies])


def collect_class_dependencies(cls, all_classes):
    """
    为一个类收集所有非POD、非枚举的C++类型依赖，用于生成 #include。
    返回蛇形命名的依赖列表。
    """
    dependencies = set()
    all_class_names = {c['name'] for c in all_classes}

    def add_if_valid_dependency(type_name: str):
        """内部辅助函数，用于清理和验证类型名称。"""
        if not type_name:
            return

        # 处理指针和引用，以及 typedarray::String -> String
        clean_name = type_name.replace('*', '').replace('&', '').strip().split('::')[-1]

        # 检查是否是需要#include的有效类依赖
        if (clean_name and
                clean_name != cls['name'] and  # 不是自身
                clean_name in all_class_names and  # 必须是已知的引擎类
                not is_pod_type(clean_name) and  # 不是 POD
                not clean_name.startswith("enum") and  # 不是枚举
                not clean_name.startswith("bitfield")):  # 不是位域
            dependencies.add(clean_name)

    # 1. 添加基类
    if cls.get('inherits'):
        add_if_valid_dependency(cls['inherits'])

    # 2. 遍历方法
    for method in cls.get('methods', []):
        # 返回值
        if 'return_value' in method:
            add_if_valid_dependency(method['return_value'].get('type'))
        # 参数
        for arg in method.get('arguments', []):
            add_if_valid_dependency(arg.get('type'))

    # 3. 遍历属性
    for prop in cls.get('properties', []):
        add_if_valid_dependency(prop.get('type'))

    # 4. 遍历信号参数 (如果需要)
    for signal in cls.get('signals', []):
        for arg in signal.get('arguments', []):
            add_if_valid_dependency(arg.get('type'))

    # 转换为蛇形命名并排序，以获得确定的输出
    return sorted([camel_to_snake(d) for d in dependencies])


def set_type(type_name: str) -> str:
    """Maps Godot type names to TypeScript type names."""
    if not type_name:
        return "any"

    # 基本类型映射
    if type_name in ("void", "Nil"):
        return "void"
    if type_name in ("bool",):
        return "boolean"
    if type_name in ("int", "float", "real_t", "int64_t", "int32_t", "int16_t", "int8_t", "uint64_t", "uint32_t",
                     "uint16_t", "uint8_t"):
        return "number"

    # 字符串和路径
    if type_name in ("String", "StringName"):
        return "string"  # 在.d.ts中，简单类型更易用
    if type_name == "NodePath":
        return "string | NodePath"

    # 特殊容器
    if type_name.startswith("typedarray::"):
        inner_type = set_type(type_name.split("::")[1])
        return f"Array<{inner_type}>"  # 或者你自定义的 GDArray<T>
    if type_name == "Array":
        return "any[]"  # 或者 GDArray<any>

    # 枚举和位域
    if type_name.startswith("enum::") or type_name.startswith("bitfield::"):
        return "number"

    # Variant 和 Object
    if type_name == "Variant":
        return "any"
    if type_name == "Object":
        return "GodotObject"  # 确保在模板中导入 GodotObject

    return type_name


def connect_args(args: list) -> str:
    """Formats a list of arguments for a TypeScript function signature."""
    if not args:
        return ""

    arg_strings = []
    for arg in args:
        # 在JS/TS中，参数名不能以数字开头，但Godot API中有 '2d' 这样的名字
        arg_name = arg['name']
        if re.match(r'^\d', arg_name):
            arg_name = f'_{arg_name}'

        # 处理可选参数
        is_optional = 'default_value' in arg
        arg_str = f"{arg_name}{'?' if is_optional else ''}: {set_type(arg['type'])}"
        arg_strings.append(arg_str)

    return ", ".join(arg_strings)


def ts_set_return(return_info) -> str:
    """
    生成 TypeScript 函数的返回类型字符串。
    能同时处理引擎类 (传入 dict) 和内置类 (传入 str)。
    """
    return_type_str = None

    if isinstance(return_info, dict):
        # 对应引擎类: method['return_value'] = {'type': 'Node', ...}
        return_type_str = return_info.get('type')
    elif isinstance(return_info, str):
        # 对应内置类: method['return_type'] = 'float'
        return_type_str = return_info

    # 如果没有返回类型或返回类型是 void，则统一为 : void
    if not return_type_str or return_type_str.lower() == 'void':
        return ': void'

    # 使用 ts_set_type 转换类型
    return f": {set_type(return_type_str)}"


def process_vararg(is_vararg: bool, last_arg: dict) -> str:
    """Generates the ...args part for vararg functions in TypeScript."""
    if not is_vararg:
        return ""

    # 如果有固定参数，vararg部分需要加逗号
    prefix = ", " if last_arg else ""
    return f"{prefix}...args: any[]"


def collect_ts_dependencies(cls: dict, all_classes: list, all_builtin_classes: list) -> dict:
    """Collects all type dependencies for a class to generate import statements."""
    deps = {
        'classes': set(),
        'builtins': set(),
        'signals': False,
    }
    all_class_names = {c['name'] for c in all_classes}
    all_builtin_names = {c['name'] for c in all_builtin_classes}

    def add_dep(type_name: str):
        if not type_name: return
        clean_name = type_name.replace('*', '').replace('&', '').strip().split('::')[-1]

        if is_pod_type(clean_name) or clean_name in ("Variant", "void", "Nil"):
            return

        if clean_name == cls['name']:  # Don't import self
            return

        if clean_name in all_class_names:
            deps['classes'].add(clean_name)
        elif clean_name in all_builtin_names:
            deps['builtins'].add(clean_name)

    # Base class
    if cls.get('inherits'):
        add_dep(cls['inherits'])

    # Methods
    for method in cls.get('methods', []):
        if method.get('return_value'):
            add_dep(method['return_value']['type'])
        for arg in method.get('arguments', []):
            add_dep(arg['type'])

    # Properties
    for prop in cls.get('properties', []):
        add_dep(prop['type'])

    # Signals
    if cls.get('signals'):
        deps['signals'] = True

    # Convert to sorted lists for stable output
    return {
        'classes': sorted([{'name': name, 'snake_name': camel_to_snake(name)} for name in deps['classes']],
                          key=lambda x: x['name']),
        'builtins': sorted([{'name': name, 'snake_name': camel_to_snake(name)} for name in deps['builtins']],
                           key=lambda x: x['name']),
        'signals': deps['signals'],
    }


ALL_HELPERS = {
    'camel_to_snake': camel_to_snake,
    'is_pod_type': is_pod_type,
    'has_vararg_method': has_vararg_method,
    'connect_mutable_args': connect_mutable_args,
    'collect_builtin_dependencies': collect_builtin_dependencies,
    'collect_class_dependencies': collect_class_dependencies,
    'put_args': put_args,
    'variant_type_cond': variant_type_cond,
    'get_property_accessor_expression': get_property_accessor_expression,
    'get_method_call_expression': get_method_call_expression,
    'get_arg_count': get_arg_count,
    'connect_args': connect_args,
    'process_vararg': process_vararg,
    'set_return': set_return,
    'set_type': set_type
}
