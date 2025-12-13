
import type { Font } from '@godot/classes/font';
import type { InputEvent } from '@godot/classes/input_event';
import type { Node } from '@godot/classes/node';
import type { StyleBox } from '@godot/classes/style_box';
import type { Texture2D } from '@godot/classes/texture2d';
import type { Theme } from '@godot/classes/theme';
import type { Viewport } from '@godot/classes/viewport';


export declare class Window extends Viewport {

    
    /**     * The raw type is 'int'     */
    public mode: number;    
    /**     * The raw type is 'String'     */
    public title: GDString | StringName | string;    
    /**     * The raw type is 'int'     */
    public initial_position: number;    
    /**     * The raw type is 'Vector2i'     */
    public position: Vector2i;    
    /**     * The raw type is 'Vector2i'     */
    public size: Vector2i;    
    /**     * The raw type is 'int'     */
    public current_screen: number;    
    /**     * The raw type is 'PackedVector2Array'     */
    public mouse_passthrough_polygon: PackedVector2Array;    
    /**     * The raw type is 'bool'     */
    public visible: boolean;    
    /**     * The raw type is 'bool'     */
    public wrap_controls: boolean;    
    /**     * The raw type is 'bool'     */
    public transient: boolean;    
    /**     * The raw type is 'bool'     */
    public transient_to_focused: boolean;    
    /**     * The raw type is 'bool'     */
    public exclusive: boolean;    
    /**     * The raw type is 'bool'     */
    public unresizable: boolean;    
    /**     * The raw type is 'bool'     */
    public borderless: boolean;    
    /**     * The raw type is 'bool'     */
    public always_on_top: boolean;    
    /**     * The raw type is 'bool'     */
    public transparent: boolean;    
    /**     * The raw type is 'bool'     */
    public unfocusable: boolean;    
    /**     * The raw type is 'bool'     */
    public popup_window: boolean;    
    /**     * The raw type is 'bool'     */
    public extend_to_title: boolean;    
    /**     * The raw type is 'bool'     */
    public mouse_passthrough: boolean;    
    /**     * The raw type is 'bool'     */
    public sharp_corners: boolean;    
    /**     * The raw type is 'bool'     */
    public exclude_from_capture: boolean;    
    /**     * The raw type is 'bool'     */
    public popup_wm_hint: boolean;    
    /**     * The raw type is 'bool'     */
    public minimize_disabled: boolean;    
    /**     * The raw type is 'bool'     */
    public maximize_disabled: boolean;    
    /**     * The raw type is 'bool'     */
    public force_native: boolean;    
    /**     * The raw type is 'Vector2i'     */
    public min_size: Vector2i;    
    /**     * The raw type is 'Vector2i'     */
    public max_size: Vector2i;    
    /**     * The raw type is 'bool'     */
    public keep_title_visible: boolean;    
    /**     * The raw type is 'Vector2i'     */
    public content_scale_size: Vector2i;    
    /**     * The raw type is 'int'     */
    public content_scale_mode: number;    
    /**     * The raw type is 'int'     */
    public content_scale_aspect: number;    
    /**     * The raw type is 'int'     */
    public content_scale_stretch: number;    
    /**     * The raw type is 'float'     */
    public content_scale_factor: number;    
    /**     * The raw type is 'bool'     */
    public auto_translate: boolean;    
    /**     * The raw type is 'String'     */
    public accessibility_name: GDString | StringName | string;    
    /**     * The raw type is 'String'     */
    public accessibility_description: GDString | StringName | string;    
    /**     * The raw type is 'Theme'     */
    public theme: Theme;    
    /**     * The raw type is 'String'     */
    public theme_type_variation: GDString | StringName | string;
    public _get_contents_minimum_size(): Vector2;
    public set_title(title: GDString | StringName | string): void;
    public get_title(): GDString;
    public set_initial_position(initialPosition: number): void;
    public get_initial_position(): number;
    public set_current_screen(index: number): void;
    public get_current_screen(): number;
    public set_position(position: Vector2i): void;
    public get_position(): Vector2i;
    public move_to_center(): void;
    public set_size(size: Vector2i): void;
    public get_size(): Vector2i;
    public reset_size(): void;
    public get_position_with_decorations(): Vector2i;
    public get_size_with_decorations(): Vector2i;
    public set_max_size(maxSize: Vector2i): void;
    public get_max_size(): Vector2i;
    public set_min_size(minSize: Vector2i): void;
    public get_min_size(): Vector2i;
    public set_mode(mode: number): void;
    public get_mode(): number;
    public set_flag(flag: number, enabled: boolean): void;
    public get_flag(flag: number): boolean;
    public is_maximize_allowed(): boolean;
    public request_attention(): void;
    public move_to_foreground(): void;
    public set_visible(visible: boolean): void;
    public is_visible(): boolean;
    public hide(): void;
    public show(): void;
    public set_transient(transient: boolean): void;
    public is_transient(): boolean;
    public set_transient_to_focused(enable: boolean): void;
    public is_transient_to_focused(): boolean;
    public set_exclusive(exclusive: boolean): void;
    public is_exclusive(): boolean;
    public set_unparent_when_invisible(unparent: boolean): void;
    public can_draw(): boolean;
    public has_focus(): boolean;
    public grab_focus(): void;
    public start_drag(): void;
    public start_resize(edge: number): void;
    public set_ime_active(active: boolean): void;
    public set_ime_position(position: Vector2i): void;
    public is_embedded(): boolean;
    public get_contents_minimum_size(): Vector2;
    public set_force_native(forceNative: boolean): void;
    public get_force_native(): boolean;
    public set_content_scale_size(size: Vector2i): void;
    public get_content_scale_size(): Vector2i;
    public set_content_scale_mode(mode: number): void;
    public get_content_scale_mode(): number;
    public set_content_scale_aspect(aspect: number): void;
    public get_content_scale_aspect(): number;
    public set_content_scale_stretch(stretch: number): void;
    public get_content_scale_stretch(): number;
    public set_keep_title_visible(titleVisible: boolean): void;
    public get_keep_title_visible(): boolean;
    public set_content_scale_factor(factor: number): void;
    public get_content_scale_factor(): number;
    public set_mouse_passthrough_polygon(polygon: PackedVector2Array): void;
    public get_mouse_passthrough_polygon(): PackedVector2Array;
    public set_wrap_controls(enable: boolean): void;
    public is_wrapping_controls(): boolean;
    public child_controls_changed(): void;
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
    public get_window_id(): number;
    public set_accessibility_name(name: GDString | StringName | string): void;
    public get_accessibility_name(): GDString;
    public set_accessibility_description(description: GDString | StringName | string): void;
    public get_accessibility_description(): GDString;
    public static get_focused_window(): Window;
    public set_layout_direction(direction: number): void;
    public get_layout_direction(): number;
    public is_layout_rtl(): boolean;
    public set_auto_translate(enable: boolean): void;
    public is_auto_translating(): boolean;
    public set_use_font_oversampling(enable: boolean): void;
    public is_using_font_oversampling(): boolean;
    public popup(rect: Rect2i = Rect2i(0, 0, 0, 0)): void;
    public popup_on_parent(parentRect: Rect2i): void;
    public popup_centered(minsize: Vector2i = Vector2i(0, 0)): void;
    public popup_centered_ratio(ratio: number = 0.8): void;
    public popup_centered_clamped(minsize: Vector2i = Vector2i(0, 0), fallbackRatio: number = 0.75): void;
    public popup_exclusive(fromNode: Node, rect: Rect2i = Rect2i(0, 0, 0, 0)): void;
    public popup_exclusive_on_parent(fromNode: Node, parentRect: Rect2i): void;
    public popup_exclusive_centered(fromNode: Node, minsize: Vector2i = Vector2i(0, 0)): void;
    public popup_exclusive_centered_ratio(fromNode: Node, ratio: number = 0.8): void;
    public popup_exclusive_centered_clamped(fromNode: Node, minsize: Vector2i = Vector2i(0, 0), fallbackRatio: number = 0.75): void;

    
    public readonly window_input: Signal<(event: InputEvent) => void>;
    public readonly files_dropped: Signal<(files: PackedStringArray) => void>;
    public readonly mouse_entered: Signal<() => void>;
    public readonly mouse_exited: Signal<() => void>;
    public readonly focus_entered: Signal<() => void>;
    public readonly focus_exited: Signal<() => void>;
    public readonly close_requested: Signal<() => void>;
    public readonly go_back_requested: Signal<() => void>;
    public readonly visibility_changed: Signal<() => void>;
    public readonly about_to_popup: Signal<() => void>;
    public readonly theme_changed: Signal<() => void>;
    public readonly dpi_changed: Signal<() => void>;
    public readonly titlebar_changed: Signal<() => void>;
    public readonly title_changed: Signal<() => void>;

