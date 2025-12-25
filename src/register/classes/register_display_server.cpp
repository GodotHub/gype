#include "register/classes/register_classes.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/str_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/image.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/display_server.hpp>


using namespace godot;

static void display_server_class_finalizer(JSRuntime *rt, JSValue val) {
}

static JSClassDef display_server_class_def = {
	"_DisplayServer",
	display_server_class_finalizer
};

static JSValue display_server_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["DisplayServer"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);
	if (JS_IsException(obj))
		return obj;

	DisplayServer *display_server_class = DisplayServer::get_singleton();
	if (!display_server_class) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, display_server_class);
	return obj;
}

static JSValue display_server_class_has_feature(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::has_feature, ctx, this_val, argc, argv);
};
static JSValue display_server_class_get_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::get_name, ctx, this_val, argc, argv);
};
static JSValue display_server_class_help_set_search_callbacks(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::help_set_search_callbacks, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_global_menu_set_popup_callbacks(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::global_menu_set_popup_callbacks, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_global_menu_add_submenu_item(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&DisplayServer::global_menu_add_submenu_item, ctx, this_val, argc, argv);
};
static JSValue display_server_class_global_menu_add_item(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&DisplayServer::global_menu_add_item, ctx, this_val, argc, argv);
};
static JSValue display_server_class_global_menu_add_check_item(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&DisplayServer::global_menu_add_check_item, ctx, this_val, argc, argv);
};
static JSValue display_server_class_global_menu_add_icon_item(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&DisplayServer::global_menu_add_icon_item, ctx, this_val, argc, argv);
};
static JSValue display_server_class_global_menu_add_icon_check_item(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&DisplayServer::global_menu_add_icon_check_item, ctx, this_val, argc, argv);
};
static JSValue display_server_class_global_menu_add_radio_check_item(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&DisplayServer::global_menu_add_radio_check_item, ctx, this_val, argc, argv);
};
static JSValue display_server_class_global_menu_add_icon_radio_check_item(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&DisplayServer::global_menu_add_icon_radio_check_item, ctx, this_val, argc, argv);
};
static JSValue display_server_class_global_menu_add_multistate_item(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&DisplayServer::global_menu_add_multistate_item, ctx, this_val, argc, argv);
};
static JSValue display_server_class_global_menu_add_separator(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&DisplayServer::global_menu_add_separator, ctx, this_val, argc, argv);
};
static JSValue display_server_class_global_menu_get_item_index_from_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::global_menu_get_item_index_from_text, ctx, this_val, argc, argv);
};
static JSValue display_server_class_global_menu_get_item_index_from_tag(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::global_menu_get_item_index_from_tag, ctx, this_val, argc, argv);
};
static JSValue display_server_class_global_menu_is_item_checked(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::global_menu_is_item_checked, ctx, this_val, argc, argv);
};
static JSValue display_server_class_global_menu_is_item_checkable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::global_menu_is_item_checkable, ctx, this_val, argc, argv);
};
static JSValue display_server_class_global_menu_is_item_radio_checkable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::global_menu_is_item_radio_checkable, ctx, this_val, argc, argv);
};
static JSValue display_server_class_global_menu_get_item_callback(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::global_menu_get_item_callback, ctx, this_val, argc, argv);
};
static JSValue display_server_class_global_menu_get_item_key_callback(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::global_menu_get_item_key_callback, ctx, this_val, argc, argv);
};
static JSValue display_server_class_global_menu_get_item_tag(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::global_menu_get_item_tag, ctx, this_val, argc, argv);
};
static JSValue display_server_class_global_menu_get_item_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::global_menu_get_item_text, ctx, this_val, argc, argv);
};
static JSValue display_server_class_global_menu_get_item_submenu(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::global_menu_get_item_submenu, ctx, this_val, argc, argv);
};
static JSValue display_server_class_global_menu_get_item_accelerator(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::global_menu_get_item_accelerator, ctx, this_val, argc, argv);
};
static JSValue display_server_class_global_menu_is_item_disabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::global_menu_is_item_disabled, ctx, this_val, argc, argv);
};
static JSValue display_server_class_global_menu_is_item_hidden(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::global_menu_is_item_hidden, ctx, this_val, argc, argv);
};
static JSValue display_server_class_global_menu_get_item_tooltip(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::global_menu_get_item_tooltip, ctx, this_val, argc, argv);
};
static JSValue display_server_class_global_menu_get_item_state(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::global_menu_get_item_state, ctx, this_val, argc, argv);
};
static JSValue display_server_class_global_menu_get_item_max_states(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::global_menu_get_item_max_states, ctx, this_val, argc, argv);
};
static JSValue display_server_class_global_menu_get_item_icon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::global_menu_get_item_icon, ctx, this_val, argc, argv);
};
static JSValue display_server_class_global_menu_get_item_indentation_level(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::global_menu_get_item_indentation_level, ctx, this_val, argc, argv);
};
static JSValue display_server_class_global_menu_set_item_checked(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::global_menu_set_item_checked, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_global_menu_set_item_checkable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::global_menu_set_item_checkable, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_global_menu_set_item_radio_checkable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::global_menu_set_item_radio_checkable, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_global_menu_set_item_callback(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::global_menu_set_item_callback, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_global_menu_set_item_hover_callbacks(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::global_menu_set_item_hover_callbacks, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_global_menu_set_item_key_callback(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::global_menu_set_item_key_callback, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_global_menu_set_item_tag(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::global_menu_set_item_tag, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_global_menu_set_item_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::global_menu_set_item_text, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_global_menu_set_item_submenu(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::global_menu_set_item_submenu, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_global_menu_set_item_accelerator(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::global_menu_set_item_accelerator, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_global_menu_set_item_disabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::global_menu_set_item_disabled, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_global_menu_set_item_hidden(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::global_menu_set_item_hidden, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_global_menu_set_item_tooltip(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::global_menu_set_item_tooltip, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_global_menu_set_item_state(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::global_menu_set_item_state, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_global_menu_set_item_max_states(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::global_menu_set_item_max_states, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_global_menu_set_item_icon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::global_menu_set_item_icon, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_global_menu_set_item_indentation_level(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::global_menu_set_item_indentation_level, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_global_menu_get_item_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::global_menu_get_item_count, ctx, this_val, argc, argv);
};
static JSValue display_server_class_global_menu_remove_item(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::global_menu_remove_item, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_global_menu_clear(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::global_menu_clear, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_global_menu_get_system_menu_roots(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::global_menu_get_system_menu_roots, ctx, this_val, argc, argv);
};
static JSValue display_server_class_tts_is_speaking(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::tts_is_speaking, ctx, this_val, argc, argv);
};
static JSValue display_server_class_tts_is_paused(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::tts_is_paused, ctx, this_val, argc, argv);
};
static JSValue display_server_class_tts_get_voices(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::tts_get_voices, ctx, this_val, argc, argv);
};
static JSValue display_server_class_tts_get_voices_for_language(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::tts_get_voices_for_language, ctx, this_val, argc, argv);
};
static JSValue display_server_class_tts_speak(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::tts_speak, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_tts_pause(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::tts_pause, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_tts_resume(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::tts_resume, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_tts_stop(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::tts_stop, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_tts_set_utterance_callback(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::tts_set_utterance_callback, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_is_dark_mode_supported(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::is_dark_mode_supported, ctx, this_val, argc, argv);
};
static JSValue display_server_class_is_dark_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::is_dark_mode, ctx, this_val, argc, argv);
};
static JSValue display_server_class_get_accent_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::get_accent_color, ctx, this_val, argc, argv);
};
static JSValue display_server_class_get_base_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::get_base_color, ctx, this_val, argc, argv);
};
static JSValue display_server_class_set_system_theme_change_callback(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::set_system_theme_change_callback, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_mouse_set_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::mouse_set_mode, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_mouse_get_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::mouse_get_mode, ctx, this_val, argc, argv);
};
static JSValue display_server_class_warp_mouse(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::warp_mouse, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_mouse_get_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::mouse_get_position, ctx, this_val, argc, argv);
};
static JSValue display_server_class_mouse_get_button_state(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::mouse_get_button_state, ctx, this_val, argc, argv);
};
static JSValue display_server_class_clipboard_set(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::clipboard_set, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_clipboard_get(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::clipboard_get, ctx, this_val, argc, argv);
};
static JSValue display_server_class_clipboard_get_image(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::clipboard_get_image, ctx, this_val, argc, argv);
};
static JSValue display_server_class_clipboard_has(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::clipboard_has, ctx, this_val, argc, argv);
};
static JSValue display_server_class_clipboard_has_image(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::clipboard_has_image, ctx, this_val, argc, argv);
};
static JSValue display_server_class_clipboard_set_primary(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::clipboard_set_primary, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_clipboard_get_primary(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::clipboard_get_primary, ctx, this_val, argc, argv);
};
static JSValue display_server_class_get_display_cutouts(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::get_display_cutouts, ctx, this_val, argc, argv);
};
static JSValue display_server_class_get_display_safe_area(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::get_display_safe_area, ctx, this_val, argc, argv);
};
static JSValue display_server_class_get_screen_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::get_screen_count, ctx, this_val, argc, argv);
};
static JSValue display_server_class_get_primary_screen(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::get_primary_screen, ctx, this_val, argc, argv);
};
static JSValue display_server_class_get_keyboard_focus_screen(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::get_keyboard_focus_screen, ctx, this_val, argc, argv);
};
static JSValue display_server_class_get_screen_from_rect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::get_screen_from_rect, ctx, this_val, argc, argv);
};
static JSValue display_server_class_screen_get_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::screen_get_position, ctx, this_val, argc, argv);
};
static JSValue display_server_class_screen_get_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::screen_get_size, ctx, this_val, argc, argv);
};
static JSValue display_server_class_screen_get_usable_rect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::screen_get_usable_rect, ctx, this_val, argc, argv);
};
static JSValue display_server_class_screen_get_dpi(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::screen_get_dpi, ctx, this_val, argc, argv);
};
static JSValue display_server_class_screen_get_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::screen_get_scale, ctx, this_val, argc, argv);
};
static JSValue display_server_class_is_touchscreen_available(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::is_touchscreen_available, ctx, this_val, argc, argv);
};
static JSValue display_server_class_screen_get_max_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::screen_get_max_scale, ctx, this_val, argc, argv);
};
static JSValue display_server_class_screen_get_refresh_rate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::screen_get_refresh_rate, ctx, this_val, argc, argv);
};
static JSValue display_server_class_screen_get_pixel(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::screen_get_pixel, ctx, this_val, argc, argv);
};
static JSValue display_server_class_screen_get_image(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::screen_get_image, ctx, this_val, argc, argv);
};
static JSValue display_server_class_screen_get_image_rect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::screen_get_image_rect, ctx, this_val, argc, argv);
};
static JSValue display_server_class_screen_set_orientation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::screen_set_orientation, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_screen_get_orientation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::screen_get_orientation, ctx, this_val, argc, argv);
};
static JSValue display_server_class_screen_set_keep_on(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::screen_set_keep_on, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_screen_is_kept_on(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::screen_is_kept_on, ctx, this_val, argc, argv);
};
static JSValue display_server_class_get_window_list(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::get_window_list, ctx, this_val, argc, argv);
};
static JSValue display_server_class_get_window_at_screen_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::get_window_at_screen_position, ctx, this_val, argc, argv);
};
static JSValue display_server_class_window_get_native_handle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::window_get_native_handle, ctx, this_val, argc, argv);
};
static JSValue display_server_class_window_get_active_popup(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::window_get_active_popup, ctx, this_val, argc, argv);
};
static JSValue display_server_class_window_set_popup_safe_rect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::window_set_popup_safe_rect, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_window_get_popup_safe_rect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::window_get_popup_safe_rect, ctx, this_val, argc, argv);
};
static JSValue display_server_class_window_set_title(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::window_set_title, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_window_get_title_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::window_get_title_size, ctx, this_val, argc, argv);
};
static JSValue display_server_class_window_set_mouse_passthrough(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::window_set_mouse_passthrough, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_window_get_current_screen(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::window_get_current_screen, ctx, this_val, argc, argv);
};
static JSValue display_server_class_window_set_current_screen(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::window_set_current_screen, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_window_get_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::window_get_position, ctx, this_val, argc, argv);
};
static JSValue display_server_class_window_get_position_with_decorations(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::window_get_position_with_decorations, ctx, this_val, argc, argv);
};
static JSValue display_server_class_window_set_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::window_set_position, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_window_get_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::window_get_size, ctx, this_val, argc, argv);
};
static JSValue display_server_class_window_set_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::window_set_size, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_window_set_rect_changed_callback(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::window_set_rect_changed_callback, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_window_set_window_event_callback(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::window_set_window_event_callback, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_window_set_input_event_callback(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::window_set_input_event_callback, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_window_set_input_text_callback(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::window_set_input_text_callback, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_window_set_drop_files_callback(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::window_set_drop_files_callback, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_window_get_attached_instance_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::window_get_attached_instance_id, ctx, this_val, argc, argv);
};
static JSValue display_server_class_window_get_max_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::window_get_max_size, ctx, this_val, argc, argv);
};
static JSValue display_server_class_window_set_max_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::window_set_max_size, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_window_get_min_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::window_get_min_size, ctx, this_val, argc, argv);
};
static JSValue display_server_class_window_set_min_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::window_set_min_size, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_window_get_size_with_decorations(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::window_get_size_with_decorations, ctx, this_val, argc, argv);
};
static JSValue display_server_class_window_get_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::window_get_mode, ctx, this_val, argc, argv);
};
static JSValue display_server_class_window_set_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::window_set_mode, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_window_set_flag(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::window_set_flag, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_window_get_flag(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::window_get_flag, ctx, this_val, argc, argv);
};
static JSValue display_server_class_window_set_window_buttons_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::window_set_window_buttons_offset, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_window_get_safe_title_margins(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::window_get_safe_title_margins, ctx, this_val, argc, argv);
};
static JSValue display_server_class_window_request_attention(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::window_request_attention, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_window_move_to_foreground(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::window_move_to_foreground, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_window_is_focused(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::window_is_focused, ctx, this_val, argc, argv);
};
static JSValue display_server_class_window_can_draw(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::window_can_draw, ctx, this_val, argc, argv);
};
static JSValue display_server_class_window_set_transient(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::window_set_transient, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_window_set_exclusive(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::window_set_exclusive, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_window_set_ime_active(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::window_set_ime_active, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_window_set_ime_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::window_set_ime_position, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_window_set_vsync_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::window_set_vsync_mode, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_window_get_vsync_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::window_get_vsync_mode, ctx, this_val, argc, argv);
};
static JSValue display_server_class_window_is_maximize_allowed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::window_is_maximize_allowed, ctx, this_val, argc, argv);
};
static JSValue display_server_class_window_maximize_on_title_dbl_click(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::window_maximize_on_title_dbl_click, ctx, this_val, argc, argv);
};
static JSValue display_server_class_window_minimize_on_title_dbl_click(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::window_minimize_on_title_dbl_click, ctx, this_val, argc, argv);
};
static JSValue display_server_class_window_start_drag(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::window_start_drag, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_window_start_resize(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::window_start_resize, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_should_increase_contrast(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::accessibility_should_increase_contrast, ctx, this_val, argc, argv);
};
static JSValue display_server_class_accessibility_should_reduce_animation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::accessibility_should_reduce_animation, ctx, this_val, argc, argv);
};
static JSValue display_server_class_accessibility_should_reduce_transparency(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::accessibility_should_reduce_transparency, ctx, this_val, argc, argv);
};
static JSValue display_server_class_accessibility_screen_reader_active(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::accessibility_screen_reader_active, ctx, this_val, argc, argv);
};
static JSValue display_server_class_accessibility_create_element(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&DisplayServer::accessibility_create_element, ctx, this_val, argc, argv);
};
static JSValue display_server_class_accessibility_create_sub_element(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&DisplayServer::accessibility_create_sub_element, ctx, this_val, argc, argv);
};
static JSValue display_server_class_accessibility_create_sub_text_edit_elements(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&DisplayServer::accessibility_create_sub_text_edit_elements, ctx, this_val, argc, argv);
};
static JSValue display_server_class_accessibility_has_element(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::accessibility_has_element, ctx, this_val, argc, argv);
};
static JSValue display_server_class_accessibility_free_element(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_free_element, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_element_set_meta(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_element_set_meta, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_element_get_meta(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::accessibility_element_get_meta, ctx, this_val, argc, argv);
};
static JSValue display_server_class_accessibility_set_window_rect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_set_window_rect, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_set_window_focused(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_set_window_focused, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_set_focus(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_focus, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_get_window_root(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::accessibility_get_window_root, ctx, this_val, argc, argv);
};
static JSValue display_server_class_accessibility_update_set_role(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_role, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_set_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_name, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_set_extra_info(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_extra_info, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_set_description(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_description, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_set_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_value, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_set_tooltip(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_tooltip, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_set_bounds(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_bounds, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_set_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_transform, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_add_child(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_add_child, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_add_related_controls(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_add_related_controls, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_add_related_details(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_add_related_details, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_add_related_described_by(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_add_related_described_by, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_add_related_flow_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_add_related_flow_to, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_add_related_labeled_by(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_add_related_labeled_by, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_add_related_radio_group(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_add_related_radio_group, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_set_active_descendant(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_active_descendant, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_set_next_on_line(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_next_on_line, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_set_previous_on_line(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_previous_on_line, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_set_member_of(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_member_of, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_set_in_page_link_target(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_in_page_link_target, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_set_error_message(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_error_message, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_set_live(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_live, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_add_action(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_add_action, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_add_custom_action(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_add_custom_action, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_set_table_row_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_table_row_count, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_set_table_column_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_table_column_count, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_set_table_row_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_table_row_index, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_set_table_column_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_table_column_index, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_set_table_cell_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_table_cell_position, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_set_table_cell_span(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_table_cell_span, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_set_list_item_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_list_item_count, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_set_list_item_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_list_item_index, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_set_list_item_level(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_list_item_level, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_set_list_item_selected(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_list_item_selected, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_set_list_item_expanded(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_list_item_expanded, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_set_popup_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_popup_type, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_set_checked(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_checked, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_set_num_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_num_value, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_set_num_range(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_num_range, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_set_num_step(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_num_step, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_set_num_jump(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_num_jump, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_set_scroll_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_scroll_x, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_set_scroll_x_range(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_scroll_x_range, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_set_scroll_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_scroll_y, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_set_scroll_y_range(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_scroll_y_range, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_set_text_decorations(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_text_decorations, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_set_text_align(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_text_align, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_set_text_selection(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_text_selection, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_set_flag(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_flag, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_set_classname(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_classname, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_set_placeholder(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_placeholder, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_set_language(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_language, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_set_text_orientation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_text_orientation, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_set_list_orientation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_list_orientation, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_set_shortcut(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_shortcut, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_set_url(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_url, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_set_role_description(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_role_description, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_set_state_description(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_state_description, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_set_color_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_color_value, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_set_background_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_background_color, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_accessibility_update_set_foreground_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::accessibility_update_set_foreground_color, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_ime_get_selection(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::ime_get_selection, ctx, this_val, argc, argv);
};
static JSValue display_server_class_ime_get_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::ime_get_text, ctx, this_val, argc, argv);
};
static JSValue display_server_class_virtual_keyboard_show(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::virtual_keyboard_show, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_virtual_keyboard_hide(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::virtual_keyboard_hide, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_virtual_keyboard_get_height(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::virtual_keyboard_get_height, ctx, this_val, argc, argv);
};
static JSValue display_server_class_has_hardware_keyboard(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::has_hardware_keyboard, ctx, this_val, argc, argv);
};
static JSValue display_server_class_set_hardware_keyboard_connection_change_callback(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::set_hardware_keyboard_connection_change_callback, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_cursor_set_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::cursor_set_shape, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_cursor_get_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::cursor_get_shape, ctx, this_val, argc, argv);
};
static JSValue display_server_class_cursor_set_custom_image(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::cursor_set_custom_image, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_get_swap_cancel_ok(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&DisplayServer::get_swap_cancel_ok, ctx, this_val, argc, argv);
};
static JSValue display_server_class_enable_for_stealing_focus(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::enable_for_stealing_focus, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_dialog_show(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&DisplayServer::dialog_show, ctx, this_val, argc, argv);
};
static JSValue display_server_class_dialog_input_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&DisplayServer::dialog_input_text, ctx, this_val, argc, argv);
};
static JSValue display_server_class_file_dialog_show(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&DisplayServer::file_dialog_show, ctx, this_val, argc, argv);
};
static JSValue display_server_class_file_dialog_with_options_show(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&DisplayServer::file_dialog_with_options_show, ctx, this_val, argc, argv);
};
static JSValue display_server_class_beep(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_const_method_no_ret(&DisplayServer::beep, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_keyboard_get_layout_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::keyboard_get_layout_count, ctx, this_val, argc, argv);
};
static JSValue display_server_class_keyboard_get_current_layout(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::keyboard_get_current_layout, ctx, this_val, argc, argv);
};
static JSValue display_server_class_keyboard_set_current_layout(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::keyboard_set_current_layout, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_keyboard_get_layout_language(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::keyboard_get_layout_language, ctx, this_val, argc, argv);
};
static JSValue display_server_class_keyboard_get_layout_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::keyboard_get_layout_name, ctx, this_val, argc, argv);
};
static JSValue display_server_class_keyboard_get_keycode_from_physical(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::keyboard_get_keycode_from_physical, ctx, this_val, argc, argv);
};
static JSValue display_server_class_keyboard_get_label_from_physical(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::keyboard_get_label_from_physical, ctx, this_val, argc, argv);
};
static JSValue display_server_class_show_emoji_and_symbol_picker(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_const_method_no_ret(&DisplayServer::show_emoji_and_symbol_picker, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_color_picker(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&DisplayServer::color_picker, ctx, this_val, argc, argv);
};
static JSValue display_server_class_process_events(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::process_events, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_force_process_and_drop_events(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::force_process_and_drop_events, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_set_native_icon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::set_native_icon, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_set_icon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::set_icon, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_create_status_indicator(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&DisplayServer::create_status_indicator, ctx, this_val, argc, argv);
};
static JSValue display_server_class_status_indicator_set_icon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::status_indicator_set_icon, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_status_indicator_set_tooltip(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::status_indicator_set_tooltip, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_status_indicator_set_menu(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::status_indicator_set_menu, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_status_indicator_set_callback(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::status_indicator_set_callback, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_status_indicator_get_rect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::status_indicator_get_rect, ctx, this_val, argc, argv);
};
static JSValue display_server_class_delete_status_indicator(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::delete_status_indicator, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_tablet_get_driver_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::tablet_get_driver_count, ctx, this_val, argc, argv);
};
static JSValue display_server_class_tablet_get_driver_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::tablet_get_driver_name, ctx, this_val, argc, argv);
};
static JSValue display_server_class_tablet_get_current_driver(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::tablet_get_current_driver, ctx, this_val, argc, argv);
};
static JSValue display_server_class_tablet_set_current_driver(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::tablet_set_current_driver, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_is_window_transparency_available(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::is_window_transparency_available, ctx, this_val, argc, argv);
};
static JSValue display_server_class_register_additional_output(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::register_additional_output, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_unregister_additional_output(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&DisplayServer::unregister_additional_output, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue display_server_class_has_additional_outputs(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&DisplayServer::has_additional_outputs, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry display_server_class_proto_funcs[] = {
	JS_CFUNC_DEF("has_feature", 1, &display_server_class_has_feature),
	JS_CFUNC_DEF("get_name", 0, &display_server_class_get_name),
	JS_CFUNC_DEF("help_set_search_callbacks", 2, &display_server_class_help_set_search_callbacks),
	JS_CFUNC_DEF("global_menu_set_popup_callbacks", 3, &display_server_class_global_menu_set_popup_callbacks),
	JS_CFUNC_DEF("global_menu_add_submenu_item", 4, &display_server_class_global_menu_add_submenu_item),
	JS_CFUNC_DEF("global_menu_add_item", 7, &display_server_class_global_menu_add_item),
	JS_CFUNC_DEF("global_menu_add_check_item", 7, &display_server_class_global_menu_add_check_item),
	JS_CFUNC_DEF("global_menu_add_icon_item", 8, &display_server_class_global_menu_add_icon_item),
	JS_CFUNC_DEF("global_menu_add_icon_check_item", 8, &display_server_class_global_menu_add_icon_check_item),
	JS_CFUNC_DEF("global_menu_add_radio_check_item", 7, &display_server_class_global_menu_add_radio_check_item),
	JS_CFUNC_DEF("global_menu_add_icon_radio_check_item", 8, &display_server_class_global_menu_add_icon_radio_check_item),
	JS_CFUNC_DEF("global_menu_add_multistate_item", 9, &display_server_class_global_menu_add_multistate_item),
	JS_CFUNC_DEF("global_menu_add_separator", 2, &display_server_class_global_menu_add_separator),
	JS_CFUNC_DEF("global_menu_get_item_index_from_text", 2, &display_server_class_global_menu_get_item_index_from_text),
	JS_CFUNC_DEF("global_menu_get_item_index_from_tag", 2, &display_server_class_global_menu_get_item_index_from_tag),
	JS_CFUNC_DEF("global_menu_is_item_checked", 2, &display_server_class_global_menu_is_item_checked),
	JS_CFUNC_DEF("global_menu_is_item_checkable", 2, &display_server_class_global_menu_is_item_checkable),
	JS_CFUNC_DEF("global_menu_is_item_radio_checkable", 2, &display_server_class_global_menu_is_item_radio_checkable),
	JS_CFUNC_DEF("global_menu_get_item_callback", 2, &display_server_class_global_menu_get_item_callback),
	JS_CFUNC_DEF("global_menu_get_item_key_callback", 2, &display_server_class_global_menu_get_item_key_callback),
	JS_CFUNC_DEF("global_menu_get_item_tag", 2, &display_server_class_global_menu_get_item_tag),
	JS_CFUNC_DEF("global_menu_get_item_text", 2, &display_server_class_global_menu_get_item_text),
	JS_CFUNC_DEF("global_menu_get_item_submenu", 2, &display_server_class_global_menu_get_item_submenu),
	JS_CFUNC_DEF("global_menu_get_item_accelerator", 2, &display_server_class_global_menu_get_item_accelerator),
	JS_CFUNC_DEF("global_menu_is_item_disabled", 2, &display_server_class_global_menu_is_item_disabled),
	JS_CFUNC_DEF("global_menu_is_item_hidden", 2, &display_server_class_global_menu_is_item_hidden),
	JS_CFUNC_DEF("global_menu_get_item_tooltip", 2, &display_server_class_global_menu_get_item_tooltip),
	JS_CFUNC_DEF("global_menu_get_item_state", 2, &display_server_class_global_menu_get_item_state),
	JS_CFUNC_DEF("global_menu_get_item_max_states", 2, &display_server_class_global_menu_get_item_max_states),
	JS_CFUNC_DEF("global_menu_get_item_icon", 2, &display_server_class_global_menu_get_item_icon),
	JS_CFUNC_DEF("global_menu_get_item_indentation_level", 2, &display_server_class_global_menu_get_item_indentation_level),
	JS_CFUNC_DEF("global_menu_set_item_checked", 3, &display_server_class_global_menu_set_item_checked),
	JS_CFUNC_DEF("global_menu_set_item_checkable", 3, &display_server_class_global_menu_set_item_checkable),
	JS_CFUNC_DEF("global_menu_set_item_radio_checkable", 3, &display_server_class_global_menu_set_item_radio_checkable),
	JS_CFUNC_DEF("global_menu_set_item_callback", 3, &display_server_class_global_menu_set_item_callback),
	JS_CFUNC_DEF("global_menu_set_item_hover_callbacks", 3, &display_server_class_global_menu_set_item_hover_callbacks),
	JS_CFUNC_DEF("global_menu_set_item_key_callback", 3, &display_server_class_global_menu_set_item_key_callback),
	JS_CFUNC_DEF("global_menu_set_item_tag", 3, &display_server_class_global_menu_set_item_tag),
	JS_CFUNC_DEF("global_menu_set_item_text", 3, &display_server_class_global_menu_set_item_text),
	JS_CFUNC_DEF("global_menu_set_item_submenu", 3, &display_server_class_global_menu_set_item_submenu),
	JS_CFUNC_DEF("global_menu_set_item_accelerator", 3, &display_server_class_global_menu_set_item_accelerator),
	JS_CFUNC_DEF("global_menu_set_item_disabled", 3, &display_server_class_global_menu_set_item_disabled),
	JS_CFUNC_DEF("global_menu_set_item_hidden", 3, &display_server_class_global_menu_set_item_hidden),
	JS_CFUNC_DEF("global_menu_set_item_tooltip", 3, &display_server_class_global_menu_set_item_tooltip),
	JS_CFUNC_DEF("global_menu_set_item_state", 3, &display_server_class_global_menu_set_item_state),
	JS_CFUNC_DEF("global_menu_set_item_max_states", 3, &display_server_class_global_menu_set_item_max_states),
	JS_CFUNC_DEF("global_menu_set_item_icon", 3, &display_server_class_global_menu_set_item_icon),
	JS_CFUNC_DEF("global_menu_set_item_indentation_level", 3, &display_server_class_global_menu_set_item_indentation_level),
	JS_CFUNC_DEF("global_menu_get_item_count", 1, &display_server_class_global_menu_get_item_count),
	JS_CFUNC_DEF("global_menu_remove_item", 2, &display_server_class_global_menu_remove_item),
	JS_CFUNC_DEF("global_menu_clear", 1, &display_server_class_global_menu_clear),
	JS_CFUNC_DEF("global_menu_get_system_menu_roots", 0, &display_server_class_global_menu_get_system_menu_roots),
	JS_CFUNC_DEF("tts_is_speaking", 0, &display_server_class_tts_is_speaking),
	JS_CFUNC_DEF("tts_is_paused", 0, &display_server_class_tts_is_paused),
	JS_CFUNC_DEF("tts_get_voices", 0, &display_server_class_tts_get_voices),
	JS_CFUNC_DEF("tts_get_voices_for_language", 1, &display_server_class_tts_get_voices_for_language),
	JS_CFUNC_DEF("tts_speak", 7, &display_server_class_tts_speak),
	JS_CFUNC_DEF("tts_pause", 0, &display_server_class_tts_pause),
	JS_CFUNC_DEF("tts_resume", 0, &display_server_class_tts_resume),
	JS_CFUNC_DEF("tts_stop", 0, &display_server_class_tts_stop),
	JS_CFUNC_DEF("tts_set_utterance_callback", 2, &display_server_class_tts_set_utterance_callback),
	JS_CFUNC_DEF("is_dark_mode_supported", 0, &display_server_class_is_dark_mode_supported),
	JS_CFUNC_DEF("is_dark_mode", 0, &display_server_class_is_dark_mode),
	JS_CFUNC_DEF("get_accent_color", 0, &display_server_class_get_accent_color),
	JS_CFUNC_DEF("get_base_color", 0, &display_server_class_get_base_color),
	JS_CFUNC_DEF("set_system_theme_change_callback", 1, &display_server_class_set_system_theme_change_callback),
	JS_CFUNC_DEF("mouse_set_mode", 1, &display_server_class_mouse_set_mode),
	JS_CFUNC_DEF("mouse_get_mode", 0, &display_server_class_mouse_get_mode),
	JS_CFUNC_DEF("warp_mouse", 1, &display_server_class_warp_mouse),
	JS_CFUNC_DEF("mouse_get_position", 0, &display_server_class_mouse_get_position),
	JS_CFUNC_DEF("mouse_get_button_state", 0, &display_server_class_mouse_get_button_state),
	JS_CFUNC_DEF("clipboard_set", 1, &display_server_class_clipboard_set),
	JS_CFUNC_DEF("clipboard_get", 0, &display_server_class_clipboard_get),
	JS_CFUNC_DEF("clipboard_get_image", 0, &display_server_class_clipboard_get_image),
	JS_CFUNC_DEF("clipboard_has", 0, &display_server_class_clipboard_has),
	JS_CFUNC_DEF("clipboard_has_image", 0, &display_server_class_clipboard_has_image),
	JS_CFUNC_DEF("clipboard_set_primary", 1, &display_server_class_clipboard_set_primary),
	JS_CFUNC_DEF("clipboard_get_primary", 0, &display_server_class_clipboard_get_primary),
	JS_CFUNC_DEF("get_display_cutouts", 0, &display_server_class_get_display_cutouts),
	JS_CFUNC_DEF("get_display_safe_area", 0, &display_server_class_get_display_safe_area),
	JS_CFUNC_DEF("get_screen_count", 0, &display_server_class_get_screen_count),
	JS_CFUNC_DEF("get_primary_screen", 0, &display_server_class_get_primary_screen),
	JS_CFUNC_DEF("get_keyboard_focus_screen", 0, &display_server_class_get_keyboard_focus_screen),
	JS_CFUNC_DEF("get_screen_from_rect", 1, &display_server_class_get_screen_from_rect),
	JS_CFUNC_DEF("screen_get_position", 1, &display_server_class_screen_get_position),
	JS_CFUNC_DEF("screen_get_size", 1, &display_server_class_screen_get_size),
	JS_CFUNC_DEF("screen_get_usable_rect", 1, &display_server_class_screen_get_usable_rect),
	JS_CFUNC_DEF("screen_get_dpi", 1, &display_server_class_screen_get_dpi),
	JS_CFUNC_DEF("screen_get_scale", 1, &display_server_class_screen_get_scale),
	JS_CFUNC_DEF("is_touchscreen_available", 0, &display_server_class_is_touchscreen_available),
	JS_CFUNC_DEF("screen_get_max_scale", 0, &display_server_class_screen_get_max_scale),
	JS_CFUNC_DEF("screen_get_refresh_rate", 1, &display_server_class_screen_get_refresh_rate),
	JS_CFUNC_DEF("screen_get_pixel", 1, &display_server_class_screen_get_pixel),
	JS_CFUNC_DEF("screen_get_image", 1, &display_server_class_screen_get_image),
	JS_CFUNC_DEF("screen_get_image_rect", 1, &display_server_class_screen_get_image_rect),
	JS_CFUNC_DEF("screen_set_orientation", 2, &display_server_class_screen_set_orientation),
	JS_CFUNC_DEF("screen_get_orientation", 1, &display_server_class_screen_get_orientation),
	JS_CFUNC_DEF("screen_set_keep_on", 1, &display_server_class_screen_set_keep_on),
	JS_CFUNC_DEF("screen_is_kept_on", 0, &display_server_class_screen_is_kept_on),
	JS_CFUNC_DEF("get_window_list", 0, &display_server_class_get_window_list),
	JS_CFUNC_DEF("get_window_at_screen_position", 1, &display_server_class_get_window_at_screen_position),
	JS_CFUNC_DEF("window_get_native_handle", 2, &display_server_class_window_get_native_handle),
	JS_CFUNC_DEF("window_get_active_popup", 0, &display_server_class_window_get_active_popup),
	JS_CFUNC_DEF("window_set_popup_safe_rect", 2, &display_server_class_window_set_popup_safe_rect),
	JS_CFUNC_DEF("window_get_popup_safe_rect", 1, &display_server_class_window_get_popup_safe_rect),
	JS_CFUNC_DEF("window_set_title", 2, &display_server_class_window_set_title),
	JS_CFUNC_DEF("window_get_title_size", 2, &display_server_class_window_get_title_size),
	JS_CFUNC_DEF("window_set_mouse_passthrough", 2, &display_server_class_window_set_mouse_passthrough),
	JS_CFUNC_DEF("window_get_current_screen", 1, &display_server_class_window_get_current_screen),
	JS_CFUNC_DEF("window_set_current_screen", 2, &display_server_class_window_set_current_screen),
	JS_CFUNC_DEF("window_get_position", 1, &display_server_class_window_get_position),
	JS_CFUNC_DEF("window_get_position_with_decorations", 1, &display_server_class_window_get_position_with_decorations),
	JS_CFUNC_DEF("window_set_position", 2, &display_server_class_window_set_position),
	JS_CFUNC_DEF("window_get_size", 1, &display_server_class_window_get_size),
	JS_CFUNC_DEF("window_set_size", 2, &display_server_class_window_set_size),
	JS_CFUNC_DEF("window_set_rect_changed_callback", 2, &display_server_class_window_set_rect_changed_callback),
	JS_CFUNC_DEF("window_set_window_event_callback", 2, &display_server_class_window_set_window_event_callback),
	JS_CFUNC_DEF("window_set_input_event_callback", 2, &display_server_class_window_set_input_event_callback),
	JS_CFUNC_DEF("window_set_input_text_callback", 2, &display_server_class_window_set_input_text_callback),
	JS_CFUNC_DEF("window_set_drop_files_callback", 2, &display_server_class_window_set_drop_files_callback),
	JS_CFUNC_DEF("window_get_attached_instance_id", 1, &display_server_class_window_get_attached_instance_id),
	JS_CFUNC_DEF("window_get_max_size", 1, &display_server_class_window_get_max_size),
	JS_CFUNC_DEF("window_set_max_size", 2, &display_server_class_window_set_max_size),
	JS_CFUNC_DEF("window_get_min_size", 1, &display_server_class_window_get_min_size),
	JS_CFUNC_DEF("window_set_min_size", 2, &display_server_class_window_set_min_size),
	JS_CFUNC_DEF("window_get_size_with_decorations", 1, &display_server_class_window_get_size_with_decorations),
	JS_CFUNC_DEF("window_get_mode", 1, &display_server_class_window_get_mode),
	JS_CFUNC_DEF("window_set_mode", 2, &display_server_class_window_set_mode),
	JS_CFUNC_DEF("window_set_flag", 3, &display_server_class_window_set_flag),
	JS_CFUNC_DEF("window_get_flag", 2, &display_server_class_window_get_flag),
	JS_CFUNC_DEF("window_set_window_buttons_offset", 2, &display_server_class_window_set_window_buttons_offset),
	JS_CFUNC_DEF("window_get_safe_title_margins", 1, &display_server_class_window_get_safe_title_margins),
	JS_CFUNC_DEF("window_request_attention", 1, &display_server_class_window_request_attention),
	JS_CFUNC_DEF("window_move_to_foreground", 1, &display_server_class_window_move_to_foreground),
	JS_CFUNC_DEF("window_is_focused", 1, &display_server_class_window_is_focused),
	JS_CFUNC_DEF("window_can_draw", 1, &display_server_class_window_can_draw),
	JS_CFUNC_DEF("window_set_transient", 2, &display_server_class_window_set_transient),
	JS_CFUNC_DEF("window_set_exclusive", 2, &display_server_class_window_set_exclusive),
	JS_CFUNC_DEF("window_set_ime_active", 2, &display_server_class_window_set_ime_active),
	JS_CFUNC_DEF("window_set_ime_position", 2, &display_server_class_window_set_ime_position),
	JS_CFUNC_DEF("window_set_vsync_mode", 2, &display_server_class_window_set_vsync_mode),
	JS_CFUNC_DEF("window_get_vsync_mode", 1, &display_server_class_window_get_vsync_mode),
	JS_CFUNC_DEF("window_is_maximize_allowed", 1, &display_server_class_window_is_maximize_allowed),
	JS_CFUNC_DEF("window_maximize_on_title_dbl_click", 0, &display_server_class_window_maximize_on_title_dbl_click),
	JS_CFUNC_DEF("window_minimize_on_title_dbl_click", 0, &display_server_class_window_minimize_on_title_dbl_click),
	JS_CFUNC_DEF("window_start_drag", 1, &display_server_class_window_start_drag),
	JS_CFUNC_DEF("window_start_resize", 2, &display_server_class_window_start_resize),
	JS_CFUNC_DEF("accessibility_should_increase_contrast", 0, &display_server_class_accessibility_should_increase_contrast),
	JS_CFUNC_DEF("accessibility_should_reduce_animation", 0, &display_server_class_accessibility_should_reduce_animation),
	JS_CFUNC_DEF("accessibility_should_reduce_transparency", 0, &display_server_class_accessibility_should_reduce_transparency),
	JS_CFUNC_DEF("accessibility_screen_reader_active", 0, &display_server_class_accessibility_screen_reader_active),
	JS_CFUNC_DEF("accessibility_create_element", 2, &display_server_class_accessibility_create_element),
	JS_CFUNC_DEF("accessibility_create_sub_element", 3, &display_server_class_accessibility_create_sub_element),
	JS_CFUNC_DEF("accessibility_create_sub_text_edit_elements", 4, &display_server_class_accessibility_create_sub_text_edit_elements),
	JS_CFUNC_DEF("accessibility_has_element", 1, &display_server_class_accessibility_has_element),
	JS_CFUNC_DEF("accessibility_free_element", 1, &display_server_class_accessibility_free_element),
	JS_CFUNC_DEF("accessibility_element_set_meta", 2, &display_server_class_accessibility_element_set_meta),
	JS_CFUNC_DEF("accessibility_element_get_meta", 1, &display_server_class_accessibility_element_get_meta),
	JS_CFUNC_DEF("accessibility_set_window_rect", 3, &display_server_class_accessibility_set_window_rect),
	JS_CFUNC_DEF("accessibility_set_window_focused", 2, &display_server_class_accessibility_set_window_focused),
	JS_CFUNC_DEF("accessibility_update_set_focus", 1, &display_server_class_accessibility_update_set_focus),
	JS_CFUNC_DEF("accessibility_get_window_root", 1, &display_server_class_accessibility_get_window_root),
	JS_CFUNC_DEF("accessibility_update_set_role", 2, &display_server_class_accessibility_update_set_role),
	JS_CFUNC_DEF("accessibility_update_set_name", 2, &display_server_class_accessibility_update_set_name),
	JS_CFUNC_DEF("accessibility_update_set_extra_info", 2, &display_server_class_accessibility_update_set_extra_info),
	JS_CFUNC_DEF("accessibility_update_set_description", 2, &display_server_class_accessibility_update_set_description),
	JS_CFUNC_DEF("accessibility_update_set_value", 2, &display_server_class_accessibility_update_set_value),
	JS_CFUNC_DEF("accessibility_update_set_tooltip", 2, &display_server_class_accessibility_update_set_tooltip),
	JS_CFUNC_DEF("accessibility_update_set_bounds", 2, &display_server_class_accessibility_update_set_bounds),
	JS_CFUNC_DEF("accessibility_update_set_transform", 2, &display_server_class_accessibility_update_set_transform),
	JS_CFUNC_DEF("accessibility_update_add_child", 2, &display_server_class_accessibility_update_add_child),
	JS_CFUNC_DEF("accessibility_update_add_related_controls", 2, &display_server_class_accessibility_update_add_related_controls),
	JS_CFUNC_DEF("accessibility_update_add_related_details", 2, &display_server_class_accessibility_update_add_related_details),
	JS_CFUNC_DEF("accessibility_update_add_related_described_by", 2, &display_server_class_accessibility_update_add_related_described_by),
	JS_CFUNC_DEF("accessibility_update_add_related_flow_to", 2, &display_server_class_accessibility_update_add_related_flow_to),
	JS_CFUNC_DEF("accessibility_update_add_related_labeled_by", 2, &display_server_class_accessibility_update_add_related_labeled_by),
	JS_CFUNC_DEF("accessibility_update_add_related_radio_group", 2, &display_server_class_accessibility_update_add_related_radio_group),
	JS_CFUNC_DEF("accessibility_update_set_active_descendant", 2, &display_server_class_accessibility_update_set_active_descendant),
	JS_CFUNC_DEF("accessibility_update_set_next_on_line", 2, &display_server_class_accessibility_update_set_next_on_line),
	JS_CFUNC_DEF("accessibility_update_set_previous_on_line", 2, &display_server_class_accessibility_update_set_previous_on_line),
	JS_CFUNC_DEF("accessibility_update_set_member_of", 2, &display_server_class_accessibility_update_set_member_of),
	JS_CFUNC_DEF("accessibility_update_set_in_page_link_target", 2, &display_server_class_accessibility_update_set_in_page_link_target),
	JS_CFUNC_DEF("accessibility_update_set_error_message", 2, &display_server_class_accessibility_update_set_error_message),
	JS_CFUNC_DEF("accessibility_update_set_live", 2, &display_server_class_accessibility_update_set_live),
	JS_CFUNC_DEF("accessibility_update_add_action", 3, &display_server_class_accessibility_update_add_action),
	JS_CFUNC_DEF("accessibility_update_add_custom_action", 3, &display_server_class_accessibility_update_add_custom_action),
	JS_CFUNC_DEF("accessibility_update_set_table_row_count", 2, &display_server_class_accessibility_update_set_table_row_count),
	JS_CFUNC_DEF("accessibility_update_set_table_column_count", 2, &display_server_class_accessibility_update_set_table_column_count),
	JS_CFUNC_DEF("accessibility_update_set_table_row_index", 2, &display_server_class_accessibility_update_set_table_row_index),
	JS_CFUNC_DEF("accessibility_update_set_table_column_index", 2, &display_server_class_accessibility_update_set_table_column_index),
	JS_CFUNC_DEF("accessibility_update_set_table_cell_position", 3, &display_server_class_accessibility_update_set_table_cell_position),
	JS_CFUNC_DEF("accessibility_update_set_table_cell_span", 3, &display_server_class_accessibility_update_set_table_cell_span),
	JS_CFUNC_DEF("accessibility_update_set_list_item_count", 2, &display_server_class_accessibility_update_set_list_item_count),
	JS_CFUNC_DEF("accessibility_update_set_list_item_index", 2, &display_server_class_accessibility_update_set_list_item_index),
	JS_CFUNC_DEF("accessibility_update_set_list_item_level", 2, &display_server_class_accessibility_update_set_list_item_level),
	JS_CFUNC_DEF("accessibility_update_set_list_item_selected", 2, &display_server_class_accessibility_update_set_list_item_selected),
	JS_CFUNC_DEF("accessibility_update_set_list_item_expanded", 2, &display_server_class_accessibility_update_set_list_item_expanded),
	JS_CFUNC_DEF("accessibility_update_set_popup_type", 2, &display_server_class_accessibility_update_set_popup_type),
	JS_CFUNC_DEF("accessibility_update_set_checked", 2, &display_server_class_accessibility_update_set_checked),
	JS_CFUNC_DEF("accessibility_update_set_num_value", 2, &display_server_class_accessibility_update_set_num_value),
	JS_CFUNC_DEF("accessibility_update_set_num_range", 3, &display_server_class_accessibility_update_set_num_range),
	JS_CFUNC_DEF("accessibility_update_set_num_step", 2, &display_server_class_accessibility_update_set_num_step),
	JS_CFUNC_DEF("accessibility_update_set_num_jump", 2, &display_server_class_accessibility_update_set_num_jump),
	JS_CFUNC_DEF("accessibility_update_set_scroll_x", 2, &display_server_class_accessibility_update_set_scroll_x),
	JS_CFUNC_DEF("accessibility_update_set_scroll_x_range", 3, &display_server_class_accessibility_update_set_scroll_x_range),
	JS_CFUNC_DEF("accessibility_update_set_scroll_y", 2, &display_server_class_accessibility_update_set_scroll_y),
	JS_CFUNC_DEF("accessibility_update_set_scroll_y_range", 3, &display_server_class_accessibility_update_set_scroll_y_range),
	JS_CFUNC_DEF("accessibility_update_set_text_decorations", 4, &display_server_class_accessibility_update_set_text_decorations),
	JS_CFUNC_DEF("accessibility_update_set_text_align", 2, &display_server_class_accessibility_update_set_text_align),
	JS_CFUNC_DEF("accessibility_update_set_text_selection", 5, &display_server_class_accessibility_update_set_text_selection),
	JS_CFUNC_DEF("accessibility_update_set_flag", 3, &display_server_class_accessibility_update_set_flag),
	JS_CFUNC_DEF("accessibility_update_set_classname", 2, &display_server_class_accessibility_update_set_classname),
	JS_CFUNC_DEF("accessibility_update_set_placeholder", 2, &display_server_class_accessibility_update_set_placeholder),
	JS_CFUNC_DEF("accessibility_update_set_language", 2, &display_server_class_accessibility_update_set_language),
	JS_CFUNC_DEF("accessibility_update_set_text_orientation", 2, &display_server_class_accessibility_update_set_text_orientation),
	JS_CFUNC_DEF("accessibility_update_set_list_orientation", 2, &display_server_class_accessibility_update_set_list_orientation),
	JS_CFUNC_DEF("accessibility_update_set_shortcut", 2, &display_server_class_accessibility_update_set_shortcut),
	JS_CFUNC_DEF("accessibility_update_set_url", 2, &display_server_class_accessibility_update_set_url),
	JS_CFUNC_DEF("accessibility_update_set_role_description", 2, &display_server_class_accessibility_update_set_role_description),
	JS_CFUNC_DEF("accessibility_update_set_state_description", 2, &display_server_class_accessibility_update_set_state_description),
	JS_CFUNC_DEF("accessibility_update_set_color_value", 2, &display_server_class_accessibility_update_set_color_value),
	JS_CFUNC_DEF("accessibility_update_set_background_color", 2, &display_server_class_accessibility_update_set_background_color),
	JS_CFUNC_DEF("accessibility_update_set_foreground_color", 2, &display_server_class_accessibility_update_set_foreground_color),
	JS_CFUNC_DEF("ime_get_selection", 0, &display_server_class_ime_get_selection),
	JS_CFUNC_DEF("ime_get_text", 0, &display_server_class_ime_get_text),
	JS_CFUNC_DEF("virtual_keyboard_show", 6, &display_server_class_virtual_keyboard_show),
	JS_CFUNC_DEF("virtual_keyboard_hide", 0, &display_server_class_virtual_keyboard_hide),
	JS_CFUNC_DEF("virtual_keyboard_get_height", 0, &display_server_class_virtual_keyboard_get_height),
	JS_CFUNC_DEF("has_hardware_keyboard", 0, &display_server_class_has_hardware_keyboard),
	JS_CFUNC_DEF("set_hardware_keyboard_connection_change_callback", 1, &display_server_class_set_hardware_keyboard_connection_change_callback),
	JS_CFUNC_DEF("cursor_set_shape", 1, &display_server_class_cursor_set_shape),
	JS_CFUNC_DEF("cursor_get_shape", 0, &display_server_class_cursor_get_shape),
	JS_CFUNC_DEF("cursor_set_custom_image", 3, &display_server_class_cursor_set_custom_image),
	JS_CFUNC_DEF("get_swap_cancel_ok", 0, &display_server_class_get_swap_cancel_ok),
	JS_CFUNC_DEF("enable_for_stealing_focus", 1, &display_server_class_enable_for_stealing_focus),
	JS_CFUNC_DEF("dialog_show", 4, &display_server_class_dialog_show),
	JS_CFUNC_DEF("dialog_input_text", 4, &display_server_class_dialog_input_text),
	JS_CFUNC_DEF("file_dialog_show", 8, &display_server_class_file_dialog_show),
	JS_CFUNC_DEF("file_dialog_with_options_show", 10, &display_server_class_file_dialog_with_options_show),
	JS_CFUNC_DEF("beep", 0, &display_server_class_beep),
	JS_CFUNC_DEF("keyboard_get_layout_count", 0, &display_server_class_keyboard_get_layout_count),
	JS_CFUNC_DEF("keyboard_get_current_layout", 0, &display_server_class_keyboard_get_current_layout),
	JS_CFUNC_DEF("keyboard_set_current_layout", 1, &display_server_class_keyboard_set_current_layout),
	JS_CFUNC_DEF("keyboard_get_layout_language", 1, &display_server_class_keyboard_get_layout_language),
	JS_CFUNC_DEF("keyboard_get_layout_name", 1, &display_server_class_keyboard_get_layout_name),
	JS_CFUNC_DEF("keyboard_get_keycode_from_physical", 1, &display_server_class_keyboard_get_keycode_from_physical),
	JS_CFUNC_DEF("keyboard_get_label_from_physical", 1, &display_server_class_keyboard_get_label_from_physical),
	JS_CFUNC_DEF("show_emoji_and_symbol_picker", 0, &display_server_class_show_emoji_and_symbol_picker),
	JS_CFUNC_DEF("color_picker", 1, &display_server_class_color_picker),
	JS_CFUNC_DEF("process_events", 0, &display_server_class_process_events),
	JS_CFUNC_DEF("force_process_and_drop_events", 0, &display_server_class_force_process_and_drop_events),
	JS_CFUNC_DEF("set_native_icon", 1, &display_server_class_set_native_icon),
	JS_CFUNC_DEF("set_icon", 1, &display_server_class_set_icon),
	JS_CFUNC_DEF("create_status_indicator", 3, &display_server_class_create_status_indicator),
	JS_CFUNC_DEF("status_indicator_set_icon", 2, &display_server_class_status_indicator_set_icon),
	JS_CFUNC_DEF("status_indicator_set_tooltip", 2, &display_server_class_status_indicator_set_tooltip),
	JS_CFUNC_DEF("status_indicator_set_menu", 2, &display_server_class_status_indicator_set_menu),
	JS_CFUNC_DEF("status_indicator_set_callback", 2, &display_server_class_status_indicator_set_callback),
	JS_CFUNC_DEF("status_indicator_get_rect", 1, &display_server_class_status_indicator_get_rect),
	JS_CFUNC_DEF("delete_status_indicator", 1, &display_server_class_delete_status_indicator),
	JS_CFUNC_DEF("tablet_get_driver_count", 0, &display_server_class_tablet_get_driver_count),
	JS_CFUNC_DEF("tablet_get_driver_name", 1, &display_server_class_tablet_get_driver_name),
	JS_CFUNC_DEF("tablet_get_current_driver", 0, &display_server_class_tablet_get_current_driver),
	JS_CFUNC_DEF("tablet_set_current_driver", 1, &display_server_class_tablet_set_current_driver),
	JS_CFUNC_DEF("is_window_transparency_available", 0, &display_server_class_is_window_transparency_available),
	JS_CFUNC_DEF("register_additional_output", 1, &display_server_class_register_additional_output),
	JS_CFUNC_DEF("unregister_additional_output", 1, &display_server_class_unregister_additional_output),
	JS_CFUNC_DEF("has_additional_outputs", 0, &display_server_class_has_additional_outputs),
};




static int js_display_server_class_init(JSContext *ctx) {
	JSClassID class_id = classes["DisplayServer"];
	classes["DisplayServer"] = class_id;
	JS_NewClass(JS_GetRuntime(ctx), class_id, &display_server_class_def);

	JSValue proto = JS_NewObject(ctx);
	JSValue base_class = JS_GetClassProto(ctx, classes["Object"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	JS_SetPropertyFunctionList(ctx, proto, display_server_class_proto_funcs, _countof(display_server_class_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, display_server_class_constructor, "_DisplayServer", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);


	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "DisplayServer", ctor);
	JS_FreeValue(ctx, global);
	return 0;
}

void register_display_server() {
	js_display_server_class_init(js_context());
}