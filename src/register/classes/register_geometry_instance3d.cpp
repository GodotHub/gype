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
#include <godot_cpp/classes/geometry_instance3d.hpp>
using namespace godot;

static void geometry_instance3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["GeometryInstance3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef geometry_instance3d_class_def = {
    "GeometryInstance3D",
    geometry_instance3d_class_finalizer
};

static JSValue geometry_instance3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["GeometryInstance3D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    GeometryInstance3D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<GeometryInstance3D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(GeometryInstance3D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue geometry_instance3d_class_set_material_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GeometryInstance3D::set_material_override, ctx, this_val, argc, argv);
};
static JSValue geometry_instance3d_class_get_material_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GeometryInstance3D::get_material_override, ctx, this_val, argc, argv);
}
static JSValue geometry_instance3d_class_set_material_overlay(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GeometryInstance3D::set_material_overlay, ctx, this_val, argc, argv);
};
static JSValue geometry_instance3d_class_get_material_overlay(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GeometryInstance3D::get_material_overlay, ctx, this_val, argc, argv);
}
static JSValue geometry_instance3d_class_set_cast_shadows_setting(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GeometryInstance3D::set_cast_shadows_setting, ctx, this_val, argc, argv);
};
static JSValue geometry_instance3d_class_get_cast_shadows_setting(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GeometryInstance3D::get_cast_shadows_setting, ctx, this_val, argc, argv);
}
static JSValue geometry_instance3d_class_set_lod_bias(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GeometryInstance3D::set_lod_bias, ctx, this_val, argc, argv);
};
static JSValue geometry_instance3d_class_get_lod_bias(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GeometryInstance3D::get_lod_bias, ctx, this_val, argc, argv);
}
static JSValue geometry_instance3d_class_set_transparency(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GeometryInstance3D::set_transparency, ctx, this_val, argc, argv);
};
static JSValue geometry_instance3d_class_get_transparency(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GeometryInstance3D::get_transparency, ctx, this_val, argc, argv);
}
static JSValue geometry_instance3d_class_set_visibility_range_end_margin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GeometryInstance3D::set_visibility_range_end_margin, ctx, this_val, argc, argv);
};
static JSValue geometry_instance3d_class_get_visibility_range_end_margin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GeometryInstance3D::get_visibility_range_end_margin, ctx, this_val, argc, argv);
}
static JSValue geometry_instance3d_class_set_visibility_range_end(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GeometryInstance3D::set_visibility_range_end, ctx, this_val, argc, argv);
};
static JSValue geometry_instance3d_class_get_visibility_range_end(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GeometryInstance3D::get_visibility_range_end, ctx, this_val, argc, argv);
}
static JSValue geometry_instance3d_class_set_visibility_range_begin_margin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GeometryInstance3D::set_visibility_range_begin_margin, ctx, this_val, argc, argv);
};
static JSValue geometry_instance3d_class_get_visibility_range_begin_margin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GeometryInstance3D::get_visibility_range_begin_margin, ctx, this_val, argc, argv);
}
static JSValue geometry_instance3d_class_set_visibility_range_begin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GeometryInstance3D::set_visibility_range_begin, ctx, this_val, argc, argv);
};
static JSValue geometry_instance3d_class_get_visibility_range_begin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GeometryInstance3D::get_visibility_range_begin, ctx, this_val, argc, argv);
}
static JSValue geometry_instance3d_class_set_visibility_range_fade_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GeometryInstance3D::set_visibility_range_fade_mode, ctx, this_val, argc, argv);
};
static JSValue geometry_instance3d_class_get_visibility_range_fade_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GeometryInstance3D::get_visibility_range_fade_mode, ctx, this_val, argc, argv);
}
static JSValue geometry_instance3d_class_set_instance_shader_parameter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GeometryInstance3D::set_instance_shader_parameter, ctx, this_val, argc, argv);
};
static JSValue geometry_instance3d_class_get_instance_shader_parameter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GeometryInstance3D::get_instance_shader_parameter, ctx, this_val, argc, argv);
};
static JSValue geometry_instance3d_class_set_extra_cull_margin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GeometryInstance3D::set_extra_cull_margin, ctx, this_val, argc, argv);
};
static JSValue geometry_instance3d_class_get_extra_cull_margin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GeometryInstance3D::get_extra_cull_margin, ctx, this_val, argc, argv);
}
static JSValue geometry_instance3d_class_set_lightmap_texel_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GeometryInstance3D::set_lightmap_texel_scale, ctx, this_val, argc, argv);
};
static JSValue geometry_instance3d_class_get_lightmap_texel_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GeometryInstance3D::get_lightmap_texel_scale, ctx, this_val, argc, argv);
}
static JSValue geometry_instance3d_class_set_lightmap_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GeometryInstance3D::set_lightmap_scale, ctx, this_val, argc, argv);
};
static JSValue geometry_instance3d_class_get_lightmap_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GeometryInstance3D::get_lightmap_scale, ctx, this_val, argc, argv);
}
static JSValue geometry_instance3d_class_set_gi_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GeometryInstance3D::set_gi_mode, ctx, this_val, argc, argv);
};
static JSValue geometry_instance3d_class_get_gi_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GeometryInstance3D::get_gi_mode, ctx, this_val, argc, argv);
}
static JSValue geometry_instance3d_class_set_ignore_occlusion_culling(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GeometryInstance3D::set_ignore_occlusion_culling, ctx, this_val, argc, argv);
};
static JSValue geometry_instance3d_class_is_ignoring_occlusion_culling(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&GeometryInstance3D::is_ignoring_occlusion_culling, ctx, this_val, argc, argv);
}
static JSValue geometry_instance3d_class_set_custom_aabb(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GeometryInstance3D::set_custom_aabb, ctx, this_val, argc, argv);
};
static JSValue geometry_instance3d_class_get_custom_aabb(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<AABB> *proxy = memnew(ObjectProxy<AABB>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> AABB {
		GeometryInstance3D *obj = static_cast<GeometryInstance3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_custom_aabb();
	};
	proxy->setter = [this_val](const AABB &value) -> void {
		GeometryInstance3D *js_proxy = static_cast<GeometryInstance3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_custom_aabb(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["AABBProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "AABBProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}

static const JSCFunctionListEntry geometry_instance3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_material_override", 1, &geometry_instance3d_class_set_material_override),
	JS_CFUNC_DEF("get_material_override", 0, &geometry_instance3d_class_get_material_override),
	JS_CFUNC_DEF("set_material_overlay", 1, &geometry_instance3d_class_set_material_overlay),
	JS_CFUNC_DEF("get_material_overlay", 0, &geometry_instance3d_class_get_material_overlay),
	JS_CFUNC_DEF("set_cast_shadows_setting", 1, &geometry_instance3d_class_set_cast_shadows_setting),
	JS_CFUNC_DEF("get_cast_shadows_setting", 0, &geometry_instance3d_class_get_cast_shadows_setting),
	JS_CFUNC_DEF("set_lod_bias", 1, &geometry_instance3d_class_set_lod_bias),
	JS_CFUNC_DEF("get_lod_bias", 0, &geometry_instance3d_class_get_lod_bias),
	JS_CFUNC_DEF("set_transparency", 1, &geometry_instance3d_class_set_transparency),
	JS_CFUNC_DEF("get_transparency", 0, &geometry_instance3d_class_get_transparency),
	JS_CFUNC_DEF("set_visibility_range_end_margin", 1, &geometry_instance3d_class_set_visibility_range_end_margin),
	JS_CFUNC_DEF("get_visibility_range_end_margin", 0, &geometry_instance3d_class_get_visibility_range_end_margin),
	JS_CFUNC_DEF("set_visibility_range_end", 1, &geometry_instance3d_class_set_visibility_range_end),
	JS_CFUNC_DEF("get_visibility_range_end", 0, &geometry_instance3d_class_get_visibility_range_end),
	JS_CFUNC_DEF("set_visibility_range_begin_margin", 1, &geometry_instance3d_class_set_visibility_range_begin_margin),
	JS_CFUNC_DEF("get_visibility_range_begin_margin", 0, &geometry_instance3d_class_get_visibility_range_begin_margin),
	JS_CFUNC_DEF("set_visibility_range_begin", 1, &geometry_instance3d_class_set_visibility_range_begin),
	JS_CFUNC_DEF("get_visibility_range_begin", 0, &geometry_instance3d_class_get_visibility_range_begin),
	JS_CFUNC_DEF("set_visibility_range_fade_mode", 1, &geometry_instance3d_class_set_visibility_range_fade_mode),
	JS_CFUNC_DEF("get_visibility_range_fade_mode", 0, &geometry_instance3d_class_get_visibility_range_fade_mode),
	JS_CFUNC_DEF("set_instance_shader_parameter", 2, &geometry_instance3d_class_set_instance_shader_parameter),
	JS_CFUNC_DEF("get_instance_shader_parameter", 1, &geometry_instance3d_class_get_instance_shader_parameter),
	JS_CFUNC_DEF("set_extra_cull_margin", 1, &geometry_instance3d_class_set_extra_cull_margin),
	JS_CFUNC_DEF("get_extra_cull_margin", 0, &geometry_instance3d_class_get_extra_cull_margin),
	JS_CFUNC_DEF("set_lightmap_texel_scale", 1, &geometry_instance3d_class_set_lightmap_texel_scale),
	JS_CFUNC_DEF("get_lightmap_texel_scale", 0, &geometry_instance3d_class_get_lightmap_texel_scale),
	JS_CFUNC_DEF("set_lightmap_scale", 1, &geometry_instance3d_class_set_lightmap_scale),
	JS_CFUNC_DEF("get_lightmap_scale", 0, &geometry_instance3d_class_get_lightmap_scale),
	JS_CFUNC_DEF("set_gi_mode", 1, &geometry_instance3d_class_set_gi_mode),
	JS_CFUNC_DEF("get_gi_mode", 0, &geometry_instance3d_class_get_gi_mode),
	JS_CFUNC_DEF("set_ignore_occlusion_culling", 1, &geometry_instance3d_class_set_ignore_occlusion_culling),
	JS_CFUNC_DEF("is_ignoring_occlusion_culling", 0, &geometry_instance3d_class_is_ignoring_occlusion_culling),
	JS_CFUNC_DEF("set_custom_aabb", 1, &geometry_instance3d_class_set_custom_aabb),
	JS_CFUNC_DEF("get_custom_aabb", 0, &geometry_instance3d_class_get_custom_aabb),
};




static void define_geometry_instance3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "material_override"),
        JS_NewCFunction(ctx, geometry_instance3d_class_get_material_override, "get_material_override", 0),
        JS_NewCFunction(ctx, geometry_instance3d_class_set_material_override, "set_material_override", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "material_overlay"),
        JS_NewCFunction(ctx, geometry_instance3d_class_get_material_overlay, "get_material_overlay", 0),
        JS_NewCFunction(ctx, geometry_instance3d_class_set_material_overlay, "set_material_overlay", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "transparency"),
        JS_NewCFunction(ctx, geometry_instance3d_class_get_transparency, "get_transparency", 0),
        JS_NewCFunction(ctx, geometry_instance3d_class_set_transparency, "set_transparency", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "cast_shadow"),
        JS_NewCFunction(ctx, geometry_instance3d_class_get_cast_shadows_setting, "get_cast_shadows_setting", 0),
        JS_NewCFunction(ctx, geometry_instance3d_class_set_cast_shadows_setting, "set_cast_shadows_setting", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "extra_cull_margin"),
        JS_NewCFunction(ctx, geometry_instance3d_class_get_extra_cull_margin, "get_extra_cull_margin", 0),
        JS_NewCFunction(ctx, geometry_instance3d_class_set_extra_cull_margin, "set_extra_cull_margin", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "custom_aabb"),
        JS_NewCFunction(ctx, geometry_instance3d_class_get_custom_aabb, "get_custom_aabb", 0),
        JS_NewCFunction(ctx, geometry_instance3d_class_set_custom_aabb, "set_custom_aabb", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "lod_bias"),
        JS_NewCFunction(ctx, geometry_instance3d_class_get_lod_bias, "get_lod_bias", 0),
        JS_NewCFunction(ctx, geometry_instance3d_class_set_lod_bias, "set_lod_bias", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "ignore_occlusion_culling"),
        JS_NewCFunction(ctx, geometry_instance3d_class_is_ignoring_occlusion_culling, "is_ignoring_occlusion_culling", 0),
        JS_NewCFunction(ctx, geometry_instance3d_class_set_ignore_occlusion_culling, "set_ignore_occlusion_culling", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "gi_mode"),
        JS_NewCFunction(ctx, geometry_instance3d_class_get_gi_mode, "get_gi_mode", 0),
        JS_NewCFunction(ctx, geometry_instance3d_class_set_gi_mode, "set_gi_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "gi_lightmap_texel_scale"),
        JS_NewCFunction(ctx, geometry_instance3d_class_get_lightmap_texel_scale, "get_lightmap_texel_scale", 0),
        JS_NewCFunction(ctx, geometry_instance3d_class_set_lightmap_texel_scale, "set_lightmap_texel_scale", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "gi_lightmap_scale"),
        JS_NewCFunction(ctx, geometry_instance3d_class_get_lightmap_scale, "get_lightmap_scale", 0),
        JS_NewCFunction(ctx, geometry_instance3d_class_set_lightmap_scale, "set_lightmap_scale", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "visibility_range_begin"),
        JS_NewCFunction(ctx, geometry_instance3d_class_get_visibility_range_begin, "get_visibility_range_begin", 0),
        JS_NewCFunction(ctx, geometry_instance3d_class_set_visibility_range_begin, "set_visibility_range_begin", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "visibility_range_begin_margin"),
        JS_NewCFunction(ctx, geometry_instance3d_class_get_visibility_range_begin_margin, "get_visibility_range_begin_margin", 0),
        JS_NewCFunction(ctx, geometry_instance3d_class_set_visibility_range_begin_margin, "set_visibility_range_begin_margin", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "visibility_range_end"),
        JS_NewCFunction(ctx, geometry_instance3d_class_get_visibility_range_end, "get_visibility_range_end", 0),
        JS_NewCFunction(ctx, geometry_instance3d_class_set_visibility_range_end, "set_visibility_range_end", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "visibility_range_end_margin"),
        JS_NewCFunction(ctx, geometry_instance3d_class_get_visibility_range_end_margin, "get_visibility_range_end_margin", 0),
        JS_NewCFunction(ctx, geometry_instance3d_class_set_visibility_range_end_margin, "set_visibility_range_end_margin", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "visibility_range_fade_mode"),
        JS_NewCFunction(ctx, geometry_instance3d_class_get_visibility_range_fade_mode, "get_visibility_range_fade_mode", 0),
        JS_NewCFunction(ctx, geometry_instance3d_class_set_visibility_range_fade_mode, "set_visibility_range_fade_mode", 1),
        JS_PROP_GETSET
    );
}

static void define_geometry_instance3d_enum(JSContext *ctx, JSValue proto) {
	JSValue ShadowCastingSetting_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, ShadowCastingSetting_obj, "SHADOW_CASTING_SETTING_OFF", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, ShadowCastingSetting_obj, "SHADOW_CASTING_SETTING_ON", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ShadowCastingSetting_obj, "SHADOW_CASTING_SETTING_DOUBLE_SIDED", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ShadowCastingSetting_obj, "SHADOW_CASTING_SETTING_SHADOWS_ONLY", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, proto, "ShadowCastingSetting", ShadowCastingSetting_obj);
	JSValue GIMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, GIMode_obj, "GI_MODE_DISABLED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, GIMode_obj, "GI_MODE_STATIC", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, GIMode_obj, "GI_MODE_DYNAMIC", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, proto, "GIMode", GIMode_obj);
	JSValue LightmapScale_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, LightmapScale_obj, "LIGHTMAP_SCALE_1X", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, LightmapScale_obj, "LIGHTMAP_SCALE_2X", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, LightmapScale_obj, "LIGHTMAP_SCALE_4X", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, LightmapScale_obj, "LIGHTMAP_SCALE_8X", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, LightmapScale_obj, "LIGHTMAP_SCALE_MAX", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, proto, "LightmapScale", LightmapScale_obj);
	JSValue VisibilityRangeFadeMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, VisibilityRangeFadeMode_obj, "VISIBILITY_RANGE_FADE_DISABLED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, VisibilityRangeFadeMode_obj, "VISIBILITY_RANGE_FADE_SELF", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, VisibilityRangeFadeMode_obj, "VISIBILITY_RANGE_FADE_DEPENDENCIES", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, proto, "VisibilityRangeFadeMode", VisibilityRangeFadeMode_obj);
}

static int js_geometry_instance3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["GeometryInstance3D"] = class_id;
	classes_by_id[class_id] = "GeometryInstance3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &geometry_instance3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["VisualInstance3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_geometry_instance3d_property(ctx, proto);
	define_geometry_instance3d_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, geometry_instance3d_class_proto_funcs, _countof(geometry_instance3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, geometry_instance3d_class_constructor, "GeometryInstance3D", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "GeometryInstance3D", ctor);

	return 0;
}

JSModuleDef *_js_init_geometry_instance3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/visual_instance3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_geometry_instance3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "GeometryInstance3D");
	return m;
}

JSModuleDef *js_init_geometry_instance3d_module(JSContext *ctx) {
	return _js_init_geometry_instance3d_module(ctx, "@godot/classes/geometry_instance3d");
}

void __register_geometry_instance3d() {
	js_init_geometry_instance3d_module(js_context());
}

void register_geometry_instance3d() {
	__register_geometry_instance3d();
}