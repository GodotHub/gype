#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/open_xr_action_map.hpp>
#include <godot_cpp/classes/open_xr_binding_modifier.hpp>
#include <godot_cpp/classes/panel_container.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/open_xr_binding_modifier_editor.hpp>
using namespace godot;

static void open_xr_binding_modifier_editor_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["OpenXRBindingModifierEditor"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef open_xr_binding_modifier_editor_class_def = {
    "OpenXRBindingModifierEditor",
    open_xr_binding_modifier_editor_class_finalizer
};

static JSValue open_xr_binding_modifier_editor_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["OpenXRBindingModifierEditor"];
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
        instance = memnew(OpenXRBindingModifierEditor);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue open_xr_binding_modifier_editor_class_get_binding_modifier(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRBindingModifierEditor::get_binding_modifier, ctx, this_val, argc, argv);
};
static JSValue open_xr_binding_modifier_editor_class_setup(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRBindingModifierEditor::setup, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry open_xr_binding_modifier_editor_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_binding_modifier", 0, &open_xr_binding_modifier_editor_class_get_binding_modifier),
	JS_CFUNC_DEF("setup", 2, &open_xr_binding_modifier_editor_class_setup),
};


static JSValue open_xr_binding_modifier_editor_class_get_binding_modifier_removed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "binding_modifier_removed");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}


static void define_open_xr_binding_modifier_editor_property(JSContext *ctx, JSValue proto) {
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "binding_modifier_removed"),
		JS_NewCFunction(ctx, open_xr_binding_modifier_editor_class_get_binding_modifier_removed_signal, "get_binding_modifier_removed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_open_xr_binding_modifier_editor_enum(JSContext *ctx, JSValue ctor) {
}

static int js_open_xr_binding_modifier_editor_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["OpenXRBindingModifierEditor"] = class_id;
	classes_by_id[class_id] = "OpenXRBindingModifierEditor";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &open_xr_binding_modifier_editor_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["PanelContainer"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_open_xr_binding_modifier_editor_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, open_xr_binding_modifier_editor_class_proto_funcs, _countof(open_xr_binding_modifier_editor_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, open_xr_binding_modifier_editor_class_constructor, "OpenXRBindingModifierEditor", 0, JS_CFUNC_constructor, 0);
	define_open_xr_binding_modifier_editor_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "OpenXRBindingModifierEditor", ctor);
	ctor_list["OpenXRBindingModifierEditor"] = ctor;

	return 0;
}

JSModuleDef *_js_init_open_xr_binding_modifier_editor_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/panel_container';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_open_xr_binding_modifier_editor_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "OpenXRBindingModifierEditor");
	return m;
}

JSModuleDef *js_init_open_xr_binding_modifier_editor_module(JSContext *ctx) {
	return _js_init_open_xr_binding_modifier_editor_module(ctx, "@godot/classes/open_xr_binding_modifier_editor");
}

void __register_open_xr_binding_modifier_editor() {
	js_init_open_xr_binding_modifier_editor_module(js_context());
}

void register_open_xr_binding_modifier_editor() {
	__register_open_xr_binding_modifier_editor();
}