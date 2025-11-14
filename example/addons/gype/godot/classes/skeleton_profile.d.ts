
import type { GDString } from '@godot/builtins/gd_string';
import type { Resource } from '@godot/classes/resource';
import type { Signal } from '@godot/builtins/signal';
import type { StringName } from '@godot/builtins/string_name';
import type { Texture2D } from '@godot/classes/texture2d';
import type { Transform3D } from '@godot/builtins/transform3d';
import type { Vector2 } from '@godot/builtins/vector2';


export declare class SkeletonProfile extends Resource {

    
    /**     * The raw type is 'StringName'     */
    public root_bone: StringName;    
    /**     * The raw type is 'StringName'     */
    public scale_base_bone: StringName;    
    /**     * The raw type is 'int'     */
    public group_size: number;    
    /**     * The raw type is 'int'     */
    public bone_size: number;
    public set_root_bone(boneName: GDString | StringName | string): void;
    public get_root_bone(): StringName;
    public set_scale_base_bone(boneName: GDString | StringName | string): void;
    public get_scale_base_bone(): StringName;
    public set_group_size(size: number): void;
    public get_group_size(): number;
    public get_group_name(grouidx: number): StringName;
    public set_group_name(grouidx: number, grouname: GDString | StringName | string): void;
    public get_texture(grouidx: number): Texture2D;
    public set_texture(grouidx: number, texture: Texture2D): void;
    public set_bone_size(size: number): void;
    public get_bone_size(): number;
    public find_bone(boneName: GDString | StringName | string): number;
    public get_bone_name(boneIdx: number): StringName;
    public set_bone_name(boneIdx: number, boneName: GDString | StringName | string): void;
    public get_bone_parent(boneIdx: number): StringName;
    public set_bone_parent(boneIdx: number, boneParent: GDString | StringName | string): void;
    public get_tail_direction(boneIdx: number): number;
    public set_tail_direction(boneIdx: number, tailDirection: number): void;
    public get_bone_tail(boneIdx: number): StringName;
    public set_bone_tail(boneIdx: number, boneTail: GDString | StringName | string): void;
    public get_reference_pose(boneIdx: number): Transform3D;
    public set_reference_pose(boneIdx: number, boneName: Transform3D): void;
    public get_handle_offset(boneIdx: number): Vector2;
    public set_handle_offset(boneIdx: number, handleOffset: Vector2): void;
    public get_group(boneIdx: number): StringName;
    public set_group(boneIdx: number, group: GDString | StringName | string): void;
    public is_required(boneIdx: number): boolean;
    public set_required(boneIdx: number, required: boolean): void;

    
    public readonly profile_updated: Signal<() => void>;

    public static readonly TailDirection: {
        TAIL_DIRECTION_AVERAGE_CHILDREN: 0;
        TAIL_DIRECTION_SPECIFIC_CHILD: 1;
        TAIL_DIRECTION_END: 2;
    };
}

