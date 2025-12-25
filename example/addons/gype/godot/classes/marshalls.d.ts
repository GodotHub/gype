
import type { GodotObject } from '@godot/classes/godot_object';


export declare class _Marshalls extends GodotObject {


    public variant_to_base64(variant: any, fullObjects: boolean = false): GDString;
    public base64_to_variant(base64Str: GDString | StringName | string, allowObjects: boolean = false): any;
    public raw_to_base64(array: PackedByteArray): GDString;
    public base64_to_raw(base64Str: GDString | StringName | string): PackedByteArray;
    public utf8_to_base64(utf8Str: GDString | StringName | string): GDString;
    public base64_to_utf8(base64Str: GDString | StringName | string): GDString;


}

declare global {
    const Marshalls: _Marshalls
}
