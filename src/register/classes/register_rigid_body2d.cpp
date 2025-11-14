#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/physics_body2d.hpp>
#include <godot_cpp/classes/physics_direct_body_state2d.hpp>
#include <godot_cpp/classes/physics_material.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/rigid_body2d.hpp>
using namespace godot;

static void rigid_body2d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["RigidBody2D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef rigid_body2d_class_def = {
    "RigidBody2D",
    rigid_body2d_class_finalizer
};

static JSValue rigid_body2d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["RigidBody2D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    RigidBody2D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<RigidBody2D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(RigidBody2D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue rigid_body2d_class_set_mass(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RigidBody2D::set_mass, ctx, this_val, argc, argv);
};
static JSValue rigid_body2d_class_get_mass(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RigidBody2D::get_mass, ctx, this_val, argc, argv);
}
static JSValue rigid_body2d_class_get_inertia(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RigidBody2D::get_inertia, ctx, this_val, argc, argv);
}
static JSValue rigid_body2d_class_set_inertia(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RigidBody2D::set_inertia, ctx, this_val, argc, argv);
};
static JSValue rigid_body2d_class_set_center_of_mass_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RigidBody2D::set_center_of_mass_mode, ctx, this_val, argc, argv);
};
static JSValue rigid_body2d_class_get_center_of_mass_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RigidBody2D::get_center_of_mass_mode, ctx, this_val, argc, argv);
}
static JSValue rigid_body2d_class_set_center_of_mass(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RigidBody2D::set_center_of_mass, ctx, this_val, argc, argv);
};
static JSValue rigid_body2d_class_get_center_of_mass(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		RigidBody2D *obj = static_cast<RigidBody2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_center_of_mass();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		RigidBody2D *js_proxy = static_cast<RigidBody2D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_center_of_mass(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2Proxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue rigid_body2d_class_set_physics_material_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RigidBody2D::set_physics_material_override, ctx, this_val, argc, argv);
};
static JSValue rigid_body2d_class_get_physics_material_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RigidBody2D::get_physics_material_override, ctx, this_val, argc, argv);
}
static JSValue rigid_body2d_class_set_gravity_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RigidBody2D::set_gravity_scale, ctx, this_val, argc, argv);
};
static JSValue rigid_body2d_class_get_gravity_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RigidBody2D::get_gravity_scale, ctx, this_val, argc, argv);
}
static JSValue rigid_body2d_class_set_linear_damp_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RigidBody2D::set_linear_damp_mode, ctx, this_val, argc, argv);
};
static JSValue rigid_body2d_class_get_linear_damp_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RigidBody2D::get_linear_damp_mode, ctx, this_val, argc, argv);
}
static JSValue rigid_body2d_class_set_angular_damp_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RigidBody2D::set_angular_damp_mode, ctx, this_val, argc, argv);
};
static JSValue rigid_body2d_class_get_angular_damp_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RigidBody2D::get_angular_damp_mode, ctx, this_val, argc, argv);
}
static JSValue rigid_body2d_class_set_linear_damp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RigidBody2D::set_linear_damp, ctx, this_val, argc, argv);
};
static JSValue rigid_body2d_class_get_linear_damp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RigidBody2D::get_linear_damp, ctx, this_val, argc, argv);
}
static JSValue rigid_body2d_class_set_angular_damp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RigidBody2D::set_angular_damp, ctx, this_val, argc, argv);
};
static JSValue rigid_body2d_class_get_angular_damp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RigidBody2D::get_angular_damp, ctx, this_val, argc, argv);
}
static JSValue rigid_body2d_class_set_linear_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RigidBody2D::set_linear_velocity, ctx, this_val, argc, argv);
};
static JSValue rigid_body2d_class_get_linear_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		RigidBody2D *obj = static_cast<RigidBody2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_linear_velocity();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		RigidBody2D *js_proxy = static_cast<RigidBody2D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_linear_velocity(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2Proxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue rigid_body2d_class_set_angular_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RigidBody2D::set_angular_velocity, ctx, this_val, argc, argv);
};
static JSValue rigid_body2d_class_get_angular_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RigidBody2D::get_angular_velocity, ctx, this_val, argc, argv);
}
static JSValue rigid_body2d_class_set_max_contacts_reported(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RigidBody2D::set_max_contacts_reported, ctx, this_val, argc, argv);
};
static JSValue rigid_body2d_class_get_max_contacts_reported(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RigidBody2D::get_max_contacts_reported, ctx, this_val, argc, argv);
}
static JSValue rigid_body2d_class_get_contact_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RigidBody2D::get_contact_count, ctx, this_val, argc, argv);
};
static JSValue rigid_body2d_class_set_use_custom_integrator(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RigidBody2D::set_use_custom_integrator, ctx, this_val, argc, argv);
};
static JSValue rigid_body2d_class_is_using_custom_integrator(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&RigidBody2D::is_using_custom_integrator, ctx, this_val, argc, argv);
}
static JSValue rigid_body2d_class_set_contact_monitor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RigidBody2D::set_contact_monitor, ctx, this_val, argc, argv);
};
static JSValue rigid_body2d_class_is_contact_monitor_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RigidBody2D::is_contact_monitor_enabled, ctx, this_val, argc, argv);
}
static JSValue rigid_body2d_class_set_continuous_collision_detection_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RigidBody2D::set_continuous_collision_detection_mode, ctx, this_val, argc, argv);
};
static JSValue rigid_body2d_class_get_continuous_collision_detection_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RigidBody2D::get_continuous_collision_detection_mode, ctx, this_val, argc, argv);
}
static JSValue rigid_body2d_class_set_axis_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RigidBody2D::set_axis_velocity, ctx, this_val, argc, argv);
};
static JSValue rigid_body2d_class_apply_central_impulse(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RigidBody2D::apply_central_impulse, ctx, this_val, argc, argv);
};
static JSValue rigid_body2d_class_apply_impulse(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RigidBody2D::apply_impulse, ctx, this_val, argc, argv);
};
static JSValue rigid_body2d_class_apply_torque_impulse(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RigidBody2D::apply_torque_impulse, ctx, this_val, argc, argv);
};
static JSValue rigid_body2d_class_apply_central_force(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RigidBody2D::apply_central_force, ctx, this_val, argc, argv);
};
static JSValue rigid_body2d_class_apply_force(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RigidBody2D::apply_force, ctx, this_val, argc, argv);
};
static JSValue rigid_body2d_class_apply_torque(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RigidBody2D::apply_torque, ctx, this_val, argc, argv);
};
static JSValue rigid_body2d_class_add_constant_central_force(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RigidBody2D::add_constant_central_force, ctx, this_val, argc, argv);
};
static JSValue rigid_body2d_class_add_constant_force(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RigidBody2D::add_constant_force, ctx, this_val, argc, argv);
};
static JSValue rigid_body2d_class_add_constant_torque(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RigidBody2D::add_constant_torque, ctx, this_val, argc, argv);
};
static JSValue rigid_body2d_class_set_constant_force(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RigidBody2D::set_constant_force, ctx, this_val, argc, argv);
};
static JSValue rigid_body2d_class_get_constant_force(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		RigidBody2D *obj = static_cast<RigidBody2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_constant_force();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		RigidBody2D *js_proxy = static_cast<RigidBody2D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_constant_force(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2Proxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue rigid_body2d_class_set_constant_torque(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RigidBody2D::set_constant_torque, ctx, this_val, argc, argv);
};
static JSValue rigid_body2d_class_get_constant_torque(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RigidBody2D::get_constant_torque, ctx, this_val, argc, argv);
}
static JSValue rigid_body2d_class_set_sleeping(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RigidBody2D::set_sleeping, ctx, this_val, argc, argv);
};
static JSValue rigid_body2d_class_is_sleeping(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RigidBody2D::is_sleeping, ctx, this_val, argc, argv);
}
static JSValue rigid_body2d_class_set_can_sleep(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RigidBody2D::set_can_sleep, ctx, this_val, argc, argv);
};
static JSValue rigid_body2d_class_is_able_to_sleep(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RigidBody2D::is_able_to_sleep, ctx, this_val, argc, argv);
}
static JSValue rigid_body2d_class_set_lock_rotation_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RigidBody2D::set_lock_rotation_enabled, ctx, this_val, argc, argv);
};
static JSValue rigid_body2d_class_is_lock_rotation_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RigidBody2D::is_lock_rotation_enabled, ctx, this_val, argc, argv);
}
static JSValue rigid_body2d_class_set_freeze_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RigidBody2D::set_freeze_enabled, ctx, this_val, argc, argv);
};
static JSValue rigid_body2d_class_is_freeze_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RigidBody2D::is_freeze_enabled, ctx, this_val, argc, argv);
}
static JSValue rigid_body2d_class_set_freeze_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RigidBody2D::set_freeze_mode, ctx, this_val, argc, argv);
};
static JSValue rigid_body2d_class_get_freeze_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RigidBody2D::get_freeze_mode, ctx, this_val, argc, argv);
}
static JSValue rigid_body2d_class_get_colliding_bodies(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RigidBody2D::get_colliding_bodies, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry rigid_body2d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_mass", 1, &rigid_body2d_class_set_mass),
	JS_CFUNC_DEF("get_mass", 0, &rigid_body2d_class_get_mass),
	JS_CFUNC_DEF("get_inertia", 0, &rigid_body2d_class_get_inertia),
	JS_CFUNC_DEF("set_inertia", 1, &rigid_body2d_class_set_inertia),
	JS_CFUNC_DEF("set_center_of_mass_mode", 1, &rigid_body2d_class_set_center_of_mass_mode),
	JS_CFUNC_DEF("get_center_of_mass_mode", 0, &rigid_body2d_class_get_center_of_mass_mode),
	JS_CFUNC_DEF("set_center_of_mass", 1, &rigid_body2d_class_set_center_of_mass),
	JS_CFUNC_DEF("get_center_of_mass", 0, &rigid_body2d_class_get_center_of_mass),
	JS_CFUNC_DEF("set_physics_material_override", 1, &rigid_body2d_class_set_physics_material_override),
	JS_CFUNC_DEF("get_physics_material_override", 0, &rigid_body2d_class_get_physics_material_override),
	JS_CFUNC_DEF("set_gravity_scale", 1, &rigid_body2d_class_set_gravity_scale),
	JS_CFUNC_DEF("get_gravity_scale", 0, &rigid_body2d_class_get_gravity_scale),
	JS_CFUNC_DEF("set_linear_damp_mode", 1, &rigid_body2d_class_set_linear_damp_mode),
	JS_CFUNC_DEF("get_linear_damp_mode", 0, &rigid_body2d_class_get_linear_damp_mode),
	JS_CFUNC_DEF("set_angular_damp_mode", 1, &rigid_body2d_class_set_angular_damp_mode),
	JS_CFUNC_DEF("get_angular_damp_mode", 0, &rigid_body2d_class_get_angular_damp_mode),
	JS_CFUNC_DEF("set_linear_damp", 1, &rigid_body2d_class_set_linear_damp),
	JS_CFUNC_DEF("get_linear_damp", 0, &rigid_body2d_class_get_linear_damp),
	JS_CFUNC_DEF("set_angular_damp", 1, &rigid_body2d_class_set_angular_damp),
	JS_CFUNC_DEF("get_angular_damp", 0, &rigid_body2d_class_get_angular_damp),
	JS_CFUNC_DEF("set_linear_velocity", 1, &rigid_body2d_class_set_linear_velocity),
	JS_CFUNC_DEF("get_linear_velocity", 0, &rigid_body2d_class_get_linear_velocity),
	JS_CFUNC_DEF("set_angular_velocity", 1, &rigid_body2d_class_set_angular_velocity),
	JS_CFUNC_DEF("get_angular_velocity", 0, &rigid_body2d_class_get_angular_velocity),
	JS_CFUNC_DEF("set_max_contacts_reported", 1, &rigid_body2d_class_set_max_contacts_reported),
	JS_CFUNC_DEF("get_max_contacts_reported", 0, &rigid_body2d_class_get_max_contacts_reported),
	JS_CFUNC_DEF("get_contact_count", 0, &rigid_body2d_class_get_contact_count),
	JS_CFUNC_DEF("set_use_custom_integrator", 1, &rigid_body2d_class_set_use_custom_integrator),
	JS_CFUNC_DEF("is_using_custom_integrator", 0, &rigid_body2d_class_is_using_custom_integrator),
	JS_CFUNC_DEF("set_contact_monitor", 1, &rigid_body2d_class_set_contact_monitor),
	JS_CFUNC_DEF("is_contact_monitor_enabled", 0, &rigid_body2d_class_is_contact_monitor_enabled),
	JS_CFUNC_DEF("set_continuous_collision_detection_mode", 1, &rigid_body2d_class_set_continuous_collision_detection_mode),
	JS_CFUNC_DEF("get_continuous_collision_detection_mode", 0, &rigid_body2d_class_get_continuous_collision_detection_mode),
	JS_CFUNC_DEF("set_axis_velocity", 1, &rigid_body2d_class_set_axis_velocity),
	JS_CFUNC_DEF("apply_central_impulse", 1, &rigid_body2d_class_apply_central_impulse),
	JS_CFUNC_DEF("apply_impulse", 2, &rigid_body2d_class_apply_impulse),
	JS_CFUNC_DEF("apply_torque_impulse", 1, &rigid_body2d_class_apply_torque_impulse),
	JS_CFUNC_DEF("apply_central_force", 1, &rigid_body2d_class_apply_central_force),
	JS_CFUNC_DEF("apply_force", 2, &rigid_body2d_class_apply_force),
	JS_CFUNC_DEF("apply_torque", 1, &rigid_body2d_class_apply_torque),
	JS_CFUNC_DEF("add_constant_central_force", 1, &rigid_body2d_class_add_constant_central_force),
	JS_CFUNC_DEF("add_constant_force", 2, &rigid_body2d_class_add_constant_force),
	JS_CFUNC_DEF("add_constant_torque", 1, &rigid_body2d_class_add_constant_torque),
	JS_CFUNC_DEF("set_constant_force", 1, &rigid_body2d_class_set_constant_force),
	JS_CFUNC_DEF("get_constant_force", 0, &rigid_body2d_class_get_constant_force),
	JS_CFUNC_DEF("set_constant_torque", 1, &rigid_body2d_class_set_constant_torque),
	JS_CFUNC_DEF("get_constant_torque", 0, &rigid_body2d_class_get_constant_torque),
	JS_CFUNC_DEF("set_sleeping", 1, &rigid_body2d_class_set_sleeping),
	JS_CFUNC_DEF("is_sleeping", 0, &rigid_body2d_class_is_sleeping),
	JS_CFUNC_DEF("set_can_sleep", 1, &rigid_body2d_class_set_can_sleep),
	JS_CFUNC_DEF("is_able_to_sleep", 0, &rigid_body2d_class_is_able_to_sleep),
	JS_CFUNC_DEF("set_lock_rotation_enabled", 1, &rigid_body2d_class_set_lock_rotation_enabled),
	JS_CFUNC_DEF("is_lock_rotation_enabled", 0, &rigid_body2d_class_is_lock_rotation_enabled),
	JS_CFUNC_DEF("set_freeze_enabled", 1, &rigid_body2d_class_set_freeze_enabled),
	JS_CFUNC_DEF("is_freeze_enabled", 0, &rigid_body2d_class_is_freeze_enabled),
	JS_CFUNC_DEF("set_freeze_mode", 1, &rigid_body2d_class_set_freeze_mode),
	JS_CFUNC_DEF("get_freeze_mode", 0, &rigid_body2d_class_get_freeze_mode),
	JS_CFUNC_DEF("get_colliding_bodies", 0, &rigid_body2d_class_get_colliding_bodies),
};


