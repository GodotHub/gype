
import type { MultiMesh } from '@godot/classes/multi_mesh';
import type { Node2D } from '@godot/classes/node2d';
import type { Texture2D } from '@godot/classes/texture2d';


export declare class MultiMeshInstance2D extends Node2D {

    
    /**     * The raw type is 'MultiMesh'     */
    public multimesh: MultiMesh;    
    /**     * The raw type is 'Texture2D'     */
    public texture: Texture2D;
    public set_multimesh(multimesh: MultiMesh): void;
    public get_multimesh(): MultiMesh;
    public set_texture(texture: Texture2D): void;
    public get_texture(): Texture2D;

    
    public readonly texture_changed: Signal<() => void>;

}

