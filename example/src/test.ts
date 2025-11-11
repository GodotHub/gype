import { Button } from "@godot/classes/button";
import { GodotClass, to_promise } from "@godot/core/class_defined";

@GodotClass
export class test extends Button {
  public test() {}

  public _enter_tree(): void {}

  public async _ready(): Promise<void> {
    await new Promise((resolve, reject) => {
      resolve("hello");
    }).then((res) => {
      GD.print(res);
    });
  }

  public _process(delta: number): void {}
}
