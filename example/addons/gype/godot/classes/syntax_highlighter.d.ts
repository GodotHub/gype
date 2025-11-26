
import type { Resource } from '@godot/classes/resource';
import type { TextEdit } from '@godot/classes/text_edit';


export declare class SyntaxHighlighter extends Resource {


    public _get_line_syntax_highlighting(line: number): Dictionary;
    public _clear_highlighting_cache(): void;
    public _update_cache(): void;
    public get_line_syntax_highlighting(line: number): Dictionary;
    public update_cache(): void;
    public clear_highlighting_cache(): void;
    public get_text_edit(): TextEdit;


}

