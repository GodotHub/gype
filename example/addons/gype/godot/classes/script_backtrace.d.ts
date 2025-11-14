
import type { GDString } from '@godot/builtins/gd_string';
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class ScriptBacktrace extends RefCounted {


    public get_language_name(): GDString;
    public is_empty(): boolean;
    public get_frame_count(): number;
    public get_frame_function(index: number): GDString;
    public get_frame_file(index: number): GDString;
    public get_frame_line(index: number): number;
    public get_global_variable_count(): number;
    public get_global_variable_name(variableIndex: number): GDString;
    public get_global_variable_value(variableIndex: number): any;
    public get_local_variable_count(frameIndex: number): number;
    public get_local_variable_name(frameIndex: number, variableIndex: number): GDString;
    public get_local_variable_value(frameIndex: number, variableIndex: number): any;
    public get_member_variable_count(frameIndex: number): number;
    public get_member_variable_name(frameIndex: number, variableIndex: number): GDString;
    public get_member_variable_value(frameIndex: number, variableIndex: number): any;
    public format(indentAll: number = 0, indentFrames: number = 4): GDString;


}

