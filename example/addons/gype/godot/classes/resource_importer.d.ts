
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class ResourceImporter extends RefCounted {


    public _get_build_dependencies(path: GDString | StringName | string): PackedStringArray;


    public static readonly ImportOrder: {
        IMPORT_ORDER_DEFAULT: 0;
        IMPORT_ORDER_SCENE: 100;
    };
}

