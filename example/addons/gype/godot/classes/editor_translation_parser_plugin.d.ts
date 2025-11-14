
import type { GDString } from '@godot/builtins/gd_string';
import type { PackedStringArray } from '@godot/builtins/packed_string_array';
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class EditorTranslationParserPlugin extends RefCounted {


    public _parse_file(path: GDString | StringName | string): Array<any>;
    public _get_recognized_extensions(): PackedStringArray;


}

