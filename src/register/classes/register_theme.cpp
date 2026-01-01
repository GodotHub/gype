#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/font.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/classes/style_box.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/theme.hpp>
using namespace godot;

static void theme_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Theme"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef theme_class_def = {
    "Theme",
    theme_class_finalizer
};

static JSValue theme_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["Theme"];
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
        instance = memnew(Theme);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue theme_class_set_icon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Theme::set_icon, ctx, this_val, argc, argv);
};
static JSValue theme_class_get_icon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Theme::get_icon, ctx, this_val, argc, argv);
};
static JSValue theme_class_has_icon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Theme::has_icon, ctx, this_val, argc, argv);
};
static JSValue theme_class_rename_icon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Theme::rename_icon, ctx, this_val, argc, argv);
};
static JSValue theme_class_clear_icon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Theme::clear_icon, ctx, this_val, argc, argv);
};
static JSValue theme_class_get_icon_list(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Theme::get_icon_list, ctx, this_val, argc, argv);
};
static JSValue theme_class_get_icon_type_list(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Theme::get_icon_type_list, ctx, this_val, argc, argv);
};
static JSValue theme_class_set_stylebox(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Theme::set_stylebox, ctx, this_val, argc, argv);
};
static JSValue theme_class_get_stylebox(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Theme::get_stylebox, ctx, this_val, argc, argv);
};
static JSValue theme_class_has_stylebox(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Theme::has_stylebox, ctx, this_val, argc, argv);
};
static JSValue theme_class_rename_stylebox(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Theme::rename_stylebox, ctx, this_val, argc, argv);
};
static JSValue theme_class_clear_stylebox(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Theme::clear_stylebox, ctx, this_val, argc, argv);
};
static JSValue theme_class_get_stylebox_list(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Theme::get_stylebox_list, ctx, this_val, argc, argv);
};
static JSValue theme_class_get_stylebox_type_list(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Theme::get_stylebox_type_list, ctx, this_val, argc, argv);
};
static JSValue theme_class_set_font(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Theme::set_font, ctx, this_val, argc, argv);
};
static JSValue theme_class_get_font(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Theme::get_font, ctx, this_val, argc, argv);
};
static JSValue theme_class_has_font(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Theme::has_font, ctx, this_val, argc, argv);
};
static JSValue theme_class_rename_font(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Theme::rename_font, ctx, this_val, argc, argv);
};
static JSValue theme_class_clear_font(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Theme::clear_font, ctx, this_val, argc, argv);
};
static JSValue theme_class_get_font_list(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Theme::get_font_list, ctx, this_val, argc, argv);
};
static JSValue theme_class_get_font_type_list(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Theme::get_font_type_list, ctx, this_val, argc, argv);
};
static JSValue theme_class_set_font_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Theme::set_font_size, ctx, this_val, argc, argv);
};
static JSValue theme_class_get_font_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Theme::get_font_size, ctx, this_val, argc, argv);
};
static JSValue theme_class_has_font_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Theme::has_font_size, ctx, this_val, argc, argv);
};
static JSValue theme_class_rename_font_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Theme::rename_font_size, ctx, this_val, argc, argv);
};
static JSValue theme_class_clear_font_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Theme::clear_font_size, ctx, this_val, argc, argv);
};
static JSValue theme_class_get_font_size_list(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Theme::get_font_size_list, ctx, this_val, argc, argv);
};
static JSValue theme_class_get_font_size_type_list(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Theme::get_font_size_type_list, ctx, this_val, argc, argv);
};
static JSValue theme_class_set_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Theme::set_color, ctx, this_val, argc, argv);
};
static JSValue theme_class_get_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Theme::get_color, ctx, this_val, argc, argv);
};
static JSValue theme_class_has_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Theme::has_color, ctx, this_val, argc, argv);
};
static JSValue theme_class_rename_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Theme::rename_color, ctx, this_val, argc, argv);
};
static JSValue theme_class_clear_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Theme::clear_color, ctx, this_val, argc, argv);
};
static JSValue theme_class_get_color_list(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Theme::get_color_list, ctx, this_val, argc, argv);
};
static JSValue theme_class_get_color_type_list(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Theme::get_color_type_list, ctx, this_val, argc, argv);
};
static JSValue theme_class_set_constant(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Theme::set_constant, ctx, this_val, argc, argv);
};
static JSValue theme_class_get_constant(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Theme::get_constant, ctx, this_val, argc, argv);
};
static JSValue theme_class_has_constant(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Theme::has_constant, ctx, this_val, argc, argv);
};
static JSValue theme_class_rename_constant(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Theme::rename_constant, ctx, this_val, argc, argv);
};
static JSValue theme_class_clear_constant(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Theme::clear_constant, ctx, this_val, argc, argv);
};
static JSValue theme_class_get_constant_list(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Theme::get_constant_list, ctx, this_val, argc, argv);
};
static JSValue theme_class_get_constant_type_list(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Theme::get_constant_type_list, ctx, this_val, argc, argv);
};
static JSValue theme_class_set_default_base_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Theme::set_default_base_scale, ctx, this_val, argc, argv);
};
static JSValue theme_class_get_default_base_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Theme::get_default_base_scale, ctx, this_val, argc, argv);
}
static JSValue theme_class_has_default_base_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Theme::has_default_base_scale, ctx, this_val, argc, argv);
};
static JSValue theme_class_set_default_font(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Theme::set_default_font, ctx, this_val, argc, argv);
};
static JSValue theme_class_get_default_font(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Theme::get_default_font, ctx, this_val, argc, argv);
}
static JSValue theme_class_has_default_font(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Theme::has_default_font, ctx, this_val, argc, argv);
};
static JSValue theme_class_set_default_font_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Theme::set_default_font_size, ctx, this_val, argc, argv);
};
static JSValue theme_class_get_default_font_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Theme::get_default_font_size, ctx, this_val, argc, argv);
}
static JSValue theme_class_has_default_font_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Theme::has_default_font_size, ctx, this_val, argc, argv);
};
static JSValue theme_class_set_theme_item(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Theme::set_theme_item, ctx, this_val, argc, argv);
};
static JSValue theme_class_get_theme_item(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Theme::get_theme_item, ctx, this_val, argc, argv);
};
static JSValue theme_class_has_theme_item(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Theme::has_theme_item, ctx, this_val, argc, argv);
};
static JSValue theme_class_rename_theme_item(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Theme::rename_theme_item, ctx, this_val, argc, argv);
};
static JSValue theme_class_clear_theme_item(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Theme::clear_theme_item, ctx, this_val, argc, argv);
};
static JSValue theme_class_get_theme_item_list(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Theme::get_theme_item_list, ctx, this_val, argc, argv);
};
static JSValue theme_class_get_theme_item_type_list(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Theme::get_theme_item_type_list, ctx, this_val, argc, argv);
};
static JSValue theme_class_set_type_variation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Theme::set_type_variation, ctx, this_val, argc, argv);
};
static JSValue theme_class_is_type_variation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Theme::is_type_variation, ctx, this_val, argc, argv);
};
static JSValue theme_class_clear_type_variation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Theme::clear_type_variation, ctx, this_val, argc, argv);
};
static JSValue theme_class_get_type_variation_base(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Theme::get_type_variation_base, ctx, this_val, argc, argv);
};
static JSValue theme_class_get_type_variation_list(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Theme::get_type_variation_list, ctx, this_val, argc, argv);
};
static JSValue theme_class_add_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Theme::add_type, ctx, this_val, argc, argv);
};
static JSValue theme_class_remove_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Theme::remove_type, ctx, this_val, argc, argv);
};
static JSValue theme_class_rename_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Theme::rename_type, ctx, this_val, argc, argv);
};
static JSValue theme_class_get_type_list(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Theme::get_type_list, ctx, this_val, argc, argv);
};
static JSValue theme_class_merge_with(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Theme::merge_with, ctx, this_val, argc, argv);
};
static JSValue theme_class_clear(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Theme::clear, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry theme_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_icon", 3, &theme_class_set_icon),
	JS_CFUNC_DEF("get_icon", 2, &theme_class_get_icon),
	JS_CFUNC_DEF("has_icon", 2, &theme_class_has_icon),
	JS_CFUNC_DEF("rename_icon", 3, &theme_class_rename_icon),
	JS_CFUNC_DEF("clear_icon", 2, &theme_class_clear_icon),
	JS_CFUNC_DEF("get_icon_list", 1, &theme_class_get_icon_list),
	JS_CFUNC_DEF("get_icon_type_list", 0, &theme_class_get_icon_type_list),
	JS_CFUNC_DEF("set_stylebox", 3, &theme_class_set_stylebox),
	JS_CFUNC_DEF("get_stylebox", 2, &theme_class_get_stylebox),
	JS_CFUNC_DEF("has_stylebox", 2, &theme_class_has_stylebox),
	JS_CFUNC_DEF("rename_stylebox", 3, &theme_class_rename_stylebox),
	JS_CFUNC_DEF("clear_stylebox", 2, &theme_class_clear_stylebox),
	JS_CFUNC_DEF("get_stylebox_list", 1, &theme_class_get_stylebox_list),
	JS_CFUNC_DEF("get_stylebox_type_list", 0, &theme_class_get_stylebox_type_list),
	JS_CFUNC_DEF("set_font", 3, &theme_class_set_font),
	JS_CFUNC_DEF("get_font", 2, &theme_class_get_font),
	JS_CFUNC_DEF("has_font", 2, &theme_class_has_font),
	JS_CFUNC_DEF("rename_font", 3, &theme_class_rename_font),
	JS_CFUNC_DEF("clear_font", 2, &theme_class_clear_font),
	JS_CFUNC_DEF("get_font_list", 1, &theme_class_get_font_list),
	JS_CFUNC_DEF("get_font_type_list", 0, &theme_class_get_font_type_list),
	JS_CFUNC_DEF("set_font_size", 3, &theme_class_set_font_size),
	JS_CFUNC_DEF("get_font_size", 2, &theme_class_get_font_size),
	JS_CFUNC_DEF("has_font_size", 2, &theme_class_has_font_size),
	JS_CFUNC_DEF("rename_font_size", 3, &theme_class_rename_font_size),
	JS_CFUNC_DEF("clear_font_size", 2, &theme_class_clear_font_size),
	JS_CFUNC_DEF("get_font_size_list", 1, &theme_class_get_font_size_list),
	JS_CFUNC_DEF("get_font_size_type_list", 0, &theme_class_get_font_size_type_list),
	JS_CFUNC_DEF("set_color", 3, &theme_class_set_color),
	JS_CFUNC_DEF("get_color", 2, &theme_class_get_color),
	JS_CFUNC_DEF("has_color", 2, &theme_class_has_color),
	JS_CFUNC_DEF("rename_color", 3, &theme_class_rename_color),
	JS_CFUNC_DEF("clear_color", 2, &theme_class_clear_color),
	JS_CFUNC_DEF("get_color_list", 1, &theme_class_get_color_list),
	JS_CFUNC_DEF("get_color_type_list", 0, &theme_class_get_color_type_list),
	JS_CFUNC_DEF("set_constant", 3, &theme_class_set_constant),
	JS_CFUNC_DEF("get_constant", 2, &theme_class_get_constant),
	JS_CFUNC_DEF("has_constant", 2, &theme_class_has_constant),
	JS_CFUNC_DEF("rename_constant", 3, &theme_class_rename_constant),
	JS_CFUNC_DEF("clear_constant", 2, &theme_class_clear_constant),
	JS_CFUNC_DEF("get_constant_list", 1, &theme_class_get_constant_list),
	JS_CFUNC_DEF("get_constant_type_list", 0, &theme_class_get_constant_type_list),
	JS_CFUNC_DEF("set_default_base_scale", 1, &theme_class_set_default_base_scale),
	JS_CFUNC_DEF("get_default_base_scale", 0, &theme_class_get_default_base_scale),
	JS_CFUNC_DEF("has_default_base_scale", 0, &theme_class_has_default_base_scale),
	JS_CFUNC_DEF("set_default_font", 1, &theme_class_set_default_font),
	JS_CFUNC_DEF("get_default_font", 0, &theme_class_get_default_font),
	JS_CFUNC_DEF("has_default_font", 0, &theme_class_has_default_font),
	JS_CFUNC_DEF("set_default_font_size", 1, &theme_class_set_default_font_size),
	JS_CFUNC_DEF("get_default_font_size", 0, &theme_class_get_default_font_size),
	JS_CFUNC_DEF("has_default_font_size", 0, &theme_class_has_default_font_size),
	JS_CFUNC_DEF("set_theme_item", 4, &theme_class_set_theme_item),
	JS_CFUNC_DEF("get_theme_item", 3, &theme_class_get_theme_item),
	JS_CFUNC_DEF("has_theme_item", 3, &theme_class_has_theme_item),
	JS_CFUNC_DEF("rename_theme_item", 4, &theme_class_rename_theme_item),
	JS_CFUNC_DEF("clear_theme_item", 3, &theme_class_clear_theme_item),
	JS_CFUNC_DEF("get_theme_item_list", 2, &theme_class_get_theme_item_list),
	JS_CFUNC_DEF("get_theme_item_type_list", 1, &theme_class_get_theme_item_type_list),
	JS_CFUNC_DEF("set_type_variation", 2, &theme_class_set_type_variation),
	JS_CFUNC_DEF("is_type_variation", 2, &theme_class_is_type_variation),
	JS_CFUNC_DEF("clear_type_variation", 1, &theme_class_clear_type_variation),
	JS_CFUNC_DEF("get_type_variation_base", 1, &theme_class_get_type_variation_base),
	JS_CFUNC_DEF("get_type_variation_list", 1, &theme_class_get_type_variation_list),
	JS_CFUNC_DEF("add_type", 1, &theme_class_add_type),
	JS_CFUNC_DEF("remove_type", 1, &theme_class_remove_type),
	JS_CFUNC_DEF("rename_type", 2, &theme_class_rename_type),
	JS_CFUNC_DEF("get_type_list", 0, &theme_class_get_type_list),
	JS_CFUNC_DEF("merge_with", 1, &theme_class_merge_with),
	JS_CFUNC_DEF("clear", 0, &theme_class_clear),
};




