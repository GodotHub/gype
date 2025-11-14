
import type { StaticBody3D } from '@godot/classes/static_body3d';


export declare class AnimatableBody3D extends StaticBody3D {

    
    /**     * The raw type is 'bool'     */
    public sync_to_physics: boolean;
    public set_sync_to_physics(enable: boolean): void;
    public is_sync_to_physics_enabled(): boolean;


}

