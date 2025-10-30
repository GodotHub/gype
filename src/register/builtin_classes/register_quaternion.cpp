#include "register/builtin_classes/register_builtin_classes.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/quickjs_helper.hpp"
#include "utils/str_helper.hpp"
#include "utils/variant_helper.hpp"
#include <quickjs.h>
#include <godot_cpp/variant/vector3.hpp>

using namespace godot;

static void quaternion_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Quaternion"];
	Quaternion *opaque_ptr = static_cast<Quaternion *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memfree(opaque_ptr);
	}
}

static JSClassDef quaternion_class_def = {
	"Quaternion",
	.finalizer = quaternion_class_finalizer
};

static JSValue quaternion_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["Quaternion"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);
	if (JS_IsException(obj)) {
		return obj;
	}

	Quaternion *instance = nullptr;	if (argc == 0) {
		instance = memnew(Quaternion());
	}
	if (argc == 1&&VariantAdapter(argv[0]).get_type() == Variant::Type::QUATERNION) {
		Quaternion v0 = VariantAdapter(argv[0]).get<Quaternion>();
		instance = memnew(Quaternion(v0));
	}
	if (argc == 1&&VariantAdapter(argv[0]).get_type() == Variant::Type::BASIS) {
		Basis v0 = VariantAdapter(argv[0]).get<Basis>();
		instance = memnew(Quaternion(v0));
	}
	if (argc == 2&&VariantAdapter(argv[0]).get_type() == Variant::Type::VECTOR3&&(VariantAdapter(argv[1]).get_type() == Variant::Type::FLOAT || VariantAdapter(argv[1]).get_type() == Variant::Type::INT)) {
		Vector3 v0 = VariantAdapter(argv[0]).get<Vector3>();
		float v1 = VariantAdapter(argv[1]).get<float>();
		instance = memnew(Quaternion(v0, v1));
	}
	if (argc == 2&&VariantAdapter(argv[0]).get_type() == Variant::Type::VECTOR3&&VariantAdapter(argv[1]).get_type() == Variant::Type::VECTOR3) {
		Vector3 v0 = VariantAdapter(argv[0]).get<Vector3>();
		Vector3 v1 = VariantAdapter(argv[1]).get<Vector3>();
		instance = memnew(Quaternion(v0, v1));
	}
	if (argc == 4&&(VariantAdapter(argv[0]).get_type() == Variant::Type::FLOAT || VariantAdapter(argv[0]).get_type() == Variant::Type::INT)&&(VariantAdapter(argv[1]).get_type() == Variant::Type::FLOAT || VariantAdapter(argv[1]).get_type() == Variant::Type::INT)&&(VariantAdapter(argv[2]).get_type() == Variant::Type::FLOAT || VariantAdapter(argv[2]).get_type() == Variant::Type::INT)&&(VariantAdapter(argv[3]).get_type() == Variant::Type::FLOAT || VariantAdapter(argv[3]).get_type() == Variant::Type::INT)) {
		float v0 = VariantAdapter(argv[0]).get<float>();
		float v1 = VariantAdapter(argv[1]).get<float>();
		float v2 = VariantAdapter(argv[2]).get<float>();
		float v3 = VariantAdapter(argv[3]).get<float>();
		instance = memnew(Quaternion(v0, v1, v2, v3));
	}

	if (!instance) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, instance);
	return obj;
}
static JSValue quaternion_class_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Quaternion::length, ctx, this_val, argc, argv);
}
static JSValue quaternion_class_length_squared(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Quaternion::length_squared, ctx, this_val, argc, argv);
}
static JSValue quaternion_class_normalized(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Quaternion::normalized, ctx, this_val, argc, argv);
}
static JSValue quaternion_class_is_normalized(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Quaternion::is_normalized, ctx, this_val, argc, argv);
}
static JSValue quaternion_class_is_equal_approx(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Quaternion::is_equal_approx, ctx, this_val, argc, argv);
}
static JSValue quaternion_class_is_finite(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Quaternion::is_finite, ctx, this_val, argc, argv);
}
static JSValue quaternion_class_inverse(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Quaternion::inverse, ctx, this_val, argc, argv);
}
static JSValue quaternion_class_log(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Quaternion::log, ctx, this_val, argc, argv);
}
static JSValue quaternion_class_exp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Quaternion::exp, ctx, this_val, argc, argv);
}
static JSValue quaternion_class_angle_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Quaternion::angle_to, ctx, this_val, argc, argv);
}
static JSValue quaternion_class_dot(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Quaternion::dot, ctx, this_val, argc, argv);
}
static JSValue quaternion_class_slerp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Quaternion::slerp, ctx, this_val, argc, argv);
}
static JSValue quaternion_class_slerpni(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Quaternion::slerpni, ctx, this_val, argc, argv);
}
static JSValue quaternion_class_spherical_cubic_interpolate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Quaternion::spherical_cubic_interpolate, ctx, this_val, argc, argv);
}
static JSValue quaternion_class_spherical_cubic_interpolate_in_time(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Quaternion::spherical_cubic_interpolate_in_time, ctx, this_val, argc, argv);
}
static JSValue quaternion_class_get_euler(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Quaternion::get_euler, ctx, this_val, argc, argv);
}
static JSValue quaternion_class_from_euler(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Quaternion::from_euler, ctx, this_val, argc, argv);
}
static JSValue quaternion_class_get_axis(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Quaternion::get_axis, ctx, this_val, argc, argv);
}
static JSValue quaternion_class_get_angle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Quaternion::get_angle, ctx, this_val, argc, argv);
}

