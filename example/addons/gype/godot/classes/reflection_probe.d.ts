
import type { VisualInstance3D } from '@godot/classes/visual_instance3d';


export declare class ReflectionProbe extends VisualInstance3D {

    
    /**     * The raw type is 'int'     */
    public update_mode: number;    
    /**     * The raw type is 'float'     */
    public intensity: number;    
    /**     * The raw type is 'float'     */
    public blend_distance: number;    
    /**     * The raw type is 'float'     */
    public max_distance: number;    
    /**     * The raw type is 'Vector3'     */
    public size: Vector3;    
    /**     * The raw type is 'Vector3'     */
    public origin_offset: Vector3;    
    /**     * The raw type is 'bool'     */
    public box_projection: boolean;    
    /**     * The raw type is 'bool'     */
    public interior: boolean;    
    /**     * The raw type is 'bool'     */
    public enable_shadows: boolean;    
    /**     * The raw type is 'int'     */
    public cull_mask: number;    
    /**     * The raw type is 'int'     */
    public reflection_mask: number;    
    /**     * The raw type is 'float'     */
    public mesh_lod_threshold: number;    
    /**     * The raw type is 'int'     */
    public ambient_mode: number;    
    /**     * The raw type is 'Color'     */
    public ambient_color: Color;    
    /**     * The raw type is 'float'     */
    public ambient_color_energy: number;
    public set_intensity(intensity: number): void;
    public get_intensity(): number;
    public set_blend_distance(blendDistance: number): void;
    public get_blend_distance(): number;
    public set_ambient_mode(ambient: number): void;
    public get_ambient_mode(): number;
    public set_ambient_color(ambient: Color): void;
    public get_ambient_color(): Color;
    public set_ambient_color_energy(ambientEnergy: number): void;
    public get_ambient_color_energy(): number;
    public set_max_distance(maxDistance: number): void;
    public get_max_distance(): number;
    public set_mesh_lod_threshold(ratio: number): void;
    public get_mesh_lod_threshold(): number;
    public set_size(size: Vector3): void;
    public get_size(): Vector3;
    public set_origin_offset(originOffset: Vector3): void;
    public get_origin_offset(): Vector3;
    public set_as_interior(enable: boolean): void;
    public is_set_as_interior(): boolean;
    public set_enable_box_projection(enable: boolean): void;
    public is_box_projection_enabled(): boolean;
    public set_enable_shadows(enable: boolean): void;
    public are_shadows_enabled(): boolean;
    public set_cull_mask(layers: number): void;
    public get_cull_mask(): number;
    public set_reflection_mask(layers: number): void;
    public get_reflection_mask(): number;
    public set_update_mode(mode: number): void;
    public get_update_mode(): number;


    public static readonly UpdateMode: {
        UPDATE_ONCE: 0;
        UPDATE_ALWAYS: 1;
    };
    public static readonly AmbientMode: {
        AMBIENT_DISABLED: 0;
        AMBIENT_ENVIRONMENT: 1;
        AMBIENT_COLOR: 2;
    };
}

