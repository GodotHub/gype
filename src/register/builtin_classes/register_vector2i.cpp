#include "register/builtin_classes/register_builtin_classes.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/quickjs_helper.hpp"
#include "utils/str_helper.hpp"
#include "utils/variant_helper.hpp"
#include <quickjs.h>


using namespace godot;

static void vector2i_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes[typeid(Vector2i)];
	GDVariantAdapter<Vector2i> *opaque_ptr = static_cast<GDVariantAdapter<Vector2i> *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr && opaque_ptr->can_memfree) {
		memfree(const_cast<Vector2i *>(opaque_ptr->m_active_variant));
	}
}

static JSClassDef vector2i_class_def = {
	"Vector2i",
	.finalizer = vector2i_class_finalizer
};

static JSValue vector2i_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes[typeid(Vector2i)];
	JSValue obj = JS_NewObjectClass(ctx, class_id);
	if (JS_IsException(obj)) {
		return obj;
	}
	
	Vector2i *instance = nullptr;
	GDVariantAdapter<Vector2i> *adapter = reinterpret_cast<GDVariantAdapter<Vector2i> *>(memalloc(sizeof(GDVariantAdapter<Vector2i>)));
	if (argc == 0) {
		instance = reinterpret_cast<Vector2i *>(memalloc(sizeof(Vector2i)));
		instance = new (instance) Vector2i();
	}
	if (argc == 1&&(JSValueAdapter<Vector2i>::can_cast(argv[0]))) {
		Vector2i v0 = *JSValueAdapter<Vector2i>(argv[0]).get();
		instance = reinterpret_cast<Vector2i *>(memalloc(sizeof(Vector2i)));
		instance = new (instance) Vector2i(v0);
	}
	if (argc == 1&&(JSValueAdapter<Vector2>::can_cast(argv[0]))) {
		Vector2 v0 = *JSValueAdapter<Vector2>(argv[0]).get();
		instance = reinterpret_cast<Vector2i *>(memalloc(sizeof(Vector2i)));
		instance = new (instance) Vector2i(v0);
	}
	if (argc == 2&&(JSValueAdapter<int>::can_cast(argv[0]))&&(JSValueAdapter<int>::can_cast(argv[1]))) {
		int v0 = *JSValueAdapter<int>(argv[0]).get();
		int v1 = *JSValueAdapter<int>(argv[1]).get();
		instance = reinterpret_cast<Vector2i *>(memalloc(sizeof(Vector2i)));
		instance = new (instance) Vector2i(v0, v1);
	}
	adapter = new (adapter) GDVariantAdapter<Vector2i>(*instance, true);

	if (!instance || !adapter) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, adapter);
	return obj;
}
static JSValue vector2i_class_aspect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2i::aspect, ctx, this_val, argc, argv);
}
static JSValue vector2i_class_max_axis_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2i::max_axis_index, ctx, this_val, argc, argv);
}
static JSValue vector2i_class_min_axis_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2i::min_axis_index, ctx, this_val, argc, argv);
}
static JSValue vector2i_class_distance_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2i::distance_to, ctx, this_val, argc, argv);
}
static JSValue vector2i_class_distance_squared_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2i::distance_squared_to, ctx, this_val, argc, argv);
}
static JSValue vector2i_class_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2i::length, ctx, this_val, argc, argv);
}
static JSValue vector2i_class_length_squared(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2i::length_squared, ctx, this_val, argc, argv);
}
static JSValue vector2i_class_sign(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2i::sign, ctx, this_val, argc, argv);
}
static JSValue vector2i_class_abs(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2i::abs, ctx, this_val, argc, argv);
}
static JSValue vector2i_class_clamp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2i::clamp, ctx, this_val, argc, argv);
}
static JSValue vector2i_class_clampi(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2i::clampi, ctx, this_val, argc, argv);
}
static JSValue vector2i_class_snapped(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2i::snapped, ctx, this_val, argc, argv);
}
static JSValue vector2i_class_snappedi(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2i::snappedi, ctx, this_val, argc, argv);
}
static JSValue vector2i_class_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2i::min, ctx, this_val, argc, argv);
}
static JSValue vector2i_class_mini(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2i::mini, ctx, this_val, argc, argv);
}
static JSValue vector2i_class_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2i::max, ctx, this_val, argc, argv);
}
static JSValue vector2i_class_maxi(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector2i::maxi, ctx, this_val, argc, argv);
}

