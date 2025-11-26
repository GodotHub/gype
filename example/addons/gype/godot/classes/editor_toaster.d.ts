
import type { HBoxContainer } from '@godot/classes/h_box_container';


export declare class EditorToaster extends HBoxContainer {


    public push_toast(message: GDString | StringName | string, severity: number = 0, tooltip: GDString | StringName | string = ""): void;


    public static readonly Severity: {
        SEVERITY_INFO: 0;
        SEVERITY_WARNING: 1;
        SEVERITY_ERROR: 2;
    };
}

