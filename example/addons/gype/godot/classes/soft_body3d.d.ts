
import type { MeshInstance3D } from '@godot/classes/mesh_instance3d';
import type { Node } from '@godot/classes/node';


export declare class SoftBody3D extends MeshInstance3D {

    
    /**     * The raw type is 'int'     */
    public collision_layer: number;    
    /**     * The raw type is 'int'     */
    public collision_mask: number;    
    /**     * The raw type is 'NodePath'     */
    public parent_collision_ignore: NodePath;    
    /**     * The raw type is 'int'     */
    public simulation_precision: number;    
    /**     * The raw type is 'float'     */
    public total_mass: number;    
    /**     * The raw type is 'float'     */
    public linear_stiffness: number;    
    /**     * The raw type is 'float'     */
    public shrinking_factor: number;    
    /**     * The raw type is 'float'     */
    public pressure_coefficient: number;    
    /**     * The raw type is 'float'     */
    public damping_coefficient: number;    
    /**     * The raw type is 'float'     */
    public drag_coefficient: number;    
    /**     * The raw type is 'bool'     */
    public ray_pickable: boolean;    
    /**     * The raw type is 'int'     */
    public disable_mode: number;
    public get_physics_rid(): RID;
    public set_collision_mask(collisionMask: number): void;
    public get_collision_mask(): number;
    public set_collision_layer(collisionLayer: number): void;
    public get_collision_layer(): number;
    public set_collision_mask_value(layerNumber: number, value: boolean): void;
    public get_collision_mask_value(layerNumber: number): boolean;
    public set_collision_layer_value(layerNumber: number, value: boolean): void;
    public get_collision_layer_value(layerNumber: number): boolean;
    public set_parent_collision_ignore(parentCollisionIgnore: NodePath | GDString | string): void;
    public get_parent_collision_ignore(): NodePath;
    public set_disable_mode(mode: number): void;
    public get_disable_mode(): number;
    public get_collision_exceptions(): Array<any>;
    public add_collision_exception_with(body: Node): void;
    public remove_collision_exception_with(body: Node): void;
    public set_simulation_precision(simulationPrecision: number): void;
    public get_simulation_precision(): number;
    public set_total_mass(mass: number): void;
    public get_total_mass(): number;
    public set_linear_stiffness(linearStiffness: number): void;
    public get_linear_stiffness(): number;
    public set_shrinking_factor(shrinkingFactor: number): void;
    public get_shrinking_factor(): number;
    public set_pressure_coefficient(pressureCoefficient: number): void;
    public get_pressure_coefficient(): number;
    public set_damping_coefficient(dampingCoefficient: number): void;
    public get_damping_coefficient(): number;
    public set_drag_coefficient(dragCoefficient: number): void;
    public get_drag_coefficient(): number;
    public get_point_transform(pointIndex: number): Vector3;
    public apply_impulse(pointIndex: number, impulse: Vector3): void;
    public apply_force(pointIndex: number, force: Vector3): void;
    public apply_central_impulse(impulse: Vector3): void;
    public apply_central_force(force: Vector3): void;
    public set_point_pinned(pointIndex: number, pinned: boolean, attachmentPath: NodePath | GDString | string = NodePath(""), insertAt: number = -1): void;
    public is_point_pinned(pointIndex: number): boolean;
    public set_ray_pickable(rayPickable: boolean): void;
    public is_ray_pickable(): boolean;


    public static readonly DisableMode: {
        DISABLE_MODE_REMOVE: 0;
        DISABLE_MODE_KEEP_ACTIVE: 1;
    };
}

