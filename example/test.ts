// Player.ts  to Area2D
import { Area2D } from "@godot/classes/area2d";
import { Input } from "@godot/classes/input";
import type { Node } from "@godot/classes/node";
import type { Node2D } from "@godot/classes/node2d";
import { Sprite2D } from "@godot/classes/sprite2d";
import { GodotExport } from "@godot/core/class_defined";

export default class Player extends Area2D {
  // Movement speed in pixels per second
  private speed: number = 400.0;
  private sprite2d!: Sprite2D;

  @GodotExport
  public struct: Struct = {
    x: 0,
    y: 0,
  };

  public _ready(): void {
    this.sprite2d = this.get_node<Sprite2D>("Sprite2D");
    GD.print("Player initialized");
  }

  public _process(delta: number): void {
    const inputDir: Vector2 = Input.get_vector(
      "ui_left",
      "ui_right",
      "ui_up",
      "ui_down"
    );
  }
}

interface Struct {
  x: number;
  y: number;
}
