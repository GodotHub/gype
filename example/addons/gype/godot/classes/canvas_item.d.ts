
import type { CanvasItemMaterial } from '@godot/classes/canvas_item_material';
import type { CanvasLayer } from '@godot/classes/canvas_layer';
import type { Font } from '@godot/classes/font';
import type { InputEvent } from '@godot/classes/input_event';
import type { Material } from '@godot/classes/material';
import type { Mesh } from '@godot/classes/mesh';
import type { MultiMesh } from '@godot/classes/multi_mesh';
import type { Node } from '@godot/classes/node';
import type { StyleBox } from '@godot/classes/style_box';
import type { Texture2D } from '@godot/classes/texture2d';
import type { World2D } from '@godot/classes/world2d';


export declare class CanvasItem extends Node {

    
    /**     * The raw type is 'bool'     */
    public visible: boolean;    
    /**     * The raw type is 'Color'     */
    public modulate: Color;    
    /**     * The raw type is 'Color'     */
    public self_modulate: Color;    
    /**     * The raw type is 'bool'     */
    public show_behind_parent: boolean;    
    /**     * The raw type is 'bool'     */
    public top_level: boolean;    
    /**     * The raw type is 'int'     */
    public clip_children: number;    
    /**     * The raw type is 'int'     */
    public light_mask: number;    
    /**     * The raw type is 'int'     */
    public visibility_layer: number;    
    /**     * The raw type is 'int'     */
    public z_index: number;    
    /**     * The raw type is 'bool'     */
    public z_as_relative: boolean;    
    /**     * The raw type is 'bool'     */
    public y_sort_enabled: boolean;    
    /**     * The raw type is 'int'     */
    public texture_filter: number;    
    /**     * The raw type is 'int'     */
    public texture_repeat: number;    
    /**     * The raw type is 'CanvasItemMaterial,ShaderMaterial'     */
    public material: Material;    
    /**     * The raw type is 'bool'     */
    public use_parent_material: boolean;
    public _draw(): void;
    public get_canvas_item(): RID;
    public set_visible(visible: boolean): void;
    public is_visible(): boolean;
    public is_visible_in_tree(): boolean;
    public show(): void;
    public hide(): void;
    public queue_redraw(): void;
    public move_to_front(): void;
    public set_as_top_level(enable: boolean): void;
    public is_set_as_top_level(): boolean;
    public set_light_mask(lightMask: number): void;
    public get_light_mask(): number;
    public set_modulate(modulate: Color): void;
    public get_modulate(): Color;
    public set_self_modulate(selfModulate: Color): void;
    public get_self_modulate(): Color;
    public set_z_index(zIndex: number): void;
    public get_z_index(): number;
    public set_z_as_relative(enable: boolean): void;
    public is_z_relative(): boolean;
    public set_y_sort_enabled(enabled: boolean): void;
    public is_y_sort_enabled(): boolean;
    public set_draw_behind_parent(enable: boolean): void;
    public is_draw_behind_parent_enabled(): boolean;
    public draw_line(_from: Vector2, to: Vector2, color: Color, width: number = -1.0, antialiased: boolean = false): void;
    public draw_dashed_line(_from: Vector2, to: Vector2, color: Color, width: number = -1.0, dash: number = 2.0, aligned: boolean = true, antialiased: boolean = false): void;
    public draw_polyline(points: PackedVector2Array, color: Color, width: number = -1.0, antialiased: boolean = false): void;
    public draw_polyline_colors(points: PackedVector2Array, colors: PackedColorArray, width: number = -1.0, antialiased: boolean = false): void;
    public draw_arc(center: Vector2, radius: number, startAngle: number, endAngle: number, pointCount: number, color: Color, width: number = -1.0, antialiased: boolean = false): void;
    public draw_multiline(points: PackedVector2Array, color: Color, width: number = -1.0, antialiased: boolean = false): void;
    public draw_multiline_colors(points: PackedVector2Array, colors: PackedColorArray, width: number = -1.0, antialiased: boolean = false): void;
    public draw_rect(rect: Rect2, color: Color, filled: boolean = true, width: number = -1.0, antialiased: boolean = false): void;
    public draw_circle(position: Vector2, radius: number, color: Color, filled: boolean = true, width: number = -1.0, antialiased: boolean = false): void;
    public draw_texture(texture: Texture2D, position: Vector2, modulate: Color = Color(1, 1, 1, 1)): void;
    public draw_texture_rect(texture: Texture2D, rect: Rect2, tile: boolean, modulate: Color = Color(1, 1, 1, 1), transpose: boolean = false): void;
    public draw_texture_rect_region(texture: Texture2D, rect: Rect2, srcRect: Rect2, modulate: Color = Color(1, 1, 1, 1), transpose: boolean = false, cliuv: boolean = true): void;
    public draw_msdf_texture_rect_region(texture: Texture2D, rect: Rect2, srcRect: Rect2, modulate: Color = Color(1, 1, 1, 1), outline: number = 0.0, pixelRange: number = 4.0, scale: number = 1.0): void;
    public draw_lcd_texture_rect_region(texture: Texture2D, rect: Rect2, srcRect: Rect2, modulate: Color = Color(1, 1, 1, 1)): void;
    public draw_style_box(styleBox: StyleBox, rect: Rect2): void;
    public draw_primitive(points: PackedVector2Array, colors: PackedColorArray, uvs: PackedVector2Array, texture: Texture2D = null): void;
    public draw_polygon(points: PackedVector2Array, colors: PackedColorArray, uvs: PackedVector2Array = PackedVector2Array(), texture: Texture2D = null): void;
    public draw_colored_polygon(points: PackedVector2Array, color: Color, uvs: PackedVector2Array = PackedVector2Array(), texture: Texture2D = null): void;
    public draw_string(font: Font, pos: Vector2, text: GDString | StringName | string, alignment: number = 0, width: number = -1, fontSize: number = 16, modulate: Color = Color(1, 1, 1, 1), justificationFlags: number = 3, direction: number = 0, orientation: number = 0, oversampling: number = 0.0): void;
    public draw_multiline_string(font: Font, pos: Vector2, text: GDString | StringName | string, alignment: number = 0, width: number = -1, fontSize: number = 16, maxLines: number = -1, modulate: Color = Color(1, 1, 1, 1), brkFlags: number = 3, justificationFlags: number = 3, direction: number = 0, orientation: number = 0, oversampling: number = 0.0): void;
    public draw_string_outline(font: Font, pos: Vector2, text: GDString | StringName | string, alignment: number = 0, width: number = -1, fontSize: number = 16, size: number = 1, modulate: Color = Color(1, 1, 1, 1), justificationFlags: number = 3, direction: number = 0, orientation: number = 0, oversampling: number = 0.0): void;
    public draw_multiline_string_outline(font: Font, pos: Vector2, text: GDString | StringName | string, alignment: number = 0, width: number = -1, fontSize: number = 16, maxLines: number = -1, size: number = 1, modulate: Color = Color(1, 1, 1, 1), brkFlags: number = 3, justificationFlags: number = 3, direction: number = 0, orientation: number = 0, oversampling: number = 0.0): void;
    public draw_char(font: Font, pos: Vector2, char: GDString | StringName | string, fontSize: number = 16, modulate: Color = Color(1, 1, 1, 1), oversampling: number = 0.0): void;
    public draw_char_outline(font: Font, pos: Vector2, char: GDString | StringName | string, fontSize: number = 16, size: number = -1, modulate: Color = Color(1, 1, 1, 1), oversampling: number = 0.0): void;
    public draw_mesh(mesh: Mesh, texture: Texture2D, transform: Transform2D = Transform2D(1, 0, 0, 1, 0, 0), modulate: Color = Color(1, 1, 1, 1)): void;
    public draw_multimesh(multimesh: MultiMesh, texture: Texture2D): void;
    public draw_set_transform(position: Vector2, rotation: number = 0.0, scale: Vector2 = Vector2(1, 1)): void;
    public draw_set_transform_matrix(xform: Transform2D): void;
    public draw_animation_slice(animationLength: number, sliceBegin: number, sliceEnd: number, offset: number = 0.0): void;
    public draw_end_animation(): void;
    public get_transform(): Transform2D;
    public get_global_transform(): Transform2D;
    public get_global_transform_with_canvas(): Transform2D;
    public get_viewport_transform(): Transform2D;
    public get_viewport_rect(): Rect2;
    public get_canvas_transform(): Transform2D;
    public get_screen_transform(): Transform2D;
    public get_local_mouse_position(): Vector2;
    public get_global_mouse_position(): Vector2;
    public get_canvas(): RID;
    public get_canvas_layer_node(): CanvasLayer;
    public get_world_2d(): World2D;
    public set_material(material: Material): void;
    public get_material(): Material;
    public set_instance_shader_parameter(name: GDString | StringName | string, value: any): void;
    public get_instance_shader_parameter(name: GDString | StringName | string): any;
    public set_use_parent_material(enable: boolean): void;
    public get_use_parent_material(): boolean;
    public set_notify_local_transform(enable: boolean): void;
    public is_local_transform_notification_enabled(): boolean;
    public set_notify_transform(enable: boolean): void;
    public is_transform_notification_enabled(): boolean;
    public force_update_transform(): void;
    public make_canvas_position_local(viewportPoint: Vector2): Vector2;
    public make_input_local(event: InputEvent): InputEvent;
    public set_visibility_layer(layer: number): void;
    public get_visibility_layer(): number;
    public set_visibility_layer_bit(layer: number, enabled: boolean): void;
    public get_visibility_layer_bit(layer: number): boolean;
    public set_texture_filter(mode: number): void;
    public get_texture_filter(): number;
    public set_texture_repeat(mode: number): void;
    public get_texture_repeat(): number;
    public set_clip_children_mode(mode: number): void;
    public get_clip_children_mode(): number;

    
    public readonly draw: Signal<() => void>;
    public readonly visibility_changed: Signal<() => void>;
    public readonly hidden: Signal<() => void>;
    public readonly item_rect_changed: Signal<() => void>;

