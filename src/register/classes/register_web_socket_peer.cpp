#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/packet_peer.hpp>
#include <godot_cpp/classes/stream_peer.hpp>
#include <godot_cpp/classes/tls_options.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/web_socket_peer.hpp>
using namespace godot;

static void web_socket_peer_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["WebSocketPeer"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef web_socket_peer_class_def = {
    "WebSocketPeer",
    web_socket_peer_class_finalizer
};

static JSValue web_socket_peer_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["WebSocketPeer"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    WebSocketPeer *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<WebSocketPeer *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(WebSocketPeer);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue web_socket_peer_class_connect_to_url(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&WebSocketPeer::connect_to_url, ctx, this_val, argc, argv);
};
static JSValue web_socket_peer_class_accept_stream(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&WebSocketPeer::accept_stream, ctx, this_val, argc, argv);
};
static JSValue web_socket_peer_class_send(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&WebSocketPeer::send, ctx, this_val, argc, argv);
};
static JSValue web_socket_peer_class_send_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&WebSocketPeer::send_text, ctx, this_val, argc, argv);
};
static JSValue web_socket_peer_class_was_string_packet(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&WebSocketPeer::was_string_packet, ctx, this_val, argc, argv);
};
static JSValue web_socket_peer_class_poll(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&WebSocketPeer::poll, ctx, this_val, argc, argv);
};
static JSValue web_socket_peer_class_close(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&WebSocketPeer::close, ctx, this_val, argc, argv);
};
static JSValue web_socket_peer_class_get_connected_host(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&WebSocketPeer::get_connected_host, ctx, this_val, argc, argv);
};
static JSValue web_socket_peer_class_get_connected_port(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&WebSocketPeer::get_connected_port, ctx, this_val, argc, argv);
};
static JSValue web_socket_peer_class_get_selected_protocol(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&WebSocketPeer::get_selected_protocol, ctx, this_val, argc, argv);
};
static JSValue web_socket_peer_class_get_requested_url(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&WebSocketPeer::get_requested_url, ctx, this_val, argc, argv);
};
static JSValue web_socket_peer_class_set_no_delay(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&WebSocketPeer::set_no_delay, ctx, this_val, argc, argv);
};
static JSValue web_socket_peer_class_get_current_outbound_buffered_amount(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&WebSocketPeer::get_current_outbound_buffered_amount, ctx, this_val, argc, argv);
};
static JSValue web_socket_peer_class_get_ready_state(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&WebSocketPeer::get_ready_state, ctx, this_val, argc, argv);
};
static JSValue web_socket_peer_class_get_close_code(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&WebSocketPeer::get_close_code, ctx, this_val, argc, argv);
};
static JSValue web_socket_peer_class_get_close_reason(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&WebSocketPeer::get_close_reason, ctx, this_val, argc, argv);
};
static JSValue web_socket_peer_class_get_supported_protocols(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedStringArray> *proxy = memnew(ObjectProxy<PackedStringArray>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedStringArray {
		WebSocketPeer *obj = static_cast<WebSocketPeer *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_supported_protocols();
	};
	proxy->setter = [this_val](const PackedStringArray &value) -> void {
		WebSocketPeer *js_proxy = static_cast<WebSocketPeer *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_supported_protocols(PackedStringArray
(Array(value)));
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["PackedStringArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "PackedStringArrayProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue web_socket_peer_class_set_supported_protocols(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&WebSocketPeer::set_supported_protocols, ctx, this_val, argc, argv);
};
static JSValue web_socket_peer_class_get_handshake_headers(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedStringArray> *proxy = memnew(ObjectProxy<PackedStringArray>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedStringArray {
		WebSocketPeer *obj = static_cast<WebSocketPeer *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_handshake_headers();
	};
	proxy->setter = [this_val](const PackedStringArray &value) -> void {
		WebSocketPeer *js_proxy = static_cast<WebSocketPeer *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_handshake_headers(PackedStringArray
(Array(value)));
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["PackedStringArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "PackedStringArrayProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue web_socket_peer_class_set_handshake_headers(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&WebSocketPeer::set_handshake_headers, ctx, this_val, argc, argv);
};
static JSValue web_socket_peer_class_get_inbound_buffer_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&WebSocketPeer::get_inbound_buffer_size, ctx, this_val, argc, argv);
}
static JSValue web_socket_peer_class_set_inbound_buffer_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&WebSocketPeer::set_inbound_buffer_size, ctx, this_val, argc, argv);
};
static JSValue web_socket_peer_class_get_outbound_buffer_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&WebSocketPeer::get_outbound_buffer_size, ctx, this_val, argc, argv);
}
static JSValue web_socket_peer_class_set_outbound_buffer_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&WebSocketPeer::set_outbound_buffer_size, ctx, this_val, argc, argv);
};
static JSValue web_socket_peer_class_set_max_queued_packets(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&WebSocketPeer::set_max_queued_packets, ctx, this_val, argc, argv);
};
static JSValue web_socket_peer_class_get_max_queued_packets(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&WebSocketPeer::get_max_queued_packets, ctx, this_val, argc, argv);
}
static JSValue web_socket_peer_class_set_heartbeat_interval(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&WebSocketPeer::set_heartbeat_interval, ctx, this_val, argc, argv);
};
static JSValue web_socket_peer_class_get_heartbeat_interval(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&WebSocketPeer::get_heartbeat_interval, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry web_socket_peer_class_proto_funcs[] = {
	JS_CFUNC_DEF("connect_to_url", 2, &web_socket_peer_class_connect_to_url),
	JS_CFUNC_DEF("accept_stream", 1, &web_socket_peer_class_accept_stream),
	JS_CFUNC_DEF("send", 2, &web_socket_peer_class_send),
	JS_CFUNC_DEF("send_text", 1, &web_socket_peer_class_send_text),
	JS_CFUNC_DEF("was_string_packet", 0, &web_socket_peer_class_was_string_packet),
	JS_CFUNC_DEF("poll", 0, &web_socket_peer_class_poll),
	JS_CFUNC_DEF("close", 2, &web_socket_peer_class_close),
	JS_CFUNC_DEF("get_connected_host", 0, &web_socket_peer_class_get_connected_host),
	JS_CFUNC_DEF("get_connected_port", 0, &web_socket_peer_class_get_connected_port),
	JS_CFUNC_DEF("get_selected_protocol", 0, &web_socket_peer_class_get_selected_protocol),
	JS_CFUNC_DEF("get_requested_url", 0, &web_socket_peer_class_get_requested_url),
	JS_CFUNC_DEF("set_no_delay", 1, &web_socket_peer_class_set_no_delay),
	JS_CFUNC_DEF("get_current_outbound_buffered_amount", 0, &web_socket_peer_class_get_current_outbound_buffered_amount),
	JS_CFUNC_DEF("get_ready_state", 0, &web_socket_peer_class_get_ready_state),
	JS_CFUNC_DEF("get_close_code", 0, &web_socket_peer_class_get_close_code),
	JS_CFUNC_DEF("get_close_reason", 0, &web_socket_peer_class_get_close_reason),
	JS_CFUNC_DEF("get_supported_protocols", 0, &web_socket_peer_class_get_supported_protocols),
	JS_CFUNC_DEF("set_supported_protocols", 1, &web_socket_peer_class_set_supported_protocols),
	JS_CFUNC_DEF("get_handshake_headers", 0, &web_socket_peer_class_get_handshake_headers),
	JS_CFUNC_DEF("set_handshake_headers", 1, &web_socket_peer_class_set_handshake_headers),
	JS_CFUNC_DEF("get_inbound_buffer_size", 0, &web_socket_peer_class_get_inbound_buffer_size),
	JS_CFUNC_DEF("set_inbound_buffer_size", 1, &web_socket_peer_class_set_inbound_buffer_size),
	JS_CFUNC_DEF("get_outbound_buffer_size", 0, &web_socket_peer_class_get_outbound_buffer_size),
	JS_CFUNC_DEF("set_outbound_buffer_size", 1, &web_socket_peer_class_set_outbound_buffer_size),
	JS_CFUNC_DEF("set_max_queued_packets", 1, &web_socket_peer_class_set_max_queued_packets),
	JS_CFUNC_DEF("get_max_queued_packets", 0, &web_socket_peer_class_get_max_queued_packets),
	JS_CFUNC_DEF("set_heartbeat_interval", 1, &web_socket_peer_class_set_heartbeat_interval),
	JS_CFUNC_DEF("get_heartbeat_interval", 0, &web_socket_peer_class_get_heartbeat_interval),
};




static void define_web_socket_peer_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "supported_protocols"),
        JS_NewCFunction(ctx, web_socket_peer_class_get_supported_protocols, "get_supported_protocols", 0),
        JS_NewCFunction(ctx, web_socket_peer_class_set_supported_protocols, "set_supported_protocols", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "handshake_headers"),
        JS_NewCFunction(ctx, web_socket_peer_class_get_handshake_headers, "get_handshake_headers", 0),
        JS_NewCFunction(ctx, web_socket_peer_class_set_handshake_headers, "set_handshake_headers", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "inbound_buffer_size"),
        JS_NewCFunction(ctx, web_socket_peer_class_get_inbound_buffer_size, "get_inbound_buffer_size", 0),
        JS_NewCFunction(ctx, web_socket_peer_class_set_inbound_buffer_size, "set_inbound_buffer_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "outbound_buffer_size"),
        JS_NewCFunction(ctx, web_socket_peer_class_get_outbound_buffer_size, "get_outbound_buffer_size", 0),
        JS_NewCFunction(ctx, web_socket_peer_class_set_outbound_buffer_size, "set_outbound_buffer_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "max_queued_packets"),
        JS_NewCFunction(ctx, web_socket_peer_class_get_max_queued_packets, "get_max_queued_packets", 0),
        JS_NewCFunction(ctx, web_socket_peer_class_set_max_queued_packets, "set_max_queued_packets", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "heartbeat_interval"),
        JS_NewCFunction(ctx, web_socket_peer_class_get_heartbeat_interval, "get_heartbeat_interval", 0),
        JS_NewCFunction(ctx, web_socket_peer_class_set_heartbeat_interval, "set_heartbeat_interval", 1),
        JS_PROP_GETSET
    );
}

