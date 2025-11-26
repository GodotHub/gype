
import type { Control } from '@godot/classes/control';
import type { GodotObject } from '@godot/classes/godot_object';
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class EditorInspectorPlugin extends RefCounted {


    public _can_handle(object: GodotObject): boolean;
    public _parse_begin(object: GodotObject): void;
    public _parse_category(object: GodotObject, category: GDString | StringName | string): void;
    public _parse_group(object: GodotObject, group: GDString | StringName | string): void;
    public _parse_property(object: GodotObject, _type: number, name: GDString | StringName | string, hintType: number, hintString: GDString | StringName | string, usageFlags: number, wide: boolean): boolean;
    public _parse_end(object: GodotObject): void;
    public add_custom_control(control: Control): void;
    public add_property_editor(property: GDString | StringName | string, editor: Control, addToEnd: boolean = false, label: GDString | StringName | string = ""): void;
    public add_property_editor_for_multiple_properties(label: GDString | StringName | string, properties: PackedStringArray, editor: Control): void;


}

