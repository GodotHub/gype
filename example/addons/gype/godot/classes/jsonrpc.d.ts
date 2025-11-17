
import type { Callable } from '@godot/builtins/callable';
import type { Dictionary } from '@godot/builtins/dictionary';
import type { GDString } from '@godot/builtins/gd_string';
import type { GodotObject } from '@godot/classes/godot_object';


export declare class JSONRPC extends GodotObject {


    public set_method(name: GDString | StringName | string, callback: Callable | Function): void;
    public process_action(action: any, recurse: boolean = false): any;
    public process_string(action: GDString | StringName | string): GDString;
    public make_request(method: GDString | StringName | string, params: any, id: any): Dictionary;
    public make_response(result: any, id: any): Dictionary;
    public make_notification(method: GDString | StringName | string, params: any): Dictionary;
    public make_response_error(code: number, message: GDString | StringName | string, id: any = null): Dictionary;


    public static readonly ErrorCode: {
        PARSE_ERROR: -32700;
        INVALID_REQUEST: -32600;
        METHOD_NOT_FOUND: -32601;
        INVALID_PARAMS: -32602;
        INTERNAL_ERROR: -32603;
    };
}

