
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class RDFramebufferPass extends RefCounted {

    
    /**     * The raw type is 'PackedInt32Array'     */
    public color_attachments: PackedInt32Array;    
    /**     * The raw type is 'PackedInt32Array'     */
    public input_attachments: PackedInt32Array;    
    /**     * The raw type is 'PackedInt32Array'     */
    public resolve_attachments: PackedInt32Array;    
    /**     * The raw type is 'PackedInt32Array'     */
    public preserve_attachments: PackedInt32Array;    
    /**     * The raw type is 'int'     */
    public depth_attachment: number;
    public set_color_attachments(member: PackedInt32Array): void;
    public get_color_attachments(): PackedInt32Array;
    public set_input_attachments(member: PackedInt32Array): void;
    public get_input_attachments(): PackedInt32Array;
    public set_resolve_attachments(member: PackedInt32Array): void;
    public get_resolve_attachments(): PackedInt32Array;
    public set_preserve_attachments(member: PackedInt32Array): void;
    public get_preserve_attachments(): PackedInt32Array;
    public set_depth_attachment(member: number): void;
    public get_depth_attachment(): number;


}

