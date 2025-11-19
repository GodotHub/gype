#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/curve.hpp>
#include <godot_cpp/classes/skeleton_modifier3d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/spring_bone_simulator3d.hpp>
using namespace godot;

static void spring_bone_simulator3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["SpringBoneSimulator3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef spring_bone_simulator3d_class_def = {
    "SpringBoneSimulator3D",
    spring_bone_simulator3d_class_finalizer
};

static JSValue spring_bone_simulator3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["SpringBoneSimulator3D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    SpringBoneSimulator3D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<SpringBoneSimulator3D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(SpringBoneSimulator3D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue spring_bone_simulator3d_class_set_root_bone_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringBoneSimulator3D::set_root_bone_name, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_get_root_bone_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpringBoneSimulator3D::get_root_bone_name, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_set_root_bone(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringBoneSimulator3D::set_root_bone, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_get_root_bone(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpringBoneSimulator3D::get_root_bone, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_set_end_bone_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringBoneSimulator3D::set_end_bone_name, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_get_end_bone_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpringBoneSimulator3D::get_end_bone_name, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_set_end_bone(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringBoneSimulator3D::set_end_bone, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_get_end_bone(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpringBoneSimulator3D::get_end_bone, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_set_extend_end_bone(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringBoneSimulator3D::set_extend_end_bone, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_is_end_bone_extended(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpringBoneSimulator3D::is_end_bone_extended, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_set_end_bone_direction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringBoneSimulator3D::set_end_bone_direction, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_get_end_bone_direction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpringBoneSimulator3D::get_end_bone_direction, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_set_end_bone_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringBoneSimulator3D::set_end_bone_length, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_get_end_bone_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpringBoneSimulator3D::get_end_bone_length, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_set_center_from(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringBoneSimulator3D::set_center_from, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_get_center_from(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpringBoneSimulator3D::get_center_from, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_set_center_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringBoneSimulator3D::set_center_node, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_get_center_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpringBoneSimulator3D::get_center_node, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_set_center_bone_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringBoneSimulator3D::set_center_bone_name, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_get_center_bone_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpringBoneSimulator3D::get_center_bone_name, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_set_center_bone(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringBoneSimulator3D::set_center_bone, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_get_center_bone(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpringBoneSimulator3D::get_center_bone, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_set_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringBoneSimulator3D::set_radius, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_get_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpringBoneSimulator3D::get_radius, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_set_rotation_axis(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringBoneSimulator3D::set_rotation_axis, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_get_rotation_axis(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpringBoneSimulator3D::get_rotation_axis, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_set_rotation_axis_vector(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringBoneSimulator3D::set_rotation_axis_vector, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_get_rotation_axis_vector(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpringBoneSimulator3D::get_rotation_axis_vector, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_set_radius_damping_curve(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringBoneSimulator3D::set_radius_damping_curve, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_get_radius_damping_curve(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpringBoneSimulator3D::get_radius_damping_curve, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_set_stiffness(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringBoneSimulator3D::set_stiffness, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_get_stiffness(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpringBoneSimulator3D::get_stiffness, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_set_stiffness_damping_curve(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringBoneSimulator3D::set_stiffness_damping_curve, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_get_stiffness_damping_curve(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpringBoneSimulator3D::get_stiffness_damping_curve, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_set_drag(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringBoneSimulator3D::set_drag, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_get_drag(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpringBoneSimulator3D::get_drag, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_set_drag_damping_curve(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringBoneSimulator3D::set_drag_damping_curve, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_get_drag_damping_curve(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpringBoneSimulator3D::get_drag_damping_curve, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_set_gravity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringBoneSimulator3D::set_gravity, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_get_gravity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpringBoneSimulator3D::get_gravity, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_set_gravity_damping_curve(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringBoneSimulator3D::set_gravity_damping_curve, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_get_gravity_damping_curve(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpringBoneSimulator3D::get_gravity_damping_curve, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_set_gravity_direction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringBoneSimulator3D::set_gravity_direction, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_get_gravity_direction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpringBoneSimulator3D::get_gravity_direction, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_set_setting_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringBoneSimulator3D::set_setting_count, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_get_setting_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpringBoneSimulator3D::get_setting_count, ctx, this_val, argc, argv);
}
static JSValue spring_bone_simulator3d_class_clear_settings(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringBoneSimulator3D::clear_settings, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_set_individual_config(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringBoneSimulator3D::set_individual_config, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_is_config_individual(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpringBoneSimulator3D::is_config_individual, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_get_joint_bone_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpringBoneSimulator3D::get_joint_bone_name, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_get_joint_bone(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpringBoneSimulator3D::get_joint_bone, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_set_joint_rotation_axis(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringBoneSimulator3D::set_joint_rotation_axis, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_get_joint_rotation_axis(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpringBoneSimulator3D::get_joint_rotation_axis, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_set_joint_rotation_axis_vector(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringBoneSimulator3D::set_joint_rotation_axis_vector, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_get_joint_rotation_axis_vector(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpringBoneSimulator3D::get_joint_rotation_axis_vector, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_set_joint_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringBoneSimulator3D::set_joint_radius, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_get_joint_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpringBoneSimulator3D::get_joint_radius, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_set_joint_stiffness(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringBoneSimulator3D::set_joint_stiffness, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_get_joint_stiffness(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpringBoneSimulator3D::get_joint_stiffness, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_set_joint_drag(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringBoneSimulator3D::set_joint_drag, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_get_joint_drag(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpringBoneSimulator3D::get_joint_drag, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_set_joint_gravity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringBoneSimulator3D::set_joint_gravity, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_get_joint_gravity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpringBoneSimulator3D::get_joint_gravity, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_set_joint_gravity_direction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringBoneSimulator3D::set_joint_gravity_direction, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_get_joint_gravity_direction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpringBoneSimulator3D::get_joint_gravity_direction, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_get_joint_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpringBoneSimulator3D::get_joint_count, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_set_enable_all_child_collisions(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringBoneSimulator3D::set_enable_all_child_collisions, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_are_all_child_collisions_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpringBoneSimulator3D::are_all_child_collisions_enabled, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_set_exclude_collision_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringBoneSimulator3D::set_exclude_collision_path, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_get_exclude_collision_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpringBoneSimulator3D::get_exclude_collision_path, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_set_exclude_collision_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringBoneSimulator3D::set_exclude_collision_count, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_get_exclude_collision_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpringBoneSimulator3D::get_exclude_collision_count, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_clear_exclude_collisions(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringBoneSimulator3D::clear_exclude_collisions, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_set_collision_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringBoneSimulator3D::set_collision_path, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_get_collision_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpringBoneSimulator3D::get_collision_path, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_set_collision_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringBoneSimulator3D::set_collision_count, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_get_collision_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SpringBoneSimulator3D::get_collision_count, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_clear_collisions(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringBoneSimulator3D::clear_collisions, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_set_external_force(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringBoneSimulator3D::set_external_force, ctx, this_val, argc, argv);
};
static JSValue spring_bone_simulator3d_class_get_external_force(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector3> *proxy = memnew(ObjectProxy<Vector3>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector3 {
		SpringBoneSimulator3D *obj = static_cast<SpringBoneSimulator3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_external_force();
	};
	proxy->setter = [this_val](const Vector3 &value) -> void {
		SpringBoneSimulator3D *js_proxy = static_cast<SpringBoneSimulator3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_external_force(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector3Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector3Proxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue spring_bone_simulator3d_class_reset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SpringBoneSimulator3D::reset, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry spring_bone_simulator3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_root_bone_name", 2, &spring_bone_simulator3d_class_set_root_bone_name),
	JS_CFUNC_DEF("get_root_bone_name", 1, &spring_bone_simulator3d_class_get_root_bone_name),
	JS_CFUNC_DEF("set_root_bone", 2, &spring_bone_simulator3d_class_set_root_bone),
	JS_CFUNC_DEF("get_root_bone", 1, &spring_bone_simulator3d_class_get_root_bone),
	JS_CFUNC_DEF("set_end_bone_name", 2, &spring_bone_simulator3d_class_set_end_bone_name),
	JS_CFUNC_DEF("get_end_bone_name", 1, &spring_bone_simulator3d_class_get_end_bone_name),
	JS_CFUNC_DEF("set_end_bone", 2, &spring_bone_simulator3d_class_set_end_bone),
	JS_CFUNC_DEF("get_end_bone", 1, &spring_bone_simulator3d_class_get_end_bone),
	JS_CFUNC_DEF("set_extend_end_bone", 2, &spring_bone_simulator3d_class_set_extend_end_bone),
	JS_CFUNC_DEF("is_end_bone_extended", 1, &spring_bone_simulator3d_class_is_end_bone_extended),
	JS_CFUNC_DEF("set_end_bone_direction", 2, &spring_bone_simulator3d_class_set_end_bone_direction),
	JS_CFUNC_DEF("get_end_bone_direction", 1, &spring_bone_simulator3d_class_get_end_bone_direction),
	JS_CFUNC_DEF("set_end_bone_length", 2, &spring_bone_simulator3d_class_set_end_bone_length),
	JS_CFUNC_DEF("get_end_bone_length", 1, &spring_bone_simulator3d_class_get_end_bone_length),
	JS_CFUNC_DEF("set_center_from", 2, &spring_bone_simulator3d_class_set_center_from),
	JS_CFUNC_DEF("get_center_from", 1, &spring_bone_simulator3d_class_get_center_from),
	JS_CFUNC_DEF("set_center_node", 2, &spring_bone_simulator3d_class_set_center_node),
	JS_CFUNC_DEF("get_center_node", 1, &spring_bone_simulator3d_class_get_center_node),
	JS_CFUNC_DEF("set_center_bone_name", 2, &spring_bone_simulator3d_class_set_center_bone_name),
	JS_CFUNC_DEF("get_center_bone_name", 1, &spring_bone_simulator3d_class_get_center_bone_name),
	JS_CFUNC_DEF("set_center_bone", 2, &spring_bone_simulator3d_class_set_center_bone),
	JS_CFUNC_DEF("get_center_bone", 1, &spring_bone_simulator3d_class_get_center_bone),
	JS_CFUNC_DEF("set_radius", 2, &spring_bone_simulator3d_class_set_radius),
	JS_CFUNC_DEF("get_radius", 1, &spring_bone_simulator3d_class_get_radius),
	JS_CFUNC_DEF("set_rotation_axis", 2, &spring_bone_simulator3d_class_set_rotation_axis),
	JS_CFUNC_DEF("get_rotation_axis", 1, &spring_bone_simulator3d_class_get_rotation_axis),
	JS_CFUNC_DEF("set_rotation_axis_vector", 2, &spring_bone_simulator3d_class_set_rotation_axis_vector),
	JS_CFUNC_DEF("get_rotation_axis_vector", 1, &spring_bone_simulator3d_class_get_rotation_axis_vector),
	JS_CFUNC_DEF("set_radius_damping_curve", 2, &spring_bone_simulator3d_class_set_radius_damping_curve),
	JS_CFUNC_DEF("get_radius_damping_curve", 1, &spring_bone_simulator3d_class_get_radius_damping_curve),
	JS_CFUNC_DEF("set_stiffness", 2, &spring_bone_simulator3d_class_set_stiffness),
	JS_CFUNC_DEF("get_stiffness", 1, &spring_bone_simulator3d_class_get_stiffness),
	JS_CFUNC_DEF("set_stiffness_damping_curve", 2, &spring_bone_simulator3d_class_set_stiffness_damping_curve),
	JS_CFUNC_DEF("get_stiffness_damping_curve", 1, &spring_bone_simulator3d_class_get_stiffness_damping_curve),
	JS_CFUNC_DEF("set_drag", 2, &spring_bone_simulator3d_class_set_drag),
	JS_CFUNC_DEF("get_drag", 1, &spring_bone_simulator3d_class_get_drag),
	JS_CFUNC_DEF("set_drag_damping_curve", 2, &spring_bone_simulator3d_class_set_drag_damping_curve),
	JS_CFUNC_DEF("get_drag_damping_curve", 1, &spring_bone_simulator3d_class_get_drag_damping_curve),
	JS_CFUNC_DEF("set_gravity", 2, &spring_bone_simulator3d_class_set_gravity),
	JS_CFUNC_DEF("get_gravity", 1, &spring_bone_simulator3d_class_get_gravity),
	JS_CFUNC_DEF("set_gravity_damping_curve", 2, &spring_bone_simulator3d_class_set_gravity_damping_curve),
	JS_CFUNC_DEF("get_gravity_damping_curve", 1, &spring_bone_simulator3d_class_get_gravity_damping_curve),
	JS_CFUNC_DEF("set_gravity_direction", 2, &spring_bone_simulator3d_class_set_gravity_direction),
	JS_CFUNC_DEF("get_gravity_direction", 1, &spring_bone_simulator3d_class_get_gravity_direction),
	JS_CFUNC_DEF("set_setting_count", 1, &spring_bone_simulator3d_class_set_setting_count),
	JS_CFUNC_DEF("get_setting_count", 0, &spring_bone_simulator3d_class_get_setting_count),
	JS_CFUNC_DEF("clear_settings", 0, &spring_bone_simulator3d_class_clear_settings),
	JS_CFUNC_DEF("set_individual_config", 2, &spring_bone_simulator3d_class_set_individual_config),
	JS_CFUNC_DEF("is_config_individual", 1, &spring_bone_simulator3d_class_is_config_individual),
	JS_CFUNC_DEF("get_joint_bone_name", 2, &spring_bone_simulator3d_class_get_joint_bone_name),
	JS_CFUNC_DEF("get_joint_bone", 2, &spring_bone_simulator3d_class_get_joint_bone),
	JS_CFUNC_DEF("set_joint_rotation_axis", 3, &spring_bone_simulator3d_class_set_joint_rotation_axis),
	JS_CFUNC_DEF("get_joint_rotation_axis", 2, &spring_bone_simulator3d_class_get_joint_rotation_axis),
	JS_CFUNC_DEF("set_joint_rotation_axis_vector", 3, &spring_bone_simulator3d_class_set_joint_rotation_axis_vector),
	JS_CFUNC_DEF("get_joint_rotation_axis_vector", 2, &spring_bone_simulator3d_class_get_joint_rotation_axis_vector),
	JS_CFUNC_DEF("set_joint_radius", 3, &spring_bone_simulator3d_class_set_joint_radius),
	JS_CFUNC_DEF("get_joint_radius", 2, &spring_bone_simulator3d_class_get_joint_radius),
	JS_CFUNC_DEF("set_joint_stiffness", 3, &spring_bone_simulator3d_class_set_joint_stiffness),
	JS_CFUNC_DEF("get_joint_stiffness", 2, &spring_bone_simulator3d_class_get_joint_stiffness),
	JS_CFUNC_DEF("set_joint_drag", 3, &spring_bone_simulator3d_class_set_joint_drag),
	JS_CFUNC_DEF("get_joint_drag", 2, &spring_bone_simulator3d_class_get_joint_drag),
	JS_CFUNC_DEF("set_joint_gravity", 3, &spring_bone_simulator3d_class_set_joint_gravity),
	JS_CFUNC_DEF("get_joint_gravity", 2, &spring_bone_simulator3d_class_get_joint_gravity),
	JS_CFUNC_DEF("set_joint_gravity_direction", 3, &spring_bone_simulator3d_class_set_joint_gravity_direction),
	JS_CFUNC_DEF("get_joint_gravity_direction", 2, &spring_bone_simulator3d_class_get_joint_gravity_direction),
	JS_CFUNC_DEF("get_joint_count", 1, &spring_bone_simulator3d_class_get_joint_count),
	JS_CFUNC_DEF("set_enable_all_child_collisions", 2, &spring_bone_simulator3d_class_set_enable_all_child_collisions),
	JS_CFUNC_DEF("are_all_child_collisions_enabled", 1, &spring_bone_simulator3d_class_are_all_child_collisions_enabled),
	JS_CFUNC_DEF("set_exclude_collision_path", 3, &spring_bone_simulator3d_class_set_exclude_collision_path),
	JS_CFUNC_DEF("get_exclude_collision_path", 2, &spring_bone_simulator3d_class_get_exclude_collision_path),
	JS_CFUNC_DEF("set_exclude_collision_count", 2, &spring_bone_simulator3d_class_set_exclude_collision_count),
	JS_CFUNC_DEF("get_exclude_collision_count", 1, &spring_bone_simulator3d_class_get_exclude_collision_count),
	JS_CFUNC_DEF("clear_exclude_collisions", 1, &spring_bone_simulator3d_class_clear_exclude_collisions),
	JS_CFUNC_DEF("set_collision_path", 3, &spring_bone_simulator3d_class_set_collision_path),
	JS_CFUNC_DEF("get_collision_path", 2, &spring_bone_simulator3d_class_get_collision_path),
	JS_CFUNC_DEF("set_collision_count", 2, &spring_bone_simulator3d_class_set_collision_count),
	JS_CFUNC_DEF("get_collision_count", 1, &spring_bone_simulator3d_class_get_collision_count),
	JS_CFUNC_DEF("clear_collisions", 1, &spring_bone_simulator3d_class_clear_collisions),
	JS_CFUNC_DEF("set_external_force", 1, &spring_bone_simulator3d_class_set_external_force),
	JS_CFUNC_DEF("get_external_force", 0, &spring_bone_simulator3d_class_get_external_force),
	JS_CFUNC_DEF("reset", 0, &spring_bone_simulator3d_class_reset),
};




static void define_spring_bone_simulator3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "external_force"),
        JS_NewCFunction(ctx, spring_bone_simulator3d_class_get_external_force, "get_external_force", 0),
        JS_NewCFunction(ctx, spring_bone_simulator3d_class_set_external_force, "set_external_force", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "setting_count"),
        JS_NewCFunction(ctx, spring_bone_simulator3d_class_get_setting_count, "get_setting_count", 0),
        JS_NewCFunction(ctx, spring_bone_simulator3d_class_set_setting_count, "set_setting_count", 1),
        JS_PROP_GETSET
    );
}

static void define_spring_bone_simulator3d_enum(JSContext *ctx, JSValue ctor) {
	JSValue BoneDirection_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, BoneDirection_obj, "BONE_DIRECTION_PLUS_X", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, BoneDirection_obj, "BONE_DIRECTION_MINUS_X", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, BoneDirection_obj, "BONE_DIRECTION_PLUS_Y", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, BoneDirection_obj, "BONE_DIRECTION_MINUS_Y", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, BoneDirection_obj, "BONE_DIRECTION_PLUS_Z", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, BoneDirection_obj, "BONE_DIRECTION_MINUS_Z", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, BoneDirection_obj, "BONE_DIRECTION_FROM_PARENT", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, ctor, "BoneDirection", BoneDirection_obj);
	JSValue CenterFrom_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, CenterFrom_obj, "CENTER_FROM_WORLD_ORIGIN", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, CenterFrom_obj, "CENTER_FROM_NODE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, CenterFrom_obj, "CENTER_FROM_BONE", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "CenterFrom", CenterFrom_obj);
	JSValue RotationAxis_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, RotationAxis_obj, "ROTATION_AXIS_X", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, RotationAxis_obj, "ROTATION_AXIS_Y", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, RotationAxis_obj, "ROTATION_AXIS_Z", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, RotationAxis_obj, "ROTATION_AXIS_ALL", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, RotationAxis_obj, "ROTATION_AXIS_CUSTOM", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, ctor, "RotationAxis", RotationAxis_obj);
}

static int js_spring_bone_simulator3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["SpringBoneSimulator3D"] = class_id;
	classes_by_id[class_id] = "SpringBoneSimulator3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &spring_bone_simulator3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["SkeletonModifier3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_spring_bone_simulator3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, spring_bone_simulator3d_class_proto_funcs, _countof(spring_bone_simulator3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, spring_bone_simulator3d_class_constructor, "SpringBoneSimulator3D", 0, JS_CFUNC_constructor, 0);
	define_spring_bone_simulator3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "SpringBoneSimulator3D", ctor);

	return 0;
}

JSModuleDef *_js_init_spring_bone_simulator3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/skeleton_modifier3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_spring_bone_simulator3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "SpringBoneSimulator3D");
	return m;
}

JSModuleDef *js_init_spring_bone_simulator3d_module(JSContext *ctx) {
	return _js_init_spring_bone_simulator3d_module(ctx, "@godot/classes/spring_bone_simulator3d");
}

void __register_spring_bone_simulator3d() {
	js_init_spring_bone_simulator3d_module(js_context());
}

void register_spring_bone_simulator3d() {
	__register_spring_bone_simulator3d();
}