#include "register/builtin_classes/register_builtin_classes.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/quickjs_helper.hpp"
#include "utils/str_helper.hpp"
#include "utils/variant_helper.hpp"
#include <quickjs.h>
#include <godot_cpp/variant/string.hpp>

using namespace godot;

static void color_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Color"];
	Color *opaque_ptr = static_cast<Color *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memfree(opaque_ptr);
	}
}

static JSClassDef color_class_def = {
	"Color",
	.finalizer = color_class_finalizer
};

static JSValue color_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["Color"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);
	if (JS_IsException(obj)) {
		return obj;
	}

	Color *instance = nullptr;	if (argc == 0) {
		instance = memnew(Color());
	}
	if (argc == 1&&VariantAdapter(argv[0]).get_type() == Variant::Type::COLOR) {
		Color v0 = VariantAdapter(argv[0]).get<Color>();
		instance = memnew(Color(v0));
	}
	if (argc == 2&&VariantAdapter(argv[0]).get_type() == Variant::Type::COLOR&&(VariantAdapter(argv[1]).get_type() == Variant::Type::FLOAT || VariantAdapter(argv[1]).get_type() == Variant::Type::INT)) {
		Color v0 = VariantAdapter(argv[0]).get<Color>();
		float v1 = VariantAdapter(argv[1]).get<float>();
		instance = memnew(Color(v0, v1));
	}
	if (argc == 3&&(VariantAdapter(argv[0]).get_type() == Variant::Type::FLOAT || VariantAdapter(argv[0]).get_type() == Variant::Type::INT)&&(VariantAdapter(argv[1]).get_type() == Variant::Type::FLOAT || VariantAdapter(argv[1]).get_type() == Variant::Type::INT)&&(VariantAdapter(argv[2]).get_type() == Variant::Type::FLOAT || VariantAdapter(argv[2]).get_type() == Variant::Type::INT)) {
		float v0 = VariantAdapter(argv[0]).get<float>();
		float v1 = VariantAdapter(argv[1]).get<float>();
		float v2 = VariantAdapter(argv[2]).get<float>();
		instance = memnew(Color(v0, v1, v2));
	}
	if (argc == 4&&(VariantAdapter(argv[0]).get_type() == Variant::Type::FLOAT || VariantAdapter(argv[0]).get_type() == Variant::Type::INT)&&(VariantAdapter(argv[1]).get_type() == Variant::Type::FLOAT || VariantAdapter(argv[1]).get_type() == Variant::Type::INT)&&(VariantAdapter(argv[2]).get_type() == Variant::Type::FLOAT || VariantAdapter(argv[2]).get_type() == Variant::Type::INT)&&(VariantAdapter(argv[3]).get_type() == Variant::Type::FLOAT || VariantAdapter(argv[3]).get_type() == Variant::Type::INT)) {
		float v0 = VariantAdapter(argv[0]).get<float>();
		float v1 = VariantAdapter(argv[1]).get<float>();
		float v2 = VariantAdapter(argv[2]).get<float>();
		float v3 = VariantAdapter(argv[3]).get<float>();
		instance = memnew(Color(v0, v1, v2, v3));
	}
	if (argc == 1&&VariantAdapter(argv[0]).get_type() == Variant::Type::STRING) {
		String v0 = VariantAdapter(argv[0]).get<String>();
		instance = memnew(Color(v0));
	}
	if (argc == 2&&VariantAdapter(argv[0]).get_type() == Variant::Type::STRING&&(VariantAdapter(argv[1]).get_type() == Variant::Type::FLOAT || VariantAdapter(argv[1]).get_type() == Variant::Type::INT)) {
		String v0 = VariantAdapter(argv[0]).get<String>();
		float v1 = VariantAdapter(argv[1]).get<float>();
		instance = memnew(Color(v0, v1));
	}

	if (!instance) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, instance);
	return obj;
}
static JSValue color_class_to_argb32(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Color::to_argb32, ctx, this_val, argc, argv);
}
static JSValue color_class_to_abgr32(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Color::to_abgr32, ctx, this_val, argc, argv);
}
static JSValue color_class_to_rgba32(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Color::to_rgba32, ctx, this_val, argc, argv);
}
static JSValue color_class_to_argb64(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Color::to_argb64, ctx, this_val, argc, argv);
}
static JSValue color_class_to_abgr64(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Color::to_abgr64, ctx, this_val, argc, argv);
}
static JSValue color_class_to_rgba64(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Color::to_rgba64, ctx, this_val, argc, argv);
}
static JSValue color_class_to_html(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Color::to_html, ctx, this_val, argc, argv);
}
static JSValue color_class_clamp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Color::clamp, ctx, this_val, argc, argv);
}
static JSValue color_class_inverted(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Color::inverted, ctx, this_val, argc, argv);
}
static JSValue color_class_lerp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Color::lerp, ctx, this_val, argc, argv);
}
static JSValue color_class_lightened(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Color::lightened, ctx, this_val, argc, argv);
}
static JSValue color_class_darkened(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Color::darkened, ctx, this_val, argc, argv);
}
static JSValue color_class_blend(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Color::blend, ctx, this_val, argc, argv);
}
static JSValue color_class_get_luminance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Color::get_luminance, ctx, this_val, argc, argv);
}
static JSValue color_class_srgb_to_linear(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Color::srgb_to_linear, ctx, this_val, argc, argv);
}
static JSValue color_class_linear_to_srgb(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Color::linear_to_srgb, ctx, this_val, argc, argv);
}
static JSValue color_class_is_equal_approx(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Color::is_equal_approx, ctx, this_val, argc, argv);
}
static JSValue color_class_hex(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Color::hex, ctx, this_val, argc, argv);
}
static JSValue color_class_hex64(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Color::hex64, ctx, this_val, argc, argv);
}
static JSValue color_class_html(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Color::html, ctx, this_val, argc, argv);
}
static JSValue color_class_html_is_valid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Color::html_is_valid, ctx, this_val, argc, argv);
}
static JSValue color_class_from_string(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Color::from_string, ctx, this_val, argc, argv);
}
static JSValue color_class_from_hsv(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Color::from_hsv, ctx, this_val, argc, argv);
}
// static JSValue color_class_from_ok_hsl(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
// 	return call_builtin_static_method_ret(&Color::from_ok_hsl, ctx, this_val, argc, argv);
// }
static JSValue color_class_from_rgbe9995(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Color::from_rgbe9995, ctx, this_val, argc, argv);
}
static JSValue color_class_from_rgba8(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Color::from_rgba8, ctx, this_val, argc, argv);
}

