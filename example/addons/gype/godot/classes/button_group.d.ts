
import type { BaseButton } from '@godot/classes/base_button';
import type { Resource } from '@godot/classes/resource';
import type { Signal } from '@godot/builtins/signal';


export declare class ButtonGroup extends Resource {

    
    /**     * The raw type is 'bool'     */
    public allow_unpress: boolean;
    public get_pressed_button(): BaseButton;
    public get_buttons(): Array<any>;
    public set_allow_unpress(enabled: boolean): void;
    public is_allow_unpress(): boolean;

    
    public readonly pressed: Signal<(button: BaseButton) => void>;

}

