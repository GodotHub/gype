#include "register/builtin_classes/register_builtin_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/quickjs_helper.hpp"
#include "utils/str_helper.hpp"
#include "utils/variant_helper.hpp"
#include <quickjs.h>



using namespace godot;

static void vector4i_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Vector4i"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memfree(opaque_ptr);
	}
}

static JSClassDef vector4i_class_def = {
	"Vector4i",
	vector4i_class_finalizer
};

static JSValue vector4i_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["Vector4i"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);

	if (JS_IsException(obj)) {
		return obj;
	}
	
	Vector4i instance;
	if (argc == 0) {
		instance = Vector4i();
	}
	if (argc == 1&&(VariantAdapter::can_cast(argv[0],Variant::Type::VECTOR4I))) {
			Vector4i
 v0 = VariantAdapter(argv[0]).get();
		instance = Vector4i(v0);
	}
	if (argc == 1&&(VariantAdapter::can_cast(argv[0],Variant::Type::VECTOR4))) {
			Vector4
 v0 = VariantAdapter(argv[0]).get();
		instance = Vector4i(v0);
	}
	if (argc == 4&&(VariantAdapter::can_cast(argv[0],Variant::Type::INT))&&(VariantAdapter::can_cast(argv[1],Variant::Type::INT))&&(VariantAdapter::can_cast(argv[2],Variant::Type::INT))&&(VariantAdapter::can_cast(argv[3],Variant::Type::INT))) {
			int
 v0 = VariantAdapter(argv[0]).get();
			int
 v1 = VariantAdapter(argv[1]).get();
			int
 v2 = VariantAdapter(argv[2]).get();
			int
 v3 = VariantAdapter(argv[3]).get();
		instance = Vector4i(v0, v1, v2, v3);
	}
	VariantAdapter *adapter = memnew(VariantAdapter(instance, true));

	if (!adapter) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, adapter);
	return obj;
}
static JSValue vector4i_class_min_axis_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector4i::min_axis_index, ctx, this_val, argc, argv);
}
static JSValue vector4i_class_max_axis_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector4i::max_axis_index, ctx, this_val, argc, argv);
}
static JSValue vector4i_class_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector4i::length, ctx, this_val, argc, argv);
}
static JSValue vector4i_class_length_squared(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector4i::length_squared, ctx, this_val, argc, argv);
}
static JSValue vector4i_class_sign(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector4i::sign, ctx, this_val, argc, argv);
}
static JSValue vector4i_class_abs(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector4i::abs, ctx, this_val, argc, argv);
}
static JSValue vector4i_class_clamp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector4i::clamp, ctx, this_val, argc, argv);
}
static JSValue vector4i_class_clampi(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector4i::clampi, ctx, this_val, argc, argv);
}
static JSValue vector4i_class_snapped(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector4i::snapped, ctx, this_val, argc, argv);
}
static JSValue vector4i_class_snappedi(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector4i::snappedi, ctx, this_val, argc, argv);
}
static JSValue vector4i_class_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector4i::min, ctx, this_val, argc, argv);
}
static JSValue vector4i_class_mini(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector4i::mini, ctx, this_val, argc, argv);
}
static JSValue vector4i_class_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector4i::max, ctx, this_val, argc, argv);
}
static JSValue vector4i_class_maxi(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector4i::maxi, ctx, this_val, argc, argv);
}
static JSValue vector4i_class_distance_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector4i::distance_to, ctx, this_val, argc, argv);
}
static JSValue vector4i_class_distance_squared_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Vector4i::distance_squared_to, ctx, this_val, argc, argv);
}

static JSValue vector4i_class_get_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Vector4i val = reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Vector4i"]))->get();
	return VariantAdapter(val.x);
}
static JSValue vector4i_class_set_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Vector4i val = reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Vector4i"]))->get();
	val.x = VariantAdapter(*argv).get();
	return JS_UNDEFINED;
}
static JSValue vector4i_class_get_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Vector4i val = reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Vector4i"]))->get();
	return VariantAdapter(val.y);
}
static JSValue vector4i_class_set_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Vector4i val = reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Vector4i"]))->get();
	val.y = VariantAdapter(*argv).get();
	return JS_UNDEFINED;
}
static JSValue vector4i_class_get_z(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Vector4i val = reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Vector4i"]))->get();
	return VariantAdapter(val.z);
}
static JSValue vector4i_class_set_z(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Vector4i val = reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Vector4i"]))->get();
	val.z = VariantAdapter(*argv).get();
	return JS_UNDEFINED;
}
static JSValue vector4i_class_get_w(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Vector4i val = reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Vector4i"]))->get();
	return VariantAdapter(val.w);
}
static JSValue vector4i_class_set_w(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Vector4i val = reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Vector4i"]))->get();
	val.w = VariantAdapter(*argv).get();
	return JS_UNDEFINED;
}

