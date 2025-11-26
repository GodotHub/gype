
import type { Resource } from '@godot/classes/resource';


export declare class RDShaderSPIRV extends Resource {

    
    /**     * The raw type is 'PackedByteArray'     */
    public bytecode_vertex: PackedByteArray;    
    /**     * The raw type is 'PackedByteArray'     */
    public bytecode_fragment: PackedByteArray;    
    /**     * The raw type is 'PackedByteArray'     */
    public bytecode_tesselation_control: PackedByteArray;    
    /**     * The raw type is 'PackedByteArray'     */
    public bytecode_tesselation_evaluation: PackedByteArray;    
    /**     * The raw type is 'PackedByteArray'     */
    public bytecode_compute: PackedByteArray;    
    /**     * The raw type is 'String'     */
    public compile_error_vertex: GDString;    
    /**     * The raw type is 'String'     */
    public compile_error_fragment: GDString;    
    /**     * The raw type is 'String'     */
    public compile_error_tesselation_control: GDString;    
    /**     * The raw type is 'String'     */
    public compile_error_tesselation_evaluation: GDString;    
    /**     * The raw type is 'String'     */
    public compile_error_compute: GDString;
    public set_stage_bytecode(stage: number, bytecode: PackedByteArray): void;
    public get_stage_bytecode(stage: number): PackedByteArray;
    public set_stage_compile_error(stage: number, compileError: GDString | StringName | string): void;
    public get_stage_compile_error(stage: number): GDString;


}

