
import type { GDString } from '@godot/builtins/gd_string';
import type { RDTextureFormat } from '@godot/classes/rd_texture_format';
import type { RDTextureView } from '@godot/classes/rd_texture_view';
import type { RID } from '@godot/builtins/rid';
import type { RenderSceneBuffers } from '@godot/classes/render_scene_buffers';
import type { StringName } from '@godot/builtins/string_name';
import type { Vector2i } from '@godot/builtins/vector2i';


export declare class RenderSceneBuffersRD extends RenderSceneBuffers {


    public has_texture(context: GDString | StringName | string, name: GDString | StringName | string): boolean;
    public create_texture(context: GDString | StringName | string, name: GDString | StringName | string, dataFormat: number, usageBits: number, textureSamples: number, size: Vector2i, layers: number, mipmaps: number, unique: boolean, discardable: boolean): RID;
    public create_texture_from_format(context: GDString | StringName | string, name: GDString | StringName | string, format: RDTextureFormat, view: RDTextureView, unique: boolean): RID;
    public create_texture_view(context: GDString | StringName | string, name: GDString | StringName | string, viewName: GDString | StringName | string, view: RDTextureView): RID;
    public get_texture(context: GDString | StringName | string, name: GDString | StringName | string): RID;
    public get_texture_format(context: GDString | StringName | string, name: GDString | StringName | string): RDTextureFormat;
    public get_texture_slice(context: GDString | StringName | string, name: GDString | StringName | string, layer: number, mipmap: number, layers: number, mipmaps: number): RID;
    public get_texture_slice_view(context: GDString | StringName | string, name: GDString | StringName | string, layer: number, mipmap: number, layers: number, mipmaps: number, view: RDTextureView): RID;
    public get_texture_slice_size(context: GDString | StringName | string, name: GDString | StringName | string, mipmap: number): Vector2i;
    public clear_context(context: GDString | StringName | string): void;
    public get_color_texture(msaa: boolean = false): RID;
    public get_color_layer(layer: number, msaa: boolean = false): RID;
    public get_depth_texture(msaa: boolean = false): RID;
    public get_depth_layer(layer: number, msaa: boolean = false): RID;
    public get_velocity_texture(msaa: boolean = false): RID;
    public get_velocity_layer(layer: number, msaa: boolean = false): RID;
    public get_render_target(): RID;
    public get_view_count(): number;
    public get_internal_size(): Vector2i;
    public get_target_size(): Vector2i;
    public get_scaling_3d_mode(): number;
    public get_fsr_sharpness(): number;
    public get_msaa_3d(): number;
    public get_texture_samples(): number;
    public get_screen_space_aa(): number;
    public get_use_taa(): boolean;
    public get_use_debanding(): boolean;


}

