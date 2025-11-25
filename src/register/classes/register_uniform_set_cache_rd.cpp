#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/rd_uniform.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/uniform_set_cache_rd.hpp>
using namespace godot;

static void uniform_set_cache_rd_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["UniformSetCacheRD"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef uniform_set_cache_rd_class_def = {
    "UniformSetCacheRD",
    uniform_set_cache_rd_class_finalizer
};

static JSValue uniform_set_cache_rd_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["UniformSetCacheRD"];
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
        instance = memnew(UniformSetCacheRD);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}



static JSValue uniform_set_cache_rd_class_get_cache(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&UniformSetCacheRD::get_cache, ctx, this_val, argc, argv);
};


static const JSCFunctionListEntry uniform_set_cache_rd_class_static_funcs[] = {
	JS_CFUNC_DEF("get_cache", 3, &uniform_set_cache_rd_class_get_cache),
};



static void define_uniform_set_cache_rd_property(JSContext *ctx, JSValue proto) {
}

static void define_uniform_set_cache_rd_enum(JSContext *ctx, JSValue ctor) {
}

static int js_uniform_set_cache_rd_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["UniformSetCacheRD"] = class_id;
	classes_by_id[class_id] = "UniformSetCacheRD";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &uniform_set_cache_rd_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["GodotObject"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_uniform_set_cache_rd_property(ctx, proto);
	JSValue ctor = JS_NewCFunction2(ctx, uniform_set_cache_rd_class_constructor, "UniformSetCacheRD", 0, JS_CFUNC_constructor, 0);
	JS_SetPropertyFunctionList(ctx, ctor, uniform_set_cache_rd_class_static_funcs, _countof(uniform_set_cache_rd_class_static_funcs));
	define_uniform_set_cache_rd_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "UniformSetCacheRD", ctor);
	ctor_list["UniformSetCacheRD"] = ctor;

	return 0;
}

JSModuleDef *_js_init_uniform_set_cache_rd_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/godot_object';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_uniform_set_cache_rd_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "UniformSetCacheRD");
	return m;
}

JSModuleDef *js_init_uniform_set_cache_rd_module(JSContext *ctx) {
	return _js_init_uniform_set_cache_rd_module(ctx, "@godot/classes/uniform_set_cache_rd");
}

void __register_uniform_set_cache_rd() {
	js_init_uniform_set_cache_rd_module(js_context());
}

void register_uniform_set_cache_rd() {
	__register_uniform_set_cache_rd();
}