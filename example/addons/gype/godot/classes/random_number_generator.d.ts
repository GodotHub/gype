
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class RandomNumberGenerator extends RefCounted {

    
    /**     * The raw type is 'int'     */
    public seed: number;    
    /**     * The raw type is 'int'     */
    public state: number;
    public set_seed(seed: number): void;
    public get_seed(): number;
    public set_state(state: number): void;
    public get_state(): number;
    public randi(): number;
    public randf(): number;
    public randfn(mean: number = 0.0, deviation: number = 1.0): number;
    public randf_range(_from: number, to: number): number;
    public randi_range(_from: number, to: number): number;
    public rand_weighted(weights: PackedFloat32Array): number;
    public randomize(): void;


}

