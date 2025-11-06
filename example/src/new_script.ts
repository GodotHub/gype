import { Node2D } from "@godot/classes/node2d";
import { GodotClass } from "@godot/core/class_defined";

@GodotClass
export class new_script extends Node2D {
	public _ready(): void {
		GD.print(this.position.x);
	}

	public _process(delta: number): void {

	}
}
	
