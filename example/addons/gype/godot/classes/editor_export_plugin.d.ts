
import { RefCounted } from "@godot/classes/ref_counted";
import { EditorExportPlatform } from "@godot/classes/editor_export_platform";
import { Resource } from "@godot/classes/resource";
import { Node } from "@godot/classes/node";

export declare class EditorExportPlugin extends RefCounted{
  public _export_file(_path: String, _type: String, _features: PackedStringArray): void;
  public _export_begin(_features: PackedStringArray, _is_debug: boolean, _path: String, _flags: number): void;
  public _export_end(): void;
  public _begin_customize_resources(_platform: EditorExportPlatform, _features: PackedStringArray): boolean;
  public _customize_resource(_resource: Resource, _path: String): Resource;
  public _begin_customize_scenes(_platform: EditorExportPlatform, _features: PackedStringArray): boolean;
  public _customize_scene(_scene: Node, _path: String): Node;
  public _get_customization_configuration_hash(): number;
  public _end_customize_scenes(): void;
  public _end_customize_resources(): void;
  public _get_export_options(_platform: EditorExportPlatform): GDArray;
  public _get_export_options_overrides(_platform: EditorExportPlatform): Dictionary;
  public _should_update_export_options(_platform: EditorExportPlatform): boolean;
  public _get_export_option_warning(_platform: EditorExportPlatform, _option: String): String;
  public _get_export_features(_platform: EditorExportPlatform, _debug: boolean): PackedStringArray;
  public _get_name(): String;
  public _supports_platform(_platform: EditorExportPlatform): boolean;
  public _get_android_dependencies(_platform: EditorExportPlatform, _debug: boolean): PackedStringArray;
  public _get_android_dependencies_maven_repos(_platform: EditorExportPlatform, _debug: boolean): PackedStringArray;
  public _get_android_libraries(_platform: EditorExportPlatform, _debug: boolean): PackedStringArray;
  public _get_android_manifest_activity_element_contents(_platform: EditorExportPlatform, _debug: boolean): String;
  public _get_android_manifest_application_element_contents(_platform: EditorExportPlatform, _debug: boolean): String;
  public _get_android_manifest_element_contents(_platform: EditorExportPlatform, _debug: boolean): String;
  public add_shared_object(_path: String, _tags: PackedStringArray, _target: String): void;
  public add_ios_project_static_lib(_path: String): void;
  public add_file(_path: String, _file: PackedByteArray, _remap: boolean): void;
  public add_ios_framework(_path: String): void;
  public add_ios_embedded_framework(_path: String): void;
  public add_ios_plist_content(_plist_content: String): void;
  public add_ios_linker_flags(_flags: String): void;
  public add_ios_bundle_file(_path: String): void;
  public add_ios_cpp_code(_code: String): void;
  public add_macos_plugin_file(_path: String): void;
  public skip(): void;
  public get_option(_name: StringName): any;
}