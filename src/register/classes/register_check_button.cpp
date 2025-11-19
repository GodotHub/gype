#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/button.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/check_button.hpp>
using namespace godot;

static void check_button_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["CheckButton"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef check_button_class_def = {
    "CheckButton",
    check_button_class_finalizer
};

static JSValue check_button_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["CheckButton"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    CheckButton *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<CheckButton *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(CheckButton);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}








static void define_check_button_property(JSContext *ctx, JSValue proto) {
}

static void define_check_button_enum(JSContext *ctx, JSValue ctor) {
}

static int js_check_button_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["CheckButton"] = class_id;
	classes_by_id[class_id] = "CheckButton";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &check_button_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Button"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_check_button_property(ctx, proto);
	JSValue ctor = JS_NewCFunction2(ctx, check_button_class_constructor, "CheckButton", 0, JS_CFUNC_constructor, 0);
	define_check_button_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "CheckButton", ctor);

	return 0;
}

JSModuleDef *_js_init_check_button_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/button';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_check_button_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "CheckButton");
	return m;
}

JSModuleDef *js_init_check_button_module(JSContext *ctx) {
	return _js_init_check_button_module(ctx, "@godot/classes/check_button");
}

void __register_check_button() {
	js_init_check_button_module(js_context());
}

void register_check_button() {
	__register_check_button();
}