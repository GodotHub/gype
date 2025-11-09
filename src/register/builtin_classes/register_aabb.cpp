#include "register/builtin_classes/register_builtin_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/quickjs_helper.hpp"
#include "utils/str_helper.hpp"
#include "utils/variant_helper.hpp"
#include <quickjs.h>
#include <godot_cpp/variant/plane.hpp>
#include <godot_cpp/variant/vector3.hpp>

using namespace godot;

static void aabb_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["AABB"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memfree(opaque_ptr);
	}
}

static JSClassDef aabb_class_def = {
	"AABB",
	.finalizer = aabb_class_finalizer
};

static JSValue aabb_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["AABB"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);

	if (JS_IsException(obj)) {
		return obj;
	}

	AABB instance;
	if (argc == 0) {
		instance = AABB();
	}
	if (argc == 1 && (VariantAdapter::can_cast(argv[0], Variant::Type::AABB))) {
		AABB v0 = VariantAdapter(argv[0]).get();
		instance = AABB(v0);
	}
	if (argc == 2 && (VariantAdapter::can_cast(argv[0], Variant::Type::VECTOR3)) && (VariantAdapter::can_cast(argv[1], Variant::Type::VECTOR3))) {
		Vector3 v0 = VariantAdapter(argv[0]).get();
		Vector3 v1 = VariantAdapter(argv[1]).get();
		instance = AABB(v0, v1);
	}
	VariantAdapter *adapter = memnew(VariantAdapter(instance, true));

	if (!adapter) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, adapter);
	return obj;
}
static JSValue aabb_class_abs(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&AABB::abs, ctx, this_val, argc, argv);
}
static JSValue aabb_class_get_center(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&AABB::get_center, ctx, this_val, argc, argv);
}
static JSValue aabb_class_get_volume(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&AABB::get_volume, ctx, this_val, argc, argv);
}
static JSValue aabb_class_has_volume(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&AABB::has_volume, ctx, this_val, argc, argv);
}
static JSValue aabb_class_has_surface(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&AABB::has_surface, ctx, this_val, argc, argv);
}
static JSValue aabb_class_has_point(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&AABB::has_point, ctx, this_val, argc, argv);
}
static JSValue aabb_class_is_equal_approx(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&AABB::is_equal_approx, ctx, this_val, argc, argv);
}
static JSValue aabb_class_is_finite(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&AABB::is_finite, ctx, this_val, argc, argv);
}
static JSValue aabb_class_intersects(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&AABB::intersects, ctx, this_val, argc, argv);
}
static JSValue aabb_class_encloses(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&AABB::encloses, ctx, this_val, argc, argv);
}
static JSValue aabb_class_intersects_plane(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&AABB::intersects_plane, ctx, this_val, argc, argv);
}
static JSValue aabb_class_intersection(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&AABB::intersection, ctx, this_val, argc, argv);
}
static JSValue aabb_class_merge(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&AABB::merge, ctx, this_val, argc, argv);
}
static JSValue aabb_class_expand(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&AABB::expand, ctx, this_val, argc, argv);
}
static JSValue aabb_class_grow(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&AABB::grow, ctx, this_val, argc, argv);
}
static JSValue aabb_class_get_support(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&AABB::get_support, ctx, this_val, argc, argv);
}
static JSValue aabb_class_get_longest_axis(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&AABB::get_longest_axis, ctx, this_val, argc, argv);
}
static JSValue aabb_class_get_longest_axis_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&AABB::get_longest_axis_index, ctx, this_val, argc, argv);
}
static JSValue aabb_class_get_longest_axis_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&AABB::get_longest_axis_size, ctx, this_val, argc, argv);
}
static JSValue aabb_class_get_shortest_axis(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&AABB::get_shortest_axis, ctx, this_val, argc, argv);
}
static JSValue aabb_class_get_shortest_axis_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&AABB::get_shortest_axis_index, ctx, this_val, argc, argv);
}
static JSValue aabb_class_get_shortest_axis_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&AABB::get_shortest_axis_size, ctx, this_val, argc, argv);
}
static JSValue aabb_class_get_endpoint(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&AABB::get_endpoint, ctx, this_val, argc, argv);
}
static JSValue aabb_class_intersects_segment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&AABB::intersects_segment_bind, ctx, this_val, argc, argv);
}
static JSValue aabb_class_intersects_ray(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&AABB::intersects_ray_bind, ctx, this_val, argc, argv);
}

