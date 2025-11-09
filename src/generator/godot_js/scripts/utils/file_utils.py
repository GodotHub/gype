import json
import os
from pathlib import Path

workspace_dir = os.getenv('VSCODE_WORKSPACE', os.getcwd())
generated_dir = Path(workspace_dir).parent.parent.parent.parent
gde_json_path = Path(workspace_dir).joinpath('../../../../', 'godot-cpp', 'gdextension', 'extension_api.json')
templates_dir = Path(workspace_dir) / '../' / 'templates'
