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
#include <godot_cpp/classes/audio_effect_filter.hpp>
using namespace godot;

static void audio_effect_filter_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["AudioEffectFilter"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef audio_effect_filter_class_def = {
    "AudioEffectFilter",
    audio_effect_filter_class_finalizer
};

static JSValue audio_effect_filter_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["AudioEffectFilter"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    AudioEffectFilter *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<AudioEffectFilter *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(AudioEffectFilter);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue audio_effect_filter_class_set_cutoff(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectFilter::set_cutoff, ctx, this_val, argc, argv);
};
static JSValue audio_effect_filter_class_get_cutoff(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectFilter::get_cutoff, ctx, this_val, argc, argv);
}
static JSValue audio_effect_filter_class_set_resonance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectFilter::set_resonance, ctx, this_val, argc, argv);
};
static JSValue audio_effect_filter_class_get_resonance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectFilter::get_resonance, ctx, this_val, argc, argv);
}
static JSValue audio_effect_filter_class_set_gain(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectFilter::set_gain, ctx, this_val, argc, argv);
};
static JSValue audio_effect_filter_class_get_gain(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectFilter::get_gain, ctx, this_val, argc, argv);
}
static JSValue audio_effect_filter_class_set_db(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectFilter::set_db, ctx, this_val, argc, argv);
};
static JSValue audio_effect_filter_class_get_db(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectFilter::get_db, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry audio_effect_filter_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_cutoff", 1, &audio_effect_filter_class_set_cutoff),
	JS_CFUNC_DEF("get_cutoff", 0, &audio_effect_filter_class_get_cutoff),
	JS_CFUNC_DEF("set_resonance", 1, &audio_effect_filter_class_set_resonance),
	JS_CFUNC_DEF("get_resonance", 0, &audio_effect_filter_class_get_resonance),
	JS_CFUNC_DEF("set_gain", 1, &audio_effect_filter_class_set_gain),
	JS_CFUNC_DEF("get_gain", 0, &audio_effect_filter_class_get_gain),
	JS_CFUNC_DEF("set_db", 1, &audio_effect_filter_class_set_db),
	JS_CFUNC_DEF("get_db", 0, &audio_effect_filter_class_get_db),
};




static void define_audio_effect_filter_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "cutoff_hz"),
        JS_NewCFunction(ctx, audio_effect_filter_class_get_cutoff, "get_cutoff", 0),
        JS_NewCFunction(ctx, audio_effect_filter_class_set_cutoff, "set_cutoff", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "resonance"),
        JS_NewCFunction(ctx, audio_effect_filter_class_get_resonance, "get_resonance", 0),
        JS_NewCFunction(ctx, audio_effect_filter_class_set_resonance, "set_resonance", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "gain"),
        JS_NewCFunction(ctx, audio_effect_filter_class_get_gain, "get_gain", 0),
        JS_NewCFunction(ctx, audio_effect_filter_class_set_gain, "set_gain", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "db"),
        JS_NewCFunction(ctx, audio_effect_filter_class_get_db, "get_db", 0),
        JS_NewCFunction(ctx, audio_effect_filter_class_set_db, "set_db", 1),
        JS_PROP_GETSET
    );
}

static void define_audio_effect_filter_enum(JSContext *ctx, JSValue ctor) {
	JSValue FilterDB_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, FilterDB_obj, "FILTER_6DB", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, FilterDB_obj, "FILTER_12DB", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, FilterDB_obj, "FILTER_18DB", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, FilterDB_obj, "FILTER_24DB", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ctor, "FilterDB", FilterDB_obj);
}

static int js_audio_effect_filter_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["AudioEffectFilter"] = class_id;
	classes_by_id[class_id] = "AudioEffectFilter";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &audio_effect_filter_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["AudioEffect"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_audio_effect_filter_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, audio_effect_filter_class_proto_funcs, _countof(audio_effect_filter_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, audio_effect_filter_class_constructor, "AudioEffectFilter", 0, JS_CFUNC_constructor, 0);
	define_audio_effect_filter_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "AudioEffectFilter", ctor);

	return 0;
}

JSModuleDef *_js_init_audio_effect_filter_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/audio_effect';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_audio_effect_filter_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "AudioEffectFilter");
	return m;
}

JSModuleDef *js_init_audio_effect_filter_module(JSContext *ctx) {
	return _js_init_audio_effect_filter_module(ctx, "@godot/classes/audio_effect_filter");
}

void __register_audio_effect_filter() {
	js_init_audio_effect_filter_module(js_context());
}

void register_audio_effect_filter() {
	__register_audio_effect_filter();
}