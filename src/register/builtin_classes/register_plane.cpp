#include "register/builtin_classes/register_builtin_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/quickjs_helper.hpp"
#include "utils/str_helper.hpp"
#include "utils/variant_helper.hpp"
#include <quickjs.h>
#include <godot_cpp/variant/vector3.hpp>


using namespace godot;

static void plane_class_finalizer(JSRuntime *rt, JSValue val) {
	// 处于栈内存的变量不需要释放,除了对象
}

static JSClassDef plane_class_def = {
	"Plane",
	.finalizer = plane_class_finalizer
};

static JSValue plane_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["Plane"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);

	if (JS_IsException(obj)) {
		return obj;
	}
	
	Plane *instance = nullptr;
	if (argc == 0) {
		instance = memnew(Plane());
	}
	if (argc == 1&&(VariantAdapter::can_cast(argv[0],Variant::Type::PLANE))) {
		Plane v0 = VariantAdapter(argv[0]).get();
		instance = memnew(Plane(v0));
	}
	if (argc == 1&&(VariantAdapter::can_cast(argv[0],Variant::Type::VECTOR3))) {
		Vector3 v0 = VariantAdapter(argv[0]).get();
		instance = memnew(Plane(v0));
	}
	if (argc == 2&&(VariantAdapter::can_cast(argv[0],Variant::Type::VECTOR3))&&(VariantAdapter::can_cast(argv[1],Variant::Type::FLOAT))) {
		Vector3 v0 = VariantAdapter(argv[0]).get();
		double v1 = VariantAdapter(argv[1]).get();
		instance = memnew(Plane(v0, v1));
	}
	if (argc == 2&&(VariantAdapter::can_cast(argv[0],Variant::Type::VECTOR3))&&(VariantAdapter::can_cast(argv[1],Variant::Type::VECTOR3))) {
		Vector3 v0 = VariantAdapter(argv[0]).get();
		Vector3 v1 = VariantAdapter(argv[1]).get();
		instance = memnew(Plane(v0, v1));
	}
	if (argc == 3&&(VariantAdapter::can_cast(argv[0],Variant::Type::VECTOR3))&&(VariantAdapter::can_cast(argv[1],Variant::Type::VECTOR3))&&(VariantAdapter::can_cast(argv[2],Variant::Type::VECTOR3))) {
		Vector3 v0 = VariantAdapter(argv[0]).get();
		Vector3 v1 = VariantAdapter(argv[1]).get();
		Vector3 v2 = VariantAdapter(argv[2]).get();
		instance = memnew(Plane(v0, v1, v2));
	}
	if (argc == 4&&(VariantAdapter::can_cast(argv[0],Variant::Type::FLOAT))&&(VariantAdapter::can_cast(argv[1],Variant::Type::FLOAT))&&(VariantAdapter::can_cast(argv[2],Variant::Type::FLOAT))&&(VariantAdapter::can_cast(argv[3],Variant::Type::FLOAT))) {
		double v0 = VariantAdapter(argv[0]).get();
		double v1 = VariantAdapter(argv[1]).get();
		double v2 = VariantAdapter(argv[2]).get();
		double v3 = VariantAdapter(argv[3]).get();
		instance = memnew(Plane(v0, v1, v2, v3));
	}
	VariantAdapter *adapter = memnew(VariantAdapter(*instance, true));

	if (!instance || !adapter) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, adapter);
	return obj;
}
static JSValue plane_class_normalized(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Plane::normalized, ctx, this_val, argc, argv);
}
static JSValue plane_class_get_center(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Plane::get_center, ctx, this_val, argc, argv);
}
static JSValue plane_class_is_equal_approx(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Plane::is_equal_approx, ctx, this_val, argc, argv);
}
static JSValue plane_class_is_finite(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Plane::is_finite, ctx, this_val, argc, argv);
}
static JSValue plane_class_is_point_over(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Plane::is_point_over, ctx, this_val, argc, argv);
}
static JSValue plane_class_distance_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Plane::distance_to, ctx, this_val, argc, argv);
}
static JSValue plane_class_has_point(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Plane::has_point, ctx, this_val, argc, argv);
}
static JSValue plane_class_project(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Plane::project, ctx, this_val, argc, argv);
}
static JSValue plane_class_intersect_3(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Plane::intersect_3, ctx, this_val, argc, argv);
}
static JSValue plane_class_intersects_ray(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Plane::intersects_ray, ctx, this_val, argc, argv);
}
static JSValue plane_class_intersects_segment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Plane::intersects_segment, ctx, this_val, argc, argv);
}

