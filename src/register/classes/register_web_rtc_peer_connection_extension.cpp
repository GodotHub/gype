#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/web_rtc_data_channel.hpp>
#include <godot_cpp/classes/web_rtc_peer_connection.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/web_rtc_peer_connection_extension.hpp>
using namespace godot;

static void web_rtc_peer_connection_extension_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["WebRTCPeerConnectionExtension"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef web_rtc_peer_connection_extension_class_def = {
    "WebRTCPeerConnectionExtension",
    web_rtc_peer_connection_extension_class_finalizer
};

static JSValue web_rtc_peer_connection_extension_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["WebRTCPeerConnectionExtension"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    WebRTCPeerConnectionExtension *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<WebRTCPeerConnectionExtension *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(WebRTCPeerConnectionExtension);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}






static void define_web_rtc_peer_connection_extension_property(JSContext *ctx, JSValue proto) {
}

static void define_web_rtc_peer_connection_extension_enum(JSContext *ctx, JSValue proto) {
}

static int js_web_rtc_peer_connection_extension_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["WebRTCPeerConnectionExtension"] = class_id;
	classes_by_id[class_id] = "WebRTCPeerConnectionExtension";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &web_rtc_peer_connection_extension_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["WebRTCPeerConnection"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_web_rtc_peer_connection_extension_property(ctx, proto);
	define_web_rtc_peer_connection_extension_enum(ctx, proto);
	JSValue ctor = JS_NewCFunction2(ctx, web_rtc_peer_connection_extension_class_constructor, "WebRTCPeerConnectionExtension", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "WebRTCPeerConnectionExtension", ctor);

	return 0;
}

JSModuleDef *_js_init_web_rtc_peer_connection_extension_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/web_rtc_peer_connection';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_web_rtc_peer_connection_extension_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "WebRTCPeerConnectionExtension");
	return m;
}

JSModuleDef *js_init_web_rtc_peer_connection_extension_module(JSContext *ctx) {
	return _js_init_web_rtc_peer_connection_extension_module(ctx, "@godot/classes/web_rtc_peer_connection_extension");
}

void __register_web_rtc_peer_connection_extension() {
	js_init_web_rtc_peer_connection_extension_module(js_context());
}

void register_web_rtc_peer_connection_extension() {
	__register_web_rtc_peer_connection_extension();
}