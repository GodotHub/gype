
import { RefCounted } from "@godot/classes/ref_counted";
import { Object } from "@godot/classes/object";

export declare class KinematicCollision2D extends RefCounted{
  public get_position(): Vector2;
  public get_normal(): Vector2;
  public get_travel(): Vector2;
  public get_remainder(): Vector2;
  public get_angle(_up_direction: Vector2): number;
  public get_depth(): number;
  public get_local_shape(): Object;
  public get_collider(): Object;
  public get_collider_id(): number;
  public get_collider_rid(): RID;
  public get_collider_shape(): Object;
  public get_collider_shape_index(): number;
  public get_collider_velocity(): Vector2;
}