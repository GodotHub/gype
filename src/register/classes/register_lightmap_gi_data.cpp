#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/classes/texture_layered.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/lightmap_gi_data.hpp>
using namespace godot;

static void lightmap_gi_data_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["LightmapGIData"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef lightmap_gi_data_class_def = {
    "LightmapGIData",
    lightmap_gi_data_class_finalizer
};

static JSValue lightmap_gi_data_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["LightmapGIData"];
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
        instance = memnew(LightmapGIData);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue lightmap_gi_data_class_set_lightmap_textures(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LightmapGIData::set_lightmap_textures, ctx, this_val, argc, argv);
};
static JSValue lightmap_gi_data_class_get_lightmap_textures(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LightmapGIData::get_lightmap_textures, ctx, this_val, argc, argv);
}
static JSValue lightmap_gi_data_class_set_shadowmask_textures(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LightmapGIData::set_shadowmask_textures, ctx, this_val, argc, argv);
};
static JSValue lightmap_gi_data_class_get_shadowmask_textures(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LightmapGIData::get_shadowmask_textures, ctx, this_val, argc, argv);
}
static JSValue lightmap_gi_data_class_set_uses_spherical_harmonics(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LightmapGIData::set_uses_spherical_harmonics, ctx, this_val, argc, argv);
};
static JSValue lightmap_gi_data_class_is_using_spherical_harmonics(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LightmapGIData::is_using_spherical_harmonics, ctx, this_val, argc, argv);
}
static JSValue lightmap_gi_data_class_add_user(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LightmapGIData::add_user, ctx, this_val, argc, argv);
};
static JSValue lightmap_gi_data_class_get_user_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LightmapGIData::get_user_count, ctx, this_val, argc, argv);
};
static JSValue lightmap_gi_data_class_get_user_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LightmapGIData::get_user_path, ctx, this_val, argc, argv);
};
static JSValue lightmap_gi_data_class_clear_users(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LightmapGIData::clear_users, ctx, this_val, argc, argv);
};
static JSValue lightmap_gi_data_class_set_light_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LightmapGIData::set_light_texture, ctx, this_val, argc, argv);
};
static JSValue lightmap_gi_data_class_get_light_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LightmapGIData::get_light_texture, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry lightmap_gi_data_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_lightmap_textures", 1, &lightmap_gi_data_class_set_lightmap_textures),
	JS_CFUNC_DEF("get_lightmap_textures", 0, &lightmap_gi_data_class_get_lightmap_textures),
	JS_CFUNC_DEF("set_shadowmask_textures", 1, &lightmap_gi_data_class_set_shadowmask_textures),
	JS_CFUNC_DEF("get_shadowmask_textures", 0, &lightmap_gi_data_class_get_shadowmask_textures),
	JS_CFUNC_DEF("set_uses_spherical_harmonics", 1, &lightmap_gi_data_class_set_uses_spherical_harmonics),
	JS_CFUNC_DEF("is_using_spherical_harmonics", 0, &lightmap_gi_data_class_is_using_spherical_harmonics),
	JS_CFUNC_DEF("add_user", 4, &lightmap_gi_data_class_add_user),
	JS_CFUNC_DEF("get_user_count", 0, &lightmap_gi_data_class_get_user_count),
	JS_CFUNC_DEF("get_user_path", 1, &lightmap_gi_data_class_get_user_path),
	JS_CFUNC_DEF("clear_users", 0, &lightmap_gi_data_class_clear_users),
	JS_CFUNC_DEF("set_light_texture", 1, &lightmap_gi_data_class_set_light_texture),
	JS_CFUNC_DEF("get_light_texture", 0, &lightmap_gi_data_class_get_light_texture),
};




static void define_lightmap_gi_data_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "lightmap_textures"),
        JS_NewCFunction(ctx, lightmap_gi_data_class_get_lightmap_textures, "get_lightmap_textures", 0),
        JS_NewCFunction(ctx, lightmap_gi_data_class_set_lightmap_textures, "set_lightmap_textures", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "shadowmask_textures"),
        JS_NewCFunction(ctx, lightmap_gi_data_class_get_shadowmask_textures, "get_shadowmask_textures", 0),
        JS_NewCFunction(ctx, lightmap_gi_data_class_set_shadowmask_textures, "set_shadowmask_textures", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "uses_spherical_harmonics"),
        JS_NewCFunction(ctx, lightmap_gi_data_class_is_using_spherical_harmonics, "is_using_spherical_harmonics", 0),
        JS_NewCFunction(ctx, lightmap_gi_data_class_set_uses_spherical_harmonics, "set_uses_spherical_harmonics", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "light_texture"),
        JS_NewCFunction(ctx, lightmap_gi_data_class_get_light_texture, "get_light_texture", 0),
        JS_NewCFunction(ctx, lightmap_gi_data_class_set_light_texture, "set_light_texture", 1),
        JS_PROP_GETSET
    );
}

static void define_lightmap_gi_data_enum(JSContext *ctx, JSValue ctor) {
	JSValue ShadowmaskMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, ShadowmaskMode_obj, "SHADOWMASK_MODE_NONE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, ShadowmaskMode_obj, "SHADOWMASK_MODE_REPLACE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ShadowmaskMode_obj, "SHADOWMASK_MODE_OVERLAY", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "ShadowmaskMode", ShadowmaskMode_obj);
}

static int js_lightmap_gi_data_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["LightmapGIData"] = class_id;
	classes_by_id[class_id] = "LightmapGIData";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &lightmap_gi_data_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_lightmap_gi_data_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, lightmap_gi_data_class_proto_funcs, _countof(lightmap_gi_data_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, lightmap_gi_data_class_constructor, "LightmapGIData", 0, JS_CFUNC_constructor, 0);
	define_lightmap_gi_data_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "LightmapGIData", ctor);
	ctor_list["LightmapGIData"] = ctor;

	return 0;
}

JSModuleDef *_js_init_lightmap_gi_data_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_lightmap_gi_data_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "LightmapGIData");
	return m;
}

JSModuleDef *js_init_lightmap_gi_data_module(JSContext *ctx) {
	return _js_init_lightmap_gi_data_module(ctx, "@godot/classes/lightmap_gi_data");
}

void __register_lightmap_gi_data() {
	js_init_lightmap_gi_data_module(js_context());
}

void register_lightmap_gi_data() {
	__register_lightmap_gi_data();
}