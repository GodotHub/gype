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
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/label_settings.hpp>
using namespace godot;

static void label_settings_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["LabelSettings"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef label_settings_class_def = {
    "LabelSettings",
    label_settings_class_finalizer
};

static JSValue label_settings_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["LabelSettings"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    LabelSettings *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<LabelSettings *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(LabelSettings);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue label_settings_class_set_line_spacing(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LabelSettings::set_line_spacing, ctx, this_val, argc, argv);
};
static JSValue label_settings_class_get_line_spacing(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LabelSettings::get_line_spacing, ctx, this_val, argc, argv);
}
static JSValue label_settings_class_set_paragraph_spacing(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LabelSettings::set_paragraph_spacing, ctx, this_val, argc, argv);
};
static JSValue label_settings_class_get_paragraph_spacing(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LabelSettings::get_paragraph_spacing, ctx, this_val, argc, argv);
}
static JSValue label_settings_class_set_font(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LabelSettings::set_font, ctx, this_val, argc, argv);
};
static JSValue label_settings_class_get_font(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LabelSettings::get_font, ctx, this_val, argc, argv);
}
static JSValue label_settings_class_set_font_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LabelSettings::set_font_size, ctx, this_val, argc, argv);
};
static JSValue label_settings_class_get_font_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LabelSettings::get_font_size, ctx, this_val, argc, argv);
}
static JSValue label_settings_class_set_font_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LabelSettings::set_font_color, ctx, this_val, argc, argv);
};
static JSValue label_settings_class_get_font_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		LabelSettings *obj = static_cast<LabelSettings *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_font_color();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		LabelSettings *js_proxy = static_cast<LabelSettings *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_font_color(value);
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
static JSValue label_settings_class_set_outline_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LabelSettings::set_outline_size, ctx, this_val, argc, argv);
};
static JSValue label_settings_class_get_outline_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LabelSettings::get_outline_size, ctx, this_val, argc, argv);
}
static JSValue label_settings_class_set_outline_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LabelSettings::set_outline_color, ctx, this_val, argc, argv);
};
static JSValue label_settings_class_get_outline_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		LabelSettings *obj = static_cast<LabelSettings *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_outline_color();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		LabelSettings *js_proxy = static_cast<LabelSettings *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_outline_color(value);
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
static JSValue label_settings_class_set_shadow_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LabelSettings::set_shadow_size, ctx, this_val, argc, argv);
};
static JSValue label_settings_class_get_shadow_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LabelSettings::get_shadow_size, ctx, this_val, argc, argv);
}
static JSValue label_settings_class_set_shadow_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LabelSettings::set_shadow_color, ctx, this_val, argc, argv);
};
static JSValue label_settings_class_get_shadow_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		LabelSettings *obj = static_cast<LabelSettings *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_shadow_color();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		LabelSettings *js_proxy = static_cast<LabelSettings *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_shadow_color(value);
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
static JSValue label_settings_class_set_shadow_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LabelSettings::set_shadow_offset, ctx, this_val, argc, argv);
};
static JSValue label_settings_class_get_shadow_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		LabelSettings *obj = static_cast<LabelSettings *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_shadow_offset();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		LabelSettings *js_proxy = static_cast<LabelSettings *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_shadow_offset(value);
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
static JSValue label_settings_class_get_stacked_outline_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LabelSettings::get_stacked_outline_count, ctx, this_val, argc, argv);
}
static JSValue label_settings_class_set_stacked_outline_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LabelSettings::set_stacked_outline_count, ctx, this_val, argc, argv);
};
static JSValue label_settings_class_add_stacked_outline(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LabelSettings::add_stacked_outline, ctx, this_val, argc, argv);
};
static JSValue label_settings_class_move_stacked_outline(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LabelSettings::move_stacked_outline, ctx, this_val, argc, argv);
};
static JSValue label_settings_class_remove_stacked_outline(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LabelSettings::remove_stacked_outline, ctx, this_val, argc, argv);
};
static JSValue label_settings_class_set_stacked_outline_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LabelSettings::set_stacked_outline_size, ctx, this_val, argc, argv);
};
static JSValue label_settings_class_get_stacked_outline_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LabelSettings::get_stacked_outline_size, ctx, this_val, argc, argv);
};
static JSValue label_settings_class_set_stacked_outline_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LabelSettings::set_stacked_outline_color, ctx, this_val, argc, argv);
};
static JSValue label_settings_class_get_stacked_outline_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LabelSettings::get_stacked_outline_color, ctx, this_val, argc, argv);
};
static JSValue label_settings_class_get_stacked_shadow_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LabelSettings::get_stacked_shadow_count, ctx, this_val, argc, argv);
}
static JSValue label_settings_class_set_stacked_shadow_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LabelSettings::set_stacked_shadow_count, ctx, this_val, argc, argv);
};
static JSValue label_settings_class_add_stacked_shadow(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LabelSettings::add_stacked_shadow, ctx, this_val, argc, argv);
};
static JSValue label_settings_class_move_stacked_shadow(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LabelSettings::move_stacked_shadow, ctx, this_val, argc, argv);
};
static JSValue label_settings_class_remove_stacked_shadow(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LabelSettings::remove_stacked_shadow, ctx, this_val, argc, argv);
};
static JSValue label_settings_class_set_stacked_shadow_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LabelSettings::set_stacked_shadow_offset, ctx, this_val, argc, argv);
};
static JSValue label_settings_class_get_stacked_shadow_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LabelSettings::get_stacked_shadow_offset, ctx, this_val, argc, argv);
};
static JSValue label_settings_class_set_stacked_shadow_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LabelSettings::set_stacked_shadow_color, ctx, this_val, argc, argv);
};
static JSValue label_settings_class_get_stacked_shadow_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LabelSettings::get_stacked_shadow_color, ctx, this_val, argc, argv);
};
static JSValue label_settings_class_set_stacked_shadow_outline_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LabelSettings::set_stacked_shadow_outline_size, ctx, this_val, argc, argv);
};
static JSValue label_settings_class_get_stacked_shadow_outline_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LabelSettings::get_stacked_shadow_outline_size, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry label_settings_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_line_spacing", 1, &label_settings_class_set_line_spacing),
	JS_CFUNC_DEF("get_line_spacing", 0, &label_settings_class_get_line_spacing),
	JS_CFUNC_DEF("set_paragraph_spacing", 1, &label_settings_class_set_paragraph_spacing),
	JS_CFUNC_DEF("get_paragraph_spacing", 0, &label_settings_class_get_paragraph_spacing),
	JS_CFUNC_DEF("set_font", 1, &label_settings_class_set_font),
	JS_CFUNC_DEF("get_font", 0, &label_settings_class_get_font),
	JS_CFUNC_DEF("set_font_size", 1, &label_settings_class_set_font_size),
	JS_CFUNC_DEF("get_font_size", 0, &label_settings_class_get_font_size),
	JS_CFUNC_DEF("set_font_color", 1, &label_settings_class_set_font_color),
	JS_CFUNC_DEF("get_font_color", 0, &label_settings_class_get_font_color),
	JS_CFUNC_DEF("set_outline_size", 1, &label_settings_class_set_outline_size),
	JS_CFUNC_DEF("get_outline_size", 0, &label_settings_class_get_outline_size),
	JS_CFUNC_DEF("set_outline_color", 1, &label_settings_class_set_outline_color),
	JS_CFUNC_DEF("get_outline_color", 0, &label_settings_class_get_outline_color),
	JS_CFUNC_DEF("set_shadow_size", 1, &label_settings_class_set_shadow_size),
	JS_CFUNC_DEF("get_shadow_size", 0, &label_settings_class_get_shadow_size),
	JS_CFUNC_DEF("set_shadow_color", 1, &label_settings_class_set_shadow_color),
	JS_CFUNC_DEF("get_shadow_color", 0, &label_settings_class_get_shadow_color),
	JS_CFUNC_DEF("set_shadow_offset", 1, &label_settings_class_set_shadow_offset),
	JS_CFUNC_DEF("get_shadow_offset", 0, &label_settings_class_get_shadow_offset),
	JS_CFUNC_DEF("get_stacked_outline_count", 0, &label_settings_class_get_stacked_outline_count),
	JS_CFUNC_DEF("set_stacked_outline_count", 1, &label_settings_class_set_stacked_outline_count),
	JS_CFUNC_DEF("add_stacked_outline", 1, &label_settings_class_add_stacked_outline),
	JS_CFUNC_DEF("move_stacked_outline", 2, &label_settings_class_move_stacked_outline),
	JS_CFUNC_DEF("remove_stacked_outline", 1, &label_settings_class_remove_stacked_outline),
	JS_CFUNC_DEF("set_stacked_outline_size", 2, &label_settings_class_set_stacked_outline_size),
	JS_CFUNC_DEF("get_stacked_outline_size", 1, &label_settings_class_get_stacked_outline_size),
	JS_CFUNC_DEF("set_stacked_outline_color", 2, &label_settings_class_set_stacked_outline_color),
	JS_CFUNC_DEF("get_stacked_outline_color", 1, &label_settings_class_get_stacked_outline_color),
	JS_CFUNC_DEF("get_stacked_shadow_count", 0, &label_settings_class_get_stacked_shadow_count),
	JS_CFUNC_DEF("set_stacked_shadow_count", 1, &label_settings_class_set_stacked_shadow_count),
	JS_CFUNC_DEF("add_stacked_shadow", 1, &label_settings_class_add_stacked_shadow),
	JS_CFUNC_DEF("move_stacked_shadow", 2, &label_settings_class_move_stacked_shadow),
	JS_CFUNC_DEF("remove_stacked_shadow", 1, &label_settings_class_remove_stacked_shadow),
	JS_CFUNC_DEF("set_stacked_shadow_offset", 2, &label_settings_class_set_stacked_shadow_offset),
	JS_CFUNC_DEF("get_stacked_shadow_offset", 1, &label_settings_class_get_stacked_shadow_offset),
	JS_CFUNC_DEF("set_stacked_shadow_color", 2, &label_settings_class_set_stacked_shadow_color),
	JS_CFUNC_DEF("get_stacked_shadow_color", 1, &label_settings_class_get_stacked_shadow_color),
	JS_CFUNC_DEF("set_stacked_shadow_outline_size", 2, &label_settings_class_set_stacked_shadow_outline_size),
	JS_CFUNC_DEF("get_stacked_shadow_outline_size", 1, &label_settings_class_get_stacked_shadow_outline_size),
};




