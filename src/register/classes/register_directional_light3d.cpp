#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/light3d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/directional_light3d.hpp>
using namespace godot;

static void directional_light3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["DirectionalLight3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef directional_light3d_class_def = {
    "DirectionalLight3D",
    directional_light3d_class_finalizer
};

static JSValue directional_light3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["DirectionalLight3D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    DirectionalLight3D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<DirectionalLight3D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(DirectionalLight3D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue directional_light3d_class_set_shadow_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&DirectionalLight3D::set_shadow_mode, ctx, this_val, argc, argv);
};
static JSValue directional_light3d_class_get_shadow_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&DirectionalLight3D::get_shadow_mode, ctx, this_val, argc, argv);
}
static JSValue directional_light3d_class_set_blend_splits(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&DirectionalLight3D::set_blend_splits, ctx, this_val, argc, argv);
};
static JSValue directional_light3d_class_is_blend_splits_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&DirectionalLight3D::is_blend_splits_enabled, ctx, this_val, argc, argv);
}
static JSValue directional_light3d_class_set_sky_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&DirectionalLight3D::set_sky_mode, ctx, this_val, argc, argv);
};
static JSValue directional_light3d_class_get_sky_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&DirectionalLight3D::get_sky_mode, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry directional_light3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_shadow_mode", 1, &directional_light3d_class_set_shadow_mode),
	JS_CFUNC_DEF("get_shadow_mode", 0, &directional_light3d_class_get_shadow_mode),
	JS_CFUNC_DEF("set_blend_splits", 1, &directional_light3d_class_set_blend_splits),
	JS_CFUNC_DEF("is_blend_splits_enabled", 0, &directional_light3d_class_is_blend_splits_enabled),
	JS_CFUNC_DEF("set_sky_mode", 1, &directional_light3d_class_set_sky_mode),
	JS_CFUNC_DEF("get_sky_mode", 0, &directional_light3d_class_get_sky_mode),
};




static void define_directional_light3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "directional_shadow_mode"),
        JS_NewCFunction(ctx, directional_light3d_class_get_shadow_mode, "get_shadow_mode", 0),
        JS_NewCFunction(ctx, directional_light3d_class_set_shadow_mode, "set_shadow_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "directional_shadow_blend_splits"),
        JS_NewCFunction(ctx, directional_light3d_class_is_blend_splits_enabled, "is_blend_splits_enabled", 0),
        JS_NewCFunction(ctx, directional_light3d_class_set_blend_splits, "set_blend_splits", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "sky_mode"),
        JS_NewCFunction(ctx, directional_light3d_class_get_sky_mode, "get_sky_mode", 0),
        JS_NewCFunction(ctx, directional_light3d_class_set_sky_mode, "set_sky_mode", 1),
        JS_PROP_GETSET
    );
}

static void define_directional_light3d_enum(JSContext *ctx, JSValue ctor) {
	JSValue ShadowMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, ShadowMode_obj, "SHADOW_ORTHOGONAL", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, ShadowMode_obj, "SHADOW_PARALLEL_2_SPLITS", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ShadowMode_obj, "SHADOW_PARALLEL_4_SPLITS", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "ShadowMode", ShadowMode_obj);
	JSValue SkyMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, SkyMode_obj, "SKY_MODE_LIGHT_AND_SKY", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, SkyMode_obj, "SKY_MODE_LIGHT_ONLY", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, SkyMode_obj, "SKY_MODE_SKY_ONLY", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "SkyMode", SkyMode_obj);
}

static int js_directional_light3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["DirectionalLight3D"] = class_id;
	classes_by_id[class_id] = "DirectionalLight3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &directional_light3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Light3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_directional_light3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, directional_light3d_class_proto_funcs, _countof(directional_light3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, directional_light3d_class_constructor, "DirectionalLight3D", 0, JS_CFUNC_constructor, 0);
	define_directional_light3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "DirectionalLight3D", ctor);

	return 0;
}

JSModuleDef *_js_init_directional_light3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/light3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_directional_light3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "DirectionalLight3D");
	return m;
}

JSModuleDef *js_init_directional_light3d_module(JSContext *ctx) {
	return _js_init_directional_light3d_module(ctx, "@godot/classes/directional_light3d");
}

void __register_directional_light3d() {
	js_init_directional_light3d_module(js_context());
}

void register_directional_light3d() {
	__register_directional_light3d();
}