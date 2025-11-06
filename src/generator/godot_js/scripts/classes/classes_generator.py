# scripts/generate_class_bindings.py
from pathlib import Path

from utils.file_utils import templates_dir as TEMPLATES_ROOT, generated_dir as GENERATED_ROOT
from utils.generation_utils import (
    load_api_data,
    setup_jinja_env,
    generate_files_from_template,
    generate_main_registration_file,
    sort_classes_by_inheritance,
    generate_vararg_helpers
)
from utils.jinja_helper import has_vararg_method, collect_class_dependencies

def main():
    """为 Godot 引擎类生成 C++ 绑定。"""
    print("Starting C++ binding generation for Godot ENGINE classes...")

    # --- 1. 定义此工作流的特定路径和配置 ---
    template_dir = TEMPLATES_ROOT / 'classes'
    output_src_dir = GENERATED_ROOT / 'src' / 'register' / 'classes'
    output_include_dir = GENERATED_ROOT / 'include' / 'register' / 'classes'

    # --- 2. 加载数据并处理 ---
    api_data = load_api_data()
    all_builtin_classes = api_data.get('builtin_classes', [])
    all_classes = api_data.get('classes', [])
    singletons = api_data.get('singletons', [])
    singleton_types = {s['type'] for s in singletons}
    all_class_names = {c['name'] for c in all_classes}

    # 使用导入的函数进行排序
    sorted_classes = sort_classes_by_inheritance(all_classes)
    singleton_classes = [c for c in sorted_classes if c['name'] in singleton_types]
    print(f"Found {len(all_classes)} engine classes. Sorted for registration.")

    # --- 3. 设置 Jinja 环境 ---
    env = setup_jinja_env(template_dir)

    # --- 4. 调用通用生成函数 ---
    # a. 为每个引擎类生成注册文件
    for cls in sorted_classes:
        is_singleton = cls['name'] in singleton_types
        # 使用导入的函数收集依赖
        dependencies = collect_class_dependencies(cls, all_classes)
        
        generate_files_from_template(
            items=[cls], # 每次只处理一个类
            template_path='classes.cpp.jinja',
            output_dir=output_src_dir,
            file_name_format='register_{item_name_snake}.cpp',
            jinja_env=env,
            # 传递上下文
            is_singleton=is_singleton,
            dependency=dependencies,
            singletons=singletons,
            classes=sorted_classes,
            builtin_classes=all_builtin_classes,
            has_vararg_methods=has_vararg_method(cls)
        )

    for cls in singleton_classes:
        dependencies = collect_class_dependencies(cls, all_classes)
        generate_files_from_template(
            items=[cls],
            template_path='singletons.cpp.jinja', # 使用您指定的、不可修改的模板
            output_dir=output_src_dir,
            file_name_format='register_{item_name_snake}.cpp', # 文件名与普通类一致，不会冲突因为类集合是互斥的
            jinja_env=env,
            dependency=dependencies,
            singletons=singletons
        )
    
    # b. & c. 生成主注册文件 (这部分保持不变)
    generate_main_registration_file(
        items=sorted_classes,
        template_path='classes.hpp.jinja',
        output_path=output_include_dir / 'register_classes.hpp',
        jinja_env=env
    )
    generate_main_registration_file(
        items=sorted_classes,
        template_path='register_classes.cpp.jinja',
        output_path=output_src_dir / 'register_classes.cpp',
        jinja_env=env
    )

    generate_vararg_helpers(
        items=sorted_classes,
        template_path='vararg_method.hpp.jinja',
        output_dir=output_include_dir,
        file_name_format='class_{item_name_snake}_vararg.hpp',
        jinja_env=env,
        is_for_classes=True,
        all_classes=all_classes,
        all_builtin_classes=all_builtin_classes,
        all_class_names=all_class_names
    )

    print("\nSuccessfully generated all ENGINE binding files.")

if __name__ == "__main__":
    main()
