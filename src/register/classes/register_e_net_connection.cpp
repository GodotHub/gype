#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/e_net_packet_peer.hpp>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/classes/tls_options.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/e_net_connection.hpp>
using namespace godot;

static void e_net_connection_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["ENetConnection"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef e_net_connection_class_def = {
    "ENetConnection",
    e_net_connection_class_finalizer
};

static JSValue e_net_connection_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["ENetConnection"];
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
        instance = memnew(ENetConnection);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue e_net_connection_class_create_host_bound(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&ENetConnection::create_host_bound, ctx, this_val, argc, argv);
};
static JSValue e_net_connection_class_create_host(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&ENetConnection::create_host, ctx, this_val, argc, argv);
};
static JSValue e_net_connection_class_destroy(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ENetConnection::destroy, ctx, this_val, argc, argv);
};
static JSValue e_net_connection_class_connect_to_host(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&ENetConnection::connect_to_host, ctx, this_val, argc, argv);
};
static JSValue e_net_connection_class_service(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&ENetConnection::service, ctx, this_val, argc, argv);
};
static JSValue e_net_connection_class_flush(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ENetConnection::flush, ctx, this_val, argc, argv);
};
static JSValue e_net_connection_class_bandwidth_limit(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ENetConnection::bandwidth_limit, ctx, this_val, argc, argv);
};
static JSValue e_net_connection_class_channel_limit(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ENetConnection::channel_limit, ctx, this_val, argc, argv);
};
static JSValue e_net_connection_class_broadcast(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ENetConnection::broadcast, ctx, this_val, argc, argv);
};
static JSValue e_net_connection_class_compress(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ENetConnection::compress, ctx, this_val, argc, argv);
};
static JSValue e_net_connection_class_dtls_server_setup(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&ENetConnection::dtls_server_setup, ctx, this_val, argc, argv);
};
static JSValue e_net_connection_class_dtls_client_setup(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&ENetConnection::dtls_client_setup, ctx, this_val, argc, argv);
};
static JSValue e_net_connection_class_refuse_new_connections(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ENetConnection::refuse_new_connections, ctx, this_val, argc, argv);
};
static JSValue e_net_connection_class_pop_statistic(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&ENetConnection::pop_statistic, ctx, this_val, argc, argv);
};
static JSValue e_net_connection_class_get_max_channels(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ENetConnection::get_max_channels, ctx, this_val, argc, argv);
};
static JSValue e_net_connection_class_get_local_port(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ENetConnection::get_local_port, ctx, this_val, argc, argv);
};
static JSValue e_net_connection_class_get_peers(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&ENetConnection::get_peers, ctx, this_val, argc, argv);
};
static JSValue e_net_connection_class_socket_send(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ENetConnection::socket_send, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry e_net_connection_class_proto_funcs[] = {
	JS_CFUNC_DEF("create_host_bound", 6, &e_net_connection_class_create_host_bound),
	JS_CFUNC_DEF("create_host", 4, &e_net_connection_class_create_host),
	JS_CFUNC_DEF("destroy", 0, &e_net_connection_class_destroy),
	JS_CFUNC_DEF("connect_to_host", 4, &e_net_connection_class_connect_to_host),
	JS_CFUNC_DEF("service", 1, &e_net_connection_class_service),
	JS_CFUNC_DEF("flush", 0, &e_net_connection_class_flush),
	JS_CFUNC_DEF("bandwidth_limit", 2, &e_net_connection_class_bandwidth_limit),
	JS_CFUNC_DEF("channel_limit", 1, &e_net_connection_class_channel_limit),
	JS_CFUNC_DEF("broadcast", 3, &e_net_connection_class_broadcast),
	JS_CFUNC_DEF("compress", 1, &e_net_connection_class_compress),
	JS_CFUNC_DEF("dtls_server_setup", 1, &e_net_connection_class_dtls_server_setup),
	JS_CFUNC_DEF("dtls_client_setup", 2, &e_net_connection_class_dtls_client_setup),
	JS_CFUNC_DEF("refuse_new_connections", 1, &e_net_connection_class_refuse_new_connections),
	JS_CFUNC_DEF("pop_statistic", 1, &e_net_connection_class_pop_statistic),
	JS_CFUNC_DEF("get_max_channels", 0, &e_net_connection_class_get_max_channels),
	JS_CFUNC_DEF("get_local_port", 0, &e_net_connection_class_get_local_port),
	JS_CFUNC_DEF("get_peers", 0, &e_net_connection_class_get_peers),
	JS_CFUNC_DEF("socket_send", 3, &e_net_connection_class_socket_send),
};




static void define_e_net_connection_property(JSContext *ctx, JSValue proto) {
}

static void define_e_net_connection_enum(JSContext *ctx, JSValue ctor) {
	JSValue CompressionMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, CompressionMode_obj, "COMPRESS_NONE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, CompressionMode_obj, "COMPRESS_RANGE_CODER", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, CompressionMode_obj, "COMPRESS_FASTLZ", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, CompressionMode_obj, "COMPRESS_ZLIB", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, CompressionMode_obj, "COMPRESS_ZSTD", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, ctor, "CompressionMode", CompressionMode_obj);
	JSValue EventType_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, EventType_obj, "EVENT_ERROR", JS_NewInt64(ctx, -1));
	JS_SetPropertyStr(ctx, EventType_obj, "EVENT_NONE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, EventType_obj, "EVENT_CONNECT", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, EventType_obj, "EVENT_DISCONNECT", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, EventType_obj, "EVENT_RECEIVE", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ctor, "EventType", EventType_obj);
	JSValue HostStatistic_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, HostStatistic_obj, "HOST_TOTAL_SENT_DATA", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, HostStatistic_obj, "HOST_TOTAL_SENT_PACKETS", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, HostStatistic_obj, "HOST_TOTAL_RECEIVED_DATA", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, HostStatistic_obj, "HOST_TOTAL_RECEIVED_PACKETS", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ctor, "HostStatistic", HostStatistic_obj);
}

static int js_e_net_connection_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["ENetConnection"] = class_id;
	classes_by_id[class_id] = "ENetConnection";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &e_net_connection_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_e_net_connection_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, e_net_connection_class_proto_funcs, _countof(e_net_connection_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, e_net_connection_class_constructor, "ENetConnection", 0, JS_CFUNC_constructor, 0);
	define_e_net_connection_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "ENetConnection", ctor);
	ctor_list["ENetConnection"] = ctor;

	return 0;
}

JSModuleDef *_js_init_e_net_connection_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_e_net_connection_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "ENetConnection");
	return m;
}

JSModuleDef *js_init_e_net_connection_module(JSContext *ctx) {
	return _js_init_e_net_connection_module(ctx, "@godot/classes/e_net_connection");
}

void __register_e_net_connection() {
	js_init_e_net_connection_module(js_context());
}

void register_e_net_connection() {
	__register_e_net_connection();
}