#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/resource_preloader.hpp>
using namespace godot;

static void resource_preloader_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["ResourcePreloader"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef resource_preloader_class_def = {
    "ResourcePreloader",
    resource_preloader_class_finalizer
};

static JSValue resource_preloader_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["ResourcePreloader"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    ResourcePreloader *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<ResourcePreloader *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(ResourcePreloader);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue resource_preloader_class_add_resource(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ResourcePreloader::add_resource, ctx, this_val, argc, argv);
};
static JSValue resource_preloader_class_remove_resource(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ResourcePreloader::remove_resource, ctx, this_val, argc, argv);
};
static JSValue resource_preloader_class_rename_resource(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ResourcePreloader::rename_resource, ctx, this_val, argc, argv);
};
static JSValue resource_preloader_class_has_resource(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ResourcePreloader::has_resource, ctx, this_val, argc, argv);
};
static JSValue resource_preloader_class_get_resource(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ResourcePreloader::get_resource, ctx, this_val, argc, argv);
};
static JSValue resource_preloader_class_get_resource_list(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ResourcePreloader::get_resource_list, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry resource_preloader_class_proto_funcs[] = {
	JS_CFUNC_DEF("add_resource", 2, &resource_preloader_class_add_resource),
	JS_CFUNC_DEF("remove_resource", 1, &resource_preloader_class_remove_resource),
	JS_CFUNC_DEF("rename_resource", 2, &resource_preloader_class_rename_resource),
	JS_CFUNC_DEF("has_resource", 1, &resource_preloader_class_has_resource),
	JS_CFUNC_DEF("get_resource", 1, &resource_preloader_class_get_resource),
	JS_CFUNC_DEF("get_resource_list", 0, &resource_preloader_class_get_resource_list),
};




static void define_resource_preloader_property(JSContext *ctx, JSValue proto) {
}

static void define_resource_preloader_enum(JSContext *ctx, JSValue proto) {
}

static int js_resource_preloader_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["ResourcePreloader"] = class_id;
	classes_by_id[class_id] = "ResourcePreloader";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &resource_preloader_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_resource_preloader_property(ctx, proto);
	define_resource_preloader_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, resource_preloader_class_proto_funcs, _countof(resource_preloader_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, resource_preloader_class_constructor, "ResourcePreloader", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "ResourcePreloader", ctor);

	return 0;
}

JSModuleDef *_js_init_resource_preloader_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_resource_preloader_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "ResourcePreloader");
	return m;
}

JSModuleDef *js_init_resource_preloader_module(JSContext *ctx) {
	return _js_init_resource_preloader_module(ctx, "@godot/classes/resource_preloader");
}

void __register_resource_preloader() {
	js_init_resource_preloader_module(js_context());
}

void register_resource_preloader() {
	__register_resource_preloader();
}