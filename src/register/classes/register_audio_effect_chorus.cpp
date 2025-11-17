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
#include <godot_cpp/classes/audio_effect_chorus.hpp>
using namespace godot;

static void audio_effect_chorus_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["AudioEffectChorus"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef audio_effect_chorus_class_def = {
    "AudioEffectChorus",
    audio_effect_chorus_class_finalizer
};

static JSValue audio_effect_chorus_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["AudioEffectChorus"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    AudioEffectChorus *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<AudioEffectChorus *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(AudioEffectChorus);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue audio_effect_chorus_class_set_voice_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectChorus::set_voice_count, ctx, this_val, argc, argv);
};
static JSValue audio_effect_chorus_class_get_voice_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectChorus::get_voice_count, ctx, this_val, argc, argv);
}
static JSValue audio_effect_chorus_class_set_voice_delay_ms(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectChorus::set_voice_delay_ms, ctx, this_val, argc, argv);
};
static JSValue audio_effect_chorus_class_get_voice_delay_ms(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectChorus::get_voice_delay_ms, ctx, this_val, argc, argv);
};
static JSValue audio_effect_chorus_class_set_voice_rate_hz(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectChorus::set_voice_rate_hz, ctx, this_val, argc, argv);
};
static JSValue audio_effect_chorus_class_get_voice_rate_hz(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectChorus::get_voice_rate_hz, ctx, this_val, argc, argv);
};
static JSValue audio_effect_chorus_class_set_voice_depth_ms(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectChorus::set_voice_depth_ms, ctx, this_val, argc, argv);
};
static JSValue audio_effect_chorus_class_get_voice_depth_ms(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectChorus::get_voice_depth_ms, ctx, this_val, argc, argv);
};
static JSValue audio_effect_chorus_class_set_voice_level_db(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectChorus::set_voice_level_db, ctx, this_val, argc, argv);
};
static JSValue audio_effect_chorus_class_get_voice_level_db(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectChorus::get_voice_level_db, ctx, this_val, argc, argv);
};
static JSValue audio_effect_chorus_class_set_voice_cutoff_hz(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectChorus::set_voice_cutoff_hz, ctx, this_val, argc, argv);
};
static JSValue audio_effect_chorus_class_get_voice_cutoff_hz(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectChorus::get_voice_cutoff_hz, ctx, this_val, argc, argv);
};
static JSValue audio_effect_chorus_class_set_voice_pan(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectChorus::set_voice_pan, ctx, this_val, argc, argv);
};
static JSValue audio_effect_chorus_class_get_voice_pan(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectChorus::get_voice_pan, ctx, this_val, argc, argv);
};
static JSValue audio_effect_chorus_class_set_wet(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectChorus::set_wet, ctx, this_val, argc, argv);
};
static JSValue audio_effect_chorus_class_get_wet(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectChorus::get_wet, ctx, this_val, argc, argv);
}
static JSValue audio_effect_chorus_class_set_dry(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectChorus::set_dry, ctx, this_val, argc, argv);
};
static JSValue audio_effect_chorus_class_get_dry(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectChorus::get_dry, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry audio_effect_chorus_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_voice_count", 1, &audio_effect_chorus_class_set_voice_count),
	JS_CFUNC_DEF("get_voice_count", 0, &audio_effect_chorus_class_get_voice_count),
	JS_CFUNC_DEF("set_voice_delay_ms", 2, &audio_effect_chorus_class_set_voice_delay_ms),
	JS_CFUNC_DEF("get_voice_delay_ms", 1, &audio_effect_chorus_class_get_voice_delay_ms),
	JS_CFUNC_DEF("set_voice_rate_hz", 2, &audio_effect_chorus_class_set_voice_rate_hz),
	JS_CFUNC_DEF("get_voice_rate_hz", 1, &audio_effect_chorus_class_get_voice_rate_hz),
	JS_CFUNC_DEF("set_voice_depth_ms", 2, &audio_effect_chorus_class_set_voice_depth_ms),
	JS_CFUNC_DEF("get_voice_depth_ms", 1, &audio_effect_chorus_class_get_voice_depth_ms),
	JS_CFUNC_DEF("set_voice_level_db", 2, &audio_effect_chorus_class_set_voice_level_db),
	JS_CFUNC_DEF("get_voice_level_db", 1, &audio_effect_chorus_class_get_voice_level_db),
	JS_CFUNC_DEF("set_voice_cutoff_hz", 2, &audio_effect_chorus_class_set_voice_cutoff_hz),
	JS_CFUNC_DEF("get_voice_cutoff_hz", 1, &audio_effect_chorus_class_get_voice_cutoff_hz),
	JS_CFUNC_DEF("set_voice_pan", 2, &audio_effect_chorus_class_set_voice_pan),
	JS_CFUNC_DEF("get_voice_pan", 1, &audio_effect_chorus_class_get_voice_pan),
	JS_CFUNC_DEF("set_wet", 1, &audio_effect_chorus_class_set_wet),
	JS_CFUNC_DEF("get_wet", 0, &audio_effect_chorus_class_get_wet),
	JS_CFUNC_DEF("set_dry", 1, &audio_effect_chorus_class_set_dry),
	JS_CFUNC_DEF("get_dry", 0, &audio_effect_chorus_class_get_dry),
};




static void define_audio_effect_chorus_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "voice_count"),
        JS_NewCFunction(ctx, audio_effect_chorus_class_get_voice_count, "get_voice_count", 0),
        JS_NewCFunction(ctx, audio_effect_chorus_class_set_voice_count, "set_voice_count", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "dry"),
        JS_NewCFunction(ctx, audio_effect_chorus_class_get_dry, "get_dry", 0),
        JS_NewCFunction(ctx, audio_effect_chorus_class_set_dry, "set_dry", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "wet"),
        JS_NewCFunction(ctx, audio_effect_chorus_class_get_wet, "get_wet", 0),
        JS_NewCFunction(ctx, audio_effect_chorus_class_set_wet, "set_wet", 1),
        JS_PROP_GETSET
    );
}

static void define_audio_effect_chorus_enum(JSContext *ctx, JSValue ctor) {
}

static int js_audio_effect_chorus_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["AudioEffectChorus"] = class_id;
	classes_by_id[class_id] = "AudioEffectChorus";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &audio_effect_chorus_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["AudioEffect"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_audio_effect_chorus_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, audio_effect_chorus_class_proto_funcs, _countof(audio_effect_chorus_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, audio_effect_chorus_class_constructor, "AudioEffectChorus", 0, JS_CFUNC_constructor, 0);
	define_audio_effect_chorus_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "AudioEffectChorus", ctor);

	return 0;
}

JSModuleDef *_js_init_audio_effect_chorus_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/audio_effect';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_audio_effect_chorus_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "AudioEffectChorus");
	return m;
}

JSModuleDef *js_init_audio_effect_chorus_module(JSContext *ctx) {
	return _js_init_audio_effect_chorus_module(ctx, "@godot/classes/audio_effect_chorus");
}

void __register_audio_effect_chorus() {
	js_init_audio_effect_chorus_module(js_context());
}

void register_audio_effect_chorus() {
	__register_audio_effect_chorus();
}