#include "register/classes/register_classes.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/str_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/xr_interface.hpp>
#include <godot_cpp/classes/xr_tracker.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/xr_server.hpp>


using namespace godot;

static void xr_server_class_finalizer(JSRuntime *rt, JSValue val) {
}

static JSClassDef xr_server_class_def = {
	"_XRServer",
	xr_server_class_finalizer
};

static JSValue xr_server_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["_XRServer"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);
	if (JS_IsException(obj))
		return obj;

	XRServer *xr_server_class = XRServer::get_singleton();
	if (!xr_server_class) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	VariantAdapter *adapter = memnew(VariantAdapter(xr_server_class));
	JS_SetOpaque(obj, adapter);
	return obj;
}

static JSValue xr_server_class_get_world_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&XRServer::get_world_scale, ctx, this_val, argc, argv);
};
static JSValue xr_server_class_set_world_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&XRServer::set_world_scale, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue xr_server_class_get_world_origin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&XRServer::get_world_origin, ctx, this_val, argc, argv);
};
static JSValue xr_server_class_set_world_origin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&XRServer::set_world_origin, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue xr_server_class_get_reference_frame(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&XRServer::get_reference_frame, ctx, this_val, argc, argv);
};
static JSValue xr_server_class_clear_reference_frame(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&XRServer::clear_reference_frame, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue xr_server_class_center_on_hmd(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&XRServer::center_on_hmd, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue xr_server_class_get_hmd_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&XRServer::get_hmd_transform, ctx, this_val, argc, argv);
};
static JSValue xr_server_class_set_camera_locked_to_origin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&XRServer::set_camera_locked_to_origin, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue xr_server_class_is_camera_locked_to_origin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&XRServer::is_camera_locked_to_origin, ctx, this_val, argc, argv);
};
static JSValue xr_server_class_add_interface(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&XRServer::add_interface, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue xr_server_class_get_interface_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&XRServer::get_interface_count, ctx, this_val, argc, argv);
};
static JSValue xr_server_class_remove_interface(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&XRServer::remove_interface, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue xr_server_class_get_interface(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&XRServer::get_interface, ctx, this_val, argc, argv);
};
static JSValue xr_server_class_get_interfaces(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&XRServer::get_interfaces, ctx, this_val, argc, argv);
};
static JSValue xr_server_class_find_interface(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&XRServer::find_interface, ctx, this_val, argc, argv);
};
static JSValue xr_server_class_add_tracker(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&XRServer::add_tracker, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue xr_server_class_remove_tracker(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&XRServer::remove_tracker, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue xr_server_class_get_trackers(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&XRServer::get_trackers, ctx, this_val, argc, argv);
};
static JSValue xr_server_class_get_tracker(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&XRServer::get_tracker, ctx, this_val, argc, argv);
};
static JSValue xr_server_class_get_primary_interface(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&XRServer::get_primary_interface, ctx, this_val, argc, argv);
};
static JSValue xr_server_class_set_primary_interface(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&XRServer::set_primary_interface, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};

static const JSCFunctionListEntry xr_server_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_world_scale", 0, &xr_server_class_get_world_scale),
	JS_CFUNC_DEF("set_world_scale", 1, &xr_server_class_set_world_scale),
	JS_CFUNC_DEF("get_world_origin", 0, &xr_server_class_get_world_origin),
	JS_CFUNC_DEF("set_world_origin", 1, &xr_server_class_set_world_origin),
	JS_CFUNC_DEF("get_reference_frame", 0, &xr_server_class_get_reference_frame),
	JS_CFUNC_DEF("clear_reference_frame", 0, &xr_server_class_clear_reference_frame),
	JS_CFUNC_DEF("center_on_hmd", 2, &xr_server_class_center_on_hmd),
	JS_CFUNC_DEF("get_hmd_transform", 0, &xr_server_class_get_hmd_transform),
	JS_CFUNC_DEF("set_camera_locked_to_origin", 1, &xr_server_class_set_camera_locked_to_origin),
	JS_CFUNC_DEF("is_camera_locked_to_origin", 0, &xr_server_class_is_camera_locked_to_origin),
	JS_CFUNC_DEF("add_interface", 1, &xr_server_class_add_interface),
	JS_CFUNC_DEF("get_interface_count", 0, &xr_server_class_get_interface_count),
	JS_CFUNC_DEF("remove_interface", 1, &xr_server_class_remove_interface),
	JS_CFUNC_DEF("get_interface", 1, &xr_server_class_get_interface),
	JS_CFUNC_DEF("get_interfaces", 0, &xr_server_class_get_interfaces),
	JS_CFUNC_DEF("find_interface", 1, &xr_server_class_find_interface),
	JS_CFUNC_DEF("add_tracker", 1, &xr_server_class_add_tracker),
	JS_CFUNC_DEF("remove_tracker", 1, &xr_server_class_remove_tracker),
	JS_CFUNC_DEF("get_trackers", 1, &xr_server_class_get_trackers),
	JS_CFUNC_DEF("get_tracker", 1, &xr_server_class_get_tracker),
	JS_CFUNC_DEF("get_primary_interface", 0, &xr_server_class_get_primary_interface),
	JS_CFUNC_DEF("set_primary_interface", 1, &xr_server_class_set_primary_interface),
};




static int js_xr_server_class_init(JSContext *ctx, JSModuleDef *m){
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["_XRServer"] = class_id;
	JS_NewClass(JS_GetRuntime(ctx), class_id, &xr_server_class_def);

	JSValue proto = JS_NewObject(ctx);
	JSValue base_class = JS_GetClassProto(ctx, classes["Object"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	JS_SetPropertyFunctionList(ctx, proto, xr_server_class_proto_funcs, _countof(xr_server_class_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, xr_server_class_constructor, "_XRServer", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);


    JSValue singleton = JS_CallConstructor(ctx, ctor, 0, {});
	JS_SetModuleExport(ctx, m, "XRServer", singleton);

	return 0;
}

JSModuleDef *_js_init_xr_server_module(JSContext *ctx, const char *module_name) {
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_xr_server_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "XRServer");
	return m;
}

void register_xr_server() {
	_js_init_xr_server_module(js_context(), "@godot/classes/xr_server");
}