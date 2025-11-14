#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/range.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/editor_spin_slider.hpp>
using namespace godot;

static void editor_spin_slider_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["EditorSpinSlider"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef editor_spin_slider_class_def = {
    "EditorSpinSlider",
    editor_spin_slider_class_finalizer
};

static JSValue editor_spin_slider_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["EditorSpinSlider"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    EditorSpinSlider *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<EditorSpinSlider *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(EditorSpinSlider);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue editor_spin_slider_class_set_label(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorSpinSlider::set_label, ctx, this_val, argc, argv);
};
static JSValue editor_spin_slider_class_get_label(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<String> *proxy = memnew(ObjectProxy<String>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> String {
		EditorSpinSlider *obj = static_cast<EditorSpinSlider *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_label();
	};
	proxy->setter = [this_val](const String &value) -> void {
		EditorSpinSlider *js_proxy = static_cast<EditorSpinSlider *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_label(value);
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
static JSValue editor_spin_slider_class_set_suffix(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorSpinSlider::set_suffix, ctx, this_val, argc, argv);
};
static JSValue editor_spin_slider_class_get_suffix(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<String> *proxy = memnew(ObjectProxy<String>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> String {
		EditorSpinSlider *obj = static_cast<EditorSpinSlider *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_suffix();
	};
	proxy->setter = [this_val](const String &value) -> void {
		EditorSpinSlider *js_proxy = static_cast<EditorSpinSlider *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_suffix(value);
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
static JSValue editor_spin_slider_class_set_read_only(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorSpinSlider::set_read_only, ctx, this_val, argc, argv);
};
static JSValue editor_spin_slider_class_is_read_only(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorSpinSlider::is_read_only, ctx, this_val, argc, argv);
}
static JSValue editor_spin_slider_class_set_flat(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorSpinSlider::set_flat, ctx, this_val, argc, argv);
};
static JSValue editor_spin_slider_class_is_flat(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorSpinSlider::is_flat, ctx, this_val, argc, argv);
}
static JSValue editor_spin_slider_class_set_hide_slider(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorSpinSlider::set_hide_slider, ctx, this_val, argc, argv);
};
static JSValue editor_spin_slider_class_is_hiding_slider(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorSpinSlider::is_hiding_slider, ctx, this_val, argc, argv);
}
static JSValue editor_spin_slider_class_set_editing_integer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorSpinSlider::set_editing_integer, ctx, this_val, argc, argv);
};
static JSValue editor_spin_slider_class_is_editing_integer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorSpinSlider::is_editing_integer, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry editor_spin_slider_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_label", 1, &editor_spin_slider_class_set_label),
	JS_CFUNC_DEF("get_label", 0, &editor_spin_slider_class_get_label),
	JS_CFUNC_DEF("set_suffix", 1, &editor_spin_slider_class_set_suffix),
	JS_CFUNC_DEF("get_suffix", 0, &editor_spin_slider_class_get_suffix),
	JS_CFUNC_DEF("set_read_only", 1, &editor_spin_slider_class_set_read_only),
	JS_CFUNC_DEF("is_read_only", 0, &editor_spin_slider_class_is_read_only),
	JS_CFUNC_DEF("set_flat", 1, &editor_spin_slider_class_set_flat),
	JS_CFUNC_DEF("is_flat", 0, &editor_spin_slider_class_is_flat),
	JS_CFUNC_DEF("set_hide_slider", 1, &editor_spin_slider_class_set_hide_slider),
	JS_CFUNC_DEF("is_hiding_slider", 0, &editor_spin_slider_class_is_hiding_slider),
	JS_CFUNC_DEF("set_editing_integer", 1, &editor_spin_slider_class_set_editing_integer),
	JS_CFUNC_DEF("is_editing_integer", 0, &editor_spin_slider_class_is_editing_integer),
};


