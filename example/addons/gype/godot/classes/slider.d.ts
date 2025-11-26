
import type { Range } from '@godot/classes/range';


export declare class Slider extends Range {

    
    /**     * The raw type is 'bool'     */
    public editable: boolean;    
    /**     * The raw type is 'bool'     */
    public scrollable: boolean;    
    /**     * The raw type is 'int'     */
    public tick_count: number;    
    /**     * The raw type is 'bool'     */
    public ticks_on_borders: boolean;    
    /**     * The raw type is 'int'     */
    public ticks_position: number;
    public set_ticks(count: number): void;
    public get_ticks(): number;
    public get_ticks_on_borders(): boolean;
    public set_ticks_on_borders(ticksOnBorder: boolean): void;
    public get_ticks_position(): number;
    public set_ticks_position(ticksOnBorder: number): void;
    public set_editable(editable: boolean): void;
    public is_editable(): boolean;
    public set_scrollable(scrollable: boolean): void;
    public is_scrollable(): boolean;

    
    public readonly drag_started: Signal;
    public readonly drag_ended: Signal;

    public static readonly TickPosition: {
        TICK_POSITION_BOTTOM_RIGHT: 0;
        TICK_POSITION_TOP_LEFT: 1;
        TICK_POSITION_BOTH: 2;
        TICK_POSITION_CENTER: 3;
    };
}

