
import type { Callable } from '@godot/builtins/callable';
import type { GDString } from '@godot/builtins/gd_string';
import type { Node } from '@godot/classes/node';
import type { NodePath } from '@godot/builtins/node_path';
import type { Signal } from '@godot/builtins/signal';


export declare class MultiplayerSpawner extends Node {

    
    /**     * The raw type is 'NodePath'     */
    public spawn_path: NodePath;    
    /**     * The raw type is 'int'     */
    public spawn_limit: number;    
    /**     * The raw type is 'Callable'     */
    public spawn_function: Callable;
    public add_spawnable_scene(path: GDString | StringName | string): void;
    public get_spawnable_scene_count(): number;
    public get_spawnable_scene(index: number): GDString;
    public clear_spawnable_scenes(): void;
    public spawn(data: any = null): Node;
    public get_spawn_path(): NodePath;
    public set_spawn_path(path: NodePath | GDString | string): void;
    public get_spawn_limit(): number;
    public set_spawn_limit(limit: number): void;
    public get_spawn_function(): Callable;
    public set_spawn_function(spawnFunction: Callable): void;

    
    public readonly despawned: Signal<(node: Node) => void>;
    public readonly spawned: Signal<(node: Node) => void>;

}

