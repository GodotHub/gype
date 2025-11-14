
import type { GDString } from '@godot/builtins/gd_string';
import type { Resource } from '@godot/classes/resource';
import type { VideoStreamPlayback } from '@godot/classes/video_stream_playback';


export declare class VideoStream extends Resource {

    
    /**     * The raw type is 'String'     */
    public file: GDString;
    public _instantiate_playback(): VideoStreamPlayback;
    public set_file(file: GDString | StringName | string): void;
    public get_file(): GDString;


}

