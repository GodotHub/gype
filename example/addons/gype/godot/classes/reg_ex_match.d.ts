
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class RegExMatch extends RefCounted {

    
    /**     * The raw type is 'String'     */
    public subject: GDString;    
    /**     * The raw type is 'Dictionary'     */
    public names: Dictionary;    
    /**     * The raw type is 'Array'     */
    public strings: GDArray;
    public get_subject(): GDString;
    public get_group_count(): number;
    public get_names(): Dictionary;
    public get_strings(): PackedStringArray;
    public get_string(name: any = 0): GDString;
    public get_start(name: any = 0): number;
    public get_end(name: any = 0): number;


}

