
import type { Node } from '@godot/classes/node';
import type { Resource } from '@godot/classes/resource';
import type { SceneState } from '@godot/classes/scene_state';


export declare class PackedScene extends Resource {


    public pack(path: Node): number;
    public instantiate(editState: number = 0): Node;
    public can_instantiate(): boolean;
    public get_state(): SceneState;


    public static readonly GenEditState: {
        GEN_EDIT_STATE_DISABLED: 0;
        GEN_EDIT_STATE_INSTANCE: 1;
        GEN_EDIT_STATE_MAIN: 2;
        GEN_EDIT_STATE_MAIN_INHERITED: 3;
    };
}

