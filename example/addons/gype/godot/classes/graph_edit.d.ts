
import type { Control } from '@godot/classes/control';
import type { Dictionary } from '@godot/builtins/dictionary';
import type { GDArray } from '@godot/builtins/gd_array';
import type { GDString } from '@godot/builtins/gd_string';
import type { GodotObject } from '@godot/classes/godot_object';
import type { GraphFrame } from '@godot/classes/graph_frame';
import type { HBoxContainer } from '@godot/classes/h_box_container';
import type { Node } from '@godot/classes/node';
import type { PackedVector2Array } from '@godot/builtins/packed_vector2_array';
import type { Rect2 } from '@godot/builtins/rect2';
import type { Signal } from '@godot/builtins/signal';
import type { StringName } from '@godot/builtins/string_name';
import type { Vector2 } from '@godot/builtins/vector2';


export declare class GraphEdit extends Control {

    
    /**     * The raw type is 'Vector2'     */
    public scroll_offset: Vector2;    
    /**     * The raw type is 'bool'     */
    public show_grid: boolean;    
    /**     * The raw type is 'int'     */
    public grid_pattern: number;    
    /**     * The raw type is 'bool'     */
    public snapping_enabled: boolean;    
    /**     * The raw type is 'int'     */
    public snapping_distance: number;    
    /**     * The raw type is 'int'     */
    public panning_scheme: number;    
    /**     * The raw type is 'bool'     */
    public right_disconnects: boolean;    
    /**     * The raw type is 'typeddictionary::int;String'     */
    public type_names: Dictionary;    
    /**     * The raw type is 'float'     */
    public connection_lines_curvature: number;    
    /**     * The raw type is 'float'     */
    public connection_lines_thickness: number;    
    /**     * The raw type is 'bool'     */
    public connection_lines_antialiased: boolean;    
    /**     * The raw type is 'typedarray::27/0:'     */
    public connections: Array<any>;    
    /**     * The raw type is 'float'     */
    public zoom: number;    
    /**     * The raw type is 'float'     */
    public zoom_min: number;    
    /**     * The raw type is 'float'     */
    public zoom_max: number;    
    /**     * The raw type is 'float'     */
    public zoom_step: number;    
    /**     * The raw type is 'bool'     */
    public minimap_enabled: boolean;    
    /**     * The raw type is 'Vector2'     */
    public minimap_size: Vector2;    
    /**     * The raw type is 'float'     */
    public minimap_opacity: number;    
    /**     * The raw type is 'bool'     */
    public show_menu: boolean;    
    /**     * The raw type is 'bool'     */
    public show_zoom_label: boolean;    
    /**     * The raw type is 'bool'     */
    public show_zoom_buttons: boolean;    
    /**     * The raw type is 'bool'     */
    public show_grid_buttons: boolean;    
    /**     * The raw type is 'bool'     */
    public show_minimap_button: boolean;    
    /**     * The raw type is 'bool'     */
    public show_arrange_button: boolean;
    public _is_in_input_hotzone(inNode: GodotObject, inPort: number, mousePosition: Vector2): boolean;
    public _is_in_output_hotzone(inNode: GodotObject, inPort: number, mousePosition: Vector2): boolean;
    public _get_connection_line(fromPosition: Vector2, toPosition: Vector2): PackedVector2Array;
    public _is_node_hover_valid(fromNode: GDString | StringName | string, fromPort: number, toNode: GDString | StringName | string, toPort: number): boolean;
    public connect_node(fromNode: GDString | StringName | string, fromPort: number, toNode: GDString | StringName | string, toPort: number, keealive: boolean = false): number;
    public is_node_connected(fromNode: GDString | StringName | string, fromPort: number, toNode: GDString | StringName | string, toPort: number): boolean;
    public disconnect_node(fromNode: GDString | StringName | string, fromPort: number, toNode: GDString | StringName | string, toPort: number): void;
    public set_connection_activity(fromNode: GDString | StringName | string, fromPort: number, toNode: GDString | StringName | string, toPort: number, amount: number): void;
    public set_connections(connections: Array<any>): void;
    public get_connection_list(): Array<any>;
    public get_connection_count(fromNode: GDString | StringName | string, fromPort: number): number;
    public get_closest_connection_at_point(point: Vector2, maxDistance: number = 4.0): Dictionary;
    public get_connection_list_from_node(node: GDString | StringName | string): Array<any>;
    public get_connections_intersecting_with_rect(rect: Rect2): Array<any>;
    public clear_connections(): void;
    public force_connection_drag_end(): void;
    public get_scroll_offset(): Vector2;
    public set_scroll_offset(offset: Vector2): void;
    public add_valid_right_disconnect_type(_type: number): void;
    public remove_valid_right_disconnect_type(_type: number): void;
    public add_valid_left_disconnect_type(_type: number): void;
    public remove_valid_left_disconnect_type(_type: number): void;
    public add_valid_connection_type(fromType: number, toType: number): void;
    public remove_valid_connection_type(fromType: number, toType: number): void;
    public is_valid_connection_type(fromType: number, toType: number): boolean;
    public get_connection_line(fromNode: Vector2, toNode: Vector2): PackedVector2Array;
    public attach_graph_element_to_frame(element: GDString | StringName | string, frame: GDString | StringName | string): void;
    public detach_graph_element_from_frame(element: GDString | StringName | string): void;
    public get_element_frame(element: GDString | StringName | string): GraphFrame;
    public get_attached_nodes_of_frame(frame: GDString | StringName | string): Array<any>;
    public set_panning_scheme(scheme: number): void;
    public get_panning_scheme(): number;
    public set_zoom(zoom: number): void;
    public get_zoom(): number;
    public set_zoom_min(zoomMin: number): void;
    public get_zoom_min(): number;
    public set_zoom_max(zoomMax: number): void;
    public get_zoom_max(): number;
    public set_zoom_step(zoomStep: number): void;
    public get_zoom_step(): number;
    public set_show_grid(enable: boolean): void;
    public is_showing_grid(): boolean;
    public set_grid_pattern(pattern: number): void;
    public get_grid_pattern(): number;
    public set_snapping_enabled(enable: boolean): void;
    public is_snapping_enabled(): boolean;
    public set_snapping_distance(pixels: number): void;
    public get_snapping_distance(): number;
    public set_connection_lines_curvature(curvature: number): void;
    public get_connection_lines_curvature(): number;
    public set_connection_lines_thickness(pixels: number): void;
    public get_connection_lines_thickness(): number;
    public set_connection_lines_antialiased(pixels: boolean): void;
    public is_connection_lines_antialiased(): boolean;
    public set_minimap_size(size: Vector2): void;
    public get_minimap_size(): Vector2;
    public set_minimap_opacity(opacity: number): void;
    public get_minimap_opacity(): number;
    public set_minimap_enabled(enable: boolean): void;
    public is_minimap_enabled(): boolean;
    public set_show_menu(hidden: boolean): void;
    public is_showing_menu(): boolean;
    public set_show_zoom_label(enable: boolean): void;
    public is_showing_zoom_label(): boolean;
    public set_show_grid_buttons(hidden: boolean): void;
    public is_showing_grid_buttons(): boolean;
    public set_show_zoom_buttons(hidden: boolean): void;
    public is_showing_zoom_buttons(): boolean;
    public set_show_minimap_button(hidden: boolean): void;
    public is_showing_minimap_button(): boolean;
    public set_show_arrange_button(hidden: boolean): void;
    public is_showing_arrange_button(): boolean;
    public set_right_disconnects(enable: boolean): void;
    public is_right_disconnects_enabled(): boolean;
    public set_type_names(typeNames: Dictionary): void;
    public get_type_names(): Dictionary;
    public get_menu_hbox(): HBoxContainer;
    public arrange_nodes(): void;
    public set_selected(node: Node): void;

    
    public readonly connection_request: Signal<(fromNode: GDString | StringName | string, fromPort: number, toNode: GDString | StringName | string, toPort: number) => void>;
    public readonly disconnection_request: Signal<(fromNode: GDString | StringName | string, fromPort: number, toNode: GDString | StringName | string, toPort: number) => void>;
    public readonly connection_to_empty: Signal<(fromNode: GDString | StringName | string, fromPort: number, releasePosition: Vector2) => void>;
    public readonly connection_from_empty: Signal<(toNode: GDString | StringName | string, toPort: number, releasePosition: Vector2) => void>;
    public readonly connection_drag_started: Signal<(fromNode: GDString | StringName | string, fromPort: number, isOutput: boolean) => void>;
    public readonly connection_drag_ended: Signal<() => void>;
    public readonly copy_nodes_request: Signal<() => void>;
    public readonly cut_nodes_request: Signal<() => void>;
    public readonly paste_nodes_request: Signal<() => void>;
    public readonly duplicate_nodes_request: Signal<() => void>;
    public readonly delete_nodes_request: Signal<(nodes: Array<any>) => void>;
    public readonly node_selected: Signal<(node: Node) => void>;
    public readonly node_deselected: Signal<(node: Node) => void>;
    public readonly frame_rect_changed: Signal<(frame: GraphFrame, newRect: Rect2) => void>;
    public readonly popup_request: Signal<(atPosition: Vector2) => void>;
    public readonly begin_node_move: Signal<() => void>;
    public readonly end_node_move: Signal<() => void>;
    public readonly graph_elements_linked_to_frame_request: Signal<(elements: GDArray, frame: GDString | StringName | string) => void>;
    public readonly scroll_offset_changed: Signal<(offset: Vector2) => void>;

    public static readonly PanningScheme: {
        SCROLL_ZOOMS: 0;
        SCROLL_PANS: 1;
    };
    public static readonly GridPattern: {
        GRID_PATTERN_LINES: 0;
        GRID_PATTERN_DOTS: 1;
    };
}

