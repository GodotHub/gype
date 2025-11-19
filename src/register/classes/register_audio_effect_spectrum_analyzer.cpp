#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/audio_effect.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/audio_effect_spectrum_analyzer.hpp>
using namespace godot;

static void audio_effect_spectrum_analyzer_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["AudioEffectSpectrumAnalyzer"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef audio_effect_spectrum_analyzer_class_def = {
    "AudioEffectSpectrumAnalyzer",
    audio_effect_spectrum_analyzer_class_finalizer
};

static JSValue audio_effect_spectrum_analyzer_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["AudioEffectSpectrumAnalyzer"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    AudioEffectSpectrumAnalyzer *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<AudioEffectSpectrumAnalyzer *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(AudioEffectSpectrumAnalyzer);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue audio_effect_spectrum_analyzer_class_set_buffer_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectSpectrumAnalyzer::set_buffer_length, ctx, this_val, argc, argv);
};
static JSValue audio_effect_spectrum_analyzer_class_get_buffer_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectSpectrumAnalyzer::get_buffer_length, ctx, this_val, argc, argv);
}
static JSValue audio_effect_spectrum_analyzer_class_set_tap_back_pos(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectSpectrumAnalyzer::set_tap_back_pos, ctx, this_val, argc, argv);
};
static JSValue audio_effect_spectrum_analyzer_class_get_tap_back_pos(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectSpectrumAnalyzer::get_tap_back_pos, ctx, this_val, argc, argv);
}
static JSValue audio_effect_spectrum_analyzer_class_set_fft_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectSpectrumAnalyzer::set_fft_size, ctx, this_val, argc, argv);
};
static JSValue audio_effect_spectrum_analyzer_class_get_fft_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectSpectrumAnalyzer::get_fft_size, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry audio_effect_spectrum_analyzer_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_buffer_length", 1, &audio_effect_spectrum_analyzer_class_set_buffer_length),
	JS_CFUNC_DEF("get_buffer_length", 0, &audio_effect_spectrum_analyzer_class_get_buffer_length),
	JS_CFUNC_DEF("set_tap_back_pos", 1, &audio_effect_spectrum_analyzer_class_set_tap_back_pos),
	JS_CFUNC_DEF("get_tap_back_pos", 0, &audio_effect_spectrum_analyzer_class_get_tap_back_pos),
	JS_CFUNC_DEF("set_fft_size", 1, &audio_effect_spectrum_analyzer_class_set_fft_size),
	JS_CFUNC_DEF("get_fft_size", 0, &audio_effect_spectrum_analyzer_class_get_fft_size),
};




static void define_audio_effect_spectrum_analyzer_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "buffer_length"),
        JS_NewCFunction(ctx, audio_effect_spectrum_analyzer_class_get_buffer_length, "get_buffer_length", 0),
        JS_NewCFunction(ctx, audio_effect_spectrum_analyzer_class_set_buffer_length, "set_buffer_length", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "tap_back_pos"),
        JS_NewCFunction(ctx, audio_effect_spectrum_analyzer_class_get_tap_back_pos, "get_tap_back_pos", 0),
        JS_NewCFunction(ctx, audio_effect_spectrum_analyzer_class_set_tap_back_pos, "set_tap_back_pos", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "fft_size"),
        JS_NewCFunction(ctx, audio_effect_spectrum_analyzer_class_get_fft_size, "get_fft_size", 0),
        JS_NewCFunction(ctx, audio_effect_spectrum_analyzer_class_set_fft_size, "set_fft_size", 1),
        JS_PROP_GETSET
    );
}

static void define_audio_effect_spectrum_analyzer_enum(JSContext *ctx, JSValue ctor) {
	JSValue FFTSize_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, FFTSize_obj, "FFT_SIZE_256", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, FFTSize_obj, "FFT_SIZE_512", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, FFTSize_obj, "FFT_SIZE_1024", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, FFTSize_obj, "FFT_SIZE_2048", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, FFTSize_obj, "FFT_SIZE_4096", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, FFTSize_obj, "FFT_SIZE_MAX", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, ctor, "FFTSize", FFTSize_obj);
}

static int js_audio_effect_spectrum_analyzer_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["AudioEffectSpectrumAnalyzer"] = class_id;
	classes_by_id[class_id] = "AudioEffectSpectrumAnalyzer";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &audio_effect_spectrum_analyzer_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["AudioEffect"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_audio_effect_spectrum_analyzer_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, audio_effect_spectrum_analyzer_class_proto_funcs, _countof(audio_effect_spectrum_analyzer_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, audio_effect_spectrum_analyzer_class_constructor, "AudioEffectSpectrumAnalyzer", 0, JS_CFUNC_constructor, 0);
	define_audio_effect_spectrum_analyzer_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "AudioEffectSpectrumAnalyzer", ctor);

	return 0;
}

JSModuleDef *_js_init_audio_effect_spectrum_analyzer_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/audio_effect';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_audio_effect_spectrum_analyzer_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "AudioEffectSpectrumAnalyzer");
	return m;
}

JSModuleDef *js_init_audio_effect_spectrum_analyzer_module(JSContext *ctx) {
	return _js_init_audio_effect_spectrum_analyzer_module(ctx, "@godot/classes/audio_effect_spectrum_analyzer");
}

void __register_audio_effect_spectrum_analyzer() {
	js_init_audio_effect_spectrum_analyzer_module(js_context());
}

void register_audio_effect_spectrum_analyzer() {
	__register_audio_effect_spectrum_analyzer();
}