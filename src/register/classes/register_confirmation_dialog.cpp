#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/accept_dialog.hpp>
#include <godot_cpp/classes/button.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/confirmation_dialog.hpp>
using namespace godot;

static void confirmation_dialog_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["ConfirmationDialog"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef confirmation_dialog_class_def = {
    "ConfirmationDialog",
    confirmation_dialog_class_finalizer
};

static JSValue confirmation_dialog_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["ConfirmationDialog"];
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
        instance = memnew(ConfirmationDialog);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue confirmation_dialog_class_get_cancel_button(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&ConfirmationDialog::get_cancel_button, ctx, this_val, argc, argv);
};
static JSValue confirmation_dialog_class_set_cancel_button_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ConfirmationDialog::set_cancel_button_text, ctx, this_val, argc, argv);
};
static JSValue confirmation_dialog_class_get_cancel_button_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ConfirmationDialog::get_cancel_button_text, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry confirmation_dialog_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_cancel_button", 0, &confirmation_dialog_class_get_cancel_button),
	JS_CFUNC_DEF("set_cancel_button_text", 1, &confirmation_dialog_class_set_cancel_button_text),
	JS_CFUNC_DEF("get_cancel_button_text", 0, &confirmation_dialog_class_get_cancel_button_text),
};




static void define_confirmation_dialog_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "cancel_button_text"),
        JS_NewCFunction(ctx, confirmation_dialog_class_get_cancel_button_text, "get_cancel_button_text", 0),
        JS_NewCFunction(ctx, confirmation_dialog_class_set_cancel_button_text, "set_cancel_button_text", 1),
        JS_PROP_GETSET
    );
}

static void define_confirmation_dialog_enum(JSContext *ctx, JSValue ctor) {
}

static int js_confirmation_dialog_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["ConfirmationDialog"] = class_id;
	classes_by_id[class_id] = "ConfirmationDialog";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &confirmation_dialog_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["AcceptDialog"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_confirmation_dialog_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, confirmation_dialog_class_proto_funcs, _countof(confirmation_dialog_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, confirmation_dialog_class_constructor, "ConfirmationDialog", 0, JS_CFUNC_constructor, 0);
	define_confirmation_dialog_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "ConfirmationDialog", ctor);
	ctor_list["ConfirmationDialog"] = ctor;

	return 0;
}

JSModuleDef *_js_init_confirmation_dialog_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/accept_dialog';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_confirmation_dialog_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "ConfirmationDialog");
	return m;
}

JSModuleDef *js_init_confirmation_dialog_module(JSContext *ctx) {
	return _js_init_confirmation_dialog_module(ctx, "@godot/classes/confirmation_dialog");
}

void __register_confirmation_dialog() {
	js_init_confirmation_dialog_module(js_context());
}

void register_confirmation_dialog() {
	__register_confirmation_dialog();
}