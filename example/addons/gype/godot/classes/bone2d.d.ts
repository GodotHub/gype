
import type { Node2D } from '@godot/classes/node2d';


export declare class Bone2D extends Node2D {

    
    /**     * The raw type is 'Transform2D'     */
    public rest: Transform2D;
    public set_rest(rest: Transform2D): void;
    public get_rest(): Transform2D;
    public apply_rest(): void;
    public get_skeleton_rest(): Transform2D;
    public get_index_in_skeleton(): number;
    public set_autocalculate_length_and_angle(autoCalculate: boolean): void;
    public get_autocalculate_length_and_angle(): boolean;
    public set_length(length: number): void;
    public get_length(): number;
    public set_bone_angle(angle: number): void;
    public get_bone_angle(): number;


}

