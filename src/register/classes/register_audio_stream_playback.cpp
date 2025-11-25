#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/audio_sample_playback.hpp>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/audio_stream_playback.hpp>
using namespace godot;

static void audio_stream_playback_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["AudioStreamPlayback"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef audio_stream_playback_class_def = {
    "AudioStreamPlayback",
    audio_stream_playback_class_finalizer
};

static JSValue audio_stream_playback_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["AudioStreamPlayback"];
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
        instance = memnew(AudioStreamPlayback);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue audio_stream_playback_class_set_sample_playback(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamPlayback::set_sample_playback, ctx, this_val, argc, argv);
};
static JSValue audio_stream_playback_class_get_sample_playback(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamPlayback::get_sample_playback, ctx, this_val, argc, argv);
};
static JSValue audio_stream_playback_class_mix_audio(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&AudioStreamPlayback::mix_audio, ctx, this_val, argc, argv);
};
static JSValue audio_stream_playback_class_start(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamPlayback::start, ctx, this_val, argc, argv);
};
static JSValue audio_stream_playback_class_seek(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamPlayback::seek, ctx, this_val, argc, argv);
};
static JSValue audio_stream_playback_class_stop(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamPlayback::stop, ctx, this_val, argc, argv);
};
static JSValue audio_stream_playback_class_get_loop_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamPlayback::get_loop_count, ctx, this_val, argc, argv);
};
static JSValue audio_stream_playback_class_get_playback_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamPlayback::get_playback_position, ctx, this_val, argc, argv);
};
static JSValue audio_stream_playback_class_is_playing(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamPlayback::is_playing, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry audio_stream_playback_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_sample_playback", 1, &audio_stream_playback_class_set_sample_playback),
	JS_CFUNC_DEF("get_sample_playback", 0, &audio_stream_playback_class_get_sample_playback),
	JS_CFUNC_DEF("mix_audio", 2, &audio_stream_playback_class_mix_audio),
	JS_CFUNC_DEF("start", 1, &audio_stream_playback_class_start),
	JS_CFUNC_DEF("seek", 1, &audio_stream_playback_class_seek),
	JS_CFUNC_DEF("stop", 0, &audio_stream_playback_class_stop),
	JS_CFUNC_DEF("get_loop_count", 0, &audio_stream_playback_class_get_loop_count),
	JS_CFUNC_DEF("get_playback_position", 0, &audio_stream_playback_class_get_playback_position),
	JS_CFUNC_DEF("is_playing", 0, &audio_stream_playback_class_is_playing),
};




static void define_audio_stream_playback_property(JSContext *ctx, JSValue proto) {
}

static void define_audio_stream_playback_enum(JSContext *ctx, JSValue ctor) {
}

static int js_audio_stream_playback_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["AudioStreamPlayback"] = class_id;
	classes_by_id[class_id] = "AudioStreamPlayback";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &audio_stream_playback_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_audio_stream_playback_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, audio_stream_playback_class_proto_funcs, _countof(audio_stream_playback_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, audio_stream_playback_class_constructor, "AudioStreamPlayback", 0, JS_CFUNC_constructor, 0);
	define_audio_stream_playback_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "AudioStreamPlayback", ctor);
	ctor_list["AudioStreamPlayback"] = ctor;

	return 0;
}

JSModuleDef *_js_init_audio_stream_playback_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_audio_stream_playback_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "AudioStreamPlayback");
	return m;
}

JSModuleDef *js_init_audio_stream_playback_module(JSContext *ctx) {
	return _js_init_audio_stream_playback_module(ctx, "@godot/classes/audio_stream_playback");
}

void __register_audio_stream_playback() {
	js_init_audio_stream_playback_module(js_context());
}

void register_audio_stream_playback() {
	__register_audio_stream_playback();
}