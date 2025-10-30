#include "register/builtin_classes/register_builtin_classes.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/quickjs_helper.hpp"
#include "utils/str_helper.hpp"
#include "utils/variant_helper.hpp"
#include <quickjs.h>


using namespace godot;

static void vector2_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Vector2"];
	Vector2 *opaque_ptr = static_cast<Vector2 *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memfree(opaque_ptr);
	}
}

static JSClassDef vector2_class_def = {
	"Vector2",
	.finalizer = vector2_class_finalizer
};

static JSValue vector2_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["Vector2"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);
	if (JS_IsException(obj)) {
		return obj;
	}

	Vector2 *instance = nullptr;	if (argc == 0) {
		instance = memnew(Vector2());
	}
	if (argc == 1&&VariantAdapter(argv[0]).get_type() == Variant::Type::VECTOR2) {
		Vector2 v0 = VariantAdapter(argv[0]).get<Vector2>();
		instance = memnew(Vector2(v0));
	}
	if (argc == 1&&VariantAdapter(argv[0]).get_type() == Variant::Type::VECTOR2I) {
		Vector2i v0 = VariantAdapter(argv[0]).get<Vector2i>();
		instance = memnew(Vector2(v0));
	}
	if (argc == 2&&(VariantAdapter(argv[0]).get_type() == Variant::Type::FLOAT || VariantAdapter(argv[0]).get_type() == Variant::Type::INT)&&(VariantAdapter(argv[1]).get_type() == Variant::Type::FLOAT || VariantAdapter(argv[1]).get_type() == Variant::Type::INT)) {
		float v0 = VariantAdapter(argv[0]).get<float>();
		float v1 = VariantAdapter(argv[1]).get<float>();
		instance = memnew(Vector2(v0, v1));
	}

	if (!instance) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, instance);
	return obj;
}
static JSValue vector2_class_angle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2::angle, ctx, this_val, argc, argv);
}
static JSValue vector2_class_angle_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2::angle_to, ctx, this_val, argc, argv);
}
static JSValue vector2_class_angle_to_point(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2::angle_to_point, ctx, this_val, argc, argv);
}
static JSValue vector2_class_direction_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2::direction_to, ctx, this_val, argc, argv);
}
static JSValue vector2_class_distance_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2::distance_to, ctx, this_val, argc, argv);
}
static JSValue vector2_class_distance_squared_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2::distance_squared_to, ctx, this_val, argc, argv);
}
static JSValue vector2_class_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2::length, ctx, this_val, argc, argv);
}
static JSValue vector2_class_length_squared(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2::length_squared, ctx, this_val, argc, argv);
}
static JSValue vector2_class_limit_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2::limit_length, ctx, this_val, argc, argv);
}
static JSValue vector2_class_normalized(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2::normalized, ctx, this_val, argc, argv);
}
static JSValue vector2_class_is_normalized(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2::is_normalized, ctx, this_val, argc, argv);
}
static JSValue vector2_class_is_equal_approx(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2::is_equal_approx, ctx, this_val, argc, argv);
}
static JSValue vector2_class_is_zero_approx(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2::is_zero_approx, ctx, this_val, argc, argv);
}
static JSValue vector2_class_is_finite(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2::is_finite, ctx, this_val, argc, argv);
}
static JSValue vector2_class_posmod(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2::posmod, ctx, this_val, argc, argv);
}
static JSValue vector2_class_posmodv(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2::posmodv, ctx, this_val, argc, argv);
}
static JSValue vector2_class_project(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2::project, ctx, this_val, argc, argv);
}
static JSValue vector2_class_lerp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2::lerp, ctx, this_val, argc, argv);
}
static JSValue vector2_class_slerp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2::slerp, ctx, this_val, argc, argv);
}
static JSValue vector2_class_cubic_interpolate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2::cubic_interpolate, ctx, this_val, argc, argv);
}
static JSValue vector2_class_cubic_interpolate_in_time(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2::cubic_interpolate_in_time, ctx, this_val, argc, argv);
}
static JSValue vector2_class_bezier_interpolate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2::bezier_interpolate, ctx, this_val, argc, argv);
}
static JSValue vector2_class_bezier_derivative(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2::bezier_derivative, ctx, this_val, argc, argv);
}
static JSValue vector2_class_max_axis_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2::max_axis_index, ctx, this_val, argc, argv);
}
static JSValue vector2_class_min_axis_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2::min_axis_index, ctx, this_val, argc, argv);
}
static JSValue vector2_class_move_toward(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2::move_toward, ctx, this_val, argc, argv);
}
static JSValue vector2_class_rotated(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2::rotated, ctx, this_val, argc, argv);
}
static JSValue vector2_class_orthogonal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2::orthogonal, ctx, this_val, argc, argv);
}
static JSValue vector2_class_floor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2::floor, ctx, this_val, argc, argv);
}
static JSValue vector2_class_ceil(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2::ceil, ctx, this_val, argc, argv);
}
static JSValue vector2_class_round(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2::round, ctx, this_val, argc, argv);
}
static JSValue vector2_class_aspect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2::aspect, ctx, this_val, argc, argv);
}
static JSValue vector2_class_dot(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2::dot, ctx, this_val, argc, argv);
}
static JSValue vector2_class_slide(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2::slide, ctx, this_val, argc, argv);
}
static JSValue vector2_class_bounce(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2::bounce, ctx, this_val, argc, argv);
}
static JSValue vector2_class_reflect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2::reflect, ctx, this_val, argc, argv);
}
static JSValue vector2_class_cross(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2::cross, ctx, this_val, argc, argv);
}
static JSValue vector2_class_abs(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2::abs, ctx, this_val, argc, argv);
}
static JSValue vector2_class_sign(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2::sign, ctx, this_val, argc, argv);
}
static JSValue vector2_class_clamp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2::clamp, ctx, this_val, argc, argv);
}
static JSValue vector2_class_clampf(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2::clampf, ctx, this_val, argc, argv);
}
static JSValue vector2_class_snapped(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2::snapped, ctx, this_val, argc, argv);
}
static JSValue vector2_class_snappedf(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2::snappedf, ctx, this_val, argc, argv);
}
static JSValue vector2_class_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2::min, ctx, this_val, argc, argv);
}
static JSValue vector2_class_minf(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2::minf, ctx, this_val, argc, argv);
}
static JSValue vector2_class_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2::max, ctx, this_val, argc, argv);
}
static JSValue vector2_class_maxf(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2::maxf, ctx, this_val, argc, argv);
}
static JSValue vector2_class_from_angle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Vector2::from_angle, ctx, this_val, argc, argv);
}

