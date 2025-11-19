#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/multiplayer_api.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/scene_multiplayer.hpp>
using namespace godot;

static void scene_multiplayer_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["SceneMultiplayer"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef scene_multiplayer_class_def = {
    "SceneMultiplayer",
    scene_multiplayer_class_finalizer
};

static JSValue scene_multiplayer_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["SceneMultiplayer"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    SceneMultiplayer *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<SceneMultiplayer *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(SceneMultiplayer);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue scene_multiplayer_class_set_root_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SceneMultiplayer::set_root_path, ctx, this_val, argc, argv);
};
static JSValue scene_multiplayer_class_get_root_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<NodePath> *proxy = memnew(ObjectProxy<NodePath>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> NodePath {
		SceneMultiplayer *obj = static_cast<SceneMultiplayer *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_root_path();
	};
	proxy->setter = [this_val](const NodePath &value) -> void {
		SceneMultiplayer *js_proxy = static_cast<SceneMultiplayer *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_root_path(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["NodePathProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "NodePathProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue scene_multiplayer_class_clear(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SceneMultiplayer::clear, ctx, this_val, argc, argv);
};
static JSValue scene_multiplayer_class_disconnect_peer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SceneMultiplayer::disconnect_peer, ctx, this_val, argc, argv);
};
static JSValue scene_multiplayer_class_get_authenticating_peers(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&SceneMultiplayer::get_authenticating_peers, ctx, this_val, argc, argv);
};
static JSValue scene_multiplayer_class_send_auth(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&SceneMultiplayer::send_auth, ctx, this_val, argc, argv);
};
static JSValue scene_multiplayer_class_complete_auth(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&SceneMultiplayer::complete_auth, ctx, this_val, argc, argv);
};
static JSValue scene_multiplayer_class_set_auth_callback(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SceneMultiplayer::set_auth_callback, ctx, this_val, argc, argv);
};
static JSValue scene_multiplayer_class_get_auth_callback(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Callable> *proxy = memnew(ObjectProxy<Callable>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Callable {
		SceneMultiplayer *obj = static_cast<SceneMultiplayer *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_auth_callback();
	};
	proxy->setter = [this_val](const Callable &value) -> void {
		SceneMultiplayer *js_proxy = static_cast<SceneMultiplayer *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_auth_callback(value);
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
static JSValue scene_multiplayer_class_set_auth_timeout(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SceneMultiplayer::set_auth_timeout, ctx, this_val, argc, argv);
};
static JSValue scene_multiplayer_class_get_auth_timeout(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SceneMultiplayer::get_auth_timeout, ctx, this_val, argc, argv);
}
static JSValue scene_multiplayer_class_set_refuse_new_connections(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SceneMultiplayer::set_refuse_new_connections, ctx, this_val, argc, argv);
};
static JSValue scene_multiplayer_class_is_refusing_new_connections(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SceneMultiplayer::is_refusing_new_connections, ctx, this_val, argc, argv);
}
static JSValue scene_multiplayer_class_set_allow_object_decoding(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SceneMultiplayer::set_allow_object_decoding, ctx, this_val, argc, argv);
};
static JSValue scene_multiplayer_class_is_object_decoding_allowed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SceneMultiplayer::is_object_decoding_allowed, ctx, this_val, argc, argv);
}
static JSValue scene_multiplayer_class_set_server_relay_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SceneMultiplayer::set_server_relay_enabled, ctx, this_val, argc, argv);
};
static JSValue scene_multiplayer_class_is_server_relay_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SceneMultiplayer::is_server_relay_enabled, ctx, this_val, argc, argv);
}
static JSValue scene_multiplayer_class_send_bytes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&SceneMultiplayer::send_bytes, ctx, this_val, argc, argv);
};
static JSValue scene_multiplayer_class_get_max_sync_packet_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SceneMultiplayer::get_max_sync_packet_size, ctx, this_val, argc, argv);
}
static JSValue scene_multiplayer_class_set_max_sync_packet_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SceneMultiplayer::set_max_sync_packet_size, ctx, this_val, argc, argv);
};
static JSValue scene_multiplayer_class_get_max_delta_packet_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SceneMultiplayer::get_max_delta_packet_size, ctx, this_val, argc, argv);
}
static JSValue scene_multiplayer_class_set_max_delta_packet_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SceneMultiplayer::set_max_delta_packet_size, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry scene_multiplayer_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_root_path", 1, &scene_multiplayer_class_set_root_path),
	JS_CFUNC_DEF("get_root_path", 0, &scene_multiplayer_class_get_root_path),
	JS_CFUNC_DEF("clear", 0, &scene_multiplayer_class_clear),
	JS_CFUNC_DEF("disconnect_peer", 1, &scene_multiplayer_class_disconnect_peer),
	JS_CFUNC_DEF("get_authenticating_peers", 0, &scene_multiplayer_class_get_authenticating_peers),
	JS_CFUNC_DEF("send_auth", 2, &scene_multiplayer_class_send_auth),
	JS_CFUNC_DEF("complete_auth", 1, &scene_multiplayer_class_complete_auth),
	JS_CFUNC_DEF("set_auth_callback", 1, &scene_multiplayer_class_set_auth_callback),
	JS_CFUNC_DEF("get_auth_callback", 0, &scene_multiplayer_class_get_auth_callback),
	JS_CFUNC_DEF("set_auth_timeout", 1, &scene_multiplayer_class_set_auth_timeout),
	JS_CFUNC_DEF("get_auth_timeout", 0, &scene_multiplayer_class_get_auth_timeout),
	JS_CFUNC_DEF("set_refuse_new_connections", 1, &scene_multiplayer_class_set_refuse_new_connections),
	JS_CFUNC_DEF("is_refusing_new_connections", 0, &scene_multiplayer_class_is_refusing_new_connections),
	JS_CFUNC_DEF("set_allow_object_decoding", 1, &scene_multiplayer_class_set_allow_object_decoding),
	JS_CFUNC_DEF("is_object_decoding_allowed", 0, &scene_multiplayer_class_is_object_decoding_allowed),
	JS_CFUNC_DEF("set_server_relay_enabled", 1, &scene_multiplayer_class_set_server_relay_enabled),
	JS_CFUNC_DEF("is_server_relay_enabled", 0, &scene_multiplayer_class_is_server_relay_enabled),
	JS_CFUNC_DEF("send_bytes", 4, &scene_multiplayer_class_send_bytes),
	JS_CFUNC_DEF("get_max_sync_packet_size", 0, &scene_multiplayer_class_get_max_sync_packet_size),
	JS_CFUNC_DEF("set_max_sync_packet_size", 1, &scene_multiplayer_class_set_max_sync_packet_size),
	JS_CFUNC_DEF("get_max_delta_packet_size", 0, &scene_multiplayer_class_get_max_delta_packet_size),
	JS_CFUNC_DEF("set_max_delta_packet_size", 1, &scene_multiplayer_class_set_max_delta_packet_size),
};


