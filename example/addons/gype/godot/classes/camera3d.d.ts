
import type { CameraAttributes } from '@godot/classes/camera_attributes';
import type { CameraAttributesPractical } from '@godot/classes/camera_attributes_practical';
import type { Compositor } from '@godot/classes/compositor';
import type { Environment } from '@godot/classes/environment';
import type { Node3D } from '@godot/classes/node3d';
import type { Projection } from '@godot/builtins/projection';
import type { RID } from '@godot/builtins/rid';
import type { Transform3D } from '@godot/builtins/transform3d';
import type { Vector2 } from '@godot/builtins/vector2';
import type { Vector3 } from '@godot/builtins/vector3';


export declare class Camera3D extends Node3D {

    
    /**     * The raw type is 'int'     */
    public keep_aspect: number;    
    /**     * The raw type is 'int'     */
    public cull_mask: number;    
    /**     * The raw type is 'Environment'     */
    public environment: Environment;    
    /**     * The raw type is 'CameraAttributesPractical,CameraAttributesPhysical'     */
    public attributes: CameraAttributes;    
    /**     * The raw type is 'Compositor'     */
    public compositor: Compositor;    
    /**     * The raw type is 'float'     */
    public h_offset: number;    
    /**     * The raw type is 'float'     */
    public v_offset: number;    
    /**     * The raw type is 'int'     */
    public doppler_tracking: number;    
    /**     * The raw type is 'int'     */
    public projection: number;    
    /**     * The raw type is 'bool'     */
    public current: boolean;    
    /**     * The raw type is 'float'     */
    public fov: number;    
    /**     * The raw type is 'float'     */
    public size: number;    
    /**     * The raw type is 'Vector2'     */
    public frustum_offset: Vector2;    
    /**     * The raw type is 'float'     */
    public near: number;    
    /**     * The raw type is 'float'     */
    public far: number;
    public project_ray_normal(screenPoint: Vector2): Vector3;
    public project_local_ray_normal(screenPoint: Vector2): Vector3;
    public project_ray_origin(screenPoint: Vector2): Vector3;
    public unproject_position(worldPoint: Vector3): Vector2;
    public is_position_behind(worldPoint: Vector3): boolean;
    public project_position(screenPoint: Vector2, zDepth: number): Vector3;
    public set_perspective(fov: number, zNear: number, zFar: number): void;
    public set_orthogonal(size: number, zNear: number, zFar: number): void;
    public set_frustum(size: number, offset: Vector2, zNear: number, zFar: number): void;
    public make_current(): void;
    public clear_current(enableNext: boolean = true): void;
    public set_current(enabled: boolean): void;
    public is_current(): boolean;
    public get_camera_transform(): Transform3D;
    public get_camera_projection(): Projection;
    public get_fov(): number;
    public get_frustum_offset(): Vector2;
    public get_size(): number;
    public get_far(): number;
    public get_near(): number;
    public set_fov(fov: number): void;
    public set_frustum_offset(offset: Vector2): void;
    public set_size(size: number): void;
    public set_far(far: number): void;
    public set_near(near: number): void;
    public get_projection(): number;
    public set_projection(mode: number): void;
    public set_h_offset(offset: number): void;
    public get_h_offset(): number;
    public set_v_offset(offset: number): void;
    public get_v_offset(): number;
    public set_cull_mask(mask: number): void;
    public get_cull_mask(): number;
    public set_environment(env: Environment): void;
    public get_environment(): Environment;
    public set_attributes(env: CameraAttributes): void;
    public get_attributes(): CameraAttributes;
    public set_compositor(compositor: Compositor): void;
    public get_compositor(): Compositor;
    public set_keep_aspect_mode(mode: number): void;
    public get_keep_aspect_mode(): number;
    public set_doppler_tracking(mode: number): void;
    public get_doppler_tracking(): number;
    public get_frustum(): Array<any>;
    public is_position_in_frustum(worldPoint: Vector3): boolean;
    public get_camera_rid(): RID;
    public get_pyramid_shape_rid(): RID;
    public set_cull_mask_value(layerNumber: number, value: boolean): void;
    public get_cull_mask_value(layerNumber: number): boolean;


    public static readonly ProjectionType: {
        PROJECTION_PERSPECTIVE: 0;
        PROJECTION_ORTHOGONAL: 1;
        PROJECTION_FRUSTUM: 2;
    };
    public static readonly KeepAspect: {
        KEEP_WIDTH: 0;
        KEEP_HEIGHT: 1;
    };
    public static readonly DopplerTracking: {
        DOPPLER_TRACKING_DISABLED: 0;
        DOPPLER_TRACKING_IDLE_STEP: 1;
        DOPPLER_TRACKING_PHYSICS_STEP: 2;
    };
}

