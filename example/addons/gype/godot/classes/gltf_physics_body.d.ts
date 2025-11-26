
import type { CollisionObject3D } from '@godot/classes/collision_object3d';
import type { Resource } from '@godot/classes/resource';


export declare class GLTFPhysicsBody extends Resource {

    
    /**     * The raw type is 'String'     */
    public body_type: GDString;    
    /**     * The raw type is 'float'     */
    public mass: number;    
    /**     * The raw type is 'Vector3'     */
    public linear_velocity: Vector3;    
    /**     * The raw type is 'Vector3'     */
    public angular_velocity: Vector3;    
    /**     * The raw type is 'Vector3'     */
    public center_of_mass: Vector3;    
    /**     * The raw type is 'Vector3'     */
    public inertia_diagonal: Vector3;    
    /**     * The raw type is 'Quaternion'     */
    public inertia_orientation: Quaternion;    
    /**     * The raw type is 'Basis'     */
    public inertia_tensor: Basis;
    public static from_node(bodyNode: CollisionObject3D): GLTFPhysicsBody;
    public to_node(): CollisionObject3D;
    public static from_dictionary(dictionary: Dictionary): GLTFPhysicsBody;
    public to_dictionary(): Dictionary;
    public get_body_type(): GDString;
    public set_body_type(bodyType: GDString | StringName | string): void;
    public get_mass(): number;
    public set_mass(mass: number): void;
    public get_linear_velocity(): Vector3;
    public set_linear_velocity(linearVelocity: Vector3): void;
    public get_angular_velocity(): Vector3;
    public set_angular_velocity(angularVelocity: Vector3): void;
    public get_center_of_mass(): Vector3;
    public set_center_of_mass(centerOfMass: Vector3): void;
    public get_inertia_diagonal(): Vector3;
    public set_inertia_diagonal(inertiaDiagonal: Vector3): void;
    public get_inertia_orientation(): Quaternion;
    public set_inertia_orientation(inertiaOrientation: Quaternion): void;
    public get_inertia_tensor(): Basis;
    public set_inertia_tensor(inertiaTensor: Basis): void;


}

