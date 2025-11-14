#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/classes/web_rtc_data_channel.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/web_rtc_peer_connection.hpp>
using namespace godot;

static void web_rtc_peer_connection_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["WebRTCPeerConnection"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef web_rtc_peer_connection_class_def = {
    "WebRTCPeerConnection",
    web_rtc_peer_connection_class_finalizer
};

static JSValue web_rtc_peer_connection_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["WebRTCPeerConnection"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    WebRTCPeerConnection *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<WebRTCPeerConnection *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(WebRTCPeerConnection);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue web_rtc_peer_connection_class_initialize(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&WebRTCPeerConnection::initialize, ctx, this_val, argc, argv);
};
static JSValue web_rtc_peer_connection_class_create_data_channel(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&WebRTCPeerConnection::create_data_channel, ctx, this_val, argc, argv);
};
static JSValue web_rtc_peer_connection_class_create_offer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&WebRTCPeerConnection::create_offer, ctx, this_val, argc, argv);
};
static JSValue web_rtc_peer_connection_class_set_local_description(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&WebRTCPeerConnection::set_local_description, ctx, this_val, argc, argv);
};
static JSValue web_rtc_peer_connection_class_set_remote_description(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&WebRTCPeerConnection::set_remote_description, ctx, this_val, argc, argv);
};
static JSValue web_rtc_peer_connection_class_add_ice_candidate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&WebRTCPeerConnection::add_ice_candidate, ctx, this_val, argc, argv);
};
static JSValue web_rtc_peer_connection_class_poll(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&WebRTCPeerConnection::poll, ctx, this_val, argc, argv);
};
static JSValue web_rtc_peer_connection_class_close(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&WebRTCPeerConnection::close, ctx, this_val, argc, argv);
};
static JSValue web_rtc_peer_connection_class_get_connection_state(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&WebRTCPeerConnection::get_connection_state, ctx, this_val, argc, argv);
};
static JSValue web_rtc_peer_connection_class_get_gathering_state(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&WebRTCPeerConnection::get_gathering_state, ctx, this_val, argc, argv);
};
static JSValue web_rtc_peer_connection_class_get_signaling_state(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&WebRTCPeerConnection::get_signaling_state, ctx, this_val, argc, argv);
};
static JSValue web_rtc_peer_connection_class_set_default_extension(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    return call_builtin_static_method_no_ret(&WebRTCPeerConnection::set_default_extension, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry web_rtc_peer_connection_class_proto_funcs[] = {
	JS_CFUNC_DEF("initialize", 1, &web_rtc_peer_connection_class_initialize),
	JS_CFUNC_DEF("create_data_channel", 2, &web_rtc_peer_connection_class_create_data_channel),
	JS_CFUNC_DEF("create_offer", 0, &web_rtc_peer_connection_class_create_offer),
	JS_CFUNC_DEF("set_local_description", 2, &web_rtc_peer_connection_class_set_local_description),
	JS_CFUNC_DEF("set_remote_description", 2, &web_rtc_peer_connection_class_set_remote_description),
	JS_CFUNC_DEF("add_ice_candidate", 3, &web_rtc_peer_connection_class_add_ice_candidate),
	JS_CFUNC_DEF("poll", 0, &web_rtc_peer_connection_class_poll),
	JS_CFUNC_DEF("close", 0, &web_rtc_peer_connection_class_close),
	JS_CFUNC_DEF("get_connection_state", 0, &web_rtc_peer_connection_class_get_connection_state),
	JS_CFUNC_DEF("get_gathering_state", 0, &web_rtc_peer_connection_class_get_gathering_state),
	JS_CFUNC_DEF("get_signaling_state", 0, &web_rtc_peer_connection_class_get_signaling_state),
};

static const JSCFunctionListEntry web_rtc_peer_connection_class_static_funcs[] = {
	JS_CFUNC_DEF("set_default_extension", 1, &web_rtc_peer_connection_class_set_default_extension),
};

static JSValue web_rtc_peer_connection_class_get_session_description_created_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	WebRTCPeerConnection *opaque = static_cast<WebRTCPeerConnection *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "session_description_created_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "session_description_created"));
		JS_DefinePropertyValueStr(ctx, this_val, "session_description_created_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue web_rtc_peer_connection_class_get_ice_candidate_created_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	WebRTCPeerConnection *opaque = static_cast<WebRTCPeerConnection *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "ice_candidate_created_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "ice_candidate_created"));
		JS_DefinePropertyValueStr(ctx, this_val, "ice_candidate_created_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue web_rtc_peer_connection_class_get_data_channel_received_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	WebRTCPeerConnection *opaque = static_cast<WebRTCPeerConnection *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "data_channel_received_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "data_channel_received"));
		JS_DefinePropertyValueStr(ctx, this_val, "data_channel_received_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_web_rtc_peer_connection_property(JSContext *ctx, JSValue proto) {
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "session_description_created"),
		JS_NewCFunction(ctx, web_rtc_peer_connection_class_get_session_description_created_signal, "get_session_description_created_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "ice_candidate_created"),
		JS_NewCFunction(ctx, web_rtc_peer_connection_class_get_ice_candidate_created_signal, "get_ice_candidate_created_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "data_channel_received"),
		JS_NewCFunction(ctx, web_rtc_peer_connection_class_get_data_channel_received_signal, "get_data_channel_received_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_web_rtc_peer_connection_enum(JSContext *ctx, JSValue proto) {
	JSValue ConnectionState_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, ConnectionState_obj, "STATE_NEW", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, ConnectionState_obj, "STATE_CONNECTING", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ConnectionState_obj, "STATE_CONNECTED", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ConnectionState_obj, "STATE_DISCONNECTED", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ConnectionState_obj, "STATE_FAILED", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, ConnectionState_obj, "STATE_CLOSED", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, proto, "ConnectionState", ConnectionState_obj);
	JSValue GatheringState_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, GatheringState_obj, "GATHERING_STATE_NEW", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, GatheringState_obj, "GATHERING_STATE_GATHERING", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, GatheringState_obj, "GATHERING_STATE_COMPLETE", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, proto, "GatheringState", GatheringState_obj);
	JSValue SignalingState_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, SignalingState_obj, "SIGNALING_STATE_STABLE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, SignalingState_obj, "SIGNALING_STATE_HAVE_LOCAL_OFFER", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, SignalingState_obj, "SIGNALING_STATE_HAVE_REMOTE_OFFER", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, SignalingState_obj, "SIGNALING_STATE_HAVE_LOCAL_PRANSWER", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, SignalingState_obj, "SIGNALING_STATE_HAVE_REMOTE_PRANSWER", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, SignalingState_obj, "SIGNALING_STATE_CLOSED", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, proto, "SignalingState", SignalingState_obj);
}

