
import type { Node } from '@godot/classes/node';


export declare class Timer extends Node {

    
    /**     * The raw type is 'int'     */
    public process_callback: number;    
    /**     * The raw type is 'float'     */
    public wait_time: number;    
    /**     * The raw type is 'bool'     */
    public one_shot: boolean;    
    /**     * The raw type is 'bool'     */
    public autostart: boolean;    
    /**     * The raw type is 'bool'     */
    public paused: boolean;    
    /**     * The raw type is 'bool'     */
    public ignore_time_scale: boolean;    
    /**     * The raw type is 'float'     */
    public time_left: number;
    public set_wait_time(timeSec: number): void;
    public get_wait_time(): number;
    public set_one_shot(enable: boolean): void;
    public is_one_shot(): boolean;
    public set_autostart(enable: boolean): void;
    public has_autostart(): boolean;
    public start(timeSec: number = -1): void;
    public stop(): void;
    public set_paused(paused: boolean): void;
    public is_paused(): boolean;
    public set_ignore_time_scale(ignore: boolean): void;
    public is_ignoring_time_scale(): boolean;
    public is_stopped(): boolean;
    public get_time_left(): number;
    public set_timer_process_callback(callback: number): void;
    public get_timer_process_callback(): number;

    
    public readonly timeout: Signal<() => void>;

    public static readonly TimerProcessCallback: {
        TIMER_PROCESS_PHYSICS: 0;
        TIMER_PROCESS_IDLE: 1;
    };
}

