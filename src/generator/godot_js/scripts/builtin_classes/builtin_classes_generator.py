from pathlib import Path

# 确保你的工具函数被正确导入
from utils.file_utils import generated_dir as GENERATED_ROOT, templates_dir as TEMPLATES_ROOT
from utils.generation_utils import (
    load_api_data,
    setup_jinja_env,
    generate_files_from_template,
    generate_main_registration_file,
    generate_vararg_helpers  # <-- 导入 vararg 生成器
)
# 导入我们需要的辅助函数，以便在 Python 脚本中使用
from utils.jinja_helper import is_pod_type, has_vararg_method, collect_builtin_dependencies, \
    get_property_proxy_accessor_expression, get_proxy_method_call_expression


def main():
    """为 Godot 内置类型生成 C++ 绑定。"""
    print("Starting C++ binding generation for Godot BUILT-IN classes...")

    # --- 1. 定义路径 ---
    template_dir = TEMPLATES_ROOT / 'builtin_classes'
    output_src_dir = GENERATED_ROOT / 'src' / 'register' / 'builtin_classes'
    output_include_dir = GENERATED_ROOT / 'include' / 'register' / 'builtin_classes'

    # --- 2. 加载和处理数据 ---
    api_data = load_api_data()
    all_builtin_classes = api_data.get('builtin_classes', [])
    classes_to_generate = [cls for cls in all_builtin_classes if not is_pod_type(cls['name'])]
    print(
        f"Found {len(all_builtin_classes)} built-in classes, will generate for {len(classes_to_generate)} non-POD classes.")

    # --- 3. 设置 Jinja 环境 ---
    env = setup_jinja_env(template_dir)

    # --- 4. 生成文件 ---

    # ========================================================================
    # 这是关键的修正部分
    # ========================================================================
    # a. 为每个非 POD 内置类单独生成注册文件
    print("\n--- Generating individual registration files ---")
    # (外部循环) 我们在 Python 中遍历每个类
    for cls in classes_to_generate:
        # (准备上下文) 为当前这个类计算它需要的所有数据
        all_methods = cls.get('methods', [])
        dependencies = collect_builtin_dependencies(cls, all_builtin_classes)

        # 创建 include 路径字符串
        include_paths = [f'#include <godot_cpp/variant/{dep}.hpp>' for dep in dependencies]
        include_path_str = "\n".join(include_paths)

        # (为单个类调用生成器) 每次只处理一个类，并传入它的专属上下文
        generate_files_from_template(
            items=[cls],  # <-- 关键：只传入一个元素的列表
            template_path='builtin_classes.cpp.jinja',  # 模板名应与你的文件系统匹配
            output_dir=output_src_dir,
            file_name_format='register_{item_name_snake}.cpp',
            jinja_env=env,
            # <-- 关键：通过 **extra_context 传入所有计算好的数据
            all_methods=all_methods,
            has_vararg_methods=has_vararg_method(cls),
            include_path=include_path_str,
            get_property_proxy_accessor_expression=get_property_proxy_accessor_expression,
            get_proxy_method_call_expression=get_proxy_method_call_expression
        )
    print("  - Generation complete.")
    # ========================================================================
    # 修正结束
    # ========================================================================

    # b. 生成主注册头文件 (这部分逻辑不变)
    generate_main_registration_file(
        items=classes_to_generate,
        template_path='builtin_classes.hpp.jinja',
        output_path=output_include_dir / 'register_builtin_classes.hpp',
        jinja_env=env
    )

    # c. 生成主注册源文件 (这部分逻辑不变)
    generate_main_registration_file(
        items=classes_to_generate,
        template_path='register_builtin_classes.cpp.jinja',
        output_path=output_src_dir / 'register_builtin_classes.cpp',
        jinja_env=env
    )

    # # d. 生成 Vararg 辅助文件 (现在可以正常工作了)
    generate_vararg_helpers(
        items=classes_to_generate,
        template_path='vararg_method.hpp.jinja',
        output_dir=output_include_dir,
        file_name_format='builtin_{item_name_snake}_vararg.hpp',
        jinja_env=env,
        all_builtin_classes=all_builtin_classes
    )

    print("\nSuccessfully generated all BUILT-IN binding files.")


if __name__ == "__main__":
    main()
