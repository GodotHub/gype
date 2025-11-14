#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/audio_stream.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/audio_stream_mp3.hpp>
using namespace godot;

static void audio_stream_mp3_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["AudioStreamMP3"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef audio_stream_mp3_class_def = {
    "AudioStreamMP3",
    audio_stream_mp3_class_finalizer
};

static JSValue audio_stream_mp3_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["AudioStreamMP3"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    AudioStreamMP3 *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<AudioStreamMP3 *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(AudioStreamMP3);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue audio_stream_mp3_class_set_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamMP3::set_data, ctx, this_val, argc, argv);
};
static JSValue audio_stream_mp3_class_get_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedByteArray> *proxy = memnew(ObjectProxy<PackedByteArray>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedByteArray {
		AudioStreamMP3 *obj = static_cast<AudioStreamMP3 *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_data();
	};
	proxy->setter = [this_val](const PackedByteArray &value) -> void {
		AudioStreamMP3 *js_proxy = static_cast<AudioStreamMP3 *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_data(PackedByteArray
(Array(value)));
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["PackedByteArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "PackedByteArrayProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue audio_stream_mp3_class_set_loop(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamMP3::set_loop, ctx, this_val, argc, argv);
};
static JSValue audio_stream_mp3_class_has_loop(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamMP3::has_loop, ctx, this_val, argc, argv);
}
static JSValue audio_stream_mp3_class_set_loop_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamMP3::set_loop_offset, ctx, this_val, argc, argv);
};
static JSValue audio_stream_mp3_class_get_loop_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamMP3::get_loop_offset, ctx, this_val, argc, argv);
}
static JSValue audio_stream_mp3_class_set_bpm(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamMP3::set_bpm, ctx, this_val, argc, argv);
};
static JSValue audio_stream_mp3_class_get_bpm(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamMP3::get_bpm, ctx, this_val, argc, argv);
}
static JSValue audio_stream_mp3_class_set_beat_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamMP3::set_beat_count, ctx, this_val, argc, argv);
};
static JSValue audio_stream_mp3_class_get_beat_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamMP3::get_beat_count, ctx, this_val, argc, argv);
}
static JSValue audio_stream_mp3_class_set_bar_beats(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamMP3::set_bar_beats, ctx, this_val, argc, argv);
};
static JSValue audio_stream_mp3_class_get_bar_beats(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamMP3::get_bar_beats, ctx, this_val, argc, argv);
}
static JSValue audio_stream_mp3_class_load_from_buffer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&AudioStreamMP3::load_from_buffer, ctx, this_val, argc, argv);
};
static JSValue audio_stream_mp3_class_load_from_file(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&AudioStreamMP3::load_from_file, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry audio_stream_mp3_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_data", 1, &audio_stream_mp3_class_set_data),
	JS_CFUNC_DEF("get_data", 0, &audio_stream_mp3_class_get_data),
	JS_CFUNC_DEF("set_loop", 1, &audio_stream_mp3_class_set_loop),
	JS_CFUNC_DEF("has_loop", 0, &audio_stream_mp3_class_has_loop),
	JS_CFUNC_DEF("set_loop_offset", 1, &audio_stream_mp3_class_set_loop_offset),
	JS_CFUNC_DEF("get_loop_offset", 0, &audio_stream_mp3_class_get_loop_offset),
	JS_CFUNC_DEF("set_bpm", 1, &audio_stream_mp3_class_set_bpm),
	JS_CFUNC_DEF("get_bpm", 0, &audio_stream_mp3_class_get_bpm),
	JS_CFUNC_DEF("set_beat_count", 1, &audio_stream_mp3_class_set_beat_count),
	JS_CFUNC_DEF("get_beat_count", 0, &audio_stream_mp3_class_get_beat_count),
	JS_CFUNC_DEF("set_bar_beats", 1, &audio_stream_mp3_class_set_bar_beats),
	JS_CFUNC_DEF("get_bar_beats", 0, &audio_stream_mp3_class_get_bar_beats),
};

static const JSCFunctionListEntry audio_stream_mp3_class_static_funcs[] = {
	JS_CFUNC_DEF("load_from_buffer", 1, &audio_stream_mp3_class_load_from_buffer),
	JS_CFUNC_DEF("load_from_file", 1, &audio_stream_mp3_class_load_from_file),
};



static void define_audio_stream_mp3_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "data"),
        JS_NewCFunction(ctx, audio_stream_mp3_class_get_data, "get_data", 0),
        JS_NewCFunction(ctx, audio_stream_mp3_class_set_data, "set_data", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "bpm"),
        JS_NewCFunction(ctx, audio_stream_mp3_class_get_bpm, "get_bpm", 0),
        JS_NewCFunction(ctx, audio_stream_mp3_class_set_bpm, "set_bpm", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "beat_count"),
        JS_NewCFunction(ctx, audio_stream_mp3_class_get_beat_count, "get_beat_count", 0),
        JS_NewCFunction(ctx, audio_stream_mp3_class_set_beat_count, "set_beat_count", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "bar_beats"),
        JS_NewCFunction(ctx, audio_stream_mp3_class_get_bar_beats, "get_bar_beats", 0),
        JS_NewCFunction(ctx, audio_stream_mp3_class_set_bar_beats, "set_bar_beats", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "loop"),
        JS_NewCFunction(ctx, audio_stream_mp3_class_has_loop, "has_loop", 0),
        JS_NewCFunction(ctx, audio_stream_mp3_class_set_loop, "set_loop", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "loop_offset"),
        JS_NewCFunction(ctx, audio_stream_mp3_class_get_loop_offset, "get_loop_offset", 0),
        JS_NewCFunction(ctx, audio_stream_mp3_class_set_loop_offset, "set_loop_offset", 1),
        JS_PROP_GETSET
    );
}

static void define_audio_stream_mp3_enum(JSContext *ctx, JSValue proto) {
}

static int js_audio_stream_mp3_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["AudioStreamMP3"] = class_id;
	classes_by_id[class_id] = "AudioStreamMP3";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &audio_stream_mp3_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["AudioStream"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_audio_stream_mp3_property(ctx, proto);
	define_audio_stream_mp3_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, audio_stream_mp3_class_proto_funcs, _countof(audio_stream_mp3_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, audio_stream_mp3_class_constructor, "AudioStreamMP3", 0, JS_CFUNC_constructor, 0);
	JS_SetPropertyFunctionList(ctx, ctor, audio_stream_mp3_class_static_funcs, _countof(audio_stream_mp3_class_static_funcs));
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "AudioStreamMP3", ctor);

	return 0;
}

JSModuleDef *_js_init_audio_stream_mp3_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/audio_stream';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_audio_stream_mp3_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "AudioStreamMP3");
	return m;
}

JSModuleDef *js_init_audio_stream_mp3_module(JSContext *ctx) {
	return _js_init_audio_stream_mp3_module(ctx, "@godot/classes/audio_stream_mp3");
}

void __register_audio_stream_mp3() {
	js_init_audio_stream_mp3_module(js_context());
}

void register_audio_stream_mp3() {
	__register_audio_stream_mp3();
}