#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/multiplayer_spawner.hpp>
using namespace godot;

static void multiplayer_spawner_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["MultiplayerSpawner"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef multiplayer_spawner_class_def = {
    "MultiplayerSpawner",
    multiplayer_spawner_class_finalizer
};

static JSValue multiplayer_spawner_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["MultiplayerSpawner"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

	VariantAdapter *adapter = nullptr;
	Object *instance = nullptr;
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
    	instance = static_cast<VariantAdapter *>(JS_GetOpaque(*argv, class_id))->get();
		adapter = memnew(VariantAdapter(instance));
    } else {
        instance = memnew(MultiplayerSpawner);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue multiplayer_spawner_class_add_spawnable_scene(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MultiplayerSpawner::add_spawnable_scene, ctx, this_val, argc, argv);
};
static JSValue multiplayer_spawner_class_get_spawnable_scene_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MultiplayerSpawner::get_spawnable_scene_count, ctx, this_val, argc, argv);
};
static JSValue multiplayer_spawner_class_get_spawnable_scene(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MultiplayerSpawner::get_spawnable_scene, ctx, this_val, argc, argv);
};
static JSValue multiplayer_spawner_class_clear_spawnable_scenes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MultiplayerSpawner::clear_spawnable_scenes, ctx, this_val, argc, argv);
};
static JSValue multiplayer_spawner_class_spawn(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&MultiplayerSpawner::spawn, ctx, this_val, argc, argv);
};
static JSValue multiplayer_spawner_class_get_spawn_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MultiplayerSpawner::get_spawn_path, ctx, this_val, argc, argv);
}
static JSValue multiplayer_spawner_class_set_spawn_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MultiplayerSpawner::set_spawn_path, ctx, this_val, argc, argv);
};
static JSValue multiplayer_spawner_class_get_spawn_limit(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&MultiplayerSpawner::get_spawn_limit, ctx, this_val, argc, argv);
}
static JSValue multiplayer_spawner_class_set_spawn_limit(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MultiplayerSpawner::set_spawn_limit, ctx, this_val, argc, argv);
};
static JSValue multiplayer_spawner_class_get_spawn_function(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Callable> *proxy = memnew(ObjectProxy<Callable>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Callable {
		MultiplayerSpawner *obj = static_cast<MultiplayerSpawner *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_spawn_function();
	};
	proxy->setter = [this_val](const Callable &value) -> void {
		MultiplayerSpawner *js_proxy = static_cast<MultiplayerSpawner *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_spawn_function(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["CallableProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "CallableProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue multiplayer_spawner_class_set_spawn_function(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MultiplayerSpawner::set_spawn_function, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry multiplayer_spawner_class_proto_funcs[] = {
	JS_CFUNC_DEF("add_spawnable_scene", 1, &multiplayer_spawner_class_add_spawnable_scene),
	JS_CFUNC_DEF("get_spawnable_scene_count", 0, &multiplayer_spawner_class_get_spawnable_scene_count),
	JS_CFUNC_DEF("get_spawnable_scene", 1, &multiplayer_spawner_class_get_spawnable_scene),
	JS_CFUNC_DEF("clear_spawnable_scenes", 0, &multiplayer_spawner_class_clear_spawnable_scenes),
	JS_CFUNC_DEF("spawn", 1, &multiplayer_spawner_class_spawn),
	JS_CFUNC_DEF("get_spawn_path", 0, &multiplayer_spawner_class_get_spawn_path),
	JS_CFUNC_DEF("set_spawn_path", 1, &multiplayer_spawner_class_set_spawn_path),
	JS_CFUNC_DEF("get_spawn_limit", 0, &multiplayer_spawner_class_get_spawn_limit),
	JS_CFUNC_DEF("set_spawn_limit", 1, &multiplayer_spawner_class_set_spawn_limit),
	JS_CFUNC_DEF("get_spawn_function", 0, &multiplayer_spawner_class_get_spawn_function),
	JS_CFUNC_DEF("set_spawn_function", 1, &multiplayer_spawner_class_set_spawn_function),
};


static JSValue multiplayer_spawner_class_get_despawned_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	MultiplayerSpawner *opaque = static_cast<MultiplayerSpawner *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "despawned_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "despawned"));
		JS_DefinePropertyValueStr(ctx, this_val, "despawned_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue multiplayer_spawner_class_get_spawned_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	MultiplayerSpawner *opaque = static_cast<MultiplayerSpawner *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "spawned_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "spawned"));
		JS_DefinePropertyValueStr(ctx, this_val, "spawned_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_multiplayer_spawner_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "spawn_path"),
        JS_NewCFunction(ctx, multiplayer_spawner_class_get_spawn_path, "get_spawn_path", 0),
        JS_NewCFunction(ctx, multiplayer_spawner_class_set_spawn_path, "set_spawn_path", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "spawn_limit"),
        JS_NewCFunction(ctx, multiplayer_spawner_class_get_spawn_limit, "get_spawn_limit", 0),
        JS_NewCFunction(ctx, multiplayer_spawner_class_set_spawn_limit, "set_spawn_limit", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "spawn_function"),
        JS_NewCFunction(ctx, multiplayer_spawner_class_get_spawn_function, "get_spawn_function", 0),
        JS_NewCFunction(ctx, multiplayer_spawner_class_set_spawn_function, "set_spawn_function", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "despawned"),
		JS_NewCFunction(ctx, multiplayer_spawner_class_get_despawned_signal, "get_despawned_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "spawned"),
		JS_NewCFunction(ctx, multiplayer_spawner_class_get_spawned_signal, "get_spawned_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_multiplayer_spawner_enum(JSContext *ctx, JSValue ctor) {
}

static int js_multiplayer_spawner_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["MultiplayerSpawner"] = class_id;
	classes_by_id[class_id] = "MultiplayerSpawner";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &multiplayer_spawner_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_multiplayer_spawner_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, multiplayer_spawner_class_proto_funcs, _countof(multiplayer_spawner_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, multiplayer_spawner_class_constructor, "MultiplayerSpawner", 0, JS_CFUNC_constructor, 0);
	define_multiplayer_spawner_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "MultiplayerSpawner", ctor);
	ctor_list["MultiplayerSpawner"] = ctor;

	return 0;
}

JSModuleDef *_js_init_multiplayer_spawner_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_multiplayer_spawner_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "MultiplayerSpawner");
	return m;
}

JSModuleDef *js_init_multiplayer_spawner_module(JSContext *ctx) {
	return _js_init_multiplayer_spawner_module(ctx, "@godot/classes/multiplayer_spawner");
}

void __register_multiplayer_spawner() {
	js_init_multiplayer_spawner_module(js_context());
}

void register_multiplayer_spawner() {
	__register_multiplayer_spawner();
}