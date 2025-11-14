#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/button.hpp>
#include <godot_cpp/classes/label.hpp>
#include <godot_cpp/classes/line_edit.hpp>
#include <godot_cpp/classes/window.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/accept_dialog.hpp>
using namespace godot;

static void accept_dialog_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["AcceptDialog"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef accept_dialog_class_def = {
    "AcceptDialog",
    accept_dialog_class_finalizer
};

static JSValue accept_dialog_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["AcceptDialog"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    AcceptDialog *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<AcceptDialog *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(AcceptDialog);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue accept_dialog_class_get_ok_button(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&AcceptDialog::get_ok_button, ctx, this_val, argc, argv);
};
static JSValue accept_dialog_class_get_label(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&AcceptDialog::get_label, ctx, this_val, argc, argv);
};
static JSValue accept_dialog_class_set_hide_on_ok(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AcceptDialog::set_hide_on_ok, ctx, this_val, argc, argv);
};
static JSValue accept_dialog_class_get_hide_on_ok(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AcceptDialog::get_hide_on_ok, ctx, this_val, argc, argv);
}
static JSValue accept_dialog_class_set_close_on_escape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AcceptDialog::set_close_on_escape, ctx, this_val, argc, argv);
};
static JSValue accept_dialog_class_get_close_on_escape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AcceptDialog::get_close_on_escape, ctx, this_val, argc, argv);
}
static JSValue accept_dialog_class_add_button(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&AcceptDialog::add_button, ctx, this_val, argc, argv);
};
static JSValue accept_dialog_class_add_cancel_button(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&AcceptDialog::add_cancel_button, ctx, this_val, argc, argv);
};
static JSValue accept_dialog_class_remove_button(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AcceptDialog::remove_button, ctx, this_val, argc, argv);
};
static JSValue accept_dialog_class_register_text_enter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AcceptDialog::register_text_enter, ctx, this_val, argc, argv);
};
static JSValue accept_dialog_class_set_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AcceptDialog::set_text, ctx, this_val, argc, argv);
};
static JSValue accept_dialog_class_get_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<String> *proxy = memnew(ObjectProxy<String>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> String {
		AcceptDialog *obj = static_cast<AcceptDialog *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_text();
	};
	proxy->setter = [this_val](const String &value) -> void {
		AcceptDialog *js_proxy = static_cast<AcceptDialog *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_text(value);
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
static JSValue accept_dialog_class_set_autowrap(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AcceptDialog::set_autowrap, ctx, this_val, argc, argv);
};
static JSValue accept_dialog_class_has_autowrap(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&AcceptDialog::has_autowrap, ctx, this_val, argc, argv);
}
static JSValue accept_dialog_class_set_ok_button_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AcceptDialog::set_ok_button_text, ctx, this_val, argc, argv);
};
static JSValue accept_dialog_class_get_ok_button_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<String> *proxy = memnew(ObjectProxy<String>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> String {
		AcceptDialog *obj = static_cast<AcceptDialog *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_ok_button_text();
	};
	proxy->setter = [this_val](const String &value) -> void {
		AcceptDialog *js_proxy = static_cast<AcceptDialog *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_ok_button_text(value);
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

static const JSCFunctionListEntry accept_dialog_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_ok_button", 0, &accept_dialog_class_get_ok_button),
	JS_CFUNC_DEF("get_label", 0, &accept_dialog_class_get_label),
	JS_CFUNC_DEF("set_hide_on_ok", 1, &accept_dialog_class_set_hide_on_ok),
	JS_CFUNC_DEF("get_hide_on_ok", 0, &accept_dialog_class_get_hide_on_ok),
	JS_CFUNC_DEF("set_close_on_escape", 1, &accept_dialog_class_set_close_on_escape),
	JS_CFUNC_DEF("get_close_on_escape", 0, &accept_dialog_class_get_close_on_escape),
	JS_CFUNC_DEF("add_button", 3, &accept_dialog_class_add_button),
	JS_CFUNC_DEF("add_cancel_button", 1, &accept_dialog_class_add_cancel_button),
	JS_CFUNC_DEF("remove_button", 1, &accept_dialog_class_remove_button),
	JS_CFUNC_DEF("register_text_enter", 1, &accept_dialog_class_register_text_enter),
	JS_CFUNC_DEF("set_text", 1, &accept_dialog_class_set_text),
	JS_CFUNC_DEF("get_text", 0, &accept_dialog_class_get_text),
	JS_CFUNC_DEF("set_autowrap", 1, &accept_dialog_class_set_autowrap),
	JS_CFUNC_DEF("has_autowrap", 0, &accept_dialog_class_has_autowrap),
	JS_CFUNC_DEF("set_ok_button_text", 1, &accept_dialog_class_set_ok_button_text),
	JS_CFUNC_DEF("get_ok_button_text", 0, &accept_dialog_class_get_ok_button_text),
};


static JSValue accept_dialog_class_get_confirmed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	AcceptDialog *opaque = static_cast<AcceptDialog *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "confirmed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "confirmed"));
		JS_DefinePropertyValueStr(ctx, this_val, "confirmed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue accept_dialog_class_get_canceled_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	AcceptDialog *opaque = static_cast<AcceptDialog *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "canceled_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "canceled"));
		JS_DefinePropertyValueStr(ctx, this_val, "canceled_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue accept_dialog_class_get_custom_action_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	AcceptDialog *opaque = static_cast<AcceptDialog *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "custom_action_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "custom_action"));
		JS_DefinePropertyValueStr(ctx, this_val, "custom_action_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_accept_dialog_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "ok_button_text"),
        JS_NewCFunction(ctx, accept_dialog_class_get_ok_button_text, "get_ok_button_text", 0),
        JS_NewCFunction(ctx, accept_dialog_class_set_ok_button_text, "set_ok_button_text", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "dialog_text"),
        JS_NewCFunction(ctx, accept_dialog_class_get_text, "get_text", 0),
        JS_NewCFunction(ctx, accept_dialog_class_set_text, "set_text", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "dialog_hide_on_ok"),
        JS_NewCFunction(ctx, accept_dialog_class_get_hide_on_ok, "get_hide_on_ok", 0),
        JS_NewCFunction(ctx, accept_dialog_class_set_hide_on_ok, "set_hide_on_ok", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "dialog_close_on_escape"),
        JS_NewCFunction(ctx, accept_dialog_class_get_close_on_escape, "get_close_on_escape", 0),
        JS_NewCFunction(ctx, accept_dialog_class_set_close_on_escape, "set_close_on_escape", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "dialog_autowrap"),
        JS_NewCFunction(ctx, accept_dialog_class_has_autowrap, "has_autowrap", 0),
        JS_NewCFunction(ctx, accept_dialog_class_set_autowrap, "set_autowrap", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "confirmed"),
		JS_NewCFunction(ctx, accept_dialog_class_get_confirmed_signal, "get_confirmed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "canceled"),
		JS_NewCFunction(ctx, accept_dialog_class_get_canceled_signal, "get_canceled_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "custom_action"),
		JS_NewCFunction(ctx, accept_dialog_class_get_custom_action_signal, "get_custom_action_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_accept_dialog_enum(JSContext *ctx, JSValue proto) {
}

static int js_accept_dialog_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["AcceptDialog"] = class_id;
	classes_by_id[class_id] = "AcceptDialog";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &accept_dialog_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Window"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_accept_dialog_property(ctx, proto);
	define_accept_dialog_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, accept_dialog_class_proto_funcs, _countof(accept_dialog_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, accept_dialog_class_constructor, "AcceptDialog", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "AcceptDialog", ctor);

	return 0;
}

JSModuleDef *_js_init_accept_dialog_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/window';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_accept_dialog_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "AcceptDialog");
	return m;
}

JSModuleDef *js_init_accept_dialog_module(JSContext *ctx) {
	return _js_init_accept_dialog_module(ctx, "@godot/classes/accept_dialog");
}

void __register_accept_dialog() {
	js_init_accept_dialog_module(js_context());
}

void register_accept_dialog() {
	__register_accept_dialog();
}