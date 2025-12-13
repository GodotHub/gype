
import type { GodotObject } from '@godot/classes/godot_object';
import type { InputEvent } from '@godot/classes/input_event';
import type { Resource } from '@godot/classes/resource';


export declare class Input extends GodotObject {

    
    /**     * The raw type is 'int'     */
    public mouse_mode: number;    
    /**     * The raw type is 'bool'     */
    public use_accumulated_input: boolean;    
    /**     * The raw type is 'bool'     */
    public emulate_mouse_from_touch: boolean;    
    /**     * The raw type is 'bool'     */
    public emulate_touch_from_mouse: boolean;
    public is_anything_pressed(): boolean;
    public is_key_pressed(keycode: number): boolean;
    public is_physical_key_pressed(keycode: number): boolean;
    public is_key_label_pressed(keycode: number): boolean;
    public is_mouse_button_pressed(button: number): boolean;
    public is_joy_button_pressed(device: number, button: number): boolean;
    public is_action_pressed(action: GDString | StringName | string, exactMatch: boolean = false): boolean;
    public is_action_just_pressed(action: GDString | StringName | string, exactMatch: boolean = false): boolean;
    public is_action_just_released(action: GDString | StringName | string, exactMatch: boolean = false): boolean;
    public is_action_just_pressed_by_event(action: GDString | StringName | string, event: InputEvent, exactMatch: boolean = false): boolean;
    public is_action_just_released_by_event(action: GDString | StringName | string, event: InputEvent, exactMatch: boolean = false): boolean;
    public get_action_strength(action: GDString | StringName | string, exactMatch: boolean = false): number;
    public get_action_raw_strength(action: GDString | StringName | string, exactMatch: boolean = false): number;
    public get_axis(negativeAction: GDString | StringName | string, positiveAction: GDString | StringName | string): number;
    public get_vector(negativeX: GDString | StringName | string, positiveX: GDString | StringName | string, negativeY: GDString | StringName | string, positiveY: GDString | StringName | string, deadzone: number = -1.0): Vector2;
    public add_joy_mapping(mapping: GDString | StringName | string, updateExisting: boolean = false): void;
    public remove_joy_mapping(guid: GDString | StringName | string): void;
    public is_joy_known(device: number): boolean;
    public get_joy_axis(device: number, axis: number): number;
    public get_joy_name(device: number): GDString;
    public get_joy_guid(device: number): GDString;
    public get_joy_info(device: number): Dictionary;
    public should_ignore_device(vendorId: number, productId: number): boolean;
    public get_connected_joypads(): Array<any>;
    public get_joy_vibration_strength(device: number): Vector2;
    public get_joy_vibration_duration(device: number): number;
    public start_joy_vibration(device: number, weakMagnitude: number, strongMagnitude: number, duration: number = 0): void;
    public stop_joy_vibration(device: number): void;
    public vibrate_handheld(durationMs: number = 500, amplitude: number = -1.0): void;
    public get_gravity(): Vector3;
    public get_accelerometer(): Vector3;
    public get_magnetometer(): Vector3;
    public get_gyroscope(): Vector3;
    public set_gravity(value: Vector3): void;
    public set_accelerometer(value: Vector3): void;
    public set_magnetometer(value: Vector3): void;
    public set_gyroscope(value: Vector3): void;
    public get_last_mouse_velocity(): Vector2;
    public get_last_mouse_screen_velocity(): Vector2;
    public get_mouse_button_mask(): number;
    public set_mouse_mode(mode: number): void;
    public get_mouse_mode(): number;
    public warp_mouse(position: Vector2): void;
    public action_press(action: GDString | StringName | string, strength: number = 1.0): void;
    public action_release(action: GDString | StringName | string): void;
    public set_default_cursor_shape(shape: number = 0): void;
    public get_current_cursor_shape(): number;
    public set_custom_mouse_cursor(image: Resource, shape: number = 0, hotspot: Vector2 = Vector2(0, 0)): void;
    public parse_input_event(event: InputEvent): void;
    public set_use_accumulated_input(enable: boolean): void;
    public is_using_accumulated_input(): boolean;
    public flush_buffered_events(): void;
    public set_emulate_mouse_from_touch(enable: boolean): void;
    public is_emulating_mouse_from_touch(): boolean;
    public set_emulate_touch_from_mouse(enable: boolean): void;
    public is_emulating_touch_from_mouse(): boolean;

    
    public readonly joy_connection_changed: Signal<(device: number, connected: boolean) => void>;

    public static readonly MouseMode: {
        MOUSE_MODE_VISIBLE: 0;
        MOUSE_MODE_HIDDEN: 1;
        MOUSE_MODE_CAPTURED: 2;
        MOUSE_MODE_CONFINED: 3;
        MOUSE_MODE_CONFINED_HIDDEN: 4;
        MOUSE_MODE_MAX: 5;
    };
    public static readonly CursorShape: {
        CURSOR_ARROW: 0;
        CURSOR_IBEAM: 1;
        CURSOR_POINTING_HAND: 2;
        CURSOR_CROSS: 3;
        CURSOR_WAIT: 4;
        CURSOR_BUSY: 5;
        CURSOR_DRAG: 6;
        CURSOR_CAN_DROP: 7;
        CURSOR_FORBIDDEN: 8;
        CURSOR_VSIZE: 9;
        CURSOR_HSIZE: 10;
        CURSOR_BDIAGSIZE: 11;
        CURSOR_FDIAGSIZE: 12;
        CURSOR_MOVE: 13;
        CURSOR_VSPLIT: 14;
        CURSOR_HSPLIT: 15;
        CURSOR_HELP: 16;
    };
}


/**
 * A singleton instance of Input.
 * This is a global variable, available from anywhere.
 */
export const Input: Input;
