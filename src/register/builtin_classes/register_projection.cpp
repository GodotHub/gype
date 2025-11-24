#include "register/builtin_classes/register_builtin_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/quickjs_helper.hpp"
#include "utils/str_helper.hpp"
#include "utils/variant_helper.hpp"
#include <quickjs.h>
#include <godot_cpp/variant/aabb.hpp>
#include <godot_cpp/variant/plane.hpp>
#include <godot_cpp/variant/rect2.hpp>
#include <godot_cpp/variant/vector2.hpp>
#include <godot_cpp/variant/vector4.hpp>


using namespace godot;

static void projection_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Projection"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memfree(opaque_ptr);
	}
}

static JSClassDef projection_class_def = {
	"Projection",
	projection_class_finalizer
};

static JSValue projection_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["Projection"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);

	if (JS_IsException(obj)) {
		return obj;
	}
	
	Projection instance;
	if (argc == 0) {
		instance = Projection();
	}
	if (argc == 1&&VariantAdapter::can_cast(argv[0], Variant::Type::PROJECTION)) {
		Projection v0 = VariantAdapter(argv[0]).get();
		instance = Projection(v0);
	}
	if (argc == 1&&VariantAdapter::can_cast(argv[0], Variant::Type::TRANSFORM3D)) {
		Transform3D v0 = VariantAdapter(argv[0]).get();
		instance = Projection(v0);
	}
	if (argc == 4&&VariantAdapter::can_cast(argv[0], Variant::Type::VECTOR4)&&VariantAdapter::can_cast(argv[1], Variant::Type::VECTOR4)&&VariantAdapter::can_cast(argv[2], Variant::Type::VECTOR4)&&VariantAdapter::can_cast(argv[3], Variant::Type::VECTOR4)) {
		Vector4 v0 = VariantAdapter(argv[0]).get();
		Vector4 v1 = VariantAdapter(argv[1]).get();
		Vector4 v2 = VariantAdapter(argv[2]).get();
		Vector4 v3 = VariantAdapter(argv[3]).get();
		instance = Projection(v0, v1, v2, v3);
	}
	VariantAdapter *adapter = memnew(VariantAdapter(instance, true));

	if (!adapter) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, adapter);
	return obj;
}
static JSValue projection_class_create_depth_correction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Projection::create_depth_correction, ctx, this_val, argc, argv);
}
static JSValue projection_class_create_light_atlas_rect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Projection::create_light_atlas_rect, ctx, this_val, argc, argv);
}
static JSValue projection_class_create_perspective(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Projection::create_perspective, ctx, this_val, argc, argv);
}
static JSValue projection_class_create_perspective_hmd(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Projection::create_perspective_hmd, ctx, this_val, argc, argv);
}
static JSValue projection_class_create_for_hmd(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Projection::create_for_hmd, ctx, this_val, argc, argv);
}
static JSValue projection_class_create_orthogonal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Projection::create_orthogonal, ctx, this_val, argc, argv);
}
static JSValue projection_class_create_orthogonal_aspect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Projection::create_orthogonal_aspect, ctx, this_val, argc, argv);
}
static JSValue projection_class_create_frustum(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Projection::create_frustum, ctx, this_val, argc, argv);
}
static JSValue projection_class_create_frustum_aspect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Projection::create_frustum_aspect, ctx, this_val, argc, argv);
}
static JSValue projection_class_create_fit_aabb(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Projection::create_fit_aabb, ctx, this_val, argc, argv);
}
static JSValue projection_class_determinant(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Projection::determinant, ctx, this_val, argc, argv);
}
static JSValue projection_class_perspective_znear_adjusted(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Projection::perspective_znear_adjusted, ctx, this_val, argc, argv);
}
static JSValue projection_class_get_projection_plane(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Projection::get_projection_plane, ctx, this_val, argc, argv);
}
static JSValue projection_class_flipped_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Projection::flipped_y, ctx, this_val, argc, argv);
}
static JSValue projection_class_jitter_offseted(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Projection::jitter_offseted, ctx, this_val, argc, argv);
}
static JSValue projection_class_get_fovy(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Projection::get_fovy, ctx, this_val, argc, argv);
}
static JSValue projection_class_get_z_far(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Projection::get_z_far, ctx, this_val, argc, argv);
}
static JSValue projection_class_get_z_near(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Projection::get_z_near, ctx, this_val, argc, argv);
}
static JSValue projection_class_get_aspect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Projection::get_aspect, ctx, this_val, argc, argv);
}
static JSValue projection_class_get_fov(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Projection::get_fov, ctx, this_val, argc, argv);
}
static JSValue projection_class_is_orthogonal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Projection::is_orthogonal, ctx, this_val, argc, argv);
}
static JSValue projection_class_get_viewport_half_extents(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Projection::get_viewport_half_extents, ctx, this_val, argc, argv);
}
static JSValue projection_class_get_far_plane_half_extents(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Projection::get_far_plane_half_extents, ctx, this_val, argc, argv);
}
static JSValue projection_class_inverse(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Projection::inverse, ctx, this_val, argc, argv);
}
static JSValue projection_class_get_pixels_per_meter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Projection::get_pixels_per_meter, ctx, this_val, argc, argv);
}
static JSValue projection_class_get_lod_multiplier(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Projection::get_lod_multiplier, ctx, this_val, argc, argv);
}

