import { Node2D } from "@godot/classes/node2d";
import { GodotClass } from "@godot/core/class_defined";

@GodotClass
export class new_script extends Node2D {
  public _ready(): void {
    let callable = new Callable(this, this.test);
    callable.call();
  }

  public _process(delta: number): void {}

  public test() {
    GD.print("test");
  }
}
