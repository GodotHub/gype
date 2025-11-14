
import type { Color } from '@godot/builtins/color';
import type { Control } from '@godot/classes/control';


export declare class ReferenceRect extends Control {

    
    /**     * The raw type is 'Color'     */
    public border_color: Color;    
    /**     * The raw type is 'float'     */
    public border_width: number;    
    /**     * The raw type is 'bool'     */
    public editor_only: boolean;
    public get_border_color(): Color;
    public set_border_color(color: Color): void;
    public get_border_width(): number;
    public set_border_width(width: number): void;
    public get_editor_only(): boolean;
    public set_editor_only(enabled: boolean): void;


}