static JSValue projection_class_get_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Projection val = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Projection"]))->get();
	return VariantAdapter(val.columns[0]);
}
static JSValue projection_class_set_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    VariantAdapter *adapter = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Projection"]));
    Projection val = adapter->get();
    val.columns[0] = VariantAdapter(*argv).get();
    adapter->set(val);
	return JS_UNDEFINED;
}
static JSValue projection_class_get_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Projection val = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Projection"]))->get();
	return VariantAdapter(val.columns[1]);
}
static JSValue projection_class_set_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    VariantAdapter *adapter = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Projection"]));
    Projection val = adapter->get();
    val.columns[1] = VariantAdapter(*argv).get();
    adapter->set(val);
	return JS_UNDEFINED;
}
static JSValue projection_class_get_z(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Projection val = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Projection"]))->get();
	return VariantAdapter(val.columns[2]);
}
static JSValue projection_class_set_z(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    VariantAdapter *adapter = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Projection"]));
    Projection val = adapter->get();
    val.columns[2] = VariantAdapter(*argv).get();
    adapter->set(val);
	return JS_UNDEFINED;
}
static JSValue projection_class_get_w(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Projection val = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Projection"]))->get();
	return VariantAdapter(val.columns[3]);
}
static JSValue projection_class_set_w(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    VariantAdapter *adapter = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Projection"]));
    Projection val = adapter->get();
    val.columns[3] = VariantAdapter(*argv).get();
    adapter->set(val);
	return JS_UNDEFINED;
}


