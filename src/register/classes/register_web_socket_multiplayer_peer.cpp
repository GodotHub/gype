#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/multiplayer_peer.hpp>
#include <godot_cpp/classes/tls_options.hpp>
#include <godot_cpp/classes/web_socket_peer.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/web_socket_multiplayer_peer.hpp>
using namespace godot;

static void web_socket_multiplayer_peer_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["WebSocketMultiplayerPeer"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef web_socket_multiplayer_peer_class_def = {
    "WebSocketMultiplayerPeer",
    web_socket_multiplayer_peer_class_finalizer
};

static JSValue web_socket_multiplayer_peer_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["WebSocketMultiplayerPeer"];
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
        instance = memnew(WebSocketMultiplayerPeer);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue web_socket_multiplayer_peer_class_create_client(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&WebSocketMultiplayerPeer::create_client, ctx, this_val, argc, argv);
};
static JSValue web_socket_multiplayer_peer_class_create_server(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&WebSocketMultiplayerPeer::create_server, ctx, this_val, argc, argv);
};
static JSValue web_socket_multiplayer_peer_class_get_peer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&WebSocketMultiplayerPeer::get_peer, ctx, this_val, argc, argv);
};
static JSValue web_socket_multiplayer_peer_class_get_peer_address(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&WebSocketMultiplayerPeer::get_peer_address, ctx, this_val, argc, argv);
};
static JSValue web_socket_multiplayer_peer_class_get_peer_port(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&WebSocketMultiplayerPeer::get_peer_port, ctx, this_val, argc, argv);
};
static JSValue web_socket_multiplayer_peer_class_get_supported_protocols(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedStringArray> *proxy = memnew(ObjectProxy<PackedStringArray>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedStringArray {
		WebSocketMultiplayerPeer *obj = static_cast<WebSocketMultiplayerPeer *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_supported_protocols();
	};
	proxy->setter = [this_val](const PackedStringArray &value) -> void {
		WebSocketMultiplayerPeer *js_proxy = static_cast<WebSocketMultiplayerPeer *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_supported_protocols(PackedStringArray
(Array(value)));
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["PackedStringArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "PackedStringArrayProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue web_socket_multiplayer_peer_class_set_supported_protocols(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&WebSocketMultiplayerPeer::set_supported_protocols, ctx, this_val, argc, argv);
};
static JSValue web_socket_multiplayer_peer_class_get_handshake_headers(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedStringArray> *proxy = memnew(ObjectProxy<PackedStringArray>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedStringArray {
		WebSocketMultiplayerPeer *obj = static_cast<WebSocketMultiplayerPeer *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_handshake_headers();
	};
	proxy->setter = [this_val](const PackedStringArray &value) -> void {
		WebSocketMultiplayerPeer *js_proxy = static_cast<WebSocketMultiplayerPeer *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_handshake_headers(PackedStringArray
(Array(value)));
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["PackedStringArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "PackedStringArrayProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue web_socket_multiplayer_peer_class_set_handshake_headers(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&WebSocketMultiplayerPeer::set_handshake_headers, ctx, this_val, argc, argv);
};
static JSValue web_socket_multiplayer_peer_class_get_inbound_buffer_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&WebSocketMultiplayerPeer::get_inbound_buffer_size, ctx, this_val, argc, argv);
}
static JSValue web_socket_multiplayer_peer_class_set_inbound_buffer_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&WebSocketMultiplayerPeer::set_inbound_buffer_size, ctx, this_val, argc, argv);
};
static JSValue web_socket_multiplayer_peer_class_get_outbound_buffer_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&WebSocketMultiplayerPeer::get_outbound_buffer_size, ctx, this_val, argc, argv);
}
static JSValue web_socket_multiplayer_peer_class_set_outbound_buffer_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&WebSocketMultiplayerPeer::set_outbound_buffer_size, ctx, this_val, argc, argv);
};
static JSValue web_socket_multiplayer_peer_class_get_handshake_timeout(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&WebSocketMultiplayerPeer::get_handshake_timeout, ctx, this_val, argc, argv);
}
static JSValue web_socket_multiplayer_peer_class_set_handshake_timeout(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&WebSocketMultiplayerPeer::set_handshake_timeout, ctx, this_val, argc, argv);
};
static JSValue web_socket_multiplayer_peer_class_set_max_queued_packets(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&WebSocketMultiplayerPeer::set_max_queued_packets, ctx, this_val, argc, argv);
};
static JSValue web_socket_multiplayer_peer_class_get_max_queued_packets(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&WebSocketMultiplayerPeer::get_max_queued_packets, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry web_socket_multiplayer_peer_class_proto_funcs[] = {
	JS_CFUNC_DEF("create_client", 2, &web_socket_multiplayer_peer_class_create_client),
	JS_CFUNC_DEF("create_server", 3, &web_socket_multiplayer_peer_class_create_server),
	JS_CFUNC_DEF("get_peer", 1, &web_socket_multiplayer_peer_class_get_peer),
	JS_CFUNC_DEF("get_peer_address", 1, &web_socket_multiplayer_peer_class_get_peer_address),
	JS_CFUNC_DEF("get_peer_port", 1, &web_socket_multiplayer_peer_class_get_peer_port),
	JS_CFUNC_DEF("get_supported_protocols", 0, &web_socket_multiplayer_peer_class_get_supported_protocols),
	JS_CFUNC_DEF("set_supported_protocols", 1, &web_socket_multiplayer_peer_class_set_supported_protocols),
	JS_CFUNC_DEF("get_handshake_headers", 0, &web_socket_multiplayer_peer_class_get_handshake_headers),
	JS_CFUNC_DEF("set_handshake_headers", 1, &web_socket_multiplayer_peer_class_set_handshake_headers),
	JS_CFUNC_DEF("get_inbound_buffer_size", 0, &web_socket_multiplayer_peer_class_get_inbound_buffer_size),
	JS_CFUNC_DEF("set_inbound_buffer_size", 1, &web_socket_multiplayer_peer_class_set_inbound_buffer_size),
	JS_CFUNC_DEF("get_outbound_buffer_size", 0, &web_socket_multiplayer_peer_class_get_outbound_buffer_size),
	JS_CFUNC_DEF("set_outbound_buffer_size", 1, &web_socket_multiplayer_peer_class_set_outbound_buffer_size),
	JS_CFUNC_DEF("get_handshake_timeout", 0, &web_socket_multiplayer_peer_class_get_handshake_timeout),
	JS_CFUNC_DEF("set_handshake_timeout", 1, &web_socket_multiplayer_peer_class_set_handshake_timeout),
	JS_CFUNC_DEF("set_max_queued_packets", 1, &web_socket_multiplayer_peer_class_set_max_queued_packets),
	JS_CFUNC_DEF("get_max_queued_packets", 0, &web_socket_multiplayer_peer_class_get_max_queued_packets),
};




static void define_web_socket_multiplayer_peer_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "supported_protocols"),
        JS_NewCFunction(ctx, web_socket_multiplayer_peer_class_get_supported_protocols, "get_supported_protocols", 0),
        JS_NewCFunction(ctx, web_socket_multiplayer_peer_class_set_supported_protocols, "set_supported_protocols", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "handshake_headers"),
        JS_NewCFunction(ctx, web_socket_multiplayer_peer_class_get_handshake_headers, "get_handshake_headers", 0),
        JS_NewCFunction(ctx, web_socket_multiplayer_peer_class_set_handshake_headers, "set_handshake_headers", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "inbound_buffer_size"),
        JS_NewCFunction(ctx, web_socket_multiplayer_peer_class_get_inbound_buffer_size, "get_inbound_buffer_size", 0),
        JS_NewCFunction(ctx, web_socket_multiplayer_peer_class_set_inbound_buffer_size, "set_inbound_buffer_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "outbound_buffer_size"),
        JS_NewCFunction(ctx, web_socket_multiplayer_peer_class_get_outbound_buffer_size, "get_outbound_buffer_size", 0),
        JS_NewCFunction(ctx, web_socket_multiplayer_peer_class_set_outbound_buffer_size, "set_outbound_buffer_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "handshake_timeout"),
        JS_NewCFunction(ctx, web_socket_multiplayer_peer_class_get_handshake_timeout, "get_handshake_timeout", 0),
        JS_NewCFunction(ctx, web_socket_multiplayer_peer_class_set_handshake_timeout, "set_handshake_timeout", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "max_queued_packets"),
        JS_NewCFunction(ctx, web_socket_multiplayer_peer_class_get_max_queued_packets, "get_max_queued_packets", 0),
        JS_NewCFunction(ctx, web_socket_multiplayer_peer_class_set_max_queued_packets, "set_max_queued_packets", 1),
        JS_PROP_GETSET
    );
}

