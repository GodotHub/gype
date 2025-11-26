
import type { OpenXRActionSet } from '@godot/classes/open_xr_action_set';
import type { OpenXRInteractionProfile } from '@godot/classes/open_xr_interaction_profile';
import type { Resource } from '@godot/classes/resource';


export declare class OpenXRActionMap extends Resource {

    
    /**     * The raw type is 'OpenXRActionSet'     */
    public action_sets: GDArray;    
    /**     * The raw type is 'OpenXRInteractionProfile'     */
    public interaction_profiles: GDArray;
    public set_action_sets(actionSets: GDArray): void;
    public get_action_sets(): GDArray;
    public get_action_set_count(): number;
    public find_action_set(name: GDString | StringName | string): OpenXRActionSet;
    public get_action_set(idx: number): OpenXRActionSet;
    public add_action_set(actionSet: OpenXRActionSet): void;
    public remove_action_set(actionSet: OpenXRActionSet): void;
    public set_interaction_profiles(interactionProfiles: GDArray): void;
    public get_interaction_profiles(): GDArray;
    public get_interaction_profile_count(): number;
    public find_interaction_profile(name: GDString | StringName | string): OpenXRInteractionProfile;
    public get_interaction_profile(idx: number): OpenXRInteractionProfile;
    public add_interaction_profile(interactionProfile: OpenXRInteractionProfile): void;
    public remove_interaction_profile(interactionProfile: OpenXRInteractionProfile): void;
    public create_default_action_sets(): void;


}

