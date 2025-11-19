#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/classes/visual_instance3d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/decal.hpp>
using namespace godot;

static void decal_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Decal"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef decal_class_def = {
    "Decal",
    decal_class_finalizer
};

static JSValue decal_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["Decal"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    Decal *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<Decal *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(Decal);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue decal_class_set_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Decal::set_size, ctx, this_val, argc, argv);
};
static JSValue decal_class_get_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector3> *proxy = memnew(ObjectProxy<Vector3>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector3 {
		Decal *obj = static_cast<Decal *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_size();
	};
	proxy->setter = [this_val](const Vector3 &value) -> void {
		Decal *js_proxy = static_cast<Decal *>(VariantAdapter(this_val).get().operator Object *());
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
static JSValue decal_class_set_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Decal::set_texture, ctx, this_val, argc, argv);
};
static JSValue decal_class_get_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Decal::get_texture, ctx, this_val, argc, argv);
}
static JSValue decal_class_set_emission_energy(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Decal::set_emission_energy, ctx, this_val, argc, argv);
};
static JSValue decal_class_get_emission_energy(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Decal::get_emission_energy, ctx, this_val, argc, argv);
}
static JSValue decal_class_set_albedo_mix(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Decal::set_albedo_mix, ctx, this_val, argc, argv);
};
static JSValue decal_class_get_albedo_mix(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Decal::get_albedo_mix, ctx, this_val, argc, argv);
}
static JSValue decal_class_set_modulate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Decal::set_modulate, ctx, this_val, argc, argv);
};
static JSValue decal_class_get_modulate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		Decal *obj = static_cast<Decal *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_modulate();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		Decal *js_proxy = static_cast<Decal *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_modulate(value);
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
static JSValue decal_class_set_upper_fade(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Decal::set_upper_fade, ctx, this_val, argc, argv);
};
static JSValue decal_class_get_upper_fade(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Decal::get_upper_fade, ctx, this_val, argc, argv);
}
static JSValue decal_class_set_lower_fade(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Decal::set_lower_fade, ctx, this_val, argc, argv);
};
static JSValue decal_class_get_lower_fade(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Decal::get_lower_fade, ctx, this_val, argc, argv);
}
static JSValue decal_class_set_normal_fade(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Decal::set_normal_fade, ctx, this_val, argc, argv);
};
static JSValue decal_class_get_normal_fade(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Decal::get_normal_fade, ctx, this_val, argc, argv);
}
static JSValue decal_class_set_enable_distance_fade(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Decal::set_enable_distance_fade, ctx, this_val, argc, argv);
};
static JSValue decal_class_is_distance_fade_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Decal::is_distance_fade_enabled, ctx, this_val, argc, argv);
}
static JSValue decal_class_set_distance_fade_begin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Decal::set_distance_fade_begin, ctx, this_val, argc, argv);
};
static JSValue decal_class_get_distance_fade_begin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Decal::get_distance_fade_begin, ctx, this_val, argc, argv);
}
static JSValue decal_class_set_distance_fade_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Decal::set_distance_fade_length, ctx, this_val, argc, argv);
};
static JSValue decal_class_get_distance_fade_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Decal::get_distance_fade_length, ctx, this_val, argc, argv);
}
static JSValue decal_class_set_cull_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Decal::set_cull_mask, ctx, this_val, argc, argv);
};
static JSValue decal_class_get_cull_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Decal::get_cull_mask, ctx, this_val, argc, argv);
}

