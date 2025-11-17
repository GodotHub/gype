import {Button} from "@godot/classes/button";
import {GodotClass, GodotSignal, to_promise} from "@godot/core/class_defined";
import {Node} from "@godot/classes/node";

@GodotClass
export class Test extends Button {

  @GodotSignal({
    name: "content",
    type: Variant.Type.STRING
  })
  private test_signal!: Signal;

  public _enter_tree(): void {
    this.test_signal.connect((content: string) => {
      GD.print(content);
    });
  }

  public _ready(): void {
    this.test_signal.emit("Hello World!");
  }

  public _process(delta: number): void {
  }
}
