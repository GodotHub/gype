#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/open_xrapi_extension.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/open_xr_extension_wrapper.hpp>
using namespace godot;

static void open_xr_extension_wrapper_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["OpenXRExtensionWrapper"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef open_xr_extension_wrapper_class_def = {
    "OpenXRExtensionWrapper",
    open_xr_extension_wrapper_class_finalizer
};

static JSValue open_xr_extension_wrapper_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["OpenXRExtensionWrapper"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    OpenXRExtensionWrapper *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<OpenXRExtensionWrapper *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(OpenXRExtensionWrapper);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue open_xr_extension_wrapper_class_get_openxr_api(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&OpenXRExtensionWrapper::get_openxr_api, ctx, this_val, argc, argv);
};
static JSValue open_xr_extension_wrapper_class_register_extension_wrapper(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRExtensionWrapper::register_extension_wrapper, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry open_xr_extension_wrapper_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_openxr_api", 0, &open_xr_extension_wrapper_class_get_openxr_api),
	JS_CFUNC_DEF("register_extension_wrapper", 0, &open_xr_extension_wrapper_class_register_extension_wrapper),
};




static void define_open_xr_extension_wrapper_property(JSContext *ctx, JSValue proto) {
}

static void define_open_xr_extension_wrapper_enum(JSContext *ctx, JSValue ctor) {
}

static int js_open_xr_extension_wrapper_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["OpenXRExtensionWrapper"] = class_id;
	classes_by_id[class_id] = "OpenXRExtensionWrapper";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &open_xr_extension_wrapper_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["GodotObject"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_open_xr_extension_wrapper_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, open_xr_extension_wrapper_class_proto_funcs, _countof(open_xr_extension_wrapper_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, open_xr_extension_wrapper_class_constructor, "OpenXRExtensionWrapper", 0, JS_CFUNC_constructor, 0);
	define_open_xr_extension_wrapper_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "OpenXRExtensionWrapper", ctor);

	return 0;
}

JSModuleDef *_js_init_open_xr_extension_wrapper_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/godot_object';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_open_xr_extension_wrapper_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "OpenXRExtensionWrapper");
	return m;
}

JSModuleDef *js_init_open_xr_extension_wrapper_module(JSContext *ctx) {
	return _js_init_open_xr_extension_wrapper_module(ctx, "@godot/classes/open_xr_extension_wrapper");
}

void __register_open_xr_extension_wrapper() {
	js_init_open_xr_extension_wrapper_module(js_context());
}

void register_open_xr_extension_wrapper() {
	__register_open_xr_extension_wrapper();
}