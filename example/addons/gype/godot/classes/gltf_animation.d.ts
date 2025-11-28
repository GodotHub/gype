
import type { Resource } from '@godot/classes/resource';


export declare class GLTFAnimation extends Resource {

    
    /**     * The raw type is 'String'     */
    public original_name: GDString | StringName | string;    
    /**     * The raw type is 'bool'     */
    public loop: boolean;
    public get_original_name(): GDString;
    public set_original_name(originalName: GDString | StringName | string): void;
    public get_loop(): boolean;
    public set_loop(loop: boolean): void;
    public get_additional_data(extensionName: GDString | StringName | string): any;
    public set_additional_data(extensionName: GDString | StringName | string, additionalData: any): void;


}