static void define_web_socket_multiplayer_peer_enum(JSContext *ctx, JSValue ctor) {
}

static int js_web_socket_multiplayer_peer_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["WebSocketMultiplayerPeer"] = class_id;
	classes_by_id[class_id] = "WebSocketMultiplayerPeer";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &web_socket_multiplayer_peer_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["MultiplayerPeer"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_web_socket_multiplayer_peer_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, web_socket_multiplayer_peer_class_proto_funcs, _countof(web_socket_multiplayer_peer_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, web_socket_multiplayer_peer_class_constructor, "WebSocketMultiplayerPeer", 0, JS_CFUNC_constructor, 0);
	define_web_socket_multiplayer_peer_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "WebSocketMultiplayerPeer", ctor);
	ctor_list["WebSocketMultiplayerPeer"] = ctor;

	return 0;
}

JSModuleDef *_js_init_web_socket_multiplayer_peer_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/multiplayer_peer';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_web_socket_multiplayer_peer_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "WebSocketMultiplayerPeer");
	return m;
}

JSModuleDef *js_init_web_socket_multiplayer_peer_module(JSContext *ctx) {
	return _js_init_web_socket_multiplayer_peer_module(ctx, "@godot/classes/web_socket_multiplayer_peer");
}

void __register_web_socket_multiplayer_peer() {
	js_init_web_socket_multiplayer_peer_module(js_context());
}

void register_web_socket_multiplayer_peer() {
	__register_web_socket_multiplayer_peer();
}