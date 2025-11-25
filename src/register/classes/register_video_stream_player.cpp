#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/classes/video_stream.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/video_stream_player.hpp>
using namespace godot;

static void video_stream_player_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["VideoStreamPlayer"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef video_stream_player_class_def = {
    "VideoStreamPlayer",
    video_stream_player_class_finalizer
};

static JSValue video_stream_player_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["VideoStreamPlayer"];
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
        instance = memnew(VideoStreamPlayer);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue video_stream_player_class_set_stream(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VideoStreamPlayer::set_stream, ctx, this_val, argc, argv);
};
static JSValue video_stream_player_class_get_stream(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VideoStreamPlayer::get_stream, ctx, this_val, argc, argv);
}
static JSValue video_stream_player_class_play(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VideoStreamPlayer::play, ctx, this_val, argc, argv);
};
static JSValue video_stream_player_class_stop(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VideoStreamPlayer::stop, ctx, this_val, argc, argv);
};
static JSValue video_stream_player_class_is_playing(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VideoStreamPlayer::is_playing, ctx, this_val, argc, argv);
};
static JSValue video_stream_player_class_set_paused(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VideoStreamPlayer::set_paused, ctx, this_val, argc, argv);
};
static JSValue video_stream_player_class_is_paused(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VideoStreamPlayer::is_paused, ctx, this_val, argc, argv);
}
static JSValue video_stream_player_class_set_loop(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VideoStreamPlayer::set_loop, ctx, this_val, argc, argv);
};
static JSValue video_stream_player_class_has_loop(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VideoStreamPlayer::has_loop, ctx, this_val, argc, argv);
}
static JSValue video_stream_player_class_set_volume(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VideoStreamPlayer::set_volume, ctx, this_val, argc, argv);
};
static JSValue video_stream_player_class_get_volume(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VideoStreamPlayer::get_volume, ctx, this_val, argc, argv);
}
static JSValue video_stream_player_class_set_volume_db(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VideoStreamPlayer::set_volume_db, ctx, this_val, argc, argv);
};
static JSValue video_stream_player_class_get_volume_db(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VideoStreamPlayer::get_volume_db, ctx, this_val, argc, argv);
}
static JSValue video_stream_player_class_set_speed_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VideoStreamPlayer::set_speed_scale, ctx, this_val, argc, argv);
};
static JSValue video_stream_player_class_get_speed_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VideoStreamPlayer::get_speed_scale, ctx, this_val, argc, argv);
}
static JSValue video_stream_player_class_set_audio_track(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VideoStreamPlayer::set_audio_track, ctx, this_val, argc, argv);
};
static JSValue video_stream_player_class_get_audio_track(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VideoStreamPlayer::get_audio_track, ctx, this_val, argc, argv);
}
static JSValue video_stream_player_class_get_stream_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VideoStreamPlayer::get_stream_name, ctx, this_val, argc, argv);
};
static JSValue video_stream_player_class_get_stream_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VideoStreamPlayer::get_stream_length, ctx, this_val, argc, argv);
};
static JSValue video_stream_player_class_set_stream_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VideoStreamPlayer::set_stream_position, ctx, this_val, argc, argv);
};
static JSValue video_stream_player_class_get_stream_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VideoStreamPlayer::get_stream_position, ctx, this_val, argc, argv);
}
static JSValue video_stream_player_class_set_autoplay(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VideoStreamPlayer::set_autoplay, ctx, this_val, argc, argv);
};
static JSValue video_stream_player_class_has_autoplay(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VideoStreamPlayer::has_autoplay, ctx, this_val, argc, argv);
}
static JSValue video_stream_player_class_set_expand(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VideoStreamPlayer::set_expand, ctx, this_val, argc, argv);
};
static JSValue video_stream_player_class_has_expand(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VideoStreamPlayer::has_expand, ctx, this_val, argc, argv);
}
static JSValue video_stream_player_class_set_buffering_msec(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VideoStreamPlayer::set_buffering_msec, ctx, this_val, argc, argv);
};
static JSValue video_stream_player_class_get_buffering_msec(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VideoStreamPlayer::get_buffering_msec, ctx, this_val, argc, argv);
}
static JSValue video_stream_player_class_set_bus(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&VideoStreamPlayer::set_bus, ctx, this_val, argc, argv);
};
static JSValue video_stream_player_class_get_bus(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VideoStreamPlayer::get_bus, ctx, this_val, argc, argv);
}
static JSValue video_stream_player_class_get_video_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&VideoStreamPlayer::get_video_texture, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry video_stream_player_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_stream", 1, &video_stream_player_class_set_stream),
	JS_CFUNC_DEF("get_stream", 0, &video_stream_player_class_get_stream),
	JS_CFUNC_DEF("play", 0, &video_stream_player_class_play),
	JS_CFUNC_DEF("stop", 0, &video_stream_player_class_stop),
	JS_CFUNC_DEF("is_playing", 0, &video_stream_player_class_is_playing),
	JS_CFUNC_DEF("set_paused", 1, &video_stream_player_class_set_paused),
	JS_CFUNC_DEF("is_paused", 0, &video_stream_player_class_is_paused),
	JS_CFUNC_DEF("set_loop", 1, &video_stream_player_class_set_loop),
	JS_CFUNC_DEF("has_loop", 0, &video_stream_player_class_has_loop),
	JS_CFUNC_DEF("set_volume", 1, &video_stream_player_class_set_volume),
	JS_CFUNC_DEF("get_volume", 0, &video_stream_player_class_get_volume),
	JS_CFUNC_DEF("set_volume_db", 1, &video_stream_player_class_set_volume_db),
	JS_CFUNC_DEF("get_volume_db", 0, &video_stream_player_class_get_volume_db),
	JS_CFUNC_DEF("set_speed_scale", 1, &video_stream_player_class_set_speed_scale),
	JS_CFUNC_DEF("get_speed_scale", 0, &video_stream_player_class_get_speed_scale),
	JS_CFUNC_DEF("set_audio_track", 1, &video_stream_player_class_set_audio_track),
	JS_CFUNC_DEF("get_audio_track", 0, &video_stream_player_class_get_audio_track),
	JS_CFUNC_DEF("get_stream_name", 0, &video_stream_player_class_get_stream_name),
	JS_CFUNC_DEF("get_stream_length", 0, &video_stream_player_class_get_stream_length),
	JS_CFUNC_DEF("set_stream_position", 1, &video_stream_player_class_set_stream_position),
	JS_CFUNC_DEF("get_stream_position", 0, &video_stream_player_class_get_stream_position),
	JS_CFUNC_DEF("set_autoplay", 1, &video_stream_player_class_set_autoplay),
	JS_CFUNC_DEF("has_autoplay", 0, &video_stream_player_class_has_autoplay),
	JS_CFUNC_DEF("set_expand", 1, &video_stream_player_class_set_expand),
	JS_CFUNC_DEF("has_expand", 0, &video_stream_player_class_has_expand),
	JS_CFUNC_DEF("set_buffering_msec", 1, &video_stream_player_class_set_buffering_msec),
	JS_CFUNC_DEF("get_buffering_msec", 0, &video_stream_player_class_get_buffering_msec),
	JS_CFUNC_DEF("set_bus", 1, &video_stream_player_class_set_bus),
	JS_CFUNC_DEF("get_bus", 0, &video_stream_player_class_get_bus),
	JS_CFUNC_DEF("get_video_texture", 0, &video_stream_player_class_get_video_texture),
};


