
import type { Resource } from '@godot/classes/resource';


export declare class Image extends Resource {

    
    /**     * The raw type is 'Dictionary'     */
    public data: Dictionary;
    public get_width(): number;
    public get_height(): number;
    public get_size(): Vector2i;
    public has_mipmaps(): boolean;
    public get_format(): number;
    public get_data(): PackedByteArray;
    public get_data_size(): number;
    public convert(format: number): void;
    public get_mipmap_count(): number;
    public get_mipmap_offset(mipmap: number): number;
    public resize_to_po2(square: boolean = false, interpolation: number = 1): void;
    public resize(width: number, height: number, interpolation: number = 1): void;
    public shrink_x2(): void;
    public crop(width: number, height: number): void;
    public flip_x(): void;
    public flip_y(): void;
    public generate_mipmaps(renormalize: boolean = false): number;
    public clear_mipmaps(): void;
    public static create(width: number, height: number, useMipmaps: boolean, format: number): Image;
    public static create_empty(width: number, height: number, useMipmaps: boolean, format: number): Image;
    public static create_from_data(width: number, height: number, useMipmaps: boolean, format: number, data: PackedByteArray): Image;
    public set_data(width: number, height: number, useMipmaps: boolean, format: number, data: PackedByteArray): void;
    public is_empty(): boolean;
    public load(path: GDString | StringName | string): number;
    public static load_from_file(path: GDString | StringName | string): Image;
    public save_png(path: GDString | StringName | string): number;
    public save_png_to_buffer(): PackedByteArray;
    public save_jpg(path: GDString | StringName | string, quality: number = 0.75): number;
    public save_jpg_to_buffer(quality: number = 0.75): PackedByteArray;
    public save_exr(path: GDString | StringName | string, grayscale: boolean = false): number;
    public save_exr_to_buffer(grayscale: boolean = false): PackedByteArray;
    public save_dds(path: GDString | StringName | string): number;
    public save_dds_to_buffer(): PackedByteArray;
    public save_webp(path: GDString | StringName | string, lossy: boolean = false, quality: number = 0.75): number;
    public save_webp_to_buffer(lossy: boolean = false, quality: number = 0.75): PackedByteArray;
    public detect_alpha(): number;
    public is_invisible(): boolean;
    public detect_used_channels(source: number = 0): number;
    public compress(mode: number, source: number = 0, astcFormat: number = 0): number;
    public compress_from_channels(mode: number, channels: number, astcFormat: number = 0): number;
    public decompress(): number;
    public is_compressed(): boolean;
    public rotate_90(direction: number): void;
    public rotate_180(): void;
    public fix_alpha_edges(): void;
    public premultiply_alpha(): void;
    public srgb_to_linear(): void;
    public linear_to_srgb(): void;
    public normal_map_to_xy(): void;
    public rgbe_to_srgb(): Image;
    public bump_map_to_normal_map(bumscale: number = 1.0): void;
    public compute_image_metrics(comparedImage: Image, useLuma: boolean): Dictionary;
    public blit_rect(src: Image, srcRect: Rect2i, dst: Vector2i): void;
    public blit_rect_mask(src: Image, mask: Image, srcRect: Rect2i, dst: Vector2i): void;
    public blend_rect(src: Image, srcRect: Rect2i, dst: Vector2i): void;
    public blend_rect_mask(src: Image, mask: Image, srcRect: Rect2i, dst: Vector2i): void;
    public fill(color: Color): void;
    public fill_rect(rect: Rect2i, color: Color): void;
    public get_used_rect(): Rect2i;
    public get_region(region: Rect2i): Image;
    public copy_from(src: Image): void;
    public get_pixelv(point: Vector2i): Color;
    public get_pixel(x: number, y: number): Color;
    public set_pixelv(point: Vector2i, color: Color): void;
    public set_pixel(x: number, y: number, color: Color): void;
    public adjust_bcs(brightness: number, contrast: number, saturation: number): void;
    public load_png_from_buffer(buffer: PackedByteArray): number;
    public load_jpg_from_buffer(buffer: PackedByteArray): number;
    public load_webp_from_buffer(buffer: PackedByteArray): number;
    public load_tga_from_buffer(buffer: PackedByteArray): number;
    public load_bmp_from_buffer(buffer: PackedByteArray): number;
    public load_ktx_from_buffer(buffer: PackedByteArray): number;
    public load_dds_from_buffer(buffer: PackedByteArray): number;
    public load_svg_from_buffer(buffer: PackedByteArray, scale: number = 1.0): number;
    public load_svg_from_string(svgStr: GDString | StringName | string, scale: number = 1.0): number;