static void define_web_socket_peer_enum(JSContext *ctx, JSValue proto) {
	JSValue WriteMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, WriteMode_obj, "WRITE_MODE_TEXT", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, WriteMode_obj, "WRITE_MODE_BINARY", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, proto, "WriteMode", WriteMode_obj);
	JSValue State_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, State_obj, "STATE_CONNECTING", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, State_obj, "STATE_OPEN", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, State_obj, "STATE_CLOSING", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, State_obj, "STATE_CLOSED", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, proto, "State", State_obj);
}

static int js_web_socket_peer_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["WebSocketPeer"] = class_id;
	classes_by_id[class_id] = "WebSocketPeer";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &web_socket_peer_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["PacketPeer"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_web_socket_peer_property(ctx, proto);
	define_web_socket_peer_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, web_socket_peer_class_proto_funcs, _countof(web_socket_peer_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, web_socket_peer_class_constructor, "WebSocketPeer", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "WebSocketPeer", ctor);

	return 0;
}

JSModuleDef *_js_init_web_socket_peer_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/packet_peer';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_web_socket_peer_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "WebSocketPeer");
	return m;
}

JSModuleDef *js_init_web_socket_peer_module(JSContext *ctx) {
	return _js_init_web_socket_peer_module(ctx, "@godot/classes/web_socket_peer");
}

void __register_web_socket_peer() {
	js_init_web_socket_peer_module(js_context());
}

void register_web_socket_peer() {
	__register_web_socket_peer();
}