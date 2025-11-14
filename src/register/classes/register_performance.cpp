#include "register/classes/register_classes.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/str_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/performance.hpp>


using namespace godot;

static void performance_class_finalizer(JSRuntime *rt, JSValue val) {
}

static JSClassDef performance_class_def = {
	"_Performance",
	performance_class_finalizer
};

static JSValue performance_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["Performance"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);
	if (JS_IsException(obj))
		return obj;

	Performance *performance_class = Performance::get_singleton();
	if (!performance_class) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, performance_class);
	return obj;
}

static JSValue performance_class_get_monitor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Performance::get_monitor, ctx, this_val, argc, argv);
};
static JSValue performance_class_add_custom_monitor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&Performance::add_custom_monitor, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue performance_class_remove_custom_monitor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&Performance::remove_custom_monitor, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue performance_class_has_custom_monitor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Performance::has_custom_monitor, ctx, this_val, argc, argv);
};
static JSValue performance_class_get_custom_monitor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Performance::get_custom_monitor, ctx, this_val, argc, argv);
};
static JSValue performance_class_get_monitor_modification_time(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Performance::get_monitor_modification_time, ctx, this_val, argc, argv);
};
static JSValue performance_class_get_custom_monitor_names(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Performance::get_custom_monitor_names, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry performance_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_monitor", 1, &performance_class_get_monitor),
	JS_CFUNC_DEF("add_custom_monitor", 3, &performance_class_add_custom_monitor),
	JS_CFUNC_DEF("remove_custom_monitor", 1, &performance_class_remove_custom_monitor),
	JS_CFUNC_DEF("has_custom_monitor", 1, &performance_class_has_custom_monitor),
	JS_CFUNC_DEF("get_custom_monitor", 1, &performance_class_get_custom_monitor),
	JS_CFUNC_DEF("get_monitor_modification_time", 0, &performance_class_get_monitor_modification_time),
	JS_CFUNC_DEF("get_custom_monitor_names", 0, &performance_class_get_custom_monitor_names),
};




static int js_performance_class_init(JSContext *ctx) {
	JSClassID class_id = classes["Performance"];
	classes["Performance"] = class_id;
	JS_NewClass(JS_GetRuntime(ctx), class_id, &performance_class_def);

	JSValue proto = JS_NewObject(ctx);
	JSValue base_class = JS_GetClassProto(ctx, classes["Object"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	JS_SetPropertyFunctionList(ctx, proto, performance_class_proto_funcs, _countof(performance_class_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, performance_class_constructor, "_Performance", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);


	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "_Performance", ctor);
	JS_FreeValue(ctx, global);
	return 0;
}

void register_performance() {
	js_performance_class_init(js_context());
}