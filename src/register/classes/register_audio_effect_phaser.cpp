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
#include <godot_cpp/classes/audio_effect_phaser.hpp>
using namespace godot;

static void audio_effect_phaser_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["AudioEffectPhaser"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef audio_effect_phaser_class_def = {
    "AudioEffectPhaser",
    audio_effect_phaser_class_finalizer
};

static JSValue audio_effect_phaser_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["AudioEffectPhaser"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    AudioEffectPhaser *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<AudioEffectPhaser *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(AudioEffectPhaser);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue audio_effect_phaser_class_set_range_min_hz(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectPhaser::set_range_min_hz, ctx, this_val, argc, argv);
};
static JSValue audio_effect_phaser_class_get_range_min_hz(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectPhaser::get_range_min_hz, ctx, this_val, argc, argv);
}
static JSValue audio_effect_phaser_class_set_range_max_hz(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectPhaser::set_range_max_hz, ctx, this_val, argc, argv);
};
static JSValue audio_effect_phaser_class_get_range_max_hz(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectPhaser::get_range_max_hz, ctx, this_val, argc, argv);
}
static JSValue audio_effect_phaser_class_set_rate_hz(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectPhaser::set_rate_hz, ctx, this_val, argc, argv);
};
static JSValue audio_effect_phaser_class_get_rate_hz(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectPhaser::get_rate_hz, ctx, this_val, argc, argv);
}
static JSValue audio_effect_phaser_class_set_feedback(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectPhaser::set_feedback, ctx, this_val, argc, argv);
};
static JSValue audio_effect_phaser_class_get_feedback(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectPhaser::get_feedback, ctx, this_val, argc, argv);
}
static JSValue audio_effect_phaser_class_set_depth(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectPhaser::set_depth, ctx, this_val, argc, argv);
};
static JSValue audio_effect_phaser_class_get_depth(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectPhaser::get_depth, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry audio_effect_phaser_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_range_min_hz", 1, &audio_effect_phaser_class_set_range_min_hz),
	JS_CFUNC_DEF("get_range_min_hz", 0, &audio_effect_phaser_class_get_range_min_hz),
	JS_CFUNC_DEF("set_range_max_hz", 1, &audio_effect_phaser_class_set_range_max_hz),
	JS_CFUNC_DEF("get_range_max_hz", 0, &audio_effect_phaser_class_get_range_max_hz),
	JS_CFUNC_DEF("set_rate_hz", 1, &audio_effect_phaser_class_set_rate_hz),
	JS_CFUNC_DEF("get_rate_hz", 0, &audio_effect_phaser_class_get_rate_hz),
	JS_CFUNC_DEF("set_feedback", 1, &audio_effect_phaser_class_set_feedback),
	JS_CFUNC_DEF("get_feedback", 0, &audio_effect_phaser_class_get_feedback),
	JS_CFUNC_DEF("set_depth", 1, &audio_effect_phaser_class_set_depth),
	JS_CFUNC_DEF("get_depth", 0, &audio_effect_phaser_class_get_depth),
};




static void define_audio_effect_phaser_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "range_min_hz"),
        JS_NewCFunction(ctx, audio_effect_phaser_class_get_range_min_hz, "get_range_min_hz", 0),
        JS_NewCFunction(ctx, audio_effect_phaser_class_set_range_min_hz, "set_range_min_hz", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "range_max_hz"),
        JS_NewCFunction(ctx, audio_effect_phaser_class_get_range_max_hz, "get_range_max_hz", 0),
        JS_NewCFunction(ctx, audio_effect_phaser_class_set_range_max_hz, "set_range_max_hz", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "rate_hz"),
        JS_NewCFunction(ctx, audio_effect_phaser_class_get_rate_hz, "get_rate_hz", 0),
        JS_NewCFunction(ctx, audio_effect_phaser_class_set_rate_hz, "set_rate_hz", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "feedback"),
        JS_NewCFunction(ctx, audio_effect_phaser_class_get_feedback, "get_feedback", 0),
        JS_NewCFunction(ctx, audio_effect_phaser_class_set_feedback, "set_feedback", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "depth"),
        JS_NewCFunction(ctx, audio_effect_phaser_class_get_depth, "get_depth", 0),
        JS_NewCFunction(ctx, audio_effect_phaser_class_set_depth, "set_depth", 1),
        JS_PROP_GETSET
    );
}

static void define_audio_effect_phaser_enum(JSContext *ctx, JSValue ctor) {
}

static int js_audio_effect_phaser_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["AudioEffectPhaser"] = class_id;
	classes_by_id[class_id] = "AudioEffectPhaser";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &audio_effect_phaser_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["AudioEffect"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_audio_effect_phaser_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, audio_effect_phaser_class_proto_funcs, _countof(audio_effect_phaser_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, audio_effect_phaser_class_constructor, "AudioEffectPhaser", 0, JS_CFUNC_constructor, 0);
	define_audio_effect_phaser_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "AudioEffectPhaser", ctor);

	return 0;
}

JSModuleDef *_js_init_audio_effect_phaser_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/audio_effect';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_audio_effect_phaser_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "AudioEffectPhaser");
	return m;
}

JSModuleDef *js_init_audio_effect_phaser_module(JSContext *ctx) {
	return _js_init_audio_effect_phaser_module(ctx, "@godot/classes/audio_effect_phaser");
}

void __register_audio_effect_phaser() {
	js_init_audio_effect_phaser_module(js_context());
}

void register_audio_effect_phaser() {
	__register_audio_effect_phaser();
}