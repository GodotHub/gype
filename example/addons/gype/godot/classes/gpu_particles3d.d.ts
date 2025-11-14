
import type { AABB } from '@godot/builtins/aabb';
import type { Color } from '@godot/builtins/color';
import type { GeometryInstance3D } from '@godot/classes/geometry_instance3d';
import type { Material } from '@godot/classes/material';
import type { Mesh } from '@godot/classes/mesh';
import type { Node } from '@godot/classes/node';
import type { NodePath } from '@godot/builtins/node_path';
import type { ParticleProcessMaterial } from '@godot/classes/particle_process_material';
import type { Signal } from '@godot/builtins/signal';
import type { Skin } from '@godot/classes/skin';
import type { Transform3D } from '@godot/builtins/transform3d';
import type { Vector3 } from '@godot/builtins/vector3';


export declare class GPUParticles3D extends GeometryInstance3D {

    
    /**     * The raw type is 'bool'     */
    public emitting: boolean;    
    /**     * The raw type is 'int'     */
    public amount: number;    
    /**     * The raw type is 'float'     */
    public amount_ratio: number;    
    /**     * The raw type is 'NodePath'     */
    public sub_emitter: NodePath;    
    /**     * The raw type is 'float'     */
    public lifetime: number;    
    /**     * The raw type is 'float'     */
    public interp_to_end: number;    
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
    /**     * The raw type is 'int'     */
    public fixed_fps: number;    
    /**     * The raw type is 'bool'     */
    public interpolate: boolean;    
    /**     * The raw type is 'bool'     */
    public fract_delta: boolean;    
    /**     * The raw type is 'float'     */
    public collision_base_size: number;    
    /**     * The raw type is 'AABB'     */
    public visibility_aabb: AABB;    
    /**     * The raw type is 'bool'     */
    public local_coords: boolean;    
    /**     * The raw type is 'int'     */
    public draw_order: number;    
    /**     * The raw type is 'int'     */
    public transform_align: number;    
    /**     * The raw type is 'bool'     */
    public trail_enabled: boolean;    
    /**     * The raw type is 'float'     */
    public trail_lifetime: number;    
    /**     * The raw type is 'ParticleProcessMaterial,ShaderMaterial'     */
    public process_material: Material;    
    /**     * The raw type is 'int'     */
    public draw_passes: number;    
    /**     * The raw type is 'Mesh'     */
    public draw_pass_1: Mesh;    
    /**     * The raw type is 'Mesh'     */
    public draw_pass_2: Mesh;    
    /**     * The raw type is 'Mesh'     */
    public draw_pass_3: Mesh;    
    /**     * The raw type is 'Mesh'     */
    public draw_pass_4: Mesh;    
    /**     * The raw type is 'Skin'     */
    public draw_skin: Skin;
    public set_emitting(emitting: boolean): void;
    public set_amount(amount: number): void;
    public set_lifetime(secs: number): void;
    public set_one_shot(enable: boolean): void;
    public set_pre_process_time(secs: number): void;
    public set_explosiveness_ratio(ratio: number): void;
    public set_randomness_ratio(ratio: number): void;
    public set_visibility_aabb(aabb: AABB): void;
    public set_use_local_coordinates(enable: boolean): void;
    public set_fixed_fps(fps: number): void;
    public set_fractional_delta(enable: boolean): void;
    public set_interpolate(enable: boolean): void;
    public set_process_material(material: Material): void;
    public set_speed_scale(scale: number): void;
    public set_collision_base_size(size: number): void;
    public set_interp_to_end(interp: number): void;
    public is_emitting(): boolean;
    public get_amount(): number;
    public get_lifetime(): number;
    public get_one_shot(): boolean;
    public get_pre_process_time(): number;
    public get_explosiveness_ratio(): number;
    public get_randomness_ratio(): number;
    public get_visibility_aabb(): AABB;
    public get_use_local_coordinates(): boolean;
    public get_fixed_fps(): number;
    public get_fractional_delta(): boolean;
    public get_interpolate(): boolean;
    public get_process_material(): Material;
    public get_speed_scale(): number;
    public get_collision_base_size(): number;
    public get_interp_to_end(): number;
    public set_use_fixed_seed(useFixedSeed: boolean): void;
    public get_use_fixed_seed(): boolean;
    public set_seed(seed: number): void;
    public get_seed(): number;
    public set_draw_order(order: number): void;
    public get_draw_order(): number;
    public set_draw_passes(passes: number): void;
    public set_draw_pass_mesh(pass: number, mesh: Mesh): void;
    public get_draw_passes(): number;
    public get_draw_pass_mesh(pass: number): Mesh;
    public set_skin(skin: Skin): void;
    public get_skin(): Skin;
    public restart(keeseed: boolean = false): void;
    public capture_aabb(): AABB;
    public set_sub_emitter(path: NodePath | GDString | string): void;
    public get_sub_emitter(): NodePath;
    public emit_particle(xform: Transform3D, velocity: Vector3, color: Color, custom: Color, flags: number): void;
    public set_trail_enabled(enabled: boolean): void;
    public set_trail_lifetime(secs: number): void;
    public is_trail_enabled(): boolean;
    public get_trail_lifetime(): number;
    public set_transform_align(align: number): void;
    public get_transform_align(): number;
    public convert_from_particles(particles: Node): void;
    public set_amount_ratio(ratio: number): void;
    public get_amount_ratio(): number;
    public request_particles_process(processTime: number): void;

    
    public readonly finished: Signal<() => void>;

    public static readonly DrawOrder: {
        DRAW_ORDER_INDEX: 0;
        DRAW_ORDER_LIFETIME: 1;
        DRAW_ORDER_REVERSE_LIFETIME: 2;
        DRAW_ORDER_VIEW_DEPTH: 3;
    };
    public static readonly EmitFlags: {
        EMIT_FLAG_POSITION: 1;
        EMIT_FLAG_ROTATION_SCALE: 2;
        EMIT_FLAG_VELOCITY: 4;
        EMIT_FLAG_COLOR: 8;
        EMIT_FLAG_CUSTOM: 16;
    };
    public static readonly TransformAlign: {
        TRANSFORM_ALIGN_DISABLED: 0;
        TRANSFORM_ALIGN_Z_BILLBOARD: 1;
        TRANSFORM_ALIGN_Y_TO_VELOCITY: 2;
        TRANSFORM_ALIGN_Z_BILLBOARD_Y_TO_VELOCITY: 3;
    };
}

