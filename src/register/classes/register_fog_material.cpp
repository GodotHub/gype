#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/material.hpp>
#include <godot_cpp/classes/texture3d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/fog_material.hpp>
using namespace godot;

static void fog_material_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["FogMaterial"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
	}
}

static JSClassDef fog_material_class_def = {
    "FogMaterial",
    fog_material_class_finalizer
};

static JSValue fog_material_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["FogMaterial"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    FogMaterial *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<FogMaterial *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(FogMaterial);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue fog_material_class_set_density(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FogMaterial::set_density, ctx, this_val, argc, argv);
};
static JSValue fog_material_class_get_density(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FogMaterial::get_density, ctx, this_val, argc, argv);
}
static JSValue fog_material_class_set_albedo(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FogMaterial::set_albedo, ctx, this_val, argc, argv);
};
static JSValue fog_material_class_get_albedo(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		FogMaterial *obj = static_cast<FogMaterial *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_albedo();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		FogMaterial *js_proxy = static_cast<FogMaterial *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_albedo(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["ColorProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "ColorProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue fog_material_class_set_emission(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FogMaterial::set_emission, ctx, this_val, argc, argv);
};
static JSValue fog_material_class_get_emission(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		FogMaterial *obj = static_cast<FogMaterial *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_emission();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		FogMaterial *js_proxy = static_cast<FogMaterial *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_emission(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["ColorProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "ColorProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue fog_material_class_set_height_falloff(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FogMaterial::set_height_falloff, ctx, this_val, argc, argv);
};
static JSValue fog_material_class_get_height_falloff(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FogMaterial::get_height_falloff, ctx, this_val, argc, argv);
}
static JSValue fog_material_class_set_edge_fade(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FogMaterial::set_edge_fade, ctx, this_val, argc, argv);
};
static JSValue fog_material_class_get_edge_fade(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FogMaterial::get_edge_fade, ctx, this_val, argc, argv);
}
static JSValue fog_material_class_set_density_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&FogMaterial::set_density_texture, ctx, this_val, argc, argv);
};
static JSValue fog_material_class_get_density_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&FogMaterial::get_density_texture, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry fog_material_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_density", 1, &fog_material_class_set_density),
	JS_CFUNC_DEF("get_density", 0, &fog_material_class_get_density),
	JS_CFUNC_DEF("set_albedo", 1, &fog_material_class_set_albedo),
	JS_CFUNC_DEF("get_albedo", 0, &fog_material_class_get_albedo),
	JS_CFUNC_DEF("set_emission", 1, &fog_material_class_set_emission),
	JS_CFUNC_DEF("get_emission", 0, &fog_material_class_get_emission),
	JS_CFUNC_DEF("set_height_falloff", 1, &fog_material_class_set_height_falloff),
	JS_CFUNC_DEF("get_height_falloff", 0, &fog_material_class_get_height_falloff),
	JS_CFUNC_DEF("set_edge_fade", 1, &fog_material_class_set_edge_fade),
	JS_CFUNC_DEF("get_edge_fade", 0, &fog_material_class_get_edge_fade),
	JS_CFUNC_DEF("set_density_texture", 1, &fog_material_class_set_density_texture),
	JS_CFUNC_DEF("get_density_texture", 0, &fog_material_class_get_density_texture),
};




static void define_fog_material_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "density"),
        JS_NewCFunction(ctx, fog_material_class_get_density, "get_density", 0),
        JS_NewCFunction(ctx, fog_material_class_set_density, "set_density", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "albedo"),
        JS_NewCFunction(ctx, fog_material_class_get_albedo, "get_albedo", 0),
        JS_NewCFunction(ctx, fog_material_class_set_albedo, "set_albedo", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "emission"),
        JS_NewCFunction(ctx, fog_material_class_get_emission, "get_emission", 0),
        JS_NewCFunction(ctx, fog_material_class_set_emission, "set_emission", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "height_falloff"),
        JS_NewCFunction(ctx, fog_material_class_get_height_falloff, "get_height_falloff", 0),
        JS_NewCFunction(ctx, fog_material_class_set_height_falloff, "set_height_falloff", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "edge_fade"),
        JS_NewCFunction(ctx, fog_material_class_get_edge_fade, "get_edge_fade", 0),
        JS_NewCFunction(ctx, fog_material_class_set_edge_fade, "set_edge_fade", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "density_texture"),
        JS_NewCFunction(ctx, fog_material_class_get_density_texture, "get_density_texture", 0),
        JS_NewCFunction(ctx, fog_material_class_set_density_texture, "set_density_texture", 1),
        JS_PROP_GETSET
    );
}

static void define_fog_material_enum(JSContext *ctx, JSValue ctor) {
}

static int js_fog_material_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["FogMaterial"] = class_id;
	classes_by_id[class_id] = "FogMaterial";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &fog_material_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Material"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_fog_material_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, fog_material_class_proto_funcs, _countof(fog_material_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, fog_material_class_constructor, "FogMaterial", 0, JS_CFUNC_constructor, 0);
	define_fog_material_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "FogMaterial", ctor);

	return 0;
}

JSModuleDef *_js_init_fog_material_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/material';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_fog_material_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "FogMaterial");
	return m;
}

JSModuleDef *js_init_fog_material_module(JSContext *ctx) {
	return _js_init_fog_material_module(ctx, "@godot/classes/fog_material");
}

void __register_fog_material() {
	js_init_fog_material_module(js_context());
}

void register_fog_material() {
	__register_fog_material();
}