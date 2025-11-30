#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/window.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/popup.hpp>
using namespace godot;

static void popup_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Popup"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef popup_class_def = {
    "Popup",
    popup_class_finalizer
};

static JSValue popup_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["Popup"];
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
        instance = memnew(Popup);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}






static JSValue popup_class_get_popup_hide_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "popup_hide");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}


static void define_popup_property(JSContext *ctx, JSValue proto) {
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "popup_hide"),
		JS_NewCFunction(ctx, popup_class_get_popup_hide_signal, "get_popup_hide_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_popup_enum(JSContext *ctx, JSValue ctor) {
}

static int js_popup_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["Popup"] = class_id;
	classes_by_id[class_id] = "Popup";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &popup_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Window"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_popup_property(ctx, proto);
	JSValue ctor = JS_NewCFunction2(ctx, popup_class_constructor, "Popup", 0, JS_CFUNC_constructor, 0);
	define_popup_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "Popup", ctor);
	ctor_list["Popup"] = ctor;

	return 0;
}

JSModuleDef *_js_init_popup_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/window';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_popup_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Popup");
	return m;
}

JSModuleDef *js_init_popup_module(JSContext *ctx) {
	return _js_init_popup_module(ctx, "@godot/classes/popup");
}

void __register_popup() {
	js_init_popup_module(js_context());
}

void register_popup() {
	__register_popup();
}