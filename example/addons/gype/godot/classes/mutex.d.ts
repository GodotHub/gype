
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class Mutex extends RefCounted {


    public lock(): void;
    public try_lock(): boolean;
    public unlock(): void;


}

