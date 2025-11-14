
import type { Image } from '@godot/classes/image';
import type { TextureLayered } from '@godot/classes/texture_layered';


export declare class ImageTextureLayered extends TextureLayered {


    public create_from_images(images: Array<any>): number;
    public update_layer(image: Image, layer: number): void;


}

