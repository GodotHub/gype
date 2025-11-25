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
#include <godot_cpp/classes/audio_effect_delay.hpp>
using namespace godot;

static void audio_effect_delay_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["AudioEffectDelay"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef audio_effect_delay_class_def = {
    "AudioEffectDelay",
    audio_effect_delay_class_finalizer
};

static JSValue audio_effect_delay_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["AudioEffectDelay"];
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
        instance = memnew(AudioEffectDelay);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue audio_effect_delay_class_set_dry(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectDelay::set_dry, ctx, this_val, argc, argv);
};
static JSValue audio_effect_delay_class_get_dry(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&AudioEffectDelay::get_dry, ctx, this_val, argc, argv);
}
static JSValue audio_effect_delay_class_set_tap1_active(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectDelay::set_tap1_active, ctx, this_val, argc, argv);
};
static JSValue audio_effect_delay_class_is_tap1_active(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectDelay::is_tap1_active, ctx, this_val, argc, argv);
}
static JSValue audio_effect_delay_class_set_tap1_delay_ms(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectDelay::set_tap1_delay_ms, ctx, this_val, argc, argv);
};
static JSValue audio_effect_delay_class_get_tap1_delay_ms(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectDelay::get_tap1_delay_ms, ctx, this_val, argc, argv);
}
static JSValue audio_effect_delay_class_set_tap1_level_db(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectDelay::set_tap1_level_db, ctx, this_val, argc, argv);
};
static JSValue audio_effect_delay_class_get_tap1_level_db(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectDelay::get_tap1_level_db, ctx, this_val, argc, argv);
}
static JSValue audio_effect_delay_class_set_tap1_pan(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectDelay::set_tap1_pan, ctx, this_val, argc, argv);
};
static JSValue audio_effect_delay_class_get_tap1_pan(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectDelay::get_tap1_pan, ctx, this_val, argc, argv);
}
static JSValue audio_effect_delay_class_set_tap2_active(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectDelay::set_tap2_active, ctx, this_val, argc, argv);
};
static JSValue audio_effect_delay_class_is_tap2_active(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectDelay::is_tap2_active, ctx, this_val, argc, argv);
}
static JSValue audio_effect_delay_class_set_tap2_delay_ms(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectDelay::set_tap2_delay_ms, ctx, this_val, argc, argv);
};
static JSValue audio_effect_delay_class_get_tap2_delay_ms(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectDelay::get_tap2_delay_ms, ctx, this_val, argc, argv);
}
static JSValue audio_effect_delay_class_set_tap2_level_db(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectDelay::set_tap2_level_db, ctx, this_val, argc, argv);
};
static JSValue audio_effect_delay_class_get_tap2_level_db(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectDelay::get_tap2_level_db, ctx, this_val, argc, argv);
}
static JSValue audio_effect_delay_class_set_tap2_pan(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectDelay::set_tap2_pan, ctx, this_val, argc, argv);
};
static JSValue audio_effect_delay_class_get_tap2_pan(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectDelay::get_tap2_pan, ctx, this_val, argc, argv);
}
static JSValue audio_effect_delay_class_set_feedback_active(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectDelay::set_feedback_active, ctx, this_val, argc, argv);
};
static JSValue audio_effect_delay_class_is_feedback_active(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectDelay::is_feedback_active, ctx, this_val, argc, argv);
}
static JSValue audio_effect_delay_class_set_feedback_delay_ms(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectDelay::set_feedback_delay_ms, ctx, this_val, argc, argv);
};
static JSValue audio_effect_delay_class_get_feedback_delay_ms(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectDelay::get_feedback_delay_ms, ctx, this_val, argc, argv);
}
static JSValue audio_effect_delay_class_set_feedback_level_db(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectDelay::set_feedback_level_db, ctx, this_val, argc, argv);
};
static JSValue audio_effect_delay_class_get_feedback_level_db(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectDelay::get_feedback_level_db, ctx, this_val, argc, argv);
}
static JSValue audio_effect_delay_class_set_feedback_lowpass(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectDelay::set_feedback_lowpass, ctx, this_val, argc, argv);
};
static JSValue audio_effect_delay_class_get_feedback_lowpass(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectDelay::get_feedback_lowpass, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry audio_effect_delay_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_dry", 1, &audio_effect_delay_class_set_dry),
	JS_CFUNC_DEF("get_dry", 0, &audio_effect_delay_class_get_dry),
	JS_CFUNC_DEF("set_tap1_active", 1, &audio_effect_delay_class_set_tap1_active),
	JS_CFUNC_DEF("is_tap1_active", 0, &audio_effect_delay_class_is_tap1_active),
	JS_CFUNC_DEF("set_tap1_delay_ms", 1, &audio_effect_delay_class_set_tap1_delay_ms),
	JS_CFUNC_DEF("get_tap1_delay_ms", 0, &audio_effect_delay_class_get_tap1_delay_ms),
	JS_CFUNC_DEF("set_tap1_level_db", 1, &audio_effect_delay_class_set_tap1_level_db),
	JS_CFUNC_DEF("get_tap1_level_db", 0, &audio_effect_delay_class_get_tap1_level_db),
	JS_CFUNC_DEF("set_tap1_pan", 1, &audio_effect_delay_class_set_tap1_pan),
	JS_CFUNC_DEF("get_tap1_pan", 0, &audio_effect_delay_class_get_tap1_pan),
	JS_CFUNC_DEF("set_tap2_active", 1, &audio_effect_delay_class_set_tap2_active),
	JS_CFUNC_DEF("is_tap2_active", 0, &audio_effect_delay_class_is_tap2_active),
	JS_CFUNC_DEF("set_tap2_delay_ms", 1, &audio_effect_delay_class_set_tap2_delay_ms),
	JS_CFUNC_DEF("get_tap2_delay_ms", 0, &audio_effect_delay_class_get_tap2_delay_ms),
	JS_CFUNC_DEF("set_tap2_level_db", 1, &audio_effect_delay_class_set_tap2_level_db),
	JS_CFUNC_DEF("get_tap2_level_db", 0, &audio_effect_delay_class_get_tap2_level_db),
	JS_CFUNC_DEF("set_tap2_pan", 1, &audio_effect_delay_class_set_tap2_pan),
	JS_CFUNC_DEF("get_tap2_pan", 0, &audio_effect_delay_class_get_tap2_pan),
	JS_CFUNC_DEF("set_feedback_active", 1, &audio_effect_delay_class_set_feedback_active),
	JS_CFUNC_DEF("is_feedback_active", 0, &audio_effect_delay_class_is_feedback_active),
	JS_CFUNC_DEF("set_feedback_delay_ms", 1, &audio_effect_delay_class_set_feedback_delay_ms),
	JS_CFUNC_DEF("get_feedback_delay_ms", 0, &audio_effect_delay_class_get_feedback_delay_ms),
	JS_CFUNC_DEF("set_feedback_level_db", 1, &audio_effect_delay_class_set_feedback_level_db),
	JS_CFUNC_DEF("get_feedback_level_db", 0, &audio_effect_delay_class_get_feedback_level_db),
	JS_CFUNC_DEF("set_feedback_lowpass", 1, &audio_effect_delay_class_set_feedback_lowpass),
	JS_CFUNC_DEF("get_feedback_lowpass", 0, &audio_effect_delay_class_get_feedback_lowpass),
};




