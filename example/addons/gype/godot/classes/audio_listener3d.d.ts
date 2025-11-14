
import type { Node3D } from '@godot/classes/node3d';
import type { Transform3D } from '@godot/builtins/transform3d';


export declare class AudioListener3D extends Node3D {

    
    /**     * The raw type is 'int'     */
    public doppler_tracking: number;
    public make_current(): void;
    public clear_current(): void;
    public is_current(): boolean;
    public get_listener_transform(): Transform3D;
    public set_doppler_tracking(mode: number): void;
    public get_doppler_tracking(): number;


    public static readonly DopplerTracking: {
        DOPPLER_TRACKING_DISABLED: 0;
        DOPPLER_TRACKING_IDLE_STEP: 1;
        DOPPLER_TRACKING_PHYSICS_STEP: 2;
    };
}

