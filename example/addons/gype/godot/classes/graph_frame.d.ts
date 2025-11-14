
import type { Color } from '@godot/builtins/color';
import type { GDString } from '@godot/builtins/gd_string';
import type { GraphElement } from '@godot/classes/graph_element';
import type { HBoxContainer } from '@godot/classes/h_box_container';
import type { Signal } from '@godot/builtins/signal';


export declare class GraphFrame extends GraphElement {

    
    /**     * The raw type is 'String'     */
    public title: GDString;    
    /**     * The raw type is 'bool'     */
    public autoshrink_enabled: boolean;    
    /**     * The raw type is 'int'     */
    public autoshrink_margin: number;    
    /**     * The raw type is 'int'     */
    public drag_margin: number;    
    /**     * The raw type is 'bool'     */
    public tint_color_enabled: boolean;    
    /**     * The raw type is 'Color'     */
    public tint_color: Color;
    public set_title(title: GDString | StringName | string): void;
    public get_title(): GDString;
    public get_titlebar_hbox(): HBoxContainer;
    public set_autoshrink_enabled(shrink: boolean): void;
    public is_autoshrink_enabled(): boolean;
    public set_autoshrink_margin(autoshrinkMargin: number): void;
    public get_autoshrink_margin(): number;
    public set_drag_margin(dragMargin: number): void;
    public get_drag_margin(): number;
    public set_tint_color_enabled(enable: boolean): void;
    public is_tint_color_enabled(): boolean;
    public set_tint_color(color: Color): void;
    public get_tint_color(): Color;

    
    public readonly autoshrink_changed: Signal<() => void>;

}

