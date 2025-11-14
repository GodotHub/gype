
import type { Container } from '@godot/classes/container';
import type { Control } from '@godot/classes/control';


export declare class BoxContainer extends Container {

    
    /**     * The raw type is 'int'     */
    public alignment: number;    
    /**     * The raw type is 'bool'     */
    public vertical: boolean;
    public add_spacer(begin: boolean): Control;
    public set_alignment(alignment: number): void;
    public get_alignment(): number;
    public set_vertical(vertical: boolean): void;
    public is_vertical(): boolean;


    public static readonly AlignmentMode: {
        ALIGNMENT_BEGIN: 0;
        ALIGNMENT_CENTER: 1;
        ALIGNMENT_END: 2;
    };
}

