#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/button_group.hpp>
#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/classes/shortcut.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/base_button.hpp>
using namespace godot;

static void base_button_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["BaseButton"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef base_button_class_def = {
    "BaseButton",
    base_button_class_finalizer
};

static JSValue base_button_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["BaseButton"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    BaseButton *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<BaseButton *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(BaseButton);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue base_button_class_set_pressed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseButton::set_pressed, ctx, this_val, argc, argv);
};
static JSValue base_button_class_is_pressed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseButton::is_pressed, ctx, this_val, argc, argv);
}
static JSValue base_button_class_set_pressed_no_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseButton::set_pressed_no_signal, ctx, this_val, argc, argv);
};
static JSValue base_button_class_is_hovered(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseButton::is_hovered, ctx, this_val, argc, argv);
};
static JSValue base_button_class_set_toggle_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseButton::set_toggle_mode, ctx, this_val, argc, argv);
};
static JSValue base_button_class_is_toggle_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseButton::is_toggle_mode, ctx, this_val, argc, argv);
}
static JSValue base_button_class_set_shortcut_in_tooltip(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseButton::set_shortcut_in_tooltip, ctx, this_val, argc, argv);
};
static JSValue base_button_class_is_shortcut_in_tooltip_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseButton::is_shortcut_in_tooltip_enabled, ctx, this_val, argc, argv);
}
static JSValue base_button_class_set_disabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseButton::set_disabled, ctx, this_val, argc, argv);
};
static JSValue base_button_class_is_disabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseButton::is_disabled, ctx, this_val, argc, argv);
}
static JSValue base_button_class_set_action_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseButton::set_action_mode, ctx, this_val, argc, argv);
};
static JSValue base_button_class_get_action_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseButton::get_action_mode, ctx, this_val, argc, argv);
}
static JSValue base_button_class_set_button_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseButton::set_button_mask, ctx, this_val, argc, argv);
};
static JSValue base_button_class_get_button_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseButton::get_button_mask, ctx, this_val, argc, argv);
}
static JSValue base_button_class_get_draw_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseButton::get_draw_mode, ctx, this_val, argc, argv);
};
static JSValue base_button_class_set_keep_pressed_outside(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseButton::set_keep_pressed_outside, ctx, this_val, argc, argv);
};
static JSValue base_button_class_is_keep_pressed_outside(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseButton::is_keep_pressed_outside, ctx, this_val, argc, argv);
}
static JSValue base_button_class_set_shortcut_feedback(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseButton::set_shortcut_feedback, ctx, this_val, argc, argv);
};
static JSValue base_button_class_is_shortcut_feedback(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseButton::is_shortcut_feedback, ctx, this_val, argc, argv);
}
static JSValue base_button_class_set_shortcut(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseButton::set_shortcut, ctx, this_val, argc, argv);
};
static JSValue base_button_class_get_shortcut(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseButton::get_shortcut, ctx, this_val, argc, argv);
}
static JSValue base_button_class_set_button_group(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseButton::set_button_group, ctx, this_val, argc, argv);
};
static JSValue base_button_class_get_button_group(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseButton::get_button_group, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry base_button_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_pressed", 1, &base_button_class_set_pressed),
	JS_CFUNC_DEF("is_pressed", 0, &base_button_class_is_pressed),
	JS_CFUNC_DEF("set_pressed_no_signal", 1, &base_button_class_set_pressed_no_signal),
	JS_CFUNC_DEF("is_hovered", 0, &base_button_class_is_hovered),
	JS_CFUNC_DEF("set_toggle_mode", 1, &base_button_class_set_toggle_mode),
	JS_CFUNC_DEF("is_toggle_mode", 0, &base_button_class_is_toggle_mode),
	JS_CFUNC_DEF("set_shortcut_in_tooltip", 1, &base_button_class_set_shortcut_in_tooltip),
	JS_CFUNC_DEF("is_shortcut_in_tooltip_enabled", 0, &base_button_class_is_shortcut_in_tooltip_enabled),
	JS_CFUNC_DEF("set_disabled", 1, &base_button_class_set_disabled),
	JS_CFUNC_DEF("is_disabled", 0, &base_button_class_is_disabled),
	JS_CFUNC_DEF("set_action_mode", 1, &base_button_class_set_action_mode),
	JS_CFUNC_DEF("get_action_mode", 0, &base_button_class_get_action_mode),
	JS_CFUNC_DEF("set_button_mask", 1, &base_button_class_set_button_mask),
	JS_CFUNC_DEF("get_button_mask", 0, &base_button_class_get_button_mask),
	JS_CFUNC_DEF("get_draw_mode", 0, &base_button_class_get_draw_mode),
	JS_CFUNC_DEF("set_keep_pressed_outside", 1, &base_button_class_set_keep_pressed_outside),
	JS_CFUNC_DEF("is_keep_pressed_outside", 0, &base_button_class_is_keep_pressed_outside),
	JS_CFUNC_DEF("set_shortcut_feedback", 1, &base_button_class_set_shortcut_feedback),
	JS_CFUNC_DEF("is_shortcut_feedback", 0, &base_button_class_is_shortcut_feedback),
	JS_CFUNC_DEF("set_shortcut", 1, &base_button_class_set_shortcut),
	JS_CFUNC_DEF("get_shortcut", 0, &base_button_class_get_shortcut),
	JS_CFUNC_DEF("set_button_group", 1, &base_button_class_set_button_group),
	JS_CFUNC_DEF("get_button_group", 0, &base_button_class_get_button_group),
};


