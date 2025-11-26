
import type { CameraAttributes } from '@godot/classes/camera_attributes';
import type { CameraAttributesPractical } from '@godot/classes/camera_attributes_practical';
import type { Environment } from '@godot/classes/environment';
import type { PhysicsDirectSpaceState3D } from '@godot/classes/physics_direct_space_state3d';
import type { Resource } from '@godot/classes/resource';


export declare class World3D extends Resource {

    
    /**     * The raw type is 'Environment'     */
    public environment: Environment;    
    /**     * The raw type is 'Environment'     */
    public fallback_environment: Environment;    
    /**     * The raw type is 'CameraAttributesPractical,CameraAttributesPhysical'     */
    public camera_attributes: CameraAttributes;    
    /**     * The raw type is 'RID'     */
    public space: RID;    
    /**     * The raw type is 'RID'     */
    public navigation_map: RID;    
    /**     * The raw type is 'RID'     */
    public scenario: RID;    
    /**     * The raw type is 'PhysicsDirectSpaceState3D'     */
    public direct_space_state: PhysicsDirectSpaceState3D;
    public get_space(): RID;
    public get_navigation_map(): RID;
    public get_scenario(): RID;
    public set_environment(env: Environment): void;
    public get_environment(): Environment;
    public set_fallback_environment(env: Environment): void;
    public get_fallback_environment(): Environment;
    public set_camera_attributes(attributes: CameraAttributes): void;
    public get_camera_attributes(): CameraAttributes;
    public get_direct_space_state(): PhysicsDirectSpaceState3D;


}