static JSValue rigid_body2d_class_get_body_shape_entered_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	RigidBody2D *opaque = static_cast<RigidBody2D *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "body_shape_entered_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "body_shape_entered"));
		JS_DefinePropertyValueStr(ctx, this_val, "body_shape_entered_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue rigid_body2d_class_get_body_shape_exited_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	RigidBody2D *opaque = static_cast<RigidBody2D *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "body_shape_exited_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "body_shape_exited"));
		JS_DefinePropertyValueStr(ctx, this_val, "body_shape_exited_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue rigid_body2d_class_get_body_entered_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	RigidBody2D *opaque = static_cast<RigidBody2D *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "body_entered_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "body_entered"));
		JS_DefinePropertyValueStr(ctx, this_val, "body_entered_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue rigid_body2d_class_get_body_exited_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	RigidBody2D *opaque = static_cast<RigidBody2D *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "body_exited_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "body_exited"));
		JS_DefinePropertyValueStr(ctx, this_val, "body_exited_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue rigid_body2d_class_get_sleeping_state_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	RigidBody2D *opaque = static_cast<RigidBody2D *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "sleeping_state_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "sleeping_state_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "sleeping_state_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_rigid_body2d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "mass"),
        JS_NewCFunction(ctx, rigid_body2d_class_get_mass, "get_mass", 0),
        JS_NewCFunction(ctx, rigid_body2d_class_set_mass, "set_mass", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "physics_material_override"),
        JS_NewCFunction(ctx, rigid_body2d_class_get_physics_material_override, "get_physics_material_override", 0),
        JS_NewCFunction(ctx, rigid_body2d_class_set_physics_material_override, "set_physics_material_override", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "gravity_scale"),
        JS_NewCFunction(ctx, rigid_body2d_class_get_gravity_scale, "get_gravity_scale", 0),
        JS_NewCFunction(ctx, rigid_body2d_class_set_gravity_scale, "set_gravity_scale", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "center_of_mass_mode"),
        JS_NewCFunction(ctx, rigid_body2d_class_get_center_of_mass_mode, "get_center_of_mass_mode", 0),
        JS_NewCFunction(ctx, rigid_body2d_class_set_center_of_mass_mode, "set_center_of_mass_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "center_of_mass"),
        JS_NewCFunction(ctx, rigid_body2d_class_get_center_of_mass, "get_center_of_mass", 0),
        JS_NewCFunction(ctx, rigid_body2d_class_set_center_of_mass, "set_center_of_mass", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "inertia"),
        JS_NewCFunction(ctx, rigid_body2d_class_get_inertia, "get_inertia", 0),
        JS_NewCFunction(ctx, rigid_body2d_class_set_inertia, "set_inertia", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "sleeping"),
        JS_NewCFunction(ctx, rigid_body2d_class_is_sleeping, "is_sleeping", 0),
        JS_NewCFunction(ctx, rigid_body2d_class_set_sleeping, "set_sleeping", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "can_sleep"),
        JS_NewCFunction(ctx, rigid_body2d_class_is_able_to_sleep, "is_able_to_sleep", 0),
        JS_NewCFunction(ctx, rigid_body2d_class_set_can_sleep, "set_can_sleep", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "lock_rotation"),
        JS_NewCFunction(ctx, rigid_body2d_class_is_lock_rotation_enabled, "is_lock_rotation_enabled", 0),
        JS_NewCFunction(ctx, rigid_body2d_class_set_lock_rotation_enabled, "set_lock_rotation_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "freeze"),
        JS_NewCFunction(ctx, rigid_body2d_class_is_freeze_enabled, "is_freeze_enabled", 0),
        JS_NewCFunction(ctx, rigid_body2d_class_set_freeze_enabled, "set_freeze_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "freeze_mode"),
        JS_NewCFunction(ctx, rigid_body2d_class_get_freeze_mode, "get_freeze_mode", 0),
        JS_NewCFunction(ctx, rigid_body2d_class_set_freeze_mode, "set_freeze_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "custom_integrator"),
        JS_NewCFunction(ctx, rigid_body2d_class_is_using_custom_integrator, "is_using_custom_integrator", 0),
        JS_NewCFunction(ctx, rigid_body2d_class_set_use_custom_integrator, "set_use_custom_integrator", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "continuous_cd"),
        JS_NewCFunction(ctx, rigid_body2d_class_get_continuous_collision_detection_mode, "get_continuous_collision_detection_mode", 0),
        JS_NewCFunction(ctx, rigid_body2d_class_set_continuous_collision_detection_mode, "set_continuous_collision_detection_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "contact_monitor"),
        JS_NewCFunction(ctx, rigid_body2d_class_is_contact_monitor_enabled, "is_contact_monitor_enabled", 0),
        JS_NewCFunction(ctx, rigid_body2d_class_set_contact_monitor, "set_contact_monitor", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "max_contacts_reported"),
        JS_NewCFunction(ctx, rigid_body2d_class_get_max_contacts_reported, "get_max_contacts_reported", 0),
        JS_NewCFunction(ctx, rigid_body2d_class_set_max_contacts_reported, "set_max_contacts_reported", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "linear_velocity"),
        JS_NewCFunction(ctx, rigid_body2d_class_get_linear_velocity, "get_linear_velocity", 0),
        JS_NewCFunction(ctx, rigid_body2d_class_set_linear_velocity, "set_linear_velocity", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "linear_damp_mode"),
        JS_NewCFunction(ctx, rigid_body2d_class_get_linear_damp_mode, "get_linear_damp_mode", 0),
        JS_NewCFunction(ctx, rigid_body2d_class_set_linear_damp_mode, "set_linear_damp_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "linear_damp"),
        JS_NewCFunction(ctx, rigid_body2d_class_get_linear_damp, "get_linear_damp", 0),
        JS_NewCFunction(ctx, rigid_body2d_class_set_linear_damp, "set_linear_damp", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "angular_velocity"),
        JS_NewCFunction(ctx, rigid_body2d_class_get_angular_velocity, "get_angular_velocity", 0),
        JS_NewCFunction(ctx, rigid_body2d_class_set_angular_velocity, "set_angular_velocity", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "angular_damp_mode"),
        JS_NewCFunction(ctx, rigid_body2d_class_get_angular_damp_mode, "get_angular_damp_mode", 0),
        JS_NewCFunction(ctx, rigid_body2d_class_set_angular_damp_mode, "set_angular_damp_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "angular_damp"),
        JS_NewCFunction(ctx, rigid_body2d_class_get_angular_damp, "get_angular_damp", 0),
        JS_NewCFunction(ctx, rigid_body2d_class_set_angular_damp, "set_angular_damp", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "constant_force"),
        JS_NewCFunction(ctx, rigid_body2d_class_get_constant_force, "get_constant_force", 0),
        JS_NewCFunction(ctx, rigid_body2d_class_set_constant_force, "set_constant_force", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "constant_torque"),
        JS_NewCFunction(ctx, rigid_body2d_class_get_constant_torque, "get_constant_torque", 0),
        JS_NewCFunction(ctx, rigid_body2d_class_set_constant_torque, "set_constant_torque", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "body_shape_entered"),
		JS_NewCFunction(ctx, rigid_body2d_class_get_body_shape_entered_signal, "get_body_shape_entered_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "body_shape_exited"),
		JS_NewCFunction(ctx, rigid_body2d_class_get_body_shape_exited_signal, "get_body_shape_exited_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "body_entered"),
		JS_NewCFunction(ctx, rigid_body2d_class_get_body_entered_signal, "get_body_entered_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "body_exited"),
		JS_NewCFunction(ctx, rigid_body2d_class_get_body_exited_signal, "get_body_exited_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "sleeping_state_changed"),
		JS_NewCFunction(ctx, rigid_body2d_class_get_sleeping_state_changed_signal, "get_sleeping_state_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_rigid_body2d_enum(JSContext *ctx, JSValue proto) {
	JSValue FreezeMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, FreezeMode_obj, "FREEZE_MODE_STATIC", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, FreezeMode_obj, "FREEZE_MODE_KINEMATIC", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, proto, "FreezeMode", FreezeMode_obj);
	JSValue CenterOfMassMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, CenterOfMassMode_obj, "CENTER_OF_MASS_MODE_AUTO", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, CenterOfMassMode_obj, "CENTER_OF_MASS_MODE_CUSTOM", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, proto, "CenterOfMassMode", CenterOfMassMode_obj);
	JSValue DampMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, DampMode_obj, "DAMP_MODE_COMBINE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, DampMode_obj, "DAMP_MODE_REPLACE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, proto, "DampMode", DampMode_obj);
	JSValue CCDMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, CCDMode_obj, "CCD_MODE_DISABLED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, CCDMode_obj, "CCD_MODE_CAST_RAY", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, CCDMode_obj, "CCD_MODE_CAST_SHAPE", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, proto, "CCDMode", CCDMode_obj);
}

static int js_rigid_body2d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["RigidBody2D"] = class_id;
	classes_by_id[class_id] = "RigidBody2D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &rigid_body2d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["PhysicsBody2D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_rigid_body2d_property(ctx, proto);
	define_rigid_body2d_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, rigid_body2d_class_proto_funcs, _countof(rigid_body2d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, rigid_body2d_class_constructor, "RigidBody2D", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "RigidBody2D", ctor);

	return 0;
}

JSModuleDef *_js_init_rigid_body2d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/physics_body2d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_rigid_body2d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "RigidBody2D");
	return m;
}

JSModuleDef *js_init_rigid_body2d_module(JSContext *ctx) {
	return _js_init_rigid_body2d_module(ctx, "@godot/classes/rigid_body2d");
}

void __register_rigid_body2d() {
	js_init_rigid_body2d_module(js_context());
}

void register_rigid_body2d() {
	__register_rigid_body2d();
}