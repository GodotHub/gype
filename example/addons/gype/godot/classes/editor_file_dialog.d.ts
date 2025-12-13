
import type { ConfirmationDialog } from '@godot/classes/confirmation_dialog';
import type { Control } from '@godot/classes/control';
import type { LineEdit } from '@godot/classes/line_edit';
import type { VBoxContainer } from '@godot/classes/v_box_container';


export declare class EditorFileDialog extends ConfirmationDialog {

    
    /**     * The raw type is 'int'     */
    public access: number;    
    /**     * The raw type is 'int'     */
    public display_mode: number;    
    /**     * The raw type is 'int'     */
    public file_mode: number;    
    /**     * The raw type is 'String'     */
    public current_dir: GDString | StringName | string;    
    /**     * The raw type is 'String'     */
    public current_file: GDString | StringName | string;    
    /**     * The raw type is 'String'     */
    public current_path: GDString | StringName | string;    
    /**     * The raw type is 'PackedStringArray'     */
    public filters: PackedStringArray;    
    /**     * The raw type is 'int'     */
    public option_count: number;    
    /**     * The raw type is 'bool'     */
    public show_hidden_files: boolean;    
    /**     * The raw type is 'bool'     */
    public disable_overwrite_warning: boolean;
    public clear_filters(): void;
    public add_filter(filter: GDString | StringName | string, description: GDString | StringName | string = ""): void;
    public set_filters(filters: PackedStringArray): void;
    public get_filters(): PackedStringArray;
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
    public clear_filename_filter(): void;
    public set_filename_filter(filter: GDString | StringName | string): void;
    public get_filename_filter(): GDString;
    public get_current_dir(): GDString;
    public get_current_file(): GDString;
    public get_current_path(): GDString;
    public set_current_dir(dir: GDString | StringName | string): void;
    public set_current_file(file: GDString | StringName | string): void;
    public set_current_path(path: GDString | StringName | string): void;
    public set_file_mode(mode: number): void;
    public get_file_mode(): number;
    public get_vbox(): VBoxContainer;
    public get_line_edit(): LineEdit;
    public set_access(access: number): void;
    public get_access(): number;
    public set_show_hidden_files(show: boolean): void;
    public is_showing_hidden_files(): boolean;
    public set_display_mode(mode: number): void;
    public get_display_mode(): number;
    public set_disable_overwrite_warning(disable: boolean): void;
    public is_overwrite_warning_disabled(): boolean;
    public add_side_menu(menu: Control, title: GDString | StringName | string = ""): void;
    public popup_file_dialog(): void;
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
}

