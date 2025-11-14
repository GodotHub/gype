
import type { CameraAttributes } from '@godot/classes/camera_attributes';
import type { CameraAttributesPractical } from '@godot/classes/camera_attributes_practical';
import type { Compositor } from '@godot/classes/compositor';
import type { Environment } from '@godot/classes/environment';
import type { Node } from '@godot/classes/node';


export declare class WorldEnvironment extends Node {

    
    /**     * The raw type is 'Environment'     */
    public environment: Environment;    
    /**     * The raw type is 'CameraAttributesPractical,CameraAttributesPhysical'     */
    public camera_attributes: CameraAttributes;    
    /**     * The raw type is 'Compositor'     */
    public compositor: Compositor;
    public set_environment(env: Environment): void;
    public get_environment(): Environment;
    public set_camera_attributes(cameraAttributes: CameraAttributes): void;
    public get_camera_attributes(): CameraAttributes;
    public set_compositor(compositor: Compositor): void;
    public get_compositor(): Compositor;


}

