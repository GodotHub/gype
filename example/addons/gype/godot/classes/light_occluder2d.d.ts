
import type { Node2D } from '@godot/classes/node2d';
import type { OccluderPolygon2D } from '@godot/classes/occluder_polygon2d';


export declare class LightOccluder2D extends Node2D {

    
    /**     * The raw type is 'OccluderPolygon2D'     */
    public occluder: OccluderPolygon2D;    
    /**     * The raw type is 'bool'     */
    public sdf_collision: boolean;    
    /**     * The raw type is 'int'     */
    public occluder_light_mask: number;
    public set_occluder_polygon(polygon: OccluderPolygon2D): void;
    public get_occluder_polygon(): OccluderPolygon2D;
    public set_occluder_light_mask(mask: number): void;
    public get_occluder_light_mask(): number;
    public set_as_sdf_collision(enable: boolean): void;
    public is_set_as_sdf_collision(): boolean;


}

