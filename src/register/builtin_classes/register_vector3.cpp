#include "register/builtin_classes/register_builtin_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/quickjs_helper.hpp"
#include "utils/str_helper.hpp"
#include "utils/variant_helper.hpp"
#include <quickjs.h>
#include <godot_cpp/variant/basis.hpp>
#include <godot_cpp/variant/vector2.hpp>


using namespace godot;

static void vector3_class_finalizer(JSRuntime *rt, JSValue val) {
	// 处于栈内存的变量不需要释放,除了对象
}

static JSClassDef vector3_class_def = {
	"Vector3",
	.finalizer = vector3_class_finalizer
};

static JSValue vector3_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["Vector3"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);

	if (JS_IsException(obj)) {
		return obj;
	}
	
	Vector3 *instance = nullptr;
	if (argc == 0) {
		instance = memnew(Vector3());
	}
	if (argc == 1&&(VariantAdapter::can_cast(argv[0],Variant::Type::VECTOR3))) {
		Vector3 v0 = VariantAdapter(argv[0]).get();
		instance = memnew(Vector3(v0));
	}
	if (argc == 1&&(VariantAdapter::can_cast(argv[0],Variant::Type::VECTOR3I))) {
		Vector3i v0 = VariantAdapter(argv[0]).get();
		instance = memnew(Vector3(v0));
	}
	if (argc == 3&&(VariantAdapter::can_cast(argv[0],Variant::Type::FLOAT))&&(VariantAdapter::can_cast(argv[1],Variant::Type::FLOAT))&&(VariantAdapter::can_cast(argv[2],Variant::Type::FLOAT))) {
		double v0 = VariantAdapter(argv[0]).get();
		double v1 = VariantAdapter(argv[1]).get();
		double v2 = VariantAdapter(argv[2]).get();
		instance = memnew(Vector3(v0, v1, v2));
	}
	VariantAdapter *adapter = memnew(VariantAdapter(*instance, true));

	if (!instance || !adapter) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, adapter);
	return obj;
}
static JSValue vector3_class_min_axis_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3::min_axis_index, ctx, this_val, argc, argv);
}
static JSValue vector3_class_max_axis_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3::max_axis_index, ctx, this_val, argc, argv);
}
static JSValue vector3_class_angle_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3::angle_to, ctx, this_val, argc, argv);
}
static JSValue vector3_class_signed_angle_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3::signed_angle_to, ctx, this_val, argc, argv);
}
static JSValue vector3_class_direction_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3::direction_to, ctx, this_val, argc, argv);
}
static JSValue vector3_class_distance_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3::distance_to, ctx, this_val, argc, argv);
}
static JSValue vector3_class_distance_squared_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3::distance_squared_to, ctx, this_val, argc, argv);
}
static JSValue vector3_class_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3::length, ctx, this_val, argc, argv);
}
static JSValue vector3_class_length_squared(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3::length_squared, ctx, this_val, argc, argv);
}
static JSValue vector3_class_limit_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3::limit_length, ctx, this_val, argc, argv);
}
static JSValue vector3_class_normalized(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3::normalized, ctx, this_val, argc, argv);
}
static JSValue vector3_class_is_normalized(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3::is_normalized, ctx, this_val, argc, argv);
}
static JSValue vector3_class_is_equal_approx(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3::is_equal_approx, ctx, this_val, argc, argv);
}
static JSValue vector3_class_is_zero_approx(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3::is_zero_approx, ctx, this_val, argc, argv);
}
static JSValue vector3_class_is_finite(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3::is_finite, ctx, this_val, argc, argv);
}
static JSValue vector3_class_inverse(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3::inverse, ctx, this_val, argc, argv);
}
static JSValue vector3_class_clamp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3::clamp, ctx, this_val, argc, argv);
}
static JSValue vector3_class_clampf(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3::clampf, ctx, this_val, argc, argv);
}
static JSValue vector3_class_snapped(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3::snapped, ctx, this_val, argc, argv);
}
static JSValue vector3_class_snappedf(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3::snappedf, ctx, this_val, argc, argv);
}
static JSValue vector3_class_rotated(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3::rotated, ctx, this_val, argc, argv);
}
static JSValue vector3_class_lerp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3::lerp, ctx, this_val, argc, argv);
}
static JSValue vector3_class_slerp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3::slerp, ctx, this_val, argc, argv);
}
static JSValue vector3_class_cubic_interpolate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3::cubic_interpolate, ctx, this_val, argc, argv);
}
static JSValue vector3_class_cubic_interpolate_in_time(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3::cubic_interpolate_in_time, ctx, this_val, argc, argv);
}
static JSValue vector3_class_bezier_interpolate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3::bezier_interpolate, ctx, this_val, argc, argv);
}
static JSValue vector3_class_bezier_derivative(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3::bezier_derivative, ctx, this_val, argc, argv);
}
static JSValue vector3_class_move_toward(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3::move_toward, ctx, this_val, argc, argv);
}
static JSValue vector3_class_dot(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3::dot, ctx, this_val, argc, argv);
}
static JSValue vector3_class_cross(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3::cross, ctx, this_val, argc, argv);
}
static JSValue vector3_class_outer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3::outer, ctx, this_val, argc, argv);
}
static JSValue vector3_class_abs(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3::abs, ctx, this_val, argc, argv);
}
static JSValue vector3_class_floor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3::floor, ctx, this_val, argc, argv);
}
static JSValue vector3_class_ceil(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3::ceil, ctx, this_val, argc, argv);
}
static JSValue vector3_class_round(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3::round, ctx, this_val, argc, argv);
}
static JSValue vector3_class_posmod(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3::posmod, ctx, this_val, argc, argv);
}
static JSValue vector3_class_posmodv(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3::posmodv, ctx, this_val, argc, argv);
}
static JSValue vector3_class_project(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3::project, ctx, this_val, argc, argv);
}
static JSValue vector3_class_slide(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3::slide, ctx, this_val, argc, argv);
}
static JSValue vector3_class_bounce(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3::bounce, ctx, this_val, argc, argv);
}
static JSValue vector3_class_reflect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3::reflect, ctx, this_val, argc, argv);
}
static JSValue vector3_class_sign(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3::sign, ctx, this_val, argc, argv);
}
static JSValue vector3_class_octahedron_encode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3::octahedron_encode, ctx, this_val, argc, argv);
}
static JSValue vector3_class_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3::min, ctx, this_val, argc, argv);
}
static JSValue vector3_class_minf(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3::minf, ctx, this_val, argc, argv);
}
static JSValue vector3_class_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3::max, ctx, this_val, argc, argv);
}
static JSValue vector3_class_maxf(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3::maxf, ctx, this_val, argc, argv);
}
static JSValue vector3_class_octahedron_decode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Vector3::octahedron_decode, ctx, this_val, argc, argv);
}

