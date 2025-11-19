#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/animation_node_state_machine_playback.hpp>
using namespace godot;

static void animation_node_state_machine_playback_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["AnimationNodeStateMachinePlayback"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
	}
}

static JSClassDef animation_node_state_machine_playback_class_def = {
    "AnimationNodeStateMachinePlayback",
    animation_node_state_machine_playback_class_finalizer
};

static JSValue animation_node_state_machine_playback_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["AnimationNodeStateMachinePlayback"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    AnimationNodeStateMachinePlayback *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<AnimationNodeStateMachinePlayback *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(AnimationNodeStateMachinePlayback);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue animation_node_state_machine_playback_class_travel(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationNodeStateMachinePlayback::travel, ctx, this_val, argc, argv);
};
static JSValue animation_node_state_machine_playback_class_start(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationNodeStateMachinePlayback::start, ctx, this_val, argc, argv);
};
static JSValue animation_node_state_machine_playback_class_next(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationNodeStateMachinePlayback::next, ctx, this_val, argc, argv);
};
static JSValue animation_node_state_machine_playback_class_stop(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationNodeStateMachinePlayback::stop, ctx, this_val, argc, argv);
};
static JSValue animation_node_state_machine_playback_class_is_playing(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationNodeStateMachinePlayback::is_playing, ctx, this_val, argc, argv);
};
static JSValue animation_node_state_machine_playback_class_get_current_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationNodeStateMachinePlayback::get_current_node, ctx, this_val, argc, argv);
};
static JSValue animation_node_state_machine_playback_class_get_current_play_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationNodeStateMachinePlayback::get_current_play_position, ctx, this_val, argc, argv);
};
static JSValue animation_node_state_machine_playback_class_get_current_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationNodeStateMachinePlayback::get_current_length, ctx, this_val, argc, argv);
};
static JSValue animation_node_state_machine_playback_class_get_fading_from_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationNodeStateMachinePlayback::get_fading_from_node, ctx, this_val, argc, argv);
};
static JSValue animation_node_state_machine_playback_class_get_travel_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationNodeStateMachinePlayback::get_travel_path, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry animation_node_state_machine_playback_class_proto_funcs[] = {
	JS_CFUNC_DEF("travel", 2, &animation_node_state_machine_playback_class_travel),
	JS_CFUNC_DEF("start", 2, &animation_node_state_machine_playback_class_start),
	JS_CFUNC_DEF("next", 0, &animation_node_state_machine_playback_class_next),
	JS_CFUNC_DEF("stop", 0, &animation_node_state_machine_playback_class_stop),
	JS_CFUNC_DEF("is_playing", 0, &animation_node_state_machine_playback_class_is_playing),
	JS_CFUNC_DEF("get_current_node", 0, &animation_node_state_machine_playback_class_get_current_node),
	JS_CFUNC_DEF("get_current_play_position", 0, &animation_node_state_machine_playback_class_get_current_play_position),
	JS_CFUNC_DEF("get_current_length", 0, &animation_node_state_machine_playback_class_get_current_length),
	JS_CFUNC_DEF("get_fading_from_node", 0, &animation_node_state_machine_playback_class_get_fading_from_node),
	JS_CFUNC_DEF("get_travel_path", 0, &animation_node_state_machine_playback_class_get_travel_path),
};


static JSValue animation_node_state_machine_playback_class_get_state_started_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	AnimationNodeStateMachinePlayback *opaque = static_cast<AnimationNodeStateMachinePlayback *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "state_started_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "state_started"));
		JS_DefinePropertyValueStr(ctx, this_val, "state_started_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue animation_node_state_machine_playback_class_get_state_finished_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	AnimationNodeStateMachinePlayback *opaque = static_cast<AnimationNodeStateMachinePlayback *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "state_finished_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "state_finished"));
		JS_DefinePropertyValueStr(ctx, this_val, "state_finished_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_animation_node_state_machine_playback_property(JSContext *ctx, JSValue proto) {
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "state_started"),
		JS_NewCFunction(ctx, animation_node_state_machine_playback_class_get_state_started_signal, "get_state_started_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "state_finished"),
		JS_NewCFunction(ctx, animation_node_state_machine_playback_class_get_state_finished_signal, "get_state_finished_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_animation_node_state_machine_playback_enum(JSContext *ctx, JSValue ctor) {
}

static int js_animation_node_state_machine_playback_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["AnimationNodeStateMachinePlayback"] = class_id;
	classes_by_id[class_id] = "AnimationNodeStateMachinePlayback";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &animation_node_state_machine_playback_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_animation_node_state_machine_playback_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, animation_node_state_machine_playback_class_proto_funcs, _countof(animation_node_state_machine_playback_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, animation_node_state_machine_playback_class_constructor, "AnimationNodeStateMachinePlayback", 0, JS_CFUNC_constructor, 0);
	define_animation_node_state_machine_playback_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "AnimationNodeStateMachinePlayback", ctor);

	return 0;
}

JSModuleDef *_js_init_animation_node_state_machine_playback_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_animation_node_state_machine_playback_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "AnimationNodeStateMachinePlayback");
	return m;
}

JSModuleDef *js_init_animation_node_state_machine_playback_module(JSContext *ctx) {
	return _js_init_animation_node_state_machine_playback_module(ctx, "@godot/classes/animation_node_state_machine_playback");
}

void __register_animation_node_state_machine_playback() {
	js_init_animation_node_state_machine_playback_module(js_context());
}

void register_animation_node_state_machine_playback() {
	__register_animation_node_state_machine_playback();
}