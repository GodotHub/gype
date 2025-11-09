
/**
 * Godot's built-in Projection type.
 *
 * As a data structure, it can be represented by a plain object.
 * @example
 * let my_vector: Projection = { x: 1, y: 0 };
 *
 * To create a new instance, use the global constructor.
 * @example
 * const my_vector = new Projection(1, 0);
 */
export interface Projection {
    x: Vector4;
    y: Vector4;
    z: Vector4;
    w: Vector4;

    createDepthCorrection(fliy: boolean): Projection;
    createLightAtlasRect(rect: Rect2): Projection;
    createPerspective(fovy: number, aspect: number, zNear: number, zFar: number, flifov: boolean = false): Projection;
    createPerspectiveHmd(fovy: number, aspect: number, zNear: number, zFar: number, flifov: boolean, eye: number, intraocularDist: number, convergenceDist: number): Projection;
    createForHmd(eye: number, aspect: number, intraocularDist: number, displayWidth: number, displayToLens: number, oversample: number, zNear: number, zFar: number): Projection;
    createOrthogonal(left: number, right: number, bottom: number, top: number, zNear: number, zFar: number): Projection;
    createOrthogonalAspect(size: number, aspect: number, zNear: number, zFar: number, flifov: boolean = false): Projection;
    createFrustum(left: number, right: number, bottom: number, top: number, zNear: number, zFar: number): Projection;
    createFrustumAspect(size: number, aspect: number, offset: Vector2, zNear: number, zFar: number, flifov: boolean = false): Projection;
    createFitAabb(aabb: AABB): Projection;
    determinant(): number;
    perspectiveZnearAdjusted(newZnear: number): Projection;
    getProjectionPlane(plane: number): Plane;
    flippedY(): Projection;
    jitterOffseted(offset: Vector2): Projection;
    getFovy(fovx: number, aspect: number): number;
    getZFar(): number;
    getZNear(): number;
    getAspect(): number;
    getFov(): number;
    isOrthogonal(): boolean;
    getViewportHalfExtents(): Vector2;
    getFarPlaneHalfExtents(): Vector2;
    inverse(): Projection;
    getPixelsPerMeter(forPixelWidth: number): number;
    getLodMultiplier(): number;
}

/**
 * A global constructor and namespace for the Projection type.
 *
 * Use `new Projection(...)` to create a new instance.
 * Access static members like `Projection.ZERO`.
 */
export declare const Projection: {
    new(): Projection;
    new(_from: Projection): Projection;
    new(_from: Transform3D): Projection;
    new(xAxis: Vector4, yAxis: Vector4, zAxis: Vector4, wAxis: Vector4): Projection;

    readonly IDENTITY: Projection;
    readonly ZERO: Projection;

    /*
    // equals(any): boolean
    // not_equals(any): boolean
    // op_not(any): boolean
    // multiply(Vector4): Vector4
    // equals(Projection): boolean
    // not_equals(Projection): boolean
    // multiply(Projection): Projection
    // in_op(Dictionary): boolean
    // in_op(GDArray): boolean
    */
};