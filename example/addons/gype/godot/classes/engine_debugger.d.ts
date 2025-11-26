
import type { EngineProfiler } from '@godot/classes/engine_profiler';
import type { GodotObject } from '@godot/classes/godot_object';
import type { ScriptLanguage } from '@godot/classes/script_language';


export declare class EngineDebugger extends GodotObject {


    public is_active(): boolean;
    public register_profiler(name: GDString | StringName | string, profiler: EngineProfiler): void;
    public unregister_profiler(name: GDString | StringName | string): void;
    public is_profiling(name: GDString | StringName | string): boolean;
    public has_profiler(name: GDString | StringName | string): boolean;
    public profiler_add_frame_data(name: GDString | StringName | string, data: GDArray): void;
    public profiler_enable(name: GDString | StringName | string, enable: boolean, arguments: GDArray = []): void;
    public register_message_capture(name: GDString | StringName | string, callable: Callable | Function): void;
    public unregister_message_capture(name: GDString | StringName | string): void;
    public has_capture(name: GDString | StringName | string): boolean;
    public line_poll(): void;
    public send_message(message: GDString | StringName | string, data: GDArray): void;
    public debug(canContinue: boolean = true, isErrorBreakpoint: boolean = false): void;
    public script_debug(language: ScriptLanguage, canContinue: boolean = true, isErrorBreakpoint: boolean = false): void;
    public set_lines_left(lines: number): void;
    public get_lines_left(): number;
    public set_depth(depth: number): void;
    public get_depth(): number;
    public is_breakpoint(line: number, source: GDString | StringName | string): boolean;
    public is_skipping_breakpoints(): boolean;
    public insert_breakpoint(line: number, source: GDString | StringName | string): void;
    public remove_breakpoint(line: number, source: GDString | StringName | string): void;
    public clear_breakpoints(): void;


}


/**
 * A singleton instance of EngineDebugger.
 * This is a global variable, available from anywhere.
 */
export const EngineDebugger: EngineDebugger;
