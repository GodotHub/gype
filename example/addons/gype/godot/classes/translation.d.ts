
import type { Resource } from '@godot/classes/resource';


export declare class Translation extends Resource {

    
    /**     * The raw type is 'Dictionary'     */
    public messages: Dictionary;    
    /**     * The raw type is 'String'     */
    public locale: GDString | StringName | string;
    public _get_plural_message(srcMessage: GDString | StringName | string, srcPluralMessage: GDString | StringName | string, n: number, context: GDString | StringName | string): StringName;
    public _get_message(srcMessage: GDString | StringName | string, context: GDString | StringName | string): StringName;
    public set_locale(locale: GDString | StringName | string): void;
    public get_locale(): GDString;
    public add_message(srcMessage: GDString | StringName | string, xlatedMessage: GDString | StringName | string, context: GDString | StringName | string = ""): void;
    public add_plural_message(srcMessage: GDString | StringName | string, xlatedMessages: PackedStringArray, context: GDString | StringName | string = ""): void;
    public get_message(srcMessage: GDString | StringName | string, context: GDString | StringName | string = ""): StringName;
    public get_plural_message(srcMessage: GDString | StringName | string, srcPluralMessage: GDString | StringName | string, n: number, context: GDString | StringName | string = ""): StringName;
    public erase_message(srcMessage: GDString | StringName | string, context: GDString | StringName | string = ""): void;
    public get_message_list(): PackedStringArray;
    public get_translated_message_list(): PackedStringArray;
    public get_message_count(): number;


}

