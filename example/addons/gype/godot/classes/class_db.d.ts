
import type { GodotObject } from '@godot/classes/godot_object';


export declare class ClassDB extends GodotObject {


    public get_class_list(): PackedStringArray;
    public get_inheriters_from_class(_class: GDString | StringName | string): PackedStringArray;
    public get_parent_class(_class: GDString | StringName | string): StringName;
    public class_exists(_class: GDString | StringName | string): boolean;
    public is_parent_class(_class: GDString | StringName | string, inherits: GDString | StringName | string): boolean;
    public can_instantiate(_class: GDString | StringName | string): boolean;
    public instantiate(_class: GDString | StringName | string): any;
    public class_get_api_type(_class: GDString | StringName | string): number;
    public class_has_signal(_class: GDString | StringName | string, signal: GDString | StringName | string): boolean;
    public class_get_signal(_class: GDString | StringName | string, signal: GDString | StringName | string): Dictionary;
    public class_get_signal_list(_class: GDString | StringName | string, noInheritance: boolean = false): Array<any>;
    public class_get_property_list(_class: GDString | StringName | string, noInheritance: boolean = false): Array<any>;
    public class_get_property_getter(_class: GDString | StringName | string, property: GDString | StringName | string): StringName;
    public class_get_property_setter(_class: GDString | StringName | string, property: GDString | StringName | string): StringName;
    public class_get_property(object: GodotObject, property: GDString | StringName | string): any;
    public class_set_property(object: GodotObject, property: GDString | StringName | string, value: any): number;
    public class_get_property_default_value(_class: GDString | StringName | string, property: GDString | StringName | string): any;
    public class_has_method(_class: GDString | StringName | string, method: GDString | StringName | string, noInheritance: boolean = false): boolean;
    public class_get_method_argument_count(_class: GDString | StringName | string, method: GDString | StringName | string, noInheritance: boolean = false): number;
    public class_get_method_list(_class: GDString | StringName | string, noInheritance: boolean = false): Array<any>;
    public class_call_static(_class: GDString | StringName | string, method: GDString | StringName | string, ...args: any[]): any;
    public class_get_integer_constant_list(_class: GDString | StringName | string, noInheritance: boolean = false): PackedStringArray;
    public class_has_integer_constant(_class: GDString | StringName | string, name: GDString | StringName | string): boolean;
    public class_get_integer_constant(_class: GDString | StringName | string, name: GDString | StringName | string): number;
    public class_has_enum(_class: GDString | StringName | string, name: GDString | StringName | string, noInheritance: boolean = false): boolean;
    public class_get_enum_list(_class: GDString | StringName | string, noInheritance: boolean = false): PackedStringArray;
    public class_get_enum_constants(_class: GDString | StringName | string, _enum: GDString | StringName | string, noInheritance: boolean = false): PackedStringArray;
    public class_get_integer_constant_enum(_class: GDString | StringName | string, name: GDString | StringName | string, noInheritance: boolean = false): StringName;
    public is_class_enum_bitfield(_class: GDString | StringName | string, _enum: GDString | StringName | string, noInheritance: boolean = false): boolean;
    public is_class_enabled(_class: GDString | StringName | string): boolean;


    public static readonly APIType: {
        API_CORE: 0;
        API_EDITOR: 1;
        API_EXTENSION: 2;
        API_EDITOR_EXTENSION: 3;
        API_NONE: 4;
    };
}


/**
 * A singleton instance of ClassDB.
 * This is a global variable, available from anywhere.
 */
export const ClassDB: ClassDB;
