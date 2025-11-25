#include "register/builtin_classes/register_builtin_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/quickjs_helper.hpp"
#include "utils/str_helper.hpp"
#include "utils/variant_helper.hpp"
#include <quickjs.h>



using namespace godot;

static void vector2i_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Vector2i"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memfree(opaque_ptr);
	}
}

static JSClassDef vector2i_class_def = {
	"Vector2i",
	vector2i_class_finalizer
};

static JSValue vector2i_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["Vector2i"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);

	if (JS_IsException(obj)) {
		return obj;
	}
	
	Vector2i instance;
	if (argc == 0) {
		instance = Vector2i();
	}
	if (argc == 1&&VariantAdapter::can_cast(argv[0], Variant::Type::VECTOR2I)) {
		Vector2i v0 = VariantAdapter(argv[0]).get();
		instance = Vector2i(v0);
	}
	if (argc == 1&&VariantAdapter::can_cast(argv[0], Variant::Type::VECTOR2)) {
		Vector2 v0 = VariantAdapter(argv[0]).get();
		instance = Vector2i(v0);
	}
	if (argc == 2&&JS_IsNumber(argv[0])&&JS_IsNumber(argv[1])) {
		int v0 = VariantAdapter(argv[0]).get();
		int v1 = VariantAdapter(argv[1]).get();
		instance = Vector2i(v0, v1);
	}
	VariantAdapter *adapter = memnew(VariantAdapter(instance));

	if (!adapter) {
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
	Vector2i val = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Vector2i"]))->get();
	return VariantAdapter(val.x);
}
static JSValue vector2i_class_set_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    VariantAdapter *adapter = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Vector2i"]));
    Vector2i val = adapter->get();
    val.x = VariantAdapter(*argv).get();
    adapter->set(val);
	return JS_UNDEFINED;
}
static JSValue vector2i_class_get_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Vector2i val = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Vector2i"]))->get();
	return VariantAdapter(val.y);
}
static JSValue vector2i_class_set_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    VariantAdapter *adapter = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Vector2i"]));
    Vector2i val = adapter->get();
    val.y = VariantAdapter(*argv).get();
    adapter->set(val);
	return JS_UNDEFINED;
}


