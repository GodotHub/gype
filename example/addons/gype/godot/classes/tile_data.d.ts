
import type { CanvasItemMaterial } from '@godot/classes/canvas_item_material';
import type { GodotObject } from '@godot/classes/godot_object';
import type { Material } from '@godot/classes/material';
import type { NavigationPolygon } from '@godot/classes/navigation_polygon';
import type { OccluderPolygon2D } from '@godot/classes/occluder_polygon2d';


export declare class TileData extends GodotObject {

    
    /**     * The raw type is 'bool'     */
    public flip_h: boolean;    
    /**     * The raw type is 'bool'     */
    public flip_v: boolean;    
    /**     * The raw type is 'bool'     */
    public transpose: boolean;    
    /**     * The raw type is 'Vector2i'     */
    public texture_origin: Vector2i;    
    /**     * The raw type is 'Color'     */
    public modulate: Color;    
    /**     * The raw type is 'CanvasItemMaterial,ShaderMaterial'     */
    public material: Material;    
    /**     * The raw type is 'int'     */
    public z_index: number;    
    /**     * The raw type is 'int'     */
    public y_sort_origin: number;    
    /**     * The raw type is 'int'     */
    public terrain_set: number;    
    /**     * The raw type is 'int'     */
    public terrain: number;    
    /**     * The raw type is 'float'     */
    public probability: number;
    public set_flip_h(flih: boolean): void;
    public get_flip_h(): boolean;
    public set_flip_v(fliv: boolean): void;
    public get_flip_v(): boolean;
    public set_transpose(transpose: boolean): void;
    public get_transpose(): boolean;
    public set_material(material: Material): void;
    public get_material(): Material;
    public set_texture_origin(textureOrigin: Vector2i): void;
    public get_texture_origin(): Vector2i;
    public set_modulate(modulate: Color): void;
    public get_modulate(): Color;
    public set_z_index(zIndex: number): void;
    public get_z_index(): number;
    public set_y_sort_origin(ySortOrigin: number): void;
    public get_y_sort_origin(): number;
    public set_occluder_polygons_count(layerId: number, polygonsCount: number): void;
    public get_occluder_polygons_count(layerId: number): number;
    public add_occluder_polygon(layerId: number): void;
    public remove_occluder_polygon(layerId: number, polygonIndex: number): void;
    public set_occluder_polygon(layerId: number, polygonIndex: number, polygon: OccluderPolygon2D): void;
    public get_occluder_polygon(layerId: number, polygonIndex: number, flih: boolean = false, fliv: boolean = false, transpose: boolean = false): OccluderPolygon2D;
    public set_occluder(layerId: number, occluderPolygon: OccluderPolygon2D): void;
    public get_occluder(layerId: number, flih: boolean = false, fliv: boolean = false, transpose: boolean = false): OccluderPolygon2D;
    public set_constant_linear_velocity(layerId: number, velocity: Vector2): void;
    public get_constant_linear_velocity(layerId: number): Vector2;
    public set_constant_angular_velocity(layerId: number, velocity: number): void;
    public get_constant_angular_velocity(layerId: number): number;
    public set_collision_polygons_count(layerId: number, polygonsCount: number): void;
    public get_collision_polygons_count(layerId: number): number;
    public add_collision_polygon(layerId: number): void;
    public remove_collision_polygon(layerId: number, polygonIndex: number): void;
    public set_collision_polygon_points(layerId: number, polygonIndex: number, polygon: PackedVector2Array): void;
    public get_collision_polygon_points(layerId: number, polygonIndex: number): PackedVector2Array;
    public set_collision_polygon_one_way(layerId: number, polygonIndex: number, oneWay: boolean): void;
    public is_collision_polygon_one_way(layerId: number, polygonIndex: number): boolean;
    public set_collision_polygon_one_way_margin(layerId: number, polygonIndex: number, oneWayMargin: number): void;
    public get_collision_polygon_one_way_margin(layerId: number, polygonIndex: number): number;
    public set_terrain_set(terrainSet: number): void;
    public get_terrain_set(): number;
    public set_terrain(terrain: number): void;
    public get_terrain(): number;
    public set_terrain_peering_bit(peeringBit: number, terrain: number): void;
    public get_terrain_peering_bit(peeringBit: number): number;
    public is_valid_terrain_peering_bit(peeringBit: number): boolean;
    public set_navigation_polygon(layerId: number, navigationPolygon: NavigationPolygon): void;
    public get_navigation_polygon(layerId: number, flih: boolean = false, fliv: boolean = false, transpose: boolean = false): NavigationPolygon;
    public set_probability(probability: number): void;
    public get_probability(): number;
    public set_custom_data(layerName: GDString | StringName | string, value: any): void;
    public get_custom_data(layerName: GDString | StringName | string): any;
    public has_custom_data(layerName: GDString | StringName | string): boolean;
    public set_custom_data_by_layer_id(layerId: number, value: any): void;
    public get_custom_data_by_layer_id(layerId: number): any;

    
    public readonly changed: Signal;

}

