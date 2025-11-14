
import type { GDString } from '@godot/builtins/gd_string';
import type { GodotObject } from '@godot/classes/godot_object';
import type { PackedStringArray } from '@godot/builtins/packed_string_array';
import type { StringName } from '@godot/builtins/string_name';
import type { Translation } from '@godot/classes/translation';
import type { TranslationDomain } from '@godot/classes/translation_domain';


export declare class TranslationServer extends GodotObject {

    
    /**     * The raw type is 'bool'     */
    public pseudolocalization_enabled: boolean;
    public set_locale(locale: GDString | StringName | string): void;
    public get_locale(): GDString;
    public get_tool_locale(): GDString;
    public compare_locales(localeA: GDString | StringName | string, localeB: GDString | StringName | string): number;
    public standardize_locale(locale: GDString | StringName | string, addDefaults: boolean = false): GDString;
    public get_all_languages(): PackedStringArray;
    public get_language_name(language: GDString | StringName | string): GDString;
    public get_all_scripts(): PackedStringArray;
    public get_script_name(script: GDString | StringName | string): GDString;
    public get_all_countries(): PackedStringArray;
    public get_country_name(country: GDString | StringName | string): GDString;
    public get_locale_name(locale: GDString | StringName | string): GDString;
    public translate(message: GDString | StringName | string, context: GDString | StringName | string = ""): StringName;
    public translate_plural(message: GDString | StringName | string, pluralMessage: GDString | StringName | string, n: number, context: GDString | StringName | string = ""): StringName;
    public add_translation(translation: Translation): void;
    public remove_translation(translation: Translation): void;
    public get_translation_object(locale: GDString | StringName | string): Translation;
    public has_domain(domain: GDString | StringName | string): boolean;
    public get_or_add_domain(domain: GDString | StringName | string): TranslationDomain;
    public remove_domain(domain: GDString | StringName | string): void;
    public clear(): void;
    public get_loaded_locales(): PackedStringArray;
    public is_pseudolocalization_enabled(): boolean;
    public set_pseudolocalization_enabled(enabled: boolean): void;
    public reload_pseudolocalization(): void;
    public pseudolocalize(message: GDString | StringName | string): StringName;


}


/**
 * A singleton instance of TranslationServer.
 * This is a global variable, available from anywhere.
 */
export const TranslationServer: TranslationServer;