static JSValue decal_class_get_texture_albedo(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&Decal::get_texture, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue decal_class_set_texture_albedo(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&Decal::set_texture, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue decal_class_get_texture_normal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&Decal::get_texture, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue decal_class_set_texture_normal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&Decal::set_texture, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue decal_class_get_texture_orm(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&Decal::get_texture, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue decal_class_set_texture_orm(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&Decal::set_texture, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue decal_class_get_texture_emission(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&Decal::get_texture, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue decal_class_set_texture_emission(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&Decal::set_texture, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}


static const JSCFunctionListEntry decal_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_size", 1, &decal_class_set_size),
	JS_CFUNC_DEF("get_size", 0, &decal_class_get_size),
	JS_CFUNC_DEF("set_texture", 2, &decal_class_set_texture),
	JS_CFUNC_DEF("get_texture", 1, &decal_class_get_texture),
	JS_CFUNC_DEF("set_emission_energy", 1, &decal_class_set_emission_energy),
	JS_CFUNC_DEF("get_emission_energy", 0, &decal_class_get_emission_energy),
	JS_CFUNC_DEF("set_albedo_mix", 1, &decal_class_set_albedo_mix),
	JS_CFUNC_DEF("get_albedo_mix", 0, &decal_class_get_albedo_mix),
	JS_CFUNC_DEF("set_modulate", 1, &decal_class_set_modulate),
	JS_CFUNC_DEF("get_modulate", 0, &decal_class_get_modulate),
	JS_CFUNC_DEF("set_upper_fade", 1, &decal_class_set_upper_fade),
	JS_CFUNC_DEF("get_upper_fade", 0, &decal_class_get_upper_fade),
	JS_CFUNC_DEF("set_lower_fade", 1, &decal_class_set_lower_fade),
	JS_CFUNC_DEF("get_lower_fade", 0, &decal_class_get_lower_fade),
	JS_CFUNC_DEF("set_normal_fade", 1, &decal_class_set_normal_fade),
	JS_CFUNC_DEF("get_normal_fade", 0, &decal_class_get_normal_fade),
	JS_CFUNC_DEF("set_enable_distance_fade", 1, &decal_class_set_enable_distance_fade),
	JS_CFUNC_DEF("is_distance_fade_enabled", 0, &decal_class_is_distance_fade_enabled),
	JS_CFUNC_DEF("set_distance_fade_begin", 1, &decal_class_set_distance_fade_begin),
	JS_CFUNC_DEF("get_distance_fade_begin", 0, &decal_class_get_distance_fade_begin),
	JS_CFUNC_DEF("set_distance_fade_length", 1, &decal_class_set_distance_fade_length),
	JS_CFUNC_DEF("get_distance_fade_length", 0, &decal_class_get_distance_fade_length),
	JS_CFUNC_DEF("set_cull_mask", 1, &decal_class_set_cull_mask),
	JS_CFUNC_DEF("get_cull_mask", 0, &decal_class_get_cull_mask),
    JS_CFUNC_MAGIC_DEF("get_texture_normal", 0, &decal_class_get_texture_normal, 1),
    JS_CFUNC_MAGIC_DEF("set_texture_normal", 1, &decal_class_set_texture_normal, 1),
    JS_CFUNC_MAGIC_DEF("get_texture_orm", 0, &decal_class_get_texture_orm, 2),
    JS_CFUNC_MAGIC_DEF("set_texture_orm", 1, &decal_class_set_texture_orm, 2),
    JS_CFUNC_MAGIC_DEF("get_texture_emission", 0, &decal_class_get_texture_emission, 3),
    JS_CFUNC_MAGIC_DEF("set_texture_emission", 1, &decal_class_set_texture_emission, 3),
};




static void define_decal_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "size"),
        JS_NewCFunction(ctx, decal_class_get_size, "get_size", 0),
        JS_NewCFunction(ctx, decal_class_set_size, "set_size", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "texture_albedo"),
		JS_NewCFunctionMagic(ctx, decal_class_get_texture_albedo, "get_texture_albedo", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 0),
		JS_NewCFunctionMagic(ctx, decal_class_set_texture_albedo, "set_texture_albedo", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 0),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "texture_normal"),
		JS_NewCFunctionMagic(ctx, decal_class_get_texture_normal, "get_texture_normal", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 1),
		JS_NewCFunctionMagic(ctx, decal_class_set_texture_normal, "set_texture_normal", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 1),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "texture_orm"),
		JS_NewCFunctionMagic(ctx, decal_class_get_texture_orm, "get_texture_orm", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 2),
		JS_NewCFunctionMagic(ctx, decal_class_set_texture_orm, "set_texture_orm", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 2),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "texture_emission"),
		JS_NewCFunctionMagic(ctx, decal_class_get_texture_emission, "get_texture_emission", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 3),
		JS_NewCFunctionMagic(ctx, decal_class_set_texture_emission, "set_texture_emission", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 3),
		JS_PROP_GETSET
	);
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "emission_energy"),
        JS_NewCFunction(ctx, decal_class_get_emission_energy, "get_emission_energy", 0),
        JS_NewCFunction(ctx, decal_class_set_emission_energy, "set_emission_energy", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "modulate"),
        JS_NewCFunction(ctx, decal_class_get_modulate, "get_modulate", 0),
        JS_NewCFunction(ctx, decal_class_set_modulate, "set_modulate", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "albedo_mix"),
        JS_NewCFunction(ctx, decal_class_get_albedo_mix, "get_albedo_mix", 0),
        JS_NewCFunction(ctx, decal_class_set_albedo_mix, "set_albedo_mix", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "normal_fade"),
        JS_NewCFunction(ctx, decal_class_get_normal_fade, "get_normal_fade", 0),
        JS_NewCFunction(ctx, decal_class_set_normal_fade, "set_normal_fade", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "upper_fade"),
        JS_NewCFunction(ctx, decal_class_get_upper_fade, "get_upper_fade", 0),
        JS_NewCFunction(ctx, decal_class_set_upper_fade, "set_upper_fade", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "lower_fade"),
        JS_NewCFunction(ctx, decal_class_get_lower_fade, "get_lower_fade", 0),
        JS_NewCFunction(ctx, decal_class_set_lower_fade, "set_lower_fade", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "distance_fade_enabled"),
        JS_NewCFunction(ctx, decal_class_is_distance_fade_enabled, "is_distance_fade_enabled", 0),
        JS_NewCFunction(ctx, decal_class_set_enable_distance_fade, "set_enable_distance_fade", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "distance_fade_begin"),
        JS_NewCFunction(ctx, decal_class_get_distance_fade_begin, "get_distance_fade_begin", 0),
        JS_NewCFunction(ctx, decal_class_set_distance_fade_begin, "set_distance_fade_begin", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "distance_fade_length"),
        JS_NewCFunction(ctx, decal_class_get_distance_fade_length, "get_distance_fade_length", 0),
        JS_NewCFunction(ctx, decal_class_set_distance_fade_length, "set_distance_fade_length", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "cull_mask"),
        JS_NewCFunction(ctx, decal_class_get_cull_mask, "get_cull_mask", 0),
        JS_NewCFunction(ctx, decal_class_set_cull_mask, "set_cull_mask", 1),
        JS_PROP_GETSET
    );
}

static void define_decal_enum(JSContext *ctx, JSValue ctor) {
	JSValue DecalTexture_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, DecalTexture_obj, "TEXTURE_ALBEDO", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, DecalTexture_obj, "TEXTURE_NORMAL", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, DecalTexture_obj, "TEXTURE_ORM", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, DecalTexture_obj, "TEXTURE_EMISSION", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, DecalTexture_obj, "TEXTURE_MAX", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, ctor, "DecalTexture", DecalTexture_obj);
}

static int js_decal_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["Decal"] = class_id;
	classes_by_id[class_id] = "Decal";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &decal_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["VisualInstance3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_decal_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, decal_class_proto_funcs, _countof(decal_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, decal_class_constructor, "Decal", 0, JS_CFUNC_constructor, 0);
	define_decal_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "Decal", ctor);

	return 0;
}

JSModuleDef *_js_init_decal_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/visual_instance3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_decal_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Decal");
	return m;
}

JSModuleDef *js_init_decal_module(JSContext *ctx) {
	return _js_init_decal_module(ctx, "@godot/classes/decal");
}

void __register_decal() {
	js_init_decal_module(js_context());
}

void register_decal() {
	__register_decal();
}