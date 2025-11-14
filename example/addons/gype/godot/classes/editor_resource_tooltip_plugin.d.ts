
import type { Control } from '@godot/classes/control';
import type { Dictionary } from '@godot/builtins/dictionary';
import type { GDString } from '@godot/builtins/gd_string';
import type { RefCounted } from '@godot/classes/ref_counted';
import type { TextureRect } from '@godot/classes/texture_rect';


export declare class EditorResourceTooltipPlugin extends RefCounted {


    public _handles(_type: GDString | StringName | string): boolean;
    public _make_tooltip_for_path(path: GDString | StringName | string, metadata: Dictionary, base: Control): Control;
    public request_thumbnail(path: GDString | StringName | string, control: TextureRect): void;


}

