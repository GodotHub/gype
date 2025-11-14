
import type { Resource } from '@godot/classes/resource';
import type { SkeletonModificationStack2D } from '@godot/classes/skeleton_modification_stack2d';


export declare class SkeletonModification2D extends Resource {

    
    /**     * The raw type is 'bool'     */
    public enabled: boolean;    
    /**     * The raw type is 'int'     */
    public execution_mode: number;
    public _execute(delta: number): void;
    public _setup_modification(modificationStack: SkeletonModificationStack2D): void;
    public _draw_editor_gizmo(): void;
    public set_enabled(enabled: boolean): void;
    public get_enabled(): boolean;
    public get_modification_stack(): SkeletonModificationStack2D;
    public set_is_setup(isSetup: boolean): void;
    public get_is_setup(): boolean;
    public set_execution_mode(executionMode: number): void;
    public get_execution_mode(): number;
    public clamp_angle(angle: number, min: number, max: number, invert: boolean): number;
    public set_editor_draw_gizmo(drawGizmo: boolean): void;
    public get_editor_draw_gizmo(): boolean;


}

