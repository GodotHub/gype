
import type { CameraFeed } from '@godot/classes/camera_feed';
import type { GodotObject } from '@godot/classes/godot_object';


export declare class CameraServer extends GodotObject {

    
    /**     * The raw type is 'bool'     */
    public monitoring_feeds: boolean;
    public set_monitoring_feeds(isMonitoringFeeds: boolean): void;
    public is_monitoring_feeds(): boolean;
    public get_feed(index: number): CameraFeed;
    public get_feed_count(): number;
    public feeds(): Array<any>;
    public add_feed(feed: CameraFeed): void;
    public remove_feed(feed: CameraFeed): void;

    
    public readonly camera_feed_added: Signal;
    public readonly camera_feed_removed: Signal;
    public readonly camera_feeds_updated: Signal;

    public static readonly FeedImage: {
        FEED_RGBA_IMAGE: 0;
        FEED_YCBCR_IMAGE: 0;
        FEED_Y_IMAGE: 0;
        FEED_CBCR_IMAGE: 1;
    };
}


/**
 * A singleton instance of CameraServer.
 * This is a global variable, available from anywhere.
 */
export const CameraServer: CameraServer;
