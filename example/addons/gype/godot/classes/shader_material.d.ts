
import { Material } from "@godot/classes/material";
import { Shader } from "@godot/classes/shader";

export declare class ShaderMaterial extends Material{
  public set_shader(_shader: Shader): void;
  public get_shader(): Shader;
  public set_shader_parameter(_param: StringName, _value: any): void;
  public get_shader_parameter(_param: StringName): any;
  public get shader(): Shader {
    get_shader();
  }
  public set shader(value): void {
    set_shader(value);
  }
}