#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/audio_stream.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/audio_stream_interactive.hpp>
using namespace godot;

static void audio_stream_interactive_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["AudioStreamInteractive"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef audio_stream_interactive_class_def = {
    "AudioStreamInteractive",
    audio_stream_interactive_class_finalizer
};

static JSValue audio_stream_interactive_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["AudioStreamInteractive"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

	VariantAdapter *adapter = nullptr;
	Object *instance = nullptr;
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
    	instance = static_cast<VariantAdapter *>(JS_GetOpaque(*argv, class_id))->get();
		adapter = memnew(VariantAdapter(instance));
    } else {
        instance = memnew(AudioStreamInteractive);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue audio_stream_interactive_class_set_clip_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamInteractive::set_clip_count, ctx, this_val, argc, argv);
};
static JSValue audio_stream_interactive_class_get_clip_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamInteractive::get_clip_count, ctx, this_val, argc, argv);
}
static JSValue audio_stream_interactive_class_set_initial_clip(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamInteractive::set_initial_clip, ctx, this_val, argc, argv);
};
static JSValue audio_stream_interactive_class_get_initial_clip(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamInteractive::get_initial_clip, ctx, this_val, argc, argv);
}
static JSValue audio_stream_interactive_class_set_clip_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamInteractive::set_clip_name, ctx, this_val, argc, argv);
};
static JSValue audio_stream_interactive_class_get_clip_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamInteractive::get_clip_name, ctx, this_val, argc, argv);
};
static JSValue audio_stream_interactive_class_set_clip_stream(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamInteractive::set_clip_stream, ctx, this_val, argc, argv);
};
static JSValue audio_stream_interactive_class_get_clip_stream(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamInteractive::get_clip_stream, ctx, this_val, argc, argv);
};
static JSValue audio_stream_interactive_class_set_clip_auto_advance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamInteractive::set_clip_auto_advance, ctx, this_val, argc, argv);
};
static JSValue audio_stream_interactive_class_get_clip_auto_advance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamInteractive::get_clip_auto_advance, ctx, this_val, argc, argv);
};
static JSValue audio_stream_interactive_class_set_clip_auto_advance_next_clip(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamInteractive::set_clip_auto_advance_next_clip, ctx, this_val, argc, argv);
};
static JSValue audio_stream_interactive_class_get_clip_auto_advance_next_clip(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamInteractive::get_clip_auto_advance_next_clip, ctx, this_val, argc, argv);
};
static JSValue audio_stream_interactive_class_add_transition(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamInteractive::add_transition, ctx, this_val, argc, argv);
};
static JSValue audio_stream_interactive_class_has_transition(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamInteractive::has_transition, ctx, this_val, argc, argv);
};
static JSValue audio_stream_interactive_class_erase_transition(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamInteractive::erase_transition, ctx, this_val, argc, argv);
};
static JSValue audio_stream_interactive_class_get_transition_list(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamInteractive::get_transition_list, ctx, this_val, argc, argv);
};
static JSValue audio_stream_interactive_class_get_transition_from_time(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamInteractive::get_transition_from_time, ctx, this_val, argc, argv);
};
static JSValue audio_stream_interactive_class_get_transition_to_time(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamInteractive::get_transition_to_time, ctx, this_val, argc, argv);
};
static JSValue audio_stream_interactive_class_get_transition_fade_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamInteractive::get_transition_fade_mode, ctx, this_val, argc, argv);
};
static JSValue audio_stream_interactive_class_get_transition_fade_beats(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamInteractive::get_transition_fade_beats, ctx, this_val, argc, argv);
};
static JSValue audio_stream_interactive_class_is_transition_using_filler_clip(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamInteractive::is_transition_using_filler_clip, ctx, this_val, argc, argv);
};
static JSValue audio_stream_interactive_class_get_transition_filler_clip(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamInteractive::get_transition_filler_clip, ctx, this_val, argc, argv);
};
static JSValue audio_stream_interactive_class_is_transition_holding_previous(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamInteractive::is_transition_holding_previous, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry audio_stream_interactive_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_clip_count", 1, &audio_stream_interactive_class_set_clip_count),
	JS_CFUNC_DEF("get_clip_count", 0, &audio_stream_interactive_class_get_clip_count),
	JS_CFUNC_DEF("set_initial_clip", 1, &audio_stream_interactive_class_set_initial_clip),
	JS_CFUNC_DEF("get_initial_clip", 0, &audio_stream_interactive_class_get_initial_clip),
	JS_CFUNC_DEF("set_clip_name", 2, &audio_stream_interactive_class_set_clip_name),
	JS_CFUNC_DEF("get_clip_name", 1, &audio_stream_interactive_class_get_clip_name),
	JS_CFUNC_DEF("set_clip_stream", 2, &audio_stream_interactive_class_set_clip_stream),
	JS_CFUNC_DEF("get_clip_stream", 1, &audio_stream_interactive_class_get_clip_stream),
	JS_CFUNC_DEF("set_clip_auto_advance", 2, &audio_stream_interactive_class_set_clip_auto_advance),
	JS_CFUNC_DEF("get_clip_auto_advance", 1, &audio_stream_interactive_class_get_clip_auto_advance),
	JS_CFUNC_DEF("set_clip_auto_advance_next_clip", 2, &audio_stream_interactive_class_set_clip_auto_advance_next_clip),
	JS_CFUNC_DEF("get_clip_auto_advance_next_clip", 1, &audio_stream_interactive_class_get_clip_auto_advance_next_clip),
	JS_CFUNC_DEF("add_transition", 9, &audio_stream_interactive_class_add_transition),
	JS_CFUNC_DEF("has_transition", 2, &audio_stream_interactive_class_has_transition),
	JS_CFUNC_DEF("erase_transition", 2, &audio_stream_interactive_class_erase_transition),
	JS_CFUNC_DEF("get_transition_list", 0, &audio_stream_interactive_class_get_transition_list),
	JS_CFUNC_DEF("get_transition_from_time", 2, &audio_stream_interactive_class_get_transition_from_time),
	JS_CFUNC_DEF("get_transition_to_time", 2, &audio_stream_interactive_class_get_transition_to_time),
	JS_CFUNC_DEF("get_transition_fade_mode", 2, &audio_stream_interactive_class_get_transition_fade_mode),
	JS_CFUNC_DEF("get_transition_fade_beats", 2, &audio_stream_interactive_class_get_transition_fade_beats),
	JS_CFUNC_DEF("is_transition_using_filler_clip", 2, &audio_stream_interactive_class_is_transition_using_filler_clip),
	JS_CFUNC_DEF("get_transition_filler_clip", 2, &audio_stream_interactive_class_get_transition_filler_clip),
	JS_CFUNC_DEF("is_transition_holding_previous", 2, &audio_stream_interactive_class_is_transition_holding_previous),
};




