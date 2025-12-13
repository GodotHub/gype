
import type { GodotObject } from '@godot/classes/godot_object';
import type { XRInterface } from '@godot/classes/xr_interface';
import type { XRTracker } from '@godot/classes/xr_tracker';


export declare class XRServer extends GodotObject {

    
    /**     * The raw type is 'float'     */
    public world_scale: number;    
    /**     * The raw type is 'Vector3'     */
    public world_origin: Transform3D;    
    /**     * The raw type is 'bool'     */
    public camera_locked_to_origin: boolean;    
    /**     * The raw type is 'Object'     */
    public primary_interface: XRInterface;
    public get_world_scale(): number;
    public set_world_scale(scale: number): void;
    public get_world_origin(): Transform3D;
    public set_world_origin(worldOrigin: Transform3D): void;
    public get_reference_frame(): Transform3D;
    public clear_reference_frame(): void;
    public center_on_hmd(rotationMode: number, keeheight: boolean): void;
    public get_hmd_transform(): Transform3D;
    public set_camera_locked_to_origin(enabled: boolean): void;
    public is_camera_locked_to_origin(): boolean;
    public add_interface(_interface: XRInterface): void;
    public get_interface_count(): number;
    public remove_interface(_interface: XRInterface): void;
    public get_interface(idx: number): XRInterface;
    public get_interfaces(): Array<any>;
    public find_interface(name: GDString | StringName | string): XRInterface;
    public add_tracker(tracker: XRTracker): void;
    public remove_tracker(tracker: XRTracker): void;
    public get_trackers(trackerTypes: number): Dictionary;
    public get_tracker(trackerName: GDString | StringName | string): XRTracker;
    public get_primary_interface(): XRInterface;
    public set_primary_interface(_interface: XRInterface): void;

    
    public readonly reference_frame_changed: Signal<() => void>;
    public readonly interface_added: Signal<(interfaceName: GDString | StringName | string) => void>;
    public readonly interface_removed: Signal<(interfaceName: GDString | StringName | string) => void>;
    public readonly tracker_added: Signal<(trackerName: GDString | StringName | string, _type: number) => void>;
    public readonly tracker_updated: Signal<(trackerName: GDString | StringName | string, _type: number) => void>;
    public readonly tracker_removed: Signal<(trackerName: GDString | StringName | string, _type: number) => void>;

    public static readonly TrackerType: {
        TRACKER_HEAD: 1;
        TRACKER_CONTROLLER: 2;
        TRACKER_BASESTATION: 4;
        TRACKER_ANCHOR: 8;
        TRACKER_HAND: 16;
        TRACKER_BODY: 32;
        TRACKER_FACE: 64;
        TRACKER_ANY_KNOWN: 127;
        TRACKER_UNKNOWN: 128;
        TRACKER_ANY: 255;
    };
    public static readonly RotationMode: {
        RESET_FULL_ROTATION: 0;
        RESET_BUT_KEEP_TILT: 1;
        DONT_RESET_ROTATION: 2;
    };
}


/**
 * A singleton instance of XRServer.
 * This is a global variable, available from anywhere.
 */
export const XRServer: XRServer;
