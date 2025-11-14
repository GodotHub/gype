
import type { CryptoKey } from '@godot/classes/crypto_key';
import type { GDString } from '@godot/builtins/gd_string';
import type { RefCounted } from '@godot/classes/ref_counted';
import type { X509Certificate } from '@godot/classes/x509_certificate';


export declare class TLSOptions extends RefCounted {


    public static client(trustedChain: X509Certificate = null, commonNameOverride: GDString | StringName | string = ""): TLSOptions;
    public static client_unsafe(trustedChain: X509Certificate = null): TLSOptions;
    public static server(key: CryptoKey, certificate: X509Certificate): TLSOptions;
    public is_server(): boolean;
    public is_unsafe_client(): boolean;
    public get_common_name_override(): GDString;
    public get_trusted_ca_chain(): X509Certificate;
    public get_private_key(): CryptoKey;
    public get_own_certificate(): X509Certificate;


}

