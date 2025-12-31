
import type { Control } from '@godot/classes/control';
import type { EditorCommandPalette } from '@godot/classes/editor_command_palette';
import type { EditorFileSystem } from '@godot/classes/editor_file_system';
import type { EditorInspector } from '@godot/classes/editor_inspector';
import type { EditorPaths } from '@godot/classes/editor_paths';
import type { EditorResourcePreview } from '@godot/classes/editor_resource_preview';
import type { EditorSelection } from '@godot/classes/editor_selection';
import type { EditorSettings } from '@godot/classes/editor_settings';
import type { EditorToaster } from '@godot/classes/editor_toaster';
import type { EditorUndoRedoManager } from '@godot/classes/editor_undo_redo_manager';
import type { FileSystemDock } from '@godot/classes/file_system_dock';
import type { GodotObject } from '@godot/classes/godot_object';
import type { Node } from '@godot/classes/node';
import type { Resource } from '@godot/classes/resource';
import type { Script } from '@godot/classes/script';
import type { ScriptEditor } from '@godot/classes/script_editor';
import type { SubViewport } from '@godot/classes/sub_viewport';
import type { Theme } from '@godot/classes/theme';
import type { VBoxContainer } from '@godot/classes/v_box_container';
import type { Window } from '@godot/classes/window';


export declare class _EditorInterface extends GodotObject {

    
    /**     * The raw type is 'bool'     */
    public distraction_free_mode: boolean;    
    /**     * The raw type is 'bool'     */
    public movie_maker_enabled: boolean;
    public restart_editor(save: boolean = true): void;
    public get_command_palette(): EditorCommandPalette;
    public get_resource_filesystem(): EditorFileSystem;
    public get_editor_paths(): EditorPaths;
    public get_resource_previewer(): EditorResourcePreview;
    public get_selection(): EditorSelection;
    public get_editor_settings(): EditorSettings;
    public get_editor_toaster(): EditorToaster;
    public get_editor_undo_redo(): EditorUndoRedoManager;
    public make_mesh_previews(meshes: Array<any>, previewSize: number): Array<any>;
    public set_plugin_enabled(plugin: GDString | StringName | string, enabled: boolean): void;
    public is_plugin_enabled(plugin: GDString | StringName | string): boolean;
    public get_editor_theme(): Theme;
    public get_base_control(): Control;
    public get_editor_main_screen(): VBoxContainer;
    public get_script_editor(): ScriptEditor;
    public get_editor_viewport_2d(): SubViewport;
    public get_editor_viewport_3d(idx: number = 0): SubViewport;
    public set_main_screen_editor(name: GDString | StringName | string): void;
    public set_distraction_free_mode(enter: boolean): void;
    public is_distraction_free_mode_enabled(): boolean;
    public is_multi_window_enabled(): boolean;
    public get_editor_scale(): number;
    public popup_dialog(dialog: Window, rect: Rect2i = Rect2i(0, 0, 0, 0)): void;
    public popup_dialog_centered(dialog: Window, minsize: Vector2i = Vector2i(0, 0)): void;
    public popup_dialog_centered_ratio(dialog: Window, ratio: number = 0.8): void;
    public popup_dialog_centered_clamped(dialog: Window, minsize: Vector2i = Vector2i(0, 0), fallbackRatio: number = 0.75): void;
    public get_current_feature_profile(): GDString;
    public set_current_feature_profile(profileName: GDString | StringName | string): void;
    public popup_node_selector(callback: Callable | Function, validTypes: Array<any> = Array[StringName]([]), currentValue: Node = null): void;
    public popup_property_selector(object: GodotObject, callback: Callable | Function, typeFilter: PackedInt32Array = PackedInt32Array(), currentValue: GDString | StringName | string = ""): void;
    public popup_method_selector(object: GodotObject, callback: Callable | Function, currentValue: GDString | StringName | string = ""): void;
    public popup_quick_open(callback: Callable | Function, baseTypes: Array<any> = Array[StringName]([])): void;
    public popup_create_dialog(callback: Callable | Function, baseType: GDString | StringName | string = "", currentType: GDString | StringName | string = "", dialogTitle: GDString | StringName | string = "", typeBlocklist: Array<any> = Array[StringName]([])): void;
    public get_file_system_dock(): FileSystemDock;
    public select_file(file: GDString | StringName | string): void;
    public get_selected_paths(): PackedStringArray;
    public get_current_path(): GDString;
    public get_current_directory(): GDString;
    public get_inspector(): EditorInspector;
    public inspect_object(object: GodotObject, forProperty: GDString | StringName | string = "", inspectorOnly: boolean = false): void;
    public edit_resource(resource: Resource): void;
    public edit_node(node: Node): void;
    public edit_script(script: Script, line: number = -1, column: number = 0, grabFocus: boolean = true): void;
    public open_scene_from_path(sceneFilepath: GDString | StringName | string, setInherited: boolean = false): void;
    public reload_scene_from_path(sceneFilepath: GDString | StringName | string): void;
    public get_open_scenes(): PackedStringArray;
    public get_open_scene_roots(): Array<any>;
    public get_edited_scene_root(): Node;
    public save_scene(): number;
    public save_scene_as(path: GDString | StringName | string, withPreview: boolean = true): void;
    public save_all_scenes(): void;
    public close_scene(): number;
    public mark_scene_as_unsaved(): void;
    public play_main_scene(): void;
    public play_current_scene(): void;
    public play_custom_scene(sceneFilepath: GDString | StringName | string): void;
    public stop_playing_scene(): void;
    public is_playing_scene(): boolean;
    public get_playing_scene(): GDString;
    public set_movie_maker_enabled(enabled: boolean): void;
    public is_movie_maker_enabled(): boolean;


}

export const EditorInterface: _EditorInterface;
