#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/stream_peer.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/stream_peer_tcp.hpp>
using namespace godot;

static void stream_peer_tcp_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["StreamPeerTCP"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef stream_peer_tcp_class_def = {
    "StreamPeerTCP",
    stream_peer_tcp_class_finalizer
};

static JSValue stream_peer_tcp_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["StreamPeerTCP"];
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
        instance = memnew(StreamPeerTCP);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue stream_peer_tcp_class_bind(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&StreamPeerTCP::bind, ctx, this_val, argc, argv);
};
static JSValue stream_peer_tcp_class_connect_to_host(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&StreamPeerTCP::connect_to_host, ctx, this_val, argc, argv);
};
static JSValue stream_peer_tcp_class_poll(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&StreamPeerTCP::poll, ctx, this_val, argc, argv);
};
static JSValue stream_peer_tcp_class_get_status(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&StreamPeerTCP::get_status, ctx, this_val, argc, argv);
};
static JSValue stream_peer_tcp_class_get_connected_host(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&StreamPeerTCP::get_connected_host, ctx, this_val, argc, argv);
};
static JSValue stream_peer_tcp_class_get_connected_port(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&StreamPeerTCP::get_connected_port, ctx, this_val, argc, argv);
};
static JSValue stream_peer_tcp_class_get_local_port(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&StreamPeerTCP::get_local_port, ctx, this_val, argc, argv);
};
static JSValue stream_peer_tcp_class_disconnect_from_host(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&StreamPeerTCP::disconnect_from_host, ctx, this_val, argc, argv);
};
static JSValue stream_peer_tcp_class_set_no_delay(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&StreamPeerTCP::set_no_delay, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry stream_peer_tcp_class_proto_funcs[] = {
	JS_CFUNC_DEF("bind", 2, &stream_peer_tcp_class_bind),
	JS_CFUNC_DEF("connect_to_host", 2, &stream_peer_tcp_class_connect_to_host),
	JS_CFUNC_DEF("poll", 0, &stream_peer_tcp_class_poll),
	JS_CFUNC_DEF("get_status", 0, &stream_peer_tcp_class_get_status),
	JS_CFUNC_DEF("get_connected_host", 0, &stream_peer_tcp_class_get_connected_host),
	JS_CFUNC_DEF("get_connected_port", 0, &stream_peer_tcp_class_get_connected_port),
	JS_CFUNC_DEF("get_local_port", 0, &stream_peer_tcp_class_get_local_port),
	JS_CFUNC_DEF("disconnect_from_host", 0, &stream_peer_tcp_class_disconnect_from_host),
	JS_CFUNC_DEF("set_no_delay", 1, &stream_peer_tcp_class_set_no_delay),
};




static void define_stream_peer_tcp_property(JSContext *ctx, JSValue proto) {
}

static void define_stream_peer_tcp_enum(JSContext *ctx, JSValue ctor) {
	JSValue Status_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, Status_obj, "STATUS_NONE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, Status_obj, "STATUS_CONNECTING", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, Status_obj, "STATUS_CONNECTED", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, Status_obj, "STATUS_ERROR", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ctor, "Status", Status_obj);
}

static int js_stream_peer_tcp_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["StreamPeerTCP"] = class_id;
	classes_by_id[class_id] = "StreamPeerTCP";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &stream_peer_tcp_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["StreamPeer"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_stream_peer_tcp_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, stream_peer_tcp_class_proto_funcs, _countof(stream_peer_tcp_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, stream_peer_tcp_class_constructor, "StreamPeerTCP", 0, JS_CFUNC_constructor, 0);
	define_stream_peer_tcp_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "StreamPeerTCP", ctor);
	ctor_list["StreamPeerTCP"] = ctor;

	return 0;
}

JSModuleDef *_js_init_stream_peer_tcp_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/stream_peer';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_stream_peer_tcp_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "StreamPeerTCP");
	return m;
}

JSModuleDef *js_init_stream_peer_tcp_module(JSContext *ctx) {
	return _js_init_stream_peer_tcp_module(ctx, "@godot/classes/stream_peer_tcp");
}

void __register_stream_peer_tcp() {
	js_init_stream_peer_tcp_module(js_context());
}

void register_stream_peer_tcp() {
	__register_stream_peer_tcp();
}