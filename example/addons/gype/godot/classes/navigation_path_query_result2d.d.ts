
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class NavigationPathQueryResult2D extends RefCounted {

    
    /**     * The raw type is 'PackedVector2Array'     */
    public path: PackedVector2Array;    
    /**     * The raw type is 'PackedInt32Array'     */
    public path_types: PackedInt32Array;    
    /**     * The raw type is 'typedarray::RID'     */
    public path_rids: Array<any>;    
    /**     * The raw type is 'PackedInt64Array'     */
    public path_owner_ids: PackedInt64Array;    
    /**     * The raw type is 'float'     */
    public path_length: number;
    public set_path(path: PackedVector2Array): void;
    public get_path(): PackedVector2Array;
    public set_path_types(pathTypes: PackedInt32Array): void;
    public get_path_types(): PackedInt32Array;
    public set_path_rids(pathRids: Array<any>): void;
    public get_path_rids(): Array<any>;
    public set_path_owner_ids(pathOwnerIds: PackedInt64Array): void;
    public get_path_owner_ids(): PackedInt64Array;
    public set_path_length(length: number): void;
    public get_path_length(): number;
    public reset(): void;


    public static readonly PathSegmentType: {
        PATH_SEGMENT_TYPE_REGION: 0;
        PATH_SEGMENT_TYPE_LINK: 1;
    };
}

