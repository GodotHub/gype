
import type { ArrayMesh } from '@godot/classes/array_mesh';
import type { Material } from '@godot/classes/material';
import type { Resource } from '@godot/classes/resource';


export declare class ImporterMesh extends Resource {


    public add_blend_shape(name: GDString | StringName | string): void;
    public get_blend_shape_count(): number;
    public get_blend_shape_name(blendShapeIdx: number): GDString;
    public set_blend_shape_mode(mode: number): void;
    public get_blend_shape_mode(): number;
    public add_surface(primitive: number, arrays: GDArray | Array, blendShapes: Array<any> = Array[Array]([]), lods: Dictionary = {}, material: Material = null, name: GDString | StringName | string = "", flags: number = 0): void;
    public get_surface_count(): number;
    public get_surface_primitive_type(surfaceIdx: number): number;
    public get_surface_name(surfaceIdx: number): GDString;
    public get_surface_arrays(surfaceIdx: number): GDArray;
    public get_surface_blend_shape_arrays(surfaceIdx: number, blendShapeIdx: number): GDArray;
    public get_surface_lod_count(surfaceIdx: number): number;
    public get_surface_lod_size(surfaceIdx: number, lodIdx: number): number;
    public get_surface_lod_indices(surfaceIdx: number, lodIdx: number): PackedInt32Array;
    public get_surface_material(surfaceIdx: number): Material;
    public get_surface_format(surfaceIdx: number): number;
    public set_surface_name(surfaceIdx: number, name: GDString | StringName | string): void;
    public set_surface_material(surfaceIdx: number, material: Material): void;
    public generate_lods(normalMergeAngle: number, normalSplitAngle: number, boneTransformArray: GDArray | Array): void;
    public get_mesh(baseMesh: ArrayMesh = null): ArrayMesh;
    public clear(): void;
    public set_lightmap_size_hint(size: Vector2i): void;
    public get_lightmap_size_hint(): Vector2i;


}

