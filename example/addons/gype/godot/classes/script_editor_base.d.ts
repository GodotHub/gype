
import type { Control } from '@godot/classes/control';
import type { EditorSyntaxHighlighter } from '@godot/classes/editor_syntax_highlighter';
import type { GodotObject } from '@godot/classes/godot_object';
import type { VBoxContainer } from '@godot/classes/v_box_container';


export declare class ScriptEditorBase extends VBoxContainer {


    public get_base_editor(): Control;
    public add_syntax_highlighter(highlighter: EditorSyntaxHighlighter): void;

    
    public readonly name_changed: Signal<() => void>;
    public readonly edited_script_changed: Signal<() => void>;
    public readonly request_help: Signal<(topic: GDString | StringName | string) => void>;
    public readonly request_open_script_at_line: Signal<(script: GodotObject, line: number) => void>;
    public readonly request_save_history: Signal<() => void>;
    public readonly request_save_previous_state: Signal<(state: Dictionary) => void>;
    public readonly go_to_help: Signal<(what: GDString | StringName | string) => void>;
    public readonly search_in_files_requested: Signal<(text: GDString | StringName | string) => void>;
    public readonly replace_in_files_requested: Signal<(text: GDString | StringName | string) => void>;
    public readonly go_to_method: Signal<(script: GodotObject, method: GDString | StringName | string) => void>;

}

