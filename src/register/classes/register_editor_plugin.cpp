#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/button.hpp>
#include <godot_cpp/classes/camera3d.hpp>
#include <godot_cpp/classes/config_file.hpp>
#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/classes/editor_context_menu_plugin.hpp>
#include <godot_cpp/classes/editor_debugger_plugin.hpp>
#include <godot_cpp/classes/editor_export_platform.hpp>
#include <godot_cpp/classes/editor_export_plugin.hpp>
#include <godot_cpp/classes/editor_import_plugin.hpp>
#include <godot_cpp/classes/editor_inspector_plugin.hpp>
#include <godot_cpp/classes/editor_interface.hpp>
#include <godot_cpp/classes/editor_node3d_gizmo_plugin.hpp>
#include <godot_cpp/classes/editor_resource_conversion_plugin.hpp>
#include <godot_cpp/classes/editor_scene_format_importer.hpp>
#include <godot_cpp/classes/editor_scene_post_import_plugin.hpp>
#include <godot_cpp/classes/editor_translation_parser_plugin.hpp>
#include <godot_cpp/classes/editor_undo_redo_manager.hpp>
#include <godot_cpp/classes/input_event.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/popup_menu.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/classes/script.hpp>
#include <godot_cpp/classes/script_create_dialog.hpp>
#include <godot_cpp/classes/shortcut.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/editor_plugin.hpp>
using namespace godot;