static JSValue aabb_class_get_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	AABB val = reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["AABB"]))->get();
	return VariantAdapter(val.position);
}
static JSValue aabb_class_set_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	AABB val = reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["AABB"]))->get();
	val.position = VariantAdapter(*argv).get();
	return JS_UNDEFINED;
}
static JSValue aabb_class_get_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	AABB val = reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["AABB"]))->get();
	return VariantAdapter(val.size);
}
static JSValue aabb_class_set_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	AABB val = reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["AABB"]))->get();
	val.size = VariantAdapter(*argv).get();
	return JS_UNDEFINED;
}
static JSValue aabb_class_get_end(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	AABB val = reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["AABB"]))->get();
	return VariantAdapter(val.get_end());
}
static JSValue aabb_class_set_end(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	AABB val = reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["AABB"]))->get();
	val.set_end(VariantAdapter(*argv).get());
	return JS_UNDEFINED;
}

static const JSCFunctionListEntry aabb_class_proto_funcs[] = {
	JS_CFUNC_DEF("abs", 0, &aabb_class_abs),
	JS_CFUNC_DEF("get_center", 0, &aabb_class_get_center),
	JS_CFUNC_DEF("get_volume", 0, &aabb_class_get_volume),
	JS_CFUNC_DEF("has_volume", 0, &aabb_class_has_volume),
	JS_CFUNC_DEF("has_surface", 0, &aabb_class_has_surface),
	JS_CFUNC_DEF("has_point", 1, &aabb_class_has_point),
	JS_CFUNC_DEF("is_equal_approx", 1, &aabb_class_is_equal_approx),
	JS_CFUNC_DEF("is_finite", 0, &aabb_class_is_finite),
	JS_CFUNC_DEF("intersects", 1, &aabb_class_intersects),
	JS_CFUNC_DEF("encloses", 1, &aabb_class_encloses),
	JS_CFUNC_DEF("intersects_plane", 1, &aabb_class_intersects_plane),
	JS_CFUNC_DEF("intersection", 1, &aabb_class_intersection),
	JS_CFUNC_DEF("merge", 1, &aabb_class_merge),
	JS_CFUNC_DEF("expand", 1, &aabb_class_expand),
	JS_CFUNC_DEF("grow", 1, &aabb_class_grow),
	JS_CFUNC_DEF("get_support", 1, &aabb_class_get_support),
	JS_CFUNC_DEF("get_longest_axis", 0, &aabb_class_get_longest_axis),
	JS_CFUNC_DEF("get_longest_axis_index", 0, &aabb_class_get_longest_axis_index),
	JS_CFUNC_DEF("get_longest_axis_size", 0, &aabb_class_get_longest_axis_size),
	JS_CFUNC_DEF("get_shortest_axis", 0, &aabb_class_get_shortest_axis),
	JS_CFUNC_DEF("get_shortest_axis_index", 0, &aabb_class_get_shortest_axis_index),
	JS_CFUNC_DEF("get_shortest_axis_size", 0, &aabb_class_get_shortest_axis_size),
	JS_CFUNC_DEF("get_endpoint", 1, &aabb_class_get_endpoint),
	JS_CFUNC_DEF("intersects_segment", 2, &aabb_class_intersects_segment),
	JS_CFUNC_DEF("intersects_ray", 2, &aabb_class_intersects_ray),
};

void define_aabb_property(JSContext *ctx, JSValue obj) {
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "position"),
			JS_NewCFunction(ctx, aabb_class_get_position, "get_position", 0),
			JS_NewCFunction(ctx, aabb_class_set_position, "set_position", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "size"),
			JS_NewCFunction(ctx, aabb_class_get_size, "get_size", 0),
			JS_NewCFunction(ctx, aabb_class_set_size, "set_size", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "end"),
			JS_NewCFunction(ctx, aabb_class_get_end, "get_end", 0),
			JS_NewCFunction(ctx, aabb_class_set_end, "set_end", 1),
			JS_PROP_GETSET);
}

