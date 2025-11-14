
import type { GDArray } from '@godot/builtins/gd_array';
import type { GDString } from '@godot/builtins/gd_string';
import type { OpenXRAction } from '@godot/classes/open_xr_action';
import type { Resource } from '@godot/classes/resource';


export declare class OpenXRActionSet extends Resource {

    
    /**     * The raw type is 'String'     */
    public localized_name: GDString;    
    /**     * The raw type is 'int'     */
    public priority: number;    
    /**     * The raw type is 'OpenXRAction'     */
    public actions: GDArray;
    public set_localized_name(localizedName: GDString | StringName | string): void;
    public get_localized_name(): GDString;
    public set_priority(priority: number): void;
    public get_priority(): number;
    public get_action_count(): number;
    public set_actions(actions: GDArray): void;
    public get_actions(): GDArray;
    public add_action(action: OpenXRAction): void;
    public remove_action(action: OpenXRAction): void;


}

