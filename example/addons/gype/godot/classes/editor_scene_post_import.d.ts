
import type { GodotObject } from '@godot/classes/godot_object';
import type { Node } from '@godot/classes/node';
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class EditorScenePostImport extends RefCounted {


    public _post_import(scene: Node): GodotObject;
    public get_source_file(): GDString;


}

