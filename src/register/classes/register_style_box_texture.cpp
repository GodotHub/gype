#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/style_box.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/style_box_texture.hpp>
using namespace godot;

static void style_box_texture_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["StyleBoxTexture"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef style_box_texture_class_def = {
    "StyleBoxTexture",
    style_box_texture_class_finalizer
};

static JSValue style_box_texture_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["StyleBoxTexture"];
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
        instance = memnew(StyleBoxTexture);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue style_box_texture_class_set_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&StyleBoxTexture::set_texture, ctx, this_val, argc, argv);
};
static JSValue style_box_texture_class_get_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&StyleBoxTexture::get_texture, ctx, this_val, argc, argv);
}
static JSValue style_box_texture_class_set_texture_margin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&StyleBoxTexture::set_texture_margin, ctx, this_val, argc, argv);
};
static JSValue style_box_texture_class_set_texture_margin_all(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&StyleBoxTexture::set_texture_margin_all, ctx, this_val, argc, argv);
};
static JSValue style_box_texture_class_get_texture_margin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&StyleBoxTexture::get_texture_margin, ctx, this_val, argc, argv);
}
static JSValue style_box_texture_class_set_expand_margin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&StyleBoxTexture::set_expand_margin, ctx, this_val, argc, argv);
};
static JSValue style_box_texture_class_set_expand_margin_all(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&StyleBoxTexture::set_expand_margin_all, ctx, this_val, argc, argv);
};
static JSValue style_box_texture_class_get_expand_margin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&StyleBoxTexture::get_expand_margin, ctx, this_val, argc, argv);
}
static JSValue style_box_texture_class_set_region_rect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&StyleBoxTexture::set_region_rect, ctx, this_val, argc, argv);
};
static JSValue style_box_texture_class_get_region_rect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Rect2> *proxy = memnew(ObjectProxy<Rect2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Rect2 {
		StyleBoxTexture *obj = static_cast<StyleBoxTexture *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_region_rect();
	};
	proxy->setter = [this_val](const Rect2 &value) -> void {
		StyleBoxTexture *js_proxy = static_cast<StyleBoxTexture *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_region_rect(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Rect2Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Rect2Proxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue style_box_texture_class_set_draw_center(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&StyleBoxTexture::set_draw_center, ctx, this_val, argc, argv);
};
static JSValue style_box_texture_class_is_draw_center_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&StyleBoxTexture::is_draw_center_enabled, ctx, this_val, argc, argv);
}
static JSValue style_box_texture_class_set_modulate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&StyleBoxTexture::set_modulate, ctx, this_val, argc, argv);
};
static JSValue style_box_texture_class_get_modulate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		StyleBoxTexture *obj = static_cast<StyleBoxTexture *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_modulate();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		StyleBoxTexture *js_proxy = static_cast<StyleBoxTexture *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_modulate(value);
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
static JSValue style_box_texture_class_set_h_axis_stretch_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&StyleBoxTexture::set_h_axis_stretch_mode, ctx, this_val, argc, argv);
};
static JSValue style_box_texture_class_get_h_axis_stretch_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&StyleBoxTexture::get_h_axis_stretch_mode, ctx, this_val, argc, argv);
}
static JSValue style_box_texture_class_set_v_axis_stretch_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&StyleBoxTexture::set_v_axis_stretch_mode, ctx, this_val, argc, argv);
};
static JSValue style_box_texture_class_get_v_axis_stretch_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&StyleBoxTexture::get_v_axis_stretch_mode, ctx, this_val, argc, argv);
}