static JSValue vector2_class_get_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Vector2 &val = *reinterpret_cast<Vector2 *>(JS_GetOpaque(this_val, classes["Vector2"]));
	return VariantAdapter(val.x);
}
static JSValue vector2_class_set_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Vector2 &val = *reinterpret_cast<Vector2 *>(JS_GetOpaque(this_val, classes["Vector2"]));
	val.x = VariantAdapter(*argv).get<float>();
	return JS_UNDEFINED;
}
static JSValue vector2_class_get_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Vector2 &val = *reinterpret_cast<Vector2 *>(JS_GetOpaque(this_val, classes["Vector2"]));
	return VariantAdapter(val.y);
}
static JSValue vector2_class_set_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Vector2 &val = *reinterpret_cast<Vector2 *>(JS_GetOpaque(this_val, classes["Vector2"]));
	val.y = VariantAdapter(*argv).get<float>();
	return JS_UNDEFINED;
}

static const JSCFunctionListEntry vector2_class_proto_funcs[] = {
	JS_CFUNC_DEF("angle", 0, &vector2_class_angle),
	JS_CFUNC_DEF("angle_to", 1, &vector2_class_angle_to),
	JS_CFUNC_DEF("angle_to_point", 1, &vector2_class_angle_to_point),
	JS_CFUNC_DEF("direction_to", 1, &vector2_class_direction_to),
	JS_CFUNC_DEF("distance_to", 1, &vector2_class_distance_to),
	JS_CFUNC_DEF("distance_squared_to", 1, &vector2_class_distance_squared_to),
	JS_CFUNC_DEF("length", 0, &vector2_class_length),
	JS_CFUNC_DEF("length_squared", 0, &vector2_class_length_squared),
	JS_CFUNC_DEF("limit_length", 1, &vector2_class_limit_length),
	JS_CFUNC_DEF("normalized", 0, &vector2_class_normalized),
	JS_CFUNC_DEF("is_normalized", 0, &vector2_class_is_normalized),
	JS_CFUNC_DEF("is_equal_approx", 1, &vector2_class_is_equal_approx),
	JS_CFUNC_DEF("is_zero_approx", 0, &vector2_class_is_zero_approx),
	JS_CFUNC_DEF("is_finite", 0, &vector2_class_is_finite),
	JS_CFUNC_DEF("posmod", 1, &vector2_class_posmod),
	JS_CFUNC_DEF("posmodv", 1, &vector2_class_posmodv),
	JS_CFUNC_DEF("project", 1, &vector2_class_project),
	JS_CFUNC_DEF("lerp", 2, &vector2_class_lerp),
	JS_CFUNC_DEF("slerp", 2, &vector2_class_slerp),
	JS_CFUNC_DEF("cubic_interpolate", 4, &vector2_class_cubic_interpolate),
	JS_CFUNC_DEF("cubic_interpolate_in_time", 7, &vector2_class_cubic_interpolate_in_time),
	JS_CFUNC_DEF("bezier_interpolate", 4, &vector2_class_bezier_interpolate),
	JS_CFUNC_DEF("bezier_derivative", 4, &vector2_class_bezier_derivative),
	JS_CFUNC_DEF("max_axis_index", 0, &vector2_class_max_axis_index),
	JS_CFUNC_DEF("min_axis_index", 0, &vector2_class_min_axis_index),
	JS_CFUNC_DEF("move_toward", 2, &vector2_class_move_toward),
	JS_CFUNC_DEF("rotated", 1, &vector2_class_rotated),
	JS_CFUNC_DEF("orthogonal", 0, &vector2_class_orthogonal),
	JS_CFUNC_DEF("floor", 0, &vector2_class_floor),
	JS_CFUNC_DEF("ceil", 0, &vector2_class_ceil),
	JS_CFUNC_DEF("round", 0, &vector2_class_round),
	JS_CFUNC_DEF("aspect", 0, &vector2_class_aspect),
	JS_CFUNC_DEF("dot", 1, &vector2_class_dot),
	JS_CFUNC_DEF("slide", 1, &vector2_class_slide),
	JS_CFUNC_DEF("bounce", 1, &vector2_class_bounce),
	JS_CFUNC_DEF("reflect", 1, &vector2_class_reflect),
	JS_CFUNC_DEF("cross", 1, &vector2_class_cross),
	JS_CFUNC_DEF("abs", 0, &vector2_class_abs),
	JS_CFUNC_DEF("sign", 0, &vector2_class_sign),
	JS_CFUNC_DEF("clamp", 2, &vector2_class_clamp),
	JS_CFUNC_DEF("clampf", 2, &vector2_class_clampf),
	JS_CFUNC_DEF("snapped", 1, &vector2_class_snapped),
	JS_CFUNC_DEF("snappedf", 1, &vector2_class_snappedf),
	JS_CFUNC_DEF("min", 1, &vector2_class_min),
	JS_CFUNC_DEF("minf", 1, &vector2_class_minf),
	JS_CFUNC_DEF("max", 1, &vector2_class_max),
	JS_CFUNC_DEF("maxf", 1, &vector2_class_maxf),
	JS_CFUNC_DEF("from_angle", 1, &vector2_class_from_angle),
};

void define_vector2_property(JSContext *ctx, JSValue obj) {
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "x"),
			JS_NewCFunction(ctx, vector2_class_get_x, "get_x", 0),
			JS_NewCFunction(ctx, vector2_class_set_x, "set_x", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "y"),
			JS_NewCFunction(ctx, vector2_class_get_y, "get_y", 0),
			JS_NewCFunction(ctx, vector2_class_set_y, "set_y", 1),
			JS_PROP_GETSET);
}

static int js_vector2_class_init(JSContext *ctx) {
	classes["Vector2"] = JS_NewClassID(&classes["Vector2"]);
	JSClassID class_id = classes["Vector2"];

	JS_NewClass(JS_GetRuntime(ctx), class_id, &vector2_class_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, class_id, proto);	define_vector2_property(ctx, proto);	JS_SetPropertyFunctionList(ctx, proto, vector2_class_proto_funcs, _countof(vector2_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, vector2_class_constructor, "Vector2", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);

	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "Vector2", ctor);

	return 0;
}

void js_init_vector2_module(JSContext *ctx) {
	js_vector2_class_init(ctx);
}

void register_vector2() {
	js_init_vector2_module(js_context());
}