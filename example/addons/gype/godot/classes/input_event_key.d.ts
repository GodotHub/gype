
import type { GDString } from '@godot/builtins/gd_string';
import type { InputEventWithModifiers } from '@godot/classes/input_event_with_modifiers';


export declare class InputEventKey extends InputEventWithModifiers {

    
    /**     * The raw type is 'bool'     */
    public pressed: boolean;    
    /**     * The raw type is 'int'     */
    public keycode: number;    
    /**     * The raw type is 'int'     */
    public physical_keycode: number;    
    /**     * The raw type is 'int'     */
    public key_label: number;    
    /**     * The raw type is 'int'     */
    public unicode: number;    
    /**     * The raw type is 'int'     */
    public location: number;    
    /**     * The raw type is 'bool'     */
    public echo: boolean;
    public set_pressed(pressed: boolean): void;
    public set_keycode(keycode: number): void;
    public get_keycode(): number;
    public set_physical_keycode(physicalKeycode: number): void;
    public get_physical_keycode(): number;
    public set_key_label(keyLabel: number): void;
    public get_key_label(): number;
    public set_unicode(unicode: number): void;
    public get_unicode(): number;
    public set_location(location: number): void;
    public get_location(): number;
    public set_echo(echo: boolean): void;
    public get_keycode_with_modifiers(): number;
    public get_physical_keycode_with_modifiers(): number;
    public get_key_label_with_modifiers(): number;
    public as_text_keycode(): GDString;
    public as_text_physical_keycode(): GDString;
    public as_text_key_label(): GDString;
    public as_text_location(): GDString;


}

