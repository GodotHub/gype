
import type { Font } from '@godot/classes/font';
import type { Resource } from '@godot/classes/resource';
import type { StyleBox } from '@godot/classes/style_box';
import type { Texture2D } from '@godot/classes/texture2d';


export declare class Theme extends Resource {

    
    /**     * The raw type is 'float'     */
    public default_base_scale: number;    
    /**     * The raw type is 'Font'     */
    public default_font: Font;    
    /**     * The raw type is 'int'     */
    public default_font_size: number;
    public set_icon(name: GDString | StringName | string, themeType: GDString | StringName | string, texture: Texture2D): void;
    public get_icon(name: GDString | StringName | string, themeType: GDString | StringName | string): Texture2D;
    public has_icon(name: GDString | StringName | string, themeType: GDString | StringName | string): boolean;
    public rename_icon(oldName: GDString | StringName | string, name: GDString | StringName | string, themeType: GDString | StringName | string): void;
    public clear_icon(name: GDString | StringName | string, themeType: GDString | StringName | string): void;
    public get_icon_list(themeType: GDString | StringName | string): PackedStringArray;
    public get_icon_type_list(): PackedStringArray;
    public set_stylebox(name: GDString | StringName | string, themeType: GDString | StringName | string, texture: StyleBox): void;
    public get_stylebox(name: GDString | StringName | string, themeType: GDString | StringName | string): StyleBox;
    public has_stylebox(name: GDString | StringName | string, themeType: GDString | StringName | string): boolean;
    public rename_stylebox(oldName: GDString | StringName | string, name: GDString | StringName | string, themeType: GDString | StringName | string): void;
    public clear_stylebox(name: GDString | StringName | string, themeType: GDString | StringName | string): void;
    public get_stylebox_list(themeType: GDString | StringName | string): PackedStringArray;
    public get_stylebox_type_list(): PackedStringArray;
    public set_font(name: GDString | StringName | string, themeType: GDString | StringName | string, font: Font): void;
    public get_font(name: GDString | StringName | string, themeType: GDString | StringName | string): Font;
    public has_font(name: GDString | StringName | string, themeType: GDString | StringName | string): boolean;
    public rename_font(oldName: GDString | StringName | string, name: GDString | StringName | string, themeType: GDString | StringName | string): void;
    public clear_font(name: GDString | StringName | string, themeType: GDString | StringName | string): void;
    public get_font_list(themeType: GDString | StringName | string): PackedStringArray;
    public get_font_type_list(): PackedStringArray;
    public set_font_size(name: GDString | StringName | string, themeType: GDString | StringName | string, fontSize: number): void;
    public get_font_size(name: GDString | StringName | string, themeType: GDString | StringName | string): number;
    public has_font_size(name: GDString | StringName | string, themeType: GDString | StringName | string): boolean;
    public rename_font_size(oldName: GDString | StringName | string, name: GDString | StringName | string, themeType: GDString | StringName | string): void;
    public clear_font_size(name: GDString | StringName | string, themeType: GDString | StringName | string): void;
    public get_font_size_list(themeType: GDString | StringName | string): PackedStringArray;
    public get_font_size_type_list(): PackedStringArray;
    public set_color(name: GDString | StringName | string, themeType: GDString | StringName | string, color: Color): void;
    public get_color(name: GDString | StringName | string, themeType: GDString | StringName | string): Color;
    public has_color(name: GDString | StringName | string, themeType: GDString | StringName | string): boolean;
    public rename_color(oldName: GDString | StringName | string, name: GDString | StringName | string, themeType: GDString | StringName | string): void;
    public clear_color(name: GDString | StringName | string, themeType: GDString | StringName | string): void;
    public get_color_list(themeType: GDString | StringName | string): PackedStringArray;
    public get_color_type_list(): PackedStringArray;
    public set_constant(name: GDString | StringName | string, themeType: GDString | StringName | string, constant: number): void;
    public get_constant(name: GDString | StringName | string, themeType: GDString | StringName | string): number;
    public has_constant(name: GDString | StringName | string, themeType: GDString | StringName | string): boolean;
    public rename_constant(oldName: GDString | StringName | string, name: GDString | StringName | string, themeType: GDString | StringName | string): void;
    public clear_constant(name: GDString | StringName | string, themeType: GDString | StringName | string): void;
    public get_constant_list(themeType: GDString | StringName | string): PackedStringArray;
    public get_constant_type_list(): PackedStringArray;
    public set_default_base_scale(baseScale: number): void;
    public get_default_base_scale(): number;
    public has_default_base_scale(): boolean;
    public set_default_font(font: Font): void;
    public get_default_font(): Font;
    public has_default_font(): boolean;
    public set_default_font_size(fontSize: number): void;
    public get_default_font_size(): number;
    public has_default_font_size(): boolean;
    public set_theme_item(dataType: number, name: GDString | StringName | string, themeType: GDString | StringName | string, value: any): void;
    public get_theme_item(dataType: number, name: GDString | StringName | string, themeType: GDString | StringName | string): any;
    public has_theme_item(dataType: number, name: GDString | StringName | string, themeType: GDString | StringName | string): boolean;
    public rename_theme_item(dataType: number, oldName: GDString | StringName | string, name: GDString | StringName | string, themeType: GDString | StringName | string): void;
    public clear_theme_item(dataType: number, name: GDString | StringName | string, themeType: GDString | StringName | string): void;
    public get_theme_item_list(dataType: number, themeType: GDString | StringName | string): PackedStringArray;
    public get_theme_item_type_list(dataType: number): PackedStringArray;
    public set_type_variation(themeType: GDString | StringName | string, baseType: GDString | StringName | string): void;
    public is_type_variation(themeType: GDString | StringName | string, baseType: GDString | StringName | string): boolean;
    public clear_type_variation(themeType: GDString | StringName | string): void;
    public get_type_variation_base(themeType: GDString | StringName | string): StringName;
    public get_type_variation_list(baseType: GDString | StringName | string): PackedStringArray;
    public add_type(themeType: GDString | StringName | string): void;
    public remove_type(themeType: GDString | StringName | string): void;
    public rename_type(oldThemeType: GDString | StringName | string, themeType: GDString | StringName | string): void;
    public get_type_list(): PackedStringArray;
    public merge_with(other: Theme): void;
    public clear(): void;


    public static readonly DataType: {
        DATA_TYPE_COLOR: 0;
        DATA_TYPE_CONSTANT: 1;
        DATA_TYPE_FONT: 2;
        DATA_TYPE_FONT_SIZE: 3;
        DATA_TYPE_ICON: 4;
        DATA_TYPE_STYLEBOX: 5;
        DATA_TYPE_MAX: 6;
    };
}

