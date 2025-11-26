
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class EditorExportPreset extends RefCounted {


    public has(property: GDString | StringName | string): boolean;
    public get_files_to_export(): PackedStringArray;
    public get_customized_files(): Dictionary;
    public get_customized_files_count(): number;
    public has_export_file(path: GDString | StringName | string): boolean;
    public get_file_export_mode(path: GDString | StringName | string, _default: number = 0): number;
    public get_project_setting(name: GDString | StringName | string): any;
    public get_preset_name(): GDString;
    public is_runnable(): boolean;
    public are_advanced_options_enabled(): boolean;
    public is_dedicated_server(): boolean;
    public get_export_filter(): number;
    public get_include_filter(): GDString;
    public get_exclude_filter(): GDString;
    public get_custom_features(): GDString;
    public get_patches(): PackedStringArray;
    public get_export_path(): GDString;
    public get_encryption_in_filter(): GDString;
    public get_encryption_ex_filter(): GDString;
    public get_encrypt_pck(): boolean;
    public get_encrypt_directory(): boolean;
    public get_encryption_key(): GDString;
    public get_script_export_mode(): number;
    public get_or_env(name: GDString | StringName | string, envVar: GDString | StringName | string): any;
    public get_version(name: GDString | StringName | string, windowsVersion: boolean): GDString;


    public static readonly ExportFilter: {
        EXPORT_ALL_RESOURCES: 0;
        EXPORT_SELECTED_SCENES: 1;
        EXPORT_SELECTED_RESOURCES: 2;
        EXCLUDE_SELECTED_RESOURCES: 3;
        EXPORT_CUSTOMIZED: 4;
    };
    public static readonly FileExportMode: {
        MODE_FILE_NOT_CUSTOMIZED: 0;
        MODE_FILE_STRIP: 1;
        MODE_FILE_KEEP: 2;
        MODE_FILE_REMOVE: 3;
    };
    public static readonly ScriptExportMode: {
        MODE_SCRIPT_TEXT: 0;
        MODE_SCRIPT_BINARY_TOKENS: 1;
        MODE_SCRIPT_BINARY_TOKENS_COMPRESSED: 2;
    };
}

