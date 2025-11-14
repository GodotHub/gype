
import type { GDArray } from '@godot/builtins/gd_array';
import type { GDString } from '@godot/builtins/gd_string';
import type { Node } from '@godot/classes/node';
import type { PackedStringArray } from '@godot/builtins/packed_string_array';
import type { Resource } from '@godot/classes/resource';
import type { StringName } from '@godot/builtins/string_name';


export declare class ResourcePreloader extends Node {

    
    /**     * The raw type is 'Array'     */
    public resources: GDArray;
    public add_resource(name: GDString | StringName | string, resource: Resource): void;
    public remove_resource(name: GDString | StringName | string): void;
    public rename_resource(name: GDString | StringName | string, newname: GDString | StringName | string): void;
    public has_resource(name: GDString | StringName | string): boolean;
    public get_resource(name: GDString | StringName | string): Resource;
    public get_resource_list(): PackedStringArray;


}

