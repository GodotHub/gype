
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class PCKPacker extends RefCounted {


    public pck_start(pckPath: GDString | StringName | string, alignment: number = 32, key: GDString | StringName | string = "0000000000000000000000000000000000000000000000000000000000000000", encryptDirectory: boolean = false): number;
    public add_file(targetPath: GDString | StringName | string, sourcePath: GDString | StringName | string, encrypt: boolean = false): number;
    public add_file_removal(targetPath: GDString | StringName | string): number;
    public flush(verbose: boolean = false): number;


}

