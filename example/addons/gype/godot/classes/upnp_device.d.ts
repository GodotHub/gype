
import type { GDString } from '@godot/builtins/gd_string';
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class UPNPDevice extends RefCounted {

    
    /**     * The raw type is 'String'     */
    public description_url: GDString;    
    /**     * The raw type is 'String'     */
    public service_type: GDString;    
    /**     * The raw type is 'String'     */
    public igd_control_url: GDString;    
    /**     * The raw type is 'String'     */
    public igd_service_type: GDString;    
    /**     * The raw type is 'String'     */
    public igd_our_addr: GDString;    
    /**     * The raw type is 'int'     */
    public igd_status: number;
    public is_valid_gateway(): boolean;
    public query_external_address(): GDString;
    public add_port_mapping(port: number, portInternal: number = 0, desc: GDString | StringName | string = "", proto: GDString | StringName | string = "UDP", duration: number = 0): number;
    public delete_port_mapping(port: number, proto: GDString | StringName | string = "UDP"): number;
    public set_description_url(url: GDString | StringName | string): void;
    public get_description_url(): GDString;
    public set_service_type(_type: GDString | StringName | string): void;
    public get_service_type(): GDString;
    public set_igd_control_url(url: GDString | StringName | string): void;
    public get_igd_control_url(): GDString;
    public set_igd_service_type(_type: GDString | StringName | string): void;
    public get_igd_service_type(): GDString;
    public set_igd_our_addr(addr: GDString | StringName | string): void;
    public get_igd_our_addr(): GDString;
    public set_igd_status(status: number): void;
    public get_igd_status(): number;


    public static readonly IGDStatus: {
        IGD_STATUS_OK: 0;
        IGD_STATUS_HTTP_ERROR: 1;
        IGD_STATUS_HTTP_EMPTY: 2;
        IGD_STATUS_NO_URLS: 3;
        IGD_STATUS_NO_IGD: 4;
        IGD_STATUS_DISCONNECTED: 5;
        IGD_STATUS_UNKNOWN_DEVICE: 6;
        IGD_STATUS_INVALID_CONTROL: 7;
        IGD_STATUS_MALLOC_ERROR: 8;
        IGD_STATUS_UNKNOWN_ERROR: 9;
    };
}