    public static readonly TextureFilter: {
        TEXTURE_FILTER_PARENT_NODE: 0;
        TEXTURE_FILTER_NEAREST: 1;
        TEXTURE_FILTER_LINEAR: 2;
        TEXTURE_FILTER_NEAREST_WITH_MIPMAPS: 3;
        TEXTURE_FILTER_LINEAR_WITH_MIPMAPS: 4;
        TEXTURE_FILTER_NEAREST_WITH_MIPMAPS_ANISOTROPIC: 5;
        TEXTURE_FILTER_LINEAR_WITH_MIPMAPS_ANISOTROPIC: 6;
        TEXTURE_FILTER_MAX: 7;
    };
    public static readonly TextureRepeat: {
        TEXTURE_REPEAT_PARENT_NODE: 0;
        TEXTURE_REPEAT_DISABLED: 1;
        TEXTURE_REPEAT_ENABLED: 2;
        TEXTURE_REPEAT_MIRROR: 3;
        TEXTURE_REPEAT_MAX: 4;
    };
    public static readonly ClipChildrenMode: {
        CLIP_CHILDREN_DISABLED: 0;
        CLIP_CHILDREN_ONLY: 1;
        CLIP_CHILDREN_AND_DRAW: 2;
        CLIP_CHILDREN_MAX: 3;
    };
}

