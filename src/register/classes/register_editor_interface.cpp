#include "register/classes/register_classes.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/str_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/classes/editor_command_palette.hpp>
#include <godot_cpp/classes/editor_file_system.hpp>
#include <godot_cpp/classes/editor_inspector.hpp>
#include <godot_cpp/classes/editor_paths.hpp>
#include <godot_cpp/classes/editor_resource_preview.hpp>
#include <godot_cpp/classes/editor_selection.hpp>
#include <godot_cpp/classes/editor_settings.hpp>
#include <godot_cpp/classes/editor_toaster.hpp>
#include <godot_cpp/classes/editor_undo_redo_manager.hpp>
#include <godot_cpp/classes/file_system_dock.hpp>
#include <godot_cpp/classes/mesh.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/classes/script.hpp>
#include <godot_cpp/classes/script_editor.hpp>
#include <godot_cpp/classes/sub_viewport.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/classes/theme.hpp>
#include <godot_cpp/classes/v_box_container.hpp>
#include <godot_cpp/classes/window.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/editor_interface.hpp>


using namespace godot;

static void editor_interface_class_finalizer(JSRuntime *rt, JSValue val) {
}

static JSClassDef editor_interface_class_def = {
	"_EditorInterface",
	editor_interface_class_finalizer
};

static JSValue editor_interface_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
	JSClassID class_id = classes["_EditorInterface"];
	JSValue obj = JS_NewObjectClass(ctx, class_id);
	if (JS_IsException(obj))
		return obj;

	EditorInterface *editor_interface_class = EditorInterface::get_singleton();
	if (!editor_interface_class) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	VariantAdapter *adapter = memnew(VariantAdapter(editor_interface_class));
	JS_SetOpaque(obj, adapter);
	return obj;
}

