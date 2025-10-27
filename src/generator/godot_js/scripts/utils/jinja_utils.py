import re
from scripts.utils.file_utils import gde_json

def is_variant(type_name):
    return (
        type_name == "Variant"
        or type_name in map(lambda e: e['name'], gde_json['builtin_classes'])
        or type_name == "Nil"
        or type_name.startswith("typedarray::")
    )

def variant_types():
    vt = map(lambda e: e['name'], gde_json['builtin_classes'])
    pt = pod_types()
    ret = list(filter(lambda e: e not in pt, vt))
    ret.append('Variant')
    return ret

def pod_types():
    return [
        "Nil", "void", "bool", "real_t", "float", "double",
        "int", "int8_t", "uint8_t", "int16_t", "uint16_t",
        "int32_t", "int64_t", "uint32_t", "uint64_t",
    ]

def is_pod_type(t):
    return t in pod_types()

def operator_id_name(op):
    op_id_map = {
        "==": "equal", "!=": "not_equal", "<": "less", "<=": "less_equal",
        ">": "greater", ">=": "greater_equal", "+": "add", "-": "subtract",
        "*": "multiply", "/": "divide", "unary-": "negate", "unary+": "positive",
        "%": "module", "**": "power", "<<": "shift_left", ">>": "shift_right",
        "&": "bit_and", "|": "bit_or", "^": "bit_xor", "~": "bit_negate",
        "and": "and", "or": "or", "xor": "xor", "not": "not", "in": "in",
    }
    return op_id_map[op]

def type_index():
    # ... (内容与你提供的一致，为简洁省略)
    return { 'NIL': 0, 'BOOL': 1, 'INT': 2, 'FLOAT': 3, 'STRING': 4, 'VECTOR2': 5, 'VECTOR2I': 6, 'RECT2': 7, 'RECT2I': 8, 'VECTOR3': 9, 'VECTOR3I': 10, 'TRANSFORM2D': 11, 'VECTOR4': 12, 'VECTOR4I': 13, 'PLANE': 14, 'QUATERNION': 15, 'AABB': 16, 'BASIS': 17, 'TRANSFORM3D': 18, 'PROJECTION': 19, 'COLOR': 20, 'STRING_NAME': 21, 'NODE_PATH': 22, 'RID': 23, 'OBJECT': 24, 'CALLABLE': 25, 'SIGNAL': 26, 'DICTIONARY': 27, 'ARRAY': 28, 'PACKED_BYTE_ARRAY': 29, 'PACKED_INT32_ARRAY': 30, 'PACKED_INT64_ARRAY': 31, 'PACKED_FLOAT32_ARRAY': 32, 'PACKED_FLOAT64_ARRAY': 33, 'PACKED_STRING_ARRAY': 34, 'PACKED_VECTOR2_ARRAY': 35, 'PACKED_VECTOR3_ARRAY': 36, 'PACKED_COLOR_ARRAY': 37, 'PACKED_VECTOR4_ARRAY': 38, 'VARIANT': 39 }


def get_type_index(t):
    return type_index()[t]

def add_prefix_suffix(values, prefix='', suffix=''):
    _values = list(values)
    for i in range(0, len(_values)):
        _values[i] = (f"{prefix}{_values[i]}{suffix}")
    return _values

def add_opaque(args):
    v_types = variant_types()
    tmp = []
    if args:
        for i in range(len(args)):
            if args[i]['type'] in v_types:
                tmp.append('%s.opaque' % args[i]['name'])
            else:
                tmp.append(args[i]['name'])
    return tmp

def camel_to_snake(name):
    name = re.sub("(.)([A-Z][a-z]+)", r"\1_\2", name)
    name = re.sub("([a-z0-9])([A-Z])", r"\1_\2", name)
    return name.replace("2_D", "2d").replace("3_D", "3d").lower()

def is_enum(type_name):
    return type_name.startswith("enum::") or type_name.startswith("bitfield::")

def is_bitfield(type_name):
    return type_name.startswith("bitfield::")

def get_enum_class(enum_name: str):
    if "." in enum_name:
        if is_bitfield(enum_name):
            return enum_name.replace("bitfield::", "").split(".")[0]
        else:
            return enum_name.replace("enum::", "").split(".")[0]
    else:
        return "GlobalConstants"

def get_enum_fullname(enum_name: str):
    if is_bitfield(enum_name):
        return enum_name.replace("bitfield::", "BitField<") + ">"
    else:
        return enum_name.replace("enum::", "")

def get_enum_name(enum_name: str):
    if is_bitfield(enum_name):
        return enum_name.replace("bitfield::", "").split(".")[-1]
    else:
        return enum_name.replace("enum::", "").split(".")[-1]

