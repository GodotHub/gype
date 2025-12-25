#include "register/classes/register_classes.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/str_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/classes/resource_format_loader.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/resource_loader.hpp>


using namespace godot;

static void resource_loader_class_finalizer(JSRuntime *rt, JSValue val) {
}

static JSClassDef resource_loader_class_def = {
	"_ResourceLoader",
	resource_loader_class_finalizer
};

static JSValue resource_loader_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["ResourceLoader"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);
	if (JS_IsException(obj))
		return obj;

	ResourceLoader *resource_loader_class = ResourceLoader::get_singleton();
	if (!resource_loader_class) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, resource_loader_class);
	return obj;
}

static JSValue resource_loader_class_load_threaded_request(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&ResourceLoader::load_threaded_request, ctx, this_val, argc, argv);
};
static JSValue resource_loader_class_load_threaded_get_status(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&ResourceLoader::load_threaded_get_status, ctx, this_val, argc, argv);
};
static JSValue resource_loader_class_load_threaded_get(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&ResourceLoader::load_threaded_get, ctx, this_val, argc, argv);
};
static JSValue resource_loader_class_load(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&ResourceLoader::load, ctx, this_val, argc, argv);
};
static JSValue resource_loader_class_get_recognized_extensions_for_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&ResourceLoader::get_recognized_extensions_for_type, ctx, this_val, argc, argv);
};
static JSValue resource_loader_class_add_resource_format_loader(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&ResourceLoader::add_resource_format_loader, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue resource_loader_class_remove_resource_format_loader(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&ResourceLoader::remove_resource_format_loader, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue resource_loader_class_set_abort_on_missing_resources(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&ResourceLoader::set_abort_on_missing_resources, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue resource_loader_class_get_dependencies(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&ResourceLoader::get_dependencies, ctx, this_val, argc, argv);
};
static JSValue resource_loader_class_has_cached(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&ResourceLoader::has_cached, ctx, this_val, argc, argv);
};
static JSValue resource_loader_class_get_cached_ref(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&ResourceLoader::get_cached_ref, ctx, this_val, argc, argv);
};
static JSValue resource_loader_class_exists(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&ResourceLoader::exists, ctx, this_val, argc, argv);
};
static JSValue resource_loader_class_get_resource_uid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&ResourceLoader::get_resource_uid, ctx, this_val, argc, argv);
};
static JSValue resource_loader_class_list_directory(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&ResourceLoader::list_directory, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry resource_loader_class_proto_funcs[] = {
	JS_CFUNC_DEF("load_threaded_request", 4, &resource_loader_class_load_threaded_request),
	JS_CFUNC_DEF("load_threaded_get_status", 2, &resource_loader_class_load_threaded_get_status),
	JS_CFUNC_DEF("load_threaded_get", 1, &resource_loader_class_load_threaded_get),
	JS_CFUNC_DEF("load", 3, &resource_loader_class_load),
	JS_CFUNC_DEF("get_recognized_extensions_for_type", 1, &resource_loader_class_get_recognized_extensions_for_type),
	JS_CFUNC_DEF("add_resource_format_loader", 2, &resource_loader_class_add_resource_format_loader),
	JS_CFUNC_DEF("remove_resource_format_loader", 1, &resource_loader_class_remove_resource_format_loader),
	JS_CFUNC_DEF("set_abort_on_missing_resources", 1, &resource_loader_class_set_abort_on_missing_resources),
	JS_CFUNC_DEF("get_dependencies", 1, &resource_loader_class_get_dependencies),
	JS_CFUNC_DEF("has_cached", 1, &resource_loader_class_has_cached),
	JS_CFUNC_DEF("get_cached_ref", 1, &resource_loader_class_get_cached_ref),
	JS_CFUNC_DEF("exists", 2, &resource_loader_class_exists),
	JS_CFUNC_DEF("get_resource_uid", 1, &resource_loader_class_get_resource_uid),
	JS_CFUNC_DEF("list_directory", 1, &resource_loader_class_list_directory),
};




static int js_resource_loader_class_init(JSContext *ctx) {
	JSClassID class_id = classes["ResourceLoader"];
	classes["ResourceLoader"] = class_id;
	JS_NewClass(JS_GetRuntime(ctx), class_id, &resource_loader_class_def);

	JSValue proto = JS_NewObject(ctx);
	JSValue base_class = JS_GetClassProto(ctx, classes["Object"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	JS_SetPropertyFunctionList(ctx, proto, resource_loader_class_proto_funcs, _countof(resource_loader_class_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, resource_loader_class_constructor, "_ResourceLoader", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);


	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "ResourceLoader", ctor);
	JS_FreeValue(ctx, global);
	return 0;
}

void register_resource_loader() {
	js_resource_loader_class_init(js_context());
}