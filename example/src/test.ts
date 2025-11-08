import { Node2D } from "@godot/classes/node2d";
import { GodotClass } from "@godot/core/class_defined";

@GodotClass
export class test extends Node2D {
	public _ready(): void {
		GD.print(this.position);
		GD.print(this.position.x);
		GD.print(++this.position.x);
		GD.print(this.position.x);
	}

	public _process(delta: number): void {

	}
}
	
