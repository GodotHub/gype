
import type { Image } from '@godot/classes/image';
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class CameraFeed extends RefCounted {

    
    /**     * The raw type is 'bool'     */
    public feed_is_active: boolean;    
    /**     * The raw type is 'Transform2D'     */
    public feed_transform: Transform2D;    
    /**     * The raw type is 'Array'     */
    public formats: GDArray | Array;
    public _activate_feed(): boolean;
    public _deactivate_feed(): void;
    public get_id(): number;
    public is_active(): boolean;
    public set_active(active: boolean): void;
    public get_name(): GDString;
    public set_name(name: GDString | StringName | string): void;
    public get_position(): number;
    public set_position(position: number): void;
    public get_transform(): Transform2D;
    public set_transform(transform: Transform2D): void;
    public set_rgb_image(rgbImage: Image): void;
    public set_ycbcr_image(ycbcrImage: Image): void;
    public set_external(width: number, height: number): void;
    public get_texture_tex_id(feedImageType: number): number;
    public get_datatype(): number;
    public get_formats(): GDArray;
    public set_format(index: number, parameters: Dictionary): boolean;

    
    public readonly frame_changed: Signal;
    public readonly format_changed: Signal;

    public static readonly FeedDataType: {
        FEED_NOIMAGE: 0;
        FEED_RGB: 1;
        FEED_YCBCR: 2;
        FEED_YCBCR_SEP: 3;
        FEED_EXTERNAL: 4;
    };
    public static readonly FeedPosition: {
        FEED_UNSPECIFIED: 0;
        FEED_FRONT: 1;
        FEED_BACK: 2;
    };
}

