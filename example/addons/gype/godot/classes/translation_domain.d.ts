
import type { RefCounted } from '@godot/classes/ref_counted';
import type { Translation } from '@godot/classes/translation';


export declare class TranslationDomain extends RefCounted {

    
    /**     * The raw type is 'bool'     */
    public enabled: boolean;    
    /**     * The raw type is 'bool'     */
    public pseudolocalization_enabled: boolean;    
    /**     * The raw type is 'bool'     */
    public pseudolocalization_accents_enabled: boolean;    
    /**     * The raw type is 'bool'     */
    public pseudolocalization_double_vowels_enabled: boolean;    
    /**     * The raw type is 'bool'     */
    public pseudolocalization_fake_bidi_enabled: boolean;    
    /**     * The raw type is 'bool'     */
    public pseudolocalization_override_enabled: boolean;    
    /**     * The raw type is 'bool'     */
    public pseudolocalization_skip_placeholders_enabled: boolean;    
    /**     * The raw type is 'float'     */
    public pseudolocalization_expansion_ratio: number;    
    /**     * The raw type is 'String'     */
    public pseudolocalization_prefix: GDString | StringName | string;    
    /**     * The raw type is 'String'     */
    public pseudolocalization_suffix: GDString | StringName | string;
    public get_translation_object(locale: GDString | StringName | string): Translation;
    public add_translation(translation: Translation): void;
    public remove_translation(translation: Translation): void;
    public clear(): void;
    public translate(message: GDString | StringName | string, context: GDString | StringName | string = ""): StringName;
    public translate_plural(message: GDString | StringName | string, messagePlural: GDString | StringName | string, n: number, context: GDString | StringName | string = ""): StringName;
    public get_locale_override(): GDString;
    public set_locale_override(locale: GDString | StringName | string): void;
    public is_enabled(): boolean;
    public set_enabled(enabled: boolean): void;
    public is_pseudolocalization_enabled(): boolean;
    public set_pseudolocalization_enabled(enabled: boolean): void;
    public is_pseudolocalization_accents_enabled(): boolean;
    public set_pseudolocalization_accents_enabled(enabled: boolean): void;
    public is_pseudolocalization_double_vowels_enabled(): boolean;
    public set_pseudolocalization_double_vowels_enabled(enabled: boolean): void;
    public is_pseudolocalization_fake_bidi_enabled(): boolean;
    public set_pseudolocalization_fake_bidi_enabled(enabled: boolean): void;
    public is_pseudolocalization_override_enabled(): boolean;
    public set_pseudolocalization_override_enabled(enabled: boolean): void;
    public is_pseudolocalization_skip_placeholders_enabled(): boolean;
    public set_pseudolocalization_skip_placeholders_enabled(enabled: boolean): void;
    public get_pseudolocalization_expansion_ratio(): number;
    public set_pseudolocalization_expansion_ratio(ratio: number): void;
    public get_pseudolocalization_prefix(): GDString;
    public set_pseudolocalization_prefix(prefix: GDString | StringName | string): void;
    public get_pseudolocalization_suffix(): GDString;
    public set_pseudolocalization_suffix(suffix: GDString | StringName | string): void;
    public pseudolocalize(message: GDString | StringName | string): StringName;


}

