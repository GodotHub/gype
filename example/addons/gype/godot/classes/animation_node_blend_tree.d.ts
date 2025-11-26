
import type { AnimationNode } from '@godot/classes/animation_node';
import type { AnimationRootNode } from '@godot/classes/animation_root_node';


export declare class AnimationNodeBlendTree extends AnimationRootNode {

    
    /**     * The raw type is 'Vector2'     */
    public graph_offset: Vector2;
    public add_node(name: GDString | StringName | string, node: AnimationNode, position: Vector2 = Vector2(0, 0)): void;
    public get_node(name: GDString | StringName | string): AnimationNode;
    public remove_node(name: GDString | StringName | string): void;
    public rename_node(name: GDString | StringName | string, newName: GDString | StringName | string): void;
    public has_node(name: GDString | StringName | string): boolean;
    public connect_node(inputNode: GDString | StringName | string, inputIndex: number, outputNode: GDString | StringName | string): void;
    public disconnect_node(inputNode: GDString | StringName | string, inputIndex: number): void;
    public get_node_list(): Array<any>;
    public set_node_position(name: GDString | StringName | string, position: Vector2): void;
    public get_node_position(name: GDString | StringName | string): Vector2;
    public set_graph_offset(offset: Vector2): void;
    public get_graph_offset(): Vector2;

    
    public readonly node_changed: Signal;

}

