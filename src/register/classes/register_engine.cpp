#include "register/classes/register_classes.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/str_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/main_loop.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/script_backtrace.hpp>
#include <godot_cpp/classes/script_language.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/engine.hpp>


using namespace godot;

static void engine_class_finalizer(JSRuntime *rt, JSValue val) {
}

static JSClassDef engine_class_def = {
	"_Engine",
	engine_class_finalizer
};

static JSValue engine_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["Engine"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);
	if (JS_IsException(obj))
		return obj;

	Engine *engine_class = Engine::get_singleton();
	if (!engine_class) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, engine_class);
	return obj;
}

static JSValue engine_class_set_physics_ticks_per_second(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&Engine::set_physics_ticks_per_second, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue engine_class_get_physics_ticks_per_second(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Engine::get_physics_ticks_per_second, ctx, this_val, argc, argv);
};
static JSValue engine_class_set_max_physics_steps_per_frame(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&Engine::set_max_physics_steps_per_frame, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue engine_class_get_max_physics_steps_per_frame(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Engine::get_max_physics_steps_per_frame, ctx, this_val, argc, argv);
};
static JSValue engine_class_set_physics_jitter_fix(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&Engine::set_physics_jitter_fix, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue engine_class_get_physics_jitter_fix(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Engine::get_physics_jitter_fix, ctx, this_val, argc, argv);
};
static JSValue engine_class_get_physics_interpolation_fraction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Engine::get_physics_interpolation_fraction, ctx, this_val, argc, argv);
};
static JSValue engine_class_set_max_fps(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&Engine::set_max_fps, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue engine_class_get_max_fps(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Engine::get_max_fps, ctx, this_val, argc, argv);
};
static JSValue engine_class_set_time_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&Engine::set_time_scale, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue engine_class_get_time_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Engine::get_time_scale, ctx, this_val, argc, argv);
};
static JSValue engine_class_get_frames_drawn(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Engine::get_frames_drawn, ctx, this_val, argc, argv);
};
static JSValue engine_class_get_frames_per_second(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Engine::get_frames_per_second, ctx, this_val, argc, argv);
};
static JSValue engine_class_get_physics_frames(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Engine::get_physics_frames, ctx, this_val, argc, argv);
};
static JSValue engine_class_get_process_frames(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Engine::get_process_frames, ctx, this_val, argc, argv);
};
static JSValue engine_class_get_main_loop(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Engine::get_main_loop, ctx, this_val, argc, argv);
};
static JSValue engine_class_get_version_info(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Engine::get_version_info, ctx, this_val, argc, argv);
};
static JSValue engine_class_get_author_info(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Engine::get_author_info, ctx, this_val, argc, argv);
};
static JSValue engine_class_get_copyright_info(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Engine::get_copyright_info, ctx, this_val, argc, argv);
};
static JSValue engine_class_get_donor_info(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Engine::get_donor_info, ctx, this_val, argc, argv);
};
static JSValue engine_class_get_license_info(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Engine::get_license_info, ctx, this_val, argc, argv);
};
static JSValue engine_class_get_license_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Engine::get_license_text, ctx, this_val, argc, argv);
};
static JSValue engine_class_get_architecture_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Engine::get_architecture_name, ctx, this_val, argc, argv);
};
static JSValue engine_class_is_in_physics_frame(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Engine::is_in_physics_frame, ctx, this_val, argc, argv);
};
static JSValue engine_class_has_singleton(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Engine::has_singleton, ctx, this_val, argc, argv);
};
static JSValue engine_class_get_singleton(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Engine::get_singleton, ctx, this_val, argc, argv);
};
static JSValue engine_class_register_singleton(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&Engine::register_singleton, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue engine_class_unregister_singleton(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&Engine::unregister_singleton, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue engine_class_get_singleton_list(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Engine::get_singleton_list, ctx, this_val, argc, argv);
};
static JSValue engine_class_register_script_language(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Engine::register_script_language, ctx, this_val, argc, argv);
};
static JSValue engine_class_unregister_script_language(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Engine::unregister_script_language, ctx, this_val, argc, argv);
};
static JSValue engine_class_get_script_language_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&Engine::get_script_language_count, ctx, this_val, argc, argv);
};
static JSValue engine_class_get_script_language(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Engine::get_script_language, ctx, this_val, argc, argv);
};
static JSValue engine_class_capture_script_backtraces(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Engine::capture_script_backtraces, ctx, this_val, argc, argv);
};
static JSValue engine_class_is_editor_hint(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Engine::is_editor_hint, ctx, this_val, argc, argv);
};
static JSValue engine_class_is_embedded_in_editor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Engine::is_embedded_in_editor, ctx, this_val, argc, argv);
};
static JSValue engine_class_get_write_movie_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Engine::get_write_movie_path, ctx, this_val, argc, argv);
};
static JSValue engine_class_set_print_to_stdout(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&Engine::set_print_to_stdout, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue engine_class_is_printing_to_stdout(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Engine::is_printing_to_stdout, ctx, this_val, argc, argv);
};
static JSValue engine_class_set_print_error_messages(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&Engine::set_print_error_messages, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue engine_class_is_printing_error_messages(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&Engine::is_printing_error_messages, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry engine_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_physics_ticks_per_second", 1, &engine_class_set_physics_ticks_per_second),
	JS_CFUNC_DEF("get_physics_ticks_per_second", 0, &engine_class_get_physics_ticks_per_second),
	JS_CFUNC_DEF("set_max_physics_steps_per_frame", 1, &engine_class_set_max_physics_steps_per_frame),
	JS_CFUNC_DEF("get_max_physics_steps_per_frame", 0, &engine_class_get_max_physics_steps_per_frame),
	JS_CFUNC_DEF("set_physics_jitter_fix", 1, &engine_class_set_physics_jitter_fix),
	JS_CFUNC_DEF("get_physics_jitter_fix", 0, &engine_class_get_physics_jitter_fix),
	JS_CFUNC_DEF("get_physics_interpolation_fraction", 0, &engine_class_get_physics_interpolation_fraction),
	JS_CFUNC_DEF("set_max_fps", 1, &engine_class_set_max_fps),
	JS_CFUNC_DEF("get_max_fps", 0, &engine_class_get_max_fps),
	JS_CFUNC_DEF("set_time_scale", 1, &engine_class_set_time_scale),
	JS_CFUNC_DEF("get_time_scale", 0, &engine_class_get_time_scale),
	JS_CFUNC_DEF("get_frames_drawn", 0, &engine_class_get_frames_drawn),
	JS_CFUNC_DEF("get_frames_per_second", 0, &engine_class_get_frames_per_second),
	JS_CFUNC_DEF("get_physics_frames", 0, &engine_class_get_physics_frames),
	JS_CFUNC_DEF("get_process_frames", 0, &engine_class_get_process_frames),
	JS_CFUNC_DEF("get_main_loop", 0, &engine_class_get_main_loop),
	JS_CFUNC_DEF("get_version_info", 0, &engine_class_get_version_info),
	JS_CFUNC_DEF("get_author_info", 0, &engine_class_get_author_info),
	JS_CFUNC_DEF("get_copyright_info", 0, &engine_class_get_copyright_info),
	JS_CFUNC_DEF("get_donor_info", 0, &engine_class_get_donor_info),
	JS_CFUNC_DEF("get_license_info", 0, &engine_class_get_license_info),
	JS_CFUNC_DEF("get_license_text", 0, &engine_class_get_license_text),
	JS_CFUNC_DEF("get_architecture_name", 0, &engine_class_get_architecture_name),
	JS_CFUNC_DEF("is_in_physics_frame", 0, &engine_class_is_in_physics_frame),
	JS_CFUNC_DEF("has_singleton", 1, &engine_class_has_singleton),
	JS_CFUNC_DEF("get_singleton", 1, &engine_class_get_singleton),
	JS_CFUNC_DEF("register_singleton", 2, &engine_class_register_singleton),
	JS_CFUNC_DEF("unregister_singleton", 1, &engine_class_unregister_singleton),
	JS_CFUNC_DEF("get_singleton_list", 0, &engine_class_get_singleton_list),
	JS_CFUNC_DEF("register_script_language", 1, &engine_class_register_script_language),
	JS_CFUNC_DEF("unregister_script_language", 1, &engine_class_unregister_script_language),
	JS_CFUNC_DEF("get_script_language_count", 0, &engine_class_get_script_language_count),
	JS_CFUNC_DEF("get_script_language", 1, &engine_class_get_script_language),
	JS_CFUNC_DEF("capture_script_backtraces", 1, &engine_class_capture_script_backtraces),
	JS_CFUNC_DEF("is_editor_hint", 0, &engine_class_is_editor_hint),
	JS_CFUNC_DEF("is_embedded_in_editor", 0, &engine_class_is_embedded_in_editor),
	JS_CFUNC_DEF("get_write_movie_path", 0, &engine_class_get_write_movie_path),
	JS_CFUNC_DEF("set_print_to_stdout", 1, &engine_class_set_print_to_stdout),
	JS_CFUNC_DEF("is_printing_to_stdout", 0, &engine_class_is_printing_to_stdout),
	JS_CFUNC_DEF("set_print_error_messages", 1, &engine_class_set_print_error_messages),
	JS_CFUNC_DEF("is_printing_error_messages", 0, &engine_class_is_printing_error_messages),
};




static int js_engine_class_init(JSContext *ctx) {
	JSClassID class_id = classes["Engine"];
	classes["Engine"] = class_id;
	JS_NewClass(JS_GetRuntime(ctx), class_id, &engine_class_def);

	JSValue proto = JS_NewObject(ctx);
	JSValue base_class = JS_GetClassProto(ctx, classes["Object"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	JS_SetPropertyFunctionList(ctx, proto, engine_class_proto_funcs, _countof(engine_class_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, engine_class_constructor, "_Engine", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);


	JSValue global = JS_GetGlobalObject(ctx);
	JS_SetPropertyStr(ctx, global, "Engine", ctor);
	JS_FreeValue(ctx, global);
	return 0;
}

void register_engine() {
	js_engine_class_init(js_context());
}