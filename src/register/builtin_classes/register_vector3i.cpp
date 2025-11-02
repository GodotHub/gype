#include "register/builtin_classes/register_builtin_classes.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/quickjs_helper.hpp"
#include "utils/str_helper.hpp"
#include "utils/variant_helper.hpp"
#include <quickjs.h>


using namespace godot;

static void vector3i_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes[typeid(Vector3i)];
	GDVariantAdapter<Vector3i> *opaque_ptr = static_cast<GDVariantAdapter<Vector3i> *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr && opaque_ptr->can_memfree) {
		memfree(const_cast<Vector3i *>(opaque_ptr->m_active_variant));
	}
}

static JSClassDef vector3i_class_def = {
	"Vector3i",
	.finalizer = vector3i_class_finalizer
};

static JSValue vector3i_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes[typeid(Vector3i)];
	JSValue obj = JS_NewObjectClass(ctx, class_id);
	if (JS_IsException(obj)) {
		return obj;
	}
	
	Vector3i *instance = nullptr;
	GDVariantAdapter<Vector3i> *adapter = reinterpret_cast<GDVariantAdapter<Vector3i> *>(memalloc(sizeof(GDVariantAdapter<Vector3i>)));
	if (argc == 0) {
		instance = reinterpret_cast<Vector3i *>(memalloc(sizeof(Vector3i)));
		instance = new (instance) Vector3i();
	}
	if (argc == 1&&(JSValueAdapter<Vector3i>::can_cast(argv[0]))) {
		Vector3i v0 = *JSValueAdapter<Vector3i>(argv[0]).get();
		instance = reinterpret_cast<Vector3i *>(memalloc(sizeof(Vector3i)));
		instance = new (instance) Vector3i(v0);
	}
	if (argc == 1&&(JSValueAdapter<Vector3>::can_cast(argv[0]))) {
		Vector3 v0 = *JSValueAdapter<Vector3>(argv[0]).get();
		instance = reinterpret_cast<Vector3i *>(memalloc(sizeof(Vector3i)));
		instance = new (instance) Vector3i(v0);
	}
	if (argc == 3&&(JSValueAdapter<int>::can_cast(argv[0]))&&(JSValueAdapter<int>::can_cast(argv[1]))&&(JSValueAdapter<int>::can_cast(argv[2]))) {
		int v0 = *JSValueAdapter<int>(argv[0]).get();
		int v1 = *JSValueAdapter<int>(argv[1]).get();
		int v2 = *JSValueAdapter<int>(argv[2]).get();
		instance = reinterpret_cast<Vector3i *>(memalloc(sizeof(Vector3i)));
		instance = new (instance) Vector3i(v0, v1, v2);
	}
	adapter = new (adapter) GDVariantAdapter<Vector3i>(*instance, true);

	if (!instance || !adapter) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, adapter);
	return obj;
}
static JSValue vector3i_class_min_axis_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3i::min_axis_index, ctx, this_val, argc, argv);
}
static JSValue vector3i_class_max_axis_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3i::max_axis_index, ctx, this_val, argc, argv);
}
static JSValue vector3i_class_distance_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3i::distance_to, ctx, this_val, argc, argv);
}
static JSValue vector3i_class_distance_squared_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3i::distance_squared_to, ctx, this_val, argc, argv);
}
static JSValue vector3i_class_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3i::length, ctx, this_val, argc, argv);
}
static JSValue vector3i_class_length_squared(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3i::length_squared, ctx, this_val, argc, argv);
}
static JSValue vector3i_class_sign(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3i::sign, ctx, this_val, argc, argv);
}
static JSValue vector3i_class_abs(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3i::abs, ctx, this_val, argc, argv);
}
static JSValue vector3i_class_clamp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3i::clamp, ctx, this_val, argc, argv);
}
static JSValue vector3i_class_clampi(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3i::clampi, ctx, this_val, argc, argv);
}
static JSValue vector3i_class_snapped(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3i::snapped, ctx, this_val, argc, argv);
}
static JSValue vector3i_class_snappedi(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3i::snappedi, ctx, this_val, argc, argv);
}
static JSValue vector3i_class_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3i::min, ctx, this_val, argc, argv);
}
static JSValue vector3i_class_mini(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3i::mini, ctx, this_val, argc, argv);
}
static JSValue vector3i_class_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3i::max, ctx, this_val, argc, argv);
}
static JSValue vector3i_class_maxi(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector3i::maxi, ctx, this_val, argc, argv);
}

