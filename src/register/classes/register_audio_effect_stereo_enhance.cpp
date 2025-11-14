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
#include <godot_cpp/classes/audio_effect_stereo_enhance.hpp>
using namespace godot;

static void audio_effect_stereo_enhance_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["AudioEffectStereoEnhance"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef audio_effect_stereo_enhance_class_def = {
    "AudioEffectStereoEnhance",
    audio_effect_stereo_enhance_class_finalizer
};

static JSValue audio_effect_stereo_enhance_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["AudioEffectStereoEnhance"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    AudioEffectStereoEnhance *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<AudioEffectStereoEnhance *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(AudioEffectStereoEnhance);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue audio_effect_stereo_enhance_class_set_pan_pullout(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectStereoEnhance::set_pan_pullout, ctx, this_val, argc, argv);
};
static JSValue audio_effect_stereo_enhance_class_get_pan_pullout(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectStereoEnhance::get_pan_pullout, ctx, this_val, argc, argv);
}
static JSValue audio_effect_stereo_enhance_class_set_time_pullout(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectStereoEnhance::set_time_pullout, ctx, this_val, argc, argv);
};
static JSValue audio_effect_stereo_enhance_class_get_time_pullout(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectStereoEnhance::get_time_pullout, ctx, this_val, argc, argv);
}
static JSValue audio_effect_stereo_enhance_class_set_surround(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectStereoEnhance::set_surround, ctx, this_val, argc, argv);
};
static JSValue audio_effect_stereo_enhance_class_get_surround(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectStereoEnhance::get_surround, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry audio_effect_stereo_enhance_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_pan_pullout", 1, &audio_effect_stereo_enhance_class_set_pan_pullout),
	JS_CFUNC_DEF("get_pan_pullout", 0, &audio_effect_stereo_enhance_class_get_pan_pullout),
	JS_CFUNC_DEF("set_time_pullout", 1, &audio_effect_stereo_enhance_class_set_time_pullout),
	JS_CFUNC_DEF("get_time_pullout", 0, &audio_effect_stereo_enhance_class_get_time_pullout),
	JS_CFUNC_DEF("set_surround", 1, &audio_effect_stereo_enhance_class_set_surround),
	JS_CFUNC_DEF("get_surround", 0, &audio_effect_stereo_enhance_class_get_surround),
};




static void define_audio_effect_stereo_enhance_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "pan_pullout"),
        JS_NewCFunction(ctx, audio_effect_stereo_enhance_class_get_pan_pullout, "get_pan_pullout", 0),
        JS_NewCFunction(ctx, audio_effect_stereo_enhance_class_set_pan_pullout, "set_pan_pullout", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "time_pullout_ms"),
        JS_NewCFunction(ctx, audio_effect_stereo_enhance_class_get_time_pullout, "get_time_pullout", 0),
        JS_NewCFunction(ctx, audio_effect_stereo_enhance_class_set_time_pullout, "set_time_pullout", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "surround"),
        JS_NewCFunction(ctx, audio_effect_stereo_enhance_class_get_surround, "get_surround", 0),
        JS_NewCFunction(ctx, audio_effect_stereo_enhance_class_set_surround, "set_surround", 1),
        JS_PROP_GETSET
    );
}

static void define_audio_effect_stereo_enhance_enum(JSContext *ctx, JSValue proto) {
}

static int js_audio_effect_stereo_enhance_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["AudioEffectStereoEnhance"] = class_id;
	classes_by_id[class_id] = "AudioEffectStereoEnhance";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &audio_effect_stereo_enhance_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["AudioEffect"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_audio_effect_stereo_enhance_property(ctx, proto);
	define_audio_effect_stereo_enhance_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, audio_effect_stereo_enhance_class_proto_funcs, _countof(audio_effect_stereo_enhance_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, audio_effect_stereo_enhance_class_constructor, "AudioEffectStereoEnhance", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "AudioEffectStereoEnhance", ctor);

	return 0;
}

JSModuleDef *_js_init_audio_effect_stereo_enhance_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/audio_effect';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_audio_effect_stereo_enhance_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "AudioEffectStereoEnhance");
	return m;
}

JSModuleDef *js_init_audio_effect_stereo_enhance_module(JSContext *ctx) {
	return _js_init_audio_effect_stereo_enhance_module(ctx, "@godot/classes/audio_effect_stereo_enhance");
}

void __register_audio_effect_stereo_enhance() {
	js_init_audio_effect_stereo_enhance_module(js_context());
}

void register_audio_effect_stereo_enhance() {
	__register_audio_effect_stereo_enhance();
}