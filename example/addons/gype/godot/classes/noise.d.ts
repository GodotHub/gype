
import type { Image } from '@godot/classes/image';
import type { Resource } from '@godot/classes/resource';


export declare class Noise extends Resource {


    public get_noise_1d(x: number): number;
    public get_noise_2d(x: number, y: number): number;
    public get_noise_2dv(v: Vector2): number;
    public get_noise_3d(x: number, y: number, z: number): number;
    public get_noise_3dv(v: Vector3): number;
    public get_image(width: number, height: number, invert: boolean = false, in3DSpace: boolean = false, normalize: boolean = true): Image;
    public get_seamless_image(width: number, height: number, invert: boolean = false, in3DSpace: boolean = false, skirt: number = 0.1, normalize: boolean = true): Image;
    public get_image_3d(width: number, height: number, depth: number, invert: boolean = false, normalize: boolean = true): Array<any>;
    public get_seamless_image_3d(width: number, height: number, depth: number, invert: boolean = false, skirt: number = 0.1, normalize: boolean = true): Array<any>;


}

