from scripts.utils.file_utils import gde_json, generated_root_dir
from jinja2 import Environment, FileSystemLoader
from pathlib import Path
from scripts.utils.jinja_utils import camel_to_snake, is_pod_type, get_enum_fullname, is_enum, is_variant, connect_args, set_return, set_type

def gen_classes_d_ts():
    env = Environment(loader=FileSystemLoader(searchpath='./templates/dts/classes'))
    cpp_template = env.get_template('classes.d.ts.jinja')
    gen_path = Path.joinpath(generated_root_dir,'example','addons','gype','godot','classes')
    config_env(env)
    for clazz in gde_json['classes']:
        if clazz['name'].find('Extension') != -1 or clazz['name'] == 'Object': 
            continue
        dependency = list(filter(lambda e: not is_variant(e), collect_dependency(clazz)))
        content = cpp_template.render({ 'class': clazz, 'singletons': gde_json['singletons'], 'dependency': dependency })
        if clazz['name'] == 'Object':
            class_name = 'GodotObject'
        else:
            class_name = clazz['name']
        with open(file=Path.joinpath(gen_path, f'{camel_to_snake(class_name)}.d.ts'), mode='w', encoding='utf8') as file:
            file.write(content)

def config_env(env: Environment):
    env.globals['connect_args'] = connect_args
    env.globals['set_return'] = set_return
    env.globals['set_type'] = set_type
    env.globals['camel_to_snake'] = camel_to_snake

def collect_dependency(clazz):
    dependency = set()
    for method in clazz.get('methods', []):
        if method.get('return_value',None) and not is_pod_type(method['return_value'].get('type', None)):
            dependency.add(method['return_value']['type'])
        if method.get('arguments', None):
            for arg in method['arguments']:
                dependency.add(arg['type'])
    dependency.add(clazz['name'])
    if clazz.get('inherits', None):
        dependency.add(clazz['inherits'])
    dependency = list(map(lambda e: e.split('::')[1] if e.startswith('typedarray::') else e, dependency))
    dependency = filter(lambda e: not is_enum(e) and not is_pod_type(e) and not is_variant(e) and e.count('*') == 0, dependency)
    return dependency