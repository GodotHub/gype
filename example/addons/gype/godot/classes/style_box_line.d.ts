
import type { StyleBox } from '@godot/classes/style_box';


export declare class StyleBoxLine extends StyleBox {

    
    /**     * The raw type is 'Color'     */
    public color: Color;    
    /**     * The raw type is 'float'     */
    public grow_begin: number;    
    /**     * The raw type is 'float'     */
    public grow_end: number;    
    /**     * The raw type is 'int'     */
    public thickness: number;    
    /**     * The raw type is 'bool'     */
    public vertical: boolean;
    public set_color(color: Color): void;
    public get_color(): Color;
    public set_thickness(thickness: number): void;
    public get_thickness(): number;
    public set_grow_begin(offset: number): void;
    public get_grow_begin(): number;
    public set_grow_end(offset: number): void;
    public get_grow_end(): number;
    public set_vertical(vertical: boolean): void;
    public is_vertical(): boolean;


}

