
import type { Node3D } from '@godot/classes/node3d';
import type { OpenXRRenderModel } from '@godot/classes/open_xr_render_model';


export declare class OpenXRRenderModelManager extends Node3D {

    
    /**     * The raw type is 'int'     */
    public tracker: number;    
    /**     * The raw type is 'String'     */
    public make_local_to_pose: GDString;
    public get_tracker(): number;
    public set_tracker(tracker: number): void;
    public get_make_local_to_pose(): GDString;
    public set_make_local_to_pose(makeLocalToPose: GDString | StringName | string): void;

    
    public readonly render_model_added: Signal;
    public readonly render_model_removed: Signal;

    public static readonly RenderModelTracker: {
        RENDER_MODEL_TRACKER_ANY: 0;
        RENDER_MODEL_TRACKER_NONE_SET: 1;
        RENDER_MODEL_TRACKER_LEFT_HAND: 2;
        RENDER_MODEL_TRACKER_RIGHT_HAND: 3;
    };
}

