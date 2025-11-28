
import type { TextureLayered } from '@godot/classes/texture_layered';


export declare class CompressedTextureLayered extends TextureLayered {

    
    /**     * The raw type is 'String'     */
    public load_path: GDString | StringName | string;
    public load(path: GDString | StringName | string): number;
    public get_load_path(): GDString;


}

