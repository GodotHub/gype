
import type { NodePath } from '@godot/builtins/node_path';
import type { SkeletonModification2D } from '@godot/classes/skeleton_modification2d';


export declare class SkeletonModification2DPhysicalBones extends SkeletonModification2D {

    
    /**     * The raw type is 'int'     */
    public physical_bone_chain_length: number;
    public set_physical_bone_chain_length(length: number): void;
    public get_physical_bone_chain_length(): number;
    public set_physical_bone_node(jointIdx: number, physicalbone2dNode: NodePath | GDString | string): void;
    public get_physical_bone_node(jointIdx: number): NodePath;
    public fetch_physical_bones(): void;
    public start_simulation(bones: Array<any> = []): void;
    public stop_simulation(bones: Array<any> = []): void;


}

