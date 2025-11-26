
import type { Mesh } from '@godot/classes/mesh';
import type { Texture2D } from '@godot/classes/texture2d';


export declare class MeshTexture extends Texture2D {

    
    /**     * The raw type is 'Mesh'     */
    public mesh: Mesh;    
    /**     * The raw type is 'Texture2D'     */
    public base_texture: Texture2D;    
    /**     * The raw type is 'Vector2'     */
    public image_size: Vector2;
    public set_mesh(mesh: Mesh): void;
    public get_mesh(): Mesh;
    public set_image_size(size: Vector2): void;
    public get_image_size(): Vector2;
    public set_base_texture(texture: Texture2D): void;
    public get_base_texture(): Texture2D;


}

