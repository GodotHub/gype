
import type { Texture3D } from '@godot/classes/texture3d';


export declare class CompressedTexture3D extends Texture3D {

    
    /**     * The raw type is 'String'     */
    public load_path: GDString | StringName | string;
    public load(path: GDString | StringName | string): number;
    public get_load_path(): GDString;


}

