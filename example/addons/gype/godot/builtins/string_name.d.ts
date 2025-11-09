
/**
 * Godot's built-in StringName type.
 *
 * As a data structure, it can be represented by a plain object.
 * @example
 * let my_vector: StringName = { x: 1, y: 0 };
 *
 * To create a new instance, use the global constructor.
 * @example
 * const my_vector = new StringName(1, 0);
 */
export interface StringName {

    casecmpTo(to: GDString | StringName | string): number;
    nocasecmpTo(to: GDString | StringName | string): number;
    naturalcasecmpTo(to: GDString | StringName | string): number;
    naturalnocasecmpTo(to: GDString | StringName | string): number;
    filecasecmpTo(to: GDString | StringName | string): number;
    filenocasecmpTo(to: GDString | StringName | string): number;
    length(): number;
    substr(_from: number, len: number = -1): GDString;
    getSlice(delimiter: GDString | StringName | string, slice: number): GDString;
    getSlicec(delimiter: number, slice: number): GDString;
    getSliceCount(delimiter: GDString | StringName | string): number;
    find(what: GDString | StringName | string, _from: number = 0): number;
    findn(what: GDString | StringName | string, _from: number = 0): number;
    count(what: GDString | StringName | string, _from: number = 0, to: number = 0): number;
    countn(what: GDString | StringName | string, _from: number = 0, to: number = 0): number;
    rfind(what: GDString | StringName | string, _from: number = -1): number;
    rfindn(what: GDString | StringName | string, _from: number = -1): number;
    match(expr: GDString | StringName | string): boolean;
    matchn(expr: GDString | StringName | string): boolean;
    beginsWith(text: GDString | StringName | string): boolean;
    endsWith(text: GDString | StringName | string): boolean;
    isSubsequenceOf(text: GDString | StringName | string): boolean;
    isSubsequenceOfn(text: GDString | StringName | string): boolean;
    bigrams(): PackedStringArray;
    similarity(text: GDString | StringName | string): number;
    format(values: any, placeholder: GDString | StringName | string = "{_}"): GDString;
    replace(what: GDString | StringName | string, forwhat: GDString | StringName | string): GDString;
    replacen(what: GDString | StringName | string, forwhat: GDString | StringName | string): GDString;
    replaceChar(key: number, _with: number): GDString;
    replaceChars(keys: GDString | StringName | string, _with: number): GDString;
    removeChar(what: number): GDString;
    removeChars(chars: GDString | StringName | string): GDString;
    repeat(count: number): GDString;
    reverse(): GDString;
    insert(position: number, what: GDString | StringName | string): GDString;
    erase(position: number, chars: number = 1): GDString;
    capitalize(): GDString;
    toCamelCase(): GDString;
    toPascalCase(): GDString;
    toSnakeCase(): GDString;
    toKebabCase(): GDString;
    split(delimiter: GDString | StringName | string = "", allowEmpty: boolean = true, maxsplit: number = 0): PackedStringArray;
    rsplit(delimiter: GDString | StringName | string = "", allowEmpty: boolean = true, maxsplit: number = 0): PackedStringArray;
    splitFloats(delimiter: GDString | StringName | string, allowEmpty: boolean = true): PackedFloat64Array;
    join(parts: PackedStringArray): GDString;
    toUpper(): GDString;
    toLower(): GDString;
    left(length: number): GDString;
    right(length: number): GDString;
    stripEdges(left: boolean = true, right: boolean = true): GDString;
    stripEscapes(): GDString;
    lstrip(chars: GDString | StringName | string): GDString;
    rstrip(chars: GDString | StringName | string): GDString;
    getExtension(): GDString;
    getBasename(): GDString;
    pathJoin(path: GDString | StringName | string): GDString;
    unicodeAt(at: number): number;
    indent(prefix: GDString | StringName | string): GDString;
    dedent(): GDString;
    md5Text(): GDString;
    sha1Text(): GDString;
    sha256Text(): GDString;
    md5Buffer(): PackedByteArray;
    sha1Buffer(): PackedByteArray;
    sha256Buffer(): PackedByteArray;
    isEmpty(): boolean;
    contains(what: GDString | StringName | string): boolean;
    containsn(what: GDString | StringName | string): boolean;
    isAbsolutePath(): boolean;
    isRelativePath(): boolean;
    simplifyPath(): GDString;
    getBaseDir(): GDString;
    getFile(): GDString;
    xmlEscape(escapeQuotes: boolean = false): GDString;
    xmlUnescape(): GDString;
    uriEncode(): GDString;
    uriDecode(): GDString;
    uriFileDecode(): GDString;
    cEscape(): GDString;
    cUnescape(): GDString;
    jsonEscape(): GDString;
    validateNodeName(): GDString;
    validateFilename(): GDString;
    isValidAsciiIdentifier(): boolean;
    isValidUnicodeIdentifier(): boolean;
    isValidIdentifier(): boolean;
    isValidInt(): boolean;
    isValidFloat(): boolean;
    isValidHexNumber(withPrefix: boolean = false): boolean;
    isValidHtmlColor(): boolean;
    isValidIpAddress(): boolean;
    isValidFilename(): boolean;
    toInt(): number;
    toFloat(): number;
    hexToInt(): number;
    binToInt(): number;
    lpad(minLength: number, character: GDString | StringName | string = " "): GDString;
    rpad(minLength: number, character: GDString | StringName | string = " "): GDString;
    padDecimals(digits: number): GDString;
    padZeros(digits: number): GDString;
    trimPrefix(prefix: GDString | StringName | string): GDString;
    trimSuffix(suffix: GDString | StringName | string): GDString;
    toAsciiBuffer(): PackedByteArray;
    toUtf8Buffer(): PackedByteArray;
    toUtf16Buffer(): PackedByteArray;
    toUtf32Buffer(): PackedByteArray;
    toWcharBuffer(): PackedByteArray;
    toMultibyteCharBuffer(encoding: GDString | StringName | string = ""): PackedByteArray;
    hexDecode(): PackedByteArray;
    hash(): number;
}

/**
 * A global constructor and namespace for the StringName type.
 *
 * Use `new StringName(...)` to create a new instance.
 * Access static members like `StringName.ZERO`.
 */
export declare const StringName: {
    new(): StringName;
    new(_from: GDString | StringName | string): StringName;
    new(_from: GDString | StringName | string): StringName;


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
};