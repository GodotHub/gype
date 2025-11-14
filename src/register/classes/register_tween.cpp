#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/callback_tweener.hpp>
#include <godot_cpp/classes/interval_tweener.hpp>
#include <godot_cpp/classes/method_tweener.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/property_tweener.hpp>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/classes/subtween_tweener.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/tween.hpp>
using namespace godot;

static void tween_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Tween"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef tween_class_def = {
    "Tween",
    tween_class_finalizer
};

static JSValue tween_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["Tween"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    Tween *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<Tween *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(Tween);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue tween_class_tween_property(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Tween::tween_property, ctx, this_val, argc, argv);
};
static JSValue tween_class_tween_interval(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Tween::tween_interval, ctx, this_val, argc, argv);
};
static JSValue tween_class_tween_callback(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Tween::tween_callback, ctx, this_val, argc, argv);
};
static JSValue tween_class_tween_method(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Tween::tween_method, ctx, this_val, argc, argv);
};
static JSValue tween_class_tween_subtween(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Tween::tween_subtween, ctx, this_val, argc, argv);
};
static JSValue tween_class_custom_step(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Tween::custom_step, ctx, this_val, argc, argv);
};
static JSValue tween_class_stop(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Tween::stop, ctx, this_val, argc, argv);
};
static JSValue tween_class_pause(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Tween::pause, ctx, this_val, argc, argv);
};
static JSValue tween_class_play(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Tween::play, ctx, this_val, argc, argv);
};
static JSValue tween_class_kill(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Tween::kill, ctx, this_val, argc, argv);
};
static JSValue tween_class_get_total_elapsed_time(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Tween::get_total_elapsed_time, ctx, this_val, argc, argv);
};
static JSValue tween_class_is_running(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Tween::is_running, ctx, this_val, argc, argv);
};
static JSValue tween_class_is_valid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Tween::is_valid, ctx, this_val, argc, argv);
};
static JSValue tween_class_bind_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Tween::bind_node, ctx, this_val, argc, argv);
};
static JSValue tween_class_set_process_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Tween::set_process_mode, ctx, this_val, argc, argv);
};
static JSValue tween_class_set_pause_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Tween::set_pause_mode, ctx, this_val, argc, argv);
};
static JSValue tween_class_set_ignore_time_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Tween::set_ignore_time_scale, ctx, this_val, argc, argv);
};
static JSValue tween_class_set_parallel(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Tween::set_parallel, ctx, this_val, argc, argv);
};
static JSValue tween_class_set_loops(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Tween::set_loops, ctx, this_val, argc, argv);
};
static JSValue tween_class_get_loops_left(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Tween::get_loops_left, ctx, this_val, argc, argv);
};
static JSValue tween_class_set_speed_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Tween::set_speed_scale, ctx, this_val, argc, argv);
};
static JSValue tween_class_set_trans(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Tween::set_trans, ctx, this_val, argc, argv);
};
static JSValue tween_class_set_ease(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Tween::set_ease, ctx, this_val, argc, argv);
};
static JSValue tween_class_parallel(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Tween::parallel, ctx, this_val, argc, argv);
};
static JSValue tween_class_chain(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Tween::chain, ctx, this_val, argc, argv);
};
static JSValue tween_class_interpolate_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&Tween::interpolate_value, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry tween_class_proto_funcs[] = {
	JS_CFUNC_DEF("tween_property", 4, &tween_class_tween_property),
	JS_CFUNC_DEF("tween_interval", 1, &tween_class_tween_interval),
	JS_CFUNC_DEF("tween_callback", 1, &tween_class_tween_callback),
	JS_CFUNC_DEF("tween_method", 4, &tween_class_tween_method),
	JS_CFUNC_DEF("tween_subtween", 1, &tween_class_tween_subtween),
	JS_CFUNC_DEF("custom_step", 1, &tween_class_custom_step),
	JS_CFUNC_DEF("stop", 0, &tween_class_stop),
	JS_CFUNC_DEF("pause", 0, &tween_class_pause),
	JS_CFUNC_DEF("play", 0, &tween_class_play),
	JS_CFUNC_DEF("kill", 0, &tween_class_kill),
	JS_CFUNC_DEF("get_total_elapsed_time", 0, &tween_class_get_total_elapsed_time),
	JS_CFUNC_DEF("is_running", 0, &tween_class_is_running),
	JS_CFUNC_DEF("is_valid", 0, &tween_class_is_valid),
	JS_CFUNC_DEF("bind_node", 1, &tween_class_bind_node),
	JS_CFUNC_DEF("set_process_mode", 1, &tween_class_set_process_mode),
	JS_CFUNC_DEF("set_pause_mode", 1, &tween_class_set_pause_mode),
	JS_CFUNC_DEF("set_ignore_time_scale", 1, &tween_class_set_ignore_time_scale),
	JS_CFUNC_DEF("set_parallel", 1, &tween_class_set_parallel),
	JS_CFUNC_DEF("set_loops", 1, &tween_class_set_loops),
	JS_CFUNC_DEF("get_loops_left", 0, &tween_class_get_loops_left),
	JS_CFUNC_DEF("set_speed_scale", 1, &tween_class_set_speed_scale),
	JS_CFUNC_DEF("set_trans", 1, &tween_class_set_trans),
	JS_CFUNC_DEF("set_ease", 1, &tween_class_set_ease),
	JS_CFUNC_DEF("parallel", 0, &tween_class_parallel),
	JS_CFUNC_DEF("chain", 0, &tween_class_chain),
};

