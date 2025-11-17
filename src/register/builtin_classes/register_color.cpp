#include "register/builtin_classes/register_builtin_classes.hpp"
#include "register/object_proxy.hpp"
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
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memfree(opaque_ptr);
	}
}

static JSClassDef color_class_def = {
	"Color",
	color_class_finalizer
};

static JSValue color_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["Color"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);

	if (JS_IsException(obj)) {
		return obj;
	}
	
	Color instance;
	if (argc == 0) {
		instance = Color();
	}
	if (argc == 1&&VariantAdapter::can_cast(argv[0], Variant::Type::COLOR)) {
		Color v0 = VariantAdapter(argv[0]).get();
		instance = Color(v0);
	}
	if (argc == 2&&VariantAdapter::can_cast(argv[0], Variant::Type::COLOR)&&JS_IsNumber(argv[1])) {
		Color v0 = VariantAdapter(argv[0]).get();
		double v1 = VariantAdapter(argv[1]).get();
		instance = Color(v0, v1);
	}
	if (argc == 3&&JS_IsNumber(argv[0])&&JS_IsNumber(argv[1])&&JS_IsNumber(argv[2])) {
		double v0 = VariantAdapter(argv[0]).get();
		double v1 = VariantAdapter(argv[1]).get();
		double v2 = VariantAdapter(argv[2]).get();
		instance = Color(v0, v1, v2);
	}
	if (argc == 4&&JS_IsNumber(argv[0])&&JS_IsNumber(argv[1])&&JS_IsNumber(argv[2])&&JS_IsNumber(argv[3])) {
		double v0 = VariantAdapter(argv[0]).get();
		double v1 = VariantAdapter(argv[1]).get();
		double v2 = VariantAdapter(argv[2]).get();
		double v3 = VariantAdapter(argv[3]).get();
		instance = Color(v0, v1, v2, v3);
	}
	if (argc == 1&&JS_IsString(argv[0])) {
		String v0 = VariantAdapter(argv[0]).get();
		instance = Color(v0);
	}
	if (argc == 2&&JS_IsString(argv[0])&&JS_IsNumber(argv[1])) {
		String v0 = VariantAdapter(argv[0]).get();
		double v1 = VariantAdapter(argv[1]).get();
		instance = Color(v0, v1);
	}
	VariantAdapter *adapter = memnew(VariantAdapter(instance, true));

	if (!adapter) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, adapter);
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
	Color val = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Color"]))->get();
	return VariantAdapter(val.r);
}
static JSValue color_class_set_r(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    VariantAdapter *adapter = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Color"]));
    Color val = adapter->get();
    val.r = VariantAdapter(*argv).get();
    adapter->set(val);
	return JS_UNDEFINED;
}
static JSValue color_class_get_g(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Color val = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Color"]))->get();
	return VariantAdapter(val.g);
}
static JSValue color_class_set_g(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    VariantAdapter *adapter = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Color"]));
    Color val = adapter->get();
    val.g = VariantAdapter(*argv).get();
    adapter->set(val);
	return JS_UNDEFINED;
}
static JSValue color_class_get_b(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Color val = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Color"]))->get();
	return VariantAdapter(val.b);
}
static JSValue color_class_set_b(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    VariantAdapter *adapter = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Color"]));
    Color val = adapter->get();
    val.b = VariantAdapter(*argv).get();
    adapter->set(val);
	return JS_UNDEFINED;
}
static JSValue color_class_get_a(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	Color val = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Color"]))->get();
	return VariantAdapter(val.a);
}
static JSValue color_class_set_a(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    VariantAdapter *adapter = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Color"]));
    Color val = adapter->get();
    val.a = VariantAdapter(*argv).get();
    adapter->set(val);
	return JS_UNDEFINED;
}
// static JSValue color_class_get_r8(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
// 	Color val = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Color"]))->get();
// 	return VariantAdapter(val.r8);
// }
// static JSValue color_class_set_r8(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
//     VariantAdapter *adapter = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Color"]));
//     Color val = adapter->get();
//     val.r8 = VariantAdapter(*argv).get();
//     adapter->set(val);
// 	return JS_UNDEFINED;
// }
// static JSValue color_class_get_g8(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
// 	Color val = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Color"]))->get();
// 	return VariantAdapter(val.g8);
// }
// static JSValue color_class_set_g8(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
//     VariantAdapter *adapter = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Color"]));
//     Color val = adapter->get();
//     val.g8 = VariantAdapter(*argv).get();
//     adapter->set(val);
// 	return JS_UNDEFINED;
// }
// static JSValue color_class_get_b8(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
// 	Color val = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Color"]))->get();
// 	return VariantAdapter(val.b8);
// }
// static JSValue color_class_set_b8(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
//     VariantAdapter *adapter = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Color"]));
//     Color val = adapter->get();
//     val.b8 = VariantAdapter(*argv).get();
//     adapter->set(val);
// 	return JS_UNDEFINED;
// }
// static JSValue color_class_get_a8(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
// 	Color val = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Color"]))->get();
// 	return VariantAdapter(val.a8);
// }
// static JSValue color_class_set_a8(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
//     VariantAdapter *adapter = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Color"]));
//     Color val = adapter->get();
//     val.a8 = VariantAdapter(*argv).get();
//     adapter->set(val);
// 	return JS_UNDEFINED;
// }
// static JSValue color_class_get_h(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
// 	Color val = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Color"]))->get();
// 	return VariantAdapter(val.h);
// }
// static JSValue color_class_set_h(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
//     VariantAdapter *adapter = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Color"]));
//     Color val = adapter->get();
//     val.h = VariantAdapter(*argv).get();
//     adapter->set(val);
// 	return JS_UNDEFINED;
// }
// static JSValue color_class_get_s(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
// 	Color val = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Color"]))->get();
// 	return VariantAdapter(val.s);
// }
// static JSValue color_class_set_s(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
//     VariantAdapter *adapter = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Color"]));
//     Color val = adapter->get();
//     val.s = VariantAdapter(*argv).get();
//     adapter->set(val);
// 	return JS_UNDEFINED;
// }
// static JSValue color_class_get_v(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
// 	Color val = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Color"]))->get();
// 	return VariantAdapter(val.v);
// }
// static JSValue color_class_set_v(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
//     VariantAdapter *adapter = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Color"]));
//     Color val = adapter->get();
//     val.v = VariantAdapter(*argv).get();
//     adapter->set(val);
// 	return JS_UNDEFINED;
// }
// static JSValue color_class_get_ok_hsl_h(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
// 	Color val = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Color"]))->get();
// 	return VariantAdapter(val.ok_hsl_h);
// }
// static JSValue color_class_set_ok_hsl_h(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
//     VariantAdapter *adapter = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Color"]));
//     Color val = adapter->get();
//     val.ok_hsl_h = VariantAdapter(*argv).get();
//     adapter->set(val);
// 	return JS_UNDEFINED;
// }
// static JSValue color_class_get_ok_hsl_s(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
// 	Color val = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Color"]))->get();
// 	return VariantAdapter(val.ok_hsl_s);
// }
// static JSValue color_class_set_ok_hsl_s(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
//     VariantAdapter *adapter = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Color"]));
//     Color val = adapter->get();
//     val.ok_hsl_s = VariantAdapter(*argv).get();
//     adapter->set(val);
// 	return JS_UNDEFINED;
// }
// static JSValue color_class_get_ok_hsl_l(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
// 	Color val = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Color"]))->get();
// 	return VariantAdapter(val.ok_hsl_l);
// }
// static JSValue color_class_set_ok_hsl_l(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
//     VariantAdapter *adapter = static_cast<VariantAdapter *>(JS_GetOpaque(this_val, classes["Color"]));
//     Color val = adapter->get();
//     val.ok_hsl_l = VariantAdapter(*argv).get();
//     adapter->set(val);
// 	return JS_UNDEFINED;
// }


