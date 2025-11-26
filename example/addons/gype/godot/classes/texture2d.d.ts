
import type { Image } from '@godot/classes/image';
import type { Resource } from '@godot/classes/resource';
import type { Texture } from '@godot/classes/texture';


export declare class Texture2D extends Texture {


    public _get_width(): number;
    public _get_height(): number;
    public _is_pixel_opaque(x: number, y: number): boolean;
    public _has_alpha(): boolean;
    public _draw(toCanvasItem: RID, pos: Vector2, modulate: Color, transpose: boolean): void;
    public _draw_rect(toCanvasItem: RID, rect: Rect2, tile: boolean, modulate: Color, transpose: boolean): void;
    public _draw_rect_region(toCanvasItem: RID, rect: Rect2, srcRect: Rect2, modulate: Color, transpose: boolean, cliuv: boolean): void;
    public get_width(): number;
    public get_height(): number;
    public get_size(): Vector2;
    public has_alpha(): boolean;
    public draw(canvasItem: RID, position: Vector2, modulate: Color = Color(1, 1, 1, 1), transpose: boolean = false): void;
    public draw_rect(canvasItem: RID, rect: Rect2, tile: boolean, modulate: Color = Color(1, 1, 1, 1), transpose: boolean = false): void;
    public draw_rect_region(canvasItem: RID, rect: Rect2, srcRect: Rect2, modulate: Color = Color(1, 1, 1, 1), transpose: boolean = false, cliuv: boolean = true): void;
    public get_image(): Image;
    public create_placeholder(): Resource;


}

