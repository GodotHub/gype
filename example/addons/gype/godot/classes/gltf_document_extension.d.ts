
import type { GLTFNode } from '@godot/classes/gltf_node';
import type { GLTFObjectModelProperty } from '@godot/classes/gltf_object_model_property';
import type { GLTFState } from '@godot/classes/gltf_state';
import type { GLTFTexture } from '@godot/classes/gltf_texture';
import type { GodotObject } from '@godot/classes/godot_object';
import type { Image } from '@godot/classes/image';
import type { Node } from '@godot/classes/node';
import type { Node3D } from '@godot/classes/node3d';
import type { Resource } from '@godot/classes/resource';


export declare class GLTFDocumentExtension extends Resource {


    public _import_preflight(state: GLTFState, extensions: PackedStringArray): number;
    public _get_supported_extensions(): PackedStringArray;
    public _parse_node_extensions(state: GLTFState, gltfNode: GLTFNode, extensions: Dictionary): number;
    public _parse_image_data(state: GLTFState, imageData: PackedByteArray, mimeType: GDString | StringName | string, retImage: Image): number;
    public _get_image_file_extension(): GDString;
    public _parse_texture_json(state: GLTFState, textureJson: Dictionary, retGltfTexture: GLTFTexture): number;
    public _import_object_model_property(state: GLTFState, splitJsonPointer: PackedStringArray, partialPaths: Array<any>): GLTFObjectModelProperty;
    public _import_post_parse(state: GLTFState): number;
    public _import_pre_generate(state: GLTFState): number;
    public _generate_scene_node(state: GLTFState, gltfNode: GLTFNode, sceneParent: Node): Node3D;
    public _import_node(state: GLTFState, gltfNode: GLTFNode, json: Dictionary, node: Node): number;
    public _import_post(state: GLTFState, root: Node): number;
    public _export_preflight(state: GLTFState, root: Node): number;
    public _convert_scene_node(state: GLTFState, gltfNode: GLTFNode, sceneNode: Node): void;
    public _export_post_convert(state: GLTFState, root: Node): number;
    public _export_preserialize(state: GLTFState): number;
    public _export_object_model_property(state: GLTFState, nodePath: NodePath | GDString | string, godotNode: Node, gltfNodeIndex: number, targetObject: GodotObject, targetDepth: number): GLTFObjectModelProperty;
    public _get_saveable_image_formats(): PackedStringArray;
    public _serialize_image_to_bytes(state: GLTFState, image: Image, imageDict: Dictionary, imageFormat: GDString | StringName | string, lossyQuality: number): PackedByteArray;
    public _save_image_at_path(state: GLTFState, image: Image, filePath: GDString | StringName | string, imageFormat: GDString | StringName | string, lossyQuality: number): number;
    public _serialize_texture_json(state: GLTFState, textureJson: Dictionary, gltfTexture: GLTFTexture, imageFormat: GDString | StringName | string): number;
    public _export_node(state: GLTFState, gltfNode: GLTFNode, json: Dictionary, node: Node): number;
    public _export_post(state: GLTFState): number;


}

