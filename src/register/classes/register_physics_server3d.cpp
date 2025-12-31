#include "register/classes/register_classes.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/str_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/physics_direct_body_state3d.hpp>
#include <godot_cpp/classes/physics_direct_space_state3d.hpp>
#include <godot_cpp/classes/physics_server3d_rendering_server_handler.hpp>
#include <godot_cpp/classes/physics_test_motion_parameters3d.hpp>
#include <godot_cpp/classes/physics_test_motion_result3d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/physics_server3d.hpp>


using namespace godot;

static void physics_server3d_class_finalizer(JSRuntime *rt, JSValue val) {
}

static JSClassDef physics_server3d_class_def = {
	"_PhysicsServer3D",
	physics_server3d_class_finalizer
};

static JSValue physics_server3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["_PhysicsServer3D"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);
	if (JS_IsException(obj))
		return obj;

	PhysicsServer3D *physics_server3d_class = PhysicsServer3D::get_singleton();
	if (!physics_server3d_class) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	VariantAdapter *adapter = memnew(VariantAdapter(physics_server3d_class));
	JS_SetOpaque(obj, adapter);
	return obj;
}

static JSValue physics_server3d_class_world_boundary_shape_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&PhysicsServer3D::world_boundary_shape_create, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_separation_ray_shape_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&PhysicsServer3D::separation_ray_shape_create, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_sphere_shape_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&PhysicsServer3D::sphere_shape_create, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_box_shape_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&PhysicsServer3D::box_shape_create, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_capsule_shape_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&PhysicsServer3D::capsule_shape_create, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_cylinder_shape_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&PhysicsServer3D::cylinder_shape_create, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_convex_polygon_shape_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&PhysicsServer3D::convex_polygon_shape_create, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_concave_polygon_shape_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&PhysicsServer3D::concave_polygon_shape_create, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_heightmap_shape_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&PhysicsServer3D::heightmap_shape_create, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_custom_shape_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&PhysicsServer3D::custom_shape_create, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_shape_set_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::shape_set_data, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_shape_set_margin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::shape_set_margin, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_shape_get_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::shape_get_type, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_shape_get_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::shape_get_data, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_shape_get_margin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::shape_get_margin, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_space_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&PhysicsServer3D::space_create, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_space_set_active(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::space_set_active, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_space_is_active(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::space_is_active, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_space_set_param(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::space_set_param, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_space_get_param(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::space_get_param, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_space_get_direct_state(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&PhysicsServer3D::space_get_direct_state, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_area_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&PhysicsServer3D::area_create, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_area_set_space(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::area_set_space, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_area_get_space(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::area_get_space, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_area_add_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::area_add_shape, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_area_set_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::area_set_shape, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_area_set_shape_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::area_set_shape_transform, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_area_set_shape_disabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::area_set_shape_disabled, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_area_get_shape_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::area_get_shape_count, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_area_get_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::area_get_shape, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_area_get_shape_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::area_get_shape_transform, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_area_remove_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::area_remove_shape, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_area_clear_shapes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::area_clear_shapes, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_area_set_collision_layer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::area_set_collision_layer, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_area_get_collision_layer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::area_get_collision_layer, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_area_set_collision_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::area_set_collision_mask, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_area_get_collision_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::area_get_collision_mask, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_area_set_param(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::area_set_param, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_area_set_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::area_set_transform, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_area_get_param(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::area_get_param, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_area_get_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::area_get_transform, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_area_attach_object_instance_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::area_attach_object_instance_id, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_area_get_object_instance_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::area_get_object_instance_id, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_area_set_monitor_callback(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::area_set_monitor_callback, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_area_set_area_monitor_callback(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::area_set_area_monitor_callback, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_area_set_monitorable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::area_set_monitorable, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_area_set_ray_pickable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::area_set_ray_pickable, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_body_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&PhysicsServer3D::body_create, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_body_set_space(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::body_set_space, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_body_get_space(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::body_get_space, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_body_set_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::body_set_mode, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_body_get_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::body_get_mode, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_body_set_collision_layer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::body_set_collision_layer, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_body_get_collision_layer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::body_get_collision_layer, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_body_set_collision_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::body_set_collision_mask, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_body_get_collision_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::body_get_collision_mask, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_body_set_collision_priority(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::body_set_collision_priority, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_body_get_collision_priority(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::body_get_collision_priority, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_body_add_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::body_add_shape, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_body_set_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::body_set_shape, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_body_set_shape_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::body_set_shape_transform, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_body_set_shape_disabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::body_set_shape_disabled, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_body_get_shape_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::body_get_shape_count, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_body_get_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::body_get_shape, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_body_get_shape_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::body_get_shape_transform, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_body_remove_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::body_remove_shape, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_body_clear_shapes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::body_clear_shapes, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_body_attach_object_instance_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::body_attach_object_instance_id, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_body_get_object_instance_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::body_get_object_instance_id, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_body_set_enable_continuous_collision_detection(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::body_set_enable_continuous_collision_detection, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_body_is_continuous_collision_detection_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::body_is_continuous_collision_detection_enabled, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_body_set_param(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::body_set_param, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_body_get_param(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::body_get_param, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_body_reset_mass_properties(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::body_reset_mass_properties, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_body_set_state(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::body_set_state, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_body_get_state(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::body_get_state, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_body_apply_central_impulse(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::body_apply_central_impulse, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_body_apply_impulse(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::body_apply_impulse, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_body_apply_torque_impulse(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::body_apply_torque_impulse, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_body_apply_central_force(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::body_apply_central_force, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_body_apply_force(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::body_apply_force, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_body_apply_torque(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::body_apply_torque, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_body_add_constant_central_force(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::body_add_constant_central_force, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_body_add_constant_force(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::body_add_constant_force, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_body_add_constant_torque(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::body_add_constant_torque, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_body_set_constant_force(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::body_set_constant_force, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_body_get_constant_force(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::body_get_constant_force, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_body_set_constant_torque(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::body_set_constant_torque, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_body_get_constant_torque(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::body_get_constant_torque, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_body_set_axis_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::body_set_axis_velocity, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_body_set_axis_lock(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::body_set_axis_lock, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_body_is_axis_locked(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::body_is_axis_locked, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_body_add_collision_exception(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::body_add_collision_exception, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_body_remove_collision_exception(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::body_remove_collision_exception, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_body_set_max_contacts_reported(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::body_set_max_contacts_reported, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_body_get_max_contacts_reported(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::body_get_max_contacts_reported, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_body_set_omit_force_integration(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::body_set_omit_force_integration, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_body_is_omitting_force_integration(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::body_is_omitting_force_integration, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_body_set_state_sync_callback(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::body_set_state_sync_callback, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_body_set_force_integration_callback(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::body_set_force_integration_callback, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_body_set_ray_pickable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::body_set_ray_pickable, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_body_test_motion(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&PhysicsServer3D::body_test_motion, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_body_get_direct_state(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&PhysicsServer3D::body_get_direct_state, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_soft_body_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&PhysicsServer3D::soft_body_create, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_soft_body_update_rendering_server(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::soft_body_update_rendering_server, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_soft_body_set_space(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::soft_body_set_space, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_soft_body_get_space(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::soft_body_get_space, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_soft_body_set_mesh(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::soft_body_set_mesh, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_soft_body_get_bounds(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::soft_body_get_bounds, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_soft_body_set_collision_layer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::soft_body_set_collision_layer, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_soft_body_get_collision_layer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::soft_body_get_collision_layer, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_soft_body_set_collision_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::soft_body_set_collision_mask, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_soft_body_get_collision_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::soft_body_get_collision_mask, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_soft_body_add_collision_exception(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::soft_body_add_collision_exception, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_soft_body_remove_collision_exception(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::soft_body_remove_collision_exception, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_soft_body_set_state(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::soft_body_set_state, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_soft_body_get_state(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::soft_body_get_state, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_soft_body_set_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::soft_body_set_transform, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_soft_body_set_ray_pickable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::soft_body_set_ray_pickable, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_soft_body_set_simulation_precision(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::soft_body_set_simulation_precision, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_soft_body_get_simulation_precision(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::soft_body_get_simulation_precision, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_soft_body_set_total_mass(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::soft_body_set_total_mass, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_soft_body_get_total_mass(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::soft_body_get_total_mass, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_soft_body_set_linear_stiffness(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::soft_body_set_linear_stiffness, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_soft_body_get_linear_stiffness(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::soft_body_get_linear_stiffness, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_soft_body_set_shrinking_factor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::soft_body_set_shrinking_factor, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_soft_body_get_shrinking_factor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::soft_body_get_shrinking_factor, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_soft_body_set_pressure_coefficient(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::soft_body_set_pressure_coefficient, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_soft_body_get_pressure_coefficient(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::soft_body_get_pressure_coefficient, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_soft_body_set_damping_coefficient(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::soft_body_set_damping_coefficient, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_soft_body_get_damping_coefficient(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::soft_body_get_damping_coefficient, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_soft_body_set_drag_coefficient(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::soft_body_set_drag_coefficient, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_soft_body_get_drag_coefficient(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::soft_body_get_drag_coefficient, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_soft_body_move_point(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::soft_body_move_point, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_soft_body_get_point_global_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::soft_body_get_point_global_position, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_soft_body_remove_all_pinned_points(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::soft_body_remove_all_pinned_points, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_soft_body_pin_point(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::soft_body_pin_point, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_soft_body_is_point_pinned(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::soft_body_is_point_pinned, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_soft_body_apply_point_impulse(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::soft_body_apply_point_impulse, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_soft_body_apply_point_force(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::soft_body_apply_point_force, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_soft_body_apply_central_impulse(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::soft_body_apply_central_impulse, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_soft_body_apply_central_force(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::soft_body_apply_central_force, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_joint_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&PhysicsServer3D::joint_create, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_joint_clear(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::joint_clear, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_joint_make_pin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::joint_make_pin, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_pin_joint_set_param(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::pin_joint_set_param, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_pin_joint_get_param(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::pin_joint_get_param, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_pin_joint_set_local_a(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::pin_joint_set_local_a, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_pin_joint_get_local_a(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::pin_joint_get_local_a, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_pin_joint_set_local_b(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::pin_joint_set_local_b, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_pin_joint_get_local_b(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::pin_joint_get_local_b, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_joint_make_hinge(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::joint_make_hinge, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_hinge_joint_set_param(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::hinge_joint_set_param, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_hinge_joint_get_param(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::hinge_joint_get_param, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_hinge_joint_set_flag(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::hinge_joint_set_flag, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_hinge_joint_get_flag(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::hinge_joint_get_flag, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_joint_make_slider(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::joint_make_slider, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_slider_joint_set_param(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::slider_joint_set_param, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_slider_joint_get_param(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::slider_joint_get_param, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_joint_make_cone_twist(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::joint_make_cone_twist, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_cone_twist_joint_set_param(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::cone_twist_joint_set_param, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_cone_twist_joint_get_param(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::cone_twist_joint_get_param, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_joint_get_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::joint_get_type, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_joint_set_solver_priority(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::joint_set_solver_priority, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_joint_get_solver_priority(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::joint_get_solver_priority, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_joint_disable_collisions_between_bodies(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::joint_disable_collisions_between_bodies, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_joint_is_disabled_collisions_between_bodies(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::joint_is_disabled_collisions_between_bodies, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_joint_make_generic_6dof(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::joint_make_generic_6dof, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_generic_6dof_joint_set_param(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::generic_6dof_joint_set_param, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_generic_6dof_joint_get_param(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::generic_6dof_joint_get_param, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_generic_6dof_joint_set_flag(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::generic_6dof_joint_set_flag, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_generic_6dof_joint_get_flag(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&PhysicsServer3D::generic_6dof_joint_get_flag, ctx, this_val, argc, argv);
};
static JSValue physics_server3d_class_free_rid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::free_rid, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_set_active(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&PhysicsServer3D::set_active, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue physics_server3d_class_get_process_info(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&PhysicsServer3D::get_process_info, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry physics_server3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("world_boundary_shape_create", 0, &physics_server3d_class_world_boundary_shape_create),
	JS_CFUNC_DEF("separation_ray_shape_create", 0, &physics_server3d_class_separation_ray_shape_create),
	JS_CFUNC_DEF("sphere_shape_create", 0, &physics_server3d_class_sphere_shape_create),
	JS_CFUNC_DEF("box_shape_create", 0, &physics_server3d_class_box_shape_create),
	JS_CFUNC_DEF("capsule_shape_create", 0, &physics_server3d_class_capsule_shape_create),
	JS_CFUNC_DEF("cylinder_shape_create", 0, &physics_server3d_class_cylinder_shape_create),
	JS_CFUNC_DEF("convex_polygon_shape_create", 0, &physics_server3d_class_convex_polygon_shape_create),
	JS_CFUNC_DEF("concave_polygon_shape_create", 0, &physics_server3d_class_concave_polygon_shape_create),
	JS_CFUNC_DEF("heightmap_shape_create", 0, &physics_server3d_class_heightmap_shape_create),
	JS_CFUNC_DEF("custom_shape_create", 0, &physics_server3d_class_custom_shape_create),
	JS_CFUNC_DEF("shape_set_data", 2, &physics_server3d_class_shape_set_data),
	JS_CFUNC_DEF("shape_set_margin", 2, &physics_server3d_class_shape_set_margin),
	JS_CFUNC_DEF("shape_get_type", 1, &physics_server3d_class_shape_get_type),
	JS_CFUNC_DEF("shape_get_data", 1, &physics_server3d_class_shape_get_data),
	JS_CFUNC_DEF("shape_get_margin", 1, &physics_server3d_class_shape_get_margin),
	JS_CFUNC_DEF("space_create", 0, &physics_server3d_class_space_create),
	JS_CFUNC_DEF("space_set_active", 2, &physics_server3d_class_space_set_active),
	JS_CFUNC_DEF("space_is_active", 1, &physics_server3d_class_space_is_active),
	JS_CFUNC_DEF("space_set_param", 3, &physics_server3d_class_space_set_param),
	JS_CFUNC_DEF("space_get_param", 2, &physics_server3d_class_space_get_param),
	JS_CFUNC_DEF("space_get_direct_state", 1, &physics_server3d_class_space_get_direct_state),
	JS_CFUNC_DEF("area_create", 0, &physics_server3d_class_area_create),
	JS_CFUNC_DEF("area_set_space", 2, &physics_server3d_class_area_set_space),
	JS_CFUNC_DEF("area_get_space", 1, &physics_server3d_class_area_get_space),
	JS_CFUNC_DEF("area_add_shape", 4, &physics_server3d_class_area_add_shape),
	JS_CFUNC_DEF("area_set_shape", 3, &physics_server3d_class_area_set_shape),
	JS_CFUNC_DEF("area_set_shape_transform", 3, &physics_server3d_class_area_set_shape_transform),
	JS_CFUNC_DEF("area_set_shape_disabled", 3, &physics_server3d_class_area_set_shape_disabled),
	JS_CFUNC_DEF("area_get_shape_count", 1, &physics_server3d_class_area_get_shape_count),
	JS_CFUNC_DEF("area_get_shape", 2, &physics_server3d_class_area_get_shape),
	JS_CFUNC_DEF("area_get_shape_transform", 2, &physics_server3d_class_area_get_shape_transform),
	JS_CFUNC_DEF("area_remove_shape", 2, &physics_server3d_class_area_remove_shape),
	JS_CFUNC_DEF("area_clear_shapes", 1, &physics_server3d_class_area_clear_shapes),
	JS_CFUNC_DEF("area_set_collision_layer", 2, &physics_server3d_class_area_set_collision_layer),
	JS_CFUNC_DEF("area_get_collision_layer", 1, &physics_server3d_class_area_get_collision_layer),
	JS_CFUNC_DEF("area_set_collision_mask", 2, &physics_server3d_class_area_set_collision_mask),
	JS_CFUNC_DEF("area_get_collision_mask", 1, &physics_server3d_class_area_get_collision_mask),
	JS_CFUNC_DEF("area_set_param", 3, &physics_server3d_class_area_set_param),
	JS_CFUNC_DEF("area_set_transform", 2, &physics_server3d_class_area_set_transform),
	JS_CFUNC_DEF("area_get_param", 2, &physics_server3d_class_area_get_param),
	JS_CFUNC_DEF("area_get_transform", 1, &physics_server3d_class_area_get_transform),
	JS_CFUNC_DEF("area_attach_object_instance_id", 2, &physics_server3d_class_area_attach_object_instance_id),
	JS_CFUNC_DEF("area_get_object_instance_id", 1, &physics_server3d_class_area_get_object_instance_id),
	JS_CFUNC_DEF("area_set_monitor_callback", 2, &physics_server3d_class_area_set_monitor_callback),
	JS_CFUNC_DEF("area_set_area_monitor_callback", 2, &physics_server3d_class_area_set_area_monitor_callback),
	JS_CFUNC_DEF("area_set_monitorable", 2, &physics_server3d_class_area_set_monitorable),
	JS_CFUNC_DEF("area_set_ray_pickable", 2, &physics_server3d_class_area_set_ray_pickable),
	JS_CFUNC_DEF("body_create", 0, &physics_server3d_class_body_create),
	JS_CFUNC_DEF("body_set_space", 2, &physics_server3d_class_body_set_space),
	JS_CFUNC_DEF("body_get_space", 1, &physics_server3d_class_body_get_space),
	JS_CFUNC_DEF("body_set_mode", 2, &physics_server3d_class_body_set_mode),
	JS_CFUNC_DEF("body_get_mode", 1, &physics_server3d_class_body_get_mode),
	JS_CFUNC_DEF("body_set_collision_layer", 2, &physics_server3d_class_body_set_collision_layer),
	JS_CFUNC_DEF("body_get_collision_layer", 1, &physics_server3d_class_body_get_collision_layer),
	JS_CFUNC_DEF("body_set_collision_mask", 2, &physics_server3d_class_body_set_collision_mask),
	JS_CFUNC_DEF("body_get_collision_mask", 1, &physics_server3d_class_body_get_collision_mask),
	JS_CFUNC_DEF("body_set_collision_priority", 2, &physics_server3d_class_body_set_collision_priority),
	JS_CFUNC_DEF("body_get_collision_priority", 1, &physics_server3d_class_body_get_collision_priority),
	JS_CFUNC_DEF("body_add_shape", 4, &physics_server3d_class_body_add_shape),
	JS_CFUNC_DEF("body_set_shape", 3, &physics_server3d_class_body_set_shape),
	JS_CFUNC_DEF("body_set_shape_transform", 3, &physics_server3d_class_body_set_shape_transform),
	JS_CFUNC_DEF("body_set_shape_disabled", 3, &physics_server3d_class_body_set_shape_disabled),
	JS_CFUNC_DEF("body_get_shape_count", 1, &physics_server3d_class_body_get_shape_count),
	JS_CFUNC_DEF("body_get_shape", 2, &physics_server3d_class_body_get_shape),
	JS_CFUNC_DEF("body_get_shape_transform", 2, &physics_server3d_class_body_get_shape_transform),
	JS_CFUNC_DEF("body_remove_shape", 2, &physics_server3d_class_body_remove_shape),
	JS_CFUNC_DEF("body_clear_shapes", 1, &physics_server3d_class_body_clear_shapes),
	JS_CFUNC_DEF("body_attach_object_instance_id", 2, &physics_server3d_class_body_attach_object_instance_id),
	JS_CFUNC_DEF("body_get_object_instance_id", 1, &physics_server3d_class_body_get_object_instance_id),
	JS_CFUNC_DEF("body_set_enable_continuous_collision_detection", 2, &physics_server3d_class_body_set_enable_continuous_collision_detection),
	JS_CFUNC_DEF("body_is_continuous_collision_detection_enabled", 1, &physics_server3d_class_body_is_continuous_collision_detection_enabled),
	JS_CFUNC_DEF("body_set_param", 3, &physics_server3d_class_body_set_param),
	JS_CFUNC_DEF("body_get_param", 2, &physics_server3d_class_body_get_param),
	JS_CFUNC_DEF("body_reset_mass_properties", 1, &physics_server3d_class_body_reset_mass_properties),
	JS_CFUNC_DEF("body_set_state", 3, &physics_server3d_class_body_set_state),
	JS_CFUNC_DEF("body_get_state", 2, &physics_server3d_class_body_get_state),
	JS_CFUNC_DEF("body_apply_central_impulse", 2, &physics_server3d_class_body_apply_central_impulse),
	JS_CFUNC_DEF("body_apply_impulse", 3, &physics_server3d_class_body_apply_impulse),
	JS_CFUNC_DEF("body_apply_torque_impulse", 2, &physics_server3d_class_body_apply_torque_impulse),
	JS_CFUNC_DEF("body_apply_central_force", 2, &physics_server3d_class_body_apply_central_force),
	JS_CFUNC_DEF("body_apply_force", 3, &physics_server3d_class_body_apply_force),
	JS_CFUNC_DEF("body_apply_torque", 2, &physics_server3d_class_body_apply_torque),
	JS_CFUNC_DEF("body_add_constant_central_force", 2, &physics_server3d_class_body_add_constant_central_force),
	JS_CFUNC_DEF("body_add_constant_force", 3, &physics_server3d_class_body_add_constant_force),
	JS_CFUNC_DEF("body_add_constant_torque", 2, &physics_server3d_class_body_add_constant_torque),
	JS_CFUNC_DEF("body_set_constant_force", 2, &physics_server3d_class_body_set_constant_force),
	JS_CFUNC_DEF("body_get_constant_force", 1, &physics_server3d_class_body_get_constant_force),
	JS_CFUNC_DEF("body_set_constant_torque", 2, &physics_server3d_class_body_set_constant_torque),
	JS_CFUNC_DEF("body_get_constant_torque", 1, &physics_server3d_class_body_get_constant_torque),
	JS_CFUNC_DEF("body_set_axis_velocity", 2, &physics_server3d_class_body_set_axis_velocity),
	JS_CFUNC_DEF("body_set_axis_lock", 3, &physics_server3d_class_body_set_axis_lock),
	JS_CFUNC_DEF("body_is_axis_locked", 2, &physics_server3d_class_body_is_axis_locked),
	JS_CFUNC_DEF("body_add_collision_exception", 2, &physics_server3d_class_body_add_collision_exception),
	JS_CFUNC_DEF("body_remove_collision_exception", 2, &physics_server3d_class_body_remove_collision_exception),
	JS_CFUNC_DEF("body_set_max_contacts_reported", 2, &physics_server3d_class_body_set_max_contacts_reported),
	JS_CFUNC_DEF("body_get_max_contacts_reported", 1, &physics_server3d_class_body_get_max_contacts_reported),
	JS_CFUNC_DEF("body_set_omit_force_integration", 2, &physics_server3d_class_body_set_omit_force_integration),
	JS_CFUNC_DEF("body_is_omitting_force_integration", 1, &physics_server3d_class_body_is_omitting_force_integration),
	JS_CFUNC_DEF("body_set_state_sync_callback", 2, &physics_server3d_class_body_set_state_sync_callback),
	JS_CFUNC_DEF("body_set_force_integration_callback", 3, &physics_server3d_class_body_set_force_integration_callback),
	JS_CFUNC_DEF("body_set_ray_pickable", 2, &physics_server3d_class_body_set_ray_pickable),
	JS_CFUNC_DEF("body_test_motion", 3, &physics_server3d_class_body_test_motion),
	JS_CFUNC_DEF("body_get_direct_state", 1, &physics_server3d_class_body_get_direct_state),
	JS_CFUNC_DEF("soft_body_create", 0, &physics_server3d_class_soft_body_create),
	JS_CFUNC_DEF("soft_body_update_rendering_server", 2, &physics_server3d_class_soft_body_update_rendering_server),
	JS_CFUNC_DEF("soft_body_set_space", 2, &physics_server3d_class_soft_body_set_space),
	JS_CFUNC_DEF("soft_body_get_space", 1, &physics_server3d_class_soft_body_get_space),
	JS_CFUNC_DEF("soft_body_set_mesh", 2, &physics_server3d_class_soft_body_set_mesh),
	JS_CFUNC_DEF("soft_body_get_bounds", 1, &physics_server3d_class_soft_body_get_bounds),
	JS_CFUNC_DEF("soft_body_set_collision_layer", 2, &physics_server3d_class_soft_body_set_collision_layer),
	JS_CFUNC_DEF("soft_body_get_collision_layer", 1, &physics_server3d_class_soft_body_get_collision_layer),
	JS_CFUNC_DEF("soft_body_set_collision_mask", 2, &physics_server3d_class_soft_body_set_collision_mask),
	JS_CFUNC_DEF("soft_body_get_collision_mask", 1, &physics_server3d_class_soft_body_get_collision_mask),
	JS_CFUNC_DEF("soft_body_add_collision_exception", 2, &physics_server3d_class_soft_body_add_collision_exception),
	JS_CFUNC_DEF("soft_body_remove_collision_exception", 2, &physics_server3d_class_soft_body_remove_collision_exception),
	JS_CFUNC_DEF("soft_body_set_state", 3, &physics_server3d_class_soft_body_set_state),
	JS_CFUNC_DEF("soft_body_get_state", 2, &physics_server3d_class_soft_body_get_state),
	JS_CFUNC_DEF("soft_body_set_transform", 2, &physics_server3d_class_soft_body_set_transform),
	JS_CFUNC_DEF("soft_body_set_ray_pickable", 2, &physics_server3d_class_soft_body_set_ray_pickable),
	JS_CFUNC_DEF("soft_body_set_simulation_precision", 2, &physics_server3d_class_soft_body_set_simulation_precision),
	JS_CFUNC_DEF("soft_body_get_simulation_precision", 1, &physics_server3d_class_soft_body_get_simulation_precision),
	JS_CFUNC_DEF("soft_body_set_total_mass", 2, &physics_server3d_class_soft_body_set_total_mass),
	JS_CFUNC_DEF("soft_body_get_total_mass", 1, &physics_server3d_class_soft_body_get_total_mass),
	JS_CFUNC_DEF("soft_body_set_linear_stiffness", 2, &physics_server3d_class_soft_body_set_linear_stiffness),
	JS_CFUNC_DEF("soft_body_get_linear_stiffness", 1, &physics_server3d_class_soft_body_get_linear_stiffness),
	JS_CFUNC_DEF("soft_body_set_shrinking_factor", 2, &physics_server3d_class_soft_body_set_shrinking_factor),
	JS_CFUNC_DEF("soft_body_get_shrinking_factor", 1, &physics_server3d_class_soft_body_get_shrinking_factor),
	JS_CFUNC_DEF("soft_body_set_pressure_coefficient", 2, &physics_server3d_class_soft_body_set_pressure_coefficient),
	JS_CFUNC_DEF("soft_body_get_pressure_coefficient", 1, &physics_server3d_class_soft_body_get_pressure_coefficient),
	JS_CFUNC_DEF("soft_body_set_damping_coefficient", 2, &physics_server3d_class_soft_body_set_damping_coefficient),
	JS_CFUNC_DEF("soft_body_get_damping_coefficient", 1, &physics_server3d_class_soft_body_get_damping_coefficient),
	JS_CFUNC_DEF("soft_body_set_drag_coefficient", 2, &physics_server3d_class_soft_body_set_drag_coefficient),
	JS_CFUNC_DEF("soft_body_get_drag_coefficient", 1, &physics_server3d_class_soft_body_get_drag_coefficient),
	JS_CFUNC_DEF("soft_body_move_point", 3, &physics_server3d_class_soft_body_move_point),
	JS_CFUNC_DEF("soft_body_get_point_global_position", 2, &physics_server3d_class_soft_body_get_point_global_position),
	JS_CFUNC_DEF("soft_body_remove_all_pinned_points", 1, &physics_server3d_class_soft_body_remove_all_pinned_points),
	JS_CFUNC_DEF("soft_body_pin_point", 3, &physics_server3d_class_soft_body_pin_point),
	JS_CFUNC_DEF("soft_body_is_point_pinned", 2, &physics_server3d_class_soft_body_is_point_pinned),
	JS_CFUNC_DEF("soft_body_apply_point_impulse", 3, &physics_server3d_class_soft_body_apply_point_impulse),
	JS_CFUNC_DEF("soft_body_apply_point_force", 3, &physics_server3d_class_soft_body_apply_point_force),
	JS_CFUNC_DEF("soft_body_apply_central_impulse", 2, &physics_server3d_class_soft_body_apply_central_impulse),
	JS_CFUNC_DEF("soft_body_apply_central_force", 2, &physics_server3d_class_soft_body_apply_central_force),
	JS_CFUNC_DEF("joint_create", 0, &physics_server3d_class_joint_create),
	JS_CFUNC_DEF("joint_clear", 1, &physics_server3d_class_joint_clear),
	JS_CFUNC_DEF("joint_make_pin", 5, &physics_server3d_class_joint_make_pin),
	JS_CFUNC_DEF("pin_joint_set_param", 3, &physics_server3d_class_pin_joint_set_param),
	JS_CFUNC_DEF("pin_joint_get_param", 2, &physics_server3d_class_pin_joint_get_param),
	JS_CFUNC_DEF("pin_joint_set_local_a", 2, &physics_server3d_class_pin_joint_set_local_a),
	JS_CFUNC_DEF("pin_joint_get_local_a", 1, &physics_server3d_class_pin_joint_get_local_a),
	JS_CFUNC_DEF("pin_joint_set_local_b", 2, &physics_server3d_class_pin_joint_set_local_b),
	JS_CFUNC_DEF("pin_joint_get_local_b", 1, &physics_server3d_class_pin_joint_get_local_b),
	JS_CFUNC_DEF("joint_make_hinge", 5, &physics_server3d_class_joint_make_hinge),
	JS_CFUNC_DEF("hinge_joint_set_param", 3, &physics_server3d_class_hinge_joint_set_param),
	JS_CFUNC_DEF("hinge_joint_get_param", 2, &physics_server3d_class_hinge_joint_get_param),
	JS_CFUNC_DEF("hinge_joint_set_flag", 3, &physics_server3d_class_hinge_joint_set_flag),
	JS_CFUNC_DEF("hinge_joint_get_flag", 2, &physics_server3d_class_hinge_joint_get_flag),
	JS_CFUNC_DEF("joint_make_slider", 5, &physics_server3d_class_joint_make_slider),
	JS_CFUNC_DEF("slider_joint_set_param", 3, &physics_server3d_class_slider_joint_set_param),
	JS_CFUNC_DEF("slider_joint_get_param", 2, &physics_server3d_class_slider_joint_get_param),
	JS_CFUNC_DEF("joint_make_cone_twist", 5, &physics_server3d_class_joint_make_cone_twist),
	JS_CFUNC_DEF("cone_twist_joint_set_param", 3, &physics_server3d_class_cone_twist_joint_set_param),
	JS_CFUNC_DEF("cone_twist_joint_get_param", 2, &physics_server3d_class_cone_twist_joint_get_param),
	JS_CFUNC_DEF("joint_get_type", 1, &physics_server3d_class_joint_get_type),
	JS_CFUNC_DEF("joint_set_solver_priority", 2, &physics_server3d_class_joint_set_solver_priority),
	JS_CFUNC_DEF("joint_get_solver_priority", 1, &physics_server3d_class_joint_get_solver_priority),
	JS_CFUNC_DEF("joint_disable_collisions_between_bodies", 2, &physics_server3d_class_joint_disable_collisions_between_bodies),
	JS_CFUNC_DEF("joint_is_disabled_collisions_between_bodies", 1, &physics_server3d_class_joint_is_disabled_collisions_between_bodies),
	JS_CFUNC_DEF("joint_make_generic_6dof", 5, &physics_server3d_class_joint_make_generic_6dof),
	JS_CFUNC_DEF("generic_6dof_joint_set_param", 4, &physics_server3d_class_generic_6dof_joint_set_param),
	JS_CFUNC_DEF("generic_6dof_joint_get_param", 3, &physics_server3d_class_generic_6dof_joint_get_param),
	JS_CFUNC_DEF("generic_6dof_joint_set_flag", 4, &physics_server3d_class_generic_6dof_joint_set_flag),
	JS_CFUNC_DEF("generic_6dof_joint_get_flag", 3, &physics_server3d_class_generic_6dof_joint_get_flag),
	JS_CFUNC_DEF("free_rid", 1, &physics_server3d_class_free_rid),
	JS_CFUNC_DEF("set_active", 1, &physics_server3d_class_set_active),
	JS_CFUNC_DEF("get_process_info", 1, &physics_server3d_class_get_process_info),
};




static int js_physics_server3d_class_init(JSContext *ctx, JSModuleDef *m){
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["_PhysicsServer3D"] = class_id;
	JS_NewClass(JS_GetRuntime(ctx), class_id, &physics_server3d_class_def);

	JSValue proto = JS_NewObject(ctx);
	JSValue base_class = JS_GetClassProto(ctx, classes["Object"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	JS_SetPropertyFunctionList(ctx, proto, physics_server3d_class_proto_funcs, _countof(physics_server3d_class_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, physics_server3d_class_constructor, "_PhysicsServer3D", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);


    JSValue singleton = JS_CallConstructor(ctx, ctor, 0, {});
	JS_SetModuleExport(ctx, m, "PhysicsServer3D", singleton);

	return 0;
}

JSModuleDef *_js_init_physics_server3d_module(JSContext *ctx, const char *module_name) {
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_physics_server3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "PhysicsServer3D");
	return m;
}

void register_physics_server3d() {
	_js_init_physics_server3d_module(js_context(), "@godot/classes/physics_server3d");
}