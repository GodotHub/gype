
import type { Texture2D } from '@godot/classes/texture2d';


export declare class ViewportTexture extends Texture2D {

    
    /**     * The raw type is 'NodePath'     */
    public viewport_path: NodePath;
    public set_viewport_path_in_scene(path: NodePath | GDString | string): void;
    public get_viewport_path_in_scene(): NodePath;


}

