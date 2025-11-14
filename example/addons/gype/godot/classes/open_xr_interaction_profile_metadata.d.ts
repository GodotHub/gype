
import type { GDString } from '@godot/builtins/gd_string';
import type { GodotObject } from '@godot/classes/godot_object';


export declare class OpenXRInteractionProfileMetadata extends GodotObject {


    public register_profile_rename(oldName: GDString | StringName | string, newName: GDString | StringName | string): void;
    public register_top_level_path(displayName: GDString | StringName | string, openxrPath: GDString | StringName | string, openxrExtensionName: GDString | StringName | string): void;
    public register_interaction_profile(displayName: GDString | StringName | string, openxrPath: GDString | StringName | string, openxrExtensionName: GDString | StringName | string): void;
    public register_io_path(interactionProfile: GDString | StringName | string, displayName: GDString | StringName | string, toplevelPath: GDString | StringName | string, openxrPath: GDString | StringName | string, openxrExtensionName: GDString | StringName | string, actionType: number): void;


}

