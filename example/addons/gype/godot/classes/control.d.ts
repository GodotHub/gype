
import type { CanvasItem } from '@godot/classes/canvas_item';
import type { Font } from '@godot/classes/font';
import type { GodotObject } from '@godot/classes/godot_object';
import type { InputEvent } from '@godot/classes/input_event';
import type { Node } from '@godot/classes/node';
import type { StyleBox } from '@godot/classes/style_box';
import type { Texture2D } from '@godot/classes/texture2d';
import type { Theme } from '@godot/classes/theme';


export declare class Control extends CanvasItem {

    
    /**     * The raw type is 'bool'     */
    public clip_contents: boolean;    
    /**     * The raw type is 'Vector2'     */
    public custom_minimum_size: Vector2;    
    /**     * The raw type is 'int'     */
    public layout_direction: number;    
    /**     * The raw type is 'int'     */
    public layout_mode: number;    
    /**     * The raw type is 'int'     */
    public anchors_preset: number;    
    /**     * The raw type is 'float'     */
    public anchor_left: number;    
    /**     * The raw type is 'float'     */
    public anchor_top: number;    
    /**     * The raw type is 'float'     */
    public anchor_right: number;    
    /**     * The raw type is 'float'     */
    public anchor_bottom: number;    
    /**     * The raw type is 'float'     */
    public offset_left: number;    
    /**     * The raw type is 'float'     */
    public offset_top: number;    
    /**     * The raw type is 'float'     */
    public offset_right: number;    
    /**     * The raw type is 'float'     */
    public offset_bottom: number;    
    /**     * The raw type is 'int'     */
    public grow_horizontal: number;    
    /**     * The raw type is 'int'     */
    public grow_vertical: number;    
    /**     * The raw type is 'Vector2'     */
    public size: Vector2;    
    /**     * The raw type is 'Vector2'     */
    public position: Vector2;    
    /**     * The raw type is 'Vector2'     */
    public global_position: Vector2;    
    /**     * The raw type is 'float'     */
    public rotation: number;    
    /**     * The raw type is 'float'     */
    public rotation_degrees: number;    
    /**     * The raw type is 'Vector2'     */
    public scale: Vector2;    
    /**     * The raw type is 'Vector2'     */
    public pivot_offset: Vector2;    
    /**     * The raw type is 'int'     */
    public size_flags_horizontal: number;    
    /**     * The raw type is 'int'     */
    public size_flags_vertical: number;    
    /**     * The raw type is 'float'     */
    public size_flags_stretch_ratio: number;    
    /**     * The raw type is 'bool'     */
    public localize_numeral_system: boolean;    
    /**     * The raw type is 'bool'     */
    public auto_translate: boolean;    
    /**     * The raw type is 'String'     */
    public tooltip_text: GDString;    
    /**     * The raw type is 'int'     */
    public tooltip_auto_translate_mode: number;    
    /**     * The raw type is 'NodePath'     */
    public focus_neighbor_left: NodePath;    
    /**     * The raw type is 'NodePath'     */
    public focus_neighbor_top: NodePath;    
    /**     * The raw type is 'NodePath'     */
    public focus_neighbor_right: NodePath;    
    /**     * The raw type is 'NodePath'     */
    public focus_neighbor_bottom: NodePath;    
    /**     * The raw type is 'NodePath'     */
    public focus_next: NodePath;    
    /**     * The raw type is 'NodePath'     */
    public focus_previous: NodePath;    
    /**     * The raw type is 'int'     */
    public focus_mode: number;    
    /**     * The raw type is 'int'     */
    public focus_behavior_recursive: number;    
    /**     * The raw type is 'int'     */
    public mouse_filter: number;    
    /**     * The raw type is 'int'     */
    public mouse_behavior_recursive: number;    
    /**     * The raw type is 'bool'     */
    public mouse_force_pass_scroll_events: boolean;    
    /**     * The raw type is 'int'     */
    public mouse_default_cursor_shape: number;    
    /**     * The raw type is 'Object'     */
    public shortcut_context: Node;    
    /**     * The raw type is 'String'     */
    public accessibility_name: GDString;    
    /**     * The raw type is 'String'     */
    public accessibility_description: GDString;    
    /**     * The raw type is 'int'     */
    public accessibility_live: number;    
    /**     * The raw type is 'typedarray::NodePath'     */
    public accessibility_controls_nodes: Array<any>;    
    /**     * The raw type is 'typedarray::NodePath'     */
    public accessibility_described_by_nodes: Array<any>;    
    /**     * The raw type is 'typedarray::NodePath'     */
    public accessibility_labeled_by_nodes: Array<any>;    
    /**     * The raw type is 'typedarray::NodePath'     */
    public accessibility_flow_to_nodes: Array<any>;    
    /**     * The raw type is 'Theme'     */
    public theme: Theme;    
    /**     * The raw type is 'String'     */
    public theme_type_variation: StringName;
    public _has_point(point: Vector2): boolean;
    public _structured_text_parser(args: GDArray, text: GDString | StringName | string): Array<any>;
    public _get_minimum_size(): Vector2;
    public _get_tooltip(atPosition: Vector2): GDString;
    public _get_drag_data(atPosition: Vector2): any;
    public _can_drop_data(atPosition: Vector2, data: any): boolean;
    public _drop_data(atPosition: Vector2, data: any): void;
    public _make_custom_tooltip(forText: GDString | StringName | string): GodotObject;
    public _accessibility_get_contextual_info(): GDString;
    public _get_accessibility_container_name(node: Node): GDString;
    public _gui_input(event: InputEvent): void;
    public accept_event(): void;
    public get_minimum_size(): Vector2;
    public get_combined_minimum_size(): Vector2;
    public set_anchors_preset(preset: number, keeoffsets: boolean = false): void;
    public set_offsets_preset(preset: number, resizeMode: number = 0, margin: number = 0): void;
    public set_anchors_and_offsets_preset(preset: number, resizeMode: number = 0, margin: number = 0): void;
    public set_anchor(side: number, anchor: number, keeoffset: boolean = false, pushOppositeAnchor: boolean = true): void;
    public get_anchor(side: number): number;
    public set_offset(side: number, offset: number): void;
    public get_offset(offset: number): number;
    public set_anchor_and_offset(side: number, anchor: number, offset: number, pushOppositeAnchor: boolean = false): void;
    public set_begin(position: Vector2): void;
    public set_end(position: Vector2): void;
    public set_position(position: Vector2, keeoffsets: boolean = false): void;
    public set_size(size: Vector2, keeoffsets: boolean = false): void;
    public reset_size(): void;
    public set_custom_minimum_size(size: Vector2): void;
    public set_global_position(position: Vector2, keeoffsets: boolean = false): void;
    public set_rotation(radians: number): void;
    public set_rotation_degrees(degrees: number): void;
    public set_scale(scale: Vector2): void;
    public set_pivot_offset(pivotOffset: Vector2): void;
    public get_begin(): Vector2;
    public get_end(): Vector2;
    public get_position(): Vector2;
    public get_size(): Vector2;
    public get_rotation(): number;
    public get_rotation_degrees(): number;
    public get_scale(): Vector2;
    public get_pivot_offset(): Vector2;
    public get_custom_minimum_size(): Vector2;
    public get_parent_area_size(): Vector2;
    public get_global_position(): Vector2;
    public get_screen_position(): Vector2;
    public get_rect(): Rect2;
    public get_global_rect(): Rect2;
    public set_focus_mode(mode: number): void;
    public get_focus_mode(): number;
    public get_focus_mode_with_override(): number;
    public set_focus_behavior_recursive(focusBehaviorRecursive: number): void;
    public get_focus_behavior_recursive(): number;
    public has_focus(): boolean;
    public grab_focus(): void;
    public release_focus(): void;
    public find_prev_valid_focus(): Control;
    public find_next_valid_focus(): Control;
    public find_valid_focus_neighbor(side: number): Control;
    public set_h_size_flags(flags: number): void;
    public get_h_size_flags(): number;
    public set_stretch_ratio(ratio: number): void;
    public get_stretch_ratio(): number;
    public set_v_size_flags(flags: number): void;
    public get_v_size_flags(): number;
    public set_theme(theme: Theme): void;
    public get_theme(): Theme;
    public set_theme_type_variation(themeType: GDString | StringName | string): void;
    public get_theme_type_variation(): StringName;
    public begin_bulk_theme_override(): void;
    public end_bulk_theme_override(): void;
    public add_theme_icon_override(name: GDString | StringName | string, texture: Texture2D): void;
    public add_theme_stylebox_override(name: GDString | StringName | string, stylebox: StyleBox): void;
    public add_theme_font_override(name: GDString | StringName | string, font: Font): void;
    public add_theme_font_size_override(name: GDString | StringName | string, fontSize: number): void;
    public add_theme_color_override(name: GDString | StringName | string, color: Color): void;
    public add_theme_constant_override(name: GDString | StringName | string, constant: number): void;
    public remove_theme_icon_override(name: GDString | StringName | string): void;
    public remove_theme_stylebox_override(name: GDString | StringName | string): void;
    public remove_theme_font_override(name: GDString | StringName | string): void;
    public remove_theme_font_size_override(name: GDString | StringName | string): void;
    public remove_theme_color_override(name: GDString | StringName | string): void;
    public remove_theme_constant_override(name: GDString | StringName | string): void;
    public get_theme_icon(name: GDString | StringName | string, themeType: GDString | StringName | string = ""): Texture2D;
    public get_theme_stylebox(name: GDString | StringName | string, themeType: GDString | StringName | string = ""): StyleBox;
    public get_theme_font(name: GDString | StringName | string, themeType: GDString | StringName | string = ""): Font;
    public get_theme_font_size(name: GDString | StringName | string, themeType: GDString | StringName | string = ""): number;
    public get_theme_color(name: GDString | StringName | string, themeType: GDString | StringName | string = ""): Color;
    public get_theme_constant(name: GDString | StringName | string, themeType: GDString | StringName | string = ""): number;
    public has_theme_icon_override(name: GDString | StringName | string): boolean;
    public has_theme_stylebox_override(name: GDString | StringName | string): boolean;
    public has_theme_font_override(name: GDString | StringName | string): boolean;
    public has_theme_font_size_override(name: GDString | StringName | string): boolean;
    public has_theme_color_override(name: GDString | StringName | string): boolean;
    public has_theme_constant_override(name: GDString | StringName | string): boolean;
    public has_theme_icon(name: GDString | StringName | string, themeType: GDString | StringName | string = ""): boolean;
    public has_theme_stylebox(name: GDString | StringName | string, themeType: GDString | StringName | string = ""): boolean;
    public has_theme_font(name: GDString | StringName | string, themeType: GDString | StringName | string = ""): boolean;
    public has_theme_font_size(name: GDString | StringName | string, themeType: GDString | StringName | string = ""): boolean;
    public has_theme_color(name: GDString | StringName | string, themeType: GDString | StringName | string = ""): boolean;
    public has_theme_constant(name: GDString | StringName | string, themeType: GDString | StringName | string = ""): boolean;
    public get_theme_default_base_scale(): number;
    public get_theme_default_font(): Font;
    public get_theme_default_font_size(): number;
    public get_parent_control(): Control;
    public set_h_grow_direction(direction: number): void;
    public get_h_grow_direction(): number;
    public set_v_grow_direction(direction: number): void;
    public get_v_grow_direction(): number;
    public set_tooltip_auto_translate_mode(mode: number): void;
    public get_tooltip_auto_translate_mode(): number;
    public set_tooltip_text(hint: GDString | StringName | string): void;
    public get_tooltip_text(): GDString;
    public get_tooltip(atPosition: Vector2 = Vector2(0, 0)): GDString;
    public set_default_cursor_shape(shape: number): void;
    public get_default_cursor_shape(): number;
    public get_cursor_shape(position: Vector2 = Vector2(0, 0)): number;
    public set_focus_neighbor(side: number, neighbor: NodePath | GDString | string): void;
    public get_focus_neighbor(side: number): NodePath;
    public set_focus_next(next: NodePath | GDString | string): void;
    public get_focus_next(): NodePath;
    public set_focus_previous(previous: NodePath | GDString | string): void;
    public get_focus_previous(): NodePath;
    public force_drag(data: any, preview: Control): void;
    public accessibility_drag(): void;
    public accessibility_drop(): void;
    public set_accessibility_name(name: GDString | StringName | string): void;
    public get_accessibility_name(): GDString;
    public set_accessibility_description(description: GDString | StringName | string): void;
    public get_accessibility_description(): GDString;
    public set_accessibility_live(mode: number): void;
    public get_accessibility_live(): number;
    public set_accessibility_controls_nodes(nodePath: Array<any>): void;
    public get_accessibility_controls_nodes(): Array<any>;
    public set_accessibility_described_by_nodes(nodePath: Array<any>): void;
    public get_accessibility_described_by_nodes(): Array<any>;
    public set_accessibility_labeled_by_nodes(nodePath: Array<any>): void;
    public get_accessibility_labeled_by_nodes(): Array<any>;
    public set_accessibility_flow_to_nodes(nodePath: Array<any>): void;
    public get_accessibility_flow_to_nodes(): Array<any>;
    public set_mouse_filter(filter: number): void;
    public get_mouse_filter(): number;
    public get_mouse_filter_with_override(): number;
    public set_mouse_behavior_recursive(mouseBehaviorRecursive: number): void;
    public get_mouse_behavior_recursive(): number;
    public set_force_pass_scroll_events(forcePassScrollEvents: boolean): void;
    public is_force_pass_scroll_events(): boolean;
    public set_clip_contents(enable: boolean): void;
    public is_clipping_contents(): boolean;
    public grab_click_focus(): void;
    public set_drag_forwarding(dragFunc: Callable | Function, canDrofunc: Callable | Function, drofunc: Callable | Function): void;
    public set_drag_preview(control: Control): void;
    public is_drag_successful(): boolean;
    public warp_mouse(position: Vector2): void;
    public set_shortcut_context(node: Node): void;
    public get_shortcut_context(): Node;
    public update_minimum_size(): void;
    public set_layout_direction(direction: number): void;
    public get_layout_direction(): number;
    public is_layout_rtl(): boolean;
    public set_auto_translate(enable: boolean): void;
    public is_auto_translating(): boolean;
    public set_localize_numeral_system(enable: boolean): void;
    public is_localizing_numeral_system(): boolean;

    
    public readonly resized: Signal;
    public readonly gui_input: Signal;
    public readonly mouse_entered: Signal;
    public readonly mouse_exited: Signal;
    public readonly focus_entered: Signal;
    public readonly focus_exited: Signal;
    public readonly size_flags_changed: Signal;
    public readonly minimum_size_changed: Signal;
    public readonly theme_changed: Signal;

