


export declare class GodotObject {


    public get_class(): GDString;
    public is_class(_class: GDString | StringName | string): boolean;
    public set(property: GDString | StringName | string, value: any): void;
    public get(property: GDString | StringName | string): any;
    public set_indexed(property_path: NodePath | GDString | string, value: any): void;
    public get_indexed(property_path: NodePath | GDString | string): any;
    public get_property_list(): Array<any>;
    public get_method_list(): Array<any>;
    public property_can_revert(property: GDString | StringName | string): boolean;
    public property_get_revert(property: GDString | StringName | string): any;
    public notification(what: number, reversed: boolean): void;
    public to_string(): GDString;
    public get_instance_id(): number;
    public set_script(script: any): void;
    public get_script(): any;
    public set_meta(name: GDString | StringName | string, value: any): void;
    public remove_meta(name: GDString | StringName | string): void;
    public get_meta(name: GDString | StringName | string, _default: any): any;
    public has_meta(name: GDString | StringName | string): boolean;
    public get_meta_list(): Array<any>;
    public add_user_signal(signal: GDString | StringName | string, arguments: GDArray): void;
    public has_user_signal(signal: GDString | StringName | string): boolean;
    public remove_user_signal(signal: GDString | StringName | string): void;
    public emit_signal(signal: GDString | StringName | string, ...args: any[]): number;
    public call(method: GDString | StringName | string, ...args: any[]): any;
    public call_deferred(method: GDString | StringName | string, ...args: any[]): any;
    public set_deferred(property: GDString | StringName | string, value: any): void;
    public callv(method: GDString | StringName | string, arg_array: GDArray): any;
    public has_method(method: GDString | StringName | string): boolean;
    public get_method_argument_count(method: GDString | StringName | string): number;
    public has_signal(signal: GDString | StringName | string): boolean;
    public get_signal_list(): Array<any>;
    public get_signal_connection_list(signal: GDString | StringName | string): Array<any>;
    public get_incoming_connections(): Array<any>;
    public connect(signal: GDString | StringName | string, callable: Callable, flags: number): number;
    public disconnect(signal: GDString | StringName | string, callable: Callable): void;
    public is_connected(signal: GDString | StringName | string, callable: Callable): boolean;
    public has_connections(signal: GDString | StringName | string): boolean;
    public set_block_signals(enable: boolean): void;
    public is_blocking_signals(): boolean;
    public notify_property_list_changed(): void;
    public set_message_translation(enable: boolean): void;
    public can_translate_messages(): boolean;
    public tr(message: GDString | StringName | string, context: GDString | StringName | string): GDString;
    public tr_n(message: GDString | StringName | string, plural_message: GDString | StringName | string, n: number, context: GDString | StringName | string): GDString;
    public get_translation_domain(): StringName;
    public set_translation_domain(domain: GDString | StringName | string): void;
    public is_queued_for_deletion(): boolean;
    public cancel_free(): void;

    
    public readonly script_changed: Signal<() => void>;
    public readonly property_list_changed: Signal<() => void>;

    public static readonly ConnectFlags: {
        CONNECT_DEFERRED: 1;
        CONNECT_PERSIST: 2;
        CONNECT_ONE_SHOT: 4;
        CONNECT_REFERENCE_COUNTED: 8;
        CONNECT_APPEND_SOURCE_OBJECT: 16;
    };
}

