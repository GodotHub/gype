
import type { BaseMaterial3D } from '@godot/classes/base_material3d';
import type { CSGPrimitive3D } from '@godot/classes/csg_primitive3d';
import type { Material } from '@godot/classes/material';


export declare class CSGPolygon3D extends CSGPrimitive3D {

    
    /**     * The raw type is 'PackedVector2Array'     */
    public polygon: PackedVector2Array;    
    /**     * The raw type is 'int'     */
    public mode: number;    
    /**     * The raw type is 'float'     */
    public depth: number;    
    /**     * The raw type is 'float'     */
    public spin_degrees: number;    
    /**     * The raw type is 'int'     */
    public spin_sides: number;    
    /**     * The raw type is 'NodePath'     */
    public path_node: NodePath;    
    /**     * The raw type is 'int'     */
    public path_interval_type: number;    
    /**     * The raw type is 'float'     */
    public path_interval: number;    
    /**     * The raw type is 'float'     */
    public path_simplify_angle: number;    
    /**     * The raw type is 'int'     */
    public path_rotation: number;    
    /**     * The raw type is 'bool'     */
    public path_rotation_accurate: boolean;    
    /**     * The raw type is 'bool'     */
    public path_local: boolean;    
    /**     * The raw type is 'bool'     */
    public path_continuous_u: boolean;    
    /**     * The raw type is 'float'     */
    public path_u_distance: number;    
    /**     * The raw type is 'bool'     */
    public path_joined: boolean;    
    /**     * The raw type is 'bool'     */
    public smooth_faces: boolean;    
    /**     * The raw type is 'BaseMaterial3D,ShaderMaterial'     */
    public material: Material;
    public set_polygon(polygon: PackedVector2Array): void;
    public get_polygon(): PackedVector2Array;
    public set_mode(mode: number): void;
    public get_mode(): number;
    public set_depth(depth: number): void;
    public get_depth(): number;
    public set_spin_degrees(degrees: number): void;
    public get_spin_degrees(): number;
    public set_spin_sides(spinSides: number): void;
    public get_spin_sides(): number;
    public set_path_node(path: NodePath | GDString | string): void;
    public get_path_node(): NodePath;
    public set_path_interval_type(intervalType: number): void;
    public get_path_interval_type(): number;
    public set_path_interval(interval: number): void;
    public get_path_interval(): number;
    public set_path_simplify_angle(degrees: number): void;
    public get_path_simplify_angle(): number;
    public set_path_rotation(pathRotation: number): void;
    public get_path_rotation(): number;
    public set_path_rotation_accurate(enable: boolean): void;
    public get_path_rotation_accurate(): boolean;
    public set_path_local(enable: boolean): void;
    public is_path_local(): boolean;
    public set_path_continuous_u(enable: boolean): void;
    public is_path_continuous_u(): boolean;
    public set_path_u_distance(distance: number): void;
    public get_path_u_distance(): number;
    public set_path_joined(enable: boolean): void;
    public is_path_joined(): boolean;
    public set_material(material: Material): void;
    public get_material(): Material;
    public set_smooth_faces(smoothFaces: boolean): void;
    public get_smooth_faces(): boolean;


    public static readonly Mode: {
        MODE_DEPTH: 0;
        MODE_SPIN: 1;
        MODE_PATH: 2;
    };
    public static readonly PathRotation: {
        PATH_ROTATION_POLYGON: 0;
        PATH_ROTATION_PATH: 1;
        PATH_ROTATION_PATH_FOLLOW: 2;
    };
    public static readonly PathIntervalType: {
        PATH_INTERVAL_DISTANCE: 0;
        PATH_INTERVAL_SUBDIVIDE: 1;
    };
}

