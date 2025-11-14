
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class RDVertexAttribute extends RefCounted {

    
    /**     * The raw type is 'int'     */
    public location: number;    
    /**     * The raw type is 'int'     */
    public offset: number;    
    /**     * The raw type is 'int'     */
    public format: number;    
    /**     * The raw type is 'int'     */
    public stride: number;    
    /**     * The raw type is 'int'     */
    public frequency: number;
    public set_location(member: number): void;
    public get_location(): number;
    public set_offset(member: number): void;
    public get_offset(): number;
    public set_format(member: number): void;
    public get_format(): number;
    public set_stride(member: number): void;
    public get_stride(): number;
    public set_frequency(member: number): void;
    public get_frequency(): number;


}

