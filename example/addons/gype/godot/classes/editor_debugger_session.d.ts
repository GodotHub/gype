
import type { Control } from '@godot/classes/control';
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class EditorDebuggerSession extends RefCounted {


    public send_message(message: GDString | StringName | string, data: GDArray | Array = []): void;
    public toggle_profiler(profiler: GDString | StringName | string, enable: boolean, data: GDArray | Array = []): void;
    public is_breaked(): boolean;
    public is_debuggable(): boolean;
    public is_active(): boolean;
    public add_session_tab(control: Control): void;
    public remove_session_tab(control: Control): void;
    public set_breakpoint(path: GDString | StringName | string, line: number, enabled: boolean): void;

    
    public readonly started: Signal<() => void>;
    public readonly stopped: Signal<() => void>;
    public readonly breaked: Signal<(canDebug: boolean) => void>;
    public readonly continued: Signal<() => void>;

}