    public static readonly Format: {
        FORMAT_L8: 0;
        FORMAT_LA8: 1;
        FORMAT_R8: 2;
        FORMAT_RG8: 3;
        FORMAT_RGB8: 4;
        FORMAT_RGBA8: 5;
        FORMAT_RGBA4444: 6;
        FORMAT_RGB565: 7;
        FORMAT_RF: 8;
        FORMAT_RGF: 9;
        FORMAT_RGBF: 10;
        FORMAT_RGBAF: 11;
        FORMAT_RH: 12;
        FORMAT_RGH: 13;
        FORMAT_RGBH: 14;
        FORMAT_RGBAH: 15;
        FORMAT_RGBE9995: 16;
        FORMAT_DXT1: 17;
        FORMAT_DXT3: 18;
        FORMAT_DXT5: 19;
        FORMAT_RGTC_R: 20;
        FORMAT_RGTC_RG: 21;
        FORMAT_BPTC_RGBA: 22;
        FORMAT_BPTC_RGBF: 23;
        FORMAT_BPTC_RGBFU: 24;
        FORMAT_ETC: 25;
        FORMAT_ETC2_R11: 26;
        FORMAT_ETC2_R11S: 27;
        FORMAT_ETC2_RG11: 28;
        FORMAT_ETC2_RG11S: 29;
        FORMAT_ETC2_RGB8: 30;
        FORMAT_ETC2_RGBA8: 31;
        FORMAT_ETC2_RGB8A1: 32;
        FORMAT_ETC2_RA_AS_RG: 33;
        FORMAT_DXT5_RA_AS_RG: 34;
        FORMAT_ASTC_4x4: 35;
        FORMAT_ASTC_4x4_HDR: 36;
        FORMAT_ASTC_8x8: 37;
        FORMAT_ASTC_8x8_HDR: 38;
        FORMAT_MAX: 39;
    };
    public static readonly Interpolation: {
        INTERPOLATE_NEAREST: 0;
        INTERPOLATE_BILINEAR: 1;
        INTERPOLATE_CUBIC: 2;
        INTERPOLATE_TRILINEAR: 3;
        INTERPOLATE_LANCZOS: 4;
    };
    public static readonly AlphaMode: {
        ALPHA_NONE: 0;
        ALPHA_BIT: 1;
        ALPHA_BLEND: 2;
    };
    public static readonly CompressMode: {
        COMPRESS_S3TC: 0;
        COMPRESS_ETC: 1;
        COMPRESS_ETC2: 2;
        COMPRESS_BPTC: 3;
        COMPRESS_ASTC: 4;
        COMPRESS_MAX: 5;
    };
    public static readonly UsedChannels: {
        USED_CHANNELS_L: 0;
        USED_CHANNELS_LA: 1;
        USED_CHANNELS_R: 2;
        USED_CHANNELS_RG: 3;
        USED_CHANNELS_RGB: 4;
        USED_CHANNELS_RGBA: 5;
    };
    public static readonly CompressSource: {
        COMPRESS_SOURCE_GENERIC: 0;
        COMPRESS_SOURCE_SRGB: 1;
        COMPRESS_SOURCE_NORMAL: 2;
    };
    public static readonly ASTCFormat: {
        ASTC_FORMAT_4x4: 0;
        ASTC_FORMAT_8x8: 1;
    };
}

