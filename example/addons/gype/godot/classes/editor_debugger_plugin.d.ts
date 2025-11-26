
import type { EditorDebuggerSession } from '@godot/classes/editor_debugger_session';
import type { RefCounted } from '@godot/classes/ref_counted';
import type { Script } from '@godot/classes/script';


export declare class EditorDebuggerPlugin extends RefCounted {


    public _setup_session(sessionId: number): void;
    public _has_capture(capture: GDString | StringName | string): boolean;
    public _capture(message: GDString | StringName | string, data: GDArray, sessionId: number): boolean;
    public _goto_script_line(script: Script, line: number): void;
    public _breakpoints_cleared_in_tree(): void;
    public _breakpoint_set_in_tree(script: Script, line: number, enabled: boolean): void;
    public get_session(id: number): EditorDebuggerSession;
    public get_sessions(): GDArray;


}

