declare global {
    export class StringName {
        constructor(): StringName;
        constructor(_from: GDString | StringName | string): StringName;
        constructor(_from: GDString | StringName | string): StringName;
    

        casecmp_to(to: GDString | StringName | string): number;
        nocasecmp_to(to: GDString | StringName | string): number;
        naturalcasecmp_to(to: GDString | StringName | string): number;
        naturalnocasecmp_to(to: GDString | StringName | string): number;
        filecasecmp_to(to: GDString | StringName | string): number;
        filenocasecmp_to(to: GDString | StringName | string): number;
        length(): number;
        substr(_from: number, len: number = -1): GDString;
        get_slice(delimiter: GDString | StringName | string, slice: number): GDString;
        get_slicec(delimiter: number, slice: number): GDString;
        get_slice_count(delimiter: GDString | StringName | string): number;
        find(what: GDString | StringName | string, _from: number = 0): number;
        findn(what: GDString | StringName | string, _from: number = 0): number;
        count(what: GDString | StringName | string, _from: number = 0, to: number = 0): number;
        countn(what: GDString | StringName | string, _from: number = 0, to: number = 0): number;
        rfind(what: GDString | StringName | string, _from: number = -1): number;
        rfindn(what: GDString | StringName | string, _from: number = -1): number;
        match(expr: GDString | StringName | string): boolean;
        matchn(expr: GDString | StringName | string): boolean;
        begins_with(text: GDString | StringName | string): boolean;
        ends_with(text: GDString | StringName | string): boolean;
        is_subsequence_of(text: GDString | StringName | string): boolean;
        is_subsequence_ofn(text: GDString | StringName | string): boolean;
        bigrams(): PackedStringArray;
        similarity(text: GDString | StringName | string): number;
        format(values: any, placeholder: GDString | StringName | string = "{_}"): GDString;
        replace(what: GDString | StringName | string, forwhat: GDString | StringName | string): GDString;
        replacen(what: GDString | StringName | string, forwhat: GDString | StringName | string): GDString;
        replace_char(key: number, _with: number): GDString;
        replace_chars(keys: GDString | StringName | string, _with: number): GDString;
        remove_char(what: number): GDString;
        remove_chars(chars: GDString | StringName | string): GDString;
        repeat(count: number): GDString;
        reverse(): GDString;
        insert(position: number, what: GDString | StringName | string): GDString;
        erase(position: number, chars: number = 1): GDString;
        capitalize(): GDString;
        to_camel_case(): GDString;
        to_pascal_case(): GDString;
        to_snake_case(): GDString;
        to_kebab_case(): GDString;
        split(delimiter: GDString | StringName | string = "", allowEmpty: boolean = true, maxsplit: number = 0): PackedStringArray;
        rsplit(delimiter: GDString | StringName | string = "", allowEmpty: boolean = true, maxsplit: number = 0): PackedStringArray;
        split_floats(delimiter: GDString | StringName | string, allowEmpty: boolean = true): PackedFloat64Array;
        join(parts: PackedStringArray): GDString;
        to_upper(): GDString;
        to_lower(): GDString;
        left(length: number): GDString;
        right(length: number): GDString;
        strip_edges(left: boolean = true, right: boolean = true): GDString;
        strip_escapes(): GDString;
        lstrip(chars: GDString | StringName | string): GDString;
        rstrip(chars: GDString | StringName | string): GDString;
        get_extension(): GDString;
        get_basename(): GDString;
        path_join(path: GDString | StringName | string): GDString;
        unicode_at(at: number): number;
        indent(prefix: GDString | StringName | string): GDString;
        dedent(): GDString;
        md5_text(): GDString;
        sha1_text(): GDString;
        sha256_text(): GDString;
        md5_buffer(): PackedByteArray;
        sha1_buffer(): PackedByteArray;
        sha256_buffer(): PackedByteArray;
        is_empty(): boolean;
        contains(what: GDString | StringName | string): boolean;
        containsn(what: GDString | StringName | string): boolean;
        is_absolute_path(): boolean;
        is_relative_path(): boolean;
        simplify_path(): GDString;
        get_base_dir(): GDString;
        get_file(): GDString;
        xml_escape(escapeQuotes: boolean = false): GDString;
        xml_unescape(): GDString;
        uri_encode(): GDString;
        uri_decode(): GDString;
        uri_file_decode(): GDString;
        c_escape(): GDString;
        c_unescape(): GDString;
        json_escape(): GDString;
        validate_node_name(): GDString;
        validate_filename(): GDString;
        is_valid_ascii_identifier(): boolean;
        is_valid_unicode_identifier(): boolean;
        is_valid_identifier(): boolean;
        is_valid_int(): boolean;
        is_valid_float(): boolean;
        is_valid_hex_number(withPrefix: boolean = false): boolean;
        is_valid_html_color(): boolean;
        is_valid_ip_address(): boolean;
        is_valid_filename(): boolean;
        to_int(): number;
        to_float(): number;
        hex_to_int(): number;
        bin_to_int(): number;
        lpad(minLength: number, character: GDString | StringName | string = " "): GDString;
        rpad(minLength: number, character: GDString | StringName | string = " "): GDString;
        pad_decimals(digits: number): GDString;
        pad_zeros(digits: number): GDString;
        trim_prefix(prefix: GDString | StringName | string): GDString;
        trim_suffix(suffix: GDString | StringName | string): GDString;
        to_ascii_buffer(): PackedByteArray;
        to_utf8_buffer(): PackedByteArray;
        to_utf16_buffer(): PackedByteArray;
        to_utf32_buffer(): PackedByteArray;
        to_wchar_buffer(): PackedByteArray;
        to_multibyte_char_buffer(encoding: GDString | StringName | string = ""): PackedByteArray;
        hex_decode(): PackedByteArray;
        hash(): number;
        
        /*
        // equals(any): boolean
        // not_equals(any): boolean
        // module(any): GDString
        // op_not(any): boolean
        // module(boolean): GDString
        // module(number): GDString
        // module(number): GDString
        // equals(GDString): boolean
        // not_equals(GDString): boolean
        // add(GDString): GDString
        // module(GDString): GDString
        // in_op(GDString): boolean
        // module(Vector2): GDString
        // module(Vector2i): GDString
        // module(Rect2): GDString
        // module(Rect2i): GDString
        // module(Vector3): GDString
        // module(Vector3i): GDString
        // module(Transform2D): GDString
        // module(Vector4): GDString
        // module(Vector4i): GDString
        // module(Plane): GDString
        // module(Quaternion): GDString
        // module(AABB): GDString
        // module(Basis): GDString
        // module(Transform3D): GDString
        // module(Projection): GDString
        // module(Color): GDString
        // equals(StringName): boolean
        // not_equals(StringName): boolean
        // less(StringName): boolean
        // less_equal(StringName): boolean
        // greater(StringName): boolean
        // greater_equal(StringName): boolean
        // add(StringName): GDString
        // module(StringName): GDString
        // in_op(StringName): boolean
        // module(NodePath): GDString
        // module(RID): GDString
        // module(GodotObject): GDString
        // in_op(GodotObject): boolean
        // module(Callable): GDString
        // module(Signal): GDString
        // module(Dictionary): GDString
        // in_op(Dictionary): boolean
        // module(GDArray): GDString
        // in_op(GDArray): boolean
        // module(PackedByteArray): GDString
        // module(PackedInt32Array): GDString
        // module(PackedInt64Array): GDString
        // module(PackedFloat32Array): GDString
        // module(PackedFloat64Array): GDString
        // module(PackedStringArray): GDString
        // in_op(PackedStringArray): boolean
        // module(PackedVector2Array): GDString
        // module(PackedVector3Array): GDString
        // module(PackedColorArray): GDString
        // module(PackedVector4Array): GDString
        */
    }
}

export {};