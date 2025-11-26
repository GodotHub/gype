
import type { Button } from '@godot/classes/button';
import type { Camera3D } from '@godot/classes/camera3d';
import type { ConfigFile } from '@godot/classes/config_file';
import type { Control } from '@godot/classes/control';
import type { EditorContextMenuPlugin } from '@godot/classes/editor_context_menu_plugin';
import type { EditorDebuggerPlugin } from '@godot/classes/editor_debugger_plugin';
import type { EditorExportPlatform } from '@godot/classes/editor_export_platform';
import type { EditorExportPlugin } from '@godot/classes/editor_export_plugin';
import type { EditorImportPlugin } from '@godot/classes/editor_import_plugin';
import type { EditorInspectorPlugin } from '@godot/classes/editor_inspector_plugin';
import type { EditorInterface } from '@godot/classes/editor_interface';
import type { EditorNode3DGizmoPlugin } from '@godot/classes/editor_node3d_gizmo_plugin';
import type { EditorResourceConversionPlugin } from '@godot/classes/editor_resource_conversion_plugin';
import type { EditorSceneFormatImporter } from '@godot/classes/editor_scene_format_importer';
import type { EditorScenePostImportPlugin } from '@godot/classes/editor_scene_post_import_plugin';
import type { EditorTranslationParserPlugin } from '@godot/classes/editor_translation_parser_plugin';
import type { EditorUndoRedoManager } from '@godot/classes/editor_undo_redo_manager';
import type { GodotObject } from '@godot/classes/godot_object';
import type { InputEvent } from '@godot/classes/input_event';
import type { Node } from '@godot/classes/node';
import type { PopupMenu } from '@godot/classes/popup_menu';
import type { Resource } from '@godot/classes/resource';
import type { Script } from '@godot/classes/script';
import type { ScriptCreateDialog } from '@godot/classes/script_create_dialog';
import type { Shortcut } from '@godot/classes/shortcut';
import type { Texture2D } from '@godot/classes/texture2d';


export declare class EditorPlugin extends Node {


