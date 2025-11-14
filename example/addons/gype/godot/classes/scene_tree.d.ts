
import type { GDString } from '@godot/builtins/gd_string';
import type { GodotObject } from '@godot/classes/godot_object';
import type { MainLoop } from '@godot/classes/main_loop';
import type { MultiplayerAPI } from '@godot/classes/multiplayer_api';
import type { Node } from '@godot/classes/node';
import type { NodePath } from '@godot/builtins/node_path';
import type { PackedScene } from '@godot/classes/packed_scene';
import type { SceneTreeTimer } from '@godot/classes/scene_tree_timer';
import type { Signal } from '@godot/builtins/signal';
import type { StringName } from '@godot/builtins/string_name';
import type { Tween } from '@godot/classes/tween';
import type { Window } from '@godot/classes/window';


export declare class SceneTree extends MainLoop {

    
    /**     * The raw type is 'bool'     */
    public auto_accept_quit: boolean;    
    /**     * The raw type is 'bool'     */
    public quit_on_go_back: boolean;    
    /**     * The raw type is 'bool'     */
    public debug_collisions_hint: boolean;    
    /**     * The raw type is 'bool'     */
    public debug_paths_hint: boolean;    
    /**     * The raw type is 'bool'     */
    public debug_navigation_hint: boolean;    
    /**     * The raw type is 'bool'     */
    public paused: boolean;    
    /**     * The raw type is 'Node'     */
    public edited_scene_root: Node;    
    /**     * The raw type is 'Node'     */
    public current_scene: Node;    
    /**     * The raw type is 'Node'     */
    public root: Node;    
    /**     * The raw type is 'bool'     */
    public multiplayer_poll: boolean;    
    /**     * The raw type is 'bool'     */
    public physics_interpolation: boolean;
    public get_root(): Window;
    public has_group(name: GDString | StringName | string): boolean;
    public is_accessibility_enabled(): boolean;
    public is_accessibility_supported(): boolean;
    public is_auto_accept_quit(): boolean;
    public set_auto_accept_quit(enabled: boolean): void;
    public is_quit_on_go_back(): boolean;
    public set_quit_on_go_back(enabled: boolean): void;
    public set_debug_collisions_hint(enable: boolean): void;
    public is_debugging_collisions_hint(): boolean;
    public set_debug_paths_hint(enable: boolean): void;
    public is_debugging_paths_hint(): boolean;
    public set_debug_navigation_hint(enable: boolean): void;
    public is_debugging_navigation_hint(): boolean;
    public set_edited_scene_root(scene: Node): void;
    public get_edited_scene_root(): Node;
    public set_pause(enable: boolean): void;
    public is_paused(): boolean;
    public create_timer(timeSec: number, processAlways: boolean = true, processInPhysics: boolean = false, ignoreTimeScale: boolean = false): SceneTreeTimer;
    public create_tween(): Tween;
    public get_processed_tweens(): Array<any>;
    public get_node_count(): number;
    public get_frame(): number;
    public quit(exitCode: number = 0): void;
    public set_physics_interpolation_enabled(enabled: boolean): void;
    public is_physics_interpolation_enabled(): boolean;
    public queue_delete(obj: GodotObject): void;
    public call_group_flags(flags: number, group: GDString | StringName | string, method: GDString | StringName | string, ...args: any[]): void;
    public notify_group_flags(callFlags: number, group: GDString | StringName | string, notification: number): void;
    public set_group_flags(callFlags: number, group: GDString | StringName | string, property: GDString | StringName | string, value: any): void;
    public call_group(group: GDString | StringName | string, method: GDString | StringName | string, ...args: any[]): void;
    public notify_group(group: GDString | StringName | string, notification: number): void;
    public set_group(group: GDString | StringName | string, property: GDString | StringName | string, value: any): void;
    public get_nodes_in_group(group: GDString | StringName | string): Array<any>;
    public get_first_node_in_group(group: GDString | StringName | string): Node;
    public get_node_count_in_group(group: GDString | StringName | string): number;
    public set_current_scene(childNode: Node): void;
    public get_current_scene(): Node;
    public change_scene_to_file(path: GDString | StringName | string): number;
    public change_scene_to_packed(packedScene: PackedScene): number;
    public reload_current_scene(): number;
    public unload_current_scene(): void;
    public set_multiplayer(multiplayer: MultiplayerAPI, rootPath: NodePath | GDString | string = NodePath("")): void;
    public get_multiplayer(forPath: NodePath | GDString | string = NodePath("")): MultiplayerAPI;
    public set_multiplayer_poll_enabled(enabled: boolean): void;
    public is_multiplayer_poll_enabled(): boolean;

    
    public readonly tree_changed: Signal<() => void>;
    public readonly scene_changed: Signal<() => void>;
    public readonly tree_process_mode_changed: Signal<() => void>;
    public readonly node_added: Signal<(node: Node) => void>;
    public readonly node_removed: Signal<(node: Node) => void>;
    public readonly node_renamed: Signal<(node: Node) => void>;
    public readonly node_configuration_warning_changed: Signal<(node: Node) => void>;
    public readonly process_frame: Signal<() => void>;
    public readonly physics_frame: Signal<() => void>;

    public static readonly GroupCallFlags: {
        GROUP_CALL_DEFAULT: 0;
        GROUP_CALL_REVERSE: 1;
        GROUP_CALL_DEFERRED: 2;
        GROUP_CALL_UNIQUE: 4;
    };
}

