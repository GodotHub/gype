

declare global {
    declare class Rect2 {
        constructor();
        constructor(_from: Rect2);
        constructor(_from: Rect2i);
        constructor(position: Vector2, size: Vector2);
        constructor(x: number, y: number, width: number, height: number);

        public position: Vector2;
        public size: Vector2;
        public end: Vector2;

        public get_center(): Vector2;
        public get_area(): number;
        public has_area(): boolean;
        public has_point(point: Vector2): boolean;
        public is_equal_approx(rect: Rect2): boolean;
        public is_finite(): boolean;
        public intersects(b: Rect2, includeBorders: boolean): boolean;
        public encloses(b: Rect2): boolean;
        public intersection(b: Rect2): Rect2;
        public merge(b: Rect2): Rect2;
        public expand(to: Vector2): Rect2;
        public get_support(direction: Vector2): Vector2;
        public grow(amount: number): Rect2;
        public grow_side(side: number, amount: number): Rect2;
        public grow_individual(left: number, top: number, right: number, bottom: number): Rect2;
        public abs(): Rect2;

    }
}

export {};