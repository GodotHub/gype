
import type { AnimationNode } from '@godot/classes/animation_node';
import type { PackedFloat32Array } from '@godot/builtins/packed_float32_array';
import type { PackedFloat64Array } from '@godot/builtins/packed_float64_array';


export declare class AnimationNodeExtension extends AnimationNode {


    public _process_animation_node(playbackInfo: PackedFloat64Array, testOnly: boolean): PackedFloat32Array;
    public static is_looping(nodeInfo: PackedFloat32Array): boolean;
    public static get_remaining_time(nodeInfo: PackedFloat32Array, breakLoop: boolean): number;


}

