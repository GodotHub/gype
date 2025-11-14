#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/physics_body3d.hpp>
#include <godot_cpp/classes/physics_direct_body_state3d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/physical_bone3d.hpp>
using namespace godot;

static void physical_bone3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["PhysicalBone3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef physical_bone3d_class_def = {
    "PhysicalBone3D",
    physical_bone3d_class_finalizer
};

static JSValue physical_bone3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["PhysicalBone3D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    PhysicalBone3D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<PhysicalBone3D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(PhysicalBone3D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue physical_bone3d_class_apply_central_impulse(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicalBone3D::apply_central_impulse, ctx, this_val, argc, argv);
};
static JSValue physical_bone3d_class_apply_impulse(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicalBone3D::apply_impulse, ctx, this_val, argc, argv);
};
static JSValue physical_bone3d_class_set_joint_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicalBone3D::set_joint_type, ctx, this_val, argc, argv);
};
static JSValue physical_bone3d_class_get_joint_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicalBone3D::get_joint_type, ctx, this_val, argc, argv);
}
static JSValue physical_bone3d_class_set_joint_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicalBone3D::set_joint_offset, ctx, this_val, argc, argv);
};
static JSValue physical_bone3d_class_get_joint_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Transform3D> *proxy = memnew(ObjectProxy<Transform3D>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Transform3D {
		PhysicalBone3D *obj = static_cast<PhysicalBone3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_joint_offset();
	};
	proxy->setter = [this_val](const Transform3D &value) -> void {
		PhysicalBone3D *js_proxy = static_cast<PhysicalBone3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_joint_offset(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Transform3DProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Transform3DProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue physical_bone3d_class_set_joint_rotation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicalBone3D::set_joint_rotation, ctx, this_val, argc, argv);
};
static JSValue physical_bone3d_class_get_joint_rotation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector3> *proxy = memnew(ObjectProxy<Vector3>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector3 {
		PhysicalBone3D *obj = static_cast<PhysicalBone3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_joint_rotation();
	};
	proxy->setter = [this_val](const Vector3 &value) -> void {
		PhysicalBone3D *js_proxy = static_cast<PhysicalBone3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_joint_rotation(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector3Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector3Proxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue physical_bone3d_class_set_body_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicalBone3D::set_body_offset, ctx, this_val, argc, argv);
};
static JSValue physical_bone3d_class_get_body_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Transform3D> *proxy = memnew(ObjectProxy<Transform3D>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Transform3D {
		PhysicalBone3D *obj = static_cast<PhysicalBone3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_body_offset();
	};
	proxy->setter = [this_val](const Transform3D &value) -> void {
		PhysicalBone3D *js_proxy = static_cast<PhysicalBone3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_body_offset(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Transform3DProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Transform3DProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue physical_bone3d_class_get_simulate_physics(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&PhysicalBone3D::get_simulate_physics, ctx, this_val, argc, argv);
};
static JSValue physical_bone3d_class_is_simulating_physics(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&PhysicalBone3D::is_simulating_physics, ctx, this_val, argc, argv);
};
static JSValue physical_bone3d_class_get_bone_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicalBone3D::get_bone_id, ctx, this_val, argc, argv);
};
static JSValue physical_bone3d_class_set_mass(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicalBone3D::set_mass, ctx, this_val, argc, argv);
};
static JSValue physical_bone3d_class_get_mass(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicalBone3D::get_mass, ctx, this_val, argc, argv);
}
static JSValue physical_bone3d_class_set_friction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicalBone3D::set_friction, ctx, this_val, argc, argv);
};
static JSValue physical_bone3d_class_get_friction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicalBone3D::get_friction, ctx, this_val, argc, argv);
}
static JSValue physical_bone3d_class_set_bounce(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicalBone3D::set_bounce, ctx, this_val, argc, argv);
};
static JSValue physical_bone3d_class_get_bounce(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicalBone3D::get_bounce, ctx, this_val, argc, argv);
}
static JSValue physical_bone3d_class_set_gravity_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicalBone3D::set_gravity_scale, ctx, this_val, argc, argv);
};
static JSValue physical_bone3d_class_get_gravity_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicalBone3D::get_gravity_scale, ctx, this_val, argc, argv);
}
static JSValue physical_bone3d_class_set_linear_damp_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicalBone3D::set_linear_damp_mode, ctx, this_val, argc, argv);
};
static JSValue physical_bone3d_class_get_linear_damp_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicalBone3D::get_linear_damp_mode, ctx, this_val, argc, argv);
}
static JSValue physical_bone3d_class_set_angular_damp_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicalBone3D::set_angular_damp_mode, ctx, this_val, argc, argv);
};
static JSValue physical_bone3d_class_get_angular_damp_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicalBone3D::get_angular_damp_mode, ctx, this_val, argc, argv);
}
static JSValue physical_bone3d_class_set_linear_damp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicalBone3D::set_linear_damp, ctx, this_val, argc, argv);
};
static JSValue physical_bone3d_class_get_linear_damp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicalBone3D::get_linear_damp, ctx, this_val, argc, argv);
}
static JSValue physical_bone3d_class_set_angular_damp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicalBone3D::set_angular_damp, ctx, this_val, argc, argv);
};
static JSValue physical_bone3d_class_get_angular_damp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicalBone3D::get_angular_damp, ctx, this_val, argc, argv);
}
static JSValue physical_bone3d_class_set_linear_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicalBone3D::set_linear_velocity, ctx, this_val, argc, argv);
};
static JSValue physical_bone3d_class_get_linear_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector3> *proxy = memnew(ObjectProxy<Vector3>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector3 {
		PhysicalBone3D *obj = static_cast<PhysicalBone3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_linear_velocity();
	};
	proxy->setter = [this_val](const Vector3 &value) -> void {
		PhysicalBone3D *js_proxy = static_cast<PhysicalBone3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_linear_velocity(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector3Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector3Proxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue physical_bone3d_class_set_angular_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicalBone3D::set_angular_velocity, ctx, this_val, argc, argv);
};
static JSValue physical_bone3d_class_get_angular_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector3> *proxy = memnew(ObjectProxy<Vector3>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector3 {
		PhysicalBone3D *obj = static_cast<PhysicalBone3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_angular_velocity();
	};
	proxy->setter = [this_val](const Vector3 &value) -> void {
		PhysicalBone3D *js_proxy = static_cast<PhysicalBone3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_angular_velocity(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector3Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector3Proxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue physical_bone3d_class_set_use_custom_integrator(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicalBone3D::set_use_custom_integrator, ctx, this_val, argc, argv);
};
static JSValue physical_bone3d_class_is_using_custom_integrator(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&PhysicalBone3D::is_using_custom_integrator, ctx, this_val, argc, argv);
}
static JSValue physical_bone3d_class_set_can_sleep(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PhysicalBone3D::set_can_sleep, ctx, this_val, argc, argv);
};
static JSValue physical_bone3d_class_is_able_to_sleep(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PhysicalBone3D::is_able_to_sleep, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry physical_bone3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("apply_central_impulse", 1, &physical_bone3d_class_apply_central_impulse),
	JS_CFUNC_DEF("apply_impulse", 2, &physical_bone3d_class_apply_impulse),
	JS_CFUNC_DEF("set_joint_type", 1, &physical_bone3d_class_set_joint_type),
	JS_CFUNC_DEF("get_joint_type", 0, &physical_bone3d_class_get_joint_type),
	JS_CFUNC_DEF("set_joint_offset", 1, &physical_bone3d_class_set_joint_offset),
	JS_CFUNC_DEF("get_joint_offset", 0, &physical_bone3d_class_get_joint_offset),
	JS_CFUNC_DEF("set_joint_rotation", 1, &physical_bone3d_class_set_joint_rotation),
	JS_CFUNC_DEF("get_joint_rotation", 0, &physical_bone3d_class_get_joint_rotation),
	JS_CFUNC_DEF("set_body_offset", 1, &physical_bone3d_class_set_body_offset),
	JS_CFUNC_DEF("get_body_offset", 0, &physical_bone3d_class_get_body_offset),
	JS_CFUNC_DEF("get_simulate_physics", 0, &physical_bone3d_class_get_simulate_physics),
	JS_CFUNC_DEF("is_simulating_physics", 0, &physical_bone3d_class_is_simulating_physics),
	JS_CFUNC_DEF("get_bone_id", 0, &physical_bone3d_class_get_bone_id),
	JS_CFUNC_DEF("set_mass", 1, &physical_bone3d_class_set_mass),
	JS_CFUNC_DEF("get_mass", 0, &physical_bone3d_class_get_mass),
	JS_CFUNC_DEF("set_friction", 1, &physical_bone3d_class_set_friction),
	JS_CFUNC_DEF("get_friction", 0, &physical_bone3d_class_get_friction),
	JS_CFUNC_DEF("set_bounce", 1, &physical_bone3d_class_set_bounce),
	JS_CFUNC_DEF("get_bounce", 0, &physical_bone3d_class_get_bounce),
	JS_CFUNC_DEF("set_gravity_scale", 1, &physical_bone3d_class_set_gravity_scale),
	JS_CFUNC_DEF("get_gravity_scale", 0, &physical_bone3d_class_get_gravity_scale),
	JS_CFUNC_DEF("set_linear_damp_mode", 1, &physical_bone3d_class_set_linear_damp_mode),
	JS_CFUNC_DEF("get_linear_damp_mode", 0, &physical_bone3d_class_get_linear_damp_mode),
	JS_CFUNC_DEF("set_angular_damp_mode", 1, &physical_bone3d_class_set_angular_damp_mode),
	JS_CFUNC_DEF("get_angular_damp_mode", 0, &physical_bone3d_class_get_angular_damp_mode),
	JS_CFUNC_DEF("set_linear_damp", 1, &physical_bone3d_class_set_linear_damp),
	JS_CFUNC_DEF("get_linear_damp", 0, &physical_bone3d_class_get_linear_damp),
	JS_CFUNC_DEF("set_angular_damp", 1, &physical_bone3d_class_set_angular_damp),
	JS_CFUNC_DEF("get_angular_damp", 0, &physical_bone3d_class_get_angular_damp),
	JS_CFUNC_DEF("set_linear_velocity", 1, &physical_bone3d_class_set_linear_velocity),
	JS_CFUNC_DEF("get_linear_velocity", 0, &physical_bone3d_class_get_linear_velocity),
	JS_CFUNC_DEF("set_angular_velocity", 1, &physical_bone3d_class_set_angular_velocity),
	JS_CFUNC_DEF("get_angular_velocity", 0, &physical_bone3d_class_get_angular_velocity),
	JS_CFUNC_DEF("set_use_custom_integrator", 1, &physical_bone3d_class_set_use_custom_integrator),
	JS_CFUNC_DEF("is_using_custom_integrator", 0, &physical_bone3d_class_is_using_custom_integrator),
	JS_CFUNC_DEF("set_can_sleep", 1, &physical_bone3d_class_set_can_sleep),
	JS_CFUNC_DEF("is_able_to_sleep", 0, &physical_bone3d_class_is_able_to_sleep),
};




static void define_physical_bone3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "joint_type"),
        JS_NewCFunction(ctx, physical_bone3d_class_get_joint_type, "get_joint_type", 0),
        JS_NewCFunction(ctx, physical_bone3d_class_set_joint_type, "set_joint_type", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "joint_offset"),
        JS_NewCFunction(ctx, physical_bone3d_class_get_joint_offset, "get_joint_offset", 0),
        JS_NewCFunction(ctx, physical_bone3d_class_set_joint_offset, "set_joint_offset", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "joint_rotation"),
        JS_NewCFunction(ctx, physical_bone3d_class_get_joint_rotation, "get_joint_rotation", 0),
        JS_NewCFunction(ctx, physical_bone3d_class_set_joint_rotation, "set_joint_rotation", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "body_offset"),
        JS_NewCFunction(ctx, physical_bone3d_class_get_body_offset, "get_body_offset", 0),
        JS_NewCFunction(ctx, physical_bone3d_class_set_body_offset, "set_body_offset", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "mass"),
        JS_NewCFunction(ctx, physical_bone3d_class_get_mass, "get_mass", 0),
        JS_NewCFunction(ctx, physical_bone3d_class_set_mass, "set_mass", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "friction"),
        JS_NewCFunction(ctx, physical_bone3d_class_get_friction, "get_friction", 0),
        JS_NewCFunction(ctx, physical_bone3d_class_set_friction, "set_friction", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "bounce"),
        JS_NewCFunction(ctx, physical_bone3d_class_get_bounce, "get_bounce", 0),
        JS_NewCFunction(ctx, physical_bone3d_class_set_bounce, "set_bounce", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "gravity_scale"),
        JS_NewCFunction(ctx, physical_bone3d_class_get_gravity_scale, "get_gravity_scale", 0),
        JS_NewCFunction(ctx, physical_bone3d_class_set_gravity_scale, "set_gravity_scale", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "custom_integrator"),
        JS_NewCFunction(ctx, physical_bone3d_class_is_using_custom_integrator, "is_using_custom_integrator", 0),
        JS_NewCFunction(ctx, physical_bone3d_class_set_use_custom_integrator, "set_use_custom_integrator", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "linear_damp_mode"),
        JS_NewCFunction(ctx, physical_bone3d_class_get_linear_damp_mode, "get_linear_damp_mode", 0),
        JS_NewCFunction(ctx, physical_bone3d_class_set_linear_damp_mode, "set_linear_damp_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "linear_damp"),
        JS_NewCFunction(ctx, physical_bone3d_class_get_linear_damp, "get_linear_damp", 0),
        JS_NewCFunction(ctx, physical_bone3d_class_set_linear_damp, "set_linear_damp", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "angular_damp_mode"),
        JS_NewCFunction(ctx, physical_bone3d_class_get_angular_damp_mode, "get_angular_damp_mode", 0),
        JS_NewCFunction(ctx, physical_bone3d_class_set_angular_damp_mode, "set_angular_damp_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "angular_damp"),
        JS_NewCFunction(ctx, physical_bone3d_class_get_angular_damp, "get_angular_damp", 0),
        JS_NewCFunction(ctx, physical_bone3d_class_set_angular_damp, "set_angular_damp", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "linear_velocity"),
        JS_NewCFunction(ctx, physical_bone3d_class_get_linear_velocity, "get_linear_velocity", 0),
        JS_NewCFunction(ctx, physical_bone3d_class_set_linear_velocity, "set_linear_velocity", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "angular_velocity"),
        JS_NewCFunction(ctx, physical_bone3d_class_get_angular_velocity, "get_angular_velocity", 0),
        JS_NewCFunction(ctx, physical_bone3d_class_set_angular_velocity, "set_angular_velocity", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "can_sleep"),
        JS_NewCFunction(ctx, physical_bone3d_class_is_able_to_sleep, "is_able_to_sleep", 0),
        JS_NewCFunction(ctx, physical_bone3d_class_set_can_sleep, "set_can_sleep", 1),
        JS_PROP_GETSET
    );
}

