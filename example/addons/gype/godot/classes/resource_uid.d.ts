
import type { GodotObject } from '@godot/classes/godot_object';


export declare class _ResourceUID extends GodotObject {


    public id_to_text(id: number): GDString;
    public text_to_id(textId: GDString | StringName | string): number;
    public create_id(): number;
    public create_id_for_path(path: GDString | StringName | string): number;
    public has_id(id: number): boolean;
    public add_id(id: number, path: GDString | StringName | string): void;
    public set_id(id: number, path: GDString | StringName | string): void;
    public get_id_path(id: number): GDString;
    public remove_id(id: number): void;
    public static uid_to_path(uid: GDString | StringName | string): GDString;
    public static path_to_uid(path: GDString | StringName | string): GDString;
    public static ensure_path(pathOrUid: GDString | StringName | string): GDString;


}

declare global {
    const ResourceUID: _ResourceUID
}
