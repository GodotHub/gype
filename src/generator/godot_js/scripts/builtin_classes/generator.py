import sys
from pathlib import Path
import json
from jinja2 import Environment, FileSystemLoader

# 假设这些路径是正确的
from scripts.utils.file_utils import gde_json_path, generated_root_dir, templates_dir
from scripts.utils.jinja_utils import (
    camel_to_snake,
    is_pod_type,
    get_method_dependencies,
    connect_mutable_args,
    variant_type_cond,
    put_args,
    get_method_call_expression,
    get_arg_count,
    get_property_accessor_expression
)

API_JSON_PATH = gde_json_path
TEMPLATES_ROOT = templates_dir
GENERATED_ROOT = generated_root_dir

def setup_jinja_env(template_dir: Path) -> Environment:
    """创建一个配置好的 Jinja2 环境，并注册所有需要的过滤器和全局函数。"""
    env = Environment(
        loader=FileSystemLoader(searchpath=str(template_dir)),
        trim_blocks=True,
        lstrip_blocks=True
    )
    # 注册所有过滤器和全局函数
    env.filters['camel_to_snake'] = camel_to_snake
    env.globals.update({
        'get_method_dependencies': get_method_dependencies,
        'connect_mutable_args': connect_mutable_args,
        'variant_type_cond': variant_type_cond,
        'put_args': put_args,
        'get_method_call_expression': get_method_call_expression,
        'get_arg_count': get_arg_count,
        'get_property_accessor_expression': get_property_accessor_expression,
    })
    return env

def generate_vararg_helper_files(classes_to_generate: list, env: Environment, output_dir: Path):
    """为包含 vararg 方法的类生成辅助头文件。"""
    print("\n--- Generating Vararg Helper Files ---")
    output_dir.mkdir(parents=True, exist_ok=True)
    # [修正] 模板名应与您的文件系统匹配，这里假设是 'builtin_vararg_method.h.jinja'
    template = env.get_template('vararg_method.hpp.jinja')

    for cls in classes_to_generate:
        vararg_methods = [m for m in cls.get('methods', []) if m.get('is_vararg')]
        if not vararg_methods:
            continue

        cls_name = cls['name']
        cls_name_lower = camel_to_snake(cls_name)
        print(f"  - Generating vararg helper for class: {cls_name}")

        dependencies = get_method_dependencies(vararg_methods, cls_name)
        
        output_content = template.render(
            cls=cls,
            vararg_methods=vararg_methods,
            dependencies=dependencies,
        )

        output_path = output_dir / f'builtin_{cls_name_lower}_vararg.hpp'
        with open(output_path, 'w', encoding='utf-8', newline='\n') as f:
            f.write(output_content)
    print("  - Vararg helper generation complete.")


def generate_individual_class_files(classes_to_generate: list, env: Environment, output_dir: Path):
    """为每个指定的内置类生成单独的 C++ 注册文件。"""
    print("\n--- Generating Individual Class Registration Files ---")
    output_dir.mkdir(parents=True, exist_ok=True)
    template = env.get_template('builtin_classes.cpp.jinja')

    for cls in classes_to_generate:
        cls_name = cls['name']
        cls_name_lower = camel_to_snake(cls_name)
        print(f"  - Generating registration file for class: {cls_name}")

        has_vararg_methods = any(m.get('is_vararg') for m in cls.get('methods', []))

        # 注意：这个 include 路径需要与 vararg 文件的最终位置匹配
        # 如果 vararg 文件在 'gen/builtin/vararg'，那么这个 include 路径是正确的
        include_path = (f'#include <godot_cpp/variant/{cls_name_lower}.hpp>')

        output = template.render(
            cls=cls,
            include_path=include_path,
            all_methods=cls.get('methods', []),
            has_vararg_methods=has_vararg_methods,
        )

        output_path = output_dir / f'register_{cls_name_lower}.cpp'
        with open(output_path, 'w', encoding='utf-8', newline='\n') as f:
            f.write(output)

def generate_main_registration_files(classes_to_generate: list, env: Environment, output_src_dir: Path, output_include_dir: Path):
    """生成主注册文件 register_builtin_classes.h 和 .cpp。"""
    print("\n--- Generating Main Registration Files ---")
    output_src_dir.mkdir(parents=True, exist_ok=True)
    output_include_dir.mkdir(parents=True, exist_ok=True)
    context = {'classes': classes_to_generate}

    h_template = env.get_template('builtin_classes.hpp.jinja')
    h_output = h_template.render(context)
    # [修正] 头文件路径直接在 output_include_dir 下
    h_path = output_include_dir/ 'builtin_classes' / 'register_builtin_classes.hpp'
    with open(h_path, 'w', encoding='utf-8', newline='\n') as f:
        f.write(h_output)
    print(f"  - Generated header: {h_path.relative_to(GENERATED_ROOT)}")

    cpp_template = env.get_template('register_builtin_classes.cpp.jinja')
    cpp_output = cpp_template.render(context)
    cpp_path = output_src_dir / 'register_builtin_classes.cpp'
    with open(cpp_path, 'w', encoding='utf-8', newline='\n') as f:
        f.write(cpp_output)
    print(f"  - Generated source: {cpp_path.relative_to(GENERATED_ROOT)}")

def main():
    """脚本的主入口点。"""
    print("Starting C++ code generation for Godot built-in classes...")
    
    template_dir = TEMPLATES_ROOT / 'builtin_classes'
    
    # 定义源文件和头文件的根目录
    output_src_root = GENERATED_ROOT / 'src' / 'register'
    output_include_root = GENERATED_ROOT / 'include' / 'register'
    
    # .cpp 文件将生成在 'generated/src/register/builtin_classes'
    output_src_dir = output_src_root / 'builtin_classes'
    
    # 主 .h 文件将生成在 'generated/include/register'
    output_include_dir = output_include_root
    
    # [修正] 为 vararg 辅助文件定义一个清晰、独立的输出目录
    # 文件将生成在 'generated/include/gen/builtin/vararg'
    vararg_output_dir = GENERATED_ROOT / 'include' / 'register' / 'builtin_classes'

    print(f"Loading API data from: {API_JSON_PATH}")
    if not API_JSON_PATH.exists():
        print(f"Error: API JSON file not found at {API_JSON_PATH}", file=sys.stderr)
        sys.exit(1)

    with open(API_JSON_PATH, 'r', encoding='utf-8') as f:
        api_data = json.load(f)

    all_builtin_classes = api_data.get('builtin_classes', [])
    classes_to_generate = [cls for cls in all_builtin_classes if not is_pod_type(cls['name'])]
    print(f"Found {len(all_builtin_classes)} built-in classes, will generate for {len(classes_to_generate)} non-POD classes.")

    # [修正] 确保您的 vararg 模板名为 'builtin_vararg_method.h.jinja'
    env = setup_jinja_env(template_dir)
    
    # 1. 生成 vararg 辅助文件到其专属目录
    generate_vararg_helper_files(classes_to_generate, env, vararg_output_dir)

    # 2. 生成所有独立的 register_{class}.cpp 文件
    generate_individual_class_files(classes_to_generate, env, output_src_dir)
    
    # 3. 生成主注册的 .h 和 .cpp 文件
    # [修正] 传递正确的 include 目录
    generate_main_registration_files(classes_to_generate, env, output_src_dir, output_include_dir)
    
    print("\nSuccessfully generated all files.")


if __name__ == '__main__':
    main()
