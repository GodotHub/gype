
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class RDAttachmentFormat extends RefCounted {

    
    /**     * The raw type is 'int'     */
    public format: number;    
    /**     * The raw type is 'int'     */
    public samples: number;    
    /**     * The raw type is 'int'     */
    public usage_flags: number;
    public set_format(member: number): void;
    public get_format(): number;
    public set_samples(member: number): void;
    public get_samples(): number;
    public set_usage_flags(member: number): void;
    public get_usage_flags(): number;


}

