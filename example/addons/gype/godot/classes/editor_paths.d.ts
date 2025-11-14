
import type { GDString } from '@godot/builtins/gd_string';
import type { GodotObject } from '@godot/classes/godot_object';


export declare class EditorPaths extends GodotObject {


    public get_data_dir(): GDString;
    public get_config_dir(): GDString;
    public get_cache_dir(): GDString;
    public is_self_contained(): boolean;
    public get_self_contained_file(): GDString;
    public get_project_settings_dir(): GDString;


}

