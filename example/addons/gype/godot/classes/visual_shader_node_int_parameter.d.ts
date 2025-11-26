
import type { VisualShaderNodeParameter } from '@godot/classes/visual_shader_node_parameter';


export declare class VisualShaderNodeIntParameter extends VisualShaderNodeParameter {

    
    /**     * The raw type is 'int'     */
    public hint: number;    
    /**     * The raw type is 'int'     */
    public min: number;    
    /**     * The raw type is 'int'     */
    public max: number;    
    /**     * The raw type is 'int'     */
    public step: number;    
    /**     * The raw type is 'PackedStringArray'     */
    public enum_names: PackedStringArray;    
    /**     * The raw type is 'bool'     */
    public default_value_enabled: boolean;    
    /**     * The raw type is 'int'     */
    public default_value: number;
    public set_hint(hint: number): void;
    public get_hint(): number;
    public set_min(value: number): void;
    public get_min(): number;
    public set_max(value: number): void;
    public get_max(): number;
    public set_step(value: number): void;
    public get_step(): number;
    public set_enum_names(names: PackedStringArray): void;
    public get_enum_names(): PackedStringArray;
    public set_default_value_enabled(enabled: boolean): void;
    public is_default_value_enabled(): boolean;
    public set_default_value(value: number): void;
    public get_default_value(): number;


    public static readonly Hint: {
        HINT_NONE: 0;
        HINT_RANGE: 1;
        HINT_RANGE_STEP: 2;
        HINT_ENUM: 3;
        HINT_MAX: 4;
    };
}

