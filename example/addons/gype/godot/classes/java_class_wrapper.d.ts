
import type { GodotObject } from '@godot/classes/godot_object';
import type { JavaClass } from '@godot/classes/java_class';
import type { JavaObject } from '@godot/classes/java_object';


export declare class _JavaClassWrapper extends GodotObject {


    public wrap(name: GDString | StringName | string): JavaClass;
    public get_exception(): JavaObject;


}

export const JavaClassWrapper: _JavaClassWrapper;