static JSValue vector2i_get_constant_ZERO(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Vector2i(0, 0));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue vector2i_get_constant_ONE(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Vector2i(1, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue vector2i_get_constant_MIN(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Vector2i(-2147483648, -2147483648));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue vector2i_get_constant_MAX(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Vector2i(2147483647, 2147483647));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue vector2i_get_constant_LEFT(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Vector2i(-1, 0));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue vector2i_get_constant_RIGHT(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Vector2i(1, 0));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue vector2i_get_constant_UP(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Vector2i(0, -1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue vector2i_get_constant_DOWN(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Vector2i(0, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
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

static const JSCFunctionListEntry vector2i_class_constants_funcs[] = {
    JS_CGETSET_DEF("ZERO", &vector2i_get_constant_ZERO, NULL),
    JS_CGETSET_DEF("ONE", &vector2i_get_constant_ONE, NULL),
    JS_CGETSET_DEF("MIN", &vector2i_get_constant_MIN, NULL),
    JS_CGETSET_DEF("MAX", &vector2i_get_constant_MAX, NULL),
    JS_CGETSET_DEF("LEFT", &vector2i_get_constant_LEFT, NULL),
    JS_CGETSET_DEF("RIGHT", &vector2i_get_constant_RIGHT, NULL),
    JS_CGETSET_DEF("UP", &vector2i_get_constant_UP, NULL),
    JS_CGETSET_DEF("DOWN", &vector2i_get_constant_DOWN, NULL),
};

static void define_vector2i_property(JSContext *ctx, JSValue obj) {
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
	JSClassID class_id = 0;
	classes["Vector2i"] = JS_NewClassID(js_runtime(), &class_id);
	classes_by_id[class_id] = "Vector2i";

	JS_NewClass(JS_GetRuntime(ctx), class_id, &vector2i_class_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, class_id, proto);	define_vector2i_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, vector2i_class_proto_funcs, _countof(vector2i_class_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, vector2i_class_constructor, "Vector2i", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetPropertyFunctionList(ctx, ctor, vector2i_class_constants_funcs, _countof(vector2i_class_constants_funcs));
	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "Vector2i", ctor);

	JS_FreeValue(ctx, global);
	return 0;
}

static void js_init_vector2i_module(JSContext *ctx) {
	js_vector2i_class_init(ctx);
}

void register_vector2i() {
	js_init_vector2i_module(js_context());
}

// ------------------Vector2iProxy------------------
static void vector2i_proxy_finalizer(JSRuntime *rt, JSValue val) {
	void *proxy = JS_GetOpaque(val, classes["Vector2iProxy"]);
	if (proxy) {
		memfree(static_cast<ObjectProxy<Vector2i> *>(proxy));
	}
}

static JSClassDef vector2i_proxy_def = {
	"Vector2iProxy",
	vector2i_proxy_finalizer
};


static JSValue vector2i_proxy_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["Vector2iProxy"];
	JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
	JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

	ObjectProxy<Vector2i> *proxy;
	JSClassID opaque_id;
	// Allow constructing from an existing native pointer
	if (argc == 1 && JS_IsObject(*argv)) {
		proxy = static_cast<ObjectProxy<Vector2i> *>(JS_GetAnyOpaque(*argv, &opaque_id));
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

static JSValue vector2i_proxy_aspect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector2iProxy"]);
    ObjectProxy<Vector2i> *proxy = static_cast<ObjectProxy<Vector2i> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector2i::aspect, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector2i_proxy_max_axis_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector2iProxy"]);
    ObjectProxy<Vector2i> *proxy = static_cast<ObjectProxy<Vector2i> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector2i::max_axis_index, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector2i_proxy_min_axis_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector2iProxy"]);
    ObjectProxy<Vector2i> *proxy = static_cast<ObjectProxy<Vector2i> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector2i::min_axis_index, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector2i_proxy_distance_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector2iProxy"]);
    ObjectProxy<Vector2i> *proxy = static_cast<ObjectProxy<Vector2i> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector2i::distance_to, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector2i_proxy_distance_squared_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector2iProxy"]);
    ObjectProxy<Vector2i> *proxy = static_cast<ObjectProxy<Vector2i> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector2i::distance_squared_to, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector2i_proxy_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector2iProxy"]);
    ObjectProxy<Vector2i> *proxy = static_cast<ObjectProxy<Vector2i> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector2i::length, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector2i_proxy_length_squared(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector2iProxy"]);
    ObjectProxy<Vector2i> *proxy = static_cast<ObjectProxy<Vector2i> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector2i::length_squared, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector2i_proxy_sign(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector2iProxy"]);
    ObjectProxy<Vector2i> *proxy = static_cast<ObjectProxy<Vector2i> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector2i::sign, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector2i_proxy_abs(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector2iProxy"]);
    ObjectProxy<Vector2i> *proxy = static_cast<ObjectProxy<Vector2i> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector2i::abs, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector2i_proxy_clamp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector2iProxy"]);
    ObjectProxy<Vector2i> *proxy = static_cast<ObjectProxy<Vector2i> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector2i::clamp, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector2i_proxy_clampi(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector2iProxy"]);
    ObjectProxy<Vector2i> *proxy = static_cast<ObjectProxy<Vector2i> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector2i::clampi, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector2i_proxy_snapped(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector2iProxy"]);
    ObjectProxy<Vector2i> *proxy = static_cast<ObjectProxy<Vector2i> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector2i::snapped, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector2i_proxy_snappedi(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector2iProxy"]);
    ObjectProxy<Vector2i> *proxy = static_cast<ObjectProxy<Vector2i> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector2i::snappedi, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector2i_proxy_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector2iProxy"]);
    ObjectProxy<Vector2i> *proxy = static_cast<ObjectProxy<Vector2i> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector2i::min, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector2i_proxy_mini(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector2iProxy"]);
    ObjectProxy<Vector2i> *proxy = static_cast<ObjectProxy<Vector2i> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector2i::mini, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector2i_proxy_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector2iProxy"]);
    ObjectProxy<Vector2i> *proxy = static_cast<ObjectProxy<Vector2i> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector2i::max, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue vector2i_proxy_maxi(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector2iProxy"]);
    ObjectProxy<Vector2i> *proxy = static_cast<ObjectProxy<Vector2i> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Vector2i::maxi, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}

static JSValue vector2i_proxy_get_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector2iProxy"]);
    ObjectProxy<Vector2i> *proxy = static_cast<ObjectProxy<Vector2i> *>(opaque);
    Vector2i ret = proxy->getter();
    return VariantAdapter(ret.x);
}
static JSValue vector2i_proxy_set_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector2iProxy"]);
    ObjectProxy<Vector2i> *proxy = static_cast<ObjectProxy<Vector2i> *>(opaque);
    VariantAdapter x(argv[0]);
    Vector2i wrapped = proxy->getter();
    wrapped.x = x.get();
    proxy->setter(wrapped);
	return JS_UNDEFINED;
}
static JSValue vector2i_proxy_get_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector2iProxy"]);
    ObjectProxy<Vector2i> *proxy = static_cast<ObjectProxy<Vector2i> *>(opaque);
    Vector2i ret = proxy->getter();
    return VariantAdapter(ret.y);
}
static JSValue vector2i_proxy_set_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Vector2iProxy"]);
    ObjectProxy<Vector2i> *proxy = static_cast<ObjectProxy<Vector2i> *>(opaque);
    VariantAdapter y(argv[0]);
    Vector2i wrapped = proxy->getter();
    wrapped.y = y.get();
    proxy->setter(wrapped);
	return JS_UNDEFINED;
}

static const JSCFunctionListEntry vector2i_proxy_proto_funcs[] = {
	JS_CFUNC_DEF("aspect", 0, &vector2i_proxy_aspect),
	JS_CFUNC_DEF("max_axis_index", 0, &vector2i_proxy_max_axis_index),
	JS_CFUNC_DEF("min_axis_index", 0, &vector2i_proxy_min_axis_index),
	JS_CFUNC_DEF("distance_to", 1, &vector2i_proxy_distance_to),
	JS_CFUNC_DEF("distance_squared_to", 1, &vector2i_proxy_distance_squared_to),
	JS_CFUNC_DEF("length", 0, &vector2i_proxy_length),
	JS_CFUNC_DEF("length_squared", 0, &vector2i_proxy_length_squared),
	JS_CFUNC_DEF("sign", 0, &vector2i_proxy_sign),
	JS_CFUNC_DEF("abs", 0, &vector2i_proxy_abs),
	JS_CFUNC_DEF("clamp", 2, &vector2i_proxy_clamp),
	JS_CFUNC_DEF("clampi", 2, &vector2i_proxy_clampi),
	JS_CFUNC_DEF("snapped", 1, &vector2i_proxy_snapped),
	JS_CFUNC_DEF("snappedi", 1, &vector2i_proxy_snappedi),
	JS_CFUNC_DEF("min", 1, &vector2i_proxy_min),
	JS_CFUNC_DEF("mini", 1, &vector2i_proxy_mini),
	JS_CFUNC_DEF("max", 1, &vector2i_proxy_max),
	JS_CFUNC_DEF("maxi", 1, &vector2i_proxy_maxi),
};

void define_vector2i_proxy_property(JSContext *ctx, JSValue obj) {
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "x"),
			JS_NewCFunction(ctx, vector2i_proxy_get_x, "get_x", 0),
			JS_NewCFunction(ctx, vector2i_proxy_set_x, "set_x", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "y"),
			JS_NewCFunction(ctx, vector2i_proxy_get_y, "get_y", 0),
			JS_NewCFunction(ctx, vector2i_proxy_set_y, "set_y", 1),
			JS_PROP_GETSET);
}

static int js_vector2i_proxy_init(JSContext *ctx) {
	JSClassID class_id = 0;
	classes["Vector2iProxy"] = JS_NewClassID(js_runtime(), &class_id);
	classes_by_id[class_id] = "Vector2iProxy";

	JS_NewClass(JS_GetRuntime(ctx), class_id, &vector2i_proxy_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, class_id, proto);
	define_vector2i_proxy_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, vector2i_proxy_proto_funcs, _countof(vector2i_proxy_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, vector2i_proxy_constructor, "Vector2iProxy", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);

	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "Vector2iProxy", ctor);

	JS_FreeValue(ctx, global);
	return 0;
}

void js_init_vector2i_proxy_module(JSContext *ctx) {
	js_vector2i_proxy_init(ctx);
}

void register_proxy_vector2i() {
	js_init_vector2i_proxy_module(js_context());
}
