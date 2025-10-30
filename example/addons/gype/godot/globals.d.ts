declare global {
    /**
     * A global object providing access to Godot's utility functions.
     */
    interface UtilityFunctions {
        sin(angle_rad: number): number;
        cos(angle_rad: number): number;
        tan(angle_rad: number): number;
        sinh(x: number): number;
        cosh(x: number): number;
        tanh(x: number): number;
        asin(x: number): number;
        acos(x: number): number;
        atan(x: number): number;
        atan2(y: number, x: number): number;
        asinh(x: number): number;
        acosh(x: number): number;
        atanh(x: number): number;
        sqrt(x: number): number;
        fmod(x: number, y: number): number;
        fposmod(x: number, y: number): number;
        posmod(x: number, y: number): number;
        floor(x: any): any;
        floorf(x: number): number;
        floori(x: number): number;
        ceil(x: any): any;
        ceilf(x: number): number;
        ceili(x: number): number;
        round(x: any): any;
        roundf(x: number): number;
        roundi(x: number): number;
        abs(x: any): any;
        absf(x: number): number;
        absi(x: number): number;
        sign(x: any): any;
        signf(x: number): number;
        signi(x: number): number;
        snapped(x: any, step: any): any;
        snappedf(x: number, step: number): number;
        snappedi(x: number, step: number): number;
        pow(base: number, exp: number): number;
        log(x: number): number;
        exp(x: number): number;
        is_nan(x: number): boolean;
        is_inf(x: number): boolean;
        is_equal_approx(a: number, b: number): boolean;
        is_zero_approx(x: number): boolean;
        is_finite(x: number): boolean;
        ease(x: number, curve: number): number;
        step_decimals(x: number): number;
        lerp(_from: any, to: any, weight: any): any;
        lerpf(_from: number, to: number, weight: number): number;
        cubic_interpolate(_from: number, to: number, pre: number, post: number, weight: number): number;
        cubic_interpolate_angle(_from: number, to: number, pre: number, post: number, weight: number): number;
        cubic_interpolate_in_time(_from: number, to: number, pre: number, post: number, weight: number, to_t: number, pre_t: number, post_t: number): number;
        cubic_interpolate_angle_in_time(_from: number, to: number, pre: number, post: number, weight: number, to_t: number, pre_t: number, post_t: number): number;
        bezier_interpolate(start: number, control_1: number, control_2: number, end: number, t: number): number;
        bezier_derivative(start: number, control_1: number, control_2: number, end: number, t: number): number;
        angle_difference(_from: number, to: number): number;
        lerp_angle(_from: number, to: number, weight: number): number;
        inverse_lerp(_from: number, to: number, weight: number): number;
        remap(value: number, istart: number, istop: number, ostart: number, ostop: number): number;
        smoothstep(_from: number, to: number, x: number): number;
        move_toward(_from: number, to: number, delta: number): number;
        rotate_toward(_from: number, to: number, delta: number): number;
        deg_to_rad(deg: number): number;
        rad_to_deg(rad: number): number;
        linear_to_db(lin: number): number;
        db_to_linear(db: number): number;
        wrap(value: any, min: any, max: any): any;
        wrapi(value: number, min: number, max: number): number;
        wrapf(value: number, min: number, max: number): number;
        max(arg1: any, arg2: any, ...args: any[]): any;
        maxi(a: number, b: number): number;
        maxf(a: number, b: number): number;
        min(arg1: any, arg2: any, ...args: any[]): any;
        mini(a: number, b: number): number;
        minf(a: number, b: number): number;
        clamp(value: any, min: any, max: any): any;
        clampi(value: number, min: number, max: number): number;
        clampf(value: number, min: number, max: number): number;
        nearest_po2(value: number): number;
        pingpong(value: number, length: number): number;
        randomize(): void;
        randi(): number;
        randf(): number;
        randi_range(_from: number, to: number): number;
        randf_range(_from: number, to: number): number;
        randfn(mean: number, deviation: number): number;
        seed(base: number): void;
        rand_from_seed(seed: number): PackedInt64Array;
        weakref(obj: any): any;
        typeof(variable: any): number;
        type_convert(variant: any, _type: number): any;
        str(arg1: any, ...args: any[]): GDString;
        error_string(error: number): GDString;
        type_string(_type: number): GDString;
        print(arg1: any, ...args: any[]): void;
        print_rich(arg1: any, ...args: any[]): void;
        printerr(arg1: any, ...args: any[]): void;
        printt(arg1: any, ...args: any[]): void;
        prints(arg1: any, ...args: any[]): void;
        printraw(arg1: any, ...args: any[]): void;
        print_verbose(arg1: any, ...args: any[]): void;
        push_error(arg1: any, ...args: any[]): void;
        push_warning(arg1: any, ...args: any[]): void;
        var_to_str(variable: any): GDString;
        str_to_var(_string: GDString | StringName | string): any;
        var_to_bytes(variable: any): PackedByteArray;
        bytes_to_var(bytes: PackedByteArray): any;
        var_to_bytes_with_objects(variable: any): PackedByteArray;
        bytes_to_var_with_objects(bytes: PackedByteArray): any;
        hash(variable: any): number;
        instance_from_id(instance_id: number): GodotObject;
        is_instance_id_valid(id: number): boolean;
        is_instance_valid(instance: any): boolean;
        rid_allocate_id(): number;
        rid_from_int64(base: number): RID;
        is_same(a: any, b: any): boolean;
    }

    /**
     * A global object providing access to Godot's utility functions.
     * Use `GD.sin(value)` instead of `sin(value)`.
     */
    const GD: UtilityFunctions;
}

// This file is global and does not export anything, but 'export {}'
// is required to make it a module and merge the global declaration.
export {};