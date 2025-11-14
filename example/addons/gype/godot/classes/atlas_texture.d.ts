
import type { Rect2 } from '@godot/builtins/rect2';
import type { Texture2D } from '@godot/classes/texture2d';


export declare class AtlasTexture extends Texture2D {

    
    /**     * The raw type is 'Texture2D'     */
    public atlas: Texture2D;    
    /**     * The raw type is 'Rect2'     */
    public region: Rect2;    
    /**     * The raw type is 'Rect2'     */
    public margin: Rect2;    
    /**     * The raw type is 'bool'     */
    public filter_clip: boolean;
    public set_atlas(atlas: Texture2D): void;
    public get_atlas(): Texture2D;
    public set_region(region: Rect2): void;
    public get_region(): Rect2;
    public set_margin(margin: Rect2): void;
    public get_margin(): Rect2;
    public set_filter_clip(enable: boolean): void;
    public has_filter_clip(): boolean;


}

