
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class XRTracker extends RefCounted {

    
    /**     * The raw type is 'int'     */
    public type: number;    
    /**     * The raw type is 'String'     */
    public name: GDString | StringName | string;    
    /**     * The raw type is 'String'     */
    public description: GDString | StringName | string;
    public get_tracker_type(): number;
    public set_tracker_type(_type: number): void;
    public get_tracker_name(): StringName;
    public set_tracker_name(name: GDString | StringName | string): void;
    public get_tracker_desc(): GDString;
    public set_tracker_desc(description: GDString | StringName | string): void;


}

