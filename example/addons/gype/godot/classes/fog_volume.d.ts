
import type { FogMaterial } from '@godot/classes/fog_material';
import type { Material } from '@godot/classes/material';
import type { Vector3 } from '@godot/builtins/vector3';
import type { VisualInstance3D } from '@godot/classes/visual_instance3d';


export declare class FogVolume extends VisualInstance3D {

    
    /**     * The raw type is 'Vector3'     */
    public size: Vector3;    
    /**     * The raw type is 'int'     */
    public shape: number;    
    /**     * The raw type is 'FogMaterial,ShaderMaterial'     */
    public material: Material;
    public set_size(size: Vector3): void;
    public get_size(): Vector3;
    public set_shape(shape: number): void;
    public get_shape(): number;
    public set_material(material: Material): void;
    public get_material(): Material;


}

