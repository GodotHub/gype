
import type { GDArray } from '@godot/builtins/gd_array';
import type { GDString } from '@godot/builtins/gd_string';
import type { GodotObject } from '@godot/classes/godot_object';
import type { InputEvent } from '@godot/classes/input_event';
import type { MultiplayerAPI } from '@godot/classes/multiplayer_api';
import type { NodePath } from '@godot/builtins/node_path';
import type { PackedStringArray } from '@godot/builtins/packed_string_array';
import type { RID } from '@godot/builtins/rid';
import type { SceneTree } from '@godot/classes/scene_tree';
import type { Signal } from '@godot/builtins/signal';
import type { StringName } from '@godot/builtins/string_name';
import type { Tween } from '@godot/classes/tween';
import type { Viewport } from '@godot/classes/viewport';
import type { Window } from '@godot/classes/window';


export declare class Node extends GodotObject {

    
    /**     * The raw type is 'StringName'     */
    public name: StringName;    
    /**     * The raw type is 'bool'     */
    public unique_name_in_owner: boolean;    
    /**     * The raw type is 'String'     */
    public scene_file_path: GDString;    
    /**     * The raw type is 'Node'     */
    public owner: Node;    
    /**     * The raw type is 'MultiplayerAPI'     */
    public multiplayer: MultiplayerAPI;    
    /**     * The raw type is 'int'     */
    public process_mode: number;    
    /**     * The raw type is 'int'     */
    public process_priority: number;    
    /**     * The raw type is 'int'     */
    public process_physics_priority: number;    
    /**     * The raw type is 'int'     */
    public process_thread_group: number;    
    /**     * The raw type is 'int'     */
    public process_thread_group_order: number;    
    /**     * The raw type is 'int'     */
    public process_thread_messages: number;    
    /**     * The raw type is 'int'     */
    public physics_interpolation_mode: number;    
    /**     * The raw type is 'int'     */
    public auto_translate_mode: number;    
    /**     * The raw type is 'String'     */
    public editor_description: GDString;
    public _process(delta: number): void;
    public _physics_process(delta: number): void;
    public _enter_tree(): void;
    public _exit_tree(): void;
    public _ready(): void;
    public _get_configuration_warnings(): PackedStringArray;
    public _get_accessibility_configuration_warnings(): PackedStringArray;
    public _input(event: InputEvent): void;
    public _shortcut_input(event: InputEvent): void;
    public _unhandled_input(event: InputEvent): void;
    public _unhandled_key_input(event: InputEvent): void;
    public _get_focused_accessibility_element(): RID;
    public static print_orphan_nodes(): void;
    public static get_orphan_node_ids(): Array<any>;
    public add_sibling(sibling: Node, forceReadableName: boolean = false): void;
    public set_name(name: GDString | StringName | string): void;
    public get_name(): StringName;
    public add_child(node: Node, forceReadableName: boolean = false, internal: number = 0): void;
    public remove_child(node: Node): void;
    public reparent(newParent: Node, keeglobalTransform: boolean = true): void;
    public get_child_count(includeInternal: boolean = false): number;
    public get_children(includeInternal: boolean = false): Array<any>;
    public get_child(idx: number, includeInternal: boolean = false): Node;
    public has_node(path: NodePath | GDString | string): boolean;
    public get_node(path: NodePath | GDString | string): Node;
    public get_node_or_null(path: NodePath | GDString | string): Node;
    public get_parent(): Node;
    public find_child(pattern: GDString | StringName | string, recursive: boolean = true, owned: boolean = true): Node;
    public find_children(pattern: GDString | StringName | string, _type: GDString | StringName | string = "", recursive: boolean = true, owned: boolean = true): Array<any>;
    public find_parent(pattern: GDString | StringName | string): Node;
    public has_node_and_resource(path: NodePath | GDString | string): boolean;
    public get_node_and_resource(path: NodePath | GDString | string): GDArray;
    public is_inside_tree(): boolean;
    public is_part_of_edited_scene(): boolean;
    public is_ancestor_of(node: Node): boolean;
    public is_greater_than(node: Node): boolean;
    public get_path(): NodePath;
    public get_path_to(node: Node, useUniquePath: boolean = false): NodePath;
    public add_to_group(group: GDString | StringName | string, persistent: boolean = false): void;
    public remove_from_group(group: GDString | StringName | string): void;
    public is_in_group(group: GDString | StringName | string): boolean;
    public move_child(childNode: Node, toIndex: number): void;
    public get_groups(): Array<any>;
    public set_owner(owner: Node): void;
    public get_owner(): Node;
    public get_index(includeInternal: boolean = false): number;
    public print_tree(): void;
    public print_tree_pretty(): void;
    public get_tree_string(): GDString;
    public get_tree_string_pretty(): GDString;
    public set_scene_file_path(sceneFilePath: GDString | StringName | string): void;
    public get_scene_file_path(): GDString;
    public propagate_notification(what: number): void;
    public propagate_call(method: GDString | StringName | string, args: GDArray = [], parentFirst: boolean = false): void;
    public set_physics_process(enable: boolean): void;
    public get_physics_process_delta_time(): number;
    public is_physics_processing(): boolean;
    public get_process_delta_time(): number;
    public set_process(enable: boolean): void;
    public set_process_priority(priority: number): void;
    public get_process_priority(): number;
    public set_physics_process_priority(priority: number): void;
    public get_physics_process_priority(): number;
    public is_processing(): boolean;
    public set_process_input(enable: boolean): void;
    public is_processing_input(): boolean;
    public set_process_shortcut_input(enable: boolean): void;
    public is_processing_shortcut_input(): boolean;
    public set_process_unhandled_input(enable: boolean): void;
    public is_processing_unhandled_input(): boolean;
    public set_process_unhandled_key_input(enable: boolean): void;
    public is_processing_unhandled_key_input(): boolean;
    public set_process_mode(mode: number): void;
    public get_process_mode(): number;
    public can_process(): boolean;
    public set_process_thread_group(mode: number): void;
    public get_process_thread_group(): number;
    public set_process_thread_messages(flags: number): void;
    public get_process_thread_messages(): number;
    public set_process_thread_group_order(order: number): void;
    public get_process_thread_group_order(): number;
    public queue_accessibility_update(): void;
    public get_accessibility_element(): RID;
    public set_display_folded(fold: boolean): void;
    public is_displayed_folded(): boolean;
    public set_process_internal(enable: boolean): void;
    public is_processing_internal(): boolean;
    public set_physics_process_internal(enable: boolean): void;
    public is_physics_processing_internal(): boolean;
    public set_physics_interpolation_mode(mode: number): void;
    public get_physics_interpolation_mode(): number;
    public is_physics_interpolated(): boolean;
    public is_physics_interpolated_and_enabled(): boolean;
    public reset_physics_interpolation(): void;
    public set_auto_translate_mode(mode: number): void;
    public get_auto_translate_mode(): number;
    public can_auto_translate(): boolean;
    public set_translation_domain_inherited(): void;
    public get_window(): Window;
    public get_last_exclusive_window(): Window;
    public get_tree(): SceneTree;
    public create_tween(): Tween;
    public duplicate(flags: number = 15): Node;
    public replace_by(node: Node, keegroups: boolean = false): void;
    public set_scene_instance_load_placeholder(loadPlaceholder: boolean): void;
    public get_scene_instance_load_placeholder(): boolean;
    public set_editable_instance(node: Node, isEditable: boolean): void;
    public is_editable_instance(node: Node): boolean;
    public get_viewport(): Viewport;
    public queue_free(): void;
    public request_ready(): void;
    public is_node_ready(): boolean;
    public set_multiplayer_authority(id: number, recursive: boolean = true): void;
    public get_multiplayer_authority(): number;
    public is_multiplayer_authority(): boolean;
    public get_multiplayer(): MultiplayerAPI;
    public rpc_config(method: GDString | StringName | string, config: any): void;
    public get_node_rpc_config(): any;
    public set_editor_description(editorDescription: GDString | StringName | string): void;
    public get_editor_description(): GDString;
    public set_unique_name_in_owner(enable: boolean): void;
    public is_unique_name_in_owner(): boolean;
    public atr(message: GDString | StringName | string, context: GDString | StringName | string = ""): GDString;
    public atr_n(message: GDString | StringName | string, pluralMessage: GDString | StringName | string, n: number, context: GDString | StringName | string = ""): GDString;
    public rpc(method: GDString | StringName | string, ...args: any[]): number;
    public rpc_id(peerId: number, method: GDString | StringName | string, ...args: any[]): number;
    public update_configuration_warnings(): void;
    public call_deferred_thread_group(method: GDString | StringName | string, ...args: any[]): any;
    public set_deferred_thread_group(property: GDString | StringName | string, value: any): void;
    public notify_deferred_thread_group(what: number): void;
    public call_thread_safe(method: GDString | StringName | string, ...args: any[]): any;
    public set_thread_safe(property: GDString | StringName | string, value: any): void;
    public notify_thread_safe(what: number): void;

    
    public readonly ready: Signal<() => void>;
    public readonly renamed: Signal<() => void>;
    public readonly tree_entered: Signal<() => void>;
    public readonly tree_exiting: Signal<() => void>;
    public readonly tree_exited: Signal<() => void>;
    public readonly child_entered_tree: Signal<(node: Node) => void>;
    public readonly child_exiting_tree: Signal<(node: Node) => void>;
    public readonly child_order_changed: Signal<() => void>;
    public readonly replacing_by: Signal<(node: Node) => void>;
    public readonly editor_description_changed: Signal<(node: Node) => void>;
    public readonly editor_state_changed: Signal<() => void>;

