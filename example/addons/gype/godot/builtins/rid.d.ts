
import type { Dictionary } from '@godot/builtins/dictionary';
import type { GDArray } from '@godot/builtins/gd_array';


export declare class RID {
    constructor();
    constructor(_from: RID);


    public is_valid(): boolean;
    public get_id(): number;

    public equals(right: any): boolean;
    public not_equals(right: any): boolean;
    public op_not(): boolean;
    public equals(right: RID): boolean;
    public not_equals(right: RID): boolean;
    public less(right: RID): boolean;
    public less_equal(right: RID): boolean;
    public greater(right: RID): boolean;
    public greater_equal(right: RID): boolean;
    public in_op(right: Dictionary): boolean;
    public in_op(right: GDArray): boolean;

}