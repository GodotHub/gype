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
#include <godot_cpp/classes/stream_peer_buffer.hpp>
using namespace godot;

static void stream_peer_buffer_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["StreamPeerBuffer"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef stream_peer_buffer_class_def = {
    "StreamPeerBuffer",
    stream_peer_buffer_class_finalizer
};

static JSValue stream_peer_buffer_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["StreamPeerBuffer"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    StreamPeerBuffer *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<StreamPeerBuffer *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(StreamPeerBuffer);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue stream_peer_buffer_class_seek(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&StreamPeerBuffer::seek, ctx, this_val, argc, argv);
};
static JSValue stream_peer_buffer_class_get_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&StreamPeerBuffer::get_size, ctx, this_val, argc, argv);
};
static JSValue stream_peer_buffer_class_get_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&StreamPeerBuffer::get_position, ctx, this_val, argc, argv);
};
static JSValue stream_peer_buffer_class_resize(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&StreamPeerBuffer::resize, ctx, this_val, argc, argv);
};
static JSValue stream_peer_buffer_class_set_data_array(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&StreamPeerBuffer::set_data_array, ctx, this_val, argc, argv);
};
static JSValue stream_peer_buffer_class_get_data_array(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedByteArray> *proxy = memnew(ObjectProxy<PackedByteArray>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedByteArray {
		StreamPeerBuffer *obj = static_cast<StreamPeerBuffer *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_data_array();
	};
	proxy->setter = [this_val](const PackedByteArray &value) -> void {
		StreamPeerBuffer *js_proxy = static_cast<StreamPeerBuffer *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_data_array(PackedByteArray
(Array(value)));
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["PackedByteArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "PackedByteArrayProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue stream_peer_buffer_class_clear(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&StreamPeerBuffer::clear, ctx, this_val, argc, argv);
};
static JSValue stream_peer_buffer_class_duplicate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&StreamPeerBuffer::duplicate, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry stream_peer_buffer_class_proto_funcs[] = {
	JS_CFUNC_DEF("seek", 1, &stream_peer_buffer_class_seek),
	JS_CFUNC_DEF("get_size", 0, &stream_peer_buffer_class_get_size),
	JS_CFUNC_DEF("get_position", 0, &stream_peer_buffer_class_get_position),
	JS_CFUNC_DEF("resize", 1, &stream_peer_buffer_class_resize),
	JS_CFUNC_DEF("set_data_array", 1, &stream_peer_buffer_class_set_data_array),
	JS_CFUNC_DEF("get_data_array", 0, &stream_peer_buffer_class_get_data_array),
	JS_CFUNC_DEF("clear", 0, &stream_peer_buffer_class_clear),
	JS_CFUNC_DEF("duplicate", 0, &stream_peer_buffer_class_duplicate),
};




static void define_stream_peer_buffer_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "data_array"),
        JS_NewCFunction(ctx, stream_peer_buffer_class_get_data_array, "get_data_array", 0),
        JS_NewCFunction(ctx, stream_peer_buffer_class_set_data_array, "set_data_array", 1),
        JS_PROP_GETSET
    );
}

static void define_stream_peer_buffer_enum(JSContext *ctx, JSValue proto) {
}

static int js_stream_peer_buffer_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["StreamPeerBuffer"] = class_id;
	classes_by_id[class_id] = "StreamPeerBuffer";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &stream_peer_buffer_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["StreamPeer"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_stream_peer_buffer_property(ctx, proto);
	define_stream_peer_buffer_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, stream_peer_buffer_class_proto_funcs, _countof(stream_peer_buffer_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, stream_peer_buffer_class_constructor, "StreamPeerBuffer", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "StreamPeerBuffer", ctor);

	return 0;
}

JSModuleDef *_js_init_stream_peer_buffer_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/stream_peer';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_stream_peer_buffer_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "StreamPeerBuffer");
	return m;
}

JSModuleDef *js_init_stream_peer_buffer_module(JSContext *ctx) {
	return _js_init_stream_peer_buffer_module(ctx, "@godot/classes/stream_peer_buffer");
}

void __register_stream_peer_buffer() {
	js_init_stream_peer_buffer_module(js_context());
}

void register_stream_peer_buffer() {
	__register_stream_peer_buffer();
}