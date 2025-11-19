#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/audio_listener2d.hpp>
using namespace godot;

static void audio_listener2d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["AudioListener2D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef audio_listener2d_class_def = {
    "AudioListener2D",
    audio_listener2d_class_finalizer
};

static JSValue audio_listener2d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["AudioListener2D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    AudioListener2D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<AudioListener2D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(AudioListener2D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue audio_listener2d_class_make_current(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioListener2D::make_current, ctx, this_val, argc, argv);
};
static JSValue audio_listener2d_class_clear_current(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioListener2D::clear_current, ctx, this_val, argc, argv);
};
static JSValue audio_listener2d_class_is_current(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioListener2D::is_current, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry audio_listener2d_class_proto_funcs[] = {
	JS_CFUNC_DEF("make_current", 0, &audio_listener2d_class_make_current),
	JS_CFUNC_DEF("clear_current", 0, &audio_listener2d_class_clear_current),
	JS_CFUNC_DEF("is_current", 0, &audio_listener2d_class_is_current),
};




static void define_audio_listener2d_property(JSContext *ctx, JSValue proto) {
}

static void define_audio_listener2d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_audio_listener2d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["AudioListener2D"] = class_id;
	classes_by_id[class_id] = "AudioListener2D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &audio_listener2d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node2D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_audio_listener2d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, audio_listener2d_class_proto_funcs, _countof(audio_listener2d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, audio_listener2d_class_constructor, "AudioListener2D", 0, JS_CFUNC_constructor, 0);
	define_audio_listener2d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "AudioListener2D", ctor);

	return 0;
}

JSModuleDef *_js_init_audio_listener2d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node2d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_audio_listener2d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "AudioListener2D");
	return m;
}

JSModuleDef *js_init_audio_listener2d_module(JSContext *ctx) {
	return _js_init_audio_listener2d_module(ctx, "@godot/classes/audio_listener2d");
}

void __register_audio_listener2d() {
	js_init_audio_listener2d_module(js_context());
}

void register_audio_listener2d() {
	__register_audio_listener2d();
}