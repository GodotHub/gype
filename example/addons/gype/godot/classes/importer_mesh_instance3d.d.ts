
import type { ImporterMesh } from '@godot/classes/importer_mesh';
import type { Node3D } from '@godot/classes/node3d';
import type { NodePath } from '@godot/builtins/node_path';
import type { Skin } from '@godot/classes/skin';


export declare class ImporterMeshInstance3D extends Node3D {

    
    /**     * The raw type is 'ImporterMesh'     */
    public mesh: ImporterMesh;    
    /**     * The raw type is 'Skin'     */
    public skin: Skin;    
    /**     * The raw type is 'NodePath'     */
    public skeleton_path: NodePath;    
    /**     * The raw type is 'int'     */
    public layer_mask: number;    
    /**     * The raw type is 'int'     */
    public cast_shadow: number;    
    /**     * The raw type is 'float'     */
    public visibility_range_begin: number;    
    /**     * The raw type is 'float'     */
    public visibility_range_begin_margin: number;    
    /**     * The raw type is 'float'     */
    public visibility_range_end: number;    
    /**     * The raw type is 'float'     */
    public visibility_range_end_margin: number;    
    /**     * The raw type is 'int'     */
    public visibility_range_fade_mode: number;
    public set_mesh(mesh: ImporterMesh): void;
    public get_mesh(): ImporterMesh;
    public set_skin(skin: Skin): void;
    public get_skin(): Skin;
    public set_skeleton_path(skeletonPath: NodePath | GDString | string): void;
    public get_skeleton_path(): NodePath;
    public set_layer_mask(layerMask: number): void;
    public get_layer_mask(): number;
    public set_cast_shadows_setting(shadowCastingSetting: number): void;
    public get_cast_shadows_setting(): number;
    public set_visibility_range_end_margin(distance: number): void;
    public get_visibility_range_end_margin(): number;
    public set_visibility_range_end(distance: number): void;
    public get_visibility_range_end(): number;
    public set_visibility_range_begin_margin(distance: number): void;
    public get_visibility_range_begin_margin(): number;
    public set_visibility_range_begin(distance: number): void;
    public get_visibility_range_begin(): number;
    public set_visibility_range_fade_mode(mode: number): void;
    public get_visibility_range_fade_mode(): number;


}

