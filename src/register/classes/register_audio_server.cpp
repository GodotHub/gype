#include "register/classes/register_classes.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/str_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/audio_bus_layout.hpp>
#include <godot_cpp/classes/audio_effect.hpp>
#include <godot_cpp/classes/audio_effect_instance.hpp>
#include <godot_cpp/classes/audio_stream.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/audio_server.hpp>


using namespace godot;

static void audio_server_class_finalizer(JSRuntime *rt, JSValue val) {
}

static JSClassDef audio_server_class_def = {
	"_AudioServer",
	audio_server_class_finalizer
};

static JSValue audio_server_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["AudioServer"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);
	if (JS_IsException(obj))
		return obj;

	AudioServer *audio_server_class = AudioServer::get_singleton();
	if (!audio_server_class) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, audio_server_class);
	return obj;
}

static JSValue audio_server_class_set_bus_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&AudioServer::set_bus_count, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue audio_server_class_get_bus_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&AudioServer::get_bus_count, ctx, this_val, argc, argv);
};
static JSValue audio_server_class_remove_bus(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&AudioServer::remove_bus, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue audio_server_class_add_bus(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&AudioServer::add_bus, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue audio_server_class_move_bus(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&AudioServer::move_bus, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue audio_server_class_set_bus_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&AudioServer::set_bus_name, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue audio_server_class_get_bus_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&AudioServer::get_bus_name, ctx, this_val, argc, argv);
};
static JSValue audio_server_class_get_bus_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&AudioServer::get_bus_index, ctx, this_val, argc, argv);
};
static JSValue audio_server_class_get_bus_channels(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&AudioServer::get_bus_channels, ctx, this_val, argc, argv);
};
static JSValue audio_server_class_set_bus_volume_db(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&AudioServer::set_bus_volume_db, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue audio_server_class_get_bus_volume_db(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&AudioServer::get_bus_volume_db, ctx, this_val, argc, argv);
};
static JSValue audio_server_class_set_bus_volume_linear(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&AudioServer::set_bus_volume_linear, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue audio_server_class_get_bus_volume_linear(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&AudioServer::get_bus_volume_linear, ctx, this_val, argc, argv);
};
static JSValue audio_server_class_set_bus_send(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&AudioServer::set_bus_send, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue audio_server_class_get_bus_send(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&AudioServer::get_bus_send, ctx, this_val, argc, argv);
};
static JSValue audio_server_class_set_bus_solo(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&AudioServer::set_bus_solo, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue audio_server_class_is_bus_solo(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&AudioServer::is_bus_solo, ctx, this_val, argc, argv);
};
static JSValue audio_server_class_set_bus_mute(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&AudioServer::set_bus_mute, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue audio_server_class_is_bus_mute(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&AudioServer::is_bus_mute, ctx, this_val, argc, argv);
};
static JSValue audio_server_class_set_bus_bypass_effects(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&AudioServer::set_bus_bypass_effects, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue audio_server_class_is_bus_bypassing_effects(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&AudioServer::is_bus_bypassing_effects, ctx, this_val, argc, argv);
};
static JSValue audio_server_class_add_bus_effect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&AudioServer::add_bus_effect, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue audio_server_class_remove_bus_effect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&AudioServer::remove_bus_effect, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue audio_server_class_get_bus_effect_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&AudioServer::get_bus_effect_count, ctx, this_val, argc, argv);
};
static JSValue audio_server_class_get_bus_effect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&AudioServer::get_bus_effect, ctx, this_val, argc, argv);
};
static JSValue audio_server_class_get_bus_effect_instance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&AudioServer::get_bus_effect_instance, ctx, this_val, argc, argv);
};
static JSValue audio_server_class_swap_bus_effects(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&AudioServer::swap_bus_effects, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue audio_server_class_set_bus_effect_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&AudioServer::set_bus_effect_enabled, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue audio_server_class_is_bus_effect_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&AudioServer::is_bus_effect_enabled, ctx, this_val, argc, argv);
};
static JSValue audio_server_class_get_bus_peak_volume_left_db(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&AudioServer::get_bus_peak_volume_left_db, ctx, this_val, argc, argv);
};
static JSValue audio_server_class_get_bus_peak_volume_right_db(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&AudioServer::get_bus_peak_volume_right_db, ctx, this_val, argc, argv);
};
static JSValue audio_server_class_set_playback_speed_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&AudioServer::set_playback_speed_scale, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue audio_server_class_get_playback_speed_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&AudioServer::get_playback_speed_scale, ctx, this_val, argc, argv);
};
static JSValue audio_server_class_lock(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&AudioServer::lock, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue audio_server_class_unlock(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&AudioServer::unlock, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue audio_server_class_get_speaker_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&AudioServer::get_speaker_mode, ctx, this_val, argc, argv);
};
static JSValue audio_server_class_get_mix_rate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&AudioServer::get_mix_rate, ctx, this_val, argc, argv);
};
static JSValue audio_server_class_get_input_mix_rate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&AudioServer::get_input_mix_rate, ctx, this_val, argc, argv);
};
static JSValue audio_server_class_get_driver_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&AudioServer::get_driver_name, ctx, this_val, argc, argv);
};
static JSValue audio_server_class_get_output_device_list(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&AudioServer::get_output_device_list, ctx, this_val, argc, argv);
};
static JSValue audio_server_class_get_output_device(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&AudioServer::get_output_device, ctx, this_val, argc, argv);
};
static JSValue audio_server_class_set_output_device(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&AudioServer::set_output_device, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue audio_server_class_get_time_to_next_mix(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&AudioServer::get_time_to_next_mix, ctx, this_val, argc, argv);
};
static JSValue audio_server_class_get_time_since_last_mix(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&AudioServer::get_time_since_last_mix, ctx, this_val, argc, argv);
};
static JSValue audio_server_class_get_output_latency(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&AudioServer::get_output_latency, ctx, this_val, argc, argv);
};
static JSValue audio_server_class_get_input_device_list(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&AudioServer::get_input_device_list, ctx, this_val, argc, argv);
};
static JSValue audio_server_class_get_input_device(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&AudioServer::get_input_device, ctx, this_val, argc, argv);
};
static JSValue audio_server_class_set_input_device(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&AudioServer::set_input_device, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue audio_server_class_set_bus_layout(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&AudioServer::set_bus_layout, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue audio_server_class_generate_bus_layout(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&AudioServer::generate_bus_layout, ctx, this_val, argc, argv);
};
static JSValue audio_server_class_set_enable_tagging_used_audio_streams(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&AudioServer::set_enable_tagging_used_audio_streams, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue audio_server_class_is_stream_registered_as_sample(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&AudioServer::is_stream_registered_as_sample, ctx, this_val, argc, argv);
};
static JSValue audio_server_class_register_stream_as_sample(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&AudioServer::register_stream_as_sample, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};

static const JSCFunctionListEntry audio_server_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_bus_count", 1, &audio_server_class_set_bus_count),
	JS_CFUNC_DEF("get_bus_count", 0, &audio_server_class_get_bus_count),
	JS_CFUNC_DEF("remove_bus", 1, &audio_server_class_remove_bus),
	JS_CFUNC_DEF("add_bus", 1, &audio_server_class_add_bus),
	JS_CFUNC_DEF("move_bus", 2, &audio_server_class_move_bus),
	JS_CFUNC_DEF("set_bus_name", 2, &audio_server_class_set_bus_name),
	JS_CFUNC_DEF("get_bus_name", 1, &audio_server_class_get_bus_name),
	JS_CFUNC_DEF("get_bus_index", 1, &audio_server_class_get_bus_index),
	JS_CFUNC_DEF("get_bus_channels", 1, &audio_server_class_get_bus_channels),
	JS_CFUNC_DEF("set_bus_volume_db", 2, &audio_server_class_set_bus_volume_db),
	JS_CFUNC_DEF("get_bus_volume_db", 1, &audio_server_class_get_bus_volume_db),
	JS_CFUNC_DEF("set_bus_volume_linear", 2, &audio_server_class_set_bus_volume_linear),
	JS_CFUNC_DEF("get_bus_volume_linear", 1, &audio_server_class_get_bus_volume_linear),
	JS_CFUNC_DEF("set_bus_send", 2, &audio_server_class_set_bus_send),
	JS_CFUNC_DEF("get_bus_send", 1, &audio_server_class_get_bus_send),
	JS_CFUNC_DEF("set_bus_solo", 2, &audio_server_class_set_bus_solo),
	JS_CFUNC_DEF("is_bus_solo", 1, &audio_server_class_is_bus_solo),
	JS_CFUNC_DEF("set_bus_mute", 2, &audio_server_class_set_bus_mute),
	JS_CFUNC_DEF("is_bus_mute", 1, &audio_server_class_is_bus_mute),
	JS_CFUNC_DEF("set_bus_bypass_effects", 2, &audio_server_class_set_bus_bypass_effects),
	JS_CFUNC_DEF("is_bus_bypassing_effects", 1, &audio_server_class_is_bus_bypassing_effects),
	JS_CFUNC_DEF("add_bus_effect", 3, &audio_server_class_add_bus_effect),
	JS_CFUNC_DEF("remove_bus_effect", 2, &audio_server_class_remove_bus_effect),
	JS_CFUNC_DEF("get_bus_effect_count", 1, &audio_server_class_get_bus_effect_count),
	JS_CFUNC_DEF("get_bus_effect", 2, &audio_server_class_get_bus_effect),
	JS_CFUNC_DEF("get_bus_effect_instance", 3, &audio_server_class_get_bus_effect_instance),
	JS_CFUNC_DEF("swap_bus_effects", 3, &audio_server_class_swap_bus_effects),
	JS_CFUNC_DEF("set_bus_effect_enabled", 3, &audio_server_class_set_bus_effect_enabled),
	JS_CFUNC_DEF("is_bus_effect_enabled", 2, &audio_server_class_is_bus_effect_enabled),
	JS_CFUNC_DEF("get_bus_peak_volume_left_db", 2, &audio_server_class_get_bus_peak_volume_left_db),
	JS_CFUNC_DEF("get_bus_peak_volume_right_db", 2, &audio_server_class_get_bus_peak_volume_right_db),
	JS_CFUNC_DEF("set_playback_speed_scale", 1, &audio_server_class_set_playback_speed_scale),
	JS_CFUNC_DEF("get_playback_speed_scale", 0, &audio_server_class_get_playback_speed_scale),
	JS_CFUNC_DEF("lock", 0, &audio_server_class_lock),
	JS_CFUNC_DEF("unlock", 0, &audio_server_class_unlock),
	JS_CFUNC_DEF("get_speaker_mode", 0, &audio_server_class_get_speaker_mode),
	JS_CFUNC_DEF("get_mix_rate", 0, &audio_server_class_get_mix_rate),
	JS_CFUNC_DEF("get_input_mix_rate", 0, &audio_server_class_get_input_mix_rate),
	JS_CFUNC_DEF("get_driver_name", 0, &audio_server_class_get_driver_name),
	JS_CFUNC_DEF("get_output_device_list", 0, &audio_server_class_get_output_device_list),
	JS_CFUNC_DEF("get_output_device", 0, &audio_server_class_get_output_device),
	JS_CFUNC_DEF("set_output_device", 1, &audio_server_class_set_output_device),
	JS_CFUNC_DEF("get_time_to_next_mix", 0, &audio_server_class_get_time_to_next_mix),
	JS_CFUNC_DEF("get_time_since_last_mix", 0, &audio_server_class_get_time_since_last_mix),
	JS_CFUNC_DEF("get_output_latency", 0, &audio_server_class_get_output_latency),
	JS_CFUNC_DEF("get_input_device_list", 0, &audio_server_class_get_input_device_list),
	JS_CFUNC_DEF("get_input_device", 0, &audio_server_class_get_input_device),
	JS_CFUNC_DEF("set_input_device", 1, &audio_server_class_set_input_device),
	JS_CFUNC_DEF("set_bus_layout", 1, &audio_server_class_set_bus_layout),
	JS_CFUNC_DEF("generate_bus_layout", 0, &audio_server_class_generate_bus_layout),
	JS_CFUNC_DEF("set_enable_tagging_used_audio_streams", 1, &audio_server_class_set_enable_tagging_used_audio_streams),
	JS_CFUNC_DEF("is_stream_registered_as_sample", 1, &audio_server_class_is_stream_registered_as_sample),
	JS_CFUNC_DEF("register_stream_as_sample", 1, &audio_server_class_register_stream_as_sample),
};




static int js_audio_server_class_init(JSContext *ctx) {
	JSClassID class_id = classes["AudioServer"];
	classes["AudioServer"] = class_id;
	JS_NewClass(JS_GetRuntime(ctx), class_id, &audio_server_class_def);

	JSValue proto = JS_NewObject(ctx);
	JSValue base_class = JS_GetClassProto(ctx, classes["Object"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	JS_SetPropertyFunctionList(ctx, proto, audio_server_class_proto_funcs, _countof(audio_server_class_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, audio_server_class_constructor, "_AudioServer", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);


	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "AudioServer", ctor);
	JS_FreeValue(ctx, global);
	return 0;
}

void register_audio_server() {
	js_audio_server_class_init(js_context());
}