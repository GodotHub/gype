
import type { EditorFileSystemDirectory } from '@godot/classes/editor_file_system_directory';
import type { Node } from '@godot/classes/node';


export declare class EditorFileSystem extends Node {


    public get_filesystem(): EditorFileSystemDirectory;
    public is_scanning(): boolean;
    public get_scanning_progress(): number;
    public scan(): void;
    public scan_sources(): void;
    public update_file(path: GDString | StringName | string): void;
    public get_filesystem_path(path: GDString | StringName | string): EditorFileSystemDirectory;
    public get_file_type(path: GDString | StringName | string): GDString;
    public reimport_files(files: PackedStringArray): void;

    
    public readonly filesystem_changed: Signal<() => void>;
    public readonly script_classes_updated: Signal<() => void>;
    public readonly sources_changed: Signal<(exist: boolean) => void>;
    public readonly resources_reimporting: Signal<(resources: PackedStringArray) => void>;
    public readonly resources_reimported: Signal<(resources: PackedStringArray) => void>;
    public readonly resources_reload: Signal<(resources: PackedStringArray) => void>;

}

