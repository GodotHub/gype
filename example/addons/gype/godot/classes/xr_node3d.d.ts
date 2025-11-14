
import type { GDString } from '@godot/builtins/gd_string';
import type { Node3D } from '@godot/classes/node3d';
import type { Signal } from '@godot/builtins/signal';
import type { StringName } from '@godot/builtins/string_name';
import type { XRPose } from '@godot/classes/xr_pose';


export declare class XRNode3D extends Node3D {

    
    /**     * The raw type is 'String'     */
    public tracker: StringName;    
    /**     * The raw type is 'String'     */
    public pose: StringName;    
    /**     * The raw type is 'bool'     */
    public show_when_tracked: boolean;
    public set_tracker(trackerName: GDString | StringName | string): void;
    public get_tracker(): StringName;
    public set_pose_name(pose: GDString | StringName | string): void;
    public get_pose_name(): StringName;
    public set_show_when_tracked(show: boolean): void;
    public get_show_when_tracked(): boolean;
    public get_is_active(): boolean;
    public get_has_tracking_data(): boolean;
    public get_pose(): XRPose;
    public trigger_haptic_pulse(actionName: GDString | StringName | string, frequency: number, amplitude: number, durationSec: number, delaySec: number): void;

    
    public readonly tracking_changed: Signal<(tracking: boolean) => void>;

}

