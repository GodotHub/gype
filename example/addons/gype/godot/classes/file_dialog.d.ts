
import type { ConfirmationDialog } from '@godot/classes/confirmation_dialog';
import type { Dictionary } from '@godot/builtins/dictionary';
import type { GDString } from '@godot/builtins/gd_string';
import type { LineEdit } from '@godot/classes/line_edit';
import type { PackedStringArray } from '@godot/builtins/packed_string_array';
import type { Signal } from '@godot/builtins/signal';
import type { VBoxContainer } from '@godot/classes/v_box_container';


export declare class FileDialog extends ConfirmationDialog {

    
    /**     * The raw type is 'bool'     */
    public mode_overrides_title: boolean;    
    /**     * The raw type is 'int'     */
    public file_mode: number;    
    /**     * The raw type is 'int'     */
    public display_mode: number;    
    /**     * The raw type is 'int'     */
    public access: number;    
    /**     * The raw type is 'String'     */
    public root_subfolder: GDString;    
    /**     * The raw type is 'PackedStringArray'     */
    public filters: PackedStringArray;    
    /**     * The raw type is 'String'     */
    public filename_filter: GDString;    
    /**     * The raw type is 'bool'     */
    public show_hidden_files: boolean;    
    /**     * The raw type is 'bool'     */
    public use_native_dialog: boolean;    
    /**     * The raw type is 'int'     */
    public option_count: number;    
    /**     * The raw type is 'bool'     */
    public hidden_files_toggle_enabled: boolean;    
    /**     * The raw type is 'bool'     */
    public file_filter_toggle_enabled: boolean;    
    /**     * The raw type is 'bool'     */
    public file_sort_options_enabled: boolean;    
    /**     * The raw type is 'bool'     */
    public folder_creation_enabled: boolean;    
    /**     * The raw type is 'bool'     */
    public favorites_enabled: boolean;    
    /**     * The raw type is 'bool'     */
    public recent_list_enabled: boolean;    
    /**     * The raw type is 'bool'     */
    public layout_toggle_enabled: boolean;    
    /**     * The raw type is 'String'     */
    public current_dir: GDString;    
    /**     * The raw type is 'String'     */
    public current_file: GDString;    
    /**     * The raw type is 'String'     */
    public current_path: GDString;
    public clear_filters(): void;
    public add_filter(filter: GDString | StringName | string, description: GDString | StringName | string = ""): void;
    public set_filters(filters: PackedStringArray): void;
    public get_filters(): PackedStringArray;
    public clear_filename_filter(): void;
    public set_filename_filter(filter: GDString | StringName | string): void;
    public get_filename_filter(): GDString;
    public get_option_name(option: number): GDString;
    public get_option_values(option: number): PackedStringArray;
    public get_option_default(option: number): number;
    public set_option_name(option: number, name: GDString | StringName | string): void;
    public set_option_values(option: number, values: PackedStringArray): void;
    public set_option_default(option: number, defaultValueIndex: number): void;
    public set_option_count(count: number): void;
    public get_option_count(): number;
    public add_option(name: GDString | StringName | string, values: PackedStringArray, defaultValueIndex: number): void;
    public get_selected_options(): Dictionary;
    public get_current_dir(): GDString;
    public get_current_file(): GDString;
    public get_current_path(): GDString;
    public set_current_dir(dir: GDString | StringName | string): void;
    public set_current_file(file: GDString | StringName | string): void;
    public set_current_path(path: GDString | StringName | string): void;
    public set_mode_overrides_title(override: boolean): void;
    public is_mode_overriding_title(): boolean;
    public set_file_mode(mode: number): void;
    public get_file_mode(): number;
    public set_display_mode(mode: number): void;
    public get_display_mode(): number;
    public get_vbox(): VBoxContainer;
    public get_line_edit(): LineEdit;
    public set_access(access: number): void;
    public get_access(): number;
    public set_root_subfolder(dir: GDString | StringName | string): void;
    public get_root_subfolder(): GDString;
    public set_show_hidden_files(show: boolean): void;
    public is_showing_hidden_files(): boolean;
    public set_use_native_dialog(native: boolean): void;
    public get_use_native_dialog(): boolean;
    public set_customization_flag_enabled(flag: number, enabled: boolean): void;
    public is_customization_flag_enabled(flag: number): boolean;
    public deselect_all(): void;
    public invalidate(): void;

    
    public readonly file_selected: Signal<(path: GDString | StringName | string) => void>;
    public readonly files_selected: Signal<(paths: PackedStringArray) => void>;
    public readonly dir_selected: Signal<(dir: GDString | StringName | string) => void>;
    public readonly filename_filter_changed: Signal<(filter: GDString | StringName | string) => void>;

    public static readonly FileMode: {
        FILE_MODE_OPEN_FILE: 0;
        FILE_MODE_OPEN_FILES: 1;
        FILE_MODE_OPEN_DIR: 2;
        FILE_MODE_OPEN_ANY: 3;
        FILE_MODE_SAVE_FILE: 4;
    };
    public static readonly Access: {
        ACCESS_RESOURCES: 0;
        ACCESS_USERDATA: 1;
        ACCESS_FILESYSTEM: 2;
    };
    public static readonly DisplayMode: {
        DISPLAY_THUMBNAILS: 0;
        DISPLAY_LIST: 1;
    };
    public static readonly Customization: {
        CUSTOMIZATION_HIDDEN_FILES: 0;
        CUSTOMIZATION_CREATE_FOLDER: 1;
        CUSTOMIZATION_FILE_FILTER: 2;
        CUSTOMIZATION_FILE_SORT: 3;
        CUSTOMIZATION_FAVORITES: 4;
        CUSTOMIZATION_RECENT: 5;
        CUSTOMIZATION_LAYOUT: 6;
    };
}

