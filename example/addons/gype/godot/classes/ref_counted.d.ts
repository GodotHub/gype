
import type { GodotObject } from '@godot/classes/godot_object';


export declare class RefCounted extends GodotObject {


    public init_ref(): boolean;
    public reference(): boolean;
    public unreference(): boolean;
    public get_reference_count(): number;


}