static JSValue style_box_texture_class_get_texture_margin_left(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&StyleBoxTexture::get_texture_margin, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue style_box_texture_class_set_texture_margin_left(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&StyleBoxTexture::set_texture_margin, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue style_box_texture_class_get_texture_margin_top(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&StyleBoxTexture::get_texture_margin, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue style_box_texture_class_set_texture_margin_top(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&StyleBoxTexture::set_texture_margin, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue style_box_texture_class_get_texture_margin_right(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&StyleBoxTexture::get_texture_margin, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue style_box_texture_class_set_texture_margin_right(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&StyleBoxTexture::set_texture_margin, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue style_box_texture_class_get_texture_margin_bottom(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&StyleBoxTexture::get_texture_margin, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue style_box_texture_class_set_texture_margin_bottom(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&StyleBoxTexture::set_texture_margin, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue style_box_texture_class_get_expand_margin_left(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&StyleBoxTexture::get_expand_margin, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue style_box_texture_class_set_expand_margin_left(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&StyleBoxTexture::set_expand_margin, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue style_box_texture_class_get_expand_margin_top(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&StyleBoxTexture::get_expand_margin, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue style_box_texture_class_set_expand_margin_top(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&StyleBoxTexture::set_expand_margin, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue style_box_texture_class_get_expand_margin_right(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&StyleBoxTexture::get_expand_margin, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue style_box_texture_class_set_expand_margin_right(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&StyleBoxTexture::set_expand_margin, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue style_box_texture_class_get_expand_margin_bottom(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&StyleBoxTexture::get_expand_margin, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue style_box_texture_class_set_expand_margin_bottom(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&StyleBoxTexture::set_expand_margin, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}


static const JSCFunctionListEntry style_box_texture_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_texture", 1, &style_box_texture_class_set_texture),
	JS_CFUNC_DEF("get_texture", 0, &style_box_texture_class_get_texture),
	JS_CFUNC_DEF("set_texture_margin", 2, &style_box_texture_class_set_texture_margin),
	JS_CFUNC_DEF("set_texture_margin_all", 1, &style_box_texture_class_set_texture_margin_all),
	JS_CFUNC_DEF("get_texture_margin", 1, &style_box_texture_class_get_texture_margin),
	JS_CFUNC_DEF("set_expand_margin", 2, &style_box_texture_class_set_expand_margin),
	JS_CFUNC_DEF("set_expand_margin_all", 1, &style_box_texture_class_set_expand_margin_all),
	JS_CFUNC_DEF("get_expand_margin", 1, &style_box_texture_class_get_expand_margin),
	JS_CFUNC_DEF("set_region_rect", 1, &style_box_texture_class_set_region_rect),
	JS_CFUNC_DEF("get_region_rect", 0, &style_box_texture_class_get_region_rect),
	JS_CFUNC_DEF("set_draw_center", 1, &style_box_texture_class_set_draw_center),
	JS_CFUNC_DEF("is_draw_center_enabled", 0, &style_box_texture_class_is_draw_center_enabled),
	JS_CFUNC_DEF("set_modulate", 1, &style_box_texture_class_set_modulate),
	JS_CFUNC_DEF("get_modulate", 0, &style_box_texture_class_get_modulate),
	JS_CFUNC_DEF("set_h_axis_stretch_mode", 1, &style_box_texture_class_set_h_axis_stretch_mode),
	JS_CFUNC_DEF("get_h_axis_stretch_mode", 0, &style_box_texture_class_get_h_axis_stretch_mode),
	JS_CFUNC_DEF("set_v_axis_stretch_mode", 1, &style_box_texture_class_set_v_axis_stretch_mode),
	JS_CFUNC_DEF("get_v_axis_stretch_mode", 0, &style_box_texture_class_get_v_axis_stretch_mode),
    JS_CFUNC_MAGIC_DEF("get_texture_margin_top", 0, &style_box_texture_class_get_texture_margin_top, 1),
    JS_CFUNC_MAGIC_DEF("set_texture_margin_top", 1, &style_box_texture_class_set_texture_margin_top, 1),
    JS_CFUNC_MAGIC_DEF("get_texture_margin_right", 0, &style_box_texture_class_get_texture_margin_right, 2),
    JS_CFUNC_MAGIC_DEF("set_texture_margin_right", 1, &style_box_texture_class_set_texture_margin_right, 2),
    JS_CFUNC_MAGIC_DEF("get_texture_margin_bottom", 0, &style_box_texture_class_get_texture_margin_bottom, 3),
    JS_CFUNC_MAGIC_DEF("set_texture_margin_bottom", 1, &style_box_texture_class_set_texture_margin_bottom, 3),
    JS_CFUNC_MAGIC_DEF("get_expand_margin_top", 0, &style_box_texture_class_get_expand_margin_top, 1),
    JS_CFUNC_MAGIC_DEF("set_expand_margin_top", 1, &style_box_texture_class_set_expand_margin_top, 1),
    JS_CFUNC_MAGIC_DEF("get_expand_margin_right", 0, &style_box_texture_class_get_expand_margin_right, 2),
    JS_CFUNC_MAGIC_DEF("set_expand_margin_right", 1, &style_box_texture_class_set_expand_margin_right, 2),
    JS_CFUNC_MAGIC_DEF("get_expand_margin_bottom", 0, &style_box_texture_class_get_expand_margin_bottom, 3),
    JS_CFUNC_MAGIC_DEF("set_expand_margin_bottom", 1, &style_box_texture_class_set_expand_margin_bottom, 3),
};




static void define_style_box_texture_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "texture"),
        JS_NewCFunction(ctx, style_box_texture_class_get_texture, "get_texture", 0),
        JS_NewCFunction(ctx, style_box_texture_class_set_texture, "set_texture", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "texture_margin_left"),
		JS_NewCFunctionMagic(ctx, style_box_texture_class_get_texture_margin_left, "get_texture_margin_left", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 0),
		JS_NewCFunctionMagic(ctx, style_box_texture_class_set_texture_margin_left, "set_texture_margin_left", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 0),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "texture_margin_top"),
		JS_NewCFunctionMagic(ctx, style_box_texture_class_get_texture_margin_top, "get_texture_margin_top", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 1),
		JS_NewCFunctionMagic(ctx, style_box_texture_class_set_texture_margin_top, "set_texture_margin_top", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 1),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "texture_margin_right"),
		JS_NewCFunctionMagic(ctx, style_box_texture_class_get_texture_margin_right, "get_texture_margin_right", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 2),
		JS_NewCFunctionMagic(ctx, style_box_texture_class_set_texture_margin_right, "set_texture_margin_right", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 2),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "texture_margin_bottom"),
		JS_NewCFunctionMagic(ctx, style_box_texture_class_get_texture_margin_bottom, "get_texture_margin_bottom", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 3),
		JS_NewCFunctionMagic(ctx, style_box_texture_class_set_texture_margin_bottom, "set_texture_margin_bottom", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 3),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "expand_margin_left"),
		JS_NewCFunctionMagic(ctx, style_box_texture_class_get_expand_margin_left, "get_expand_margin_left", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 0),
		JS_NewCFunctionMagic(ctx, style_box_texture_class_set_expand_margin_left, "set_expand_margin_left", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 0),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "expand_margin_top"),
		JS_NewCFunctionMagic(ctx, style_box_texture_class_get_expand_margin_top, "get_expand_margin_top", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 1),
		JS_NewCFunctionMagic(ctx, style_box_texture_class_set_expand_margin_top, "set_expand_margin_top", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 1),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "expand_margin_right"),
		JS_NewCFunctionMagic(ctx, style_box_texture_class_get_expand_margin_right, "get_expand_margin_right", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 2),
		JS_NewCFunctionMagic(ctx, style_box_texture_class_set_expand_margin_right, "set_expand_margin_right", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 2),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "expand_margin_bottom"),
		JS_NewCFunctionMagic(ctx, style_box_texture_class_get_expand_margin_bottom, "get_expand_margin_bottom", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 3),
		JS_NewCFunctionMagic(ctx, style_box_texture_class_set_expand_margin_bottom, "set_expand_margin_bottom", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 3),
		JS_PROP_GETSET
	);
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "axis_stretch_horizontal"),
        JS_NewCFunction(ctx, style_box_texture_class_get_h_axis_stretch_mode, "get_h_axis_stretch_mode", 0),
        JS_NewCFunction(ctx, style_box_texture_class_set_h_axis_stretch_mode, "set_h_axis_stretch_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "axis_stretch_vertical"),
        JS_NewCFunction(ctx, style_box_texture_class_get_v_axis_stretch_mode, "get_v_axis_stretch_mode", 0),
        JS_NewCFunction(ctx, style_box_texture_class_set_v_axis_stretch_mode, "set_v_axis_stretch_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "region_rect"),
        JS_NewCFunction(ctx, style_box_texture_class_get_region_rect, "get_region_rect", 0),
        JS_NewCFunction(ctx, style_box_texture_class_set_region_rect, "set_region_rect", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "modulate_color"),
        JS_NewCFunction(ctx, style_box_texture_class_get_modulate, "get_modulate", 0),
        JS_NewCFunction(ctx, style_box_texture_class_set_modulate, "set_modulate", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "draw_center"),
        JS_NewCFunction(ctx, style_box_texture_class_is_draw_center_enabled, "is_draw_center_enabled", 0),
        JS_NewCFunction(ctx, style_box_texture_class_set_draw_center, "set_draw_center", 1),
        JS_PROP_GETSET
    );
}

static void define_style_box_texture_enum(JSContext *ctx, JSValue ctor) {
	JSValue AxisStretchMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, AxisStretchMode_obj, "AXIS_STRETCH_MODE_STRETCH", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, AxisStretchMode_obj, "AXIS_STRETCH_MODE_TILE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, AxisStretchMode_obj, "AXIS_STRETCH_MODE_TILE_FIT", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "AxisStretchMode", AxisStretchMode_obj);
}

static int js_style_box_texture_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["StyleBoxTexture"] = class_id;
	classes_by_id[class_id] = "StyleBoxTexture";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &style_box_texture_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["StyleBox"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_style_box_texture_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, style_box_texture_class_proto_funcs, _countof(style_box_texture_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, style_box_texture_class_constructor, "StyleBoxTexture", 0, JS_CFUNC_constructor, 0);
	define_style_box_texture_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "StyleBoxTexture", ctor);
	ctor_list["StyleBoxTexture"] = ctor;

	return 0;
}

JSModuleDef *_js_init_style_box_texture_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/style_box';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_style_box_texture_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "StyleBoxTexture");
	return m;
}

JSModuleDef *js_init_style_box_texture_module(JSContext *ctx) {
	return _js_init_style_box_texture_module(ctx, "@godot/classes/style_box_texture");
}

void __register_style_box_texture() {
	js_init_style_box_texture_module(js_context());
}

void register_style_box_texture() {
	__register_style_box_texture();
}