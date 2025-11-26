
import type { Image } from '@godot/classes/image';
import type { Texture2D } from '@godot/classes/texture2d';


export declare class ImageTexture extends Texture2D {


    public static create_from_image(image: Image): ImageTexture;
    public get_format(): number;
    public set_image(image: Image): void;
    public update(image: Image): void;
    public set_size_override(size: Vector2i): void;


}

