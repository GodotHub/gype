
import type { Color } from '@godot/builtins/color';
import type { PackedColorArray } from '@godot/builtins/packed_color_array';
import type { Signal } from '@godot/builtins/signal';
import type { VBoxContainer } from '@godot/classes/v_box_container';


export declare class ColorPicker extends VBoxContainer {

    
    /**     * The raw type is 'Color'     */
    public color: Color;    
    /**     * The raw type is 'bool'     */
    public edit_alpha: boolean;    
    /**     * The raw type is 'bool'     */
    public edit_intensity: boolean;    
    /**     * The raw type is 'int'     */
    public color_mode: number;    
    /**     * The raw type is 'bool'     */
    public deferred_mode: boolean;    
    /**     * The raw type is 'int'     */
    public picker_shape: number;    
    /**     * The raw type is 'bool'     */
    public can_add_swatches: boolean;    
    /**     * The raw type is 'bool'     */
    public sampler_visible: boolean;    
    /**     * The raw type is 'bool'     */
    public color_modes_visible: boolean;    
    /**     * The raw type is 'bool'     */
    public sliders_visible: boolean;    
    /**     * The raw type is 'bool'     */
    public hex_visible: boolean;    
    /**     * The raw type is 'bool'     */
    public presets_visible: boolean;
    public set_pick_color(color: Color): void;
    public get_pick_color(): Color;
    public set_deferred_mode(mode: boolean): void;
    public is_deferred_mode(): boolean;
    public set_color_mode(colorMode: number): void;
    public get_color_mode(): number;
    public set_edit_alpha(show: boolean): void;
    public is_editing_alpha(): boolean;
    public set_edit_intensity(show: boolean): void;
    public is_editing_intensity(): boolean;
    public set_can_add_swatches(enabled: boolean): void;
    public are_swatches_enabled(): boolean;
    public set_presets_visible(visible: boolean): void;
    public are_presets_visible(): boolean;
    public set_modes_visible(visible: boolean): void;
    public are_modes_visible(): boolean;
    public set_sampler_visible(visible: boolean): void;
    public is_sampler_visible(): boolean;
    public set_sliders_visible(visible: boolean): void;
    public are_sliders_visible(): boolean;
    public set_hex_visible(visible: boolean): void;
    public is_hex_visible(): boolean;
    public add_preset(color: Color): void;
    public erase_preset(color: Color): void;
    public get_presets(): PackedColorArray;
    public add_recent_preset(color: Color): void;
    public erase_recent_preset(color: Color): void;
    public get_recent_presets(): PackedColorArray;
    public set_picker_shape(shape: number): void;
    public get_picker_shape(): number;

    
    public readonly color_changed: Signal<(color: Color) => void>;
    public readonly preset_added: Signal<(color: Color) => void>;
    public readonly preset_removed: Signal<(color: Color) => void>;

    public static readonly ColorModeType: {
        MODE_RGB: 0;
        MODE_HSV: 1;
        MODE_RAW: 2;
        MODE_LINEAR: 2;
        MODE_OKHSL: 3;
    };
    public static readonly PickerShapeType: {
        SHAPE_HSV_RECTANGLE: 0;
        SHAPE_HSV_WHEEL: 1;
        SHAPE_VHS_CIRCLE: 2;
        SHAPE_OKHSL_CIRCLE: 3;
        SHAPE_NONE: 4;
        SHAPE_OK_HS_RECTANGLE: 5;
        SHAPE_OK_HL_RECTANGLE: 6;
    };
}

