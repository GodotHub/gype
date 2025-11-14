
import type { GDString } from '@godot/builtins/gd_string';
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class Logger extends RefCounted {


    public _log_error(_function: GDString | StringName | string, file: GDString | StringName | string, line: number, code: GDString | StringName | string, rationale: GDString | StringName | string, editorNotify: boolean, errorType: number, scriptBacktraces: Array<any>): void;
    public _log_message(message: GDString | StringName | string, error: boolean): void;


    public static readonly ErrorType: {
        ERROR_TYPE_ERROR: 0;
        ERROR_TYPE_WARNING: 1;
        ERROR_TYPE_SCRIPT: 2;
        ERROR_TYPE_SHADER: 3;
    };
}

