
import type { GDExtension } from '@godot/classes/gd_extension';
import type { GodotObject } from '@godot/classes/godot_object';


export declare class _GDExtensionManager extends GodotObject {


    public load_extension(path: GDString | StringName | string): number;
    public reload_extension(path: GDString | StringName | string): number;
    public unload_extension(path: GDString | StringName | string): number;
    public is_extension_loaded(path: GDString | StringName | string): boolean;
    public get_loaded_extensions(): PackedStringArray;
    public get_extension(path: GDString | StringName | string): GDExtension;

    
    public readonly extensions_reloaded: Signal<() => void>;
    public readonly extension_loaded: Signal<(extension: GDExtension) => void>;
    public readonly extension_unloading: Signal<(extension: GDExtension) => void>;

    public static readonly LoadStatus: {
        LOAD_STATUS_OK: 0;
        LOAD_STATUS_FAILED: 1;
        LOAD_STATUS_ALREADY_LOADED: 2;
        LOAD_STATUS_NOT_LOADED: 3;
        LOAD_STATUS_NEEDS_RESTART: 4;
    };
}

export const GDExtensionManager: _GDExtensionManager;
