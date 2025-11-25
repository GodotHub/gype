#include "register/builtin_classes/register_builtin_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/quickjs_helper.hpp"
#include "utils/str_helper.hpp"
#include "utils/variant_helper.hpp"
#include <quickjs.h>
#include <godot_cpp/variant/vector2.hpp>


using namespace godot;

static void rect2_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Rect2"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memfree(opaque_ptr);
	}
}

static JSClassDef rect2_class_def = {
	"Rect2",
	rect2_class_finalizer
};

static JSValue rect2_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["Rect2"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);

	if (JS_IsException(obj)) {
		return obj;
	}
	
	Rect2 instance;
	if (argc == 0) {
		instance = Rect2();
	}
	if (argc == 1&&VariantAdapter::can_cast(argv[0], Variant::Type::RECT2)) {
		Rect2 v0 = VariantAdapter(argv[0]).get();
		instance = Rect2(v0);
	}
	if (argc == 1&&VariantAdapter::can_cast(argv[0], Variant::Type::RECT2I)) {
		Rect2i v0 = VariantAdapter(argv[0]).get();
		instance = Rect2(v0);
	}
	if (argc == 2&&VariantAdapter::can_cast(argv[0], Variant::Type::VECTOR2)&&VariantAdapter::can_cast(argv[1], Variant::Type::VECTOR2)) {
		Vector2 v0 = VariantAdapter(argv[0]).get();
		Vector2 v1 = VariantAdapter(argv[1]).get();
		instance = Rect2(v0, v1);
	}
	if (argc == 4&&JS_IsNumber(argv[0])&&JS_IsNumber(argv[1])&&JS_IsNumber(argv[2])&&JS_IsNumber(argv[3])) {
		double v0 = VariantAdapter(argv[0]).get();
		double v1 = VariantAdapter(argv[1]).get();
		double v2 = VariantAdapter(argv[2]).get();
		double v3 = VariantAdapter(argv[3]).get();
		instance = Rect2(v0, v1, v2, v3);
	}
	VariantAdapter *adapter = memnew(VariantAdapter(instance));

	if (!adapter) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, adapter);
	return obj;
}
static JSValue rect2_class_get_center(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Rect2::get_center, ctx, this_val, argc, argv);
}
static JSValue rect2_class_get_area(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Rect2::get_area, ctx, this_val, argc, argv);
}
static JSValue rect2_class_has_area(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Rect2::has_area, ctx, this_val, argc, argv);
}
static JSValue rect2_class_has_point(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Rect2::has_point, ctx, this_val, argc, argv);
}
static JSValue rect2_class_is_equal_approx(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Rect2::is_equal_approx, ctx, this_val, argc, argv);
}
static JSValue rect2_class_is_finite(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Rect2::is_finite, ctx, this_val, argc, argv);
}
static JSValue rect2_class_intersects(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Rect2::intersects, ctx, this_val, argc, argv);
}
static JSValue rect2_class_encloses(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Rect2::encloses, ctx, this_val, argc, argv);
}
static JSValue rect2_class_intersection(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Rect2::intersection, ctx, this_val, argc, argv);
}
static JSValue rect2_class_merge(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Rect2::merge, ctx, this_val, argc, argv);
}
static JSValue rect2_class_expand(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Rect2::expand, ctx, this_val, argc, argv);
}
static JSValue rect2_class_get_support(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Rect2::get_support, ctx, this_val, argc, argv);
}
static JSValue rect2_class_grow(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Rect2::grow, ctx, this_val, argc, argv);
}
static JSValue rect2_class_grow_side(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Rect2::grow_side, ctx, this_val, argc, argv);
}
static JSValue rect2_class_grow_individual(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Rect2::grow_individual, ctx, this_val, argc, argv);
}
static JSValue rect2_class_abs(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Rect2::abs, ctx, this_val, argc, argv);
}