static JSValue vector2i_class_get_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Vector2i &val = *reinterpret_cast<Vector2i *>(JS_GetOpaque(this_val, classes[typeid(Vector2i)]));
	return GDVariantAdapter<int>(val.x);
}
static JSValue vector2i_class_set_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Vector2i &val = *reinterpret_cast<Vector2i *>(JS_GetOpaque(this_val, classes[typeid(Vector2i)]));
	val.x = *JSValueAdapter<int>(*argv).get();
	return JS_UNDEFINED;
}
static JSValue vector2i_class_get_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Vector2i &val = *reinterpret_cast<Vector2i *>(JS_GetOpaque(this_val, classes[typeid(Vector2i)]));
	return GDVariantAdapter<int>(val.y);
}
static JSValue vector2i_class_set_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Vector2i &val = *reinterpret_cast<Vector2i *>(JS_GetOpaque(this_val, classes[typeid(Vector2i)]));
	val.y = *JSValueAdapter<int>(*argv).get();
	return JS_UNDEFINED;
}

static const JSCFunctionListEntry vector2i_class_proto_funcs[] = {
	JS_CFUNC_DEF("aspect", 0, &vector2i_class_aspect),
	JS_CFUNC_DEF("max_axis_index", 0, &vector2i_class_max_axis_index),
	JS_CFUNC_DEF("min_axis_index", 0, &vector2i_class_min_axis_index),
	JS_CFUNC_DEF("distance_to", 1, &vector2i_class_distance_to),
	JS_CFUNC_DEF("distance_squared_to", 1, &vector2i_class_distance_squared_to),
	JS_CFUNC_DEF("length", 0, &vector2i_class_length),
	JS_CFUNC_DEF("length_squared", 0, &vector2i_class_length_squared),
	JS_CFUNC_DEF("sign", 0, &vector2i_class_sign),
	JS_CFUNC_DEF("abs", 0, &vector2i_class_abs),
	JS_CFUNC_DEF("clamp", 2, &vector2i_class_clamp),
	JS_CFUNC_DEF("clampi", 2, &vector2i_class_clampi),
	JS_CFUNC_DEF("snapped", 1, &vector2i_class_snapped),
	JS_CFUNC_DEF("snappedi", 1, &vector2i_class_snappedi),
	JS_CFUNC_DEF("min", 1, &vector2i_class_min),
	JS_CFUNC_DEF("mini", 1, &vector2i_class_mini),
	JS_CFUNC_DEF("max", 1, &vector2i_class_max),
	JS_CFUNC_DEF("maxi", 1, &vector2i_class_maxi),
};

void define_vector2i_property(JSContext *ctx, JSValue obj) {
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "x"),
			JS_NewCFunction(ctx, vector2i_class_get_x, "get_x", 0),
			JS_NewCFunction(ctx, vector2i_class_set_x, "set_x", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "y"),
			JS_NewCFunction(ctx, vector2i_class_get_y, "get_y", 0),
			JS_NewCFunction(ctx, vector2i_class_set_y, "set_y", 1),
			JS_PROP_GETSET);
}

static int js_vector2i_class_init(JSContext *ctx) {
	JSClassID class_id = JS_NewClassID(&classes[typeid(Vector2i)]);

	JS_NewClass(JS_GetRuntime(ctx), class_id, &vector2i_class_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, class_id, proto);	define_vector2i_property(ctx, proto);	JS_SetPropertyFunctionList(ctx, proto, vector2i_class_proto_funcs, _countof(vector2i_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, vector2i_class_constructor, "Vector2i", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);

	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "Vector2i", ctor);

	return 0;
}

void js_init_vector2i_module(JSContext *ctx) {
	js_vector2i_class_init(ctx);
}

void register_vector2i() {
	js_init_vector2i_module(js_context());
}