static int js_aabb_class_init(JSContext *ctx) {
	JSClassID class_id = 0;
	classes["AABB"] = JS_NewClassID(&class_id);
	classes_by_id[class_id] = "AABB";

	JS_NewClass(JS_GetRuntime(ctx), class_id, &aabb_class_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, class_id, proto);
	define_aabb_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, aabb_class_proto_funcs, _countof(aabb_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, aabb_class_constructor, "AABB", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);

	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "AABB", ctor);

	return 0;
}

void js_init_aabb_module(JSContext *ctx) {
	js_aabb_class_init(ctx);
}

void register_aabb() {
	js_init_aabb_module(js_context());
}

// ------------------AABBProxy------------------
static void aabb_proxy_finalizer(JSRuntime *rt, JSValue val) {
	void *proxy = JS_GetOpaque(val, classes["AABBProxy"]);
	if (proxy) {
		memfree(static_cast<ObjectProxy<AABB> *>(proxy));
	}
}

static JSClassDef aabb_proxy_def = {
	"AABBProxy",
	.finalizer = aabb_proxy_finalizer
};

static JSValue aabb_proxy_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["AABBProxy"];
	JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
	JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

	ObjectProxy<AABB> *proxy;
	JSClassID opaque_id;
	// Allow constructing from an existing native pointer
	if (argc == 1 && JS_IsObject(*argv)) {
		proxy = static_cast<ObjectProxy<AABB> *>(JS_GetAnyOpaque(*argv, &opaque_id));
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

static JSValue aabb_proxy_abs(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["AABBProxy"]);
	ObjectProxy<AABB> *proxy = reinterpret_cast<ObjectProxy<AABB> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&AABB::abs, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}
static JSValue aabb_proxy_get_center(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["AABBProxy"]);
	ObjectProxy<AABB> *proxy = reinterpret_cast<ObjectProxy<AABB> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&AABB::get_center, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}
static JSValue aabb_proxy_get_volume(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["AABBProxy"]);
	ObjectProxy<AABB> *proxy = reinterpret_cast<ObjectProxy<AABB> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&AABB::get_volume, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}
static JSValue aabb_proxy_has_volume(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["AABBProxy"]);
	ObjectProxy<AABB> *proxy = reinterpret_cast<ObjectProxy<AABB> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&AABB::has_volume, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}
static JSValue aabb_proxy_has_surface(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["AABBProxy"]);
	ObjectProxy<AABB> *proxy = reinterpret_cast<ObjectProxy<AABB> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&AABB::has_surface, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}
static JSValue aabb_proxy_has_point(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["AABBProxy"]);
	ObjectProxy<AABB> *proxy = reinterpret_cast<ObjectProxy<AABB> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&AABB::has_point, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}
static JSValue aabb_proxy_is_equal_approx(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["AABBProxy"]);
	ObjectProxy<AABB> *proxy = reinterpret_cast<ObjectProxy<AABB> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&AABB::is_equal_approx, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}
static JSValue aabb_proxy_is_finite(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["AABBProxy"]);
	ObjectProxy<AABB> *proxy = reinterpret_cast<ObjectProxy<AABB> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&AABB::is_finite, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}
static JSValue aabb_proxy_intersects(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["AABBProxy"]);
	ObjectProxy<AABB> *proxy = reinterpret_cast<ObjectProxy<AABB> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&AABB::intersects, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}
static JSValue aabb_proxy_encloses(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["AABBProxy"]);
	ObjectProxy<AABB> *proxy = reinterpret_cast<ObjectProxy<AABB> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&AABB::encloses, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}
static JSValue aabb_proxy_intersects_plane(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["AABBProxy"]);
	ObjectProxy<AABB> *proxy = reinterpret_cast<ObjectProxy<AABB> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&AABB::intersects_plane, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}
static JSValue aabb_proxy_intersection(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["AABBProxy"]);
	ObjectProxy<AABB> *proxy = reinterpret_cast<ObjectProxy<AABB> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&AABB::intersection, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}
static JSValue aabb_proxy_merge(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["AABBProxy"]);
	ObjectProxy<AABB> *proxy = reinterpret_cast<ObjectProxy<AABB> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&AABB::merge, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}
static JSValue aabb_proxy_expand(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["AABBProxy"]);
	ObjectProxy<AABB> *proxy = reinterpret_cast<ObjectProxy<AABB> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&AABB::expand, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}