    public static readonly ProcessMode: {
        PROCESS_MODE_INHERIT: 0;
        PROCESS_MODE_PAUSABLE: 1;
        PROCESS_MODE_WHEN_PAUSED: 2;
        PROCESS_MODE_ALWAYS: 3;
        PROCESS_MODE_DISABLED: 4;
    };
    public static readonly ProcessThreadGroup: {
        PROCESS_THREAD_GROUP_INHERIT: 0;
        PROCESS_THREAD_GROUP_MAIN_THREAD: 1;
        PROCESS_THREAD_GROUP_SUB_THREAD: 2;
    };
    public static readonly ProcessThreadMessages: {
        FLAG_PROCESS_THREAD_MESSAGES: 1;
        FLAG_PROCESS_THREAD_MESSAGES_PHYSICS: 2;
        FLAG_PROCESS_THREAD_MESSAGES_ALL: 3;
    };
    public static readonly PhysicsInterpolationMode: {
        PHYSICS_INTERPOLATION_MODE_INHERIT: 0;
        PHYSICS_INTERPOLATION_MODE_ON: 1;
        PHYSICS_INTERPOLATION_MODE_OFF: 2;
    };
    public static readonly DuplicateFlags: {
        DUPLICATE_SIGNALS: 1;
        DUPLICATE_GROUPS: 2;
        DUPLICATE_SCRIPTS: 4;
        DUPLICATE_USE_INSTANTIATION: 8;
    };
    public static readonly InternalMode: {
        INTERNAL_MODE_DISABLED: 0;
        INTERNAL_MODE_FRONT: 1;
        INTERNAL_MODE_BACK: 2;
    };
    public static readonly AutoTranslateMode: {
        AUTO_TRANSLATE_MODE_INHERIT: 0;
        AUTO_TRANSLATE_MODE_ALWAYS: 1;
        AUTO_TRANSLATE_MODE_DISABLED: 2;
    };
}

