
import type { Color } from '@godot/builtins/color';
import type { NodePath } from '@godot/builtins/node_path';
import type { VisualInstance3D } from '@godot/classes/visual_instance3d';


export declare class RootMotionView extends VisualInstance3D {

    
    /**     * The raw type is 'NodePath'     */
    public animation_path: NodePath;    
    /**     * The raw type is 'Color'     */
    public color: Color;    
    /**     * The raw type is 'float'     */
    public cell_size: number;    
    /**     * The raw type is 'float'     */
    public radius: number;    
    /**     * The raw type is 'bool'     */
    public zero_y: boolean;
    public set_animation_path(path: NodePath | GDString | string): void;
    public get_animation_path(): NodePath;
    public set_color(color: Color): void;
    public get_color(): Color;
    public set_cell_size(size: number): void;
    public get_cell_size(): number;
    public set_radius(size: number): void;
    public get_radius(): number;
    public set_zero_y(enable: boolean): void;
    public get_zero_y(): boolean;


}

