
import type { TextureLayered } from '@godot/classes/texture_layered';


export declare class PlaceholderTextureLayered extends TextureLayered {

    
    /**     * The raw type is 'Vector2i'     */
    public size: Vector2i;    
    /**     * The raw type is 'int'     */
    public layers: number;
    public set_size(size: Vector2i): void;
    public get_size(): Vector2i;
    public set_layers(layers: number): void;


}