    public static readonly FocusMode: {
        FOCUS_NONE: 0;
        FOCUS_CLICK: 1;
        FOCUS_ALL: 2;
        FOCUS_ACCESSIBILITY: 3;
    };
    public static readonly FocusBehaviorRecursive: {
        FOCUS_BEHAVIOR_INHERITED: 0;
        FOCUS_BEHAVIOR_DISABLED: 1;
        FOCUS_BEHAVIOR_ENABLED: 2;
    };
    public static readonly MouseBehaviorRecursive: {
        MOUSE_BEHAVIOR_INHERITED: 0;
        MOUSE_BEHAVIOR_DISABLED: 1;
        MOUSE_BEHAVIOR_ENABLED: 2;
    };
    public static readonly CursorShape: {
        CURSOR_ARROW: 0;
        CURSOR_IBEAM: 1;
        CURSOR_POINTING_HAND: 2;
        CURSOR_CROSS: 3;
        CURSOR_WAIT: 4;
        CURSOR_BUSY: 5;
        CURSOR_DRAG: 6;
        CURSOR_CAN_DROP: 7;
        CURSOR_FORBIDDEN: 8;
        CURSOR_VSIZE: 9;
        CURSOR_HSIZE: 10;
        CURSOR_BDIAGSIZE: 11;
        CURSOR_FDIAGSIZE: 12;
        CURSOR_MOVE: 13;
        CURSOR_VSPLIT: 14;
        CURSOR_HSPLIT: 15;
        CURSOR_HELP: 16;
    };
    public static readonly LayoutPreset: {
        PRESET_TOP_LEFT: 0;
        PRESET_TOP_RIGHT: 1;
        PRESET_BOTTOM_LEFT: 2;
        PRESET_BOTTOM_RIGHT: 3;
        PRESET_CENTER_LEFT: 4;
        PRESET_CENTER_TOP: 5;
        PRESET_CENTER_RIGHT: 6;
        PRESET_CENTER_BOTTOM: 7;
        PRESET_CENTER: 8;
        PRESET_LEFT_WIDE: 9;
        PRESET_TOP_WIDE: 10;
        PRESET_RIGHT_WIDE: 11;
        PRESET_BOTTOM_WIDE: 12;
        PRESET_VCENTER_WIDE: 13;
        PRESET_HCENTER_WIDE: 14;
        PRESET_FULL_RECT: 15;
    };
    public static readonly LayoutPresetMode: {
        PRESET_MODE_MINSIZE: 0;
        PRESET_MODE_KEEP_WIDTH: 1;
        PRESET_MODE_KEEP_HEIGHT: 2;
        PRESET_MODE_KEEP_SIZE: 3;
    };
    public static readonly SizeFlags: {
        SIZE_SHRINK_BEGIN: 0;
        SIZE_FILL: 1;
        SIZE_EXPAND: 2;
        SIZE_EXPAND_FILL: 3;
        SIZE_SHRINK_CENTER: 4;
        SIZE_SHRINK_END: 8;
    };
    public static readonly MouseFilter: {
        MOUSE_FILTER_STOP: 0;
        MOUSE_FILTER_PASS: 1;
        MOUSE_FILTER_IGNORE: 2;
    };
    public static readonly GrowDirection: {
        GROW_DIRECTION_BEGIN: 0;
        GROW_DIRECTION_END: 1;
        GROW_DIRECTION_BOTH: 2;
    };
    public static readonly Anchor: {
        ANCHOR_BEGIN: 0;
        ANCHOR_END: 1;
    };
    public static readonly LayoutDirection: {
        LAYOUT_DIRECTION_INHERITED: 0;
        LAYOUT_DIRECTION_APPLICATION_LOCALE: 1;
        LAYOUT_DIRECTION_LTR: 2;
        LAYOUT_DIRECTION_RTL: 3;
        LAYOUT_DIRECTION_SYSTEM_LOCALE: 4;
        LAYOUT_DIRECTION_MAX: 5;
        LAYOUT_DIRECTION_LOCALE: 1;
    };
    public static readonly TextDirection: {
        TEXT_DIRECTION_INHERITED: 3;
        TEXT_DIRECTION_AUTO: 0;
        TEXT_DIRECTION_LTR: 1;
        TEXT_DIRECTION_RTL: 2;
    };
}

