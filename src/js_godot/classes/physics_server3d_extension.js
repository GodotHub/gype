import * as internal from '__internal__';
import { PackedVector3Array } from 'src/js_godot/variant/packed_vector3_array'
import { Variant } from 'src/js_godot/variant/variant'
import { Vector3 } from 'src/js_godot/variant/vector3'
import { Transform3D } from 'src/js_godot/variant/transform3d'
import { AABB } from 'src/js_godot/variant/aabb'
import { RID } from 'src/js_godot/variant/rid'
import { PhysicsServer3D } from 'src/js_godot/classesphysics_server3d'
import { Callable } from 'src/js_godot/variant/callable'
class _MethodBindings {
    method__world_boundary_shape_create;
    method__separation_ray_shape_create;
    method__sphere_shape_create;
    method__box_shape_create;
    method__capsule_shape_create;
    method__cylinder_shape_create;
    method__convex_polygon_shape_create;
    method__concave_polygon_shape_create;
    method__heightmap_shape_create;
    method__custom_shape_create;
    method__shape_set_data;
    method__shape_set_custom_solver_bias;
    method__shape_set_margin;
    method__shape_get_margin;
    method__shape_get_type;
    method__shape_get_data;
    method__shape_get_custom_solver_bias;
    method__space_create;
    method__space_set_active;
    method__space_is_active;
    method__space_set_param;
    method__space_get_param;
    method__space_get_direct_state;
    method__space_set_debug_contacts;
    method__space_get_contacts;
    method__space_get_contact_count;
    method__area_create;
    method__area_set_space;
    method__area_get_space;
    method__area_add_shape;
    method__area_set_shape;
    method__area_set_shape_transform;
    method__area_set_shape_disabled;
    method__area_get_shape_count;
    method__area_get_shape;
    method__area_get_shape_transform;
    method__area_remove_shape;
    method__area_clear_shapes;
    method__area_attach_object_instance_id;
    method__area_get_object_instance_id;
    method__area_set_param;
    method__area_set_transform;
    method__area_get_param;
    method__area_get_transform;
    method__area_set_collision_layer;
    method__area_get_collision_layer;
    method__area_set_collision_mask;
    method__area_get_collision_mask;
    method__area_set_monitorable;
    method__area_set_ray_pickable;
    method__area_set_monitor_callback;
    method__area_set_area_monitor_callback;
    method__body_create;
    method__body_set_space;
    method__body_get_space;
    method__body_set_mode;
    method__body_get_mode;
    method__body_add_shape;
    method__body_set_shape;
    method__body_set_shape_transform;
    method__body_set_shape_disabled;
    method__body_get_shape_count;
    method__body_get_shape;
    method__body_get_shape_transform;
    method__body_remove_shape;
    method__body_clear_shapes;
    method__body_attach_object_instance_id;
    method__body_get_object_instance_id;
    method__body_set_enable_continuous_collision_detection;
    method__body_is_continuous_collision_detection_enabled;
    method__body_set_collision_layer;
    method__body_get_collision_layer;
    method__body_set_collision_mask;
    method__body_get_collision_mask;
    method__body_set_collision_priority;
    method__body_get_collision_priority;
    method__body_set_user_flags;
    method__body_get_user_flags;
    method__body_set_param;
    method__body_get_param;
    method__body_reset_mass_properties;
    method__body_set_state;
    method__body_get_state;
    method__body_apply_central_impulse;
    method__body_apply_impulse;
    method__body_apply_torque_impulse;
    method__body_apply_central_force;
    method__body_apply_force;
    method__body_apply_torque;
    method__body_add_constant_central_force;
    method__body_add_constant_force;
    method__body_add_constant_torque;
    method__body_set_constant_force;
    method__body_get_constant_force;
    method__body_set_constant_torque;
    method__body_get_constant_torque;
    method__body_set_axis_velocity;
    method__body_set_axis_lock;
    method__body_is_axis_locked;
    method__body_add_collision_exception;
    method__body_remove_collision_exception;
    method__body_get_collision_exceptions;
    method__body_set_max_contacts_reported;
    method__body_get_max_contacts_reported;
    method__body_set_contacts_reported_depth_threshold;
    method__body_get_contacts_reported_depth_threshold;
    method__body_set_omit_force_integration;
    method__body_is_omitting_force_integration;
    method__body_set_state_sync_callback;
    method__body_set_force_integration_callback;
    method__body_set_ray_pickable;
    method__body_test_motion;
    method__body_get_direct_state;
    method__soft_body_create;
    method__soft_body_update_rendering_server;
    method__soft_body_set_space;
    method__soft_body_get_space;
    method__soft_body_set_ray_pickable;
    method__soft_body_set_collision_layer;
    method__soft_body_get_collision_layer;
    method__soft_body_set_collision_mask;
    method__soft_body_get_collision_mask;
    method__soft_body_add_collision_exception;
    method__soft_body_remove_collision_exception;
    method__soft_body_get_collision_exceptions;
    method__soft_body_set_state;
    method__soft_body_get_state;
    method__soft_body_set_transform;
    method__soft_body_set_simulation_precision;
    method__soft_body_get_simulation_precision;
    method__soft_body_set_total_mass;
    method__soft_body_get_total_mass;
    method__soft_body_set_linear_stiffness;
    method__soft_body_get_linear_stiffness;
    method__soft_body_set_pressure_coefficient;
    method__soft_body_get_pressure_coefficient;
    method__soft_body_set_damping_coefficient;
    method__soft_body_get_damping_coefficient;
    method__soft_body_set_drag_coefficient;
    method__soft_body_get_drag_coefficient;
    method__soft_body_set_mesh;
    method__soft_body_get_bounds;
    method__soft_body_move_point;
    method__soft_body_get_point_global_position;
    method__soft_body_remove_all_pinned_points;
    method__soft_body_pin_point;
    method__soft_body_is_point_pinned;
    method__joint_create;
    method__joint_clear;
    method__joint_make_pin;
    method__pin_joint_set_param;
    method__pin_joint_get_param;
    method__pin_joint_set_local_a;
    method__pin_joint_get_local_a;
    method__pin_joint_set_local_b;
    method__pin_joint_get_local_b;
    method__joint_make_hinge;
    method__joint_make_hinge_simple;
    method__hinge_joint_set_param;
    method__hinge_joint_get_param;
    method__hinge_joint_set_flag;
    method__hinge_joint_get_flag;
    method__joint_make_slider;
    method__slider_joint_set_param;
    method__slider_joint_get_param;
    method__joint_make_cone_twist;
    method__cone_twist_joint_set_param;
    method__cone_twist_joint_get_param;
    method__joint_make_generic_6dof;
    method__generic_6dof_joint_set_param;
    method__generic_6dof_joint_get_param;
    method__generic_6dof_joint_set_flag;
    method__generic_6dof_joint_get_flag;
    method__joint_get_type;
    method__joint_set_solver_priority;
    method__joint_get_solver_priority;
    method__joint_disable_collisions_between_bodies;
    method__joint_is_disabled_collisions_between_bodies;
    method__free_rid;
    method__set_active;
    method__init;
    method__step;
    method__sync;
    method__flush_queries;
    method__end_sync;
    method__finish;
    method__is_flushing_queries;
    method__get_process_info;
    method_body_test_motion_is_excluding_body;
    method_body_test_motion_is_excluding_object;
}


