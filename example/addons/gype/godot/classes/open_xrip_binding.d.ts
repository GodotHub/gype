
import type { OpenXRAction } from '@godot/classes/open_xr_action';
import type { OpenXRActionBindingModifier } from '@godot/classes/open_xr_action_binding_modifier';
import type { Resource } from '@godot/classes/resource';


export declare class OpenXRIPBinding extends Resource {

    
    /**     * The raw type is 'OpenXRAction'     */
    public action: OpenXRAction;    
    /**     * The raw type is 'String'     */
    public binding_path: GDString;    
    /**     * The raw type is 'OpenXRActionBindingModifier'     */
    public binding_modifiers: GDArray;    
    /**     * The raw type is 'PackedStringArray'     */
    public paths: PackedStringArray;
    public set_action(action: OpenXRAction): void;
    public get_action(): OpenXRAction;
    public set_binding_path(bindingPath: GDString | StringName | string): void;
    public get_binding_path(): GDString;
    public get_binding_modifier_count(): number;
    public get_binding_modifier(index: number): OpenXRActionBindingModifier;
    public set_binding_modifiers(bindingModifiers: GDArray): void;
    public get_binding_modifiers(): GDArray;
    public set_paths(paths: PackedStringArray): void;
    public get_paths(): PackedStringArray;
    public get_path_count(): number;
    public has_path(path: GDString | StringName | string): boolean;
    public add_path(path: GDString | StringName | string): void;
    public remove_path(path: GDString | StringName | string): void;


}

