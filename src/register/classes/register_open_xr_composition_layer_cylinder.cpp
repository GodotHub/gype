#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/open_xr_composition_layer.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/open_xr_composition_layer_cylinder.hpp>
using namespace godot;

static void open_xr_composition_layer_cylinder_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["OpenXRCompositionLayerCylinder"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef open_xr_composition_layer_cylinder_class_def = {
    "OpenXRCompositionLayerCylinder",
    open_xr_composition_layer_cylinder_class_finalizer
};

static JSValue open_xr_composition_layer_cylinder_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["OpenXRCompositionLayerCylinder"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    OpenXRCompositionLayerCylinder *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<OpenXRCompositionLayerCylinder *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(OpenXRCompositionLayerCylinder);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue open_xr_composition_layer_cylinder_class_set_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRCompositionLayerCylinder::set_radius, ctx, this_val, argc, argv);
};
static JSValue open_xr_composition_layer_cylinder_class_get_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRCompositionLayerCylinder::get_radius, ctx, this_val, argc, argv);
}
static JSValue open_xr_composition_layer_cylinder_class_set_aspect_ratio(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRCompositionLayerCylinder::set_aspect_ratio, ctx, this_val, argc, argv);
};
static JSValue open_xr_composition_layer_cylinder_class_get_aspect_ratio(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRCompositionLayerCylinder::get_aspect_ratio, ctx, this_val, argc, argv);
}
static JSValue open_xr_composition_layer_cylinder_class_set_central_angle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRCompositionLayerCylinder::set_central_angle, ctx, this_val, argc, argv);
};
static JSValue open_xr_composition_layer_cylinder_class_get_central_angle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRCompositionLayerCylinder::get_central_angle, ctx, this_val, argc, argv);
}
static JSValue open_xr_composition_layer_cylinder_class_set_fallback_segments(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRCompositionLayerCylinder::set_fallback_segments, ctx, this_val, argc, argv);
};
static JSValue open_xr_composition_layer_cylinder_class_get_fallback_segments(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRCompositionLayerCylinder::get_fallback_segments, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry open_xr_composition_layer_cylinder_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_radius", 1, &open_xr_composition_layer_cylinder_class_set_radius),
	JS_CFUNC_DEF("get_radius", 0, &open_xr_composition_layer_cylinder_class_get_radius),
	JS_CFUNC_DEF("set_aspect_ratio", 1, &open_xr_composition_layer_cylinder_class_set_aspect_ratio),
	JS_CFUNC_DEF("get_aspect_ratio", 0, &open_xr_composition_layer_cylinder_class_get_aspect_ratio),
	JS_CFUNC_DEF("set_central_angle", 1, &open_xr_composition_layer_cylinder_class_set_central_angle),
	JS_CFUNC_DEF("get_central_angle", 0, &open_xr_composition_layer_cylinder_class_get_central_angle),
	JS_CFUNC_DEF("set_fallback_segments", 1, &open_xr_composition_layer_cylinder_class_set_fallback_segments),
	JS_CFUNC_DEF("get_fallback_segments", 0, &open_xr_composition_layer_cylinder_class_get_fallback_segments),
};




static void define_open_xr_composition_layer_cylinder_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "radius"),
        JS_NewCFunction(ctx, open_xr_composition_layer_cylinder_class_get_radius, "get_radius", 0),
        JS_NewCFunction(ctx, open_xr_composition_layer_cylinder_class_set_radius, "set_radius", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "aspect_ratio"),
        JS_NewCFunction(ctx, open_xr_composition_layer_cylinder_class_get_aspect_ratio, "get_aspect_ratio", 0),
        JS_NewCFunction(ctx, open_xr_composition_layer_cylinder_class_set_aspect_ratio, "set_aspect_ratio", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "central_angle"),
        JS_NewCFunction(ctx, open_xr_composition_layer_cylinder_class_get_central_angle, "get_central_angle", 0),
        JS_NewCFunction(ctx, open_xr_composition_layer_cylinder_class_set_central_angle, "set_central_angle", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "fallback_segments"),
        JS_NewCFunction(ctx, open_xr_composition_layer_cylinder_class_get_fallback_segments, "get_fallback_segments", 0),
        JS_NewCFunction(ctx, open_xr_composition_layer_cylinder_class_set_fallback_segments, "set_fallback_segments", 1),
        JS_PROP_GETSET
    );
}

static void define_open_xr_composition_layer_cylinder_enum(JSContext *ctx, JSValue proto) {
}

static int js_open_xr_composition_layer_cylinder_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["OpenXRCompositionLayerCylinder"] = class_id;
	classes_by_id[class_id] = "OpenXRCompositionLayerCylinder";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &open_xr_composition_layer_cylinder_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["OpenXRCompositionLayer"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_open_xr_composition_layer_cylinder_property(ctx, proto);
	define_open_xr_composition_layer_cylinder_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, open_xr_composition_layer_cylinder_class_proto_funcs, _countof(open_xr_composition_layer_cylinder_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, open_xr_composition_layer_cylinder_class_constructor, "OpenXRCompositionLayerCylinder", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "OpenXRCompositionLayerCylinder", ctor);

	return 0;
}

JSModuleDef *_js_init_open_xr_composition_layer_cylinder_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/open_xr_composition_layer';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_open_xr_composition_layer_cylinder_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "OpenXRCompositionLayerCylinder");
	return m;
}

JSModuleDef *js_init_open_xr_composition_layer_cylinder_module(JSContext *ctx) {
	return _js_init_open_xr_composition_layer_cylinder_module(ctx, "@godot/classes/open_xr_composition_layer_cylinder");
}

void __register_open_xr_composition_layer_cylinder() {
	js_init_open_xr_composition_layer_cylinder_module(js_context());
}

void register_open_xr_composition_layer_cylinder() {
	__register_open_xr_composition_layer_cylinder();
}