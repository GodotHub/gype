import {Button} from "@godot/classes/button";
import {GodotClass, GodotSignal, to_promise} from "@godot/core/class_defined";

@GodotClass
export class Test extends Button {
  @GodotSignal
  private test_signal!: Signal;

  public async _enter_tree(): Promise<void> {
    await to_promise(this.test_signal);
    GD.print("Test signal");
  }

  public _ready(): void {
    this.test_signal.emit();
  }

  public _process(delta: number): void {
  }
}
