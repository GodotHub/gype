
import type { VisualShaderNode } from '@godot/classes/visual_shader_node';


export declare class VisualShaderNodeColorOp extends VisualShaderNode {

    
    /**     * The raw type is 'int'     */
    public operator: number;
    public set_operator(op: number): void;
    public get_operator(): number;


    public static readonly Operator: {
        OP_SCREEN: 0;
        OP_DIFFERENCE: 1;
        OP_DARKEN: 2;
        OP_LIGHTEN: 3;
        OP_OVERLAY: 4;
        OP_DODGE: 5;
        OP_BURN: 6;
        OP_SOFT_LIGHT: 7;
        OP_HARD_LIGHT: 8;
        OP_MAX: 9;
    };
}

