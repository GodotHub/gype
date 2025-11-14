
import type { PhysicsDirectSpaceState2D } from '@godot/classes/physics_direct_space_state2d';
import type { RID } from '@godot/builtins/rid';
import type { Transform2D } from '@godot/builtins/transform2d';
import type { Vector2 } from '@godot/builtins/vector2';


export declare class PhysicsDirectSpaceState2DExtension extends PhysicsDirectSpaceState2D {


    public _intersect_ray(_from: Vector2, to: Vector2, collisionMask: number, collideWithBodies: boolean, collideWithAreas: boolean, hitFromInside: boolean, result: any): boolean;
    public _intersect_point(position: Vector2, canvasInstanceId: number, collisionMask: number, collideWithBodies: boolean, collideWithAreas: boolean, results: any, maxResults: number): number;
    public _intersect_shape(shapeRid: RID, transform: Transform2D, motion: Vector2, margin: number, collisionMask: number, collideWithBodies: boolean, collideWithAreas: boolean, result: any, maxResults: number): number;
    public _cast_motion(shapeRid: RID, transform: Transform2D, motion: Vector2, margin: number, collisionMask: number, collideWithBodies: boolean, collideWithAreas: boolean, closestSafe: any, closestUnsafe: any): boolean;
    public _collide_shape(shapeRid: RID, transform: Transform2D, motion: Vector2, margin: number, collisionMask: number, collideWithBodies: boolean, collideWithAreas: boolean, results: any, maxResults: number, resultCount: any): boolean;
    public _rest_info(shapeRid: RID, transform: Transform2D, motion: Vector2, margin: number, collisionMask: number, collideWithBodies: boolean, collideWithAreas: boolean, restInfo: any): boolean;
    public is_body_excluded_from_query(body: RID): boolean;


}

