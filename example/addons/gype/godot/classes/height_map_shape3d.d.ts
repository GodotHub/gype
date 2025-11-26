
import type { Image } from '@godot/classes/image';
import type { Shape3D } from '@godot/classes/shape3d';


export declare class HeightMapShape3D extends Shape3D {

    
    /**     * The raw type is 'int'     */
    public map_width: number;    
    /**     * The raw type is 'int'     */
    public map_depth: number;    
    /**     * The raw type is 'PackedFloat32Array'     */
    public map_data: PackedFloat32Array;
    public set_map_width(width: number): void;
    public get_map_width(): number;
    public set_map_depth(height: number): void;
    public get_map_depth(): number;
    public set_map_data(data: PackedFloat32Array): void;
    public get_map_data(): PackedFloat32Array;
    public get_min_height(): number;
    public get_max_height(): number;
    public update_map_data_from_image(image: Image, heightMin: number, heightMax: number): void;


}

