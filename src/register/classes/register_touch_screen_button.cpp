#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/bit_map.hpp>
#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/shape2d.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/touch_screen_button.hpp>
using namespace godot;

static void touch_screen_button_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["TouchScreenButton"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef touch_screen_button_class_def = {
    "TouchScreenButton",
    touch_screen_button_class_finalizer
};

static JSValue touch_screen_button_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["TouchScreenButton"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    TouchScreenButton *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<TouchScreenButton *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(TouchScreenButton);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue touch_screen_button_class_set_texture_normal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TouchScreenButton::set_texture_normal, ctx, this_val, argc, argv);
};
static JSValue touch_screen_button_class_get_texture_normal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TouchScreenButton::get_texture_normal, ctx, this_val, argc, argv);
}
static JSValue touch_screen_button_class_set_texture_pressed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TouchScreenButton::set_texture_pressed, ctx, this_val, argc, argv);
};
static JSValue touch_screen_button_class_get_texture_pressed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TouchScreenButton::get_texture_pressed, ctx, this_val, argc, argv);
}
static JSValue touch_screen_button_class_set_bitmask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TouchScreenButton::set_bitmask, ctx, this_val, argc, argv);
};
static JSValue touch_screen_button_class_get_bitmask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TouchScreenButton::get_bitmask, ctx, this_val, argc, argv);
}
static JSValue touch_screen_button_class_set_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TouchScreenButton::set_shape, ctx, this_val, argc, argv);
};
static JSValue touch_screen_button_class_get_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TouchScreenButton::get_shape, ctx, this_val, argc, argv);
}
static JSValue touch_screen_button_class_set_shape_centered(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TouchScreenButton::set_shape_centered, ctx, this_val, argc, argv);
};
static JSValue touch_screen_button_class_is_shape_centered(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TouchScreenButton::is_shape_centered, ctx, this_val, argc, argv);
}
static JSValue touch_screen_button_class_set_shape_visible(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TouchScreenButton::set_shape_visible, ctx, this_val, argc, argv);
};
static JSValue touch_screen_button_class_is_shape_visible(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TouchScreenButton::is_shape_visible, ctx, this_val, argc, argv);
}
static JSValue touch_screen_button_class_set_action(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TouchScreenButton::set_action, ctx, this_val, argc, argv);
};
static JSValue touch_screen_button_class_get_action(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<String> *proxy = memnew(ObjectProxy<String>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> String {
		TouchScreenButton *obj = static_cast<TouchScreenButton *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_action();
	};
	proxy->setter = [this_val](const String &value) -> void {
		TouchScreenButton *js_proxy = static_cast<TouchScreenButton *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_action(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["StringProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "StringProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue touch_screen_button_class_set_visibility_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TouchScreenButton::set_visibility_mode, ctx, this_val, argc, argv);
};
static JSValue touch_screen_button_class_get_visibility_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TouchScreenButton::get_visibility_mode, ctx, this_val, argc, argv);
}
static JSValue touch_screen_button_class_set_passby_press(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&TouchScreenButton::set_passby_press, ctx, this_val, argc, argv);
};
static JSValue touch_screen_button_class_is_passby_press_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TouchScreenButton::is_passby_press_enabled, ctx, this_val, argc, argv);
}
static JSValue touch_screen_button_class_is_pressed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&TouchScreenButton::is_pressed, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry touch_screen_button_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_texture_normal", 1, &touch_screen_button_class_set_texture_normal),
	JS_CFUNC_DEF("get_texture_normal", 0, &touch_screen_button_class_get_texture_normal),
	JS_CFUNC_DEF("set_texture_pressed", 1, &touch_screen_button_class_set_texture_pressed),
	JS_CFUNC_DEF("get_texture_pressed", 0, &touch_screen_button_class_get_texture_pressed),
	JS_CFUNC_DEF("set_bitmask", 1, &touch_screen_button_class_set_bitmask),
	JS_CFUNC_DEF("get_bitmask", 0, &touch_screen_button_class_get_bitmask),
	JS_CFUNC_DEF("set_shape", 1, &touch_screen_button_class_set_shape),
	JS_CFUNC_DEF("get_shape", 0, &touch_screen_button_class_get_shape),
	JS_CFUNC_DEF("set_shape_centered", 1, &touch_screen_button_class_set_shape_centered),
	JS_CFUNC_DEF("is_shape_centered", 0, &touch_screen_button_class_is_shape_centered),
	JS_CFUNC_DEF("set_shape_visible", 1, &touch_screen_button_class_set_shape_visible),
	JS_CFUNC_DEF("is_shape_visible", 0, &touch_screen_button_class_is_shape_visible),
	JS_CFUNC_DEF("set_action", 1, &touch_screen_button_class_set_action),
	JS_CFUNC_DEF("get_action", 0, &touch_screen_button_class_get_action),
	JS_CFUNC_DEF("set_visibility_mode", 1, &touch_screen_button_class_set_visibility_mode),
	JS_CFUNC_DEF("get_visibility_mode", 0, &touch_screen_button_class_get_visibility_mode),
	JS_CFUNC_DEF("set_passby_press", 1, &touch_screen_button_class_set_passby_press),
	JS_CFUNC_DEF("is_passby_press_enabled", 0, &touch_screen_button_class_is_passby_press_enabled),
	JS_CFUNC_DEF("is_pressed", 0, &touch_screen_button_class_is_pressed),
};


