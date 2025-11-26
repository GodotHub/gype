
import type { CanvasLayer } from '@godot/classes/canvas_layer';


export declare class ParallaxBackground extends CanvasLayer {

    
    /**     * The raw type is 'Vector2'     */
    public scroll_offset: Vector2;    
    /**     * The raw type is 'Vector2'     */
    public scroll_base_offset: Vector2;    
    /**     * The raw type is 'Vector2'     */
    public scroll_base_scale: Vector2;    
    /**     * The raw type is 'Vector2'     */
    public scroll_limit_begin: Vector2;    
    /**     * The raw type is 'Vector2'     */
    public scroll_limit_end: Vector2;    
    /**     * The raw type is 'bool'     */
    public scroll_ignore_camera_zoom: boolean;
    public set_scroll_offset(offset: Vector2): void;
    public get_scroll_offset(): Vector2;
    public set_scroll_base_offset(offset: Vector2): void;
    public get_scroll_base_offset(): Vector2;
    public set_scroll_base_scale(scale: Vector2): void;
    public get_scroll_base_scale(): Vector2;
    public set_limit_begin(offset: Vector2): void;
    public get_limit_begin(): Vector2;
    public set_limit_end(offset: Vector2): void;
    public get_limit_end(): Vector2;
    public set_ignore_camera_zoom(ignore: boolean): void;
    public is_ignore_camera_zoom(): boolean;


}

