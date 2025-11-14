
import type { InputEvent } from '@godot/classes/input_event';
import type { Shortcut } from '@godot/classes/shortcut';


export declare class InputEventShortcut extends InputEvent {

    
    /**     * The raw type is 'Shortcut'     */
    public shortcut: Shortcut;
    public set_shortcut(shortcut: Shortcut): void;
    public get_shortcut(): Shortcut;


}

