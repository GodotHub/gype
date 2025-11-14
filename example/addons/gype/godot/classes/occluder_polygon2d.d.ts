
import type { PackedVector2Array } from '@godot/builtins/packed_vector2_array';
import type { Resource } from '@godot/classes/resource';


export declare class OccluderPolygon2D extends Resource {

    
    /**     * The raw type is 'bool'     */
    public closed: boolean;    
    /**     * The raw type is 'int'     */
    public cull_mode: number;    
    /**     * The raw type is 'PackedVector2Array'     */
    public polygon: PackedVector2Array;
    public set_closed(closed: boolean): void;
    public is_closed(): boolean;
    public set_cull_mode(cullMode: number): void;
    public get_cull_mode(): number;
    public set_polygon(polygon: PackedVector2Array): void;
    public get_polygon(): PackedVector2Array;


    public static readonly CullMode: {
        CULL_DISABLED: 0;
        CULL_CLOCKWISE: 1;
        CULL_COUNTER_CLOCKWISE: 2;
    };
}

