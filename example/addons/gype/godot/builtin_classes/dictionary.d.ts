

declare global {
export declare class Dictionary {
  constructor();
  constructor(_from: Dictionary);
  public size(): void;
  public is_empty(): void;
  public clear(): void;
  public merge(_dictionary: Dictionary, _overwrite: boolean): void;
  public merged(_dictionary: Dictionary, _overwrite: boolean): void;
  public has(_key: any): void;
  public has_all(_keys: GDArray): void;
  public find_key(_value: any): void;
  public erase(_key: any): void;
  public hash(): void;
  public keys(): void;
  public values(): void;
  public duplicate(_deep: boolean): void;
  public get(_key: any, _default: any): void;
  public get_or_add(_key: any, _default: any): void;
  public make_read_only(): void;
  public is_read_only(): void;
  public recursive_equal(_dictionary: Dictionary, _recursion_count: number): void;
}
}

export {};