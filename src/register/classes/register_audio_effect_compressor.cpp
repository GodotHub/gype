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
#include <godot_cpp/classes/audio_effect_compressor.hpp>
using namespace godot;

static void audio_effect_compressor_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["AudioEffectCompressor"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef audio_effect_compressor_class_def = {
    "AudioEffectCompressor",
    audio_effect_compressor_class_finalizer
};

static JSValue audio_effect_compressor_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["AudioEffectCompressor"];
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
        instance = memnew(AudioEffectCompressor);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue audio_effect_compressor_class_set_threshold(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectCompressor::set_threshold, ctx, this_val, argc, argv);
};
static JSValue audio_effect_compressor_class_get_threshold(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectCompressor::get_threshold, ctx, this_val, argc, argv);
}
static JSValue audio_effect_compressor_class_set_ratio(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectCompressor::set_ratio, ctx, this_val, argc, argv);
};
static JSValue audio_effect_compressor_class_get_ratio(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectCompressor::get_ratio, ctx, this_val, argc, argv);
}
static JSValue audio_effect_compressor_class_set_gain(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectCompressor::set_gain, ctx, this_val, argc, argv);
};
static JSValue audio_effect_compressor_class_get_gain(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectCompressor::get_gain, ctx, this_val, argc, argv);
}
static JSValue audio_effect_compressor_class_set_attack_us(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectCompressor::set_attack_us, ctx, this_val, argc, argv);
};
static JSValue audio_effect_compressor_class_get_attack_us(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectCompressor::get_attack_us, ctx, this_val, argc, argv);
}
static JSValue audio_effect_compressor_class_set_release_ms(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectCompressor::set_release_ms, ctx, this_val, argc, argv);
};
static JSValue audio_effect_compressor_class_get_release_ms(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectCompressor::get_release_ms, ctx, this_val, argc, argv);
}
static JSValue audio_effect_compressor_class_set_mix(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectCompressor::set_mix, ctx, this_val, argc, argv);
};
static JSValue audio_effect_compressor_class_get_mix(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectCompressor::get_mix, ctx, this_val, argc, argv);
}
static JSValue audio_effect_compressor_class_set_sidechain(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectCompressor::set_sidechain, ctx, this_val, argc, argv);
};
static JSValue audio_effect_compressor_class_get_sidechain(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectCompressor::get_sidechain, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry audio_effect_compressor_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_threshold", 1, &audio_effect_compressor_class_set_threshold),
	JS_CFUNC_DEF("get_threshold", 0, &audio_effect_compressor_class_get_threshold),
	JS_CFUNC_DEF("set_ratio", 1, &audio_effect_compressor_class_set_ratio),
	JS_CFUNC_DEF("get_ratio", 0, &audio_effect_compressor_class_get_ratio),
	JS_CFUNC_DEF("set_gain", 1, &audio_effect_compressor_class_set_gain),
	JS_CFUNC_DEF("get_gain", 0, &audio_effect_compressor_class_get_gain),
	JS_CFUNC_DEF("set_attack_us", 1, &audio_effect_compressor_class_set_attack_us),
	JS_CFUNC_DEF("get_attack_us", 0, &audio_effect_compressor_class_get_attack_us),
	JS_CFUNC_DEF("set_release_ms", 1, &audio_effect_compressor_class_set_release_ms),
	JS_CFUNC_DEF("get_release_ms", 0, &audio_effect_compressor_class_get_release_ms),
	JS_CFUNC_DEF("set_mix", 1, &audio_effect_compressor_class_set_mix),
	JS_CFUNC_DEF("get_mix", 0, &audio_effect_compressor_class_get_mix),
	JS_CFUNC_DEF("set_sidechain", 1, &audio_effect_compressor_class_set_sidechain),
	JS_CFUNC_DEF("get_sidechain", 0, &audio_effect_compressor_class_get_sidechain),
};




static void define_audio_effect_compressor_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "threshold"),
        JS_NewCFunction(ctx, audio_effect_compressor_class_get_threshold, "get_threshold", 0),
        JS_NewCFunction(ctx, audio_effect_compressor_class_set_threshold, "set_threshold", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "ratio"),
        JS_NewCFunction(ctx, audio_effect_compressor_class_get_ratio, "get_ratio", 0),
        JS_NewCFunction(ctx, audio_effect_compressor_class_set_ratio, "set_ratio", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "gain"),
        JS_NewCFunction(ctx, audio_effect_compressor_class_get_gain, "get_gain", 0),
        JS_NewCFunction(ctx, audio_effect_compressor_class_set_gain, "set_gain", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "attack_us"),
        JS_NewCFunction(ctx, audio_effect_compressor_class_get_attack_us, "get_attack_us", 0),
        JS_NewCFunction(ctx, audio_effect_compressor_class_set_attack_us, "set_attack_us", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "release_ms"),
        JS_NewCFunction(ctx, audio_effect_compressor_class_get_release_ms, "get_release_ms", 0),
        JS_NewCFunction(ctx, audio_effect_compressor_class_set_release_ms, "set_release_ms", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "mix"),
        JS_NewCFunction(ctx, audio_effect_compressor_class_get_mix, "get_mix", 0),
        JS_NewCFunction(ctx, audio_effect_compressor_class_set_mix, "set_mix", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "sidechain"),
        JS_NewCFunction(ctx, audio_effect_compressor_class_get_sidechain, "get_sidechain", 0),
        JS_NewCFunction(ctx, audio_effect_compressor_class_set_sidechain, "set_sidechain", 1),
        JS_PROP_GETSET
    );
}

static void define_audio_effect_compressor_enum(JSContext *ctx, JSValue ctor) {
}

static int js_audio_effect_compressor_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["AudioEffectCompressor"] = class_id;
	classes_by_id[class_id] = "AudioEffectCompressor";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &audio_effect_compressor_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["AudioEffect"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_audio_effect_compressor_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, audio_effect_compressor_class_proto_funcs, _countof(audio_effect_compressor_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, audio_effect_compressor_class_constructor, "AudioEffectCompressor", 0, JS_CFUNC_constructor, 0);
	define_audio_effect_compressor_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "AudioEffectCompressor", ctor);
	ctor_list["AudioEffectCompressor"] = ctor;

	return 0;
}

JSModuleDef *_js_init_audio_effect_compressor_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/audio_effect';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_audio_effect_compressor_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "AudioEffectCompressor");
	return m;
}

JSModuleDef *js_init_audio_effect_compressor_module(JSContext *ctx) {
	return _js_init_audio_effect_compressor_module(ctx, "@godot/classes/audio_effect_compressor");
}

void __register_audio_effect_compressor() {
	js_init_audio_effect_compressor_module(js_context());
}

void register_audio_effect_compressor() {
	__register_audio_effect_compressor();
}