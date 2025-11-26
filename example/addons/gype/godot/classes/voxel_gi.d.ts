
import type { CameraAttributes } from '@godot/classes/camera_attributes';
import type { CameraAttributesPractical } from '@godot/classes/camera_attributes_practical';
import type { Node } from '@godot/classes/node';
import type { VisualInstance3D } from '@godot/classes/visual_instance3d';
import type { VoxelGIData } from '@godot/classes/voxel_gi_data';


export declare class VoxelGI extends VisualInstance3D {

    
    /**     * The raw type is 'int'     */
    public subdiv: number;    
    /**     * The raw type is 'Vector3'     */
    public size: Vector3;    
    /**     * The raw type is 'CameraAttributesPractical,CameraAttributesPhysical'     */
    public camera_attributes: CameraAttributes;    
    /**     * The raw type is 'VoxelGIData'     */
    public data: VoxelGIData;
    public set_probe_data(data: VoxelGIData): void;
    public get_probe_data(): VoxelGIData;
    public set_subdiv(subdiv: number): void;
    public get_subdiv(): number;
    public set_size(size: Vector3): void;
    public get_size(): Vector3;
    public set_camera_attributes(cameraAttributes: CameraAttributes): void;
    public get_camera_attributes(): CameraAttributes;
    public bake(fromNode: Node = null, createVisualDebug: boolean = false): void;
    public debug_bake(): void;


    public static readonly Subdiv: {
        SUBDIV_64: 0;
        SUBDIV_128: 1;
        SUBDIV_256: 2;
        SUBDIV_512: 3;
        SUBDIV_MAX: 4;
    };
}

