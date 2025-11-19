#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/multiplayer_peer.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/multiplayer_api.hpp>
using namespace godot;

static void multiplayer_api_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["MultiplayerAPI"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
	}
}

static JSClassDef multiplayer_api_class_def = {
    "MultiplayerAPI",
    multiplayer_api_class_finalizer
};

static JSValue multiplayer_api_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["MultiplayerAPI"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    MultiplayerAPI *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<MultiplayerAPI *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(MultiplayerAPI);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue multiplayer_api_class_has_multiplayer_peer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&MultiplayerAPI::has_multiplayer_peer, ctx, this_val, argc, argv);
};
static JSValue multiplayer_api_class_get_multiplayer_peer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&MultiplayerAPI::get_multiplayer_peer, ctx, this_val, argc, argv);
}
static JSValue multiplayer_api_class_set_multiplayer_peer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&MultiplayerAPI::set_multiplayer_peer, ctx, this_val, argc, argv);
};
static JSValue multiplayer_api_class_get_unique_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&MultiplayerAPI::get_unique_id, ctx, this_val, argc, argv);
};
static JSValue multiplayer_api_class_is_server(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&MultiplayerAPI::is_server, ctx, this_val, argc, argv);
};
static JSValue multiplayer_api_class_get_remote_sender_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&MultiplayerAPI::get_remote_sender_id, ctx, this_val, argc, argv);
};
static JSValue multiplayer_api_class_poll(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&MultiplayerAPI::poll, ctx, this_val, argc, argv);
};
static JSValue multiplayer_api_class_rpc(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&MultiplayerAPI::rpc, ctx, this_val, argc, argv);
};
static JSValue multiplayer_api_class_object_configuration_add(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&MultiplayerAPI::object_configuration_add, ctx, this_val, argc, argv);
};
static JSValue multiplayer_api_class_object_configuration_remove(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&MultiplayerAPI::object_configuration_remove, ctx, this_val, argc, argv);
};
static JSValue multiplayer_api_class_get_peers(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&MultiplayerAPI::get_peers, ctx, this_val, argc, argv);
};


