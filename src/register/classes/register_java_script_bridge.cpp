#include "register/classes/register_classes.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/str_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "register/classes/class_java_script_bridge_vararg.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/java_script_object.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/java_script_bridge.hpp>


using namespace godot;

static void java_script_bridge_class_finalizer(JSRuntime *rt, JSValue val) {
}

static JSClassDef java_script_bridge_class_def = {
	"_JavaScriptBridge",
	java_script_bridge_class_finalizer
};

static JSValue java_script_bridge_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["JavaScriptBridge"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);
	if (JS_IsException(obj))
		return obj;

	JavaScriptBridge *java_script_bridge_class = JavaScriptBridge::get_singleton();
	if (!java_script_bridge_class) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, java_script_bridge_class);
	return obj;
}

static JSValue java_script_bridge_class_eval(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&JavaScriptBridge::eval, ctx, this_val, argc, argv);
};
static JSValue java_script_bridge_class_get_interface(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&JavaScriptBridge::get_interface, ctx, this_val, argc, argv);
};
static JSValue java_script_bridge_class_create_callback(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&JavaScriptBridge::create_callback, ctx, this_val, argc, argv);
};
static JSValue java_script_bridge_class_is_js_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&JavaScriptBridge::is_js_buffer, ctx, this_val, argc, argv);
};
static JSValue java_script_bridge_class_js_buffer_to_packed_byte_array(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&JavaScriptBridge::js_buffer_to_packed_byte_array, ctx, this_val, argc, argv);
};
static JSValue java_script_bridge_class_download_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&JavaScriptBridge::download_buffer, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue java_script_bridge_class_pwa_needs_update(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&JavaScriptBridge::pwa_needs_update, ctx, this_val, argc, argv);
};
static JSValue java_script_bridge_class_pwa_update(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&JavaScriptBridge::pwa_update, ctx, this_val, argc, argv);
};
static JSValue java_script_bridge_class_force_fs_sync(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&JavaScriptBridge::force_fs_sync, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue java_script_bridge_class_create_object(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_free_owner_vararg_method_ret(&js_create_object, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry java_script_bridge_class_proto_funcs[] = {
	JS_CFUNC_DEF("eval", 2, &java_script_bridge_class_eval),
	JS_CFUNC_DEF("get_interface", 1, &java_script_bridge_class_get_interface),
	JS_CFUNC_DEF("create_callback", 1, &java_script_bridge_class_create_callback),
	JS_CFUNC_DEF("is_js_buffer", 1, &java_script_bridge_class_is_js_buffer),
	JS_CFUNC_DEF("js_buffer_to_packed_byte_array", 1, &java_script_bridge_class_js_buffer_to_packed_byte_array),
	JS_CFUNC_DEF("download_buffer", 3, &java_script_bridge_class_download_buffer),
	JS_CFUNC_DEF("pwa_needs_update", 0, &java_script_bridge_class_pwa_needs_update),
	JS_CFUNC_DEF("pwa_update", 0, &java_script_bridge_class_pwa_update),
	JS_CFUNC_DEF("force_fs_sync", 0, &java_script_bridge_class_force_fs_sync),
	JS_CFUNC_DEF("create_object", 1, &java_script_bridge_class_create_object),
};




static int js_java_script_bridge_class_init(JSContext *ctx) {
	JSClassID class_id = classes["JavaScriptBridge"];
	classes["JavaScriptBridge"] = class_id;
	JS_NewClass(JS_GetRuntime(ctx), class_id, &java_script_bridge_class_def);

	JSValue proto = JS_NewObject(ctx);
	JSValue base_class = JS_GetClassProto(ctx, classes["Object"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	JS_SetPropertyFunctionList(ctx, proto, java_script_bridge_class_proto_funcs, _countof(java_script_bridge_class_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, java_script_bridge_class_constructor, "_JavaScriptBridge", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);


	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "_JavaScriptBridge", ctor);
	JS_FreeValue(ctx, global);
	return 0;
}

void register_java_script_bridge() {
	js_java_script_bridge_class_init(js_context());
}