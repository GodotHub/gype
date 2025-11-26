
import type { AnimationNode } from '@godot/classes/animation_node';
import type { AnimationNodeStateMachineTransition } from '@godot/classes/animation_node_state_machine_transition';
import type { AnimationRootNode } from '@godot/classes/animation_root_node';


export declare class AnimationNodeStateMachine extends AnimationRootNode {

    
    /**     * The raw type is 'int'     */
    public state_machine_type: number;    
    /**     * The raw type is 'bool'     */
    public allow_transition_to_self: boolean;    
    /**     * The raw type is 'bool'     */
    public reset_ends: boolean;
    public add_node(name: GDString | StringName | string, node: AnimationNode, position: Vector2 = Vector2(0, 0)): void;
    public replace_node(name: GDString | StringName | string, node: AnimationNode): void;
    public get_node(name: GDString | StringName | string): AnimationNode;
    public remove_node(name: GDString | StringName | string): void;
    public rename_node(name: GDString | StringName | string, newName: GDString | StringName | string): void;
    public has_node(name: GDString | StringName | string): boolean;
    public get_node_name(node: AnimationNode): StringName;
    public get_node_list(): Array<any>;
    public set_node_position(name: GDString | StringName | string, position: Vector2): void;
    public get_node_position(name: GDString | StringName | string): Vector2;
    public has_transition(_from: GDString | StringName | string, to: GDString | StringName | string): boolean;
    public add_transition(_from: GDString | StringName | string, to: GDString | StringName | string, transition: AnimationNodeStateMachineTransition): void;
    public get_transition(idx: number): AnimationNodeStateMachineTransition;
    public get_transition_from(idx: number): StringName;
    public get_transition_to(idx: number): StringName;
    public get_transition_count(): number;
    public remove_transition_by_index(idx: number): void;
    public remove_transition(_from: GDString | StringName | string, to: GDString | StringName | string): void;
    public set_graph_offset(offset: Vector2): void;
    public get_graph_offset(): Vector2;
    public set_state_machine_type(stateMachineType: number): void;
    public get_state_machine_type(): number;
    public set_allow_transition_to_self(enable: boolean): void;
    public is_allow_transition_to_self(): boolean;
    public set_reset_ends(enable: boolean): void;
    public are_ends_reset(): boolean;


    public static readonly StateMachineType: {
        STATE_MACHINE_TYPE_ROOT: 0;
        STATE_MACHINE_TYPE_NESTED: 1;
        STATE_MACHINE_TYPE_GROUPED: 2;
    };
}