static JSValue scene_multiplayer_class_get_peer_authenticating_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	SceneMultiplayer *opaque = static_cast<SceneMultiplayer *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "peer_authenticating_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "peer_authenticating"));
		JS_DefinePropertyValueStr(ctx, this_val, "peer_authenticating_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue scene_multiplayer_class_get_peer_authentication_failed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	SceneMultiplayer *opaque = static_cast<SceneMultiplayer *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "peer_authentication_failed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "peer_authentication_failed"));
		JS_DefinePropertyValueStr(ctx, this_val, "peer_authentication_failed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue scene_multiplayer_class_get_peer_packet_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	SceneMultiplayer *opaque = static_cast<SceneMultiplayer *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "peer_packet_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "peer_packet"));
		JS_DefinePropertyValueStr(ctx, this_val, "peer_packet_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_scene_multiplayer_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "root_path"),
        JS_NewCFunction(ctx, scene_multiplayer_class_get_root_path, "get_root_path", 0),
        JS_NewCFunction(ctx, scene_multiplayer_class_set_root_path, "set_root_path", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "auth_callback"),
        JS_NewCFunction(ctx, scene_multiplayer_class_get_auth_callback, "get_auth_callback", 0),
        JS_NewCFunction(ctx, scene_multiplayer_class_set_auth_callback, "set_auth_callback", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "auth_timeout"),
        JS_NewCFunction(ctx, scene_multiplayer_class_get_auth_timeout, "get_auth_timeout", 0),
        JS_NewCFunction(ctx, scene_multiplayer_class_set_auth_timeout, "set_auth_timeout", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "allow_object_decoding"),
        JS_NewCFunction(ctx, scene_multiplayer_class_is_object_decoding_allowed, "is_object_decoding_allowed", 0),
        JS_NewCFunction(ctx, scene_multiplayer_class_set_allow_object_decoding, "set_allow_object_decoding", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "refuse_new_connections"),
        JS_NewCFunction(ctx, scene_multiplayer_class_is_refusing_new_connections, "is_refusing_new_connections", 0),
        JS_NewCFunction(ctx, scene_multiplayer_class_set_refuse_new_connections, "set_refuse_new_connections", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "server_relay"),
        JS_NewCFunction(ctx, scene_multiplayer_class_is_server_relay_enabled, "is_server_relay_enabled", 0),
        JS_NewCFunction(ctx, scene_multiplayer_class_set_server_relay_enabled, "set_server_relay_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "max_sync_packet_size"),
        JS_NewCFunction(ctx, scene_multiplayer_class_get_max_sync_packet_size, "get_max_sync_packet_size", 0),
        JS_NewCFunction(ctx, scene_multiplayer_class_set_max_sync_packet_size, "set_max_sync_packet_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "max_delta_packet_size"),
        JS_NewCFunction(ctx, scene_multiplayer_class_get_max_delta_packet_size, "get_max_delta_packet_size", 0),
        JS_NewCFunction(ctx, scene_multiplayer_class_set_max_delta_packet_size, "set_max_delta_packet_size", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "peer_authenticating"),
		JS_NewCFunction(ctx, scene_multiplayer_class_get_peer_authenticating_signal, "get_peer_authenticating_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "peer_authentication_failed"),
		JS_NewCFunction(ctx, scene_multiplayer_class_get_peer_authentication_failed_signal, "get_peer_authentication_failed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "peer_packet"),
		JS_NewCFunction(ctx, scene_multiplayer_class_get_peer_packet_signal, "get_peer_packet_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_scene_multiplayer_enum(JSContext *ctx, JSValue ctor) {
}

static int js_scene_multiplayer_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["SceneMultiplayer"] = class_id;
	classes_by_id[class_id] = "SceneMultiplayer";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &scene_multiplayer_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["MultiplayerAPI"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_scene_multiplayer_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, scene_multiplayer_class_proto_funcs, _countof(scene_multiplayer_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, scene_multiplayer_class_constructor, "SceneMultiplayer", 0, JS_CFUNC_constructor, 0);
	define_scene_multiplayer_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "SceneMultiplayer", ctor);

	return 0;
}

JSModuleDef *_js_init_scene_multiplayer_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/multiplayer_api';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_scene_multiplayer_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "SceneMultiplayer");
	return m;
}

JSModuleDef *js_init_scene_multiplayer_module(JSContext *ctx) {
	return _js_init_scene_multiplayer_module(ctx, "@godot/classes/scene_multiplayer");
}

void __register_scene_multiplayer() {
	js_init_scene_multiplayer_module(js_context());
}

void register_scene_multiplayer() {
	__register_scene_multiplayer();
}