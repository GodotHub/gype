
import { RefCounted } from "@godot/classes/ref_counted";

export declare class RegExMatch extends RefCounted{
  public get_subject(): String;
  public get_group_count(): number;
  public get_names(): Dictionary;
  public get_strings(): PackedStringArray;
  public get_string(_name: any): String;
  public get_start(_name: any): number;
  public get_end(_name: any): number;
  public get subject(): String {
    get_subject();
  }
  public get names(): Dictionary {
    get_names();
  }
  public get strings(): GDArray {
    get_strings();
  }
}