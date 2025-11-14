
import type { EditorInterface } from '@godot/classes/editor_interface';
import type { Node } from '@godot/classes/node';
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class EditorScript extends RefCounted {


    public _run(): void;
    public add_root_node(node: Node): void;
    public get_scene(): Node;
    public get_editor_interface(): EditorInterface;


}

