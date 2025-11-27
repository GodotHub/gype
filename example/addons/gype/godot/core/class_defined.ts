import { GodotObject } from "@godot/classes/godot_object";
import { RefCounted } from "@godot/classes/ref_counted";

const _GodotClass = Symbol("_GodotClass");
const _Tool = Symbol("_Tool");
const _Export = Symbol("_Export");

type GodotConstructor = abstract new () => GodotObject;

export function GodotClass<T extends GodotConstructor>(
  target: T,
  context: ClassDecoratorContext<T>
): void {
  if (context.kind !== "class") {
    throw new Error("GodotClass decorator can only be applied to classes.");
  }

  (target as any)[_GodotClass] = true;
}

export function GodotTool<T extends GodotConstructor>(
  target: T,
  context: ClassDecoratorContext<T>
): void {
  if (context.kind !== "class") {
    throw new Error("GodotTool decorator can only be applied to classes.");
  }

  (target as any)[_Tool] = true;
}

export function GodotExport(type: number) {
  return function (value: undefined, context: ClassFieldDecoratorContext) {};
}

interface SignalArgument {
  name: string;
  type: number;
}

type SignalDecorator = <T extends GodotObject>(
  value: undefined,
  context: ClassFieldDecoratorContext<T, Signal>
) => void;

export function GodotSignal(...args: SignalArgument[]): SignalDecorator;
export function GodotSignal<T extends GodotObject>(
  value: undefined,
  context: ClassFieldDecoratorContext<T, Signal>
): void;

export function GodotSignal(...args: any[]): SignalDecorator | void {
  const decoratorLogic = (
    context: ClassFieldDecoratorContext<any, Signal>,
    signalArgs: SignalArgument[]
  ): void => {
    const propertyKey = context.name as string;

    context.addInitializer(function (this: GodotObject) {
      // const godotArgs = signalArgs.flatMap(arg => [arg.name, arg.type]);
      this.add_user_signal(propertyKey, signalArgs);
      const signalValue = new Signal(this, propertyKey);

      Object.defineProperty(this, propertyKey, {
        value: signalValue,
        writable: false,
        configurable: false,
        enumerable: false,
      });
    });
  };

  // --- 调用方式判断 ---
  const isDirectUsage =
    args.length === 2 &&
    args[0] === undefined &&
    args[1] &&
    typeof args[1] === "object" &&
    "kind" in args[1] &&
    args[1].kind === "field";

  if (isDirectUsage) {
    const context = args[1] as ClassFieldDecoratorContext<any, Signal>;
    decoratorLogic(context, []);
  } else {
    const signalArgs = args as SignalArgument[];
    return (
      value: undefined,
      context: ClassFieldDecoratorContext<any, Signal>
    ) => {
      decoratorLogic(context, signalArgs);
    };
  }
}

const _resolvers = new Set();

export function to_promise(signal: Signal): Promise<void> {
  return new Promise((resolve, reject): void => {
    const resolver = new Resolver(resolve);
    signal.connect(resolver.callback, 4);
  });
}

class Resolver extends RefCounted {
  #resolve: Function;
  #callback: Callable;

  constructor(resolve: Function) {
    super();
    this.#resolve = resolve;
    this.#callback = new Callable(this, this.resolve);
    _resolvers.add(this);
  }

  get callback() {
    return this.#callback;
  }

  public resolve(): void {
    this.#resolve();
    _resolvers.delete(this);
  }
}
