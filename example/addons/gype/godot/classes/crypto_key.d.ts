
import type { Resource } from '@godot/classes/resource';


export declare class CryptoKey extends Resource {


    public save(path: GDString | StringName | string, publicOnly: boolean = false): number;
    public load(path: GDString | StringName | string, publicOnly: boolean = false): number;
    public is_public_only(): boolean;
    public save_to_string(publicOnly: boolean = false): GDString;
    public load_from_string(stringKey: GDString | StringName | string, publicOnly: boolean = false): number;


}

