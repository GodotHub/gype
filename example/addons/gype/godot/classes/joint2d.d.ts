
import type { Node2D } from '@godot/classes/node2d';
import type { NodePath } from '@godot/builtins/node_path';
import type { RID } from '@godot/builtins/rid';


export declare class Joint2D extends Node2D {

    
    /**     * The raw type is 'NodePath'     */
    public node_a: NodePath;    
    /**     * The raw type is 'NodePath'     */
    public node_b: NodePath;    
    /**     * The raw type is 'float'     */
    public bias: number;    
    /**     * The raw type is 'bool'     */
    public disable_collision: boolean;
    public set_node_a(node: NodePath | GDString | string): void;
    public get_node_a(): NodePath;
    public set_node_b(node: NodePath | GDString | string): void;
    public get_node_b(): NodePath;
    public set_bias(bias: number): void;
    public get_bias(): number;
    public set_exclude_nodes_from_collision(enable: boolean): void;
    public get_exclude_nodes_from_collision(): boolean;
    public get_rid(): RID;


}

