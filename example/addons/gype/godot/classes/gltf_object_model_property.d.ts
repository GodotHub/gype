
import type { Expression } from '@godot/classes/expression';
import type { GDArray } from '@godot/builtins/gd_array';
import type { GDString } from '@godot/builtins/gd_string';
import type { NodePath } from '@godot/builtins/node_path';
import type { PackedStringArray } from '@godot/builtins/packed_string_array';
import type { RefCounted } from '@godot/classes/ref_counted';
import type { StringName } from '@godot/builtins/string_name';


export declare class GLTFObjectModelProperty extends RefCounted {

    
    /**     * The raw type is 'Expression'     */
    public gltf_to_godot_expression: Expression;    
    /**     * The raw type is 'Expression'     */
    public godot_to_gltf_expression: Expression;    
    /**     * The raw type is 'Array'     */
    public node_paths: Array<any>;    
    /**     * The raw type is 'int'     */
    public object_model_type: number;    
    /**     * The raw type is 'PackedStringArray'     */
    public json_pointers: Array<any>;    
    /**     * The raw type is 'int'     */
    public variant_type: number;
    public append_node_path(nodePath: NodePath | GDString | string): void;
    public append_path_to_property(nodePath: NodePath | GDString | string, proname: GDString | StringName | string): void;
    public get_accessor_type(): number;
    public get_gltf_to_godot_expression(): Expression;
    public set_gltf_to_godot_expression(gltfToGodotExpr: Expression): void;
    public get_godot_to_gltf_expression(): Expression;
    public set_godot_to_gltf_expression(godotToGltfExpr: Expression): void;
    public get_node_paths(): Array<any>;
    public has_node_paths(): boolean;
    public set_node_paths(nodePaths: Array<any>): void;
    public get_object_model_type(): number;
    public set_object_model_type(_type: number): void;
    public get_json_pointers(): Array<any>;
    public has_json_pointers(): boolean;
    public set_json_pointers(jsonPointers: Array<any>): void;
    public get_variant_type(): number;
    public set_variant_type(variantType: number): void;
    public set_types(variantType: number, objModelType: number): void;


    public static readonly GLTFObjectModelType: {
        GLTF_OBJECT_MODEL_TYPE_UNKNOWN: 0;
        GLTF_OBJECT_MODEL_TYPE_BOOL: 1;
        GLTF_OBJECT_MODEL_TYPE_FLOAT: 2;
        GLTF_OBJECT_MODEL_TYPE_FLOAT_ARRAY: 3;
        GLTF_OBJECT_MODEL_TYPE_FLOAT2: 4;
        GLTF_OBJECT_MODEL_TYPE_FLOAT3: 5;
        GLTF_OBJECT_MODEL_TYPE_FLOAT4: 6;
        GLTF_OBJECT_MODEL_TYPE_FLOAT2X2: 7;
        GLTF_OBJECT_MODEL_TYPE_FLOAT3X3: 8;
        GLTF_OBJECT_MODEL_TYPE_FLOAT4X4: 9;
        GLTF_OBJECT_MODEL_TYPE_INT: 10;
    };
}

