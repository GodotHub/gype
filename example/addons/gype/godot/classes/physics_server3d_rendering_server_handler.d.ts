
import type { AABB } from '@godot/builtins/aabb';
import type { GodotObject } from '@godot/classes/godot_object';
import type { Vector3 } from '@godot/builtins/vector3';


export declare class PhysicsServer3DRenderingServerHandler extends GodotObject {


    public _set_vertex(vertexId: number, vertex: Vector3): void;
    public _set_normal(vertexId: number, normal: Vector3): void;
    public _set_aabb(aabb: AABB): void;
    public set_vertex(vertexId: number, vertex: Vector3): void;
    public set_normal(vertexId: number, normal: Vector3): void;
    public set_aabb(aabb: AABB): void;


}

