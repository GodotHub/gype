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
#include <godot_cpp/classes/audio_effect_eq.hpp>
using namespace godot;

static void audio_effect_eq_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["AudioEffectEQ"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef audio_effect_eq_class_def = {
    "AudioEffectEQ",
    audio_effect_eq_class_finalizer
};

static JSValue audio_effect_eq_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["AudioEffectEQ"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    AudioEffectEQ *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<AudioEffectEQ *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(AudioEffectEQ);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue audio_effect_eq_class_set_band_gain_db(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectEQ::set_band_gain_db, ctx, this_val, argc, argv);
};
static JSValue audio_effect_eq_class_get_band_gain_db(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectEQ::get_band_gain_db, ctx, this_val, argc, argv);
};
static JSValue audio_effect_eq_class_get_band_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectEQ::get_band_count, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry audio_effect_eq_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_band_gain_db", 2, &audio_effect_eq_class_set_band_gain_db),
	JS_CFUNC_DEF("get_band_gain_db", 1, &audio_effect_eq_class_get_band_gain_db),
	JS_CFUNC_DEF("get_band_count", 0, &audio_effect_eq_class_get_band_count),
};




static void define_audio_effect_eq_property(JSContext *ctx, JSValue proto) {
}

static void define_audio_effect_eq_enum(JSContext *ctx, JSValue proto) {
}

static int js_audio_effect_eq_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["AudioEffectEQ"] = class_id;
	classes_by_id[class_id] = "AudioEffectEQ";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &audio_effect_eq_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["AudioEffect"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_audio_effect_eq_property(ctx, proto);
	define_audio_effect_eq_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, audio_effect_eq_class_proto_funcs, _countof(audio_effect_eq_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, audio_effect_eq_class_constructor, "AudioEffectEQ", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "AudioEffectEQ", ctor);

	return 0;
}

JSModuleDef *_js_init_audio_effect_eq_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/audio_effect';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_audio_effect_eq_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "AudioEffectEQ");
	return m;
}

JSModuleDef *js_init_audio_effect_eq_module(JSContext *ctx) {
	return _js_init_audio_effect_eq_module(ctx, "@godot/classes/audio_effect_eq");
}

void __register_audio_effect_eq() {
	js_init_audio_effect_eq_module(js_context());
}

void register_audio_effect_eq() {
	__register_audio_effect_eq();
}