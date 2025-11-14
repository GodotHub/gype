
import type { GDArray } from '@godot/builtins/gd_array';
import type { GDString } from '@godot/builtins/gd_string';
import type { GodotObject } from '@godot/classes/godot_object';
import type { PackedStringArray } from '@godot/builtins/packed_string_array';
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class Expression extends RefCounted {


    public parse(expression: GDString | StringName | string, inputNames: PackedStringArray = PackedStringArray()): number;
    public execute(inputs: GDArray = [], baseInstance: GodotObject = null, showError: boolean = true, constCallsOnly: boolean = false): any;
    public has_execute_failed(): boolean;
    public get_error_text(): GDString;


}

