
import type { Container } from '@godot/classes/container';
import type { Control } from '@godot/classes/control';
import type { HScrollBar } from '@godot/classes/h_scroll_bar';
import type { VScrollBar } from '@godot/classes/v_scroll_bar';


export declare class ScrollContainer extends Container {

    
    /**     * The raw type is 'bool'     */
    public follow_focus: boolean;    
    /**     * The raw type is 'bool'     */
    public draw_focus_border: boolean;    
    /**     * The raw type is 'int'     */
    public scroll_horizontal: number;    
    /**     * The raw type is 'int'     */
    public scroll_vertical: number;    
    /**     * The raw type is 'float'     */
    public scroll_horizontal_custom_step: number;    
    /**     * The raw type is 'float'     */
    public scroll_vertical_custom_step: number;    
    /**     * The raw type is 'int'     */
    public horizontal_scroll_mode: number;    
    /**     * The raw type is 'int'     */
    public vertical_scroll_mode: number;    
    /**     * The raw type is 'int'     */
    public scroll_deadzone: number;
    public set_h_scroll(value: number): void;
    public get_h_scroll(): number;
    public set_v_scroll(value: number): void;
    public get_v_scroll(): number;
    public set_horizontal_custom_step(value: number): void;
    public get_horizontal_custom_step(): number;
    public set_vertical_custom_step(value: number): void;
    public get_vertical_custom_step(): number;
    public set_horizontal_scroll_mode(enable: number): void;
    public get_horizontal_scroll_mode(): number;
    public set_vertical_scroll_mode(enable: number): void;
    public get_vertical_scroll_mode(): number;
    public set_deadzone(deadzone: number): void;
    public get_deadzone(): number;
    public set_follow_focus(enabled: boolean): void;
    public is_following_focus(): boolean;
    public get_h_scroll_bar(): HScrollBar;
    public get_v_scroll_bar(): VScrollBar;
    public ensure_control_visible(control: Control): void;
    public set_draw_focus_border(draw: boolean): void;
    public get_draw_focus_border(): boolean;

    
    public readonly scroll_started: Signal<() => void>;
    public readonly scroll_ended: Signal<() => void>;

    public static readonly ScrollMode: {
        SCROLL_MODE_DISABLED: 0;
        SCROLL_MODE_AUTO: 1;
        SCROLL_MODE_SHOW_ALWAYS: 2;
        SCROLL_MODE_SHOW_NEVER: 3;
        SCROLL_MODE_RESERVE: 4;
    };
}