static JSValue projection_get_constant_IDENTITY(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Projection(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue projection_get_constant_ZERO(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Projection(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}

static const JSCFunctionListEntry projection_class_proto_funcs[] = {
	JS_CFUNC_DEF("create_depth_correction", 1, &projection_class_create_depth_correction),
	JS_CFUNC_DEF("create_light_atlas_rect", 1, &projection_class_create_light_atlas_rect),
	JS_CFUNC_DEF("create_perspective", 5, &projection_class_create_perspective),
	JS_CFUNC_DEF("create_perspective_hmd", 8, &projection_class_create_perspective_hmd),
	JS_CFUNC_DEF("create_for_hmd", 8, &projection_class_create_for_hmd),
	JS_CFUNC_DEF("create_orthogonal", 6, &projection_class_create_orthogonal),
	JS_CFUNC_DEF("create_orthogonal_aspect", 5, &projection_class_create_orthogonal_aspect),
	JS_CFUNC_DEF("create_frustum", 6, &projection_class_create_frustum),
	JS_CFUNC_DEF("create_frustum_aspect", 6, &projection_class_create_frustum_aspect),
	JS_CFUNC_DEF("create_fit_aabb", 1, &projection_class_create_fit_aabb),
	JS_CFUNC_DEF("determinant", 0, &projection_class_determinant),
	JS_CFUNC_DEF("perspective_znear_adjusted", 1, &projection_class_perspective_znear_adjusted),
	JS_CFUNC_DEF("get_projection_plane", 1, &projection_class_get_projection_plane),
	JS_CFUNC_DEF("flipped_y", 0, &projection_class_flipped_y),
	JS_CFUNC_DEF("jitter_offseted", 1, &projection_class_jitter_offseted),
	JS_CFUNC_DEF("get_fovy", 2, &projection_class_get_fovy),
	JS_CFUNC_DEF("get_z_far", 0, &projection_class_get_z_far),
	JS_CFUNC_DEF("get_z_near", 0, &projection_class_get_z_near),
	JS_CFUNC_DEF("get_aspect", 0, &projection_class_get_aspect),
	JS_CFUNC_DEF("get_fov", 0, &projection_class_get_fov),
	JS_CFUNC_DEF("is_orthogonal", 0, &projection_class_is_orthogonal),
	JS_CFUNC_DEF("get_viewport_half_extents", 0, &projection_class_get_viewport_half_extents),
	JS_CFUNC_DEF("get_far_plane_half_extents", 0, &projection_class_get_far_plane_half_extents),
	JS_CFUNC_DEF("inverse", 0, &projection_class_inverse),
	JS_CFUNC_DEF("get_pixels_per_meter", 1, &projection_class_get_pixels_per_meter),
	JS_CFUNC_DEF("get_lod_multiplier", 0, &projection_class_get_lod_multiplier),
};

static const JSCFunctionListEntry projection_class_constants_funcs[] = {
    JS_CGETSET_DEF("IDENTITY", &projection_get_constant_IDENTITY, NULL),
    JS_CGETSET_DEF("ZERO", &projection_get_constant_ZERO, NULL),
};

static void define_projection_property(JSContext *ctx, JSValue obj) {
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "x"),
			JS_NewCFunction(ctx, projection_class_get_x, "get_x", 0),
			JS_NewCFunction(ctx, projection_class_set_x, "set_x", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "y"),
			JS_NewCFunction(ctx, projection_class_get_y, "get_y", 0),
			JS_NewCFunction(ctx, projection_class_set_y, "set_y", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "z"),
			JS_NewCFunction(ctx, projection_class_get_z, "get_z", 0),
			JS_NewCFunction(ctx, projection_class_set_z, "set_z", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "w"),
			JS_NewCFunction(ctx, projection_class_get_w, "get_w", 0),
			JS_NewCFunction(ctx, projection_class_set_w, "set_w", 1),
			JS_PROP_GETSET);
}


static int js_projection_class_init(JSContext *ctx) {
	JSClassID class_id = 0;
	classes["Projection"] = JS_NewClassID(js_runtime(), &class_id);
	classes_by_id[class_id] = "Projection";

	JS_NewClass(JS_GetRuntime(ctx), class_id, &projection_class_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, class_id, proto);	define_projection_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, projection_class_proto_funcs, _countof(projection_class_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, projection_class_constructor, "Projection", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetPropertyFunctionList(ctx, ctor, projection_class_constants_funcs, _countof(projection_class_constants_funcs));
	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "Projection", ctor);

	JS_FreeValue(ctx, global);
	return 0;
}

static void js_init_projection_module(JSContext *ctx) {
	js_projection_class_init(ctx);
}

void register_projection() {
	js_init_projection_module(js_context());
}

// ------------------ProjectionProxy------------------
static void projection_proxy_finalizer(JSRuntime *rt, JSValue val) {
	void *proxy = JS_GetOpaque(val, classes["ProjectionProxy"]);
	if (proxy) {
		memfree(static_cast<ObjectProxy<Projection> *>(proxy));
	}
}

static JSClassDef projection_proxy_def = {
	"ProjectionProxy",
	projection_proxy_finalizer
};


static JSValue projection_proxy_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["ProjectionProxy"];
	JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
	JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

	ObjectProxy<Projection> *proxy;
	JSClassID opaque_id;
	// Allow constructing from an existing native pointer
	if (argc == 1 && JS_IsObject(*argv)) {
		proxy = static_cast<ObjectProxy<Projection> *>(JS_GetAnyOpaque(*argv, &opaque_id));
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

static JSValue projection_proxy_create_depth_correction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Projection::create_depth_correction, ctx, this_val, argc, argv);
}
static JSValue projection_proxy_create_light_atlas_rect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Projection::create_light_atlas_rect, ctx, this_val, argc, argv);
}
static JSValue projection_proxy_create_perspective(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Projection::create_perspective, ctx, this_val, argc, argv);
}
static JSValue projection_proxy_create_perspective_hmd(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Projection::create_perspective_hmd, ctx, this_val, argc, argv);
}
static JSValue projection_proxy_create_for_hmd(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Projection::create_for_hmd, ctx, this_val, argc, argv);
}
static JSValue projection_proxy_create_orthogonal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Projection::create_orthogonal, ctx, this_val, argc, argv);
}
static JSValue projection_proxy_create_orthogonal_aspect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Projection::create_orthogonal_aspect, ctx, this_val, argc, argv);
}
static JSValue projection_proxy_create_frustum(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Projection::create_frustum, ctx, this_val, argc, argv);
}
static JSValue projection_proxy_create_frustum_aspect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Projection::create_frustum_aspect, ctx, this_val, argc, argv);
}
static JSValue projection_proxy_create_fit_aabb(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Projection::create_fit_aabb, ctx, this_val, argc, argv);
}
static JSValue projection_proxy_determinant(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["ProjectionProxy"]);
    ObjectProxy<Projection> *proxy = static_cast<ObjectProxy<Projection> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Projection::determinant, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue projection_proxy_perspective_znear_adjusted(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["ProjectionProxy"]);
    ObjectProxy<Projection> *proxy = static_cast<ObjectProxy<Projection> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Projection::perspective_znear_adjusted, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue projection_proxy_get_projection_plane(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["ProjectionProxy"]);
    ObjectProxy<Projection> *proxy = static_cast<ObjectProxy<Projection> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Projection::get_projection_plane, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue projection_proxy_flipped_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["ProjectionProxy"]);
    ObjectProxy<Projection> *proxy = static_cast<ObjectProxy<Projection> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Projection::flipped_y, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue projection_proxy_jitter_offseted(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["ProjectionProxy"]);
    ObjectProxy<Projection> *proxy = static_cast<ObjectProxy<Projection> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Projection::jitter_offseted, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue projection_proxy_get_fovy(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Projection::get_fovy, ctx, this_val, argc, argv);
}
static JSValue projection_proxy_get_z_far(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["ProjectionProxy"]);
    ObjectProxy<Projection> *proxy = static_cast<ObjectProxy<Projection> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Projection::get_z_far, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue projection_proxy_get_z_near(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["ProjectionProxy"]);
    ObjectProxy<Projection> *proxy = static_cast<ObjectProxy<Projection> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Projection::get_z_near, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue projection_proxy_get_aspect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["ProjectionProxy"]);
    ObjectProxy<Projection> *proxy = static_cast<ObjectProxy<Projection> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Projection::get_aspect, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue projection_proxy_get_fov(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["ProjectionProxy"]);
    ObjectProxy<Projection> *proxy = static_cast<ObjectProxy<Projection> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Projection::get_fov, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue projection_proxy_is_orthogonal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["ProjectionProxy"]);
    ObjectProxy<Projection> *proxy = static_cast<ObjectProxy<Projection> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Projection::is_orthogonal, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue projection_proxy_get_viewport_half_extents(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["ProjectionProxy"]);
    ObjectProxy<Projection> *proxy = static_cast<ObjectProxy<Projection> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Projection::get_viewport_half_extents, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue projection_proxy_get_far_plane_half_extents(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["ProjectionProxy"]);
    ObjectProxy<Projection> *proxy = static_cast<ObjectProxy<Projection> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Projection::get_far_plane_half_extents, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue projection_proxy_inverse(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["ProjectionProxy"]);
    ObjectProxy<Projection> *proxy = static_cast<ObjectProxy<Projection> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Projection::inverse, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue projection_proxy_get_pixels_per_meter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["ProjectionProxy"]);
    ObjectProxy<Projection> *proxy = static_cast<ObjectProxy<Projection> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Projection::get_pixels_per_meter, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue projection_proxy_get_lod_multiplier(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["ProjectionProxy"]);
    ObjectProxy<Projection> *proxy = static_cast<ObjectProxy<Projection> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Projection::get_lod_multiplier, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}

