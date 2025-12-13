
import type { Control } from '@godot/classes/control';


export declare class Container extends Control {


    public _get_allowed_size_flags_horizontal(): PackedInt32Array;
    public _get_allowed_size_flags_vertical(): PackedInt32Array;
    public queue_sort(): void;
    public fit_child_in_rect(child: Control, rect: Rect2): void;

    
    public readonly pre_sort_children: Signal<() => void>;
    public readonly sort_children: Signal<() => void>;

}

