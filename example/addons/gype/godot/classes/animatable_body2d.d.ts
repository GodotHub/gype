
import type { StaticBody2D } from '@godot/classes/static_body2d';


export declare class AnimatableBody2D extends StaticBody2D {

    
    /**     * The raw type is 'bool'     */
    public sync_to_physics: boolean;
    public set_sync_to_physics(enable: boolean): void;
    public is_sync_to_physics_enabled(): boolean;


}

