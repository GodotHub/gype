
import type { Container } from '@godot/classes/container';
import type { Control } from '@godot/classes/control';


export declare class SplitContainer extends Container {

    
    /**     * The raw type is 'int'     */
    public split_offset: number;    
    /**     * The raw type is 'bool'     */
    public collapsed: boolean;    
    /**     * The raw type is 'bool'     */
    public dragging_enabled: boolean;    
    /**     * The raw type is 'int'     */
    public dragger_visibility: number;    
    /**     * The raw type is 'bool'     */
    public vertical: boolean;    
    /**     * The raw type is 'bool'     */
    public touch_dragger_enabled: boolean;    
    /**     * The raw type is 'int'     */
    public drag_area_margin_begin: number;    
    /**     * The raw type is 'int'     */
    public drag_area_margin_end: number;    
    /**     * The raw type is 'int'     */
    public drag_area_offset: number;    
    /**     * The raw type is 'bool'     */
    public drag_area_highlight_in_editor: boolean;
    public set_split_offset(offset: number): void;
    public get_split_offset(): number;
    public clamp_split_offset(): void;
    public set_collapsed(collapsed: boolean): void;
    public is_collapsed(): boolean;
    public set_dragger_visibility(mode: number): void;
    public get_dragger_visibility(): number;
    public set_vertical(vertical: boolean): void;
    public is_vertical(): boolean;
    public set_dragging_enabled(draggingEnabled: boolean): void;
    public is_dragging_enabled(): boolean;
    public set_drag_area_margin_begin(margin: number): void;
    public get_drag_area_margin_begin(): number;
    public set_drag_area_margin_end(margin: number): void;
    public get_drag_area_margin_end(): number;
    public set_drag_area_offset(offset: number): void;
    public get_drag_area_offset(): number;
    public set_drag_area_highlight_in_editor(dragAreaHighlightInEditor: boolean): void;
    public is_drag_area_highlight_in_editor_enabled(): boolean;
    public get_drag_area_control(): Control;
    public set_touch_dragger_enabled(enabled: boolean): void;
    public is_touch_dragger_enabled(): boolean;

    
    public readonly dragged: Signal<(offset: number) => void>;
    public readonly drag_started: Signal<() => void>;
    public readonly drag_ended: Signal<() => void>;

    public static readonly DraggerVisibility: {
        DRAGGER_VISIBLE: 0;
        DRAGGER_HIDDEN: 1;
        DRAGGER_HIDDEN_COLLAPSED: 2;
    };
}

