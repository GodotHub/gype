#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/render_scene_buffers_configuration.hpp>
using namespace godot;

static void render_scene_buffers_configuration_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["RenderSceneBuffersConfiguration"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef render_scene_buffers_configuration_class_def = {
    "RenderSceneBuffersConfiguration",
    render_scene_buffers_configuration_class_finalizer
};

static JSValue render_scene_buffers_configuration_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["RenderSceneBuffersConfiguration"];
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
        instance = memnew(RenderSceneBuffersConfiguration);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue render_scene_buffers_configuration_class_get_render_target(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<RID> *proxy = memnew(ObjectProxy<RID>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> RID {
		RenderSceneBuffersConfiguration *obj = static_cast<RenderSceneBuffersConfiguration *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_render_target();
	};
	proxy->setter = [this_val](const RID &value) -> void {
		RenderSceneBuffersConfiguration *js_proxy = static_cast<RenderSceneBuffersConfiguration *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_render_target(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["RIDProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "RIDProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue render_scene_buffers_configuration_class_set_render_target(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RenderSceneBuffersConfiguration::set_render_target, ctx, this_val, argc, argv);
};
static JSValue render_scene_buffers_configuration_class_get_internal_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2i> *proxy = memnew(ObjectProxy<Vector2i>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2i {
		RenderSceneBuffersConfiguration *obj = static_cast<RenderSceneBuffersConfiguration *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_internal_size();
	};
	proxy->setter = [this_val](const Vector2i &value) -> void {
		RenderSceneBuffersConfiguration *js_proxy = static_cast<RenderSceneBuffersConfiguration *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_internal_size(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2iProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2iProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue render_scene_buffers_configuration_class_set_internal_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RenderSceneBuffersConfiguration::set_internal_size, ctx, this_val, argc, argv);
};
static JSValue render_scene_buffers_configuration_class_get_target_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2i> *proxy = memnew(ObjectProxy<Vector2i>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2i {
		RenderSceneBuffersConfiguration *obj = static_cast<RenderSceneBuffersConfiguration *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_target_size();
	};
	proxy->setter = [this_val](const Vector2i &value) -> void {
		RenderSceneBuffersConfiguration *js_proxy = static_cast<RenderSceneBuffersConfiguration *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_target_size(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2iProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2iProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue render_scene_buffers_configuration_class_set_target_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RenderSceneBuffersConfiguration::set_target_size, ctx, this_val, argc, argv);
};
static JSValue render_scene_buffers_configuration_class_get_view_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RenderSceneBuffersConfiguration::get_view_count, ctx, this_val, argc, argv);
}
static JSValue render_scene_buffers_configuration_class_set_view_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RenderSceneBuffersConfiguration::set_view_count, ctx, this_val, argc, argv);
};
static JSValue render_scene_buffers_configuration_class_get_scaling_3d_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RenderSceneBuffersConfiguration::get_scaling_3d_mode, ctx, this_val, argc, argv);
}
static JSValue render_scene_buffers_configuration_class_set_scaling_3d_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RenderSceneBuffersConfiguration::set_scaling_3d_mode, ctx, this_val, argc, argv);
};
static JSValue render_scene_buffers_configuration_class_get_msaa_3d(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RenderSceneBuffersConfiguration::get_msaa_3d, ctx, this_val, argc, argv);
}
static JSValue render_scene_buffers_configuration_class_set_msaa_3d(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RenderSceneBuffersConfiguration::set_msaa_3d, ctx, this_val, argc, argv);
};
static JSValue render_scene_buffers_configuration_class_get_screen_space_aa(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RenderSceneBuffersConfiguration::get_screen_space_aa, ctx, this_val, argc, argv);
}
static JSValue render_scene_buffers_configuration_class_set_screen_space_aa(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RenderSceneBuffersConfiguration::set_screen_space_aa, ctx, this_val, argc, argv);
};
static JSValue render_scene_buffers_configuration_class_get_fsr_sharpness(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RenderSceneBuffersConfiguration::get_fsr_sharpness, ctx, this_val, argc, argv);
}
static JSValue render_scene_buffers_configuration_class_set_fsr_sharpness(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RenderSceneBuffersConfiguration::set_fsr_sharpness, ctx, this_val, argc, argv);
};
static JSValue render_scene_buffers_configuration_class_get_texture_mipmap_bias(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RenderSceneBuffersConfiguration::get_texture_mipmap_bias, ctx, this_val, argc, argv);
}
static JSValue render_scene_buffers_configuration_class_set_texture_mipmap_bias(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RenderSceneBuffersConfiguration::set_texture_mipmap_bias, ctx, this_val, argc, argv);
};
static JSValue render_scene_buffers_configuration_class_get_anisotropic_filtering_level(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RenderSceneBuffersConfiguration::get_anisotropic_filtering_level, ctx, this_val, argc, argv);
}
static JSValue render_scene_buffers_configuration_class_set_anisotropic_filtering_level(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RenderSceneBuffersConfiguration::set_anisotropic_filtering_level, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry render_scene_buffers_configuration_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_render_target", 0, &render_scene_buffers_configuration_class_get_render_target),
	JS_CFUNC_DEF("set_render_target", 1, &render_scene_buffers_configuration_class_set_render_target),
	JS_CFUNC_DEF("get_internal_size", 0, &render_scene_buffers_configuration_class_get_internal_size),
	JS_CFUNC_DEF("set_internal_size", 1, &render_scene_buffers_configuration_class_set_internal_size),
	JS_CFUNC_DEF("get_target_size", 0, &render_scene_buffers_configuration_class_get_target_size),
	JS_CFUNC_DEF("set_target_size", 1, &render_scene_buffers_configuration_class_set_target_size),
	JS_CFUNC_DEF("get_view_count", 0, &render_scene_buffers_configuration_class_get_view_count),
	JS_CFUNC_DEF("set_view_count", 1, &render_scene_buffers_configuration_class_set_view_count),
	JS_CFUNC_DEF("get_scaling_3d_mode", 0, &render_scene_buffers_configuration_class_get_scaling_3d_mode),
	JS_CFUNC_DEF("set_scaling_3d_mode", 1, &render_scene_buffers_configuration_class_set_scaling_3d_mode),
	JS_CFUNC_DEF("get_msaa_3d", 0, &render_scene_buffers_configuration_class_get_msaa_3d),
	JS_CFUNC_DEF("set_msaa_3d", 1, &render_scene_buffers_configuration_class_set_msaa_3d),
	JS_CFUNC_DEF("get_screen_space_aa", 0, &render_scene_buffers_configuration_class_get_screen_space_aa),
	JS_CFUNC_DEF("set_screen_space_aa", 1, &render_scene_buffers_configuration_class_set_screen_space_aa),
	JS_CFUNC_DEF("get_fsr_sharpness", 0, &render_scene_buffers_configuration_class_get_fsr_sharpness),
	JS_CFUNC_DEF("set_fsr_sharpness", 1, &render_scene_buffers_configuration_class_set_fsr_sharpness),
	JS_CFUNC_DEF("get_texture_mipmap_bias", 0, &render_scene_buffers_configuration_class_get_texture_mipmap_bias),
	JS_CFUNC_DEF("set_texture_mipmap_bias", 1, &render_scene_buffers_configuration_class_set_texture_mipmap_bias),
	JS_CFUNC_DEF("get_anisotropic_filtering_level", 0, &render_scene_buffers_configuration_class_get_anisotropic_filtering_level),
	JS_CFUNC_DEF("set_anisotropic_filtering_level", 1, &render_scene_buffers_configuration_class_set_anisotropic_filtering_level),
};




