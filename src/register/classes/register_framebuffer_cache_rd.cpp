#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/rd_framebuffer_pass.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/framebuffer_cache_rd.hpp>
using namespace godot;

static void framebuffer_cache_rd_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["FramebufferCacheRD"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef framebuffer_cache_rd_class_def = {
    "FramebufferCacheRD",
    framebuffer_cache_rd_class_finalizer
};

static JSValue framebuffer_cache_rd_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["FramebufferCacheRD"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    FramebufferCacheRD *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<FramebufferCacheRD *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(FramebufferCacheRD);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue framebuffer_cache_rd_class_get_cache_multipass(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&FramebufferCacheRD::get_cache_multipass, ctx, this_val, argc, argv);
};


static const JSCFunctionListEntry framebuffer_cache_rd_class_static_funcs[] = {
	JS_CFUNC_DEF("get_cache_multipass", 3, &framebuffer_cache_rd_class_get_cache_multipass),
};



static void define_framebuffer_cache_rd_property(JSContext *ctx, JSValue proto) {
}

static void define_framebuffer_cache_rd_enum(JSContext *ctx, JSValue ctor) {
}

static int js_framebuffer_cache_rd_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["FramebufferCacheRD"] = class_id;
	classes_by_id[class_id] = "FramebufferCacheRD";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &framebuffer_cache_rd_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["GodotObject"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_framebuffer_cache_rd_property(ctx, proto);
	JSValue ctor = JS_NewCFunction2(ctx, framebuffer_cache_rd_class_constructor, "FramebufferCacheRD", 0, JS_CFUNC_constructor, 0);
	JS_SetPropertyFunctionList(ctx, ctor, framebuffer_cache_rd_class_static_funcs, _countof(framebuffer_cache_rd_class_static_funcs));
	define_framebuffer_cache_rd_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "FramebufferCacheRD", ctor);

	return 0;
}

JSModuleDef *_js_init_framebuffer_cache_rd_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/godot_object';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_framebuffer_cache_rd_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "FramebufferCacheRD");
	return m;
}

JSModuleDef *js_init_framebuffer_cache_rd_module(JSContext *ctx) {
	return _js_init_framebuffer_cache_rd_module(ctx, "@godot/classes/framebuffer_cache_rd");
}

void __register_framebuffer_cache_rd() {
	js_init_framebuffer_cache_rd_module(js_context());
}

void register_framebuffer_cache_rd() {
	__register_framebuffer_cache_rd();
}