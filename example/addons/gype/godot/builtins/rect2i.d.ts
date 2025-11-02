

declare global {
    declare class Rect2i {
        constructor();
        constructor(_from: Rect2i);
        constructor(_from: Rect2);
        constructor(position: Vector2i, size: Vector2i);
        constructor(x: number, y: number, width: number, height: number);

        public position: Vector2i;
        public size: Vector2i;
        public end: Vector2i;

        public get_center(): Vector2i;
        public get_area(): number;
        public has_area(): boolean;
        public has_point(point: Vector2i): boolean;
        public intersects(b: Rect2i): boolean;
        public encloses(b: Rect2i): boolean;
        public intersection(b: Rect2i): Rect2i;
        public merge(b: Rect2i): Rect2i;
        public expand(to: Vector2i): Rect2i;
        public grow(amount: number): Rect2i;
        public grow_side(side: number, amount: number): Rect2i;
        public grow_individual(left: number, top: number, right: number, bottom: number): Rect2i;
        public abs(): Rect2i;

    }
}

export {};