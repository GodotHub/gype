#include "register/classes/register_classes.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/str_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/gd_extension.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/gd_extension_manager.hpp>


using namespace godot;

static void gd_extension_manager_class_finalizer(JSRuntime *rt, JSValue val) {
}

static JSClassDef gd_extension_manager_class_def = {
	"_GDExtensionManager",
	gd_extension_manager_class_finalizer
};

static JSValue gd_extension_manager_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["_GDExtensionManager"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);
	if (JS_IsException(obj))
		return obj;

	GDExtensionManager *gd_extension_manager_class = GDExtensionManager::get_singleton();
	if (!gd_extension_manager_class) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	VariantAdapter *adapter = memnew(VariantAdapter(gd_extension_manager_class));
	JS_SetOpaque(obj, adapter);
	return obj;
}

static JSValue gd_extension_manager_class_load_extension(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&GDExtensionManager::load_extension, ctx, this_val, argc, argv);
};
static JSValue gd_extension_manager_class_reload_extension(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&GDExtensionManager::reload_extension, ctx, this_val, argc, argv);
};
static JSValue gd_extension_manager_class_unload_extension(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&GDExtensionManager::unload_extension, ctx, this_val, argc, argv);
};
static JSValue gd_extension_manager_class_is_extension_loaded(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&GDExtensionManager::is_extension_loaded, ctx, this_val, argc, argv);
};
static JSValue gd_extension_manager_class_get_loaded_extensions(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&GDExtensionManager::get_loaded_extensions, ctx, this_val, argc, argv);
};
static JSValue gd_extension_manager_class_get_extension(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&GDExtensionManager::get_extension, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry gd_extension_manager_class_proto_funcs[] = {
	JS_CFUNC_DEF("load_extension", 1, &gd_extension_manager_class_load_extension),
	JS_CFUNC_DEF("reload_extension", 1, &gd_extension_manager_class_reload_extension),
	JS_CFUNC_DEF("unload_extension", 1, &gd_extension_manager_class_unload_extension),
	JS_CFUNC_DEF("is_extension_loaded", 1, &gd_extension_manager_class_is_extension_loaded),
	JS_CFUNC_DEF("get_loaded_extensions", 0, &gd_extension_manager_class_get_loaded_extensions),
	JS_CFUNC_DEF("get_extension", 1, &gd_extension_manager_class_get_extension),
};




static int js_gd_extension_manager_class_init(JSContext *ctx, JSModuleDef *m){
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["_GDExtensionManager"] = class_id;
	JS_NewClass(JS_GetRuntime(ctx), class_id, &gd_extension_manager_class_def);

	JSValue proto = JS_NewObject(ctx);
	JSValue base_class = JS_GetClassProto(ctx, classes["Object"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	JS_SetPropertyFunctionList(ctx, proto, gd_extension_manager_class_proto_funcs, _countof(gd_extension_manager_class_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, gd_extension_manager_class_constructor, "_GDExtensionManager", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);


    JSValue singleton = JS_CallConstructor(ctx, ctor, 0, {});
	JS_SetModuleExport(ctx, m, "GDExtensionManager", singleton);

	return 0;
}

JSModuleDef *_js_init_gd_extension_manager_module(JSContext *ctx, const char *module_name) {
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_gd_extension_manager_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "GDExtensionManager");
	return m;
}

void register_gd_extension_manager() {
	_js_init_gd_extension_manager_module(js_context(), "@godot/classes/gd_extension_manager");
}