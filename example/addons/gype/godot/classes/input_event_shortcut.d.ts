
import { Shortcut } from "@godot/classes/shortcut";
import { InputEvent } from "@godot/classes/input_event";

export declare class InputEventShortcut extends InputEvent{
  public set_shortcut(_shortcut: Shortcut): void;
  public get_shortcut(): Shortcut;
  public get shortcut(): Shortcut {
    get_shortcut();
  }
  public set shortcut(value): void {
    set_shortcut(value);
  }
}