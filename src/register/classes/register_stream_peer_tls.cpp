#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/stream_peer.hpp>
#include <godot_cpp/classes/tls_options.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/stream_peer_tls.hpp>
using namespace godot;

static void stream_peer_tls_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["StreamPeerTLS"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef stream_peer_tls_class_def = {
    "StreamPeerTLS",
    stream_peer_tls_class_finalizer
};

static JSValue stream_peer_tls_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["StreamPeerTLS"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    StreamPeerTLS *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<StreamPeerTLS *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(StreamPeerTLS);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue stream_peer_tls_class_poll(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&StreamPeerTLS::poll, ctx, this_val, argc, argv);
};
static JSValue stream_peer_tls_class_accept_stream(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&StreamPeerTLS::accept_stream, ctx, this_val, argc, argv);
};
static JSValue stream_peer_tls_class_connect_to_stream(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&StreamPeerTLS::connect_to_stream, ctx, this_val, argc, argv);
};
static JSValue stream_peer_tls_class_get_status(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&StreamPeerTLS::get_status, ctx, this_val, argc, argv);
};
static JSValue stream_peer_tls_class_get_stream(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&StreamPeerTLS::get_stream, ctx, this_val, argc, argv);
};
static JSValue stream_peer_tls_class_disconnect_from_stream(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&StreamPeerTLS::disconnect_from_stream, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry stream_peer_tls_class_proto_funcs[] = {
	JS_CFUNC_DEF("poll", 0, &stream_peer_tls_class_poll),
	JS_CFUNC_DEF("accept_stream", 2, &stream_peer_tls_class_accept_stream),
	JS_CFUNC_DEF("connect_to_stream", 3, &stream_peer_tls_class_connect_to_stream),
	JS_CFUNC_DEF("get_status", 0, &stream_peer_tls_class_get_status),
	JS_CFUNC_DEF("get_stream", 0, &stream_peer_tls_class_get_stream),
	JS_CFUNC_DEF("disconnect_from_stream", 0, &stream_peer_tls_class_disconnect_from_stream),
};




static void define_stream_peer_tls_property(JSContext *ctx, JSValue proto) {
}

static void define_stream_peer_tls_enum(JSContext *ctx, JSValue proto) {
	JSValue Status_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, Status_obj, "STATUS_DISCONNECTED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, Status_obj, "STATUS_HANDSHAKING", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, Status_obj, "STATUS_CONNECTED", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, Status_obj, "STATUS_ERROR", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, Status_obj, "STATUS_ERROR_HOSTNAME_MISMATCH", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, proto, "Status", Status_obj);
}

static int js_stream_peer_tls_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["StreamPeerTLS"] = class_id;
	classes_by_id[class_id] = "StreamPeerTLS";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &stream_peer_tls_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["StreamPeer"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_stream_peer_tls_property(ctx, proto);
	define_stream_peer_tls_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, stream_peer_tls_class_proto_funcs, _countof(stream_peer_tls_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, stream_peer_tls_class_constructor, "StreamPeerTLS", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "StreamPeerTLS", ctor);

	return 0;
}

JSModuleDef *_js_init_stream_peer_tls_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/stream_peer';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_stream_peer_tls_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "StreamPeerTLS");
	return m;
}

JSModuleDef *js_init_stream_peer_tls_module(JSContext *ctx) {
	return _js_init_stream_peer_tls_module(ctx, "@godot/classes/stream_peer_tls");
}

void __register_stream_peer_tls() {
	js_init_stream_peer_tls_module(js_context());
}

void register_stream_peer_tls() {
	__register_stream_peer_tls();
}