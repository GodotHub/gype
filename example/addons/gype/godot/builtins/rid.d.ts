declare global {
    export class RID {
        constructor(): RID;
        constructor(_from: RID): RID;
    

        is_valid(): boolean;
        get_id(): number;
        
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
    }
}

export {};