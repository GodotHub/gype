
import type { Color } from '@godot/builtins/color';
import type { CurveTexture } from '@godot/classes/curve_texture';
import type { CurveXYZTexture } from '@godot/classes/curve_xyz_texture';
import type { GradientTexture1D } from '@godot/classes/gradient_texture1_d';
import type { Material } from '@godot/classes/material';
import type { Signal } from '@godot/builtins/signal';
import type { Texture2D } from '@godot/classes/texture2d';
import type { Vector2 } from '@godot/builtins/vector2';
import type { Vector3 } from '@godot/builtins/vector3';


export declare class ParticleProcessMaterial extends Material {

    
    /**     * The raw type is 'float'     */
    public lifetime_randomness: number;    
    /**     * The raw type is 'bool'     */
    public particle_flag_align_y: boolean;    
    /**     * The raw type is 'bool'     */
    public particle_flag_rotate_y: boolean;    
    /**     * The raw type is 'bool'     */
    public particle_flag_disable_z: boolean;    
    /**     * The raw type is 'bool'     */
    public particle_flag_damping_as_friction: boolean;    
    /**     * The raw type is 'Vector3'     */
    public emission_shape_offset: Vector3;    
    /**     * The raw type is 'Vector3'     */
    public emission_shape_scale: Vector3;    
    /**     * The raw type is 'int'     */
    public emission_shape: number;    
    /**     * The raw type is 'float'     */
    public emission_sphere_radius: number;    
    /**     * The raw type is 'Vector3'     */
    public emission_box_extents: Vector3;    
    /**     * The raw type is 'Texture2D'     */
    public emission_point_texture: Texture2D;    
    /**     * The raw type is 'Texture2D'     */
    public emission_normal_texture: Texture2D;    
    /**     * The raw type is 'Texture2D'     */
    public emission_color_texture: Texture2D;    
    /**     * The raw type is 'int'     */
    public emission_point_count: number;    
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
    /**     * The raw type is 'Vector2'     */
    public angle: Vector2;    
    /**     * The raw type is 'float'     */
    public angle_min: number;    
    /**     * The raw type is 'float'     */
    public angle_max: number;    
    /**     * The raw type is 'CurveTexture'     */
    public angle_curve: CurveTexture;    
    /**     * The raw type is 'float'     */
    public inherit_velocity_ratio: number;    
    /**     * The raw type is 'Vector3'     */
    public velocity_pivot: Vector3;    
    /**     * The raw type is 'Vector3'     */
    public direction: Vector3;    
    /**     * The raw type is 'float'     */
    public spread: number;    
    /**     * The raw type is 'float'     */
    public flatness: number;    
    /**     * The raw type is 'Vector2'     */
    public initial_velocity: Vector2;    
    /**     * The raw type is 'float'     */
    public initial_velocity_min: number;    
    /**     * The raw type is 'float'     */
    public initial_velocity_max: number;    
    /**     * The raw type is 'Vector2'     */
    public angular_velocity: Vector2;    
    /**     * The raw type is 'float'     */
    public angular_velocity_min: number;    
    /**     * The raw type is 'float'     */
    public angular_velocity_max: number;    
    /**     * The raw type is 'CurveTexture'     */
    public angular_velocity_curve: CurveTexture;    
    /**     * The raw type is 'Vector2'     */
    public directional_velocity: Vector2;    
    /**     * The raw type is 'float'     */
    public directional_velocity_min: number;    
    /**     * The raw type is 'float'     */
    public directional_velocity_max: number;    
    /**     * The raw type is 'CurveXYZTexture'     */
    public directional_velocity_curve: CurveXYZTexture;    
    /**     * The raw type is 'Vector2'     */
    public orbit_velocity: Vector2;    
    /**     * The raw type is 'float'     */
    public orbit_velocity_min: number;    
    /**     * The raw type is 'float'     */
    public orbit_velocity_max: number;    
    /**     * The raw type is 'CurveTexture,CurveXYZTexture'     */
    public orbit_velocity_curve: CurveTexture;    
    /**     * The raw type is 'Vector2'     */
    public radial_velocity: Vector2;    
    /**     * The raw type is 'float'     */
    public radial_velocity_min: number;    
    /**     * The raw type is 'float'     */
    public radial_velocity_max: number;    
    /**     * The raw type is 'CurveTexture'     */
    public radial_velocity_curve: CurveTexture;    
    /**     * The raw type is 'CurveTexture'     */
    public velocity_limit_curve: Texture2D;    
    /**     * The raw type is 'Vector3'     */
    public gravity: Vector3;    
    /**     * The raw type is 'Vector2'     */
    public linear_accel: Vector2;    
    /**     * The raw type is 'float'     */
    public linear_accel_min: number;    
    /**     * The raw type is 'float'     */
    public linear_accel_max: number;    
    /**     * The raw type is 'CurveTexture'     */
    public linear_accel_curve: CurveTexture;    
    /**     * The raw type is 'Vector2'     */
    public radial_accel: Vector2;    
    /**     * The raw type is 'float'     */
    public radial_accel_min: number;    
    /**     * The raw type is 'float'     */
    public radial_accel_max: number;    
    /**     * The raw type is 'CurveTexture'     */
    public radial_accel_curve: CurveTexture;    
    /**     * The raw type is 'Vector2'     */
    public tangential_accel: Vector2;    
    /**     * The raw type is 'float'     */
    public tangential_accel_min: number;    
    /**     * The raw type is 'float'     */
    public tangential_accel_max: number;    
    /**     * The raw type is 'CurveTexture'     */
    public tangential_accel_curve: CurveTexture;    
    /**     * The raw type is 'Vector2'     */
    public damping: Vector2;    
    /**     * The raw type is 'float'     */
    public damping_min: number;    
    /**     * The raw type is 'float'     */
    public damping_max: number;    
    /**     * The raw type is 'CurveTexture'     */
    public damping_curve: CurveTexture;    
    /**     * The raw type is 'bool'     */
    public attractor_interaction_enabled: boolean;    
    /**     * The raw type is 'Vector2'     */
    public scale: Vector2;    
    /**     * The raw type is 'float'     */
    public scale_min: number;    
    /**     * The raw type is 'float'     */
    public scale_max: number;    
    /**     * The raw type is 'CurveTexture,CurveXYZTexture'     */
    public scale_curve: CurveTexture;    
    /**     * The raw type is 'Vector2'     */
    public scale_over_velocity: Vector2;    
    /**     * The raw type is 'float'     */
    public scale_over_velocity_min: number;    
    /**     * The raw type is 'float'     */
    public scale_over_velocity_max: number;    
    /**     * The raw type is 'CurveTexture,CurveXYZTexture'     */
    public scale_over_velocity_curve: CurveTexture;    
    /**     * The raw type is 'Color'     */
    public color: Color;    
    /**     * The raw type is 'GradientTexture1D'     */
    public color_ramp: Texture2D;    
    /**     * The raw type is 'GradientTexture1D'     */
    public color_initial_ramp: Texture2D;    
    /**     * The raw type is 'CurveTexture'     */
    public alpha_curve: Texture2D;    
    /**     * The raw type is 'CurveTexture'     */
    public emission_curve: Texture2D;    
    /**     * The raw type is 'Vector2'     */
    public hue_variation: Vector2;    
    /**     * The raw type is 'float'     */
    public hue_variation_min: number;    
    /**     * The raw type is 'float'     */
    public hue_variation_max: number;    
    /**     * The raw type is 'CurveTexture'     */
    public hue_variation_curve: CurveTexture;    
    /**     * The raw type is 'Vector2'     */
    public anim_speed: Vector2;    
    /**     * The raw type is 'float'     */
    public anim_speed_min: number;    
    /**     * The raw type is 'float'     */
    public anim_speed_max: number;    
    /**     * The raw type is 'CurveTexture'     */
    public anim_speed_curve: CurveTexture;    
    /**     * The raw type is 'Vector2'     */
    public anim_offset: Vector2;    
    /**     * The raw type is 'float'     */
    public anim_offset_min: number;    
    /**     * The raw type is 'float'     */
    public anim_offset_max: number;    
    /**     * The raw type is 'CurveTexture'     */
    public anim_offset_curve: CurveTexture;    
    /**     * The raw type is 'bool'     */
    public turbulence_enabled: boolean;    
    /**     * The raw type is 'float'     */
    public turbulence_noise_strength: number;    
    /**     * The raw type is 'float'     */
    public turbulence_noise_scale: number;    
    /**     * The raw type is 'Vector3'     */
    public turbulence_noise_speed: Vector3;    
    /**     * The raw type is 'float'     */
    public turbulence_noise_speed_random: number;    
    /**     * The raw type is 'Vector2'     */
    public turbulence_influence: Vector2;    
    /**     * The raw type is 'float'     */
    public turbulence_influence_min: number;    
    /**     * The raw type is 'float'     */
    public turbulence_influence_max: number;    
    /**     * The raw type is 'Vector2'     */
    public turbulence_initial_displacement: Vector2;    
    /**     * The raw type is 'float'     */
    public turbulence_initial_displacement_min: number;    
    /**     * The raw type is 'float'     */
    public turbulence_initial_displacement_max: number;    
    /**     * The raw type is 'CurveTexture'     */
    public turbulence_influence_over_life: CurveTexture;    
    /**     * The raw type is 'int'     */
    public collision_mode: number;    
    /**     * The raw type is 'float'     */
    public collision_friction: number;    
    /**     * The raw type is 'float'     */
    public collision_bounce: number;    
    /**     * The raw type is 'bool'     */
    public collision_use_scale: boolean;    
    /**     * The raw type is 'int'     */
    public sub_emitter_mode: number;    
    /**     * The raw type is 'float'     */
    public sub_emitter_frequency: number;    
    /**     * The raw type is 'int'     */
    public sub_emitter_amount_at_end: number;    
    /**     * The raw type is 'int'     */
    public sub_emitter_amount_at_collision: number;    
    /**     * The raw type is 'int'     */
    public sub_emitter_amount_at_start: number;    
    /**     * The raw type is 'bool'     */
    public sub_emitter_keep_velocity: boolean;
    public set_direction(degrees: Vector3): void;
    public get_direction(): Vector3;
    public set_inherit_velocity_ratio(ratio: number): void;
    public get_inherit_velocity_ratio(): number;
    public set_spread(degrees: number): void;
    public get_spread(): number;
    public set_flatness(amount: number): void;
    public get_flatness(): number;
    public set_param(param: number, value: Vector2): void;
    public get_param(param: number): Vector2;
    public set_param_min(param: number, value: number): void;
    public get_param_min(param: number): number;
    public set_param_max(param: number, value: number): void;
    public get_param_max(param: number): number;
    public set_param_texture(param: number, texture: Texture2D): void;
    public get_param_texture(param: number): Texture2D;
    public set_color(color: Color): void;
    public get_color(): Color;
    public set_color_ramp(ramp: Texture2D): void;
    public get_color_ramp(): Texture2D;
    public set_alpha_curve(curve: Texture2D): void;
    public get_alpha_curve(): Texture2D;
    public set_emission_curve(curve: Texture2D): void;
    public get_emission_curve(): Texture2D;
    public set_color_initial_ramp(ramp: Texture2D): void;
    public get_color_initial_ramp(): Texture2D;
    public set_velocity_limit_curve(curve: Texture2D): void;
    public get_velocity_limit_curve(): Texture2D;
    public set_particle_flag(particleFlag: number, enable: boolean): void;
    public get_particle_flag(particleFlag: number): boolean;
    public set_velocity_pivot(pivot: Vector3): void;
    public get_velocity_pivot(): Vector3;
    public set_emission_shape(shape: number): void;
    public get_emission_shape(): number;
    public set_emission_sphere_radius(radius: number): void;
    public get_emission_sphere_radius(): number;
    public set_emission_box_extents(extents: Vector3): void;
    public get_emission_box_extents(): Vector3;
    public set_emission_point_texture(texture: Texture2D): void;
    public get_emission_point_texture(): Texture2D;
    public set_emission_normal_texture(texture: Texture2D): void;
    public get_emission_normal_texture(): Texture2D;
    public set_emission_color_texture(texture: Texture2D): void;
    public get_emission_color_texture(): Texture2D;
    public set_emission_point_count(pointCount: number): void;
    public get_emission_point_count(): number;
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
    public set_emission_shape_offset(emissionShapeOffset: Vector3): void;
    public get_emission_shape_offset(): Vector3;
    public set_emission_shape_scale(emissionShapeScale: Vector3): void;
    public get_emission_shape_scale(): Vector3;
    public get_turbulence_enabled(): boolean;
    public set_turbulence_enabled(turbulenceEnabled: boolean): void;
    public get_turbulence_noise_strength(): number;
    public set_turbulence_noise_strength(turbulenceNoiseStrength: number): void;
    public get_turbulence_noise_scale(): number;
    public set_turbulence_noise_scale(turbulenceNoiseScale: number): void;
    public get_turbulence_noise_speed_random(): number;
    public set_turbulence_noise_speed_random(turbulenceNoiseSpeedRandom: number): void;
    public get_turbulence_noise_speed(): Vector3;
    public set_turbulence_noise_speed(turbulenceNoiseSpeed: Vector3): void;
    public get_gravity(): Vector3;
    public set_gravity(accelVec: Vector3): void;
    public set_lifetime_randomness(randomness: number): void;
    public get_lifetime_randomness(): number;
    public get_sub_emitter_mode(): number;
    public set_sub_emitter_mode(mode: number): void;
    public get_sub_emitter_frequency(): number;
    public set_sub_emitter_frequency(hz: number): void;
    public get_sub_emitter_amount_at_end(): number;
    public set_sub_emitter_amount_at_end(amount: number): void;
    public get_sub_emitter_amount_at_collision(): number;
    public set_sub_emitter_amount_at_collision(amount: number): void;
    public get_sub_emitter_amount_at_start(): number;
    public set_sub_emitter_amount_at_start(amount: number): void;
    public get_sub_emitter_keep_velocity(): boolean;
    public set_sub_emitter_keep_velocity(enable: boolean): void;
    public set_attractor_interaction_enabled(enabled: boolean): void;
    public is_attractor_interaction_enabled(): boolean;
    public set_collision_mode(mode: number): void;
    public get_collision_mode(): number;
    public set_collision_use_scale(radius: boolean): void;
    public is_collision_using_scale(): boolean;
    public set_collision_friction(friction: number): void;
    public get_collision_friction(): number;
    public set_collision_bounce(bounce: number): void;
    public get_collision_bounce(): number;

    
    public readonly emission_shape_changed: Signal<() => void>;

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
        PARAM_RADIAL_VELOCITY: 15;
        PARAM_DIRECTIONAL_VELOCITY: 16;
        PARAM_SCALE_OVER_VELOCITY: 17;
        PARAM_MAX: 18;
        PARAM_TURB_VEL_INFLUENCE: 13;
        PARAM_TURB_INIT_DISPLACEMENT: 14;
        PARAM_TURB_INFLUENCE_OVER_LIFE: 12;
    };
    public static readonly ParticleFlags: {
        PARTICLE_FLAG_ALIGN_Y_TO_VELOCITY: 0;
        PARTICLE_FLAG_ROTATE_Y: 1;
        PARTICLE_FLAG_DISABLE_Z: 2;
        PARTICLE_FLAG_DAMPING_AS_FRICTION: 3;
        PARTICLE_FLAG_MAX: 4;
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
    public static readonly SubEmitterMode: {
        SUB_EMITTER_DISABLED: 0;
        SUB_EMITTER_CONSTANT: 1;
        SUB_EMITTER_AT_END: 2;
        SUB_EMITTER_AT_COLLISION: 3;
        SUB_EMITTER_AT_START: 4;
        SUB_EMITTER_MAX: 5;
    };
    public static readonly CollisionMode: {
        COLLISION_DISABLED: 0;
        COLLISION_RIGID: 1;
        COLLISION_HIDE_ON_CONTACT: 2;
        COLLISION_MAX: 3;
    };
}

