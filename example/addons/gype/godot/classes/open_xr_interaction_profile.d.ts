
import type { OpenXRIPBinding } from '@godot/classes/open_xrip_binding';
import type { OpenXRIPBindingModifier } from '@godot/classes/open_xrip_binding_modifier';
import type { Resource } from '@godot/classes/resource';


export declare class OpenXRInteractionProfile extends Resource {

    
    /**     * The raw type is 'String'     */
    public interaction_profile_path: GDString | StringName | string;    
    /**     * The raw type is 'OpenXRIPBinding'     */
    public bindings: GDArray | Array;    
    /**     * The raw type is 'OpenXRIPBindingModifier'     */
    public binding_modifiers: GDArray | Array;
    public set_interaction_profile_path(interactionProfilePath: GDString | StringName | string): void;
    public get_interaction_profile_path(): GDString;
    public get_binding_count(): number;
    public get_binding(index: number): OpenXRIPBinding;
    public set_bindings(bindings: GDArray | Array): void;
    public get_bindings(): GDArray;
    public get_binding_modifier_count(): number;
    public get_binding_modifier(index: number): OpenXRIPBindingModifier;
    public set_binding_modifiers(bindingModifiers: GDArray | Array): void;
    public get_binding_modifiers(): GDArray;


}

