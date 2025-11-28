
import type { GLTFDocumentExtension } from '@godot/classes/gltf_document_extension';
import type { GLTFObjectModelProperty } from '@godot/classes/gltf_object_model_property';
import type { GLTFState } from '@godot/classes/gltf_state';
import type { Node } from '@godot/classes/node';
import type { Resource } from '@godot/classes/resource';


export declare class GLTFDocument extends Resource {

    
    /**     * The raw type is 'String'     */
    public image_format: GDString | StringName | string;    
    /**     * The raw type is 'float'     */
    public lossy_quality: number;    
    /**     * The raw type is 'String'     */
    public fallback_image_format: GDString | StringName | string;    
    /**     * The raw type is 'float'     */
    public fallback_image_quality: number;    
    /**     * The raw type is 'int'     */
    public root_node_mode: number;    
    /**     * The raw type is 'int'     */
    public visibility_mode: number;
    public set_image_format(imageFormat: GDString | StringName | string): void;
    public get_image_format(): GDString;
    public set_lossy_quality(lossyQuality: number): void;
    public get_lossy_quality(): number;
    public set_fallback_image_format(fallbackImageFormat: GDString | StringName | string): void;
    public get_fallback_image_format(): GDString;
    public set_fallback_image_quality(fallbackImageQuality: number): void;
    public get_fallback_image_quality(): number;
    public set_root_node_mode(rootNodeMode: number): void;
    public get_root_node_mode(): number;
    public set_visibility_mode(visibilityMode: number): void;
    public get_visibility_mode(): number;
    public append_from_file(path: GDString | StringName | string, state: GLTFState, flags: number = 0, basePath: GDString | StringName | string = ""): number;
    public append_from_buffer(bytes: PackedByteArray, basePath: GDString | StringName | string, state: GLTFState, flags: number = 0): number;
    public append_from_scene(node: Node, state: GLTFState, flags: number = 0): number;
    public generate_scene(state: GLTFState, bakeFps: number = 30, trimming: boolean = false, removeImmutableTracks: boolean = true): Node;
    public generate_buffer(state: GLTFState): PackedByteArray;
    public write_to_filesystem(state: GLTFState, path: GDString | StringName | string): number;
    public static import_object_model_property(state: GLTFState, jsonPointer: GDString | StringName | string): GLTFObjectModelProperty;
    public static export_object_model_property(state: GLTFState, nodePath: NodePath | GDString | string, godotNode: Node, gltfNodeIndex: number): GLTFObjectModelProperty;
    public static register_gltf_document_extension(extension: GLTFDocumentExtension, firstPriority: boolean = false): void;
    public static unregister_gltf_document_extension(extension: GLTFDocumentExtension): void;
    public static get_supported_gltf_extensions(): PackedStringArray;


    public static readonly RootNodeMode: {
        ROOT_NODE_MODE_SINGLE_ROOT: 0;
        ROOT_NODE_MODE_KEEP_ROOT: 1;
        ROOT_NODE_MODE_MULTI_ROOT: 2;
    };
    public static readonly VisibilityMode: {
        VISIBILITY_MODE_INCLUDE_REQUIRED: 0;
        VISIBILITY_MODE_INCLUDE_OPTIONAL: 1;
        VISIBILITY_MODE_EXCLUDE: 2;
    };
}

