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
#include <godot_cpp/classes/audio_stream_wav.hpp>
using namespace godot;

static void audio_stream_wav_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["AudioStreamWAV"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef audio_stream_wav_class_def = {
    "AudioStreamWAV",
    audio_stream_wav_class_finalizer
};

static JSValue audio_stream_wav_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["AudioStreamWAV"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    AudioStreamWAV *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<AudioStreamWAV *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(AudioStreamWAV);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue audio_stream_wav_class_set_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamWAV::set_data, ctx, this_val, argc, argv);
};
static JSValue audio_stream_wav_class_get_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedByteArray> *proxy = memnew(ObjectProxy<PackedByteArray>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedByteArray {
		AudioStreamWAV *obj = static_cast<AudioStreamWAV *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_data();
	};
	proxy->setter = [this_val](const PackedByteArray &value) -> void {
		AudioStreamWAV *js_proxy = static_cast<AudioStreamWAV *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_data(PackedByteArray
(Array(value)));
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["PackedByteArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "PackedByteArrayProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue audio_stream_wav_class_set_format(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamWAV::set_format, ctx, this_val, argc, argv);
};
static JSValue audio_stream_wav_class_get_format(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamWAV::get_format, ctx, this_val, argc, argv);
}
static JSValue audio_stream_wav_class_set_loop_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamWAV::set_loop_mode, ctx, this_val, argc, argv);
};
static JSValue audio_stream_wav_class_get_loop_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamWAV::get_loop_mode, ctx, this_val, argc, argv);
}
static JSValue audio_stream_wav_class_set_loop_begin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamWAV::set_loop_begin, ctx, this_val, argc, argv);
};
static JSValue audio_stream_wav_class_get_loop_begin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamWAV::get_loop_begin, ctx, this_val, argc, argv);
}
static JSValue audio_stream_wav_class_set_loop_end(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamWAV::set_loop_end, ctx, this_val, argc, argv);
};
static JSValue audio_stream_wav_class_get_loop_end(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamWAV::get_loop_end, ctx, this_val, argc, argv);
}
static JSValue audio_stream_wav_class_set_mix_rate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamWAV::set_mix_rate, ctx, this_val, argc, argv);
};
static JSValue audio_stream_wav_class_get_mix_rate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamWAV::get_mix_rate, ctx, this_val, argc, argv);
}
static JSValue audio_stream_wav_class_set_stereo(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamWAV::set_stereo, ctx, this_val, argc, argv);
};
static JSValue audio_stream_wav_class_is_stereo(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamWAV::is_stereo, ctx, this_val, argc, argv);
}
static JSValue audio_stream_wav_class_set_tags(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamWAV::set_tags, ctx, this_val, argc, argv);
};
static JSValue audio_stream_wav_class_get_tags(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Dictionary> *proxy = memnew(ObjectProxy<Dictionary>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Dictionary {
		AudioStreamWAV *obj = static_cast<AudioStreamWAV *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_tags();
	};
	proxy->setter = [this_val](const Dictionary &value) -> void {
		AudioStreamWAV *js_proxy = static_cast<AudioStreamWAV *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_tags(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["DictionaryProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "DictionaryProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue audio_stream_wav_class_save_to_wav(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&AudioStreamWAV::save_to_wav, ctx, this_val, argc, argv);
};
static JSValue audio_stream_wav_class_load_from_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&AudioStreamWAV::load_from_buffer, ctx, this_val, argc, argv);
};
static JSValue audio_stream_wav_class_load_from_file(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&AudioStreamWAV::load_from_file, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry audio_stream_wav_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_data", 1, &audio_stream_wav_class_set_data),
	JS_CFUNC_DEF("get_data", 0, &audio_stream_wav_class_get_data),
	JS_CFUNC_DEF("set_format", 1, &audio_stream_wav_class_set_format),
	JS_CFUNC_DEF("get_format", 0, &audio_stream_wav_class_get_format),
	JS_CFUNC_DEF("set_loop_mode", 1, &audio_stream_wav_class_set_loop_mode),
	JS_CFUNC_DEF("get_loop_mode", 0, &audio_stream_wav_class_get_loop_mode),
	JS_CFUNC_DEF("set_loop_begin", 1, &audio_stream_wav_class_set_loop_begin),
	JS_CFUNC_DEF("get_loop_begin", 0, &audio_stream_wav_class_get_loop_begin),
	JS_CFUNC_DEF("set_loop_end", 1, &audio_stream_wav_class_set_loop_end),
	JS_CFUNC_DEF("get_loop_end", 0, &audio_stream_wav_class_get_loop_end),
	JS_CFUNC_DEF("set_mix_rate", 1, &audio_stream_wav_class_set_mix_rate),
	JS_CFUNC_DEF("get_mix_rate", 0, &audio_stream_wav_class_get_mix_rate),
	JS_CFUNC_DEF("set_stereo", 1, &audio_stream_wav_class_set_stereo),
	JS_CFUNC_DEF("is_stereo", 0, &audio_stream_wav_class_is_stereo),
	JS_CFUNC_DEF("set_tags", 1, &audio_stream_wav_class_set_tags),
	JS_CFUNC_DEF("get_tags", 0, &audio_stream_wav_class_get_tags),
	JS_CFUNC_DEF("save_to_wav", 1, &audio_stream_wav_class_save_to_wav),
};

static const JSCFunctionListEntry audio_stream_wav_class_static_funcs[] = {
	JS_CFUNC_DEF("load_from_buffer", 2, &audio_stream_wav_class_load_from_buffer),
	JS_CFUNC_DEF("load_from_file", 2, &audio_stream_wav_class_load_from_file),
};



static void define_audio_stream_wav_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "data"),
        JS_NewCFunction(ctx, audio_stream_wav_class_get_data, "get_data", 0),
        JS_NewCFunction(ctx, audio_stream_wav_class_set_data, "set_data", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "format"),
        JS_NewCFunction(ctx, audio_stream_wav_class_get_format, "get_format", 0),
        JS_NewCFunction(ctx, audio_stream_wav_class_set_format, "set_format", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "loop_mode"),
        JS_NewCFunction(ctx, audio_stream_wav_class_get_loop_mode, "get_loop_mode", 0),
        JS_NewCFunction(ctx, audio_stream_wav_class_set_loop_mode, "set_loop_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "loop_begin"),
        JS_NewCFunction(ctx, audio_stream_wav_class_get_loop_begin, "get_loop_begin", 0),
        JS_NewCFunction(ctx, audio_stream_wav_class_set_loop_begin, "set_loop_begin", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "loop_end"),
        JS_NewCFunction(ctx, audio_stream_wav_class_get_loop_end, "get_loop_end", 0),
        JS_NewCFunction(ctx, audio_stream_wav_class_set_loop_end, "set_loop_end", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "mix_rate"),
        JS_NewCFunction(ctx, audio_stream_wav_class_get_mix_rate, "get_mix_rate", 0),
        JS_NewCFunction(ctx, audio_stream_wav_class_set_mix_rate, "set_mix_rate", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "stereo"),
        JS_NewCFunction(ctx, audio_stream_wav_class_is_stereo, "is_stereo", 0),
        JS_NewCFunction(ctx, audio_stream_wav_class_set_stereo, "set_stereo", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "tags"),
        JS_NewCFunction(ctx, audio_stream_wav_class_get_tags, "get_tags", 0),
        JS_NewCFunction(ctx, audio_stream_wav_class_set_tags, "set_tags", 1),
        JS_PROP_GETSET
    );
}

