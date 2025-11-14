
import type { GLTFState } from '@godot/classes/gltf_state';
import type { PackedByteArray } from '@godot/builtins/packed_byte_array';
import type { Resource } from '@godot/classes/resource';


export declare class GLTFBufferView extends Resource {

    
    /**     * The raw type is 'int'     */
    public buffer: number;    
    /**     * The raw type is 'int'     */
    public byte_offset: number;    
    /**     * The raw type is 'int'     */
    public byte_length: number;    
    /**     * The raw type is 'int'     */
    public byte_stride: number;    
    /**     * The raw type is 'bool'     */
    public indices: boolean;    
    /**     * The raw type is 'bool'     */
    public vertex_attributes: boolean;
    public load_buffer_view_data(state: GLTFState): PackedByteArray;
    public get_buffer(): number;
    public set_buffer(buffer: number): void;
    public get_byte_offset(): number;
    public set_byte_offset(byteOffset: number): void;
    public get_byte_length(): number;
    public set_byte_length(byteLength: number): void;
    public get_byte_stride(): number;
    public set_byte_stride(byteStride: number): void;
    public get_indices(): boolean;
    public set_indices(indices: boolean): void;
    public get_vertex_attributes(): boolean;
    public set_vertex_attributes(isAttributes: boolean): void;


}

