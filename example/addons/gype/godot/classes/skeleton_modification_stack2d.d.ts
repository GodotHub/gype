
import type { Resource } from '@godot/classes/resource';
import type { Skeleton2D } from '@godot/classes/skeleton2d';
import type { SkeletonModification2D } from '@godot/classes/skeleton_modification2d';


export declare class SkeletonModificationStack2D extends Resource {

    
    /**     * The raw type is 'bool'     */
    public enabled: boolean;    
    /**     * The raw type is 'float'     */
    public strength: number;    
    /**     * The raw type is 'int'     */
    public modification_count: number;
    public setup(): void;
    public execute(delta: number, executionMode: number): void;
    public enable_all_modifications(enabled: boolean): void;
    public get_modification(modIdx: number): SkeletonModification2D;
    public add_modification(modification: SkeletonModification2D): void;
    public delete_modification(modIdx: number): void;
    public set_modification(modIdx: number, modification: SkeletonModification2D): void;
    public set_modification_count(count: number): void;
    public get_modification_count(): number;
    public get_is_setup(): boolean;
    public set_enabled(enabled: boolean): void;
    public get_enabled(): boolean;
    public set_strength(strength: number): void;
    public get_strength(): number;
    public get_skeleton(): Skeleton2D;


}

