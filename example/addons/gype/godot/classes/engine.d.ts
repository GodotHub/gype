
import type { GodotObject } from '@godot/classes/godot_object';
import type { MainLoop } from '@godot/classes/main_loop';
import type { ScriptLanguage } from '@godot/classes/script_language';


export declare class Engine extends GodotObject {

    
    /**     * The raw type is 'bool'     */
    public print_error_messages: boolean;    
    /**     * The raw type is 'bool'     */
    public print_to_stdout: boolean;    
    /**     * The raw type is 'int'     */
    public physics_ticks_per_second: number;    
    /**     * The raw type is 'int'     */
    public max_physics_steps_per_frame: number;    
    /**     * The raw type is 'int'     */
    public max_fps: number;    
    /**     * The raw type is 'float'     */
    public time_scale: number;    
    /**     * The raw type is 'float'     */
    public physics_jitter_fix: number;
    public set_physics_ticks_per_second(physicsTicksPerSecond: number): void;
    public get_physics_ticks_per_second(): number;
    public set_max_physics_steps_per_frame(maxPhysicsSteps: number): void;
    public get_max_physics_steps_per_frame(): number;
    public set_physics_jitter_fix(physicsJitterFix: number): void;
    public get_physics_jitter_fix(): number;
    public get_physics_interpolation_fraction(): number;
    public set_max_fps(maxFps: number): void;
    public get_max_fps(): number;
    public set_time_scale(timeScale: number): void;
    public get_time_scale(): number;
    public get_frames_drawn(): number;
    public get_frames_per_second(): number;
    public get_physics_frames(): number;
    public get_process_frames(): number;
    public get_main_loop(): MainLoop;
    public get_version_info(): Dictionary;
    public get_author_info(): Dictionary;
    public get_copyright_info(): Array<any>;
    public get_donor_info(): Dictionary;
    public get_license_info(): Dictionary;
    public get_license_text(): GDString;
    public get_architecture_name(): GDString;
    public is_in_physics_frame(): boolean;
    public has_singleton(name: GDString | StringName | string): boolean;
    public get_singleton(name: GDString | StringName | string): GodotObject;
    public register_singleton(name: GDString | StringName | string, instance: GodotObject): void;
    public unregister_singleton(name: GDString | StringName | string): void;
    public get_singleton_list(): PackedStringArray;
    public register_script_language(language: ScriptLanguage): number;
    public unregister_script_language(language: ScriptLanguage): number;
    public get_script_language_count(): number;
    public get_script_language(index: number): ScriptLanguage;
    public capture_script_backtraces(includeVariables: boolean = false): Array<any>;
    public is_editor_hint(): boolean;
    public is_embedded_in_editor(): boolean;
    public get_write_movie_path(): GDString;
    public set_print_to_stdout(enabled: boolean): void;
    public is_printing_to_stdout(): boolean;
    public set_print_error_messages(enabled: boolean): void;
    public is_printing_error_messages(): boolean;


}


/**
 * A singleton instance of Engine.
 * This is a global variable, available from anywhere.
 */
export const Engine: Engine;
