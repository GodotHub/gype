
import { Curve } from "@godot/classes/curve";
import { Texture2D } from "@godot/classes/texture2d";

export declare class CurveXYZTexture extends Texture2D{
  public set_width(_width: number): void;
  public set_curve_x(_curve: Curve): void;
  public get_curve_x(): Curve;
  public set_curve_y(_curve: Curve): void;
  public get_curve_y(): Curve;
  public set_curve_z(_curve: Curve): void;
  public get_curve_z(): Curve;
  public get width(): number {
    get_width();
  }
  public set width(value): void {
    set_width(value);
  }
  public get curve_x(): Curve {
    get_curve_x();
  }
  public set curve_x(value): void {
    set_curve_x(value);
  }
  public get curve_y(): Curve {
    get_curve_y();
  }
  public set curve_y(value): void {
    set_curve_y(value);
  }
  public get curve_z(): Curve {
    get_curve_z();
  }
  public set curve_z(value): void {
    set_curve_z(value);
  }
}