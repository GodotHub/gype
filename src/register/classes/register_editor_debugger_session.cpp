#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/editor_debugger_session.hpp>
using namespace godot;

static void editor_debugger_session_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["EditorDebuggerSession"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef editor_debugger_session_class_def = {
    "EditorDebuggerSession",
    editor_debugger_session_class_finalizer
};

static JSValue editor_debugger_session_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["EditorDebuggerSession"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    EditorDebuggerSession *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<EditorDebuggerSession *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(EditorDebuggerSession);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue editor_debugger_session_class_send_message(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorDebuggerSession::send_message, ctx, this_val, argc, argv);
};
static JSValue editor_debugger_session_class_toggle_profiler(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorDebuggerSession::toggle_profiler, ctx, this_val, argc, argv);
};
static JSValue editor_debugger_session_class_is_breaked(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&EditorDebuggerSession::is_breaked, ctx, this_val, argc, argv);
};
static JSValue editor_debugger_session_class_is_debuggable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&EditorDebuggerSession::is_debuggable, ctx, this_val, argc, argv);
};
static JSValue editor_debugger_session_class_is_active(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&EditorDebuggerSession::is_active, ctx, this_val, argc, argv);
};
static JSValue editor_debugger_session_class_add_session_tab(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorDebuggerSession::add_session_tab, ctx, this_val, argc, argv);
};
static JSValue editor_debugger_session_class_remove_session_tab(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorDebuggerSession::remove_session_tab, ctx, this_val, argc, argv);
};
static JSValue editor_debugger_session_class_set_breakpoint(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorDebuggerSession::set_breakpoint, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry editor_debugger_session_class_proto_funcs[] = {
	JS_CFUNC_DEF("send_message", 2, &editor_debugger_session_class_send_message),
	JS_CFUNC_DEF("toggle_profiler", 3, &editor_debugger_session_class_toggle_profiler),
	JS_CFUNC_DEF("is_breaked", 0, &editor_debugger_session_class_is_breaked),
	JS_CFUNC_DEF("is_debuggable", 0, &editor_debugger_session_class_is_debuggable),
	JS_CFUNC_DEF("is_active", 0, &editor_debugger_session_class_is_active),
	JS_CFUNC_DEF("add_session_tab", 1, &editor_debugger_session_class_add_session_tab),
	JS_CFUNC_DEF("remove_session_tab", 1, &editor_debugger_session_class_remove_session_tab),
	JS_CFUNC_DEF("set_breakpoint", 3, &editor_debugger_session_class_set_breakpoint),
};


static JSValue editor_debugger_session_class_get_started_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	EditorDebuggerSession *opaque = static_cast<EditorDebuggerSession *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "started_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "started"));
		JS_DefinePropertyValueStr(ctx, this_val, "started_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue editor_debugger_session_class_get_stopped_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	EditorDebuggerSession *opaque = static_cast<EditorDebuggerSession *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "stopped_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "stopped"));
		JS_DefinePropertyValueStr(ctx, this_val, "stopped_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue editor_debugger_session_class_get_breaked_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	EditorDebuggerSession *opaque = static_cast<EditorDebuggerSession *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "breaked_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "breaked"));
		JS_DefinePropertyValueStr(ctx, this_val, "breaked_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue editor_debugger_session_class_get_continued_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	EditorDebuggerSession *opaque = static_cast<EditorDebuggerSession *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "continued_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "continued"));
		JS_DefinePropertyValueStr(ctx, this_val, "continued_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_editor_debugger_session_property(JSContext *ctx, JSValue proto) {
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "started"),
		JS_NewCFunction(ctx, editor_debugger_session_class_get_started_signal, "get_started_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "stopped"),
		JS_NewCFunction(ctx, editor_debugger_session_class_get_stopped_signal, "get_stopped_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "breaked"),
		JS_NewCFunction(ctx, editor_debugger_session_class_get_breaked_signal, "get_breaked_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "continued"),
		JS_NewCFunction(ctx, editor_debugger_session_class_get_continued_signal, "get_continued_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_editor_debugger_session_enum(JSContext *ctx, JSValue ctor) {
}

static int js_editor_debugger_session_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["EditorDebuggerSession"] = class_id;
	classes_by_id[class_id] = "EditorDebuggerSession";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &editor_debugger_session_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_editor_debugger_session_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, editor_debugger_session_class_proto_funcs, _countof(editor_debugger_session_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, editor_debugger_session_class_constructor, "EditorDebuggerSession", 0, JS_CFUNC_constructor, 0);
	define_editor_debugger_session_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "EditorDebuggerSession", ctor);

	return 0;
}

JSModuleDef *_js_init_editor_debugger_session_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_editor_debugger_session_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "EditorDebuggerSession");
	return m;
}

JSModuleDef *js_init_editor_debugger_session_module(JSContext *ctx) {
	return _js_init_editor_debugger_session_module(ctx, "@godot/classes/editor_debugger_session");
}

void __register_editor_debugger_session() {
	js_init_editor_debugger_session_module(js_context());
}

void register_editor_debugger_session() {
	__register_editor_debugger_session();
}