static JSValue vector3_class_get_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Vector3 val = reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Vector3"]))->get();
	return VariantAdapter(val.x);
}
static JSValue vector3_class_set_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Vector3 val = reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Vector3"]))->get();
	val.x = VariantAdapter(*argv).get();
	return JS_UNDEFINED;
}
static JSValue vector3_class_get_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Vector3 val = reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Vector3"]))->get();
	return VariantAdapter(val.y);
}
static JSValue vector3_class_set_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Vector3 val = reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Vector3"]))->get();
	val.y = VariantAdapter(*argv).get();
	return JS_UNDEFINED;
}
static JSValue vector3_class_get_z(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Vector3 val = reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Vector3"]))->get();
	return VariantAdapter(val.z);
}
static JSValue vector3_class_set_z(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Vector3 val = reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Vector3"]))->get();
	val.z = VariantAdapter(*argv).get();
	return JS_UNDEFINED;
}

static const JSCFunctionListEntry vector3_class_proto_funcs[] = {
	JS_CFUNC_DEF("min_axis_index", 0, &vector3_class_min_axis_index),
	JS_CFUNC_DEF("max_axis_index", 0, &vector3_class_max_axis_index),
	JS_CFUNC_DEF("angle_to", 1, &vector3_class_angle_to),
	JS_CFUNC_DEF("signed_angle_to", 2, &vector3_class_signed_angle_to),
	JS_CFUNC_DEF("direction_to", 1, &vector3_class_direction_to),
	JS_CFUNC_DEF("distance_to", 1, &vector3_class_distance_to),
	JS_CFUNC_DEF("distance_squared_to", 1, &vector3_class_distance_squared_to),
	JS_CFUNC_DEF("length", 0, &vector3_class_length),
	JS_CFUNC_DEF("length_squared", 0, &vector3_class_length_squared),
	JS_CFUNC_DEF("limit_length", 1, &vector3_class_limit_length),
	JS_CFUNC_DEF("normalized", 0, &vector3_class_normalized),
	JS_CFUNC_DEF("is_normalized", 0, &vector3_class_is_normalized),
	JS_CFUNC_DEF("is_equal_approx", 1, &vector3_class_is_equal_approx),
	JS_CFUNC_DEF("is_zero_approx", 0, &vector3_class_is_zero_approx),
	JS_CFUNC_DEF("is_finite", 0, &vector3_class_is_finite),
	JS_CFUNC_DEF("inverse", 0, &vector3_class_inverse),
	JS_CFUNC_DEF("clamp", 2, &vector3_class_clamp),
	JS_CFUNC_DEF("clampf", 2, &vector3_class_clampf),
	JS_CFUNC_DEF("snapped", 1, &vector3_class_snapped),
	JS_CFUNC_DEF("snappedf", 1, &vector3_class_snappedf),
	JS_CFUNC_DEF("rotated", 2, &vector3_class_rotated),
	JS_CFUNC_DEF("lerp", 2, &vector3_class_lerp),
	JS_CFUNC_DEF("slerp", 2, &vector3_class_slerp),
	JS_CFUNC_DEF("cubic_interpolate", 4, &vector3_class_cubic_interpolate),
	JS_CFUNC_DEF("cubic_interpolate_in_time", 7, &vector3_class_cubic_interpolate_in_time),
	JS_CFUNC_DEF("bezier_interpolate", 4, &vector3_class_bezier_interpolate),
	JS_CFUNC_DEF("bezier_derivative", 4, &vector3_class_bezier_derivative),
	JS_CFUNC_DEF("move_toward", 2, &vector3_class_move_toward),
	JS_CFUNC_DEF("dot", 1, &vector3_class_dot),
	JS_CFUNC_DEF("cross", 1, &vector3_class_cross),
	JS_CFUNC_DEF("outer", 1, &vector3_class_outer),
	JS_CFUNC_DEF("abs", 0, &vector3_class_abs),
	JS_CFUNC_DEF("floor", 0, &vector3_class_floor),
	JS_CFUNC_DEF("ceil", 0, &vector3_class_ceil),
	JS_CFUNC_DEF("round", 0, &vector3_class_round),
	JS_CFUNC_DEF("posmod", 1, &vector3_class_posmod),
	JS_CFUNC_DEF("posmodv", 1, &vector3_class_posmodv),
	JS_CFUNC_DEF("project", 1, &vector3_class_project),
	JS_CFUNC_DEF("slide", 1, &vector3_class_slide),
	JS_CFUNC_DEF("bounce", 1, &vector3_class_bounce),
	JS_CFUNC_DEF("reflect", 1, &vector3_class_reflect),
	JS_CFUNC_DEF("sign", 0, &vector3_class_sign),
	JS_CFUNC_DEF("octahedron_encode", 0, &vector3_class_octahedron_encode),
	JS_CFUNC_DEF("min", 1, &vector3_class_min),
	JS_CFUNC_DEF("minf", 1, &vector3_class_minf),
	JS_CFUNC_DEF("max", 1, &vector3_class_max),
	JS_CFUNC_DEF("maxf", 1, &vector3_class_maxf),
	JS_CFUNC_DEF("octahedron_decode", 1, &vector3_class_octahedron_decode),
};