static JSValue video_stream_player_class_get_finished_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	VideoStreamPlayer *opaque = static_cast<VideoStreamPlayer *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "finished_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "finished"));
		JS_DefinePropertyValueStr(ctx, this_val, "finished_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_video_stream_player_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "audio_track"),
        JS_NewCFunction(ctx, video_stream_player_class_get_audio_track, "get_audio_track", 0),
        JS_NewCFunction(ctx, video_stream_player_class_set_audio_track, "set_audio_track", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "stream"),
        JS_NewCFunction(ctx, video_stream_player_class_get_stream, "get_stream", 0),
        JS_NewCFunction(ctx, video_stream_player_class_set_stream, "set_stream", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "volume_db"),
        JS_NewCFunction(ctx, video_stream_player_class_get_volume_db, "get_volume_db", 0),
        JS_NewCFunction(ctx, video_stream_player_class_set_volume_db, "set_volume_db", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "volume"),
        JS_NewCFunction(ctx, video_stream_player_class_get_volume, "get_volume", 0),
        JS_NewCFunction(ctx, video_stream_player_class_set_volume, "set_volume", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "speed_scale"),
        JS_NewCFunction(ctx, video_stream_player_class_get_speed_scale, "get_speed_scale", 0),
        JS_NewCFunction(ctx, video_stream_player_class_set_speed_scale, "set_speed_scale", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "autoplay"),
        JS_NewCFunction(ctx, video_stream_player_class_has_autoplay, "has_autoplay", 0),
        JS_NewCFunction(ctx, video_stream_player_class_set_autoplay, "set_autoplay", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "paused"),
        JS_NewCFunction(ctx, video_stream_player_class_is_paused, "is_paused", 0),
        JS_NewCFunction(ctx, video_stream_player_class_set_paused, "set_paused", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "expand"),
        JS_NewCFunction(ctx, video_stream_player_class_has_expand, "has_expand", 0),
        JS_NewCFunction(ctx, video_stream_player_class_set_expand, "set_expand", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "loop"),
        JS_NewCFunction(ctx, video_stream_player_class_has_loop, "has_loop", 0),
        JS_NewCFunction(ctx, video_stream_player_class_set_loop, "set_loop", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "buffering_msec"),
        JS_NewCFunction(ctx, video_stream_player_class_get_buffering_msec, "get_buffering_msec", 0),
        JS_NewCFunction(ctx, video_stream_player_class_set_buffering_msec, "set_buffering_msec", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "stream_position"),
        JS_NewCFunction(ctx, video_stream_player_class_get_stream_position, "get_stream_position", 0),
        JS_NewCFunction(ctx, video_stream_player_class_set_stream_position, "set_stream_position", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "bus"),
        JS_NewCFunction(ctx, video_stream_player_class_get_bus, "get_bus", 0),
        JS_NewCFunction(ctx, video_stream_player_class_set_bus, "set_bus", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "finished"),
		JS_NewCFunction(ctx, video_stream_player_class_get_finished_signal, "get_finished_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_video_stream_player_enum(JSContext *ctx, JSValue ctor) {
}

static int js_video_stream_player_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["VideoStreamPlayer"] = class_id;
	classes_by_id[class_id] = "VideoStreamPlayer";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &video_stream_player_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Control"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_video_stream_player_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, video_stream_player_class_proto_funcs, _countof(video_stream_player_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, video_stream_player_class_constructor, "VideoStreamPlayer", 0, JS_CFUNC_constructor, 0);
	define_video_stream_player_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "VideoStreamPlayer", ctor);
	ctor_list["VideoStreamPlayer"] = ctor;

	return 0;
}

JSModuleDef *_js_init_video_stream_player_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/control';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_video_stream_player_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "VideoStreamPlayer");
	return m;
}

JSModuleDef *js_init_video_stream_player_module(JSContext *ctx) {
	return _js_init_video_stream_player_module(ctx, "@godot/classes/video_stream_player");
}

void __register_video_stream_player() {
	js_init_video_stream_player_module(js_context());
}

void register_video_stream_player() {
	__register_video_stream_player();
}