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
#include <godot_cpp/classes/audio_stream_generator.hpp>
using namespace godot;

static void audio_stream_generator_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["AudioStreamGenerator"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef audio_stream_generator_class_def = {
    "AudioStreamGenerator",
    audio_stream_generator_class_finalizer
};

static JSValue audio_stream_generator_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["AudioStreamGenerator"];
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
        instance = memnew(AudioStreamGenerator);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue audio_stream_generator_class_set_mix_rate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamGenerator::set_mix_rate, ctx, this_val, argc, argv);
};
static JSValue audio_stream_generator_class_get_mix_rate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamGenerator::get_mix_rate, ctx, this_val, argc, argv);
}
static JSValue audio_stream_generator_class_set_mix_rate_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamGenerator::set_mix_rate_mode, ctx, this_val, argc, argv);
};
static JSValue audio_stream_generator_class_get_mix_rate_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamGenerator::get_mix_rate_mode, ctx, this_val, argc, argv);
}
static JSValue audio_stream_generator_class_set_buffer_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamGenerator::set_buffer_length, ctx, this_val, argc, argv);
};
static JSValue audio_stream_generator_class_get_buffer_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamGenerator::get_buffer_length, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry audio_stream_generator_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_mix_rate", 1, &audio_stream_generator_class_set_mix_rate),
	JS_CFUNC_DEF("get_mix_rate", 0, &audio_stream_generator_class_get_mix_rate),
	JS_CFUNC_DEF("set_mix_rate_mode", 1, &audio_stream_generator_class_set_mix_rate_mode),
	JS_CFUNC_DEF("get_mix_rate_mode", 0, &audio_stream_generator_class_get_mix_rate_mode),
	JS_CFUNC_DEF("set_buffer_length", 1, &audio_stream_generator_class_set_buffer_length),
	JS_CFUNC_DEF("get_buffer_length", 0, &audio_stream_generator_class_get_buffer_length),
};




static void define_audio_stream_generator_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "mix_rate_mode"),
        JS_NewCFunction(ctx, audio_stream_generator_class_get_mix_rate_mode, "get_mix_rate_mode", 0),
        JS_NewCFunction(ctx, audio_stream_generator_class_set_mix_rate_mode, "set_mix_rate_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "mix_rate"),
        JS_NewCFunction(ctx, audio_stream_generator_class_get_mix_rate, "get_mix_rate", 0),
        JS_NewCFunction(ctx, audio_stream_generator_class_set_mix_rate, "set_mix_rate", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "buffer_length"),
        JS_NewCFunction(ctx, audio_stream_generator_class_get_buffer_length, "get_buffer_length", 0),
        JS_NewCFunction(ctx, audio_stream_generator_class_set_buffer_length, "set_buffer_length", 1),
        JS_PROP_GETSET
    );
}

static void define_audio_stream_generator_enum(JSContext *ctx, JSValue ctor) {
	JSValue AudioStreamGeneratorMixRate_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, AudioStreamGeneratorMixRate_obj, "MIX_RATE_OUTPUT", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, AudioStreamGeneratorMixRate_obj, "MIX_RATE_INPUT", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, AudioStreamGeneratorMixRate_obj, "MIX_RATE_CUSTOM", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, AudioStreamGeneratorMixRate_obj, "MIX_RATE_MAX", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ctor, "AudioStreamGeneratorMixRate", AudioStreamGeneratorMixRate_obj);
}

static int js_audio_stream_generator_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["AudioStreamGenerator"] = class_id;
	classes_by_id[class_id] = "AudioStreamGenerator";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &audio_stream_generator_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["AudioStream"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_audio_stream_generator_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, audio_stream_generator_class_proto_funcs, _countof(audio_stream_generator_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, audio_stream_generator_class_constructor, "AudioStreamGenerator", 0, JS_CFUNC_constructor, 0);
	define_audio_stream_generator_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "AudioStreamGenerator", ctor);
	ctor_list["AudioStreamGenerator"] = ctor;

	return 0;
}

JSModuleDef *_js_init_audio_stream_generator_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/audio_stream';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_audio_stream_generator_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "AudioStreamGenerator");
	return m;
}

JSModuleDef *js_init_audio_stream_generator_module(JSContext *ctx) {
	return _js_init_audio_stream_generator_module(ctx, "@godot/classes/audio_stream_generator");
}

void __register_audio_stream_generator() {
	js_init_audio_stream_generator_module(js_context());
}

void register_audio_stream_generator() {
	__register_audio_stream_generator();
}