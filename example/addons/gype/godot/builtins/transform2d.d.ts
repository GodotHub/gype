

declare global {
    declare class Transform2D {
        constructor();
        constructor(_from: Transform2D);
        constructor(rotation: number, position: Vector2);
        constructor(rotation: number, scale: Vector2, skew: number, position: Vector2);
        constructor(x_axis: Vector2, y_axis: Vector2, origin: Vector2);

        public x: Vector2;
        public y: Vector2;
        public origin: Vector2;

        public inverse(): Transform2D;
        public affine_inverse(): Transform2D;
        public get_rotation(): number;
        public get_origin(): Vector2;
        public get_scale(): Vector2;
        public get_skew(): number;
        public orthonormalized(): Transform2D;
        public rotated(angle: number): Transform2D;
        public rotated_local(angle: number): Transform2D;
        public scaled(scale: Vector2): Transform2D;
        public scaled_local(scale: Vector2): Transform2D;
        public translated(offset: Vector2): Transform2D;
        public translated_local(offset: Vector2): Transform2D;
        public determinant(): number;
        public basis_xform(v: Vector2): Vector2;
        public basis_xform_inv(v: Vector2): Vector2;
        public interpolate_with(xform: Transform2D, weight: number): Transform2D;
        public is_conformal(): boolean;
        public is_equal_approx(xform: Transform2D): boolean;
        public is_finite(): boolean;
        public looking_at(target: Vector2): Transform2D;

    }
}

export {};