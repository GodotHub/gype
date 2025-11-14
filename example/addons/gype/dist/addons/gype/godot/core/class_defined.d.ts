import { GodotObject } from "@godot/classes/godot_object";
type GodotConstructor = new () => GodotObject;
export declare function GodotClass<T extends GodotConstructor>(target: T, context: ClassDecoratorContext<T>): void;
export declare function Tool<T extends GodotConstructor>(target: T, context: ClassDecoratorContext<T>): void;
interface SignalArgument {
    name: string;
    type: number;
}
type SignalDecorator = <T extends GodotObject>(value: undefined, context: ClassFieldDecoratorContext<T, Signal>) => void;
export declare function GodotSignal(...args: SignalArgument[]): SignalDecorator;
export declare function GodotSignal<T extends GodotObject>(value: undefined, context: ClassFieldDecoratorContext<T, Signal>): void;
export declare function to_promise(signal: Signal): Promise<void>;
export {};
//# sourceMappingURL=class_defined.d.ts.map