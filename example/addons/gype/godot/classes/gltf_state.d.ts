
import type { AnimationPlayer } from '@godot/classes/animation_player';
import type { Dictionary } from '@godot/builtins/dictionary';
import type { GDArray } from '@godot/builtins/gd_array';
import type { GDString } from '@godot/builtins/gd_string';
import type { GLTFNode } from '@godot/classes/gltf_node';
import type { Node } from '@godot/classes/node';
import type { PackedByteArray } from '@godot/builtins/packed_byte_array';
import type { PackedInt32Array } from '@godot/builtins/packed_int32_array';
import type { Resource } from '@godot/classes/resource';
import type { StringName } from '@godot/builtins/string_name';


export declare class GLTFState extends Resource {

    
    /**     * The raw type is 'Dictionary'     */
    public json: Dictionary;    
    /**     * The raw type is 'int'     */
    public major_version: number;    
    /**     * The raw type is 'int'     */
    public minor_version: number;    
    /**     * The raw type is 'String'     */
    public copyright: GDString;    
    /**     * The raw type is 'PackedByteArray'     */
    public glb_data: PackedByteArray;    
    /**     * The raw type is 'bool'     */
    public use_named_skin_binds: boolean;    
    /**     * The raw type is 'Array'     */
    public nodes: Array<any>;    
    /**     * The raw type is 'Array'     */
    public buffers: Array<any>;    
    /**     * The raw type is 'Array'     */
    public buffer_views: Array<any>;    
    /**     * The raw type is 'Array'     */
    public accessors: Array<any>;    
    /**     * The raw type is 'Array'     */
    public meshes: Array<any>;    
    /**     * The raw type is 'Array'     */
    public materials: Array<any>;    
    /**     * The raw type is 'String'     */
    public scene_name: GDString;    
    /**     * The raw type is 'String'     */
    public base_path: GDString;    
    /**     * The raw type is 'String'     */
    public filename: GDString;    
    /**     * The raw type is 'PackedInt32Array'     */
    public root_nodes: PackedInt32Array;    
    /**     * The raw type is 'Array'     */
    public textures: Array<any>;    
    /**     * The raw type is 'Array'     */
    public texture_samplers: Array<any>;    
    /**     * The raw type is 'Array'     */
    public images: Array<any>;    
    /**     * The raw type is 'Array'     */
    public skins: Array<any>;    
    /**     * The raw type is 'Array'     */
    public cameras: Array<any>;    
    /**     * The raw type is 'Array'     */
    public lights: Array<any>;    
    /**     * The raw type is 'Array'     */
    public unique_names: Array<any>;    
    /**     * The raw type is 'Array'     */
    public unique_animation_names: Array<any>;    
    /**     * The raw type is 'Array'     */
    public skeletons: Array<any>;    
    /**     * The raw type is 'bool'     */
    public create_animations: boolean;    
    /**     * The raw type is 'bool'     */
    public import_as_skeleton_bones: boolean;    
    /**     * The raw type is 'Array'     */
    public animations: Array<any>;    
    /**     * The raw type is 'int'     */
    public handle_binary_image: number;    
    /**     * The raw type is 'float'     */
    public bake_fps: number;
    public add_used_extension(extensionName: GDString | StringName | string, required: boolean): void;
    public append_data_to_buffers(data: PackedByteArray, deduplication: boolean): number;
    public append_gltf_node(gltfNode: GLTFNode, godotSceneNode: Node, parentNodeIndex: number): number;
    public get_json(): Dictionary;
    public set_json(json: Dictionary): void;
    public get_major_version(): number;
    public set_major_version(majorVersion: number): void;
    public get_minor_version(): number;
    public set_minor_version(minorVersion: number): void;
    public get_copyright(): GDString;
    public set_copyright(copyright: GDString | StringName | string): void;
    public get_glb_data(): PackedByteArray;
    public set_glb_data(glbData: PackedByteArray): void;
    public get_use_named_skin_binds(): boolean;
    public set_use_named_skin_binds(useNamedSkinBinds: boolean): void;
    public get_nodes(): Array<any>;
    public set_nodes(nodes: Array<any>): void;
    public get_buffers(): Array<any>;
    public set_buffers(buffers: Array<any>): void;
    public get_buffer_views(): Array<any>;
    public set_buffer_views(bufferViews: Array<any>): void;
    public get_accessors(): Array<any>;
    public set_accessors(accessors: Array<any>): void;
    public get_meshes(): Array<any>;
    public set_meshes(meshes: Array<any>): void;
    public get_animation_players_count(idx: number): number;
    public get_animation_player(idx: number): AnimationPlayer;
    public get_materials(): Array<any>;
    public set_materials(materials: Array<any>): void;
    public get_scene_name(): GDString;
    public set_scene_name(sceneName: GDString | StringName | string): void;
    public get_base_path(): GDString;
    public set_base_path(basePath: GDString | StringName | string): void;
    public get_filename(): GDString;
    public set_filename(filename: GDString | StringName | string): void;
    public get_root_nodes(): PackedInt32Array;
    public set_root_nodes(rootNodes: PackedInt32Array): void;
    public get_textures(): Array<any>;
    public set_textures(textures: Array<any>): void;
    public get_texture_samplers(): Array<any>;
    public set_texture_samplers(textureSamplers: Array<any>): void;
    public get_images(): Array<any>;
    public set_images(images: Array<any>): void;
    public get_skins(): Array<any>;
    public set_skins(skins: Array<any>): void;
    public get_cameras(): Array<any>;
    public set_cameras(cameras: Array<any>): void;
    public get_lights(): Array<any>;
    public set_lights(lights: Array<any>): void;
    public get_unique_names(): Array<any>;
    public set_unique_names(uniqueNames: Array<any>): void;
    public get_unique_animation_names(): Array<any>;
    public set_unique_animation_names(uniqueAnimationNames: Array<any>): void;
    public get_skeletons(): Array<any>;
    public set_skeletons(skeletons: Array<any>): void;
    public get_create_animations(): boolean;
    public set_create_animations(createAnimations: boolean): void;
    public get_import_as_skeleton_bones(): boolean;
    public set_import_as_skeleton_bones(importAsSkeletonBones: boolean): void;
    public get_animations(): Array<any>;
    public set_animations(animations: Array<any>): void;
    public get_scene_node(idx: number): Node;
    public get_node_index(sceneNode: Node): number;
    public get_additional_data(extensionName: GDString | StringName | string): any;
    public set_additional_data(extensionName: GDString | StringName | string, additionalData: any): void;
    public get_handle_binary_image(): number;
    public set_handle_binary_image(method: number): void;
    public set_bake_fps(value: number): void;
    public get_bake_fps(): number;


}