static void define_theme_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "default_base_scale"),
        JS_NewCFunction(ctx, theme_class_get_default_base_scale, "get_default_base_scale", 0),
        JS_NewCFunction(ctx, theme_class_set_default_base_scale, "set_default_base_scale", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "default_font"),
        JS_NewCFunction(ctx, theme_class_get_default_font, "get_default_font", 0),
        JS_NewCFunction(ctx, theme_class_set_default_font, "set_default_font", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "default_font_size"),
        JS_NewCFunction(ctx, theme_class_get_default_font_size, "get_default_font_size", 0),
        JS_NewCFunction(ctx, theme_class_set_default_font_size, "set_default_font_size", 1),
        JS_PROP_GETSET
    );
}

static void define_theme_enum(JSContext *ctx, JSValue ctor) {
	JSValue DataType_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, DataType_obj, "DATA_TYPE_COLOR", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, DataType_obj, "DATA_TYPE_CONSTANT", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, DataType_obj, "DATA_TYPE_FONT", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, DataType_obj, "DATA_TYPE_FONT_SIZE", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, DataType_obj, "DATA_TYPE_ICON", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, DataType_obj, "DATA_TYPE_STYLEBOX", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, DataType_obj, "DATA_TYPE_MAX", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, ctor, "DataType", DataType_obj);
}

static int js_theme_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["Theme"] = class_id;
	classes_by_id[class_id] = "Theme";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &theme_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_theme_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, theme_class_proto_funcs, _countof(theme_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, theme_class_constructor, "Theme", 0, JS_CFUNC_constructor, 0);
	define_theme_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "Theme", ctor);
	ctor_list["Theme"] = ctor;

	return 0;
}

JSModuleDef *_js_init_theme_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_theme_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Theme");
	return m;
}

JSModuleDef *js_init_theme_module(JSContext *ctx) {
	return _js_init_theme_module(ctx, "@godot/classes/theme");
}

void __register_theme() {
	js_init_theme_module(js_context());
}

void register_theme() {
	__register_theme();
}