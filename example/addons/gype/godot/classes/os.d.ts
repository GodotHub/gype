
import type { GodotObject } from '@godot/classes/godot_object';
import type { Logger } from '@godot/classes/logger';


export declare class OS extends GodotObject {

    
    /**     * The raw type is 'bool'     */
    public low_processor_usage_mode: boolean;    
    /**     * The raw type is 'int'     */
    public low_processor_usage_mode_sleep_usec: number;    
    /**     * The raw type is 'bool'     */
    public delta_smoothing: boolean;
    public get_entropy(size: number): PackedByteArray;
    public get_system_ca_certificates(): GDString;
    public get_connected_midi_inputs(): PackedStringArray;
    public open_midi_inputs(): void;
    public close_midi_inputs(): void;
    public alert(text: GDString | StringName | string, title: GDString | StringName | string = "Alert!"): void;
    public crash(message: GDString | StringName | string): void;
    public set_low_processor_usage_mode(enable: boolean): void;
    public is_in_low_processor_usage_mode(): boolean;
    public set_low_processor_usage_mode_sleep_usec(usec: number): void;
    public get_low_processor_usage_mode_sleep_usec(): number;
    public set_delta_smoothing(deltaSmoothingEnabled: boolean): void;
    public is_delta_smoothing_enabled(): boolean;
    public get_processor_count(): number;
    public get_processor_name(): GDString;
    public get_system_fonts(): PackedStringArray;
    public get_system_font_path(fontName: GDString | StringName | string, weight: number = 400, stretch: number = 100, italic: boolean = false): GDString;
    public get_system_font_path_for_text(fontName: GDString | StringName | string, text: GDString | StringName | string, locale: GDString | StringName | string = "", script: GDString | StringName | string = "", weight: number = 400, stretch: number = 100, italic: boolean = false): PackedStringArray;
    public get_executable_path(): GDString;
    public read_string_from_stdin(bufferSize: number = 1024): GDString;
    public read_buffer_from_stdin(bufferSize: number = 1024): PackedByteArray;
    public get_stdin_type(): number;
    public get_stdout_type(): number;
    public get_stderr_type(): number;
    public execute(path: GDString | StringName | string, arguments: PackedStringArray, output: GDArray | Array = [], readStderr: boolean = false, openConsole: boolean = false): number;
    public execute_with_pipe(path: GDString | StringName | string, arguments: PackedStringArray, blocking: boolean = true): Dictionary;
    public create_process(path: GDString | StringName | string, arguments: PackedStringArray, openConsole: boolean = false): number;
    public create_instance(arguments: PackedStringArray): number;
    public open_with_program(programPath: GDString | StringName | string, paths: PackedStringArray): number;
    public kill(pid: number): number;
    public shell_open(uri: GDString | StringName | string): number;
    public shell_show_in_file_manager(fileOrDirPath: GDString | StringName | string, openFolder: boolean = true): number;
    public is_process_running(pid: number): boolean;
    public get_process_exit_code(pid: number): number;
    public get_process_id(): number;
    public has_environment(variable: GDString | StringName | string): boolean;
    public get_environment(variable: GDString | StringName | string): GDString;
    public set_environment(variable: GDString | StringName | string, value: GDString | StringName | string): void;
    public unset_environment(variable: GDString | StringName | string): void;
    public get_name(): GDString;
    public get_distribution_name(): GDString;
    public get_version(): GDString;
    public get_version_alias(): GDString;
    public get_cmdline_args(): PackedStringArray;
    public get_cmdline_user_args(): PackedStringArray;
    public get_video_adapter_driver_info(): PackedStringArray;
    public set_restart_on_exit(restart: boolean, arguments: PackedStringArray = PackedStringArray()): void;
    public is_restart_on_exit_set(): boolean;
    public get_restart_on_exit_arguments(): PackedStringArray;
    public delay_usec(usec: number): void;
    public delay_msec(msec: number): void;
    public get_locale(): GDString;
    public get_locale_language(): GDString;
    public get_model_name(): GDString;
    public is_userfs_persistent(): boolean;
    public is_stdout_verbose(): boolean;
    public is_debug_build(): boolean;
    public get_static_memory_usage(): number;
    public get_static_memory_peak_usage(): number;
    public get_memory_info(): Dictionary;
    public move_to_trash(path: GDString | StringName | string): number;
    public get_user_data_dir(): GDString;
    public get_system_dir(dir: number, sharedStorage: boolean = true): GDString;
    public get_config_dir(): GDString;
    public get_data_dir(): GDString;
    public get_cache_dir(): GDString;
    public get_temp_dir(): GDString;
    public get_unique_id(): GDString;
    public get_keycode_string(code: number): GDString;
    public is_keycode_unicode(code: number): boolean;
    public find_keycode_from_string(_string: GDString | StringName | string): number;
    public set_use_file_access_save_and_swap(enabled: boolean): void;
    public set_thread_name(name: GDString | StringName | string): number;
    public get_thread_caller_id(): number;
    public get_main_thread_id(): number;
    public has_feature(tagName: GDString | StringName | string): boolean;
    public is_sandboxed(): boolean;
    public request_permission(name: GDString | StringName | string): boolean;
    public request_permissions(): boolean;
    public get_granted_permissions(): PackedStringArray;
    public revoke_granted_permissions(): void;
    public add_logger(logger: Logger): void;
    public remove_logger(logger: Logger): void;


    public static readonly RenderingDriver: {
        RENDERING_DRIVER_VULKAN: 0;
        RENDERING_DRIVER_OPENGL3: 1;
        RENDERING_DRIVER_D3D12: 2;
        RENDERING_DRIVER_METAL: 3;
    };
    public static readonly SystemDir: {
        SYSTEM_DIR_DESKTOP: 0;
        SYSTEM_DIR_DCIM: 1;
        SYSTEM_DIR_DOCUMENTS: 2;
        SYSTEM_DIR_DOWNLOADS: 3;
        SYSTEM_DIR_MOVIES: 4;
        SYSTEM_DIR_MUSIC: 5;
        SYSTEM_DIR_PICTURES: 6;
        SYSTEM_DIR_RINGTONES: 7;
    };
    public static readonly StdHandleType: {
        STD_HANDLE_INVALID: 0;
        STD_HANDLE_CONSOLE: 1;
        STD_HANDLE_FILE: 2;
        STD_HANDLE_PIPE: 3;
        STD_HANDLE_UNKNOWN: 4;
    };
}


/**
 * A singleton instance of OS.
 * This is a global variable, available from anywhere.
 */
export const OS: OS;
