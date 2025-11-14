
import type { GDArray } from '@godot/builtins/gd_array';
import type { GDString } from '@godot/builtins/gd_string';
import type { OpenXRIPBinding } from '@godot/classes/open_xrip_binding';
import type { OpenXRIPBindingModifier } from '@godot/classes/open_xrip_binding_modifier';
import type { Resource } from '@godot/classes/resource';


export declare class OpenXRInteractionProfile extends Resource {

    
    /**     * The raw type is 'String'     */
    public interaction_profile_path: GDString;    
    /**     * The raw type is 'OpenXRIPBinding'     */
    public bindings: GDArray;    
    /**     * The raw type is 'OpenXRIPBindingModifier'     */
    public binding_modifiers: GDArray;
    public set_interaction_profile_path(interactionProfilePath: GDString | StringName | string): void;
    public get_interaction_profile_path(): GDString;
    public get_binding_count(): number;
    public get_binding(index: number): OpenXRIPBinding;
    public set_bindings(bindings: GDArray): void;
    public get_bindings(): GDArray;
    public get_binding_modifier_count(): number;
    public get_binding_modifier(index: number): OpenXRIPBindingModifier;
    public set_binding_modifiers(bindingModifiers: GDArray): void;
    public get_binding_modifiers(): GDArray;


}

