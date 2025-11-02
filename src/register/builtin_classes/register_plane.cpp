#include "register/builtin_classes/register_builtin_classes.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/quickjs_helper.hpp"
#include "utils/str_helper.hpp"
#include "utils/variant_helper.hpp"
#include <quickjs.h>
#include <godot_cpp/variant/vector3.hpp>

using namespace godot;

static void plane_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes[typeid(Plane)];
	GDVariantAdapter<Plane> *opaque_ptr = static_cast<GDVariantAdapter<Plane> *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr && opaque_ptr->can_memfree) {
		memfree(const_cast<Plane *>(opaque_ptr->m_active_variant));
	}
}

static JSClassDef plane_class_def = {
	"Plane",
	.finalizer = plane_class_finalizer
};

static JSValue plane_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes[typeid(Plane)];
	JSValue obj = JS_NewObjectClass(ctx, class_id);
	if (JS_IsException(obj)) {
		return obj;
	}
	
	Plane *instance = nullptr;
	GDVariantAdapter<Plane> *adapter = reinterpret_cast<GDVariantAdapter<Plane> *>(memalloc(sizeof(GDVariantAdapter<Plane>)));
	if (argc == 0) {
		instance = reinterpret_cast<Plane *>(memalloc(sizeof(Plane)));
		instance = new (instance) Plane();
	}
	if (argc == 1&&(JSValueAdapter<Plane>::can_cast(argv[0]))) {
		Plane v0 = *JSValueAdapter<Plane>(argv[0]).get();
		instance = reinterpret_cast<Plane *>(memalloc(sizeof(Plane)));
		instance = new (instance) Plane(v0);
	}
	if (argc == 1&&(JSValueAdapter<Vector3>::can_cast(argv[0]))) {
		Vector3 v0 = *JSValueAdapter<Vector3>(argv[0]).get();
		instance = reinterpret_cast<Plane *>(memalloc(sizeof(Plane)));
		instance = new (instance) Plane(v0);
	}
	if (argc == 2&&(JSValueAdapter<Vector3>::can_cast(argv[0]))&&(JSValueAdapter<float>::can_cast(argv[1]))) {
		Vector3 v0 = *JSValueAdapter<Vector3>(argv[0]).get();
		float v1 = *JSValueAdapter<float>(argv[1]).get();
		instance = reinterpret_cast<Plane *>(memalloc(sizeof(Plane)));
		instance = new (instance) Plane(v0, v1);
	}
	if (argc == 2&&(JSValueAdapter<Vector3>::can_cast(argv[0]))&&(JSValueAdapter<Vector3>::can_cast(argv[1]))) {
		Vector3 v0 = *JSValueAdapter<Vector3>(argv[0]).get();
		Vector3 v1 = *JSValueAdapter<Vector3>(argv[1]).get();
		instance = reinterpret_cast<Plane *>(memalloc(sizeof(Plane)));
		instance = new (instance) Plane(v0, v1);
	}
	if (argc == 3&&(JSValueAdapter<Vector3>::can_cast(argv[0]))&&(JSValueAdapter<Vector3>::can_cast(argv[1]))&&(JSValueAdapter<Vector3>::can_cast(argv[2]))) {
		Vector3 v0 = *JSValueAdapter<Vector3>(argv[0]).get();
		Vector3 v1 = *JSValueAdapter<Vector3>(argv[1]).get();
		Vector3 v2 = *JSValueAdapter<Vector3>(argv[2]).get();
		instance = reinterpret_cast<Plane *>(memalloc(sizeof(Plane)));
		instance = new (instance) Plane(v0, v1, v2);
	}
	if (argc == 4&&(JSValueAdapter<float>::can_cast(argv[0]))&&(JSValueAdapter<float>::can_cast(argv[1]))&&(JSValueAdapter<float>::can_cast(argv[2]))&&(JSValueAdapter<float>::can_cast(argv[3]))) {
		float v0 = *JSValueAdapter<float>(argv[0]).get();
		float v1 = *JSValueAdapter<float>(argv[1]).get();
		float v2 = *JSValueAdapter<float>(argv[2]).get();
		float v3 = *JSValueAdapter<float>(argv[3]).get();
		instance = reinterpret_cast<Plane *>(memalloc(sizeof(Plane)));
		instance = new (instance) Plane(v0, v1, v2, v3);
	}
	adapter = new (adapter) GDVariantAdapter<Plane>(*instance, true);

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
	Plane &val = *reinterpret_cast<Plane *>(JS_GetOpaque(this_val, classes[typeid(Plane)]));
	return GDVariantAdapter<float>(val.normal.x);
}
static JSValue plane_class_set_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Plane &val = *reinterpret_cast<Plane *>(JS_GetOpaque(this_val, classes[typeid(Plane)]));
	val.normal.x = *JSValueAdapter<float>(*argv).get();
	return JS_UNDEFINED;
}
static JSValue plane_class_get_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Plane &val = *reinterpret_cast<Plane *>(JS_GetOpaque(this_val, classes[typeid(Plane)]));
	return GDVariantAdapter<float>(val.normal.y);
}
static JSValue plane_class_set_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Plane &val = *reinterpret_cast<Plane *>(JS_GetOpaque(this_val, classes[typeid(Plane)]));
	val.normal.y = *JSValueAdapter<float>(*argv).get();
	return JS_UNDEFINED;
}
static JSValue plane_class_get_z(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Plane &val = *reinterpret_cast<Plane *>(JS_GetOpaque(this_val, classes[typeid(Plane)]));
	return GDVariantAdapter<float>(val.normal.z);
}
static JSValue plane_class_set_z(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Plane &val = *reinterpret_cast<Plane *>(JS_GetOpaque(this_val, classes[typeid(Plane)]));
	val.normal.z = *JSValueAdapter<float>(*argv).get();
	return JS_UNDEFINED;
}
static JSValue plane_class_get_d(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Plane &val = *reinterpret_cast<Plane *>(JS_GetOpaque(this_val, classes[typeid(Plane)]));
	return GDVariantAdapter<float>(val.d);
}
static JSValue plane_class_set_d(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Plane &val = *reinterpret_cast<Plane *>(JS_GetOpaque(this_val, classes[typeid(Plane)]));
	val.d = *JSValueAdapter<float>(*argv).get();
	return JS_UNDEFINED;
}
static JSValue plane_class_get_normal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Plane &val = *reinterpret_cast<Plane *>(JS_GetOpaque(this_val, classes[typeid(Plane)]));
	return GDVariantAdapter<Vector3>(val.normal);
}
static JSValue plane_class_set_normal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Plane &val = *reinterpret_cast<Plane *>(JS_GetOpaque(this_val, classes[typeid(Plane)]));
	val.normal = *JSValueAdapter<Vector3>(*argv).get();
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
	JSClassID class_id = JS_NewClassID(&classes[typeid(Plane)]);

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