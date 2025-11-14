#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/packet_peer.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/packet_peer_udp.hpp>
using namespace godot;

static void packet_peer_udp_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["PacketPeerUDP"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef packet_peer_udp_class_def = {
    "PacketPeerUDP",
    packet_peer_udp_class_finalizer
};

static JSValue packet_peer_udp_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["PacketPeerUDP"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    PacketPeerUDP *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<PacketPeerUDP *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(PacketPeerUDP);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue packet_peer_udp_class_bind(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&PacketPeerUDP::bind, ctx, this_val, argc, argv);
};
static JSValue packet_peer_udp_class_close(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PacketPeerUDP::close, ctx, this_val, argc, argv);
};
static JSValue packet_peer_udp_class_wait(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&PacketPeerUDP::wait, ctx, this_val, argc, argv);
};
static JSValue packet_peer_udp_class_is_bound(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PacketPeerUDP::is_bound, ctx, this_val, argc, argv);
};
static JSValue packet_peer_udp_class_connect_to_host(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&PacketPeerUDP::connect_to_host, ctx, this_val, argc, argv);
};
static JSValue packet_peer_udp_class_is_socket_connected(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PacketPeerUDP::is_socket_connected, ctx, this_val, argc, argv);
};
static JSValue packet_peer_udp_class_get_packet_ip(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PacketPeerUDP::get_packet_ip, ctx, this_val, argc, argv);
};
static JSValue packet_peer_udp_class_get_packet_port(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PacketPeerUDP::get_packet_port, ctx, this_val, argc, argv);
};
static JSValue packet_peer_udp_class_get_local_port(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PacketPeerUDP::get_local_port, ctx, this_val, argc, argv);
};
static JSValue packet_peer_udp_class_set_dest_address(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&PacketPeerUDP::set_dest_address, ctx, this_val, argc, argv);
};
static JSValue packet_peer_udp_class_set_broadcast_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PacketPeerUDP::set_broadcast_enabled, ctx, this_val, argc, argv);
};
static JSValue packet_peer_udp_class_join_multicast_group(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&PacketPeerUDP::join_multicast_group, ctx, this_val, argc, argv);
};
static JSValue packet_peer_udp_class_leave_multicast_group(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&PacketPeerUDP::leave_multicast_group, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry packet_peer_udp_class_proto_funcs[] = {
	JS_CFUNC_DEF("bind", 3, &packet_peer_udp_class_bind),
	JS_CFUNC_DEF("close", 0, &packet_peer_udp_class_close),
	JS_CFUNC_DEF("wait", 0, &packet_peer_udp_class_wait),
	JS_CFUNC_DEF("is_bound", 0, &packet_peer_udp_class_is_bound),
	JS_CFUNC_DEF("connect_to_host", 2, &packet_peer_udp_class_connect_to_host),
	JS_CFUNC_DEF("is_socket_connected", 0, &packet_peer_udp_class_is_socket_connected),
	JS_CFUNC_DEF("get_packet_ip", 0, &packet_peer_udp_class_get_packet_ip),
	JS_CFUNC_DEF("get_packet_port", 0, &packet_peer_udp_class_get_packet_port),
	JS_CFUNC_DEF("get_local_port", 0, &packet_peer_udp_class_get_local_port),
	JS_CFUNC_DEF("set_dest_address", 2, &packet_peer_udp_class_set_dest_address),
	JS_CFUNC_DEF("set_broadcast_enabled", 1, &packet_peer_udp_class_set_broadcast_enabled),
	JS_CFUNC_DEF("join_multicast_group", 2, &packet_peer_udp_class_join_multicast_group),
	JS_CFUNC_DEF("leave_multicast_group", 2, &packet_peer_udp_class_leave_multicast_group),
};




static void define_packet_peer_udp_property(JSContext *ctx, JSValue proto) {
}

static void define_packet_peer_udp_enum(JSContext *ctx, JSValue proto) {
}

static int js_packet_peer_udp_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["PacketPeerUDP"] = class_id;
	classes_by_id[class_id] = "PacketPeerUDP";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &packet_peer_udp_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["PacketPeer"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_packet_peer_udp_property(ctx, proto);
	define_packet_peer_udp_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, packet_peer_udp_class_proto_funcs, _countof(packet_peer_udp_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, packet_peer_udp_class_constructor, "PacketPeerUDP", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "PacketPeerUDP", ctor);

	return 0;
}

JSModuleDef *_js_init_packet_peer_udp_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/packet_peer';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_packet_peer_udp_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "PacketPeerUDP");
	return m;
}

JSModuleDef *js_init_packet_peer_udp_module(JSContext *ctx) {
	return _js_init_packet_peer_udp_module(ctx, "@godot/classes/packet_peer_udp");
}

void __register_packet_peer_udp() {
	js_init_packet_peer_udp_module(js_context());
}

void register_packet_peer_udp() {
	__register_packet_peer_udp();
}