
import type { Color } from '@godot/builtins/color';
import type { Material } from '@godot/classes/material';
import type { Mesh } from '@godot/classes/mesh';
import type { Plane } from '@godot/builtins/plane';
import type { Vector2 } from '@godot/builtins/vector2';
import type { Vector3 } from '@godot/builtins/vector3';


export declare class ImmediateMesh extends Mesh {


    public surface_begin(primitive: number, material: Material = null): void;
    public surface_set_color(color: Color): void;
    public surface_set_normal(normal: Vector3): void;
    public surface_set_tangent(tangent: Plane): void;
    public surface_set_uv(uv: Vector2): void;
    public surface_set_uv2(uv2: Vector2): void;
    public surface_add_vertex(vertex: Vector3): void;
    public surface_add_vertex_2d(vertex: Vector2): void;
    public surface_end(): void;
    public clear_surfaces(): void;


}

