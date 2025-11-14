#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/timer.hpp>
using namespace godot;

static void timer_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Timer"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef timer_class_def = {
    "Timer",
    timer_class_finalizer
};

static JSValue timer_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["Timer"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    Timer *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<Timer *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(Timer);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue timer_class_set_wait_time(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Timer::set_wait_time, ctx, this_val, argc, argv);
};
static JSValue timer_class_get_wait_time(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Timer::get_wait_time, ctx, this_val, argc, argv);
}
static JSValue timer_class_set_one_shot(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Timer::set_one_shot, ctx, this_val, argc, argv);
};
static JSValue timer_class_is_one_shot(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Timer::is_one_shot, ctx, this_val, argc, argv);
}
static JSValue timer_class_set_autostart(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Timer::set_autostart, ctx, this_val, argc, argv);
};
static JSValue timer_class_has_autostart(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Timer::has_autostart, ctx, this_val, argc, argv);
}
static JSValue timer_class_start(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Timer::start, ctx, this_val, argc, argv);
};
static JSValue timer_class_stop(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Timer::stop, ctx, this_val, argc, argv);
};
static JSValue timer_class_set_paused(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Timer::set_paused, ctx, this_val, argc, argv);
};
static JSValue timer_class_is_paused(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Timer::is_paused, ctx, this_val, argc, argv);
}
static JSValue timer_class_set_ignore_time_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Timer::set_ignore_time_scale, ctx, this_val, argc, argv);
};
static JSValue timer_class_is_ignoring_time_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Timer::is_ignoring_time_scale, ctx, this_val, argc, argv);
}
static JSValue timer_class_is_stopped(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Timer::is_stopped, ctx, this_val, argc, argv);
};
static JSValue timer_class_get_time_left(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Timer::get_time_left, ctx, this_val, argc, argv);
}
static JSValue timer_class_set_timer_process_callback(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Timer::set_timer_process_callback, ctx, this_val, argc, argv);
};
static JSValue timer_class_get_timer_process_callback(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Timer::get_timer_process_callback, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry timer_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_wait_time", 1, &timer_class_set_wait_time),
	JS_CFUNC_DEF("get_wait_time", 0, &timer_class_get_wait_time),
	JS_CFUNC_DEF("set_one_shot", 1, &timer_class_set_one_shot),
	JS_CFUNC_DEF("is_one_shot", 0, &timer_class_is_one_shot),
	JS_CFUNC_DEF("set_autostart", 1, &timer_class_set_autostart),
	JS_CFUNC_DEF("has_autostart", 0, &timer_class_has_autostart),
	JS_CFUNC_DEF("start", 1, &timer_class_start),
	JS_CFUNC_DEF("stop", 0, &timer_class_stop),
	JS_CFUNC_DEF("set_paused", 1, &timer_class_set_paused),
	JS_CFUNC_DEF("is_paused", 0, &timer_class_is_paused),
	JS_CFUNC_DEF("set_ignore_time_scale", 1, &timer_class_set_ignore_time_scale),
	JS_CFUNC_DEF("is_ignoring_time_scale", 0, &timer_class_is_ignoring_time_scale),
	JS_CFUNC_DEF("is_stopped", 0, &timer_class_is_stopped),
	JS_CFUNC_DEF("get_time_left", 0, &timer_class_get_time_left),
	JS_CFUNC_DEF("set_timer_process_callback", 1, &timer_class_set_timer_process_callback),
	JS_CFUNC_DEF("get_timer_process_callback", 0, &timer_class_get_timer_process_callback),
};


static JSValue timer_class_get_timeout_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	Timer *opaque = static_cast<Timer *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "timeout_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "timeout"));
		JS_DefinePropertyValueStr(ctx, this_val, "timeout_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_timer_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "process_callback"),
        JS_NewCFunction(ctx, timer_class_get_timer_process_callback, "get_timer_process_callback", 0),
        JS_NewCFunction(ctx, timer_class_set_timer_process_callback, "set_timer_process_callback", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "wait_time"),
        JS_NewCFunction(ctx, timer_class_get_wait_time, "get_wait_time", 0),
        JS_NewCFunction(ctx, timer_class_set_wait_time, "set_wait_time", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "one_shot"),
        JS_NewCFunction(ctx, timer_class_is_one_shot, "is_one_shot", 0),
        JS_NewCFunction(ctx, timer_class_set_one_shot, "set_one_shot", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "autostart"),
        JS_NewCFunction(ctx, timer_class_has_autostart, "has_autostart", 0),
        JS_NewCFunction(ctx, timer_class_set_autostart, "set_autostart", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "paused"),
        JS_NewCFunction(ctx, timer_class_is_paused, "is_paused", 0),
        JS_NewCFunction(ctx, timer_class_set_paused, "set_paused", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "ignore_time_scale"),
        JS_NewCFunction(ctx, timer_class_is_ignoring_time_scale, "is_ignoring_time_scale", 0),
        JS_NewCFunction(ctx, timer_class_set_ignore_time_scale, "set_ignore_time_scale", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "time_left"),
        JS_NewCFunction(ctx, timer_class_get_time_left, "get_time_left", 0),
        JS_UNDEFINED,
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "timeout"),
		JS_NewCFunction(ctx, timer_class_get_timeout_signal, "get_timeout_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_timer_enum(JSContext *ctx, JSValue proto) {
	JSValue TimerProcessCallback_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, TimerProcessCallback_obj, "TIMER_PROCESS_PHYSICS", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, TimerProcessCallback_obj, "TIMER_PROCESS_IDLE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, proto, "TimerProcessCallback", TimerProcessCallback_obj);
}

static int js_timer_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["Timer"] = class_id;
	classes_by_id[class_id] = "Timer";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &timer_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_timer_property(ctx, proto);
	define_timer_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, timer_class_proto_funcs, _countof(timer_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, timer_class_constructor, "Timer", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "Timer", ctor);

	return 0;
}

JSModuleDef *_js_init_timer_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_timer_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Timer");
	return m;
}

JSModuleDef *js_init_timer_module(JSContext *ctx) {
	return _js_init_timer_module(ctx, "@godot/classes/timer");
}

void __register_timer() {
	js_init_timer_module(js_context());
}

void register_timer() {
	__register_timer();
}