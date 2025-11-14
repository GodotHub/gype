
import type { Resource } from '@godot/classes/resource';


export declare class GDExtension extends Resource {


    public is_library_open(): boolean;
    public get_minimum_library_initialization_level(): number;


    public static readonly InitializationLevel: {
        INITIALIZATION_LEVEL_CORE: 0;
        INITIALIZATION_LEVEL_SERVERS: 1;
        INITIALIZATION_LEVEL_SCENE: 2;
        INITIALIZATION_LEVEL_EDITOR: 3;
    };
}

