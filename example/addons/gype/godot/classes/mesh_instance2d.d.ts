
import type { Mesh } from '@godot/classes/mesh';
import type { Node2D } from '@godot/classes/node2d';
import type { Signal } from '@godot/builtins/signal';
import type { Texture2D } from '@godot/classes/texture2d';


export declare class MeshInstance2D extends Node2D {

    
    /**     * The raw type is 'Mesh'     */
    public mesh: Mesh;    
    /**     * The raw type is 'Texture2D'     */
    public texture: Texture2D;
    public set_mesh(mesh: Mesh): void;
    public get_mesh(): Mesh;
    public set_texture(texture: Texture2D): void;
    public get_texture(): Texture2D;

    
    public readonly texture_changed: Signal<() => void>;

}

