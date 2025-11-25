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
#include <godot_cpp/classes/audio_effect_capture.hpp>
using namespace godot;

static void audio_effect_capture_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["AudioEffectCapture"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef audio_effect_capture_class_def = {
    "AudioEffectCapture",
    audio_effect_capture_class_finalizer
};

static JSValue audio_effect_capture_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["AudioEffectCapture"];
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
        instance = memnew(AudioEffectCapture);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue audio_effect_capture_class_can_get_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectCapture::can_get_buffer, ctx, this_val, argc, argv);
};
static JSValue audio_effect_capture_class_get_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&AudioEffectCapture::get_buffer, ctx, this_val, argc, argv);
};
static JSValue audio_effect_capture_class_clear_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectCapture::clear_buffer, ctx, this_val, argc, argv);
};
static JSValue audio_effect_capture_class_set_buffer_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioEffectCapture::set_buffer_length, ctx, this_val, argc, argv);
};
static JSValue audio_effect_capture_class_get_buffer_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&AudioEffectCapture::get_buffer_length, ctx, this_val, argc, argv);
}
static JSValue audio_effect_capture_class_get_frames_available(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectCapture::get_frames_available, ctx, this_val, argc, argv);
};
static JSValue audio_effect_capture_class_get_discarded_frames(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectCapture::get_discarded_frames, ctx, this_val, argc, argv);
};
static JSValue audio_effect_capture_class_get_buffer_length_frames(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectCapture::get_buffer_length_frames, ctx, this_val, argc, argv);
};
static JSValue audio_effect_capture_class_get_pushed_frames(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioEffectCapture::get_pushed_frames, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry audio_effect_capture_class_proto_funcs[] = {
	JS_CFUNC_DEF("can_get_buffer", 1, &audio_effect_capture_class_can_get_buffer),
	JS_CFUNC_DEF("get_buffer", 1, &audio_effect_capture_class_get_buffer),
	JS_CFUNC_DEF("clear_buffer", 0, &audio_effect_capture_class_clear_buffer),
	JS_CFUNC_DEF("set_buffer_length", 1, &audio_effect_capture_class_set_buffer_length),
	JS_CFUNC_DEF("get_buffer_length", 0, &audio_effect_capture_class_get_buffer_length),
	JS_CFUNC_DEF("get_frames_available", 0, &audio_effect_capture_class_get_frames_available),
	JS_CFUNC_DEF("get_discarded_frames", 0, &audio_effect_capture_class_get_discarded_frames),
	JS_CFUNC_DEF("get_buffer_length_frames", 0, &audio_effect_capture_class_get_buffer_length_frames),
	JS_CFUNC_DEF("get_pushed_frames", 0, &audio_effect_capture_class_get_pushed_frames),
};




static void define_audio_effect_capture_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "buffer_length"),
        JS_NewCFunction(ctx, audio_effect_capture_class_get_buffer_length, "get_buffer_length", 0),
        JS_NewCFunction(ctx, audio_effect_capture_class_set_buffer_length, "set_buffer_length", 1),
        JS_PROP_GETSET
    );
}

static void define_audio_effect_capture_enum(JSContext *ctx, JSValue ctor) {
}

static int js_audio_effect_capture_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["AudioEffectCapture"] = class_id;
	classes_by_id[class_id] = "AudioEffectCapture";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &audio_effect_capture_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["AudioEffect"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_audio_effect_capture_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, audio_effect_capture_class_proto_funcs, _countof(audio_effect_capture_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, audio_effect_capture_class_constructor, "AudioEffectCapture", 0, JS_CFUNC_constructor, 0);
	define_audio_effect_capture_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "AudioEffectCapture", ctor);
	ctor_list["AudioEffectCapture"] = ctor;

	return 0;
}

JSModuleDef *_js_init_audio_effect_capture_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/audio_effect';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_audio_effect_capture_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "AudioEffectCapture");
	return m;
}

JSModuleDef *js_init_audio_effect_capture_module(JSContext *ctx) {
	return _js_init_audio_effect_capture_module(ctx, "@godot/classes/audio_effect_capture");
}

void __register_audio_effect_capture() {
	js_init_audio_effect_capture_module(js_context());
}

void register_audio_effect_capture() {
	__register_audio_effect_capture();
}