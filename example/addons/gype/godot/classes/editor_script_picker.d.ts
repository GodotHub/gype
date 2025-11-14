
import type { EditorResourcePicker } from '@godot/classes/editor_resource_picker';
import type { Node } from '@godot/classes/node';


export declare class EditorScriptPicker extends EditorResourcePicker {

    
    /**     * The raw type is 'Node'     */
    public script_owner: Node;
    public set_script_owner(ownerNode: Node): void;
    public get_script_owner(): Node;


}

