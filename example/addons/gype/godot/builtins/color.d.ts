declare global {
    export interface Color {
        r: number;
        g: number;
        b: number;
        a: number;
        r8: number;
        g8: number;
        b8: number;
        a8: number;
        h: number;
        s: number;
        v: number;
        ok_hsl_h: number;
        ok_hsl_s: number;
        ok_hsl_l: number;

        to_argb32(): number;
        to_abgr32(): number;
        to_rgba32(): number;
        to_argb64(): number;
        to_abgr64(): number;
        to_rgba64(): number;
        to_html(withAlpha: boolean = true): GDString;
        clamp(min: Color = Color(0, 0, 0, 0), max: Color = Color(1, 1, 1, 1)): Color;
        inverted(): Color;
        lerp(to: Color, weight: number): Color;
        lightened(amount: number): Color;
        darkened(amount: number): Color;
        blend(over: Color): Color;
        get_luminance(): number;
        srgb_to_linear(): Color;
        linear_to_srgb(): Color;
        is_equal_approx(to: Color): boolean;
        hex(hex: number): Color;
        hex64(hex: number): Color;
        html(rgba: GDString | StringName | string): Color;
        html_is_valid(color: GDString | StringName | string): boolean;
        from_string(str: GDString | StringName | string, _default: Color): Color;
        from_hsv(h: number, s: number, v: number, alpha: number = 1.0): Color;
        from_ok_hsl(h: number, s: number, l: number, alpha: number = 1.0): Color;
        from_rgbe9995(rgbe: number): Color;
        from_rgba8(r8: number, g8: number, b8: number, a8: number = 255): Color;
    }

    /**
    * A global constructor and namespace for the Color type.
    *
    * Use `new Color(...)` to create a new instance.
    * Access static members like `Color.ZERO`.
    */
    export declare const Color: {
        new(): Color;
        new(_from: Color): Color;
        new(_from: Color, alpha: number): Color;
        new(r: number, g: number, b: number): Color;
        new(r: number, g: number, b: number, a: number): Color;
        new(code: GDString | StringName | string): Color;
        new(code: GDString | StringName | string, alpha: number): Color;

        readonly ALICE_BLUE: Color;
        readonly ANTIQUE_WHITE: Color;
        readonly AQUA: Color;
        readonly AQUAMARINE: Color;
        readonly AZURE: Color;
        readonly BEIGE: Color;
        readonly BISQUE: Color;
        readonly BLACK: Color;
        readonly BLANCHED_ALMOND: Color;
        readonly BLUE: Color;
        readonly BLUE_VIOLET: Color;
        readonly BROWN: Color;
        readonly BURLYWOOD: Color;
        readonly CADET_BLUE: Color;
        readonly CHARTREUSE: Color;
        readonly CHOCOLATE: Color;
        readonly CORAL: Color;
        readonly CORNFLOWER_BLUE: Color;
        readonly CORNSILK: Color;
        readonly CRIMSON: Color;
        readonly CYAN: Color;
        readonly DARK_BLUE: Color;
        readonly DARK_CYAN: Color;
        readonly DARK_GOLDENROD: Color;
        readonly DARK_GRAY: Color;
        readonly DARK_GREEN: Color;
        readonly DARK_KHAKI: Color;
        readonly DARK_MAGENTA: Color;
        readonly DARK_OLIVE_GREEN: Color;
        readonly DARK_ORANGE: Color;
        readonly DARK_ORCHID: Color;
        readonly DARK_RED: Color;
        readonly DARK_SALMON: Color;
        readonly DARK_SEA_GREEN: Color;
        readonly DARK_SLATE_BLUE: Color;
        readonly DARK_SLATE_GRAY: Color;
        readonly DARK_TURQUOISE: Color;
        readonly DARK_VIOLET: Color;
        readonly DEEP_PINK: Color;
        readonly DEEP_SKY_BLUE: Color;
        readonly DIM_GRAY: Color;
        readonly DODGER_BLUE: Color;
        readonly FIREBRICK: Color;
        readonly FLORAL_WHITE: Color;
        readonly FOREST_GREEN: Color;
        readonly FUCHSIA: Color;
        readonly GAINSBORO: Color;
        readonly GHOST_WHITE: Color;
        readonly GOLD: Color;
        readonly GOLDENROD: Color;
        readonly GRAY: Color;
        readonly GREEN: Color;
        readonly GREEN_YELLOW: Color;
        readonly HONEYDEW: Color;
        readonly HOT_PINK: Color;
        readonly INDIAN_RED: Color;
        readonly INDIGO: Color;
        readonly IVORY: Color;
        readonly KHAKI: Color;
        readonly LAVENDER: Color;
        readonly LAVENDER_BLUSH: Color;
        readonly LAWN_GREEN: Color;
        readonly LEMON_CHIFFON: Color;
        readonly LIGHT_BLUE: Color;
        readonly LIGHT_CORAL: Color;
        readonly LIGHT_CYAN: Color;
        readonly LIGHT_GOLDENROD: Color;
        readonly LIGHT_GRAY: Color;
        readonly LIGHT_GREEN: Color;
        readonly LIGHT_PINK: Color;
        readonly LIGHT_SALMON: Color;
        readonly LIGHT_SEA_GREEN: Color;
        readonly LIGHT_SKY_BLUE: Color;
        readonly LIGHT_SLATE_GRAY: Color;
        readonly LIGHT_STEEL_BLUE: Color;
        readonly LIGHT_YELLOW: Color;
        readonly LIME: Color;
        readonly LIME_GREEN: Color;
        readonly LINEN: Color;
        readonly MAGENTA: Color;
        readonly MAROON: Color;
        readonly MEDIUM_AQUAMARINE: Color;
        readonly MEDIUM_BLUE: Color;
        readonly MEDIUM_ORCHID: Color;
        readonly MEDIUM_PURPLE: Color;
        readonly MEDIUM_SEA_GREEN: Color;
        readonly MEDIUM_SLATE_BLUE: Color;
        readonly MEDIUM_SPRING_GREEN: Color;
        readonly MEDIUM_TURQUOISE: Color;
        readonly MEDIUM_VIOLET_RED: Color;
        readonly MIDNIGHT_BLUE: Color;
        readonly MINT_CREAM: Color;
        readonly MISTY_ROSE: Color;
        readonly MOCCASIN: Color;
        readonly NAVAJO_WHITE: Color;
        readonly NAVY_BLUE: Color;
        readonly OLD_LACE: Color;
        readonly OLIVE: Color;
        readonly OLIVE_DRAB: Color;
        readonly ORANGE: Color;
        readonly ORANGE_RED: Color;
        readonly ORCHID: Color;
        readonly PALE_GOLDENROD: Color;
        readonly PALE_GREEN: Color;
        readonly PALE_TURQUOISE: Color;
        readonly PALE_VIOLET_RED: Color;
        readonly PAPAYA_WHIP: Color;
        readonly PEACH_PUFF: Color;
        readonly PERU: Color;
        readonly PINK: Color;
        readonly PLUM: Color;
        readonly POWDER_BLUE: Color;
        readonly PURPLE: Color;
        readonly REBECCA_PURPLE: Color;
        readonly RED: Color;
        readonly ROSY_BROWN: Color;
        readonly ROYAL_BLUE: Color;
        readonly SADDLE_BROWN: Color;
        readonly SALMON: Color;
        readonly SANDY_BROWN: Color;
        readonly SEA_GREEN: Color;
        readonly SEASHELL: Color;
        readonly SIENNA: Color;
        readonly SILVER: Color;
        readonly SKY_BLUE: Color;
        readonly SLATE_BLUE: Color;
        readonly SLATE_GRAY: Color;
        readonly SNOW: Color;
        readonly SPRING_GREEN: Color;
        readonly STEEL_BLUE: Color;
        readonly TAN: Color;
        readonly TEAL: Color;
        readonly THISTLE: Color;
        readonly TOMATO: Color;
        readonly TRANSPARENT: Color;
        readonly TURQUOISE: Color;
        readonly VIOLET: Color;
        readonly WEB_GRAY: Color;
        readonly WEB_GREEN: Color;
        readonly WEB_MAROON: Color;
        readonly WEB_PURPLE: Color;
        readonly WHEAT: Color;
        readonly WHITE: Color;
        readonly WHITE_SMOKE: Color;
        readonly YELLOW: Color;
        readonly YELLOW_GREEN: Color;

        /*
        // equals(any): boolean
        // not_equals(any): boolean
        // negate(any): Color
        // positive(any): Color
        // op_not(any): boolean
        // multiply(number): Color
        // divide(number): Color
        // multiply(number): Color
        // divide(number): Color
        // equals(Color): boolean
        // not_equals(Color): boolean
        // add(Color): Color
        // subtract(Color): Color
        // multiply(Color): Color
        // divide(Color): Color
        // in_op(Dictionary): boolean
        // in_op(GDArray): boolean
        // in_op(PackedColorArray): boolean
        */
    };
}

export {};