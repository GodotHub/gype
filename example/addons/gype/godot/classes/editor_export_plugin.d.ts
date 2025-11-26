
import type { EditorExportPlatform } from '@godot/classes/editor_export_platform';
import type { EditorExportPreset } from '@godot/classes/editor_export_preset';
import type { Node } from '@godot/classes/node';
import type { RefCounted } from '@godot/classes/ref_counted';
import type { Resource } from '@godot/classes/resource';


export declare class EditorExportPlugin extends RefCounted {


    public _export_file(path: GDString | StringName | string, _type: GDString | StringName | string, features: PackedStringArray): void;
    public _export_begin(features: PackedStringArray, isDebug: boolean, path: GDString | StringName | string, flags: number): void;
    public _export_end(): void;
    public _begin_customize_resources(platform: EditorExportPlatform, features: PackedStringArray): boolean;
    public _customize_resource(resource: Resource, path: GDString | StringName | string): Resource;
    public _begin_customize_scenes(platform: EditorExportPlatform, features: PackedStringArray): boolean;
    public _customize_scene(scene: Node, path: GDString | StringName | string): Node;
    public _get_customization_configuration_hash(): number;
    public _end_customize_scenes(): void;
    public _end_customize_resources(): void;
    public _get_export_options(platform: EditorExportPlatform): Array<any>;
    public _get_export_options_overrides(platform: EditorExportPlatform): Dictionary;
    public _should_update_export_options(platform: EditorExportPlatform): boolean;
    public _get_export_option_visibility(platform: EditorExportPlatform, option: GDString | StringName | string): boolean;
    public _get_export_option_warning(platform: EditorExportPlatform, option: GDString | StringName | string): GDString;
    public _get_export_features(platform: EditorExportPlatform, debug: boolean): PackedStringArray;
    public _get_name(): GDString;
    public _supports_platform(platform: EditorExportPlatform): boolean;
    public _get_android_dependencies(platform: EditorExportPlatform, debug: boolean): PackedStringArray;
    public _get_android_dependencies_maven_repos(platform: EditorExportPlatform, debug: boolean): PackedStringArray;
    public _get_android_libraries(platform: EditorExportPlatform, debug: boolean): PackedStringArray;
    public _get_android_manifest_activity_element_contents(platform: EditorExportPlatform, debug: boolean): GDString;
    public _get_android_manifest_application_element_contents(platform: EditorExportPlatform, debug: boolean): GDString;
    public _get_android_manifest_element_contents(platform: EditorExportPlatform, debug: boolean): GDString;
    public _update_android_prebuilt_manifest(platform: EditorExportPlatform, manifestData: PackedByteArray): PackedByteArray;
    public add_shared_object(path: GDString | StringName | string, tags: PackedStringArray, target: GDString | StringName | string): void;
    public add_file(path: GDString | StringName | string, file: PackedByteArray, remap: boolean): void;
    public add_apple_embedded_platform_project_static_lib(path: GDString | StringName | string): void;
    public add_apple_embedded_platform_framework(path: GDString | StringName | string): void;
    public add_apple_embedded_platform_embedded_framework(path: GDString | StringName | string): void;
    public add_apple_embedded_platform_plist_content(plistContent: GDString | StringName | string): void;
    public add_apple_embedded_platform_linker_flags(flags: GDString | StringName | string): void;
    public add_apple_embedded_platform_bundle_file(path: GDString | StringName | string): void;
    public add_apple_embedded_platform_cpp_code(code: GDString | StringName | string): void;
    public add_ios_project_static_lib(path: GDString | StringName | string): void;
    public add_ios_framework(path: GDString | StringName | string): void;
    public add_ios_embedded_framework(path: GDString | StringName | string): void;
    public add_ios_plist_content(plistContent: GDString | StringName | string): void;
    public add_ios_linker_flags(flags: GDString | StringName | string): void;
    public add_ios_bundle_file(path: GDString | StringName | string): void;
    public add_ios_cpp_code(code: GDString | StringName | string): void;
    public add_macos_plugin_file(path: GDString | StringName | string): void;
    public skip(): void;
    public get_option(name: GDString | StringName | string): any;
    public get_export_preset(): EditorExportPreset;
    public get_export_platform(): EditorExportPlatform;


}

