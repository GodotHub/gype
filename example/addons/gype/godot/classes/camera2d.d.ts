
import type { Node } from '@godot/classes/node';
import type { Node2D } from '@godot/classes/node2d';
import type { Vector2 } from '@godot/builtins/vector2';
import type { Viewport } from '@godot/classes/viewport';


export declare class Camera2D extends Node2D {

    
    /**     * The raw type is 'Vector2'     */
    public offset: Vector2;    
    /**     * The raw type is 'int'     */
    public anchor_mode: number;    
    /**     * The raw type is 'bool'     */
    public ignore_rotation: boolean;    
    /**     * The raw type is 'bool'     */
    public enabled: boolean;    
    /**     * The raw type is 'Vector2'     */
    public zoom: Vector2;    
    /**     * The raw type is 'Viewport'     */
    public custom_viewport: Node;    
    /**     * The raw type is 'int'     */
    public process_callback: number;    
    /**     * The raw type is 'bool'     */
    public limit_enabled: boolean;    
    /**     * The raw type is 'int'     */
    public limit_left: number;    
    /**     * The raw type is 'int'     */
    public limit_top: number;    
    /**     * The raw type is 'int'     */
    public limit_right: number;    
    /**     * The raw type is 'int'     */
    public limit_bottom: number;    
    /**     * The raw type is 'bool'     */
    public limit_smoothed: boolean;    
    /**     * The raw type is 'bool'     */
    public position_smoothing_enabled: boolean;    
    /**     * The raw type is 'float'     */
    public position_smoothing_speed: number;    
    /**     * The raw type is 'bool'     */
    public rotation_smoothing_enabled: boolean;    
    /**     * The raw type is 'float'     */
    public rotation_smoothing_speed: number;    
    /**     * The raw type is 'bool'     */
    public drag_horizontal_enabled: boolean;    
    /**     * The raw type is 'bool'     */
    public drag_vertical_enabled: boolean;    
    /**     * The raw type is 'float'     */
    public drag_horizontal_offset: number;    
    /**     * The raw type is 'float'     */
    public drag_vertical_offset: number;    
    /**     * The raw type is 'float'     */
    public drag_left_margin: number;    
    /**     * The raw type is 'float'     */
    public drag_top_margin: number;    
    /**     * The raw type is 'float'     */
    public drag_right_margin: number;    
    /**     * The raw type is 'float'     */
    public drag_bottom_margin: number;    
    /**     * The raw type is 'bool'     */
    public editor_draw_screen: boolean;    
    /**     * The raw type is 'bool'     */
    public editor_draw_limits: boolean;    
    /**     * The raw type is 'bool'     */
    public editor_draw_drag_margin: boolean;
    public set_offset(offset: Vector2): void;
    public get_offset(): Vector2;
    public set_anchor_mode(anchorMode: number): void;
    public get_anchor_mode(): number;
    public set_ignore_rotation(ignore: boolean): void;
    public is_ignoring_rotation(): boolean;
    public set_process_callback(mode: number): void;
    public get_process_callback(): number;
    public set_enabled(enabled: boolean): void;
    public is_enabled(): boolean;
    public make_current(): void;
    public is_current(): boolean;
    public set_limit_enabled(limitEnabled: boolean): void;
    public is_limit_enabled(): boolean;
    public set_limit(margin: number, limit: number): void;
    public get_limit(margin: number): number;
    public set_limit_smoothing_enabled(limitSmoothingEnabled: boolean): void;
    public is_limit_smoothing_enabled(): boolean;
    public set_drag_vertical_enabled(enabled: boolean): void;
    public is_drag_vertical_enabled(): boolean;
    public set_drag_horizontal_enabled(enabled: boolean): void;
    public is_drag_horizontal_enabled(): boolean;
    public set_drag_vertical_offset(offset: number): void;
    public get_drag_vertical_offset(): number;
    public set_drag_horizontal_offset(offset: number): void;
    public get_drag_horizontal_offset(): number;
    public set_drag_margin(margin: number, dragMargin: number): void;
    public get_drag_margin(margin: number): number;
    public get_target_position(): Vector2;
    public get_screen_center_position(): Vector2;
    public get_screen_rotation(): number;
    public set_zoom(zoom: Vector2): void;
    public get_zoom(): Vector2;
    public set_custom_viewport(viewport: Node): void;
    public get_custom_viewport(): Node;
    public set_position_smoothing_speed(positionSmoothingSpeed: number): void;
    public get_position_smoothing_speed(): number;
    public set_position_smoothing_enabled(enabled: boolean): void;
    public is_position_smoothing_enabled(): boolean;
    public set_rotation_smoothing_enabled(enabled: boolean): void;
    public is_rotation_smoothing_enabled(): boolean;
    public set_rotation_smoothing_speed(speed: number): void;
    public get_rotation_smoothing_speed(): number;
    public force_update_scroll(): void;
    public reset_smoothing(): void;
    public align(): void;
    public set_screen_drawing_enabled(screenDrawingEnabled: boolean): void;
    public is_screen_drawing_enabled(): boolean;
    public set_limit_drawing_enabled(limitDrawingEnabled: boolean): void;
    public is_limit_drawing_enabled(): boolean;
    public set_margin_drawing_enabled(marginDrawingEnabled: boolean): void;
    public is_margin_drawing_enabled(): boolean;


    public static readonly AnchorMode: {
        ANCHOR_MODE_FIXED_TOP_LEFT: 0;
        ANCHOR_MODE_DRAG_CENTER: 1;
    };
    public static readonly Camera2DProcessCallback: {
        CAMERA2D_PROCESS_PHYSICS: 0;
        CAMERA2D_PROCESS_IDLE: 1;
    };
}

