
import { EditorResourcePreviewGenerator } from "@godot/classes/editor_resource_preview_generator";
import { Object } from "@godot/classes/object";
import { Resource } from "@godot/classes/resource";
import { Node } from "@godot/classes/node";

export declare class EditorResourcePreview extends Node{
  public queue_resource_preview(_path: String, _receiver: Object, _receiver_func: StringName, _userdata: any): void;
  public queue_edited_resource_preview(_resource: Resource, _receiver: Object, _receiver_func: StringName, _userdata: any): void;
  public add_preview_generator(_generator: EditorResourcePreviewGenerator): void;
  public remove_preview_generator(_generator: EditorResourcePreviewGenerator): void;
  public check_for_invalidation(_path: String): void;
}