static JSValue color_class_get_r(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Color &val = *reinterpret_cast<Color *>(JS_GetOpaque(this_val, classes["Color"]));
	return VariantAdapter(val.r);
}
static JSValue color_class_set_r(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Color &val = *reinterpret_cast<Color *>(JS_GetOpaque(this_val, classes["Color"]));
	val.r = VariantAdapter(*argv).get<float>();
	return JS_UNDEFINED;
}
static JSValue color_class_get_g(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Color &val = *reinterpret_cast<Color *>(JS_GetOpaque(this_val, classes["Color"]));
	return VariantAdapter(val.g);
}
static JSValue color_class_set_g(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Color &val = *reinterpret_cast<Color *>(JS_GetOpaque(this_val, classes["Color"]));
	val.g = VariantAdapter(*argv).get<float>();
	return JS_UNDEFINED;
}
static JSValue color_class_get_b(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Color &val = *reinterpret_cast<Color *>(JS_GetOpaque(this_val, classes["Color"]));
	return VariantAdapter(val.b);
}
static JSValue color_class_set_b(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Color &val = *reinterpret_cast<Color *>(JS_GetOpaque(this_val, classes["Color"]));
	val.b = VariantAdapter(*argv).get<float>();
	return JS_UNDEFINED;
}
static JSValue color_class_get_a(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Color &val = *reinterpret_cast<Color *>(JS_GetOpaque(this_val, classes["Color"]));
	return VariantAdapter(val.a);
}
static JSValue color_class_set_a(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Color &val = *reinterpret_cast<Color *>(JS_GetOpaque(this_val, classes["Color"]));
	val.a = VariantAdapter(*argv).get<float>();
	return JS_UNDEFINED;
}
static JSValue color_class_get_r8(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Color &val = *reinterpret_cast<Color *>(JS_GetOpaque(this_val, classes["Color"]));
	return VariantAdapter(val.get_r8());
}
static JSValue color_class_set_r8(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Color &val = *reinterpret_cast<Color *>(JS_GetOpaque(this_val, classes["Color"]));
	val.set_r8(VariantAdapter(*argv).get<int>());
	return JS_UNDEFINED;
}
static JSValue color_class_get_g8(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Color &val = *reinterpret_cast<Color *>(JS_GetOpaque(this_val, classes["Color"]));
	return VariantAdapter(val.get_g8());
}
static JSValue color_class_set_g8(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Color &val = *reinterpret_cast<Color *>(JS_GetOpaque(this_val, classes["Color"]));
	val.set_g8(VariantAdapter(*argv).get<int>());
	return JS_UNDEFINED;
}
static JSValue color_class_get_b8(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Color &val = *reinterpret_cast<Color *>(JS_GetOpaque(this_val, classes["Color"]));
	return VariantAdapter(val.get_b8());
}
static JSValue color_class_set_b8(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Color &val = *reinterpret_cast<Color *>(JS_GetOpaque(this_val, classes["Color"]));
	val.set_b8(VariantAdapter(*argv).get<int>());
	return JS_UNDEFINED;
}
static JSValue color_class_get_a8(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Color &val = *reinterpret_cast<Color *>(JS_GetOpaque(this_val, classes["Color"]));
	return VariantAdapter(val.get_a8());
}
static JSValue color_class_set_a8(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Color &val = *reinterpret_cast<Color *>(JS_GetOpaque(this_val, classes["Color"]));
	val.set_a8(VariantAdapter(*argv).get<int>());
	return JS_UNDEFINED;
}
static JSValue color_class_get_h(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Color &val = *reinterpret_cast<Color *>(JS_GetOpaque(this_val, classes["Color"]));
	return VariantAdapter(val.get_h());
}
static JSValue color_class_set_h(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Color &val = *reinterpret_cast<Color *>(JS_GetOpaque(this_val, classes["Color"]));
	val.set_h(VariantAdapter(*argv).get<float>());
	return JS_UNDEFINED;
}
static JSValue color_class_get_s(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Color &val = *reinterpret_cast<Color *>(JS_GetOpaque(this_val, classes["Color"]));
	return VariantAdapter(val.get_s());
}
static JSValue color_class_set_s(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Color &val = *reinterpret_cast<Color *>(JS_GetOpaque(this_val, classes["Color"]));
	val.set_s(VariantAdapter(*argv).get<float>());
	return JS_UNDEFINED;
}
static JSValue color_class_get_v(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Color &val = *reinterpret_cast<Color *>(JS_GetOpaque(this_val, classes["Color"]));
	return VariantAdapter(val.get_v());
}
static JSValue color_class_set_v(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Color &val = *reinterpret_cast<Color *>(JS_GetOpaque(this_val, classes["Color"]));
	val.set_v(VariantAdapter(*argv).get<float>());
	return JS_UNDEFINED;
}
// static JSValue color_class_get_ok_hsl_h(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
// 	Color &val = *reinterpret_cast<Color *>(JS_GetOpaque(this_val, classes["Color"]));
// 	return VariantAdapter(val.ok_hsl_h);
// }
// static JSValue color_class_set_ok_hsl_h(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
// 	Color &val = *reinterpret_cast<Color *>(JS_GetOpaque(this_val, classes["Color"]));
// 	val.ok_hsl_h = VariantAdapter(*argv).get<float>();
// 	return JS_UNDEFINED;
// }
// static JSValue color_class_get_ok_hsl_s(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
// 	Color &val = *reinterpret_cast<Color *>(JS_GetOpaque(this_val, classes["Color"]));
// 	return VariantAdapter(val.ok_hsl_s);
// }
// static JSValue color_class_set_ok_hsl_s(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
// 	Color &val = *reinterpret_cast<Color *>(JS_GetOpaque(this_val, classes["Color"]));
// 	val.ok_hsl_s = VariantAdapter(*argv).get<float>();
// 	return JS_UNDEFINED;
// }
// static JSValue color_class_get_ok_hsl_l(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
// 	Color &val = *reinterpret_cast<Color *>(JS_GetOpaque(this_val, classes["Color"]));
// 	return VariantAdapter(val.ok_hsl_l);
// }
// static JSValue color_class_set_ok_hsl_l(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
// 	Color &val = *reinterpret_cast<Color *>(JS_GetOpaque(this_val, classes["Color"]));
// 	val.ok_hsl_l = VariantAdapter(*argv).get<float>();
// 	return JS_UNDEFINED;
// }

