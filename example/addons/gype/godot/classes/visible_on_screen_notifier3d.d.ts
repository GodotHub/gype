
import type { AABB } from '@godot/builtins/aabb';
import type { Signal } from '@godot/builtins/signal';
import type { VisualInstance3D } from '@godot/classes/visual_instance3d';


export declare class VisibleOnScreenNotifier3D extends VisualInstance3D {

    
    /**     * The raw type is 'AABB'     */
    public aabb: AABB;
    public set_aabb(rect: AABB): void;
    public is_on_screen(): boolean;

    
    public readonly screen_entered: Signal<() => void>;
    public readonly screen_exited: Signal<() => void>;

}