void define_vector3_property(JSContext *ctx, JSValue obj) {
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "x"),
			JS_NewCFunction(ctx, vector3_class_get_x, "get_x", 0),
			JS_NewCFunction(ctx, vector3_class_set_x, "set_x", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "y"),
			JS_NewCFunction(ctx, vector3_class_get_y, "get_y", 0),
			JS_NewCFunction(ctx, vector3_class_set_y, "set_y", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "z"),
			JS_NewCFunction(ctx, vector3_class_get_z, "get_z", 0),
			JS_NewCFunction(ctx, vector3_class_set_z, "set_z", 1),
			JS_PROP_GETSET);
}

static int js_vector3_class_init(JSContext *ctx) {
	JSClassID class_id = 0;
	classes["Vector3"] = JS_NewClassID(&class_id);
	classes_by_id[class_id] = "Vector3";

	JS_NewClass(JS_GetRuntime(ctx), class_id, &vector3_class_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, class_id, proto);	define_vector3_property(ctx, proto);	JS_SetPropertyFunctionList(ctx, proto, vector3_class_proto_funcs, _countof(vector3_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, vector3_class_constructor, "Vector3", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);

	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "Vector3", ctor);

	return 0;
}

void js_init_vector3_module(JSContext *ctx) {
	js_vector3_class_init(ctx);
}

