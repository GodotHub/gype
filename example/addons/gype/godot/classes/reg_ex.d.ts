
import { RefCounted } from "@godot/classes/ref_counted";
import { RegExMatch } from "@godot/classes/reg_ex_match";
import { RegExMatch } from "@godot/classes/reg_ex_match";

export declare class RegEx extends RefCounted{
  public create_from_string(_pattern: String): RegEx;
  public clear(): void;
  public compile(_pattern: String): number;
  public search(_subject: String, _offset: number, _end: number): RegExMatch;
  public search_all(_subject: String, _offset: number, _end: number): GDArray;
  public sub(_subject: String, _replacement: String, _all: boolean, _offset: number, _end: number): String;
  public is_valid(): boolean;
  public get_pattern(): String;
  public get_group_count(): number;
  public get_names(): PackedStringArray;
}