static JSValue aabb_proxy_grow(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["AABBProxy"]);
	ObjectProxy<AABB> *proxy = reinterpret_cast<ObjectProxy<AABB> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&AABB::grow, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}
static JSValue aabb_proxy_get_support(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["AABBProxy"]);
	ObjectProxy<AABB> *proxy = reinterpret_cast<ObjectProxy<AABB> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&AABB::get_support, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}
static JSValue aabb_proxy_get_longest_axis(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["AABBProxy"]);
	ObjectProxy<AABB> *proxy = reinterpret_cast<ObjectProxy<AABB> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&AABB::get_longest_axis, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}
static JSValue aabb_proxy_get_longest_axis_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["AABBProxy"]);
	ObjectProxy<AABB> *proxy = reinterpret_cast<ObjectProxy<AABB> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&AABB::get_longest_axis_index, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}
static JSValue aabb_proxy_get_longest_axis_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["AABBProxy"]);
	ObjectProxy<AABB> *proxy = reinterpret_cast<ObjectProxy<AABB> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&AABB::get_longest_axis_size, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}
static JSValue aabb_proxy_get_shortest_axis(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["AABBProxy"]);
	ObjectProxy<AABB> *proxy = reinterpret_cast<ObjectProxy<AABB> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&AABB::get_shortest_axis, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}
static JSValue aabb_proxy_get_shortest_axis_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["AABBProxy"]);
	ObjectProxy<AABB> *proxy = reinterpret_cast<ObjectProxy<AABB> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&AABB::get_shortest_axis_index, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}
static JSValue aabb_proxy_get_shortest_axis_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["AABBProxy"]);
	ObjectProxy<AABB> *proxy = reinterpret_cast<ObjectProxy<AABB> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&AABB::get_shortest_axis_size, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}
static JSValue aabb_proxy_get_endpoint(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["AABBProxy"]);
	ObjectProxy<AABB> *proxy = reinterpret_cast<ObjectProxy<AABB> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&AABB::get_endpoint, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}
static JSValue aabb_proxy_intersects_segment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["AABBProxy"]);
	ObjectProxy<AABB> *proxy = reinterpret_cast<ObjectProxy<AABB> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&AABB::intersects_segment_bind, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}
static JSValue aabb_proxy_intersects_ray(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["AABBProxy"]);
	ObjectProxy<AABB> *proxy = reinterpret_cast<ObjectProxy<AABB> *>(opaque);
	Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
	this_val = VariantAdapter(wrapped);
	JSValue ret = call_builtin_const_method_ret(&AABB::intersects_ray_bind, ctx, this_val, argc, argv);
	JS_FreeValue(ctx, this_val);
	return ret;
}

static JSValue aabb_proxy_get_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["AABBProxy"]);
	ObjectProxy<AABB> *proxy = reinterpret_cast<ObjectProxy<AABB> *>(opaque);
	AABB ret = proxy->getter();
	return VariantAdapter(ret.position);
}
static JSValue aabb_proxy_set_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["AABBProxy"]);
	ObjectProxy<AABB> *proxy = reinterpret_cast<ObjectProxy<AABB> *>(opaque);
	VariantAdapter position(argv[0]);
	AABB wrapped = proxy->getter();
	wrapped.position = position.get();
	proxy->setter(wrapped);
	return JS_UNDEFINED;
}
static JSValue aabb_proxy_get_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["AABBProxy"]);
	ObjectProxy<AABB> *proxy = reinterpret_cast<ObjectProxy<AABB> *>(opaque);
	AABB ret = proxy->getter();
	return VariantAdapter(ret.size);
}
static JSValue aabb_proxy_set_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["AABBProxy"]);
	ObjectProxy<AABB> *proxy = reinterpret_cast<ObjectProxy<AABB> *>(opaque);
	VariantAdapter size(argv[0]);
	AABB wrapped = proxy->getter();
	wrapped.size = size.get();
	proxy->setter(wrapped);
	return JS_UNDEFINED;
}
static JSValue aabb_proxy_get_end(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["AABBProxy"]);
	ObjectProxy<AABB> *proxy = reinterpret_cast<ObjectProxy<AABB> *>(opaque);
	AABB ret = proxy->getter();
	return VariantAdapter(ret.get_end());
}
static JSValue aabb_proxy_set_end(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["AABBProxy"]);
	ObjectProxy<AABB> *proxy = reinterpret_cast<ObjectProxy<AABB> *>(opaque);
	VariantAdapter end(argv[0]);
	AABB wrapped = proxy->getter();
	wrapped.set_end(end.get());
	proxy->setter(wrapped);
	return JS_UNDEFINED;
}

