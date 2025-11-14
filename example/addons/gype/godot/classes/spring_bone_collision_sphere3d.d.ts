
import type { SpringBoneCollision3D } from '@godot/classes/spring_bone_collision3d';


export declare class SpringBoneCollisionSphere3D extends SpringBoneCollision3D {

    
    /**     * The raw type is 'float'     */
    public radius: number;    
    /**     * The raw type is 'bool'     */
    public inside: boolean;
    public set_radius(radius: number): void;
    public get_radius(): number;
    public set_inside(enabled: boolean): void;
    public is_inside(): boolean;


}

