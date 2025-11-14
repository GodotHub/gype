
import type { CanvasItem } from '@godot/classes/canvas_item';
import type { RID } from '@godot/builtins/rid';
import type { Rect2 } from '@godot/builtins/rect2';
import type { Resource } from '@godot/classes/resource';
import type { Vector2 } from '@godot/builtins/vector2';


export declare class StyleBox extends Resource {

    
    /**     * The raw type is 'float'     */
    public content_margin_left: number;    
    /**     * The raw type is 'float'     */
    public content_margin_top: number;    
    /**     * The raw type is 'float'     */
    public content_margin_right: number;    
    /**     * The raw type is 'float'     */
    public content_margin_bottom: number;
    public _draw(toCanvasItem: RID, rect: Rect2): void;
    public _get_draw_rect(rect: Rect2): Rect2;
    public _get_minimum_size(): Vector2;
    public _test_mask(point: Vector2, rect: Rect2): boolean;
    public get_minimum_size(): Vector2;
    public set_content_margin(margin: number, offset: number): void;
    public set_content_margin_all(offset: number): void;
    public get_content_margin(margin: number): number;
    public get_margin(margin: number): number;
    public get_offset(): Vector2;
    public draw(canvasItem: RID, rect: Rect2): void;
    public get_current_item_drawn(): CanvasItem;
    public test_mask(point: Vector2, rect: Rect2): boolean;


}

