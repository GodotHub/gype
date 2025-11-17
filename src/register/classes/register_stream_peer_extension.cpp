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
#include <godot_cpp/classes/stream_peer_extension.hpp>
using namespace godot;

static void stream_peer_extension_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["StreamPeerExtension"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef stream_peer_extension_class_def = {
    "StreamPeerExtension",
    stream_peer_extension_class_finalizer
};

static JSValue stream_peer_extension_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["StreamPeerExtension"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    StreamPeerExtension *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<StreamPeerExtension *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(StreamPeerExtension);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}






static void define_stream_peer_extension_property(JSContext *ctx, JSValue proto) {
}

static void define_stream_peer_extension_enum(JSContext *ctx, JSValue ctor) {
}

static int js_stream_peer_extension_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["StreamPeerExtension"] = class_id;
	classes_by_id[class_id] = "StreamPeerExtension";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &stream_peer_extension_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["StreamPeer"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_stream_peer_extension_property(ctx, proto);
	JSValue ctor = JS_NewCFunction2(ctx, stream_peer_extension_class_constructor, "StreamPeerExtension", 0, JS_CFUNC_constructor, 0);
	define_stream_peer_extension_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "StreamPeerExtension", ctor);

	return 0;
}

JSModuleDef *_js_init_stream_peer_extension_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/stream_peer';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_stream_peer_extension_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "StreamPeerExtension");
	return m;
}

JSModuleDef *js_init_stream_peer_extension_module(JSContext *ctx) {
	return _js_init_stream_peer_extension_module(ctx, "@godot/classes/stream_peer_extension");
}

void __register_stream_peer_extension() {
	js_init_stream_peer_extension_module(js_context());
}

void register_stream_peer_extension() {
	__register_stream_peer_extension();
}