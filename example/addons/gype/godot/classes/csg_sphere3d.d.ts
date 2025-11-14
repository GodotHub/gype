
import type { BaseMaterial3D } from '@godot/classes/base_material3d';
import type { CSGPrimitive3D } from '@godot/classes/csg_primitive3d';
import type { Material } from '@godot/classes/material';


export declare class CSGSphere3D extends CSGPrimitive3D {

    
    /**     * The raw type is 'float'     */
    public radius: number;    
    /**     * The raw type is 'int'     */
    public radial_segments: number;    
    /**     * The raw type is 'int'     */
    public rings: number;    
    /**     * The raw type is 'bool'     */
    public smooth_faces: boolean;    
    /**     * The raw type is 'BaseMaterial3D,ShaderMaterial'     */
    public material: Material;
    public set_radius(radius: number): void;
    public get_radius(): number;
    public set_radial_segments(radialSegments: number): void;
    public get_radial_segments(): number;
    public set_rings(rings: number): void;
    public get_rings(): number;
    public set_smooth_faces(smoothFaces: boolean): void;
    public get_smooth_faces(): boolean;
    public set_material(material: Material): void;
    public get_material(): Material;


}

