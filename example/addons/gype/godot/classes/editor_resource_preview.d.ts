
import type { EditorResourcePreviewGenerator } from '@godot/classes/editor_resource_preview_generator';
import type { GDString } from '@godot/builtins/gd_string';
import type { GodotObject } from '@godot/classes/godot_object';
import type { Node } from '@godot/classes/node';
import type { Resource } from '@godot/classes/resource';
import type { Signal } from '@godot/builtins/signal';
import type { StringName } from '@godot/builtins/string_name';


export declare class EditorResourcePreview extends Node {


    public queue_resource_preview(path: GDString | StringName | string, receiver: GodotObject, receiverFunc: GDString | StringName | string, userdata: any): void;
    public queue_edited_resource_preview(resource: Resource, receiver: GodotObject, receiverFunc: GDString | StringName | string, userdata: any): void;
    public add_preview_generator(generator: EditorResourcePreviewGenerator): void;
    public remove_preview_generator(generator: EditorResourcePreviewGenerator): void;
    public check_for_invalidation(path: GDString | StringName | string): void;

    
    public readonly preview_invalidated: Signal<(path: GDString | StringName | string) => void>;

}

