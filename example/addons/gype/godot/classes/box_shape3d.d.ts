
import type { Shape3D } from '@godot/classes/shape3d';
import type { Vector3 } from '@godot/builtins/vector3';


export declare class BoxShape3D extends Shape3D {

    
    /**     * The raw type is 'Vector3'     */
    public size: Vector3;
    public set_size(size: Vector3): void;
    public get_size(): Vector3;


}

