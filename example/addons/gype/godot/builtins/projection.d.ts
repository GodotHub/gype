declare global {
    export class Projection {
        constructor(): Projection;
        constructor(_from: Projection): Projection;
        constructor(_from: Transform3D): Projection;
        constructor(xAxis: Vector4, yAxis: Vector4, zAxis: Vector4, wAxis: Vector4): Projection;
        readonly static IDENTITY: Projection;
        readonly static ZERO: Projection;
    
        x: Vector4;
        y: Vector4;
        z: Vector4;
        w: Vector4;

        create_depth_correction(fliy: boolean): Projection;
        create_light_atlas_rect(rect: Rect2): Projection;
        create_perspective(fovy: number, aspect: number, zNear: number, zFar: number, flifov: boolean = false): Projection;
        create_perspective_hmd(fovy: number, aspect: number, zNear: number, zFar: number, flifov: boolean, eye: number, intraocularDist: number, convergenceDist: number): Projection;
        create_for_hmd(eye: number, aspect: number, intraocularDist: number, displayWidth: number, displayToLens: number, oversample: number, zNear: number, zFar: number): Projection;
        create_orthogonal(left: number, right: number, bottom: number, top: number, zNear: number, zFar: number): Projection;
        create_orthogonal_aspect(size: number, aspect: number, zNear: number, zFar: number, flifov: boolean = false): Projection;
        create_frustum(left: number, right: number, bottom: number, top: number, zNear: number, zFar: number): Projection;
        create_frustum_aspect(size: number, aspect: number, offset: Vector2, zNear: number, zFar: number, flifov: boolean = false): Projection;
        create_fit_aabb(aabb: AABB): Projection;
        determinant(): number;
        perspective_znear_adjusted(newZnear: number): Projection;
        get_projection_plane(plane: number): Plane;
        flipped_y(): Projection;
        jitter_offseted(offset: Vector2): Projection;
        get_fovy(fovx: number, aspect: number): number;
        get_z_far(): number;
        get_z_near(): number;
        get_aspect(): number;
        get_fov(): number;
        is_orthogonal(): boolean;
        get_viewport_half_extents(): Vector2;
        get_far_plane_half_extents(): Vector2;
        inverse(): Projection;
        get_pixels_per_meter(forPixelWidth: number): number;
        get_lod_multiplier(): number;
        
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
    }
}

export {};