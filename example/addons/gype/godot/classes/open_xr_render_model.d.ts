
import type { GDString } from '@godot/builtins/gd_string';
import type { Node3D } from '@godot/classes/node3d';
import type { RID } from '@godot/builtins/rid';
import type { Signal } from '@godot/builtins/signal';


export declare class OpenXRRenderModel extends Node3D {

    
    /**     * The raw type is 'RID'     */
    public render_model: RID;
    public get_top_level_path(): GDString;
    public get_render_model(): RID;
    public set_render_model(renderModel: RID): void;

    
    public readonly render_model_top_level_path_changed: Signal<() => void>;

}