static int js_web_rtc_peer_connection_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["WebRTCPeerConnection"] = class_id;
	classes_by_id[class_id] = "WebRTCPeerConnection";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &web_rtc_peer_connection_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_web_rtc_peer_connection_property(ctx, proto);
	define_web_rtc_peer_connection_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, web_rtc_peer_connection_class_proto_funcs, _countof(web_rtc_peer_connection_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, web_rtc_peer_connection_class_constructor, "WebRTCPeerConnection", 0, JS_CFUNC_constructor, 0);
	JS_SetPropertyFunctionList(ctx, ctor, web_rtc_peer_connection_class_static_funcs, _countof(web_rtc_peer_connection_class_static_funcs));
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "WebRTCPeerConnection", ctor);

	return 0;
}

JSModuleDef *_js_init_web_rtc_peer_connection_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_web_rtc_peer_connection_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "WebRTCPeerConnection");
	return m;
}

JSModuleDef *js_init_web_rtc_peer_connection_module(JSContext *ctx) {
	return _js_init_web_rtc_peer_connection_module(ctx, "@godot/classes/web_rtc_peer_connection");
}

void __register_web_rtc_peer_connection() {
	js_init_web_rtc_peer_connection_module(js_context());
}

void register_web_rtc_peer_connection() {
	__register_web_rtc_peer_connection();
}