#include "register/classes/register_classes.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/str_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/camera_feed.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/camera_server.hpp>


using namespace godot;

static void camera_server_class_finalizer(JSRuntime *rt, JSValue val) {
}

static JSClassDef camera_server_class_def = {
	"_CameraServer",
	camera_server_class_finalizer
};

static JSValue camera_server_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["CameraServer"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);
	if (JS_IsException(obj))
		return obj;

	CameraServer *camera_server_class = CameraServer::get_singleton();
	if (!camera_server_class) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, camera_server_class);
	return obj;
}

static JSValue camera_server_class_set_monitoring_feeds(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&CameraServer::set_monitoring_feeds, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue camera_server_class_is_monitoring_feeds(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&CameraServer::is_monitoring_feeds, ctx, this_val, argc, argv);
};
static JSValue camera_server_class_get_feed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&CameraServer::get_feed, ctx, this_val, argc, argv);
};
static JSValue camera_server_class_get_feed_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&CameraServer::get_feed_count, ctx, this_val, argc, argv);
};
static JSValue camera_server_class_feeds(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&CameraServer::feeds, ctx, this_val, argc, argv);
};
static JSValue camera_server_class_add_feed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&CameraServer::add_feed, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue camera_server_class_remove_feed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&CameraServer::remove_feed, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};

static const JSCFunctionListEntry camera_server_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_monitoring_feeds", 1, &camera_server_class_set_monitoring_feeds),
	JS_CFUNC_DEF("is_monitoring_feeds", 0, &camera_server_class_is_monitoring_feeds),
	JS_CFUNC_DEF("get_feed", 1, &camera_server_class_get_feed),
	JS_CFUNC_DEF("get_feed_count", 0, &camera_server_class_get_feed_count),
	JS_CFUNC_DEF("feeds", 0, &camera_server_class_feeds),
	JS_CFUNC_DEF("add_feed", 1, &camera_server_class_add_feed),
	JS_CFUNC_DEF("remove_feed", 1, &camera_server_class_remove_feed),
};




static int js_camera_server_class_init(JSContext *ctx) {
	JSClassID class_id = classes["CameraServer"];
	classes["CameraServer"] = class_id;
	JS_NewClass(JS_GetRuntime(ctx), class_id, &camera_server_class_def);

	JSValue proto = JS_NewObject(ctx);
	JSValue base_class = JS_GetClassProto(ctx, classes["Object"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	JS_SetPropertyFunctionList(ctx, proto, camera_server_class_proto_funcs, _countof(camera_server_class_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, camera_server_class_constructor, "_CameraServer", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);


	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "_CameraServer", ctor);
	JS_FreeValue(ctx, global);
	return 0;
}

void register_camera_server() {
	js_camera_server_class_init(js_context());
}