
import type { GDString } from '@godot/builtins/gd_string';
import type { PackedInt32Array } from '@godot/builtins/packed_int32_array';
import type { Shader } from '@godot/classes/shader';
import type { StringName } from '@godot/builtins/string_name';
import type { Vector2 } from '@godot/builtins/vector2';
import type { VisualShaderNode } from '@godot/classes/visual_shader_node';


export declare class VisualShader extends Shader {

    
    /**     * The raw type is 'Vector2'     */
    public graph_offset: Vector2;
    public set_mode(mode: number): void;
    public add_node(_type: number, node: VisualShaderNode, position: Vector2, id: number): void;
    public get_node(_type: number, id: number): VisualShaderNode;
    public set_node_position(_type: number, id: number, position: Vector2): void;
    public get_node_position(_type: number, id: number): Vector2;
    public get_node_list(_type: number): PackedInt32Array;
    public get_valid_node_id(_type: number): number;
    public remove_node(_type: number, id: number): void;
    public replace_node(_type: number, id: number, newClass: GDString | StringName | string): void;
    public is_node_connection(_type: number, fromNode: number, fromPort: number, toNode: number, toPort: number): boolean;
    public can_connect_nodes(_type: number, fromNode: number, fromPort: number, toNode: number, toPort: number): boolean;
    public connect_nodes(_type: number, fromNode: number, fromPort: number, toNode: number, toPort: number): number;
    public disconnect_nodes(_type: number, fromNode: number, fromPort: number, toNode: number, toPort: number): void;
    public connect_nodes_forced(_type: number, fromNode: number, fromPort: number, toNode: number, toPort: number): void;
    public get_node_connections(_type: number): Array<any>;
    public attach_node_to_frame(_type: number, id: number, frame: number): void;
    public detach_node_from_frame(_type: number, id: number): void;
    public add_varying(name: GDString | StringName | string, mode: number, _type: number): void;
    public remove_varying(name: GDString | StringName | string): void;
    public has_varying(name: GDString | StringName | string): boolean;
    public set_graph_offset(offset: Vector2): void;
    public get_graph_offset(): Vector2;


    public static readonly Type: {
        TYPE_VERTEX: 0;
        TYPE_FRAGMENT: 1;
        TYPE_LIGHT: 2;
        TYPE_START: 3;
        TYPE_PROCESS: 4;
        TYPE_COLLIDE: 5;
        TYPE_START_CUSTOM: 6;
        TYPE_PROCESS_CUSTOM: 7;
        TYPE_SKY: 8;
        TYPE_FOG: 9;
        TYPE_MAX: 10;
    };
    public static readonly VaryingMode: {
        VARYING_MODE_VERTEX_TO_FRAG_LIGHT: 0;
        VARYING_MODE_FRAG_TO_LIGHT: 1;
        VARYING_MODE_MAX: 2;
    };
    public static readonly VaryingType: {
        VARYING_TYPE_FLOAT: 0;
        VARYING_TYPE_INT: 1;
        VARYING_TYPE_UINT: 2;
        VARYING_TYPE_VECTOR_2D: 3;
        VARYING_TYPE_VECTOR_3D: 4;
        VARYING_TYPE_VECTOR_4D: 5;
        VARYING_TYPE_BOOLEAN: 6;
        VARYING_TYPE_TRANSFORM: 7;
        VARYING_TYPE_MAX: 8;
    };
}

