
import { RefCounted } from "@godot/classes/ref_counted";

export declare class EditorTranslationParserPlugin extends RefCounted{
  public _parse_file(_path: String, _msgids: GDArray, _msgids_context_plural: GDArray): void;
  public _get_recognized_extensions(): PackedStringArray;
}