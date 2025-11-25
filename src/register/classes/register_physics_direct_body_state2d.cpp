#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/physics_direct_space_state2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/physics_direct_body_state2d.hpp>
using namespace godot;

static void physics_direct_body_state2d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["PhysicsDirectBodyState2D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef physics_direct_body_state2d_class_def = {
    "PhysicsDirectBodyState2D",
    physics_direct_body_state2d_class_finalizer
};

static JSValue physics_direct_body_state2d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["PhysicsDirectBodyState2D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

	VariantAdapter *adapter = nullptr;
	Object *instance = nullptr;
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
    	instance = static_cast<VariantAdapter *>(JS_GetOpaque(*argv, class_id))->get();
		adapter = memnew(VariantAdapter(instance));
    } else {
        instance = memnew(PhysicsDirectBodyState2D);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue physics_direct_body_state2d_class_get_total_gravity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		PhysicsDirectBodyState2D *obj = static_cast<PhysicsDirectBodyState2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_total_gravity();
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2Proxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue physics_direct_body_state2d_class_get_total_linear_damp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsDirectBodyState2D::get_total_linear_damp, ctx, this_val, argc, argv);
}
static JSValue physics_direct_body_state2d_class_get_total_angular_damp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsDirectBodyState2D::get_total_angular_damp, ctx, this_val, argc, argv);
}
static JSValue physics_direct_body_state2d_class_get_center_of_mass(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		PhysicsDirectBodyState2D *obj = static_cast<PhysicsDirectBodyState2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_center_of_mass();
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2Proxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue physics_direct_body_state2d_class_get_center_of_mass_local(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		PhysicsDirectBodyState2D *obj = static_cast<PhysicsDirectBodyState2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_center_of_mass_local();
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2Proxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue physics_direct_body_state2d_class_get_inverse_mass(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsDirectBodyState2D::get_inverse_mass, ctx, this_val, argc, argv);
}
static JSValue physics_direct_body_state2d_class_get_inverse_inertia(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsDirectBodyState2D::get_inverse_inertia, ctx, this_val, argc, argv);
}
static JSValue physics_direct_body_state2d_class_set_linear_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsDirectBodyState2D::set_linear_velocity, ctx, this_val, argc, argv);
};
static JSValue physics_direct_body_state2d_class_get_linear_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		PhysicsDirectBodyState2D *obj = static_cast<PhysicsDirectBodyState2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_linear_velocity();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		PhysicsDirectBodyState2D *js_proxy = static_cast<PhysicsDirectBodyState2D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_linear_velocity(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2Proxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue physics_direct_body_state2d_class_set_angular_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsDirectBodyState2D::set_angular_velocity, ctx, this_val, argc, argv);
};
static JSValue physics_direct_body_state2d_class_get_angular_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsDirectBodyState2D::get_angular_velocity, ctx, this_val, argc, argv);
}
static JSValue physics_direct_body_state2d_class_set_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsDirectBodyState2D::set_transform, ctx, this_val, argc, argv);
};
static JSValue physics_direct_body_state2d_class_get_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Transform2D> *proxy = memnew(ObjectProxy<Transform2D>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Transform2D {
		PhysicsDirectBodyState2D *obj = static_cast<PhysicsDirectBodyState2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_transform();
	};
	proxy->setter = [this_val](const Transform2D &value) -> void {
		PhysicsDirectBodyState2D *js_proxy = static_cast<PhysicsDirectBodyState2D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_transform(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Transform2DProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Transform2DProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue physics_direct_body_state2d_class_get_velocity_at_local_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsDirectBodyState2D::get_velocity_at_local_position, ctx, this_val, argc, argv);
};
static JSValue physics_direct_body_state2d_class_apply_central_impulse(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsDirectBodyState2D::apply_central_impulse, ctx, this_val, argc, argv);
};
static JSValue physics_direct_body_state2d_class_apply_torque_impulse(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsDirectBodyState2D::apply_torque_impulse, ctx, this_val, argc, argv);
};
static JSValue physics_direct_body_state2d_class_apply_impulse(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsDirectBodyState2D::apply_impulse, ctx, this_val, argc, argv);
};
static JSValue physics_direct_body_state2d_class_apply_central_force(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsDirectBodyState2D::apply_central_force, ctx, this_val, argc, argv);
};
static JSValue physics_direct_body_state2d_class_apply_force(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsDirectBodyState2D::apply_force, ctx, this_val, argc, argv);
};
static JSValue physics_direct_body_state2d_class_apply_torque(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsDirectBodyState2D::apply_torque, ctx, this_val, argc, argv);
};
static JSValue physics_direct_body_state2d_class_add_constant_central_force(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsDirectBodyState2D::add_constant_central_force, ctx, this_val, argc, argv);
};
static JSValue physics_direct_body_state2d_class_add_constant_force(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsDirectBodyState2D::add_constant_force, ctx, this_val, argc, argv);
};
static JSValue physics_direct_body_state2d_class_add_constant_torque(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsDirectBodyState2D::add_constant_torque, ctx, this_val, argc, argv);
};
static JSValue physics_direct_body_state2d_class_set_constant_force(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsDirectBodyState2D::set_constant_force, ctx, this_val, argc, argv);
};
static JSValue physics_direct_body_state2d_class_get_constant_force(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsDirectBodyState2D::get_constant_force, ctx, this_val, argc, argv);
};
static JSValue physics_direct_body_state2d_class_set_constant_torque(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsDirectBodyState2D::set_constant_torque, ctx, this_val, argc, argv);
};
static JSValue physics_direct_body_state2d_class_get_constant_torque(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsDirectBodyState2D::get_constant_torque, ctx, this_val, argc, argv);
};
static JSValue physics_direct_body_state2d_class_set_sleep_state(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsDirectBodyState2D::set_sleep_state, ctx, this_val, argc, argv);
};
static JSValue physics_direct_body_state2d_class_is_sleeping(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsDirectBodyState2D::is_sleeping, ctx, this_val, argc, argv);
}
static JSValue physics_direct_body_state2d_class_set_collision_layer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsDirectBodyState2D::set_collision_layer, ctx, this_val, argc, argv);
};
static JSValue physics_direct_body_state2d_class_get_collision_layer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsDirectBodyState2D::get_collision_layer, ctx, this_val, argc, argv);
}
static JSValue physics_direct_body_state2d_class_set_collision_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsDirectBodyState2D::set_collision_mask, ctx, this_val, argc, argv);
};
static JSValue physics_direct_body_state2d_class_get_collision_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsDirectBodyState2D::get_collision_mask, ctx, this_val, argc, argv);
}
static JSValue physics_direct_body_state2d_class_get_contact_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsDirectBodyState2D::get_contact_count, ctx, this_val, argc, argv);
};
static JSValue physics_direct_body_state2d_class_get_contact_local_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsDirectBodyState2D::get_contact_local_position, ctx, this_val, argc, argv);
};
static JSValue physics_direct_body_state2d_class_get_contact_local_normal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsDirectBodyState2D::get_contact_local_normal, ctx, this_val, argc, argv);
};
static JSValue physics_direct_body_state2d_class_get_contact_local_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsDirectBodyState2D::get_contact_local_shape, ctx, this_val, argc, argv);
};
static JSValue physics_direct_body_state2d_class_get_contact_local_velocity_at_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsDirectBodyState2D::get_contact_local_velocity_at_position, ctx, this_val, argc, argv);
};
static JSValue physics_direct_body_state2d_class_get_contact_collider(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsDirectBodyState2D::get_contact_collider, ctx, this_val, argc, argv);
};
static JSValue physics_direct_body_state2d_class_get_contact_collider_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsDirectBodyState2D::get_contact_collider_position, ctx, this_val, argc, argv);
};
static JSValue physics_direct_body_state2d_class_get_contact_collider_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsDirectBodyState2D::get_contact_collider_id, ctx, this_val, argc, argv);
};
static JSValue physics_direct_body_state2d_class_get_contact_collider_object(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsDirectBodyState2D::get_contact_collider_object, ctx, this_val, argc, argv);
};
static JSValue physics_direct_body_state2d_class_get_contact_collider_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsDirectBodyState2D::get_contact_collider_shape, ctx, this_val, argc, argv);
};
static JSValue physics_direct_body_state2d_class_get_contact_collider_velocity_at_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsDirectBodyState2D::get_contact_collider_velocity_at_position, ctx, this_val, argc, argv);
};
static JSValue physics_direct_body_state2d_class_get_contact_impulse(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsDirectBodyState2D::get_contact_impulse, ctx, this_val, argc, argv);
};
static JSValue physics_direct_body_state2d_class_get_step(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicsDirectBodyState2D::get_step, ctx, this_val, argc, argv);
}
static JSValue physics_direct_body_state2d_class_integrate_forces(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicsDirectBodyState2D::integrate_forces, ctx, this_val, argc, argv);
};
static JSValue physics_direct_body_state2d_class_get_space_state(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&PhysicsDirectBodyState2D::get_space_state, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry physics_direct_body_state2d_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_total_gravity", 0, &physics_direct_body_state2d_class_get_total_gravity),
	JS_CFUNC_DEF("get_total_linear_damp", 0, &physics_direct_body_state2d_class_get_total_linear_damp),
	JS_CFUNC_DEF("get_total_angular_damp", 0, &physics_direct_body_state2d_class_get_total_angular_damp),
	JS_CFUNC_DEF("get_center_of_mass", 0, &physics_direct_body_state2d_class_get_center_of_mass),
	JS_CFUNC_DEF("get_center_of_mass_local", 0, &physics_direct_body_state2d_class_get_center_of_mass_local),
	JS_CFUNC_DEF("get_inverse_mass", 0, &physics_direct_body_state2d_class_get_inverse_mass),
	JS_CFUNC_DEF("get_inverse_inertia", 0, &physics_direct_body_state2d_class_get_inverse_inertia),
	JS_CFUNC_DEF("set_linear_velocity", 1, &physics_direct_body_state2d_class_set_linear_velocity),
	JS_CFUNC_DEF("get_linear_velocity", 0, &physics_direct_body_state2d_class_get_linear_velocity),
	JS_CFUNC_DEF("set_angular_velocity", 1, &physics_direct_body_state2d_class_set_angular_velocity),
	JS_CFUNC_DEF("get_angular_velocity", 0, &physics_direct_body_state2d_class_get_angular_velocity),
	JS_CFUNC_DEF("set_transform", 1, &physics_direct_body_state2d_class_set_transform),
	JS_CFUNC_DEF("get_transform", 0, &physics_direct_body_state2d_class_get_transform),
	JS_CFUNC_DEF("get_velocity_at_local_position", 1, &physics_direct_body_state2d_class_get_velocity_at_local_position),
	JS_CFUNC_DEF("apply_central_impulse", 1, &physics_direct_body_state2d_class_apply_central_impulse),
	JS_CFUNC_DEF("apply_torque_impulse", 1, &physics_direct_body_state2d_class_apply_torque_impulse),
	JS_CFUNC_DEF("apply_impulse", 2, &physics_direct_body_state2d_class_apply_impulse),
	JS_CFUNC_DEF("apply_central_force", 1, &physics_direct_body_state2d_class_apply_central_force),
	JS_CFUNC_DEF("apply_force", 2, &physics_direct_body_state2d_class_apply_force),
	JS_CFUNC_DEF("apply_torque", 1, &physics_direct_body_state2d_class_apply_torque),
	JS_CFUNC_DEF("add_constant_central_force", 1, &physics_direct_body_state2d_class_add_constant_central_force),
	JS_CFUNC_DEF("add_constant_force", 2, &physics_direct_body_state2d_class_add_constant_force),
	JS_CFUNC_DEF("add_constant_torque", 1, &physics_direct_body_state2d_class_add_constant_torque),
	JS_CFUNC_DEF("set_constant_force", 1, &physics_direct_body_state2d_class_set_constant_force),
	JS_CFUNC_DEF("get_constant_force", 0, &physics_direct_body_state2d_class_get_constant_force),
	JS_CFUNC_DEF("set_constant_torque", 1, &physics_direct_body_state2d_class_set_constant_torque),
	JS_CFUNC_DEF("get_constant_torque", 0, &physics_direct_body_state2d_class_get_constant_torque),
	JS_CFUNC_DEF("set_sleep_state", 1, &physics_direct_body_state2d_class_set_sleep_state),
	JS_CFUNC_DEF("is_sleeping", 0, &physics_direct_body_state2d_class_is_sleeping),
	JS_CFUNC_DEF("set_collision_layer", 1, &physics_direct_body_state2d_class_set_collision_layer),
	JS_CFUNC_DEF("get_collision_layer", 0, &physics_direct_body_state2d_class_get_collision_layer),
	JS_CFUNC_DEF("set_collision_mask", 1, &physics_direct_body_state2d_class_set_collision_mask),
	JS_CFUNC_DEF("get_collision_mask", 0, &physics_direct_body_state2d_class_get_collision_mask),
	JS_CFUNC_DEF("get_contact_count", 0, &physics_direct_body_state2d_class_get_contact_count),
	JS_CFUNC_DEF("get_contact_local_position", 1, &physics_direct_body_state2d_class_get_contact_local_position),
	JS_CFUNC_DEF("get_contact_local_normal", 1, &physics_direct_body_state2d_class_get_contact_local_normal),
	JS_CFUNC_DEF("get_contact_local_shape", 1, &physics_direct_body_state2d_class_get_contact_local_shape),
	JS_CFUNC_DEF("get_contact_local_velocity_at_position", 1, &physics_direct_body_state2d_class_get_contact_local_velocity_at_position),
	JS_CFUNC_DEF("get_contact_collider", 1, &physics_direct_body_state2d_class_get_contact_collider),
	JS_CFUNC_DEF("get_contact_collider_position", 1, &physics_direct_body_state2d_class_get_contact_collider_position),
	JS_CFUNC_DEF("get_contact_collider_id", 1, &physics_direct_body_state2d_class_get_contact_collider_id),
	JS_CFUNC_DEF("get_contact_collider_object", 1, &physics_direct_body_state2d_class_get_contact_collider_object),
	JS_CFUNC_DEF("get_contact_collider_shape", 1, &physics_direct_body_state2d_class_get_contact_collider_shape),
	JS_CFUNC_DEF("get_contact_collider_velocity_at_position", 1, &physics_direct_body_state2d_class_get_contact_collider_velocity_at_position),
	JS_CFUNC_DEF("get_contact_impulse", 1, &physics_direct_body_state2d_class_get_contact_impulse),
	JS_CFUNC_DEF("get_step", 0, &physics_direct_body_state2d_class_get_step),
	JS_CFUNC_DEF("integrate_forces", 0, &physics_direct_body_state2d_class_integrate_forces),
	JS_CFUNC_DEF("get_space_state", 0, &physics_direct_body_state2d_class_get_space_state),
};




