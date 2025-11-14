
import type { BaseMaterial3D } from '@godot/classes/base_material3d';
import type { CSGPrimitive3D } from '@godot/classes/csg_primitive3d';
import type { Material } from '@godot/classes/material';
import type { Vector3 } from '@godot/builtins/vector3';


export declare class CSGBox3D extends CSGPrimitive3D {

    
    /**     * The raw type is 'Vector3'     */
    public size: Vector3;    
    /**     * The raw type is 'BaseMaterial3D,ShaderMaterial'     */
    public material: Material;
    public set_size(size: Vector3): void;
    public get_size(): Vector3;
    public set_material(material: Material): void;
    public get_material(): Material;


}

