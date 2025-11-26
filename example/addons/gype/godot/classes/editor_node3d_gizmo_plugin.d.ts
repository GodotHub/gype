
import type { Camera3D } from '@godot/classes/camera3d';
import type { EditorNode3DGizmo } from '@godot/classes/editor_node3d_gizmo';
import type { Node3D } from '@godot/classes/node3d';
import type { Resource } from '@godot/classes/resource';
import type { StandardMaterial3D } from '@godot/classes/standard_material3d';
import type { Texture2D } from '@godot/classes/texture2d';


export declare class EditorNode3DGizmoPlugin extends Resource {


    public _has_gizmo(forNode3D: Node3D): boolean;
    public _create_gizmo(forNode3D: Node3D): EditorNode3DGizmo;
    public _get_gizmo_name(): GDString;
    public _get_priority(): number;
    public _can_be_hidden(): boolean;
    public _is_selectable_when_hidden(): boolean;
    public _redraw(gizmo: EditorNode3DGizmo): void;
    public _get_handle_name(gizmo: EditorNode3DGizmo, handleId: number, secondary: boolean): GDString;
    public _is_handle_highlighted(gizmo: EditorNode3DGizmo, handleId: number, secondary: boolean): boolean;
    public _get_handle_value(gizmo: EditorNode3DGizmo, handleId: number, secondary: boolean): any;
    public _begin_handle_action(gizmo: EditorNode3DGizmo, handleId: number, secondary: boolean): void;
    public _set_handle(gizmo: EditorNode3DGizmo, handleId: number, secondary: boolean, camera: Camera3D, screenPos: Vector2): void;
    public _commit_handle(gizmo: EditorNode3DGizmo, handleId: number, secondary: boolean, restore: any, cancel: boolean): void;
    public _subgizmos_intersect_ray(gizmo: EditorNode3DGizmo, camera: Camera3D, screenPos: Vector2): number;
    public _subgizmos_intersect_frustum(gizmo: EditorNode3DGizmo, camera: Camera3D, frustumPlanes: Array<any>): PackedInt32Array;
    public _get_subgizmo_transform(gizmo: EditorNode3DGizmo, subgizmoId: number): Transform3D;
    public _set_subgizmo_transform(gizmo: EditorNode3DGizmo, subgizmoId: number, transform: Transform3D): void;
    public _commit_subgizmos(gizmo: EditorNode3DGizmo, ids: PackedInt32Array, restores: Array<any>, cancel: boolean): void;
    public create_material(name: GDString | StringName | string, color: Color, billboard: boolean = false, onTop: boolean = false, useVertexColor: boolean = false): void;
    public create_icon_material(name: GDString | StringName | string, texture: Texture2D, onTop: boolean = false, color: Color = Color(1, 1, 1, 1)): void;
    public create_handle_material(name: GDString | StringName | string, billboard: boolean = false, texture: Texture2D = null): void;
    public add_material(name: GDString | StringName | string, material: StandardMaterial3D): void;
    public get_material(name: GDString | StringName | string, gizmo: EditorNode3DGizmo = null): StandardMaterial3D;


}

