
import type { AnimationNode } from '@godot/classes/animation_node';


export declare class AnimationNodeSync extends AnimationNode {

    
    /**     * The raw type is 'bool'     */
    public sync: boolean;
    public set_use_sync(enable: boolean): void;
    public is_using_sync(): boolean;


}