static void define_physics_direct_body_state2d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "step"),
        JS_NewCFunction(ctx, physics_direct_body_state2d_class_get_step, "get_step", 0),
        JS_UNDEFINED,
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "inverse_mass"),
        JS_NewCFunction(ctx, physics_direct_body_state2d_class_get_inverse_mass, "get_inverse_mass", 0),
        JS_UNDEFINED,
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "inverse_inertia"),
        JS_NewCFunction(ctx, physics_direct_body_state2d_class_get_inverse_inertia, "get_inverse_inertia", 0),
        JS_UNDEFINED,
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "total_angular_damp"),
        JS_NewCFunction(ctx, physics_direct_body_state2d_class_get_total_angular_damp, "get_total_angular_damp", 0),
        JS_UNDEFINED,
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "total_linear_damp"),
        JS_NewCFunction(ctx, physics_direct_body_state2d_class_get_total_linear_damp, "get_total_linear_damp", 0),
        JS_UNDEFINED,
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "total_gravity"),
        JS_NewCFunction(ctx, physics_direct_body_state2d_class_get_total_gravity, "get_total_gravity", 0),
        JS_UNDEFINED,
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "center_of_mass"),
        JS_NewCFunction(ctx, physics_direct_body_state2d_class_get_center_of_mass, "get_center_of_mass", 0),
        JS_UNDEFINED,
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "center_of_mass_local"),
        JS_NewCFunction(ctx, physics_direct_body_state2d_class_get_center_of_mass_local, "get_center_of_mass_local", 0),
        JS_UNDEFINED,
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "angular_velocity"),
        JS_NewCFunction(ctx, physics_direct_body_state2d_class_get_angular_velocity, "get_angular_velocity", 0),
        JS_NewCFunction(ctx, physics_direct_body_state2d_class_set_angular_velocity, "set_angular_velocity", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "linear_velocity"),
        JS_NewCFunction(ctx, physics_direct_body_state2d_class_get_linear_velocity, "get_linear_velocity", 0),
        JS_NewCFunction(ctx, physics_direct_body_state2d_class_set_linear_velocity, "set_linear_velocity", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "sleeping"),
        JS_NewCFunction(ctx, physics_direct_body_state2d_class_is_sleeping, "is_sleeping", 0),
        JS_NewCFunction(ctx, physics_direct_body_state2d_class_set_sleep_state, "set_sleep_state", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "collision_layer"),
        JS_NewCFunction(ctx, physics_direct_body_state2d_class_get_collision_layer, "get_collision_layer", 0),
        JS_NewCFunction(ctx, physics_direct_body_state2d_class_set_collision_layer, "set_collision_layer", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "collision_mask"),
        JS_NewCFunction(ctx, physics_direct_body_state2d_class_get_collision_mask, "get_collision_mask", 0),
        JS_NewCFunction(ctx, physics_direct_body_state2d_class_set_collision_mask, "set_collision_mask", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "transform"),
        JS_NewCFunction(ctx, physics_direct_body_state2d_class_get_transform, "get_transform", 0),
        JS_NewCFunction(ctx, physics_direct_body_state2d_class_set_transform, "set_transform", 1),
        JS_PROP_GETSET
    );
}

