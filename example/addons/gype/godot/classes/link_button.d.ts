
import type { BaseButton } from '@godot/classes/base_button';


export declare class LinkButton extends BaseButton {

    
    /**     * The raw type is 'String'     */
    public text: GDString;    
    /**     * The raw type is 'int'     */
    public underline: number;    
    /**     * The raw type is 'String'     */
    public uri: GDString;    
    /**     * The raw type is 'int'     */
    public text_direction: number;    
    /**     * The raw type is 'String'     */
    public language: GDString;    
    /**     * The raw type is 'int'     */
    public structured_text_bidi_override: number;    
    /**     * The raw type is 'Array'     */
    public structured_text_bidi_override_options: GDArray;
    public set_text(text: GDString | StringName | string): void;
    public get_text(): GDString;
    public set_text_direction(direction: number): void;
    public get_text_direction(): number;
    public set_language(language: GDString | StringName | string): void;
    public get_language(): GDString;
    public set_uri(uri: GDString | StringName | string): void;
    public get_uri(): GDString;
    public set_underline_mode(underlineMode: number): void;
    public get_underline_mode(): number;
    public set_structured_text_bidi_override(parser: number): void;
    public get_structured_text_bidi_override(): number;
    public set_structured_text_bidi_override_options(args: GDArray | Array): void;
    public get_structured_text_bidi_override_options(): GDArray;


    public static readonly UnderlineMode: {
        UNDERLINE_MODE_ALWAYS: 0;
        UNDERLINE_MODE_ON_HOVER: 1;
        UNDERLINE_MODE_NEVER: 2;
    };
}

