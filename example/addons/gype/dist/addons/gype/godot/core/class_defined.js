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
const _GodotClass = Symbol("_GodotClass");
export function GodotClass(target) {
    target[_GodotClass] = true;
    return target;
}
const _Tool = Symbol("_Tool");
export function Tool(target) {
    target[_Tool] = true;
    return target;
}
const _resolvers = new Set();
export function to_promise(signal) {
    return new Promise((resolve, reject) => {
        let instance = signal.get_object();
        GD.print(instance);
        if (!GD.is_instance_id_valid(instance.get_instance_id()))
            reject("instance invalid");
        const resolver = new Resolver(resolve);
        _resolvers.add(resolver);
        signal.connect(resolver.callback, 4);
    });
}
class Resolver extends Node {
    constructor(resolve) {
        super();
        _Resolver_resolve.set(this, void 0);
        _Resolver_callback.set(this, void 0);
        __classPrivateFieldSet(this, _Resolver_resolve, resolve, "f");
        __classPrivateFieldSet(this, _Resolver_callback, new Callable(this, this.resolve), "f");
    }
    get callback() {
        return __classPrivateFieldGet(this, _Resolver_callback, "f");
    }
    resolve() {
        __classPrivateFieldGet(this, _Resolver_resolve, "f").call(this);
    }
}
_Resolver_resolve = new WeakMap(), _Resolver_callback = new WeakMap();
//# sourceMappingURL=class_defined.js.map