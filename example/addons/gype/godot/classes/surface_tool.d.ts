
import type { AABB } from '@godot/builtins/aabb';
import type { ArrayMesh } from '@godot/classes/array_mesh';
import type { Color } from '@godot/builtins/color';
import type { GDArray } from '@godot/builtins/gd_array';
import type { GDString } from '@godot/builtins/gd_string';
import type { Material } from '@godot/classes/material';
import type { Mesh } from '@godot/classes/mesh';
import type { PackedColorArray } from '@godot/builtins/packed_color_array';
import type { PackedFloat32Array } from '@godot/builtins/packed_float32_array';
import type { PackedInt32Array } from '@godot/builtins/packed_int32_array';
import type { PackedVector2Array } from '@godot/builtins/packed_vector2_array';
import type { PackedVector3Array } from '@godot/builtins/packed_vector3_array';
import type { Plane } from '@godot/builtins/plane';
import type { RefCounted } from '@godot/classes/ref_counted';
import type { Transform3D } from '@godot/builtins/transform3d';
import type { Vector2 } from '@godot/builtins/vector2';
import type { Vector3 } from '@godot/builtins/vector3';


export declare class SurfaceTool extends RefCounted {


    public set_skin_weight_count(count: number): void;
    public get_skin_weight_count(): number;
    public set_custom_format(channelIndex: number, format: number): void;
    public get_custom_format(channelIndex: number): number;
    public begin(primitive: number): void;
    public add_vertex(vertex: Vector3): void;
    public set_color(color: Color): void;
    public set_normal(normal: Vector3): void;
    public set_tangent(tangent: Plane): void;
    public set_uv(uv: Vector2): void;
    public set_uv2(uv2: Vector2): void;
    public set_bones(bones: PackedInt32Array): void;
    public set_weights(weights: PackedFloat32Array): void;
    public set_custom(channelIndex: number, customColor: Color): void;
    public set_smooth_group(index: number): void;
    public add_triangle_fan(vertices: PackedVector3Array, uvs: PackedVector2Array = PackedVector2Array(), colors: PackedColorArray = PackedColorArray(), uv2s: PackedVector2Array = PackedVector2Array(), normals: PackedVector3Array = PackedVector3Array(), tangents: Array<any> = Array[Plane]([])): void;
    public add_index(index: number): void;
    public index(): void;
    public deindex(): void;
    public generate_normals(flip: boolean = false): void;
    public generate_tangents(): void;
    public optimize_indices_for_cache(): void;
    public get_aabb(): AABB;
    public generate_lod(ndThreshold: number, targetIndexCount: number = 3): PackedInt32Array;
    public set_material(material: Material): void;
    public get_primitive_type(): number;
    public clear(): void;
    public create_from(existing: Mesh, surface: number): void;
    public create_from_arrays(arrays: GDArray, primitiveType: number = 3): void;
    public create_from_blend_shape(existing: Mesh, surface: number, blendShape: GDString | StringName | string): void;
    public append_from(existing: Mesh, surface: number, transform: Transform3D): void;
    public commit(existing: ArrayMesh = null, flags: number = 0): ArrayMesh;
    public commit_to_arrays(): GDArray;


    public static readonly CustomFormat: {
        CUSTOM_RGBA8_UNORM: 0;
        CUSTOM_RGBA8_SNORM: 1;
        CUSTOM_RG_HALF: 2;
        CUSTOM_RGBA_HALF: 3;
        CUSTOM_R_FLOAT: 4;
        CUSTOM_RG_FLOAT: 5;
        CUSTOM_RGB_FLOAT: 6;
        CUSTOM_RGBA_FLOAT: 7;
        CUSTOM_MAX: 8;
    };
    public static readonly SkinWeightCount: {
        SKIN_4_WEIGHTS: 0;
        SKIN_8_WEIGHTS: 1;
    };
}

