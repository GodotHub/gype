declare global {
    export interface NodePath {

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
    }

    /**
    * A global constructor and namespace for the NodePath type.
    *
    * Use `new NodePath(...)` to create a new instance.
    * Access static members like `NodePath.ZERO`.
    */
    export declare const NodePath: {
        new(): NodePath;
        new(_from: NodePath | GDString | string): NodePath;
        new(_from: GDString | StringName | string): NodePath;


        /*
        // equals(any): boolean
        // not_equals(any): boolean
        // op_not(any): boolean
        // equals(NodePath): boolean
        // not_equals(NodePath): boolean
        // in_op(Dictionary): boolean
        // in_op(GDArray): boolean
        */
    };
}

export {};