def connect_mutable_args(arguments):
    arg_str = []
    if arguments is not None or len(arguments) > 0:
        for arg in arguments:
            if is_pod_type(arg['type']):
                arg_str.append(f"{arg['type']} p_{arg['name']}")
            elif arg['type'] == 'Object':
                arg_str.append(f"Object * p_{arg['name']}")
            else:
                arg_str.append(f"const {arg['type']}& p_{arg['name']}")
    arg_str.append('std::vector<Variant> p_args')
    return ','.join(arg_str)

def has_vararg_method(clazz):
    for method in clazz.get('methods', []):
        if method['is_vararg']:
            return True
    return False

# ---给内置类使用 (IMPLEMENTED FUNCTIONS)
# =================================================================

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

def variant_type_cond(arguments):
    """
    【已实现】
    为构造函数重载生成C++的类型检查条件字符串。
    这用于在多个构造函数中根据传入的JS参数类型选择正确的C++构造函数。
    
    例如，对于 (Vector3, Vector3) 构造函数，它会生成:
    "&&VariantAdapter(argv[0]).get_type() == Variant::Type::VECTOR3&&VariantAdapter(argv[1]).get_type() == Variant::Type::VECTOR3"
    
    特别处理：当期望类型为 float 时，也允许传入 int。
    
    :param arguments: 来自 extension_api.json 的参数列表。
    :return: C++ 'if' 条件检查字符串，如果无参数则返回空字符串。
    """
    if not arguments:
        return ''

    conditions = []
    for i, arg in enumerate(arguments):
        # 将 JSON 中的类型名 (如 "Vector3i") 转换为 Variant.Type 枚举名 (如 "VECTOR3I")
        vtype = camel_to_snake(arg['type']).upper()
        
        # 特殊处理：如果C++需要float，我们可以接受JS的number（可能是int或float）
        if vtype == 'FLOAT':
            condition = f'(VariantAdapter(argv[{i}]).get_type() == Variant::Type::FLOAT || VariantAdapter(argv[{i}]).get_type() == Variant::Type::INT)'
        else:
            condition = f'VariantAdapter(argv[{i}]).get_type() == Variant::Type::{vtype}'
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
    """
    根据方法属性生成完整的 C++ 方法调用包装表达式。
    这将处理 static, const, vararg, 和 return value 的所有组合。
    """
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
        else: # 无返回值
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
            return (f'call_builtin{const_suffix}_method_no_ret(&{class_name}::{method_name}, ctx, this_val, argc, argv);\n'
                    '    return JS_UNDEFINED;')

def get_property_accessor_expression(member, access_type):
    """为属性生成 getter 或 setter 的 C++ 表达式。"""
    member_name = member['name']
    
    if access_type == 'get':
        getter = member.get('getter_name')
        if getter:
            return f'return VariantAdapter(val.{getter}());'
        else:
            return f'return VariantAdapter(val.{member_name});'
    
    elif access_type == 'set':
        setter = member.get('setter_name')
        member_type = member['type']
        if setter:
            return f'val.{setter}(VariantAdapter(*argv).get<{member_type}>());'
        else:
            return f'val.{member_name} = VariantAdapter(*argv).get<{member_type}>();'
    
    return "// Invalid access type"
def get_method_dependencies(methods: list, current_class_name: str) -> list:
    """
    从方法列表中提取所有非 POD、非当前类的类型依赖。
    用于在生成的头文件中 #include 必要的类定义。
    """
    dependencies = set()
    # 基础类型和当前类不需要作为依赖项被包含
    basic_types = {'void', 'bool', 'int', 'float', 'enum', 'bitfield', current_class_name}
    
    for method in methods:
        # 检查返回类型
        if method.get('return_type'):
            clean_type = method['return_type'].replace('*', '').replace('&', '').strip()
            if clean_type and clean_type not in basic_types and not clean_type.startswith(('enum', 'bitfield')):
                 dependencies.add(camel_to_snake(clean_type))
        
        # 检查参数类型
        for arg in method.get('arguments', []):
            if arg.get('type'):
                clean_type = arg['type'].replace('*', '').replace('&', '').strip()
                if clean_type and clean_type not in basic_types and not clean_type.startswith(('enum', 'bitfield')):
                    dependencies.add(camel_to_snake(clean_type))
                    
    # 对于内置类，依赖项都在 <godot_cpp/variant/...> 中，所以这个逻辑是正确的。
    return sorted(list(dependencies))


def connect_mutable_args(args: list) -> str:
    """
    将参数列表格式化为 C++ 函数签名，并为 vararg 函数追加一个 vector<Variant> 参数。
    """
    arg_strings = []
    if args:
        for arg in args:
            # Godot 的复杂类型通常用 const& 传递以提高效率
            arg_type = arg['type']
            if arg_type not in ('int', 'float', 'bool'):
                arg_strings.append(f"const {arg_type}& p_{arg['name']}")
            else:
                arg_strings.append(f"{arg_type} p_{arg['name']}")
    
    # 为可变参数部分追加 vector
    arg_strings.append("const std::vector<Variant>& p_args")
    
    return ", ".join(arg_strings)