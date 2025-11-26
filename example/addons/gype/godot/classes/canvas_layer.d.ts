
import type { Node } from '@godot/classes/node';
import type { Viewport } from '@godot/classes/viewport';


export declare class CanvasLayer extends Node {

    
    /**     * The raw type is 'int'     */
    public layer: number;    
    /**     * The raw type is 'bool'     */
    public visible: boolean;    
    /**     * The raw type is 'Vector2'     */
    public offset: Vector2;    
    /**     * The raw type is 'float'     */
    public rotation: number;    
    /**     * The raw type is 'Vector2'     */
    public scale: Vector2;    
    /**     * The raw type is 'Transform2D'     */
    public transform: Transform2D;    
    /**     * The raw type is 'Viewport'     */
    public custom_viewport: Node;    
    /**     * The raw type is 'bool'     */
    public follow_viewport_enabled: boolean;    
    /**     * The raw type is 'float'     */
    public follow_viewport_scale: number;
    public set_layer(layer: number): void;
    public get_layer(): number;
    public set_visible(visible: boolean): void;
    public is_visible(): boolean;
    public show(): void;
    public hide(): void;
    public set_transform(transform: Transform2D): void;
    public get_transform(): Transform2D;
    public get_final_transform(): Transform2D;
    public set_offset(offset: Vector2): void;
    public get_offset(): Vector2;
    public set_rotation(radians: number): void;
    public get_rotation(): number;
    public set_scale(scale: Vector2): void;
    public get_scale(): Vector2;
    public set_follow_viewport(enable: boolean): void;
    public is_following_viewport(): boolean;
    public set_follow_viewport_scale(scale: number): void;
    public get_follow_viewport_scale(): number;
    public set_custom_viewport(viewport: Node): void;
    public get_custom_viewport(): Node;
    public get_canvas(): RID;

    
    public readonly visibility_changed: Signal;

}

