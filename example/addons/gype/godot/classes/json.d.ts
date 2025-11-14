
import type { GDString } from '@godot/builtins/gd_string';
import type { Resource } from '@godot/classes/resource';


export declare class JSON extends Resource {

    
    /**     * The raw type is 'Variant'     */
    public data: any;
    public static stringify(data: any, indent: GDString | StringName | string = "", sortKeys: boolean = true, fullPrecision: boolean = false): GDString;
    public static parse_string(jsonString: GDString | StringName | string): any;
    public parse(jsonText: GDString | StringName | string, keetext: boolean = false): number;
    public get_data(): any;
    public set_data(data: any): void;
    public get_parsed_text(): GDString;
    public get_error_line(): number;
    public get_error_message(): GDString;
    public static from_native(variant: any, fullObjects: boolean = false): any;
    public static to_native(json: any, allowObjects: boolean = false): any;


}

