
import type { RefCounted } from '@godot/classes/ref_counted';
import type { Resource } from '@godot/classes/resource';


export declare class ResourceFormatSaver extends RefCounted {


    public _save(resource: Resource, path: GDString | StringName | string, flags: number): number;
    public _set_uid(path: GDString | StringName | string, uid: number): number;
    public _recognize(resource: Resource): boolean;
    public _get_recognized_extensions(resource: Resource): PackedStringArray;
    public _recognize_path(resource: Resource, path: GDString | StringName | string): boolean;


}

