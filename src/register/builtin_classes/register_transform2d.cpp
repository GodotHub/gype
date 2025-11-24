#include "register/builtin_classes/register_builtin_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/quickjs_helper.hpp"
#include "utils/str_helper.hpp"
#include "utils/variant_helper.hpp"
#include <quickjs.h>

#include <godot_cpp/variant/transform2d.hpp>
#include <godot_cpp/variant/vector2.hpp>


using namespace godot;

static void transform2d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Transform2D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memfree(opaque_ptr);
	}
}

static JSClassDef transform2d_class_def = {
	"Transform2D",
	transform2d_class_finalizer
};

static JSValue transform2d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["Transform2D"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);

	if (JS_IsException(obj)) {
		return obj;
	}
	
	Transform2D instance;
	if (argc == 0) {
		instance = Transform2D();
	}
	if (argc == 1&&VariantAdapter::can_cast(argv[0], Variant::Type::TRANSFORM2D)) {
		Transform2D v0 = VariantAdapter(argv[0]).get();
		instance = Transform2D(v0);
	}
	if (argc == 2&&JS_IsNumber(argv[0])&&VariantAdapter::can_cast(argv[1], Variant::Type::VECTOR2)) {
		double v0 = VariantAdapter(argv[0]).get();
		Vector2 v1 = VariantAdapter(argv[1]).get();
		instance = Transform2D(v0, v1);
	}
	if (argc == 4&&JS_IsNumber(argv[0])&&VariantAdapter::can_cast(argv[1], Variant::Type::VECTOR2)&&JS_IsNumber(argv[2])&&VariantAdapter::can_cast(argv[3], Variant::Type::VECTOR2)) {
		double v0 = VariantAdapter(argv[0]).get();
		Vector2 v1 = VariantAdapter(argv[1]).get();
		double v2 = VariantAdapter(argv[2]).get();
		Vector2 v3 = VariantAdapter(argv[3]).get();
		instance = Transform2D(v0, v1, v2, v3);
	}
	if (argc == 3&&VariantAdapter::can_cast(argv[0], Variant::Type::VECTOR2)&&VariantAdapter::can_cast(argv[1], Variant::Type::VECTOR2)&&VariantAdapter::can_cast(argv[2], Variant::Type::VECTOR2)) {
		Vector2 v0 = VariantAdapter(argv[0]).get();
		Vector2 v1 = VariantAdapter(argv[1]).get();
		Vector2 v2 = VariantAdapter(argv[2]).get();
		instance = Transform2D(v0, v1, v2);
	}
	VariantAdapter *adapter = memnew(VariantAdapter(instance, true));

	if (!adapter) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, adapter);
	return obj;
}
static JSValue transform2d_class_inverse(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Transform2D::inverse, ctx, this_val, argc, argv);
}
static JSValue transform2d_class_affine_inverse(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Transform2D::affine_inverse, ctx, this_val, argc, argv);
}
static JSValue transform2d_class_get_rotation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Transform2D::get_rotation, ctx, this_val, argc, argv);
}
static JSValue transform2d_class_get_origin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Transform2D::get_origin, ctx, this_val, argc, argv);
}
static JSValue transform2d_class_get_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Transform2D::get_scale, ctx, this_val, argc, argv);
}
static JSValue transform2d_class_get_skew(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Transform2D::get_skew, ctx, this_val, argc, argv);
}
static JSValue transform2d_class_orthonormalized(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Transform2D::orthonormalized, ctx, this_val, argc, argv);
}
static JSValue transform2d_class_rotated(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Transform2D::rotated, ctx, this_val, argc, argv);
}
static JSValue transform2d_class_rotated_local(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Transform2D::rotated_local, ctx, this_val, argc, argv);
}
static JSValue transform2d_class_scaled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Transform2D::scaled, ctx, this_val, argc, argv);
}
static JSValue transform2d_class_scaled_local(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Transform2D::scaled_local, ctx, this_val, argc, argv);
}
static JSValue transform2d_class_translated(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Transform2D::translated, ctx, this_val, argc, argv);
}
static JSValue transform2d_class_translated_local(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Transform2D::translated_local, ctx, this_val, argc, argv);
}
static JSValue transform2d_class_determinant(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Transform2D::determinant, ctx, this_val, argc, argv);
}
static JSValue transform2d_class_basis_xform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Transform2D::basis_xform, ctx, this_val, argc, argv);
}
static JSValue transform2d_class_basis_xform_inv(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Transform2D::basis_xform_inv, ctx, this_val, argc, argv);
}
static JSValue transform2d_class_interpolate_with(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Transform2D::interpolate_with, ctx, this_val, argc, argv);
}
static JSValue transform2d_class_is_conformal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Transform2D::is_conformal, ctx, this_val, argc, argv);
}
static JSValue transform2d_class_is_equal_approx(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Transform2D::is_equal_approx, ctx, this_val, argc, argv);
}
static JSValue transform2d_class_is_finite(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Transform2D::is_finite, ctx, this_val, argc, argv);
}
static JSValue transform2d_class_looking_at(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Transform2D::looking_at, ctx, this_val, argc, argv);
}

