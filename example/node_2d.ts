
import { Node2D } from "@godot/classes/node2d";

export default class node_2d extends Node2D {
	public override _ready(): void {
		GD.print("hello");
	}

	public override _process(delta: number): void {

	}
}
	
