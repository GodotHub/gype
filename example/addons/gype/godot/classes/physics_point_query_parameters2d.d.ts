
import { RefCounted } from "@godot/classes/ref_counted";

export declare class PhysicsPointQueryParameters2D extends RefCounted{
  public set_position(_position: Vector2): void;
  public get_position(): Vector2;
  public set_canvas_instance_id(_canvas_instance_id: number): void;
  public get_canvas_instance_id(): number;
  public set_collision_mask(_collision_mask: number): void;
  public get_collision_mask(): number;
  public set_exclude(_exclude: GDArray): void;
  public get_exclude(): GDArray;
  public set_collide_with_bodies(_enable: boolean): void;
  public is_collide_with_bodies_enabled(): boolean;
  public set_collide_with_areas(_enable: boolean): void;
  public is_collide_with_areas_enabled(): boolean;
  public get position(): Vector2 {
    get_position();
  }
  public set position(value): void {
    set_position(value);
  }
  public get canvas_instance_id(): number {
    get_canvas_instance_id();
  }
  public set canvas_instance_id(value): void {
    set_canvas_instance_id(value);
  }
  public get collision_mask(): number {
    get_collision_mask();
  }
  public set collision_mask(value): void {
    set_collision_mask(value);
  }
  public get exclude(): GDArray {
    get_exclude();
  }
  public set exclude(value): void {
    set_exclude(value);
  }
  public get collide_with_bodies(): boolean {
    is_collide_with_bodies_enabled();
  }
  public set collide_with_bodies(value): void {
    set_collide_with_bodies(value);
  }
  public get collide_with_areas(): boolean {
    is_collide_with_areas_enabled();
  }
  public set collide_with_areas(value): void {
    set_collide_with_areas(value);
  }
}