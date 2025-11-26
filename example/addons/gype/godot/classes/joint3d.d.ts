
import type { Node3D } from '@godot/classes/node3d';


export declare class Joint3D extends Node3D {

    
    /**     * The raw type is 'NodePath'     */
    public node_a: NodePath;    
    /**     * The raw type is 'NodePath'     */
    public node_b: NodePath;    
    /**     * The raw type is 'int'     */
    public solver_priority: number;    
    /**     * The raw type is 'bool'     */
    public exclude_nodes_from_collision: boolean;
    public set_node_a(node: NodePath | GDString | string): void;
    public get_node_a(): NodePath;
    public set_node_b(node: NodePath | GDString | string): void;
    public get_node_b(): NodePath;
    public set_solver_priority(priority: number): void;
    public get_solver_priority(): number;
    public set_exclude_nodes_from_collision(enable: boolean): void;
    public get_exclude_nodes_from_collision(): boolean;
    public get_rid(): RID;


}

