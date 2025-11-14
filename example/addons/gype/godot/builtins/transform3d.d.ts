declare global {
    export class Transform3D {
        constructor(): Transform3D;
        constructor(_from: Transform3D): Transform3D;
        constructor(basis: Basis, origin: Vector3): Transform3D;
        constructor(xAxis: Vector3, yAxis: Vector3, zAxis: Vector3, origin: Vector3): Transform3D;
        constructor(_from: Projection): Transform3D;
        readonly IDENTITY: Transform3D;
        readonly FLIP_X: Transform3D;
        readonly FLIP_Y: Transform3D;
        readonly FLIP_Z: Transform3D;
    
        basis: Basis;
        origin: Vector3;

        inverse(): Transform3D;
        affine_inverse(): Transform3D;
        orthonormalized(): Transform3D;
        rotated(axis: Vector3, angle: number): Transform3D;
        rotated_local(axis: Vector3, angle: number): Transform3D;
        scaled(scale: Vector3): Transform3D;
        scaled_local(scale: Vector3): Transform3D;
        translated(offset: Vector3): Transform3D;
        translated_local(offset: Vector3): Transform3D;
        looking_at(target: Vector3, up: Vector3 = Vector3(0, 1, 0), useModelFront: boolean = false): Transform3D;
        interpolate_with(xform: Transform3D, weight: number): Transform3D;
        is_equal_approx(xform: Transform3D): boolean;
        is_finite(): boolean;
        
        /*
        // equals(any): boolean
        // not_equals(any): boolean
        // op_not(any): boolean
        // multiply(number): Transform3D
        // divide(number): Transform3D
        // multiply(number): Transform3D
        // divide(number): Transform3D
        // multiply(Vector3): Vector3
        // multiply(Plane): Plane
        // multiply(AABB): AABB
        // equals(Transform3D): boolean
        // not_equals(Transform3D): boolean
        // multiply(Transform3D): Transform3D
        // in_op(Dictionary): boolean
        // in_op(GDArray): boolean
        // multiply(PackedVector3Array): PackedVector3Array
        */
    }
}

export {};