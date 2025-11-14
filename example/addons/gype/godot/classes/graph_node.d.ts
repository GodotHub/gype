
import type { Color } from '@godot/builtins/color';
import type { GDString } from '@godot/builtins/gd_string';
import type { GraphElement } from '@godot/classes/graph_element';
import type { HBoxContainer } from '@godot/classes/h_box_container';
import type { Signal } from '@godot/builtins/signal';
import type { Texture2D } from '@godot/classes/texture2d';
import type { Vector2 } from '@godot/builtins/vector2';
import type { Vector2i } from '@godot/builtins/vector2i';


export declare class GraphNode extends GraphElement {

    
    /**     * The raw type is 'String'     */
    public title: GDString;    
    /**     * The raw type is 'bool'     */
    public ignore_invalid_connection_type: boolean;    
    /**     * The raw type is 'int'     */
    public slots_focus_mode: number;
    public _draw_port(slotIndex: number, position: Vector2i, left: boolean, color: Color): void;
    public set_title(title: GDString | StringName | string): void;
    public get_title(): GDString;
    public get_titlebar_hbox(): HBoxContainer;
    public set_slot(slotIndex: number, enableLeftPort: boolean, typeLeft: number, colorLeft: Color, enableRightPort: boolean, typeRight: number, colorRight: Color, customIconLeft: Texture2D = null, customIconRight: Texture2D = null, drawStylebox: boolean = true): void;
    public clear_slot(slotIndex: number): void;
    public clear_all_slots(): void;
    public is_slot_enabled_left(slotIndex: number): boolean;
    public set_slot_enabled_left(slotIndex: number, enable: boolean): void;
    public set_slot_type_left(slotIndex: number, _type: number): void;
    public get_slot_type_left(slotIndex: number): number;
    public set_slot_color_left(slotIndex: number, color: Color): void;
    public get_slot_color_left(slotIndex: number): Color;
    public set_slot_custom_icon_left(slotIndex: number, customIcon: Texture2D): void;
    public get_slot_custom_icon_left(slotIndex: number): Texture2D;
    public is_slot_enabled_right(slotIndex: number): boolean;
    public set_slot_enabled_right(slotIndex: number, enable: boolean): void;
    public set_slot_type_right(slotIndex: number, _type: number): void;
    public get_slot_type_right(slotIndex: number): number;
    public set_slot_color_right(slotIndex: number, color: Color): void;
    public get_slot_color_right(slotIndex: number): Color;
    public set_slot_custom_icon_right(slotIndex: number, customIcon: Texture2D): void;
    public get_slot_custom_icon_right(slotIndex: number): Texture2D;
    public is_slot_draw_stylebox(slotIndex: number): boolean;
    public set_slot_draw_stylebox(slotIndex: number, enable: boolean): void;
    public set_ignore_invalid_connection_type(ignore: boolean): void;
    public is_ignoring_valid_connection_type(): boolean;
    public set_slots_focus_mode(focusMode: number): void;
    public get_slots_focus_mode(): number;
    public get_input_port_count(): number;
    public get_input_port_position(portIdx: number): Vector2;
    public get_input_port_type(portIdx: number): number;
    public get_input_port_color(portIdx: number): Color;
    public get_input_port_slot(portIdx: number): number;
    public get_output_port_count(): number;
    public get_output_port_position(portIdx: number): Vector2;
    public get_output_port_type(portIdx: number): number;
    public get_output_port_color(portIdx: number): Color;
    public get_output_port_slot(portIdx: number): number;

    
    public readonly slot_updated: Signal<(slotIndex: number) => void>;
    public readonly slot_sizes_changed: Signal<() => void>;

}

