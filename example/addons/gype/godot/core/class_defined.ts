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

// 1. 重载签名 A：无参数直接使用 -> @GodotExport
export function GodotExport(
  target: undefined, 
  context: ClassFieldDecoratorContext
): void;

// 2. 重载签名 B：带参数工厂模式 -> @GodotExport(1)
export function GodotExport(
  hint: number
): (target: undefined, context: ClassFieldDecoratorContext) => void;

// 3. 统一实现函数 (Implementation)
export function GodotExport(arg1: any, arg2?: any) {
  // 提取通用的业务逻辑
  const runLogic = (ctx: ClassFieldDecoratorContext, hint?: number) => {
    
  };

  // --- 运行时判断 ---
  
  // 在 Stage 3 标准中，直接使用装饰器时：
  // arg1 是 undefined (字段初始值占位)
  // arg2 是 context 对象 (包含 kind: 'field')
  const isDirectUsage = 
    arg2 && 
    typeof arg2 === 'object' && 
    arg2.kind === 'field';

  if (isDirectUsage) {
    // 场景 1: @GodotExport
    // arg1 是 target(undefined), arg2 是 context
    return runLogic(arg2);
  } else {
    // 场景 2: @GodotExport(1)
    // arg1 是 hint (number)
    const hint = arg1;
    
    // 返回真正的装饰器函数
    return function (target: undefined, context: ClassFieldDecoratorContext) {
      runLogic(context, hint);
    };
  }
}


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
