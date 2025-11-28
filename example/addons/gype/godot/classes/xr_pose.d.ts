
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class XRPose extends RefCounted {

    
    /**     * The raw type is 'bool'     */
    public has_tracking_data: boolean;    
    /**     * The raw type is 'String'     */
    public name: GDString | StringName | string;    
    /**     * The raw type is 'String'     */
    public transform: Transform3D;    
    /**     * The raw type is 'String'     */
    public linear_velocity: Vector3;    
    /**     * The raw type is 'String'     */
    public angular_velocity: Vector3;    
    /**     * The raw type is 'int'     */
    public tracking_confidence: number;
    public set_has_tracking_data(hasTrackingData: boolean): void;
    public get_has_tracking_data(): boolean;
    public set_name(name: GDString | StringName | string): void;
    public get_name(): StringName;
    public set_transform(transform: Transform3D): void;
    public get_transform(): Transform3D;
    public get_adjusted_transform(): Transform3D;
    public set_linear_velocity(velocity: Vector3): void;
    public get_linear_velocity(): Vector3;
    public set_angular_velocity(velocity: Vector3): void;
    public get_angular_velocity(): Vector3;
    public set_tracking_confidence(trackingConfidence: number): void;
    public get_tracking_confidence(): number;


    public static readonly TrackingConfidence: {
        XR_TRACKING_CONFIDENCE_NONE: 0;
        XR_TRACKING_CONFIDENCE_LOW: 1;
        XR_TRACKING_CONFIDENCE_HIGH: 2;
    };
}

