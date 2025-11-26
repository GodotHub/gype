
import type { Resource } from '@godot/classes/resource';


export declare class Material extends Resource {

    
    /**     * The raw type is 'int'     */
    public render_priority: number;    
    /**     * The raw type is 'Material'     */
    public next_pass: Material;
    public _get_shader_rid(): RID;
    public _get_shader_mode(): number;
    public _can_do_next_pass(): boolean;
    public _can_use_render_priority(): boolean;
    public set_next_pass(nextPass: Material): void;
    public get_next_pass(): Material;
    public set_render_priority(priority: number): void;
    public get_render_priority(): number;
    public inspect_native_shader_code(): void;
    public create_placeholder(): Resource;


}

