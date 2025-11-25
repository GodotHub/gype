#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/web_rtc_data_channel.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/web_rtc_data_channel_extension.hpp>
using namespace godot;

static void web_rtc_data_channel_extension_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["WebRTCDataChannelExtension"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef web_rtc_data_channel_extension_class_def = {
    "WebRTCDataChannelExtension",
    web_rtc_data_channel_extension_class_finalizer
};

static JSValue web_rtc_data_channel_extension_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["WebRTCDataChannelExtension"];
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
        instance = memnew(WebRTCDataChannelExtension);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}








static void define_web_rtc_data_channel_extension_property(JSContext *ctx, JSValue proto) {
}

static void define_web_rtc_data_channel_extension_enum(JSContext *ctx, JSValue ctor) {
}

static int js_web_rtc_data_channel_extension_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["WebRTCDataChannelExtension"] = class_id;
	classes_by_id[class_id] = "WebRTCDataChannelExtension";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &web_rtc_data_channel_extension_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["WebRTCDataChannel"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_web_rtc_data_channel_extension_property(ctx, proto);
	JSValue ctor = JS_NewCFunction2(ctx, web_rtc_data_channel_extension_class_constructor, "WebRTCDataChannelExtension", 0, JS_CFUNC_constructor, 0);
	define_web_rtc_data_channel_extension_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "WebRTCDataChannelExtension", ctor);
	ctor_list["WebRTCDataChannelExtension"] = ctor;

	return 0;
}

JSModuleDef *_js_init_web_rtc_data_channel_extension_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/web_rtc_data_channel';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_web_rtc_data_channel_extension_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "WebRTCDataChannelExtension");
	return m;
}

JSModuleDef *js_init_web_rtc_data_channel_extension_module(JSContext *ctx) {
	return _js_init_web_rtc_data_channel_extension_module(ctx, "@godot/classes/web_rtc_data_channel_extension");
}

void __register_web_rtc_data_channel_extension() {
	js_init_web_rtc_data_channel_extension_module(js_context());
}

void register_web_rtc_data_channel_extension() {
	__register_web_rtc_data_channel_extension();
}