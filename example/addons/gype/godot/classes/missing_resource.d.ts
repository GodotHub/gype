
import type { Resource } from '@godot/classes/resource';


export declare class MissingResource extends Resource {

    
    /**     * The raw type is 'String'     */
    public original_class: GDString;    
    /**     * The raw type is 'bool'     */
    public recording_properties: boolean;
    public set_original_class(name: GDString | StringName | string): void;
    public get_original_class(): GDString;
    public set_recording_properties(enable: boolean): void;
    public is_recording_properties(): boolean;


}

