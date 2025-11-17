declare global {
    export class Color {
        constructor(): Color;
        constructor(_from: Color): Color;
        constructor(_from: Color, alpha: number): Color;
        constructor(r: number, g: number, b: number): Color;
        constructor(r: number, g: number, b: number, a: number): Color;
        constructor(code: GDString | StringName | string): Color;
        constructor(code: GDString | StringName | string, alpha: number): Color;
        readonly static ALICE_BLUE: Color;
        readonly static ANTIQUE_WHITE: Color;
        readonly static AQUA: Color;
        readonly static AQUAMARINE: Color;
        readonly static AZURE: Color;
        readonly static BEIGE: Color;
        readonly static BISQUE: Color;
        readonly static BLACK: Color;
        readonly static BLANCHED_ALMOND: Color;
        readonly static BLUE: Color;
        readonly static BLUE_VIOLET: Color;
        readonly static BROWN: Color;
        readonly static BURLYWOOD: Color;
        readonly static CADET_BLUE: Color;
        readonly static CHARTREUSE: Color;
        readonly static CHOCOLATE: Color;
        readonly static CORAL: Color;
        readonly static CORNFLOWER_BLUE: Color;
        readonly static CORNSILK: Color;
        readonly static CRIMSON: Color;
        readonly static CYAN: Color;
        readonly static DARK_BLUE: Color;
        readonly static DARK_CYAN: Color;
        readonly static DARK_GOLDENROD: Color;
        readonly static DARK_GRAY: Color;
        readonly static DARK_GREEN: Color;
        readonly static DARK_KHAKI: Color;
        readonly static DARK_MAGENTA: Color;
        readonly static DARK_OLIVE_GREEN: Color;
        readonly static DARK_ORANGE: Color;
        readonly static DARK_ORCHID: Color;
        readonly static DARK_RED: Color;
        readonly static DARK_SALMON: Color;
        readonly static DARK_SEA_GREEN: Color;
        readonly static DARK_SLATE_BLUE: Color;
        readonly static DARK_SLATE_GRAY: Color;
        readonly static DARK_TURQUOISE: Color;
        readonly static DARK_VIOLET: Color;
        readonly static DEEP_PINK: Color;
        readonly static DEEP_SKY_BLUE: Color;
        readonly static DIM_GRAY: Color;
        readonly static DODGER_BLUE: Color;
        readonly static FIREBRICK: Color;
        readonly static FLORAL_WHITE: Color;
        readonly static FOREST_GREEN: Color;
        readonly static FUCHSIA: Color;
        readonly static GAINSBORO: Color;
        readonly static GHOST_WHITE: Color;
        readonly static GOLD: Color;
        readonly static GOLDENROD: Color;
        readonly static GRAY: Color;
        readonly static GREEN: Color;
        readonly static GREEN_YELLOW: Color;
        readonly static HONEYDEW: Color;
        readonly static HOT_PINK: Color;
        readonly static INDIAN_RED: Color;
        readonly static INDIGO: Color;
        readonly static IVORY: Color;
        readonly static KHAKI: Color;
        readonly static LAVENDER: Color;
        readonly static LAVENDER_BLUSH: Color;
        readonly static LAWN_GREEN: Color;
        readonly static LEMON_CHIFFON: Color;
        readonly static LIGHT_BLUE: Color;
        readonly static LIGHT_CORAL: Color;
        readonly static LIGHT_CYAN: Color;
        readonly static LIGHT_GOLDENROD: Color;
        readonly static LIGHT_GRAY: Color;
        readonly static LIGHT_GREEN: Color;
        readonly static LIGHT_PINK: Color;
        readonly static LIGHT_SALMON: Color;
        readonly static LIGHT_SEA_GREEN: Color;
        readonly static LIGHT_SKY_BLUE: Color;
        readonly static LIGHT_SLATE_GRAY: Color;
        readonly static LIGHT_STEEL_BLUE: Color;
        readonly static LIGHT_YELLOW: Color;
        readonly static LIME: Color;
        readonly static LIME_GREEN: Color;
        readonly static LINEN: Color;
        readonly static MAGENTA: Color;
        readonly static MAROON: Color;
        readonly static MEDIUM_AQUAMARINE: Color;
        readonly static MEDIUM_BLUE: Color;
        readonly static MEDIUM_ORCHID: Color;
        readonly static MEDIUM_PURPLE: Color;
        readonly static MEDIUM_SEA_GREEN: Color;
        readonly static MEDIUM_SLATE_BLUE: Color;
        readonly static MEDIUM_SPRING_GREEN: Color;
        readonly static MEDIUM_TURQUOISE: Color;
        readonly static MEDIUM_VIOLET_RED: Color;
        readonly static MIDNIGHT_BLUE: Color;
        readonly static MINT_CREAM: Color;
        readonly static MISTY_ROSE: Color;
        readonly static MOCCASIN: Color;
        readonly static NAVAJO_WHITE: Color;
        readonly static NAVY_BLUE: Color;
        readonly static OLD_LACE: Color;
        readonly static OLIVE: Color;
        readonly static OLIVE_DRAB: Color;
        readonly static ORANGE: Color;
        readonly static ORANGE_RED: Color;
        readonly static ORCHID: Color;
        readonly static PALE_GOLDENROD: Color;
        readonly static PALE_GREEN: Color;
        readonly static PALE_TURQUOISE: Color;
        readonly static PALE_VIOLET_RED: Color;
        readonly static PAPAYA_WHIP: Color;
        readonly static PEACH_PUFF: Color;
        readonly static PERU: Color;
        readonly static PINK: Color;
        readonly static PLUM: Color;
        readonly static POWDER_BLUE: Color;
        readonly static PURPLE: Color;
        readonly static REBECCA_PURPLE: Color;
        readonly static RED: Color;
        readonly static ROSY_BROWN: Color;
        readonly static ROYAL_BLUE: Color;
        readonly static SADDLE_BROWN: Color;
        readonly static SALMON: Color;
        readonly static SANDY_BROWN: Color;
        readonly static SEA_GREEN: Color;
        readonly static SEASHELL: Color;
        readonly static SIENNA: Color;
        readonly static SILVER: Color;
        readonly static SKY_BLUE: Color;
        readonly static SLATE_BLUE: Color;
        readonly static SLATE_GRAY: Color;
        readonly static SNOW: Color;
        readonly static SPRING_GREEN: Color;
        readonly static STEEL_BLUE: Color;
        readonly static TAN: Color;
        readonly static TEAL: Color;
        readonly static THISTLE: Color;
        readonly static TOMATO: Color;
        readonly static TRANSPARENT: Color;
        readonly static TURQUOISE: Color;
        readonly static VIOLET: Color;
        readonly static WEB_GRAY: Color;
        readonly static WEB_GREEN: Color;
        readonly static WEB_MAROON: Color;
        readonly static WEB_PURPLE: Color;
        readonly static WHEAT: Color;
        readonly static WHITE: Color;
        readonly static WHITE_SMOKE: Color;
        readonly static YELLOW: Color;
        readonly static YELLOW_GREEN: Color;
    
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
    }
}

export {};