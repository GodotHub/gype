
import type { Container } from '@godot/classes/container';


export declare class GraphElement extends Container {

    
    /**     * The raw type is 'Vector2'     */
    public position_offset: Vector2;    
    /**     * The raw type is 'bool'     */
    public resizable: boolean;    
    /**     * The raw type is 'bool'     */
    public draggable: boolean;    
    /**     * The raw type is 'bool'     */
    public selectable: boolean;    
    /**     * The raw type is 'bool'     */
    public selected: boolean;
    public set_resizable(resizable: boolean): void;
    public is_resizable(): boolean;
    public set_draggable(draggable: boolean): void;
    public is_draggable(): boolean;
    public set_selectable(selectable: boolean): void;
    public is_selectable(): boolean;
    public set_selected(selected: boolean): void;
    public is_selected(): boolean;
    public set_position_offset(offset: Vector2): void;
    public get_position_offset(): Vector2;

    
    public readonly node_selected: Signal;
    public readonly node_deselected: Signal;
    public readonly raise_request: Signal;
    public readonly delete_request: Signal;
    public readonly resize_request: Signal;
    public readonly resize_end: Signal;
    public readonly dragged: Signal;
    public readonly position_offset_changed: Signal;

}

