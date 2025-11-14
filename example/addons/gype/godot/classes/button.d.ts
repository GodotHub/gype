
import type { BaseButton } from '@godot/classes/base_button';
import type { GDString } from '@godot/builtins/gd_string';
import type { Texture2D } from '@godot/classes/texture2d';


export declare class Button extends BaseButton {

    
    /**     * The raw type is 'String'     */
    public text: GDString;    
    /**     * The raw type is 'Texture2D'     */
    public icon: Texture2D;    
    /**     * The raw type is 'bool'     */
    public flat: boolean;    
    /**     * The raw type is 'int'     */
    public alignment: number;    
    /**     * The raw type is 'int'     */
    public text_overrun_behavior: number;    
    /**     * The raw type is 'int'     */
    public autowrap_mode: number;    
    /**     * The raw type is 'int'     */
    public autowrap_trim_flags: number;    
    /**     * The raw type is 'bool'     */
    public clip_text: boolean;    
    /**     * The raw type is 'int'     */
    public icon_alignment: number;    
    /**     * The raw type is 'int'     */
    public vertical_icon_alignment: number;    
    /**     * The raw type is 'bool'     */
    public expand_icon: boolean;    
    /**     * The raw type is 'int'     */
    public text_direction: number;    
    /**     * The raw type is 'String'     */
    public language: GDString;
    public set_text(text: GDString | StringName | string): void;
    public get_text(): GDString;
    public set_text_overrun_behavior(overrunBehavior: number): void;
    public get_text_overrun_behavior(): number;
    public set_autowrap_mode(autowramode: number): void;
    public get_autowrap_mode(): number;
    public set_autowrap_trim_flags(autowratrimFlags: number): void;
    public get_autowrap_trim_flags(): number;
    public set_text_direction(direction: number): void;
    public get_text_direction(): number;
    public set_language(language: GDString | StringName | string): void;
    public get_language(): GDString;
    public set_button_icon(texture: Texture2D): void;
    public get_button_icon(): Texture2D;
    public set_flat(enabled: boolean): void;
    public is_flat(): boolean;
    public set_clip_text(enabled: boolean): void;
    public get_clip_text(): boolean;
    public set_text_alignment(alignment: number): void;
    public get_text_alignment(): number;
    public set_icon_alignment(iconAlignment: number): void;
    public get_icon_alignment(): number;
    public set_vertical_icon_alignment(verticalIconAlignment: number): void;
    public get_vertical_icon_alignment(): number;
    public set_expand_icon(enabled: boolean): void;
    public is_expand_icon(): boolean;


}

