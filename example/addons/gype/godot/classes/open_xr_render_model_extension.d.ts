
import type { Node3D } from '@godot/classes/node3d';
import type { OpenXRExtensionWrapper } from '@godot/classes/open_xr_extension_wrapper';


export declare class OpenXRRenderModelExtension extends OpenXRExtensionWrapper {


    public is_active(): boolean;
    public render_model_create(renderModelId: number): RID;
    public render_model_destroy(renderModel: RID): void;
    public render_model_get_all(): Array<any>;
    public render_model_new_scene_instance(renderModel: RID): Node3D;
    public render_model_get_subaction_paths(renderModel: RID): PackedStringArray;
    public render_model_get_top_level_path(renderModel: RID): GDString;
    public render_model_get_confidence(renderModel: RID): number;
    public render_model_get_root_transform(renderModel: RID): Transform3D;
    public render_model_get_animatable_node_count(renderModel: RID): number;
    public render_model_get_animatable_node_name(renderModel: RID, index: number): GDString;
    public render_model_is_animatable_node_visible(renderModel: RID, index: number): boolean;
    public render_model_get_animatable_node_transform(renderModel: RID, index: number): Transform3D;

    
    public readonly render_model_added: Signal;
    public readonly render_model_removed: Signal;
    public readonly render_model_top_level_path_changed: Signal;

}