static const JSCFunctionListEntry color_class_proto_funcs[] = {
	JS_CFUNC_DEF("to_argb32", 0, &color_class_to_argb32),
	JS_CFUNC_DEF("to_abgr32", 0, &color_class_to_abgr32),
	JS_CFUNC_DEF("to_rgba32", 0, &color_class_to_rgba32),
	JS_CFUNC_DEF("to_argb64", 0, &color_class_to_argb64),
	JS_CFUNC_DEF("to_abgr64", 0, &color_class_to_abgr64),
	JS_CFUNC_DEF("to_rgba64", 0, &color_class_to_rgba64),
	JS_CFUNC_DEF("to_html", 1, &color_class_to_html),
	JS_CFUNC_DEF("clamp", 2, &color_class_clamp),
	JS_CFUNC_DEF("inverted", 0, &color_class_inverted),
	JS_CFUNC_DEF("lerp", 2, &color_class_lerp),
	JS_CFUNC_DEF("lightened", 1, &color_class_lightened),
	JS_CFUNC_DEF("darkened", 1, &color_class_darkened),
	JS_CFUNC_DEF("blend", 1, &color_class_blend),
	JS_CFUNC_DEF("get_luminance", 0, &color_class_get_luminance),
	JS_CFUNC_DEF("srgb_to_linear", 0, &color_class_srgb_to_linear),
	JS_CFUNC_DEF("linear_to_srgb", 0, &color_class_linear_to_srgb),
	JS_CFUNC_DEF("is_equal_approx", 1, &color_class_is_equal_approx),
	JS_CFUNC_DEF("hex", 1, &color_class_hex),
	JS_CFUNC_DEF("hex64", 1, &color_class_hex64),
	JS_CFUNC_DEF("html", 1, &color_class_html),
	JS_CFUNC_DEF("html_is_valid", 1, &color_class_html_is_valid),
	JS_CFUNC_DEF("from_string", 2, &color_class_from_string),
	JS_CFUNC_DEF("from_hsv", 4, &color_class_from_hsv),
	// JS_CFUNC_DEF("from_ok_hsl", 4, &color_class_from_ok_hsl),
	JS_CFUNC_DEF("from_rgbe9995", 1, &color_class_from_rgbe9995),
	JS_CFUNC_DEF("from_rgba8", 4, &color_class_from_rgba8),
};

