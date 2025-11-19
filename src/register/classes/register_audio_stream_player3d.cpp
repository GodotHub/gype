#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/audio_stream.hpp>
#include <godot_cpp/classes/audio_stream_playback.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/audio_stream_player3d.hpp>
using namespace godot;

static void audio_stream_player3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["AudioStreamPlayer3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef audio_stream_player3d_class_def = {
    "AudioStreamPlayer3D",
    audio_stream_player3d_class_finalizer
};

static JSValue audio_stream_player3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["AudioStreamPlayer3D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    AudioStreamPlayer3D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<AudioStreamPlayer3D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(AudioStreamPlayer3D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue audio_stream_player3d_class_set_stream(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamPlayer3D::set_stream, ctx, this_val, argc, argv);
};
static JSValue audio_stream_player3d_class_get_stream(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamPlayer3D::get_stream, ctx, this_val, argc, argv);
}
static JSValue audio_stream_player3d_class_set_volume_db(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamPlayer3D::set_volume_db, ctx, this_val, argc, argv);
};
static JSValue audio_stream_player3d_class_get_volume_db(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamPlayer3D::get_volume_db, ctx, this_val, argc, argv);
}
static JSValue audio_stream_player3d_class_set_volume_linear(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamPlayer3D::set_volume_linear, ctx, this_val, argc, argv);
};
static JSValue audio_stream_player3d_class_get_volume_linear(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamPlayer3D::get_volume_linear, ctx, this_val, argc, argv);
}
static JSValue audio_stream_player3d_class_set_unit_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamPlayer3D::set_unit_size, ctx, this_val, argc, argv);
};
static JSValue audio_stream_player3d_class_get_unit_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamPlayer3D::get_unit_size, ctx, this_val, argc, argv);
}
static JSValue audio_stream_player3d_class_set_max_db(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamPlayer3D::set_max_db, ctx, this_val, argc, argv);
};
static JSValue audio_stream_player3d_class_get_max_db(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamPlayer3D::get_max_db, ctx, this_val, argc, argv);
}
static JSValue audio_stream_player3d_class_set_pitch_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamPlayer3D::set_pitch_scale, ctx, this_val, argc, argv);
};
static JSValue audio_stream_player3d_class_get_pitch_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamPlayer3D::get_pitch_scale, ctx, this_val, argc, argv);
}
static JSValue audio_stream_player3d_class_play(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamPlayer3D::play, ctx, this_val, argc, argv);
};
static JSValue audio_stream_player3d_class_seek(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamPlayer3D::seek, ctx, this_val, argc, argv);
};
static JSValue audio_stream_player3d_class_stop(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamPlayer3D::stop, ctx, this_val, argc, argv);
};
static JSValue audio_stream_player3d_class_is_playing(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamPlayer3D::is_playing, ctx, this_val, argc, argv);
}
static JSValue audio_stream_player3d_class_get_playback_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&AudioStreamPlayer3D::get_playback_position, ctx, this_val, argc, argv);
};
static JSValue audio_stream_player3d_class_set_bus(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamPlayer3D::set_bus, ctx, this_val, argc, argv);
};
static JSValue audio_stream_player3d_class_get_bus(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<StringName> *proxy = memnew(ObjectProxy<StringName>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> StringName {
		AudioStreamPlayer3D *obj = static_cast<AudioStreamPlayer3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_bus();
	};
	proxy->setter = [this_val](const StringName &value) -> void {
		AudioStreamPlayer3D *js_proxy = static_cast<AudioStreamPlayer3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_bus(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["StringNameProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "StringNameProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue audio_stream_player3d_class_set_autoplay(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamPlayer3D::set_autoplay, ctx, this_val, argc, argv);
};
static JSValue audio_stream_player3d_class_is_autoplay_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamPlayer3D::is_autoplay_enabled, ctx, this_val, argc, argv);
}
static JSValue audio_stream_player3d_class_set_playing(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamPlayer3D::set_playing, ctx, this_val, argc, argv);
};
static JSValue audio_stream_player3d_class_set_max_distance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamPlayer3D::set_max_distance, ctx, this_val, argc, argv);
};
static JSValue audio_stream_player3d_class_get_max_distance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamPlayer3D::get_max_distance, ctx, this_val, argc, argv);
}
static JSValue audio_stream_player3d_class_set_area_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamPlayer3D::set_area_mask, ctx, this_val, argc, argv);
};
static JSValue audio_stream_player3d_class_get_area_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamPlayer3D::get_area_mask, ctx, this_val, argc, argv);
}
static JSValue audio_stream_player3d_class_set_emission_angle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamPlayer3D::set_emission_angle, ctx, this_val, argc, argv);
};
static JSValue audio_stream_player3d_class_get_emission_angle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamPlayer3D::get_emission_angle, ctx, this_val, argc, argv);
}
static JSValue audio_stream_player3d_class_set_emission_angle_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamPlayer3D::set_emission_angle_enabled, ctx, this_val, argc, argv);
};
static JSValue audio_stream_player3d_class_is_emission_angle_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamPlayer3D::is_emission_angle_enabled, ctx, this_val, argc, argv);
}
static JSValue audio_stream_player3d_class_set_emission_angle_filter_attenuation_db(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamPlayer3D::set_emission_angle_filter_attenuation_db, ctx, this_val, argc, argv);
};
static JSValue audio_stream_player3d_class_get_emission_angle_filter_attenuation_db(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamPlayer3D::get_emission_angle_filter_attenuation_db, ctx, this_val, argc, argv);
}
static JSValue audio_stream_player3d_class_set_attenuation_filter_cutoff_hz(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamPlayer3D::set_attenuation_filter_cutoff_hz, ctx, this_val, argc, argv);
};
static JSValue audio_stream_player3d_class_get_attenuation_filter_cutoff_hz(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamPlayer3D::get_attenuation_filter_cutoff_hz, ctx, this_val, argc, argv);
}
static JSValue audio_stream_player3d_class_set_attenuation_filter_db(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamPlayer3D::set_attenuation_filter_db, ctx, this_val, argc, argv);
};
static JSValue audio_stream_player3d_class_get_attenuation_filter_db(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamPlayer3D::get_attenuation_filter_db, ctx, this_val, argc, argv);
}
static JSValue audio_stream_player3d_class_set_attenuation_model(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamPlayer3D::set_attenuation_model, ctx, this_val, argc, argv);
};
static JSValue audio_stream_player3d_class_get_attenuation_model(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamPlayer3D::get_attenuation_model, ctx, this_val, argc, argv);
}
static JSValue audio_stream_player3d_class_set_doppler_tracking(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamPlayer3D::set_doppler_tracking, ctx, this_val, argc, argv);
};
static JSValue audio_stream_player3d_class_get_doppler_tracking(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamPlayer3D::get_doppler_tracking, ctx, this_val, argc, argv);
}
static JSValue audio_stream_player3d_class_set_stream_paused(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamPlayer3D::set_stream_paused, ctx, this_val, argc, argv);
};
static JSValue audio_stream_player3d_class_get_stream_paused(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamPlayer3D::get_stream_paused, ctx, this_val, argc, argv);
}
static JSValue audio_stream_player3d_class_set_max_polyphony(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamPlayer3D::set_max_polyphony, ctx, this_val, argc, argv);
};
static JSValue audio_stream_player3d_class_get_max_polyphony(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamPlayer3D::get_max_polyphony, ctx, this_val, argc, argv);
}
static JSValue audio_stream_player3d_class_set_panning_strength(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamPlayer3D::set_panning_strength, ctx, this_val, argc, argv);
};
static JSValue audio_stream_player3d_class_get_panning_strength(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamPlayer3D::get_panning_strength, ctx, this_val, argc, argv);
}
static JSValue audio_stream_player3d_class_has_stream_playback(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&AudioStreamPlayer3D::has_stream_playback, ctx, this_val, argc, argv);
};
static JSValue audio_stream_player3d_class_get_stream_playback(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&AudioStreamPlayer3D::get_stream_playback, ctx, this_val, argc, argv);
};
static JSValue audio_stream_player3d_class_set_playback_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&AudioStreamPlayer3D::set_playback_type, ctx, this_val, argc, argv);
};
static JSValue audio_stream_player3d_class_get_playback_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&AudioStreamPlayer3D::get_playback_type, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry audio_stream_player3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_stream", 1, &audio_stream_player3d_class_set_stream),
	JS_CFUNC_DEF("get_stream", 0, &audio_stream_player3d_class_get_stream),
	JS_CFUNC_DEF("set_volume_db", 1, &audio_stream_player3d_class_set_volume_db),
	JS_CFUNC_DEF("get_volume_db", 0, &audio_stream_player3d_class_get_volume_db),
	JS_CFUNC_DEF("set_volume_linear", 1, &audio_stream_player3d_class_set_volume_linear),
	JS_CFUNC_DEF("get_volume_linear", 0, &audio_stream_player3d_class_get_volume_linear),
	JS_CFUNC_DEF("set_unit_size", 1, &audio_stream_player3d_class_set_unit_size),
	JS_CFUNC_DEF("get_unit_size", 0, &audio_stream_player3d_class_get_unit_size),
	JS_CFUNC_DEF("set_max_db", 1, &audio_stream_player3d_class_set_max_db),
	JS_CFUNC_DEF("get_max_db", 0, &audio_stream_player3d_class_get_max_db),
	JS_CFUNC_DEF("set_pitch_scale", 1, &audio_stream_player3d_class_set_pitch_scale),
	JS_CFUNC_DEF("get_pitch_scale", 0, &audio_stream_player3d_class_get_pitch_scale),
	JS_CFUNC_DEF("play", 1, &audio_stream_player3d_class_play),
	JS_CFUNC_DEF("seek", 1, &audio_stream_player3d_class_seek),
	JS_CFUNC_DEF("stop", 0, &audio_stream_player3d_class_stop),
	JS_CFUNC_DEF("is_playing", 0, &audio_stream_player3d_class_is_playing),
	JS_CFUNC_DEF("get_playback_position", 0, &audio_stream_player3d_class_get_playback_position),
	JS_CFUNC_DEF("set_bus", 1, &audio_stream_player3d_class_set_bus),
	JS_CFUNC_DEF("get_bus", 0, &audio_stream_player3d_class_get_bus),
	JS_CFUNC_DEF("set_autoplay", 1, &audio_stream_player3d_class_set_autoplay),
	JS_CFUNC_DEF("is_autoplay_enabled", 0, &audio_stream_player3d_class_is_autoplay_enabled),
	JS_CFUNC_DEF("set_playing", 1, &audio_stream_player3d_class_set_playing),
	JS_CFUNC_DEF("set_max_distance", 1, &audio_stream_player3d_class_set_max_distance),
	JS_CFUNC_DEF("get_max_distance", 0, &audio_stream_player3d_class_get_max_distance),
	JS_CFUNC_DEF("set_area_mask", 1, &audio_stream_player3d_class_set_area_mask),
	JS_CFUNC_DEF("get_area_mask", 0, &audio_stream_player3d_class_get_area_mask),
	JS_CFUNC_DEF("set_emission_angle", 1, &audio_stream_player3d_class_set_emission_angle),
	JS_CFUNC_DEF("get_emission_angle", 0, &audio_stream_player3d_class_get_emission_angle),
	JS_CFUNC_DEF("set_emission_angle_enabled", 1, &audio_stream_player3d_class_set_emission_angle_enabled),
	JS_CFUNC_DEF("is_emission_angle_enabled", 0, &audio_stream_player3d_class_is_emission_angle_enabled),
	JS_CFUNC_DEF("set_emission_angle_filter_attenuation_db", 1, &audio_stream_player3d_class_set_emission_angle_filter_attenuation_db),
	JS_CFUNC_DEF("get_emission_angle_filter_attenuation_db", 0, &audio_stream_player3d_class_get_emission_angle_filter_attenuation_db),
	JS_CFUNC_DEF("set_attenuation_filter_cutoff_hz", 1, &audio_stream_player3d_class_set_attenuation_filter_cutoff_hz),
	JS_CFUNC_DEF("get_attenuation_filter_cutoff_hz", 0, &audio_stream_player3d_class_get_attenuation_filter_cutoff_hz),
	JS_CFUNC_DEF("set_attenuation_filter_db", 1, &audio_stream_player3d_class_set_attenuation_filter_db),
	JS_CFUNC_DEF("get_attenuation_filter_db", 0, &audio_stream_player3d_class_get_attenuation_filter_db),
	JS_CFUNC_DEF("set_attenuation_model", 1, &audio_stream_player3d_class_set_attenuation_model),
	JS_CFUNC_DEF("get_attenuation_model", 0, &audio_stream_player3d_class_get_attenuation_model),
	JS_CFUNC_DEF("set_doppler_tracking", 1, &audio_stream_player3d_class_set_doppler_tracking),
	JS_CFUNC_DEF("get_doppler_tracking", 0, &audio_stream_player3d_class_get_doppler_tracking),
	JS_CFUNC_DEF("set_stream_paused", 1, &audio_stream_player3d_class_set_stream_paused),
	JS_CFUNC_DEF("get_stream_paused", 0, &audio_stream_player3d_class_get_stream_paused),
	JS_CFUNC_DEF("set_max_polyphony", 1, &audio_stream_player3d_class_set_max_polyphony),
	JS_CFUNC_DEF("get_max_polyphony", 0, &audio_stream_player3d_class_get_max_polyphony),
	JS_CFUNC_DEF("set_panning_strength", 1, &audio_stream_player3d_class_set_panning_strength),
	JS_CFUNC_DEF("get_panning_strength", 0, &audio_stream_player3d_class_get_panning_strength),
	JS_CFUNC_DEF("has_stream_playback", 0, &audio_stream_player3d_class_has_stream_playback),
	JS_CFUNC_DEF("get_stream_playback", 0, &audio_stream_player3d_class_get_stream_playback),
	JS_CFUNC_DEF("set_playback_type", 1, &audio_stream_player3d_class_set_playback_type),
	JS_CFUNC_DEF("get_playback_type", 0, &audio_stream_player3d_class_get_playback_type),
};


