
import type { GodotObject } from '@godot/classes/godot_object';
import type { OpenXRActionMap } from '@godot/classes/open_xr_action_map';
import type { OpenXRBindingModifier } from '@godot/classes/open_xr_binding_modifier';
import type { PanelContainer } from '@godot/classes/panel_container';
import type { Signal } from '@godot/builtins/signal';


export declare class OpenXRBindingModifierEditor extends PanelContainer {


    public get_binding_modifier(): OpenXRBindingModifier;
    public setup(actionMap: OpenXRActionMap, bindingModifier: OpenXRBindingModifier): void;

    
    public readonly binding_modifier_removed: Signal<(bindingModifierEditor: GodotObject) => void>;

}

