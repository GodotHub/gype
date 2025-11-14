
import type { Node3D } from '@godot/classes/node3d';


export declare class XROrigin3D extends Node3D {

    
    /**     * The raw type is 'float'     */
    public world_scale: number;    
    /**     * The raw type is 'bool'     */
    public current: boolean;
    public set_world_scale(worldScale: number): void;
    public get_world_scale(): number;
    public set_current(enabled: boolean): void;
    public is_current(): boolean;


}

