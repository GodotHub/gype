
import type { GDString } from '@godot/builtins/gd_string';
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class RDShaderSource extends RefCounted {

    
    /**     * The raw type is 'String'     */
    public source_vertex: GDString;    
    /**     * The raw type is 'String'     */
    public source_fragment: GDString;    
    /**     * The raw type is 'String'     */
    public source_tesselation_control: GDString;    
    /**     * The raw type is 'String'     */
    public source_tesselation_evaluation: GDString;    
    /**     * The raw type is 'String'     */
    public source_compute: GDString;    
    /**     * The raw type is 'int'     */
    public language: number;
    public set_stage_source(stage: number, source: GDString | StringName | string): void;
    public get_stage_source(stage: number): GDString;
    public set_language(language: number): void;
    public get_language(): number;


}

