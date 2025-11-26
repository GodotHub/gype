
import type { VisualShaderNodeResizableBase } from '@godot/classes/visual_shader_node_resizable_base';


export declare class VisualShaderNodeFrame extends VisualShaderNodeResizableBase {

    
    /**     * The raw type is 'String'     */
    public title: GDString;    
    /**     * The raw type is 'bool'     */
    public tint_color_enabled: boolean;    
    /**     * The raw type is 'Color'     */
    public tint_color: Color;    
    /**     * The raw type is 'bool'     */
    public autoshrink: boolean;    
    /**     * The raw type is 'PackedInt32Array'     */
    public attached_nodes: PackedInt32Array;
    public set_title(title: GDString | StringName | string): void;
    public get_title(): GDString;
    public set_tint_color_enabled(enable: boolean): void;
    public is_tint_color_enabled(): boolean;
    public set_tint_color(color: Color): void;
    public get_tint_color(): Color;
    public set_autoshrink_enabled(enable: boolean): void;
    public is_autoshrink_enabled(): boolean;
    public add_attached_node(node: number): void;
    public remove_attached_node(node: number): void;
    public set_attached_nodes(attachedNodes: PackedInt32Array): void;
    public get_attached_nodes(): PackedInt32Array;


}

