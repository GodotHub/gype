
import type { GDString } from '@godot/builtins/gd_string';
import type { Node } from '@godot/classes/node';
import type { PackedByteArray } from '@godot/builtins/packed_byte_array';
import type { PackedStringArray } from '@godot/builtins/packed_string_array';
import type { Signal } from '@godot/builtins/signal';
import type { TLSOptions } from '@godot/classes/tls_options';


export declare class HTTPRequest extends Node {

    
    /**     * The raw type is 'String'     */
    public download_file: GDString;    
    /**     * The raw type is 'int'     */
    public download_chunk_size: number;    
    /**     * The raw type is 'bool'     */
    public use_threads: boolean;    
    /**     * The raw type is 'bool'     */
    public accept_gzip: boolean;    
    /**     * The raw type is 'int'     */
    public body_size_limit: number;    
    /**     * The raw type is 'int'     */
    public max_redirects: number;    
    /**     * The raw type is 'float'     */
    public timeout: number;
    public request(url: GDString | StringName | string, customHeaders: PackedStringArray = PackedStringArray(), method: number = 0, requestData: GDString | StringName | string = ""): number;
    public request_raw(url: GDString | StringName | string, customHeaders: PackedStringArray = PackedStringArray(), method: number = 0, requestDataRaw: PackedByteArray = PackedByteArray()): number;
    public cancel_request(): void;
    public set_tls_options(clientOptions: TLSOptions): void;
    public get_http_client_status(): number;
    public set_use_threads(enable: boolean): void;
    public is_using_threads(): boolean;
    public set_accept_gzip(enable: boolean): void;
    public is_accepting_gzip(): boolean;
    public set_body_size_limit(bytes: number): void;
    public get_body_size_limit(): number;
    public set_max_redirects(amount: number): void;
    public get_max_redirects(): number;
    public set_download_file(path: GDString | StringName | string): void;
    public get_download_file(): GDString;
    public get_downloaded_bytes(): number;
    public get_body_size(): number;
    public set_timeout(timeout: number): void;
    public get_timeout(): number;
    public set_download_chunk_size(chunkSize: number): void;
    public get_download_chunk_size(): number;
    public set_http_proxy(host: GDString | StringName | string, port: number): void;
    public set_https_proxy(host: GDString | StringName | string, port: number): void;

    
    public readonly request_completed: Signal<(result: number, responseCode: number, headers: PackedStringArray, body: PackedByteArray) => void>;

    public static readonly Result: {
        RESULT_SUCCESS: 0;
        RESULT_CHUNKED_BODY_SIZE_MISMATCH: 1;
        RESULT_CANT_CONNECT: 2;
        RESULT_CANT_RESOLVE: 3;
        RESULT_CONNECTION_ERROR: 4;
        RESULT_TLS_HANDSHAKE_ERROR: 5;
        RESULT_NO_RESPONSE: 6;
        RESULT_BODY_SIZE_LIMIT_EXCEEDED: 7;
        RESULT_BODY_DECOMPRESS_FAILED: 8;
        RESULT_REQUEST_FAILED: 9;
        RESULT_DOWNLOAD_FILE_CANT_OPEN: 10;
        RESULT_DOWNLOAD_FILE_WRITE_ERROR: 11;
        RESULT_REDIRECT_LIMIT_REACHED: 12;
        RESULT_TIMEOUT: 13;
    };
}

