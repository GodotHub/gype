#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/confirmation_dialog.hpp>
#include <godot_cpp/classes/script.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/script_create_dialog.hpp>
using namespace godot;

static void script_create_dialog_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["ScriptCreateDialog"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef script_create_dialog_class_def = {
    "ScriptCreateDialog",
    script_create_dialog_class_finalizer
};

static JSValue script_create_dialog_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["ScriptCreateDialog"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    ScriptCreateDialog *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<ScriptCreateDialog *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(ScriptCreateDialog);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue script_create_dialog_class_config(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ScriptCreateDialog::config, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry script_create_dialog_class_proto_funcs[] = {
	JS_CFUNC_DEF("config", 4, &script_create_dialog_class_config),
};


static JSValue script_create_dialog_class_get_script_created_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ScriptCreateDialog *opaque = static_cast<ScriptCreateDialog *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "script_created_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "script_created"));
		JS_DefinePropertyValueStr(ctx, this_val, "script_created_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_script_create_dialog_property(JSContext *ctx, JSValue proto) {
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "script_created"),
		JS_NewCFunction(ctx, script_create_dialog_class_get_script_created_signal, "get_script_created_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_script_create_dialog_enum(JSContext *ctx, JSValue ctor) {
}

static int js_script_create_dialog_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["ScriptCreateDialog"] = class_id;
	classes_by_id[class_id] = "ScriptCreateDialog";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &script_create_dialog_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["ConfirmationDialog"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_script_create_dialog_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, script_create_dialog_class_proto_funcs, _countof(script_create_dialog_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, script_create_dialog_class_constructor, "ScriptCreateDialog", 0, JS_CFUNC_constructor, 0);
	define_script_create_dialog_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "ScriptCreateDialog", ctor);

	return 0;
}

JSModuleDef *_js_init_script_create_dialog_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/confirmation_dialog';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_script_create_dialog_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "ScriptCreateDialog");
	return m;
}

JSModuleDef *js_init_script_create_dialog_module(JSContext *ctx) {
	return _js_init_script_create_dialog_module(ctx, "@godot/classes/script_create_dialog");
}

void __register_script_create_dialog() {
	js_init_script_create_dialog_module(js_context());
}

void register_script_create_dialog() {
	__register_script_create_dialog();
}