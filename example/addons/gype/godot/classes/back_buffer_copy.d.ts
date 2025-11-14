
import type { Node2D } from '@godot/classes/node2d';
import type { Rect2 } from '@godot/builtins/rect2';


export declare class BackBufferCopy extends Node2D {

    
    /**     * The raw type is 'int'     */
    public copy_mode: number;    
    /**     * The raw type is 'Rect2'     */
    public rect: Rect2;
    public set_rect(rect: Rect2): void;
    public get_rect(): Rect2;
    public set_copy_mode(copyMode: number): void;
    public get_copy_mode(): number;


    public static readonly CopyMode: {
        COPY_MODE_DISABLED: 0;
        COPY_MODE_RECT: 1;
        COPY_MODE_VIEWPORT: 2;
    };
}

