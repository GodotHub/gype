#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/packet_peer.hpp>
#include <godot_cpp/classes/stream_peer.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/packet_peer_stream.hpp>
using namespace godot;

static void packet_peer_stream_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["PacketPeerStream"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef packet_peer_stream_class_def = {
    "PacketPeerStream",
    packet_peer_stream_class_finalizer
};

static JSValue packet_peer_stream_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["PacketPeerStream"];
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
        instance = memnew(PacketPeerStream);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue packet_peer_stream_class_set_stream_peer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PacketPeerStream::set_stream_peer, ctx, this_val, argc, argv);
};
static JSValue packet_peer_stream_class_get_stream_peer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PacketPeerStream::get_stream_peer, ctx, this_val, argc, argv);
}
static JSValue packet_peer_stream_class_set_input_buffer_max_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PacketPeerStream::set_input_buffer_max_size, ctx, this_val, argc, argv);
};
static JSValue packet_peer_stream_class_set_output_buffer_max_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PacketPeerStream::set_output_buffer_max_size, ctx, this_val, argc, argv);
};
static JSValue packet_peer_stream_class_get_input_buffer_max_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PacketPeerStream::get_input_buffer_max_size, ctx, this_val, argc, argv);
}
static JSValue packet_peer_stream_class_get_output_buffer_max_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PacketPeerStream::get_output_buffer_max_size, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry packet_peer_stream_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_stream_peer", 1, &packet_peer_stream_class_set_stream_peer),
	JS_CFUNC_DEF("get_stream_peer", 0, &packet_peer_stream_class_get_stream_peer),
	JS_CFUNC_DEF("set_input_buffer_max_size", 1, &packet_peer_stream_class_set_input_buffer_max_size),
	JS_CFUNC_DEF("set_output_buffer_max_size", 1, &packet_peer_stream_class_set_output_buffer_max_size),
	JS_CFUNC_DEF("get_input_buffer_max_size", 0, &packet_peer_stream_class_get_input_buffer_max_size),
	JS_CFUNC_DEF("get_output_buffer_max_size", 0, &packet_peer_stream_class_get_output_buffer_max_size),
};




static void define_packet_peer_stream_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "input_buffer_max_size"),
        JS_NewCFunction(ctx, packet_peer_stream_class_get_input_buffer_max_size, "get_input_buffer_max_size", 0),
        JS_NewCFunction(ctx, packet_peer_stream_class_set_input_buffer_max_size, "set_input_buffer_max_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "output_buffer_max_size"),
        JS_NewCFunction(ctx, packet_peer_stream_class_get_output_buffer_max_size, "get_output_buffer_max_size", 0),
        JS_NewCFunction(ctx, packet_peer_stream_class_set_output_buffer_max_size, "set_output_buffer_max_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "stream_peer"),
        JS_NewCFunction(ctx, packet_peer_stream_class_get_stream_peer, "get_stream_peer", 0),
        JS_NewCFunction(ctx, packet_peer_stream_class_set_stream_peer, "set_stream_peer", 1),
        JS_PROP_GETSET
    );
}

static void define_packet_peer_stream_enum(JSContext *ctx, JSValue ctor) {
}

static int js_packet_peer_stream_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["PacketPeerStream"] = class_id;
	classes_by_id[class_id] = "PacketPeerStream";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &packet_peer_stream_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["PacketPeer"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_packet_peer_stream_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, packet_peer_stream_class_proto_funcs, _countof(packet_peer_stream_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, packet_peer_stream_class_constructor, "PacketPeerStream", 0, JS_CFUNC_constructor, 0);
	define_packet_peer_stream_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "PacketPeerStream", ctor);
	ctor_list["PacketPeerStream"] = ctor;

	return 0;
}

JSModuleDef *_js_init_packet_peer_stream_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/packet_peer';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_packet_peer_stream_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "PacketPeerStream");
	return m;
}

JSModuleDef *js_init_packet_peer_stream_module(JSContext *ctx) {
	return _js_init_packet_peer_stream_module(ctx, "@godot/classes/packet_peer_stream");
}

void __register_packet_peer_stream() {
	js_init_packet_peer_stream_module(js_context());
}

void register_packet_peer_stream() {
	__register_packet_peer_stream();
}