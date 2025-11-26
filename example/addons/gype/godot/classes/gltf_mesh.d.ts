
import type { GodotObject } from '@godot/classes/godot_object';
import type { ImporterMesh } from '@godot/classes/importer_mesh';
import type { Resource } from '@godot/classes/resource';


export declare class GLTFMesh extends Resource {

    
    /**     * The raw type is 'String'     */
    public original_name: GDString;    
    /**     * The raw type is 'Object'     */
    public mesh: ImporterMesh;    
    /**     * The raw type is 'PackedFloat32Array'     */
    public blend_weights: PackedFloat32Array;    
    /**     * The raw type is 'Array'     */
    public instance_materials: Array<any>;
    public get_original_name(): GDString;
    public set_original_name(originalName: GDString | StringName | string): void;
    public get_mesh(): ImporterMesh;
    public set_mesh(mesh: ImporterMesh): void;
    public get_blend_weights(): PackedFloat32Array;
    public set_blend_weights(blendWeights: PackedFloat32Array): void;
    public get_instance_materials(): Array<any>;
    public set_instance_materials(instanceMaterials: Array<any>): void;
    public get_additional_data(extensionName: GDString | StringName | string): any;
    public set_additional_data(extensionName: GDString | StringName | string, additionalData: any): void;


}