static JSValue projection_proxy_get_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["ProjectionProxy"]);
    ObjectProxy<Projection> *proxy = static_cast<ObjectProxy<Projection> *>(opaque);
    Projection ret = proxy->getter();
    return VariantAdapter(ret.columns[0]);
}
static JSValue projection_proxy_set_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["ProjectionProxy"]);
    ObjectProxy<Projection> *proxy = static_cast<ObjectProxy<Projection> *>(opaque);
    VariantAdapter x(argv[0]);
    Projection wrapped = proxy->getter();
    wrapped.columns[0] = x.get();
    proxy->setter(wrapped);
	return JS_UNDEFINED;
}
static JSValue projection_proxy_get_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["ProjectionProxy"]);
    ObjectProxy<Projection> *proxy = static_cast<ObjectProxy<Projection> *>(opaque);
    Projection ret = proxy->getter();
    return VariantAdapter(ret.columns[1]);
}
static JSValue projection_proxy_set_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["ProjectionProxy"]);
    ObjectProxy<Projection> *proxy = static_cast<ObjectProxy<Projection> *>(opaque);
    VariantAdapter y(argv[0]);
    Projection wrapped = proxy->getter();
    wrapped.columns[1] = y.get();
    proxy->setter(wrapped);
	return JS_UNDEFINED;
}
static JSValue projection_proxy_get_z(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["ProjectionProxy"]);
    ObjectProxy<Projection> *proxy = static_cast<ObjectProxy<Projection> *>(opaque);
    Projection ret = proxy->getter();
    return VariantAdapter(ret.columns[2]);
}
static JSValue projection_proxy_set_z(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["ProjectionProxy"]);
    ObjectProxy<Projection> *proxy = static_cast<ObjectProxy<Projection> *>(opaque);
    VariantAdapter z(argv[0]);
    Projection wrapped = proxy->getter();
    wrapped.columns[2] = z.get();
    proxy->setter(wrapped);
	return JS_UNDEFINED;
}
static JSValue projection_proxy_get_w(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["ProjectionProxy"]);
    ObjectProxy<Projection> *proxy = static_cast<ObjectProxy<Projection> *>(opaque);
    Projection ret = proxy->getter();
    return VariantAdapter(ret.columns[3]);
}
static JSValue projection_proxy_set_w(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["ProjectionProxy"]);
    ObjectProxy<Projection> *proxy = static_cast<ObjectProxy<Projection> *>(opaque);
    VariantAdapter w(argv[0]);
    Projection wrapped = proxy->getter();
    wrapped.columns[3] = w.get();
    proxy->setter(wrapped);
	return JS_UNDEFINED;
}

