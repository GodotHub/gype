
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class Semaphore extends RefCounted {


    public wait(): void;
    public try_wait(): boolean;
    public post(count: number = 1): void;


}

