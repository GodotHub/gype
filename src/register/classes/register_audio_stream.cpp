#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/audio_sample.hpp>
#include <godot_cpp/classes/audio_stream_playback.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/audio_stream.hpp>
using namespace godot;

static void audio_stream_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["AudioStream"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef audio_stream_class_def = {
    "AudioStream",
    audio_stream_class_finalizer
};

static JSValue audio_stream_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["AudioStream"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    AudioStream *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<AudioStream *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(AudioStream);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue audio_stream_class_get_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStream::get_length, ctx, this_val, argc, argv);
};
static JSValue audio_stream_class_is_monophonic(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStream::is_monophonic, ctx, this_val, argc, argv);
};
static JSValue audio_stream_class_instantiate_playback(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&AudioStream::instantiate_playback, ctx, this_val, argc, argv);
};
static JSValue audio_stream_class_can_be_sampled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStream::can_be_sampled, ctx, this_val, argc, argv);
};
static JSValue audio_stream_class_generate_sample(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStream::generate_sample, ctx, this_val, argc, argv);
};
static JSValue audio_stream_class_is_meta_stream(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStream::is_meta_stream, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry audio_stream_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_length", 0, &audio_stream_class_get_length),
	JS_CFUNC_DEF("is_monophonic", 0, &audio_stream_class_is_monophonic),
	JS_CFUNC_DEF("instantiate_playback", 0, &audio_stream_class_instantiate_playback),
	JS_CFUNC_DEF("can_be_sampled", 0, &audio_stream_class_can_be_sampled),
	JS_CFUNC_DEF("generate_sample", 0, &audio_stream_class_generate_sample),
	JS_CFUNC_DEF("is_meta_stream", 0, &audio_stream_class_is_meta_stream),
};


static JSValue audio_stream_class_get_parameter_list_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	AudioStream *opaque = static_cast<AudioStream *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "parameter_list_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "parameter_list_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "parameter_list_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_audio_stream_property(JSContext *ctx, JSValue proto) {
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "parameter_list_changed"),
		JS_NewCFunction(ctx, audio_stream_class_get_parameter_list_changed_signal, "get_parameter_list_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_audio_stream_enum(JSContext *ctx, JSValue ctor) {
}

static int js_audio_stream_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["AudioStream"] = class_id;
	classes_by_id[class_id] = "AudioStream";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &audio_stream_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_audio_stream_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, audio_stream_class_proto_funcs, _countof(audio_stream_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, audio_stream_class_constructor, "AudioStream", 0, JS_CFUNC_constructor, 0);
	define_audio_stream_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "AudioStream", ctor);

	return 0;
}

JSModuleDef *_js_init_audio_stream_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_audio_stream_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "AudioStream");
	return m;
}

JSModuleDef *js_init_audio_stream_module(JSContext *ctx) {
	return _js_init_audio_stream_module(ctx, "@godot/classes/audio_stream");
}

void __register_audio_stream() {
	js_init_audio_stream_module(js_context());
}

void register_audio_stream() {
	__register_audio_stream();
}