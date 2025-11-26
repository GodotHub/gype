
import type { PhysicsBody2D } from '@godot/classes/physics_body2d';
import type { PhysicsMaterial } from '@godot/classes/physics_material';


export declare class StaticBody2D extends PhysicsBody2D {

    
    /**     * The raw type is 'PhysicsMaterial'     */
    public physics_material_override: PhysicsMaterial;    
    /**     * The raw type is 'Vector2'     */
    public constant_linear_velocity: Vector2;    
    /**     * The raw type is 'float'     */
    public constant_angular_velocity: number;
    public set_constant_linear_velocity(vel: Vector2): void;
    public set_constant_angular_velocity(vel: number): void;
    public get_constant_linear_velocity(): Vector2;
    public get_constant_angular_velocity(): number;
    public set_physics_material_override(physicsMaterialOverride: PhysicsMaterial): void;
    public get_physics_material_override(): PhysicsMaterial;


}

