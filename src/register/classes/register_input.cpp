#include "register/classes/register_classes.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/str_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/input_event.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/input.hpp>


using namespace godot;

static void input_class_finalizer(JSRuntime *rt, JSValue val) {
}

static JSClassDef input_class_def = {
	"_Input",
	input_class_finalizer
};

static JSValue input_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["Input"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);
	if (JS_IsException(obj))
		return obj;

	Input *input_class = Input::get_singleton();
	if (!input_class) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, input_class);
	return obj;
}

static JSValue input_class_is_anything_pressed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Input::is_anything_pressed, ctx, this_val, argc, argv);
};
static JSValue input_class_is_key_pressed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Input::is_key_pressed, ctx, this_val, argc, argv);
};
static JSValue input_class_is_physical_key_pressed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Input::is_physical_key_pressed, ctx, this_val, argc, argv);
};
static JSValue input_class_is_key_label_pressed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Input::is_key_label_pressed, ctx, this_val, argc, argv);
};
static JSValue input_class_is_mouse_button_pressed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Input::is_mouse_button_pressed, ctx, this_val, argc, argv);
};
static JSValue input_class_is_joy_button_pressed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Input::is_joy_button_pressed, ctx, this_val, argc, argv);
};
static JSValue input_class_is_action_pressed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Input::is_action_pressed, ctx, this_val, argc, argv);
};
static JSValue input_class_is_action_just_pressed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Input::is_action_just_pressed, ctx, this_val, argc, argv);
};
static JSValue input_class_is_action_just_released(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Input::is_action_just_released, ctx, this_val, argc, argv);
};
static JSValue input_class_is_action_just_pressed_by_event(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Input::is_action_just_pressed_by_event, ctx, this_val, argc, argv);
};
static JSValue input_class_is_action_just_released_by_event(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Input::is_action_just_released_by_event, ctx, this_val, argc, argv);
};
static JSValue input_class_get_action_strength(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Input::get_action_strength, ctx, this_val, argc, argv);
};
static JSValue input_class_get_action_raw_strength(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Input::get_action_raw_strength, ctx, this_val, argc, argv);
};
static JSValue input_class_get_axis(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Input::get_axis, ctx, this_val, argc, argv);
};
static JSValue input_class_get_vector(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Input::get_vector, ctx, this_val, argc, argv);
};
static JSValue input_class_add_joy_mapping(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&Input::add_joy_mapping, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue input_class_remove_joy_mapping(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&Input::remove_joy_mapping, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue input_class_is_joy_known(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Input::is_joy_known, ctx, this_val, argc, argv);
};
static JSValue input_class_get_joy_axis(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Input::get_joy_axis, ctx, this_val, argc, argv);
};
static JSValue input_class_get_joy_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Input::get_joy_name, ctx, this_val, argc, argv);
};
static JSValue input_class_get_joy_guid(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Input::get_joy_guid, ctx, this_val, argc, argv);
};
static JSValue input_class_get_joy_info(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Input::get_joy_info, ctx, this_val, argc, argv);
};
static JSValue input_class_should_ignore_device(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Input::should_ignore_device, ctx, this_val, argc, argv);
};
static JSValue input_class_get_connected_joypads(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Input::get_connected_joypads, ctx, this_val, argc, argv);
};
static JSValue input_class_get_joy_vibration_strength(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Input::get_joy_vibration_strength, ctx, this_val, argc, argv);
};
static JSValue input_class_get_joy_vibration_duration(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Input::get_joy_vibration_duration, ctx, this_val, argc, argv);
};
static JSValue input_class_start_joy_vibration(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&Input::start_joy_vibration, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue input_class_stop_joy_vibration(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&Input::stop_joy_vibration, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue input_class_vibrate_handheld(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&Input::vibrate_handheld, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue input_class_get_gravity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Input::get_gravity, ctx, this_val, argc, argv);
};
static JSValue input_class_get_accelerometer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Input::get_accelerometer, ctx, this_val, argc, argv);
};
static JSValue input_class_get_magnetometer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Input::get_magnetometer, ctx, this_val, argc, argv);
};
static JSValue input_class_get_gyroscope(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Input::get_gyroscope, ctx, this_val, argc, argv);
};
static JSValue input_class_set_gravity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&Input::set_gravity, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue input_class_set_accelerometer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&Input::set_accelerometer, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue input_class_set_magnetometer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&Input::set_magnetometer, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue input_class_set_gyroscope(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&Input::set_gyroscope, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue input_class_get_last_mouse_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Input::get_last_mouse_velocity, ctx, this_val, argc, argv);
};
static JSValue input_class_get_last_mouse_screen_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Input::get_last_mouse_screen_velocity, ctx, this_val, argc, argv);
};
static JSValue input_class_get_mouse_button_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Input::get_mouse_button_mask, ctx, this_val, argc, argv);
};
static JSValue input_class_set_mouse_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&Input::set_mouse_mode, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue input_class_get_mouse_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Input::get_mouse_mode, ctx, this_val, argc, argv);
};
static JSValue input_class_warp_mouse(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&Input::warp_mouse, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue input_class_action_press(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&Input::action_press, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue input_class_action_release(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&Input::action_release, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue input_class_set_default_cursor_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&Input::set_default_cursor_shape, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue input_class_get_current_cursor_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Input::get_current_cursor_shape, ctx, this_val, argc, argv);
};
static JSValue input_class_set_custom_mouse_cursor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&Input::set_custom_mouse_cursor, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue input_class_parse_input_event(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&Input::parse_input_event, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue input_class_set_use_accumulated_input(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&Input::set_use_accumulated_input, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue input_class_is_using_accumulated_input(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Input::is_using_accumulated_input, ctx, this_val, argc, argv);
};
static JSValue input_class_flush_buffered_events(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&Input::flush_buffered_events, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue input_class_set_emulate_mouse_from_touch(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&Input::set_emulate_mouse_from_touch, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue input_class_is_emulating_mouse_from_touch(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Input::is_emulating_mouse_from_touch, ctx, this_val, argc, argv);
};
static JSValue input_class_set_emulate_touch_from_mouse(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&Input::set_emulate_touch_from_mouse, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue input_class_is_emulating_touch_from_mouse(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Input::is_emulating_touch_from_mouse, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry input_class_proto_funcs[] = {
	JS_CFUNC_DEF("is_anything_pressed", 0, &input_class_is_anything_pressed),
	JS_CFUNC_DEF("is_key_pressed", 1, &input_class_is_key_pressed),
	JS_CFUNC_DEF("is_physical_key_pressed", 1, &input_class_is_physical_key_pressed),
	JS_CFUNC_DEF("is_key_label_pressed", 1, &input_class_is_key_label_pressed),
	JS_CFUNC_DEF("is_mouse_button_pressed", 1, &input_class_is_mouse_button_pressed),
	JS_CFUNC_DEF("is_joy_button_pressed", 2, &input_class_is_joy_button_pressed),
	JS_CFUNC_DEF("is_action_pressed", 2, &input_class_is_action_pressed),
	JS_CFUNC_DEF("is_action_just_pressed", 2, &input_class_is_action_just_pressed),
	JS_CFUNC_DEF("is_action_just_released", 2, &input_class_is_action_just_released),
	JS_CFUNC_DEF("is_action_just_pressed_by_event", 3, &input_class_is_action_just_pressed_by_event),
	JS_CFUNC_DEF("is_action_just_released_by_event", 3, &input_class_is_action_just_released_by_event),
	JS_CFUNC_DEF("get_action_strength", 2, &input_class_get_action_strength),
	JS_CFUNC_DEF("get_action_raw_strength", 2, &input_class_get_action_raw_strength),
	JS_CFUNC_DEF("get_axis", 2, &input_class_get_axis),
	JS_CFUNC_DEF("get_vector", 5, &input_class_get_vector),
	JS_CFUNC_DEF("add_joy_mapping", 2, &input_class_add_joy_mapping),
	JS_CFUNC_DEF("remove_joy_mapping", 1, &input_class_remove_joy_mapping),
	JS_CFUNC_DEF("is_joy_known", 1, &input_class_is_joy_known),
	JS_CFUNC_DEF("get_joy_axis", 2, &input_class_get_joy_axis),
	JS_CFUNC_DEF("get_joy_name", 1, &input_class_get_joy_name),
	JS_CFUNC_DEF("get_joy_guid", 1, &input_class_get_joy_guid),
	JS_CFUNC_DEF("get_joy_info", 1, &input_class_get_joy_info),
	JS_CFUNC_DEF("should_ignore_device", 2, &input_class_should_ignore_device),
	JS_CFUNC_DEF("get_connected_joypads", 0, &input_class_get_connected_joypads),
	JS_CFUNC_DEF("get_joy_vibration_strength", 1, &input_class_get_joy_vibration_strength),
	JS_CFUNC_DEF("get_joy_vibration_duration", 1, &input_class_get_joy_vibration_duration),
	JS_CFUNC_DEF("start_joy_vibration", 4, &input_class_start_joy_vibration),
	JS_CFUNC_DEF("stop_joy_vibration", 1, &input_class_stop_joy_vibration),
	JS_CFUNC_DEF("vibrate_handheld", 2, &input_class_vibrate_handheld),
	JS_CFUNC_DEF("get_gravity", 0, &input_class_get_gravity),
	JS_CFUNC_DEF("get_accelerometer", 0, &input_class_get_accelerometer),
	JS_CFUNC_DEF("get_magnetometer", 0, &input_class_get_magnetometer),
	JS_CFUNC_DEF("get_gyroscope", 0, &input_class_get_gyroscope),
	JS_CFUNC_DEF("set_gravity", 1, &input_class_set_gravity),
	JS_CFUNC_DEF("set_accelerometer", 1, &input_class_set_accelerometer),
	JS_CFUNC_DEF("set_magnetometer", 1, &input_class_set_magnetometer),
	JS_CFUNC_DEF("set_gyroscope", 1, &input_class_set_gyroscope),
	JS_CFUNC_DEF("get_last_mouse_velocity", 0, &input_class_get_last_mouse_velocity),
	JS_CFUNC_DEF("get_last_mouse_screen_velocity", 0, &input_class_get_last_mouse_screen_velocity),
	JS_CFUNC_DEF("get_mouse_button_mask", 0, &input_class_get_mouse_button_mask),
	JS_CFUNC_DEF("set_mouse_mode", 1, &input_class_set_mouse_mode),
	JS_CFUNC_DEF("get_mouse_mode", 0, &input_class_get_mouse_mode),
	JS_CFUNC_DEF("warp_mouse", 1, &input_class_warp_mouse),
	JS_CFUNC_DEF("action_press", 2, &input_class_action_press),
	JS_CFUNC_DEF("action_release", 1, &input_class_action_release),
	JS_CFUNC_DEF("set_default_cursor_shape", 1, &input_class_set_default_cursor_shape),
	JS_CFUNC_DEF("get_current_cursor_shape", 0, &input_class_get_current_cursor_shape),
	JS_CFUNC_DEF("set_custom_mouse_cursor", 3, &input_class_set_custom_mouse_cursor),
	JS_CFUNC_DEF("parse_input_event", 1, &input_class_parse_input_event),
	JS_CFUNC_DEF("set_use_accumulated_input", 1, &input_class_set_use_accumulated_input),
	JS_CFUNC_DEF("is_using_accumulated_input", 0, &input_class_is_using_accumulated_input),
	JS_CFUNC_DEF("flush_buffered_events", 0, &input_class_flush_buffered_events),
	JS_CFUNC_DEF("set_emulate_mouse_from_touch", 1, &input_class_set_emulate_mouse_from_touch),
	JS_CFUNC_DEF("is_emulating_mouse_from_touch", 0, &input_class_is_emulating_mouse_from_touch),
	JS_CFUNC_DEF("set_emulate_touch_from_mouse", 1, &input_class_set_emulate_touch_from_mouse),
	JS_CFUNC_DEF("is_emulating_touch_from_mouse", 0, &input_class_is_emulating_touch_from_mouse),
};




static int js_input_class_init(JSContext *ctx) {
	JSClassID class_id = classes["Input"];
	classes["Input"] = class_id;
	JS_NewClass(JS_GetRuntime(ctx), class_id, &input_class_def);

	JSValue proto = JS_NewObject(ctx);
	JSValue base_class = JS_GetClassProto(ctx, classes["Object"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	JS_SetPropertyFunctionList(ctx, proto, input_class_proto_funcs, _countof(input_class_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, input_class_constructor, "_Input", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);


	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "Input", ctor);
	JS_FreeValue(ctx, global);
	return 0;
}

void register_input() {
	js_input_class_init(js_context());
}