export class PhysicsServer3DExtension extends PhysicsServer3D{

  static _bindings = new _MethodBindings();

  constructor(godot_object) {
    if (!godot_object) {
      super("PhysicsServer3DExtension");
    } else {
      super(godot_object);
    }
  }
  
  static _init_bindings() {
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_world_boundary_shape_create");
      this._bindings.method__world_boundary_shape_create = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_separation_ray_shape_create");
      this._bindings.method__separation_ray_shape_create = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_sphere_shape_create");
      this._bindings.method__sphere_shape_create = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_box_shape_create");
      this._bindings.method__box_shape_create = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_capsule_shape_create");
      this._bindings.method__capsule_shape_create = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_cylinder_shape_create");
      this._bindings.method__cylinder_shape_create = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_convex_polygon_shape_create");
      this._bindings.method__convex_polygon_shape_create = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_concave_polygon_shape_create");
      this._bindings.method__concave_polygon_shape_create = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_heightmap_shape_create");
      this._bindings.method__heightmap_shape_create = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_custom_shape_create");
      this._bindings.method__custom_shape_create = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_shape_set_data");
      this._bindings.method__shape_set_data = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_shape_set_custom_solver_bias");
      this._bindings.method__shape_set_custom_solver_bias = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_shape_set_margin");
      this._bindings.method__shape_set_margin = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_shape_get_margin");
      this._bindings.method__shape_get_margin = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_shape_get_type");
      this._bindings.method__shape_get_type = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_shape_get_data");
      this._bindings.method__shape_get_data = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_shape_get_custom_solver_bias");
      this._bindings.method__shape_get_custom_solver_bias = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_space_create");
      this._bindings.method__space_create = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_space_set_active");
      this._bindings.method__space_set_active = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_space_is_active");
      this._bindings.method__space_is_active = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_space_set_param");
      this._bindings.method__space_set_param = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_space_get_param");
      this._bindings.method__space_get_param = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_space_get_direct_state");
      this._bindings.method__space_get_direct_state = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_space_set_debug_contacts");
      this._bindings.method__space_set_debug_contacts = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_space_get_contacts");
      this._bindings.method__space_get_contacts = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_space_get_contact_count");
      this._bindings.method__space_get_contact_count = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_area_create");
      this._bindings.method__area_create = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_area_set_space");
      this._bindings.method__area_set_space = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_area_get_space");
      this._bindings.method__area_get_space = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_area_add_shape");
      this._bindings.method__area_add_shape = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_area_set_shape");
      this._bindings.method__area_set_shape = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_area_set_shape_transform");
      this._bindings.method__area_set_shape_transform = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_area_set_shape_disabled");
      this._bindings.method__area_set_shape_disabled = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_area_get_shape_count");
      this._bindings.method__area_get_shape_count = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_area_get_shape");
      this._bindings.method__area_get_shape = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_area_get_shape_transform");
      this._bindings.method__area_get_shape_transform = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_area_remove_shape");
      this._bindings.method__area_remove_shape = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_area_clear_shapes");
      this._bindings.method__area_clear_shapes = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_area_attach_object_instance_id");
      this._bindings.method__area_attach_object_instance_id = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_area_get_object_instance_id");
      this._bindings.method__area_get_object_instance_id = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_area_set_param");
      this._bindings.method__area_set_param = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_area_set_transform");
      this._bindings.method__area_set_transform = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_area_get_param");
      this._bindings.method__area_get_param = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_area_get_transform");
      this._bindings.method__area_get_transform = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_area_set_collision_layer");
      this._bindings.method__area_set_collision_layer = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_area_get_collision_layer");
      this._bindings.method__area_get_collision_layer = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_area_set_collision_mask");
      this._bindings.method__area_set_collision_mask = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_area_get_collision_mask");
      this._bindings.method__area_get_collision_mask = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_area_set_monitorable");
      this._bindings.method__area_set_monitorable = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_area_set_ray_pickable");
      this._bindings.method__area_set_ray_pickable = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_area_set_monitor_callback");
      this._bindings.method__area_set_monitor_callback = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_area_set_area_monitor_callback");
      this._bindings.method__area_set_area_monitor_callback = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_create");
      this._bindings.method__body_create = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_set_space");
      this._bindings.method__body_set_space = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_get_space");
      this._bindings.method__body_get_space = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_set_mode");
      this._bindings.method__body_set_mode = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_get_mode");
      this._bindings.method__body_get_mode = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_add_shape");
      this._bindings.method__body_add_shape = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_set_shape");
      this._bindings.method__body_set_shape = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_set_shape_transform");
      this._bindings.method__body_set_shape_transform = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_set_shape_disabled");
      this._bindings.method__body_set_shape_disabled = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_get_shape_count");
      this._bindings.method__body_get_shape_count = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_get_shape");
      this._bindings.method__body_get_shape = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_get_shape_transform");
      this._bindings.method__body_get_shape_transform = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_remove_shape");
      this._bindings.method__body_remove_shape = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_clear_shapes");
      this._bindings.method__body_clear_shapes = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_attach_object_instance_id");
      this._bindings.method__body_attach_object_instance_id = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_get_object_instance_id");
      this._bindings.method__body_get_object_instance_id = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_set_enable_continuous_collision_detection");
      this._bindings.method__body_set_enable_continuous_collision_detection = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_is_continuous_collision_detection_enabled");
      this._bindings.method__body_is_continuous_collision_detection_enabled = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_set_collision_layer");
      this._bindings.method__body_set_collision_layer = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_get_collision_layer");
      this._bindings.method__body_get_collision_layer = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_set_collision_mask");
      this._bindings.method__body_set_collision_mask = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_get_collision_mask");
      this._bindings.method__body_get_collision_mask = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_set_collision_priority");
      this._bindings.method__body_set_collision_priority = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_get_collision_priority");
      this._bindings.method__body_get_collision_priority = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_set_user_flags");
      this._bindings.method__body_set_user_flags = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_get_user_flags");
      this._bindings.method__body_get_user_flags = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_set_param");
      this._bindings.method__body_set_param = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_get_param");
      this._bindings.method__body_get_param = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_reset_mass_properties");
      this._bindings.method__body_reset_mass_properties = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_set_state");
      this._bindings.method__body_set_state = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_get_state");
      this._bindings.method__body_get_state = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_apply_central_impulse");
      this._bindings.method__body_apply_central_impulse = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_apply_impulse");
      this._bindings.method__body_apply_impulse = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_apply_torque_impulse");
      this._bindings.method__body_apply_torque_impulse = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_apply_central_force");
      this._bindings.method__body_apply_central_force = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_apply_force");
      this._bindings.method__body_apply_force = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_apply_torque");
      this._bindings.method__body_apply_torque = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_add_constant_central_force");
      this._bindings.method__body_add_constant_central_force = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_add_constant_force");
      this._bindings.method__body_add_constant_force = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_add_constant_torque");
      this._bindings.method__body_add_constant_torque = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_set_constant_force");
      this._bindings.method__body_set_constant_force = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_get_constant_force");
      this._bindings.method__body_get_constant_force = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_set_constant_torque");
      this._bindings.method__body_set_constant_torque = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_get_constant_torque");
      this._bindings.method__body_get_constant_torque = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_set_axis_velocity");
      this._bindings.method__body_set_axis_velocity = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_set_axis_lock");
      this._bindings.method__body_set_axis_lock = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_is_axis_locked");
      this._bindings.method__body_is_axis_locked = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_add_collision_exception");
      this._bindings.method__body_add_collision_exception = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_remove_collision_exception");
      this._bindings.method__body_remove_collision_exception = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_get_collision_exceptions");
      this._bindings.method__body_get_collision_exceptions = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_set_max_contacts_reported");
      this._bindings.method__body_set_max_contacts_reported = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_get_max_contacts_reported");
      this._bindings.method__body_get_max_contacts_reported = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_set_contacts_reported_depth_threshold");
      this._bindings.method__body_set_contacts_reported_depth_threshold = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_get_contacts_reported_depth_threshold");
      this._bindings.method__body_get_contacts_reported_depth_threshold = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_set_omit_force_integration");
      this._bindings.method__body_set_omit_force_integration = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_is_omitting_force_integration");
      this._bindings.method__body_is_omitting_force_integration = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_set_state_sync_callback");
      this._bindings.method__body_set_state_sync_callback = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_set_force_integration_callback");
      this._bindings.method__body_set_force_integration_callback = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_set_ray_pickable");
      this._bindings.method__body_set_ray_pickable = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_test_motion");
      this._bindings.method__body_test_motion = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_body_get_direct_state");
      this._bindings.method__body_get_direct_state = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_soft_body_create");
      this._bindings.method__soft_body_create = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_soft_body_update_rendering_server");
      this._bindings.method__soft_body_update_rendering_server = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_soft_body_set_space");
      this._bindings.method__soft_body_set_space = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_soft_body_get_space");
      this._bindings.method__soft_body_get_space = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_soft_body_set_ray_pickable");
      this._bindings.method__soft_body_set_ray_pickable = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_soft_body_set_collision_layer");
      this._bindings.method__soft_body_set_collision_layer = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_soft_body_get_collision_layer");
      this._bindings.method__soft_body_get_collision_layer = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_soft_body_set_collision_mask");
      this._bindings.method__soft_body_set_collision_mask = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_soft_body_get_collision_mask");
      this._bindings.method__soft_body_get_collision_mask = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_soft_body_add_collision_exception");
      this._bindings.method__soft_body_add_collision_exception = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_soft_body_remove_collision_exception");
      this._bindings.method__soft_body_remove_collision_exception = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_soft_body_get_collision_exceptions");
      this._bindings.method__soft_body_get_collision_exceptions = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_soft_body_set_state");
      this._bindings.method__soft_body_set_state = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_soft_body_get_state");
      this._bindings.method__soft_body_get_state = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_soft_body_set_transform");
      this._bindings.method__soft_body_set_transform = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_soft_body_set_simulation_precision");
      this._bindings.method__soft_body_set_simulation_precision = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_soft_body_get_simulation_precision");
      this._bindings.method__soft_body_get_simulation_precision = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_soft_body_set_total_mass");
      this._bindings.method__soft_body_set_total_mass = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_soft_body_get_total_mass");
      this._bindings.method__soft_body_get_total_mass = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_soft_body_set_linear_stiffness");
      this._bindings.method__soft_body_set_linear_stiffness = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_soft_body_get_linear_stiffness");
      this._bindings.method__soft_body_get_linear_stiffness = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_soft_body_set_pressure_coefficient");
      this._bindings.method__soft_body_set_pressure_coefficient = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_soft_body_get_pressure_coefficient");
      this._bindings.method__soft_body_get_pressure_coefficient = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_soft_body_set_damping_coefficient");
      this._bindings.method__soft_body_set_damping_coefficient = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_soft_body_get_damping_coefficient");
      this._bindings.method__soft_body_get_damping_coefficient = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_soft_body_set_drag_coefficient");
      this._bindings.method__soft_body_set_drag_coefficient = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_soft_body_get_drag_coefficient");
      this._bindings.method__soft_body_get_drag_coefficient = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_soft_body_set_mesh");
      this._bindings.method__soft_body_set_mesh = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_soft_body_get_bounds");
      this._bindings.method__soft_body_get_bounds = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_soft_body_move_point");
      this._bindings.method__soft_body_move_point = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_soft_body_get_point_global_position");
      this._bindings.method__soft_body_get_point_global_position = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_soft_body_remove_all_pinned_points");
      this._bindings.method__soft_body_remove_all_pinned_points = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_soft_body_pin_point");
      this._bindings.method__soft_body_pin_point = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_soft_body_is_point_pinned");
      this._bindings.method__soft_body_is_point_pinned = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_joint_create");
      this._bindings.method__joint_create = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_joint_clear");
      this._bindings.method__joint_clear = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_joint_make_pin");
      this._bindings.method__joint_make_pin = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_pin_joint_set_param");
      this._bindings.method__pin_joint_set_param = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_pin_joint_get_param");
      this._bindings.method__pin_joint_get_param = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_pin_joint_set_local_a");
      this._bindings.method__pin_joint_set_local_a = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_pin_joint_get_local_a");
      this._bindings.method__pin_joint_get_local_a = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_pin_joint_set_local_b");
      this._bindings.method__pin_joint_set_local_b = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_pin_joint_get_local_b");
      this._bindings.method__pin_joint_get_local_b = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_joint_make_hinge");
      this._bindings.method__joint_make_hinge = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_joint_make_hinge_simple");
      this._bindings.method__joint_make_hinge_simple = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_hinge_joint_set_param");
      this._bindings.method__hinge_joint_set_param = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_hinge_joint_get_param");
      this._bindings.method__hinge_joint_get_param = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_hinge_joint_set_flag");
      this._bindings.method__hinge_joint_set_flag = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_hinge_joint_get_flag");
      this._bindings.method__hinge_joint_get_flag = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_joint_make_slider");
      this._bindings.method__joint_make_slider = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_slider_joint_set_param");
      this._bindings.method__slider_joint_set_param = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_slider_joint_get_param");
      this._bindings.method__slider_joint_get_param = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_joint_make_cone_twist");
      this._bindings.method__joint_make_cone_twist = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_cone_twist_joint_set_param");
      this._bindings.method__cone_twist_joint_set_param = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_cone_twist_joint_get_param");
      this._bindings.method__cone_twist_joint_get_param = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_joint_make_generic_6dof");
      this._bindings.method__joint_make_generic_6dof = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_generic_6dof_joint_set_param");
      this._bindings.method__generic_6dof_joint_set_param = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_generic_6dof_joint_get_param");
      this._bindings.method__generic_6dof_joint_get_param = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_generic_6dof_joint_set_flag");
      this._bindings.method__generic_6dof_joint_set_flag = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_generic_6dof_joint_get_flag");
      this._bindings.method__generic_6dof_joint_get_flag = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_joint_get_type");
      this._bindings.method__joint_get_type = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_joint_set_solver_priority");
      this._bindings.method__joint_set_solver_priority = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_joint_get_solver_priority");
      this._bindings.method__joint_get_solver_priority = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_joint_disable_collisions_between_bodies");
      this._bindings.method__joint_disable_collisions_between_bodies = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_joint_is_disabled_collisions_between_bodies");
      this._bindings.method__joint_is_disabled_collisions_between_bodies = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_free_rid");
      this._bindings.method__free_rid = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_set_active");
      this._bindings.method__set_active = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_init");
      this._bindings.method__init = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_step");
      this._bindings.method__step = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_sync");
      this._bindings.method__sync = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_flush_queries");
      this._bindings.method__flush_queries = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_end_sync");
      this._bindings.method__end_sync = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_finish");
      this._bindings.method__finish = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_is_flushing_queries");
      this._bindings.method__is_flushing_queries = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("_get_process_info");
      this._bindings.method__get_process_info = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("body_test_motion_is_excluding_body");
      this._bindings.method_body_test_motion_is_excluding_body = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        4155700596
      );
    }
    {
      let classname = new StringName("PhysicsServer3DExtension");
      let methodname = new StringName("body_test_motion_is_excluding_object");
      this._bindings.method_body_test_motion_is_excluding_object = internal.classdb_get_method_bind(
        classname.opaque, 
        methodname.opaque, 
        1116898809
      );
    }
  }
  _world_boundary_shape_create() {
    return _call_native_mb_ret(
      ClassDB._bindings.method__world_boundary_shape_create,
      this._owner,
			Variant.Type.RID
    ,
      
    );
  }
  _separation_ray_shape_create() {
    return _call_native_mb_ret(
      ClassDB._bindings.method__separation_ray_shape_create,
      this._owner,
			Variant.Type.RID
    ,
      
    );
  }
  _sphere_shape_create() {
    return _call_native_mb_ret(
      ClassDB._bindings.method__sphere_shape_create,
      this._owner,
			Variant.Type.RID
    ,
      
    );
  }
  _box_shape_create() {
    return _call_native_mb_ret(
      ClassDB._bindings.method__box_shape_create,
      this._owner,
			Variant.Type.RID
    ,
      
    );
  }
  _capsule_shape_create() {
    return _call_native_mb_ret(
      ClassDB._bindings.method__capsule_shape_create,
      this._owner,
			Variant.Type.RID
    ,
      
    );
  }
  _cylinder_shape_create() {
    return _call_native_mb_ret(
      ClassDB._bindings.method__cylinder_shape_create,
      this._owner,
			Variant.Type.RID
    ,
      
    );
  }
  _convex_polygon_shape_create() {
    return _call_native_mb_ret(
      ClassDB._bindings.method__convex_polygon_shape_create,
      this._owner,
			Variant.Type.RID
    ,
      
    );
  }
  _concave_polygon_shape_create() {
    return _call_native_mb_ret(
      ClassDB._bindings.method__concave_polygon_shape_create,
      this._owner,
			Variant.Type.RID
    ,
      
    );
  }
  _heightmap_shape_create() {
    return _call_native_mb_ret(
      ClassDB._bindings.method__heightmap_shape_create,
      this._owner,
			Variant.Type.RID
    ,
      
    );
  }
  _custom_shape_create() {
    return _call_native_mb_ret(
      ClassDB._bindings.method__custom_shape_create,
      this._owner,
			Variant.Type.RID
    ,
      
    );
  }
  _shape_set_data(_shape, _data) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__shape_set_data,
      this._owner,
      _shape, _data
    );
  }
  _shape_set_custom_solver_bias(_shape, _bias) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__shape_set_custom_solver_bias,
      this._owner,
      _shape, _bias
    );
  }
  _shape_set_margin(_shape, _margin) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__shape_set_margin,
      this._owner,
      _shape, _margin
    );
  }
  _shape_get_margin(_shape) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__shape_get_margin,
      this._owner,
			Variant.Type.FLOAT,
      _shape
    );
  }
  _shape_get_type(_shape) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__shape_get_type,
      this._owner,
			Variant.INT,
      _shape
    );
  }
  _shape_get_data(_shape) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__shape_get_data,
      this._owner,
			Variant.Type.VARIANT
    ,
      _shape
    );
  }
  _shape_get_custom_solver_bias(_shape) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__shape_get_custom_solver_bias,
      this._owner,
			Variant.Type.FLOAT,
      _shape
    );
  }
  _space_create() {
    return _call_native_mb_ret(
      ClassDB._bindings.method__space_create,
      this._owner,
			Variant.Type.RID
    ,
      
    );
  }
  _space_set_active(_space, _active) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__space_set_active,
      this._owner,
      _space, _active
    );
  }
  _space_is_active(_space) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__space_is_active,
      this._owner,
			Variant.Type.BOOL,
      _space
    );
  }
  _space_set_param(_space, _param, _value) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__space_set_param,
      this._owner,
      _space, _param, _value
    );
  }
  _space_get_param(_space, _param) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__space_get_param,
      this._owner,
			Variant.Type.FLOAT,
      _space, _param
    );
  }
  _space_get_direct_state(_space) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__space_get_direct_state,
      this._owner,
			Variant.INT,
      _space
    );
  }
  _space_set_debug_contacts(_space, _max_contacts) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__space_set_debug_contacts,
      this._owner,
      _space, _max_contacts
    );
  }
  _space_get_contacts(_space) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__space_get_contacts,
      this._owner,
			Variant.Type.PACKED_VECTOR3_ARRAY
    ,
      _space
    );
  }
  _space_get_contact_count(_space) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__space_get_contact_count,
      this._owner,
			Variant.Type.INT,
      _space
    );
  }
  _area_create() {
    return _call_native_mb_ret(
      ClassDB._bindings.method__area_create,
      this._owner,
			Variant.Type.RID
    ,
      
    );
  }
  _area_set_space(_area, _space) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__area_set_space,
      this._owner,
      _area, _space
    );
  }
  _area_get_space(_area) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__area_get_space,
      this._owner,
			Variant.Type.RID
    ,
      _area
    );
  }
  _area_add_shape(_area, _shape, _transform, _disabled) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__area_add_shape,
      this._owner,
      _area, _shape, _transform, _disabled
    );
  }
  _area_set_shape(_area, _shape_idx, _shape) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__area_set_shape,
      this._owner,
      _area, _shape_idx, _shape
    );
  }
  _area_set_shape_transform(_area, _shape_idx, _transform) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__area_set_shape_transform,
      this._owner,
      _area, _shape_idx, _transform
    );
  }
  _area_set_shape_disabled(_area, _shape_idx, _disabled) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__area_set_shape_disabled,
      this._owner,
      _area, _shape_idx, _disabled
    );
  }
  _area_get_shape_count(_area) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__area_get_shape_count,
      this._owner,
			Variant.Type.INT,
      _area
    );
  }
  _area_get_shape(_area, _shape_idx) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__area_get_shape,
      this._owner,
			Variant.Type.RID
    ,
      _area, _shape_idx
    );
  }
  _area_get_shape_transform(_area, _shape_idx) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__area_get_shape_transform,
      this._owner,
			Variant.Type.TRANSFORM3D
    ,
      _area, _shape_idx
    );
  }
  _area_remove_shape(_area, _shape_idx) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__area_remove_shape,
      this._owner,
      _area, _shape_idx
    );
  }
  _area_clear_shapes(_area) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__area_clear_shapes,
      this._owner,
      _area
    );
  }
  _area_attach_object_instance_id(_area, _id) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__area_attach_object_instance_id,
      this._owner,
      _area, _id
    );
  }
  _area_get_object_instance_id(_area) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__area_get_object_instance_id,
      this._owner,
			Variant.Type.INT,
      _area
    );
  }
  _area_set_param(_area, _param, _value) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__area_set_param,
      this._owner,
      _area, _param, _value
    );
  }
  _area_set_transform(_area, _transform) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__area_set_transform,
      this._owner,
      _area, _transform
    );
  }
  _area_get_param(_area, _param) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__area_get_param,
      this._owner,
			Variant.Type.VARIANT
    ,
      _area, _param
    );
  }
  _area_get_transform(_area) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__area_get_transform,
      this._owner,
			Variant.Type.TRANSFORM3D
    ,
      _area
    );
  }
  _area_set_collision_layer(_area, _layer) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__area_set_collision_layer,
      this._owner,
      _area, _layer
    );
  }
  _area_get_collision_layer(_area) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__area_get_collision_layer,
      this._owner,
			Variant.Type.INT,
      _area
    );
  }
  _area_set_collision_mask(_area, _mask) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__area_set_collision_mask,
      this._owner,
      _area, _mask
    );
  }
  _area_get_collision_mask(_area) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__area_get_collision_mask,
      this._owner,
			Variant.Type.INT,
      _area
    );
  }
  _area_set_monitorable(_area, _monitorable) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__area_set_monitorable,
      this._owner,
      _area, _monitorable
    );
  }
  _area_set_ray_pickable(_area, _enable) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__area_set_ray_pickable,
      this._owner,
      _area, _enable
    );
  }
  _area_set_monitor_callback(_area, _callback) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__area_set_monitor_callback,
      this._owner,
      _area, _callback
    );
  }
  _area_set_area_monitor_callback(_area, _callback) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__area_set_area_monitor_callback,
      this._owner,
      _area, _callback
    );
  }
  _body_create() {
    return _call_native_mb_ret(
      ClassDB._bindings.method__body_create,
      this._owner,
			Variant.Type.RID
    ,
      
    );
  }
  _body_set_space(_body, _space) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__body_set_space,
      this._owner,
      _body, _space
    );
  }
  _body_get_space(_body) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__body_get_space,
      this._owner,
			Variant.Type.RID
    ,
      _body
    );
  }
  _body_set_mode(_body, _mode) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__body_set_mode,
      this._owner,
      _body, _mode
    );
  }
  _body_get_mode(_body) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__body_get_mode,
      this._owner,
			Variant.INT,
      _body
    );
  }
  _body_add_shape(_body, _shape, _transform, _disabled) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__body_add_shape,
      this._owner,
      _body, _shape, _transform, _disabled
    );
  }
  _body_set_shape(_body, _shape_idx, _shape) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__body_set_shape,
      this._owner,
      _body, _shape_idx, _shape
    );
  }
  _body_set_shape_transform(_body, _shape_idx, _transform) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__body_set_shape_transform,
      this._owner,
      _body, _shape_idx, _transform
    );
  }
  _body_set_shape_disabled(_body, _shape_idx, _disabled) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__body_set_shape_disabled,
      this._owner,
      _body, _shape_idx, _disabled
    );
  }
  _body_get_shape_count(_body) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__body_get_shape_count,
      this._owner,
			Variant.Type.INT,
      _body
    );
  }
  _body_get_shape(_body, _shape_idx) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__body_get_shape,
      this._owner,
			Variant.Type.RID
    ,
      _body, _shape_idx
    );
  }
  _body_get_shape_transform(_body, _shape_idx) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__body_get_shape_transform,
      this._owner,
			Variant.Type.TRANSFORM3D
    ,
      _body, _shape_idx
    );
  }
  _body_remove_shape(_body, _shape_idx) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__body_remove_shape,
      this._owner,
      _body, _shape_idx
    );
  }
  _body_clear_shapes(_body) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__body_clear_shapes,
      this._owner,
      _body
    );
  }
  _body_attach_object_instance_id(_body, _id) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__body_attach_object_instance_id,
      this._owner,
      _body, _id
    );
  }
  _body_get_object_instance_id(_body) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__body_get_object_instance_id,
      this._owner,
			Variant.Type.INT,
      _body
    );
  }
  _body_set_enable_continuous_collision_detection(_body, _enable) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__body_set_enable_continuous_collision_detection,
      this._owner,
      _body, _enable
    );
  }
  _body_is_continuous_collision_detection_enabled(_body) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__body_is_continuous_collision_detection_enabled,
      this._owner,
			Variant.Type.BOOL,
      _body
    );
  }
  _body_set_collision_layer(_body, _layer) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__body_set_collision_layer,
      this._owner,
      _body, _layer
    );
  }
  _body_get_collision_layer(_body) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__body_get_collision_layer,
      this._owner,
			Variant.Type.INT,
      _body
    );
  }
  _body_set_collision_mask(_body, _mask) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__body_set_collision_mask,
      this._owner,
      _body, _mask
    );
  }
  _body_get_collision_mask(_body) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__body_get_collision_mask,
      this._owner,
			Variant.Type.INT,
      _body
    );
  }
  _body_set_collision_priority(_body, _priority) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__body_set_collision_priority,
      this._owner,
      _body, _priority
    );
  }
  _body_get_collision_priority(_body) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__body_get_collision_priority,
      this._owner,
			Variant.Type.FLOAT,
      _body
    );
  }
  _body_set_user_flags(_body, _flags) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__body_set_user_flags,
      this._owner,
      _body, _flags
    );
  }
  _body_get_user_flags(_body) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__body_get_user_flags,
      this._owner,
			Variant.Type.INT,
      _body
    );
  }
  _body_set_param(_body, _param, _value) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__body_set_param,
      this._owner,
      _body, _param, _value
    );
  }
  _body_get_param(_body, _param) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__body_get_param,
      this._owner,
			Variant.Type.VARIANT
    ,
      _body, _param
    );
  }
  _body_reset_mass_properties(_body) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__body_reset_mass_properties,
      this._owner,
      _body
    );
  }
  _body_set_state(_body, _state, _value) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__body_set_state,
      this._owner,
      _body, _state, _value
    );
  }
  _body_get_state(_body, _state) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__body_get_state,
      this._owner,
			Variant.Type.VARIANT
    ,
      _body, _state
    );
  }
  _body_apply_central_impulse(_body, _impulse) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__body_apply_central_impulse,
      this._owner,
      _body, _impulse
    );
  }
  _body_apply_impulse(_body, _impulse, _position) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__body_apply_impulse,
      this._owner,
      _body, _impulse, _position
    );
  }
  _body_apply_torque_impulse(_body, _impulse) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__body_apply_torque_impulse,
      this._owner,
      _body, _impulse
    );
  }
  _body_apply_central_force(_body, _force) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__body_apply_central_force,
      this._owner,
      _body, _force
    );
  }
  _body_apply_force(_body, _force, _position) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__body_apply_force,
      this._owner,
      _body, _force, _position
    );
  }
  _body_apply_torque(_body, _torque) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__body_apply_torque,
      this._owner,
      _body, _torque
    );
  }
  _body_add_constant_central_force(_body, _force) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__body_add_constant_central_force,
      this._owner,
      _body, _force
    );
  }
  _body_add_constant_force(_body, _force, _position) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__body_add_constant_force,
      this._owner,
      _body, _force, _position
    );
  }
  _body_add_constant_torque(_body, _torque) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__body_add_constant_torque,
      this._owner,
      _body, _torque
    );
  }
  _body_set_constant_force(_body, _force) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__body_set_constant_force,
      this._owner,
      _body, _force
    );
  }
  _body_get_constant_force(_body) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__body_get_constant_force,
      this._owner,
			Variant.Type.VECTOR3
    ,
      _body
    );
  }
  _body_set_constant_torque(_body, _torque) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__body_set_constant_torque,
      this._owner,
      _body, _torque
    );
  }
  _body_get_constant_torque(_body) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__body_get_constant_torque,
      this._owner,
			Variant.Type.VECTOR3
    ,
      _body
    );
  }
  _body_set_axis_velocity(_body, _axis_velocity) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__body_set_axis_velocity,
      this._owner,
      _body, _axis_velocity
    );
  }
  _body_set_axis_lock(_body, _axis, _lock) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__body_set_axis_lock,
      this._owner,
      _body, _axis, _lock
    );
  }
  _body_is_axis_locked(_body, _axis) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__body_is_axis_locked,
      this._owner,
			Variant.Type.BOOL,
      _body, _axis
    );
  }
  _body_add_collision_exception(_body, _excepted_body) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__body_add_collision_exception,
      this._owner,
      _body, _excepted_body
    );
  }
  _body_remove_collision_exception(_body, _excepted_body) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__body_remove_collision_exception,
      this._owner,
      _body, _excepted_body
    );
  }
  _body_get_collision_exceptions(_body) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__body_get_collision_exceptions,
      this._owner,
			Variant.INT,
      _body
    );
  }
  _body_set_max_contacts_reported(_body, _amount) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__body_set_max_contacts_reported,
      this._owner,
      _body, _amount
    );
  }
  _body_get_max_contacts_reported(_body) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__body_get_max_contacts_reported,
      this._owner,
			Variant.Type.INT,
      _body
    );
  }
  _body_set_contacts_reported_depth_threshold(_body, _threshold) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__body_set_contacts_reported_depth_threshold,
      this._owner,
      _body, _threshold
    );
  }
  _body_get_contacts_reported_depth_threshold(_body) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__body_get_contacts_reported_depth_threshold,
      this._owner,
			Variant.Type.FLOAT,
      _body
    );
  }
  _body_set_omit_force_integration(_body, _enable) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__body_set_omit_force_integration,
      this._owner,
      _body, _enable
    );
  }
  _body_is_omitting_force_integration(_body) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__body_is_omitting_force_integration,
      this._owner,
			Variant.Type.BOOL,
      _body
    );
  }
  _body_set_state_sync_callback(_body, _callable) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__body_set_state_sync_callback,
      this._owner,
      _body, _callable
    );
  }
  _body_set_force_integration_callback(_body, _callable, _userdata) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__body_set_force_integration_callback,
      this._owner,
      _body, _callable, _userdata
    );
  }
  _body_set_ray_pickable(_body, _enable) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__body_set_ray_pickable,
      this._owner,
      _body, _enable
    );
  }
  _body_test_motion(_body, _from, _motion, _margin, _max_collisions, _collide_separation_ray, _recovery_as_collision, _result) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__body_test_motion,
      this._owner,
			Variant.Type.BOOL,
      _body, _from, _motion, _margin, _max_collisions, _collide_separation_ray, _recovery_as_collision, _result
    );
  }
  _body_get_direct_state(_body) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__body_get_direct_state,
      this._owner,
			Variant.INT,
      _body
    );
  }
  _soft_body_create() {
    return _call_native_mb_ret(
      ClassDB._bindings.method__soft_body_create,
      this._owner,
			Variant.Type.RID
    ,
      
    );
  }
  _soft_body_update_rendering_server(_body, _rendering_server_handler) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__soft_body_update_rendering_server,
      this._owner,
      _body, _rendering_server_handler
    );
  }
  _soft_body_set_space(_body, _space) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__soft_body_set_space,
      this._owner,
      _body, _space
    );
  }
  _soft_body_get_space(_body) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__soft_body_get_space,
      this._owner,
			Variant.Type.RID
    ,
      _body
    );
  }
  _soft_body_set_ray_pickable(_body, _enable) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__soft_body_set_ray_pickable,
      this._owner,
      _body, _enable
    );
  }
  _soft_body_set_collision_layer(_body, _layer) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__soft_body_set_collision_layer,
      this._owner,
      _body, _layer
    );
  }
  _soft_body_get_collision_layer(_body) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__soft_body_get_collision_layer,
      this._owner,
			Variant.Type.INT,
      _body
    );
  }
  _soft_body_set_collision_mask(_body, _mask) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__soft_body_set_collision_mask,
      this._owner,
      _body, _mask
    );
  }
  _soft_body_get_collision_mask(_body) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__soft_body_get_collision_mask,
      this._owner,
			Variant.Type.INT,
      _body
    );
  }
  _soft_body_add_collision_exception(_body, _body_b) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__soft_body_add_collision_exception,
      this._owner,
      _body, _body_b
    );
  }
  _soft_body_remove_collision_exception(_body, _body_b) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__soft_body_remove_collision_exception,
      this._owner,
      _body, _body_b
    );
  }
  _soft_body_get_collision_exceptions(_body) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__soft_body_get_collision_exceptions,
      this._owner,
			Variant.INT,
      _body
    );
  }
  _soft_body_set_state(_body, _state, _variant) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__soft_body_set_state,
      this._owner,
      _body, _state, _variant
    );
  }
  _soft_body_get_state(_body, _state) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__soft_body_get_state,
      this._owner,
			Variant.Type.VARIANT
    ,
      _body, _state
    );
  }
  _soft_body_set_transform(_body, _transform) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__soft_body_set_transform,
      this._owner,
      _body, _transform
    );
  }
  _soft_body_set_simulation_precision(_body, _simulation_precision) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__soft_body_set_simulation_precision,
      this._owner,
      _body, _simulation_precision
    );
  }
  _soft_body_get_simulation_precision(_body) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__soft_body_get_simulation_precision,
      this._owner,
			Variant.Type.INT,
      _body
    );
  }
  _soft_body_set_total_mass(_body, _total_mass) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__soft_body_set_total_mass,
      this._owner,
      _body, _total_mass
    );
  }
  _soft_body_get_total_mass(_body) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__soft_body_get_total_mass,
      this._owner,
			Variant.Type.FLOAT,
      _body
    );
  }
  _soft_body_set_linear_stiffness(_body, _linear_stiffness) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__soft_body_set_linear_stiffness,
      this._owner,
      _body, _linear_stiffness
    );
  }
  _soft_body_get_linear_stiffness(_body) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__soft_body_get_linear_stiffness,
      this._owner,
			Variant.Type.FLOAT,
      _body
    );
  }
  _soft_body_set_pressure_coefficient(_body, _pressure_coefficient) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__soft_body_set_pressure_coefficient,
      this._owner,
      _body, _pressure_coefficient
    );
  }
  _soft_body_get_pressure_coefficient(_body) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__soft_body_get_pressure_coefficient,
      this._owner,
			Variant.Type.FLOAT,
      _body
    );
  }
  _soft_body_set_damping_coefficient(_body, _damping_coefficient) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__soft_body_set_damping_coefficient,
      this._owner,
      _body, _damping_coefficient
    );
  }
  _soft_body_get_damping_coefficient(_body) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__soft_body_get_damping_coefficient,
      this._owner,
			Variant.Type.FLOAT,
      _body
    );
  }
  _soft_body_set_drag_coefficient(_body, _drag_coefficient) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__soft_body_set_drag_coefficient,
      this._owner,
      _body, _drag_coefficient
    );
  }
  _soft_body_get_drag_coefficient(_body) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__soft_body_get_drag_coefficient,
      this._owner,
			Variant.Type.FLOAT,
      _body
    );
  }
  _soft_body_set_mesh(_body, _mesh) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__soft_body_set_mesh,
      this._owner,
      _body, _mesh
    );
  }
  _soft_body_get_bounds(_body) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__soft_body_get_bounds,
      this._owner,
			Variant.Type.AABB
    ,
      _body
    );
  }
  _soft_body_move_point(_body, _point_index, _global_position) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__soft_body_move_point,
      this._owner,
      _body, _point_index, _global_position
    );
  }
  _soft_body_get_point_global_position(_body, _point_index) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__soft_body_get_point_global_position,
      this._owner,
			Variant.Type.VECTOR3
    ,
      _body, _point_index
    );
  }
  _soft_body_remove_all_pinned_points(_body) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__soft_body_remove_all_pinned_points,
      this._owner,
      _body
    );
  }
  _soft_body_pin_point(_body, _point_index, _pin) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__soft_body_pin_point,
      this._owner,
      _body, _point_index, _pin
    );
  }
  _soft_body_is_point_pinned(_body, _point_index) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__soft_body_is_point_pinned,
      this._owner,
			Variant.Type.BOOL,
      _body, _point_index
    );
  }
  _joint_create() {
    return _call_native_mb_ret(
      ClassDB._bindings.method__joint_create,
      this._owner,
			Variant.Type.RID
    ,
      
    );
  }
  _joint_clear(_joint) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__joint_clear,
      this._owner,
      _joint
    );
  }
  _joint_make_pin(_joint, _body_A, _local_A, _body_B, _local_B) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__joint_make_pin,
      this._owner,
      _joint, _body_A, _local_A, _body_B, _local_B
    );
  }
  _pin_joint_set_param(_joint, _param, _value) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__pin_joint_set_param,
      this._owner,
      _joint, _param, _value
    );
  }
  _pin_joint_get_param(_joint, _param) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__pin_joint_get_param,
      this._owner,
			Variant.Type.FLOAT,
      _joint, _param
    );
  }
  _pin_joint_set_local_a(_joint, _local_A) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__pin_joint_set_local_a,
      this._owner,
      _joint, _local_A
    );
  }
  _pin_joint_get_local_a(_joint) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__pin_joint_get_local_a,
      this._owner,
			Variant.Type.VECTOR3
    ,
      _joint
    );
  }
  _pin_joint_set_local_b(_joint, _local_B) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__pin_joint_set_local_b,
      this._owner,
      _joint, _local_B
    );
  }
  _pin_joint_get_local_b(_joint) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__pin_joint_get_local_b,
      this._owner,
			Variant.Type.VECTOR3
    ,
      _joint
    );
  }
  _joint_make_hinge(_joint, _body_A, _hinge_A, _body_B, _hinge_B) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__joint_make_hinge,
      this._owner,
      _joint, _body_A, _hinge_A, _body_B, _hinge_B
    );
  }
  _joint_make_hinge_simple(_joint, _body_A, _pivot_A, _axis_A, _body_B, _pivot_B, _axis_B) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__joint_make_hinge_simple,
      this._owner,
      _joint, _body_A, _pivot_A, _axis_A, _body_B, _pivot_B, _axis_B
    );
  }
  _hinge_joint_set_param(_joint, _param, _value) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__hinge_joint_set_param,
      this._owner,
      _joint, _param, _value
    );
  }
  _hinge_joint_get_param(_joint, _param) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__hinge_joint_get_param,
      this._owner,
			Variant.Type.FLOAT,
      _joint, _param
    );
  }
  _hinge_joint_set_flag(_joint, _flag, _enabled) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__hinge_joint_set_flag,
      this._owner,
      _joint, _flag, _enabled
    );
  }
  _hinge_joint_get_flag(_joint, _flag) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__hinge_joint_get_flag,
      this._owner,
			Variant.Type.BOOL,
      _joint, _flag
    );
  }
  _joint_make_slider(_joint, _body_A, _local_ref_A, _body_B, _local_ref_B) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__joint_make_slider,
      this._owner,
      _joint, _body_A, _local_ref_A, _body_B, _local_ref_B
    );
  }
  _slider_joint_set_param(_joint, _param, _value) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__slider_joint_set_param,
      this._owner,
      _joint, _param, _value
    );
  }
  _slider_joint_get_param(_joint, _param) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__slider_joint_get_param,
      this._owner,
			Variant.Type.FLOAT,
      _joint, _param
    );
  }
  _joint_make_cone_twist(_joint, _body_A, _local_ref_A, _body_B, _local_ref_B) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__joint_make_cone_twist,
      this._owner,
      _joint, _body_A, _local_ref_A, _body_B, _local_ref_B
    );
  }
  _cone_twist_joint_set_param(_joint, _param, _value) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__cone_twist_joint_set_param,
      this._owner,
      _joint, _param, _value
    );
  }
  _cone_twist_joint_get_param(_joint, _param) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__cone_twist_joint_get_param,
      this._owner,
			Variant.Type.FLOAT,
      _joint, _param
    );
  }
  _joint_make_generic_6dof(_joint, _body_A, _local_ref_A, _body_B, _local_ref_B) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__joint_make_generic_6dof,
      this._owner,
      _joint, _body_A, _local_ref_A, _body_B, _local_ref_B
    );
  }
  _generic_6dof_joint_set_param(_joint, _axis, _param, _value) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__generic_6dof_joint_set_param,
      this._owner,
      _joint, _axis, _param, _value
    );
  }
  _generic_6dof_joint_get_param(_joint, _axis, _param) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__generic_6dof_joint_get_param,
      this._owner,
			Variant.Type.FLOAT,
      _joint, _axis, _param
    );
  }
  _generic_6dof_joint_set_flag(_joint, _axis, _flag, _enable) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__generic_6dof_joint_set_flag,
      this._owner,
      _joint, _axis, _flag, _enable
    );
  }
  _generic_6dof_joint_get_flag(_joint, _axis, _flag) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__generic_6dof_joint_get_flag,
      this._owner,
			Variant.Type.BOOL,
      _joint, _axis, _flag
    );
  }
  _joint_get_type(_joint) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__joint_get_type,
      this._owner,
			Variant.INT,
      _joint
    );
  }
  _joint_set_solver_priority(_joint, _priority) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__joint_set_solver_priority,
      this._owner,
      _joint, _priority
    );
  }
  _joint_get_solver_priority(_joint) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__joint_get_solver_priority,
      this._owner,
			Variant.Type.INT,
      _joint
    );
  }
  _joint_disable_collisions_between_bodies(_joint, _disable) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__joint_disable_collisions_between_bodies,
      this._owner,
      _joint, _disable
    );
  }
  _joint_is_disabled_collisions_between_bodies(_joint) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__joint_is_disabled_collisions_between_bodies,
      this._owner,
			Variant.Type.BOOL,
      _joint
    );
  }
  _free_rid(_rid) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__free_rid,
      this._owner,
      _rid
    );
  }
  _set_active(_active) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__set_active,
      this._owner,
      _active
    );
  }
  _init() {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__init,
      this._owner,
      
    );
  }
  _step(_step) {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__step,
      this._owner,
      _step
    );
  }
  _sync() {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__sync,
      this._owner,
      
    );
  }
  _flush_queries() {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__flush_queries,
      this._owner,
      
    );
  }
  _end_sync() {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__end_sync,
      this._owner,
      
    );
  }
  _finish() {
    return _call_native_mb_no_ret(
      ClassDB._bindings.method__finish,
      this._owner,
      
    );
  }
  _is_flushing_queries() {
    return _call_native_mb_ret(
      ClassDB._bindings.method__is_flushing_queries,
      this._owner,
			Variant.Type.BOOL,
      
    );
  }
  _get_process_info(_process_info) {
    return _call_native_mb_ret(
      ClassDB._bindings.method__get_process_info,
      this._owner,
			Variant.Type.INT,
      _process_info
    );
  }
  body_test_motion_is_excluding_body(_body) {
    return _call_native_mb_ret(
      ClassDB._bindings.method_body_test_motion_is_excluding_body,
      this._owner,
			Variant.Type.BOOL,
      _body
    );
  }
  body_test_motion_is_excluding_object(_object) {
    return _call_native_mb_ret(
      ClassDB._bindings.method_body_test_motion_is_excluding_object,
      this._owner,
			Variant.Type.BOOL,
      _object
    );
  }
}