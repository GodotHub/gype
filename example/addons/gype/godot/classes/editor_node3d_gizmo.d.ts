
import type { Camera3D } from '@godot/classes/camera3d';
import type { Color } from '@godot/builtins/color';
import type { EditorNode3DGizmoPlugin } from '@godot/classes/editor_node3d_gizmo_plugin';
import type { GDString } from '@godot/builtins/gd_string';
import type { Material } from '@godot/classes/material';
import type { Mesh } from '@godot/classes/mesh';
import type { Node } from '@godot/classes/node';
import type { Node3D } from '@godot/classes/node3d';
import type { Node3DGizmo } from '@godot/classes/node3d_gizmo';
import type { PackedInt32Array } from '@godot/builtins/packed_int32_array';
import type { PackedVector3Array } from '@godot/builtins/packed_vector3_array';
import type { SkinReference } from '@godot/classes/skin_reference';
import type { Transform3D } from '@godot/builtins/transform3d';
import type { TriangleMesh } from '@godot/classes/triangle_mesh';
import type { Vector2 } from '@godot/builtins/vector2';


export declare class EditorNode3DGizmo extends Node3DGizmo {


    public _redraw(): void;
    public _get_handle_name(id: number, secondary: boolean): GDString;
    public _is_handle_highlighted(id: number, secondary: boolean): boolean;
    public _get_handle_value(id: number, secondary: boolean): any;
    public _begin_handle_action(id: number, secondary: boolean): void;
    public _set_handle(id: number, secondary: boolean, camera: Camera3D, point: Vector2): void;
    public _commit_handle(id: number, secondary: boolean, restore: any, cancel: boolean): void;
    public _subgizmos_intersect_ray(camera: Camera3D, point: Vector2): number;
    public _subgizmos_intersect_frustum(camera: Camera3D, frustum: Array<any>): PackedInt32Array;
    public _set_subgizmo_transform(id: number, transform: Transform3D): void;
    public _get_subgizmo_transform(id: number): Transform3D;
    public _commit_subgizmos(ids: PackedInt32Array, restores: Array<any>, cancel: boolean): void;
    public add_lines(lines: PackedVector3Array, material: Material, billboard: boolean = false, modulate: Color = Color(1, 1, 1, 1)): void;
    public add_mesh(mesh: Mesh, material: Material = null, transform: Transform3D = Transform3D(1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0), skeleton: SkinReference = null): void;
    public add_collision_segments(segments: PackedVector3Array): void;
    public add_collision_triangles(triangles: TriangleMesh): void;
    public add_unscaled_billboard(material: Material, defaultScale: number = 1, modulate: Color = Color(1, 1, 1, 1)): void;
    public add_handles(handles: PackedVector3Array, material: Material, ids: PackedInt32Array, billboard: boolean = false, secondary: boolean = false): void;
    public set_node_3d(node: Node): void;
    public get_node_3d(): Node3D;
    public get_plugin(): EditorNode3DGizmoPlugin;
    public clear(): void;
    public set_hidden(hidden: boolean): void;
    public is_subgizmo_selected(id: number): boolean;
    public get_subgizmo_selection(): PackedInt32Array;


}

