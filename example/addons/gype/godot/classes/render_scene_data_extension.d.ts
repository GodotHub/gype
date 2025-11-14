
import type { Projection } from '@godot/builtins/projection';
import type { RID } from '@godot/builtins/rid';
import type { RenderSceneData } from '@godot/classes/render_scene_data';
import type { Transform3D } from '@godot/builtins/transform3d';
import type { Vector3 } from '@godot/builtins/vector3';


export declare class RenderSceneDataExtension extends RenderSceneData {


    public _get_cam_transform(): Transform3D;
    public _get_cam_projection(): Projection;
    public _get_view_count(): number;
    public _get_view_eye_offset(view: number): Vector3;
    public _get_view_projection(view: number): Projection;
    public _get_uniform_buffer(): RID;


}

