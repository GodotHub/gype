
import type { Color } from '@godot/builtins/color';
import type { Node3D } from '@godot/classes/node3d';
import type { Resource } from '@godot/classes/resource';
import type { Shape3D } from '@godot/classes/shape3d';


export declare class CollisionShape3D extends Node3D {

    
    /**     * The raw type is 'Shape3D'     */
    public shape: Shape3D;    
    /**     * The raw type is 'bool'     */
    public disabled: boolean;    
    /**     * The raw type is 'Color'     */
    public debug_color: Color;    
    /**     * The raw type is 'bool'     */
    public debug_fill: boolean;
    public resource_changed(resource: Resource): void;
    public set_shape(shape: Shape3D): void;
    public get_shape(): Shape3D;
    public set_disabled(enable: boolean): void;
    public is_disabled(): boolean;
    public make_convex_from_siblings(): void;
    public set_debug_color(color: Color): void;
    public get_debug_color(): Color;
    public set_enable_debug_fill(enable: boolean): void;
    public get_enable_debug_fill(): boolean;


}

