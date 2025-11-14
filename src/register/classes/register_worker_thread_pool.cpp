#include "register/classes/register_classes.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/str_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/worker_thread_pool.hpp>


using namespace godot;

static void worker_thread_pool_class_finalizer(JSRuntime *rt, JSValue val) {
}

static JSClassDef worker_thread_pool_class_def = {
	"_WorkerThreadPool",
	worker_thread_pool_class_finalizer
};

static JSValue worker_thread_pool_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["WorkerThreadPool"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);
	if (JS_IsException(obj))
		return obj;

	WorkerThreadPool *worker_thread_pool_class = WorkerThreadPool::get_singleton();
	if (!worker_thread_pool_class) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, worker_thread_pool_class);
	return obj;
}

static JSValue worker_thread_pool_class_add_task(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&WorkerThreadPool::add_task, ctx, this_val, argc, argv);
};
static JSValue worker_thread_pool_class_is_task_completed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&WorkerThreadPool::is_task_completed, ctx, this_val, argc, argv);
};
static JSValue worker_thread_pool_class_wait_for_task_completion(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&WorkerThreadPool::wait_for_task_completion, ctx, this_val, argc, argv);
};
static JSValue worker_thread_pool_class_get_caller_task_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&WorkerThreadPool::get_caller_task_id, ctx, this_val, argc, argv);
};
static JSValue worker_thread_pool_class_add_group_task(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&WorkerThreadPool::add_group_task, ctx, this_val, argc, argv);
};
static JSValue worker_thread_pool_class_is_group_task_completed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&WorkerThreadPool::is_group_task_completed, ctx, this_val, argc, argv);
};
static JSValue worker_thread_pool_class_get_group_processed_element_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&WorkerThreadPool::get_group_processed_element_count, ctx, this_val, argc, argv);
};
static JSValue worker_thread_pool_class_wait_for_group_task_completion(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&WorkerThreadPool::wait_for_group_task_completion, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue worker_thread_pool_class_get_caller_group_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&WorkerThreadPool::get_caller_group_id, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry worker_thread_pool_class_proto_funcs[] = {
	JS_CFUNC_DEF("add_task", 3, &worker_thread_pool_class_add_task),
	JS_CFUNC_DEF("is_task_completed", 1, &worker_thread_pool_class_is_task_completed),
	JS_CFUNC_DEF("wait_for_task_completion", 1, &worker_thread_pool_class_wait_for_task_completion),
	JS_CFUNC_DEF("get_caller_task_id", 0, &worker_thread_pool_class_get_caller_task_id),
	JS_CFUNC_DEF("add_group_task", 5, &worker_thread_pool_class_add_group_task),
	JS_CFUNC_DEF("is_group_task_completed", 1, &worker_thread_pool_class_is_group_task_completed),
	JS_CFUNC_DEF("get_group_processed_element_count", 1, &worker_thread_pool_class_get_group_processed_element_count),
	JS_CFUNC_DEF("wait_for_group_task_completion", 1, &worker_thread_pool_class_wait_for_group_task_completion),
	JS_CFUNC_DEF("get_caller_group_id", 0, &worker_thread_pool_class_get_caller_group_id),
};




static int js_worker_thread_pool_class_init(JSContext *ctx) {
	JSClassID class_id = classes["WorkerThreadPool"];
	classes["WorkerThreadPool"] = class_id;
	JS_NewClass(JS_GetRuntime(ctx), class_id, &worker_thread_pool_class_def);

	JSValue proto = JS_NewObject(ctx);
	JSValue base_class = JS_GetClassProto(ctx, classes["Object"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	JS_SetPropertyFunctionList(ctx, proto, worker_thread_pool_class_proto_funcs, _countof(worker_thread_pool_class_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, worker_thread_pool_class_constructor, "_WorkerThreadPool", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);


	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "_WorkerThreadPool", ctor);
	JS_FreeValue(ctx, global);
	return 0;
}

void register_worker_thread_pool() {
	js_worker_thread_pool_class_init(js_context());
}