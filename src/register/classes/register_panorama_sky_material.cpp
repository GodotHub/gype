#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/material.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/panorama_sky_material.hpp>
using namespace godot;

static void panorama_sky_material_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["PanoramaSkyMaterial"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef panorama_sky_material_class_def = {
    "PanoramaSkyMaterial",
    panorama_sky_material_class_finalizer
};

static JSValue panorama_sky_material_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["PanoramaSkyMaterial"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    PanoramaSkyMaterial *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<PanoramaSkyMaterial *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(PanoramaSkyMaterial);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue panorama_sky_material_class_set_panorama(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PanoramaSkyMaterial::set_panorama, ctx, this_val, argc, argv);
};
static JSValue panorama_sky_material_class_get_panorama(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PanoramaSkyMaterial::get_panorama, ctx, this_val, argc, argv);
}
static JSValue panorama_sky_material_class_set_filtering_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PanoramaSkyMaterial::set_filtering_enabled, ctx, this_val, argc, argv);
};
static JSValue panorama_sky_material_class_is_filtering_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PanoramaSkyMaterial::is_filtering_enabled, ctx, this_val, argc, argv);
}
static JSValue panorama_sky_material_class_set_energy_multiplier(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&PanoramaSkyMaterial::set_energy_multiplier, ctx, this_val, argc, argv);
};
static JSValue panorama_sky_material_class_get_energy_multiplier(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&PanoramaSkyMaterial::get_energy_multiplier, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry panorama_sky_material_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_panorama", 1, &panorama_sky_material_class_set_panorama),
	JS_CFUNC_DEF("get_panorama", 0, &panorama_sky_material_class_get_panorama),
	JS_CFUNC_DEF("set_filtering_enabled", 1, &panorama_sky_material_class_set_filtering_enabled),
	JS_CFUNC_DEF("is_filtering_enabled", 0, &panorama_sky_material_class_is_filtering_enabled),
	JS_CFUNC_DEF("set_energy_multiplier", 1, &panorama_sky_material_class_set_energy_multiplier),
	JS_CFUNC_DEF("get_energy_multiplier", 0, &panorama_sky_material_class_get_energy_multiplier),
};




static void define_panorama_sky_material_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "panorama"),
        JS_NewCFunction(ctx, panorama_sky_material_class_get_panorama, "get_panorama", 0),
        JS_NewCFunction(ctx, panorama_sky_material_class_set_panorama, "set_panorama", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "filter"),
        JS_NewCFunction(ctx, panorama_sky_material_class_is_filtering_enabled, "is_filtering_enabled", 0),
        JS_NewCFunction(ctx, panorama_sky_material_class_set_filtering_enabled, "set_filtering_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "energy_multiplier"),
        JS_NewCFunction(ctx, panorama_sky_material_class_get_energy_multiplier, "get_energy_multiplier", 0),
        JS_NewCFunction(ctx, panorama_sky_material_class_set_energy_multiplier, "set_energy_multiplier", 1),
        JS_PROP_GETSET
    );
}

static void define_panorama_sky_material_enum(JSContext *ctx, JSValue ctor) {
}

static int js_panorama_sky_material_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["PanoramaSkyMaterial"] = class_id;
	classes_by_id[class_id] = "PanoramaSkyMaterial";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &panorama_sky_material_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Material"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_panorama_sky_material_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, panorama_sky_material_class_proto_funcs, _countof(panorama_sky_material_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, panorama_sky_material_class_constructor, "PanoramaSkyMaterial", 0, JS_CFUNC_constructor, 0);
	define_panorama_sky_material_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "PanoramaSkyMaterial", ctor);

	return 0;
}

JSModuleDef *_js_init_panorama_sky_material_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/material';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_panorama_sky_material_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "PanoramaSkyMaterial");
	return m;
}

JSModuleDef *js_init_panorama_sky_material_module(JSContext *ctx) {
	return _js_init_panorama_sky_material_module(ctx, "@godot/classes/panorama_sky_material");
}

void __register_panorama_sky_material() {
	js_init_panorama_sky_material_module(js_context());
}

void register_panorama_sky_material() {
	__register_panorama_sky_material();
}