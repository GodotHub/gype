
import type { Container } from '@godot/classes/container';
import type { Control } from '@godot/classes/control';
import type { GDArray } from '@godot/builtins/gd_array';
import type { GDString } from '@godot/builtins/gd_string';
import type { GodotObject } from '@godot/classes/godot_object';
import type { PackedStringArray } from '@godot/builtins/packed_string_array';
import type { Resource } from '@godot/classes/resource';
import type { Signal } from '@godot/builtins/signal';
import type { StringName } from '@godot/builtins/string_name';


export declare class EditorProperty extends Container {

    
    /**     * The raw type is 'String'     */
    public label: GDString;    
    /**     * The raw type is 'bool'     */
    public read_only: boolean;    
    /**     * The raw type is 'bool'     */
    public draw_label: boolean;    
    /**     * The raw type is 'bool'     */
    public draw_background: boolean;    
    /**     * The raw type is 'bool'     */
    public checkable: boolean;    
    /**     * The raw type is 'bool'     */
    public checked: boolean;    
    /**     * The raw type is 'bool'     */
    public draw_warning: boolean;    
    /**     * The raw type is 'bool'     */
    public keying: boolean;    
    /**     * The raw type is 'bool'     */
    public deletable: boolean;    
    /**     * The raw type is 'bool'     */
    public selectable: boolean;    
    /**     * The raw type is 'bool'     */
    public use_folding: boolean;    
    /**     * The raw type is 'float'     */
    public name_split_ratio: number;
    public _update_property(): void;
    public _set_read_only(readOnly: boolean): void;
    public set_label(text: GDString | StringName | string): void;
    public get_label(): GDString;
    public set_read_only(readOnly: boolean): void;
    public is_read_only(): boolean;
    public set_draw_label(drawLabel: boolean): void;
    public is_draw_label(): boolean;
    public set_draw_background(drawBackground: boolean): void;
    public is_draw_background(): boolean;
    public set_checkable(checkable: boolean): void;
    public is_checkable(): boolean;
    public set_checked(checked: boolean): void;
    public is_checked(): boolean;
    public set_draw_warning(drawWarning: boolean): void;
    public is_draw_warning(): boolean;
    public set_keying(keying: boolean): void;
    public is_keying(): boolean;
    public set_deletable(deletable: boolean): void;
    public is_deletable(): boolean;
    public get_edited_property(): StringName;
    public get_edited_object(): GodotObject;
    public update_property(): void;
    public add_focusable(control: Control): void;
    public set_bottom_editor(editor: Control): void;
    public set_selectable(selectable: boolean): void;
    public is_selectable(): boolean;
    public set_use_folding(useFolding: boolean): void;
    public is_using_folding(): boolean;
    public set_name_split_ratio(ratio: number): void;
    public get_name_split_ratio(): number;
    public deselect(): void;
    public is_selected(): boolean;
    public select(focusable: number = -1): void;
    public set_object_and_property(object: GodotObject, property: GDString | StringName | string): void;
    public set_label_reference(control: Control): void;
    public emit_changed(property: GDString | StringName | string, value: any, field: GDString | StringName | string = "", changing: boolean = false): void;

    
    public readonly property_changed: Signal<(property: GDString | StringName | string, value: any, field: GDString | StringName | string, changing: boolean) => void>;
    public readonly multiple_properties_changed: Signal<(properties: PackedStringArray, value: GDArray) => void>;
    public readonly property_keyed: Signal<(property: GDString | StringName | string) => void>;
    public readonly property_deleted: Signal<(property: GDString | StringName | string) => void>;
    public readonly property_keyed_with_value: Signal<(property: GDString | StringName | string, value: any) => void>;
    public readonly property_checked: Signal<(property: GDString | StringName | string, checked: boolean) => void>;
    public readonly property_overridden: Signal<() => void>;
    public readonly property_favorited: Signal<(property: GDString | StringName | string, favorited: boolean) => void>;
    public readonly property_pinned: Signal<(property: GDString | StringName | string, pinned: boolean) => void>;
    public readonly property_can_revert_changed: Signal<(property: GDString | StringName | string, canRevert: boolean) => void>;
    public readonly resource_selected: Signal<(path: GDString | StringName | string, resource: Resource) => void>;
    public readonly object_id_selected: Signal<(property: GDString | StringName | string, id: number) => void>;
    public readonly selected: Signal<(path: GDString | StringName | string, focusableIdx: number) => void>;

}

