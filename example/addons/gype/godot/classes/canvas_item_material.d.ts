
import { Material } from "@godot/classes/material";

export declare class CanvasItemMaterial extends Material{
  public set_blend_mode(_blend_mode: number): void;
  public get_blend_mode(): number;
  public set_light_mode(_light_mode: number): void;
  public get_light_mode(): number;
  public set_particles_animation(_particles_anim: boolean): void;
  public get_particles_animation(): boolean;
  public set_particles_anim_h_frames(_frames: number): void;
  public get_particles_anim_h_frames(): number;
  public set_particles_anim_v_frames(_frames: number): void;
  public get_particles_anim_v_frames(): number;
  public set_particles_anim_loop(_loop: boolean): void;
  public get_particles_anim_loop(): boolean;
  public get blend_mode(): number {
    get_blend_mode();
  }
  public set blend_mode(value): void {
    set_blend_mode(value);
  }
  public get light_mode(): number {
    get_light_mode();
  }
  public set light_mode(value): void {
    set_light_mode(value);
  }
  public get particles_animation(): boolean {
    get_particles_animation();
  }
  public set particles_animation(value): void {
    set_particles_animation(value);
  }
  public get particles_anim_h_frames(): number {
    get_particles_anim_h_frames();
  }
  public set particles_anim_h_frames(value): void {
    set_particles_anim_h_frames(value);
  }
  public get particles_anim_v_frames(): number {
    get_particles_anim_v_frames();
  }
  public set particles_anim_v_frames(value): void {
    set_particles_anim_v_frames(value);
  }
  public get particles_anim_loop(): boolean {
    get_particles_anim_loop();
  }
  public set particles_anim_loop(value): void {
    set_particles_anim_loop(value);
  }
  static BlendMode = {
    BLEND_MODE_MIX = 0,
    BLEND_MODE_ADD = 1,
    BLEND_MODE_SUB = 2,
    BLEND_MODE_MUL = 3,
    BLEND_MODE_PREMULT_ALPHA = 4,
  }
  static LightMode = {
    LIGHT_MODE_NORMAL = 0,
    LIGHT_MODE_UNSHADED = 1,
    LIGHT_MODE_LIGHT_ONLY = 2,
  }
}