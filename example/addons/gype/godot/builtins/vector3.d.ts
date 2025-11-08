

declare global {
    declare class Vector3 {
        constructor();
        constructor(_from: Vector3);
        constructor(_from: Vector3i);
        constructor(x: number, y: number, z: number);

        public x: number;
        public y: number;
        public z: number;

        public min_axis_index(): number;
        public max_axis_index(): number;
        public angle_to(to: Vector3): number;
        public signed_angle_to(to: Vector3, axis: Vector3): number;
        public direction_to(to: Vector3): Vector3;
        public distance_to(to: Vector3): number;
        public distance_squared_to(to: Vector3): number;
        public length(): number;
        public length_squared(): number;
        public limit_length(length: number): Vector3;
        public normalized(): Vector3;
        public is_normalized(): boolean;
        public is_equal_approx(to: Vector3): boolean;
        public is_zero_approx(): boolean;
        public is_finite(): boolean;
        public inverse(): Vector3;
        public clamp(min: Vector3, max: Vector3): Vector3;
        public clampf(min: number, max: number): Vector3;
        public snapped(step: Vector3): Vector3;
        public snappedf(step: number): Vector3;
        public rotated(axis: Vector3, angle: number): Vector3;
        public lerp(to: Vector3, weight: number): Vector3;
        public slerp(to: Vector3, weight: number): Vector3;
        public cubic_interpolate(b: Vector3, preA: Vector3, postB: Vector3, weight: number): Vector3;
        public cubic_interpolate_in_time(b: Vector3, preA: Vector3, postB: Vector3, weight: number, bT: number, preAT: number, postBT: number): Vector3;
        public bezier_interpolate(control1: Vector3, control2: Vector3, end: Vector3, t: number): Vector3;
        public bezier_derivative(control1: Vector3, control2: Vector3, end: Vector3, t: number): Vector3;
        public move_toward(to: Vector3, delta: number): Vector3;
        public dot(_with: Vector3): number;
        public cross(_with: Vector3): Vector3;
        public outer(_with: Vector3): Basis;
        public abs(): Vector3;
        public floor(): Vector3;
        public ceil(): Vector3;
        public round(): Vector3;
        public posmod(mod: number): Vector3;
        public posmodv(modv: Vector3): Vector3;
        public project(b: Vector3): Vector3;
        public slide(n: Vector3): Vector3;
        public bounce(n: Vector3): Vector3;
        public reflect(n: Vector3): Vector3;
        public sign(): Vector3;
        public octahedron_encode(): Vector2;
        public min(_with: Vector3): Vector3;
        public minf(_with: number): Vector3;
        public max(_with: Vector3): Vector3;
        public maxf(_with: number): Vector3;
        public static octahedron_decode(uv: Vector2): Vector3;

        public static readonly Axis: {
            AXIS_X: 0;
            AXIS_Y: 1;
            AXIS_Z: 2;
        };
    }
}

export {};