static void define_audio_effect_delay_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "dry"),
        JS_NewCFunction(ctx, audio_effect_delay_class_get_dry, "get_dry", 0),
        JS_NewCFunction(ctx, audio_effect_delay_class_set_dry, "set_dry", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "tap1_active"),
        JS_NewCFunction(ctx, audio_effect_delay_class_is_tap1_active, "is_tap1_active", 0),
        JS_NewCFunction(ctx, audio_effect_delay_class_set_tap1_active, "set_tap1_active", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "tap1_delay_ms"),
        JS_NewCFunction(ctx, audio_effect_delay_class_get_tap1_delay_ms, "get_tap1_delay_ms", 0),
        JS_NewCFunction(ctx, audio_effect_delay_class_set_tap1_delay_ms, "set_tap1_delay_ms", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "tap1_level_db"),
        JS_NewCFunction(ctx, audio_effect_delay_class_get_tap1_level_db, "get_tap1_level_db", 0),
        JS_NewCFunction(ctx, audio_effect_delay_class_set_tap1_level_db, "set_tap1_level_db", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "tap1_pan"),
        JS_NewCFunction(ctx, audio_effect_delay_class_get_tap1_pan, "get_tap1_pan", 0),
        JS_NewCFunction(ctx, audio_effect_delay_class_set_tap1_pan, "set_tap1_pan", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "tap2_active"),
        JS_NewCFunction(ctx, audio_effect_delay_class_is_tap2_active, "is_tap2_active", 0),
        JS_NewCFunction(ctx, audio_effect_delay_class_set_tap2_active, "set_tap2_active", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "tap2_delay_ms"),
        JS_NewCFunction(ctx, audio_effect_delay_class_get_tap2_delay_ms, "get_tap2_delay_ms", 0),
        JS_NewCFunction(ctx, audio_effect_delay_class_set_tap2_delay_ms, "set_tap2_delay_ms", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "tap2_level_db"),
        JS_NewCFunction(ctx, audio_effect_delay_class_get_tap2_level_db, "get_tap2_level_db", 0),
        JS_NewCFunction(ctx, audio_effect_delay_class_set_tap2_level_db, "set_tap2_level_db", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "tap2_pan"),
        JS_NewCFunction(ctx, audio_effect_delay_class_get_tap2_pan, "get_tap2_pan", 0),
        JS_NewCFunction(ctx, audio_effect_delay_class_set_tap2_pan, "set_tap2_pan", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "feedback_active"),
        JS_NewCFunction(ctx, audio_effect_delay_class_is_feedback_active, "is_feedback_active", 0),
        JS_NewCFunction(ctx, audio_effect_delay_class_set_feedback_active, "set_feedback_active", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "feedback_delay_ms"),
        JS_NewCFunction(ctx, audio_effect_delay_class_get_feedback_delay_ms, "get_feedback_delay_ms", 0),
        JS_NewCFunction(ctx, audio_effect_delay_class_set_feedback_delay_ms, "set_feedback_delay_ms", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "feedback_level_db"),
        JS_NewCFunction(ctx, audio_effect_delay_class_get_feedback_level_db, "get_feedback_level_db", 0),
        JS_NewCFunction(ctx, audio_effect_delay_class_set_feedback_level_db, "set_feedback_level_db", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "feedback_lowpass"),
        JS_NewCFunction(ctx, audio_effect_delay_class_get_feedback_lowpass, "get_feedback_lowpass", 0),
        JS_NewCFunction(ctx, audio_effect_delay_class_set_feedback_lowpass, "set_feedback_lowpass", 1),
        JS_PROP_GETSET
    );
}

static void define_audio_effect_delay_enum(JSContext *ctx, JSValue ctor) {
}

static int js_audio_effect_delay_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["AudioEffectDelay"] = class_id;
	classes_by_id[class_id] = "AudioEffectDelay";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &audio_effect_delay_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["AudioEffect"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_audio_effect_delay_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, audio_effect_delay_class_proto_funcs, _countof(audio_effect_delay_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, audio_effect_delay_class_constructor, "AudioEffectDelay", 0, JS_CFUNC_constructor, 0);
	define_audio_effect_delay_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "AudioEffectDelay", ctor);
	ctor_list["AudioEffectDelay"] = ctor;

	return 0;
}

JSModuleDef *_js_init_audio_effect_delay_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/audio_effect';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_audio_effect_delay_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "AudioEffectDelay");
	return m;
}

JSModuleDef *js_init_audio_effect_delay_module(JSContext *ctx) {
	return _js_init_audio_effect_delay_module(ctx, "@godot/classes/audio_effect_delay");
}

void __register_audio_effect_delay() {
	js_init_audio_effect_delay_module(js_context());
}

void register_audio_effect_delay() {
	__register_audio_effect_delay();
}