static void define_physical_bone3d_enum(JSContext *ctx, JSValue proto) {
	JSValue DampMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, DampMode_obj, "DAMP_MODE_COMBINE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, DampMode_obj, "DAMP_MODE_REPLACE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, proto, "DampMode", DampMode_obj);
	JSValue JointType_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, JointType_obj, "JOINT_TYPE_NONE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, JointType_obj, "JOINT_TYPE_PIN", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, JointType_obj, "JOINT_TYPE_CONE", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, JointType_obj, "JOINT_TYPE_HINGE", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, JointType_obj, "JOINT_TYPE_SLIDER", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, JointType_obj, "JOINT_TYPE_6DOF", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, proto, "JointType", JointType_obj);
}

static int js_physical_bone3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["PhysicalBone3D"] = class_id;
	classes_by_id[class_id] = "PhysicalBone3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &physical_bone3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["PhysicsBody3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_physical_bone3d_property(ctx, proto);
	define_physical_bone3d_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, physical_bone3d_class_proto_funcs, _countof(physical_bone3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, physical_bone3d_class_constructor, "PhysicalBone3D", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "PhysicalBone3D", ctor);

	return 0;
}

JSModuleDef *_js_init_physical_bone3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/physics_body3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_physical_bone3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "PhysicalBone3D");
	return m;
}

JSModuleDef *js_init_physical_bone3d_module(JSContext *ctx) {
	return _js_init_physical_bone3d_module(ctx, "@godot/classes/physical_bone3d");
}

void __register_physical_bone3d() {
	js_init_physical_bone3d_module(js_context());
}

void register_physical_bone3d() {
	__register_physical_bone3d();
}