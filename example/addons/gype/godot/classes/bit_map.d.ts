
import type { Image } from '@godot/classes/image';
import type { Resource } from '@godot/classes/resource';


export declare class BitMap extends Resource {

    
    /**     * The raw type is 'Dictionary'     */
    public data: Dictionary;
    public create(size: Vector2i): void;
    public create_from_image_alpha(image: Image, threshold: number = 0.1): void;
    public set_bitv(position: Vector2i, bit: boolean): void;
    public set_bit(x: number, y: number, bit: boolean): void;
    public get_bitv(position: Vector2i): boolean;
    public get_bit(x: number, y: number): boolean;
    public set_bit_rect(rect: Rect2i, bit: boolean): void;
    public get_true_bit_count(): number;
    public get_size(): Vector2i;
    public resize(newSize: Vector2i): void;
    public grow_mask(pixels: number, rect: Rect2i): void;
    public convert_to_image(): Image;
    public opaque_to_polygons(rect: Rect2i, epsilon: number = 2.0): Array<any>;


}

