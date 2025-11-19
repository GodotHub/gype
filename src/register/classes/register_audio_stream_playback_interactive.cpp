#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/audio_stream_playback.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/audio_stream_playback_interactive.hpp>
using namespace godot;

static void audio_stream_playback_interactive_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["AudioStreamPlaybackInteractive"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef audio_stream_playback_interactive_class_def = {
    "AudioStreamPlaybackInteractive",
    audio_stream_playback_interactive_class_finalizer
};

static JSValue audio_stream_playback_interactive_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["AudioStreamPlaybackInteractive"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    AudioStreamPlaybackInteractive *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<AudioStreamPlaybackInteractive *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(AudioStreamPlaybackInteractive);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue audio_stream_playback_interactive_class_switch_to_clip_by_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamPlaybackInteractive::switch_to_clip_by_name, ctx, this_val, argc, argv);
};
static JSValue audio_stream_playback_interactive_class_switch_to_clip(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamPlaybackInteractive::switch_to_clip, ctx, this_val, argc, argv);
};
static JSValue audio_stream_playback_interactive_class_get_current_clip_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamPlaybackInteractive::get_current_clip_index, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry audio_stream_playback_interactive_class_proto_funcs[] = {
	JS_CFUNC_DEF("switch_to_clip_by_name", 1, &audio_stream_playback_interactive_class_switch_to_clip_by_name),
	JS_CFUNC_DEF("switch_to_clip", 1, &audio_stream_playback_interactive_class_switch_to_clip),
	JS_CFUNC_DEF("get_current_clip_index", 0, &audio_stream_playback_interactive_class_get_current_clip_index),
};




static void define_audio_stream_playback_interactive_property(JSContext *ctx, JSValue proto) {
}

static void define_audio_stream_playback_interactive_enum(JSContext *ctx, JSValue ctor) {
}

static int js_audio_stream_playback_interactive_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["AudioStreamPlaybackInteractive"] = class_id;
	classes_by_id[class_id] = "AudioStreamPlaybackInteractive";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &audio_stream_playback_interactive_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["AudioStreamPlayback"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_audio_stream_playback_interactive_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, audio_stream_playback_interactive_class_proto_funcs, _countof(audio_stream_playback_interactive_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, audio_stream_playback_interactive_class_constructor, "AudioStreamPlaybackInteractive", 0, JS_CFUNC_constructor, 0);
	define_audio_stream_playback_interactive_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "AudioStreamPlaybackInteractive", ctor);

	return 0;
}

JSModuleDef *_js_init_audio_stream_playback_interactive_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/audio_stream_playback';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_audio_stream_playback_interactive_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "AudioStreamPlaybackInteractive");
	return m;
}

JSModuleDef *js_init_audio_stream_playback_interactive_module(JSContext *ctx) {
	return _js_init_audio_stream_playback_interactive_module(ctx, "@godot/classes/audio_stream_playback_interactive");
}

void __register_audio_stream_playback_interactive() {
	js_init_audio_stream_playback_interactive_module(js_context());
}

void register_audio_stream_playback_interactive() {
	__register_audio_stream_playback_interactive();
}