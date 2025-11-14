
import type { GDArray } from '@godot/builtins/gd_array';
import type { PackedVector2Array } from '@godot/builtins/packed_vector2_array';
import type { Rect2 } from '@godot/builtins/rect2';
import type { Resource } from '@godot/classes/resource';


export declare class NavigationMeshSourceGeometryData2D extends Resource {

    
    /**     * The raw type is 'Array'     */
    public traversable_outlines: Array<any>;    
    /**     * The raw type is 'Array'     */
    public obstruction_outlines: Array<any>;    
    /**     * The raw type is 'Array'     */
    public projected_obstructions: GDArray;
    public clear(): void;
    public has_data(): boolean;
    public set_traversable_outlines(traversableOutlines: Array<any>): void;
    public get_traversable_outlines(): Array<any>;
    public set_obstruction_outlines(obstructionOutlines: Array<any>): void;
    public get_obstruction_outlines(): Array<any>;
    public append_traversable_outlines(traversableOutlines: Array<any>): void;
    public append_obstruction_outlines(obstructionOutlines: Array<any>): void;
    public add_traversable_outline(shapeOutline: PackedVector2Array): void;
    public add_obstruction_outline(shapeOutline: PackedVector2Array): void;
    public merge(otherGeometry: NavigationMeshSourceGeometryData2D): void;
    public add_projected_obstruction(vertices: PackedVector2Array, carve: boolean): void;
    public clear_projected_obstructions(): void;
    public set_projected_obstructions(projectedObstructions: GDArray): void;
    public get_projected_obstructions(): GDArray;
    public get_bounds(): Rect2;


}

