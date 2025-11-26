
import type { Resource } from '@godot/classes/resource';


export declare class X509Certificate extends Resource {


    public save(path: GDString | StringName | string): number;
    public load(path: GDString | StringName | string): number;
    public save_to_string(): GDString;
    public load_from_string(_string: GDString | StringName | string): number;


}