static void define_audio_stream_wav_enum(JSContext *ctx, JSValue ctor) {
	JSValue Format_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, Format_obj, "FORMAT_8_BITS", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, Format_obj, "FORMAT_16_BITS", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, Format_obj, "FORMAT_IMA_ADPCM", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, Format_obj, "FORMAT_QOA", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ctor, "Format", Format_obj);
	JSValue LoopMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, LoopMode_obj, "LOOP_DISABLED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, LoopMode_obj, "LOOP_FORWARD", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, LoopMode_obj, "LOOP_PINGPONG", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, LoopMode_obj, "LOOP_BACKWARD", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ctor, "LoopMode", LoopMode_obj);
}

static int js_audio_stream_wav_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["AudioStreamWAV"] = class_id;
	classes_by_id[class_id] = "AudioStreamWAV";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &audio_stream_wav_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["AudioStream"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_audio_stream_wav_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, audio_stream_wav_class_proto_funcs, _countof(audio_stream_wav_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, audio_stream_wav_class_constructor, "AudioStreamWAV", 0, JS_CFUNC_constructor, 0);
	JS_SetPropertyFunctionList(ctx, ctor, audio_stream_wav_class_static_funcs, _countof(audio_stream_wav_class_static_funcs));
	define_audio_stream_wav_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "AudioStreamWAV", ctor);

	return 0;
}

JSModuleDef *_js_init_audio_stream_wav_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/audio_stream';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_audio_stream_wav_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "AudioStreamWAV");
	return m;
}

JSModuleDef *js_init_audio_stream_wav_module(JSContext *ctx) {
	return _js_init_audio_stream_wav_module(ctx, "@godot/classes/audio_stream_wav");
}

void __register_audio_stream_wav() {
	js_init_audio_stream_wav_module(js_context());
}

void register_audio_stream_wav() {
	__register_audio_stream_wav();
}