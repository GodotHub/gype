
import type { CryptoKey } from '@godot/classes/crypto_key';
import type { GDString } from '@godot/builtins/gd_string';
import type { PackedByteArray } from '@godot/builtins/packed_byte_array';
import type { RefCounted } from '@godot/classes/ref_counted';
import type { X509Certificate } from '@godot/classes/x509_certificate';


export declare class Crypto extends RefCounted {


    public generate_random_bytes(size: number): PackedByteArray;
    public generate_rsa(size: number): CryptoKey;
    public generate_self_signed_certificate(key: CryptoKey, issuerName: GDString | StringName | string = "CN=myserver,O=myorganisation,C=IT", notBefore: GDString | StringName | string = "20140101000000", notAfter: GDString | StringName | string = "20340101000000"): X509Certificate;
    public sign(hashType: number, hash: PackedByteArray, key: CryptoKey): PackedByteArray;
    public verify(hashType: number, hash: PackedByteArray, signature: PackedByteArray, key: CryptoKey): boolean;
    public encrypt(key: CryptoKey, plaintext: PackedByteArray): PackedByteArray;
    public decrypt(key: CryptoKey, ciphertext: PackedByteArray): PackedByteArray;
    public hmac_digest(hashType: number, key: PackedByteArray, msg: PackedByteArray): PackedByteArray;
    public constant_time_compare(trusted: PackedByteArray, received: PackedByteArray): boolean;


}