static const JSCFunctionListEntry projection_proxy_proto_funcs[] = {
	JS_CFUNC_DEF("create_depth_correction", 1, &projection_proxy_create_depth_correction),
	JS_CFUNC_DEF("create_light_atlas_rect", 1, &projection_proxy_create_light_atlas_rect),
	JS_CFUNC_DEF("create_perspective", 5, &projection_proxy_create_perspective),
	JS_CFUNC_DEF("create_perspective_hmd", 8, &projection_proxy_create_perspective_hmd),
	JS_CFUNC_DEF("create_for_hmd", 8, &projection_proxy_create_for_hmd),
	JS_CFUNC_DEF("create_orthogonal", 6, &projection_proxy_create_orthogonal),
	JS_CFUNC_DEF("create_orthogonal_aspect", 5, &projection_proxy_create_orthogonal_aspect),
	JS_CFUNC_DEF("create_frustum", 6, &projection_proxy_create_frustum),
	JS_CFUNC_DEF("create_frustum_aspect", 6, &projection_proxy_create_frustum_aspect),
	JS_CFUNC_DEF("create_fit_aabb", 1, &projection_proxy_create_fit_aabb),
	JS_CFUNC_DEF("determinant", 0, &projection_proxy_determinant),
	JS_CFUNC_DEF("perspective_znear_adjusted", 1, &projection_proxy_perspective_znear_adjusted),
	JS_CFUNC_DEF("get_projection_plane", 1, &projection_proxy_get_projection_plane),
	JS_CFUNC_DEF("flipped_y", 0, &projection_proxy_flipped_y),
	JS_CFUNC_DEF("jitter_offseted", 1, &projection_proxy_jitter_offseted),
	JS_CFUNC_DEF("get_fovy", 2, &projection_proxy_get_fovy),
	JS_CFUNC_DEF("get_z_far", 0, &projection_proxy_get_z_far),
	JS_CFUNC_DEF("get_z_near", 0, &projection_proxy_get_z_near),
	JS_CFUNC_DEF("get_aspect", 0, &projection_proxy_get_aspect),
	JS_CFUNC_DEF("get_fov", 0, &projection_proxy_get_fov),
	JS_CFUNC_DEF("is_orthogonal", 0, &projection_proxy_is_orthogonal),
	JS_CFUNC_DEF("get_viewport_half_extents", 0, &projection_proxy_get_viewport_half_extents),
	JS_CFUNC_DEF("get_far_plane_half_extents", 0, &projection_proxy_get_far_plane_half_extents),
	JS_CFUNC_DEF("inverse", 0, &projection_proxy_inverse),
	JS_CFUNC_DEF("get_pixels_per_meter", 1, &projection_proxy_get_pixels_per_meter),
	JS_CFUNC_DEF("get_lod_multiplier", 0, &projection_proxy_get_lod_multiplier),
};

