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
#include <godot_cpp/classes/audio_effect_reverb.hpp>
using namespace godot;

static void audio_effect_reverb_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["AudioEffectReverb"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef audio_effect_reverb_class_def = {
    "AudioEffectReverb",
    audio_effect_reverb_class_finalizer
};

static JSValue audio_effect_reverb_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["AudioEffectReverb"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    AudioEffectReverb *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<AudioEffectReverb *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(AudioEffectReverb);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue audio_effect_reverb_class_set_predelay_msec(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectReverb::set_predelay_msec, ctx, this_val, argc, argv);
};
static JSValue audio_effect_reverb_class_get_predelay_msec(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectReverb::get_predelay_msec, ctx, this_val, argc, argv);
}
static JSValue audio_effect_reverb_class_set_predelay_feedback(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectReverb::set_predelay_feedback, ctx, this_val, argc, argv);
};
static JSValue audio_effect_reverb_class_get_predelay_feedback(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectReverb::get_predelay_feedback, ctx, this_val, argc, argv);
}
static JSValue audio_effect_reverb_class_set_room_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectReverb::set_room_size, ctx, this_val, argc, argv);
};
static JSValue audio_effect_reverb_class_get_room_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectReverb::get_room_size, ctx, this_val, argc, argv);
}
static JSValue audio_effect_reverb_class_set_damping(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectReverb::set_damping, ctx, this_val, argc, argv);
};
static JSValue audio_effect_reverb_class_get_damping(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectReverb::get_damping, ctx, this_val, argc, argv);
}
static JSValue audio_effect_reverb_class_set_spread(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectReverb::set_spread, ctx, this_val, argc, argv);
};
static JSValue audio_effect_reverb_class_get_spread(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectReverb::get_spread, ctx, this_val, argc, argv);
}
static JSValue audio_effect_reverb_class_set_dry(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectReverb::set_dry, ctx, this_val, argc, argv);
};
static JSValue audio_effect_reverb_class_get_dry(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectReverb::get_dry, ctx, this_val, argc, argv);
}
static JSValue audio_effect_reverb_class_set_wet(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectReverb::set_wet, ctx, this_val, argc, argv);
};
static JSValue audio_effect_reverb_class_get_wet(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectReverb::get_wet, ctx, this_val, argc, argv);
}
static JSValue audio_effect_reverb_class_set_hpf(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectReverb::set_hpf, ctx, this_val, argc, argv);
};
static JSValue audio_effect_reverb_class_get_hpf(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectReverb::get_hpf, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry audio_effect_reverb_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_predelay_msec", 1, &audio_effect_reverb_class_set_predelay_msec),
	JS_CFUNC_DEF("get_predelay_msec", 0, &audio_effect_reverb_class_get_predelay_msec),
	JS_CFUNC_DEF("set_predelay_feedback", 1, &audio_effect_reverb_class_set_predelay_feedback),
	JS_CFUNC_DEF("get_predelay_feedback", 0, &audio_effect_reverb_class_get_predelay_feedback),
	JS_CFUNC_DEF("set_room_size", 1, &audio_effect_reverb_class_set_room_size),
	JS_CFUNC_DEF("get_room_size", 0, &audio_effect_reverb_class_get_room_size),
	JS_CFUNC_DEF("set_damping", 1, &audio_effect_reverb_class_set_damping),
	JS_CFUNC_DEF("get_damping", 0, &audio_effect_reverb_class_get_damping),
	JS_CFUNC_DEF("set_spread", 1, &audio_effect_reverb_class_set_spread),
	JS_CFUNC_DEF("get_spread", 0, &audio_effect_reverb_class_get_spread),
	JS_CFUNC_DEF("set_dry", 1, &audio_effect_reverb_class_set_dry),
	JS_CFUNC_DEF("get_dry", 0, &audio_effect_reverb_class_get_dry),
	JS_CFUNC_DEF("set_wet", 1, &audio_effect_reverb_class_set_wet),
	JS_CFUNC_DEF("get_wet", 0, &audio_effect_reverb_class_get_wet),
	JS_CFUNC_DEF("set_hpf", 1, &audio_effect_reverb_class_set_hpf),
	JS_CFUNC_DEF("get_hpf", 0, &audio_effect_reverb_class_get_hpf),
};




static void define_audio_effect_reverb_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "predelay_msec"),
        JS_NewCFunction(ctx, audio_effect_reverb_class_get_predelay_msec, "get_predelay_msec", 0),
        JS_NewCFunction(ctx, audio_effect_reverb_class_set_predelay_msec, "set_predelay_msec", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "predelay_feedback"),
        JS_NewCFunction(ctx, audio_effect_reverb_class_get_predelay_feedback, "get_predelay_feedback", 0),
        JS_NewCFunction(ctx, audio_effect_reverb_class_set_predelay_feedback, "set_predelay_feedback", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "room_size"),
        JS_NewCFunction(ctx, audio_effect_reverb_class_get_room_size, "get_room_size", 0),
        JS_NewCFunction(ctx, audio_effect_reverb_class_set_room_size, "set_room_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "damping"),
        JS_NewCFunction(ctx, audio_effect_reverb_class_get_damping, "get_damping", 0),
        JS_NewCFunction(ctx, audio_effect_reverb_class_set_damping, "set_damping", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "spread"),
        JS_NewCFunction(ctx, audio_effect_reverb_class_get_spread, "get_spread", 0),
        JS_NewCFunction(ctx, audio_effect_reverb_class_set_spread, "set_spread", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "hipass"),
        JS_NewCFunction(ctx, audio_effect_reverb_class_get_hpf, "get_hpf", 0),
        JS_NewCFunction(ctx, audio_effect_reverb_class_set_hpf, "set_hpf", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "dry"),
        JS_NewCFunction(ctx, audio_effect_reverb_class_get_dry, "get_dry", 0),
        JS_NewCFunction(ctx, audio_effect_reverb_class_set_dry, "set_dry", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "wet"),
        JS_NewCFunction(ctx, audio_effect_reverb_class_get_wet, "get_wet", 0),
        JS_NewCFunction(ctx, audio_effect_reverb_class_set_wet, "set_wet", 1),
        JS_PROP_GETSET
    );
}

static void define_audio_effect_reverb_enum(JSContext *ctx, JSValue proto) {
}

static int js_audio_effect_reverb_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["AudioEffectReverb"] = class_id;
	classes_by_id[class_id] = "AudioEffectReverb";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &audio_effect_reverb_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["AudioEffect"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_audio_effect_reverb_property(ctx, proto);
	define_audio_effect_reverb_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, audio_effect_reverb_class_proto_funcs, _countof(audio_effect_reverb_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, audio_effect_reverb_class_constructor, "AudioEffectReverb", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "AudioEffectReverb", ctor);

	return 0;
}

JSModuleDef *_js_init_audio_effect_reverb_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/audio_effect';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_audio_effect_reverb_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "AudioEffectReverb");
	return m;
}

JSModuleDef *js_init_audio_effect_reverb_module(JSContext *ctx) {
	return _js_init_audio_effect_reverb_module(ctx, "@godot/classes/audio_effect_reverb");
}

void __register_audio_effect_reverb() {
	js_init_audio_effect_reverb_module(js_context());
}

void register_audio_effect_reverb() {
	__register_audio_effect_reverb();
}