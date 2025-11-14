
import type { Vector2i } from '@godot/builtins/vector2i';
import type { Viewport } from '@godot/classes/viewport';


export declare class SubViewport extends Viewport {

    
    /**     * The raw type is 'Vector2i'     */
    public size: Vector2i;    
    /**     * The raw type is 'Vector2i'     */
    public size_2d_override: Vector2i;    
    /**     * The raw type is 'bool'     */
    public size_2d_override_stretch: boolean;    
    /**     * The raw type is 'int'     */
    public render_target_clear_mode: number;    
    /**     * The raw type is 'int'     */
    public render_target_update_mode: number;
    public set_size(size: Vector2i): void;
    public get_size(): Vector2i;
    public set_size_2d_override(size: Vector2i): void;
    public get_size_2d_override(): Vector2i;
    public set_size_2d_override_stretch(enable: boolean): void;
    public is_size_2d_override_stretch_enabled(): boolean;
    public set_update_mode(mode: number): void;
    public get_update_mode(): number;
    public set_clear_mode(mode: number): void;
    public get_clear_mode(): number;


    public static readonly ClearMode: {
        CLEAR_MODE_ALWAYS: 0;
        CLEAR_MODE_NEVER: 1;
        CLEAR_MODE_ONCE: 2;
    };
    public static readonly UpdateMode: {
        UPDATE_DISABLED: 0;
        UPDATE_ONCE: 1;
        UPDATE_WHEN_VISIBLE: 2;
        UPDATE_WHEN_PARENT_VISIBLE: 3;
        UPDATE_ALWAYS: 4;
    };
}

