
import type { KinematicCollision2D } from '@godot/classes/kinematic_collision2d';
import type { PhysicsBody2D } from '@godot/classes/physics_body2d';


export declare class CharacterBody2D extends PhysicsBody2D {

    
    /**     * The raw type is 'int'     */
    public motion_mode: number;    
    /**     * The raw type is 'Vector2'     */
    public up_direction: Vector2;    
    /**     * The raw type is 'Vector2'     */
    public velocity: Vector2;    
    /**     * The raw type is 'bool'     */
    public slide_on_ceiling: boolean;    
    /**     * The raw type is 'int'     */
    public max_slides: number;    
    /**     * The raw type is 'float'     */
    public wall_min_slide_angle: number;    
    /**     * The raw type is 'bool'     */
    public floor_stop_on_slope: boolean;    
    /**     * The raw type is 'bool'     */
    public floor_constant_speed: boolean;    
    /**     * The raw type is 'bool'     */
    public floor_block_on_wall: boolean;    
    /**     * The raw type is 'float'     */
    public floor_max_angle: number;    
    /**     * The raw type is 'float'     */
    public floor_snap_length: number;    
    /**     * The raw type is 'int'     */
    public platform_on_leave: number;    
    /**     * The raw type is 'int'     */
    public platform_floor_layers: number;    
    /**     * The raw type is 'int'     */
    public platform_wall_layers: number;    
    /**     * The raw type is 'float'     */
    public safe_margin: number;
    public move_and_slide(): boolean;
    public apply_floor_snap(): void;
    public set_velocity(velocity: Vector2): void;
    public get_velocity(): Vector2;
    public set_safe_margin(margin: number): void;
    public get_safe_margin(): number;
    public is_floor_stop_on_slope_enabled(): boolean;
    public set_floor_stop_on_slope_enabled(enabled: boolean): void;
    public set_floor_constant_speed_enabled(enabled: boolean): void;
    public is_floor_constant_speed_enabled(): boolean;
    public set_floor_block_on_wall_enabled(enabled: boolean): void;
    public is_floor_block_on_wall_enabled(): boolean;
    public set_slide_on_ceiling_enabled(enabled: boolean): void;
    public is_slide_on_ceiling_enabled(): boolean;
    public set_platform_floor_layers(excludeLayer: number): void;
    public get_platform_floor_layers(): number;
    public set_platform_wall_layers(excludeLayer: number): void;
    public get_platform_wall_layers(): number;
    public get_max_slides(): number;
    public set_max_slides(maxSlides: number): void;
    public get_floor_max_angle(): number;
    public set_floor_max_angle(radians: number): void;
    public get_floor_snap_length(): number;
    public set_floor_snap_length(floorSnalength: number): void;
    public get_wall_min_slide_angle(): number;
    public set_wall_min_slide_angle(radians: number): void;
    public get_up_direction(): Vector2;
    public set_up_direction(udirection: Vector2): void;
    public set_motion_mode(mode: number): void;
    public get_motion_mode(): number;
    public set_platform_on_leave(onLeaveApplyVelocity: number): void;
    public get_platform_on_leave(): number;
    public is_on_floor(): boolean;
    public is_on_floor_only(): boolean;
    public is_on_ceiling(): boolean;
    public is_on_ceiling_only(): boolean;
    public is_on_wall(): boolean;
    public is_on_wall_only(): boolean;
    public get_floor_normal(): Vector2;
    public get_wall_normal(): Vector2;
    public get_last_motion(): Vector2;
    public get_position_delta(): Vector2;
    public get_real_velocity(): Vector2;
    public get_floor_angle(udirection: Vector2 = Vector2(0, -1)): number;
    public get_platform_velocity(): Vector2;
    public get_slide_collision_count(): number;
    public get_slide_collision(slideIdx: number): KinematicCollision2D;
    public get_last_slide_collision(): KinematicCollision2D;


    public static readonly MotionMode: {
        MOTION_MODE_GROUNDED: 0;
        MOTION_MODE_FLOATING: 1;
    };
    public static readonly PlatformOnLeave: {
        PLATFORM_ON_LEAVE_ADD_VELOCITY: 0;
        PLATFORM_ON_LEAVE_ADD_UPWARD_VELOCITY: 1;
        PLATFORM_ON_LEAVE_DO_NOTHING: 2;
    };
}

