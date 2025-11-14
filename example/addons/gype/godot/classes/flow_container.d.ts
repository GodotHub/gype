
import type { Container } from '@godot/classes/container';


export declare class FlowContainer extends Container {

    
    /**     * The raw type is 'int'     */
    public alignment: number;    
    /**     * The raw type is 'int'     */
    public last_wrap_alignment: number;    
    /**     * The raw type is 'bool'     */
    public vertical: boolean;    
    /**     * The raw type is 'bool'     */
    public reverse_fill: boolean;
    public get_line_count(): number;
    public set_alignment(alignment: number): void;
    public get_alignment(): number;
    public set_last_wrap_alignment(lastWraalignment: number): void;
    public get_last_wrap_alignment(): number;
    public set_vertical(vertical: boolean): void;
    public is_vertical(): boolean;
    public set_reverse_fill(reverseFill: boolean): void;
    public is_reverse_fill(): boolean;


    public static readonly AlignmentMode: {
        ALIGNMENT_BEGIN: 0;
        ALIGNMENT_CENTER: 1;
        ALIGNMENT_END: 2;
    };
    public static readonly LastWrapAlignmentMode: {
        LAST_WRAP_ALIGNMENT_INHERIT: 0;
        LAST_WRAP_ALIGNMENT_BEGIN: 1;
        LAST_WRAP_ALIGNMENT_CENTER: 2;
        LAST_WRAP_ALIGNMENT_END: 3;
    };
}

