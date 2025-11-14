
import type { Texture2D } from '@godot/classes/texture2d';
import type { Vector2 } from '@godot/builtins/vector2';


export declare class ExternalTexture extends Texture2D {

    
    /**     * The raw type is 'Vector2'     */
    public size: Vector2;
    public set_size(size: Vector2): void;
    public get_external_texture_id(): number;
    public set_external_buffer_id(externalBufferId: number): void;


}

