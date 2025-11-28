
import type { RefCounted } from '@godot/classes/ref_counted';
import type { UPNPDevice } from '@godot/classes/upnp_device';


export declare class UPNP extends RefCounted {

    
    /**     * The raw type is 'String'     */
    public discover_multicast_if: GDString | StringName | string;    
    /**     * The raw type is 'int'     */
    public discover_local_port: number;    
    /**     * The raw type is 'bool'     */
    public discover_ipv6: boolean;
    public get_device_count(): number;
    public get_device(index: number): UPNPDevice;
    public add_device(device: UPNPDevice): void;
    public set_device(index: number, device: UPNPDevice): void;
    public remove_device(index: number): void;
    public clear_devices(): void;
    public get_gateway(): UPNPDevice;
    public discover(timeout: number = 2000, ttl: number = 2, deviceFilter: GDString | StringName | string = "InternetGatewayDevice"): number;
    public query_external_address(): GDString;
    public add_port_mapping(port: number, portInternal: number = 0, desc: GDString | StringName | string = "", proto: GDString | StringName | string = "UDP", duration: number = 0): number;
    public delete_port_mapping(port: number, proto: GDString | StringName | string = "UDP"): number;
    public set_discover_multicast_if(mIf: GDString | StringName | string): void;
    public get_discover_multicast_if(): GDString;
    public set_discover_local_port(port: number): void;
    public get_discover_local_port(): number;
    public set_discover_ipv6(ipv6: boolean): void;
    public is_discover_ipv6(): boolean;


    public static readonly UPNPResult: {
        UPNP_RESULT_SUCCESS: 0;
        UPNP_RESULT_NOT_AUTHORIZED: 1;
        UPNP_RESULT_PORT_MAPPING_NOT_FOUND: 2;
        UPNP_RESULT_INCONSISTENT_PARAMETERS: 3;
        UPNP_RESULT_NO_SUCH_ENTRY_IN_ARRAY: 4;
        UPNP_RESULT_ACTION_FAILED: 5;
        UPNP_RESULT_SRC_IP_WILDCARD_NOT_PERMITTED: 6;
        UPNP_RESULT_EXT_PORT_WILDCARD_NOT_PERMITTED: 7;
        UPNP_RESULT_INT_PORT_WILDCARD_NOT_PERMITTED: 8;
        UPNP_RESULT_REMOTE_HOST_MUST_BE_WILDCARD: 9;
        UPNP_RESULT_EXT_PORT_MUST_BE_WILDCARD: 10;
        UPNP_RESULT_NO_PORT_MAPS_AVAILABLE: 11;
        UPNP_RESULT_CONFLICT_WITH_OTHER_MECHANISM: 12;
        UPNP_RESULT_CONFLICT_WITH_OTHER_MAPPING: 13;
        UPNP_RESULT_SAME_PORT_VALUES_REQUIRED: 14;
        UPNP_RESULT_ONLY_PERMANENT_LEASE_SUPPORTED: 15;
        UPNP_RESULT_INVALID_GATEWAY: 16;
        UPNP_RESULT_INVALID_PORT: 17;
        UPNP_RESULT_INVALID_PROTOCOL: 18;
        UPNP_RESULT_INVALID_DURATION: 19;
        UPNP_RESULT_INVALID_ARGS: 20;
        UPNP_RESULT_INVALID_RESPONSE: 21;
        UPNP_RESULT_INVALID_PARAM: 22;
        UPNP_RESULT_HTTP_ERROR: 23;
        UPNP_RESULT_SOCKET_ERROR: 24;
        UPNP_RESULT_MEM_ALLOC_ERROR: 25;
        UPNP_RESULT_NO_GATEWAY: 26;
        UPNP_RESULT_NO_DEVICES: 27;
        UPNP_RESULT_UNKNOWN_ERROR: 28;
    };
}

