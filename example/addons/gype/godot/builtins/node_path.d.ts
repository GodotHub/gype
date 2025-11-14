declare global {
    export class NodePath {
        constructor(): NodePath;
        constructor(_from: NodePath | GDString | string): NodePath;
        constructor(_from: GDString | StringName | string): NodePath;
    

        is_absolute(): boolean;
        get_name_count(): number;
        get_name(idx: number): StringName;
        get_subname_count(): number;
        hash(): number;
        get_subname(idx: number): StringName;
        get_concatenated_names(): StringName;
        get_concatenated_subnames(): StringName;
        slice(begin: number, end: number = 2147483647): NodePath;
        get_as_property_path(): NodePath;
        is_empty(): boolean;
        
        /*
        // equals(any): boolean
        // not_equals(any): boolean
        // op_not(any): boolean
        // equals(NodePath): boolean
        // not_equals(NodePath): boolean
        // in_op(Dictionary): boolean
        // in_op(GDArray): boolean
        */
    }
}

export {};