static JSValue color_get_constant_ALICE_BLUE(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.9411765, 0.972549, 1, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_ANTIQUE_WHITE(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.98039216, 0.92156863, 0.84313726, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_AQUA(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0, 1, 1, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_AQUAMARINE(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.49803922, 1, 0.83137256, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_AZURE(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.9411765, 1, 1, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_BEIGE(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.9607843, 0.9607843, 0.8627451, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_BISQUE(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(1, 0.89411765, 0.76862746, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_BLACK(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0, 0, 0, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_BLANCHED_ALMOND(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(1, 0.92156863, 0.8039216, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_BLUE(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0, 0, 1, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_BLUE_VIOLET(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.5411765, 0.16862746, 0.8862745, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_BROWN(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.64705884, 0.16470589, 0.16470589, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_BURLYWOOD(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.87058824, 0.72156864, 0.5294118, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_CADET_BLUE(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.37254903, 0.61960787, 0.627451, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_CHARTREUSE(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.49803922, 1, 0, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_CHOCOLATE(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.8235294, 0.4117647, 0.11764706, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_CORAL(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(1, 0.49803922, 0.3137255, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_CORNFLOWER_BLUE(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.39215687, 0.58431375, 0.92941177, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_CORNSILK(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(1, 0.972549, 0.8627451, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_CRIMSON(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.8627451, 0.078431375, 0.23529412, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_CYAN(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0, 1, 1, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_DARK_BLUE(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0, 0, 0.54509807, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_DARK_CYAN(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0, 0.54509807, 0.54509807, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_DARK_GOLDENROD(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.72156864, 0.5254902, 0.043137256, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_DARK_GRAY(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.6627451, 0.6627451, 0.6627451, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_DARK_GREEN(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0, 0.39215687, 0, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_DARK_KHAKI(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.7411765, 0.7176471, 0.41960785, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_DARK_MAGENTA(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.54509807, 0, 0.54509807, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_DARK_OLIVE_GREEN(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.33333334, 0.41960785, 0.18431373, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_DARK_ORANGE(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(1, 0.54901963, 0, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_DARK_ORCHID(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.6, 0.19607843, 0.8, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_DARK_RED(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.54509807, 0, 0, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_DARK_SALMON(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.9137255, 0.5882353, 0.47843137, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_DARK_SEA_GREEN(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.56078434, 0.7372549, 0.56078434, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_DARK_SLATE_BLUE(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.28235295, 0.23921569, 0.54509807, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_DARK_SLATE_GRAY(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.18431373, 0.30980393, 0.30980393, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_DARK_TURQUOISE(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0, 0.80784315, 0.81960785, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_DARK_VIOLET(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.5803922, 0, 0.827451, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_DEEP_PINK(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(1, 0.078431375, 0.5764706, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_DEEP_SKY_BLUE(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0, 0.7490196, 1, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_DIM_GRAY(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.4117647, 0.4117647, 0.4117647, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_DODGER_BLUE(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.11764706, 0.5647059, 1, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_FIREBRICK(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.69803923, 0.13333334, 0.13333334, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_FLORAL_WHITE(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(1, 0.98039216, 0.9411765, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_FOREST_GREEN(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.13333334, 0.54509807, 0.13333334, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_FUCHSIA(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(1, 0, 1, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_GAINSBORO(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.8627451, 0.8627451, 0.8627451, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_GHOST_WHITE(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.972549, 0.972549, 1, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_GOLD(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(1, 0.84313726, 0, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_GOLDENROD(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.85490197, 0.64705884, 0.1254902, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_GRAY(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.74509805, 0.74509805, 0.74509805, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_GREEN(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0, 1, 0, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_GREEN_YELLOW(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.6784314, 1, 0.18431373, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_HONEYDEW(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.9411765, 1, 0.9411765, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_HOT_PINK(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(1, 0.4117647, 0.7058824, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_INDIAN_RED(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.8039216, 0.36078432, 0.36078432, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_INDIGO(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.29411766, 0, 0.50980395, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_IVORY(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(1, 1, 0.9411765, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_KHAKI(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.9411765, 0.9019608, 0.54901963, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_LAVENDER(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.9019608, 0.9019608, 0.98039216, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_LAVENDER_BLUSH(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(1, 0.9411765, 0.9607843, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_LAWN_GREEN(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.4862745, 0.9882353, 0, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_LEMON_CHIFFON(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(1, 0.98039216, 0.8039216, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_LIGHT_BLUE(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.6784314, 0.84705883, 0.9019608, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_LIGHT_CORAL(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.9411765, 0.5019608, 0.5019608, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_LIGHT_CYAN(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.8784314, 1, 1, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_LIGHT_GOLDENROD(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.98039216, 0.98039216, 0.8235294, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_LIGHT_GRAY(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.827451, 0.827451, 0.827451, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_LIGHT_GREEN(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.5647059, 0.93333334, 0.5647059, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_LIGHT_PINK(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(1, 0.7137255, 0.75686276, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_LIGHT_SALMON(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(1, 0.627451, 0.47843137, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_LIGHT_SEA_GREEN(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.1254902, 0.69803923, 0.6666667, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_LIGHT_SKY_BLUE(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.5294118, 0.80784315, 0.98039216, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_LIGHT_SLATE_GRAY(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.46666667, 0.53333336, 0.6, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_LIGHT_STEEL_BLUE(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.6901961, 0.76862746, 0.87058824, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_LIGHT_YELLOW(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(1, 1, 0.8784314, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_LIME(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0, 1, 0, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_LIME_GREEN(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.19607843, 0.8039216, 0.19607843, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_LINEN(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.98039216, 0.9411765, 0.9019608, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_MAGENTA(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(1, 0, 1, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_MAROON(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.6901961, 0.1882353, 0.3764706, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_MEDIUM_AQUAMARINE(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.4, 0.8039216, 0.6666667, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_MEDIUM_BLUE(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0, 0, 0.8039216, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_MEDIUM_ORCHID(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.7294118, 0.33333334, 0.827451, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_MEDIUM_PURPLE(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.5764706, 0.4392157, 0.85882354, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_MEDIUM_SEA_GREEN(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.23529412, 0.7019608, 0.44313726, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_MEDIUM_SLATE_BLUE(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.48235294, 0.40784314, 0.93333334, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_MEDIUM_SPRING_GREEN(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0, 0.98039216, 0.6039216, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_MEDIUM_TURQUOISE(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.28235295, 0.81960785, 0.8, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_MEDIUM_VIOLET_RED(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.78039217, 0.08235294, 0.52156866, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_MIDNIGHT_BLUE(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.09803922, 0.09803922, 0.4392157, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_MINT_CREAM(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.9607843, 1, 0.98039216, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_MISTY_ROSE(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(1, 0.89411765, 0.88235295, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_MOCCASIN(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(1, 0.89411765, 0.70980394, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_NAVAJO_WHITE(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(1, 0.87058824, 0.6784314, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_NAVY_BLUE(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0, 0, 0.5019608, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_OLD_LACE(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.99215686, 0.9607843, 0.9019608, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_OLIVE(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.5019608, 0.5019608, 0, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_OLIVE_DRAB(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.41960785, 0.5568628, 0.13725491, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_ORANGE(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(1, 0.64705884, 0, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_ORANGE_RED(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(1, 0.27058825, 0, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_ORCHID(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.85490197, 0.4392157, 0.8392157, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_PALE_GOLDENROD(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.93333334, 0.9098039, 0.6666667, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_PALE_GREEN(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.59607846, 0.9843137, 0.59607846, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_PALE_TURQUOISE(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.6862745, 0.93333334, 0.93333334, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_PALE_VIOLET_RED(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.85882354, 0.4392157, 0.5764706, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_PAPAYA_WHIP(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(1, 0.9372549, 0.8352941, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_PEACH_PUFF(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(1, 0.85490197, 0.7254902, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_PERU(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.8039216, 0.52156866, 0.24705882, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_PINK(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(1, 0.7529412, 0.79607844, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_PLUM(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.8666667, 0.627451, 0.8666667, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_POWDER_BLUE(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.6901961, 0.8784314, 0.9019608, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_PURPLE(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.627451, 0.1254902, 0.9411765, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_REBECCA_PURPLE(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.4, 0.2, 0.6, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_RED(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(1, 0, 0, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_ROSY_BROWN(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.7372549, 0.56078434, 0.56078434, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_ROYAL_BLUE(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.25490198, 0.4117647, 0.88235295, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_SADDLE_BROWN(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.54509807, 0.27058825, 0.07450981, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_SALMON(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.98039216, 0.5019608, 0.44705883, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_SANDY_BROWN(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.95686275, 0.6431373, 0.3764706, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_SEA_GREEN(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.18039216, 0.54509807, 0.34117648, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_SEASHELL(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(1, 0.9607843, 0.93333334, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_SIENNA(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.627451, 0.32156864, 0.1764706, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_SILVER(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.7529412, 0.7529412, 0.7529412, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_SKY_BLUE(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.5294118, 0.80784315, 0.92156863, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_SLATE_BLUE(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.41568628, 0.3529412, 0.8039216, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_SLATE_GRAY(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.4392157, 0.5019608, 0.5647059, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_SNOW(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(1, 0.98039216, 0.98039216, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_SPRING_GREEN(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0, 1, 0.49803922, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_STEEL_BLUE(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.27450982, 0.50980395, 0.7058824, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_TAN(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.8235294, 0.7058824, 0.54901963, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_TEAL(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0, 0.5019608, 0.5019608, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_THISTLE(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.84705883, 0.7490196, 0.84705883, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_TOMATO(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(1, 0.3882353, 0.2784314, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_TRANSPARENT(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(1, 1, 1, 0));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_TURQUOISE(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.2509804, 0.8784314, 0.8156863, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_VIOLET(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.93333334, 0.50980395, 0.93333334, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_WEB_GRAY(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.5019608, 0.5019608, 0.5019608, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_WEB_GREEN(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0, 0.5019608, 0, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_WEB_MAROON(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.5019608, 0, 0, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_WEB_PURPLE(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.5019608, 0, 0.5019608, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_WHEAT(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.9607843, 0.87058824, 0.7019608, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_WHITE(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(1, 1, 1, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_WHITE_SMOKE(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.9607843, 0.9607843, 0.9607843, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_YELLOW(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(1, 1, 0, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}
static JSValue color_get_constant_YELLOW_GREEN(JSContext *ctx, JSValueConst this_val) {
    JSValue arg = variant_to_jsvalue(Color(0.6039216, 0.8039216, 0.19607843, 1));
    JSValue constant = JS_CallConstructor(ctx, this_val, 1, &arg);
	JS_FreeValue(ctx, arg);
	return constant;
}

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

static const JSCFunctionListEntry color_class_constants_funcs[] = {
    JS_CGETSET_DEF("ALICE_BLUE", &color_get_constant_ALICE_BLUE, NULL),
    JS_CGETSET_DEF("ANTIQUE_WHITE", &color_get_constant_ANTIQUE_WHITE, NULL),
    JS_CGETSET_DEF("AQUA", &color_get_constant_AQUA, NULL),
    JS_CGETSET_DEF("AQUAMARINE", &color_get_constant_AQUAMARINE, NULL),
    JS_CGETSET_DEF("AZURE", &color_get_constant_AZURE, NULL),
    JS_CGETSET_DEF("BEIGE", &color_get_constant_BEIGE, NULL),
    JS_CGETSET_DEF("BISQUE", &color_get_constant_BISQUE, NULL),
    JS_CGETSET_DEF("BLACK", &color_get_constant_BLACK, NULL),
    JS_CGETSET_DEF("BLANCHED_ALMOND", &color_get_constant_BLANCHED_ALMOND, NULL),
    JS_CGETSET_DEF("BLUE", &color_get_constant_BLUE, NULL),
    JS_CGETSET_DEF("BLUE_VIOLET", &color_get_constant_BLUE_VIOLET, NULL),
    JS_CGETSET_DEF("BROWN", &color_get_constant_BROWN, NULL),
    JS_CGETSET_DEF("BURLYWOOD", &color_get_constant_BURLYWOOD, NULL),
    JS_CGETSET_DEF("CADET_BLUE", &color_get_constant_CADET_BLUE, NULL),
    JS_CGETSET_DEF("CHARTREUSE", &color_get_constant_CHARTREUSE, NULL),
    JS_CGETSET_DEF("CHOCOLATE", &color_get_constant_CHOCOLATE, NULL),
    JS_CGETSET_DEF("CORAL", &color_get_constant_CORAL, NULL),
    JS_CGETSET_DEF("CORNFLOWER_BLUE", &color_get_constant_CORNFLOWER_BLUE, NULL),
    JS_CGETSET_DEF("CORNSILK", &color_get_constant_CORNSILK, NULL),
    JS_CGETSET_DEF("CRIMSON", &color_get_constant_CRIMSON, NULL),
    JS_CGETSET_DEF("CYAN", &color_get_constant_CYAN, NULL),
    JS_CGETSET_DEF("DARK_BLUE", &color_get_constant_DARK_BLUE, NULL),
    JS_CGETSET_DEF("DARK_CYAN", &color_get_constant_DARK_CYAN, NULL),
    JS_CGETSET_DEF("DARK_GOLDENROD", &color_get_constant_DARK_GOLDENROD, NULL),
    JS_CGETSET_DEF("DARK_GRAY", &color_get_constant_DARK_GRAY, NULL),
    JS_CGETSET_DEF("DARK_GREEN", &color_get_constant_DARK_GREEN, NULL),
    JS_CGETSET_DEF("DARK_KHAKI", &color_get_constant_DARK_KHAKI, NULL),
    JS_CGETSET_DEF("DARK_MAGENTA", &color_get_constant_DARK_MAGENTA, NULL),
    JS_CGETSET_DEF("DARK_OLIVE_GREEN", &color_get_constant_DARK_OLIVE_GREEN, NULL),
    JS_CGETSET_DEF("DARK_ORANGE", &color_get_constant_DARK_ORANGE, NULL),
    JS_CGETSET_DEF("DARK_ORCHID", &color_get_constant_DARK_ORCHID, NULL),
    JS_CGETSET_DEF("DARK_RED", &color_get_constant_DARK_RED, NULL),
    JS_CGETSET_DEF("DARK_SALMON", &color_get_constant_DARK_SALMON, NULL),
    JS_CGETSET_DEF("DARK_SEA_GREEN", &color_get_constant_DARK_SEA_GREEN, NULL),
    JS_CGETSET_DEF("DARK_SLATE_BLUE", &color_get_constant_DARK_SLATE_BLUE, NULL),
    JS_CGETSET_DEF("DARK_SLATE_GRAY", &color_get_constant_DARK_SLATE_GRAY, NULL),
    JS_CGETSET_DEF("DARK_TURQUOISE", &color_get_constant_DARK_TURQUOISE, NULL),
    JS_CGETSET_DEF("DARK_VIOLET", &color_get_constant_DARK_VIOLET, NULL),
    JS_CGETSET_DEF("DEEP_PINK", &color_get_constant_DEEP_PINK, NULL),
    JS_CGETSET_DEF("DEEP_SKY_BLUE", &color_get_constant_DEEP_SKY_BLUE, NULL),
    JS_CGETSET_DEF("DIM_GRAY", &color_get_constant_DIM_GRAY, NULL),
    JS_CGETSET_DEF("DODGER_BLUE", &color_get_constant_DODGER_BLUE, NULL),
    JS_CGETSET_DEF("FIREBRICK", &color_get_constant_FIREBRICK, NULL),
    JS_CGETSET_DEF("FLORAL_WHITE", &color_get_constant_FLORAL_WHITE, NULL),
    JS_CGETSET_DEF("FOREST_GREEN", &color_get_constant_FOREST_GREEN, NULL),
    JS_CGETSET_DEF("FUCHSIA", &color_get_constant_FUCHSIA, NULL),
    JS_CGETSET_DEF("GAINSBORO", &color_get_constant_GAINSBORO, NULL),
    JS_CGETSET_DEF("GHOST_WHITE", &color_get_constant_GHOST_WHITE, NULL),
    JS_CGETSET_DEF("GOLD", &color_get_constant_GOLD, NULL),
    JS_CGETSET_DEF("GOLDENROD", &color_get_constant_GOLDENROD, NULL),
    JS_CGETSET_DEF("GRAY", &color_get_constant_GRAY, NULL),
    JS_CGETSET_DEF("GREEN", &color_get_constant_GREEN, NULL),
    JS_CGETSET_DEF("GREEN_YELLOW", &color_get_constant_GREEN_YELLOW, NULL),
    JS_CGETSET_DEF("HONEYDEW", &color_get_constant_HONEYDEW, NULL),
    JS_CGETSET_DEF("HOT_PINK", &color_get_constant_HOT_PINK, NULL),
    JS_CGETSET_DEF("INDIAN_RED", &color_get_constant_INDIAN_RED, NULL),
    JS_CGETSET_DEF("INDIGO", &color_get_constant_INDIGO, NULL),
    JS_CGETSET_DEF("IVORY", &color_get_constant_IVORY, NULL),
    JS_CGETSET_DEF("KHAKI", &color_get_constant_KHAKI, NULL),
    JS_CGETSET_DEF("LAVENDER", &color_get_constant_LAVENDER, NULL),
    JS_CGETSET_DEF("LAVENDER_BLUSH", &color_get_constant_LAVENDER_BLUSH, NULL),
    JS_CGETSET_DEF("LAWN_GREEN", &color_get_constant_LAWN_GREEN, NULL),
    JS_CGETSET_DEF("LEMON_CHIFFON", &color_get_constant_LEMON_CHIFFON, NULL),
    JS_CGETSET_DEF("LIGHT_BLUE", &color_get_constant_LIGHT_BLUE, NULL),
    JS_CGETSET_DEF("LIGHT_CORAL", &color_get_constant_LIGHT_CORAL, NULL),
    JS_CGETSET_DEF("LIGHT_CYAN", &color_get_constant_LIGHT_CYAN, NULL),
    JS_CGETSET_DEF("LIGHT_GOLDENROD", &color_get_constant_LIGHT_GOLDENROD, NULL),
    JS_CGETSET_DEF("LIGHT_GRAY", &color_get_constant_LIGHT_GRAY, NULL),
    JS_CGETSET_DEF("LIGHT_GREEN", &color_get_constant_LIGHT_GREEN, NULL),
    JS_CGETSET_DEF("LIGHT_PINK", &color_get_constant_LIGHT_PINK, NULL),
    JS_CGETSET_DEF("LIGHT_SALMON", &color_get_constant_LIGHT_SALMON, NULL),
    JS_CGETSET_DEF("LIGHT_SEA_GREEN", &color_get_constant_LIGHT_SEA_GREEN, NULL),
    JS_CGETSET_DEF("LIGHT_SKY_BLUE", &color_get_constant_LIGHT_SKY_BLUE, NULL),
    JS_CGETSET_DEF("LIGHT_SLATE_GRAY", &color_get_constant_LIGHT_SLATE_GRAY, NULL),
    JS_CGETSET_DEF("LIGHT_STEEL_BLUE", &color_get_constant_LIGHT_STEEL_BLUE, NULL),
    JS_CGETSET_DEF("LIGHT_YELLOW", &color_get_constant_LIGHT_YELLOW, NULL),
    JS_CGETSET_DEF("LIME", &color_get_constant_LIME, NULL),
    JS_CGETSET_DEF("LIME_GREEN", &color_get_constant_LIME_GREEN, NULL),
    JS_CGETSET_DEF("LINEN", &color_get_constant_LINEN, NULL),
    JS_CGETSET_DEF("MAGENTA", &color_get_constant_MAGENTA, NULL),
    JS_CGETSET_DEF("MAROON", &color_get_constant_MAROON, NULL),
    JS_CGETSET_DEF("MEDIUM_AQUAMARINE", &color_get_constant_MEDIUM_AQUAMARINE, NULL),
    JS_CGETSET_DEF("MEDIUM_BLUE", &color_get_constant_MEDIUM_BLUE, NULL),
    JS_CGETSET_DEF("MEDIUM_ORCHID", &color_get_constant_MEDIUM_ORCHID, NULL),
    JS_CGETSET_DEF("MEDIUM_PURPLE", &color_get_constant_MEDIUM_PURPLE, NULL),
    JS_CGETSET_DEF("MEDIUM_SEA_GREEN", &color_get_constant_MEDIUM_SEA_GREEN, NULL),
    JS_CGETSET_DEF("MEDIUM_SLATE_BLUE", &color_get_constant_MEDIUM_SLATE_BLUE, NULL),
    JS_CGETSET_DEF("MEDIUM_SPRING_GREEN", &color_get_constant_MEDIUM_SPRING_GREEN, NULL),
    JS_CGETSET_DEF("MEDIUM_TURQUOISE", &color_get_constant_MEDIUM_TURQUOISE, NULL),
    JS_CGETSET_DEF("MEDIUM_VIOLET_RED", &color_get_constant_MEDIUM_VIOLET_RED, NULL),
    JS_CGETSET_DEF("MIDNIGHT_BLUE", &color_get_constant_MIDNIGHT_BLUE, NULL),
    JS_CGETSET_DEF("MINT_CREAM", &color_get_constant_MINT_CREAM, NULL),
    JS_CGETSET_DEF("MISTY_ROSE", &color_get_constant_MISTY_ROSE, NULL),
    JS_CGETSET_DEF("MOCCASIN", &color_get_constant_MOCCASIN, NULL),
    JS_CGETSET_DEF("NAVAJO_WHITE", &color_get_constant_NAVAJO_WHITE, NULL),
    JS_CGETSET_DEF("NAVY_BLUE", &color_get_constant_NAVY_BLUE, NULL),
    JS_CGETSET_DEF("OLD_LACE", &color_get_constant_OLD_LACE, NULL),
    JS_CGETSET_DEF("OLIVE", &color_get_constant_OLIVE, NULL),
    JS_CGETSET_DEF("OLIVE_DRAB", &color_get_constant_OLIVE_DRAB, NULL),
    JS_CGETSET_DEF("ORANGE", &color_get_constant_ORANGE, NULL),
    JS_CGETSET_DEF("ORANGE_RED", &color_get_constant_ORANGE_RED, NULL),
    JS_CGETSET_DEF("ORCHID", &color_get_constant_ORCHID, NULL),
    JS_CGETSET_DEF("PALE_GOLDENROD", &color_get_constant_PALE_GOLDENROD, NULL),
    JS_CGETSET_DEF("PALE_GREEN", &color_get_constant_PALE_GREEN, NULL),
    JS_CGETSET_DEF("PALE_TURQUOISE", &color_get_constant_PALE_TURQUOISE, NULL),
    JS_CGETSET_DEF("PALE_VIOLET_RED", &color_get_constant_PALE_VIOLET_RED, NULL),
    JS_CGETSET_DEF("PAPAYA_WHIP", &color_get_constant_PAPAYA_WHIP, NULL),
    JS_CGETSET_DEF("PEACH_PUFF", &color_get_constant_PEACH_PUFF, NULL),
    JS_CGETSET_DEF("PERU", &color_get_constant_PERU, NULL),
    JS_CGETSET_DEF("PINK", &color_get_constant_PINK, NULL),
    JS_CGETSET_DEF("PLUM", &color_get_constant_PLUM, NULL),
    JS_CGETSET_DEF("POWDER_BLUE", &color_get_constant_POWDER_BLUE, NULL),
    JS_CGETSET_DEF("PURPLE", &color_get_constant_PURPLE, NULL),
    JS_CGETSET_DEF("REBECCA_PURPLE", &color_get_constant_REBECCA_PURPLE, NULL),
    JS_CGETSET_DEF("RED", &color_get_constant_RED, NULL),
    JS_CGETSET_DEF("ROSY_BROWN", &color_get_constant_ROSY_BROWN, NULL),
    JS_CGETSET_DEF("ROYAL_BLUE", &color_get_constant_ROYAL_BLUE, NULL),
    JS_CGETSET_DEF("SADDLE_BROWN", &color_get_constant_SADDLE_BROWN, NULL),
    JS_CGETSET_DEF("SALMON", &color_get_constant_SALMON, NULL),
    JS_CGETSET_DEF("SANDY_BROWN", &color_get_constant_SANDY_BROWN, NULL),
    JS_CGETSET_DEF("SEA_GREEN", &color_get_constant_SEA_GREEN, NULL),
    JS_CGETSET_DEF("SEASHELL", &color_get_constant_SEASHELL, NULL),
    JS_CGETSET_DEF("SIENNA", &color_get_constant_SIENNA, NULL),
    JS_CGETSET_DEF("SILVER", &color_get_constant_SILVER, NULL),
    JS_CGETSET_DEF("SKY_BLUE", &color_get_constant_SKY_BLUE, NULL),
    JS_CGETSET_DEF("SLATE_BLUE", &color_get_constant_SLATE_BLUE, NULL),
    JS_CGETSET_DEF("SLATE_GRAY", &color_get_constant_SLATE_GRAY, NULL),
    JS_CGETSET_DEF("SNOW", &color_get_constant_SNOW, NULL),
    JS_CGETSET_DEF("SPRING_GREEN", &color_get_constant_SPRING_GREEN, NULL),
    JS_CGETSET_DEF("STEEL_BLUE", &color_get_constant_STEEL_BLUE, NULL),
    JS_CGETSET_DEF("TAN", &color_get_constant_TAN, NULL),
    JS_CGETSET_DEF("TEAL", &color_get_constant_TEAL, NULL),
    JS_CGETSET_DEF("THISTLE", &color_get_constant_THISTLE, NULL),
    JS_CGETSET_DEF("TOMATO", &color_get_constant_TOMATO, NULL),
    JS_CGETSET_DEF("TRANSPARENT", &color_get_constant_TRANSPARENT, NULL),
    JS_CGETSET_DEF("TURQUOISE", &color_get_constant_TURQUOISE, NULL),
    JS_CGETSET_DEF("VIOLET", &color_get_constant_VIOLET, NULL),
    JS_CGETSET_DEF("WEB_GRAY", &color_get_constant_WEB_GRAY, NULL),
    JS_CGETSET_DEF("WEB_GREEN", &color_get_constant_WEB_GREEN, NULL),
    JS_CGETSET_DEF("WEB_MAROON", &color_get_constant_WEB_MAROON, NULL),
    JS_CGETSET_DEF("WEB_PURPLE", &color_get_constant_WEB_PURPLE, NULL),
    JS_CGETSET_DEF("WHEAT", &color_get_constant_WHEAT, NULL),
    JS_CGETSET_DEF("WHITE", &color_get_constant_WHITE, NULL),
    JS_CGETSET_DEF("WHITE_SMOKE", &color_get_constant_WHITE_SMOKE, NULL),
    JS_CGETSET_DEF("YELLOW", &color_get_constant_YELLOW, NULL),
    JS_CGETSET_DEF("YELLOW_GREEN", &color_get_constant_YELLOW_GREEN, NULL),
};

static void define_color_property(JSContext *ctx, JSValue obj) {
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
	// JS_DefinePropertyGetSet(
	// 		ctx,
	// 		obj,
	// 		JS_NewAtom(ctx, "r8"),
	// 		JS_NewCFunction(ctx, color_class_get_r8, "get_r8", 0),
	// 		JS_NewCFunction(ctx, color_class_set_r8, "set_r8", 1),
	// 		JS_PROP_GETSET);
	// JS_DefinePropertyGetSet(
	// 		ctx,
	// 		obj,
	// 		JS_NewAtom(ctx, "g8"),
	// 		JS_NewCFunction(ctx, color_class_get_g8, "get_g8", 0),
	// 		JS_NewCFunction(ctx, color_class_set_g8, "set_g8", 1),
	// 		JS_PROP_GETSET);
	// JS_DefinePropertyGetSet(
	// 		ctx,
	// 		obj,
	// 		JS_NewAtom(ctx, "b8"),
	// 		JS_NewCFunction(ctx, color_class_get_b8, "get_b8", 0),
	// 		JS_NewCFunction(ctx, color_class_set_b8, "set_b8", 1),
	// 		JS_PROP_GETSET);
	// JS_DefinePropertyGetSet(
	// 		ctx,
	// 		obj,
	// 		JS_NewAtom(ctx, "a8"),
	// 		JS_NewCFunction(ctx, color_class_get_a8, "get_a8", 0),
	// 		JS_NewCFunction(ctx, color_class_set_a8, "set_a8", 1),
	// 		JS_PROP_GETSET);
	// JS_DefinePropertyGetSet(
	// 		ctx,
	// 		obj,
	// 		JS_NewAtom(ctx, "h"),
	// 		JS_NewCFunction(ctx, color_class_get_h, "get_h", 0),
	// 		JS_NewCFunction(ctx, color_class_set_h, "set_h", 1),
	// 		JS_PROP_GETSET);
	// JS_DefinePropertyGetSet(
	// 		ctx,
	// 		obj,
	// 		JS_NewAtom(ctx, "s"),
	// 		JS_NewCFunction(ctx, color_class_get_s, "get_s", 0),
	// 		JS_NewCFunction(ctx, color_class_set_s, "set_s", 1),
	// 		JS_PROP_GETSET);
	// JS_DefinePropertyGetSet(
	// 		ctx,
	// 		obj,
	// 		JS_NewAtom(ctx, "v"),
	// 		JS_NewCFunction(ctx, color_class_get_v, "get_v", 0),
	// 		JS_NewCFunction(ctx, color_class_set_v, "set_v", 1),
	// 		JS_PROP_GETSET);
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
	JSClassID class_id = 0;
	classes["Color"] = JS_NewClassID(js_runtime(), &class_id);
	classes_by_id[class_id] = "Color";

	JS_NewClass(JS_GetRuntime(ctx), class_id, &color_class_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, class_id, proto);	define_color_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, color_class_proto_funcs, _countof(color_class_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, color_class_constructor, "Color", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetPropertyFunctionList(ctx, ctor, color_class_constants_funcs, _countof(color_class_constants_funcs));
	
	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "Color", ctor);

	JS_FreeValue(ctx, global);
	return 0;
}

static void js_init_color_module(JSContext *ctx) {
	js_color_class_init(ctx);
}

void register_color() {
	js_init_color_module(js_context());
}

// ------------------ColorProxy------------------
static void color_proxy_finalizer(JSRuntime *rt, JSValue val) {
	void *proxy = JS_GetOpaque(val, classes["ColorProxy"]);
	if (proxy) {
		memfree(static_cast<ObjectProxy<Color> *>(proxy));
	}
}

static JSClassDef color_proxy_def = {
	"ColorProxy",
	color_proxy_finalizer
};


static JSValue color_proxy_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["ColorProxy"];
	JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
	JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

	ObjectProxy<Color> *proxy;
	JSClassID opaque_id;
	// Allow constructing from an existing native pointer
	if (argc == 1 && JS_IsObject(*argv)) {
		proxy = static_cast<ObjectProxy<Color> *>(JS_GetAnyOpaque(*argv, &opaque_id));
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

static JSValue color_proxy_to_argb32(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["ColorProxy"]);
    ObjectProxy<Color> *proxy = static_cast<ObjectProxy<Color> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Color::to_argb32, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue color_proxy_to_abgr32(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["ColorProxy"]);
    ObjectProxy<Color> *proxy = static_cast<ObjectProxy<Color> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Color::to_abgr32, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue color_proxy_to_rgba32(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["ColorProxy"]);
    ObjectProxy<Color> *proxy = static_cast<ObjectProxy<Color> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Color::to_rgba32, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue color_proxy_to_argb64(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["ColorProxy"]);
    ObjectProxy<Color> *proxy = static_cast<ObjectProxy<Color> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Color::to_argb64, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue color_proxy_to_abgr64(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["ColorProxy"]);
    ObjectProxy<Color> *proxy = static_cast<ObjectProxy<Color> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Color::to_abgr64, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue color_proxy_to_rgba64(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["ColorProxy"]);
    ObjectProxy<Color> *proxy = static_cast<ObjectProxy<Color> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Color::to_rgba64, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue color_proxy_to_html(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["ColorProxy"]);
    ObjectProxy<Color> *proxy = static_cast<ObjectProxy<Color> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Color::to_html, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue color_proxy_clamp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["ColorProxy"]);
    ObjectProxy<Color> *proxy = static_cast<ObjectProxy<Color> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Color::clamp, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue color_proxy_inverted(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["ColorProxy"]);
    ObjectProxy<Color> *proxy = static_cast<ObjectProxy<Color> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Color::inverted, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue color_proxy_lerp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["ColorProxy"]);
    ObjectProxy<Color> *proxy = static_cast<ObjectProxy<Color> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Color::lerp, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue color_proxy_lightened(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["ColorProxy"]);
    ObjectProxy<Color> *proxy = static_cast<ObjectProxy<Color> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Color::lightened, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue color_proxy_darkened(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["ColorProxy"]);
    ObjectProxy<Color> *proxy = static_cast<ObjectProxy<Color> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Color::darkened, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue color_proxy_blend(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["ColorProxy"]);
    ObjectProxy<Color> *proxy = static_cast<ObjectProxy<Color> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Color::blend, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue color_proxy_get_luminance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["ColorProxy"]);
    ObjectProxy<Color> *proxy = static_cast<ObjectProxy<Color> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Color::get_luminance, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue color_proxy_srgb_to_linear(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["ColorProxy"]);
    ObjectProxy<Color> *proxy = static_cast<ObjectProxy<Color> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Color::srgb_to_linear, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue color_proxy_linear_to_srgb(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["ColorProxy"]);
    ObjectProxy<Color> *proxy = static_cast<ObjectProxy<Color> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Color::linear_to_srgb, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue color_proxy_is_equal_approx(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["ColorProxy"]);
    ObjectProxy<Color> *proxy = static_cast<ObjectProxy<Color> *>(opaque);
    Object *wrapped = proxy->wrapped;
    this_val = VariantAdapter(wrapped);
    JSValue ret = call_builtin_const_method_ret(&Color::is_equal_approx, ctx, this_val, argc, argv);
    JS_FreeValue(ctx, this_val);
    return ret;
}
static JSValue color_proxy_hex(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Color::hex, ctx, this_val, argc, argv);
}
static JSValue color_proxy_hex64(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Color::hex64, ctx, this_val, argc, argv);
}
static JSValue color_proxy_html(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Color::html, ctx, this_val, argc, argv);
}
static JSValue color_proxy_html_is_valid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Color::html_is_valid, ctx, this_val, argc, argv);
}
static JSValue color_proxy_from_string(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Color::from_string, ctx, this_val, argc, argv);
}
static JSValue color_proxy_from_hsv(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Color::from_hsv, ctx, this_val, argc, argv);
}
// static JSValue color_proxy_from_ok_hsl(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
// 	return call_builtin_static_method_ret(&Color::from_ok_hsl, ctx, this_val, argc, argv);
// }
static JSValue color_proxy_from_rgbe9995(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Color::from_rgbe9995, ctx, this_val, argc, argv);
}
static JSValue color_proxy_from_rgba8(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Color::from_rgba8, ctx, this_val, argc, argv);
}

static JSValue color_proxy_get_r(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["ColorProxy"]);
    ObjectProxy<Color> *proxy = static_cast<ObjectProxy<Color> *>(opaque);
    Color ret = proxy->getter();
    return VariantAdapter(ret.r);
}
static JSValue color_proxy_set_r(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["ColorProxy"]);
    ObjectProxy<Color> *proxy = static_cast<ObjectProxy<Color> *>(opaque);
    VariantAdapter r(argv[0]);
    Color wrapped = proxy->getter();
    wrapped.r = r.get();
    proxy->setter(wrapped);
	return JS_UNDEFINED;
}
static JSValue color_proxy_get_g(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["ColorProxy"]);
    ObjectProxy<Color> *proxy = static_cast<ObjectProxy<Color> *>(opaque);
    Color ret = proxy->getter();
    return VariantAdapter(ret.g);
}
static JSValue color_proxy_set_g(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["ColorProxy"]);
    ObjectProxy<Color> *proxy = static_cast<ObjectProxy<Color> *>(opaque);
    VariantAdapter g(argv[0]);
    Color wrapped = proxy->getter();
    wrapped.g = g.get();
    proxy->setter(wrapped);
	return JS_UNDEFINED;
}
static JSValue color_proxy_get_b(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["ColorProxy"]);
    ObjectProxy<Color> *proxy = static_cast<ObjectProxy<Color> *>(opaque);
    Color ret = proxy->getter();
    return VariantAdapter(ret.b);
}
static JSValue color_proxy_set_b(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["ColorProxy"]);
    ObjectProxy<Color> *proxy = static_cast<ObjectProxy<Color> *>(opaque);
    VariantAdapter b(argv[0]);
    Color wrapped = proxy->getter();
    wrapped.b = b.get();
    proxy->setter(wrapped);
	return JS_UNDEFINED;
}
static JSValue color_proxy_get_a(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["ColorProxy"]);
    ObjectProxy<Color> *proxy = static_cast<ObjectProxy<Color> *>(opaque);
    Color ret = proxy->getter();
    return VariantAdapter(ret.a);
}
static JSValue color_proxy_set_a(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	void *opaque = JS_GetOpaque(this_val, classes["ColorProxy"]);
    ObjectProxy<Color> *proxy = static_cast<ObjectProxy<Color> *>(opaque);
    VariantAdapter a(argv[0]);
    Color wrapped = proxy->getter();
    wrapped.a = a.get();
    proxy->setter(wrapped);
	return JS_UNDEFINED;
}
// static JSValue color_proxy_get_r8(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
// 	void *opaque = JS_GetOpaque(this_val, classes["ColorProxy"]);
//     ObjectProxy<Color> *proxy = static_cast<ObjectProxy<Color> *>(opaque);
//     Color ret = proxy->getter();
//     return VariantAdapter(ret.r8);
// }
// static JSValue color_proxy_set_r8(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
// 	void *opaque = JS_GetOpaque(this_val, classes["ColorProxy"]);
//     ObjectProxy<Color> *proxy = static_cast<ObjectProxy<Color> *>(opaque);
//     VariantAdapter r8(argv[0]);
//     Color wrapped = proxy->getter();
//     wrapped.r8 = r8.get();
//     proxy->setter(wrapped);
// 	return JS_UNDEFINED;
// }
// static JSValue color_proxy_get_g8(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
// 	void *opaque = JS_GetOpaque(this_val, classes["ColorProxy"]);
//     ObjectProxy<Color> *proxy = static_cast<ObjectProxy<Color> *>(opaque);
//     Color ret = proxy->getter();
//     return VariantAdapter(ret.g8);
// }
// static JSValue color_proxy_set_g8(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
// 	void *opaque = JS_GetOpaque(this_val, classes["ColorProxy"]);
//     ObjectProxy<Color> *proxy = static_cast<ObjectProxy<Color> *>(opaque);
//     VariantAdapter g8(argv[0]);
//     Color wrapped = proxy->getter();
//     wrapped.g8 = g8.get();
//     proxy->setter(wrapped);
// 	return JS_UNDEFINED;
// }
// static JSValue color_proxy_get_b8(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
// 	void *opaque = JS_GetOpaque(this_val, classes["ColorProxy"]);
//     ObjectProxy<Color> *proxy = static_cast<ObjectProxy<Color> *>(opaque);
//     Color ret = proxy->getter();
//     return VariantAdapter(ret.b8);
// }
// static JSValue color_proxy_set_b8(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
// 	void *opaque = JS_GetOpaque(this_val, classes["ColorProxy"]);
//     ObjectProxy<Color> *proxy = static_cast<ObjectProxy<Color> *>(opaque);
//     VariantAdapter b8(argv[0]);
//     Color wrapped = proxy->getter();
//     wrapped.b8 = b8.get();
//     proxy->setter(wrapped);
// 	return JS_UNDEFINED;
// }
// static JSValue color_proxy_get_a8(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
// 	void *opaque = JS_GetOpaque(this_val, classes["ColorProxy"]);
//     ObjectProxy<Color> *proxy = static_cast<ObjectProxy<Color> *>(opaque);
//     Color ret = proxy->getter();
//     return VariantAdapter(ret.a8);
// }
// static JSValue color_proxy_set_a8(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
// 	void *opaque = JS_GetOpaque(this_val, classes["ColorProxy"]);
//     ObjectProxy<Color> *proxy = static_cast<ObjectProxy<Color> *>(opaque);
//     VariantAdapter a8(argv[0]);
//     Color wrapped = proxy->getter();
//     wrapped.a8 = a8.get();
//     proxy->setter(wrapped);
// 	return JS_UNDEFINED;
// }
// static JSValue color_proxy_get_h(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
// 	void *opaque = JS_GetOpaque(this_val, classes["ColorProxy"]);
//     ObjectProxy<Color> *proxy = static_cast<ObjectProxy<Color> *>(opaque);
//     Color ret = proxy->getter();
//     return VariantAdapter(ret.h);
// }
// static JSValue color_proxy_set_h(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
// 	void *opaque = JS_GetOpaque(this_val, classes["ColorProxy"]);
//     ObjectProxy<Color> *proxy = static_cast<ObjectProxy<Color> *>(opaque);
//     VariantAdapter h(argv[0]);
//     Color wrapped = proxy->getter();
//     wrapped.h = h.get();
//     proxy->setter(wrapped);
// 	return JS_UNDEFINED;
// }
// static JSValue color_proxy_get_s(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
// 	void *opaque = JS_GetOpaque(this_val, classes["ColorProxy"]);
//     ObjectProxy<Color> *proxy = static_cast<ObjectProxy<Color> *>(opaque);
//     Color ret = proxy->getter();
//     return VariantAdapter(ret.s);
// }
// static JSValue color_proxy_set_s(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
// 	void *opaque = JS_GetOpaque(this_val, classes["ColorProxy"]);
//     ObjectProxy<Color> *proxy = static_cast<ObjectProxy<Color> *>(opaque);
//     VariantAdapter s(argv[0]);
//     Color wrapped = proxy->getter();
//     wrapped.s = s.get();
//     proxy->setter(wrapped);
// 	return JS_UNDEFINED;
// }
// static JSValue color_proxy_get_v(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
// 	void *opaque = JS_GetOpaque(this_val, classes["ColorProxy"]);
//     ObjectProxy<Color> *proxy = static_cast<ObjectProxy<Color> *>(opaque);
//     Color ret = proxy->getter();
//     return VariantAdapter(ret.v);
// }
// static JSValue color_proxy_set_v(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
// 	void *opaque = JS_GetOpaque(this_val, classes["ColorProxy"]);
//     ObjectProxy<Color> *proxy = static_cast<ObjectProxy<Color> *>(opaque);
//     VariantAdapter v(argv[0]);
//     Color wrapped = proxy->getter();
//     wrapped.v = v.get();
//     proxy->setter(wrapped);
// 	return JS_UNDEFINED;
// }
// static JSValue color_proxy_get_ok_hsl_h(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
// 	void *opaque = JS_GetOpaque(this_val, classes["ColorProxy"]);
//     ObjectProxy<Color> *proxy = static_cast<ObjectProxy<Color> *>(opaque);
//     Color ret = proxy->getter();
//     return VariantAdapter(ret.ok_hsl_h);
// }
// static JSValue color_proxy_set_ok_hsl_h(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
// 	void *opaque = JS_GetOpaque(this_val, classes["ColorProxy"]);
//     ObjectProxy<Color> *proxy = static_cast<ObjectProxy<Color> *>(opaque);
//     VariantAdapter ok_hsl_h(argv[0]);
//     Color wrapped = proxy->getter();
//     wrapped.ok_hsl_h = ok_hsl_h.get();
//     proxy->setter(wrapped);
// 	return JS_UNDEFINED;
// }
// static JSValue color_proxy_get_ok_hsl_s(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
// 	void *opaque = JS_GetOpaque(this_val, classes["ColorProxy"]);
//     ObjectProxy<Color> *proxy = static_cast<ObjectProxy<Color> *>(opaque);
//     Color ret = proxy->getter();
//     return VariantAdapter(ret.ok_hsl_s);
// }
// static JSValue color_proxy_set_ok_hsl_s(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
// 	void *opaque = JS_GetOpaque(this_val, classes["ColorProxy"]);
//     ObjectProxy<Color> *proxy = static_cast<ObjectProxy<Color> *>(opaque);
//     VariantAdapter ok_hsl_s(argv[0]);
//     Color wrapped = proxy->getter();
//     wrapped.ok_hsl_s = ok_hsl_s.get();
//     proxy->setter(wrapped);
// 	return JS_UNDEFINED;
// }
// static JSValue color_proxy_get_ok_hsl_l(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
// 	void *opaque = JS_GetOpaque(this_val, classes["ColorProxy"]);
//     ObjectProxy<Color> *proxy = static_cast<ObjectProxy<Color> *>(opaque);
//     Color ret = proxy->getter();
//     return VariantAdapter(ret.ok_hsl_l);
// }
// static JSValue color_proxy_set_ok_hsl_l(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
// 	void *opaque = JS_GetOpaque(this_val, classes["ColorProxy"]);
//     ObjectProxy<Color> *proxy = static_cast<ObjectProxy<Color> *>(opaque);
//     VariantAdapter ok_hsl_l(argv[0]);
//     Color wrapped = proxy->getter();
//     wrapped.ok_hsl_l = ok_hsl_l.get();
//     proxy->setter(wrapped);
// 	return JS_UNDEFINED;
// }

static const JSCFunctionListEntry color_proxy_proto_funcs[] = {
	JS_CFUNC_DEF("to_argb32", 0, &color_proxy_to_argb32),
	JS_CFUNC_DEF("to_abgr32", 0, &color_proxy_to_abgr32),
	JS_CFUNC_DEF("to_rgba32", 0, &color_proxy_to_rgba32),
	JS_CFUNC_DEF("to_argb64", 0, &color_proxy_to_argb64),
	JS_CFUNC_DEF("to_abgr64", 0, &color_proxy_to_abgr64),
	JS_CFUNC_DEF("to_rgba64", 0, &color_proxy_to_rgba64),
	JS_CFUNC_DEF("to_html", 1, &color_proxy_to_html),
	JS_CFUNC_DEF("clamp", 2, &color_proxy_clamp),
	JS_CFUNC_DEF("inverted", 0, &color_proxy_inverted),
	JS_CFUNC_DEF("lerp", 2, &color_proxy_lerp),
	JS_CFUNC_DEF("lightened", 1, &color_proxy_lightened),
	JS_CFUNC_DEF("darkened", 1, &color_proxy_darkened),
	JS_CFUNC_DEF("blend", 1, &color_proxy_blend),
	JS_CFUNC_DEF("get_luminance", 0, &color_proxy_get_luminance),
	JS_CFUNC_DEF("srgb_to_linear", 0, &color_proxy_srgb_to_linear),
	JS_CFUNC_DEF("linear_to_srgb", 0, &color_proxy_linear_to_srgb),
	JS_CFUNC_DEF("is_equal_approx", 1, &color_proxy_is_equal_approx),
	JS_CFUNC_DEF("hex", 1, &color_proxy_hex),
	JS_CFUNC_DEF("hex64", 1, &color_proxy_hex64),
	JS_CFUNC_DEF("html", 1, &color_proxy_html),
	JS_CFUNC_DEF("html_is_valid", 1, &color_proxy_html_is_valid),
	JS_CFUNC_DEF("from_string", 2, &color_proxy_from_string),
	JS_CFUNC_DEF("from_hsv", 4, &color_proxy_from_hsv),
	// JS_CFUNC_DEF("from_ok_hsl", 4, &color_proxy_from_ok_hsl),
	JS_CFUNC_DEF("from_rgbe9995", 1, &color_proxy_from_rgbe9995),
	JS_CFUNC_DEF("from_rgba8", 4, &color_proxy_from_rgba8),
};

void define_color_proxy_property(JSContext *ctx, JSValue obj) {
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "r"),
			JS_NewCFunction(ctx, color_proxy_get_r, "get_r", 0),
			JS_NewCFunction(ctx, color_proxy_set_r, "set_r", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "g"),
			JS_NewCFunction(ctx, color_proxy_get_g, "get_g", 0),
			JS_NewCFunction(ctx, color_proxy_set_g, "set_g", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "b"),
			JS_NewCFunction(ctx, color_proxy_get_b, "get_b", 0),
			JS_NewCFunction(ctx, color_proxy_set_b, "set_b", 1),
			JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
			ctx,
			obj,
			JS_NewAtom(ctx, "a"),
			JS_NewCFunction(ctx, color_proxy_get_a, "get_a", 0),
			JS_NewCFunction(ctx, color_proxy_set_a, "set_a", 1),
			JS_PROP_GETSET);
	// JS_DefinePropertyGetSet(
	// 		ctx,
	// 		obj,
	// 		JS_NewAtom(ctx, "r8"),
	// 		JS_NewCFunction(ctx, color_proxy_get_r8, "get_r8", 0),
	// 		JS_NewCFunction(ctx, color_proxy_set_r8, "set_r8", 1),
	// 		JS_PROP_GETSET);
	// JS_DefinePropertyGetSet(
	// 		ctx,
	// 		obj,
	// 		JS_NewAtom(ctx, "g8"),
	// 		JS_NewCFunction(ctx, color_proxy_get_g8, "get_g8", 0),
	// 		JS_NewCFunction(ctx, color_proxy_set_g8, "set_g8", 1),
	// 		JS_PROP_GETSET);
	// JS_DefinePropertyGetSet(
	// 		ctx,
	// 		obj,
	// 		JS_NewAtom(ctx, "b8"),
	// 		JS_NewCFunction(ctx, color_proxy_get_b8, "get_b8", 0),
	// 		JS_NewCFunction(ctx, color_proxy_set_b8, "set_b8", 1),
	// 		JS_PROP_GETSET);
	// JS_DefinePropertyGetSet(
	// 		ctx,
	// 		obj,
	// 		JS_NewAtom(ctx, "a8"),
	// 		JS_NewCFunction(ctx, color_proxy_get_a8, "get_a8", 0),
	// 		JS_NewCFunction(ctx, color_proxy_set_a8, "set_a8", 1),
	// 		JS_PROP_GETSET);
	// JS_DefinePropertyGetSet(
	// 		ctx,
	// 		obj,
	// 		JS_NewAtom(ctx, "h"),
	// 		JS_NewCFunction(ctx, color_proxy_get_h, "get_h", 0),
	// 		JS_NewCFunction(ctx, color_proxy_set_h, "set_h", 1),
	// 		JS_PROP_GETSET);
	// JS_DefinePropertyGetSet(
	// 		ctx,
	// 		obj,
	// 		JS_NewAtom(ctx, "s"),
	// 		JS_NewCFunction(ctx, color_proxy_get_s, "get_s", 0),
	// 		JS_NewCFunction(ctx, color_proxy_set_s, "set_s", 1),
	// 		JS_PROP_GETSET);
	// JS_DefinePropertyGetSet(
	// 		ctx,
	// 		obj,
	// 		JS_NewAtom(ctx, "v"),
	// 		JS_NewCFunction(ctx, color_proxy_get_v, "get_v", 0),
	// 		JS_NewCFunction(ctx, color_proxy_set_v, "set_v", 1),
	// 		JS_PROP_GETSET);
	// JS_DefinePropertyGetSet(
	// 		ctx,
	// 		obj,
	// 		JS_NewAtom(ctx, "ok_hsl_h"),
	// 		JS_NewCFunction(ctx, color_proxy_get_ok_hsl_h, "get_ok_hsl_h", 0),
	// 		JS_NewCFunction(ctx, color_proxy_set_ok_hsl_h, "set_ok_hsl_h", 1),
	// 		JS_PROP_GETSET);
	// JS_DefinePropertyGetSet(
	// 		ctx,
	// 		obj,
	// 		JS_NewAtom(ctx, "ok_hsl_s"),
	// 		JS_NewCFunction(ctx, color_proxy_get_ok_hsl_s, "get_ok_hsl_s", 0),
	// 		JS_NewCFunction(ctx, color_proxy_set_ok_hsl_s, "set_ok_hsl_s", 1),
	// 		JS_PROP_GETSET);
	// JS_DefinePropertyGetSet(
	// 		ctx,
	// 		obj,
	// 		JS_NewAtom(ctx, "ok_hsl_l"),
	// 		JS_NewCFunction(ctx, color_proxy_get_ok_hsl_l, "get_ok_hsl_l", 0),
	// 		JS_NewCFunction(ctx, color_proxy_set_ok_hsl_l, "set_ok_hsl_l", 1),
	// 		JS_PROP_GETSET);
}

static int js_color_proxy_init(JSContext *ctx) {
	JSClassID class_id = 0;
	classes["ColorProxy"] = JS_NewClassID(js_runtime(), &class_id);
	classes_by_id[class_id] = "ColorProxy";

	JS_NewClass(JS_GetRuntime(ctx), class_id, &color_proxy_def);

	JSValue proto = JS_NewObject(ctx);
	JS_SetClassProto(ctx, class_id, proto);
	define_color_proxy_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, color_proxy_proto_funcs, _countof(color_proxy_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, color_proxy_constructor, "ColorProxy", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);

	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "ColorProxy", ctor);

	JS_FreeValue(ctx, global);
	return 0;
}

void js_init_color_proxy_module(JSContext *ctx) {
	js_color_proxy_init(ctx);
}

void register_proxy_color() {
	js_init_color_proxy_module(js_context());
}