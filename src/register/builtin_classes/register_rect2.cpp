#include "register/builtin_classes/register_builtin_classes.hpp"
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
	Rect2 *opaque_ptr = static_cast<Rect2 *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memfree(opaque_ptr);
	}
}

static JSClassDef rect2_class_def = {
	"Rect2",
	.finalizer = rect2_class_finalizer
};

static JSValue rect2_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["Rect2"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);
	if (JS_IsException(obj)) {
		return obj;
	}

	Rect2 *instance = nullptr;	if (argc == 0) {
		instance = memnew(Rect2());
	}
	if (argc == 1&&VariantAdapter(argv[0]).get_type() == Variant::Type::RECT2) {
		Rect2 v0 = VariantAdapter(argv[0]).get<Rect2>();
		instance = memnew(Rect2(v0));
	}
	if (argc == 1&&VariantAdapter(argv[0]).get_type() == Variant::Type::RECT2I) {
		Rect2i v0 = VariantAdapter(argv[0]).get<Rect2i>();
		instance = memnew(Rect2(v0));
	}
	if (argc == 2&&VariantAdapter(argv[0]).get_type() == Variant::Type::VECTOR2&&VariantAdapter(argv[1]).get_type() == Variant::Type::VECTOR2) {
		Vector2 v0 = VariantAdapter(argv[0]).get<Vector2>();
		Vector2 v1 = VariantAdapter(argv[1]).get<Vector2>();
		instance = memnew(Rect2(v0, v1));
	}
	if (argc == 4&&(VariantAdapter(argv[0]).get_type() == Variant::Type::FLOAT || VariantAdapter(argv[0]).get_type() == Variant::Type::INT)&&(VariantAdapter(argv[1]).get_type() == Variant::Type::FLOAT || VariantAdapter(argv[1]).get_type() == Variant::Type::INT)&&(VariantAdapter(argv[2]).get_type() == Variant::Type::FLOAT || VariantAdapter(argv[2]).get_type() == Variant::Type::INT)&&(VariantAdapter(argv[3]).get_type() == Variant::Type::FLOAT || VariantAdapter(argv[3]).get_type() == Variant::Type::INT)) {
		float v0 = VariantAdapter(argv[0]).get<float>();
		float v1 = VariantAdapter(argv[1]).get<float>();
		float v2 = VariantAdapter(argv[2]).get<float>();
		float v3 = VariantAdapter(argv[3]).get<float>();
		instance = memnew(Rect2(v0, v1, v2, v3));
	}

	if (!instance) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, instance);
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
	Rect2 &val = *reinterpret_cast<Rect2 *>(JS_GetOpaque(this_val, classes["Rect2"]));
	return VariantAdapter(val.position);
}
static JSValue rect2_class_set_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Rect2 &val = *reinterpret_cast<Rect2 *>(JS_GetOpaque(this_val, classes["Rect2"]));
	val.position = VariantAdapter(*argv).get<Vector2>();
	return JS_UNDEFINED;
}
static JSValue rect2_class_get_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Rect2 &val = *reinterpret_cast<Rect2 *>(JS_GetOpaque(this_val, classes["Rect2"]));
	return VariantAdapter(val.size);
}
static JSValue rect2_class_set_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Rect2 &val = *reinterpret_cast<Rect2 *>(JS_GetOpaque(this_val, classes["Rect2"]));
	val.size = VariantAdapter(*argv).get<Vector2>();
	return JS_UNDEFINED;
}
static JSValue rect2_class_get_end(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Rect2 &val = *reinterpret_cast<Rect2 *>(JS_GetOpaque(this_val, classes["Rect2"]));
	return VariantAdapter(val.get_end());
}
static JSValue rect2_class_set_end(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Rect2 &val = *reinterpret_cast<Rect2 *>(JS_GetOpaque(this_val, classes["Rect2"]));
	val.set_end(VariantAdapter(*argv).get<Vector2>());
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

void define_rect2_property(JSContext *ctx, JSValue obj) {
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
	classes["Rect2"] = JS_NewClassID(&classes["Rect2"]);
	JSClassID class_id = classes["Rect2"];

	JS_NewClass(JS_GetRuntime(ctx), class_id, &rect2_class_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, class_id, proto);	define_rect2_property(ctx, proto);	JS_SetPropertyFunctionList(ctx, proto, rect2_class_proto_funcs, _countof(rect2_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, rect2_class_constructor, "Rect2", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);

	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "Rect2", ctor);

	return 0;
}

void js_init_rect2_module(JSContext *ctx) {
	js_rect2_class_init(ctx);
}

void register_rect2() {
	js_init_rect2_module(js_context());
}