
import { Texture2D } from "@godot/classes/texture2d";
import { Object } from "@godot/classes/object";
import { Font } from "@godot/classes/font";
import { Tree } from "@godot/classes/tree";

export declare class TreeItem extends Object{
  public set_cell_mode(_column: number, _mode: number): void;
  public get_cell_mode(_column: number): number;
  public set_edit_multiline(_column: number, _multiline: boolean): void;
  public is_edit_multiline(_column: number): boolean;
  public set_checked(_column: number, _checked: boolean): void;
  public set_indeterminate(_column: number, _indeterminate: boolean): void;
  public is_checked(_column: number): boolean;
  public is_indeterminate(_column: number): boolean;
  public propagate_check(_column: number, _emit_signal: boolean): void;
  public set_text(_column: number, _text: String): void;
  public get_text(_column: number): String;
  public set_text_direction(_column: number, _direction: number): void;
  public get_text_direction(_column: number): number;
  public set_autowrap_mode(_column: number, _autowrap_mode: number): void;
  public get_autowrap_mode(_column: number): number;
  public set_text_overrun_behavior(_column: number, _overrun_behavior: number): void;
  public get_text_overrun_behavior(_column: number): number;
  public set_structured_text_bidi_override(_column: number, _parser: number): void;
  public get_structured_text_bidi_override(_column: number): number;
  public set_structured_text_bidi_override_options(_column: number, _args: GDArray): void;
  public get_structured_text_bidi_override_options(_column: number): GDArray;
  public set_language(_column: number, _language: String): void;
  public get_language(_column: number): String;
  public set_suffix(_column: number, _text: String): void;
  public get_suffix(_column: number): String;
  public set_icon(_column: number, _texture: Texture2D): void;
  public get_icon(_column: number): Texture2D;
  public set_icon_region(_column: number, _region: Rect2): void;
  public get_icon_region(_column: number): Rect2;
  public set_icon_max_width(_column: number, _width: number): void;
  public get_icon_max_width(_column: number): number;
  public set_icon_modulate(_column: number, _modulate: Color): void;
  public get_icon_modulate(_column: number): Color;
  public set_range(_column: number, _value: number): void;
  public get_range(_column: number): number;
  public set_range_config(_column: number, _min: number, _max: number, _step: number, _expr: boolean): void;
  public get_range_config(_column: number): Dictionary;
  public set_metadata(_column: number, _meta: any): void;
  public get_metadata(_column: number): any;
  public set_custom_draw(_column: number, _object: Object, _callback: StringName): void;
  public set_custom_draw_callback(_column: number, _callback: Callable): void;
  public get_custom_draw_callback(_column: number): Callable;
  public set_collapsed(_enable: boolean): void;
  public is_collapsed(): boolean;
  public set_collapsed_recursive(_enable: boolean): void;
  public is_any_collapsed(_only_visible: boolean): boolean;
  public set_visible(_enable: boolean): void;
  public is_visible(): boolean;
  public is_visible_in_tree(): boolean;
  public uncollapse_tree(): void;
  public set_custom_minimum_height(_height: number): void;
  public get_custom_minimum_height(): number;
  public set_selectable(_column: number, _selectable: boolean): void;
  public is_selectable(_column: number): boolean;
  public is_selected(_column: number): boolean;
  public select(_column: number): void;
  public deselect(_column: number): void;
  public set_editable(_column: number, _enabled: boolean): void;
  public is_editable(_column: number): boolean;
  public set_custom_color(_column: number, _color: Color): void;
  public get_custom_color(_column: number): Color;
  public clear_custom_color(_column: number): void;
  public set_custom_font(_column: number, _font: Font): void;
  public get_custom_font(_column: number): Font;
  public set_custom_font_size(_column: number, _font_size: number): void;
  public get_custom_font_size(_column: number): number;
  public set_custom_bg_color(_column: number, _color: Color, _just_outline: boolean): void;
  public clear_custom_bg_color(_column: number): void;
  public get_custom_bg_color(_column: number): Color;
  public set_custom_as_button(_column: number, _enable: boolean): void;
  public is_custom_set_as_button(_column: number): boolean;
  public add_button(_column: number, _button: Texture2D, _id: number, _disabled: boolean, _tooltip_text: String): void;
  public get_button_count(_column: number): number;
  public get_button_tooltip_text(_column: number, _button_index: number): String;
  public get_button_id(_column: number, _button_index: number): number;
  public get_button_by_id(_column: number, _id: number): number;
  public get_button_color(_column: number, _id: number): Color;
  public get_button(_column: number, _button_index: number): Texture2D;
  public set_button_tooltip_text(_column: number, _button_index: number, _tooltip: String): void;
  public set_button(_column: number, _button_index: number, _button: Texture2D): void;
  public erase_button(_column: number, _button_index: number): void;
  public set_button_disabled(_column: number, _button_index: number, _disabled: boolean): void;
  public set_button_color(_column: number, _button_index: number, _color: Color): void;
  public is_button_disabled(_column: number, _button_index: number): boolean;
  public set_tooltip_text(_column: number, _tooltip: String): void;
  public get_tooltip_text(_column: number): String;
  public set_text_alignment(_column: number, _text_alignment: number): void;
  public get_text_alignment(_column: number): number;
  public set_expand_right(_column: number, _enable: boolean): void;
  public get_expand_right(_column: number): boolean;
  public set_disable_folding(_disable: boolean): void;
  public is_folding_disabled(): boolean;
  public create_child(_index: number): TreeItem;
  public add_child(_child: TreeItem): void;
  public remove_child(_child: TreeItem): void;
  public get_tree(): Tree;
  public get_next(): TreeItem;
  public get_prev(): TreeItem;
  public get_parent(): TreeItem;
  public get_first_child(): TreeItem;
  public get_next_in_tree(_wrap: boolean): TreeItem;
  public get_prev_in_tree(_wrap: boolean): TreeItem;
  public get_next_visible(_wrap: boolean): TreeItem;
  public get_prev_visible(_wrap: boolean): TreeItem;
  public get_child(_index: number): TreeItem;
  public get_child_count(): number;
  public get_children(): GDArray;
  public get_index(): number;
  public move_before(_item: TreeItem): void;
  public move_after(_item: TreeItem): void;
  public call_recursive(_method: StringName): void;
  public get collapsed(): boolean {
    is_collapsed();
  }
  public set collapsed(value): void {
    set_collapsed(value);
  }
  public get visible(): boolean {
    is_visible();
  }
  public set visible(value): void {
    set_visible(value);
  }
  public get disable_folding(): boolean {
    is_folding_disabled();
  }
  public set disable_folding(value): void {
    set_disable_folding(value);
  }
  public get custom_minimum_height(): number {
    get_custom_minimum_height();
  }
  public set custom_minimum_height(value): void {
    set_custom_minimum_height(value);
  }
  static TreeCellMode = {
    CELL_MODE_STRING = 0,
    CELL_MODE_CHECK = 1,
    CELL_MODE_RANGE = 2,
    CELL_MODE_ICON = 3,
    CELL_MODE_CUSTOM = 4,
  }
}