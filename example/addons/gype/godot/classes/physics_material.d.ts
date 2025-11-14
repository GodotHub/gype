
import type { Resource } from '@godot/classes/resource';


export declare class PhysicsMaterial extends Resource {

    
    /**     * The raw type is 'float'     */
    public friction: number;    
    /**     * The raw type is 'bool'     */
    public rough: boolean;    
    /**     * The raw type is 'float'     */
    public bounce: number;    
    /**     * The raw type is 'bool'     */
    public absorbent: boolean;
    public set_friction(friction: number): void;
    public get_friction(): number;
    public set_rough(rough: boolean): void;
    public is_rough(): boolean;
    public set_bounce(bounce: number): void;
    public get_bounce(): number;
    public set_absorbent(absorbent: boolean): void;
    public is_absorbent(): boolean;


}