static JSValue transform2d_class_get_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Transform2D val = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Transform2D"]))->get();
	return VariantAdapter(val.columns[0]);
}
static JSValue transform2d_class_set_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    VariantAdapter *adapter = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Transform2D"]));
    Transform2D val = adapter->get();
    val.columns[0] = VariantAdapter(*argv).get();
    adapter->set(val);
	return JS_UNDEFINED;
}
static JSValue transform2d_class_get_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Transform2D val = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Transform2D"]))->get();
	return VariantAdapter(val.columns[1]);
}
static JSValue transform2d_class_set_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    VariantAdapter *adapter = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Transform2D"]));
    Transform2D val = adapter->get();
    val.columns[1] = VariantAdapter(*argv).get();
    adapter->set(val);
	return JS_UNDEFINED;
}
// static JSValue transform2d_class_get_origin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
// 	Transform2D val = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Transform2D"]))->get();
// 	return VariantAdapter(val.origin);
// }
static JSValue transform2d_class_set_origin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    VariantAdapter *adapter = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Transform2D"]));
    Transform2D val = adapter->get();
    val.set_origin(VariantAdapter(*argv).get());
    adapter->set(val);
	return JS_UNDEFINED;
}


static JSValue transform2d_get_constant_IDENTITY(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Transform2D(1, 0, 0, 1, 0, 0));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue transform2d_get_constant_FLIP_X(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Transform2D(-1, 0, 0, 1, 0, 0));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue transform2d_get_constant_FLIP_Y(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Transform2D(1, 0, 0, -1, 0, 0));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}

static const JSCFunctionListEntry transform2d_class_proto_funcs[] = {
	JS_CFUNC_DEF("inverse", 0, &transform2d_class_inverse),
	JS_CFUNC_DEF("affine_inverse", 0, &transform2d_class_affine_inverse),
	JS_CFUNC_DEF("get_rotation", 0, &transform2d_class_get_rotation),
	JS_CFUNC_DEF("get_origin", 0, &transform2d_class_get_origin),
	JS_CFUNC_DEF("get_scale", 0, &transform2d_class_get_scale),
	JS_CFUNC_DEF("get_skew", 0, &transform2d_class_get_skew),
	JS_CFUNC_DEF("orthonormalized", 0, &transform2d_class_orthonormalized),
	JS_CFUNC_DEF("rotated", 1, &transform2d_class_rotated),
	JS_CFUNC_DEF("rotated_local", 1, &transform2d_class_rotated_local),
	JS_CFUNC_DEF("scaled", 1, &transform2d_class_scaled),
	JS_CFUNC_DEF("scaled_local", 1, &transform2d_class_scaled_local),
	JS_CFUNC_DEF("translated", 1, &transform2d_class_translated),
	JS_CFUNC_DEF("translated_local", 1, &transform2d_class_translated_local),
	JS_CFUNC_DEF("determinant", 0, &transform2d_class_determinant),
	JS_CFUNC_DEF("basis_xform", 1, &transform2d_class_basis_xform),
	JS_CFUNC_DEF("basis_xform_inv", 1, &transform2d_class_basis_xform_inv),
	JS_CFUNC_DEF("interpolate_with", 2, &transform2d_class_interpolate_with),
	JS_CFUNC_DEF("is_conformal", 0, &transform2d_class_is_conformal),
	JS_CFUNC_DEF("is_equal_approx", 1, &transform2d_class_is_equal_approx),
	JS_CFUNC_DEF("is_finite", 0, &transform2d_class_is_finite),
	JS_CFUNC_DEF("looking_at", 1, &transform2d_class_looking_at),
};

