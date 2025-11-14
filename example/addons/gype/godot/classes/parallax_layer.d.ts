
import type { Node2D } from '@godot/classes/node2d';
import type { Vector2 } from '@godot/builtins/vector2';


export declare class ParallaxLayer extends Node2D {

    
    /**     * The raw type is 'Vector2'     */
    public motion_scale: Vector2;    
    /**     * The raw type is 'Vector2'     */
    public motion_offset: Vector2;    
    /**     * The raw type is 'Vector2'     */
    public motion_mirroring: Vector2;
    public set_motion_scale(scale: Vector2): void;
    public get_motion_scale(): Vector2;
    public set_motion_offset(offset: Vector2): void;
    public get_motion_offset(): Vector2;
    public set_mirroring(mirror: Vector2): void;
    public get_mirroring(): Vector2;


}

