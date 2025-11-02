

declare global {
    declare class Vector2 {
        constructor();
        constructor(_from: Vector2);
        constructor(_from: Vector2i);
        constructor(x: number, y: number);

        public x: number;
        public y: number;

        public angle(): number;
        public angle_to(to: Vector2): number;
        public angle_to_point(to: Vector2): number;
        public direction_to(to: Vector2): Vector2;
        public distance_to(to: Vector2): number;
        public distance_squared_to(to: Vector2): number;
        public length(): number;
        public length_squared(): number;
        public limit_length(length: number): Vector2;
        public normalized(): Vector2;
        public is_normalized(): boolean;
        public is_equal_approx(to: Vector2): boolean;
        public is_zero_approx(): boolean;
        public is_finite(): boolean;
        public posmod(mod: number): Vector2;
        public posmodv(modv: Vector2): Vector2;
        public project(b: Vector2): Vector2;
        public lerp(to: Vector2, weight: number): Vector2;
        public slerp(to: Vector2, weight: number): Vector2;
        public cubic_interpolate(b: Vector2, pre_a: Vector2, post_b: Vector2, weight: number): Vector2;
        public cubic_interpolate_in_time(b: Vector2, pre_a: Vector2, post_b: Vector2, weight: number, b_t: number, pre_a_t: number, post_b_t: number): Vector2;
        public bezier_interpolate(control_1: Vector2, control_2: Vector2, end: Vector2, t: number): Vector2;
        public bezier_derivative(control_1: Vector2, control_2: Vector2, end: Vector2, t: number): Vector2;
        public max_axis_index(): number;
        public min_axis_index(): number;
        public move_toward(to: Vector2, delta: number): Vector2;
        public rotated(angle: number): Vector2;
        public orthogonal(): Vector2;
        public floor(): Vector2;
        public ceil(): Vector2;
        public round(): Vector2;
        public aspect(): number;
        public dot(_with: Vector2): number;
        public slide(n: Vector2): Vector2;
        public bounce(n: Vector2): Vector2;
        public reflect(line: Vector2): Vector2;
        public cross(_with: Vector2): number;
        public abs(): Vector2;
        public sign(): Vector2;
        public clamp(min: Vector2, max: Vector2): Vector2;
        public clampf(min: number, max: number): Vector2;
        public snapped(step: Vector2): Vector2;
        public snappedf(step: number): Vector2;
        public min(_with: Vector2): Vector2;
        public minf(_with: number): Vector2;
        public max(_with: Vector2): Vector2;
        public maxf(_with: number): Vector2;
        public static from_angle(angle: number): Vector2;

        public static readonly Axis: {
            AXIS_X: 0;
            AXIS_Y: 1;
        };
    }
}

export {};