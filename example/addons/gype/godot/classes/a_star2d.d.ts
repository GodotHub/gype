
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class AStar2D extends RefCounted {

    
    /**     * The raw type is 'bool'     */
    public neighbor_filter_enabled: boolean;
    public _filter_neighbor(fromId: number, neighborId: number): boolean;
    public _estimate_cost(fromId: number, endId: number): number;
    public _compute_cost(fromId: number, toId: number): number;
    public get_available_point_id(): number;
    public add_point(id: number, position: Vector2, weightScale: number = 1.0): void;
    public get_point_position(id: number): Vector2;
    public set_point_position(id: number, position: Vector2): void;
    public get_point_weight_scale(id: number): number;
    public set_point_weight_scale(id: number, weightScale: number): void;
    public remove_point(id: number): void;
    public has_point(id: number): boolean;
    public get_point_connections(id: number): PackedInt64Array;
    public get_point_ids(): PackedInt64Array;
    public set_neighbor_filter_enabled(enabled: boolean): void;
    public is_neighbor_filter_enabled(): boolean;
    public set_point_disabled(id: number, disabled: boolean = true): void;
    public is_point_disabled(id: number): boolean;
    public connect_points(id: number, toId: number, bidirectional: boolean = true): void;
    public disconnect_points(id: number, toId: number, bidirectional: boolean = true): void;
    public are_points_connected(id: number, toId: number, bidirectional: boolean = true): boolean;
    public get_point_count(): number;
    public get_point_capacity(): number;
    public reserve_space(numNodes: number): void;
    public clear(): void;
    public get_closest_point(toPosition: Vector2, includeDisabled: boolean = false): number;
    public get_closest_position_in_segment(toPosition: Vector2): Vector2;
    public get_point_path(fromId: number, toId: number, allowPartialPath: boolean = false): PackedVector2Array;
    public get_id_path(fromId: number, toId: number, allowPartialPath: boolean = false): PackedInt64Array;


}

