
import type { Node2D } from '@godot/classes/node2d';


export declare class RemoteTransform2D extends Node2D {

    
    /**     * The raw type is 'NodePath'     */
    public remote_path: NodePath;    
    /**     * The raw type is 'bool'     */
    public use_global_coordinates: boolean;    
    /**     * The raw type is 'bool'     */
    public update_position: boolean;    
    /**     * The raw type is 'bool'     */
    public update_rotation: boolean;    
    /**     * The raw type is 'bool'     */
    public update_scale: boolean;
    public set_remote_node(path: NodePath | GDString | string): void;
    public get_remote_node(): NodePath;
    public force_update_cache(): void;
    public set_use_global_coordinates(useGlobalCoordinates: boolean): void;
    public get_use_global_coordinates(): boolean;
    public set_update_position(updateRemotePosition: boolean): void;
    public get_update_position(): boolean;
    public set_update_rotation(updateRemoteRotation: boolean): void;
    public get_update_rotation(): boolean;
    public set_update_scale(updateRemoteScale: boolean): void;
    public get_update_scale(): boolean;


}

