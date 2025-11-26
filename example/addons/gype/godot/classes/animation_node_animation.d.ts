
import type { AnimationRootNode } from '@godot/classes/animation_root_node';


export declare class AnimationNodeAnimation extends AnimationRootNode {

    
    /**     * The raw type is 'StringName'     */
    public animation: StringName;    
    /**     * The raw type is 'int'     */
    public play_mode: number;    
    /**     * The raw type is 'bool'     */
    public advance_on_start: boolean;    
    /**     * The raw type is 'bool'     */
    public use_custom_timeline: boolean;    
    /**     * The raw type is 'float'     */
    public timeline_length: number;    
    /**     * The raw type is 'bool'     */
    public stretch_time_scale: boolean;    
    /**     * The raw type is 'float'     */
    public start_offset: number;    
    /**     * The raw type is 'int'     */
    public loop_mode: number;
    public set_animation(name: GDString | StringName | string): void;
    public get_animation(): StringName;
    public set_play_mode(mode: number): void;
    public get_play_mode(): number;
    public set_advance_on_start(advanceOnStart: boolean): void;
    public is_advance_on_start(): boolean;
    public set_use_custom_timeline(useCustomTimeline: boolean): void;
    public is_using_custom_timeline(): boolean;
    public set_timeline_length(timelineLength: number): void;
    public get_timeline_length(): number;
    public set_stretch_time_scale(stretchTimeScale: boolean): void;
    public is_stretching_time_scale(): boolean;
    public set_start_offset(startOffset: number): void;
    public get_start_offset(): number;
    public set_loop_mode(loomode: number): void;
    public get_loop_mode(): number;


    public static readonly PlayMode: {
        PLAY_MODE_FORWARD: 0;
        PLAY_MODE_BACKWARD: 1;
    };
}

