
import type { RefCounted } from '@godot/classes/ref_counted';
import type { Resource } from '@godot/classes/resource';
import type { Texture2D } from '@godot/classes/texture2d';


export declare class EditorResourcePreviewGenerator extends RefCounted {


    public _handles(_type: GDString | StringName | string): boolean;
    public _generate(resource: Resource, size: Vector2i, metadata: Dictionary): Texture2D;
    public _generate_from_path(path: GDString | StringName | string, size: Vector2i, metadata: Dictionary): Texture2D;
    public _generate_small_preview_automatically(): boolean;
    public _can_generate_small_preview(): boolean;


}

