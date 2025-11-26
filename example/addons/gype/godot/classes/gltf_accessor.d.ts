
import type { Resource } from '@godot/classes/resource';


export declare class GLTFAccessor extends Resource {

    
    /**     * The raw type is 'int'     */
    public buffer_view: number;    
    /**     * The raw type is 'int'     */
    public byte_offset: number;    
    /**     * The raw type is 'int'     */
    public component_type: number;    
    /**     * The raw type is 'bool'     */
    public normalized: boolean;    
    /**     * The raw type is 'int'     */
    public count: number;    
    /**     * The raw type is 'int'     */
    public accessor_type: number;    
    /**     * The raw type is 'int'     */
    public type: number;    
    /**     * The raw type is 'PackedFloat64Array'     */
    public min: PackedFloat64Array;    
    /**     * The raw type is 'PackedFloat64Array'     */
    public max: PackedFloat64Array;    
    /**     * The raw type is 'int'     */
    public sparse_count: number;    
    /**     * The raw type is 'int'     */
    public sparse_indices_buffer_view: number;    
    /**     * The raw type is 'int'     */
    public sparse_indices_byte_offset: number;    
    /**     * The raw type is 'int'     */
    public sparse_indices_component_type: number;    
    /**     * The raw type is 'int'     */
    public sparse_values_buffer_view: number;    
    /**     * The raw type is 'int'     */
    public sparse_values_byte_offset: number;
    public get_buffer_view(): number;
    public set_buffer_view(bufferView: number): void;
    public get_byte_offset(): number;
    public set_byte_offset(byteOffset: number): void;
    public get_component_type(): number;
    public set_component_type(componentType: number): void;
    public get_normalized(): boolean;
    public set_normalized(normalized: boolean): void;
    public get_count(): number;
    public set_count(count: number): void;
    public get_accessor_type(): number;
    public set_accessor_type(accessorType: number): void;
    public get_type(): number;
    public set_type(_type: number): void;
    public get_min(): PackedFloat64Array;
    public set_min(min: PackedFloat64Array): void;
    public get_max(): PackedFloat64Array;
    public set_max(max: PackedFloat64Array): void;
    public get_sparse_count(): number;
    public set_sparse_count(sparseCount: number): void;
    public get_sparse_indices_buffer_view(): number;
    public set_sparse_indices_buffer_view(sparseIndicesBufferView: number): void;
    public get_sparse_indices_byte_offset(): number;
    public set_sparse_indices_byte_offset(sparseIndicesByteOffset: number): void;
    public get_sparse_indices_component_type(): number;
    public set_sparse_indices_component_type(sparseIndicesComponentType: number): void;
    public get_sparse_values_buffer_view(): number;
    public set_sparse_values_buffer_view(sparseValuesBufferView: number): void;
    public get_sparse_values_byte_offset(): number;
    public set_sparse_values_byte_offset(sparseValuesByteOffset: number): void;


    public static readonly GLTFAccessorType: {
        TYPE_SCALAR: 0;
        TYPE_VEC2: 1;
        TYPE_VEC3: 2;
        TYPE_VEC4: 3;
        TYPE_MAT2: 4;
        TYPE_MAT3: 5;
        TYPE_MAT4: 6;
    };
    public static readonly GLTFComponentType: {
        COMPONENT_TYPE_NONE: 0;
        COMPONENT_TYPE_SIGNED_BYTE: 5120;
        COMPONENT_TYPE_UNSIGNED_BYTE: 5121;
        COMPONENT_TYPE_SIGNED_SHORT: 5122;
        COMPONENT_TYPE_UNSIGNED_SHORT: 5123;
        COMPONENT_TYPE_SIGNED_INT: 5124;
        COMPONENT_TYPE_UNSIGNED_INT: 5125;
        COMPONENT_TYPE_SINGLE_FLOAT: 5126;
        COMPONENT_TYPE_DOUBLE_FLOAT: 5130;
        COMPONENT_TYPE_HALF_FLOAT: 5131;
        COMPONENT_TYPE_SIGNED_LONG: 5134;
        COMPONENT_TYPE_UNSIGNED_LONG: 5135;
    };
}

