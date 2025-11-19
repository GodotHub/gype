#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/java_object.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/sub_viewport.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/open_xr_composition_layer.hpp>
using namespace godot;

static void open_xr_composition_layer_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["OpenXRCompositionLayer"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef open_xr_composition_layer_class_def = {
    "OpenXRCompositionLayer",
    open_xr_composition_layer_class_finalizer
};

static JSValue open_xr_composition_layer_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["OpenXRCompositionLayer"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    OpenXRCompositionLayer *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<OpenXRCompositionLayer *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(OpenXRCompositionLayer);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue open_xr_composition_layer_class_set_layer_viewport(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRCompositionLayer::set_layer_viewport, ctx, this_val, argc, argv);
};
static JSValue open_xr_composition_layer_class_get_layer_viewport(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRCompositionLayer::get_layer_viewport, ctx, this_val, argc, argv);
}
static JSValue open_xr_composition_layer_class_set_use_android_surface(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRCompositionLayer::set_use_android_surface, ctx, this_val, argc, argv);
};
static JSValue open_xr_composition_layer_class_get_use_android_surface(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRCompositionLayer::get_use_android_surface, ctx, this_val, argc, argv);
}
static JSValue open_xr_composition_layer_class_set_android_surface_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRCompositionLayer::set_android_surface_size, ctx, this_val, argc, argv);
};
static JSValue open_xr_composition_layer_class_get_android_surface_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2i> *proxy = memnew(ObjectProxy<Vector2i>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2i {
		OpenXRCompositionLayer *obj = static_cast<OpenXRCompositionLayer *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_android_surface_size();
	};
	proxy->setter = [this_val](const Vector2i &value) -> void {
		OpenXRCompositionLayer *js_proxy = static_cast<OpenXRCompositionLayer *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_android_surface_size(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2iProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2iProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue open_xr_composition_layer_class_set_enable_hole_punch(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRCompositionLayer::set_enable_hole_punch, ctx, this_val, argc, argv);
};
static JSValue open_xr_composition_layer_class_get_enable_hole_punch(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRCompositionLayer::get_enable_hole_punch, ctx, this_val, argc, argv);
}
static JSValue open_xr_composition_layer_class_set_sort_order(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRCompositionLayer::set_sort_order, ctx, this_val, argc, argv);
};
static JSValue open_xr_composition_layer_class_get_sort_order(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRCompositionLayer::get_sort_order, ctx, this_val, argc, argv);
}
static JSValue open_xr_composition_layer_class_set_alpha_blend(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRCompositionLayer::set_alpha_blend, ctx, this_val, argc, argv);
};
static JSValue open_xr_composition_layer_class_get_alpha_blend(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRCompositionLayer::get_alpha_blend, ctx, this_val, argc, argv);
}
static JSValue open_xr_composition_layer_class_get_android_surface(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&OpenXRCompositionLayer::get_android_surface, ctx, this_val, argc, argv);
};
static JSValue open_xr_composition_layer_class_is_natively_supported(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRCompositionLayer::is_natively_supported, ctx, this_val, argc, argv);
};
static JSValue open_xr_composition_layer_class_set_min_filter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRCompositionLayer::set_min_filter, ctx, this_val, argc, argv);
};
static JSValue open_xr_composition_layer_class_get_min_filter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRCompositionLayer::get_min_filter, ctx, this_val, argc, argv);
}
static JSValue open_xr_composition_layer_class_set_mag_filter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRCompositionLayer::set_mag_filter, ctx, this_val, argc, argv);
};
static JSValue open_xr_composition_layer_class_get_mag_filter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRCompositionLayer::get_mag_filter, ctx, this_val, argc, argv);
}
static JSValue open_xr_composition_layer_class_set_mipmap_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRCompositionLayer::set_mipmap_mode, ctx, this_val, argc, argv);
};
static JSValue open_xr_composition_layer_class_get_mipmap_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRCompositionLayer::get_mipmap_mode, ctx, this_val, argc, argv);
}
static JSValue open_xr_composition_layer_class_set_horizontal_wrap(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRCompositionLayer::set_horizontal_wrap, ctx, this_val, argc, argv);
};
static JSValue open_xr_composition_layer_class_get_horizontal_wrap(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRCompositionLayer::get_horizontal_wrap, ctx, this_val, argc, argv);
}
static JSValue open_xr_composition_layer_class_set_vertical_wrap(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRCompositionLayer::set_vertical_wrap, ctx, this_val, argc, argv);
};
static JSValue open_xr_composition_layer_class_get_vertical_wrap(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRCompositionLayer::get_vertical_wrap, ctx, this_val, argc, argv);
}
static JSValue open_xr_composition_layer_class_set_red_swizzle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRCompositionLayer::set_red_swizzle, ctx, this_val, argc, argv);
};
static JSValue open_xr_composition_layer_class_get_red_swizzle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRCompositionLayer::get_red_swizzle, ctx, this_val, argc, argv);
}
static JSValue open_xr_composition_layer_class_set_green_swizzle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRCompositionLayer::set_green_swizzle, ctx, this_val, argc, argv);
};
static JSValue open_xr_composition_layer_class_get_green_swizzle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRCompositionLayer::get_green_swizzle, ctx, this_val, argc, argv);
}
static JSValue open_xr_composition_layer_class_set_blue_swizzle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRCompositionLayer::set_blue_swizzle, ctx, this_val, argc, argv);
};
static JSValue open_xr_composition_layer_class_get_blue_swizzle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRCompositionLayer::get_blue_swizzle, ctx, this_val, argc, argv);
}
static JSValue open_xr_composition_layer_class_set_alpha_swizzle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRCompositionLayer::set_alpha_swizzle, ctx, this_val, argc, argv);
};
static JSValue open_xr_composition_layer_class_get_alpha_swizzle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRCompositionLayer::get_alpha_swizzle, ctx, this_val, argc, argv);
}
static JSValue open_xr_composition_layer_class_set_max_anisotropy(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRCompositionLayer::set_max_anisotropy, ctx, this_val, argc, argv);
};
static JSValue open_xr_composition_layer_class_get_max_anisotropy(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRCompositionLayer::get_max_anisotropy, ctx, this_val, argc, argv);
}
static JSValue open_xr_composition_layer_class_set_border_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRCompositionLayer::set_border_color, ctx, this_val, argc, argv);
};
static JSValue open_xr_composition_layer_class_get_border_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		OpenXRCompositionLayer *obj = static_cast<OpenXRCompositionLayer *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_border_color();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		OpenXRCompositionLayer *js_proxy = static_cast<OpenXRCompositionLayer *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_border_color(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["ColorProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "ColorProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue open_xr_composition_layer_class_intersects_ray(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRCompositionLayer::intersects_ray, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry open_xr_composition_layer_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_layer_viewport", 1, &open_xr_composition_layer_class_set_layer_viewport),
	JS_CFUNC_DEF("get_layer_viewport", 0, &open_xr_composition_layer_class_get_layer_viewport),
	JS_CFUNC_DEF("set_use_android_surface", 1, &open_xr_composition_layer_class_set_use_android_surface),
	JS_CFUNC_DEF("get_use_android_surface", 0, &open_xr_composition_layer_class_get_use_android_surface),
	JS_CFUNC_DEF("set_android_surface_size", 1, &open_xr_composition_layer_class_set_android_surface_size),
	JS_CFUNC_DEF("get_android_surface_size", 0, &open_xr_composition_layer_class_get_android_surface_size),
	JS_CFUNC_DEF("set_enable_hole_punch", 1, &open_xr_composition_layer_class_set_enable_hole_punch),
	JS_CFUNC_DEF("get_enable_hole_punch", 0, &open_xr_composition_layer_class_get_enable_hole_punch),
	JS_CFUNC_DEF("set_sort_order", 1, &open_xr_composition_layer_class_set_sort_order),
	JS_CFUNC_DEF("get_sort_order", 0, &open_xr_composition_layer_class_get_sort_order),
	JS_CFUNC_DEF("set_alpha_blend", 1, &open_xr_composition_layer_class_set_alpha_blend),
	JS_CFUNC_DEF("get_alpha_blend", 0, &open_xr_composition_layer_class_get_alpha_blend),
	JS_CFUNC_DEF("get_android_surface", 0, &open_xr_composition_layer_class_get_android_surface),
	JS_CFUNC_DEF("is_natively_supported", 0, &open_xr_composition_layer_class_is_natively_supported),
	JS_CFUNC_DEF("set_min_filter", 1, &open_xr_composition_layer_class_set_min_filter),
	JS_CFUNC_DEF("get_min_filter", 0, &open_xr_composition_layer_class_get_min_filter),
	JS_CFUNC_DEF("set_mag_filter", 1, &open_xr_composition_layer_class_set_mag_filter),
	JS_CFUNC_DEF("get_mag_filter", 0, &open_xr_composition_layer_class_get_mag_filter),
	JS_CFUNC_DEF("set_mipmap_mode", 1, &open_xr_composition_layer_class_set_mipmap_mode),
	JS_CFUNC_DEF("get_mipmap_mode", 0, &open_xr_composition_layer_class_get_mipmap_mode),
	JS_CFUNC_DEF("set_horizontal_wrap", 1, &open_xr_composition_layer_class_set_horizontal_wrap),
	JS_CFUNC_DEF("get_horizontal_wrap", 0, &open_xr_composition_layer_class_get_horizontal_wrap),
	JS_CFUNC_DEF("set_vertical_wrap", 1, &open_xr_composition_layer_class_set_vertical_wrap),
	JS_CFUNC_DEF("get_vertical_wrap", 0, &open_xr_composition_layer_class_get_vertical_wrap),
	JS_CFUNC_DEF("set_red_swizzle", 1, &open_xr_composition_layer_class_set_red_swizzle),
	JS_CFUNC_DEF("get_red_swizzle", 0, &open_xr_composition_layer_class_get_red_swizzle),
	JS_CFUNC_DEF("set_green_swizzle", 1, &open_xr_composition_layer_class_set_green_swizzle),
	JS_CFUNC_DEF("get_green_swizzle", 0, &open_xr_composition_layer_class_get_green_swizzle),
	JS_CFUNC_DEF("set_blue_swizzle", 1, &open_xr_composition_layer_class_set_blue_swizzle),
	JS_CFUNC_DEF("get_blue_swizzle", 0, &open_xr_composition_layer_class_get_blue_swizzle),
	JS_CFUNC_DEF("set_alpha_swizzle", 1, &open_xr_composition_layer_class_set_alpha_swizzle),
	JS_CFUNC_DEF("get_alpha_swizzle", 0, &open_xr_composition_layer_class_get_alpha_swizzle),
	JS_CFUNC_DEF("set_max_anisotropy", 1, &open_xr_composition_layer_class_set_max_anisotropy),
	JS_CFUNC_DEF("get_max_anisotropy", 0, &open_xr_composition_layer_class_get_max_anisotropy),
	JS_CFUNC_DEF("set_border_color", 1, &open_xr_composition_layer_class_set_border_color),
	JS_CFUNC_DEF("get_border_color", 0, &open_xr_composition_layer_class_get_border_color),
	JS_CFUNC_DEF("intersects_ray", 2, &open_xr_composition_layer_class_intersects_ray),
};




static void define_open_xr_composition_layer_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "layer_viewport"),
        JS_NewCFunction(ctx, open_xr_composition_layer_class_get_layer_viewport, "get_layer_viewport", 0),
        JS_NewCFunction(ctx, open_xr_composition_layer_class_set_layer_viewport, "set_layer_viewport", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "use_android_surface"),
        JS_NewCFunction(ctx, open_xr_composition_layer_class_get_use_android_surface, "get_use_android_surface", 0),
        JS_NewCFunction(ctx, open_xr_composition_layer_class_set_use_android_surface, "set_use_android_surface", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "android_surface_size"),
        JS_NewCFunction(ctx, open_xr_composition_layer_class_get_android_surface_size, "get_android_surface_size", 0),
        JS_NewCFunction(ctx, open_xr_composition_layer_class_set_android_surface_size, "set_android_surface_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "sort_order"),
        JS_NewCFunction(ctx, open_xr_composition_layer_class_get_sort_order, "get_sort_order", 0),
        JS_NewCFunction(ctx, open_xr_composition_layer_class_set_sort_order, "set_sort_order", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "alpha_blend"),
        JS_NewCFunction(ctx, open_xr_composition_layer_class_get_alpha_blend, "get_alpha_blend", 0),
        JS_NewCFunction(ctx, open_xr_composition_layer_class_set_alpha_blend, "set_alpha_blend", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "enable_hole_punch"),
        JS_NewCFunction(ctx, open_xr_composition_layer_class_get_enable_hole_punch, "get_enable_hole_punch", 0),
        JS_NewCFunction(ctx, open_xr_composition_layer_class_set_enable_hole_punch, "set_enable_hole_punch", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "swapchain_state_min_filter"),
        JS_NewCFunction(ctx, open_xr_composition_layer_class_get_min_filter, "get_min_filter", 0),
        JS_NewCFunction(ctx, open_xr_composition_layer_class_set_min_filter, "set_min_filter", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "swapchain_state_mag_filter"),
        JS_NewCFunction(ctx, open_xr_composition_layer_class_get_mag_filter, "get_mag_filter", 0),
        JS_NewCFunction(ctx, open_xr_composition_layer_class_set_mag_filter, "set_mag_filter", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "swapchain_state_mipmap_mode"),
        JS_NewCFunction(ctx, open_xr_composition_layer_class_get_mipmap_mode, "get_mipmap_mode", 0),
        JS_NewCFunction(ctx, open_xr_composition_layer_class_set_mipmap_mode, "set_mipmap_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "swapchain_state_horizontal_wrap"),
        JS_NewCFunction(ctx, open_xr_composition_layer_class_get_horizontal_wrap, "get_horizontal_wrap", 0),
        JS_NewCFunction(ctx, open_xr_composition_layer_class_set_horizontal_wrap, "set_horizontal_wrap", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "swapchain_state_vertical_wrap"),
        JS_NewCFunction(ctx, open_xr_composition_layer_class_get_vertical_wrap, "get_vertical_wrap", 0),
        JS_NewCFunction(ctx, open_xr_composition_layer_class_set_vertical_wrap, "set_vertical_wrap", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "swapchain_state_red_swizzle"),
        JS_NewCFunction(ctx, open_xr_composition_layer_class_get_red_swizzle, "get_red_swizzle", 0),
        JS_NewCFunction(ctx, open_xr_composition_layer_class_set_red_swizzle, "set_red_swizzle", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "swapchain_state_green_swizzle"),
        JS_NewCFunction(ctx, open_xr_composition_layer_class_get_green_swizzle, "get_green_swizzle", 0),
        JS_NewCFunction(ctx, open_xr_composition_layer_class_set_green_swizzle, "set_green_swizzle", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "swapchain_state_blue_swizzle"),
        JS_NewCFunction(ctx, open_xr_composition_layer_class_get_blue_swizzle, "get_blue_swizzle", 0),
        JS_NewCFunction(ctx, open_xr_composition_layer_class_set_blue_swizzle, "set_blue_swizzle", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "swapchain_state_alpha_swizzle"),
        JS_NewCFunction(ctx, open_xr_composition_layer_class_get_alpha_swizzle, "get_alpha_swizzle", 0),
        JS_NewCFunction(ctx, open_xr_composition_layer_class_set_alpha_swizzle, "set_alpha_swizzle", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "swapchain_state_max_anisotropy"),
        JS_NewCFunction(ctx, open_xr_composition_layer_class_get_max_anisotropy, "get_max_anisotropy", 0),
        JS_NewCFunction(ctx, open_xr_composition_layer_class_set_max_anisotropy, "set_max_anisotropy", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "swapchain_state_border_color"),
        JS_NewCFunction(ctx, open_xr_composition_layer_class_get_border_color, "get_border_color", 0),
        JS_NewCFunction(ctx, open_xr_composition_layer_class_set_border_color, "set_border_color", 1),
        JS_PROP_GETSET
    );
}

static void define_open_xr_composition_layer_enum(JSContext *ctx, JSValue ctor) {
	JSValue Filter_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, Filter_obj, "FILTER_NEAREST", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, Filter_obj, "FILTER_LINEAR", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, Filter_obj, "FILTER_CUBIC", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "Filter", Filter_obj);
	JSValue MipmapMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, MipmapMode_obj, "MIPMAP_MODE_DISABLED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, MipmapMode_obj, "MIPMAP_MODE_NEAREST", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, MipmapMode_obj, "MIPMAP_MODE_LINEAR", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "MipmapMode", MipmapMode_obj);
	JSValue Wrap_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, Wrap_obj, "WRAP_CLAMP_TO_BORDER", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, Wrap_obj, "WRAP_CLAMP_TO_EDGE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, Wrap_obj, "WRAP_REPEAT", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, Wrap_obj, "WRAP_MIRRORED_REPEAT", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, Wrap_obj, "WRAP_MIRROR_CLAMP_TO_EDGE", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, ctor, "Wrap", Wrap_obj);
	JSValue Swizzle_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, Swizzle_obj, "SWIZZLE_RED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, Swizzle_obj, "SWIZZLE_GREEN", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, Swizzle_obj, "SWIZZLE_BLUE", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, Swizzle_obj, "SWIZZLE_ALPHA", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, Swizzle_obj, "SWIZZLE_ZERO", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, Swizzle_obj, "SWIZZLE_ONE", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, ctor, "Swizzle", Swizzle_obj);
}

static int js_open_xr_composition_layer_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["OpenXRCompositionLayer"] = class_id;
	classes_by_id[class_id] = "OpenXRCompositionLayer";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &open_xr_composition_layer_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_open_xr_composition_layer_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, open_xr_composition_layer_class_proto_funcs, _countof(open_xr_composition_layer_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, open_xr_composition_layer_class_constructor, "OpenXRCompositionLayer", 0, JS_CFUNC_constructor, 0);
	define_open_xr_composition_layer_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "OpenXRCompositionLayer", ctor);

	return 0;
}

JSModuleDef *_js_init_open_xr_composition_layer_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_open_xr_composition_layer_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "OpenXRCompositionLayer");
	return m;
}

JSModuleDef *js_init_open_xr_composition_layer_module(JSContext *ctx) {
	return _js_init_open_xr_composition_layer_module(ctx, "@godot/classes/open_xr_composition_layer");
}

void __register_open_xr_composition_layer() {
	js_init_open_xr_composition_layer_module(js_context());
}

void register_open_xr_composition_layer() {
	__register_open_xr_composition_layer();
}