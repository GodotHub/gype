
import type { Light3D } from '@godot/classes/light3d';
import type { Resource } from '@godot/classes/resource';


export declare class GLTFLight extends Resource {

    
    /**     * The raw type is 'Color'     */
    public color: Color;    
    /**     * The raw type is 'float'     */
    public intensity: number;    
    /**     * The raw type is 'String'     */
    public light_type: GDString;    
    /**     * The raw type is 'float'     */
    public range: number;    
    /**     * The raw type is 'float'     */
    public inner_cone_angle: number;    
    /**     * The raw type is 'float'     */
    public outer_cone_angle: number;
    public static from_node(lightNode: Light3D): GLTFLight;
    public to_node(): Light3D;
    public static from_dictionary(dictionary: Dictionary): GLTFLight;
    public to_dictionary(): Dictionary;
    public get_color(): Color;
    public set_color(color: Color): void;
    public get_intensity(): number;
    public set_intensity(intensity: number): void;
    public get_light_type(): GDString;
    public set_light_type(lightType: GDString | StringName | string): void;
    public get_range(): number;
    public set_range(range: number): void;
    public get_inner_cone_angle(): number;
    public set_inner_cone_angle(innerConeAngle: number): void;
    public get_outer_cone_angle(): number;
    public set_outer_cone_angle(outerConeAngle: number): void;
    public get_additional_data(extensionName: GDString | StringName | string): any;
    public set_additional_data(extensionName: GDString | StringName | string, additionalData: any): void;


}

