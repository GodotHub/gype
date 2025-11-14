
import type { AABB } from '@godot/builtins/aabb';
import type { Color } from '@godot/builtins/color';
import type { Curve } from '@godot/classes/curve';
import type { GeometryInstance3D } from '@godot/classes/geometry_instance3d';
import type { Gradient } from '@godot/classes/gradient';
import type { Mesh } from '@godot/classes/mesh';
import type { Node } from '@godot/classes/node';
import type { PackedColorArray } from '@godot/builtins/packed_color_array';
import type { PackedVector3Array } from '@godot/builtins/packed_vector3_array';
import type { Signal } from '@godot/builtins/signal';
import type { Vector3 } from '@godot/builtins/vector3';


export declare class CPUParticles3D extends GeometryInstance3D {

    
    /**     * The raw type is 'bool'     */
    public emitting: boolean;    
    /**     * The raw type is 'int'     */
    public amount: number;    
    /**     * The raw type is 'float'     */
    public lifetime: number;    
    /**     * The raw type is 'bool'     */
    public one_shot: boolean;    
    /**     * The raw type is 'float'     */
    public preprocess: number;    
    /**     * The raw type is 'float'     */
    public speed_scale: number;    
    /**     * The raw type is 'float'     */
    public explosiveness: number;    
    /**     * The raw type is 'float'     */
    public randomness: number;    
    /**     * The raw type is 'bool'     */
    public use_fixed_seed: boolean;    
    /**     * The raw type is 'int'     */
    public seed: number;    
    /**     * The raw type is 'float'     */
    public lifetime_randomness: number;    
    /**     * The raw type is 'int'     */
    public fixed_fps: number;    
    /**     * The raw type is 'bool'     */
    public fract_delta: boolean;    
    /**     * The raw type is 'AABB'     */
    public visibility_aabb: AABB;    
    /**     * The raw type is 'bool'     */
    public local_coords: boolean;    
    /**     * The raw type is 'int'     */
    public draw_order: number;    
    /**     * The raw type is 'Mesh'     */
    public mesh: Mesh;    
    /**     * The raw type is 'int'     */
    public emission_shape: number;    
    /**     * The raw type is 'float'     */
    public emission_sphere_radius: number;    
    /**     * The raw type is 'Vector3'     */
    public emission_box_extents: Vector3;    
    /**     * The raw type is 'PackedVector3Array'     */
    public emission_points: PackedVector3Array;    
    /**     * The raw type is 'PackedVector3Array'     */
    public emission_normals: PackedVector3Array;    
    /**     * The raw type is 'PackedColorArray'     */
    public emission_colors: PackedColorArray;    
    /**     * The raw type is 'Vector3'     */
    public emission_ring_axis: Vector3;    
    /**     * The raw type is 'float'     */
    public emission_ring_height: number;    
    /**     * The raw type is 'float'     */
    public emission_ring_radius: number;    
    /**     * The raw type is 'float'     */
    public emission_ring_inner_radius: number;    
    /**     * The raw type is 'float'     */
    public emission_ring_cone_angle: number;    
    /**     * The raw type is 'bool'     */
    public particle_flag_align_y: boolean;    
    /**     * The raw type is 'bool'     */
    public particle_flag_rotate_y: boolean;    
    /**     * The raw type is 'bool'     */
    public particle_flag_disable_z: boolean;    
    /**     * The raw type is 'Vector3'     */
    public direction: Vector3;    
    /**     * The raw type is 'float'     */
    public spread: number;    
    /**     * The raw type is 'float'     */
    public flatness: number;    
    /**     * The raw type is 'Vector3'     */
    public gravity: Vector3;    
    /**     * The raw type is 'float'     */
    public initial_velocity_min: number;    
    /**     * The raw type is 'float'     */
    public initial_velocity_max: number;    
    /**     * The raw type is 'float'     */
    public angular_velocity_min: number;    
    /**     * The raw type is 'float'     */
    public angular_velocity_max: number;    
    /**     * The raw type is 'Curve'     */
    public angular_velocity_curve: Curve;    
    /**     * The raw type is 'float'     */
    public orbit_velocity_min: number;    
    /**     * The raw type is 'float'     */
    public orbit_velocity_max: number;    
    /**     * The raw type is 'Curve'     */
    public orbit_velocity_curve: Curve;    
    /**     * The raw type is 'float'     */
    public linear_accel_min: number;    
    /**     * The raw type is 'float'     */
    public linear_accel_max: number;    
    /**     * The raw type is 'Curve'     */
    public linear_accel_curve: Curve;    
    /**     * The raw type is 'float'     */
    public radial_accel_min: number;    
    /**     * The raw type is 'float'     */
    public radial_accel_max: number;    
    /**     * The raw type is 'Curve'     */
    public radial_accel_curve: Curve;    
    /**     * The raw type is 'float'     */
    public tangential_accel_min: number;    
    /**     * The raw type is 'float'     */
    public tangential_accel_max: number;    
    /**     * The raw type is 'Curve'     */
    public tangential_accel_curve: Curve;    
    /**     * The raw type is 'float'     */
    public damping_min: number;    
    /**     * The raw type is 'float'     */
    public damping_max: number;    
    /**     * The raw type is 'Curve'     */
    public damping_curve: Curve;    
    /**     * The raw type is 'float'     */
    public angle_min: number;    
    /**     * The raw type is 'float'     */
    public angle_max: number;    
    /**     * The raw type is 'Curve'     */
    public angle_curve: Curve;    
    /**     * The raw type is 'float'     */
    public scale_amount_min: number;    
    /**     * The raw type is 'float'     */
    public scale_amount_max: number;    
    /**     * The raw type is 'Curve'     */
    public scale_amount_curve: Curve;    
    /**     * The raw type is 'bool'     */
    public split_scale: boolean;    
    /**     * The raw type is 'Curve'     */
    public scale_curve_x: Curve;    
    /**     * The raw type is 'Curve'     */
    public scale_curve_y: Curve;    
    /**     * The raw type is 'Curve'     */
    public scale_curve_z: Curve;    
    /**     * The raw type is 'Color'     */
    public color: Color;    
    /**     * The raw type is 'Gradient'     */
    public color_ramp: Gradient;    
    /**     * The raw type is 'Gradient'     */
    public color_initial_ramp: Gradient;    
    /**     * The raw type is 'float'     */
    public hue_variation_min: number;    
    /**     * The raw type is 'float'     */
    public hue_variation_max: number;    
    /**     * The raw type is 'Curve'     */
    public hue_variation_curve: Curve;    
    /**     * The raw type is 'float'     */
    public anim_speed_min: number;    
    /**     * The raw type is 'float'     */
    public anim_speed_max: number;    
    /**     * The raw type is 'Curve'     */
    public anim_speed_curve: Curve;    
    /**     * The raw type is 'float'     */
    public anim_offset_min: number;    
    /**     * The raw type is 'float'     */
    public anim_offset_max: number;    
    /**     * The raw type is 'Curve'     */
    public anim_offset_curve: Curve;
    public set_emitting(emitting: boolean): void;
    public set_amount(amount: number): void;
    public set_lifetime(secs: number): void;
    public set_one_shot(enable: boolean): void;
    public set_pre_process_time(secs: number): void;
    public set_explosiveness_ratio(ratio: number): void;
    public set_randomness_ratio(ratio: number): void;
    public set_visibility_aabb(aabb: AABB): void;
    public set_lifetime_randomness(random: number): void;
    public set_use_local_coordinates(enable: boolean): void;
    public set_fixed_fps(fps: number): void;
    public set_fractional_delta(enable: boolean): void;
    public set_speed_scale(scale: number): void;
    public is_emitting(): boolean;
    public get_amount(): number;
    public get_lifetime(): number;
    public get_one_shot(): boolean;
    public get_pre_process_time(): number;
    public get_explosiveness_ratio(): number;
    public get_randomness_ratio(): number;
    public get_visibility_aabb(): AABB;
    public get_lifetime_randomness(): number;
    public get_use_local_coordinates(): boolean;
    public get_fixed_fps(): number;
    public get_fractional_delta(): boolean;
    public get_speed_scale(): number;
    public set_draw_order(order: number): void;
    public get_draw_order(): number;
    public set_mesh(mesh: Mesh): void;
    public get_mesh(): Mesh;
    public set_use_fixed_seed(useFixedSeed: boolean): void;
    public get_use_fixed_seed(): boolean;
    public set_seed(seed: number): void;
    public get_seed(): number;
    public restart(keeseed: boolean = false): void;
    public request_particles_process(processTime: number): void;
    public capture_aabb(): AABB;
    public set_direction(direction: Vector3): void;
    public get_direction(): Vector3;
    public set_spread(degrees: number): void;
    public get_spread(): number;
    public set_flatness(amount: number): void;
    public get_flatness(): number;
    public set_param_min(param: number, value: number): void;
    public get_param_min(param: number): number;
    public set_param_max(param: number, value: number): void;
    public get_param_max(param: number): number;
    public set_param_curve(param: number, curve: Curve): void;
    public get_param_curve(param: number): Curve;
    public set_color(color: Color): void;
    public get_color(): Color;
    public set_color_ramp(ramp: Gradient): void;
    public get_color_ramp(): Gradient;
    public set_color_initial_ramp(ramp: Gradient): void;
    public get_color_initial_ramp(): Gradient;
    public set_particle_flag(particleFlag: number, enable: boolean): void;
    public get_particle_flag(particleFlag: number): boolean;
    public set_emission_shape(shape: number): void;
    public get_emission_shape(): number;
    public set_emission_sphere_radius(radius: number): void;
    public get_emission_sphere_radius(): number;
    public set_emission_box_extents(extents: Vector3): void;
    public get_emission_box_extents(): Vector3;
    public set_emission_points(array: PackedVector3Array): void;
    public get_emission_points(): PackedVector3Array;
    public set_emission_normals(array: PackedVector3Array): void;
    public get_emission_normals(): PackedVector3Array;
    public set_emission_colors(array: PackedColorArray): void;
    public get_emission_colors(): PackedColorArray;
    public set_emission_ring_axis(axis: Vector3): void;
    public get_emission_ring_axis(): Vector3;
    public set_emission_ring_height(height: number): void;
    public get_emission_ring_height(): number;
    public set_emission_ring_radius(radius: number): void;
    public get_emission_ring_radius(): number;
    public set_emission_ring_inner_radius(innerRadius: number): void;
    public get_emission_ring_inner_radius(): number;
    public set_emission_ring_cone_angle(coneAngle: number): void;
    public get_emission_ring_cone_angle(): number;
    public get_gravity(): Vector3;
    public set_gravity(accelVec: Vector3): void;
    public get_split_scale(): boolean;
    public set_split_scale(splitScale: boolean): void;
    public get_scale_curve_x(): Curve;
    public set_scale_curve_x(scaleCurve: Curve): void;
    public get_scale_curve_y(): Curve;
    public set_scale_curve_y(scaleCurve: Curve): void;
    public get_scale_curve_z(): Curve;
    public set_scale_curve_z(scaleCurve: Curve): void;
    public convert_from_particles(particles: Node): void;

    
    public readonly finished: Signal<() => void>;

