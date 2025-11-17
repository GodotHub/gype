
import type { Callable } from '@godot/builtins/callable';
import type { Node } from '@godot/classes/node';
import type { NodePath } from '@godot/builtins/node_path';
import type { SceneReplicationConfig } from '@godot/classes/scene_replication_config';
import type { Signal } from '@godot/builtins/signal';


export declare class MultiplayerSynchronizer extends Node {

    
    /**     * The raw type is 'NodePath'     */
    public root_path: NodePath;    
    /**     * The raw type is 'float'     */
    public replication_interval: number;    
    /**     * The raw type is 'float'     */
    public delta_interval: number;    
    /**     * The raw type is 'SceneReplicationConfig'     */
    public replication_config: SceneReplicationConfig;    
    /**     * The raw type is 'int'     */
    public visibility_update_mode: number;    
    /**     * The raw type is 'bool'     */
    public public_visibility: boolean;
    public set_root_path(path: NodePath | GDString | string): void;
    public get_root_path(): NodePath;
    public set_replication_interval(milliseconds: number): void;
    public get_replication_interval(): number;
    public set_delta_interval(milliseconds: number): void;
    public get_delta_interval(): number;
    public set_replication_config(config: SceneReplicationConfig): void;
    public get_replication_config(): SceneReplicationConfig;
    public set_visibility_update_mode(mode: number): void;
    public get_visibility_update_mode(): number;
    public update_visibility(forPeer: number = 0): void;
    public set_visibility_public(visible: boolean): void;
    public is_visibility_public(): boolean;
    public add_visibility_filter(filter: Callable | Function): void;
    public remove_visibility_filter(filter: Callable | Function): void;
    public set_visibility_for(peer: number, visible: boolean): void;
    public get_visibility_for(peer: number): boolean;

    
    public readonly synchronized: Signal<() => void>;
    public readonly delta_synchronized: Signal<() => void>;
    public readonly visibility_changed: Signal<(forPeer: number) => void>;

    public static readonly VisibilityUpdateMode: {
        VISIBILITY_PROCESS_IDLE: 0;
        VISIBILITY_PROCESS_PHYSICS: 1;
        VISIBILITY_PROCESS_NONE: 2;
    };
}