void register_vector3() {
	js_init_vector3_module(js_context());
}

// ------------------Vector3Proxy------------------
static void vector3_proxy_finalizer(JSRuntime *rt, JSValue val) {
	void *proxy = JS_GetOpaque(val, classes["Vector3Proxy"]);
	if (proxy) {
		memfree(static_cast<ObjectProxy<Vector3> *>(proxy));
	}
}

static JSClassDef vector3_proxy_def = {
	"Vector3Proxy",
	.finalizer = vector3_proxy_finalizer
};


static JSValue vector3_proxy_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["Vector3Proxy"];
	JSValue proto = JS_GetPropertyStr(js_context(), new_target, "prototype");
	JSValue obj = JS_NewObjectProtoClass(js_context(), proto, class_id);
	if (is_exception(js_context(), obj)) {
		return obj;
	}

	ObjectProxy<Vector3> *proxy;
	JSClassID opaque_id;
	// Allow constructing from an existing native pointer
	if (argc == 1 && JS_IsObject(*argv)) {
		proxy = static_cast<ObjectProxy<Vector3> *>(JS_GetAnyOpaque(*argv, &opaque_id));
	} else {
		return JS_EXCEPTION;
	}

	if (!proxy) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	return obj;
}

static JSValue vector3_proxy_min_axis_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector3::min_axis_index, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector3_proxy_max_axis_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector3::max_axis_index, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector3_proxy_angle_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector3::angle_to, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector3_proxy_signed_angle_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector3::signed_angle_to, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector3_proxy_direction_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector3::direction_to, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector3_proxy_distance_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector3::distance_to, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector3_proxy_distance_squared_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector3::distance_squared_to, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector3_proxy_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector3::length, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector3_proxy_length_squared(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector3::length_squared, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector3_proxy_limit_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector3::limit_length, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector3_proxy_normalized(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector3::normalized, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector3_proxy_is_normalized(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector3::is_normalized, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector3_proxy_is_equal_approx(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector3::is_equal_approx, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector3_proxy_is_zero_approx(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector3::is_zero_approx, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector3_proxy_is_finite(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector3::is_finite, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector3_proxy_inverse(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector3::inverse, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector3_proxy_clamp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector3::clamp, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector3_proxy_clampf(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector3::clampf, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector3_proxy_snapped(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector3::snapped, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector3_proxy_snappedf(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector3::snappedf, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector3_proxy_rotated(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector3::rotated, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector3_proxy_lerp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector3::lerp, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector3_proxy_slerp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector3::slerp, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector3_proxy_cubic_interpolate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector3::cubic_interpolate, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector3_proxy_cubic_interpolate_in_time(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector3::cubic_interpolate_in_time, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector3_proxy_bezier_interpolate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector3::bezier_interpolate, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector3_proxy_bezier_derivative(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector3::bezier_derivative, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector3_proxy_move_toward(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector3::move_toward, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector3_proxy_dot(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector3::dot, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector3_proxy_cross(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector3::cross, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector3_proxy_outer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector3::outer, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector3_proxy_abs(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector3::abs, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector3_proxy_floor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector3::floor, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector3_proxy_ceil(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector3::ceil, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector3_proxy_round(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector3::round, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector3_proxy_posmod(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector3::posmod, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector3_proxy_posmodv(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector3::posmodv, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector3_proxy_project(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector3::project, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector3_proxy_slide(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector3::slide, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector3_proxy_bounce(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector3::bounce, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector3_proxy_reflect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector3::reflect, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector3_proxy_sign(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector3::sign, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector3_proxy_octahedron_encode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector3::octahedron_encode, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector3_proxy_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector3::min, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector3_proxy_minf(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector3::minf, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector3_proxy_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector3::max, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector3_proxy_maxf(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector3::maxf, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector3_proxy_octahedron_decode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Vector3::octahedron_decode, ctx, this_val, argc, argv);
}

static JSValue vector3_proxy_get_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    Vector3 ret = proxy->getter();
    return VariantAdapter(ret.x);
}
static JSValue vector3_proxy_set_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    VariantAdapter x(argv[0]);
    Vector3 wrapped = proxy->getter();
    wrapped.x = x.get();
    proxy->setter(wrapped);
	return JS_UNDEFINED;
}
static JSValue vector3_proxy_get_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    Vector3 ret = proxy->getter();
    return VariantAdapter(ret.y);
}
static JSValue vector3_proxy_set_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    VariantAdapter y(argv[0]);
    Vector3 wrapped = proxy->getter();
    wrapped.y = y.get();
    proxy->setter(wrapped);
	return JS_UNDEFINED;
}
static JSValue vector3_proxy_get_z(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    Vector3 ret = proxy->getter();
    return VariantAdapter(ret.z);
}
static JSValue vector3_proxy_set_z(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector3Proxy"]);
    ObjectProxy<Vector3> *proxy = reinterpret_cast<ObjectProxy<Vector3> *>(opaque);
    VariantAdapter z(argv[0]);
    Vector3 wrapped = proxy->getter();
    wrapped.z = z.get();
    proxy->setter(wrapped);
	return JS_UNDEFINED;
}

static const JSCFunctionListEntry vector3_proxy_proto_funcs[] = {
	JS_CFUNC_DEF("min_axis_index", 0, &vector3_proxy_min_axis_index),
	JS_CFUNC_DEF("max_axis_index", 0, &vector3_proxy_max_axis_index),
	JS_CFUNC_DEF("angle_to", 1, &vector3_proxy_angle_to),
	JS_CFUNC_DEF("signed_angle_to", 2, &vector3_proxy_signed_angle_to),
	JS_CFUNC_DEF("direction_to", 1, &vector3_proxy_direction_to),
	JS_CFUNC_DEF("distance_to", 1, &vector3_proxy_distance_to),
	JS_CFUNC_DEF("distance_squared_to", 1, &vector3_proxy_distance_squared_to),
	JS_CFUNC_DEF("length", 0, &vector3_proxy_length),
	JS_CFUNC_DEF("length_squared", 0, &vector3_proxy_length_squared),
	JS_CFUNC_DEF("limit_length", 1, &vector3_proxy_limit_length),
	JS_CFUNC_DEF("normalized", 0, &vector3_proxy_normalized),
	JS_CFUNC_DEF("is_normalized", 0, &vector3_proxy_is_normalized),
	JS_CFUNC_DEF("is_equal_approx", 1, &vector3_proxy_is_equal_approx),
	JS_CFUNC_DEF("is_zero_approx", 0, &vector3_proxy_is_zero_approx),
	JS_CFUNC_DEF("is_finite", 0, &vector3_proxy_is_finite),
	JS_CFUNC_DEF("inverse", 0, &vector3_proxy_inverse),
	JS_CFUNC_DEF("clamp", 2, &vector3_proxy_clamp),
	JS_CFUNC_DEF("clampf", 2, &vector3_proxy_clampf),
	JS_CFUNC_DEF("snapped", 1, &vector3_proxy_snapped),
	JS_CFUNC_DEF("snappedf", 1, &vector3_proxy_snappedf),
	JS_CFUNC_DEF("rotated", 2, &vector3_proxy_rotated),
	JS_CFUNC_DEF("lerp", 2, &vector3_proxy_lerp),
	JS_CFUNC_DEF("slerp", 2, &vector3_proxy_slerp),
	JS_CFUNC_DEF("cubic_interpolate", 4, &vector3_proxy_cubic_interpolate),
	JS_CFUNC_DEF("cubic_interpolate_in_time", 7, &vector3_proxy_cubic_interpolate_in_time),
	JS_CFUNC_DEF("bezier_interpolate", 4, &vector3_proxy_bezier_interpolate),
	JS_CFUNC_DEF("bezier_derivative", 4, &vector3_proxy_bezier_derivative),
	JS_CFUNC_DEF("move_toward", 2, &vector3_proxy_move_toward),
	JS_CFUNC_DEF("dot", 1, &vector3_proxy_dot),
	JS_CFUNC_DEF("cross", 1, &vector3_proxy_cross),
	JS_CFUNC_DEF("outer", 1, &vector3_proxy_outer),
	JS_CFUNC_DEF("abs", 0, &vector3_proxy_abs),
	JS_CFUNC_DEF("floor", 0, &vector3_proxy_floor),
	JS_CFUNC_DEF("ceil", 0, &vector3_proxy_ceil),
	JS_CFUNC_DEF("round", 0, &vector3_proxy_round),
	JS_CFUNC_DEF("posmod", 1, &vector3_proxy_posmod),
	JS_CFUNC_DEF("posmodv", 1, &vector3_proxy_posmodv),
	JS_CFUNC_DEF("project", 1, &vector3_proxy_project),
	JS_CFUNC_DEF("slide", 1, &vector3_proxy_slide),
	JS_CFUNC_DEF("bounce", 1, &vector3_proxy_bounce),
	JS_CFUNC_DEF("reflect", 1, &vector3_proxy_reflect),
	JS_CFUNC_DEF("sign", 0, &vector3_proxy_sign),
	JS_CFUNC_DEF("octahedron_encode", 0, &vector3_proxy_octahedron_encode),
	JS_CFUNC_DEF("min", 1, &vector3_proxy_min),
	JS_CFUNC_DEF("minf", 1, &vector3_proxy_minf),
	JS_CFUNC_DEF("max", 1, &vector3_proxy_max),
	JS_CFUNC_DEF("maxf", 1, &vector3_proxy_maxf),
	JS_CFUNC_DEF("octahedron_decode", 1, &vector3_proxy_octahedron_decode),
};

void define_vector3_proxy_property(JSContext *ctx, JSValue obj) {
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "x"),
			JS_NewCFunction(ctx, vector3_proxy_get_x, "get_x", 0),
			JS_NewCFunction(ctx, vector3_proxy_set_x, "set_x", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "y"),
			JS_NewCFunction(ctx, vector3_proxy_get_y, "get_y", 0),
			JS_NewCFunction(ctx, vector3_proxy_set_y, "set_y", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "z"),
			JS_NewCFunction(ctx, vector3_proxy_get_z, "get_z", 0),
			JS_NewCFunction(ctx, vector3_proxy_set_z, "set_z", 1),
			JS_PROP_GETSET);
}

static int js_vector3_proxy_init(JSContext *ctx) {
	JSClassID class_id = 0;
	classes["Vector3Proxy"] = JS_NewClassID(&class_id);
	classes_by_id[class_id] = "Vector3Proxy";

	JS_NewClass(JS_GetRuntime(ctx), class_id, &vector3_proxy_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, class_id, proto);
	define_vector3_proxy_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, vector3_proxy_proto_funcs, _countof(vector3_proxy_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, vector3_proxy_constructor, "Vector3Proxy", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);

	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "Vector3Proxy", ctor);

	return 0;
}

void js_init_vector3_proxy_module(JSContext *ctx) {
	js_vector3_proxy_init(ctx);
}

void register_proxy_vector3() {
	js_init_vector3_proxy_module(js_context());
}