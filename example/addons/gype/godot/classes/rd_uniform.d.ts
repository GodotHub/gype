
import type { RID } from '@godot/builtins/rid';
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class RDUniform extends RefCounted {

    
    /**     * The raw type is 'int'     */
    public uniform_type: number;    
    /**     * The raw type is 'int'     */
    public binding: number;
    public set_uniform_type(member: number): void;
    public get_uniform_type(): number;
    public set_binding(member: number): void;
    public get_binding(): number;
    public add_id(id: RID): void;
    public clear_ids(): void;
    public get_ids(): Array<any>;


}

