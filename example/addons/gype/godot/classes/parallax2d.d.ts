
import type { Node2D } from '@godot/classes/node2d';


export declare class Parallax2D extends Node2D {

    
    /**     * The raw type is 'Vector2'     */
    public scroll_scale: Vector2;    
    /**     * The raw type is 'Vector2'     */
    public scroll_offset: Vector2;    
    /**     * The raw type is 'Vector2'     */
    public repeat_size: Vector2;    
    /**     * The raw type is 'Vector2'     */
    public autoscroll: Vector2;    
    /**     * The raw type is 'int'     */
    public repeat_times: number;    
    /**     * The raw type is 'Vector2'     */
    public limit_begin: Vector2;    
    /**     * The raw type is 'Vector2'     */
    public limit_end: Vector2;    
    /**     * The raw type is 'bool'     */
    public follow_viewport: boolean;    
    /**     * The raw type is 'bool'     */
    public ignore_camera_scroll: boolean;    
    /**     * The raw type is 'Vector2'     */
    public screen_offset: Vector2;
    public set_scroll_scale(scale: Vector2): void;
    public get_scroll_scale(): Vector2;
    public set_repeat_size(repeatSize: Vector2): void;
    public get_repeat_size(): Vector2;
    public set_repeat_times(repeatTimes: number): void;
    public get_repeat_times(): number;
    public set_autoscroll(autoscroll: Vector2): void;
    public get_autoscroll(): Vector2;
    public set_scroll_offset(offset: Vector2): void;
    public get_scroll_offset(): Vector2;
    public set_screen_offset(offset: Vector2): void;
    public get_screen_offset(): Vector2;
    public set_limit_begin(offset: Vector2): void;
    public get_limit_begin(): Vector2;
    public set_limit_end(offset: Vector2): void;
    public get_limit_end(): Vector2;
    public set_follow_viewport(follow: boolean): void;
    public get_follow_viewport(): boolean;
    public set_ignore_camera_scroll(ignore: boolean): void;
    public is_ignore_camera_scroll(): boolean;


}

