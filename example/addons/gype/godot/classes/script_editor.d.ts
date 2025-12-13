
import type { EditorSyntaxHighlighter } from '@godot/classes/editor_syntax_highlighter';
import type { PanelContainer } from '@godot/classes/panel_container';
import type { Script } from '@godot/classes/script';
import type { ScriptEditorBase } from '@godot/classes/script_editor_base';


export declare class ScriptEditor extends PanelContainer {


    public get_current_editor(): ScriptEditorBase;
    public get_open_script_editors(): Array<any>;
    public get_breakpoints(): PackedStringArray;
    public register_syntax_highlighter(syntaxHighlighter: EditorSyntaxHighlighter): void;
    public unregister_syntax_highlighter(syntaxHighlighter: EditorSyntaxHighlighter): void;
    public goto_line(lineNumber: number): void;
    public get_current_script(): Script;
    public get_open_scripts(): Array<any>;
    public open_script_create_dialog(baseName: GDString | StringName | string, basePath: GDString | StringName | string): void;
    public goto_help(topic: GDString | StringName | string): void;
    public update_docs_from_script(script: Script): void;
    public clear_docs_from_script(script: Script): void;

    
    public readonly editor_script_changed: Signal<(script: Script) => void>;
    public readonly script_close: Signal<(script: Script) => void>;

}