    public static readonly Mode: {
        MODE_WINDOWED: 0;
        MODE_MINIMIZED: 1;
        MODE_MAXIMIZED: 2;
        MODE_FULLSCREEN: 3;
        MODE_EXCLUSIVE_FULLSCREEN: 4;
    };
    public static readonly Flags: {
        FLAG_RESIZE_DISABLED: 0;
        FLAG_BORDERLESS: 1;
        FLAG_ALWAYS_ON_TOP: 2;
        FLAG_TRANSPARENT: 3;
        FLAG_NO_FOCUS: 4;
        FLAG_POPUP: 5;
        FLAG_EXTEND_TO_TITLE: 6;
        FLAG_MOUSE_PASSTHROUGH: 7;
        FLAG_SHARP_CORNERS: 8;
        FLAG_EXCLUDE_FROM_CAPTURE: 9;
        FLAG_POPUP_WM_HINT: 10;
        FLAG_MINIMIZE_DISABLED: 11;
        FLAG_MAXIMIZE_DISABLED: 12;
        FLAG_MAX: 13;
    };
    public static readonly ContentScaleMode: {
        CONTENT_SCALE_MODE_DISABLED: 0;
        CONTENT_SCALE_MODE_CANVAS_ITEMS: 1;
        CONTENT_SCALE_MODE_VIEWPORT: 2;
    };
    public static readonly ContentScaleAspect: {
        CONTENT_SCALE_ASPECT_IGNORE: 0;
        CONTENT_SCALE_ASPECT_KEEP: 1;
        CONTENT_SCALE_ASPECT_KEEP_WIDTH: 2;
        CONTENT_SCALE_ASPECT_KEEP_HEIGHT: 3;
        CONTENT_SCALE_ASPECT_EXPAND: 4;
    };
    public static readonly ContentScaleStretch: {
        CONTENT_SCALE_STRETCH_FRACTIONAL: 0;
        CONTENT_SCALE_STRETCH_INTEGER: 1;
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
    public static readonly WindowInitialPosition: {
        WINDOW_INITIAL_POSITION_ABSOLUTE: 0;
        WINDOW_INITIAL_POSITION_CENTER_PRIMARY_SCREEN: 1;
        WINDOW_INITIAL_POSITION_CENTER_MAIN_WINDOW_SCREEN: 2;
        WINDOW_INITIAL_POSITION_CENTER_OTHER_SCREEN: 3;
        WINDOW_INITIAL_POSITION_CENTER_SCREEN_WITH_MOUSE_FOCUS: 4;
        WINDOW_INITIAL_POSITION_CENTER_SCREEN_WITH_KEYBOARD_FOCUS: 5;
    };
}