static const JSCFunctionListEntry transform2d_class_constants_funcs[] = {
    JS_CGETSET_DEF("IDENTITY", &transform2d_get_constant_IDENTITY, NULL),
    JS_CGETSET_DEF("FLIP_X", &transform2d_get_constant_FLIP_X, NULL),
    JS_CGETSET_DEF("FLIP_Y", &transform2d_get_constant_FLIP_Y, NULL),
};

static void define_transform2d_property(JSContext *ctx, JSValue obj) {
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "x"),
			JS_NewCFunction(ctx, transform2d_class_get_x, "get_x", 0),
			JS_NewCFunction(ctx, transform2d_class_set_x, "set_x", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "y"),
			JS_NewCFunction(ctx, transform2d_class_get_y, "get_y", 0),
			JS_NewCFunction(ctx, transform2d_class_set_y, "set_y", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "origin"),
			JS_NewCFunction(ctx, transform2d_class_get_origin, "get_origin", 0),
			JS_NewCFunction(ctx, transform2d_class_set_origin, "set_origin", 1),
			JS_PROP_GETSET);
}


static int js_transform2d_class_init(JSContext *ctx) {
	JSClassID class_id = 0;
	classes["Transform2D"] = JS_NewClassID(js_runtime(), &class_id);
	classes_by_id[class_id] = "Transform2D";

	JS_NewClass(JS_GetRuntime(ctx), class_id, &transform2d_class_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, class_id, proto);	define_transform2d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, transform2d_class_proto_funcs, _countof(transform2d_class_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, transform2d_class_constructor, "Transform2D", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetPropertyFunctionList(ctx, ctor, transform2d_class_constants_funcs, _countof(transform2d_class_constants_funcs));
	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "Transform2D", ctor);

	JS_FreeValue(ctx, global);
	return 0;
}

static void js_init_transform2d_module(JSContext *ctx) {
	js_transform2d_class_init(ctx);
}

void register_transform2d() {
	js_init_transform2d_module(js_context());
}

// ------------------Transform2DProxy------------------
static void transform2d_proxy_finalizer(JSRuntime *rt, JSValue val) {
	void *proxy = JS_GetOpaque(val, classes["Transform2DProxy"]);
	if (proxy) {
		memfree(static_cast<ObjectProxy<Transform2D> *>(proxy));
	}
}

static JSClassDef transform2d_proxy_def = {
	"Transform2DProxy",
	transform2d_proxy_finalizer
};


