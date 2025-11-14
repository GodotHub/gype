
import type { BaseMaterial3D } from '@godot/classes/base_material3d';
import type { CSGPrimitive3D } from '@godot/classes/csg_primitive3d';
import type { Material } from '@godot/classes/material';


export declare class CSGCylinder3D extends CSGPrimitive3D {

    
    /**     * The raw type is 'float'     */
    public radius: number;    
    /**     * The raw type is 'float'     */
    public height: number;    
    /**     * The raw type is 'int'     */
    public sides: number;    
    /**     * The raw type is 'bool'     */
    public cone: boolean;    
    /**     * The raw type is 'bool'     */
    public smooth_faces: boolean;    
    /**     * The raw type is 'BaseMaterial3D,ShaderMaterial'     */
    public material: Material;
    public set_radius(radius: number): void;
    public get_radius(): number;
    public set_height(height: number): void;
    public get_height(): number;
    public set_sides(sides: number): void;
    public get_sides(): number;
    public set_cone(cone: boolean): void;
    public is_cone(): boolean;
    public set_material(material: Material): void;
    public get_material(): Material;
    public set_smooth_faces(smoothFaces: boolean): void;
    public get_smooth_faces(): boolean;


}

