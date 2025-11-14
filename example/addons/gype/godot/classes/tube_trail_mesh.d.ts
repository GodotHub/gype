
import type { Curve } from '@godot/classes/curve';
import type { PrimitiveMesh } from '@godot/classes/primitive_mesh';


export declare class TubeTrailMesh extends PrimitiveMesh {

    
    /**     * The raw type is 'float'     */
    public radius: number;    
    /**     * The raw type is 'int'     */
    public radial_steps: number;    
    /**     * The raw type is 'int'     */
    public sections: number;    
    /**     * The raw type is 'float'     */
    public section_length: number;    
    /**     * The raw type is 'int'     */
    public section_rings: number;    
    /**     * The raw type is 'bool'     */
    public cap_top: boolean;    
    /**     * The raw type is 'bool'     */
    public cap_bottom: boolean;    
    /**     * The raw type is 'Curve'     */
    public curve: Curve;
    public set_radius(radius: number): void;
    public get_radius(): number;
    public set_radial_steps(radialSteps: number): void;
    public get_radial_steps(): number;
    public set_sections(sections: number): void;
    public get_sections(): number;
    public set_section_length(sectionLength: number): void;
    public get_section_length(): number;
    public set_section_rings(sectionRings: number): void;
    public get_section_rings(): number;
    public set_cap_top(catop: boolean): void;
    public is_cap_top(): boolean;
    public set_cap_bottom(cabottom: boolean): void;
    public is_cap_bottom(): boolean;
    public set_curve(curve: Curve): void;
    public get_curve(): Curve;


}

