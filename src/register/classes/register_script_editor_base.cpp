#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/classes/editor_syntax_highlighter.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/v_box_container.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/script_editor_base.hpp>
using namespace godot;

static void script_editor_base_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["ScriptEditorBase"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef script_editor_base_class_def = {
    "ScriptEditorBase",
    script_editor_base_class_finalizer
};

static JSValue script_editor_base_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["ScriptEditorBase"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    ScriptEditorBase *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<ScriptEditorBase *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(ScriptEditorBase);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue script_editor_base_class_get_base_editor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ScriptEditorBase::get_base_editor, ctx, this_val, argc, argv);
};
static JSValue script_editor_base_class_add_syntax_highlighter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ScriptEditorBase::add_syntax_highlighter, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry script_editor_base_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_base_editor", 0, &script_editor_base_class_get_base_editor),
	JS_CFUNC_DEF("add_syntax_highlighter", 1, &script_editor_base_class_add_syntax_highlighter),
};


static JSValue script_editor_base_class_get_name_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ScriptEditorBase *opaque = static_cast<ScriptEditorBase *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "name_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "name_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "name_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue script_editor_base_class_get_edited_script_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ScriptEditorBase *opaque = static_cast<ScriptEditorBase *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "edited_script_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "edited_script_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "edited_script_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue script_editor_base_class_get_request_help_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ScriptEditorBase *opaque = static_cast<ScriptEditorBase *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "request_help_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "request_help"));
		JS_DefinePropertyValueStr(ctx, this_val, "request_help_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue script_editor_base_class_get_request_open_script_at_line_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ScriptEditorBase *opaque = static_cast<ScriptEditorBase *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "request_open_script_at_line_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "request_open_script_at_line"));
		JS_DefinePropertyValueStr(ctx, this_val, "request_open_script_at_line_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue script_editor_base_class_get_request_save_history_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ScriptEditorBase *opaque = static_cast<ScriptEditorBase *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "request_save_history_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "request_save_history"));
		JS_DefinePropertyValueStr(ctx, this_val, "request_save_history_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue script_editor_base_class_get_request_save_previous_state_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ScriptEditorBase *opaque = static_cast<ScriptEditorBase *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "request_save_previous_state_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "request_save_previous_state"));
		JS_DefinePropertyValueStr(ctx, this_val, "request_save_previous_state_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue script_editor_base_class_get_go_to_help_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ScriptEditorBase *opaque = static_cast<ScriptEditorBase *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "go_to_help_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "go_to_help"));
		JS_DefinePropertyValueStr(ctx, this_val, "go_to_help_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue script_editor_base_class_get_search_in_files_requested_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ScriptEditorBase *opaque = static_cast<ScriptEditorBase *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "search_in_files_requested_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "search_in_files_requested"));
		JS_DefinePropertyValueStr(ctx, this_val, "search_in_files_requested_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue script_editor_base_class_get_replace_in_files_requested_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ScriptEditorBase *opaque = static_cast<ScriptEditorBase *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "replace_in_files_requested_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "replace_in_files_requested"));
		JS_DefinePropertyValueStr(ctx, this_val, "replace_in_files_requested_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue script_editor_base_class_get_go_to_method_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ScriptEditorBase *opaque = static_cast<ScriptEditorBase *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "go_to_method_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "go_to_method"));
		JS_DefinePropertyValueStr(ctx, this_val, "go_to_method_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_script_editor_base_property(JSContext *ctx, JSValue proto) {
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "name_changed"),
		JS_NewCFunction(ctx, script_editor_base_class_get_name_changed_signal, "get_name_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "edited_script_changed"),
		JS_NewCFunction(ctx, script_editor_base_class_get_edited_script_changed_signal, "get_edited_script_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "request_help"),
		JS_NewCFunction(ctx, script_editor_base_class_get_request_help_signal, "get_request_help_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "request_open_script_at_line"),
		JS_NewCFunction(ctx, script_editor_base_class_get_request_open_script_at_line_signal, "get_request_open_script_at_line_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "request_save_history"),
		JS_NewCFunction(ctx, script_editor_base_class_get_request_save_history_signal, "get_request_save_history_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "request_save_previous_state"),
		JS_NewCFunction(ctx, script_editor_base_class_get_request_save_previous_state_signal, "get_request_save_previous_state_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "go_to_help"),
		JS_NewCFunction(ctx, script_editor_base_class_get_go_to_help_signal, "get_go_to_help_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "search_in_files_requested"),
		JS_NewCFunction(ctx, script_editor_base_class_get_search_in_files_requested_signal, "get_search_in_files_requested_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "replace_in_files_requested"),
		JS_NewCFunction(ctx, script_editor_base_class_get_replace_in_files_requested_signal, "get_replace_in_files_requested_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "go_to_method"),
		JS_NewCFunction(ctx, script_editor_base_class_get_go_to_method_signal, "get_go_to_method_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_script_editor_base_enum(JSContext *ctx, JSValue ctor) {
}

static int js_script_editor_base_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["ScriptEditorBase"] = class_id;
	classes_by_id[class_id] = "ScriptEditorBase";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &script_editor_base_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["VBoxContainer"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_script_editor_base_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, script_editor_base_class_proto_funcs, _countof(script_editor_base_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, script_editor_base_class_constructor, "ScriptEditorBase", 0, JS_CFUNC_constructor, 0);
	define_script_editor_base_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "ScriptEditorBase", ctor);

	return 0;
}

JSModuleDef *_js_init_script_editor_base_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/v_box_container';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_script_editor_base_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "ScriptEditorBase");
	return m;
}

JSModuleDef *js_init_script_editor_base_module(JSContext *ctx) {
	return _js_init_script_editor_base_module(ctx, "@godot/classes/script_editor_base");
}

void __register_script_editor_base() {
	js_init_script_editor_base_module(js_context());
}

void register_script_editor_base() {
	__register_script_editor_base();
}