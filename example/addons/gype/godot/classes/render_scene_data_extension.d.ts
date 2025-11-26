
import type { RenderSceneData } from '@godot/classes/render_scene_data';


export declare class RenderSceneDataExtension extends RenderSceneData {


    public _get_cam_transform(): Transform3D;
    public _get_cam_projection(): Projection;
    public _get_view_count(): number;
    public _get_view_eye_offset(view: number): Vector3;
    public _get_view_projection(view: number): Projection;
    public _get_uniform_buffer(): RID;


}

