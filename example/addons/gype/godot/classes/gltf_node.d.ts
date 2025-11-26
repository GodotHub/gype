
import type { GLTFState } from '@godot/classes/gltf_state';
import type { Resource } from '@godot/classes/resource';


export declare class GLTFNode extends Resource {

    
    /**     * The raw type is 'String'     */
    public original_name: GDString;    
    /**     * The raw type is 'int'     */
    public parent: number;    
    /**     * The raw type is 'int'     */
    public height: number;    
    /**     * The raw type is 'Transform3D'     */
    public xform: Transform3D;    
    /**     * The raw type is 'int'     */
    public mesh: number;    
    /**     * The raw type is 'int'     */
    public camera: number;    
    /**     * The raw type is 'int'     */
    public skin: number;    
    /**     * The raw type is 'int'     */
    public skeleton: number;    
    /**     * The raw type is 'Vector3'     */
    public position: Vector3;    
    /**     * The raw type is 'Quaternion'     */
    public rotation: Quaternion;    
    /**     * The raw type is 'Vector3'     */
    public scale: Vector3;    
    /**     * The raw type is 'PackedInt32Array'     */
    public children: PackedInt32Array;    
    /**     * The raw type is 'int'     */
    public light: number;    
    /**     * The raw type is 'bool'     */
    public visible: boolean;
    public get_original_name(): GDString;
    public set_original_name(originalName: GDString | StringName | string): void;
    public get_parent(): number;
    public set_parent(parent: number): void;
    public get_height(): number;
    public set_height(height: number): void;
    public get_xform(): Transform3D;
    public set_xform(xform: Transform3D): void;
    public get_mesh(): number;
    public set_mesh(mesh: number): void;
    public get_camera(): number;
    public set_camera(camera: number): void;
    public get_skin(): number;
    public set_skin(skin: number): void;
    public get_skeleton(): number;
    public set_skeleton(skeleton: number): void;
    public get_position(): Vector3;
    public set_position(position: Vector3): void;
    public get_rotation(): Quaternion;
    public set_rotation(rotation: Quaternion): void;
    public get_scale(): Vector3;
    public set_scale(scale: Vector3): void;
    public get_children(): PackedInt32Array;
    public set_children(children: PackedInt32Array): void;
    public append_child_index(childIndex: number): void;
    public get_light(): number;
    public set_light(light: number): void;
    public get_visible(): boolean;
    public set_visible(visible: boolean): void;
    public get_additional_data(extensionName: GDString | StringName | string): any;
    public set_additional_data(extensionName: GDString | StringName | string, additionalData: any): void;
    public get_scene_node_path(gltfState: GLTFState, handleSkeletons: boolean = true): NodePath;


}

