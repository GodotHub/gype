#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/packet_peer.hpp>
using namespace godot;

static void packet_peer_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["PacketPeer"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef packet_peer_class_def = {
    "PacketPeer",
    packet_peer_class_finalizer
};

static JSValue packet_peer_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["PacketPeer"];
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
        instance = memnew(PacketPeer);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue packet_peer_class_get_var(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&PacketPeer::get_var, ctx, this_val, argc, argv);
};
static JSValue packet_peer_class_put_var(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&PacketPeer::put_var, ctx, this_val, argc, argv);
};
static JSValue packet_peer_class_get_packet(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&PacketPeer::get_packet, ctx, this_val, argc, argv);
};
static JSValue packet_peer_class_put_packet(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&PacketPeer::put_packet, ctx, this_val, argc, argv);
};
static JSValue packet_peer_class_get_packet_error(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PacketPeer::get_packet_error, ctx, this_val, argc, argv);
};
static JSValue packet_peer_class_get_available_packet_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PacketPeer::get_available_packet_count, ctx, this_val, argc, argv);
};
static JSValue packet_peer_class_get_encode_buffer_max_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PacketPeer::get_encode_buffer_max_size, ctx, this_val, argc, argv);
}
static JSValue packet_peer_class_set_encode_buffer_max_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PacketPeer::set_encode_buffer_max_size, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry packet_peer_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_var", 1, &packet_peer_class_get_var),
	JS_CFUNC_DEF("put_var", 2, &packet_peer_class_put_var),
	JS_CFUNC_DEF("get_packet", 0, &packet_peer_class_get_packet),
	JS_CFUNC_DEF("put_packet", 1, &packet_peer_class_put_packet),
	JS_CFUNC_DEF("get_packet_error", 0, &packet_peer_class_get_packet_error),
	JS_CFUNC_DEF("get_available_packet_count", 0, &packet_peer_class_get_available_packet_count),
	JS_CFUNC_DEF("get_encode_buffer_max_size", 0, &packet_peer_class_get_encode_buffer_max_size),
	JS_CFUNC_DEF("set_encode_buffer_max_size", 1, &packet_peer_class_set_encode_buffer_max_size),
};




static void define_packet_peer_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "encode_buffer_max_size"),
        JS_NewCFunction(ctx, packet_peer_class_get_encode_buffer_max_size, "get_encode_buffer_max_size", 0),
        JS_NewCFunction(ctx, packet_peer_class_set_encode_buffer_max_size, "set_encode_buffer_max_size", 1),
        JS_PROP_GETSET
    );
}

static void define_packet_peer_enum(JSContext *ctx, JSValue ctor) {
}

static int js_packet_peer_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["PacketPeer"] = class_id;
	classes_by_id[class_id] = "PacketPeer";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &packet_peer_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_packet_peer_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, packet_peer_class_proto_funcs, _countof(packet_peer_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, packet_peer_class_constructor, "PacketPeer", 0, JS_CFUNC_constructor, 0);
	define_packet_peer_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "PacketPeer", ctor);
	ctor_list["PacketPeer"] = ctor;

	return 0;
}

JSModuleDef *_js_init_packet_peer_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_packet_peer_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "PacketPeer");
	return m;
}

JSModuleDef *js_init_packet_peer_module(JSContext *ctx) {
	return _js_init_packet_peer_module(ctx, "@godot/classes/packet_peer");
}

void __register_packet_peer() {
	js_init_packet_peer_module(js_context());
}

void register_packet_peer() {
	__register_packet_peer();
}