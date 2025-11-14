
import type { Dictionary } from '@godot/builtins/dictionary';
import type { GDString } from '@godot/builtins/gd_string';
import type { GodotObject } from '@godot/classes/godot_object';


export declare class Time extends GodotObject {


    public get_datetime_dict_from_unix_time(unixTimeVal: number): Dictionary;
    public get_date_dict_from_unix_time(unixTimeVal: number): Dictionary;
    public get_time_dict_from_unix_time(unixTimeVal: number): Dictionary;
    public get_datetime_string_from_unix_time(unixTimeVal: number, useSpace: boolean = false): GDString;
    public get_date_string_from_unix_time(unixTimeVal: number): GDString;
    public get_time_string_from_unix_time(unixTimeVal: number): GDString;
    public get_datetime_dict_from_datetime_string(datetime: GDString | StringName | string, weekday: boolean): Dictionary;
    public get_datetime_string_from_datetime_dict(datetime: Dictionary, useSpace: boolean): GDString;
    public get_unix_time_from_datetime_dict(datetime: Dictionary): number;
    public get_unix_time_from_datetime_string(datetime: GDString | StringName | string): number;
    public get_offset_string_from_offset_minutes(offsetMinutes: number): GDString;
    public get_datetime_dict_from_system(utc: boolean = false): Dictionary;
    public get_date_dict_from_system(utc: boolean = false): Dictionary;
    public get_time_dict_from_system(utc: boolean = false): Dictionary;
    public get_datetime_string_from_system(utc: boolean = false, useSpace: boolean = false): GDString;
    public get_date_string_from_system(utc: boolean = false): GDString;
    public get_time_string_from_system(utc: boolean = false): GDString;
    public get_time_zone_from_system(): Dictionary;
    public get_unix_time_from_system(): number;
    public get_ticks_msec(): number;
    public get_ticks_usec(): number;


    public static readonly Month: {
        MONTH_JANUARY: 1;
        MONTH_FEBRUARY: 2;
        MONTH_MARCH: 3;
        MONTH_APRIL: 4;
        MONTH_MAY: 5;
        MONTH_JUNE: 6;
        MONTH_JULY: 7;
        MONTH_AUGUST: 8;
        MONTH_SEPTEMBER: 9;
        MONTH_OCTOBER: 10;
        MONTH_NOVEMBER: 11;
        MONTH_DECEMBER: 12;
    };
    public static readonly Weekday: {
        WEEKDAY_SUNDAY: 0;
        WEEKDAY_MONDAY: 1;
        WEEKDAY_TUESDAY: 2;
        WEEKDAY_WEDNESDAY: 3;
        WEEKDAY_THURSDAY: 4;
        WEEKDAY_FRIDAY: 5;
        WEEKDAY_SATURDAY: 6;
    };
}


/**
 * A singleton instance of Time.
 * This is a global variable, available from anywhere.
 */
export const Time: Time;