static void define_physics_direct_body_state2d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_physics_direct_body_state2d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["PhysicsDirectBodyState2D"] = class_id;
	classes_by_id[class_id] = "PhysicsDirectBodyState2D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &physics_direct_body_state2d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["GodotObject"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_physics_direct_body_state2d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, physics_direct_body_state2d_class_proto_funcs, _countof(physics_direct_body_state2d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, physics_direct_body_state2d_class_constructor, "PhysicsDirectBodyState2D", 0, JS_CFUNC_constructor, 0);
	define_physics_direct_body_state2d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "PhysicsDirectBodyState2D", ctor);
	ctor_list["PhysicsDirectBodyState2D"] = ctor;

	return 0;
}

JSModuleDef *_js_init_physics_direct_body_state2d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/godot_object';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_physics_direct_body_state2d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "PhysicsDirectBodyState2D");
	return m;
}

JSModuleDef *js_init_physics_direct_body_state2d_module(JSContext *ctx) {
	return _js_init_physics_direct_body_state2d_module(ctx, "@godot/classes/physics_direct_body_state2d");
}

void __register_physics_direct_body_state2d() {
	js_init_physics_direct_body_state2d_module(js_context());
}

void register_physics_direct_body_state2d() {
	__register_physics_direct_body_state2d();
}