static JSValue audio_stream_player3d_class_get_finished_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	AudioStreamPlayer3D *opaque = static_cast<AudioStreamPlayer3D *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "finished_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "finished"));
		JS_DefinePropertyValueStr(ctx, this_val, "finished_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_audio_stream_player3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "stream"),
        JS_NewCFunction(ctx, audio_stream_player3d_class_get_stream, "get_stream", 0),
        JS_NewCFunction(ctx, audio_stream_player3d_class_set_stream, "set_stream", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "attenuation_model"),
        JS_NewCFunction(ctx, audio_stream_player3d_class_get_attenuation_model, "get_attenuation_model", 0),
        JS_NewCFunction(ctx, audio_stream_player3d_class_set_attenuation_model, "set_attenuation_model", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "volume_db"),
        JS_NewCFunction(ctx, audio_stream_player3d_class_get_volume_db, "get_volume_db", 0),
        JS_NewCFunction(ctx, audio_stream_player3d_class_set_volume_db, "set_volume_db", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "volume_linear"),
        JS_NewCFunction(ctx, audio_stream_player3d_class_get_volume_linear, "get_volume_linear", 0),
        JS_NewCFunction(ctx, audio_stream_player3d_class_set_volume_linear, "set_volume_linear", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "unit_size"),
        JS_NewCFunction(ctx, audio_stream_player3d_class_get_unit_size, "get_unit_size", 0),
        JS_NewCFunction(ctx, audio_stream_player3d_class_set_unit_size, "set_unit_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "max_db"),
        JS_NewCFunction(ctx, audio_stream_player3d_class_get_max_db, "get_max_db", 0),
        JS_NewCFunction(ctx, audio_stream_player3d_class_set_max_db, "set_max_db", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "pitch_scale"),
        JS_NewCFunction(ctx, audio_stream_player3d_class_get_pitch_scale, "get_pitch_scale", 0),
        JS_NewCFunction(ctx, audio_stream_player3d_class_set_pitch_scale, "set_pitch_scale", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "playing"),
        JS_NewCFunction(ctx, audio_stream_player3d_class_is_playing, "is_playing", 0),
        JS_NewCFunction(ctx, audio_stream_player3d_class_set_playing, "set_playing", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "autoplay"),
        JS_NewCFunction(ctx, audio_stream_player3d_class_is_autoplay_enabled, "is_autoplay_enabled", 0),
        JS_NewCFunction(ctx, audio_stream_player3d_class_set_autoplay, "set_autoplay", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "stream_paused"),
        JS_NewCFunction(ctx, audio_stream_player3d_class_get_stream_paused, "get_stream_paused", 0),
        JS_NewCFunction(ctx, audio_stream_player3d_class_set_stream_paused, "set_stream_paused", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "max_distance"),
        JS_NewCFunction(ctx, audio_stream_player3d_class_get_max_distance, "get_max_distance", 0),
        JS_NewCFunction(ctx, audio_stream_player3d_class_set_max_distance, "set_max_distance", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "max_polyphony"),
        JS_NewCFunction(ctx, audio_stream_player3d_class_get_max_polyphony, "get_max_polyphony", 0),
        JS_NewCFunction(ctx, audio_stream_player3d_class_set_max_polyphony, "set_max_polyphony", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "panning_strength"),
        JS_NewCFunction(ctx, audio_stream_player3d_class_get_panning_strength, "get_panning_strength", 0),
        JS_NewCFunction(ctx, audio_stream_player3d_class_set_panning_strength, "set_panning_strength", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "bus"),
        JS_NewCFunction(ctx, audio_stream_player3d_class_get_bus, "get_bus", 0),
        JS_NewCFunction(ctx, audio_stream_player3d_class_set_bus, "set_bus", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "area_mask"),
        JS_NewCFunction(ctx, audio_stream_player3d_class_get_area_mask, "get_area_mask", 0),
        JS_NewCFunction(ctx, audio_stream_player3d_class_set_area_mask, "set_area_mask", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "playback_type"),
        JS_NewCFunction(ctx, audio_stream_player3d_class_get_playback_type, "get_playback_type", 0),
        JS_NewCFunction(ctx, audio_stream_player3d_class_set_playback_type, "set_playback_type", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "emission_angle_enabled"),
        JS_NewCFunction(ctx, audio_stream_player3d_class_is_emission_angle_enabled, "is_emission_angle_enabled", 0),
        JS_NewCFunction(ctx, audio_stream_player3d_class_set_emission_angle_enabled, "set_emission_angle_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "emission_angle_degrees"),
        JS_NewCFunction(ctx, audio_stream_player3d_class_get_emission_angle, "get_emission_angle", 0),
        JS_NewCFunction(ctx, audio_stream_player3d_class_set_emission_angle, "set_emission_angle", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "emission_angle_filter_attenuation_db"),
        JS_NewCFunction(ctx, audio_stream_player3d_class_get_emission_angle_filter_attenuation_db, "get_emission_angle_filter_attenuation_db", 0),
        JS_NewCFunction(ctx, audio_stream_player3d_class_set_emission_angle_filter_attenuation_db, "set_emission_angle_filter_attenuation_db", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "attenuation_filter_cutoff_hz"),
        JS_NewCFunction(ctx, audio_stream_player3d_class_get_attenuation_filter_cutoff_hz, "get_attenuation_filter_cutoff_hz", 0),
        JS_NewCFunction(ctx, audio_stream_player3d_class_set_attenuation_filter_cutoff_hz, "set_attenuation_filter_cutoff_hz", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "attenuation_filter_db"),
        JS_NewCFunction(ctx, audio_stream_player3d_class_get_attenuation_filter_db, "get_attenuation_filter_db", 0),
        JS_NewCFunction(ctx, audio_stream_player3d_class_set_attenuation_filter_db, "set_attenuation_filter_db", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "doppler_tracking"),
        JS_NewCFunction(ctx, audio_stream_player3d_class_get_doppler_tracking, "get_doppler_tracking", 0),
        JS_NewCFunction(ctx, audio_stream_player3d_class_set_doppler_tracking, "set_doppler_tracking", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "finished"),
		JS_NewCFunction(ctx, audio_stream_player3d_class_get_finished_signal, "get_finished_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_audio_stream_player3d_enum(JSContext *ctx, JSValue ctor) {
	JSValue AttenuationModel_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, AttenuationModel_obj, "ATTENUATION_INVERSE_DISTANCE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, AttenuationModel_obj, "ATTENUATION_INVERSE_SQUARE_DISTANCE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, AttenuationModel_obj, "ATTENUATION_LOGARITHMIC", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, AttenuationModel_obj, "ATTENUATION_DISABLED", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ctor, "AttenuationModel", AttenuationModel_obj);
	JSValue DopplerTracking_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, DopplerTracking_obj, "DOPPLER_TRACKING_DISABLED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, DopplerTracking_obj, "DOPPLER_TRACKING_IDLE_STEP", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, DopplerTracking_obj, "DOPPLER_TRACKING_PHYSICS_STEP", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "DopplerTracking", DopplerTracking_obj);
}

static int js_audio_stream_player3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["AudioStreamPlayer3D"] = class_id;
	classes_by_id[class_id] = "AudioStreamPlayer3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &audio_stream_player3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_audio_stream_player3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, audio_stream_player3d_class_proto_funcs, _countof(audio_stream_player3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, audio_stream_player3d_class_constructor, "AudioStreamPlayer3D", 0, JS_CFUNC_constructor, 0);
	define_audio_stream_player3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "AudioStreamPlayer3D", ctor);

	return 0;
}

JSModuleDef *_js_init_audio_stream_player3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_audio_stream_player3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "AudioStreamPlayer3D");
	return m;
}

JSModuleDef *js_init_audio_stream_player3d_module(JSContext *ctx) {
	return _js_init_audio_stream_player3d_module(ctx, "@godot/classes/audio_stream_player3d");
}

void __register_audio_stream_player3d() {
	js_init_audio_stream_player3d_module(js_context());
}

void register_audio_stream_player3d() {
	__register_audio_stream_player3d();
}