static JSValue editor_spin_slider_class_get_grabbed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	EditorSpinSlider *opaque = static_cast<EditorSpinSlider *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "grabbed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "grabbed"));
		JS_DefinePropertyValueStr(ctx, this_val, "grabbed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue editor_spin_slider_class_get_ungrabbed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	EditorSpinSlider *opaque = static_cast<EditorSpinSlider *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "ungrabbed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "ungrabbed"));
		JS_DefinePropertyValueStr(ctx, this_val, "ungrabbed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue editor_spin_slider_class_get_updown_pressed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	EditorSpinSlider *opaque = static_cast<EditorSpinSlider *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "updown_pressed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "updown_pressed"));
		JS_DefinePropertyValueStr(ctx, this_val, "updown_pressed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue editor_spin_slider_class_get_value_focus_entered_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	EditorSpinSlider *opaque = static_cast<EditorSpinSlider *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "value_focus_entered_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "value_focus_entered"));
		JS_DefinePropertyValueStr(ctx, this_val, "value_focus_entered_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue editor_spin_slider_class_get_value_focus_exited_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	EditorSpinSlider *opaque = static_cast<EditorSpinSlider *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "value_focus_exited_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "value_focus_exited"));
		JS_DefinePropertyValueStr(ctx, this_val, "value_focus_exited_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_editor_spin_slider_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "label"),
        JS_NewCFunction(ctx, editor_spin_slider_class_get_label, "get_label", 0),
        JS_NewCFunction(ctx, editor_spin_slider_class_set_label, "set_label", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "suffix"),
        JS_NewCFunction(ctx, editor_spin_slider_class_get_suffix, "get_suffix", 0),
        JS_NewCFunction(ctx, editor_spin_slider_class_set_suffix, "set_suffix", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "read_only"),
        JS_NewCFunction(ctx, editor_spin_slider_class_is_read_only, "is_read_only", 0),
        JS_NewCFunction(ctx, editor_spin_slider_class_set_read_only, "set_read_only", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "flat"),
        JS_NewCFunction(ctx, editor_spin_slider_class_is_flat, "is_flat", 0),
        JS_NewCFunction(ctx, editor_spin_slider_class_set_flat, "set_flat", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "hide_slider"),
        JS_NewCFunction(ctx, editor_spin_slider_class_is_hiding_slider, "is_hiding_slider", 0),
        JS_NewCFunction(ctx, editor_spin_slider_class_set_hide_slider, "set_hide_slider", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "editing_integer"),
        JS_NewCFunction(ctx, editor_spin_slider_class_is_editing_integer, "is_editing_integer", 0),
        JS_NewCFunction(ctx, editor_spin_slider_class_set_editing_integer, "set_editing_integer", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "grabbed"),
		JS_NewCFunction(ctx, editor_spin_slider_class_get_grabbed_signal, "get_grabbed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "ungrabbed"),
		JS_NewCFunction(ctx, editor_spin_slider_class_get_ungrabbed_signal, "get_ungrabbed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "updown_pressed"),
		JS_NewCFunction(ctx, editor_spin_slider_class_get_updown_pressed_signal, "get_updown_pressed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "value_focus_entered"),
		JS_NewCFunction(ctx, editor_spin_slider_class_get_value_focus_entered_signal, "get_value_focus_entered_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "value_focus_exited"),
		JS_NewCFunction(ctx, editor_spin_slider_class_get_value_focus_exited_signal, "get_value_focus_exited_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_editor_spin_slider_enum(JSContext *ctx, JSValue proto) {
}

static int js_editor_spin_slider_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["EditorSpinSlider"] = class_id;
	classes_by_id[class_id] = "EditorSpinSlider";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &editor_spin_slider_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Range"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_editor_spin_slider_property(ctx, proto);
	define_editor_spin_slider_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, editor_spin_slider_class_proto_funcs, _countof(editor_spin_slider_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, editor_spin_slider_class_constructor, "EditorSpinSlider", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "EditorSpinSlider", ctor);

	return 0;
}

JSModuleDef *_js_init_editor_spin_slider_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/range';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_editor_spin_slider_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "EditorSpinSlider");
	return m;
}

JSModuleDef *js_init_editor_spin_slider_module(JSContext *ctx) {
	return _js_init_editor_spin_slider_module(ctx, "@godot/classes/editor_spin_slider");
}

void __register_editor_spin_slider() {
	js_init_editor_spin_slider_module(js_context());
}

void register_editor_spin_slider() {
	__register_editor_spin_slider();
}