

declare global {
    declare class Projection {
        constructor();
        constructor(_from: Projection);
        constructor(_from: Transform3D);
        constructor(x_axis: Vector4, y_axis: Vector4, z_axis: Vector4, w_axis: Vector4);

        public x: Vector4;
        public y: Vector4;
        public z: Vector4;
        public w: Vector4;

        public static create_depth_correction(fliy: boolean): Projection;
        public static create_light_atlas_rect(rect: Rect2): Projection;
        public static create_perspective(fovy: number, aspect: number, z_near: number, z_far: number, flifov: boolean): Projection;
        public static create_perspective_hmd(fovy: number, aspect: number, z_near: number, z_far: number, flifov: boolean, eye: number, intraocular_dist: number, convergence_dist: number): Projection;
        public static create_for_hmd(eye: number, aspect: number, intraocular_dist: number, display_width: number, display_to_lens: number, oversample: number, z_near: number, z_far: number): Projection;
        public static create_orthogonal(left: number, right: number, bottom: number, top: number, z_near: number, z_far: number): Projection;
        public static create_orthogonal_aspect(size: number, aspect: number, z_near: number, z_far: number, flifov: boolean): Projection;
        public static create_frustum(left: number, right: number, bottom: number, top: number, z_near: number, z_far: number): Projection;
        public static create_frustum_aspect(size: number, aspect: number, offset: Vector2, z_near: number, z_far: number, flifov: boolean): Projection;
        public static create_fit_aabb(aabb: AABB): Projection;
        public determinant(): number;
        public perspective_znear_adjusted(new_znear: number): Projection;
        public get_projection_plane(plane: number): Plane;
        public flipped_y(): Projection;
        public jitter_offseted(offset: Vector2): Projection;
        public static get_fovy(fovx: number, aspect: number): number;
        public get_z_far(): number;
        public get_z_near(): number;
        public get_aspect(): number;
        public get_fov(): number;
        public is_orthogonal(): boolean;
        public get_viewport_half_extents(): Vector2;
        public get_far_plane_half_extents(): Vector2;
        public inverse(): Projection;
        public get_pixels_per_meter(for_pixel_width: number): number;
        public get_lod_multiplier(): number;

        public static readonly Planes: {
            PLANE_NEAR: 0;
            PLANE_FAR: 1;
            PLANE_LEFT: 2;
            PLANE_TOP: 3;
            PLANE_RIGHT: 4;
            PLANE_BOTTOM: 5;
        };
    }
}

export {};