static const JSCFunctionListEntry vector4i_class_proto_funcs[] = {
	JS_CFUNC_DEF("min_axis_index", 0, &vector4i_class_min_axis_index),
	JS_CFUNC_DEF("max_axis_index", 0, &vector4i_class_max_axis_index),
	JS_CFUNC_DEF("length", 0, &vector4i_class_length),
	JS_CFUNC_DEF("length_squared", 0, &vector4i_class_length_squared),
	JS_CFUNC_DEF("sign", 0, &vector4i_class_sign),
	JS_CFUNC_DEF("abs", 0, &vector4i_class_abs),
	JS_CFUNC_DEF("clamp", 2, &vector4i_class_clamp),
	JS_CFUNC_DEF("clampi", 2, &vector4i_class_clampi),
	JS_CFUNC_DEF("snapped", 1, &vector4i_class_snapped),
	JS_CFUNC_DEF("snappedi", 1, &vector4i_class_snappedi),
	JS_CFUNC_DEF("min", 1, &vector4i_class_min),
	JS_CFUNC_DEF("mini", 1, &vector4i_class_mini),
	JS_CFUNC_DEF("max", 1, &vector4i_class_max),
	JS_CFUNC_DEF("maxi", 1, &vector4i_class_maxi),
	JS_CFUNC_DEF("distance_to", 1, &vector4i_class_distance_to),
	JS_CFUNC_DEF("distance_squared_to", 1, &vector4i_class_distance_squared_to),
};

void define_vector4i_property(JSContext *ctx, JSValue obj) {
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "x"),
			JS_NewCFunction(ctx, vector4i_class_get_x, "get_x", 0),
			JS_NewCFunction(ctx, vector4i_class_set_x, "set_x", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "y"),
			JS_NewCFunction(ctx, vector4i_class_get_y, "get_y", 0),
			JS_NewCFunction(ctx, vector4i_class_set_y, "set_y", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "z"),
			JS_NewCFunction(ctx, vector4i_class_get_z, "get_z", 0),
			JS_NewCFunction(ctx, vector4i_class_set_z, "set_z", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "w"),
			JS_NewCFunction(ctx, vector4i_class_get_w, "get_w", 0),
			JS_NewCFunction(ctx, vector4i_class_set_w, "set_w", 1),
			JS_PROP_GETSET);
}

static int js_vector4i_class_init(JSContext *ctx) {
	JSClassID class_id = 0;
	classes["Vector4i"] = JS_NewClassID(js_runtime(), &class_id);
	classes_by_id[class_id] = "Vector4i";

	JS_NewClass(JS_GetRuntime(ctx), class_id, &vector4i_class_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, class_id, proto);	define_vector4i_property(ctx, proto);	JS_SetPropertyFunctionList(ctx, proto, vector4i_class_proto_funcs, _countof(vector4i_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, vector4i_class_constructor, "Vector4i", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);

	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "Vector4i", ctor);

	return 0;
}

void js_init_vector4i_module(JSContext *ctx) {
	js_vector4i_class_init(ctx);
}

void register_vector4i() {
	js_init_vector4i_module(js_context());
}

// ------------------Vector4iProxy------------------
static void vector4i_proxy_finalizer(JSRuntime *rt, JSValue val) {
	void *proxy = JS_GetOpaque(val, classes["Vector4iProxy"]);
	if (proxy) {
		memfree(static_cast<ObjectProxy<Vector4i> *>(proxy));
	}
}

static JSClassDef vector4i_proxy_def = {
	.class_name = "Vector4iProxy",
	.finalizer = vector4i_proxy_finalizer
};