static JSValue rect2_class_get_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Rect2 val = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Rect2"]))->get();
	return VariantAdapter(val.position);
}
static JSValue rect2_class_set_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    VariantAdapter *adapter = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Rect2"]));
    Rect2 val = adapter->get();
    val.position = VariantAdapter(*argv).get();
    adapter->set(val);
	return JS_UNDEFINED;
}
static JSValue rect2_class_get_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Rect2 val = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Rect2"]))->get();
	return VariantAdapter(val.size);
}
static JSValue rect2_class_set_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    VariantAdapter *adapter = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Rect2"]));
    Rect2 val = adapter->get();
    val.size = VariantAdapter(*argv).get();
    adapter->set(val);
	return JS_UNDEFINED;
}
static JSValue rect2_class_get_end(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Rect2 val = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Rect2"]))->get();
	return VariantAdapter(val.get_end());
}
static JSValue rect2_class_set_end(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    VariantAdapter *adapter = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Rect2"]));
    Rect2 val = adapter->get();
    val.set_end(VariantAdapter(*argv).get());
    adapter->set(val);
	return JS_UNDEFINED;
}



static const JSCFunctionListEntry rect2_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_center", 0, &rect2_class_get_center),
	JS_CFUNC_DEF("get_area", 0, &rect2_class_get_area),
	JS_CFUNC_DEF("has_area", 0, &rect2_class_has_area),
	JS_CFUNC_DEF("has_point", 1, &rect2_class_has_point),
	JS_CFUNC_DEF("is_equal_approx", 1, &rect2_class_is_equal_approx),
	JS_CFUNC_DEF("is_finite", 0, &rect2_class_is_finite),
	JS_CFUNC_DEF("intersects", 2, &rect2_class_intersects),
	JS_CFUNC_DEF("encloses", 1, &rect2_class_encloses),
	JS_CFUNC_DEF("intersection", 1, &rect2_class_intersection),
	JS_CFUNC_DEF("merge", 1, &rect2_class_merge),
	JS_CFUNC_DEF("expand", 1, &rect2_class_expand),
	JS_CFUNC_DEF("get_support", 1, &rect2_class_get_support),
	JS_CFUNC_DEF("grow", 1, &rect2_class_grow),
	JS_CFUNC_DEF("grow_side", 2, &rect2_class_grow_side),
	JS_CFUNC_DEF("grow_individual", 4, &rect2_class_grow_individual),
	JS_CFUNC_DEF("abs", 0, &rect2_class_abs),
};


static void define_rect2_property(JSContext *ctx, JSValue obj) {
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "position"),
			JS_NewCFunction(ctx, rect2_class_get_position, "get_position", 0),
			JS_NewCFunction(ctx, rect2_class_set_position, "set_position", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "size"),
			JS_NewCFunction(ctx, rect2_class_get_size, "get_size", 0),
			JS_NewCFunction(ctx, rect2_class_set_size, "set_size", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "end"),
			JS_NewCFunction(ctx, rect2_class_get_end, "get_end", 0),
			JS_NewCFunction(ctx, rect2_class_set_end, "set_end", 1),
			JS_PROP_GETSET);
}


static int js_rect2_class_init(JSContext *ctx) {
	JSClassID class_id = 0;
	classes["Rect2"] = JS_NewClassID(js_runtime(), &class_id);
	classes_by_id[class_id] = "Rect2";

	JS_NewClass(JS_GetRuntime(ctx), class_id, &rect2_class_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, class_id, proto);	define_rect2_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, rect2_class_proto_funcs, _countof(rect2_class_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, rect2_class_constructor, "Rect2", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "Rect2", ctor);

	JS_FreeValue(ctx, global);
	return 0;
}

static void js_init_rect2_module(JSContext *ctx) {
	js_rect2_class_init(ctx);
}

void register_rect2() {
	js_init_rect2_module(js_context());
}

// ------------------Rect2Proxy------------------
static void rect2_proxy_finalizer(JSRuntime *rt, JSValue val) {
	void *proxy = JS_GetOpaque(val, classes["Rect2Proxy"]);
	if (proxy) {
		memfree(static_cast<ObjectProxy<Rect2> *>(proxy));
	}
}

static JSClassDef rect2_proxy_def = {
	"Rect2Proxy",
	rect2_proxy_finalizer
};


