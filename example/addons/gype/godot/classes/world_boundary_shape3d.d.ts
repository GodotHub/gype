
import type { Plane } from '@godot/builtins/plane';
import type { Shape3D } from '@godot/classes/shape3d';


export declare class WorldBoundaryShape3D extends Shape3D {

    
    /**     * The raw type is 'Plane'     */
    public plane: Plane;
    public set_plane(plane: Plane): void;
    public get_plane(): Plane;


}

