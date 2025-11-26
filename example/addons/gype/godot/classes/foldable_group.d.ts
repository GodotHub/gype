
import type { FoldableContainer } from '@godot/classes/foldable_container';
import type { Resource } from '@godot/classes/resource';


export declare class FoldableGroup extends Resource {

    
    /**     * The raw type is 'bool'     */
    public allow_folding_all: boolean;
    public get_expanded_container(): FoldableContainer;
    public get_containers(): Array<any>;
    public set_allow_folding_all(enabled: boolean): void;
    public is_allow_folding_all(): boolean;

    
    public readonly expanded: Signal;

}

