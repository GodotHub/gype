
import type { Resource } from '@godot/classes/resource';


export declare class OpenXRAction extends Resource {

    
    /**     * The raw type is 'String'     */
    public localized_name: GDString | StringName | string;    
    /**     * The raw type is 'int'     */
    public action_type: number;    
    /**     * The raw type is 'PackedStringArray'     */
    public toplevel_paths: PackedStringArray;
    public set_localized_name(localizedName: GDString | StringName | string): void;
    public get_localized_name(): GDString;
    public set_action_type(actionType: number): void;
    public get_action_type(): number;
    public set_toplevel_paths(toplevelPaths: PackedStringArray): void;
    public get_toplevel_paths(): PackedStringArray;


    public static readonly ActionType: {
        OPENXR_ACTION_BOOL: 0;
        OPENXR_ACTION_FLOAT: 1;
        OPENXR_ACTION_VECTOR2: 2;
        OPENXR_ACTION_POSE: 3;
    };
}

