
import type { AnimationMixer } from '@godot/classes/animation_mixer';
import type { AnimationRootNode } from '@godot/classes/animation_root_node';


export declare class AnimationTree extends AnimationMixer {

    
    /**     * The raw type is 'AnimationRootNode'     */
    public tree_root: AnimationRootNode;    
    /**     * The raw type is 'NodePath'     */
    public advance_expression_base_node: NodePath;    
    /**     * The raw type is 'NodePath'     */
    public anim_player: NodePath;
    public set_tree_root(animationNode: AnimationRootNode): void;
    public get_tree_root(): AnimationRootNode;
    public set_advance_expression_base_node(path: NodePath | GDString | string): void;
    public get_advance_expression_base_node(): NodePath;
    public set_animation_player(path: NodePath | GDString | string): void;
    public get_animation_player(): NodePath;
    public set_process_callback(mode: number): void;
    public get_process_callback(): number;

    
    public readonly animation_player_changed: Signal;

    public static readonly AnimationProcessCallback: {
        ANIMATION_PROCESS_PHYSICS: 0;
        ANIMATION_PROCESS_IDLE: 1;
        ANIMATION_PROCESS_MANUAL: 2;
    };
}

