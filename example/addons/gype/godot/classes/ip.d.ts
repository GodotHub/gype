
import type { GodotObject } from '@godot/classes/godot_object';


export declare class _IP extends GodotObject {


    public resolve_hostname(host: GDString | StringName | string, itype: number = 3): GDString;
    public resolve_hostname_addresses(host: GDString | StringName | string, itype: number = 3): PackedStringArray;
    public resolve_hostname_queue_item(host: GDString | StringName | string, itype: number = 3): number;
    public get_resolve_item_status(id: number): number;
    public get_resolve_item_address(id: number): GDString;
    public get_resolve_item_addresses(id: number): GDArray;
    public erase_resolve_item(id: number): void;
    public get_local_addresses(): PackedStringArray;
    public get_local_interfaces(): Array<any>;
    public clear_cache(hostname: GDString | StringName | string = ""): void;


    public static readonly ResolverStatus: {
        RESOLVER_STATUS_NONE: 0;
        RESOLVER_STATUS_WAITING: 1;
        RESOLVER_STATUS_DONE: 2;
        RESOLVER_STATUS_ERROR: 3;
    };
    public static readonly Type: {
        TYPE_NONE: 0;
        TYPE_IPV4: 1;
        TYPE_IPV6: 2;
        TYPE_ANY: 3;
    };
}

export const IP: _IP;
