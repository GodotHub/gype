
import type { PhysicsDirectSpaceState3D } from '@godot/classes/physics_direct_space_state3d';


export declare class PhysicsDirectSpaceState3DExtension extends PhysicsDirectSpaceState3D {


    public _intersect_ray(_from: Vector3, to: Vector3, collisionMask: number, collideWithBodies: boolean, collideWithAreas: boolean, hitFromInside: boolean, hitBackFaces: boolean, pickRay: boolean, result: any): boolean;
    public _intersect_point(position: Vector3, collisionMask: number, collideWithBodies: boolean, collideWithAreas: boolean, results: any, maxResults: number): number;
    public _intersect_shape(shapeRid: RID, transform: Transform3D, motion: Vector3, margin: number, collisionMask: number, collideWithBodies: boolean, collideWithAreas: boolean, resultCount: any, maxResults: number): number;
    public _cast_motion(shapeRid: RID, transform: Transform3D, motion: Vector3, margin: number, collisionMask: number, collideWithBodies: boolean, collideWithAreas: boolean, closestSafe: any, closestUnsafe: any, info: any): boolean;
    public _collide_shape(shapeRid: RID, transform: Transform3D, motion: Vector3, margin: number, collisionMask: number, collideWithBodies: boolean, collideWithAreas: boolean, results: any, maxResults: number, resultCount: any): boolean;
    public _rest_info(shapeRid: RID, transform: Transform3D, motion: Vector3, margin: number, collisionMask: number, collideWithBodies: boolean, collideWithAreas: boolean, restInfo: any): boolean;
    public _get_closest_point_to_object_volume(object: RID, point: Vector3): Vector3;
    public is_body_excluded_from_query(body: RID): boolean;


}

