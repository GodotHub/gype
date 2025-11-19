#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/thread.hpp>
using namespace godot;

static void thread_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Thread"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef thread_class_def = {
    "Thread",
    thread_class_finalizer
};

static JSValue thread_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["Thread"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    Thread *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<Thread *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(Thread);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue thread_class_start(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Thread::start, ctx, this_val, argc, argv);
};
static JSValue thread_class_get_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Thread::get_id, ctx, this_val, argc, argv);
};
static JSValue thread_class_is_started(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Thread::is_started, ctx, this_val, argc, argv);
};
static JSValue thread_class_is_alive(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Thread::is_alive, ctx, this_val, argc, argv);
};
static JSValue thread_class_wait_to_finish(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Thread::wait_to_finish, ctx, this_val, argc, argv);
};


static JSValue thread_class_set_thread_safety_checks_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    return call_builtin_static_method_no_ret(&Thread::set_thread_safety_checks_enabled, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry thread_class_proto_funcs[] = {
	JS_CFUNC_DEF("start", 2, &thread_class_start),
	JS_CFUNC_DEF("get_id", 0, &thread_class_get_id),
	JS_CFUNC_DEF("is_started", 0, &thread_class_is_started),
	JS_CFUNC_DEF("is_alive", 0, &thread_class_is_alive),
	JS_CFUNC_DEF("wait_to_finish", 0, &thread_class_wait_to_finish),
};

static const JSCFunctionListEntry thread_class_static_funcs[] = {
	JS_CFUNC_DEF("set_thread_safety_checks_enabled", 1, &thread_class_set_thread_safety_checks_enabled),
};



static void define_thread_property(JSContext *ctx, JSValue proto) {
}

static void define_thread_enum(JSContext *ctx, JSValue ctor) {
	JSValue Priority_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, Priority_obj, "PRIORITY_LOW", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, Priority_obj, "PRIORITY_NORMAL", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, Priority_obj, "PRIORITY_HIGH", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "Priority", Priority_obj);
}

static int js_thread_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["Thread"] = class_id;
	classes_by_id[class_id] = "Thread";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &thread_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_thread_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, thread_class_proto_funcs, _countof(thread_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, thread_class_constructor, "Thread", 0, JS_CFUNC_constructor, 0);
	JS_SetPropertyFunctionList(ctx, ctor, thread_class_static_funcs, _countof(thread_class_static_funcs));
	define_thread_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "Thread", ctor);

	return 0;
}

JSModuleDef *_js_init_thread_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_thread_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Thread");
	return m;
}

JSModuleDef *js_init_thread_module(JSContext *ctx) {
	return _js_init_thread_module(ctx, "@godot/classes/thread");
}

void __register_thread() {
	js_init_thread_module(js_context());
}

void register_thread() {
	__register_thread();
}