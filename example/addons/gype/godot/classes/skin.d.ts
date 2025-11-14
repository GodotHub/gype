
import type { GDString } from '@godot/builtins/gd_string';
import type { Resource } from '@godot/classes/resource';
import type { StringName } from '@godot/builtins/string_name';
import type { Transform3D } from '@godot/builtins/transform3d';


export declare class Skin extends Resource {


    public set_bind_count(bindCount: number): void;
    public get_bind_count(): number;
    public add_bind(bone: number, pose: Transform3D): void;
    public add_named_bind(name: GDString | StringName | string, pose: Transform3D): void;
    public set_bind_pose(bindIndex: number, pose: Transform3D): void;
    public get_bind_pose(bindIndex: number): Transform3D;
    public set_bind_name(bindIndex: number, name: GDString | StringName | string): void;
    public get_bind_name(bindIndex: number): StringName;
    public set_bind_bone(bindIndex: number, bone: number): void;
    public get_bind_bone(bindIndex: number): number;
    public clear_binds(): void;


}

