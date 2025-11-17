#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/button.hpp>
#include <godot_cpp/classes/color_picker.hpp>
#include <godot_cpp/classes/popup_panel.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/color_picker_button.hpp>
using namespace godot;

static void color_picker_button_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["ColorPickerButton"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef color_picker_button_class_def = {
    "ColorPickerButton",
    color_picker_button_class_finalizer
};

static JSValue color_picker_button_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["ColorPickerButton"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    ColorPickerButton *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<ColorPickerButton *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(ColorPickerButton);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue color_picker_button_class_set_pick_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ColorPickerButton::set_pick_color, ctx, this_val, argc, argv);
};
static JSValue color_picker_button_class_get_pick_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		ColorPickerButton *obj = static_cast<ColorPickerButton *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_pick_color();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		ColorPickerButton *js_proxy = static_cast<ColorPickerButton *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_pick_color(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["ColorProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "ColorProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue color_picker_button_class_get_picker(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&ColorPickerButton::get_picker, ctx, this_val, argc, argv);
};
static JSValue color_picker_button_class_get_popup(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&ColorPickerButton::get_popup, ctx, this_val, argc, argv);
};
static JSValue color_picker_button_class_set_edit_alpha(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ColorPickerButton::set_edit_alpha, ctx, this_val, argc, argv);
};
static JSValue color_picker_button_class_is_editing_alpha(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ColorPickerButton::is_editing_alpha, ctx, this_val, argc, argv);
}
static JSValue color_picker_button_class_set_edit_intensity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ColorPickerButton::set_edit_intensity, ctx, this_val, argc, argv);
};
static JSValue color_picker_button_class_is_editing_intensity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ColorPickerButton::is_editing_intensity, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry color_picker_button_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_pick_color", 1, &color_picker_button_class_set_pick_color),
	JS_CFUNC_DEF("get_pick_color", 0, &color_picker_button_class_get_pick_color),
	JS_CFUNC_DEF("get_picker", 0, &color_picker_button_class_get_picker),
	JS_CFUNC_DEF("get_popup", 0, &color_picker_button_class_get_popup),
	JS_CFUNC_DEF("set_edit_alpha", 1, &color_picker_button_class_set_edit_alpha),
	JS_CFUNC_DEF("is_editing_alpha", 0, &color_picker_button_class_is_editing_alpha),
	JS_CFUNC_DEF("set_edit_intensity", 1, &color_picker_button_class_set_edit_intensity),
	JS_CFUNC_DEF("is_editing_intensity", 0, &color_picker_button_class_is_editing_intensity),
};


static JSValue color_picker_button_class_get_color_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ColorPickerButton *opaque = static_cast<ColorPickerButton *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "color_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "color_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "color_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue color_picker_button_class_get_popup_closed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ColorPickerButton *opaque = static_cast<ColorPickerButton *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "popup_closed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "popup_closed"));
		JS_DefinePropertyValueStr(ctx, this_val, "popup_closed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue color_picker_button_class_get_picker_created_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ColorPickerButton *opaque = static_cast<ColorPickerButton *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "picker_created_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "picker_created"));
		JS_DefinePropertyValueStr(ctx, this_val, "picker_created_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_color_picker_button_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "color"),
        JS_NewCFunction(ctx, color_picker_button_class_get_pick_color, "get_pick_color", 0),
        JS_NewCFunction(ctx, color_picker_button_class_set_pick_color, "set_pick_color", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "edit_alpha"),
        JS_NewCFunction(ctx, color_picker_button_class_is_editing_alpha, "is_editing_alpha", 0),
        JS_NewCFunction(ctx, color_picker_button_class_set_edit_alpha, "set_edit_alpha", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "edit_intensity"),
        JS_NewCFunction(ctx, color_picker_button_class_is_editing_intensity, "is_editing_intensity", 0),
        JS_NewCFunction(ctx, color_picker_button_class_set_edit_intensity, "set_edit_intensity", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "color_changed"),
		JS_NewCFunction(ctx, color_picker_button_class_get_color_changed_signal, "get_color_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "popup_closed"),
		JS_NewCFunction(ctx, color_picker_button_class_get_popup_closed_signal, "get_popup_closed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "picker_created"),
		JS_NewCFunction(ctx, color_picker_button_class_get_picker_created_signal, "get_picker_created_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_color_picker_button_enum(JSContext *ctx, JSValue ctor) {
}

static int js_color_picker_button_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["ColorPickerButton"] = class_id;
	classes_by_id[class_id] = "ColorPickerButton";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &color_picker_button_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Button"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_color_picker_button_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, color_picker_button_class_proto_funcs, _countof(color_picker_button_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, color_picker_button_class_constructor, "ColorPickerButton", 0, JS_CFUNC_constructor, 0);
	define_color_picker_button_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "ColorPickerButton", ctor);

	return 0;
}

JSModuleDef *_js_init_color_picker_button_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/button';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_color_picker_button_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "ColorPickerButton");
	return m;
}

JSModuleDef *js_init_color_picker_button_module(JSContext *ctx) {
	return _js_init_color_picker_button_module(ctx, "@godot/classes/color_picker_button");
}

void __register_color_picker_button() {
	js_init_color_picker_button_module(js_context());
}

void register_color_picker_button() {
	__register_color_picker_button();
}