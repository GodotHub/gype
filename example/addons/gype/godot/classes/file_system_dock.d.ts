
import type { EditorResourceTooltipPlugin } from '@godot/classes/editor_resource_tooltip_plugin';
import type { Resource } from '@godot/classes/resource';
import type { VBoxContainer } from '@godot/classes/v_box_container';


export declare class FileSystemDock extends VBoxContainer {


    public navigate_to_path(path: GDString | StringName | string): void;
    public add_resource_tooltip_plugin(plugin: EditorResourceTooltipPlugin): void;
    public remove_resource_tooltip_plugin(plugin: EditorResourceTooltipPlugin): void;

    
    public readonly inherit: Signal;
    public readonly instantiate: Signal;
    public readonly resource_removed: Signal;
    public readonly file_removed: Signal;
    public readonly folder_removed: Signal;
    public readonly files_moved: Signal;
    public readonly folder_moved: Signal;
    public readonly folder_color_changed: Signal;
    public readonly display_mode_changed: Signal;

}

