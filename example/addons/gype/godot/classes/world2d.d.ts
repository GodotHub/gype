
import type { PhysicsDirectSpaceState2D } from '@godot/classes/physics_direct_space_state2d';
import type { Resource } from '@godot/classes/resource';


export declare class World2D extends Resource {

    
    /**     * The raw type is 'RID'     */
    public canvas: RID;    
    /**     * The raw type is 'RID'     */
    public navigation_map: RID;    
    /**     * The raw type is 'RID'     */
    public space: RID;    
    /**     * The raw type is 'PhysicsDirectSpaceState2D'     */
    public direct_space_state: PhysicsDirectSpaceState2D;
    public get_canvas(): RID;
    public get_navigation_map(): RID;
    public get_space(): RID;
    public get_direct_space_state(): PhysicsDirectSpaceState2D;


}

