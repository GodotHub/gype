declare global {
    export interface RID {

        is_valid(): boolean;
        get_id(): number;
    }

    /**
    * A global constructor and namespace for the RID type.
    *
    * Use `new RID(...)` to create a new instance.
    * Access static members like `RID.ZERO`.
    */
    export declare const RID: {
        new(): RID;
        new(_from: RID): RID;


        /*
        // equals(any): boolean
        // not_equals(any): boolean
        // op_not(any): boolean
        // equals(RID): boolean
        // not_equals(RID): boolean
        // less(RID): boolean
        // less_equal(RID): boolean
        // greater(RID): boolean
        // greater_equal(RID): boolean
        // in_op(Dictionary): boolean
        // in_op(GDArray): boolean
        */
    };
}

export {};