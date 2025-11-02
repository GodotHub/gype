

declare global {
    declare class Transform3D {
        constructor();
        constructor(_from: Transform3D);
        constructor(basis: Basis, origin: Vector3);
        constructor(x_axis: Vector3, y_axis: Vector3, z_axis: Vector3, origin: Vector3);
        constructor(_from: Projection);

        public basis: Basis;
        public origin: Vector3;

        public inverse(): Transform3D;
        public affine_inverse(): Transform3D;
        public orthonormalized(): Transform3D;
        public rotated(axis: Vector3, angle: number): Transform3D;
        public rotated_local(axis: Vector3, angle: number): Transform3D;
        public scaled(scale: Vector3): Transform3D;
        public scaled_local(scale: Vector3): Transform3D;
        public translated(offset: Vector3): Transform3D;
        public translated_local(offset: Vector3): Transform3D;
        public looking_at(target: Vector3, up: Vector3, use_model_front: boolean): Transform3D;
        public interpolate_with(xform: Transform3D, weight: number): Transform3D;
        public is_equal_approx(xform: Transform3D): boolean;
        public is_finite(): boolean;

    }
}

export {};