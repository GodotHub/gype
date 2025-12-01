#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/range.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/texture_progress_bar.hpp>
using namespace godot;

static void texture_progress_bar_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["TextureProgressBar"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef texture_progress_bar_class_def = {
    "TextureProgressBar",
    texture_progress_bar_class_finalizer
};

static JSValue texture_progress_bar_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["TextureProgressBar"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

	VariantAdapter *adapter = nullptr;
	Object *instance = nullptr;
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
    	instance = static_cast<VariantAdapter *>(JS_GetOpaque(*argv, class_id))->get();
		adapter = memnew(VariantAdapter(instance));
    } else {
        instance = memnew(TextureProgressBar);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue texture_progress_bar_class_set_under_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextureProgressBar::set_under_texture, ctx, this_val, argc, argv);
};
static JSValue texture_progress_bar_class_get_under_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextureProgressBar::get_under_texture, ctx, this_val, argc, argv);
}
static JSValue texture_progress_bar_class_set_progress_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextureProgressBar::set_progress_texture, ctx, this_val, argc, argv);
};
static JSValue texture_progress_bar_class_get_progress_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextureProgressBar::get_progress_texture, ctx, this_val, argc, argv);
}
static JSValue texture_progress_bar_class_set_over_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextureProgressBar::set_over_texture, ctx, this_val, argc, argv);
};
static JSValue texture_progress_bar_class_get_over_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextureProgressBar::get_over_texture, ctx, this_val, argc, argv);
}
static JSValue texture_progress_bar_class_set_fill_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextureProgressBar::set_fill_mode, ctx, this_val, argc, argv);
};
static JSValue texture_progress_bar_class_get_fill_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&TextureProgressBar::get_fill_mode, ctx, this_val, argc, argv);
}
static JSValue texture_progress_bar_class_set_tint_under(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextureProgressBar::set_tint_under, ctx, this_val, argc, argv);
};
static JSValue texture_progress_bar_class_get_tint_under(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		TextureProgressBar *obj = static_cast<TextureProgressBar *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_tint_under();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		TextureProgressBar *js_proxy = static_cast<TextureProgressBar *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_tint_under(value);
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
static JSValue texture_progress_bar_class_set_tint_progress(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextureProgressBar::set_tint_progress, ctx, this_val, argc, argv);
};
static JSValue texture_progress_bar_class_get_tint_progress(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		TextureProgressBar *obj = static_cast<TextureProgressBar *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_tint_progress();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		TextureProgressBar *js_proxy = static_cast<TextureProgressBar *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_tint_progress(value);
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
static JSValue texture_progress_bar_class_set_tint_over(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextureProgressBar::set_tint_over, ctx, this_val, argc, argv);
};
static JSValue texture_progress_bar_class_get_tint_over(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		TextureProgressBar *obj = static_cast<TextureProgressBar *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_tint_over();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		TextureProgressBar *js_proxy = static_cast<TextureProgressBar *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_tint_over(value);
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
static JSValue texture_progress_bar_class_set_texture_progress_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextureProgressBar::set_texture_progress_offset, ctx, this_val, argc, argv);
};
static JSValue texture_progress_bar_class_get_texture_progress_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		TextureProgressBar *obj = static_cast<TextureProgressBar *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_texture_progress_offset();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		TextureProgressBar *js_proxy = static_cast<TextureProgressBar *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_texture_progress_offset(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2Proxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue texture_progress_bar_class_set_radial_initial_angle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextureProgressBar::set_radial_initial_angle, ctx, this_val, argc, argv);
};
static JSValue texture_progress_bar_class_get_radial_initial_angle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&TextureProgressBar::get_radial_initial_angle, ctx, this_val, argc, argv);
}
static JSValue texture_progress_bar_class_set_radial_center_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextureProgressBar::set_radial_center_offset, ctx, this_val, argc, argv);
};
static JSValue texture_progress_bar_class_get_radial_center_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		TextureProgressBar *obj = static_cast<TextureProgressBar *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_radial_center_offset();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		TextureProgressBar *js_proxy = static_cast<TextureProgressBar *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_radial_center_offset(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2Proxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue texture_progress_bar_class_set_fill_degrees(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextureProgressBar::set_fill_degrees, ctx, this_val, argc, argv);
};
static JSValue texture_progress_bar_class_get_fill_degrees(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&TextureProgressBar::get_fill_degrees, ctx, this_val, argc, argv);
}
static JSValue texture_progress_bar_class_set_stretch_margin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextureProgressBar::set_stretch_margin, ctx, this_val, argc, argv);
};
static JSValue texture_progress_bar_class_get_stretch_margin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextureProgressBar::get_stretch_margin, ctx, this_val, argc, argv);
}
static JSValue texture_progress_bar_class_set_nine_patch_stretch(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TextureProgressBar::set_nine_patch_stretch, ctx, this_val, argc, argv);
};
static JSValue texture_progress_bar_class_get_nine_patch_stretch(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TextureProgressBar::get_nine_patch_stretch, ctx, this_val, argc, argv);
}

