
import type { GodotObject } from '@godot/classes/godot_object';
import type { RenderSceneBuffers } from '@godot/classes/render_scene_buffers';
import type { RenderSceneData } from '@godot/classes/render_scene_data';


export declare class RenderData extends GodotObject {


    public get_render_scene_buffers(): RenderSceneBuffers;
    public get_render_scene_data(): RenderSceneData;
    public get_environment(): RID;
    public get_camera_attributes(): RID;


}

