#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/box_container.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/h_box_container.hpp>
using namespace godot;

static void h_box_container_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["HBoxContainer"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef h_box_container_class_def = {
    "HBoxContainer",
    h_box_container_class_finalizer
};

static JSValue h_box_container_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["HBoxContainer"];
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
        instance = memnew(HBoxContainer);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}








static void define_h_box_container_property(JSContext *ctx, JSValue proto) {
}

static void define_h_box_container_enum(JSContext *ctx, JSValue ctor) {
}

static int js_h_box_container_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["HBoxContainer"] = class_id;
	classes_by_id[class_id] = "HBoxContainer";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &h_box_container_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["BoxContainer"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_h_box_container_property(ctx, proto);
	JSValue ctor = JS_NewCFunction2(ctx, h_box_container_class_constructor, "HBoxContainer", 0, JS_CFUNC_constructor, 0);
	define_h_box_container_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "HBoxContainer", ctor);
	ctor_list["HBoxContainer"] = ctor;

	return 0;
}

JSModuleDef *_js_init_h_box_container_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/box_container';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_h_box_container_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "HBoxContainer");
	return m;
}

JSModuleDef *js_init_h_box_container_module(JSContext *ctx) {
	return _js_init_h_box_container_module(ctx, "@godot/classes/h_box_container");
}

void __register_h_box_container() {
	js_init_h_box_container_module(js_context());
}

void register_h_box_container() {
	__register_h_box_container();
}