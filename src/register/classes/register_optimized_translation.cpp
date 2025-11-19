#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/translation.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/optimized_translation.hpp>
using namespace godot;

static void optimized_translation_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["OptimizedTranslation"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef optimized_translation_class_def = {
    "OptimizedTranslation",
    optimized_translation_class_finalizer
};

static JSValue optimized_translation_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["OptimizedTranslation"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    OptimizedTranslation *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<OptimizedTranslation *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(OptimizedTranslation);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue optimized_translation_class_generate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OptimizedTranslation::generate, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry optimized_translation_class_proto_funcs[] = {
	JS_CFUNC_DEF("generate", 1, &optimized_translation_class_generate),
};




static void define_optimized_translation_property(JSContext *ctx, JSValue proto) {
}

static void define_optimized_translation_enum(JSContext *ctx, JSValue ctor) {
}

static int js_optimized_translation_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["OptimizedTranslation"] = class_id;
	classes_by_id[class_id] = "OptimizedTranslation";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &optimized_translation_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Translation"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_optimized_translation_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, optimized_translation_class_proto_funcs, _countof(optimized_translation_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, optimized_translation_class_constructor, "OptimizedTranslation", 0, JS_CFUNC_constructor, 0);
	define_optimized_translation_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "OptimizedTranslation", ctor);

	return 0;
}

JSModuleDef *_js_init_optimized_translation_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/translation';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_optimized_translation_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "OptimizedTranslation");
	return m;
}

JSModuleDef *js_init_optimized_translation_module(JSContext *ctx) {
	return _js_init_optimized_translation_module(ctx, "@godot/classes/optimized_translation");
}

void __register_optimized_translation() {
	js_init_optimized_translation_module(js_context());
}

void register_optimized_translation() {
	__register_optimized_translation();
}