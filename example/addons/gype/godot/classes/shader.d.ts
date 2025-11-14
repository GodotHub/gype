
import type { GDArray } from '@godot/builtins/gd_array';
import type { GDString } from '@godot/builtins/gd_string';
import type { Resource } from '@godot/classes/resource';
import type { StringName } from '@godot/builtins/string_name';
import type { Texture } from '@godot/classes/texture';


export declare class Shader extends Resource {

    
    /**     * The raw type is 'String'     */
    public code: GDString;
    public get_mode(): number;
    public set_code(code: GDString | StringName | string): void;
    public get_code(): GDString;
    public set_default_texture_parameter(name: GDString | StringName | string, texture: Texture, index: number = 0): void;
    public get_default_texture_parameter(name: GDString | StringName | string, index: number = 0): Texture;
    public get_shader_uniform_list(getGroups: boolean = false): GDArray;
    public inspect_native_shader_code(): void;


    public static readonly Mode: {
        MODE_SPATIAL: 0;
        MODE_CANVAS_ITEM: 1;
        MODE_PARTICLES: 2;
        MODE_SKY: 3;
        MODE_FOG: 4;
    };
}

