
import type { BaseMaterial3D } from '@godot/classes/base_material3d';
import type { CSGPrimitive3D } from '@godot/classes/csg_primitive3d';
import type { Material } from '@godot/classes/material';


export declare class CSGTorus3D extends CSGPrimitive3D {

    
    /**     * The raw type is 'float'     */
    public inner_radius: number;    
    /**     * The raw type is 'float'     */
    public outer_radius: number;    
    /**     * The raw type is 'int'     */
    public sides: number;    
    /**     * The raw type is 'int'     */
    public ring_sides: number;    
    /**     * The raw type is 'bool'     */
    public smooth_faces: boolean;    
    /**     * The raw type is 'BaseMaterial3D,ShaderMaterial'     */
    public material: Material;
    public set_inner_radius(radius: number): void;
    public get_inner_radius(): number;
    public set_outer_radius(radius: number): void;
    public get_outer_radius(): number;
    public set_sides(sides: number): void;
    public get_sides(): number;
    public set_ring_sides(sides: number): void;
    public get_ring_sides(): number;
    public set_material(material: Material): void;
    public get_material(): Material;
    public set_smooth_faces(smoothFaces: boolean): void;
    public get_smooth_faces(): boolean;


}

