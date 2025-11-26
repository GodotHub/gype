
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class ConfigFile extends RefCounted {


    public set_value(section: GDString | StringName | string, key: GDString | StringName | string, value: any): void;
    public get_value(section: GDString | StringName | string, key: GDString | StringName | string, _default: any = null): any;
    public has_section(section: GDString | StringName | string): boolean;
    public has_section_key(section: GDString | StringName | string, key: GDString | StringName | string): boolean;
    public get_sections(): PackedStringArray;
    public get_section_keys(section: GDString | StringName | string): PackedStringArray;
    public erase_section(section: GDString | StringName | string): void;
    public erase_section_key(section: GDString | StringName | string, key: GDString | StringName | string): void;
    public load(path: GDString | StringName | string): number;
    public parse(data: GDString | StringName | string): number;
    public save(path: GDString | StringName | string): number;
    public encode_to_text(): GDString;
    public load_encrypted(path: GDString | StringName | string, key: PackedByteArray): number;
    public load_encrypted_pass(path: GDString | StringName | string, password: GDString | StringName | string): number;
    public save_encrypted(path: GDString | StringName | string, key: PackedByteArray): number;
    public save_encrypted_pass(path: GDString | StringName | string, password: GDString | StringName | string): number;
    public clear(): void;


}

