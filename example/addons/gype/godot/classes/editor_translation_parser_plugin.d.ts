
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class EditorTranslationParserPlugin extends RefCounted {


    public _parse_file(path: GDString | StringName | string): Array<any>;
    public _get_recognized_extensions(): PackedStringArray;


}

