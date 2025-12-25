
import type { CameraFeed } from '@godot/classes/camera_feed';
import type { GodotObject } from '@godot/classes/godot_object';


export declare class _CameraServer extends GodotObject {

    
    /**     * The raw type is 'bool'     */
    public monitoring_feeds: boolean;
    public set_monitoring_feeds(isMonitoringFeeds: boolean): void;
    public is_monitoring_feeds(): boolean;
    public get_feed(index: number): CameraFeed;
    public get_feed_count(): number;
    public feeds(): Array<any>;
    public add_feed(feed: CameraFeed): void;
    public remove_feed(feed: CameraFeed): void;

    
    public readonly camera_feed_added: Signal<(id: number) => void>;
    public readonly camera_feed_removed: Signal<(id: number) => void>;
    public readonly camera_feeds_updated: Signal<() => void>;

    public static readonly FeedImage: {
        FEED_RGBA_IMAGE: 0;
        FEED_YCBCR_IMAGE: 0;
        FEED_Y_IMAGE: 0;
        FEED_CBCR_IMAGE: 1;
    };
}

declare global {
    const CameraServer: _CameraServer
}
