
import type { Range } from '@godot/classes/range';


export declare class ProgressBar extends Range {

    
    /**     * The raw type is 'int'     */
    public fill_mode: number;    
    /**     * The raw type is 'bool'     */
    public show_percentage: boolean;    
    /**     * The raw type is 'bool'     */
    public indeterminate: boolean;    
    /**     * The raw type is 'bool'     */
    public editor_preview_indeterminate: boolean;
    public set_fill_mode(mode: number): void;
    public get_fill_mode(): number;
    public set_show_percentage(visible: boolean): void;
    public is_percentage_shown(): boolean;
    public set_indeterminate(indeterminate: boolean): void;
    public is_indeterminate(): boolean;
    public set_editor_preview_indeterminate(previewIndeterminate: boolean): void;
    public is_editor_preview_indeterminate_enabled(): boolean;


    public static readonly FillMode: {
        FILL_BEGIN_TO_END: 0;
        FILL_END_TO_BEGIN: 1;
        FILL_TOP_TO_BOTTOM: 2;
        FILL_BOTTOM_TO_TOP: 3;
    };
}

