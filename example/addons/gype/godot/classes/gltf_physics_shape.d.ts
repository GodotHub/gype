
import type { CollisionShape3D } from '@godot/classes/collision_shape3d';
import type { ImporterMesh } from '@godot/classes/importer_mesh';
import type { Resource } from '@godot/classes/resource';
import type { Shape3D } from '@godot/classes/shape3d';


export declare class GLTFPhysicsShape extends Resource {

    
    /**     * The raw type is 'String'     */
    public shape_type: GDString | StringName | string;    
    /**     * The raw type is 'Vector3'     */
    public size: Vector3;    
    /**     * The raw type is 'float'     */
    public radius: number;    
    /**     * The raw type is 'float'     */
    public height: number;    
    /**     * The raw type is 'bool'     */
    public is_trigger: boolean;    
    /**     * The raw type is 'int'     */
    public mesh_index: number;    
    /**     * The raw type is 'ImporterMesh'     */
    public importer_mesh: ImporterMesh;
    public static from_node(shapeNode: CollisionShape3D): GLTFPhysicsShape;
    public to_node(cacheShapes: boolean = false): CollisionShape3D;
    public static from_resource(shapeResource: Shape3D): GLTFPhysicsShape;
    public to_resource(cacheShapes: boolean = false): Shape3D;
    public static from_dictionary(dictionary: Dictionary): GLTFPhysicsShape;
    public to_dictionary(): Dictionary;
    public get_shape_type(): GDString;
    public set_shape_type(shapeType: GDString | StringName | string): void;
    public get_size(): Vector3;
    public set_size(size: Vector3): void;
    public get_radius(): number;
    public set_radius(radius: number): void;
    public get_height(): number;
    public set_height(height: number): void;
    public get_is_trigger(): boolean;
    public set_is_trigger(isTrigger: boolean): void;
    public get_mesh_index(): number;
    public set_mesh_index(meshIndex: number): void;
    public get_importer_mesh(): ImporterMesh;
    public set_importer_mesh(importerMesh: ImporterMesh): void;


}

