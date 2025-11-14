
import type { RID } from '@godot/builtins/rid';
import type { Texture2D } from '@godot/classes/texture2d';


export declare class Texture2DRD extends Texture2D {

    
    /**     * The raw type is 'RID'     */
    public texture_rd_rid: RID;
    public set_texture_rd_rid(textureRdRid: RID): void;
    public get_texture_rd_rid(): RID;


}

