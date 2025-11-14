
import type { Dictionary } from '@godot/builtins/dictionary';
import type { GodotObject } from '@godot/classes/godot_object';
import type { OpenXRAPIExtension } from '@godot/classes/open_xrapi_extension';
import type { PackedStringArray } from '@godot/builtins/packed_string_array';
import type { RID } from '@godot/builtins/rid';


export declare class OpenXRExtensionWrapper extends GodotObject {


    public _get_requested_extensions(): Dictionary;
    public _set_system_properties_and_get_next_pointer(nextPointer: any): number;
    public _set_instance_create_info_and_get_next_pointer(nextPointer: any): number;
    public _set_session_create_and_get_next_pointer(nextPointer: any): number;
    public _set_swapchain_create_info_and_get_next_pointer(nextPointer: any): number;
    public _set_hand_joint_locations_and_get_next_pointer(handIndex: number, nextPointer: any): number;
    public _set_projection_views_and_get_next_pointer(viewIndex: number, nextPointer: any): number;
    public _set_frame_wait_info_and_get_next_pointer(nextPointer: any): number;
    public _set_frame_end_info_and_get_next_pointer(nextPointer: any): number;
    public _set_view_locate_info_and_get_next_pointer(nextPointer: any): number;
    public _set_reference_space_create_info_and_get_next_pointer(referenceSpaceType: number, nextPointer: any): number;
    public _get_composition_layer_count(): number;
    public _get_composition_layer(index: number): number;
    public _get_composition_layer_order(index: number): number;
    public _get_suggested_tracker_names(): PackedStringArray;
    public _on_register_metadata(): void;
    public _on_before_instance_created(): void;
    public _on_instance_created(instance: number): void;
    public _on_instance_destroyed(): void;
    public _on_session_created(session: number): void;
    public _on_process(): void;
    public _on_sync_actions(): void;
    public _on_pre_render(): void;
    public _on_main_swapchains_created(): void;
    public _on_pre_draw_viewport(viewport: RID): void;
    public _on_post_draw_viewport(viewport: RID): void;
    public _on_session_destroyed(): void;
    public _on_state_idle(): void;
    public _on_state_ready(): void;
    public _on_state_synchronized(): void;
    public _on_state_visible(): void;
    public _on_state_focused(): void;
    public _on_state_stopping(): void;
    public _on_state_loss_pending(): void;
    public _on_state_exiting(): void;
    public _on_event_polled(event: any): boolean;
    public _set_viewport_composition_layer_and_get_next_pointer(layer: any, propertyValues: Dictionary, nextPointer: any): number;
    public _get_viewport_composition_layer_extension_properties(): Array<any>;
    public _get_viewport_composition_layer_extension_property_defaults(): Dictionary;
    public _on_viewport_composition_layer_destroyed(layer: any): void;
    public _set_android_surface_swapchain_create_info_and_get_next_pointer(propertyValues: Dictionary, nextPointer: any): number;
    public get_openxr_api(): OpenXRAPIExtension;
    public register_extension_wrapper(): void;


}

