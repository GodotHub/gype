
import type { Mesh } from '@godot/classes/mesh';
import type { Resource } from '@godot/classes/resource';


export declare class MultiMesh extends Resource {

    
    /**     * The raw type is 'int'     */
    public transform_format: number;    
    /**     * The raw type is 'bool'     */
    public use_colors: boolean;    
    /**     * The raw type is 'bool'     */
    public use_custom_data: boolean;    
    /**     * The raw type is 'AABB'     */
    public custom_aabb: AABB;    
    /**     * The raw type is 'int'     */
    public instance_count: number;    
    /**     * The raw type is 'int'     */
    public visible_instance_count: number;    
    /**     * The raw type is 'Mesh'     */
    public mesh: Mesh;    
    /**     * The raw type is 'PackedFloat32Array'     */
    public buffer: PackedFloat32Array;    
    /**     * The raw type is 'PackedVector3Array'     */
    public transform_array: PackedVector3Array;    
    /**     * The raw type is 'PackedVector2Array'     */
    public transform_2d_array: PackedVector2Array;    
    /**     * The raw type is 'PackedColorArray'     */
    public color_array: PackedColorArray;    
    /**     * The raw type is 'PackedColorArray'     */
    public custom_data_array: PackedColorArray;    
    /**     * The raw type is 'int'     */
    public physics_interpolation_quality: number;
    public set_mesh(mesh: Mesh): void;
    public get_mesh(): Mesh;
    public set_use_colors(enable: boolean): void;
    public is_using_colors(): boolean;
    public set_use_custom_data(enable: boolean): void;
    public is_using_custom_data(): boolean;
    public set_transform_format(format: number): void;
    public get_transform_format(): number;
    public set_instance_count(count: number): void;
    public get_instance_count(): number;
    public set_visible_instance_count(count: number): void;
    public get_visible_instance_count(): number;
    public set_physics_interpolation_quality(quality: number): void;
    public get_physics_interpolation_quality(): number;
    public set_instance_transform(instance: number, transform: Transform3D): void;
    public set_instance_transform_2d(instance: number, transform: Transform2D): void;
    public get_instance_transform(instance: number): Transform3D;
    public get_instance_transform_2d(instance: number): Transform2D;
    public set_instance_color(instance: number, color: Color): void;
    public get_instance_color(instance: number): Color;
    public set_instance_custom_data(instance: number, customData: Color): void;
    public get_instance_custom_data(instance: number): Color;
    public reset_instance_physics_interpolation(instance: number): void;
    public set_custom_aabb(aabb: AABB): void;
    public get_custom_aabb(): AABB;
    public get_aabb(): AABB;
    public get_buffer(): PackedFloat32Array;
    public set_buffer(buffer: PackedFloat32Array): void;
    public set_buffer_interpolated(bufferCurr: PackedFloat32Array, bufferPrev: PackedFloat32Array): void;


    public static readonly TransformFormat: {
        TRANSFORM_2D: 0;
        TRANSFORM_3D: 1;
    };
    public static readonly PhysicsInterpolationQuality: {
        INTERP_QUALITY_FAST: 0;
        INTERP_QUALITY_HIGH: 1;
    };
}

