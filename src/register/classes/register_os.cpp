#include "register/classes/register_classes.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/str_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/logger.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/os.hpp>


using namespace godot;

static void os_class_finalizer(JSRuntime *rt, JSValue val) {
}

static JSClassDef os_class_def = {
	"_OS",
	os_class_finalizer
};

static JSValue os_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["OS"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);
	if (JS_IsException(obj))
		return obj;

	OS *os_class = OS::get_singleton();
	if (!os_class) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, os_class);
	return obj;
}

static JSValue os_class_get_entropy(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&OS::get_entropy, ctx, this_val, argc, argv);
};
static JSValue os_class_get_system_ca_certificates(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&OS::get_system_ca_certificates, ctx, this_val, argc, argv);
};
static JSValue os_class_get_connected_midi_inputs(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&OS::get_connected_midi_inputs, ctx, this_val, argc, argv);
};
static JSValue os_class_open_midi_inputs(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&OS::open_midi_inputs, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue os_class_close_midi_inputs(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&OS::close_midi_inputs, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue os_class_alert(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&OS::alert, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue os_class_crash(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&OS::crash, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue os_class_set_low_processor_usage_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&OS::set_low_processor_usage_mode, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue os_class_is_in_low_processor_usage_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&OS::is_in_low_processor_usage_mode, ctx, this_val, argc, argv);
};
static JSValue os_class_set_low_processor_usage_mode_sleep_usec(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&OS::set_low_processor_usage_mode_sleep_usec, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue os_class_get_low_processor_usage_mode_sleep_usec(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&OS::get_low_processor_usage_mode_sleep_usec, ctx, this_val, argc, argv);
};
static JSValue os_class_set_delta_smoothing(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&OS::set_delta_smoothing, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue os_class_is_delta_smoothing_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&OS::is_delta_smoothing_enabled, ctx, this_val, argc, argv);
};
static JSValue os_class_get_processor_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&OS::get_processor_count, ctx, this_val, argc, argv);
};
static JSValue os_class_get_processor_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&OS::get_processor_name, ctx, this_val, argc, argv);
};
static JSValue os_class_get_system_fonts(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&OS::get_system_fonts, ctx, this_val, argc, argv);
};
static JSValue os_class_get_system_font_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&OS::get_system_font_path, ctx, this_val, argc, argv);
};
static JSValue os_class_get_system_font_path_for_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&OS::get_system_font_path_for_text, ctx, this_val, argc, argv);
};
static JSValue os_class_get_executable_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&OS::get_executable_path, ctx, this_val, argc, argv);
};
static JSValue os_class_read_string_from_stdin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&OS::read_string_from_stdin, ctx, this_val, argc, argv);
};
static JSValue os_class_read_buffer_from_stdin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&OS::read_buffer_from_stdin, ctx, this_val, argc, argv);
};
static JSValue os_class_get_stdin_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&OS::get_stdin_type, ctx, this_val, argc, argv);
};
static JSValue os_class_get_stdout_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&OS::get_stdout_type, ctx, this_val, argc, argv);
};
static JSValue os_class_get_stderr_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&OS::get_stderr_type, ctx, this_val, argc, argv);
};
static JSValue os_class_execute(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&OS::execute, ctx, this_val, argc, argv);
};
static JSValue os_class_execute_with_pipe(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&OS::execute_with_pipe, ctx, this_val, argc, argv);
};
static JSValue os_class_create_process(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&OS::create_process, ctx, this_val, argc, argv);
};
static JSValue os_class_create_instance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&OS::create_instance, ctx, this_val, argc, argv);
};
static JSValue os_class_open_with_program(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&OS::open_with_program, ctx, this_val, argc, argv);
};
static JSValue os_class_kill(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&OS::kill, ctx, this_val, argc, argv);
};
static JSValue os_class_shell_open(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&OS::shell_open, ctx, this_val, argc, argv);
};
static JSValue os_class_shell_show_in_file_manager(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&OS::shell_show_in_file_manager, ctx, this_val, argc, argv);
};
static JSValue os_class_is_process_running(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&OS::is_process_running, ctx, this_val, argc, argv);
};
static JSValue os_class_get_process_exit_code(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&OS::get_process_exit_code, ctx, this_val, argc, argv);
};
static JSValue os_class_get_process_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&OS::get_process_id, ctx, this_val, argc, argv);
};
static JSValue os_class_has_environment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&OS::has_environment, ctx, this_val, argc, argv);
};
static JSValue os_class_get_environment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&OS::get_environment, ctx, this_val, argc, argv);
};
static JSValue os_class_set_environment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_const_method_no_ret(&OS::set_environment, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue os_class_unset_environment(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_const_method_no_ret(&OS::unset_environment, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue os_class_get_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&OS::get_name, ctx, this_val, argc, argv);
};
static JSValue os_class_get_distribution_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&OS::get_distribution_name, ctx, this_val, argc, argv);
};
static JSValue os_class_get_version(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&OS::get_version, ctx, this_val, argc, argv);
};
static JSValue os_class_get_version_alias(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&OS::get_version_alias, ctx, this_val, argc, argv);
};
static JSValue os_class_get_cmdline_args(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&OS::get_cmdline_args, ctx, this_val, argc, argv);
};
static JSValue os_class_get_cmdline_user_args(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&OS::get_cmdline_user_args, ctx, this_val, argc, argv);
};
static JSValue os_class_get_video_adapter_driver_info(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&OS::get_video_adapter_driver_info, ctx, this_val, argc, argv);
};
static JSValue os_class_set_restart_on_exit(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&OS::set_restart_on_exit, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue os_class_is_restart_on_exit_set(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&OS::is_restart_on_exit_set, ctx, this_val, argc, argv);
};
static JSValue os_class_get_restart_on_exit_arguments(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&OS::get_restart_on_exit_arguments, ctx, this_val, argc, argv);
};
static JSValue os_class_delay_usec(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_const_method_no_ret(&OS::delay_usec, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue os_class_delay_msec(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_const_method_no_ret(&OS::delay_msec, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue os_class_get_locale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&OS::get_locale, ctx, this_val, argc, argv);
};
static JSValue os_class_get_locale_language(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&OS::get_locale_language, ctx, this_val, argc, argv);
};
static JSValue os_class_get_model_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&OS::get_model_name, ctx, this_val, argc, argv);
};
static JSValue os_class_is_userfs_persistent(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&OS::is_userfs_persistent, ctx, this_val, argc, argv);
};
static JSValue os_class_is_stdout_verbose(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&OS::is_stdout_verbose, ctx, this_val, argc, argv);
};
static JSValue os_class_is_debug_build(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&OS::is_debug_build, ctx, this_val, argc, argv);
};
static JSValue os_class_get_static_memory_usage(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&OS::get_static_memory_usage, ctx, this_val, argc, argv);
};
static JSValue os_class_get_static_memory_peak_usage(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&OS::get_static_memory_peak_usage, ctx, this_val, argc, argv);
};
static JSValue os_class_get_memory_info(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&OS::get_memory_info, ctx, this_val, argc, argv);
};
static JSValue os_class_move_to_trash(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&OS::move_to_trash, ctx, this_val, argc, argv);
};
static JSValue os_class_get_user_data_dir(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&OS::get_user_data_dir, ctx, this_val, argc, argv);
};
static JSValue os_class_get_system_dir(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&OS::get_system_dir, ctx, this_val, argc, argv);
};
static JSValue os_class_get_config_dir(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&OS::get_config_dir, ctx, this_val, argc, argv);
};
static JSValue os_class_get_data_dir(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&OS::get_data_dir, ctx, this_val, argc, argv);
};
static JSValue os_class_get_cache_dir(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&OS::get_cache_dir, ctx, this_val, argc, argv);
};
static JSValue os_class_get_temp_dir(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&OS::get_temp_dir, ctx, this_val, argc, argv);
};
static JSValue os_class_get_unique_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&OS::get_unique_id, ctx, this_val, argc, argv);
};
static JSValue os_class_get_keycode_string(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&OS::get_keycode_string, ctx, this_val, argc, argv);
};
static JSValue os_class_is_keycode_unicode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&OS::is_keycode_unicode, ctx, this_val, argc, argv);
};
static JSValue os_class_find_keycode_from_string(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&OS::find_keycode_from_string, ctx, this_val, argc, argv);
};
static JSValue os_class_set_use_file_access_save_and_swap(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&OS::set_use_file_access_save_and_swap, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue os_class_set_thread_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&OS::set_thread_name, ctx, this_val, argc, argv);
};
static JSValue os_class_get_thread_caller_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&OS::get_thread_caller_id, ctx, this_val, argc, argv);
};
static JSValue os_class_get_main_thread_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&OS::get_main_thread_id, ctx, this_val, argc, argv);
};
static JSValue os_class_has_feature(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&OS::has_feature, ctx, this_val, argc, argv);
};
static JSValue os_class_is_sandboxed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&OS::is_sandboxed, ctx, this_val, argc, argv);
};
static JSValue os_class_request_permission(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&OS::request_permission, ctx, this_val, argc, argv);
};
static JSValue os_class_request_permissions(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&OS::request_permissions, ctx, this_val, argc, argv);
};
static JSValue os_class_get_granted_permissions(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&OS::get_granted_permissions, ctx, this_val, argc, argv);
};
static JSValue os_class_revoke_granted_permissions(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&OS::revoke_granted_permissions, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue os_class_add_logger(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&OS::add_logger, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue os_class_remove_logger(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&OS::remove_logger, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};

static const JSCFunctionListEntry os_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_entropy", 1, &os_class_get_entropy),
	JS_CFUNC_DEF("get_system_ca_certificates", 0, &os_class_get_system_ca_certificates),
	JS_CFUNC_DEF("get_connected_midi_inputs", 0, &os_class_get_connected_midi_inputs),
	JS_CFUNC_DEF("open_midi_inputs", 0, &os_class_open_midi_inputs),
	JS_CFUNC_DEF("close_midi_inputs", 0, &os_class_close_midi_inputs),
	JS_CFUNC_DEF("alert", 2, &os_class_alert),
	JS_CFUNC_DEF("crash", 1, &os_class_crash),
	JS_CFUNC_DEF("set_low_processor_usage_mode", 1, &os_class_set_low_processor_usage_mode),
	JS_CFUNC_DEF("is_in_low_processor_usage_mode", 0, &os_class_is_in_low_processor_usage_mode),
	JS_CFUNC_DEF("set_low_processor_usage_mode_sleep_usec", 1, &os_class_set_low_processor_usage_mode_sleep_usec),
	JS_CFUNC_DEF("get_low_processor_usage_mode_sleep_usec", 0, &os_class_get_low_processor_usage_mode_sleep_usec),
	JS_CFUNC_DEF("set_delta_smoothing", 1, &os_class_set_delta_smoothing),
	JS_CFUNC_DEF("is_delta_smoothing_enabled", 0, &os_class_is_delta_smoothing_enabled),
	JS_CFUNC_DEF("get_processor_count", 0, &os_class_get_processor_count),
	JS_CFUNC_DEF("get_processor_name", 0, &os_class_get_processor_name),
	JS_CFUNC_DEF("get_system_fonts", 0, &os_class_get_system_fonts),
	JS_CFUNC_DEF("get_system_font_path", 4, &os_class_get_system_font_path),
	JS_CFUNC_DEF("get_system_font_path_for_text", 7, &os_class_get_system_font_path_for_text),
	JS_CFUNC_DEF("get_executable_path", 0, &os_class_get_executable_path),
	JS_CFUNC_DEF("read_string_from_stdin", 1, &os_class_read_string_from_stdin),
	JS_CFUNC_DEF("read_buffer_from_stdin", 1, &os_class_read_buffer_from_stdin),
	JS_CFUNC_DEF("get_stdin_type", 0, &os_class_get_stdin_type),
	JS_CFUNC_DEF("get_stdout_type", 0, &os_class_get_stdout_type),
	JS_CFUNC_DEF("get_stderr_type", 0, &os_class_get_stderr_type),
	JS_CFUNC_DEF("execute", 5, &os_class_execute),
	JS_CFUNC_DEF("execute_with_pipe", 3, &os_class_execute_with_pipe),
	JS_CFUNC_DEF("create_process", 3, &os_class_create_process),
	JS_CFUNC_DEF("create_instance", 1, &os_class_create_instance),
	JS_CFUNC_DEF("open_with_program", 2, &os_class_open_with_program),
	JS_CFUNC_DEF("kill", 1, &os_class_kill),
	JS_CFUNC_DEF("shell_open", 1, &os_class_shell_open),
	JS_CFUNC_DEF("shell_show_in_file_manager", 2, &os_class_shell_show_in_file_manager),
	JS_CFUNC_DEF("is_process_running", 1, &os_class_is_process_running),
	JS_CFUNC_DEF("get_process_exit_code", 1, &os_class_get_process_exit_code),
	JS_CFUNC_DEF("get_process_id", 0, &os_class_get_process_id),
	JS_CFUNC_DEF("has_environment", 1, &os_class_has_environment),
	JS_CFUNC_DEF("get_environment", 1, &os_class_get_environment),
	JS_CFUNC_DEF("set_environment", 2, &os_class_set_environment),
	JS_CFUNC_DEF("unset_environment", 1, &os_class_unset_environment),
	JS_CFUNC_DEF("get_name", 0, &os_class_get_name),
	JS_CFUNC_DEF("get_distribution_name", 0, &os_class_get_distribution_name),
	JS_CFUNC_DEF("get_version", 0, &os_class_get_version),
	JS_CFUNC_DEF("get_version_alias", 0, &os_class_get_version_alias),
	JS_CFUNC_DEF("get_cmdline_args", 0, &os_class_get_cmdline_args),
	JS_CFUNC_DEF("get_cmdline_user_args", 0, &os_class_get_cmdline_user_args),
	JS_CFUNC_DEF("get_video_adapter_driver_info", 0, &os_class_get_video_adapter_driver_info),
	JS_CFUNC_DEF("set_restart_on_exit", 2, &os_class_set_restart_on_exit),
	JS_CFUNC_DEF("is_restart_on_exit_set", 0, &os_class_is_restart_on_exit_set),
	JS_CFUNC_DEF("get_restart_on_exit_arguments", 0, &os_class_get_restart_on_exit_arguments),
	JS_CFUNC_DEF("delay_usec", 1, &os_class_delay_usec),
	JS_CFUNC_DEF("delay_msec", 1, &os_class_delay_msec),
	JS_CFUNC_DEF("get_locale", 0, &os_class_get_locale),
	JS_CFUNC_DEF("get_locale_language", 0, &os_class_get_locale_language),
	JS_CFUNC_DEF("get_model_name", 0, &os_class_get_model_name),
	JS_CFUNC_DEF("is_userfs_persistent", 0, &os_class_is_userfs_persistent),
	JS_CFUNC_DEF("is_stdout_verbose", 0, &os_class_is_stdout_verbose),
	JS_CFUNC_DEF("is_debug_build", 0, &os_class_is_debug_build),
	JS_CFUNC_DEF("get_static_memory_usage", 0, &os_class_get_static_memory_usage),
	JS_CFUNC_DEF("get_static_memory_peak_usage", 0, &os_class_get_static_memory_peak_usage),
	JS_CFUNC_DEF("get_memory_info", 0, &os_class_get_memory_info),
	JS_CFUNC_DEF("move_to_trash", 1, &os_class_move_to_trash),
	JS_CFUNC_DEF("get_user_data_dir", 0, &os_class_get_user_data_dir),
	JS_CFUNC_DEF("get_system_dir", 2, &os_class_get_system_dir),
	JS_CFUNC_DEF("get_config_dir", 0, &os_class_get_config_dir),
	JS_CFUNC_DEF("get_data_dir", 0, &os_class_get_data_dir),
	JS_CFUNC_DEF("get_cache_dir", 0, &os_class_get_cache_dir),
	JS_CFUNC_DEF("get_temp_dir", 0, &os_class_get_temp_dir),
	JS_CFUNC_DEF("get_unique_id", 0, &os_class_get_unique_id),
	JS_CFUNC_DEF("get_keycode_string", 1, &os_class_get_keycode_string),
	JS_CFUNC_DEF("is_keycode_unicode", 1, &os_class_is_keycode_unicode),
	JS_CFUNC_DEF("find_keycode_from_string", 1, &os_class_find_keycode_from_string),
	JS_CFUNC_DEF("set_use_file_access_save_and_swap", 1, &os_class_set_use_file_access_save_and_swap),
	JS_CFUNC_DEF("set_thread_name", 1, &os_class_set_thread_name),
	JS_CFUNC_DEF("get_thread_caller_id", 0, &os_class_get_thread_caller_id),
	JS_CFUNC_DEF("get_main_thread_id", 0, &os_class_get_main_thread_id),
	JS_CFUNC_DEF("has_feature", 1, &os_class_has_feature),
	JS_CFUNC_DEF("is_sandboxed", 0, &os_class_is_sandboxed),
	JS_CFUNC_DEF("request_permission", 1, &os_class_request_permission),
	JS_CFUNC_DEF("request_permissions", 0, &os_class_request_permissions),
	JS_CFUNC_DEF("get_granted_permissions", 0, &os_class_get_granted_permissions),
	JS_CFUNC_DEF("revoke_granted_permissions", 0, &os_class_revoke_granted_permissions),
	JS_CFUNC_DEF("add_logger", 1, &os_class_add_logger),
	JS_CFUNC_DEF("remove_logger", 1, &os_class_remove_logger),
};




static int js_os_class_init(JSContext *ctx) {
	JSClassID class_id = classes["OS"];
	classes["OS"] = class_id;
	JS_NewClass(JS_GetRuntime(ctx), class_id, &os_class_def);

	JSValue proto = JS_NewObject(ctx);
	JSValue base_class = JS_GetClassProto(ctx, classes["Object"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	JS_SetPropertyFunctionList(ctx, proto, os_class_proto_funcs, _countof(os_class_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, os_class_constructor, "_OS", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);


	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "OS", ctor);
	JS_FreeValue(ctx, global);
	return 0;
}

void register_os() {
	js_os_class_init(js_context());
}