static JSValue touch_screen_button_class_get_pressed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	TouchScreenButton *opaque = static_cast<TouchScreenButton *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "pressed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "pressed"));
		JS_DefinePropertyValueStr(ctx, this_val, "pressed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue touch_screen_button_class_get_released_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	TouchScreenButton *opaque = static_cast<TouchScreenButton *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "released_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "released"));
		JS_DefinePropertyValueStr(ctx, this_val, "released_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_touch_screen_button_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "texture_normal"),
        JS_NewCFunction(ctx, touch_screen_button_class_get_texture_normal, "get_texture_normal", 0),
        JS_NewCFunction(ctx, touch_screen_button_class_set_texture_normal, "set_texture_normal", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "texture_pressed"),
        JS_NewCFunction(ctx, touch_screen_button_class_get_texture_pressed, "get_texture_pressed", 0),
        JS_NewCFunction(ctx, touch_screen_button_class_set_texture_pressed, "set_texture_pressed", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "bitmask"),
        JS_NewCFunction(ctx, touch_screen_button_class_get_bitmask, "get_bitmask", 0),
        JS_NewCFunction(ctx, touch_screen_button_class_set_bitmask, "set_bitmask", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "shape"),
        JS_NewCFunction(ctx, touch_screen_button_class_get_shape, "get_shape", 0),
        JS_NewCFunction(ctx, touch_screen_button_class_set_shape, "set_shape", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "shape_centered"),
        JS_NewCFunction(ctx, touch_screen_button_class_is_shape_centered, "is_shape_centered", 0),
        JS_NewCFunction(ctx, touch_screen_button_class_set_shape_centered, "set_shape_centered", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "shape_visible"),
        JS_NewCFunction(ctx, touch_screen_button_class_is_shape_visible, "is_shape_visible", 0),
        JS_NewCFunction(ctx, touch_screen_button_class_set_shape_visible, "set_shape_visible", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "passby_press"),
        JS_NewCFunction(ctx, touch_screen_button_class_is_passby_press_enabled, "is_passby_press_enabled", 0),
        JS_NewCFunction(ctx, touch_screen_button_class_set_passby_press, "set_passby_press", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "action"),
        JS_NewCFunction(ctx, touch_screen_button_class_get_action, "get_action", 0),
        JS_NewCFunction(ctx, touch_screen_button_class_set_action, "set_action", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "visibility_mode"),
        JS_NewCFunction(ctx, touch_screen_button_class_get_visibility_mode, "get_visibility_mode", 0),
        JS_NewCFunction(ctx, touch_screen_button_class_set_visibility_mode, "set_visibility_mode", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "pressed"),
		JS_NewCFunction(ctx, touch_screen_button_class_get_pressed_signal, "get_pressed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "released"),
		JS_NewCFunction(ctx, touch_screen_button_class_get_released_signal, "get_released_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_touch_screen_button_enum(JSContext *ctx, JSValue proto) {
	JSValue VisibilityMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, VisibilityMode_obj, "VISIBILITY_ALWAYS", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, VisibilityMode_obj, "VISIBILITY_TOUCHSCREEN_ONLY", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, proto, "VisibilityMode", VisibilityMode_obj);
}

static int js_touch_screen_button_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["TouchScreenButton"] = class_id;
	classes_by_id[class_id] = "TouchScreenButton";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &touch_screen_button_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node2D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_touch_screen_button_property(ctx, proto);
	define_touch_screen_button_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, touch_screen_button_class_proto_funcs, _countof(touch_screen_button_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, touch_screen_button_class_constructor, "TouchScreenButton", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "TouchScreenButton", ctor);

	return 0;
}

JSModuleDef *_js_init_touch_screen_button_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node2d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_touch_screen_button_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "TouchScreenButton");
	return m;
}

JSModuleDef *js_init_touch_screen_button_module(JSContext *ctx) {
	return _js_init_touch_screen_button_module(ctx, "@godot/classes/touch_screen_button");
}

void __register_touch_screen_button() {
	js_init_touch_screen_button_module(js_context());
}

void register_touch_screen_button() {
	__register_touch_screen_button();
}