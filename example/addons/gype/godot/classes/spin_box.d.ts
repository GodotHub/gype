
import type { LineEdit } from '@godot/classes/line_edit';
import type { Range } from '@godot/classes/range';


export declare class SpinBox extends Range {

    
    /**     * The raw type is 'int'     */
    public alignment: number;    
    /**     * The raw type is 'bool'     */
    public editable: boolean;    
    /**     * The raw type is 'bool'     */
    public update_on_text_changed: boolean;    
    /**     * The raw type is 'String'     */
    public prefix: GDString | StringName | string;    
    /**     * The raw type is 'String'     */
    public suffix: GDString | StringName | string;    
    /**     * The raw type is 'float'     */
    public custom_arrow_step: number;    
    /**     * The raw type is 'bool'     */
    public select_all_on_focus: boolean;
    public set_horizontal_alignment(alignment: number): void;
    public get_horizontal_alignment(): number;
    public set_suffix(suffix: GDString | StringName | string): void;
    public get_suffix(): GDString;
    public set_prefix(prefix: GDString | StringName | string): void;
    public get_prefix(): GDString;
    public set_editable(enabled: boolean): void;
    public set_custom_arrow_step(arrowStep: number): void;
    public get_custom_arrow_step(): number;
    public is_editable(): boolean;
    public set_update_on_text_changed(enabled: boolean): void;
    public get_update_on_text_changed(): boolean;
    public set_select_all_on_focus(enabled: boolean): void;
    public is_select_all_on_focus(): boolean;
    public apply(): void;
    public get_line_edit(): LineEdit;


}

