
import type { Dictionary } from '@godot/builtins/dictionary';
import type { GodotObject } from '@godot/classes/godot_object';
import type { PackedFloat32Array } from '@godot/builtins/packed_float32_array';
import type { PhysicsPointQueryParameters3D } from '@godot/classes/physics_point_query_parameters3d';
import type { PhysicsRayQueryParameters3D } from '@godot/classes/physics_ray_query_parameters3d';
import type { PhysicsShapeQueryParameters3D } from '@godot/classes/physics_shape_query_parameters3d';


export declare class PhysicsDirectSpaceState3D extends GodotObject {


    public intersect_point(parameters: PhysicsPointQueryParameters3D, maxResults: number = 32): Array<any>;
    public intersect_ray(parameters: PhysicsRayQueryParameters3D): Dictionary;
    public intersect_shape(parameters: PhysicsShapeQueryParameters3D, maxResults: number = 32): Array<any>;
    public cast_motion(parameters: PhysicsShapeQueryParameters3D): PackedFloat32Array;
    public collide_shape(parameters: PhysicsShapeQueryParameters3D, maxResults: number = 32): Array<any>;
    public get_rest_info(parameters: PhysicsShapeQueryParameters3D): Dictionary;


}