static JSValue base_button_class_get_pressed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	BaseButton *opaque = static_cast<BaseButton *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "pressed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "pressed"));
		JS_DefinePropertyValueStr(ctx, this_val, "pressed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue base_button_class_get_button_up_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	BaseButton *opaque = static_cast<BaseButton *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "button_up_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "button_up"));
		JS_DefinePropertyValueStr(ctx, this_val, "button_up_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue base_button_class_get_button_down_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	BaseButton *opaque = static_cast<BaseButton *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "button_down_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "button_down"));
		JS_DefinePropertyValueStr(ctx, this_val, "button_down_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue base_button_class_get_toggled_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	BaseButton *opaque = static_cast<BaseButton *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "toggled_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "toggled"));
		JS_DefinePropertyValueStr(ctx, this_val, "toggled_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_base_button_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "disabled"),
        JS_NewCFunction(ctx, base_button_class_is_disabled, "is_disabled", 0),
        JS_NewCFunction(ctx, base_button_class_set_disabled, "set_disabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "toggle_mode"),
        JS_NewCFunction(ctx, base_button_class_is_toggle_mode, "is_toggle_mode", 0),
        JS_NewCFunction(ctx, base_button_class_set_toggle_mode, "set_toggle_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "button_pressed"),
        JS_NewCFunction(ctx, base_button_class_is_pressed, "is_pressed", 0),
        JS_NewCFunction(ctx, base_button_class_set_pressed, "set_pressed", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "action_mode"),
        JS_NewCFunction(ctx, base_button_class_get_action_mode, "get_action_mode", 0),
        JS_NewCFunction(ctx, base_button_class_set_action_mode, "set_action_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "button_mask"),
        JS_NewCFunction(ctx, base_button_class_get_button_mask, "get_button_mask", 0),
        JS_NewCFunction(ctx, base_button_class_set_button_mask, "set_button_mask", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "keep_pressed_outside"),
        JS_NewCFunction(ctx, base_button_class_is_keep_pressed_outside, "is_keep_pressed_outside", 0),
        JS_NewCFunction(ctx, base_button_class_set_keep_pressed_outside, "set_keep_pressed_outside", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "button_group"),
        JS_NewCFunction(ctx, base_button_class_get_button_group, "get_button_group", 0),
        JS_NewCFunction(ctx, base_button_class_set_button_group, "set_button_group", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "shortcut"),
        JS_NewCFunction(ctx, base_button_class_get_shortcut, "get_shortcut", 0),
        JS_NewCFunction(ctx, base_button_class_set_shortcut, "set_shortcut", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "shortcut_feedback"),
        JS_NewCFunction(ctx, base_button_class_is_shortcut_feedback, "is_shortcut_feedback", 0),
        JS_NewCFunction(ctx, base_button_class_set_shortcut_feedback, "set_shortcut_feedback", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "shortcut_in_tooltip"),
        JS_NewCFunction(ctx, base_button_class_is_shortcut_in_tooltip_enabled, "is_shortcut_in_tooltip_enabled", 0),
        JS_NewCFunction(ctx, base_button_class_set_shortcut_in_tooltip, "set_shortcut_in_tooltip", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "pressed"),
		JS_NewCFunction(ctx, base_button_class_get_pressed_signal, "get_pressed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "button_up"),
		JS_NewCFunction(ctx, base_button_class_get_button_up_signal, "get_button_up_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "button_down"),
		JS_NewCFunction(ctx, base_button_class_get_button_down_signal, "get_button_down_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "toggled"),
		JS_NewCFunction(ctx, base_button_class_get_toggled_signal, "get_toggled_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_base_button_enum(JSContext *ctx, JSValue ctor) {
	JSValue DrawMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, DrawMode_obj, "DRAW_NORMAL", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, DrawMode_obj, "DRAW_PRESSED", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, DrawMode_obj, "DRAW_HOVER", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, DrawMode_obj, "DRAW_DISABLED", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, DrawMode_obj, "DRAW_HOVER_PRESSED", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, ctor, "DrawMode", DrawMode_obj);
	JSValue ActionMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, ActionMode_obj, "ACTION_MODE_BUTTON_PRESS", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, ActionMode_obj, "ACTION_MODE_BUTTON_RELEASE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ctor, "ActionMode", ActionMode_obj);
}

static int js_base_button_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["BaseButton"] = class_id;
	classes_by_id[class_id] = "BaseButton";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &base_button_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Control"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_base_button_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, base_button_class_proto_funcs, _countof(base_button_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, base_button_class_constructor, "BaseButton", 0, JS_CFUNC_constructor, 0);
	define_base_button_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "BaseButton", ctor);

	return 0;
}

JSModuleDef *_js_init_base_button_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/control';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_base_button_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "BaseButton");
	return m;
}

JSModuleDef *js_init_base_button_module(JSContext *ctx) {
	return _js_init_base_button_module(ctx, "@godot/classes/base_button");
}

void __register_base_button() {
	js_init_base_button_module(js_context());
}

void register_base_button() {
	__register_base_button();
}