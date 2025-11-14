
import type { Color } from '@godot/builtins/color';
import type { GodotObject } from '@godot/classes/godot_object';
import type { Image } from '@godot/classes/image';
import type { Resource } from '@godot/classes/resource';


export declare class GLTFSpecGloss extends Resource {

    
    /**     * The raw type is 'Object'     */
    public diffuse_img: Image;    
    /**     * The raw type is 'Color'     */
    public diffuse_factor: Color;    
    /**     * The raw type is 'float'     */
    public gloss_factor: number;    
    /**     * The raw type is 'Color'     */
    public specular_factor: Color;    
    /**     * The raw type is 'Object'     */
    public spec_gloss_img: Image;
    public get_diffuse_img(): Image;
    public set_diffuse_img(diffuseImg: Image): void;
    public get_diffuse_factor(): Color;
    public set_diffuse_factor(diffuseFactor: Color): void;
    public get_gloss_factor(): number;
    public set_gloss_factor(glossFactor: number): void;
    public get_specular_factor(): Color;
    public set_specular_factor(specularFactor: Color): void;
    public get_spec_gloss_img(): Image;
    public set_spec_gloss_img(specGlossImg: Image): void;


}