    public static readonly DrawOrder: {
        DRAW_ORDER_INDEX: 0;
        DRAW_ORDER_LIFETIME: 1;
        DRAW_ORDER_VIEW_DEPTH: 2;
    };
    public static readonly Parameter: {
        PARAM_INITIAL_LINEAR_VELOCITY: 0;
        PARAM_ANGULAR_VELOCITY: 1;
        PARAM_ORBIT_VELOCITY: 2;
        PARAM_LINEAR_ACCEL: 3;
        PARAM_RADIAL_ACCEL: 4;
        PARAM_TANGENTIAL_ACCEL: 5;
        PARAM_DAMPING: 6;
        PARAM_ANGLE: 7;
        PARAM_SCALE: 8;
        PARAM_HUE_VARIATION: 9;
        PARAM_ANIM_SPEED: 10;
        PARAM_ANIM_OFFSET: 11;
        PARAM_MAX: 12;
    };
    public static readonly ParticleFlags: {
        PARTICLE_FLAG_ALIGN_Y_TO_VELOCITY: 0;
        PARTICLE_FLAG_ROTATE_Y: 1;
        PARTICLE_FLAG_DISABLE_Z: 2;
        PARTICLE_FLAG_MAX: 3;
    };
    public static readonly EmissionShape: {
        EMISSION_SHAPE_POINT: 0;
        EMISSION_SHAPE_SPHERE: 1;
        EMISSION_SHAPE_SPHERE_SURFACE: 2;
        EMISSION_SHAPE_BOX: 3;
        EMISSION_SHAPE_POINTS: 4;
        EMISSION_SHAPE_DIRECTED_POINTS: 5;
        EMISSION_SHAPE_RING: 6;
        EMISSION_SHAPE_MAX: 7;
    };
}

