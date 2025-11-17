declare global {
    export class Plane {
        constructor(): Plane;
        constructor(_from: Plane): Plane;
        constructor(normal: Vector3): Plane;
        constructor(normal: Vector3, d: number): Plane;
        constructor(normal: Vector3, point: Vector3): Plane;
        constructor(point1: Vector3, point2: Vector3, point3: Vector3): Plane;
        constructor(a: number, b: number, c: number, d: number): Plane;
        readonly static PLANE_YZ: Plane;
        readonly static PLANE_XZ: Plane;
        readonly static PLANE_XY: Plane;
    
        x: number;
        y: number;
        z: number;
        d: number;
        normal: Vector3;

        normalized(): Plane;
        get_center(): Vector3;
        is_equal_approx(toPlane: Plane): boolean;
        is_finite(): boolean;
        is_point_over(point: Vector3): boolean;
        distance_to(point: Vector3): number;
        has_point(point: Vector3, tolerance: number = 1e-05): boolean;
        project(point: Vector3): Vector3;
        intersect_3(b: Plane, c: Plane): any;
        intersects_ray(_from: Vector3, dir: Vector3): any;
        intersects_segment(_from: Vector3, to: Vector3): any;
        
        /*
        // equals(any): boolean
        // not_equals(any): boolean
        // negate(any): Plane
        // positive(any): Plane
        // op_not(any): boolean
        // equals(Plane): boolean
        // not_equals(Plane): boolean
        // multiply(Transform3D): Plane
        // in_op(Dictionary): boolean
        // in_op(GDArray): boolean
        */
    }
}

export {};