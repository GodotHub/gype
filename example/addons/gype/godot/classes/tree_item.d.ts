
import type { Font } from '@godot/classes/font';
import type { GodotObject } from '@godot/classes/godot_object';
import type { Texture2D } from '@godot/classes/texture2d';
import type { Tree } from '@godot/classes/tree';


export declare class TreeItem extends GodotObject {

    
    /**     * The raw type is 'bool'     */
    public collapsed: boolean;    
    /**     * The raw type is 'bool'     */
    public visible: boolean;    
    /**     * The raw type is 'bool'     */
    public disable_folding: boolean;    
    /**     * The raw type is 'int'     */
    public custom_minimum_height: number;
    public set_cell_mode(column: number, mode: number): void;
    public get_cell_mode(column: number): number;
    public set_auto_translate_mode(column: number, mode: number): void;
    public get_auto_translate_mode(column: number): number;
    public set_edit_multiline(column: number, multiline: boolean): void;
    public is_edit_multiline(column: number): boolean;
    public set_checked(column: number, checked: boolean): void;
    public set_indeterminate(column: number, indeterminate: boolean): void;
    public is_checked(column: number): boolean;
    public is_indeterminate(column: number): boolean;
    public propagate_check(column: number, emitSignal: boolean = true): void;
    public set_text(column: number, text: GDString | StringName | string): void;
    public get_text(column: number): GDString;
    public set_description(column: number, description: GDString | StringName | string): void;
    public get_description(column: number): GDString;
    public set_text_direction(column: number, direction: number): void;
    public get_text_direction(column: number): number;
    public set_autowrap_mode(column: number, autowramode: number): void;
    public get_autowrap_mode(column: number): number;
    public set_text_overrun_behavior(column: number, overrunBehavior: number): void;
    public get_text_overrun_behavior(column: number): number;
    public set_structured_text_bidi_override(column: number, parser: number): void;
    public get_structured_text_bidi_override(column: number): number;
    public set_structured_text_bidi_override_options(column: number, args: GDArray): void;
    public get_structured_text_bidi_override_options(column: number): GDArray;
    public set_language(column: number, language: GDString | StringName | string): void;
    public get_language(column: number): GDString;
    public set_suffix(column: number, text: GDString | StringName | string): void;
    public get_suffix(column: number): GDString;
    public set_icon(column: number, texture: Texture2D): void;
    public get_icon(column: number): Texture2D;
    public set_icon_overlay(column: number, texture: Texture2D): void;
    public get_icon_overlay(column: number): Texture2D;
    public set_icon_region(column: number, region: Rect2): void;
    public get_icon_region(column: number): Rect2;
    public set_icon_max_width(column: number, width: number): void;
    public get_icon_max_width(column: number): number;
    public set_icon_modulate(column: number, modulate: Color): void;
    public get_icon_modulate(column: number): Color;
    public set_range(column: number, value: number): void;
    public get_range(column: number): number;
    public set_range_config(column: number, min: number, max: number, step: number, expr: boolean = false): void;
    public get_range_config(column: number): Dictionary;
    public set_metadata(column: number, meta: any): void;
    public get_metadata(column: number): any;
    public set_custom_draw(column: number, object: GodotObject, callback: GDString | StringName | string): void;
    public set_custom_draw_callback(column: number, callback: Callable | Function): void;
    public get_custom_draw_callback(column: number): Callable;
    public set_collapsed(enable: boolean): void;
    public is_collapsed(): boolean;
    public set_collapsed_recursive(enable: boolean): void;
    public is_any_collapsed(onlyVisible: boolean = false): boolean;
    public set_visible(enable: boolean): void;
    public is_visible(): boolean;
    public is_visible_in_tree(): boolean;
    public uncollapse_tree(): void;
    public set_custom_minimum_height(height: number): void;
    public get_custom_minimum_height(): number;
    public set_selectable(column: number, selectable: boolean): void;
    public is_selectable(column: number): boolean;
    public is_selected(column: number): boolean;
    public select(column: number): void;
    public deselect(column: number): void;
    public set_editable(column: number, enabled: boolean): void;
    public is_editable(column: number): boolean;
    public set_custom_color(column: number, color: Color): void;
    public get_custom_color(column: number): Color;
    public clear_custom_color(column: number): void;
    public set_custom_font(column: number, font: Font): void;
    public get_custom_font(column: number): Font;
    public set_custom_font_size(column: number, fontSize: number): void;
    public get_custom_font_size(column: number): number;
    public set_custom_bg_color(column: number, color: Color, justOutline: boolean = false): void;
    public clear_custom_bg_color(column: number): void;
    public get_custom_bg_color(column: number): Color;
    public set_custom_as_button(column: number, enable: boolean): void;
    public is_custom_set_as_button(column: number): boolean;
    public clear_buttons(): void;
    public add_button(column: number, button: Texture2D, id: number = -1, disabled: boolean = false, tooltitext: GDString | StringName | string = "", description: GDString | StringName | string = ""): void;
    public get_button_count(column: number): number;
    public get_button_tooltip_text(column: number, buttonIndex: number): GDString;
    public get_button_id(column: number, buttonIndex: number): number;
    public get_button_by_id(column: number, id: number): number;
    public get_button_color(column: number, id: number): Color;
    public get_button(column: number, buttonIndex: number): Texture2D;
    public set_button_tooltip_text(column: number, buttonIndex: number, tooltip: GDString | StringName | string): void;
    public set_button(column: number, buttonIndex: number, button: Texture2D): void;
    public erase_button(column: number, buttonIndex: number): void;
    public set_button_description(column: number, buttonIndex: number, description: GDString | StringName | string): void;
    public set_button_disabled(column: number, buttonIndex: number, disabled: boolean): void;
    public set_button_color(column: number, buttonIndex: number, color: Color): void;
    public is_button_disabled(column: number, buttonIndex: number): boolean;
    public set_tooltip_text(column: number, tooltip: GDString | StringName | string): void;
    public get_tooltip_text(column: number): GDString;
    public set_text_alignment(column: number, textAlignment: number): void;
    public get_text_alignment(column: number): number;
    public set_expand_right(column: number, enable: boolean): void;
    public get_expand_right(column: number): boolean;
    public set_disable_folding(disable: boolean): void;
    public is_folding_disabled(): boolean;
    public create_child(index: number = -1): TreeItem;
    public add_child(child: TreeItem): void;
    public remove_child(child: TreeItem): void;
    public get_tree(): Tree;
    public get_next(): TreeItem;
    public get_prev(): TreeItem;
    public get_parent(): TreeItem;
    public get_first_child(): TreeItem;
    public get_next_in_tree(wrap: boolean = false): TreeItem;
    public get_prev_in_tree(wrap: boolean = false): TreeItem;
    public get_next_visible(wrap: boolean = false): TreeItem;
    public get_prev_visible(wrap: boolean = false): TreeItem;
    public get_child(index: number): TreeItem;
    public get_child_count(): number;
    public get_children(): Array<any>;
    public get_index(): number;
    public move_before(item: TreeItem): void;
    public move_after(item: TreeItem): void;
    public call_recursive(method: GDString | StringName | string, ...args: any[]): void;


    public static readonly TreeCellMode: {
        CELL_MODE_STRING: 0;
        CELL_MODE_CHECK: 1;
        CELL_MODE_RANGE: 2;
        CELL_MODE_ICON: 3;
        CELL_MODE_CUSTOM: 4;
    };
}