static const JSCFunctionListEntry tween_class_static_funcs[] = {
	JS_CFUNC_DEF("interpolate_value", 6, &tween_class_interpolate_value),
};

static JSValue tween_class_get_step_finished_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	Tween *opaque = static_cast<Tween *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "step_finished_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "step_finished"));
		JS_DefinePropertyValueStr(ctx, this_val, "step_finished_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue tween_class_get_loop_finished_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	Tween *opaque = static_cast<Tween *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "loop_finished_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "loop_finished"));
		JS_DefinePropertyValueStr(ctx, this_val, "loop_finished_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue tween_class_get_finished_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	Tween *opaque = static_cast<Tween *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "finished_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "finished"));
		JS_DefinePropertyValueStr(ctx, this_val, "finished_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_tween_property(JSContext *ctx, JSValue proto) {
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "step_finished"),
		JS_NewCFunction(ctx, tween_class_get_step_finished_signal, "get_step_finished_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "loop_finished"),
		JS_NewCFunction(ctx, tween_class_get_loop_finished_signal, "get_loop_finished_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "finished"),
		JS_NewCFunction(ctx, tween_class_get_finished_signal, "get_finished_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_tween_enum(JSContext *ctx, JSValue proto) {
	JSValue TweenProcessMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, TweenProcessMode_obj, "TWEEN_PROCESS_PHYSICS", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, TweenProcessMode_obj, "TWEEN_PROCESS_IDLE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, proto, "TweenProcessMode", TweenProcessMode_obj);
	JSValue TweenPauseMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, TweenPauseMode_obj, "TWEEN_PAUSE_BOUND", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, TweenPauseMode_obj, "TWEEN_PAUSE_STOP", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, TweenPauseMode_obj, "TWEEN_PAUSE_PROCESS", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, proto, "TweenPauseMode", TweenPauseMode_obj);
	JSValue TransitionType_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, TransitionType_obj, "TRANS_LINEAR", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, TransitionType_obj, "TRANS_SINE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, TransitionType_obj, "TRANS_QUINT", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, TransitionType_obj, "TRANS_QUART", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, TransitionType_obj, "TRANS_QUAD", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, TransitionType_obj, "TRANS_EXPO", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, TransitionType_obj, "TRANS_ELASTIC", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, TransitionType_obj, "TRANS_CUBIC", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, TransitionType_obj, "TRANS_CIRC", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, TransitionType_obj, "TRANS_BOUNCE", JS_NewInt64(ctx, 9));
	JS_SetPropertyStr(ctx, TransitionType_obj, "TRANS_BACK", JS_NewInt64(ctx, 10));
	JS_SetPropertyStr(ctx, TransitionType_obj, "TRANS_SPRING", JS_NewInt64(ctx, 11));
	JS_SetPropertyStr(ctx, proto, "TransitionType", TransitionType_obj);
	JSValue EaseType_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, EaseType_obj, "EASE_IN", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, EaseType_obj, "EASE_OUT", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, EaseType_obj, "EASE_IN_OUT", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, EaseType_obj, "EASE_OUT_IN", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, proto, "EaseType", EaseType_obj);
}

static int js_tween_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["Tween"] = class_id;
	classes_by_id[class_id] = "Tween";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &tween_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_tween_property(ctx, proto);
	define_tween_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, tween_class_proto_funcs, _countof(tween_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, tween_class_constructor, "Tween", 0, JS_CFUNC_constructor, 0);
	JS_SetPropertyFunctionList(ctx, ctor, tween_class_static_funcs, _countof(tween_class_static_funcs));
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "Tween", ctor);

	return 0;
}

JSModuleDef *_js_init_tween_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_tween_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Tween");
	return m;
}

JSModuleDef *js_init_tween_module(JSContext *ctx) {
	return _js_init_tween_module(ctx, "@godot/classes/tween");
}

void __register_tween() {
	js_init_tween_module(js_context());
}

void register_tween() {
	__register_tween();
}