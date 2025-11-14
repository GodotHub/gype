
import type { NodePath } from '@godot/builtins/node_path';
import type { Resource } from '@godot/classes/resource';


export declare class SceneReplicationConfig extends Resource {


    public get_properties(): Array<any>;
    public add_property(path: NodePath | GDString | string, index: number = -1): void;
    public has_property(path: NodePath | GDString | string): boolean;
    public remove_property(path: NodePath | GDString | string): void;
    public property_get_index(path: NodePath | GDString | string): number;
    public property_get_spawn(path: NodePath | GDString | string): boolean;
    public property_set_spawn(path: NodePath | GDString | string, enabled: boolean): void;
    public property_get_replication_mode(path: NodePath | GDString | string): number;
    public property_set_replication_mode(path: NodePath | GDString | string, mode: number): void;
    public property_get_sync(path: NodePath | GDString | string): boolean;
    public property_set_sync(path: NodePath | GDString | string, enabled: boolean): void;
    public property_get_watch(path: NodePath | GDString | string): boolean;
    public property_set_watch(path: NodePath | GDString | string, enabled: boolean): void;


    public static readonly ReplicationMode: {
        REPLICATION_MODE_NEVER: 0;
        REPLICATION_MODE_ALWAYS: 1;
        REPLICATION_MODE_ON_CHANGE: 2;
    };
}