static JSValue plane_class_get_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Plane val = reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Plane"]))->get();
	return VariantAdapter(val.normal.x);
}
static JSValue plane_class_set_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Plane val = reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Plane"]))->get();
	val.normal.x = VariantAdapter(*argv).get();
	return JS_UNDEFINED;
}
static JSValue plane_class_get_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Plane val = reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Plane"]))->get();
	return VariantAdapter(val.normal.y);
}
static JSValue plane_class_set_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Plane val = reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Plane"]))->get();
	val.normal.y = VariantAdapter(*argv).get();
	return JS_UNDEFINED;
}
static JSValue plane_class_get_z(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Plane val = reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Plane"]))->get();
	return VariantAdapter(val.normal.z);
}
static JSValue plane_class_set_z(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Plane val = reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Plane"]))->get();
	val.normal.z = VariantAdapter(*argv).get();
	return JS_UNDEFINED;
}
static JSValue plane_class_get_d(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Plane val = reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Plane"]))->get();
	return VariantAdapter(val.d);
}
static JSValue plane_class_set_d(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Plane val = reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Plane"]))->get();
	val.d = VariantAdapter(*argv).get();
	return JS_UNDEFINED;
}
static JSValue plane_class_get_normal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Plane val = reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Plane"]))->get();
	return VariantAdapter(val.normal);
}
static JSValue plane_class_set_normal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Plane val = reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Plane"]))->get();
	val.normal = VariantAdapter(*argv).get();
	return JS_UNDEFINED;
}

static const JSCFunctionListEntry plane_class_proto_funcs[] = {
	JS_CFUNC_DEF("normalized", 0, &plane_class_normalized),
	JS_CFUNC_DEF("get_center", 0, &plane_class_get_center),
	JS_CFUNC_DEF("is_equal_approx", 1, &plane_class_is_equal_approx),
	JS_CFUNC_DEF("is_finite", 0, &plane_class_is_finite),
	JS_CFUNC_DEF("is_point_over", 1, &plane_class_is_point_over),
	JS_CFUNC_DEF("distance_to", 1, &plane_class_distance_to),
	JS_CFUNC_DEF("has_point", 2, &plane_class_has_point),
	JS_CFUNC_DEF("project", 1, &plane_class_project),
	JS_CFUNC_DEF("intersect_3", 2, &plane_class_intersect_3),
	JS_CFUNC_DEF("intersects_ray", 2, &plane_class_intersects_ray),
	JS_CFUNC_DEF("intersects_segment", 2, &plane_class_intersects_segment),
};

void define_plane_property(JSContext *ctx, JSValue obj) {
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "x"),
			JS_NewCFunction(ctx, plane_class_get_x, "get_x", 0),
			JS_NewCFunction(ctx, plane_class_set_x, "set_x", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "y"),
			JS_NewCFunction(ctx, plane_class_get_y, "get_y", 0),
			JS_NewCFunction(ctx, plane_class_set_y, "set_y", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "z"),
			JS_NewCFunction(ctx, plane_class_get_z, "get_z", 0),
			JS_NewCFunction(ctx, plane_class_set_z, "set_z", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "d"),
			JS_NewCFunction(ctx, plane_class_get_d, "get_d", 0),
			JS_NewCFunction(ctx, plane_class_set_d, "set_d", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "normal"),
			JS_NewCFunction(ctx, plane_class_get_normal, "get_normal", 0),
			JS_NewCFunction(ctx, plane_class_set_normal, "set_normal", 1),
			JS_PROP_GETSET);
}

static int js_plane_class_init(JSContext *ctx) {
	JSClassID class_id = 0;
	classes["Plane"] = JS_NewClassID(&class_id);
	classes_by_id[class_id] = "Plane";

	JS_NewClass(JS_GetRuntime(ctx), class_id, &plane_class_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, class_id, proto);	define_plane_property(ctx, proto);	JS_SetPropertyFunctionList(ctx, proto, plane_class_proto_funcs, _countof(plane_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, plane_class_constructor, "Plane", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);

	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "Plane", ctor);

	return 0;
}

void js_init_plane_module(JSContext *ctx) {
	js_plane_class_init(ctx);
}

void register_plane() {
	js_init_plane_module(js_context());
}

// ------------------PlaneProxy------------------
static void plane_proxy_finalizer(JSRuntime *rt, JSValue val) {
	void *proxy = JS_GetOpaque(val, classes["PlaneProxy"]);
	if (proxy) {
		memfree(static_cast<ObjectProxy<Plane> *>(proxy));
	}
}

