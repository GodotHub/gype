import { Node2D } from "@godot/classes/node2d";
import { GodotClass } from "@godot/core/class_defined";

@GodotClass
export class Game extends Node2D {
  public _ready(): void {
	let vec = new Vector2();
	vec.x++;
	GD.print(vec);
	this.position.x++;
	GD.print(this.position);
	let arr = [0, 1];
	GD.print(arr);
  }

  public _process(delta: number): void {}
}
