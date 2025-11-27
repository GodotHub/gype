
import type { EditorExportPreset } from '@godot/classes/editor_export_preset';
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class EditorExportPlatform extends RefCounted {


    public get_os_name(): GDString;
    public create_preset(): EditorExportPreset;
    public find_export_template(templateFileName: GDString | StringName | string): Dictionary;
    public get_current_presets(): GDArray;
    public save_pack(preset: EditorExportPreset, debug: boolean, path: GDString | StringName | string, embed: boolean = false): Dictionary;
    public save_zip(preset: EditorExportPreset, debug: boolean, path: GDString | StringName | string): Dictionary;
    public save_pack_patch(preset: EditorExportPreset, debug: boolean, path: GDString | StringName | string): Dictionary;
    public save_zip_patch(preset: EditorExportPreset, debug: boolean, path: GDString | StringName | string): Dictionary;
    public gen_export_flags(flags: number): PackedStringArray;
    public export_project_files(preset: EditorExportPreset, debug: boolean, saveCb: Callable | Function, sharedCb: Callable | Function = Callable()): number;
    public export_project(preset: EditorExportPreset, debug: boolean, path: GDString | StringName | string, flags: number = 0): number;
    public export_pack(preset: EditorExportPreset, debug: boolean, path: GDString | StringName | string, flags: number = 0): number;
    public export_zip(preset: EditorExportPreset, debug: boolean, path: GDString | StringName | string, flags: number = 0): number;
    public export_pack_patch(preset: EditorExportPreset, debug: boolean, path: GDString | StringName | string, patches: PackedStringArray = PackedStringArray(), flags: number = 0): number;
    public export_zip_patch(preset: EditorExportPreset, debug: boolean, path: GDString | StringName | string, patches: PackedStringArray = PackedStringArray(), flags: number = 0): number;
    public clear_messages(): void;
    public add_message(_type: number, category: GDString | StringName | string, message: GDString | StringName | string): void;
    public get_message_count(): number;
    public get_message_type(index: number): number;
    public get_message_category(index: number): GDString;
    public get_message_text(index: number): GDString;
    public get_worst_message_type(): number;
    public ssh_run_on_remote(host: GDString | StringName | string, port: GDString | StringName | string, sshArg: PackedStringArray, cmdArgs: GDString | StringName | string, output: GDArray | Array = [], portFwd: number = -1): number;
    public ssh_run_on_remote_no_wait(host: GDString | StringName | string, port: GDString | StringName | string, sshArgs: PackedStringArray, cmdArgs: GDString | StringName | string, portFwd: number = -1): number;
    public ssh_push_to_remote(host: GDString | StringName | string, port: GDString | StringName | string, scargs: PackedStringArray, srcFile: GDString | StringName | string, dstFile: GDString | StringName | string): number;
    public get_internal_export_files(preset: EditorExportPreset, debug: boolean): Dictionary;
    public static get_forced_export_files(preset: EditorExportPreset = null): PackedStringArray;


    public static readonly ExportMessageType: {
        EXPORT_MESSAGE_NONE: 0;
        EXPORT_MESSAGE_INFO: 1;
        EXPORT_MESSAGE_WARNING: 2;
        EXPORT_MESSAGE_ERROR: 3;
    };
    public static readonly DebugFlags: {
        DEBUG_FLAG_DUMB_CLIENT: 1;
        DEBUG_FLAG_REMOTE_DEBUG: 2;
        DEBUG_FLAG_REMOTE_DEBUG_LOCALHOST: 4;
        DEBUG_FLAG_VIEW_COLLISIONS: 8;
        DEBUG_FLAG_VIEW_NAVIGATION: 16;
    };
}

