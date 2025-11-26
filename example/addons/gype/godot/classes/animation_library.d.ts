
import type { Animation } from '@godot/classes/animation';
import type { Resource } from '@godot/classes/resource';


export declare class AnimationLibrary extends Resource {


    public add_animation(name: GDString | StringName | string, animation: Animation): number;
    public remove_animation(name: GDString | StringName | string): void;
    public rename_animation(name: GDString | StringName | string, newname: GDString | StringName | string): void;
    public has_animation(name: GDString | StringName | string): boolean;
    public get_animation(name: GDString | StringName | string): Animation;
    public get_animation_list(): Array<any>;
    public get_animation_list_size(): number;

    
    public readonly animation_added: Signal;
    public readonly animation_removed: Signal;
    public readonly animation_renamed: Signal;
    public readonly animation_changed: Signal;

}

