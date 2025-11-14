
import type { GDString } from '@godot/builtins/gd_string';
import type { PackedStringArray } from '@godot/builtins/packed_string_array';
import type { SyntaxHighlighter } from '@godot/classes/syntax_highlighter';


export declare class EditorSyntaxHighlighter extends SyntaxHighlighter {


    public _get_name(): GDString;
    public _get_supported_languages(): PackedStringArray;
    public _create(): EditorSyntaxHighlighter;


}

