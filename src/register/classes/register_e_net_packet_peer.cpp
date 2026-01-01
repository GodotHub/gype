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
#include <godot_cpp/classes/e_net_packet_peer.hpp>
using namespace godot;

static void e_net_packet_peer_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["ENetPacketPeer"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef e_net_packet_peer_class_def = {
    "ENetPacketPeer",
    e_net_packet_peer_class_finalizer
};

static JSValue e_net_packet_peer_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["ENetPacketPeer"];
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
        instance = memnew(ENetPacketPeer);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue e_net_packet_peer_class_peer_disconnect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ENetPacketPeer::peer_disconnect, ctx, this_val, argc, argv);
};
static JSValue e_net_packet_peer_class_peer_disconnect_later(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ENetPacketPeer::peer_disconnect_later, ctx, this_val, argc, argv);
};
static JSValue e_net_packet_peer_class_peer_disconnect_now(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ENetPacketPeer::peer_disconnect_now, ctx, this_val, argc, argv);
};
static JSValue e_net_packet_peer_class_ping(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ENetPacketPeer::ping, ctx, this_val, argc, argv);
};
static JSValue e_net_packet_peer_class_ping_interval(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ENetPacketPeer::ping_interval, ctx, this_val, argc, argv);
};
static JSValue e_net_packet_peer_class_reset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ENetPacketPeer::reset, ctx, this_val, argc, argv);
};
static JSValue e_net_packet_peer_class_send(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&ENetPacketPeer::send, ctx, this_val, argc, argv);
};
static JSValue e_net_packet_peer_class_throttle_configure(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ENetPacketPeer::throttle_configure, ctx, this_val, argc, argv);
};
static JSValue e_net_packet_peer_class_set_timeout(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ENetPacketPeer::set_timeout, ctx, this_val, argc, argv);
};
static JSValue e_net_packet_peer_class_get_packet_flags(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ENetPacketPeer::get_packet_flags, ctx, this_val, argc, argv);
};
static JSValue e_net_packet_peer_class_get_remote_address(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ENetPacketPeer::get_remote_address, ctx, this_val, argc, argv);
};
static JSValue e_net_packet_peer_class_get_remote_port(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ENetPacketPeer::get_remote_port, ctx, this_val, argc, argv);
};
static JSValue e_net_packet_peer_class_get_statistic(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&ENetPacketPeer::get_statistic, ctx, this_val, argc, argv);
};
static JSValue e_net_packet_peer_class_get_state(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ENetPacketPeer::get_state, ctx, this_val, argc, argv);
};
static JSValue e_net_packet_peer_class_get_channels(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ENetPacketPeer::get_channels, ctx, this_val, argc, argv);
};
static JSValue e_net_packet_peer_class_is_active(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ENetPacketPeer::is_active, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry e_net_packet_peer_class_proto_funcs[] = {
	JS_CFUNC_DEF("peer_disconnect", 1, &e_net_packet_peer_class_peer_disconnect),
	JS_CFUNC_DEF("peer_disconnect_later", 1, &e_net_packet_peer_class_peer_disconnect_later),
	JS_CFUNC_DEF("peer_disconnect_now", 1, &e_net_packet_peer_class_peer_disconnect_now),
	JS_CFUNC_DEF("ping", 0, &e_net_packet_peer_class_ping),
	JS_CFUNC_DEF("ping_interval", 1, &e_net_packet_peer_class_ping_interval),
	JS_CFUNC_DEF("reset", 0, &e_net_packet_peer_class_reset),
	JS_CFUNC_DEF("send", 3, &e_net_packet_peer_class_send),
	JS_CFUNC_DEF("throttle_configure", 3, &e_net_packet_peer_class_throttle_configure),
	JS_CFUNC_DEF("set_timeout", 3, &e_net_packet_peer_class_set_timeout),
	JS_CFUNC_DEF("get_packet_flags", 0, &e_net_packet_peer_class_get_packet_flags),
	JS_CFUNC_DEF("get_remote_address", 0, &e_net_packet_peer_class_get_remote_address),
	JS_CFUNC_DEF("get_remote_port", 0, &e_net_packet_peer_class_get_remote_port),
	JS_CFUNC_DEF("get_statistic", 1, &e_net_packet_peer_class_get_statistic),
	JS_CFUNC_DEF("get_state", 0, &e_net_packet_peer_class_get_state),
	JS_CFUNC_DEF("get_channels", 0, &e_net_packet_peer_class_get_channels),
	JS_CFUNC_DEF("is_active", 0, &e_net_packet_peer_class_is_active),
};




static void define_e_net_packet_peer_property(JSContext *ctx, JSValue proto) {
}

static void define_e_net_packet_peer_enum(JSContext *ctx, JSValue ctor) {
	JSValue PeerState_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, PeerState_obj, "STATE_DISCONNECTED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, PeerState_obj, "STATE_CONNECTING", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, PeerState_obj, "STATE_ACKNOWLEDGING_CONNECT", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, PeerState_obj, "STATE_CONNECTION_PENDING", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, PeerState_obj, "STATE_CONNECTION_SUCCEEDED", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, PeerState_obj, "STATE_CONNECTED", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, PeerState_obj, "STATE_DISCONNECT_LATER", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, PeerState_obj, "STATE_DISCONNECTING", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, PeerState_obj, "STATE_ACKNOWLEDGING_DISCONNECT", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, PeerState_obj, "STATE_ZOMBIE", JS_NewInt64(ctx, 9));
	JS_SetPropertyStr(ctx, ctor, "PeerState", PeerState_obj);
	JSValue PeerStatistic_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, PeerStatistic_obj, "PEER_PACKET_LOSS", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, PeerStatistic_obj, "PEER_PACKET_LOSS_VARIANCE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, PeerStatistic_obj, "PEER_PACKET_LOSS_EPOCH", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, PeerStatistic_obj, "PEER_ROUND_TRIP_TIME", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, PeerStatistic_obj, "PEER_ROUND_TRIP_TIME_VARIANCE", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, PeerStatistic_obj, "PEER_LAST_ROUND_TRIP_TIME", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, PeerStatistic_obj, "PEER_LAST_ROUND_TRIP_TIME_VARIANCE", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, PeerStatistic_obj, "PEER_PACKET_THROTTLE", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, PeerStatistic_obj, "PEER_PACKET_THROTTLE_LIMIT", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, PeerStatistic_obj, "PEER_PACKET_THROTTLE_COUNTER", JS_NewInt64(ctx, 9));
	JS_SetPropertyStr(ctx, PeerStatistic_obj, "PEER_PACKET_THROTTLE_EPOCH", JS_NewInt64(ctx, 10));
	JS_SetPropertyStr(ctx, PeerStatistic_obj, "PEER_PACKET_THROTTLE_ACCELERATION", JS_NewInt64(ctx, 11));
	JS_SetPropertyStr(ctx, PeerStatistic_obj, "PEER_PACKET_THROTTLE_DECELERATION", JS_NewInt64(ctx, 12));
	JS_SetPropertyStr(ctx, PeerStatistic_obj, "PEER_PACKET_THROTTLE_INTERVAL", JS_NewInt64(ctx, 13));
	JS_SetPropertyStr(ctx, ctor, "PeerStatistic", PeerStatistic_obj);
}

static int js_e_net_packet_peer_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["ENetPacketPeer"] = class_id;
	classes_by_id[class_id] = "ENetPacketPeer";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &e_net_packet_peer_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["PacketPeer"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_e_net_packet_peer_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, e_net_packet_peer_class_proto_funcs, _countof(e_net_packet_peer_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, e_net_packet_peer_class_constructor, "ENetPacketPeer", 0, JS_CFUNC_constructor, 0);
	define_e_net_packet_peer_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "ENetPacketPeer", ctor);
	ctor_list["ENetPacketPeer"] = ctor;

	return 0;
}

JSModuleDef *_js_init_e_net_packet_peer_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/packet_peer';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_e_net_packet_peer_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "ENetPacketPeer");
	return m;
}

JSModuleDef *js_init_e_net_packet_peer_module(JSContext *ctx) {
	return _js_init_e_net_packet_peer_module(ctx, "@godot/classes/e_net_packet_peer");
}

void __register_e_net_packet_peer() {
	js_init_e_net_packet_peer_module(js_context());
}

void register_e_net_packet_peer() {
	__register_e_net_packet_peer();
}