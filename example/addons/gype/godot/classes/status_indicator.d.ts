
import type { GDString } from '@godot/builtins/gd_string';
import type { Node } from '@godot/classes/node';
import type { NodePath } from '@godot/builtins/node_path';
import type { Rect2 } from '@godot/builtins/rect2';
import type { Signal } from '@godot/builtins/signal';
import type { Texture2D } from '@godot/classes/texture2d';
import type { Vector2i } from '@godot/builtins/vector2i';


export declare class StatusIndicator extends Node {

    
    /**     * The raw type is 'String'     */
    public tooltip: GDString;    
    /**     * The raw type is 'Texture2D'     */
    public icon: Texture2D;    
    /**     * The raw type is 'NodePath'     */
    public menu: NodePath;    
    /**     * The raw type is 'bool'     */
    public visible: boolean;
    public set_tooltip(tooltip: GDString | StringName | string): void;
    public get_tooltip(): GDString;
    public set_icon(texture: Texture2D): void;
    public get_icon(): Texture2D;
    public set_visible(visible: boolean): void;
    public is_visible(): boolean;
    public set_menu(menu: NodePath | GDString | string): void;
    public get_menu(): NodePath;
    public get_rect(): Rect2;

    
    public readonly pressed: Signal<(mouseButton: number, mousePosition: Vector2i) => void>;

}