static JSValue vector3i_class_get_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Vector3i &val = *reinterpret_cast<Vector3i *>(JS_GetOpaque(this_val, classes[typeid(Vector3i)]));
	return GDVariantAdapter<int>(val.x);
}
static JSValue vector3i_class_set_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Vector3i &val = *reinterpret_cast<Vector3i *>(JS_GetOpaque(this_val, classes[typeid(Vector3i)]));
	val.x = *JSValueAdapter<int>(*argv).get();
	return JS_UNDEFINED;
}
static JSValue vector3i_class_get_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Vector3i &val = *reinterpret_cast<Vector3i *>(JS_GetOpaque(this_val, classes[typeid(Vector3i)]));
	return GDVariantAdapter<int>(val.y);
}
static JSValue vector3i_class_set_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Vector3i &val = *reinterpret_cast<Vector3i *>(JS_GetOpaque(this_val, classes[typeid(Vector3i)]));
	val.y = *JSValueAdapter<int>(*argv).get();
	return JS_UNDEFINED;
}
static JSValue vector3i_class_get_z(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Vector3i &val = *reinterpret_cast<Vector3i *>(JS_GetOpaque(this_val, classes[typeid(Vector3i)]));
	return GDVariantAdapter<int>(val.z);
}
static JSValue vector3i_class_set_z(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Vector3i &val = *reinterpret_cast<Vector3i *>(JS_GetOpaque(this_val, classes[typeid(Vector3i)]));
	val.z = *JSValueAdapter<int>(*argv).get();
	return JS_UNDEFINED;
}

static const JSCFunctionListEntry vector3i_class_proto_funcs[] = {
	JS_CFUNC_DEF("min_axis_index", 0, &vector3i_class_min_axis_index),
	JS_CFUNC_DEF("max_axis_index", 0, &vector3i_class_max_axis_index),
	JS_CFUNC_DEF("distance_to", 1, &vector3i_class_distance_to),
	JS_CFUNC_DEF("distance_squared_to", 1, &vector3i_class_distance_squared_to),
	JS_CFUNC_DEF("length", 0, &vector3i_class_length),
	JS_CFUNC_DEF("length_squared", 0, &vector3i_class_length_squared),
	JS_CFUNC_DEF("sign", 0, &vector3i_class_sign),
	JS_CFUNC_DEF("abs", 0, &vector3i_class_abs),
	JS_CFUNC_DEF("clamp", 2, &vector3i_class_clamp),
	JS_CFUNC_DEF("clampi", 2, &vector3i_class_clampi),
	JS_CFUNC_DEF("snapped", 1, &vector3i_class_snapped),
	JS_CFUNC_DEF("snappedi", 1, &vector3i_class_snappedi),
	JS_CFUNC_DEF("min", 1, &vector3i_class_min),
	JS_CFUNC_DEF("mini", 1, &vector3i_class_mini),
	JS_CFUNC_DEF("max", 1, &vector3i_class_max),
	JS_CFUNC_DEF("maxi", 1, &vector3i_class_maxi),
};

void define_vector3i_property(JSContext *ctx, JSValue obj) {
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "x"),
			JS_NewCFunction(ctx, vector3i_class_get_x, "get_x", 0),
			JS_NewCFunction(ctx, vector3i_class_set_x, "set_x", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "y"),
			JS_NewCFunction(ctx, vector3i_class_get_y, "get_y", 0),
			JS_NewCFunction(ctx, vector3i_class_set_y, "set_y", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "z"),
			JS_NewCFunction(ctx, vector3i_class_get_z, "get_z", 0),
			JS_NewCFunction(ctx, vector3i_class_set_z, "set_z", 1),
			JS_PROP_GETSET);
}

static int js_vector3i_class_init(JSContext *ctx) {
	JSClassID class_id = JS_NewClassID(&classes[typeid(Vector3i)]);

	JS_NewClass(JS_GetRuntime(ctx), class_id, &vector3i_class_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, class_id, proto);	define_vector3i_property(ctx, proto);	JS_SetPropertyFunctionList(ctx, proto, vector3i_class_proto_funcs, _countof(vector3i_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, vector3i_class_constructor, "Vector3i", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);

	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "Vector3i", ctor);

	return 0;
}

void js_init_vector3i_module(JSContext *ctx) {
	js_vector3i_class_init(ctx);
}

void register_vector3i() {
	js_init_vector3i_module(js_context());
}