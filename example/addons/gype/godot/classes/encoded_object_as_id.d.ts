
import { RefCounted } from "@godot/classes/ref_counted";

export declare class EncodedObjectAsID extends RefCounted{
  public set_object_id(_id: number): void;
  public get_object_id(): number;
  public get object_id(): number {
    get_object_id();
  }
  public set object_id(value): void {
    set_object_id(value);
  }
}