static JSValue transform2d_proxy_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["Transform2DProxy"];
	JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
	JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

	ObjectProxy<Transform2D> *proxy;
	JSClassID opaque_id;
	// Allow constructing from an existing native pointer
	if (argc == 1 && JS_IsObject(*argv)) {
		proxy = static_cast<ObjectProxy<Transform2D> *>(JS_GetAnyOpaque(*argv, &opaque_id));
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

static JSValue transform2d_proxy_inverse(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Transform2DProxy"]);
    ObjectProxy<Transform2D> *proxy = static_cast<ObjectProxy<Transform2D> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Transform2D::inverse, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue transform2d_proxy_affine_inverse(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Transform2DProxy"]);
    ObjectProxy<Transform2D> *proxy = static_cast<ObjectProxy<Transform2D> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Transform2D::affine_inverse, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue transform2d_proxy_get_rotation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Transform2DProxy"]);
    ObjectProxy<Transform2D> *proxy = static_cast<ObjectProxy<Transform2D> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Transform2D::get_rotation, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue transform2d_proxy_get_origin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Transform2DProxy"]);
    ObjectProxy<Transform2D> *proxy = static_cast<ObjectProxy<Transform2D> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Transform2D::get_origin, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue transform2d_proxy_get_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Transform2DProxy"]);
    ObjectProxy<Transform2D> *proxy = static_cast<ObjectProxy<Transform2D> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Transform2D::get_scale, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue transform2d_proxy_get_skew(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Transform2DProxy"]);
    ObjectProxy<Transform2D> *proxy = static_cast<ObjectProxy<Transform2D> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Transform2D::get_skew, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue transform2d_proxy_orthonormalized(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Transform2DProxy"]);
    ObjectProxy<Transform2D> *proxy = static_cast<ObjectProxy<Transform2D> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Transform2D::orthonormalized, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue transform2d_proxy_rotated(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Transform2DProxy"]);
    ObjectProxy<Transform2D> *proxy = static_cast<ObjectProxy<Transform2D> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Transform2D::rotated, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue transform2d_proxy_rotated_local(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Transform2DProxy"]);
    ObjectProxy<Transform2D> *proxy = static_cast<ObjectProxy<Transform2D> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Transform2D::rotated_local, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue transform2d_proxy_scaled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Transform2DProxy"]);
    ObjectProxy<Transform2D> *proxy = static_cast<ObjectProxy<Transform2D> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Transform2D::scaled, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue transform2d_proxy_scaled_local(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Transform2DProxy"]);
    ObjectProxy<Transform2D> *proxy = static_cast<ObjectProxy<Transform2D> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Transform2D::scaled_local, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue transform2d_proxy_translated(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Transform2DProxy"]);
    ObjectProxy<Transform2D> *proxy = static_cast<ObjectProxy<Transform2D> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Transform2D::translated, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue transform2d_proxy_translated_local(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Transform2DProxy"]);
    ObjectProxy<Transform2D> *proxy = static_cast<ObjectProxy<Transform2D> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Transform2D::translated_local, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue transform2d_proxy_determinant(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Transform2DProxy"]);
    ObjectProxy<Transform2D> *proxy = static_cast<ObjectProxy<Transform2D> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Transform2D::determinant, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue transform2d_proxy_basis_xform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Transform2DProxy"]);
    ObjectProxy<Transform2D> *proxy = static_cast<ObjectProxy<Transform2D> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Transform2D::basis_xform, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue transform2d_proxy_basis_xform_inv(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Transform2DProxy"]);
    ObjectProxy<Transform2D> *proxy = static_cast<ObjectProxy<Transform2D> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Transform2D::basis_xform_inv, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue transform2d_proxy_interpolate_with(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Transform2DProxy"]);
    ObjectProxy<Transform2D> *proxy = static_cast<ObjectProxy<Transform2D> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Transform2D::interpolate_with, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue transform2d_proxy_is_conformal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Transform2DProxy"]);
    ObjectProxy<Transform2D> *proxy = static_cast<ObjectProxy<Transform2D> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Transform2D::is_conformal, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue transform2d_proxy_is_equal_approx(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Transform2DProxy"]);
    ObjectProxy<Transform2D> *proxy = static_cast<ObjectProxy<Transform2D> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Transform2D::is_equal_approx, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue transform2d_proxy_is_finite(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Transform2DProxy"]);
    ObjectProxy<Transform2D> *proxy = static_cast<ObjectProxy<Transform2D> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Transform2D::is_finite, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue transform2d_proxy_looking_at(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Transform2DProxy"]);
    ObjectProxy<Transform2D> *proxy = static_cast<ObjectProxy<Transform2D> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Transform2D::looking_at, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}

static JSValue transform2d_proxy_get_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Transform2DProxy"]);
    ObjectProxy<Transform2D> *proxy = static_cast<ObjectProxy<Transform2D> *>(opaque);
    Transform2D ret = proxy->getter();
    return VariantAdapter(ret.columns[0]);
}
static JSValue transform2d_proxy_set_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Transform2DProxy"]);
    ObjectProxy<Transform2D> *proxy = static_cast<ObjectProxy<Transform2D> *>(opaque);
    VariantAdapter x(argv[0]);
    Transform2D wrapped = proxy->getter();
    wrapped.columns[0] = x.get();
    proxy->setter(wrapped);
	return JS_UNDEFINED;
}
static JSValue transform2d_proxy_get_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Transform2DProxy"]);
    ObjectProxy<Transform2D> *proxy = static_cast<ObjectProxy<Transform2D> *>(opaque);
    Transform2D ret = proxy->getter();
    return VariantAdapter(ret.columns[1]);
}
static JSValue transform2d_proxy_set_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Transform2DProxy"]);
    ObjectProxy<Transform2D> *proxy = static_cast<ObjectProxy<Transform2D> *>(opaque);
    VariantAdapter y(argv[0]);
    Transform2D wrapped = proxy->getter();
    wrapped.columns[1] = y.get();
    proxy->setter(wrapped);
	return JS_UNDEFINED;
}
// static JSValue transform2d_proxy_get_origin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
// 	void *opaque = JS_GetOpaque(this_val, classes["Transform2DProxy"]);
//     ObjectProxy<Transform2D> *proxy = static_cast<ObjectProxy<Transform2D> *>(opaque);
//     Transform2D ret = proxy->getter();
//     return VariantAdapter(ret.origin);
// }
static JSValue transform2d_proxy_set_origin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["Transform2DProxy"]);
    ObjectProxy<Transform2D> *proxy = static_cast<ObjectProxy<Transform2D> *>(opaque);
    VariantAdapter origin(argv[0]);
    Transform2D wrapped = proxy->getter();
    wrapped.set_origin(origin.get());
    proxy->setter(wrapped);
	return JS_UNDEFINED;
}

static const JSCFunctionListEntry transform2d_proxy_proto_funcs[] = {
	JS_CFUNC_DEF("inverse", 0, &transform2d_proxy_inverse),
	JS_CFUNC_DEF("affine_inverse", 0, &transform2d_proxy_affine_inverse),
	JS_CFUNC_DEF("get_rotation", 0, &transform2d_proxy_get_rotation),
	JS_CFUNC_DEF("get_origin", 0, &transform2d_proxy_get_origin),
	JS_CFUNC_DEF("get_scale", 0, &transform2d_proxy_get_scale),
	JS_CFUNC_DEF("get_skew", 0, &transform2d_proxy_get_skew),
	JS_CFUNC_DEF("orthonormalized", 0, &transform2d_proxy_orthonormalized),
	JS_CFUNC_DEF("rotated", 1, &transform2d_proxy_rotated),
	JS_CFUNC_DEF("rotated_local", 1, &transform2d_proxy_rotated_local),
	JS_CFUNC_DEF("scaled", 1, &transform2d_proxy_scaled),
	JS_CFUNC_DEF("scaled_local", 1, &transform2d_proxy_scaled_local),
	JS_CFUNC_DEF("translated", 1, &transform2d_proxy_translated),
	JS_CFUNC_DEF("translated_local", 1, &transform2d_proxy_translated_local),
	JS_CFUNC_DEF("determinant", 0, &transform2d_proxy_determinant),
	JS_CFUNC_DEF("basis_xform", 1, &transform2d_proxy_basis_xform),
	JS_CFUNC_DEF("basis_xform_inv", 1, &transform2d_proxy_basis_xform_inv),
	JS_CFUNC_DEF("interpolate_with", 2, &transform2d_proxy_interpolate_with),
	JS_CFUNC_DEF("is_conformal", 0, &transform2d_proxy_is_conformal),
	JS_CFUNC_DEF("is_equal_approx", 1, &transform2d_proxy_is_equal_approx),
	JS_CFUNC_DEF("is_finite", 0, &transform2d_proxy_is_finite),
	JS_CFUNC_DEF("looking_at", 1, &transform2d_proxy_looking_at),
};

void define_transform2d_proxy_property(JSContext *ctx, JSValue obj) {
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "x"),
			JS_NewCFunction(ctx, transform2d_proxy_get_x, "get_x", 0),
			JS_NewCFunction(ctx, transform2d_proxy_set_x, "set_x", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "y"),
			JS_NewCFunction(ctx, transform2d_proxy_get_y, "get_y", 0),
			JS_NewCFunction(ctx, transform2d_proxy_set_y, "set_y", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "origin"),
			JS_NewCFunction(ctx, transform2d_proxy_get_origin, "get_origin", 0),
			JS_NewCFunction(ctx, transform2d_proxy_set_origin, "set_origin", 1),
			JS_PROP_GETSET);
}

static int js_transform2d_proxy_init(JSContext *ctx) {
	JSClassID class_id = 0;
	classes["Transform2DProxy"] = JS_NewClassID(js_runtime(), &class_id);
	classes_by_id[class_id] = "Transform2DProxy";

	JS_NewClass(JS_GetRuntime(ctx), class_id, &transform2d_proxy_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, class_id, proto);
	define_transform2d_proxy_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, transform2d_proxy_proto_funcs, _countof(transform2d_proxy_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, transform2d_proxy_constructor, "Transform2DProxy", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);

	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "Transform2DProxy", ctor);

	JS_FreeValue(ctx, global);
	return 0;
}

void js_init_transform2d_proxy_module(JSContext *ctx) {
	js_transform2d_proxy_init(ctx);
}

void register_proxy_transform2d() {
	js_init_transform2d_proxy_module(js_context());
}
