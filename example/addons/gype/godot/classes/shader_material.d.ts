
import type { Material } from '@godot/classes/material';
import type { Shader } from '@godot/classes/shader';


export declare class ShaderMaterial extends Material {

    
    /**     * The raw type is 'Shader'     */
    public shader: Shader;
    public set_shader(shader: Shader): void;
    public get_shader(): Shader;
    public set_shader_parameter(param: GDString | StringName | string, value: any): void;
    public get_shader_parameter(param: GDString | StringName | string): any;


}

