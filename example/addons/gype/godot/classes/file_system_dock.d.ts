
import type { EditorResourceTooltipPlugin } from '@godot/classes/editor_resource_tooltip_plugin';
import type { GDString } from '@godot/builtins/gd_string';
import type { PackedStringArray } from '@godot/builtins/packed_string_array';
import type { Resource } from '@godot/classes/resource';
import type { Signal } from '@godot/builtins/signal';
import type { VBoxContainer } from '@godot/classes/v_box_container';


export declare class FileSystemDock extends VBoxContainer {


    public navigate_to_path(path: GDString | StringName | string): void;
    public add_resource_tooltip_plugin(plugin: EditorResourceTooltipPlugin): void;
    public remove_resource_tooltip_plugin(plugin: EditorResourceTooltipPlugin): void;

    
    public readonly inherit: Signal<(file: GDString | StringName | string) => void>;
    public readonly instantiate: Signal<(files: PackedStringArray) => void>;
    public readonly resource_removed: Signal<(resource: Resource) => void>;
    public readonly file_removed: Signal<(file: GDString | StringName | string) => void>;
    public readonly folder_removed: Signal<(folder: GDString | StringName | string) => void>;
    public readonly files_moved: Signal<(oldFile: GDString | StringName | string, newFile: GDString | StringName | string) => void>;
    public readonly folder_moved: Signal<(oldFolder: GDString | StringName | string, newFolder: GDString | StringName | string) => void>;
    public readonly folder_color_changed: Signal<() => void>;
    public readonly display_mode_changed: Signal<() => void>;

}

