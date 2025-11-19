#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/multiplayer_peer.hpp>
#include <godot_cpp/classes/web_rtc_peer_connection.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/web_rtc_multiplayer_peer.hpp>
using namespace godot;

static void web_rtc_multiplayer_peer_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["WebRTCMultiplayerPeer"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef web_rtc_multiplayer_peer_class_def = {
    "WebRTCMultiplayerPeer",
    web_rtc_multiplayer_peer_class_finalizer
};

static JSValue web_rtc_multiplayer_peer_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["WebRTCMultiplayerPeer"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    WebRTCMultiplayerPeer *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<WebRTCMultiplayerPeer *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(WebRTCMultiplayerPeer);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue web_rtc_multiplayer_peer_class_create_server(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&WebRTCMultiplayerPeer::create_server, ctx, this_val, argc, argv);
};
static JSValue web_rtc_multiplayer_peer_class_create_client(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&WebRTCMultiplayerPeer::create_client, ctx, this_val, argc, argv);
};
static JSValue web_rtc_multiplayer_peer_class_create_mesh(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&WebRTCMultiplayerPeer::create_mesh, ctx, this_val, argc, argv);
};
static JSValue web_rtc_multiplayer_peer_class_add_peer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&WebRTCMultiplayerPeer::add_peer, ctx, this_val, argc, argv);
};
static JSValue web_rtc_multiplayer_peer_class_remove_peer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&WebRTCMultiplayerPeer::remove_peer, ctx, this_val, argc, argv);
};
static JSValue web_rtc_multiplayer_peer_class_has_peer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&WebRTCMultiplayerPeer::has_peer, ctx, this_val, argc, argv);
};
static JSValue web_rtc_multiplayer_peer_class_get_peer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&WebRTCMultiplayerPeer::get_peer, ctx, this_val, argc, argv);
};
static JSValue web_rtc_multiplayer_peer_class_get_peers(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&WebRTCMultiplayerPeer::get_peers, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry web_rtc_multiplayer_peer_class_proto_funcs[] = {
	JS_CFUNC_DEF("create_server", 1, &web_rtc_multiplayer_peer_class_create_server),
	JS_CFUNC_DEF("create_client", 2, &web_rtc_multiplayer_peer_class_create_client),
	JS_CFUNC_DEF("create_mesh", 2, &web_rtc_multiplayer_peer_class_create_mesh),
	JS_CFUNC_DEF("add_peer", 3, &web_rtc_multiplayer_peer_class_add_peer),
	JS_CFUNC_DEF("remove_peer", 1, &web_rtc_multiplayer_peer_class_remove_peer),
	JS_CFUNC_DEF("has_peer", 1, &web_rtc_multiplayer_peer_class_has_peer),
	JS_CFUNC_DEF("get_peer", 1, &web_rtc_multiplayer_peer_class_get_peer),
	JS_CFUNC_DEF("get_peers", 0, &web_rtc_multiplayer_peer_class_get_peers),
};




static void define_web_rtc_multiplayer_peer_property(JSContext *ctx, JSValue proto) {
}

static void define_web_rtc_multiplayer_peer_enum(JSContext *ctx, JSValue ctor) {
}

static int js_web_rtc_multiplayer_peer_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["WebRTCMultiplayerPeer"] = class_id;
	classes_by_id[class_id] = "WebRTCMultiplayerPeer";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &web_rtc_multiplayer_peer_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["MultiplayerPeer"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_web_rtc_multiplayer_peer_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, web_rtc_multiplayer_peer_class_proto_funcs, _countof(web_rtc_multiplayer_peer_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, web_rtc_multiplayer_peer_class_constructor, "WebRTCMultiplayerPeer", 0, JS_CFUNC_constructor, 0);
	define_web_rtc_multiplayer_peer_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "WebRTCMultiplayerPeer", ctor);

	return 0;
}

JSModuleDef *_js_init_web_rtc_multiplayer_peer_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/multiplayer_peer';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_web_rtc_multiplayer_peer_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "WebRTCMultiplayerPeer");
	return m;
}

JSModuleDef *js_init_web_rtc_multiplayer_peer_module(JSContext *ctx) {
	return _js_init_web_rtc_multiplayer_peer_module(ctx, "@godot/classes/web_rtc_multiplayer_peer");
}

void __register_web_rtc_multiplayer_peer() {
	js_init_web_rtc_multiplayer_peer_module(js_context());
}

void register_web_rtc_multiplayer_peer() {
	__register_web_rtc_multiplayer_peer();
}