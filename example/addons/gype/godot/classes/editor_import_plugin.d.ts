
import type { Dictionary } from '@godot/builtins/dictionary';
import type { GDString } from '@godot/builtins/gd_string';
import type { PackedStringArray } from '@godot/builtins/packed_string_array';
import type { ResourceImporter } from '@godot/classes/resource_importer';
import type { StringName } from '@godot/builtins/string_name';


export declare class EditorImportPlugin extends ResourceImporter {


    public _get_importer_name(): GDString;
    public _get_visible_name(): GDString;
    public _get_preset_count(): number;
    public _get_preset_name(presetIndex: number): GDString;
    public _get_recognized_extensions(): PackedStringArray;
    public _get_import_options(path: GDString | StringName | string, presetIndex: number): Array<any>;
    public _get_save_extension(): GDString;
    public _get_resource_type(): GDString;
    public _get_priority(): number;
    public _get_import_order(): number;
    public _get_format_version(): number;
    public _get_option_visibility(path: GDString | StringName | string, optionName: GDString | StringName | string, options: Dictionary): boolean;
    public _import(sourceFile: GDString | StringName | string, savePath: GDString | StringName | string, options: Dictionary, platformVariants: Array<any>, genFiles: Array<any>): number;
    public _can_import_threaded(): boolean;
    public append_import_external_resource(path: GDString | StringName | string, customOptions: Dictionary = {}, customImporter: GDString | StringName | string = "", generatorParameters: any = null): number;


}

