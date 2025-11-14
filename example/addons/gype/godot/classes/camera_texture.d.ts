
import type { Texture2D } from '@godot/classes/texture2d';


export declare class CameraTexture extends Texture2D {

    
    /**     * The raw type is 'int'     */
    public camera_feed_id: number;    
    /**     * The raw type is 'int'     */
    public which_feed: number;    
    /**     * The raw type is 'bool'     */
    public camera_is_active: boolean;
    public set_camera_feed_id(feedId: number): void;
    public get_camera_feed_id(): number;
    public set_which_feed(whichFeed: number): void;
    public get_which_feed(): number;
    public set_camera_active(active: boolean): void;
    public get_camera_active(): boolean;


}

