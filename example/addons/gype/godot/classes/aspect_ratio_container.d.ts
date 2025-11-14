
import type { Container } from '@godot/classes/container';


export declare class AspectRatioContainer extends Container {

    
    /**     * The raw type is 'float'     */
    public ratio: number;    
    /**     * The raw type is 'int'     */
    public stretch_mode: number;    
    /**     * The raw type is 'int'     */
    public alignment_horizontal: number;    
    /**     * The raw type is 'int'     */
    public alignment_vertical: number;
    public set_ratio(ratio: number): void;
    public get_ratio(): number;
    public set_stretch_mode(stretchMode: number): void;
    public get_stretch_mode(): number;
    public set_alignment_horizontal(alignmentHorizontal: number): void;
    public get_alignment_horizontal(): number;
    public set_alignment_vertical(alignmentVertical: number): void;
    public get_alignment_vertical(): number;


    public static readonly StretchMode: {
        STRETCH_WIDTH_CONTROLS_HEIGHT: 0;
        STRETCH_HEIGHT_CONTROLS_WIDTH: 1;
        STRETCH_FIT: 2;
        STRETCH_COVER: 3;
    };
    public static readonly AlignmentMode: {
        ALIGNMENT_BEGIN: 0;
        ALIGNMENT_CENTER: 1;
        ALIGNMENT_END: 2;
    };
}

