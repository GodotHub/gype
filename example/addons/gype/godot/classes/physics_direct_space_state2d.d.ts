
import { PhysicsShapeQueryParameters2D } from "@godot/classes/physics_shape_query_parameters2d";
import { PhysicsRayQueryParameters2D } from "@godot/classes/physics_ray_query_parameters2d";
import { PhysicsPointQueryParameters2D } from "@godot/classes/physics_point_query_parameters2d";
import { Object } from "@godot/classes/object";

export declare class PhysicsDirectSpaceState2D extends Object{
  public intersect_point(_parameters: PhysicsPointQueryParameters2D, _max_results: number): GDArray;
  public intersect_ray(_parameters: PhysicsRayQueryParameters2D): Dictionary;
  public intersect_shape(_parameters: PhysicsShapeQueryParameters2D, _max_results: number): GDArray;
  public cast_motion(_parameters: PhysicsShapeQueryParameters2D): PackedFloat32Array;
  public collide_shape(_parameters: PhysicsShapeQueryParameters2D, _max_results: number): GDArray;
  public get_rest_info(_parameters: PhysicsShapeQueryParameters2D): Dictionary;
}