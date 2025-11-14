
import type { EditorExportPlatform } from '@godot/classes/editor_export_platform';
import type { EditorExportPreset } from '@godot/classes/editor_export_preset';
import type { GDString } from '@godot/builtins/gd_string';
import type { PackedStringArray } from '@godot/builtins/packed_string_array';
import type { StringName } from '@godot/builtins/string_name';
import type { Texture2D } from '@godot/classes/texture2d';


export declare class EditorExportPlatformExtension extends EditorExportPlatform {


    public _get_preset_features(preset: EditorExportPreset): PackedStringArray;
    public _is_executable(path: GDString | StringName | string): boolean;
    public _get_export_options(): Array<any>;
    public _should_update_export_options(): boolean;
    public _get_export_option_visibility(preset: EditorExportPreset, option: GDString | StringName | string): boolean;
    public _get_export_option_warning(preset: EditorExportPreset, option: GDString | StringName | string): GDString;
    public _get_os_name(): GDString;
    public _get_name(): GDString;
    public _get_logo(): Texture2D;
    public _poll_export(): boolean;
    public _get_options_count(): number;
    public _get_options_tooltip(): GDString;
    public _get_option_icon(device: number): Texture2D;
    public _get_option_label(device: number): GDString;
    public _get_option_tooltip(device: number): GDString;
    public _get_device_architecture(device: number): GDString;
    public _cleanup(): void;
    public _run(preset: EditorExportPreset, device: number, debugFlags: number): number;
    public _get_run_icon(): Texture2D;
    public _can_export(preset: EditorExportPreset, debug: boolean): boolean;
    public _has_valid_export_configuration(preset: EditorExportPreset, debug: boolean): boolean;
    public _has_valid_project_configuration(preset: EditorExportPreset): boolean;
    public _get_binary_extensions(preset: EditorExportPreset): PackedStringArray;
    public _export_project(preset: EditorExportPreset, debug: boolean, path: GDString | StringName | string, flags: number): number;
    public _export_pack(preset: EditorExportPreset, debug: boolean, path: GDString | StringName | string, flags: number): number;
    public _export_zip(preset: EditorExportPreset, debug: boolean, path: GDString | StringName | string, flags: number): number;
    public _export_pack_patch(preset: EditorExportPreset, debug: boolean, path: GDString | StringName | string, patches: PackedStringArray, flags: number): number;
    public _export_zip_patch(preset: EditorExportPreset, debug: boolean, path: GDString | StringName | string, patches: PackedStringArray, flags: number): number;
    public _get_platform_features(): PackedStringArray;
    public _get_debug_protocol(): GDString;
    public set_config_error(errorText: GDString | StringName | string): void;
    public get_config_error(): GDString;
    public set_config_missing_templates(missingTemplates: boolean): void;
    public get_config_missing_templates(): boolean;


}

