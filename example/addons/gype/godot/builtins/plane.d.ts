

declare global {
    declare class Plane {
        constructor();
        constructor(_from: Plane);
        constructor(normal: Vector3);
        constructor(normal: Vector3, d: number);
        constructor(normal: Vector3, point: Vector3);
        constructor(point1: Vector3, point2: Vector3, point3: Vector3);
        constructor(a: number, b: number, c: number, d: number);

        public x: number;
        public y: number;
        public z: number;
        public d: number;
        public normal: Vector3;

        public normalized(): Plane;
        public get_center(): Vector3;
        public is_equal_approx(to_plane: Plane): boolean;
        public is_finite(): boolean;
        public is_point_over(point: Vector3): boolean;
        public distance_to(point: Vector3): number;
        public has_point(point: Vector3, tolerance: number): boolean;
        public project(point: Vector3): Vector3;
        public intersect_3(b: Plane, c: Plane): any;
        public intersects_ray(_from: Vector3, dir: Vector3): any;
        public intersects_segment(_from: Vector3, to: Vector3): any;

    }
}

export {};