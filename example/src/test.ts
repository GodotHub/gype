import { Button } from "@godot/classes/button";
import { GodotClass, to_promise } from "@godot/core/class_defined";
import * as os from "os";

@GodotClass
export class test extends Button {
  public test() {}

  public _enter_tree(): void {}

  public _ready(): void {
	os.setTimeout(() => {}, 0);
  }

  public _process(delta: number): void {}
}
