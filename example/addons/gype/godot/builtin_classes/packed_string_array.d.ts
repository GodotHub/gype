

declare global {
export declare class PackedStringArray {
  constructor();
  constructor(_from: PackedStringArray);
  constructor(_from: GDArray);
  public size(): number;
  public is_empty(): boolean;
  public set(_index: number, _value: GDString | StringName | string): void;
  public push_back(_value: GDString | StringName | string): boolean;
  public append(_value: GDString | StringName | string): boolean;
  public append_array(_array: PackedStringArray): void;
  public remove_at(_index: number): void;
  public insert(_at_index: number, _value: GDString | StringName | string): number;
  public fill(_value: GDString | StringName | string): void;
  public resize(_new_size: number): number;
  public clear(): void;
  public has(_value: GDString | StringName | string): boolean;
  public reverse(): void;
  public slice(_begin: number, _end: number = 2147483647): PackedStringArray;
  public to_byte_array(): PackedByteArray;
  public sort(): void;
  public bsearch(_value: GDString | StringName | string, _before: boolean = true): number;
  public duplicate(): PackedStringArray;
  public find(_value: GDString | StringName | string, _from: number = 0): number;
  public rfind(_value: GDString | StringName | string, _from: number = -1): number;
  public count(_value: GDString | StringName | string): number;
}
}

export {};