
import type { Image } from '@godot/classes/image';
import type { Texture2D } from '@godot/classes/texture2d';


export declare class PortableCompressedTexture2D extends Texture2D {

    
    /**     * The raw type is 'Vector2'     */
    public size_override: Vector2;    
    /**     * The raw type is 'bool'     */
    public keep_compressed_buffer: boolean;
    public create_from_image(image: Image, compressionMode: number, normalMap: boolean = false, lossyQuality: number = 0.8): void;
    public get_format(): number;
    public get_compression_mode(): number;
    public set_size_override(size: Vector2): void;
    public get_size_override(): Vector2;
    public set_keep_compressed_buffer(keep: boolean): void;
    public is_keeping_compressed_buffer(): boolean;
    public set_basisu_compressor_params(uastcLevel: number, rdoQualityLoss: number): void;
    public static set_keep_all_compressed_buffers(keep: boolean): void;
    public static is_keeping_all_compressed_buffers(): boolean;


    public static readonly CompressionMode: {
        COMPRESSION_MODE_LOSSLESS: 0;
        COMPRESSION_MODE_LOSSY: 1;
        COMPRESSION_MODE_BASIS_UNIVERSAL: 2;
        COMPRESSION_MODE_S3TC: 3;
        COMPRESSION_MODE_ETC2: 4;
        COMPRESSION_MODE_BPTC: 5;
        COMPRESSION_MODE_ASTC: 6;
    };
}

