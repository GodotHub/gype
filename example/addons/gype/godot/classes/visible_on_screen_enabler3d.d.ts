
import type { VisibleOnScreenNotifier3D } from '@godot/classes/visible_on_screen_notifier3d';


export declare class VisibleOnScreenEnabler3D extends VisibleOnScreenNotifier3D {

    
    /**     * The raw type is 'int'     */
    public enable_mode: number;    
    /**     * The raw type is 'NodePath'     */
    public enable_node_path: NodePath;
    public set_enable_mode(mode: number): void;
    public get_enable_mode(): number;
    public set_enable_node_path(path: NodePath | GDString | string): void;
    public get_enable_node_path(): NodePath;


    public static readonly EnableMode: {
        ENABLE_MODE_INHERIT: 0;
        ENABLE_MODE_ALWAYS: 1;
        ENABLE_MODE_WHEN_PAUSED: 2;
    };
}

