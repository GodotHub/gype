
import type { CollisionObject2D } from '@godot/classes/collision_object2d';
import type { Node } from '@godot/classes/node';
import type { Node2D } from '@godot/classes/node2d';


export declare class Area2D extends CollisionObject2D {

    
    /**     * The raw type is 'bool'     */
    public monitoring: boolean;    
    /**     * The raw type is 'bool'     */
    public monitorable: boolean;    
    /**     * The raw type is 'int'     */
    public priority: number;    
    /**     * The raw type is 'int'     */
    public gravity_space_override: number;    
    /**     * The raw type is 'bool'     */
    public gravity_point: boolean;    
    /**     * The raw type is 'float'     */
    public gravity_point_unit_distance: number;    
    /**     * The raw type is 'Vector2'     */
    public gravity_point_center: Vector2;    
    /**     * The raw type is 'Vector2'     */
    public gravity_direction: Vector2;    
    /**     * The raw type is 'float'     */
    public gravity: number;    
    /**     * The raw type is 'int'     */
    public linear_damp_space_override: number;    
    /**     * The raw type is 'float'     */
    public linear_damp: number;    
    /**     * The raw type is 'int'     */
    public angular_damp_space_override: number;    
    /**     * The raw type is 'float'     */
    public angular_damp: number;    
    /**     * The raw type is 'bool'     */
    public audio_bus_override: boolean;    
    /**     * The raw type is 'StringName'     */
    public audio_bus_name: GDString | StringName | string;
    public set_gravity_space_override_mode(spaceOverrideMode: number): void;
    public get_gravity_space_override_mode(): number;
    public set_gravity_is_point(enable: boolean): void;
    public is_gravity_a_point(): boolean;
    public set_gravity_point_unit_distance(distanceScale: number): void;
    public get_gravity_point_unit_distance(): number;
    public set_gravity_point_center(center: Vector2): void;
    public get_gravity_point_center(): Vector2;
    public set_gravity_direction(direction: Vector2): void;
    public get_gravity_direction(): Vector2;
    public set_gravity(gravity: number): void;
    public get_gravity(): number;
    public set_linear_damp_space_override_mode(spaceOverrideMode: number): void;
    public get_linear_damp_space_override_mode(): number;
    public set_angular_damp_space_override_mode(spaceOverrideMode: number): void;
    public get_angular_damp_space_override_mode(): number;
    public set_linear_damp(linearDamp: number): void;
    public get_linear_damp(): number;
    public set_angular_damp(angularDamp: number): void;
    public get_angular_damp(): number;
    public set_priority(priority: number): void;
    public get_priority(): number;
    public set_monitoring(enable: boolean): void;
    public is_monitoring(): boolean;
    public set_monitorable(enable: boolean): void;
    public is_monitorable(): boolean;
    public get_overlapping_bodies(): Array<any>;
    public get_overlapping_areas(): Array<any>;
    public has_overlapping_bodies(): boolean;
    public has_overlapping_areas(): boolean;
    public overlaps_body(body: Node): boolean;
    public overlaps_area(area: Node): boolean;
    public set_audio_bus_name(name: GDString | StringName | string): void;
    public get_audio_bus_name(): StringName;
    public set_audio_bus_override(enable: boolean): void;
    public is_overriding_audio_bus(): boolean;

    
    public readonly body_shape_entered: Signal<(bodyRid: RID, body: Node2D, bodyShapeIndex: number, localShapeIndex: number) => void>;
    public readonly body_shape_exited: Signal<(bodyRid: RID, body: Node2D, bodyShapeIndex: number, localShapeIndex: number) => void>;
    public readonly body_entered: Signal<(body: Node2D) => void>;
    public readonly body_exited: Signal<(body: Node2D) => void>;
    public readonly area_shape_entered: Signal<(areaRid: RID, area: Area2D, areaShapeIndex: number, localShapeIndex: number) => void>;
    public readonly area_shape_exited: Signal<(areaRid: RID, area: Area2D, areaShapeIndex: number, localShapeIndex: number) => void>;
    public readonly area_entered: Signal<(area: Area2D) => void>;
    public readonly area_exited: Signal<(area: Area2D) => void>;

    public static readonly SpaceOverride: {
        SPACE_OVERRIDE_DISABLED: 0;
        SPACE_OVERRIDE_COMBINE: 1;
        SPACE_OVERRIDE_COMBINE_REPLACE: 2;
        SPACE_OVERRIDE_REPLACE: 3;
        SPACE_OVERRIDE_REPLACE_COMBINE: 4;
    };
}

