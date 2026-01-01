#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/material.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/sky.hpp>
using namespace godot;

static void sky_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Sky"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef sky_class_def = {
    "Sky",
    sky_class_finalizer
};

static JSValue sky_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["Sky"];
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
        instance = memnew(Sky);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue sky_class_set_radiance_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Sky::set_radiance_size, ctx, this_val, argc, argv);
};
static JSValue sky_class_get_radiance_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Sky::get_radiance_size, ctx, this_val, argc, argv);
}
static JSValue sky_class_set_process_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Sky::set_process_mode, ctx, this_val, argc, argv);
};
static JSValue sky_class_get_process_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Sky::get_process_mode, ctx, this_val, argc, argv);
}
static JSValue sky_class_set_material(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Sky::set_material, ctx, this_val, argc, argv);
};
static JSValue sky_class_get_material(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Sky::get_material, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry sky_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_radiance_size", 1, &sky_class_set_radiance_size),
	JS_CFUNC_DEF("get_radiance_size", 0, &sky_class_get_radiance_size),
	JS_CFUNC_DEF("set_process_mode", 1, &sky_class_set_process_mode),
	JS_CFUNC_DEF("get_process_mode", 0, &sky_class_get_process_mode),
	JS_CFUNC_DEF("set_material", 1, &sky_class_set_material),
	JS_CFUNC_DEF("get_material", 0, &sky_class_get_material),
};




static void define_sky_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "sky_material"),
        JS_NewCFunction(ctx, sky_class_get_material, "get_material", 0),
        JS_NewCFunction(ctx, sky_class_set_material, "set_material", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "process_mode"),
        JS_NewCFunction(ctx, sky_class_get_process_mode, "get_process_mode", 0),
        JS_NewCFunction(ctx, sky_class_set_process_mode, "set_process_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "radiance_size"),
        JS_NewCFunction(ctx, sky_class_get_radiance_size, "get_radiance_size", 0),
        JS_NewCFunction(ctx, sky_class_set_radiance_size, "set_radiance_size", 1),
        JS_PROP_GETSET
    );
}

static void define_sky_enum(JSContext *ctx, JSValue ctor) {
	JSValue RadianceSize_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, RadianceSize_obj, "RADIANCE_SIZE_32", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, RadianceSize_obj, "RADIANCE_SIZE_64", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, RadianceSize_obj, "RADIANCE_SIZE_128", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, RadianceSize_obj, "RADIANCE_SIZE_256", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, RadianceSize_obj, "RADIANCE_SIZE_512", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, RadianceSize_obj, "RADIANCE_SIZE_1024", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, RadianceSize_obj, "RADIANCE_SIZE_2048", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, RadianceSize_obj, "RADIANCE_SIZE_MAX", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, ctor, "RadianceSize", RadianceSize_obj);
	JSValue ProcessMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, ProcessMode_obj, "PROCESS_MODE_AUTOMATIC", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, ProcessMode_obj, "PROCESS_MODE_QUALITY", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ProcessMode_obj, "PROCESS_MODE_INCREMENTAL", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ProcessMode_obj, "PROCESS_MODE_REALTIME", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ctor, "ProcessMode", ProcessMode_obj);
}

static int js_sky_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["Sky"] = class_id;
	classes_by_id[class_id] = "Sky";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &sky_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_sky_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, sky_class_proto_funcs, _countof(sky_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, sky_class_constructor, "Sky", 0, JS_CFUNC_constructor, 0);
	define_sky_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "Sky", ctor);
	ctor_list["Sky"] = ctor;

	return 0;
}

JSModuleDef *_js_init_sky_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_sky_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Sky");
	return m;
}

JSModuleDef *js_init_sky_module(JSContext *ctx) {
	return _js_init_sky_module(ctx, "@godot/classes/sky");
}

void __register_sky() {
	js_init_sky_module(js_context());
}

void register_sky() {
	__register_sky();
}