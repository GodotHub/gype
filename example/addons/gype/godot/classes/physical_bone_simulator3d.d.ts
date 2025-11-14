
import type { RID } from '@godot/builtins/rid';
import type { SkeletonModifier3D } from '@godot/classes/skeleton_modifier3d';


export declare class PhysicalBoneSimulator3D extends SkeletonModifier3D {


    public is_simulating_physics(): boolean;
    public physical_bones_stop_simulation(): void;
    public physical_bones_start_simulation(bones: Array<any> = []): void;
    public physical_bones_add_collision_exception(exception: RID): void;
    public physical_bones_remove_collision_exception(exception: RID): void;


}

