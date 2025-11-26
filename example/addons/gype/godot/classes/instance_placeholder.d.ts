
import type { Node } from '@godot/classes/node';
import type { PackedScene } from '@godot/classes/packed_scene';


export declare class InstancePlaceholder extends Node {


    public get_stored_values(withOrder: boolean = false): Dictionary;
    public create_instance(replace: boolean = false, customScene: PackedScene = null): Node;
    public get_instance_path(): GDString;


}