static void define_render_scene_buffers_configuration_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "render_target"),
        JS_NewCFunction(ctx, render_scene_buffers_configuration_class_get_render_target, "get_render_target", 0),
        JS_NewCFunction(ctx, render_scene_buffers_configuration_class_set_render_target, "set_render_target", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "internal_size"),
        JS_NewCFunction(ctx, render_scene_buffers_configuration_class_get_internal_size, "get_internal_size", 0),
        JS_NewCFunction(ctx, render_scene_buffers_configuration_class_set_internal_size, "set_internal_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "target_size"),
        JS_NewCFunction(ctx, render_scene_buffers_configuration_class_get_target_size, "get_target_size", 0),
        JS_NewCFunction(ctx, render_scene_buffers_configuration_class_set_target_size, "set_target_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "view_count"),
        JS_NewCFunction(ctx, render_scene_buffers_configuration_class_get_view_count, "get_view_count", 0),
        JS_NewCFunction(ctx, render_scene_buffers_configuration_class_set_view_count, "set_view_count", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "scaling_3d_mode"),
        JS_NewCFunction(ctx, render_scene_buffers_configuration_class_get_scaling_3d_mode, "get_scaling_3d_mode", 0),
        JS_NewCFunction(ctx, render_scene_buffers_configuration_class_set_scaling_3d_mode, "set_scaling_3d_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "msaa_3d"),
        JS_NewCFunction(ctx, render_scene_buffers_configuration_class_get_msaa_3d, "get_msaa_3d", 0),
        JS_NewCFunction(ctx, render_scene_buffers_configuration_class_set_msaa_3d, "set_msaa_3d", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "screen_space_aa"),
        JS_NewCFunction(ctx, render_scene_buffers_configuration_class_get_screen_space_aa, "get_screen_space_aa", 0),
        JS_NewCFunction(ctx, render_scene_buffers_configuration_class_set_screen_space_aa, "set_screen_space_aa", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "fsr_sharpness"),
        JS_NewCFunction(ctx, render_scene_buffers_configuration_class_get_fsr_sharpness, "get_fsr_sharpness", 0),
        JS_NewCFunction(ctx, render_scene_buffers_configuration_class_set_fsr_sharpness, "set_fsr_sharpness", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "texture_mipmap_bias"),
        JS_NewCFunction(ctx, render_scene_buffers_configuration_class_get_texture_mipmap_bias, "get_texture_mipmap_bias", 0),
        JS_NewCFunction(ctx, render_scene_buffers_configuration_class_set_texture_mipmap_bias, "set_texture_mipmap_bias", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "anisotropic_filtering_level"),
        JS_NewCFunction(ctx, render_scene_buffers_configuration_class_get_anisotropic_filtering_level, "get_anisotropic_filtering_level", 0),
        JS_NewCFunction(ctx, render_scene_buffers_configuration_class_set_anisotropic_filtering_level, "set_anisotropic_filtering_level", 1),
        JS_PROP_GETSET
    );
}

static void define_render_scene_buffers_configuration_enum(JSContext *ctx, JSValue ctor) {
}

static int js_render_scene_buffers_configuration_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["RenderSceneBuffersConfiguration"] = class_id;
	classes_by_id[class_id] = "RenderSceneBuffersConfiguration";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &render_scene_buffers_configuration_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_render_scene_buffers_configuration_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, render_scene_buffers_configuration_class_proto_funcs, _countof(render_scene_buffers_configuration_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, render_scene_buffers_configuration_class_constructor, "RenderSceneBuffersConfiguration", 0, JS_CFUNC_constructor, 0);
	define_render_scene_buffers_configuration_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "RenderSceneBuffersConfiguration", ctor);
	ctor_list["RenderSceneBuffersConfiguration"] = ctor;

	return 0;
}

JSModuleDef *_js_init_render_scene_buffers_configuration_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_render_scene_buffers_configuration_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "RenderSceneBuffersConfiguration");
	return m;
}

JSModuleDef *js_init_render_scene_buffers_configuration_module(JSContext *ctx) {
	return _js_init_render_scene_buffers_configuration_module(ctx, "@godot/classes/render_scene_buffers_configuration");
}

void __register_render_scene_buffers_configuration() {
	js_init_render_scene_buffers_configuration_module(js_context());
}

void register_render_scene_buffers_configuration() {
	__register_render_scene_buffers_configuration();
}