
import type { Callable } from '@godot/builtins/callable';
import type { GDString } from '@godot/builtins/gd_string';
import type { GodotObject } from '@godot/classes/godot_object';


export declare class WorkerThreadPool extends GodotObject {


    public add_task(action: Callable | Function, highPriority: boolean = false, description: GDString | StringName | string = ""): number;
    public is_task_completed(taskId: number): boolean;
    public wait_for_task_completion(taskId: number): number;
    public get_caller_task_id(): number;
    public add_group_task(action: Callable | Function, elements: number, tasksNeeded: number = -1, highPriority: boolean = false, description: GDString | StringName | string = ""): number;
    public is_group_task_completed(grouid: number): boolean;
    public get_group_processed_element_count(grouid: number): number;
    public wait_for_group_task_completion(grouid: number): void;
    public get_caller_group_id(): number;


}


/**
 * A singleton instance of WorkerThreadPool.
 * This is a global variable, available from anywhere.
 */
export const WorkerThreadPool: WorkerThreadPool;
