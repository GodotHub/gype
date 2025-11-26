
import type { Range } from '@godot/classes/range';


export declare class EditorSpinSlider extends Range {

    
    /**     * The raw type is 'String'     */
    public label: GDString;    
    /**     * The raw type is 'String'     */
    public suffix: GDString;    
    /**     * The raw type is 'bool'     */
    public read_only: boolean;    
    /**     * The raw type is 'bool'     */
    public flat: boolean;    
    /**     * The raw type is 'bool'     */
    public hide_slider: boolean;    
    /**     * The raw type is 'bool'     */
    public editing_integer: boolean;
    public set_label(label: GDString | StringName | string): void;
    public get_label(): GDString;
    public set_suffix(suffix: GDString | StringName | string): void;
    public get_suffix(): GDString;
    public set_read_only(readOnly: boolean): void;
    public is_read_only(): boolean;
    public set_flat(flat: boolean): void;
    public is_flat(): boolean;
    public set_hide_slider(hideSlider: boolean): void;
    public is_hiding_slider(): boolean;
    public set_editing_integer(editingInteger: boolean): void;
    public is_editing_integer(): boolean;

    
    public readonly grabbed: Signal;
    public readonly ungrabbed: Signal;
    public readonly updown_pressed: Signal;
    public readonly value_focus_entered: Signal;
    public readonly value_focus_exited: Signal;

}

