
import type { Control } from '@godot/classes/control';
import type { Node } from '@godot/classes/node';
import type { Signal } from '@godot/builtins/signal';


export declare class Range extends Control {

    
    /**     * The raw type is 'float'     */
    public min_value: number;    
    /**     * The raw type is 'float'     */
    public max_value: number;    
    /**     * The raw type is 'float'     */
    public step: number;    
    /**     * The raw type is 'float'     */
    public page: number;    
    /**     * The raw type is 'float'     */
    public value: number;    
    /**     * The raw type is 'float'     */
    public ratio: number;    
    /**     * The raw type is 'bool'     */
    public exp_edit: boolean;    
    /**     * The raw type is 'bool'     */
    public rounded: boolean;    
    /**     * The raw type is 'bool'     */
    public allow_greater: boolean;    
    /**     * The raw type is 'bool'     */
    public allow_lesser: boolean;
    public _value_changed(newValue: number): void;
    public get_value(): number;
    public get_min(): number;
    public get_max(): number;
    public get_step(): number;
    public get_page(): number;
    public get_as_ratio(): number;
    public set_value(value: number): void;
    public set_value_no_signal(value: number): void;
    public set_min(minimum: number): void;
    public set_max(maximum: number): void;
    public set_step(step: number): void;
    public set_page(pagesize: number): void;
    public set_as_ratio(value: number): void;
    public set_use_rounded_values(enabled: boolean): void;
    public is_using_rounded_values(): boolean;
    public set_exp_ratio(enabled: boolean): void;
    public is_ratio_exp(): boolean;
    public set_allow_greater(allow: boolean): void;
    public is_greater_allowed(): boolean;
    public set_allow_lesser(allow: boolean): void;
    public is_lesser_allowed(): boolean;
    public share(_with: Node): void;
    public unshare(): void;

    
    public readonly value_changed: Signal<(value: number) => void>;
    public readonly changed: Signal<() => void>;

}

