
import type { Callable } from '@godot/builtins/callable';
import type { GodotObject } from '@godot/classes/godot_object';
import type { PhysicsDirectBodyState2D } from '@godot/classes/physics_direct_body_state2d';
import type { PhysicsDirectSpaceState2D } from '@godot/classes/physics_direct_space_state2d';
import type { PhysicsTestMotionParameters2D } from '@godot/classes/physics_test_motion_parameters2d';
import type { PhysicsTestMotionResult2D } from '@godot/classes/physics_test_motion_result2d';
import type { RID } from '@godot/builtins/rid';
import type { Transform2D } from '@godot/builtins/transform2d';
import type { Vector2 } from '@godot/builtins/vector2';


export declare class PhysicsServer2D extends GodotObject {


    public world_boundary_shape_create(): RID;
    public separation_ray_shape_create(): RID;
    public segment_shape_create(): RID;
    public circle_shape_create(): RID;
    public rectangle_shape_create(): RID;
    public capsule_shape_create(): RID;
    public convex_polygon_shape_create(): RID;
    public concave_polygon_shape_create(): RID;
    public shape_set_data(shape: RID, data: any): void;
    public shape_get_type(shape: RID): number;
    public shape_get_data(shape: RID): any;
    public space_create(): RID;
    public space_set_active(space: RID, active: boolean): void;
    public space_is_active(space: RID): boolean;
    public space_set_param(space: RID, param: number, value: number): void;
    public space_get_param(space: RID, param: number): number;
    public space_get_direct_state(space: RID): PhysicsDirectSpaceState2D;
    public area_create(): RID;
    public area_set_space(area: RID, space: RID): void;
    public area_get_space(area: RID): RID;
    public area_add_shape(area: RID, shape: RID, transform: Transform2D = Transform2D(1, 0, 0, 1, 0, 0), disabled: boolean = false): void;
    public area_set_shape(area: RID, shapeIdx: number, shape: RID): void;
    public area_set_shape_transform(area: RID, shapeIdx: number, transform: Transform2D): void;
    public area_set_shape_disabled(area: RID, shapeIdx: number, disabled: boolean): void;
    public area_get_shape_count(area: RID): number;
    public area_get_shape(area: RID, shapeIdx: number): RID;
    public area_get_shape_transform(area: RID, shapeIdx: number): Transform2D;
    public area_remove_shape(area: RID, shapeIdx: number): void;
    public area_clear_shapes(area: RID): void;
    public area_set_collision_layer(area: RID, layer: number): void;
    public area_get_collision_layer(area: RID): number;
    public area_set_collision_mask(area: RID, mask: number): void;
    public area_get_collision_mask(area: RID): number;
    public area_set_param(area: RID, param: number, value: any): void;
    public area_set_transform(area: RID, transform: Transform2D): void;
    public area_get_param(area: RID, param: number): any;
    public area_get_transform(area: RID): Transform2D;
    public area_attach_object_instance_id(area: RID, id: number): void;
    public area_get_object_instance_id(area: RID): number;
    public area_attach_canvas_instance_id(area: RID, id: number): void;
    public area_get_canvas_instance_id(area: RID): number;
    public area_set_monitor_callback(area: RID, callback: Callable | Function): void;
    public area_set_area_monitor_callback(area: RID, callback: Callable | Function): void;
    public area_set_monitorable(area: RID, monitorable: boolean): void;
    public body_create(): RID;
    public body_set_space(body: RID, space: RID): void;
    public body_get_space(body: RID): RID;
    public body_set_mode(body: RID, mode: number): void;
    public body_get_mode(body: RID): number;
    public body_add_shape(body: RID, shape: RID, transform: Transform2D = Transform2D(1, 0, 0, 1, 0, 0), disabled: boolean = false): void;
    public body_set_shape(body: RID, shapeIdx: number, shape: RID): void;
    public body_set_shape_transform(body: RID, shapeIdx: number, transform: Transform2D): void;
    public body_get_shape_count(body: RID): number;
    public body_get_shape(body: RID, shapeIdx: number): RID;
    public body_get_shape_transform(body: RID, shapeIdx: number): Transform2D;
    public body_remove_shape(body: RID, shapeIdx: number): void;
    public body_clear_shapes(body: RID): void;
    public body_set_shape_disabled(body: RID, shapeIdx: number, disabled: boolean): void;
    public body_set_shape_as_one_way_collision(body: RID, shapeIdx: number, enable: boolean, margin: number): void;
    public body_attach_object_instance_id(body: RID, id: number): void;
    public body_get_object_instance_id(body: RID): number;
    public body_attach_canvas_instance_id(body: RID, id: number): void;
    public body_get_canvas_instance_id(body: RID): number;
    public body_set_continuous_collision_detection_mode(body: RID, mode: number): void;
    public body_get_continuous_collision_detection_mode(body: RID): number;
    public body_set_collision_layer(body: RID, layer: number): void;
    public body_get_collision_layer(body: RID): number;
    public body_set_collision_mask(body: RID, mask: number): void;
    public body_get_collision_mask(body: RID): number;
    public body_set_collision_priority(body: RID, priority: number): void;
    public body_get_collision_priority(body: RID): number;
    public body_set_param(body: RID, param: number, value: any): void;
    public body_get_param(body: RID, param: number): any;
    public body_reset_mass_properties(body: RID): void;
    public body_set_state(body: RID, state: number, value: any): void;
    public body_get_state(body: RID, state: number): any;
    public body_apply_central_impulse(body: RID, impulse: Vector2): void;
    public body_apply_torque_impulse(body: RID, impulse: number): void;
    public body_apply_impulse(body: RID, impulse: Vector2, position: Vector2 = Vector2(0, 0)): void;
    public body_apply_central_force(body: RID, force: Vector2): void;
    public body_apply_force(body: RID, force: Vector2, position: Vector2 = Vector2(0, 0)): void;
    public body_apply_torque(body: RID, torque: number): void;
    public body_add_constant_central_force(body: RID, force: Vector2): void;
    public body_add_constant_force(body: RID, force: Vector2, position: Vector2 = Vector2(0, 0)): void;
    public body_add_constant_torque(body: RID, torque: number): void;
    public body_set_constant_force(body: RID, force: Vector2): void;
    public body_get_constant_force(body: RID): Vector2;
    public body_set_constant_torque(body: RID, torque: number): void;
    public body_get_constant_torque(body: RID): number;
    public body_set_axis_velocity(body: RID, axisVelocity: Vector2): void;
    public body_add_collision_exception(body: RID, exceptedBody: RID): void;
    public body_remove_collision_exception(body: RID, exceptedBody: RID): void;
    public body_set_max_contacts_reported(body: RID, amount: number): void;
    public body_get_max_contacts_reported(body: RID): number;
    public body_set_omit_force_integration(body: RID, enable: boolean): void;
    public body_is_omitting_force_integration(body: RID): boolean;
    public body_set_state_sync_callback(body: RID, callable: Callable | Function): void;
    public body_set_force_integration_callback(body: RID, callable: Callable | Function, userdata: any = null): void;
    public body_test_motion(body: RID, parameters: PhysicsTestMotionParameters2D, result: PhysicsTestMotionResult2D = null): boolean;
    public body_get_direct_state(body: RID): PhysicsDirectBodyState2D;
    public joint_create(): RID;
    public joint_clear(joint: RID): void;
    public joint_set_param(joint: RID, param: number, value: number): void;
    public joint_get_param(joint: RID, param: number): number;
    public joint_disable_collisions_between_bodies(joint: RID, disable: boolean): void;
    public joint_is_disabled_collisions_between_bodies(joint: RID): boolean;
    public joint_make_pin(joint: RID, anchor: Vector2, bodyA: RID, bodyB: RID = RID()): void;
    public joint_make_groove(joint: RID, groove1A: Vector2, groove2A: Vector2, anchorB: Vector2, bodyA: RID = RID(), bodyB: RID = RID()): void;
    public joint_make_damped_spring(joint: RID, anchorA: Vector2, anchorB: Vector2, bodyA: RID, bodyB: RID = RID()): void;
    public pin_joint_set_flag(joint: RID, flag: number, enabled: boolean): void;
    public pin_joint_get_flag(joint: RID, flag: number): boolean;
    public pin_joint_set_param(joint: RID, param: number, value: number): void;
    public pin_joint_get_param(joint: RID, param: number): number;
    public damped_spring_joint_set_param(joint: RID, param: number, value: number): void;
    public damped_spring_joint_get_param(joint: RID, param: number): number;
    public joint_get_type(joint: RID): number;
    public free_rid(rid: RID): void;
    public set_active(active: boolean): void;
    public get_process_info(processInfo: number): number;


