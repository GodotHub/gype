#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/xr_interface.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/xr_interface_extension.hpp>
using namespace godot;

static void xr_interface_extension_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["XRInterfaceExtension"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef xr_interface_extension_class_def = {
    "XRInterfaceExtension",
    xr_interface_extension_class_finalizer
};

static JSValue xr_interface_extension_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["XRInterfaceExtension"];
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
        instance = memnew(XRInterfaceExtension);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue xr_interface_extension_class_get_color_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&XRInterfaceExtension::get_color_texture, ctx, this_val, argc, argv);
};
static JSValue xr_interface_extension_class_get_depth_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&XRInterfaceExtension::get_depth_texture, ctx, this_val, argc, argv);
};
static JSValue xr_interface_extension_class_get_velocity_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&XRInterfaceExtension::get_velocity_texture, ctx, this_val, argc, argv);
};
static JSValue xr_interface_extension_class_add_blit(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&XRInterfaceExtension::add_blit, ctx, this_val, argc, argv);
};
static JSValue xr_interface_extension_class_get_render_target_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&XRInterfaceExtension::get_render_target_texture, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry xr_interface_extension_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_color_texture", 0, &xr_interface_extension_class_get_color_texture),
	JS_CFUNC_DEF("get_depth_texture", 0, &xr_interface_extension_class_get_depth_texture),
	JS_CFUNC_DEF("get_velocity_texture", 0, &xr_interface_extension_class_get_velocity_texture),
	JS_CFUNC_DEF("add_blit", 11, &xr_interface_extension_class_add_blit),
	JS_CFUNC_DEF("get_render_target_texture", 1, &xr_interface_extension_class_get_render_target_texture),
};




static void define_xr_interface_extension_property(JSContext *ctx, JSValue proto) {
}

static void define_xr_interface_extension_enum(JSContext *ctx, JSValue ctor) {
}

static int js_xr_interface_extension_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["XRInterfaceExtension"] = class_id;
	classes_by_id[class_id] = "XRInterfaceExtension";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &xr_interface_extension_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["XRInterface"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_xr_interface_extension_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, xr_interface_extension_class_proto_funcs, _countof(xr_interface_extension_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, xr_interface_extension_class_constructor, "XRInterfaceExtension", 0, JS_CFUNC_constructor, 0);
	define_xr_interface_extension_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "XRInterfaceExtension", ctor);
	ctor_list["XRInterfaceExtension"] = ctor;

	return 0;
}

JSModuleDef *_js_init_xr_interface_extension_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/xr_interface';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_xr_interface_extension_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "XRInterfaceExtension");
	return m;
}

JSModuleDef *js_init_xr_interface_extension_module(JSContext *ctx) {
	return _js_init_xr_interface_extension_module(ctx, "@godot/classes/xr_interface_extension");
}

void __register_xr_interface_extension() {
	js_init_xr_interface_extension_module(js_context());
}

void register_xr_interface_extension() {
	__register_xr_interface_extension();
}