static const JSCFunctionListEntry aabb_proxy_proto_funcs[] = {
	JS_CFUNC_DEF("abs", 0, &aabb_proxy_abs),
	JS_CFUNC_DEF("get_center", 0, &aabb_proxy_get_center),
	JS_CFUNC_DEF("get_volume", 0, &aabb_proxy_get_volume),
	JS_CFUNC_DEF("has_volume", 0, &aabb_proxy_has_volume),
	JS_CFUNC_DEF("has_surface", 0, &aabb_proxy_has_surface),
	JS_CFUNC_DEF("has_point", 1, &aabb_proxy_has_point),
	JS_CFUNC_DEF("is_equal_approx", 1, &aabb_proxy_is_equal_approx),
	JS_CFUNC_DEF("is_finite", 0, &aabb_proxy_is_finite),
	JS_CFUNC_DEF("intersects", 1, &aabb_proxy_intersects),
	JS_CFUNC_DEF("encloses", 1, &aabb_proxy_encloses),
	JS_CFUNC_DEF("intersects_plane", 1, &aabb_proxy_intersects_plane),
	JS_CFUNC_DEF("intersection", 1, &aabb_proxy_intersection),
	JS_CFUNC_DEF("merge", 1, &aabb_proxy_merge),
	JS_CFUNC_DEF("expand", 1, &aabb_proxy_expand),
	JS_CFUNC_DEF("grow", 1, &aabb_proxy_grow),
	JS_CFUNC_DEF("get_support", 1, &aabb_proxy_get_support),
	JS_CFUNC_DEF("get_longest_axis", 0, &aabb_proxy_get_longest_axis),
	JS_CFUNC_DEF("get_longest_axis_index", 0, &aabb_proxy_get_longest_axis_index),
	JS_CFUNC_DEF("get_longest_axis_size", 0, &aabb_proxy_get_longest_axis_size),
	JS_CFUNC_DEF("get_shortest_axis", 0, &aabb_proxy_get_shortest_axis),
	JS_CFUNC_DEF("get_shortest_axis_index", 0, &aabb_proxy_get_shortest_axis_index),
	JS_CFUNC_DEF("get_shortest_axis_size", 0, &aabb_proxy_get_shortest_axis_size),
	JS_CFUNC_DEF("get_endpoint", 1, &aabb_proxy_get_endpoint),
	JS_CFUNC_DEF("intersects_segment", 2, &aabb_proxy_intersects_segment),
	JS_CFUNC_DEF("intersects_ray", 2, &aabb_proxy_intersects_ray),
};

void define_aabb_proxy_property(JSContext *ctx, JSValue obj) {
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "position"),
			JS_NewCFunction(ctx, aabb_proxy_get_position, "get_position", 0),
			JS_NewCFunction(ctx, aabb_proxy_set_position, "set_position", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "size"),
			JS_NewCFunction(ctx, aabb_proxy_get_size, "get_size", 0),
			JS_NewCFunction(ctx, aabb_proxy_set_size, "set_size", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "end"),
			JS_NewCFunction(ctx, aabb_proxy_get_end, "get_end", 0),
			JS_NewCFunction(ctx, aabb_proxy_set_end, "set_end", 1),
			JS_PROP_GETSET);
}

static int js_aabb_proxy_init(JSContext *ctx) {
	JSClassID class_id = 0;
	classes["AABBProxy"] = JS_NewClassID(&class_id);
	classes_by_id[class_id] = "AABBProxy";

	JS_NewClass(JS_GetRuntime(ctx), class_id, &aabb_proxy_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, class_id, proto);
	define_aabb_proxy_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, aabb_proxy_proto_funcs, _countof(aabb_proxy_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, aabb_proxy_constructor, "AABBProxy", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);

	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "AABBProxy", ctor);

	return 0;
}

void js_init_aabb_proxy_module(JSContext *ctx) {
	js_aabb_proxy_init(ctx);
}

void register_proxy_aabb() {
	js_init_aabb_proxy_module(js_context());
}