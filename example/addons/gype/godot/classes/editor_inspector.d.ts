
import type { EditorProperty } from '@godot/classes/editor_property';
import type { GodotObject } from '@godot/classes/godot_object';
import type { Resource } from '@godot/classes/resource';
import type { ScrollContainer } from '@godot/classes/scroll_container';


export declare class EditorInspector extends ScrollContainer {


    public edit(object: GodotObject): void;
    public get_selected_path(): GDString;
    public get_edited_object(): GodotObject;
    public static instantiate_property_editor(object: GodotObject, _type: number, path: GDString | StringName | string, hint: number, hintText: GDString | StringName | string, usage: number, wide: boolean = false): EditorProperty;

    
    public readonly property_selected: Signal<(property: GDString | StringName | string) => void>;
    public readonly property_keyed: Signal<(property: GDString | StringName | string, value: any, advance: boolean) => void>;
    public readonly property_deleted: Signal<(property: GDString | StringName | string) => void>;
    public readonly resource_selected: Signal<(resource: Resource, path: GDString | StringName | string) => void>;
    public readonly object_id_selected: Signal<(id: number) => void>;
    public readonly property_edited: Signal<(property: GDString | StringName | string) => void>;
    public readonly property_toggled: Signal<(property: GDString | StringName | string, checked: boolean) => void>;
    public readonly edited_object_changed: Signal<() => void>;
    public readonly restart_requested: Signal<() => void>;

}