static JSValue multiplayer_api_class_set_default_interface(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    return call_builtin_static_method_no_ret(&MultiplayerAPI::set_default_interface, ctx, this_val, argc, argv);
};
static JSValue multiplayer_api_class_get_default_interface(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&MultiplayerAPI::get_default_interface, ctx, this_val, argc, argv);
};
static JSValue multiplayer_api_class_create_default_interface(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_method_ret(&MultiplayerAPI::create_default_interface, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry multiplayer_api_class_proto_funcs[] = {
	JS_CFUNC_DEF("has_multiplayer_peer", 0, &multiplayer_api_class_has_multiplayer_peer),
	JS_CFUNC_DEF("get_multiplayer_peer", 0, &multiplayer_api_class_get_multiplayer_peer),
	JS_CFUNC_DEF("set_multiplayer_peer", 1, &multiplayer_api_class_set_multiplayer_peer),
	JS_CFUNC_DEF("get_unique_id", 0, &multiplayer_api_class_get_unique_id),
	JS_CFUNC_DEF("is_server", 0, &multiplayer_api_class_is_server),
	JS_CFUNC_DEF("get_remote_sender_id", 0, &multiplayer_api_class_get_remote_sender_id),
	JS_CFUNC_DEF("poll", 0, &multiplayer_api_class_poll),
	JS_CFUNC_DEF("rpc", 4, &multiplayer_api_class_rpc),
	JS_CFUNC_DEF("object_configuration_add", 2, &multiplayer_api_class_object_configuration_add),
	JS_CFUNC_DEF("object_configuration_remove", 2, &multiplayer_api_class_object_configuration_remove),
	JS_CFUNC_DEF("get_peers", 0, &multiplayer_api_class_get_peers),
};

static const JSCFunctionListEntry multiplayer_api_class_static_funcs[] = {
	JS_CFUNC_DEF("set_default_interface", 1, &multiplayer_api_class_set_default_interface),
	JS_CFUNC_DEF("get_default_interface", 0, &multiplayer_api_class_get_default_interface),
	JS_CFUNC_DEF("create_default_interface", 0, &multiplayer_api_class_create_default_interface),
};

static JSValue multiplayer_api_class_get_peer_connected_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	MultiplayerAPI *opaque = static_cast<MultiplayerAPI *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "peer_connected_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "peer_connected"));
		JS_DefinePropertyValueStr(ctx, this_val, "peer_connected_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue multiplayer_api_class_get_peer_disconnected_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	MultiplayerAPI *opaque = static_cast<MultiplayerAPI *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "peer_disconnected_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "peer_disconnected"));
		JS_DefinePropertyValueStr(ctx, this_val, "peer_disconnected_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue multiplayer_api_class_get_connected_to_server_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	MultiplayerAPI *opaque = static_cast<MultiplayerAPI *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "connected_to_server_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "connected_to_server"));
		JS_DefinePropertyValueStr(ctx, this_val, "connected_to_server_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue multiplayer_api_class_get_connection_failed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	MultiplayerAPI *opaque = static_cast<MultiplayerAPI *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "connection_failed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "connection_failed"));
		JS_DefinePropertyValueStr(ctx, this_val, "connection_failed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue multiplayer_api_class_get_server_disconnected_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	MultiplayerAPI *opaque = static_cast<MultiplayerAPI *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "server_disconnected_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "server_disconnected"));
		JS_DefinePropertyValueStr(ctx, this_val, "server_disconnected_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_multiplayer_api_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "multiplayer_peer"),
        JS_NewCFunction(ctx, multiplayer_api_class_get_multiplayer_peer, "get_multiplayer_peer", 0),
        JS_NewCFunction(ctx, multiplayer_api_class_set_multiplayer_peer, "set_multiplayer_peer", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "peer_connected"),
		JS_NewCFunction(ctx, multiplayer_api_class_get_peer_connected_signal, "get_peer_connected_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "peer_disconnected"),
		JS_NewCFunction(ctx, multiplayer_api_class_get_peer_disconnected_signal, "get_peer_disconnected_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "connected_to_server"),
		JS_NewCFunction(ctx, multiplayer_api_class_get_connected_to_server_signal, "get_connected_to_server_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "connection_failed"),
		JS_NewCFunction(ctx, multiplayer_api_class_get_connection_failed_signal, "get_connection_failed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "server_disconnected"),
		JS_NewCFunction(ctx, multiplayer_api_class_get_server_disconnected_signal, "get_server_disconnected_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_multiplayer_api_enum(JSContext *ctx, JSValue ctor) {
	JSValue RPCMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, RPCMode_obj, "RPC_MODE_DISABLED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, RPCMode_obj, "RPC_MODE_ANY_PEER", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, RPCMode_obj, "RPC_MODE_AUTHORITY", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "RPCMode", RPCMode_obj);
}

static int js_multiplayer_api_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["MultiplayerAPI"] = class_id;
	classes_by_id[class_id] = "MultiplayerAPI";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &multiplayer_api_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_multiplayer_api_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, multiplayer_api_class_proto_funcs, _countof(multiplayer_api_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, multiplayer_api_class_constructor, "MultiplayerAPI", 0, JS_CFUNC_constructor, 0);
	JS_SetPropertyFunctionList(ctx, ctor, multiplayer_api_class_static_funcs, _countof(multiplayer_api_class_static_funcs));
	define_multiplayer_api_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "MultiplayerAPI", ctor);

	return 0;
}

JSModuleDef *_js_init_multiplayer_api_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_multiplayer_api_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "MultiplayerAPI");
	return m;
}

JSModuleDef *js_init_multiplayer_api_module(JSContext *ctx) {
	return _js_init_multiplayer_api_module(ctx, "@godot/classes/multiplayer_api");
}

void __register_multiplayer_api() {
	js_init_multiplayer_api_module(js_context());
}

void register_multiplayer_api() {
	__register_multiplayer_api();
}