static void editor_plugin_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["EditorPlugin"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef editor_plugin_class_def = {
    "EditorPlugin",
    editor_plugin_class_finalizer
};

static JSValue editor_plugin_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["EditorPlugin"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    EditorPlugin *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<EditorPlugin *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(EditorPlugin);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue editor_plugin_class_add_control_to_container(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorPlugin::add_control_to_container, ctx, this_val, argc, argv);
};
static JSValue editor_plugin_class_add_control_to_bottom_panel(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&EditorPlugin::add_control_to_bottom_panel, ctx, this_val, argc, argv);
};
static JSValue editor_plugin_class_add_control_to_dock(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorPlugin::add_control_to_dock, ctx, this_val, argc, argv);
};
static JSValue editor_plugin_class_remove_control_from_docks(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorPlugin::remove_control_from_docks, ctx, this_val, argc, argv);
};
static JSValue editor_plugin_class_remove_control_from_bottom_panel(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorPlugin::remove_control_from_bottom_panel, ctx, this_val, argc, argv);
};
static JSValue editor_plugin_class_remove_control_from_container(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorPlugin::remove_control_from_container, ctx, this_val, argc, argv);
};
static JSValue editor_plugin_class_set_dock_tab_icon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorPlugin::set_dock_tab_icon, ctx, this_val, argc, argv);
};
static JSValue editor_plugin_class_add_tool_menu_item(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorPlugin::add_tool_menu_item, ctx, this_val, argc, argv);
};
static JSValue editor_plugin_class_add_tool_submenu_item(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorPlugin::add_tool_submenu_item, ctx, this_val, argc, argv);
};
static JSValue editor_plugin_class_remove_tool_menu_item(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorPlugin::remove_tool_menu_item, ctx, this_val, argc, argv);
};
static JSValue editor_plugin_class_get_export_as_menu(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&EditorPlugin::get_export_as_menu, ctx, this_val, argc, argv);
};
static JSValue editor_plugin_class_add_custom_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorPlugin::add_custom_type, ctx, this_val, argc, argv);
};
static JSValue editor_plugin_class_remove_custom_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorPlugin::remove_custom_type, ctx, this_val, argc, argv);
};
static JSValue editor_plugin_class_add_autoload_singleton(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorPlugin::add_autoload_singleton, ctx, this_val, argc, argv);
};
static JSValue editor_plugin_class_remove_autoload_singleton(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorPlugin::remove_autoload_singleton, ctx, this_val, argc, argv);
};
static JSValue editor_plugin_class_update_overlays(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorPlugin::update_overlays, ctx, this_val, argc, argv);
};
static JSValue editor_plugin_class_make_bottom_panel_item_visible(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorPlugin::make_bottom_panel_item_visible, ctx, this_val, argc, argv);
};
static JSValue editor_plugin_class_hide_bottom_panel(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorPlugin::hide_bottom_panel, ctx, this_val, argc, argv);
};
static JSValue editor_plugin_class_get_undo_redo(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&EditorPlugin::get_undo_redo, ctx, this_val, argc, argv);
};
static JSValue editor_plugin_class_add_undo_redo_inspector_hook_callback(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorPlugin::add_undo_redo_inspector_hook_callback, ctx, this_val, argc, argv);
};
static JSValue editor_plugin_class_remove_undo_redo_inspector_hook_callback(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorPlugin::remove_undo_redo_inspector_hook_callback, ctx, this_val, argc, argv);
};
static JSValue editor_plugin_class_queue_save_layout(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorPlugin::queue_save_layout, ctx, this_val, argc, argv);
};
static JSValue editor_plugin_class_add_translation_parser_plugin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorPlugin::add_translation_parser_plugin, ctx, this_val, argc, argv);
};
static JSValue editor_plugin_class_remove_translation_parser_plugin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorPlugin::remove_translation_parser_plugin, ctx, this_val, argc, argv);
};
static JSValue editor_plugin_class_add_import_plugin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorPlugin::add_import_plugin, ctx, this_val, argc, argv);
};
static JSValue editor_plugin_class_remove_import_plugin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorPlugin::remove_import_plugin, ctx, this_val, argc, argv);
};
static JSValue editor_plugin_class_add_scene_format_importer_plugin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorPlugin::add_scene_format_importer_plugin, ctx, this_val, argc, argv);
};
static JSValue editor_plugin_class_remove_scene_format_importer_plugin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorPlugin::remove_scene_format_importer_plugin, ctx, this_val, argc, argv);
};
static JSValue editor_plugin_class_add_scene_post_import_plugin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorPlugin::add_scene_post_import_plugin, ctx, this_val, argc, argv);
};
static JSValue editor_plugin_class_remove_scene_post_import_plugin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorPlugin::remove_scene_post_import_plugin, ctx, this_val, argc, argv);
};
static JSValue editor_plugin_class_add_export_plugin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorPlugin::add_export_plugin, ctx, this_val, argc, argv);
};
static JSValue editor_plugin_class_remove_export_plugin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorPlugin::remove_export_plugin, ctx, this_val, argc, argv);
};
static JSValue editor_plugin_class_add_export_platform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorPlugin::add_export_platform, ctx, this_val, argc, argv);
};
static JSValue editor_plugin_class_remove_export_platform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorPlugin::remove_export_platform, ctx, this_val, argc, argv);
};
static JSValue editor_plugin_class_add_node_3d_gizmo_plugin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorPlugin::add_node_3d_gizmo_plugin, ctx, this_val, argc, argv);
};
static JSValue editor_plugin_class_remove_node_3d_gizmo_plugin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorPlugin::remove_node_3d_gizmo_plugin, ctx, this_val, argc, argv);
};
static JSValue editor_plugin_class_add_inspector_plugin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorPlugin::add_inspector_plugin, ctx, this_val, argc, argv);
};
static JSValue editor_plugin_class_remove_inspector_plugin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorPlugin::remove_inspector_plugin, ctx, this_val, argc, argv);
};
static JSValue editor_plugin_class_add_resource_conversion_plugin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorPlugin::add_resource_conversion_plugin, ctx, this_val, argc, argv);
};
static JSValue editor_plugin_class_remove_resource_conversion_plugin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorPlugin::remove_resource_conversion_plugin, ctx, this_val, argc, argv);
};
static JSValue editor_plugin_class_set_input_event_forwarding_always_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorPlugin::set_input_event_forwarding_always_enabled, ctx, this_val, argc, argv);
};
static JSValue editor_plugin_class_set_force_draw_over_forwarding_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorPlugin::set_force_draw_over_forwarding_enabled, ctx, this_val, argc, argv);
};
static JSValue editor_plugin_class_add_context_menu_plugin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorPlugin::add_context_menu_plugin, ctx, this_val, argc, argv);
};
static JSValue editor_plugin_class_remove_context_menu_plugin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorPlugin::remove_context_menu_plugin, ctx, this_val, argc, argv);
};
static JSValue editor_plugin_class_get_editor_interface(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&EditorPlugin::get_editor_interface, ctx, this_val, argc, argv);
};
static JSValue editor_plugin_class_get_script_create_dialog(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&EditorPlugin::get_script_create_dialog, ctx, this_val, argc, argv);
};
static JSValue editor_plugin_class_add_debugger_plugin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorPlugin::add_debugger_plugin, ctx, this_val, argc, argv);
};
static JSValue editor_plugin_class_remove_debugger_plugin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&EditorPlugin::remove_debugger_plugin, ctx, this_val, argc, argv);
};
static JSValue editor_plugin_class_get_plugin_version(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&EditorPlugin::get_plugin_version, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry editor_plugin_class_proto_funcs[] = {
	JS_CFUNC_DEF("add_control_to_container", 2, &editor_plugin_class_add_control_to_container),
	JS_CFUNC_DEF("add_control_to_bottom_panel", 3, &editor_plugin_class_add_control_to_bottom_panel),
	JS_CFUNC_DEF("add_control_to_dock", 3, &editor_plugin_class_add_control_to_dock),
	JS_CFUNC_DEF("remove_control_from_docks", 1, &editor_plugin_class_remove_control_from_docks),
	JS_CFUNC_DEF("remove_control_from_bottom_panel", 1, &editor_plugin_class_remove_control_from_bottom_panel),
	JS_CFUNC_DEF("remove_control_from_container", 2, &editor_plugin_class_remove_control_from_container),
	JS_CFUNC_DEF("set_dock_tab_icon", 2, &editor_plugin_class_set_dock_tab_icon),
	JS_CFUNC_DEF("add_tool_menu_item", 2, &editor_plugin_class_add_tool_menu_item),
	JS_CFUNC_DEF("add_tool_submenu_item", 2, &editor_plugin_class_add_tool_submenu_item),
	JS_CFUNC_DEF("remove_tool_menu_item", 1, &editor_plugin_class_remove_tool_menu_item),
	JS_CFUNC_DEF("get_export_as_menu", 0, &editor_plugin_class_get_export_as_menu),
	JS_CFUNC_DEF("add_custom_type", 4, &editor_plugin_class_add_custom_type),
	JS_CFUNC_DEF("remove_custom_type", 1, &editor_plugin_class_remove_custom_type),
	JS_CFUNC_DEF("add_autoload_singleton", 2, &editor_plugin_class_add_autoload_singleton),
	JS_CFUNC_DEF("remove_autoload_singleton", 1, &editor_plugin_class_remove_autoload_singleton),
	JS_CFUNC_DEF("update_overlays", 0, &editor_plugin_class_update_overlays),
	JS_CFUNC_DEF("make_bottom_panel_item_visible", 1, &editor_plugin_class_make_bottom_panel_item_visible),
	JS_CFUNC_DEF("hide_bottom_panel", 0, &editor_plugin_class_hide_bottom_panel),
	JS_CFUNC_DEF("get_undo_redo", 0, &editor_plugin_class_get_undo_redo),
	JS_CFUNC_DEF("add_undo_redo_inspector_hook_callback", 1, &editor_plugin_class_add_undo_redo_inspector_hook_callback),
	JS_CFUNC_DEF("remove_undo_redo_inspector_hook_callback", 1, &editor_plugin_class_remove_undo_redo_inspector_hook_callback),
	JS_CFUNC_DEF("queue_save_layout", 0, &editor_plugin_class_queue_save_layout),
	JS_CFUNC_DEF("add_translation_parser_plugin", 1, &editor_plugin_class_add_translation_parser_plugin),
	JS_CFUNC_DEF("remove_translation_parser_plugin", 1, &editor_plugin_class_remove_translation_parser_plugin),
	JS_CFUNC_DEF("add_import_plugin", 2, &editor_plugin_class_add_import_plugin),
	JS_CFUNC_DEF("remove_import_plugin", 1, &editor_plugin_class_remove_import_plugin),
	JS_CFUNC_DEF("add_scene_format_importer_plugin", 2, &editor_plugin_class_add_scene_format_importer_plugin),
	JS_CFUNC_DEF("remove_scene_format_importer_plugin", 1, &editor_plugin_class_remove_scene_format_importer_plugin),
	JS_CFUNC_DEF("add_scene_post_import_plugin", 2, &editor_plugin_class_add_scene_post_import_plugin),
	JS_CFUNC_DEF("remove_scene_post_import_plugin", 1, &editor_plugin_class_remove_scene_post_import_plugin),
	JS_CFUNC_DEF("add_export_plugin", 1, &editor_plugin_class_add_export_plugin),
	JS_CFUNC_DEF("remove_export_plugin", 1, &editor_plugin_class_remove_export_plugin),
	JS_CFUNC_DEF("add_export_platform", 1, &editor_plugin_class_add_export_platform),
	JS_CFUNC_DEF("remove_export_platform", 1, &editor_plugin_class_remove_export_platform),
	JS_CFUNC_DEF("add_node_3d_gizmo_plugin", 1, &editor_plugin_class_add_node_3d_gizmo_plugin),
	JS_CFUNC_DEF("remove_node_3d_gizmo_plugin", 1, &editor_plugin_class_remove_node_3d_gizmo_plugin),
	JS_CFUNC_DEF("add_inspector_plugin", 1, &editor_plugin_class_add_inspector_plugin),
	JS_CFUNC_DEF("remove_inspector_plugin", 1, &editor_plugin_class_remove_inspector_plugin),
	JS_CFUNC_DEF("add_resource_conversion_plugin", 1, &editor_plugin_class_add_resource_conversion_plugin),
	JS_CFUNC_DEF("remove_resource_conversion_plugin", 1, &editor_plugin_class_remove_resource_conversion_plugin),
	JS_CFUNC_DEF("set_input_event_forwarding_always_enabled", 0, &editor_plugin_class_set_input_event_forwarding_always_enabled),
	JS_CFUNC_DEF("set_force_draw_over_forwarding_enabled", 0, &editor_plugin_class_set_force_draw_over_forwarding_enabled),
	JS_CFUNC_DEF("add_context_menu_plugin", 2, &editor_plugin_class_add_context_menu_plugin),
	JS_CFUNC_DEF("remove_context_menu_plugin", 1, &editor_plugin_class_remove_context_menu_plugin),
	JS_CFUNC_DEF("get_editor_interface", 0, &editor_plugin_class_get_editor_interface),
	JS_CFUNC_DEF("get_script_create_dialog", 0, &editor_plugin_class_get_script_create_dialog),
	JS_CFUNC_DEF("add_debugger_plugin", 1, &editor_plugin_class_add_debugger_plugin),
	JS_CFUNC_DEF("remove_debugger_plugin", 1, &editor_plugin_class_remove_debugger_plugin),
	JS_CFUNC_DEF("get_plugin_version", 0, &editor_plugin_class_get_plugin_version),
};


static JSValue editor_plugin_class_get_scene_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	EditorPlugin *opaque = static_cast<EditorPlugin *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "scene_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "scene_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "scene_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue editor_plugin_class_get_scene_closed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	EditorPlugin *opaque = static_cast<EditorPlugin *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "scene_closed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "scene_closed"));
		JS_DefinePropertyValueStr(ctx, this_val, "scene_closed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue editor_plugin_class_get_main_screen_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	EditorPlugin *opaque = static_cast<EditorPlugin *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "main_screen_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "main_screen_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "main_screen_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue editor_plugin_class_get_resource_saved_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	EditorPlugin *opaque = static_cast<EditorPlugin *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "resource_saved_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "resource_saved"));
		JS_DefinePropertyValueStr(ctx, this_val, "resource_saved_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue editor_plugin_class_get_scene_saved_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	EditorPlugin *opaque = static_cast<EditorPlugin *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "scene_saved_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "scene_saved"));
		JS_DefinePropertyValueStr(ctx, this_val, "scene_saved_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue editor_plugin_class_get_project_settings_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	EditorPlugin *opaque = static_cast<EditorPlugin *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "project_settings_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "project_settings_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "project_settings_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_editor_plugin_property(JSContext *ctx, JSValue proto) {
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "scene_changed"),
		JS_NewCFunction(ctx, editor_plugin_class_get_scene_changed_signal, "get_scene_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "scene_closed"),
		JS_NewCFunction(ctx, editor_plugin_class_get_scene_closed_signal, "get_scene_closed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "main_screen_changed"),
		JS_NewCFunction(ctx, editor_plugin_class_get_main_screen_changed_signal, "get_main_screen_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "resource_saved"),
		JS_NewCFunction(ctx, editor_plugin_class_get_resource_saved_signal, "get_resource_saved_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "scene_saved"),
		JS_NewCFunction(ctx, editor_plugin_class_get_scene_saved_signal, "get_scene_saved_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "project_settings_changed"),
		JS_NewCFunction(ctx, editor_plugin_class_get_project_settings_changed_signal, "get_project_settings_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_editor_plugin_enum(JSContext *ctx, JSValue ctor) {
	JSValue CustomControlContainer_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, CustomControlContainer_obj, "CONTAINER_TOOLBAR", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, CustomControlContainer_obj, "CONTAINER_SPATIAL_EDITOR_MENU", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, CustomControlContainer_obj, "CONTAINER_SPATIAL_EDITOR_SIDE_LEFT", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, CustomControlContainer_obj, "CONTAINER_SPATIAL_EDITOR_SIDE_RIGHT", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, CustomControlContainer_obj, "CONTAINER_SPATIAL_EDITOR_BOTTOM", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, CustomControlContainer_obj, "CONTAINER_CANVAS_EDITOR_MENU", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, CustomControlContainer_obj, "CONTAINER_CANVAS_EDITOR_SIDE_LEFT", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, CustomControlContainer_obj, "CONTAINER_CANVAS_EDITOR_SIDE_RIGHT", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, CustomControlContainer_obj, "CONTAINER_CANVAS_EDITOR_BOTTOM", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, CustomControlContainer_obj, "CONTAINER_INSPECTOR_BOTTOM", JS_NewInt64(ctx, 9));
	JS_SetPropertyStr(ctx, CustomControlContainer_obj, "CONTAINER_PROJECT_SETTING_TAB_LEFT", JS_NewInt64(ctx, 10));
	JS_SetPropertyStr(ctx, CustomControlContainer_obj, "CONTAINER_PROJECT_SETTING_TAB_RIGHT", JS_NewInt64(ctx, 11));
	JS_SetPropertyStr(ctx, ctor, "CustomControlContainer", CustomControlContainer_obj);
	JSValue DockSlot_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, DockSlot_obj, "DOCK_SLOT_LEFT_UL", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, DockSlot_obj, "DOCK_SLOT_LEFT_BL", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, DockSlot_obj, "DOCK_SLOT_LEFT_UR", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, DockSlot_obj, "DOCK_SLOT_LEFT_BR", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, DockSlot_obj, "DOCK_SLOT_RIGHT_UL", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, DockSlot_obj, "DOCK_SLOT_RIGHT_BL", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, DockSlot_obj, "DOCK_SLOT_RIGHT_UR", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, DockSlot_obj, "DOCK_SLOT_RIGHT_BR", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, DockSlot_obj, "DOCK_SLOT_MAX", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, ctor, "DockSlot", DockSlot_obj);
	JSValue AfterGUIInput_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, AfterGUIInput_obj, "AFTER_GUI_INPUT_PASS", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, AfterGUIInput_obj, "AFTER_GUI_INPUT_STOP", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, AfterGUIInput_obj, "AFTER_GUI_INPUT_CUSTOM", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "AfterGUIInput", AfterGUIInput_obj);
}

static int js_editor_plugin_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["EditorPlugin"] = class_id;
	classes_by_id[class_id] = "EditorPlugin";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &editor_plugin_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_editor_plugin_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, editor_plugin_class_proto_funcs, _countof(editor_plugin_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, editor_plugin_class_constructor, "EditorPlugin", 0, JS_CFUNC_constructor, 0);
	define_editor_plugin_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "EditorPlugin", ctor);

	return 0;
}

JSModuleDef *_js_init_editor_plugin_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_editor_plugin_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "EditorPlugin");
	return m;
}

JSModuleDef *js_init_editor_plugin_module(JSContext *ctx) {
	return _js_init_editor_plugin_module(ctx, "@godot/classes/editor_plugin");
}

void __register_editor_plugin() {
	js_init_editor_plugin_module(js_context());
}

void register_editor_plugin() {
	__register_editor_plugin();
}