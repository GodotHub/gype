
import type { Callable } from '@godot/builtins/callable';
import type { Tweener } from '@godot/classes/tweener';


export declare class PropertyTweener extends Tweener {


    public from(value: any): PropertyTweener;
    public from_current(): PropertyTweener;
    public as_relative(): PropertyTweener;
    public set_trans(trans: number): PropertyTweener;
    public set_ease(ease: number): PropertyTweener;
    public set_custom_interpolator(interpolatorMethod: Callable): PropertyTweener;
    public set_delay(delay: number): PropertyTweener;


}