    public static readonly SpaceParameter: {
        SPACE_PARAM_CONTACT_RECYCLE_RADIUS: 0;
        SPACE_PARAM_CONTACT_MAX_SEPARATION: 1;
        SPACE_PARAM_CONTACT_MAX_ALLOWED_PENETRATION: 2;
        SPACE_PARAM_CONTACT_DEFAULT_BIAS: 3;
        SPACE_PARAM_BODY_LINEAR_VELOCITY_SLEEP_THRESHOLD: 4;
        SPACE_PARAM_BODY_ANGULAR_VELOCITY_SLEEP_THRESHOLD: 5;
        SPACE_PARAM_BODY_TIME_TO_SLEEP: 6;
        SPACE_PARAM_CONSTRAINT_DEFAULT_BIAS: 7;
        SPACE_PARAM_SOLVER_ITERATIONS: 8;
    };
    public static readonly ShapeType: {
        SHAPE_WORLD_BOUNDARY: 0;
        SHAPE_SEPARATION_RAY: 1;
        SHAPE_SEGMENT: 2;
        SHAPE_CIRCLE: 3;
        SHAPE_RECTANGLE: 4;
        SHAPE_CAPSULE: 5;
        SHAPE_CONVEX_POLYGON: 6;
        SHAPE_CONCAVE_POLYGON: 7;
        SHAPE_CUSTOM: 8;
    };
    public static readonly AreaParameter: {
        AREA_PARAM_GRAVITY_OVERRIDE_MODE: 0;
        AREA_PARAM_GRAVITY: 1;
        AREA_PARAM_GRAVITY_VECTOR: 2;
        AREA_PARAM_GRAVITY_IS_POINT: 3;
        AREA_PARAM_GRAVITY_POINT_UNIT_DISTANCE: 4;
        AREA_PARAM_LINEAR_DAMP_OVERRIDE_MODE: 5;
        AREA_PARAM_LINEAR_DAMP: 6;
        AREA_PARAM_ANGULAR_DAMP_OVERRIDE_MODE: 7;
        AREA_PARAM_ANGULAR_DAMP: 8;
        AREA_PARAM_PRIORITY: 9;
    };
    public static readonly AreaSpaceOverrideMode: {
        AREA_SPACE_OVERRIDE_DISABLED: 0;
        AREA_SPACE_OVERRIDE_COMBINE: 1;
        AREA_SPACE_OVERRIDE_COMBINE_REPLACE: 2;
        AREA_SPACE_OVERRIDE_REPLACE: 3;
        AREA_SPACE_OVERRIDE_REPLACE_COMBINE: 4;
    };
    public static readonly BodyMode: {
        BODY_MODE_STATIC: 0;
        BODY_MODE_KINEMATIC: 1;
        BODY_MODE_RIGID: 2;
        BODY_MODE_RIGID_LINEAR: 3;
    };
    public static readonly BodyParameter: {
        BODY_PARAM_BOUNCE: 0;
        BODY_PARAM_FRICTION: 1;
        BODY_PARAM_MASS: 2;
        BODY_PARAM_INERTIA: 3;
        BODY_PARAM_CENTER_OF_MASS: 4;
        BODY_PARAM_GRAVITY_SCALE: 5;
        BODY_PARAM_LINEAR_DAMP_MODE: 6;
        BODY_PARAM_ANGULAR_DAMP_MODE: 7;
        BODY_PARAM_LINEAR_DAMP: 8;
        BODY_PARAM_ANGULAR_DAMP: 9;
        BODY_PARAM_MAX: 10;
    };
    public static readonly BodyDampMode: {
        BODY_DAMP_MODE_COMBINE: 0;
        BODY_DAMP_MODE_REPLACE: 1;
    };
    public static readonly BodyState: {
        BODY_STATE_TRANSFORM: 0;
        BODY_STATE_LINEAR_VELOCITY: 1;
        BODY_STATE_ANGULAR_VELOCITY: 2;
        BODY_STATE_SLEEPING: 3;
        BODY_STATE_CAN_SLEEP: 4;
    };
    public static readonly JointType: {
        JOINT_TYPE_PIN: 0;
        JOINT_TYPE_GROOVE: 1;
        JOINT_TYPE_DAMPED_SPRING: 2;
        JOINT_TYPE_MAX: 3;
    };
    public static readonly JointParam: {
        JOINT_PARAM_BIAS: 0;
        JOINT_PARAM_MAX_BIAS: 1;
        JOINT_PARAM_MAX_FORCE: 2;
    };
    public static readonly PinJointParam: {
        PIN_JOINT_SOFTNESS: 0;
        PIN_JOINT_LIMIT_UPPER: 1;
        PIN_JOINT_LIMIT_LOWER: 2;
        PIN_JOINT_MOTOR_TARGET_VELOCITY: 3;
    };
    public static readonly PinJointFlag: {
        PIN_JOINT_FLAG_ANGULAR_LIMIT_ENABLED: 0;
        PIN_JOINT_FLAG_MOTOR_ENABLED: 1;
    };
    public static readonly DampedSpringParam: {
        DAMPED_SPRING_REST_LENGTH: 0;
        DAMPED_SPRING_STIFFNESS: 1;
        DAMPED_SPRING_DAMPING: 2;
    };
    public static readonly CCDMode: {
        CCD_MODE_DISABLED: 0;
        CCD_MODE_CAST_RAY: 1;
        CCD_MODE_CAST_SHAPE: 2;
    };
    public static readonly AreaBodyStatus: {
        AREA_BODY_ADDED: 0;
        AREA_BODY_REMOVED: 1;
    };
    public static readonly ProcessInfo: {
        INFO_ACTIVE_OBJECTS: 0;
        INFO_COLLISION_PAIRS: 1;
        INFO_ISLAND_COUNT: 2;
    };
}


/**
 * A singleton instance of PhysicsServer2D.
 * This is a global variable, available from anywhere.
 */
export const PhysicsServer2D: PhysicsServer2D;
