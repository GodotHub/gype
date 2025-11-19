#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/material.hpp>
#include <godot_cpp/classes/visual_instance3d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/fog_volume.hpp>
using namespace godot;

static void fog_volume_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["FogVolume"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef fog_volume_class_def = {
    "FogVolume",
    fog_volume_class_finalizer
};

static JSValue fog_volume_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["FogVolume"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    FogVolume *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<FogVolume *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(FogVolume);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue fog_volume_class_set_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FogVolume::set_size, ctx, this_val, argc, argv);
};
static JSValue fog_volume_class_get_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector3> *proxy = memnew(ObjectProxy<Vector3>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector3 {
		FogVolume *obj = static_cast<FogVolume *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_size();
	};
	proxy->setter = [this_val](const Vector3 &value) -> void {
		FogVolume *js_proxy = static_cast<FogVolume *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_size(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector3Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector3Proxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue fog_volume_class_set_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FogVolume::set_shape, ctx, this_val, argc, argv);
};
static JSValue fog_volume_class_get_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FogVolume::get_shape, ctx, this_val, argc, argv);
}
static JSValue fog_volume_class_set_material(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FogVolume::set_material, ctx, this_val, argc, argv);
};
static JSValue fog_volume_class_get_material(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FogVolume::get_material, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry fog_volume_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_size", 1, &fog_volume_class_set_size),
	JS_CFUNC_DEF("get_size", 0, &fog_volume_class_get_size),
	JS_CFUNC_DEF("set_shape", 1, &fog_volume_class_set_shape),
	JS_CFUNC_DEF("get_shape", 0, &fog_volume_class_get_shape),
	JS_CFUNC_DEF("set_material", 1, &fog_volume_class_set_material),
	JS_CFUNC_DEF("get_material", 0, &fog_volume_class_get_material),
};




static void define_fog_volume_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "size"),
        JS_NewCFunction(ctx, fog_volume_class_get_size, "get_size", 0),
        JS_NewCFunction(ctx, fog_volume_class_set_size, "set_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "shape"),
        JS_NewCFunction(ctx, fog_volume_class_get_shape, "get_shape", 0),
        JS_NewCFunction(ctx, fog_volume_class_set_shape, "set_shape", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "material"),
        JS_NewCFunction(ctx, fog_volume_class_get_material, "get_material", 0),
        JS_NewCFunction(ctx, fog_volume_class_set_material, "set_material", 1),
        JS_PROP_GETSET
    );
}

static void define_fog_volume_enum(JSContext *ctx, JSValue ctor) {
}

static int js_fog_volume_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["FogVolume"] = class_id;
	classes_by_id[class_id] = "FogVolume";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &fog_volume_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["VisualInstance3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_fog_volume_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, fog_volume_class_proto_funcs, _countof(fog_volume_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, fog_volume_class_constructor, "FogVolume", 0, JS_CFUNC_constructor, 0);
	define_fog_volume_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "FogVolume", ctor);

	return 0;
}

JSModuleDef *_js_init_fog_volume_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/visual_instance3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_fog_volume_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "FogVolume");
	return m;
}

JSModuleDef *js_init_fog_volume_module(JSContext *ctx) {
	return _js_init_fog_volume_module(ctx, "@godot/classes/fog_volume");
}

void __register_fog_volume() {
	js_init_fog_volume_module(js_context());
}

void register_fog_volume() {
	__register_fog_volume();
}