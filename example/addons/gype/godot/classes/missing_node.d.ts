
import type { GDString } from '@godot/builtins/gd_string';
import type { Node } from '@godot/classes/node';


export declare class MissingNode extends Node {

    
    /**     * The raw type is 'String'     */
    public original_class: GDString;    
    /**     * The raw type is 'String'     */
    public original_scene: GDString;    
    /**     * The raw type is 'bool'     */
    public recording_properties: boolean;
    public set_original_class(name: GDString | StringName | string): void;
    public get_original_class(): GDString;
    public set_original_scene(name: GDString | StringName | string): void;
    public get_original_scene(): GDString;
    public set_recording_properties(enable: boolean): void;
    public is_recording_properties(): boolean;


}

