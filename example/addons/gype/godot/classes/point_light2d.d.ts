
import type { Light2D } from '@godot/classes/light2d';
import type { Texture2D } from '@godot/classes/texture2d';
import type { Vector2 } from '@godot/builtins/vector2';


export declare class PointLight2D extends Light2D {

    
    /**     * The raw type is 'Texture2D,-AnimatedTexture,-AtlasTexture,-CameraTexture,-CanvasTexture,-MeshTexture,-Texture2DRD,-ViewportTexture'     */
    public texture: Texture2D;    
    /**     * The raw type is 'Vector2'     */
    public offset: Vector2;    
    /**     * The raw type is 'float'     */
    public texture_scale: number;    
    /**     * The raw type is 'float'     */
    public height: number;
    public set_texture(texture: Texture2D): void;
    public get_texture(): Texture2D;
    public set_texture_offset(textureOffset: Vector2): void;
    public get_texture_offset(): Vector2;
    public set_texture_scale(textureScale: number): void;
    public get_texture_scale(): number;


}

