
import type { GodotObject } from '@godot/classes/godot_object';
import type { PackedVector2Array } from '@godot/builtins/packed_vector2_array';
import type { RID } from '@godot/builtins/rid';
import type { Rect2i } from '@godot/builtins/rect2i';
import type { Vector2 } from '@godot/builtins/vector2';


export declare class XRVRS extends GodotObject {

    
    /**     * The raw type is 'float'     */
    public vrs_min_radius: number;    
    /**     * The raw type is 'float'     */
    public vrs_strength: number;    
    /**     * The raw type is 'Rect2i'     */
    public vrs_render_region: Rect2i;
    public get_vrs_min_radius(): number;
    public set_vrs_min_radius(radius: number): void;
    public get_vrs_strength(): number;
    public set_vrs_strength(strength: number): void;
    public get_vrs_render_region(): Rect2i;
    public set_vrs_render_region(renderRegion: Rect2i): void;
    public make_vrs_texture(targetSize: Vector2, eyeFoci: PackedVector2Array): RID;


}

