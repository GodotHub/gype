
import type { RigidBody3D } from '@godot/classes/rigid_body3d';


export declare class VehicleBody3D extends RigidBody3D {

    
    /**     * The raw type is 'float'     */
    public engine_force: number;    
    /**     * The raw type is 'float'     */
    public brake: number;    
    /**     * The raw type is 'float'     */
    public steering: number;
    public set_engine_force(engineForce: number): void;
    public get_engine_force(): number;
    public set_brake(brake: number): void;
    public get_brake(): number;
    public set_steering(steering: number): void;
    public get_steering(): number;


}

