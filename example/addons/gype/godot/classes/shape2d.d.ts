
import type { Color } from '@godot/builtins/color';
import type { PackedVector2Array } from '@godot/builtins/packed_vector2_array';
import type { RID } from '@godot/builtins/rid';
import type { Rect2 } from '@godot/builtins/rect2';
import type { Resource } from '@godot/classes/resource';
import type { Transform2D } from '@godot/builtins/transform2d';
import type { Vector2 } from '@godot/builtins/vector2';


export declare class Shape2D extends Resource {

    
    /**     * The raw type is 'float'     */
    public custom_solver_bias: number;
    public set_custom_solver_bias(bias: number): void;
    public get_custom_solver_bias(): number;
    public collide(localXform: Transform2D, withShape: Shape2D, shapeXform: Transform2D): boolean;
    public collide_with_motion(localXform: Transform2D, localMotion: Vector2, withShape: Shape2D, shapeXform: Transform2D, shapeMotion: Vector2): boolean;
    public collide_and_get_contacts(localXform: Transform2D, withShape: Shape2D, shapeXform: Transform2D): PackedVector2Array;
    public collide_with_motion_and_get_contacts(localXform: Transform2D, localMotion: Vector2, withShape: Shape2D, shapeXform: Transform2D, shapeMotion: Vector2): PackedVector2Array;
    public draw(canvasItem: RID, color: Color): void;
    public get_rect(): Rect2;


}

