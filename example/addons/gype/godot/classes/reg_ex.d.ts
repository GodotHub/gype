
import type { GDString } from '@godot/builtins/gd_string';
import type { PackedStringArray } from '@godot/builtins/packed_string_array';
import type { RefCounted } from '@godot/classes/ref_counted';
import type { RegExMatch } from '@godot/classes/reg_ex_match';


export declare class RegEx extends RefCounted {


    public static create_from_string(pattern: GDString | StringName | string, showError: boolean = true): RegEx;
    public clear(): void;
    public compile(pattern: GDString | StringName | string, showError: boolean = true): number;
    public search(subject: GDString | StringName | string, offset: number = 0, end: number = -1): RegExMatch;
    public search_all(subject: GDString | StringName | string, offset: number = 0, end: number = -1): Array<any>;
    public sub(subject: GDString | StringName | string, replacement: GDString | StringName | string, all: boolean = false, offset: number = 0, end: number = -1): GDString;
    public is_valid(): boolean;
    public get_pattern(): GDString;
    public get_group_count(): number;
    public get_names(): PackedStringArray;


}

