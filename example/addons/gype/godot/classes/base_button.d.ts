
import type { ButtonGroup } from '@godot/classes/button_group';
import type { Control } from '@godot/classes/control';
import type { Shortcut } from '@godot/classes/shortcut';


export declare class BaseButton extends Control {

    
    /**     * The raw type is 'bool'     */
    public disabled: boolean;    
    /**     * The raw type is 'bool'     */
    public toggle_mode: boolean;    
    /**     * The raw type is 'bool'     */
    public button_pressed: boolean;    
    /**     * The raw type is 'int'     */
    public action_mode: number;    
    /**     * The raw type is 'int'     */
    public button_mask: number;    
    /**     * The raw type is 'bool'     */
    public keep_pressed_outside: boolean;    
    /**     * The raw type is 'ButtonGroup'     */
    public button_group: ButtonGroup;    
    /**     * The raw type is 'Shortcut'     */
    public shortcut: Shortcut;    
    /**     * The raw type is 'bool'     */
    public shortcut_feedback: boolean;    
    /**     * The raw type is 'bool'     */
    public shortcut_in_tooltip: boolean;
    public _pressed(): void;
    public _toggled(toggledOn: boolean): void;
    public set_pressed(pressed: boolean): void;
    public is_pressed(): boolean;
    public set_pressed_no_signal(pressed: boolean): void;
    public is_hovered(): boolean;
    public set_toggle_mode(enabled: boolean): void;
    public is_toggle_mode(): boolean;
    public set_shortcut_in_tooltip(enabled: boolean): void;
    public is_shortcut_in_tooltip_enabled(): boolean;
    public set_disabled(disabled: boolean): void;
    public is_disabled(): boolean;
    public set_action_mode(mode: number): void;
    public get_action_mode(): number;
    public set_button_mask(mask: number): void;
    public get_button_mask(): number;
    public get_draw_mode(): number;
    public set_keep_pressed_outside(enabled: boolean): void;
    public is_keep_pressed_outside(): boolean;
    public set_shortcut_feedback(enabled: boolean): void;
    public is_shortcut_feedback(): boolean;
    public set_shortcut(shortcut: Shortcut): void;
    public get_shortcut(): Shortcut;
    public set_button_group(buttonGroup: ButtonGroup): void;
    public get_button_group(): ButtonGroup;

    
    public readonly pressed: Signal;
    public readonly button_up: Signal;
    public readonly button_down: Signal;
    public readonly toggled: Signal;

    public static readonly DrawMode: {
        DRAW_NORMAL: 0;
        DRAW_PRESSED: 1;
        DRAW_HOVER: 2;
        DRAW_DISABLED: 3;
        DRAW_HOVER_PRESSED: 4;
    };
    public static readonly ActionMode: {
        ACTION_MODE_BUTTON_PRESS: 0;
        ACTION_MODE_BUTTON_RELEASE: 1;
    };
}

