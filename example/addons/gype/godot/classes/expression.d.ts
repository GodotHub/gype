
import type { GodotObject } from '@godot/classes/godot_object';
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class Expression extends RefCounted {


    public parse(expression: GDString | StringName | string, inputNames: PackedStringArray = PackedStringArray()): number;
    public execute(inputs: GDArray | Array = [], baseInstance: GodotObject = null, showError: boolean = true, constCallsOnly: boolean = false): any;
    public has_execute_failed(): boolean;
    public get_error_text(): GDString;


}

