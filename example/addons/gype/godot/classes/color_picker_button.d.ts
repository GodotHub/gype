
import type { Button } from '@godot/classes/button';
import type { Color } from '@godot/builtins/color';
import type { ColorPicker } from '@godot/classes/color_picker';
import type { PopupPanel } from '@godot/classes/popup_panel';
import type { Signal } from '@godot/builtins/signal';


export declare class ColorPickerButton extends Button {

    
    /**     * The raw type is 'Color'     */
    public color: Color;    
    /**     * The raw type is 'bool'     */
    public edit_alpha: boolean;    
    /**     * The raw type is 'bool'     */
    public edit_intensity: boolean;
    public set_pick_color(color: Color): void;
    public get_pick_color(): Color;
    public get_picker(): ColorPicker;
    public get_popup(): PopupPanel;
    public set_edit_alpha(show: boolean): void;
    public is_editing_alpha(): boolean;
    public set_edit_intensity(show: boolean): void;
    public is_editing_intensity(): boolean;

    
    public readonly color_changed: Signal<(color: Color) => void>;
    public readonly popup_closed: Signal<() => void>;
    public readonly picker_created: Signal<() => void>;

}