void define_projection_proxy_property(JSContext *ctx, JSValue obj) {
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "x"),
			JS_NewCFunction(ctx, projection_proxy_get_x, "get_x", 0),
			JS_NewCFunction(ctx, projection_proxy_set_x, "set_x", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "y"),
			JS_NewCFunction(ctx, projection_proxy_get_y, "get_y", 0),
			JS_NewCFunction(ctx, projection_proxy_set_y, "set_y", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "z"),
			JS_NewCFunction(ctx, projection_proxy_get_z, "get_z", 0),
			JS_NewCFunction(ctx, projection_proxy_set_z, "set_z", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "w"),
			JS_NewCFunction(ctx, projection_proxy_get_w, "get_w", 0),
			JS_NewCFunction(ctx, projection_proxy_set_w, "set_w", 1),
			JS_PROP_GETSET);
}

static int js_projection_proxy_init(JSContext *ctx) {
	JSClassID class_id = 0;
	classes["ProjectionProxy"] = JS_NewClassID(js_runtime(), &class_id);
	classes_by_id[class_id] = "ProjectionProxy";

	JS_NewClass(JS_GetRuntime(ctx), class_id, &projection_proxy_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, class_id, proto);
	define_projection_proxy_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, projection_proxy_proto_funcs, _countof(projection_proxy_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, projection_proxy_constructor, "ProjectionProxy", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);

	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "ProjectionProxy", ctor);

	JS_FreeValue(ctx, global);
	return 0;
}

void js_init_projection_proxy_module(JSContext *ctx) {
	js_projection_proxy_init(ctx);
}

void register_proxy_projection() {
	js_init_projection_proxy_module(js_context());
}
