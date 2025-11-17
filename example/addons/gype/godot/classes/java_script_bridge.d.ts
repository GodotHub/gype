
import type { Callable } from '@godot/builtins/callable';
import type { GDString } from '@godot/builtins/gd_string';
import type { GodotObject } from '@godot/classes/godot_object';
import type { JavaScriptObject } from '@godot/classes/java_script_object';
import type { PackedByteArray } from '@godot/builtins/packed_byte_array';
import type { Signal } from '@godot/builtins/signal';


export declare class JavaScriptBridge extends GodotObject {


    public eval(code: GDString | StringName | string, useGlobalExecutionContext: boolean = false): any;
    public get_interface(_interface: GDString | StringName | string): JavaScriptObject;
    public create_callback(callable: Callable | Function): JavaScriptObject;
    public is_js_buffer(javascriptObject: JavaScriptObject): boolean;
    public js_buffer_to_packed_byte_array(javascriptBuffer: JavaScriptObject): PackedByteArray;
    public create_object(object: GDString | StringName | string, ...args: any[]): any;
    public download_buffer(buffer: PackedByteArray, name: GDString | StringName | string, mime: GDString | StringName | string = "application/octet-stream"): void;
    public pwa_needs_update(): boolean;
    public pwa_update(): number;
    public force_fs_sync(): void;

    
    public readonly pwa_update_available: Signal<() => void>;

}


/**
 * A singleton instance of JavaScriptBridge.
 * This is a global variable, available from anywhere.
 */
export const JavaScriptBridge: JavaScriptBridge;
