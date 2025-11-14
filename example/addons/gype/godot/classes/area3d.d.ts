
import type { CollisionObject3D } from '@godot/classes/collision_object3d';
import type { GDString } from '@godot/builtins/gd_string';
import type { Node } from '@godot/classes/node';
import type { Node3D } from '@godot/classes/node3d';
import type { NodePath } from '@godot/builtins/node_path';
import type { RID } from '@godot/builtins/rid';
import type { Signal } from '@godot/builtins/signal';
import type { StringName } from '@godot/builtins/string_name';
import type { Vector3 } from '@godot/builtins/vector3';


export declare class Area3D extends CollisionObject3D {

    
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
    /**     * The raw type is 'Vector3'     */
    public gravity_point_center: Vector3;    
    /**     * The raw type is 'Vector3'     */
    public gravity_direction: Vector3;    
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
    /**     * The raw type is 'float'     */
    public wind_force_magnitude: number;    
    /**     * The raw type is 'float'     */
    public wind_attenuation_factor: number;    
    /**     * The raw type is 'NodePath'     */
    public wind_source_path: NodePath;    
    /**     * The raw type is 'bool'     */
    public audio_bus_override: boolean;    
    /**     * The raw type is 'StringName'     */
    public audio_bus_name: StringName;    
    /**     * The raw type is 'bool'     */
    public reverb_bus_enabled: boolean;    
    /**     * The raw type is 'StringName'     */
    public reverb_bus_name: StringName;    
    /**     * The raw type is 'float'     */
    public reverb_bus_amount: number;    
    /**     * The raw type is 'float'     */
    public reverb_bus_uniformity: number;
    public set_gravity_space_override_mode(spaceOverrideMode: number): void;
    public get_gravity_space_override_mode(): number;
    public set_gravity_is_point(enable: boolean): void;
    public is_gravity_a_point(): boolean;
    public set_gravity_point_unit_distance(distanceScale: number): void;
    public get_gravity_point_unit_distance(): number;
    public set_gravity_point_center(center: Vector3): void;
    public get_gravity_point_center(): Vector3;
    public set_gravity_direction(direction: Vector3): void;
    public get_gravity_direction(): Vector3;
    public set_gravity(gravity: number): void;
    public get_gravity(): number;
    public set_linear_damp_space_override_mode(spaceOverrideMode: number): void;
    public get_linear_damp_space_override_mode(): number;
    public set_angular_damp_space_override_mode(spaceOverrideMode: number): void;
    public get_angular_damp_space_override_mode(): number;
    public set_angular_damp(angularDamp: number): void;
    public get_angular_damp(): number;
    public set_linear_damp(linearDamp: number): void;
    public get_linear_damp(): number;
    public set_priority(priority: number): void;
    public get_priority(): number;
    public set_wind_force_magnitude(windForceMagnitude: number): void;
    public get_wind_force_magnitude(): number;
    public set_wind_attenuation_factor(windAttenuationFactor: number): void;
    public get_wind_attenuation_factor(): number;
    public set_wind_source_path(windSourcePath: NodePath | GDString | string): void;
    public get_wind_source_path(): NodePath;
    public set_monitorable(enable: boolean): void;
    public is_monitorable(): boolean;
    public set_monitoring(enable: boolean): void;
    public is_monitoring(): boolean;
    public get_overlapping_bodies(): Array<any>;
    public get_overlapping_areas(): Array<any>;
    public has_overlapping_bodies(): boolean;
    public has_overlapping_areas(): boolean;
    public overlaps_body(body: Node): boolean;
    public overlaps_area(area: Node): boolean;
    public set_audio_bus_override(enable: boolean): void;
    public is_overriding_audio_bus(): boolean;
    public set_audio_bus_name(name: GDString | StringName | string): void;
    public get_audio_bus_name(): StringName;
    public set_use_reverb_bus(enable: boolean): void;
    public is_using_reverb_bus(): boolean;
    public set_reverb_bus_name(name: GDString | StringName | string): void;
    public get_reverb_bus_name(): StringName;
    public set_reverb_amount(amount: number): void;
    public get_reverb_amount(): number;
    public set_reverb_uniformity(amount: number): void;
    public get_reverb_uniformity(): number;

    
    public readonly body_shape_entered: Signal<(bodyRid: RID, body: Node3D, bodyShapeIndex: number, localShapeIndex: number) => void>;
    public readonly body_shape_exited: Signal<(bodyRid: RID, body: Node3D, bodyShapeIndex: number, localShapeIndex: number) => void>;
    public readonly body_entered: Signal<(body: Node3D) => void>;
    public readonly body_exited: Signal<(body: Node3D) => void>;
    public readonly area_shape_entered: Signal<(areaRid: RID, area: Area3D, areaShapeIndex: number, localShapeIndex: number) => void>;
    public readonly area_shape_exited: Signal<(areaRid: RID, area: Area3D, areaShapeIndex: number, localShapeIndex: number) => void>;
    public readonly area_entered: Signal<(area: Area3D) => void>;
    public readonly area_exited: Signal<(area: Area3D) => void>;

    public static readonly SpaceOverride: {
        SPACE_OVERRIDE_DISABLED: 0;
        SPACE_OVERRIDE_COMBINE: 1;
        SPACE_OVERRIDE_COMBINE_REPLACE: 2;
        SPACE_OVERRIDE_REPLACE: 3;
        SPACE_OVERRIDE_REPLACE_COMBINE: 4;
    };
}