static void define_label_settings_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "line_spacing"),
        JS_NewCFunction(ctx, label_settings_class_get_line_spacing, "get_line_spacing", 0),
        JS_NewCFunction(ctx, label_settings_class_set_line_spacing, "set_line_spacing", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "paragraph_spacing"),
        JS_NewCFunction(ctx, label_settings_class_get_paragraph_spacing, "get_paragraph_spacing", 0),
        JS_NewCFunction(ctx, label_settings_class_set_paragraph_spacing, "set_paragraph_spacing", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "font"),
        JS_NewCFunction(ctx, label_settings_class_get_font, "get_font", 0),
        JS_NewCFunction(ctx, label_settings_class_set_font, "set_font", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "font_size"),
        JS_NewCFunction(ctx, label_settings_class_get_font_size, "get_font_size", 0),
        JS_NewCFunction(ctx, label_settings_class_set_font_size, "set_font_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "font_color"),
        JS_NewCFunction(ctx, label_settings_class_get_font_color, "get_font_color", 0),
        JS_NewCFunction(ctx, label_settings_class_set_font_color, "set_font_color", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "outline_size"),
        JS_NewCFunction(ctx, label_settings_class_get_outline_size, "get_outline_size", 0),
        JS_NewCFunction(ctx, label_settings_class_set_outline_size, "set_outline_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "outline_color"),
        JS_NewCFunction(ctx, label_settings_class_get_outline_color, "get_outline_color", 0),
        JS_NewCFunction(ctx, label_settings_class_set_outline_color, "set_outline_color", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "shadow_size"),
        JS_NewCFunction(ctx, label_settings_class_get_shadow_size, "get_shadow_size", 0),
        JS_NewCFunction(ctx, label_settings_class_set_shadow_size, "set_shadow_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "shadow_color"),
        JS_NewCFunction(ctx, label_settings_class_get_shadow_color, "get_shadow_color", 0),
        JS_NewCFunction(ctx, label_settings_class_set_shadow_color, "set_shadow_color", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "shadow_offset"),
        JS_NewCFunction(ctx, label_settings_class_get_shadow_offset, "get_shadow_offset", 0),
        JS_NewCFunction(ctx, label_settings_class_set_shadow_offset, "set_shadow_offset", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "stacked_outline_count"),
        JS_NewCFunction(ctx, label_settings_class_get_stacked_outline_count, "get_stacked_outline_count", 0),
        JS_NewCFunction(ctx, label_settings_class_set_stacked_outline_count, "set_stacked_outline_count", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "stacked_shadow_count"),
        JS_NewCFunction(ctx, label_settings_class_get_stacked_shadow_count, "get_stacked_shadow_count", 0),
        JS_NewCFunction(ctx, label_settings_class_set_stacked_shadow_count, "set_stacked_shadow_count", 1),
        JS_PROP_GETSET
    );
}

static void define_label_settings_enum(JSContext *ctx, JSValue ctor) {
}

static int js_label_settings_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["LabelSettings"] = class_id;
	classes_by_id[class_id] = "LabelSettings";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &label_settings_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_label_settings_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, label_settings_class_proto_funcs, _countof(label_settings_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, label_settings_class_constructor, "LabelSettings", 0, JS_CFUNC_constructor, 0);
	define_label_settings_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "LabelSettings", ctor);

	return 0;
}

JSModuleDef *_js_init_label_settings_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_label_settings_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "LabelSettings");
	return m;
}

JSModuleDef *js_init_label_settings_module(JSContext *ctx) {
	return _js_init_label_settings_module(ctx, "@godot/classes/label_settings");
}

void __register_label_settings() {
	js_init_label_settings_module(js_context());
}

void register_label_settings() {
	__register_label_settings();
}