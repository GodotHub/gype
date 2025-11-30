#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/editor_syntax_highlighter.hpp>
#include <godot_cpp/classes/panel_container.hpp>
#include <godot_cpp/classes/script.hpp>
#include <godot_cpp/classes/script_editor_base.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/script_editor.hpp>
using namespace godot;

static void script_editor_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["ScriptEditor"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef script_editor_class_def = {
    "ScriptEditor",
    script_editor_class_finalizer
};

static JSValue script_editor_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["ScriptEditor"];
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
        instance = memnew(ScriptEditor);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue script_editor_class_get_current_editor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ScriptEditor::get_current_editor, ctx, this_val, argc, argv);
};
static JSValue script_editor_class_get_open_script_editors(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ScriptEditor::get_open_script_editors, ctx, this_val, argc, argv);
};
static JSValue script_editor_class_get_breakpoints(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&ScriptEditor::get_breakpoints, ctx, this_val, argc, argv);
};
static JSValue script_editor_class_register_syntax_highlighter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ScriptEditor::register_syntax_highlighter, ctx, this_val, argc, argv);
};
static JSValue script_editor_class_unregister_syntax_highlighter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ScriptEditor::unregister_syntax_highlighter, ctx, this_val, argc, argv);
};
static JSValue script_editor_class_goto_line(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ScriptEditor::goto_line, ctx, this_val, argc, argv);
};
static JSValue script_editor_class_get_current_script(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&ScriptEditor::get_current_script, ctx, this_val, argc, argv);
};
static JSValue script_editor_class_get_open_scripts(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ScriptEditor::get_open_scripts, ctx, this_val, argc, argv);
};
static JSValue script_editor_class_open_script_create_dialog(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ScriptEditor::open_script_create_dialog, ctx, this_val, argc, argv);
};
static JSValue script_editor_class_goto_help(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ScriptEditor::goto_help, ctx, this_val, argc, argv);
};
static JSValue script_editor_class_update_docs_from_script(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ScriptEditor::update_docs_from_script, ctx, this_val, argc, argv);
};
static JSValue script_editor_class_clear_docs_from_script(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ScriptEditor::clear_docs_from_script, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry script_editor_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_current_editor", 0, &script_editor_class_get_current_editor),
	JS_CFUNC_DEF("get_open_script_editors", 0, &script_editor_class_get_open_script_editors),
	JS_CFUNC_DEF("get_breakpoints", 0, &script_editor_class_get_breakpoints),
	JS_CFUNC_DEF("register_syntax_highlighter", 1, &script_editor_class_register_syntax_highlighter),
	JS_CFUNC_DEF("unregister_syntax_highlighter", 1, &script_editor_class_unregister_syntax_highlighter),
	JS_CFUNC_DEF("goto_line", 1, &script_editor_class_goto_line),
	JS_CFUNC_DEF("get_current_script", 0, &script_editor_class_get_current_script),
	JS_CFUNC_DEF("get_open_scripts", 0, &script_editor_class_get_open_scripts),
	JS_CFUNC_DEF("open_script_create_dialog", 2, &script_editor_class_open_script_create_dialog),
	JS_CFUNC_DEF("goto_help", 1, &script_editor_class_goto_help),
	JS_CFUNC_DEF("update_docs_from_script", 1, &script_editor_class_update_docs_from_script),
	JS_CFUNC_DEF("clear_docs_from_script", 1, &script_editor_class_clear_docs_from_script),
};


static JSValue script_editor_class_get_editor_script_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "editor_script_changed");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue script_editor_class_get_script_close_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "script_close");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}


static void define_script_editor_property(JSContext *ctx, JSValue proto) {
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "editor_script_changed"),
		JS_NewCFunction(ctx, script_editor_class_get_editor_script_changed_signal, "get_editor_script_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "script_close"),
		JS_NewCFunction(ctx, script_editor_class_get_script_close_signal, "get_script_close_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_script_editor_enum(JSContext *ctx, JSValue ctor) {
}

static int js_script_editor_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["ScriptEditor"] = class_id;
	classes_by_id[class_id] = "ScriptEditor";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &script_editor_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["PanelContainer"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_script_editor_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, script_editor_class_proto_funcs, _countof(script_editor_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, script_editor_class_constructor, "ScriptEditor", 0, JS_CFUNC_constructor, 0);
	define_script_editor_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "ScriptEditor", ctor);
	ctor_list["ScriptEditor"] = ctor;

	return 0;
}

JSModuleDef *_js_init_script_editor_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/panel_container';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_script_editor_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "ScriptEditor");
	return m;
}

JSModuleDef *js_init_script_editor_module(JSContext *ctx) {
	return _js_init_script_editor_module(ctx, "@godot/classes/script_editor");
}

void __register_script_editor() {
	js_init_script_editor_module(js_context());
}

void register_script_editor() {
	__register_script_editor();
}