static JSValue editor_interface_class_restart_editor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&EditorInterface::restart_editor, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue editor_interface_class_get_command_palette(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&EditorInterface::get_command_palette, ctx, this_val, argc, argv);
};
static JSValue editor_interface_class_get_resource_filesystem(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&EditorInterface::get_resource_filesystem, ctx, this_val, argc, argv);
};
static JSValue editor_interface_class_get_editor_paths(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&EditorInterface::get_editor_paths, ctx, this_val, argc, argv);
};
static JSValue editor_interface_class_get_resource_previewer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&EditorInterface::get_resource_previewer, ctx, this_val, argc, argv);
};
static JSValue editor_interface_class_get_selection(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&EditorInterface::get_selection, ctx, this_val, argc, argv);
};
static JSValue editor_interface_class_get_editor_settings(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&EditorInterface::get_editor_settings, ctx, this_val, argc, argv);
};
static JSValue editor_interface_class_get_editor_toaster(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&EditorInterface::get_editor_toaster, ctx, this_val, argc, argv);
};
static JSValue editor_interface_class_get_editor_undo_redo(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&EditorInterface::get_editor_undo_redo, ctx, this_val, argc, argv);
};
static JSValue editor_interface_class_make_mesh_previews(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&EditorInterface::make_mesh_previews, ctx, this_val, argc, argv);
};
static JSValue editor_interface_class_set_plugin_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&EditorInterface::set_plugin_enabled, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue editor_interface_class_is_plugin_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&EditorInterface::is_plugin_enabled, ctx, this_val, argc, argv);
};
static JSValue editor_interface_class_get_editor_theme(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&EditorInterface::get_editor_theme, ctx, this_val, argc, argv);
};
static JSValue editor_interface_class_get_base_control(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&EditorInterface::get_base_control, ctx, this_val, argc, argv);
};
static JSValue editor_interface_class_get_editor_main_screen(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&EditorInterface::get_editor_main_screen, ctx, this_val, argc, argv);
};
static JSValue editor_interface_class_get_script_editor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&EditorInterface::get_script_editor, ctx, this_val, argc, argv);
};
static JSValue editor_interface_class_get_editor_viewport_2d(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&EditorInterface::get_editor_viewport_2d, ctx, this_val, argc, argv);
};
static JSValue editor_interface_class_get_editor_viewport_3d(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&EditorInterface::get_editor_viewport_3d, ctx, this_val, argc, argv);
};
static JSValue editor_interface_class_set_main_screen_editor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&EditorInterface::set_main_screen_editor, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue editor_interface_class_set_distraction_free_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&EditorInterface::set_distraction_free_mode, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue editor_interface_class_is_distraction_free_mode_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&EditorInterface::is_distraction_free_mode_enabled, ctx, this_val, argc, argv);
};
static JSValue editor_interface_class_is_multi_window_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&EditorInterface::is_multi_window_enabled, ctx, this_val, argc, argv);
};
static JSValue editor_interface_class_get_editor_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&EditorInterface::get_editor_scale, ctx, this_val, argc, argv);
};
static JSValue editor_interface_class_popup_dialog(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&EditorInterface::popup_dialog, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue editor_interface_class_popup_dialog_centered(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&EditorInterface::popup_dialog_centered, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue editor_interface_class_popup_dialog_centered_ratio(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&EditorInterface::popup_dialog_centered_ratio, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue editor_interface_class_popup_dialog_centered_clamped(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&EditorInterface::popup_dialog_centered_clamped, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue editor_interface_class_get_current_feature_profile(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&EditorInterface::get_current_feature_profile, ctx, this_val, argc, argv);
};
static JSValue editor_interface_class_set_current_feature_profile(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&EditorInterface::set_current_feature_profile, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue editor_interface_class_popup_node_selector(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&EditorInterface::popup_node_selector, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue editor_interface_class_popup_property_selector(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&EditorInterface::popup_property_selector, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue editor_interface_class_popup_method_selector(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&EditorInterface::popup_method_selector, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue editor_interface_class_popup_quick_open(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&EditorInterface::popup_quick_open, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue editor_interface_class_popup_create_dialog(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&EditorInterface::popup_create_dialog, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue editor_interface_class_get_file_system_dock(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&EditorInterface::get_file_system_dock, ctx, this_val, argc, argv);
};
static JSValue editor_interface_class_select_file(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&EditorInterface::select_file, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue editor_interface_class_get_selected_paths(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&EditorInterface::get_selected_paths, ctx, this_val, argc, argv);
};
static JSValue editor_interface_class_get_current_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&EditorInterface::get_current_path, ctx, this_val, argc, argv);
};
static JSValue editor_interface_class_get_current_directory(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&EditorInterface::get_current_directory, ctx, this_val, argc, argv);
};
static JSValue editor_interface_class_get_inspector(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&EditorInterface::get_inspector, ctx, this_val, argc, argv);
};
static JSValue editor_interface_class_inspect_object(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&EditorInterface::inspect_object, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue editor_interface_class_edit_resource(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&EditorInterface::edit_resource, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue editor_interface_class_edit_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&EditorInterface::edit_node, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue editor_interface_class_edit_script(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&EditorInterface::edit_script, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue editor_interface_class_open_scene_from_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&EditorInterface::open_scene_from_path, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue editor_interface_class_reload_scene_from_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&EditorInterface::reload_scene_from_path, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue editor_interface_class_get_open_scenes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&EditorInterface::get_open_scenes, ctx, this_val, argc, argv);
};
static JSValue editor_interface_class_get_open_scene_roots(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&EditorInterface::get_open_scene_roots, ctx, this_val, argc, argv);
};
static JSValue editor_interface_class_get_edited_scene_root(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&EditorInterface::get_edited_scene_root, ctx, this_val, argc, argv);
};
static JSValue editor_interface_class_save_scene(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&EditorInterface::save_scene, ctx, this_val, argc, argv);
};
static JSValue editor_interface_class_save_scene_as(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&EditorInterface::save_scene_as, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue editor_interface_class_save_all_scenes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&EditorInterface::save_all_scenes, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue editor_interface_class_close_scene(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_method_ret(&EditorInterface::close_scene, ctx, this_val, argc, argv);
};
static JSValue editor_interface_class_mark_scene_as_unsaved(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&EditorInterface::mark_scene_as_unsaved, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue editor_interface_class_play_main_scene(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&EditorInterface::play_main_scene, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue editor_interface_class_play_current_scene(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&EditorInterface::play_current_scene, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue editor_interface_class_play_custom_scene(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&EditorInterface::play_custom_scene, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue editor_interface_class_stop_playing_scene(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&EditorInterface::stop_playing_scene, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue editor_interface_class_is_playing_scene(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&EditorInterface::is_playing_scene, ctx, this_val, argc, argv);
};
static JSValue editor_interface_class_get_playing_scene(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&EditorInterface::get_playing_scene, ctx, this_val, argc, argv);
};
static JSValue editor_interface_class_set_movie_maker_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    call_builtin_method_no_ret(&EditorInterface::set_movie_maker_enabled, ctx, this_val, argc, argv);
	return JS_UNDEFINED;
};
static JSValue editor_interface_class_is_movie_maker_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_method_ret(&EditorInterface::is_movie_maker_enabled, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry editor_interface_class_proto_funcs[] = {
	JS_CFUNC_DEF("restart_editor", 1, &editor_interface_class_restart_editor),
	JS_CFUNC_DEF("get_command_palette", 0, &editor_interface_class_get_command_palette),
	JS_CFUNC_DEF("get_resource_filesystem", 0, &editor_interface_class_get_resource_filesystem),
	JS_CFUNC_DEF("get_editor_paths", 0, &editor_interface_class_get_editor_paths),
	JS_CFUNC_DEF("get_resource_previewer", 0, &editor_interface_class_get_resource_previewer),
	JS_CFUNC_DEF("get_selection", 0, &editor_interface_class_get_selection),
	JS_CFUNC_DEF("get_editor_settings", 0, &editor_interface_class_get_editor_settings),
	JS_CFUNC_DEF("get_editor_toaster", 0, &editor_interface_class_get_editor_toaster),
	JS_CFUNC_DEF("get_editor_undo_redo", 0, &editor_interface_class_get_editor_undo_redo),
	JS_CFUNC_DEF("make_mesh_previews", 2, &editor_interface_class_make_mesh_previews),
	JS_CFUNC_DEF("set_plugin_enabled", 2, &editor_interface_class_set_plugin_enabled),
	JS_CFUNC_DEF("is_plugin_enabled", 1, &editor_interface_class_is_plugin_enabled),
	JS_CFUNC_DEF("get_editor_theme", 0, &editor_interface_class_get_editor_theme),
	JS_CFUNC_DEF("get_base_control", 0, &editor_interface_class_get_base_control),
	JS_CFUNC_DEF("get_editor_main_screen", 0, &editor_interface_class_get_editor_main_screen),
	JS_CFUNC_DEF("get_script_editor", 0, &editor_interface_class_get_script_editor),
	JS_CFUNC_DEF("get_editor_viewport_2d", 0, &editor_interface_class_get_editor_viewport_2d),
	JS_CFUNC_DEF("get_editor_viewport_3d", 1, &editor_interface_class_get_editor_viewport_3d),
	JS_CFUNC_DEF("set_main_screen_editor", 1, &editor_interface_class_set_main_screen_editor),
	JS_CFUNC_DEF("set_distraction_free_mode", 1, &editor_interface_class_set_distraction_free_mode),
	JS_CFUNC_DEF("is_distraction_free_mode_enabled", 0, &editor_interface_class_is_distraction_free_mode_enabled),
	JS_CFUNC_DEF("is_multi_window_enabled", 0, &editor_interface_class_is_multi_window_enabled),
	JS_CFUNC_DEF("get_editor_scale", 0, &editor_interface_class_get_editor_scale),
	JS_CFUNC_DEF("popup_dialog", 2, &editor_interface_class_popup_dialog),
	JS_CFUNC_DEF("popup_dialog_centered", 2, &editor_interface_class_popup_dialog_centered),
	JS_CFUNC_DEF("popup_dialog_centered_ratio", 2, &editor_interface_class_popup_dialog_centered_ratio),
	JS_CFUNC_DEF("popup_dialog_centered_clamped", 3, &editor_interface_class_popup_dialog_centered_clamped),
	JS_CFUNC_DEF("get_current_feature_profile", 0, &editor_interface_class_get_current_feature_profile),
	JS_CFUNC_DEF("set_current_feature_profile", 1, &editor_interface_class_set_current_feature_profile),
	JS_CFUNC_DEF("popup_node_selector", 3, &editor_interface_class_popup_node_selector),
	JS_CFUNC_DEF("popup_property_selector", 4, &editor_interface_class_popup_property_selector),
	JS_CFUNC_DEF("popup_method_selector", 3, &editor_interface_class_popup_method_selector),
	JS_CFUNC_DEF("popup_quick_open", 2, &editor_interface_class_popup_quick_open),
	JS_CFUNC_DEF("popup_create_dialog", 5, &editor_interface_class_popup_create_dialog),
	JS_CFUNC_DEF("get_file_system_dock", 0, &editor_interface_class_get_file_system_dock),
	JS_CFUNC_DEF("select_file", 1, &editor_interface_class_select_file),
	JS_CFUNC_DEF("get_selected_paths", 0, &editor_interface_class_get_selected_paths),
	JS_CFUNC_DEF("get_current_path", 0, &editor_interface_class_get_current_path),
	JS_CFUNC_DEF("get_current_directory", 0, &editor_interface_class_get_current_directory),
	JS_CFUNC_DEF("get_inspector", 0, &editor_interface_class_get_inspector),
	JS_CFUNC_DEF("inspect_object", 3, &editor_interface_class_inspect_object),
	JS_CFUNC_DEF("edit_resource", 1, &editor_interface_class_edit_resource),
	JS_CFUNC_DEF("edit_node", 1, &editor_interface_class_edit_node),
	JS_CFUNC_DEF("edit_script", 4, &editor_interface_class_edit_script),
	JS_CFUNC_DEF("open_scene_from_path", 2, &editor_interface_class_open_scene_from_path),
	JS_CFUNC_DEF("reload_scene_from_path", 1, &editor_interface_class_reload_scene_from_path),
	JS_CFUNC_DEF("get_open_scenes", 0, &editor_interface_class_get_open_scenes),
	JS_CFUNC_DEF("get_open_scene_roots", 0, &editor_interface_class_get_open_scene_roots),
	JS_CFUNC_DEF("get_edited_scene_root", 0, &editor_interface_class_get_edited_scene_root),
	JS_CFUNC_DEF("save_scene", 0, &editor_interface_class_save_scene),
	JS_CFUNC_DEF("save_scene_as", 2, &editor_interface_class_save_scene_as),
	JS_CFUNC_DEF("save_all_scenes", 0, &editor_interface_class_save_all_scenes),
	JS_CFUNC_DEF("close_scene", 0, &editor_interface_class_close_scene),
	JS_CFUNC_DEF("mark_scene_as_unsaved", 0, &editor_interface_class_mark_scene_as_unsaved),
	JS_CFUNC_DEF("play_main_scene", 0, &editor_interface_class_play_main_scene),
	JS_CFUNC_DEF("play_current_scene", 0, &editor_interface_class_play_current_scene),
	JS_CFUNC_DEF("play_custom_scene", 1, &editor_interface_class_play_custom_scene),
	JS_CFUNC_DEF("stop_playing_scene", 0, &editor_interface_class_stop_playing_scene),
	JS_CFUNC_DEF("is_playing_scene", 0, &editor_interface_class_is_playing_scene),
	JS_CFUNC_DEF("get_playing_scene", 0, &editor_interface_class_get_playing_scene),
	JS_CFUNC_DEF("set_movie_maker_enabled", 1, &editor_interface_class_set_movie_maker_enabled),
	JS_CFUNC_DEF("is_movie_maker_enabled", 0, &editor_interface_class_is_movie_maker_enabled),
};




static int js_editor_interface_class_init(JSContext *ctx, JSModuleDef *m){
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["_EditorInterface"] = class_id;
	JS_NewClass(JS_GetRuntime(ctx), class_id, &editor_interface_class_def);

	JSValue proto = JS_NewObject(ctx);
	JSValue base_class = JS_GetClassProto(ctx, classes["Object"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	JS_SetPropertyFunctionList(ctx, proto, editor_interface_class_proto_funcs, _countof(editor_interface_class_proto_funcs));

	JSValue ctor = JS_NewCFunction2(ctx, editor_interface_class_constructor, "_EditorInterface", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);


    JSValue singleton = JS_CallConstructor(ctx, ctor, 0, {});
	JS_SetModuleExport(ctx, m, "EditorInterface", singleton);

	return 0;
}

JSModuleDef *_js_init_editor_interface_module(JSContext *ctx, const char *module_name) {
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_editor_interface_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "EditorInterface");
	return m;
}

void register_editor_interface() {
	_js_init_editor_interface_module(js_context(), "@godot/classes/editor_interface");
}