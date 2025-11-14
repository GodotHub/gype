
import type { GDString } from '@godot/builtins/gd_string';
import type { GodotObject } from '@godot/classes/godot_object';
import type { JavaClass } from '@godot/classes/java_class';
import type { JavaObject } from '@godot/classes/java_object';


export declare class JavaClassWrapper extends GodotObject {


    public wrap(name: GDString | StringName | string): JavaClass;
    public get_exception(): JavaObject;


}


/**
 * A singleton instance of JavaClassWrapper.
 * This is a global variable, available from anywhere.
 */
export const JavaClassWrapper: JavaClassWrapper;
