
#include "quickjs/env.h"
#include "quickjs/quickjs.h"
#include "quickjs/quickjs_helper.h"
#include "quickjs/str_helper.h"
#include "utils/func_utils.h"
#include <godot_cpp/variant/transform2d.hpp>

using namespace godot;

static void transform2d_class_finalizer(JSRuntime *rt, JSValue val) {
	Transform2D *transform2d = static_cast<Transform2D *>(JS_GetOpaque(val, Transform2D::__class_id));
	if (transform2d)
		memfree(transform2d);
}

static JSClassDef transform2d_class_def = {
	"Transform2D",
	.finalizer = transform2d_class_finalizer
};

static JSValue transform2d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSValue obj = JS_NewObjectClass(ctx, Transform2D::__class_id);
	if (JS_IsException(obj))
		return obj;

	Transform2D *transform2d_class = nullptr;

	if (argc == 0) {
		transform2d_class = memnew(Transform2D());
	}

	if (argc == 1 && Variant(argv[0]).get_type() == Variant::Type::TRANSFORM2D) {
		Transform2D v0 = Variant(argv[0]);
		transform2d_class = memnew(Transform2D(v0));
	}

	if (argc == 2 && (Variant(argv[0]).get_type() == Variant::Type::FLOAT || Variant(argv[0]).get_type() == Variant::Type::INT) && Variant(argv[1]).get_type() == Variant::Type::VECTOR2) {
		float v0 = Variant(argv[0]);
		Vector2 v1 = Variant(argv[1]);
		transform2d_class = memnew(Transform2D(v0, v1));
	}

	if (argc == 4 && (Variant(argv[0]).get_type() == Variant::Type::FLOAT || Variant(argv[0]).get_type() == Variant::Type::INT) && Variant(argv[1]).get_type() == Variant::Type::VECTOR2 && (Variant(argv[2]).get_type() == Variant::Type::FLOAT || Variant(argv[2]).get_type() == Variant::Type::INT) && Variant(argv[3]).get_type() == Variant::Type::VECTOR2) {
		float v0 = Variant(argv[0]);
		Vector2 v1 = Variant(argv[1]);
		float v2 = Variant(argv[2]);
		Vector2 v3 = Variant(argv[3]);
		transform2d_class = memnew(Transform2D(v0, v1, v2, v3));
	}

	if (argc == 3 && Variant(argv[0]).get_type() == Variant::Type::VECTOR2 && Variant(argv[1]).get_type() == Variant::Type::VECTOR2 && Variant(argv[2]).get_type() == Variant::Type::VECTOR2) {
		Vector2 v0 = Variant(argv[0]);
		Vector2 v1 = Variant(argv[1]);
		Vector2 v2 = Variant(argv[2]);
		transform2d_class = memnew(Transform2D(v0, v1, v2));
	}

	if (!transform2d_class) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, transform2d_class);
	return obj;
}
static JSValue transform2d_class_inverse(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Transform2D::inverse, ctx, this_val, argc, argv);
};
static JSValue transform2d_class_affine_inverse(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Transform2D::affine_inverse, ctx, this_val, argc, argv);
};
static JSValue transform2d_class_get_rotation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Transform2D::get_rotation, ctx, this_val, argc, argv);
};
static JSValue transform2d_class_get_origin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Transform2D::get_origin, ctx, this_val, argc, argv);
};
static JSValue transform2d_class_get_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Transform2D::get_scale, ctx, this_val, argc, argv);
};
static JSValue transform2d_class_get_skew(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Transform2D::get_skew, ctx, this_val, argc, argv);
};
static JSValue transform2d_class_orthonormalized(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Transform2D::orthonormalized, ctx, this_val, argc, argv);
};
static JSValue transform2d_class_rotated(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Transform2D::rotated, ctx, this_val, argc, argv);
};
static JSValue transform2d_class_rotated_local(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Transform2D::rotated_local, ctx, this_val, argc, argv);
};
static JSValue transform2d_class_scaled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Transform2D::scaled, ctx, this_val, argc, argv);
};
static JSValue transform2d_class_scaled_local(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Transform2D::scaled_local, ctx, this_val, argc, argv);
};
static JSValue transform2d_class_translated(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Transform2D::translated, ctx, this_val, argc, argv);
};
static JSValue transform2d_class_translated_local(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Transform2D::translated_local, ctx, this_val, argc, argv);
};
static JSValue transform2d_class_basis_xform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Transform2D::basis_xform, ctx, this_val, argc, argv);
};
static JSValue transform2d_class_basis_xform_inv(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Transform2D::basis_xform_inv, ctx, this_val, argc, argv);
};
static JSValue transform2d_class_interpolate_with(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Transform2D::interpolate_with, ctx, this_val, argc, argv);
};
static JSValue transform2d_class_is_equal_approx(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Transform2D::is_equal_approx, ctx, this_val, argc, argv);
};
static JSValue transform2d_class_is_finite(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Transform2D::is_finite, ctx, this_val, argc, argv);
};
static JSValue transform2d_class_looking_at(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Transform2D::looking_at, ctx, this_val, argc, argv);
};

static JSValue transform2d_class_get_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Transform2D &val = *reinterpret_cast<Transform2D *>(JS_GetOpaque(this_val, Transform2D::__class_id));
	return Variant(val.columns[0]);
}
static JSValue transform2d_class_set_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Transform2D &val = *reinterpret_cast<Transform2D *>(JS_GetOpaque(this_val, Transform2D::__class_id));
	val.columns[0] = Variant(*argv);
	return JS_UNDEFINED;
}

static JSValue transform2d_class_get_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Transform2D &val = *reinterpret_cast<Transform2D *>(JS_GetOpaque(this_val, Transform2D::__class_id));
	return Variant(val.columns[1]);
}
static JSValue transform2d_class_set_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Transform2D &val = *reinterpret_cast<Transform2D *>(JS_GetOpaque(this_val, Transform2D::__class_id));
	val.columns[1] = Variant(*argv);
	return JS_UNDEFINED;
}

static JSValue transform2d_class_set_origin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_no_ret(&Transform2D::set_origin, ctx, this_val, argc, argv);
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
	JS_CFUNC_DEF("basis_xform", 1, &transform2d_class_basis_xform),
	JS_CFUNC_DEF("basis_xform_inv", 1, &transform2d_class_basis_xform_inv),
	JS_CFUNC_DEF("interpolate_with", 2, &transform2d_class_interpolate_with),
	JS_CFUNC_DEF("is_equal_approx", 1, &transform2d_class_is_equal_approx),
	JS_CFUNC_DEF("is_finite", 0, &transform2d_class_is_finite),
	JS_CFUNC_DEF("looking_at", 1, &transform2d_class_looking_at),
};

void define_transform2d_property(JSContext *ctx, JSValue obj) {
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
	classes["Transform2D"] = Transform2D::__class_id;
	class_id_list.insert(Transform2D::__class_id);
	JS_NewClass(JS_GetRuntime(ctx), Transform2D::__class_id, &transform2d_class_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, Transform2D::__class_id, proto);
	define_transform2d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, transform2d_class_proto_funcs, _countof(transform2d_class_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, transform2d_class_constructor, "Transform2D", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);

	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "Transform2D", ctor);

	return 0;
}

void js_init_transform2d_module(JSContext *ctx) {
	js_transform2d_class_init(ctx);
}

void register_transform2d() {
	Transform2D::__init_js_class_id();
	js_init_transform2d_module(ctx);
}