
import { OpenXRAction } from "@godot/classes/open_xr_action";
import { Resource } from "@godot/classes/resource";

export declare class OpenXRActionSet extends Resource{
  public set_localized_name(_localized_name: String): void;
  public get_localized_name(): String;
  public set_priority(_priority: number): void;
  public get_priority(): number;
  public get_action_count(): number;
  public set_actions(_actions: GDArray): void;
  public get_actions(): GDArray;
  public add_action(_action: OpenXRAction): void;
  public remove_action(_action: OpenXRAction): void;
  public get localized_name(): String {
    get_localized_name();
  }
  public set localized_name(value): void {
    set_localized_name(value);
  }
  public get priority(): number {
    get_priority();
  }
  public set priority(value): void {
    set_priority(value);
  }
  public get actions(): OpenXRAction {
    get_actions();
  }
  public set actions(value): void {
    set_actions(value);
  }
}