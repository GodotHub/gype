
import type { Color } from '@godot/builtins/color';
import type { Dictionary } from '@godot/builtins/dictionary';
import type { GDString } from '@godot/builtins/gd_string';
import type { SyntaxHighlighter } from '@godot/classes/syntax_highlighter';


export declare class CodeHighlighter extends SyntaxHighlighter {

    
    /**     * The raw type is 'Color'     */
    public number_color: Color;    
    /**     * The raw type is 'Color'     */
    public symbol_color: Color;    
    /**     * The raw type is 'Color'     */
    public function_color: Color;    
    /**     * The raw type is 'Color'     */
    public member_variable_color: Color;    
    /**     * The raw type is 'Dictionary'     */
    public keyword_colors: Dictionary;    
    /**     * The raw type is 'Dictionary'     */
    public member_keyword_colors: Dictionary;    
    /**     * The raw type is 'Dictionary'     */
    public color_regions: Dictionary;
    public add_keyword_color(keyword: GDString | StringName | string, color: Color): void;
    public remove_keyword_color(keyword: GDString | StringName | string): void;
    public has_keyword_color(keyword: GDString | StringName | string): boolean;
    public get_keyword_color(keyword: GDString | StringName | string): Color;
    public set_keyword_colors(keywords: Dictionary): void;
    public clear_keyword_colors(): void;
    public get_keyword_colors(): Dictionary;
    public add_member_keyword_color(memberKeyword: GDString | StringName | string, color: Color): void;
    public remove_member_keyword_color(memberKeyword: GDString | StringName | string): void;
    public has_member_keyword_color(memberKeyword: GDString | StringName | string): boolean;
    public get_member_keyword_color(memberKeyword: GDString | StringName | string): Color;
    public set_member_keyword_colors(memberKeyword: Dictionary): void;
    public clear_member_keyword_colors(): void;
    public get_member_keyword_colors(): Dictionary;
    public add_color_region(startKey: GDString | StringName | string, endKey: GDString | StringName | string, color: Color, lineOnly: boolean = false): void;
    public remove_color_region(startKey: GDString | StringName | string): void;
    public has_color_region(startKey: GDString | StringName | string): boolean;
    public set_color_regions(colorRegions: Dictionary): void;
    public clear_color_regions(): void;
    public get_color_regions(): Dictionary;
    public set_function_color(color: Color): void;
    public get_function_color(): Color;
    public set_number_color(color: Color): void;
    public get_number_color(): Color;
    public set_symbol_color(color: Color): void;
    public get_symbol_color(): Color;
    public set_member_variable_color(color: Color): void;
    public get_member_variable_color(): Color;


}

