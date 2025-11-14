
import type { Curve } from '@godot/classes/curve';
import type { PrimitiveMesh } from '@godot/classes/primitive_mesh';


export declare class RibbonTrailMesh extends PrimitiveMesh {

    
    /**     * The raw type is 'int'     */
    public shape: number;    
    /**     * The raw type is 'float'     */
    public size: number;    
    /**     * The raw type is 'int'     */
    public sections: number;    
    /**     * The raw type is 'float'     */
    public section_length: number;    
    /**     * The raw type is 'int'     */
    public section_segments: number;    
    /**     * The raw type is 'Curve'     */
    public curve: Curve;
    public set_size(size: number): void;
    public get_size(): number;
    public set_sections(sections: number): void;
    public get_sections(): number;
    public set_section_length(sectionLength: number): void;
    public get_section_length(): number;
    public set_section_segments(sectionSegments: number): void;
    public get_section_segments(): number;
    public set_curve(curve: Curve): void;
    public get_curve(): Curve;
    public set_shape(shape: number): void;
    public get_shape(): number;


    public static readonly Shape: {
        SHAPE_FLAT: 0;
        SHAPE_CROSS: 1;
    };
}

