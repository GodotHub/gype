
import type { EditorProperty } from '@godot/classes/editor_property';
import type { GodotObject } from '@godot/classes/godot_object';
import type { Resource } from '@godot/classes/resource';
import type { ScrollContainer } from '@godot/classes/scroll_container';


export declare class EditorInspector extends ScrollContainer {


    public edit(object: GodotObject): void;
    public get_selected_path(): GDString;
    public get_edited_object(): GodotObject;
    public static instantiate_property_editor(object: GodotObject, _type: number, path: GDString | StringName | string, hint: number, hintText: GDString | StringName | string, usage: number, wide: boolean = false): EditorProperty;

    
    public readonly property_selected: Signal;
    public readonly property_keyed: Signal;
    public readonly property_deleted: Signal;
    public readonly resource_selected: Signal;
    public readonly object_id_selected: Signal;
    public readonly property_edited: Signal;
    public readonly property_toggled: Signal;
    public readonly edited_object_changed: Signal;
    public readonly restart_requested: Signal;

}

