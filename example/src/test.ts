import { Node2D } from "@godot/classes/node2d";
import { GodotClass } from "@godot/core/class_defined";

@GodotClass
export class test extends Node2D {
  public _ready(): void {
    this.position = new Vector2(0, 0);
    this.move_to(new Vector2(10, 10));
  }

  public _process(delta: number): void {}

  public move_to(pos: Vector2): void {
    GD.print(pos);
  }
}
