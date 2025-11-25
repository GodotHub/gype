#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/audio_stream_playback_resampled.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/audio_stream_generator_playback.hpp>
using namespace godot;

static void audio_stream_generator_playback_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["AudioStreamGeneratorPlayback"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef audio_stream_generator_playback_class_def = {
    "AudioStreamGeneratorPlayback",
    audio_stream_generator_playback_class_finalizer
};

static JSValue audio_stream_generator_playback_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["AudioStreamGeneratorPlayback"];
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
        instance = memnew(AudioStreamGeneratorPlayback);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue audio_stream_generator_playback_class_push_frame(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&AudioStreamGeneratorPlayback::push_frame, ctx, this_val, argc, argv);
};
static JSValue audio_stream_generator_playback_class_can_push_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamGeneratorPlayback::can_push_buffer, ctx, this_val, argc, argv);
};
static JSValue audio_stream_generator_playback_class_push_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&AudioStreamGeneratorPlayback::push_buffer, ctx, this_val, argc, argv);
};
static JSValue audio_stream_generator_playback_class_get_frames_available(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamGeneratorPlayback::get_frames_available, ctx, this_val, argc, argv);
};
static JSValue audio_stream_generator_playback_class_get_skips(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamGeneratorPlayback::get_skips, ctx, this_val, argc, argv);
};
static JSValue audio_stream_generator_playback_class_clear_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamGeneratorPlayback::clear_buffer, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry audio_stream_generator_playback_class_proto_funcs[] = {
	JS_CFUNC_DEF("push_frame", 1, &audio_stream_generator_playback_class_push_frame),
	JS_CFUNC_DEF("can_push_buffer", 1, &audio_stream_generator_playback_class_can_push_buffer),
	JS_CFUNC_DEF("push_buffer", 1, &audio_stream_generator_playback_class_push_buffer),
	JS_CFUNC_DEF("get_frames_available", 0, &audio_stream_generator_playback_class_get_frames_available),
	JS_CFUNC_DEF("get_skips", 0, &audio_stream_generator_playback_class_get_skips),
	JS_CFUNC_DEF("clear_buffer", 0, &audio_stream_generator_playback_class_clear_buffer),
};




static void define_audio_stream_generator_playback_property(JSContext *ctx, JSValue proto) {
}

static void define_audio_stream_generator_playback_enum(JSContext *ctx, JSValue ctor) {
}

static int js_audio_stream_generator_playback_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["AudioStreamGeneratorPlayback"] = class_id;
	classes_by_id[class_id] = "AudioStreamGeneratorPlayback";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &audio_stream_generator_playback_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["AudioStreamPlaybackResampled"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_audio_stream_generator_playback_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, audio_stream_generator_playback_class_proto_funcs, _countof(audio_stream_generator_playback_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, audio_stream_generator_playback_class_constructor, "AudioStreamGeneratorPlayback", 0, JS_CFUNC_constructor, 0);
	define_audio_stream_generator_playback_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "AudioStreamGeneratorPlayback", ctor);
	ctor_list["AudioStreamGeneratorPlayback"] = ctor;

	return 0;
}

JSModuleDef *_js_init_audio_stream_generator_playback_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/audio_stream_playback_resampled';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_audio_stream_generator_playback_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "AudioStreamGeneratorPlayback");
	return m;
}

JSModuleDef *js_init_audio_stream_generator_playback_module(JSContext *ctx) {
	return _js_init_audio_stream_generator_playback_module(ctx, "@godot/classes/audio_stream_generator_playback");
}

void __register_audio_stream_generator_playback() {
	js_init_audio_stream_generator_playback_module(js_context());
}

void register_audio_stream_generator_playback() {
	__register_audio_stream_generator_playback();
}