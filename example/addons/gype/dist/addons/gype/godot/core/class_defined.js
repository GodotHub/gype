var __classPrivateFieldSet = (this && this.__classPrivateFieldSet) || function (receiver, state, value, kind, f) {
    if (kind === "m") throw new TypeError("Private method is not writable");
    if (kind === "a" && !f) throw new TypeError("Private accessor was defined without a setter");
    if (typeof state === "function" ? receiver !== state || !f : !state.has(receiver)) throw new TypeError("Cannot write private member to an object whose class did not declare it");
    return (kind === "a" ? f.call(receiver, value) : f ? f.value = value : state.set(receiver, value)), value;
};
var __classPrivateFieldGet = (this && this.__classPrivateFieldGet) || function (receiver, state, kind, f) {
    if (kind === "a" && !f) throw new TypeError("Private accessor was defined without a getter");
    if (typeof state === "function" ? receiver !== state || !f : !state.has(receiver)) throw new TypeError("Cannot read private member from an object whose class did not declare it");
    return kind === "m" ? f : kind === "a" ? f.call(receiver) : f ? f.value : state.get(receiver);
};
var _Resolver_resolve, _Resolver_callback;
import { Node } from "@godot/classes/node";
import { GodotObject } from "@godot/classes/godot_object";
import { RefCounted } from "@godot/classes/ref_counted";
const _GodotClass = Symbol("_GodotClass");
const _Tool = Symbol("_Tool");
export function GodotClass(target, context) {
    if (context.kind !== "class") {
        throw new Error("GodotClass decorator can only be applied to classes.");
    }
    target[_GodotClass] = true;
}
export function Tool(target, context) {
    if (context.kind !== "class") {
        throw new Error("Tool decorator can only be applied to classes.");
    }
    target[_Tool] = true;
}
export function GodotSignal(...args) {
    const decoratorLogic = (context, signalArgs) => {
        const propertyKey = context.name;
        context.addInitializer(function () {
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
    const isDirectUsage = args.length === 2 &&
        args[0] === undefined &&
        args[1] &&
        typeof args[1] === 'object' &&
        'kind' in args[1] &&
        args[1].kind === 'field';
    if (isDirectUsage) {
        const context = args[1];
        decoratorLogic(context, []);
    }
    else {
        const signalArgs = args;
        return (value, context) => {
            decoratorLogic(context, signalArgs);
        };
    }
}
const _resolvers = new Set();
export function to_promise(signal) {
    return new Promise((resolve, reject) => {
        const resolver = new Resolver(resolve);
        signal.connect(resolver.callback, 4);
    });
}
class Resolver extends RefCounted {
    constructor(resolve) {
        super();
        _Resolver_resolve.set(this, void 0);
        _Resolver_callback.set(this, void 0);
        __classPrivateFieldSet(this, _Resolver_resolve, resolve, "f");
        __classPrivateFieldSet(this, _Resolver_callback, new Callable(this, this.resolve), "f");
        _resolvers.add(this);
    }
    get callback() {
        return __classPrivateFieldGet(this, _Resolver_callback, "f");
    }
    resolve() {
        __classPrivateFieldGet(this, _Resolver_resolve, "f").call(this);
        _resolvers.delete(this);
    }
}
_Resolver_resolve = new WeakMap(), _Resolver_callback = new WeakMap();
//# sourceMappingURL=class_defined.js.map