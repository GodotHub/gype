#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/e_net_connection.hpp>
#include <godot_cpp/classes/e_net_packet_peer.hpp>
#include <godot_cpp/classes/multiplayer_peer.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/e_net_multiplayer_peer.hpp>
using namespace godot;

static void e_net_multiplayer_peer_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["ENetMultiplayerPeer"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef e_net_multiplayer_peer_class_def = {
    "ENetMultiplayerPeer",
    e_net_multiplayer_peer_class_finalizer
};

static JSValue e_net_multiplayer_peer_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["ENetMultiplayerPeer"];
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
        instance = memnew(ENetMultiplayerPeer);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue e_net_multiplayer_peer_class_create_server(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&ENetMultiplayerPeer::create_server, ctx, this_val, argc, argv);
};
static JSValue e_net_multiplayer_peer_class_create_client(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&ENetMultiplayerPeer::create_client, ctx, this_val, argc, argv);
};
static JSValue e_net_multiplayer_peer_class_create_mesh(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&ENetMultiplayerPeer::create_mesh, ctx, this_val, argc, argv);
};
static JSValue e_net_multiplayer_peer_class_add_mesh_peer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&ENetMultiplayerPeer::add_mesh_peer, ctx, this_val, argc, argv);
};
static JSValue e_net_multiplayer_peer_class_set_bind_ip(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ENetMultiplayerPeer::set_bind_ip, ctx, this_val, argc, argv);
};
static JSValue e_net_multiplayer_peer_class_get_host(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ENetMultiplayerPeer::get_host, ctx, this_val, argc, argv);
}
static JSValue e_net_multiplayer_peer_class_get_peer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ENetMultiplayerPeer::get_peer, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry e_net_multiplayer_peer_class_proto_funcs[] = {
	JS_CFUNC_DEF("create_server", 5, &e_net_multiplayer_peer_class_create_server),
	JS_CFUNC_DEF("create_client", 6, &e_net_multiplayer_peer_class_create_client),
	JS_CFUNC_DEF("create_mesh", 1, &e_net_multiplayer_peer_class_create_mesh),
	JS_CFUNC_DEF("add_mesh_peer", 2, &e_net_multiplayer_peer_class_add_mesh_peer),
	JS_CFUNC_DEF("set_bind_ip", 1, &e_net_multiplayer_peer_class_set_bind_ip),
	JS_CFUNC_DEF("get_host", 0, &e_net_multiplayer_peer_class_get_host),
	JS_CFUNC_DEF("get_peer", 1, &e_net_multiplayer_peer_class_get_peer),
};




static void define_e_net_multiplayer_peer_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "host"),
        JS_NewCFunction(ctx, e_net_multiplayer_peer_class_get_host, "get_host", 0),
        JS_UNDEFINED,
        JS_PROP_GETSET
    );
}

static void define_e_net_multiplayer_peer_enum(JSContext *ctx, JSValue ctor) {
}

static int js_e_net_multiplayer_peer_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["ENetMultiplayerPeer"] = class_id;
	classes_by_id[class_id] = "ENetMultiplayerPeer";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &e_net_multiplayer_peer_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["MultiplayerPeer"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_e_net_multiplayer_peer_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, e_net_multiplayer_peer_class_proto_funcs, _countof(e_net_multiplayer_peer_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, e_net_multiplayer_peer_class_constructor, "ENetMultiplayerPeer", 0, JS_CFUNC_constructor, 0);
	define_e_net_multiplayer_peer_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "ENetMultiplayerPeer", ctor);
	ctor_list["ENetMultiplayerPeer"] = ctor;

	return 0;
}

JSModuleDef *_js_init_e_net_multiplayer_peer_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/multiplayer_peer';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_e_net_multiplayer_peer_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "ENetMultiplayerPeer");
	return m;
}

JSModuleDef *js_init_e_net_multiplayer_peer_module(JSContext *ctx) {
	return _js_init_e_net_multiplayer_peer_module(ctx, "@godot/classes/e_net_multiplayer_peer");
}

void __register_e_net_multiplayer_peer() {
	js_init_e_net_multiplayer_peer_module(js_context());
}

void register_e_net_multiplayer_peer() {
	__register_e_net_multiplayer_peer();
}