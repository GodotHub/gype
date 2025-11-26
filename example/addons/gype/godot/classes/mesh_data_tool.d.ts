
import type { ArrayMesh } from '@godot/classes/array_mesh';
import type { Material } from '@godot/classes/material';
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class MeshDataTool extends RefCounted {


    public clear(): void;
    public create_from_surface(mesh: ArrayMesh, surface: number): number;
    public commit_to_surface(mesh: ArrayMesh, compressionFlags: number = 0): number;
    public get_format(): number;
    public get_vertex_count(): number;
    public get_edge_count(): number;
    public get_face_count(): number;
    public set_vertex(idx: number, vertex: Vector3): void;
    public get_vertex(idx: number): Vector3;
    public set_vertex_normal(idx: number, normal: Vector3): void;
    public get_vertex_normal(idx: number): Vector3;
    public set_vertex_tangent(idx: number, tangent: Plane): void;
    public get_vertex_tangent(idx: number): Plane;
    public set_vertex_uv(idx: number, uv: Vector2): void;
    public get_vertex_uv(idx: number): Vector2;
    public set_vertex_uv2(idx: number, uv2: Vector2): void;
    public get_vertex_uv2(idx: number): Vector2;
    public set_vertex_color(idx: number, color: Color): void;
    public get_vertex_color(idx: number): Color;
    public set_vertex_bones(idx: number, bones: PackedInt32Array): void;
    public get_vertex_bones(idx: number): PackedInt32Array;
    public set_vertex_weights(idx: number, weights: PackedFloat32Array): void;
    public get_vertex_weights(idx: number): PackedFloat32Array;
    public set_vertex_meta(idx: number, meta: any): void;
    public get_vertex_meta(idx: number): any;
    public get_vertex_edges(idx: number): PackedInt32Array;
    public get_vertex_faces(idx: number): PackedInt32Array;
    public get_edge_vertex(idx: number, vertex: number): number;
    public get_edge_faces(idx: number): PackedInt32Array;
    public set_edge_meta(idx: number, meta: any): void;
    public get_edge_meta(idx: number): any;
    public get_face_vertex(idx: number, vertex: number): number;
    public get_face_edge(idx: number, edge: number): number;
    public set_face_meta(idx: number, meta: any): void;
    public get_face_meta(idx: number): any;
    public get_face_normal(idx: number): Vector3;
    public set_material(material: Material): void;
    public get_material(): Material;


}

