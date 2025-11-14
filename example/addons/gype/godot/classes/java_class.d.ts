
import type { GDString } from '@godot/builtins/gd_string';
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class JavaClass extends RefCounted {


    public get_java_class_name(): GDString;
    public get_java_method_list(): Array<any>;
    public get_java_parent_class(): JavaClass;


}

