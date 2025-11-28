
import type { InputEvent } from '@godot/classes/input_event';
import type { Resource } from '@godot/classes/resource';


export declare class Shortcut extends Resource {

    
    /**     * The raw type is 'typedarray::24/17:InputEvent'     */
    public events: GDArray | Array;
    public set_events(events: GDArray | Array): void;
    public get_events(): GDArray;
    public has_valid_event(): boolean;
    public matches_event(event: InputEvent): boolean;
    public get_as_text(): GDString;


}

