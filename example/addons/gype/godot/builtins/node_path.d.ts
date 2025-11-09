
/**
 * Godot's built-in NodePath type.
 *
 * As a data structure, it can be represented by a plain object.
 * @example
 * let my_vector: NodePath = { x: 1, y: 0 };
 *
 * To create a new instance, use the global constructor.
 * @example
 * const my_vector = new NodePath(1, 0);
 */
export interface NodePath {

    isAbsolute(): boolean;
    getNameCount(): number;
    getName(idx: number): StringName;
    getSubnameCount(): number;
    hash(): number;
    getSubname(idx: number): StringName;
    getConcatenatedNames(): StringName;
    getConcatenatedSubnames(): StringName;
    slice(begin: number, end: number = 2147483647): NodePath;
    getAsPropertyPath(): NodePath;
    isEmpty(): boolean;
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