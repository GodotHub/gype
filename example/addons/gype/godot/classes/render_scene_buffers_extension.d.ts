
import type { RenderSceneBuffers } from '@godot/classes/render_scene_buffers';
import type { RenderSceneBuffersConfiguration } from '@godot/classes/render_scene_buffers_configuration';


export declare class RenderSceneBuffersExtension extends RenderSceneBuffers {


    public _configure(config: RenderSceneBuffersConfiguration): void;
    public _set_fsr_sharpness(fsrSharpness: number): void;
    public _set_texture_mipmap_bias(textureMipmabias: number): void;
    public _set_anisotropic_filtering_level(anisotropicFilteringLevel: number): void;
    public _set_use_debanding(useDebanding: boolean): void;


}

