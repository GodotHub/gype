
import type { GodotObject } from '@godot/classes/godot_object';


export declare class RenderSceneData extends GodotObject {


    public get_cam_transform(): Transform3D;
    public get_cam_projection(): Projection;
    public get_view_count(): number;
    public get_view_eye_offset(view: number): Vector3;
    public get_view_projection(view: number): Projection;
    public get_uniform_buffer(): RID;


}

