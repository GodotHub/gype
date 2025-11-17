#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/xr_origin3d.hpp>
using namespace godot;

static void xr_origin3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["XROrigin3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef xr_origin3d_class_def = {
    "XROrigin3D",
    xr_origin3d_class_finalizer
};

static JSValue xr_origin3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["XROrigin3D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    XROrigin3D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<XROrigin3D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(XROrigin3D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue xr_origin3d_class_set_world_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&XROrigin3D::set_world_scale, ctx, this_val, argc, argv);
};
static JSValue xr_origin3d_class_get_world_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XROrigin3D::get_world_scale, ctx, this_val, argc, argv);
}
static JSValue xr_origin3d_class_set_current(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&XROrigin3D::set_current, ctx, this_val, argc, argv);
};
static JSValue xr_origin3d_class_is_current(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XROrigin3D::is_current, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry xr_origin3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_world_scale", 1, &xr_origin3d_class_set_world_scale),
	JS_CFUNC_DEF("get_world_scale", 0, &xr_origin3d_class_get_world_scale),
	JS_CFUNC_DEF("set_current", 1, &xr_origin3d_class_set_current),
	JS_CFUNC_DEF("is_current", 0, &xr_origin3d_class_is_current),
};




static void define_xr_origin3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "world_scale"),
        JS_NewCFunction(ctx, xr_origin3d_class_get_world_scale, "get_world_scale", 0),
        JS_NewCFunction(ctx, xr_origin3d_class_set_world_scale, "set_world_scale", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "current"),
        JS_NewCFunction(ctx, xr_origin3d_class_is_current, "is_current", 0),
        JS_NewCFunction(ctx, xr_origin3d_class_set_current, "set_current", 1),
        JS_PROP_GETSET
    );
}

static void define_xr_origin3d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_xr_origin3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["XROrigin3D"] = class_id;
	classes_by_id[class_id] = "XROrigin3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &xr_origin3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_xr_origin3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, xr_origin3d_class_proto_funcs, _countof(xr_origin3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, xr_origin3d_class_constructor, "XROrigin3D", 0, JS_CFUNC_constructor, 0);
	define_xr_origin3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "XROrigin3D", ctor);

	return 0;
}

JSModuleDef *_js_init_xr_origin3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_xr_origin3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "XROrigin3D");
	return m;
}

JSModuleDef *js_init_xr_origin3d_module(JSContext *ctx) {
	return _js_init_xr_origin3d_module(ctx, "@godot/classes/xr_origin3d");
}

void __register_xr_origin3d() {
	js_init_xr_origin3d_module(js_context());
}

void register_xr_origin3d() {
	__register_xr_origin3d();
}