
import type { GDString } from '@godot/builtins/gd_string';
import type { Node3D } from '@godot/classes/node3d';
import type { NodePath } from '@godot/builtins/node_path';
import type { StringName } from '@godot/builtins/string_name';


export declare class XRFaceModifier3D extends Node3D {

    
    /**     * The raw type is 'String'     */
    public face_tracker: StringName;    
    /**     * The raw type is 'NodePath'     */
    public target: NodePath;
    public set_face_tracker(trackerName: GDString | StringName | string): void;
    public get_face_tracker(): StringName;
    public set_target(target: NodePath | GDString | string): void;
    public get_target(): NodePath;


}

