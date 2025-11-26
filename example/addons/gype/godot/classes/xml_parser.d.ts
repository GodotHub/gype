
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class XMLParser extends RefCounted {


    public read(): number;
    public get_node_type(): number;
    public get_node_name(): GDString;
    public get_node_data(): GDString;
    public get_node_offset(): number;
    public get_attribute_count(): number;
    public get_attribute_name(idx: number): GDString;
    public get_attribute_value(idx: number): GDString;
    public has_attribute(name: GDString | StringName | string): boolean;
    public get_named_attribute_value(name: GDString | StringName | string): GDString;
    public get_named_attribute_value_safe(name: GDString | StringName | string): GDString;
    public is_empty(): boolean;
    public get_current_line(): number;
    public skip_section(): void;
    public seek(position: number): number;
    public open(file: GDString | StringName | string): number;
    public open_buffer(buffer: PackedByteArray): number;


    public static readonly NodeType: {
        NODE_NONE: 0;
        NODE_ELEMENT: 1;
        NODE_ELEMENT_END: 2;
        NODE_TEXT: 3;
        NODE_COMMENT: 4;
        NODE_CDATA: 5;
        NODE_UNKNOWN: 6;
    };
}