static JSValue vector4i_proxy_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["Vector4iProxy"];
	JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
	JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

	ObjectProxy<Vector4i> *proxy;
	JSClassID opaque_id;
	// Allow constructing from an existing native pointer
	if (argc == 1 && JS_IsObject(*argv)) {
		proxy = static_cast<ObjectProxy<Vector4i> *>(JS_GetAnyOpaque(*argv, &opaque_id));
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

static JSValue vector4i_proxy_min_axis_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector4iProxy"]);
    ObjectProxy<Vector4i> *proxy = reinterpret_cast<ObjectProxy<Vector4i> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector4i::min_axis_index, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector4i_proxy_max_axis_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector4iProxy"]);
    ObjectProxy<Vector4i> *proxy = reinterpret_cast<ObjectProxy<Vector4i> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector4i::max_axis_index, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector4i_proxy_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector4iProxy"]);
    ObjectProxy<Vector4i> *proxy = reinterpret_cast<ObjectProxy<Vector4i> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector4i::length, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector4i_proxy_length_squared(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector4iProxy"]);
    ObjectProxy<Vector4i> *proxy = reinterpret_cast<ObjectProxy<Vector4i> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector4i::length_squared, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector4i_proxy_sign(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector4iProxy"]);
    ObjectProxy<Vector4i> *proxy = reinterpret_cast<ObjectProxy<Vector4i> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector4i::sign, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector4i_proxy_abs(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector4iProxy"]);
    ObjectProxy<Vector4i> *proxy = reinterpret_cast<ObjectProxy<Vector4i> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector4i::abs, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector4i_proxy_clamp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector4iProxy"]);
    ObjectProxy<Vector4i> *proxy = reinterpret_cast<ObjectProxy<Vector4i> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector4i::clamp, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector4i_proxy_clampi(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector4iProxy"]);
    ObjectProxy<Vector4i> *proxy = reinterpret_cast<ObjectProxy<Vector4i> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector4i::clampi, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector4i_proxy_snapped(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector4iProxy"]);
    ObjectProxy<Vector4i> *proxy = reinterpret_cast<ObjectProxy<Vector4i> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector4i::snapped, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector4i_proxy_snappedi(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector4iProxy"]);
    ObjectProxy<Vector4i> *proxy = reinterpret_cast<ObjectProxy<Vector4i> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector4i::snappedi, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector4i_proxy_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector4iProxy"]);
    ObjectProxy<Vector4i> *proxy = reinterpret_cast<ObjectProxy<Vector4i> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector4i::min, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector4i_proxy_mini(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector4iProxy"]);
    ObjectProxy<Vector4i> *proxy = reinterpret_cast<ObjectProxy<Vector4i> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector4i::mini, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector4i_proxy_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector4iProxy"]);
    ObjectProxy<Vector4i> *proxy = reinterpret_cast<ObjectProxy<Vector4i> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector4i::max, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector4i_proxy_maxi(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector4iProxy"]);
    ObjectProxy<Vector4i> *proxy = reinterpret_cast<ObjectProxy<Vector4i> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector4i::maxi, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector4i_proxy_distance_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector4iProxy"]);
    ObjectProxy<Vector4i> *proxy = reinterpret_cast<ObjectProxy<Vector4i> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector4i::distance_to, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector4i_proxy_distance_squared_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector4iProxy"]);
    ObjectProxy<Vector4i> *proxy = reinterpret_cast<ObjectProxy<Vector4i> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector4i::distance_squared_to, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}

static JSValue vector4i_proxy_get_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector4iProxy"]);
    ObjectProxy<Vector4i> *proxy = reinterpret_cast<ObjectProxy<Vector4i> *>(opaque);
    Vector4i ret = proxy->getter();
    return VariantAdapter(ret.x);
}
static JSValue vector4i_proxy_set_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector4iProxy"]);
    ObjectProxy<Vector4i> *proxy = reinterpret_cast<ObjectProxy<Vector4i> *>(opaque);
    VariantAdapter x(argv[0]);
    Vector4i wrapped = proxy->getter();
    wrapped.x = x.get();
    proxy->setter(wrapped);
	return JS_UNDEFINED;
}
static JSValue vector4i_proxy_get_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector4iProxy"]);
    ObjectProxy<Vector4i> *proxy = reinterpret_cast<ObjectProxy<Vector4i> *>(opaque);
    Vector4i ret = proxy->getter();
    return VariantAdapter(ret.y);
}
static JSValue vector4i_proxy_set_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector4iProxy"]);
    ObjectProxy<Vector4i> *proxy = reinterpret_cast<ObjectProxy<Vector4i> *>(opaque);
    VariantAdapter y(argv[0]);
    Vector4i wrapped = proxy->getter();
    wrapped.y = y.get();
    proxy->setter(wrapped);
	return JS_UNDEFINED;
}
static JSValue vector4i_proxy_get_z(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector4iProxy"]);
    ObjectProxy<Vector4i> *proxy = reinterpret_cast<ObjectProxy<Vector4i> *>(opaque);
    Vector4i ret = proxy->getter();
    return VariantAdapter(ret.z);
}
static JSValue vector4i_proxy_set_z(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector4iProxy"]);
    ObjectProxy<Vector4i> *proxy = reinterpret_cast<ObjectProxy<Vector4i> *>(opaque);
    VariantAdapter z(argv[0]);
    Vector4i wrapped = proxy->getter();
    wrapped.z = z.get();
    proxy->setter(wrapped);
	return JS_UNDEFINED;
}
static JSValue vector4i_proxy_get_w(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector4iProxy"]);
    ObjectProxy<Vector4i> *proxy = reinterpret_cast<ObjectProxy<Vector4i> *>(opaque);
    Vector4i ret = proxy->getter();
    return VariantAdapter(ret.w);
}
static JSValue vector4i_proxy_set_w(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector4iProxy"]);
    ObjectProxy<Vector4i> *proxy = reinterpret_cast<ObjectProxy<Vector4i> *>(opaque);
    VariantAdapter w(argv[0]);
    Vector4i wrapped = proxy->getter();
    wrapped.w = w.get();
    proxy->setter(wrapped);
	return JS_UNDEFINED;
}

static const JSCFunctionListEntry vector4i_proxy_proto_funcs[] = {
	JS_CFUNC_DEF("min_axis_index", 0, &vector4i_proxy_min_axis_index),
	JS_CFUNC_DEF("max_axis_index", 0, &vector4i_proxy_max_axis_index),
	JS_CFUNC_DEF("length", 0, &vector4i_proxy_length),
	JS_CFUNC_DEF("length_squared", 0, &vector4i_proxy_length_squared),
	JS_CFUNC_DEF("sign", 0, &vector4i_proxy_sign),
	JS_CFUNC_DEF("abs", 0, &vector4i_proxy_abs),
	JS_CFUNC_DEF("clamp", 2, &vector4i_proxy_clamp),
	JS_CFUNC_DEF("clampi", 2, &vector4i_proxy_clampi),
	JS_CFUNC_DEF("snapped", 1, &vector4i_proxy_snapped),
	JS_CFUNC_DEF("snappedi", 1, &vector4i_proxy_snappedi),
	JS_CFUNC_DEF("min", 1, &vector4i_proxy_min),
	JS_CFUNC_DEF("mini", 1, &vector4i_proxy_mini),
	JS_CFUNC_DEF("max", 1, &vector4i_proxy_max),
	JS_CFUNC_DEF("maxi", 1, &vector4i_proxy_maxi),
	JS_CFUNC_DEF("distance_to", 1, &vector4i_proxy_distance_to),
	JS_CFUNC_DEF("distance_squared_to", 1, &vector4i_proxy_distance_squared_to),
};

void define_vector4i_proxy_property(JSContext *ctx, JSValue obj) {
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "x"),
			JS_NewCFunction(ctx, vector4i_proxy_get_x, "get_x", 0),
			JS_NewCFunction(ctx, vector4i_proxy_set_x, "set_x", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "y"),
			JS_NewCFunction(ctx, vector4i_proxy_get_y, "get_y", 0),
			JS_NewCFunction(ctx, vector4i_proxy_set_y, "set_y", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "z"),
			JS_NewCFunction(ctx, vector4i_proxy_get_z, "get_z", 0),
			JS_NewCFunction(ctx, vector4i_proxy_set_z, "set_z", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "w"),
			JS_NewCFunction(ctx, vector4i_proxy_get_w, "get_w", 0),
			JS_NewCFunction(ctx, vector4i_proxy_set_w, "set_w", 1),
			JS_PROP_GETSET);
}

static int js_vector4i_proxy_init(JSContext *ctx) {
	JSClassID class_id = 0;
	classes["Vector4iProxy"] = JS_NewClassID(js_runtime(), &class_id);
	classes_by_id[class_id] = "Vector4iProxy";

	JS_NewClass(JS_GetRuntime(ctx), class_id, &vector4i_proxy_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, class_id, proto);
	define_vector4i_proxy_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, vector4i_proxy_proto_funcs, _countof(vector4i_proxy_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, vector4i_proxy_constructor, "Vector4iProxy", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);

	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "Vector4iProxy", ctor);

	return 0;
}

void js_init_vector4i_proxy_module(JSContext *ctx) {
	js_vector4i_proxy_init(ctx);
}

void register_proxy_vector4i() {
	js_init_vector4i_proxy_module(js_context());
}