static JSClassDef plane_proxy_def = {
	"PlaneProxy",
	.finalizer = plane_proxy_finalizer
};


static JSValue plane_proxy_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["PlaneProxy"];
	JSValue proto = JS_GetPropertyStr(js_context(), new_target, "prototype");
	JSValue obj = JS_NewObjectProtoClass(js_context(), proto, class_id);
	if (is_exception(js_context(), obj)) {
		return obj;
	}

	ObjectProxy<Plane> *proxy;
	JSClassID opaque_id;
	// Allow constructing from an existing native pointer
	if (argc == 1 && JS_IsObject(*argv)) {
		proxy = static_cast<ObjectProxy<Plane> *>(JS_GetAnyOpaque(*argv, &opaque_id));
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

static JSValue plane_proxy_normalized(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["PlaneProxy"]);
    ObjectProxy<Plane> *proxy = reinterpret_cast<ObjectProxy<Plane> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Plane::normalized, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue plane_proxy_get_center(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["PlaneProxy"]);
    ObjectProxy<Plane> *proxy = reinterpret_cast<ObjectProxy<Plane> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Plane::get_center, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue plane_proxy_is_equal_approx(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["PlaneProxy"]);
    ObjectProxy<Plane> *proxy = reinterpret_cast<ObjectProxy<Plane> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Plane::is_equal_approx, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue plane_proxy_is_finite(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["PlaneProxy"]);
    ObjectProxy<Plane> *proxy = reinterpret_cast<ObjectProxy<Plane> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Plane::is_finite, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue plane_proxy_is_point_over(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["PlaneProxy"]);
    ObjectProxy<Plane> *proxy = reinterpret_cast<ObjectProxy<Plane> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Plane::is_point_over, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue plane_proxy_distance_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["PlaneProxy"]);
    ObjectProxy<Plane> *proxy = reinterpret_cast<ObjectProxy<Plane> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Plane::distance_to, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue plane_proxy_has_point(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["PlaneProxy"]);
    ObjectProxy<Plane> *proxy = reinterpret_cast<ObjectProxy<Plane> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Plane::has_point, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue plane_proxy_project(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["PlaneProxy"]);
    ObjectProxy<Plane> *proxy = reinterpret_cast<ObjectProxy<Plane> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Plane::project, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue plane_proxy_intersect_3(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["PlaneProxy"]);
    ObjectProxy<Plane> *proxy = reinterpret_cast<ObjectProxy<Plane> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Plane::intersect_3, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue plane_proxy_intersects_ray(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["PlaneProxy"]);
    ObjectProxy<Plane> *proxy = reinterpret_cast<ObjectProxy<Plane> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Plane::intersects_ray, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue plane_proxy_intersects_segment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["PlaneProxy"]);
    ObjectProxy<Plane> *proxy = reinterpret_cast<ObjectProxy<Plane> *>(opaque);
    Object *wrapped = reinterpret_cast<Object *>(proxy->wrapped);
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Plane::intersects_segment, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}

