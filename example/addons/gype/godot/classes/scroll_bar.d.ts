
import type { Range } from '@godot/classes/range';


export declare class ScrollBar extends Range {

    
    /**     * The raw type is 'float'     */
    public custom_step: number;
    public set_custom_step(step: number): void;
    public get_custom_step(): number;

    
    public readonly scrolling: Signal<() => void>;

}

