
import type { Resource } from '@godot/classes/resource';


export declare class GLTFTexture extends Resource {

    
    /**     * The raw type is 'int'     */
    public src_image: number;    
    /**     * The raw type is 'int'     */
    public sampler: number;
    public get_src_image(): number;
    public set_src_image(srcImage: number): void;
    public get_sampler(): number;
    public set_sampler(sampler: number): void;


}

