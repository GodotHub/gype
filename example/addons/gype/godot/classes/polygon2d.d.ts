
import type { Color } from '@godot/builtins/color';
import type { GDArray } from '@godot/builtins/gd_array';
import type { Node2D } from '@godot/classes/node2d';
import type { NodePath } from '@godot/builtins/node_path';
import type { PackedColorArray } from '@godot/builtins/packed_color_array';
import type { PackedFloat32Array } from '@godot/builtins/packed_float32_array';
import type { PackedVector2Array } from '@godot/builtins/packed_vector2_array';
import type { Texture2D } from '@godot/classes/texture2d';
import type { Vector2 } from '@godot/builtins/vector2';


export declare class Polygon2D extends Node2D {

    
    /**     * The raw type is 'Color'     */
    public color: Color;    
    /**     * The raw type is 'Vector2'     */
    public offset: Vector2;    
    /**     * The raw type is 'bool'     */
    public antialiased: boolean;    
    /**     * The raw type is 'Texture2D'     */
    public texture: Texture2D;    
    /**     * The raw type is 'Vector2'     */
    public texture_offset: Vector2;    
    /**     * The raw type is 'Vector2'     */
    public texture_scale: Vector2;    
    /**     * The raw type is 'float'     */
    public texture_rotation: number;    
    /**     * The raw type is 'NodePath'     */
    public skeleton: NodePath;    
    /**     * The raw type is 'bool'     */
    public invert_enabled: boolean;    
    /**     * The raw type is 'float'     */
    public invert_border: number;    
    /**     * The raw type is 'PackedVector2Array'     */
    public polygon: PackedVector2Array;    
    /**     * The raw type is 'PackedVector2Array'     */
    public uv: PackedVector2Array;    
    /**     * The raw type is 'PackedColorArray'     */
    public vertex_colors: PackedColorArray;    
    /**     * The raw type is 'Array'     */
    public polygons: GDArray;    
    /**     * The raw type is 'Array'     */
    public bones: GDArray;    
    /**     * The raw type is 'int'     */
    public internal_vertex_count: number;
    public set_polygon(polygon: PackedVector2Array): void;
    public get_polygon(): PackedVector2Array;
    public set_uv(uv: PackedVector2Array): void;
    public get_uv(): PackedVector2Array;
    public set_color(color: Color): void;
    public get_color(): Color;
    public set_polygons(polygons: GDArray): void;
    public get_polygons(): GDArray;
    public set_vertex_colors(vertexColors: PackedColorArray): void;
    public get_vertex_colors(): PackedColorArray;
    public set_texture(texture: Texture2D): void;
    public get_texture(): Texture2D;
    public set_texture_offset(textureOffset: Vector2): void;
    public get_texture_offset(): Vector2;
    public set_texture_rotation(textureRotation: number): void;
    public get_texture_rotation(): number;
    public set_texture_scale(textureScale: Vector2): void;
    public get_texture_scale(): Vector2;
    public set_invert_enabled(invert: boolean): void;
    public get_invert_enabled(): boolean;
    public set_antialiased(antialiased: boolean): void;
    public get_antialiased(): boolean;
    public set_invert_border(invertBorder: number): void;
    public get_invert_border(): number;
    public set_offset(offset: Vector2): void;
    public get_offset(): Vector2;
    public add_bone(path: NodePath | GDString | string, weights: PackedFloat32Array): void;
    public get_bone_count(): number;
    public get_bone_path(index: number): NodePath;
    public get_bone_weights(index: number): PackedFloat32Array;
    public erase_bone(index: number): void;
    public clear_bones(): void;
    public set_bone_path(index: number, path: NodePath | GDString | string): void;
    public set_bone_weights(index: number, weights: PackedFloat32Array): void;
    public set_skeleton(skeleton: NodePath | GDString | string): void;
    public get_skeleton(): NodePath;
    public set_internal_vertex_count(internalVertexCount: number): void;
    public get_internal_vertex_count(): number;


}