void define_color_property(JSContext *ctx, JSValue obj) {
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "r"),
			JS_NewCFunction(ctx, color_class_get_r, "get_r", 0),
			JS_NewCFunction(ctx, color_class_set_r, "set_r", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "g"),
			JS_NewCFunction(ctx, color_class_get_g, "get_g", 0),
			JS_NewCFunction(ctx, color_class_set_g, "set_g", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "b"),
			JS_NewCFunction(ctx, color_class_get_b, "get_b", 0),
			JS_NewCFunction(ctx, color_class_set_b, "set_b", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "a"),
			JS_NewCFunction(ctx, color_class_get_a, "get_a", 0),
			JS_NewCFunction(ctx, color_class_set_a, "set_a", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "r8"),
			JS_NewCFunction(ctx, color_class_get_r8, "get_r8", 0),
			JS_NewCFunction(ctx, color_class_set_r8, "set_r8", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "g8"),
			JS_NewCFunction(ctx, color_class_get_g8, "get_g8", 0),
			JS_NewCFunction(ctx, color_class_set_g8, "set_g8", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "b8"),
			JS_NewCFunction(ctx, color_class_get_b8, "get_b8", 0),
			JS_NewCFunction(ctx, color_class_set_b8, "set_b8", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "a8"),
			JS_NewCFunction(ctx, color_class_get_a8, "get_a8", 0),
			JS_NewCFunction(ctx, color_class_set_a8, "set_a8", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "h"),
			JS_NewCFunction(ctx, color_class_get_h, "get_h", 0),
			JS_NewCFunction(ctx, color_class_set_h, "set_h", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "s"),
			JS_NewCFunction(ctx, color_class_get_s, "get_s", 0),
			JS_NewCFunction(ctx, color_class_set_s, "set_s", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "v"),
			JS_NewCFunction(ctx, color_class_get_v, "get_v", 0),
			JS_NewCFunction(ctx, color_class_set_v, "set_v", 1),
			JS_PROP_GETSET);
	// JS_DefinePropertyGetSet(
	// 		ctx,
	// 		obj,
	// 		JS_NewAtom(ctx, "ok_hsl_h"),
	// 		JS_NewCFunction(ctx, color_class_get_ok_hsl_h, "get_ok_hsl_h", 0),
	// 		JS_NewCFunction(ctx, color_class_set_ok_hsl_h, "set_ok_hsl_h", 1),
	// 		JS_PROP_GETSET);
	// JS_DefinePropertyGetSet(
	// 		ctx,
	// 		obj,
	// 		JS_NewAtom(ctx, "ok_hsl_s"),
	// 		JS_NewCFunction(ctx, color_class_get_ok_hsl_s, "get_ok_hsl_s", 0),
	// 		JS_NewCFunction(ctx, color_class_set_ok_hsl_s, "set_ok_hsl_s", 1),
	// 		JS_PROP_GETSET);
	// JS_DefinePropertyGetSet(
	// 		ctx,
	// 		obj,
	// 		JS_NewAtom(ctx, "ok_hsl_l"),
	// 		JS_NewCFunction(ctx, color_class_get_ok_hsl_l, "get_ok_hsl_l", 0),
	// 		JS_NewCFunction(ctx, color_class_set_ok_hsl_l, "set_ok_hsl_l", 1),
	// 		JS_PROP_GETSET);
}

static int js_color_class_init(JSContext *ctx) {
	classes["Color"] = JS_NewClassID(&classes["Color"]);
	JSClassID class_id = classes["Color"];

	JS_NewClass(JS_GetRuntime(ctx), class_id, &color_class_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, class_id, proto);	define_color_property(ctx, proto);	JS_SetPropertyFunctionList(ctx, proto, color_class_proto_funcs, _countof(color_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, color_class_constructor, "Color", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);

	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "Color", ctor);

	return 0;
}

void js_init_color_module(JSContext *ctx) {
	js_color_class_init(ctx);
}

void register_color() {
	js_init_color_module(js_context());
}