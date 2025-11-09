# scripts/utils/generation_utils.py
import json
from jinja2 import Environment, FileSystemLoader
from pathlib import Path
from typing import Callable, List, Dict, Any
from utils.file_utils import gde_json_path as API_JSON_PATH
from utils.jinja_helper import ALL_HELPERS, is_pod_type, camel_to_snake, collect_method_dependencies, \
    collect_builtin_dependencies


def sort_classes_by_inheritance(classes: List[Dict]) -> List[Dict]:
    """
    通过拓扑排序对类进行排序，确保基类在派生类之前。
    这对于C++的#include顺序和JS的类注册顺序至关重要。
    """
    class_map = {cls['name']: cls for cls in classes}

    # 构建图的邻接表 (父类 -> 子类列表) 和入度表 (子类 -> 父类数量)
    adj = {name: [] for name in class_map}
    in_degree = {name: 0 for name in class_map}

    for name, cls_data in class_map.items():
        parent = cls_data.get('inherits')
        if parent and parent in class_map:
            adj[parent].append(name)
            in_degree[name] += 1

    # 初始化队列，加入所有入度为0的节点（即没有父类或父类不在列表中的根节点）
    queue = [name for name, degree in in_degree.items() if degree == 0]

    sorted_list = []
    while queue:
        class_name = queue.pop(0)
        if class_name in class_map:
            sorted_list.append(class_map[class_name])

        # 遍历当前节点的所有邻接节点（子类）
        for child_name in adj.get(class_name, []):
            in_degree[child_name] -= 1
            # 如果子类的所有父依赖都已处理完毕，则将其加入队列
            if in_degree[child_name] == 0:
                queue.append(child_name)

    # 检查排序是否成功
    if len(sorted_list) != len(classes):
        # 找出循环依赖或缺失的基类
        missing = [name for name, degree in in_degree.items() if degree > 0]
        raise RuntimeError(
            f"Class sorting failed. Possible circular dependency or missing base class. Problematic classes: {missing}")

    return sorted_list


def load_api_data() -> Dict[str, Any]:
    """加载并返回 extension_api.json 的内容。"""
    if not API_JSON_PATH.exists():
        raise FileNotFoundError(f"API JSON file not found at {API_JSON_PATH}")
    with open(API_JSON_PATH, 'r', encoding='utf-8') as f:
        return json.load(f)


def setup_jinja_env(template_dir: Path, custom_globals: Dict = None) -> Environment:
    """创建一个配置好的 Jinja2 环境。"""
    env = Environment(
        loader=FileSystemLoader(searchpath=str(template_dir)),
        trim_blocks=True,
        lstrip_blocks=True,
    )
    # 注册所有共享的过滤器和全局函数
    env.globals.update(ALL_HELPERS)
    if custom_globals:
        env.globals.update(custom_globals)
    return env


def generate_files_from_template(
        items: List[Dict],
        template_path: str,
        output_dir: Path,
        file_name_format: str,
        jinja_env: Environment,
        **extra_context: Any
):
    """
    一个通用的函数，用于根据模板为一系列项目（如类）生成文件。

    :param items: 要迭代的项目列表 (例如, api_data['classes'])
    :param template_path: Jinja2 模板的文件名
    :param output_dir: 文件输出目录
    :param file_name_format: 文件名的格式化字符串 (例如, "register_{item_name_snake}.cpp")
    :param jinja_env: Jinja2 环境
    :param extra_context: 传递给模板的额外上下文
    """
    print(f"\n--- Generating files using template '{template_path}' ---")
    output_dir.mkdir(parents=True, exist_ok=True)
    template = jinja_env.get_template(template_path)

    for item in items:
        item_name = item['name']
        item_name_snake = ALL_HELPERS['camel_to_snake'](item_name)

        file_name = file_name_format.format(
            item_name=item_name,
            item_name_snake=item_name_snake
        )
        print(f"  - Generating: {file_name}")

        context = {
            'cls': item,
            **extra_context
        }

        output_content = template.render(context)
        output_path = output_dir / file_name
        output_path.write_text(output_content, encoding='utf-8', newline='\n')
    print("  - Generation complete.")


def generate_main_registration_file(
        items: List[Dict],
        template_path: str,
        output_path: Path,
        jinja_env: Environment,
        **extra_context: Any
):
    """生成一个主注册文件 (例如 register_classes.hpp 或 .cpp)。"""
    print(f"\n--- Generating main file: {output_path.name} ---")
    output_path.parent.mkdir(parents=True, exist_ok=True)
    template = jinja_env.get_template(template_path)

    context = {
        'classes': items,
        **extra_context
    }

    output_content = template.render(context)
    output_path.write_text(output_content, encoding='utf-8', newline='\n')
    print(f"  - Generated: {output_path}")


def generate_vararg_helpers(
        items: List[Dict],
        template_path: str,
        output_dir: Path,
        file_name_format: str,
        jinja_env: Environment,
        is_for_classes: bool = False,  # <-- 新增标志以区分逻辑
        **extra_context: Any
):
    """
    为包含 vararg 方法的类/内置类型生成辅助头文件。
    """
    print(f"\n--- Generating vararg helper files using template '{template_path}' ---")
    output_dir.mkdir(parents=True, exist_ok=True)
    template = jinja_env.get_template(template_path)

    has_vararg_method_checker = jinja_env.globals.get('has_vararg_method')
    if not has_vararg_method_checker:
        raise RuntimeError("'has_vararg_method' helper not found in Jinja environment.")

    generated_count = 0
    for item in items:
        if has_vararg_method_checker(item):
            item_name = item['name']
            item_name_snake = ALL_HELPERS['camel_to_snake'](item_name)

            file_name = file_name_format.format(
                item_name=item_name,
                item_name_snake=item_name_snake
            )
            print(f"  - Generating: {file_name} (for {item_name})")

            vararg_methods = [m for m in item.get('methods', []) if m.get('is_vararg')]

            # --- 上下文准备逻辑 ---
            context = {'cls': item, 'vararg_methods': vararg_methods, **extra_context}

            if is_for_classes:
                # 对于引擎类，使用新的、更强大的依赖收集器
                dep_collector = collect_method_dependencies
                all_classes = extra_context.get('all_classes', [])
                all_builtin_classes = extra_context.get('all_builtin_classes', [])
                class_deps, variant_deps = dep_collector(vararg_methods, all_classes, all_builtin_classes)
                context['class_deps'] = class_deps
                context['variant_deps'] = variant_deps
            else:
                # 对于内置类型，使用旧的依赖收集器
                dep_collector = collect_builtin_dependencies
                all_builtin_classes = extra_context.get('all_builtin_classes', [])
                context['dependencies'] = dep_collector(item, all_builtin_classes)
            # --- 上下文准备逻辑结束 ---

            output_content = template.render(context)
            output_path = output_dir / file_name
            output_path.write_text(output_content, encoding='utf-8', newline='\n')
            generated_count += 1

    if generated_count > 0:
        print(f"  - Generation complete. ({generated_count} files created)")
    else:
        print("  - No items with vararg methods found. Nothing to generate.")
