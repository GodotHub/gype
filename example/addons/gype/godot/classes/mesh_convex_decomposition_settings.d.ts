
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class MeshConvexDecompositionSettings extends RefCounted {

    
    /**     * The raw type is 'float'     */
    public max_concavity: number;    
    /**     * The raw type is 'float'     */
    public symmetry_planes_clipping_bias: number;    
    /**     * The raw type is 'float'     */
    public revolution_axes_clipping_bias: number;    
    /**     * The raw type is 'float'     */
    public min_volume_per_convex_hull: number;    
    /**     * The raw type is 'int'     */
    public resolution: number;    
    /**     * The raw type is 'int'     */
    public max_num_vertices_per_convex_hull: number;    
    /**     * The raw type is 'int'     */
    public plane_downsampling: number;    
    /**     * The raw type is 'int'     */
    public convex_hull_downsampling: number;    
    /**     * The raw type is 'bool'     */
    public normalize_mesh: boolean;    
    /**     * The raw type is 'int'     */
    public mode: number;    
    /**     * The raw type is 'bool'     */
    public convex_hull_approximation: boolean;    
    /**     * The raw type is 'int'     */
    public max_convex_hulls: number;    
    /**     * The raw type is 'bool'     */
    public project_hull_vertices: boolean;
    public set_max_concavity(maxConcavity: number): void;
    public get_max_concavity(): number;
    public set_symmetry_planes_clipping_bias(symmetryPlanesClippingBias: number): void;
    public get_symmetry_planes_clipping_bias(): number;
    public set_revolution_axes_clipping_bias(revolutionAxesClippingBias: number): void;
    public get_revolution_axes_clipping_bias(): number;
    public set_min_volume_per_convex_hull(minVolumePerConvexHull: number): void;
    public get_min_volume_per_convex_hull(): number;
    public set_resolution(minVolumePerConvexHull: number): void;
    public get_resolution(): number;
    public set_max_num_vertices_per_convex_hull(maxNumVerticesPerConvexHull: number): void;
    public get_max_num_vertices_per_convex_hull(): number;
    public set_plane_downsampling(planeDownsampling: number): void;
    public get_plane_downsampling(): number;
    public set_convex_hull_downsampling(convexHullDownsampling: number): void;
    public get_convex_hull_downsampling(): number;
    public set_normalize_mesh(normalizeMesh: boolean): void;
    public get_normalize_mesh(): boolean;
    public set_mode(mode: number): void;
    public get_mode(): number;
    public set_convex_hull_approximation(convexHullApproximation: boolean): void;
    public get_convex_hull_approximation(): boolean;
    public set_max_convex_hulls(maxConvexHulls: number): void;
    public get_max_convex_hulls(): number;
    public set_project_hull_vertices(projectHullVertices: boolean): void;
    public get_project_hull_vertices(): boolean;


    public static readonly Mode: {
        CONVEX_DECOMPOSITION_MODE_VOXEL: 0;
        CONVEX_DECOMPOSITION_MODE_TETRAHEDRON: 1;
    };
}

