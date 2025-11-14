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
#include <godot_cpp/classes/audio_effect_distortion.hpp>
using namespace godot;

static void audio_effect_distortion_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["AudioEffectDistortion"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef audio_effect_distortion_class_def = {
    "AudioEffectDistortion",
    audio_effect_distortion_class_finalizer
};

static JSValue audio_effect_distortion_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["AudioEffectDistortion"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    AudioEffectDistortion *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<AudioEffectDistortion *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(AudioEffectDistortion);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue audio_effect_distortion_class_set_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectDistortion::set_mode, ctx, this_val, argc, argv);
};
static JSValue audio_effect_distortion_class_get_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectDistortion::get_mode, ctx, this_val, argc, argv);
}
static JSValue audio_effect_distortion_class_set_pre_gain(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectDistortion::set_pre_gain, ctx, this_val, argc, argv);
};
static JSValue audio_effect_distortion_class_get_pre_gain(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectDistortion::get_pre_gain, ctx, this_val, argc, argv);
}
static JSValue audio_effect_distortion_class_set_keep_hf_hz(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectDistortion::set_keep_hf_hz, ctx, this_val, argc, argv);
};
static JSValue audio_effect_distortion_class_get_keep_hf_hz(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectDistortion::get_keep_hf_hz, ctx, this_val, argc, argv);
}
static JSValue audio_effect_distortion_class_set_drive(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectDistortion::set_drive, ctx, this_val, argc, argv);
};
static JSValue audio_effect_distortion_class_get_drive(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectDistortion::get_drive, ctx, this_val, argc, argv);
}
static JSValue audio_effect_distortion_class_set_post_gain(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectDistortion::set_post_gain, ctx, this_val, argc, argv);
};
static JSValue audio_effect_distortion_class_get_post_gain(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectDistortion::get_post_gain, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry audio_effect_distortion_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_mode", 1, &audio_effect_distortion_class_set_mode),
	JS_CFUNC_DEF("get_mode", 0, &audio_effect_distortion_class_get_mode),
	JS_CFUNC_DEF("set_pre_gain", 1, &audio_effect_distortion_class_set_pre_gain),
	JS_CFUNC_DEF("get_pre_gain", 0, &audio_effect_distortion_class_get_pre_gain),
	JS_CFUNC_DEF("set_keep_hf_hz", 1, &audio_effect_distortion_class_set_keep_hf_hz),
	JS_CFUNC_DEF("get_keep_hf_hz", 0, &audio_effect_distortion_class_get_keep_hf_hz),
	JS_CFUNC_DEF("set_drive", 1, &audio_effect_distortion_class_set_drive),
	JS_CFUNC_DEF("get_drive", 0, &audio_effect_distortion_class_get_drive),
	JS_CFUNC_DEF("set_post_gain", 1, &audio_effect_distortion_class_set_post_gain),
	JS_CFUNC_DEF("get_post_gain", 0, &audio_effect_distortion_class_get_post_gain),
};




static void define_audio_effect_distortion_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "mode"),
        JS_NewCFunction(ctx, audio_effect_distortion_class_get_mode, "get_mode", 0),
        JS_NewCFunction(ctx, audio_effect_distortion_class_set_mode, "set_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "pre_gain"),
        JS_NewCFunction(ctx, audio_effect_distortion_class_get_pre_gain, "get_pre_gain", 0),
        JS_NewCFunction(ctx, audio_effect_distortion_class_set_pre_gain, "set_pre_gain", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "keep_hf_hz"),
        JS_NewCFunction(ctx, audio_effect_distortion_class_get_keep_hf_hz, "get_keep_hf_hz", 0),
        JS_NewCFunction(ctx, audio_effect_distortion_class_set_keep_hf_hz, "set_keep_hf_hz", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "drive"),
        JS_NewCFunction(ctx, audio_effect_distortion_class_get_drive, "get_drive", 0),
        JS_NewCFunction(ctx, audio_effect_distortion_class_set_drive, "set_drive", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "post_gain"),
        JS_NewCFunction(ctx, audio_effect_distortion_class_get_post_gain, "get_post_gain", 0),
        JS_NewCFunction(ctx, audio_effect_distortion_class_set_post_gain, "set_post_gain", 1),
        JS_PROP_GETSET
    );
}

static void define_audio_effect_distortion_enum(JSContext *ctx, JSValue proto) {
	JSValue Mode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, Mode_obj, "MODE_CLIP", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, Mode_obj, "MODE_ATAN", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, Mode_obj, "MODE_LOFI", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, Mode_obj, "MODE_OVERDRIVE", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, Mode_obj, "MODE_WAVESHAPE", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, proto, "Mode", Mode_obj);
}

static int js_audio_effect_distortion_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["AudioEffectDistortion"] = class_id;
	classes_by_id[class_id] = "AudioEffectDistortion";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &audio_effect_distortion_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["AudioEffect"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_audio_effect_distortion_property(ctx, proto);
	define_audio_effect_distortion_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, audio_effect_distortion_class_proto_funcs, _countof(audio_effect_distortion_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, audio_effect_distortion_class_constructor, "AudioEffectDistortion", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "AudioEffectDistortion", ctor);

	return 0;
}

JSModuleDef *_js_init_audio_effect_distortion_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/audio_effect';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_audio_effect_distortion_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "AudioEffectDistortion");
	return m;
}

JSModuleDef *js_init_audio_effect_distortion_module(JSContext *ctx) {
	return _js_init_audio_effect_distortion_module(ctx, "@godot/classes/audio_effect_distortion");
}

void __register_audio_effect_distortion() {
	js_init_audio_effect_distortion_module(js_context());
}

void register_audio_effect_distortion() {
	__register_audio_effect_distortion();
}