static JSValue texture_progress_bar_class_get_stretch_margin_left(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&TextureProgressBar::get_stretch_margin, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue texture_progress_bar_class_set_stretch_margin_left(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&TextureProgressBar::set_stretch_margin, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue texture_progress_bar_class_get_stretch_margin_top(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&TextureProgressBar::get_stretch_margin, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue texture_progress_bar_class_set_stretch_margin_top(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&TextureProgressBar::set_stretch_margin, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue texture_progress_bar_class_get_stretch_margin_right(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&TextureProgressBar::get_stretch_margin, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue texture_progress_bar_class_set_stretch_margin_right(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&TextureProgressBar::set_stretch_margin, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue texture_progress_bar_class_get_stretch_margin_bottom(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&TextureProgressBar::get_stretch_margin, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue texture_progress_bar_class_set_stretch_margin_bottom(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&TextureProgressBar::set_stretch_margin, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}


static const JSCFunctionListEntry texture_progress_bar_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_under_texture", 1, &texture_progress_bar_class_set_under_texture),
	JS_CFUNC_DEF("get_under_texture", 0, &texture_progress_bar_class_get_under_texture),
	JS_CFUNC_DEF("set_progress_texture", 1, &texture_progress_bar_class_set_progress_texture),
	JS_CFUNC_DEF("get_progress_texture", 0, &texture_progress_bar_class_get_progress_texture),
	JS_CFUNC_DEF("set_over_texture", 1, &texture_progress_bar_class_set_over_texture),
	JS_CFUNC_DEF("get_over_texture", 0, &texture_progress_bar_class_get_over_texture),
	JS_CFUNC_DEF("set_fill_mode", 1, &texture_progress_bar_class_set_fill_mode),
	JS_CFUNC_DEF("get_fill_mode", 0, &texture_progress_bar_class_get_fill_mode),
	JS_CFUNC_DEF("set_tint_under", 1, &texture_progress_bar_class_set_tint_under),
	JS_CFUNC_DEF("get_tint_under", 0, &texture_progress_bar_class_get_tint_under),
	JS_CFUNC_DEF("set_tint_progress", 1, &texture_progress_bar_class_set_tint_progress),
	JS_CFUNC_DEF("get_tint_progress", 0, &texture_progress_bar_class_get_tint_progress),
	JS_CFUNC_DEF("set_tint_over", 1, &texture_progress_bar_class_set_tint_over),
	JS_CFUNC_DEF("get_tint_over", 0, &texture_progress_bar_class_get_tint_over),
	JS_CFUNC_DEF("set_texture_progress_offset", 1, &texture_progress_bar_class_set_texture_progress_offset),
	JS_CFUNC_DEF("get_texture_progress_offset", 0, &texture_progress_bar_class_get_texture_progress_offset),
	JS_CFUNC_DEF("set_radial_initial_angle", 1, &texture_progress_bar_class_set_radial_initial_angle),
	JS_CFUNC_DEF("get_radial_initial_angle", 0, &texture_progress_bar_class_get_radial_initial_angle),
	JS_CFUNC_DEF("set_radial_center_offset", 1, &texture_progress_bar_class_set_radial_center_offset),
	JS_CFUNC_DEF("get_radial_center_offset", 0, &texture_progress_bar_class_get_radial_center_offset),
	JS_CFUNC_DEF("set_fill_degrees", 1, &texture_progress_bar_class_set_fill_degrees),
	JS_CFUNC_DEF("get_fill_degrees", 0, &texture_progress_bar_class_get_fill_degrees),
	JS_CFUNC_DEF("set_stretch_margin", 2, &texture_progress_bar_class_set_stretch_margin),
	JS_CFUNC_DEF("get_stretch_margin", 1, &texture_progress_bar_class_get_stretch_margin),
	JS_CFUNC_DEF("set_nine_patch_stretch", 1, &texture_progress_bar_class_set_nine_patch_stretch),
	JS_CFUNC_DEF("get_nine_patch_stretch", 0, &texture_progress_bar_class_get_nine_patch_stretch),
    JS_CFUNC_MAGIC_DEF("get_stretch_margin_top", 0, &texture_progress_bar_class_get_stretch_margin_top, 1),
    JS_CFUNC_MAGIC_DEF("set_stretch_margin_top", 1, &texture_progress_bar_class_set_stretch_margin_top, 1),
    JS_CFUNC_MAGIC_DEF("get_stretch_margin_right", 0, &texture_progress_bar_class_get_stretch_margin_right, 2),
    JS_CFUNC_MAGIC_DEF("set_stretch_margin_right", 1, &texture_progress_bar_class_set_stretch_margin_right, 2),
    JS_CFUNC_MAGIC_DEF("get_stretch_margin_bottom", 0, &texture_progress_bar_class_get_stretch_margin_bottom, 3),
    JS_CFUNC_MAGIC_DEF("set_stretch_margin_bottom", 1, &texture_progress_bar_class_set_stretch_margin_bottom, 3),
};




static void define_texture_progress_bar_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "fill_mode"),
        JS_NewCFunction(ctx, texture_progress_bar_class_get_fill_mode, "get_fill_mode", 0),
        JS_NewCFunction(ctx, texture_progress_bar_class_set_fill_mode, "set_fill_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "radial_initial_angle"),
        JS_NewCFunction(ctx, texture_progress_bar_class_get_radial_initial_angle, "get_radial_initial_angle", 0),
        JS_NewCFunction(ctx, texture_progress_bar_class_set_radial_initial_angle, "set_radial_initial_angle", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "radial_fill_degrees"),
        JS_NewCFunction(ctx, texture_progress_bar_class_get_fill_degrees, "get_fill_degrees", 0),
        JS_NewCFunction(ctx, texture_progress_bar_class_set_fill_degrees, "set_fill_degrees", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "radial_center_offset"),
        JS_NewCFunction(ctx, texture_progress_bar_class_get_radial_center_offset, "get_radial_center_offset", 0),
        JS_NewCFunction(ctx, texture_progress_bar_class_set_radial_center_offset, "set_radial_center_offset", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "nine_patch_stretch"),
        JS_NewCFunction(ctx, texture_progress_bar_class_get_nine_patch_stretch, "get_nine_patch_stretch", 0),
        JS_NewCFunction(ctx, texture_progress_bar_class_set_nine_patch_stretch, "set_nine_patch_stretch", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stretch_margin_left"),
		JS_NewCFunctionMagic(ctx, texture_progress_bar_class_get_stretch_margin_left, "get_stretch_margin_left", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 0),
		JS_NewCFunctionMagic(ctx, texture_progress_bar_class_set_stretch_margin_left, "set_stretch_margin_left", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 0),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stretch_margin_top"),
		JS_NewCFunctionMagic(ctx, texture_progress_bar_class_get_stretch_margin_top, "get_stretch_margin_top", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 1),
		JS_NewCFunctionMagic(ctx, texture_progress_bar_class_set_stretch_margin_top, "set_stretch_margin_top", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 1),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stretch_margin_right"),
		JS_NewCFunctionMagic(ctx, texture_progress_bar_class_get_stretch_margin_right, "get_stretch_margin_right", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 2),
		JS_NewCFunctionMagic(ctx, texture_progress_bar_class_set_stretch_margin_right, "set_stretch_margin_right", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 2),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "stretch_margin_bottom"),
		JS_NewCFunctionMagic(ctx, texture_progress_bar_class_get_stretch_margin_bottom, "get_stretch_margin_bottom", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 3),
		JS_NewCFunctionMagic(ctx, texture_progress_bar_class_set_stretch_margin_bottom, "set_stretch_margin_bottom", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 3),
		JS_PROP_GETSET
	);
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "texture_under"),
        JS_NewCFunction(ctx, texture_progress_bar_class_get_under_texture, "get_under_texture", 0),
        JS_NewCFunction(ctx, texture_progress_bar_class_set_under_texture, "set_under_texture", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "texture_over"),
        JS_NewCFunction(ctx, texture_progress_bar_class_get_over_texture, "get_over_texture", 0),
        JS_NewCFunction(ctx, texture_progress_bar_class_set_over_texture, "set_over_texture", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "texture_progress"),
        JS_NewCFunction(ctx, texture_progress_bar_class_get_progress_texture, "get_progress_texture", 0),
        JS_NewCFunction(ctx, texture_progress_bar_class_set_progress_texture, "set_progress_texture", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "texture_progress_offset"),
        JS_NewCFunction(ctx, texture_progress_bar_class_get_texture_progress_offset, "get_texture_progress_offset", 0),
        JS_NewCFunction(ctx, texture_progress_bar_class_set_texture_progress_offset, "set_texture_progress_offset", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "tint_under"),
        JS_NewCFunction(ctx, texture_progress_bar_class_get_tint_under, "get_tint_under", 0),
        JS_NewCFunction(ctx, texture_progress_bar_class_set_tint_under, "set_tint_under", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "tint_over"),
        JS_NewCFunction(ctx, texture_progress_bar_class_get_tint_over, "get_tint_over", 0),
        JS_NewCFunction(ctx, texture_progress_bar_class_set_tint_over, "set_tint_over", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "tint_progress"),
        JS_NewCFunction(ctx, texture_progress_bar_class_get_tint_progress, "get_tint_progress", 0),
        JS_NewCFunction(ctx, texture_progress_bar_class_set_tint_progress, "set_tint_progress", 1),
        JS_PROP_GETSET
    );
}

static void define_texture_progress_bar_enum(JSContext *ctx, JSValue ctor) {
	JSValue FillMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, FillMode_obj, "FILL_LEFT_TO_RIGHT", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, FillMode_obj, "FILL_RIGHT_TO_LEFT", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, FillMode_obj, "FILL_TOP_TO_BOTTOM", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, FillMode_obj, "FILL_BOTTOM_TO_TOP", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, FillMode_obj, "FILL_CLOCKWISE", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, FillMode_obj, "FILL_COUNTER_CLOCKWISE", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, FillMode_obj, "FILL_BILINEAR_LEFT_AND_RIGHT", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, FillMode_obj, "FILL_BILINEAR_TOP_AND_BOTTOM", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, FillMode_obj, "FILL_CLOCKWISE_AND_COUNTER_CLOCKWISE", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, ctor, "FillMode", FillMode_obj);
}

static int js_texture_progress_bar_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["TextureProgressBar"] = class_id;
	classes_by_id[class_id] = "TextureProgressBar";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &texture_progress_bar_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Range"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_texture_progress_bar_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, texture_progress_bar_class_proto_funcs, _countof(texture_progress_bar_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, texture_progress_bar_class_constructor, "TextureProgressBar", 0, JS_CFUNC_constructor, 0);
	define_texture_progress_bar_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "TextureProgressBar", ctor);
	ctor_list["TextureProgressBar"] = ctor;

	return 0;
}

JSModuleDef *_js_init_texture_progress_bar_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/range';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_texture_progress_bar_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "TextureProgressBar");
	return m;
}

JSModuleDef *js_init_texture_progress_bar_module(JSContext *ctx) {
	return _js_init_texture_progress_bar_module(ctx, "@godot/classes/texture_progress_bar");
}

void __register_texture_progress_bar() {
	js_init_texture_progress_bar_module(js_context());
}

void register_texture_progress_bar() {
	__register_texture_progress_bar();
}