static JSValue plane_proxy_get_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["PlaneProxy"]);
    ObjectProxy<Plane> *proxy = reinterpret_cast<ObjectProxy<Plane> *>(opaque);
    Plane ret = proxy->getter();
    return VariantAdapter(ret.normal.x);
}
static JSValue plane_proxy_set_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["PlaneProxy"]);
    ObjectProxy<Plane> *proxy = reinterpret_cast<ObjectProxy<Plane> *>(opaque);
    VariantAdapter x(argv[0]);
    Plane wrapped = proxy->getter();
    wrapped.normal.x = x.get();
    proxy->setter(wrapped);
	return JS_UNDEFINED;
}
static JSValue plane_proxy_get_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["PlaneProxy"]);
    ObjectProxy<Plane> *proxy = reinterpret_cast<ObjectProxy<Plane> *>(opaque);
    Plane ret = proxy->getter();
    return VariantAdapter(ret.normal.y);
}
static JSValue plane_proxy_set_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["PlaneProxy"]);
    ObjectProxy<Plane> *proxy = reinterpret_cast<ObjectProxy<Plane> *>(opaque);
    VariantAdapter y(argv[0]);
    Plane wrapped = proxy->getter();
    wrapped.normal.y = y.get();
    proxy->setter(wrapped);
	return JS_UNDEFINED;
}
static JSValue plane_proxy_get_z(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["PlaneProxy"]);
    ObjectProxy<Plane> *proxy = reinterpret_cast<ObjectProxy<Plane> *>(opaque);
    Plane ret = proxy->getter();
    return VariantAdapter(ret.normal.z);
}
static JSValue plane_proxy_set_z(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["PlaneProxy"]);
    ObjectProxy<Plane> *proxy = reinterpret_cast<ObjectProxy<Plane> *>(opaque);
    VariantAdapter z(argv[0]);
    Plane wrapped = proxy->getter();
    wrapped.normal.z = z.get();
    proxy->setter(wrapped);
	return JS_UNDEFINED;
}
static JSValue plane_proxy_get_d(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["PlaneProxy"]);
    ObjectProxy<Plane> *proxy = reinterpret_cast<ObjectProxy<Plane> *>(opaque);
    Plane ret = proxy->getter();
    return VariantAdapter(ret.d);
}
static JSValue plane_proxy_set_d(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["PlaneProxy"]);
    ObjectProxy<Plane> *proxy = reinterpret_cast<ObjectProxy<Plane> *>(opaque);
    VariantAdapter d(argv[0]);
    Plane wrapped = proxy->getter();
    wrapped.d = d.get();
    proxy->setter(wrapped);
	return JS_UNDEFINED;
}
static JSValue plane_proxy_get_normal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["PlaneProxy"]);
    ObjectProxy<Plane> *proxy = reinterpret_cast<ObjectProxy<Plane> *>(opaque);
    Plane ret = proxy->getter();
    return VariantAdapter(ret.normal);
}
static JSValue plane_proxy_set_normal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["PlaneProxy"]);
    ObjectProxy<Plane> *proxy = reinterpret_cast<ObjectProxy<Plane> *>(opaque);
    VariantAdapter normal(argv[0]);
    Plane wrapped = proxy->getter();
    wrapped.normal = normal.get();
    proxy->setter(wrapped);
	return JS_UNDEFINED;
}

static const JSCFunctionListEntry plane_proxy_proto_funcs[] = {
	JS_CFUNC_DEF("normalized", 0, &plane_proxy_normalized),
	JS_CFUNC_DEF("get_center", 0, &plane_proxy_get_center),
	JS_CFUNC_DEF("is_equal_approx", 1, &plane_proxy_is_equal_approx),
	JS_CFUNC_DEF("is_finite", 0, &plane_proxy_is_finite),
	JS_CFUNC_DEF("is_point_over", 1, &plane_proxy_is_point_over),
	JS_CFUNC_DEF("distance_to", 1, &plane_proxy_distance_to),
	JS_CFUNC_DEF("has_point", 2, &plane_proxy_has_point),
	JS_CFUNC_DEF("project", 1, &plane_proxy_project),
	JS_CFUNC_DEF("intersect_3", 2, &plane_proxy_intersect_3),
	JS_CFUNC_DEF("intersects_ray", 2, &plane_proxy_intersects_ray),
	JS_CFUNC_DEF("intersects_segment", 2, &plane_proxy_intersects_segment),
};

void define_plane_proxy_property(JSContext *ctx, JSValue obj) {
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "x"),
			JS_NewCFunction(ctx, plane_proxy_get_x, "get_x", 0),
			JS_NewCFunction(ctx, plane_proxy_set_x, "set_x", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "y"),
			JS_NewCFunction(ctx, plane_proxy_get_y, "get_y", 0),
			JS_NewCFunction(ctx, plane_proxy_set_y, "set_y", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "z"),
			JS_NewCFunction(ctx, plane_proxy_get_z, "get_z", 0),
			JS_NewCFunction(ctx, plane_proxy_set_z, "set_z", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "d"),
			JS_NewCFunction(ctx, plane_proxy_get_d, "get_d", 0),
			JS_NewCFunction(ctx, plane_proxy_set_d, "set_d", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "normal"),
			JS_NewCFunction(ctx, plane_proxy_get_normal, "get_normal", 0),
			JS_NewCFunction(ctx, plane_proxy_set_normal, "set_normal", 1),
			JS_PROP_GETSET);
}

static int js_plane_proxy_init(JSContext *ctx) {
	JSClassID class_id = 0;
	classes["PlaneProxy"] = JS_NewClassID(&class_id);
	classes_by_id[class_id] = "PlaneProxy";

	JS_NewClass(JS_GetRuntime(ctx), class_id, &plane_proxy_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, class_id, proto);
	define_plane_proxy_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, plane_proxy_proto_funcs, _countof(plane_proxy_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, plane_proxy_constructor, "PlaneProxy", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);

	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "PlaneProxy", ctor);

	return 0;
}

void js_init_plane_proxy_module(JSContext *ctx) {
	js_plane_proxy_init(ctx);
}

void register_proxy_plane() {
	js_init_plane_proxy_module(js_context());
}