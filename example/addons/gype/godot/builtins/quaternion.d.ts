

declare global {
    declare class Quaternion {
        constructor();
        constructor(_from: Quaternion);
        constructor(_from: Basis);
        constructor(axis: Vector3, angle: number);
        constructor(arcFrom: Vector3, arcTo: Vector3);
        constructor(x: number, y: number, z: number, w: number);

        public x: number;
        public y: number;
        public z: number;
        public w: number;

        public length(): number;
        public length_squared(): number;
        public normalized(): Quaternion;
        public is_normalized(): boolean;
        public is_equal_approx(to: Quaternion): boolean;
        public is_finite(): boolean;
        public inverse(): Quaternion;
        public log(): Quaternion;
        public exp(): Quaternion;
        public angle_to(to: Quaternion): number;
        public dot(_with: Quaternion): number;
        public slerp(to: Quaternion, weight: number): Quaternion;
        public slerpni(to: Quaternion, weight: number): Quaternion;
        public spherical_cubic_interpolate(b: Quaternion, preA: Quaternion, postB: Quaternion, weight: number): Quaternion;
        public spherical_cubic_interpolate_in_time(b: Quaternion, preA: Quaternion, postB: Quaternion, weight: number, bT: number, preAT: number, postBT: number): Quaternion;
        public get_euler(order: number): Vector3;
        public static from_euler(euler: Vector3): Quaternion;
        public get_axis(): Vector3;
        public get_angle(): number;

    }
}

export {};