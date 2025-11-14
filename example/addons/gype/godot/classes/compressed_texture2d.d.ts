
import type { GDString } from '@godot/builtins/gd_string';
import type { Texture2D } from '@godot/classes/texture2d';


export declare class CompressedTexture2D extends Texture2D {

    
    /**     * The raw type is 'String'     */
    public load_path: GDString;
    public load(path: GDString | StringName | string): number;
    public get_load_path(): GDString;


}

