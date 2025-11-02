

declare global {
    declare class Vector4i {
        constructor();
        constructor(_from: Vector4i);
        constructor(_from: Vector4);
        constructor(x: number, y: number, z: number, w: number);

        public x: number;
        public y: number;
        public z: number;
        public w: number;

        public min_axis_index(): number;
        public max_axis_index(): number;
        public length(): number;
        public length_squared(): number;
        public sign(): Vector4i;
        public abs(): Vector4i;
        public clamp(min: Vector4i, max: Vector4i): Vector4i;
        public clampi(min: number, max: number): Vector4i;
        public snapped(step: Vector4i): Vector4i;
        public snappedi(step: number): Vector4i;
        public min(_with: Vector4i): Vector4i;
        public mini(_with: number): Vector4i;
        public max(_with: Vector4i): Vector4i;
        public maxi(_with: number): Vector4i;
        public distance_to(to: Vector4i): number;
        public distance_squared_to(to: Vector4i): number;

        public static readonly Axis: {
            AXIS_X: 0;
            AXIS_Y: 1;
            AXIS_Z: 2;
            AXIS_W: 3;
        };
    }
}

export {};