static JSValue rect2_proxy_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["Rect2Proxy"];
	JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
	JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

	ObjectProxy<Rect2> *proxy;
	JSClassID opaque_id;
	// Allow constructing from an existing native pointer
	if (argc == 1 && JS_IsObject(*argv)) {
		proxy = static_cast<ObjectProxy<Rect2> *>(JS_GetAnyOpaque(*argv, &opaque_id));
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

static JSValue rect2_proxy_get_center(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Rect2Proxy"]);
    ObjectProxy<Rect2> *proxy = static_cast<ObjectProxy<Rect2> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Rect2::get_center, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue rect2_proxy_get_area(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Rect2Proxy"]);
    ObjectProxy<Rect2> *proxy = static_cast<ObjectProxy<Rect2> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Rect2::get_area, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue rect2_proxy_has_area(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Rect2Proxy"]);
    ObjectProxy<Rect2> *proxy = static_cast<ObjectProxy<Rect2> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Rect2::has_area, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue rect2_proxy_has_point(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Rect2Proxy"]);
    ObjectProxy<Rect2> *proxy = static_cast<ObjectProxy<Rect2> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Rect2::has_point, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue rect2_proxy_is_equal_approx(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Rect2Proxy"]);
    ObjectProxy<Rect2> *proxy = static_cast<ObjectProxy<Rect2> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Rect2::is_equal_approx, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue rect2_proxy_is_finite(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Rect2Proxy"]);
    ObjectProxy<Rect2> *proxy = static_cast<ObjectProxy<Rect2> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Rect2::is_finite, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue rect2_proxy_intersects(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Rect2Proxy"]);
    ObjectProxy<Rect2> *proxy = static_cast<ObjectProxy<Rect2> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Rect2::intersects, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue rect2_proxy_encloses(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Rect2Proxy"]);
    ObjectProxy<Rect2> *proxy = static_cast<ObjectProxy<Rect2> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Rect2::encloses, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue rect2_proxy_intersection(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Rect2Proxy"]);
    ObjectProxy<Rect2> *proxy = static_cast<ObjectProxy<Rect2> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Rect2::intersection, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue rect2_proxy_merge(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Rect2Proxy"]);
    ObjectProxy<Rect2> *proxy = static_cast<ObjectProxy<Rect2> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Rect2::merge, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue rect2_proxy_expand(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Rect2Proxy"]);
    ObjectProxy<Rect2> *proxy = static_cast<ObjectProxy<Rect2> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Rect2::expand, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue rect2_proxy_get_support(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Rect2Proxy"]);
    ObjectProxy<Rect2> *proxy = static_cast<ObjectProxy<Rect2> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Rect2::get_support, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue rect2_proxy_grow(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Rect2Proxy"]);
    ObjectProxy<Rect2> *proxy = static_cast<ObjectProxy<Rect2> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Rect2::grow, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue rect2_proxy_grow_side(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Rect2Proxy"]);
    ObjectProxy<Rect2> *proxy = static_cast<ObjectProxy<Rect2> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Rect2::grow_side, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue rect2_proxy_grow_individual(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Rect2Proxy"]);
    ObjectProxy<Rect2> *proxy = static_cast<ObjectProxy<Rect2> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Rect2::grow_individual, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue rect2_proxy_abs(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Rect2Proxy"]);
    ObjectProxy<Rect2> *proxy = static_cast<ObjectProxy<Rect2> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Rect2::abs, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}

static JSValue rect2_proxy_get_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Rect2Proxy"]);
    ObjectProxy<Rect2> *proxy = static_cast<ObjectProxy<Rect2> *>(opaque);
    Rect2 ret = proxy->getter();
    return VariantAdapter(ret.position);
}
static JSValue rect2_proxy_set_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Rect2Proxy"]);
    ObjectProxy<Rect2> *proxy = static_cast<ObjectProxy<Rect2> *>(opaque);
    VariantAdapter position(argv[0]);
    Rect2 wrapped = proxy->getter();
    wrapped.position = position.get();
    proxy->setter(wrapped);
	return JS_UNDEFINED;
}
static JSValue rect2_proxy_get_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Rect2Proxy"]);
    ObjectProxy<Rect2> *proxy = static_cast<ObjectProxy<Rect2> *>(opaque);
    Rect2 ret = proxy->getter();
    return VariantAdapter(ret.size);
}
static JSValue rect2_proxy_set_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Rect2Proxy"]);
    ObjectProxy<Rect2> *proxy = static_cast<ObjectProxy<Rect2> *>(opaque);
    VariantAdapter size(argv[0]);
    Rect2 wrapped = proxy->getter();
    wrapped.size = size.get();
    proxy->setter(wrapped);
	return JS_UNDEFINED;
}
static JSValue rect2_proxy_get_end(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Rect2Proxy"]);
    ObjectProxy<Rect2> *proxy = static_cast<ObjectProxy<Rect2> *>(opaque);
    Rect2 ret = proxy->getter();
    return VariantAdapter(ret.get_end());
}
static JSValue rect2_proxy_set_end(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Rect2Proxy"]);
    ObjectProxy<Rect2> *proxy = static_cast<ObjectProxy<Rect2> *>(opaque);
    VariantAdapter end(argv[0]);
    Rect2 wrapped = proxy->getter();
    wrapped.set_end(end.get());
    proxy->setter(wrapped);
	return JS_UNDEFINED;
}

static const JSCFunctionListEntry rect2_proxy_proto_funcs[] = {
	JS_CFUNC_DEF("get_center", 0, &rect2_proxy_get_center),
	JS_CFUNC_DEF("get_area", 0, &rect2_proxy_get_area),
	JS_CFUNC_DEF("has_area", 0, &rect2_proxy_has_area),
	JS_CFUNC_DEF("has_point", 1, &rect2_proxy_has_point),
	JS_CFUNC_DEF("is_equal_approx", 1, &rect2_proxy_is_equal_approx),
	JS_CFUNC_DEF("is_finite", 0, &rect2_proxy_is_finite),
	JS_CFUNC_DEF("intersects", 2, &rect2_proxy_intersects),
	JS_CFUNC_DEF("encloses", 1, &rect2_proxy_encloses),
	JS_CFUNC_DEF("intersection", 1, &rect2_proxy_intersection),
	JS_CFUNC_DEF("merge", 1, &rect2_proxy_merge),
	JS_CFUNC_DEF("expand", 1, &rect2_proxy_expand),
	JS_CFUNC_DEF("get_support", 1, &rect2_proxy_get_support),
	JS_CFUNC_DEF("grow", 1, &rect2_proxy_grow),
	JS_CFUNC_DEF("grow_side", 2, &rect2_proxy_grow_side),
	JS_CFUNC_DEF("grow_individual", 4, &rect2_proxy_grow_individual),
	JS_CFUNC_DEF("abs", 0, &rect2_proxy_abs),
};

void define_rect2_proxy_property(JSContext *ctx, JSValue obj) {
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "position"),
			JS_NewCFunction(ctx, rect2_proxy_get_position, "get_position", 0),
			JS_NewCFunction(ctx, rect2_proxy_set_position, "set_position", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "size"),
			JS_NewCFunction(ctx, rect2_proxy_get_size, "get_size", 0),
			JS_NewCFunction(ctx, rect2_proxy_set_size, "set_size", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "end"),
			JS_NewCFunction(ctx, rect2_proxy_get_end, "get_end", 0),
			JS_NewCFunction(ctx, rect2_proxy_set_end, "set_end", 1),
			JS_PROP_GETSET);
}

static int js_rect2_proxy_init(JSContext *ctx) {
	JSClassID class_id = 0;
	classes["Rect2Proxy"] = JS_NewClassID(js_runtime(), &class_id);
	classes_by_id[class_id] = "Rect2Proxy";

	JS_NewClass(JS_GetRuntime(ctx), class_id, &rect2_proxy_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, class_id, proto);
	define_rect2_proxy_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, rect2_proxy_proto_funcs, _countof(rect2_proxy_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, rect2_proxy_constructor, "Rect2Proxy", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);

	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "Rect2Proxy", ctor);

	JS_FreeValue(ctx, global);
	return 0;
}

void js_init_rect2_proxy_module(JSContext *ctx) {
	js_rect2_proxy_init(ctx);
}

void register_proxy_rect2() {
	js_init_rect2_proxy_module(js_context());
}
