import { GodotObject } from "@godot/classes/godot_object";
import { RefCounted } from "@godot/classes/ref_counted";

const _Tool = Symbol("_Tool");
const _Export = Symbol("_Export");

type GodotConstructor = new () => GodotObject;

export function GodotTool<T extends GodotConstructor>(
  target: T,
  context: ClassDecoratorContext<T>
): void {
  if (context.kind !== "class") {
    throw new Error("GodotTool decorator can only be applied to classes.");
  }

  (target as any)[_Tool] = true;
}

export function GodotExport(
  target: any,
  context: ClassFieldDecoratorContext<any>
): void {}

export function GodotSignal<T extends (...args: any[]) => any>(
  value: undefined,
  context: ClassFieldDecoratorContext<any, Signal<T>>
) {
  if (context.kind !== "field") {
    throw new Error(
      "GodotSignal decorator can only be applied to class fields."
    );
  }
  context.addInitializer(function () {
    if (!(this as GodotObject).has_user_signal(String(context.name))) {
      (this as GodotObject).add_user_signal(String(context.name));
    }
    (this as any)[context.name] = new Signal<T>(this, String(context.name));
  });
}

const _resolvers = new Set();

export function to_promise(signal: Signal<any>): Promise<void> {
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
