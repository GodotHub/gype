#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/animation_mixer.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/animation_player.hpp>
using namespace godot;

static void animation_player_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["AnimationPlayer"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef animation_player_class_def = {
    "AnimationPlayer",
    animation_player_class_finalizer
};

static JSValue animation_player_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["AnimationPlayer"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    AnimationPlayer *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<AnimationPlayer *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(AnimationPlayer);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue animation_player_class_animation_set_next(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationPlayer::animation_set_next, ctx, this_val, argc, argv);
};
static JSValue animation_player_class_animation_get_next(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationPlayer::animation_get_next, ctx, this_val, argc, argv);
};
static JSValue animation_player_class_set_blend_time(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationPlayer::set_blend_time, ctx, this_val, argc, argv);
};
static JSValue animation_player_class_get_blend_time(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationPlayer::get_blend_time, ctx, this_val, argc, argv);
};
static JSValue animation_player_class_set_default_blend_time(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationPlayer::set_default_blend_time, ctx, this_val, argc, argv);
};
static JSValue animation_player_class_get_default_blend_time(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationPlayer::get_default_blend_time, ctx, this_val, argc, argv);
}
static JSValue animation_player_class_set_auto_capture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationPlayer::set_auto_capture, ctx, this_val, argc, argv);
};
static JSValue animation_player_class_is_auto_capture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationPlayer::is_auto_capture, ctx, this_val, argc, argv);
}
static JSValue animation_player_class_set_auto_capture_duration(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationPlayer::set_auto_capture_duration, ctx, this_val, argc, argv);
};
static JSValue animation_player_class_get_auto_capture_duration(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationPlayer::get_auto_capture_duration, ctx, this_val, argc, argv);
}
static JSValue animation_player_class_set_auto_capture_transition_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationPlayer::set_auto_capture_transition_type, ctx, this_val, argc, argv);
};
static JSValue animation_player_class_get_auto_capture_transition_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationPlayer::get_auto_capture_transition_type, ctx, this_val, argc, argv);
}
static JSValue animation_player_class_set_auto_capture_ease_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationPlayer::set_auto_capture_ease_type, ctx, this_val, argc, argv);
};
static JSValue animation_player_class_get_auto_capture_ease_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationPlayer::get_auto_capture_ease_type, ctx, this_val, argc, argv);
}
static JSValue animation_player_class_play(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationPlayer::play, ctx, this_val, argc, argv);
};
static JSValue animation_player_class_play_section_with_markers(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationPlayer::play_section_with_markers, ctx, this_val, argc, argv);
};
static JSValue animation_player_class_play_section(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationPlayer::play_section, ctx, this_val, argc, argv);
};
static JSValue animation_player_class_play_backwards(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationPlayer::play_backwards, ctx, this_val, argc, argv);
};
static JSValue animation_player_class_play_section_with_markers_backwards(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationPlayer::play_section_with_markers_backwards, ctx, this_val, argc, argv);
};
static JSValue animation_player_class_play_section_backwards(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationPlayer::play_section_backwards, ctx, this_val, argc, argv);
};
static JSValue animation_player_class_play_with_capture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationPlayer::play_with_capture, ctx, this_val, argc, argv);
};
static JSValue animation_player_class_pause(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationPlayer::pause, ctx, this_val, argc, argv);
};
static JSValue animation_player_class_stop(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationPlayer::stop, ctx, this_val, argc, argv);
};
static JSValue animation_player_class_is_playing(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationPlayer::is_playing, ctx, this_val, argc, argv);
};
static JSValue animation_player_class_set_current_animation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationPlayer::set_current_animation, ctx, this_val, argc, argv);
};
static JSValue animation_player_class_get_current_animation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationPlayer::get_current_animation, ctx, this_val, argc, argv);
}
static JSValue animation_player_class_set_assigned_animation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationPlayer::set_assigned_animation, ctx, this_val, argc, argv);
};
static JSValue animation_player_class_get_assigned_animation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationPlayer::get_assigned_animation, ctx, this_val, argc, argv);
}
static JSValue animation_player_class_queue(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationPlayer::queue, ctx, this_val, argc, argv);
};
static JSValue animation_player_class_get_queue(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&AnimationPlayer::get_queue, ctx, this_val, argc, argv);
};
static JSValue animation_player_class_clear_queue(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationPlayer::clear_queue, ctx, this_val, argc, argv);
};
static JSValue animation_player_class_set_speed_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationPlayer::set_speed_scale, ctx, this_val, argc, argv);
};
static JSValue animation_player_class_get_speed_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationPlayer::get_speed_scale, ctx, this_val, argc, argv);
}
static JSValue animation_player_class_get_playing_speed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationPlayer::get_playing_speed, ctx, this_val, argc, argv);
};
static JSValue animation_player_class_set_autoplay(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationPlayer::set_autoplay, ctx, this_val, argc, argv);
};
static JSValue animation_player_class_get_autoplay(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationPlayer::get_autoplay, ctx, this_val, argc, argv);
}
static JSValue animation_player_class_set_movie_quit_on_finish_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationPlayer::set_movie_quit_on_finish_enabled, ctx, this_val, argc, argv);
};
static JSValue animation_player_class_is_movie_quit_on_finish_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationPlayer::is_movie_quit_on_finish_enabled, ctx, this_val, argc, argv);
}
static JSValue animation_player_class_get_current_animation_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationPlayer::get_current_animation_position, ctx, this_val, argc, argv);
}
static JSValue animation_player_class_get_current_animation_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationPlayer::get_current_animation_length, ctx, this_val, argc, argv);
}
static JSValue animation_player_class_set_section_with_markers(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationPlayer::set_section_with_markers, ctx, this_val, argc, argv);
};
static JSValue animation_player_class_set_section(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationPlayer::set_section, ctx, this_val, argc, argv);
};
static JSValue animation_player_class_reset_section(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationPlayer::reset_section, ctx, this_val, argc, argv);
};
static JSValue animation_player_class_get_section_start_time(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationPlayer::get_section_start_time, ctx, this_val, argc, argv);
};
static JSValue animation_player_class_get_section_end_time(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationPlayer::get_section_end_time, ctx, this_val, argc, argv);
};
static JSValue animation_player_class_has_section(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationPlayer::has_section, ctx, this_val, argc, argv);
};
static JSValue animation_player_class_seek(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationPlayer::seek, ctx, this_val, argc, argv);
};
static JSValue animation_player_class_set_process_callback(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationPlayer::set_process_callback, ctx, this_val, argc, argv);
};
static JSValue animation_player_class_get_process_callback(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationPlayer::get_process_callback, ctx, this_val, argc, argv);
};
static JSValue animation_player_class_set_method_call_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationPlayer::set_method_call_mode, ctx, this_val, argc, argv);
};
static JSValue animation_player_class_get_method_call_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationPlayer::get_method_call_mode, ctx, this_val, argc, argv);
};
static JSValue animation_player_class_set_root(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AnimationPlayer::set_root, ctx, this_val, argc, argv);
};
static JSValue animation_player_class_get_root(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AnimationPlayer::get_root, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry animation_player_class_proto_funcs[] = {
	JS_CFUNC_DEF("animation_set_next", 2, &animation_player_class_animation_set_next),
	JS_CFUNC_DEF("animation_get_next", 1, &animation_player_class_animation_get_next),
	JS_CFUNC_DEF("set_blend_time", 3, &animation_player_class_set_blend_time),
	JS_CFUNC_DEF("get_blend_time", 2, &animation_player_class_get_blend_time),
	JS_CFUNC_DEF("set_default_blend_time", 1, &animation_player_class_set_default_blend_time),
	JS_CFUNC_DEF("get_default_blend_time", 0, &animation_player_class_get_default_blend_time),
	JS_CFUNC_DEF("set_auto_capture", 1, &animation_player_class_set_auto_capture),
	JS_CFUNC_DEF("is_auto_capture", 0, &animation_player_class_is_auto_capture),
	JS_CFUNC_DEF("set_auto_capture_duration", 1, &animation_player_class_set_auto_capture_duration),
	JS_CFUNC_DEF("get_auto_capture_duration", 0, &animation_player_class_get_auto_capture_duration),
	JS_CFUNC_DEF("set_auto_capture_transition_type", 1, &animation_player_class_set_auto_capture_transition_type),
	JS_CFUNC_DEF("get_auto_capture_transition_type", 0, &animation_player_class_get_auto_capture_transition_type),
	JS_CFUNC_DEF("set_auto_capture_ease_type", 1, &animation_player_class_set_auto_capture_ease_type),
	JS_CFUNC_DEF("get_auto_capture_ease_type", 0, &animation_player_class_get_auto_capture_ease_type),
	JS_CFUNC_DEF("play", 4, &animation_player_class_play),
	JS_CFUNC_DEF("play_section_with_markers", 6, &animation_player_class_play_section_with_markers),
	JS_CFUNC_DEF("play_section", 6, &animation_player_class_play_section),
	JS_CFUNC_DEF("play_backwards", 2, &animation_player_class_play_backwards),
	JS_CFUNC_DEF("play_section_with_markers_backwards", 4, &animation_player_class_play_section_with_markers_backwards),
	JS_CFUNC_DEF("play_section_backwards", 4, &animation_player_class_play_section_backwards),
	JS_CFUNC_DEF("play_with_capture", 7, &animation_player_class_play_with_capture),
	JS_CFUNC_DEF("pause", 0, &animation_player_class_pause),
	JS_CFUNC_DEF("stop", 1, &animation_player_class_stop),
	JS_CFUNC_DEF("is_playing", 0, &animation_player_class_is_playing),
	JS_CFUNC_DEF("set_current_animation", 1, &animation_player_class_set_current_animation),
	JS_CFUNC_DEF("get_current_animation", 0, &animation_player_class_get_current_animation),
	JS_CFUNC_DEF("set_assigned_animation", 1, &animation_player_class_set_assigned_animation),
	JS_CFUNC_DEF("get_assigned_animation", 0, &animation_player_class_get_assigned_animation),
	JS_CFUNC_DEF("queue", 1, &animation_player_class_queue),
	JS_CFUNC_DEF("get_queue", 0, &animation_player_class_get_queue),
	JS_CFUNC_DEF("clear_queue", 0, &animation_player_class_clear_queue),
	JS_CFUNC_DEF("set_speed_scale", 1, &animation_player_class_set_speed_scale),
	JS_CFUNC_DEF("get_speed_scale", 0, &animation_player_class_get_speed_scale),
	JS_CFUNC_DEF("get_playing_speed", 0, &animation_player_class_get_playing_speed),
	JS_CFUNC_DEF("set_autoplay", 1, &animation_player_class_set_autoplay),
	JS_CFUNC_DEF("get_autoplay", 0, &animation_player_class_get_autoplay),
	JS_CFUNC_DEF("set_movie_quit_on_finish_enabled", 1, &animation_player_class_set_movie_quit_on_finish_enabled),
	JS_CFUNC_DEF("is_movie_quit_on_finish_enabled", 0, &animation_player_class_is_movie_quit_on_finish_enabled),
	JS_CFUNC_DEF("get_current_animation_position", 0, &animation_player_class_get_current_animation_position),
	JS_CFUNC_DEF("get_current_animation_length", 0, &animation_player_class_get_current_animation_length),
	JS_CFUNC_DEF("set_section_with_markers", 2, &animation_player_class_set_section_with_markers),
	JS_CFUNC_DEF("set_section", 2, &animation_player_class_set_section),
	JS_CFUNC_DEF("reset_section", 0, &animation_player_class_reset_section),
	JS_CFUNC_DEF("get_section_start_time", 0, &animation_player_class_get_section_start_time),
	JS_CFUNC_DEF("get_section_end_time", 0, &animation_player_class_get_section_end_time),
	JS_CFUNC_DEF("has_section", 0, &animation_player_class_has_section),
	JS_CFUNC_DEF("seek", 3, &animation_player_class_seek),
	JS_CFUNC_DEF("set_process_callback", 1, &animation_player_class_set_process_callback),
	JS_CFUNC_DEF("get_process_callback", 0, &animation_player_class_get_process_callback),
	JS_CFUNC_DEF("set_method_call_mode", 1, &animation_player_class_set_method_call_mode),
	JS_CFUNC_DEF("get_method_call_mode", 0, &animation_player_class_get_method_call_mode),
	JS_CFUNC_DEF("set_root", 1, &animation_player_class_set_root),
	JS_CFUNC_DEF("get_root", 0, &animation_player_class_get_root),
};


static JSValue animation_player_class_get_current_animation_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	AnimationPlayer *opaque = static_cast<AnimationPlayer *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "current_animation_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "current_animation_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "current_animation_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue animation_player_class_get_animation_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	AnimationPlayer *opaque = static_cast<AnimationPlayer *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "animation_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "animation_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "animation_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_animation_player_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "current_animation"),
        JS_NewCFunction(ctx, animation_player_class_get_current_animation, "get_current_animation", 0),
        JS_NewCFunction(ctx, animation_player_class_set_current_animation, "set_current_animation", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "assigned_animation"),
        JS_NewCFunction(ctx, animation_player_class_get_assigned_animation, "get_assigned_animation", 0),
        JS_NewCFunction(ctx, animation_player_class_set_assigned_animation, "set_assigned_animation", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "autoplay"),
        JS_NewCFunction(ctx, animation_player_class_get_autoplay, "get_autoplay", 0),
        JS_NewCFunction(ctx, animation_player_class_set_autoplay, "set_autoplay", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "current_animation_length"),
        JS_NewCFunction(ctx, animation_player_class_get_current_animation_length, "get_current_animation_length", 0),
        JS_UNDEFINED,
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "current_animation_position"),
        JS_NewCFunction(ctx, animation_player_class_get_current_animation_position, "get_current_animation_position", 0),
        JS_UNDEFINED,
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "playback_auto_capture"),
        JS_NewCFunction(ctx, animation_player_class_is_auto_capture, "is_auto_capture", 0),
        JS_NewCFunction(ctx, animation_player_class_set_auto_capture, "set_auto_capture", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "playback_auto_capture_duration"),
        JS_NewCFunction(ctx, animation_player_class_get_auto_capture_duration, "get_auto_capture_duration", 0),
        JS_NewCFunction(ctx, animation_player_class_set_auto_capture_duration, "set_auto_capture_duration", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "playback_auto_capture_transition_type"),
        JS_NewCFunction(ctx, animation_player_class_get_auto_capture_transition_type, "get_auto_capture_transition_type", 0),
        JS_NewCFunction(ctx, animation_player_class_set_auto_capture_transition_type, "set_auto_capture_transition_type", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "playback_auto_capture_ease_type"),
        JS_NewCFunction(ctx, animation_player_class_get_auto_capture_ease_type, "get_auto_capture_ease_type", 0),
        JS_NewCFunction(ctx, animation_player_class_set_auto_capture_ease_type, "set_auto_capture_ease_type", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "playback_default_blend_time"),
        JS_NewCFunction(ctx, animation_player_class_get_default_blend_time, "get_default_blend_time", 0),
        JS_NewCFunction(ctx, animation_player_class_set_default_blend_time, "set_default_blend_time", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "speed_scale"),
        JS_NewCFunction(ctx, animation_player_class_get_speed_scale, "get_speed_scale", 0),
        JS_NewCFunction(ctx, animation_player_class_set_speed_scale, "set_speed_scale", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "movie_quit_on_finish"),
        JS_NewCFunction(ctx, animation_player_class_is_movie_quit_on_finish_enabled, "is_movie_quit_on_finish_enabled", 0),
        JS_NewCFunction(ctx, animation_player_class_set_movie_quit_on_finish_enabled, "set_movie_quit_on_finish_enabled", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "current_animation_changed"),
		JS_NewCFunction(ctx, animation_player_class_get_current_animation_changed_signal, "get_current_animation_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "animation_changed"),
		JS_NewCFunction(ctx, animation_player_class_get_animation_changed_signal, "get_animation_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_animation_player_enum(JSContext *ctx, JSValue ctor) {
	JSValue AnimationProcessCallback_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, AnimationProcessCallback_obj, "ANIMATION_PROCESS_PHYSICS", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, AnimationProcessCallback_obj, "ANIMATION_PROCESS_IDLE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, AnimationProcessCallback_obj, "ANIMATION_PROCESS_MANUAL", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "AnimationProcessCallback", AnimationProcessCallback_obj);
	JSValue AnimationMethodCallMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, AnimationMethodCallMode_obj, "ANIMATION_METHOD_CALL_DEFERRED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, AnimationMethodCallMode_obj, "ANIMATION_METHOD_CALL_IMMEDIATE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ctor, "AnimationMethodCallMode", AnimationMethodCallMode_obj);
}

static int js_animation_player_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["AnimationPlayer"] = class_id;
	classes_by_id[class_id] = "AnimationPlayer";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &animation_player_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["AnimationMixer"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_animation_player_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, animation_player_class_proto_funcs, _countof(animation_player_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, animation_player_class_constructor, "AnimationPlayer", 0, JS_CFUNC_constructor, 0);
	define_animation_player_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "AnimationPlayer", ctor);

	return 0;
}

JSModuleDef *_js_init_animation_player_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/animation_mixer';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_animation_player_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "AnimationPlayer");
	return m;
}

JSModuleDef *js_init_animation_player_module(JSContext *ctx) {
	return _js_init_animation_player_module(ctx, "@godot/classes/animation_player");
}

void __register_animation_player() {
	js_init_animation_player_module(js_context());
}

void register_animation_player() {
	__register_animation_player();
}