    public _forward_canvas_gui_input(event: InputEvent): boolean;
    public _forward_canvas_draw_over_viewport(viewportControl: Control): void;
    public _forward_canvas_force_draw_over_viewport(viewportControl: Control): void;
    public _forward_3d_gui_input(viewportCamera: Camera3D, event: InputEvent): number;
    public _forward_3d_draw_over_viewport(viewportControl: Control): void;
    public _forward_3d_force_draw_over_viewport(viewportControl: Control): void;
    public _get_plugin_name(): GDString;
    public _get_plugin_icon(): Texture2D;
    public _has_main_screen(): boolean;
    public _make_visible(visible: boolean): void;
    public _edit(object: GodotObject): void;
    public _handles(object: GodotObject): boolean;
    public _get_state(): Dictionary;
    public _set_state(state: Dictionary): void;
    public _clear(): void;
    public _get_unsaved_status(forScene: GDString | StringName | string): GDString;
    public _save_external_data(): void;
    public _apply_changes(): void;
    public _get_breakpoints(): PackedStringArray;
    public _set_window_layout(configuration: ConfigFile): void;
    public _get_window_layout(configuration: ConfigFile): void;
    public _build(): boolean;
    public _enable_plugin(): void;
    public _disable_plugin(): void;
    public add_control_to_container(container: number, control: Control): void;
    public add_control_to_bottom_panel(control: Control, title: GDString | StringName | string, shortcut: Shortcut = null): Button;
    public add_control_to_dock(slot: number, control: Control, shortcut: Shortcut = null): void;
    public remove_control_from_docks(control: Control): void;
    public remove_control_from_bottom_panel(control: Control): void;
    public remove_control_from_container(container: number, control: Control): void;
    public set_dock_tab_icon(control: Control, icon: Texture2D): void;
    public add_tool_menu_item(name: GDString | StringName | string, callable: Callable | Function): void;
    public add_tool_submenu_item(name: GDString | StringName | string, submenu: PopupMenu): void;
    public remove_tool_menu_item(name: GDString | StringName | string): void;
    public get_export_as_menu(): PopupMenu;
    public add_custom_type(_type: GDString | StringName | string, base: GDString | StringName | string, script: Script, icon: Texture2D): void;
    public remove_custom_type(_type: GDString | StringName | string): void;
    public add_autoload_singleton(name: GDString | StringName | string, path: GDString | StringName | string): void;
    public remove_autoload_singleton(name: GDString | StringName | string): void;
    public update_overlays(): number;
    public make_bottom_panel_item_visible(item: Control): void;
    public hide_bottom_panel(): void;
    public get_undo_redo(): EditorUndoRedoManager;
    public add_undo_redo_inspector_hook_callback(callable: Callable | Function): void;
    public remove_undo_redo_inspector_hook_callback(callable: Callable | Function): void;
    public queue_save_layout(): void;
    public add_translation_parser_plugin(parser: EditorTranslationParserPlugin): void;
    public remove_translation_parser_plugin(parser: EditorTranslationParserPlugin): void;
    public add_import_plugin(importer: EditorImportPlugin, firstPriority: boolean = false): void;
    public remove_import_plugin(importer: EditorImportPlugin): void;
    public add_scene_format_importer_plugin(sceneFormatImporter: EditorSceneFormatImporter, firstPriority: boolean = false): void;
    public remove_scene_format_importer_plugin(sceneFormatImporter: EditorSceneFormatImporter): void;
    public add_scene_post_import_plugin(sceneImportPlugin: EditorScenePostImportPlugin, firstPriority: boolean = false): void;
    public remove_scene_post_import_plugin(sceneImportPlugin: EditorScenePostImportPlugin): void;
    public add_export_plugin(plugin: EditorExportPlugin): void;
    public remove_export_plugin(plugin: EditorExportPlugin): void;
    public add_export_platform(platform: EditorExportPlatform): void;
    public remove_export_platform(platform: EditorExportPlatform): void;
    public add_node_3d_gizmo_plugin(plugin: EditorNode3DGizmoPlugin): void;
    public remove_node_3d_gizmo_plugin(plugin: EditorNode3DGizmoPlugin): void;
    public add_inspector_plugin(plugin: EditorInspectorPlugin): void;
    public remove_inspector_plugin(plugin: EditorInspectorPlugin): void;
    public add_resource_conversion_plugin(plugin: EditorResourceConversionPlugin): void;
    public remove_resource_conversion_plugin(plugin: EditorResourceConversionPlugin): void;
    public set_input_event_forwarding_always_enabled(): void;
    public set_force_draw_over_forwarding_enabled(): void;
    public add_context_menu_plugin(slot: number, plugin: EditorContextMenuPlugin): void;
    public remove_context_menu_plugin(plugin: EditorContextMenuPlugin): void;
    public get_editor_interface(): EditorInterface;
    public get_script_create_dialog(): ScriptCreateDialog;
    public add_debugger_plugin(script: EditorDebuggerPlugin): void;
    public remove_debugger_plugin(script: EditorDebuggerPlugin): void;
    public get_plugin_version(): GDString;

    
    public readonly scene_changed: Signal;
    public readonly scene_closed: Signal;
    public readonly main_screen_changed: Signal;
    public readonly resource_saved: Signal;
    public readonly scene_saved: Signal;
    public readonly project_settings_changed: Signal;

    public static readonly CustomControlContainer: {
        CONTAINER_TOOLBAR: 0;
        CONTAINER_SPATIAL_EDITOR_MENU: 1;
        CONTAINER_SPATIAL_EDITOR_SIDE_LEFT: 2;
        CONTAINER_SPATIAL_EDITOR_SIDE_RIGHT: 3;
        CONTAINER_SPATIAL_EDITOR_BOTTOM: 4;
        CONTAINER_CANVAS_EDITOR_MENU: 5;
        CONTAINER_CANVAS_EDITOR_SIDE_LEFT: 6;
        CONTAINER_CANVAS_EDITOR_SIDE_RIGHT: 7;
        CONTAINER_CANVAS_EDITOR_BOTTOM: 8;
        CONTAINER_INSPECTOR_BOTTOM: 9;
        CONTAINER_PROJECT_SETTING_TAB_LEFT: 10;
        CONTAINER_PROJECT_SETTING_TAB_RIGHT: 11;
    };
    public static readonly DockSlot: {
        DOCK_SLOT_LEFT_UL: 0;
        DOCK_SLOT_LEFT_BL: 1;
        DOCK_SLOT_LEFT_UR: 2;
        DOCK_SLOT_LEFT_BR: 3;
        DOCK_SLOT_RIGHT_UL: 4;
        DOCK_SLOT_RIGHT_BL: 5;
        DOCK_SLOT_RIGHT_UR: 6;
        DOCK_SLOT_RIGHT_BR: 7;
        DOCK_SLOT_MAX: 8;
    };
    public static readonly AfterGUIInput: {
        AFTER_GUI_INPUT_PASS: 0;
        AFTER_GUI_INPUT_STOP: 1;
        AFTER_GUI_INPUT_CUSTOM: 2;
    };
}

