
import type { RDShaderSPIRV } from '@godot/classes/rd_shader_spirv';
import type { Resource } from '@godot/classes/resource';


export declare class RDShaderFile extends Resource {

    
    /**     * The raw type is 'String'     */
    public base_error: GDString;
    public set_bytecode(bytecode: RDShaderSPIRV, version: GDString | StringName | string = ""): void;
    public get_spirv(version: GDString | StringName | string = ""): RDShaderSPIRV;
    public get_version_list(): Array<any>;
    public set_base_error(error: GDString | StringName | string): void;
    public get_base_error(): GDString;


}

