import { Node2D } from "@godot/classes/node2d";
import { GodotClass } from "@godot/core/class_defined";

@GodotClass
export class Game extends Node2D {
	public _ready(): void {
		GD.print("ready");
	}

	public _process(delta: number): void {
	}
}
