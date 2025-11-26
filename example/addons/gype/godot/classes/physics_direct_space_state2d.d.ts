
import type { GodotObject } from '@godot/classes/godot_object';
import type { PhysicsPointQueryParameters2D } from '@godot/classes/physics_point_query_parameters2d';
import type { PhysicsRayQueryParameters2D } from '@godot/classes/physics_ray_query_parameters2d';
import type { PhysicsShapeQueryParameters2D } from '@godot/classes/physics_shape_query_parameters2d';


export declare class PhysicsDirectSpaceState2D extends GodotObject {


    public intersect_point(parameters: PhysicsPointQueryParameters2D, maxResults: number = 32): Array<any>;
    public intersect_ray(parameters: PhysicsRayQueryParameters2D): Dictionary;
    public intersect_shape(parameters: PhysicsShapeQueryParameters2D, maxResults: number = 32): Array<any>;
    public cast_motion(parameters: PhysicsShapeQueryParameters2D): PackedFloat32Array;
    public collide_shape(parameters: PhysicsShapeQueryParameters2D, maxResults: number = 32): Array<any>;
    public get_rest_info(parameters: PhysicsShapeQueryParameters2D): Dictionary;


}

