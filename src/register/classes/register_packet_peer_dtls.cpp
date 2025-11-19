#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/packet_peer.hpp>
#include <godot_cpp/classes/packet_peer_udp.hpp>
#include <godot_cpp/classes/tls_options.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/packet_peer_dtls.hpp>
using namespace godot;

static void packet_peer_dtls_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["PacketPeerDTLS"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
	}
}

static JSClassDef packet_peer_dtls_class_def = {
    "PacketPeerDTLS",
    packet_peer_dtls_class_finalizer
};

static JSValue packet_peer_dtls_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["PacketPeerDTLS"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    PacketPeerDTLS *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<PacketPeerDTLS *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(PacketPeerDTLS);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue packet_peer_dtls_class_poll(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PacketPeerDTLS::poll, ctx, this_val, argc, argv);
};
static JSValue packet_peer_dtls_class_connect_to_peer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&PacketPeerDTLS::connect_to_peer, ctx, this_val, argc, argv);
};
static JSValue packet_peer_dtls_class_get_status(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PacketPeerDTLS::get_status, ctx, this_val, argc, argv);
};
static JSValue packet_peer_dtls_class_disconnect_from_peer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PacketPeerDTLS::disconnect_from_peer, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry packet_peer_dtls_class_proto_funcs[] = {
	JS_CFUNC_DEF("poll", 0, &packet_peer_dtls_class_poll),
	JS_CFUNC_DEF("connect_to_peer", 3, &packet_peer_dtls_class_connect_to_peer),
	JS_CFUNC_DEF("get_status", 0, &packet_peer_dtls_class_get_status),
	JS_CFUNC_DEF("disconnect_from_peer", 0, &packet_peer_dtls_class_disconnect_from_peer),
};




static void define_packet_peer_dtls_property(JSContext *ctx, JSValue proto) {
}

static void define_packet_peer_dtls_enum(JSContext *ctx, JSValue ctor) {
	JSValue Status_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, Status_obj, "STATUS_DISCONNECTED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, Status_obj, "STATUS_HANDSHAKING", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, Status_obj, "STATUS_CONNECTED", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, Status_obj, "STATUS_ERROR", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, Status_obj, "STATUS_ERROR_HOSTNAME_MISMATCH", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, ctor, "Status", Status_obj);
}

static int js_packet_peer_dtls_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["PacketPeerDTLS"] = class_id;
	classes_by_id[class_id] = "PacketPeerDTLS";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &packet_peer_dtls_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["PacketPeer"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_packet_peer_dtls_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, packet_peer_dtls_class_proto_funcs, _countof(packet_peer_dtls_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, packet_peer_dtls_class_constructor, "PacketPeerDTLS", 0, JS_CFUNC_constructor, 0);
	define_packet_peer_dtls_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "PacketPeerDTLS", ctor);

	return 0;
}

JSModuleDef *_js_init_packet_peer_dtls_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/packet_peer';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_packet_peer_dtls_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "PacketPeerDTLS");
	return m;
}

JSModuleDef *js_init_packet_peer_dtls_module(JSContext *ctx) {
	return _js_init_packet_peer_dtls_module(ctx, "@godot/classes/packet_peer_dtls");
}

void __register_packet_peer_dtls() {
	js_init_packet_peer_dtls_module(js_context());
}

void register_packet_peer_dtls() {
	__register_packet_peer_dtls();
}