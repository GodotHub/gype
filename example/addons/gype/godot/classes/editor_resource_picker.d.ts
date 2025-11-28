
import type { GodotObject } from '@godot/classes/godot_object';
import type { HBoxContainer } from '@godot/classes/h_box_container';
import type { Resource } from '@godot/classes/resource';


export declare class EditorResourcePicker extends HBoxContainer {

    
    /**     * The raw type is 'String'     */
    public base_type: GDString | StringName | string;    
    /**     * The raw type is 'Resource'     */
    public edited_resource: Resource;    
    /**     * The raw type is 'bool'     */
    public editable: boolean;    
    /**     * The raw type is 'bool'     */
    public toggle_mode: boolean;
    public _set_create_options(menuNode: GodotObject): void;
    public _handle_menu_selected(id: number): boolean;
    public set_base_type(baseType: GDString | StringName | string): void;
    public get_base_type(): GDString;
    public get_allowed_types(): PackedStringArray;
    public set_edited_resource(resource: Resource): void;
    public get_edited_resource(): Resource;
    public set_toggle_mode(enable: boolean): void;
    public is_toggle_mode(): boolean;
    public set_toggle_pressed(pressed: boolean): void;
    public set_editable(enable: boolean): void;
    public is_editable(): boolean;

    
    public readonly resource_selected: Signal;
    public readonly resource_changed: Signal;

}