static JSValue quaternion_class_get_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Quaternion &val = *reinterpret_cast<Quaternion *>(JS_GetOpaque(this_val, classes["Quaternion"]));
	return VariantAdapter(val.x);
}
static JSValue quaternion_class_set_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Quaternion &val = *reinterpret_cast<Quaternion *>(JS_GetOpaque(this_val, classes["Quaternion"]));
	val.x = VariantAdapter(*argv).get<float>();
	return JS_UNDEFINED;
}
static JSValue quaternion_class_get_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Quaternion &val = *reinterpret_cast<Quaternion *>(JS_GetOpaque(this_val, classes["Quaternion"]));
	return VariantAdapter(val.y);
}
static JSValue quaternion_class_set_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Quaternion &val = *reinterpret_cast<Quaternion *>(JS_GetOpaque(this_val, classes["Quaternion"]));
	val.y = VariantAdapter(*argv).get<float>();
	return JS_UNDEFINED;
}
static JSValue quaternion_class_get_z(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Quaternion &val = *reinterpret_cast<Quaternion *>(JS_GetOpaque(this_val, classes["Quaternion"]));
	return VariantAdapter(val.z);
}
static JSValue quaternion_class_set_z(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Quaternion &val = *reinterpret_cast<Quaternion *>(JS_GetOpaque(this_val, classes["Quaternion"]));
	val.z = VariantAdapter(*argv).get<float>();
	return JS_UNDEFINED;
}
static JSValue quaternion_class_get_w(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Quaternion &val = *reinterpret_cast<Quaternion *>(JS_GetOpaque(this_val, classes["Quaternion"]));
	return VariantAdapter(val.w);
}
static JSValue quaternion_class_set_w(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Quaternion &val = *reinterpret_cast<Quaternion *>(JS_GetOpaque(this_val, classes["Quaternion"]));
	val.w = VariantAdapter(*argv).get<float>();
	return JS_UNDEFINED;
}

static const JSCFunctionListEntry quaternion_class_proto_funcs[] = {
	JS_CFUNC_DEF("length", 0, &quaternion_class_length),
	JS_CFUNC_DEF("length_squared", 0, &quaternion_class_length_squared),
	JS_CFUNC_DEF("normalized", 0, &quaternion_class_normalized),
	JS_CFUNC_DEF("is_normalized", 0, &quaternion_class_is_normalized),
	JS_CFUNC_DEF("is_equal_approx", 1, &quaternion_class_is_equal_approx),
	JS_CFUNC_DEF("is_finite", 0, &quaternion_class_is_finite),
	JS_CFUNC_DEF("inverse", 0, &quaternion_class_inverse),
	JS_CFUNC_DEF("log", 0, &quaternion_class_log),
	JS_CFUNC_DEF("exp", 0, &quaternion_class_exp),
	JS_CFUNC_DEF("angle_to", 1, &quaternion_class_angle_to),
	JS_CFUNC_DEF("dot", 1, &quaternion_class_dot),
	JS_CFUNC_DEF("slerp", 2, &quaternion_class_slerp),
	JS_CFUNC_DEF("slerpni", 2, &quaternion_class_slerpni),
	JS_CFUNC_DEF("spherical_cubic_interpolate", 4, &quaternion_class_spherical_cubic_interpolate),
	JS_CFUNC_DEF("spherical_cubic_interpolate_in_time", 7, &quaternion_class_spherical_cubic_interpolate_in_time),
	JS_CFUNC_DEF("get_euler", 1, &quaternion_class_get_euler),
	JS_CFUNC_DEF("from_euler", 1, &quaternion_class_from_euler),
	JS_CFUNC_DEF("get_axis", 0, &quaternion_class_get_axis),
	JS_CFUNC_DEF("get_angle", 0, &quaternion_class_get_angle),
};

void define_quaternion_property(JSContext *ctx, JSValue obj) {
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "x"),
			JS_NewCFunction(ctx, quaternion_class_get_x, "get_x", 0),
			JS_NewCFunction(ctx, quaternion_class_set_x, "set_x", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "y"),
			JS_NewCFunction(ctx, quaternion_class_get_y, "get_y", 0),
			JS_NewCFunction(ctx, quaternion_class_set_y, "set_y", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "z"),
			JS_NewCFunction(ctx, quaternion_class_get_z, "get_z", 0),
			JS_NewCFunction(ctx, quaternion_class_set_z, "set_z", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "w"),
			JS_NewCFunction(ctx, quaternion_class_get_w, "get_w", 0),
			JS_NewCFunction(ctx, quaternion_class_set_w, "set_w", 1),
			JS_PROP_GETSET);
}

static int js_quaternion_class_init(JSContext *ctx) {
	classes["Quaternion"] = JS_NewClassID(&classes["Quaternion"]);
	JSClassID class_id = classes["Quaternion"];

	JS_NewClass(JS_GetRuntime(ctx), class_id, &quaternion_class_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, class_id, proto);	define_quaternion_property(ctx, proto);	JS_SetPropertyFunctionList(ctx, proto, quaternion_class_proto_funcs, _countof(quaternion_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, quaternion_class_constructor, "Quaternion", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);

	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "Quaternion", ctor);

	return 0;
}

void js_init_quaternion_module(JSContext *ctx) {
	js_quaternion_class_init(ctx);
}

void register_quaternion() {
	js_init_quaternion_module(js_context());
}