static void define_audio_stream_interactive_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "clip_count"),
        JS_NewCFunction(ctx, audio_stream_interactive_class_get_clip_count, "get_clip_count", 0),
        JS_NewCFunction(ctx, audio_stream_interactive_class_set_clip_count, "set_clip_count", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "initial_clip"),
        JS_NewCFunction(ctx, audio_stream_interactive_class_get_initial_clip, "get_initial_clip", 0),
        JS_NewCFunction(ctx, audio_stream_interactive_class_set_initial_clip, "set_initial_clip", 1),
        JS_PROP_GETSET
    );
}

static void define_audio_stream_interactive_enum(JSContext *ctx, JSValue ctor) {
	JSValue TransitionFromTime_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, TransitionFromTime_obj, "TRANSITION_FROM_TIME_IMMEDIATE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, TransitionFromTime_obj, "TRANSITION_FROM_TIME_NEXT_BEAT", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, TransitionFromTime_obj, "TRANSITION_FROM_TIME_NEXT_BAR", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, TransitionFromTime_obj, "TRANSITION_FROM_TIME_END", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ctor, "TransitionFromTime", TransitionFromTime_obj);
	JSValue TransitionToTime_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, TransitionToTime_obj, "TRANSITION_TO_TIME_SAME_POSITION", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, TransitionToTime_obj, "TRANSITION_TO_TIME_START", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ctor, "TransitionToTime", TransitionToTime_obj);
	JSValue FadeMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, FadeMode_obj, "FADE_DISABLED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, FadeMode_obj, "FADE_IN", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, FadeMode_obj, "FADE_OUT", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, FadeMode_obj, "FADE_CROSS", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, FadeMode_obj, "FADE_AUTOMATIC", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, ctor, "FadeMode", FadeMode_obj);
	JSValue AutoAdvanceMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, AutoAdvanceMode_obj, "AUTO_ADVANCE_DISABLED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, AutoAdvanceMode_obj, "AUTO_ADVANCE_ENABLED", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, AutoAdvanceMode_obj, "AUTO_ADVANCE_RETURN_TO_HOLD", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "AutoAdvanceMode", AutoAdvanceMode_obj);
}

static int js_audio_stream_interactive_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["AudioStreamInteractive"] = class_id;
	classes_by_id[class_id] = "AudioStreamInteractive";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &audio_stream_interactive_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["AudioStream"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_audio_stream_interactive_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, audio_stream_interactive_class_proto_funcs, _countof(audio_stream_interactive_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, audio_stream_interactive_class_constructor, "AudioStreamInteractive", 0, JS_CFUNC_constructor, 0);
	define_audio_stream_interactive_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "AudioStreamInteractive", ctor);
	ctor_list["AudioStreamInteractive"] = ctor;

	return 0;
}

JSModuleDef *_js_init_audio_stream_interactive_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/audio_stream';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_audio_stream_interactive_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "AudioStreamInteractive");
	return m;
}

JSModuleDef *js_init_audio_stream_interactive_module(JSContext *ctx) {
	return _js_init_audio_stream_interactive_module(ctx, "@godot/classes/audio_stream_interactive");
}

void __register_audio_stream_interactive() {
	js_init_audio_stream_interactive_module(js_context());
}

void register_audio_stream_interactive() {
	__register_audio_stream_interactive();
}