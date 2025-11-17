#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/main_loop.hpp>
using namespace godot;

static void main_loop_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["MainLoop"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef main_loop_class_def = {
    "MainLoop",
    main_loop_class_finalizer
};

static JSValue main_loop_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["MainLoop"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    MainLoop *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<MainLoop *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(MainLoop);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}




static JSValue main_loop_class_get_on_request_permissions_result_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	MainLoop *opaque = static_cast<MainLoop *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "on_request_permissions_result_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "on_request_permissions_result"));
		JS_DefinePropertyValueStr(ctx, this_val, "on_request_permissions_result_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_main_loop_property(JSContext *ctx, JSValue proto) {
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "on_request_permissions_result"),
		JS_NewCFunction(ctx, main_loop_class_get_on_request_permissions_result_signal, "get_on_request_permissions_result_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_main_loop_enum(JSContext *ctx, JSValue ctor) {
}

static int js_main_loop_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["MainLoop"] = class_id;
	classes_by_id[class_id] = "MainLoop";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &main_loop_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["GodotObject"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_main_loop_property(ctx, proto);
	JSValue ctor = JS_NewCFunction2(ctx, main_loop_class_constructor, "MainLoop", 0, JS_CFUNC_constructor, 0);
	define_main_loop_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "MainLoop", ctor);

	return 0;
}

JSModuleDef *_js_init_main_loop_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/godot_object';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_main_loop_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "MainLoop");
	return m;
}

JSModuleDef *js_init_main_loop_module(JSContext *ctx) {
	return _js_init_main_loop_module(ctx, "@godot/classes/main_loop");
}

void __register_main_loop() {
	js_init_main_loop_module(js_context());
}

void register_main_loop() {
	__register_main_loop();
}