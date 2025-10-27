import os
import json
from pathlib import Path

def _read_gde_json():
    root = Path(workspace_dir)
    return json.loads(root.joinpath('../../../', 'godot-cpp','gdextension','extension_api.json').read_text(encoding='utf8'))

workspace_dir = os.getenv('VSCODE_WORKSPACE', os.getcwd())
generated_root_dir = Path(workspace_dir).parent.parent.parent
gde_json_path = Path(workspace_dir).joinpath('../../../', 'godot-cpp','gdextension','extension_api.json')
templates_dir = Path(workspace_dir).joinpath('templates')
gde_json = _read_gde_json()