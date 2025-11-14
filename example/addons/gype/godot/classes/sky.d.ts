
import type { Material } from '@godot/classes/material';
import type { PanoramaSkyMaterial } from '@godot/classes/panorama_sky_material';
import type { Resource } from '@godot/classes/resource';


export declare class Sky extends Resource {

    
    /**     * The raw type is 'PanoramaSkyMaterial,ProceduralSkyMaterial,PhysicalSkyMaterial,ShaderMaterial'     */
    public sky_material: Material;    
    /**     * The raw type is 'int'     */
    public process_mode: number;    
    /**     * The raw type is 'int'     */
    public radiance_size: number;
    public set_radiance_size(size: number): void;
    public get_radiance_size(): number;
    public set_process_mode(mode: number): void;
    public get_process_mode(): number;
    public set_material(material: Material): void;
    public get_material(): Material;


    public static readonly RadianceSize: {
        RADIANCE_SIZE_32: 0;
        RADIANCE_SIZE_64: 1;
        RADIANCE_SIZE_128: 2;
        RADIANCE_SIZE_256: 3;
        RADIANCE_SIZE_512: 4;
        RADIANCE_SIZE_1024: 5;
        RADIANCE_SIZE_2048: 6;
        RADIANCE_SIZE_MAX: 7;
    };
    public static readonly ProcessMode: {
        PROCESS_MODE_AUTOMATIC: 0;
        PROCESS_MODE_QUALITY: 1;
        PROCESS_MODE_INCREMENTAL: 2;
        PROCESS_MODE_REALTIME: 3;
    };
}

