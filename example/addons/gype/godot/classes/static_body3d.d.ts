
import type { PhysicsBody3D } from '@godot/classes/physics_body3d';
import type { PhysicsMaterial } from '@godot/classes/physics_material';
import type { Vector3 } from '@godot/builtins/vector3';


export declare class StaticBody3D extends PhysicsBody3D {

    
    /**     * The raw type is 'PhysicsMaterial'     */
    public physics_material_override: PhysicsMaterial;    
    /**     * The raw type is 'Vector3'     */
    public constant_linear_velocity: Vector3;    
    /**     * The raw type is 'Vector3'     */
    public constant_angular_velocity: Vector3;
    public set_constant_linear_velocity(vel: Vector3): void;
    public set_constant_angular_velocity(vel: Vector3): void;
    public get_constant_linear_velocity(): Vector3;
    public get_constant_angular_velocity(): Vector3;
    public set_physics_material_override(physicsMaterialOverride: PhysicsMaterial): void;
    public get_physics_material_override(): PhysicsMaterial;


}

