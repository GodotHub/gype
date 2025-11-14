
import type { BaseMaterial3D } from '@godot/classes/base_material3d';
import type { CSGPrimitive3D } from '@godot/classes/csg_primitive3d';
import type { Material } from '@godot/classes/material';
import type { Mesh } from '@godot/classes/mesh';


export declare class CSGMesh3D extends CSGPrimitive3D {

    
    /**     * The raw type is 'Mesh,-PlaneMesh,-PointMesh,-QuadMesh,-RibbonTrailMesh'     */
    public mesh: Mesh;    
    /**     * The raw type is 'BaseMaterial3D,ShaderMaterial'     */
    public material: Material;
    public set_mesh(mesh: Mesh): void;
    public get_mesh(): Mesh;
    public set_material(material: Material): void;
    public get_material(): Material;


}

