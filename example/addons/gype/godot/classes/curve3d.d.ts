
import type { Resource } from '@godot/classes/resource';


export declare class Curve3D extends Resource {

    
    /**     * The raw type is 'bool'     */
    public closed: boolean;    
    /**     * The raw type is 'float'     */
    public bake_interval: number;    
    /**     * The raw type is 'int'     */
    public point_count: number;    
    /**     * The raw type is 'bool'     */
    public up_vector_enabled: boolean;
    public get_point_count(): number;
    public set_point_count(count: number): void;
    public add_point(position: Vector3, _in: Vector3 = Vector3(0, 0, 0), out: Vector3 = Vector3(0, 0, 0), index: number = -1): void;
    public set_point_position(idx: number, position: Vector3): void;
    public get_point_position(idx: number): Vector3;
    public set_point_tilt(idx: number, tilt: number): void;
    public get_point_tilt(idx: number): number;
    public set_point_in(idx: number, position: Vector3): void;
    public get_point_in(idx: number): Vector3;
    public set_point_out(idx: number, position: Vector3): void;
    public get_point_out(idx: number): Vector3;
    public remove_point(idx: number): void;
    public clear_points(): void;
    public sample(idx: number, t: number): Vector3;
    public samplef(fofs: number): Vector3;
    public set_closed(closed: boolean): void;
    public is_closed(): boolean;
    public set_bake_interval(distance: number): void;
    public get_bake_interval(): number;
    public set_up_vector_enabled(enable: boolean): void;
    public is_up_vector_enabled(): boolean;
    public get_baked_length(): number;
    public sample_baked(offset: number = 0.0, cubic: boolean = false): Vector3;
    public sample_baked_with_rotation(offset: number = 0.0, cubic: boolean = false, applyTilt: boolean = false): Transform3D;
    public sample_baked_up_vector(offset: number, applyTilt: boolean = false): Vector3;
    public get_baked_points(): PackedVector3Array;
    public get_baked_tilts(): PackedFloat32Array;
    public get_baked_up_vectors(): PackedVector3Array;
    public get_closest_point(toPoint: Vector3): Vector3;
    public get_closest_offset(toPoint: Vector3): number;
    public tessellate(maxStages: number = 5, toleranceDegrees: number = 4): PackedVector3Array;
    public tessellate_even_length(maxStages: number = 5, toleranceLength: number = 0.2): PackedVector3Array;


}

