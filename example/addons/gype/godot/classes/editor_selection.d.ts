
import type { GodotObject } from '@godot/classes/godot_object';
import type { Node } from '@godot/classes/node';
import type { Signal } from '@godot/builtins/signal';


export declare class EditorSelection extends GodotObject {


    public clear(): void;
    public add_node(node: Node): void;
    public remove_node(node: Node): void;
    public get_selected_nodes(): Array<any>;
    public get_top_selected_nodes(): Array<any>;
    public get_transformable_selected_nodes(): Array<any>;

    
    public readonly selection_changed: Signal<() => void>;

}

