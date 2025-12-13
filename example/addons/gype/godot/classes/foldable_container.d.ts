
import type { Container } from '@godot/classes/container';
import type { Control } from '@godot/classes/control';
import type { FoldableGroup } from '@godot/classes/foldable_group';


export declare class FoldableContainer extends Container {

    
    /**     * The raw type is 'bool'     */
    public folded: boolean;    
    /**     * The raw type is 'String'     */
    public title: GDString | StringName | string;    
    /**     * The raw type is 'int'     */
    public title_alignment: number;    
    /**     * The raw type is 'int'     */
    public title_position: number;    
    /**     * The raw type is 'int'     */
    public title_text_overrun_behavior: number;    
    /**     * The raw type is 'FoldableGroup'     */
    public foldable_group: FoldableGroup;    
    /**     * The raw type is 'int'     */
    public title_text_direction: number;    
    /**     * The raw type is 'String'     */
    public language: GDString | StringName | string;
    public fold(): void;
    public expand(): void;
    public set_folded(folded: boolean): void;
    public is_folded(): boolean;
    public set_foldable_group(buttonGroup: FoldableGroup): void;
    public get_foldable_group(): FoldableGroup;
    public set_title(text: GDString | StringName | string): void;
    public get_title(): GDString;
    public set_title_alignment(alignment: number): void;
    public get_title_alignment(): number;
    public set_language(language: GDString | StringName | string): void;
    public get_language(): GDString;
    public set_title_text_direction(textDirection: number): void;
    public get_title_text_direction(): number;
    public set_title_text_overrun_behavior(overrunBehavior: number): void;
    public get_title_text_overrun_behavior(): number;
    public set_title_position(titlePosition: number): void;
    public get_title_position(): number;
    public add_title_bar_control(control: Control): void;
    public remove_title_bar_control(control: Control): void;

    
    public readonly folding_changed: Signal<(isFolded: boolean) => void>;

    public static readonly TitlePosition: {
        POSITION_TOP: 0;
        POSITION_BOTTOM: 1;
    };
}

