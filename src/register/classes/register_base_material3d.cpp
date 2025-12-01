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
#include <godot_cpp/classes/base_material3d.hpp>
using namespace godot;

static void base_material3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["BaseMaterial3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef base_material3d_class_def = {
    "BaseMaterial3D",
    base_material3d_class_finalizer
};

static JSValue base_material3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["BaseMaterial3D"];
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
        instance = memnew(BaseMaterial3D);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue base_material3d_class_set_albedo(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_albedo, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_albedo(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		BaseMaterial3D *obj = static_cast<BaseMaterial3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_albedo();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		BaseMaterial3D *js_proxy = static_cast<BaseMaterial3D *>(VariantAdapter(this_val).get().operator Object *());
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
static JSValue base_material3d_class_set_transparency(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_transparency, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_transparency(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_transparency, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_alpha_antialiasing(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_alpha_antialiasing, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_alpha_antialiasing(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_alpha_antialiasing, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_alpha_antialiasing_edge(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_alpha_antialiasing_edge, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_alpha_antialiasing_edge(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_alpha_antialiasing_edge, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_shading_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_shading_mode, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_shading_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_shading_mode, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_specular(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_specular, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_specular(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_specular, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_metallic(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_metallic, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_metallic(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_metallic, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_roughness(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_roughness, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_roughness(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_roughness, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_emission(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_emission, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_emission(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		BaseMaterial3D *obj = static_cast<BaseMaterial3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_emission();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		BaseMaterial3D *js_proxy = static_cast<BaseMaterial3D *>(VariantAdapter(this_val).get().operator Object *());
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
static JSValue base_material3d_class_set_emission_energy_multiplier(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_emission_energy_multiplier, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_emission_energy_multiplier(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_emission_energy_multiplier, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_emission_intensity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_emission_intensity, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_emission_intensity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_emission_intensity, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_normal_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_normal_scale, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_normal_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_normal_scale, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_rim(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_rim, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_rim(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_rim, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_rim_tint(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_rim_tint, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_rim_tint(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_rim_tint, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_clearcoat(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_clearcoat, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_clearcoat(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_clearcoat, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_clearcoat_roughness(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_clearcoat_roughness, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_clearcoat_roughness(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_clearcoat_roughness, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_anisotropy(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_anisotropy, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_anisotropy(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_anisotropy, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_heightmap_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_heightmap_scale, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_heightmap_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_heightmap_scale, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_subsurface_scattering_strength(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_subsurface_scattering_strength, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_subsurface_scattering_strength(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_subsurface_scattering_strength, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_transmittance_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_transmittance_color, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_transmittance_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		BaseMaterial3D *obj = static_cast<BaseMaterial3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_transmittance_color();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		BaseMaterial3D *js_proxy = static_cast<BaseMaterial3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_transmittance_color(value);
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
static JSValue base_material3d_class_set_transmittance_depth(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_transmittance_depth, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_transmittance_depth(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_transmittance_depth, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_transmittance_boost(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_transmittance_boost, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_transmittance_boost(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_transmittance_boost, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_backlight(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_backlight, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_backlight(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		BaseMaterial3D *obj = static_cast<BaseMaterial3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_backlight();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		BaseMaterial3D *js_proxy = static_cast<BaseMaterial3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_backlight(value);
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
static JSValue base_material3d_class_set_refraction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_refraction, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_refraction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_refraction, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_point_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_point_size, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_point_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_point_size, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_detail_uv(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_detail_uv, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_detail_uv(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_detail_uv, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_blend_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_blend_mode, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_blend_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_blend_mode, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_depth_draw_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_depth_draw_mode, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_depth_draw_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_depth_draw_mode, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_depth_test(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_depth_test, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_depth_test(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_depth_test, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_cull_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_cull_mode, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_cull_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_cull_mode, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_diffuse_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_diffuse_mode, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_diffuse_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_diffuse_mode, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_specular_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_specular_mode, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_specular_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_specular_mode, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_flag(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_flag, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_flag(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_flag, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_texture_filter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_texture_filter, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_texture_filter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_texture_filter, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_feature(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_feature, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_feature(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_feature, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_texture, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_texture, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_detail_blend_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_detail_blend_mode, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_detail_blend_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_detail_blend_mode, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_uv1_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_uv1_scale, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_uv1_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector3> *proxy = memnew(ObjectProxy<Vector3>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector3 {
		BaseMaterial3D *obj = static_cast<BaseMaterial3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_uv1_scale();
	};
	proxy->setter = [this_val](const Vector3 &value) -> void {
		BaseMaterial3D *js_proxy = static_cast<BaseMaterial3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_uv1_scale(value);
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
static JSValue base_material3d_class_set_uv1_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_uv1_offset, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_uv1_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector3> *proxy = memnew(ObjectProxy<Vector3>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector3 {
		BaseMaterial3D *obj = static_cast<BaseMaterial3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_uv1_offset();
	};
	proxy->setter = [this_val](const Vector3 &value) -> void {
		BaseMaterial3D *js_proxy = static_cast<BaseMaterial3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_uv1_offset(value);
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
static JSValue base_material3d_class_set_uv1_triplanar_blend_sharpness(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_uv1_triplanar_blend_sharpness, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_uv1_triplanar_blend_sharpness(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_uv1_triplanar_blend_sharpness, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_uv2_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_uv2_scale, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_uv2_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector3> *proxy = memnew(ObjectProxy<Vector3>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector3 {
		BaseMaterial3D *obj = static_cast<BaseMaterial3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_uv2_scale();
	};
	proxy->setter = [this_val](const Vector3 &value) -> void {
		BaseMaterial3D *js_proxy = static_cast<BaseMaterial3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_uv2_scale(value);
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
static JSValue base_material3d_class_set_uv2_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_uv2_offset, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_uv2_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector3> *proxy = memnew(ObjectProxy<Vector3>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector3 {
		BaseMaterial3D *obj = static_cast<BaseMaterial3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_uv2_offset();
	};
	proxy->setter = [this_val](const Vector3 &value) -> void {
		BaseMaterial3D *js_proxy = static_cast<BaseMaterial3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_uv2_offset(value);
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
static JSValue base_material3d_class_set_uv2_triplanar_blend_sharpness(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_uv2_triplanar_blend_sharpness, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_uv2_triplanar_blend_sharpness(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_uv2_triplanar_blend_sharpness, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_billboard_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_billboard_mode, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_billboard_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_billboard_mode, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_particles_anim_h_frames(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_particles_anim_h_frames, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_particles_anim_h_frames(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_particles_anim_h_frames, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_particles_anim_v_frames(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_particles_anim_v_frames, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_particles_anim_v_frames(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_particles_anim_v_frames, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_particles_anim_loop(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_particles_anim_loop, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_particles_anim_loop(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_particles_anim_loop, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_heightmap_deep_parallax(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_heightmap_deep_parallax, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_is_heightmap_deep_parallax_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::is_heightmap_deep_parallax_enabled, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_heightmap_deep_parallax_min_layers(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_heightmap_deep_parallax_min_layers, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_heightmap_deep_parallax_min_layers(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_heightmap_deep_parallax_min_layers, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_heightmap_deep_parallax_max_layers(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_heightmap_deep_parallax_max_layers, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_heightmap_deep_parallax_max_layers(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_heightmap_deep_parallax_max_layers, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_heightmap_deep_parallax_flip_tangent(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_heightmap_deep_parallax_flip_tangent, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_heightmap_deep_parallax_flip_tangent(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_heightmap_deep_parallax_flip_tangent, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_heightmap_deep_parallax_flip_binormal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_heightmap_deep_parallax_flip_binormal, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_heightmap_deep_parallax_flip_binormal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_heightmap_deep_parallax_flip_binormal, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_grow(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_grow, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_grow(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_grow, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_emission_operator(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_emission_operator, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_emission_operator(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_emission_operator, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_ao_light_affect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_ao_light_affect, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_ao_light_affect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_ao_light_affect, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_alpha_scissor_threshold(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_alpha_scissor_threshold, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_alpha_scissor_threshold(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_alpha_scissor_threshold, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_alpha_hash_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_alpha_hash_scale, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_alpha_hash_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_alpha_hash_scale, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_grow_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_grow_enabled, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_is_grow_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::is_grow_enabled, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_metallic_texture_channel(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_metallic_texture_channel, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_metallic_texture_channel(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_metallic_texture_channel, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_roughness_texture_channel(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_roughness_texture_channel, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_roughness_texture_channel(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_roughness_texture_channel, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_ao_texture_channel(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_ao_texture_channel, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_ao_texture_channel(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_ao_texture_channel, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_refraction_texture_channel(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_refraction_texture_channel, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_refraction_texture_channel(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_refraction_texture_channel, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_proximity_fade_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_proximity_fade_enabled, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_is_proximity_fade_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::is_proximity_fade_enabled, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_proximity_fade_distance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_proximity_fade_distance, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_proximity_fade_distance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_proximity_fade_distance, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_msdf_pixel_range(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_msdf_pixel_range, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_msdf_pixel_range(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_msdf_pixel_range, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_msdf_outline_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_msdf_outline_size, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_msdf_outline_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_msdf_outline_size, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_distance_fade(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_distance_fade, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_distance_fade(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_distance_fade, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_distance_fade_max_distance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_distance_fade_max_distance, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_distance_fade_max_distance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_distance_fade_max_distance, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_distance_fade_min_distance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_distance_fade_min_distance, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_distance_fade_min_distance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_distance_fade_min_distance, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_z_clip_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_z_clip_scale, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_z_clip_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_z_clip_scale, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_fov_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_fov_override, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_fov_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_fov_override, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_stencil_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_stencil_mode, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_stencil_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_stencil_mode, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_stencil_flags(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_stencil_flags, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_stencil_flags(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_stencil_flags, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_stencil_compare(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_stencil_compare, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_stencil_compare(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_stencil_compare, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_stencil_reference(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_stencil_reference, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_stencil_reference(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_stencil_reference, ctx, this_val, argc, argv);
}
static JSValue base_material3d_class_set_stencil_effect_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_stencil_effect_color, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_stencil_effect_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		BaseMaterial3D *obj = static_cast<BaseMaterial3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_stencil_effect_color();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		BaseMaterial3D *js_proxy = static_cast<BaseMaterial3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_stencil_effect_color(value);
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
static JSValue base_material3d_class_set_stencil_effect_outline_thickness(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BaseMaterial3D::set_stencil_effect_outline_thickness, ctx, this_val, argc, argv);
};
static JSValue base_material3d_class_get_stencil_effect_outline_thickness(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BaseMaterial3D::get_stencil_effect_outline_thickness, ctx, this_val, argc, argv);
}

static JSValue base_material3d_class_get_no_depth_test(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_flag, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_no_depth_test(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_flag, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_disable_ambient_light(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_flag, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_disable_ambient_light(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_flag, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_disable_fog(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_flag, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_disable_fog(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_flag, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_disable_specular_occlusion(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_flag, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_disable_specular_occlusion(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_flag, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_vertex_color_use_as_albedo(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_flag, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_vertex_color_use_as_albedo(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_flag, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_vertex_color_is_srgb(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_flag, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_vertex_color_is_srgb(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_flag, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_albedo_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_texture, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_albedo_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_texture, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_albedo_texture_force_srgb(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_flag, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_albedo_texture_force_srgb(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_flag, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_albedo_texture_msdf(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_flag, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_albedo_texture_msdf(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_flag, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_orm_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_texture, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_orm_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_texture, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_metallic_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_texture, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_metallic_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_texture, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_roughness_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_texture, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_roughness_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_texture, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_emission_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_feature, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_emission_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_feature, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_emission_on_uv2(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_flag, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_emission_on_uv2(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_flag, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_emission_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_texture, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_emission_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_texture, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_normal_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_feature, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_normal_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_feature, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_normal_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_texture, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_normal_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_texture, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_bent_normal_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_feature, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_bent_normal_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_feature, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_bent_normal_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_texture, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_bent_normal_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_texture, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_rim_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_feature, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_rim_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_feature, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_rim_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_texture, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_rim_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_texture, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_clearcoat_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_feature, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_clearcoat_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_feature, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_clearcoat_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_texture, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_clearcoat_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_texture, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_anisotropy_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_feature, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_anisotropy_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_feature, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_anisotropy_flowmap(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_texture, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_anisotropy_flowmap(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_texture, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_ao_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_feature, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_ao_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_feature, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_ao_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_texture, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_ao_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_texture, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_ao_on_uv2(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_flag, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_ao_on_uv2(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_flag, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_heightmap_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_feature, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_heightmap_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_feature, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_heightmap_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_texture, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_heightmap_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_texture, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_heightmap_flip_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_flag, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_heightmap_flip_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_flag, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_subsurf_scatter_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_feature, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_subsurf_scatter_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_feature, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_subsurf_scatter_skin_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_flag, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_subsurf_scatter_skin_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_flag, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_subsurf_scatter_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_texture, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_subsurf_scatter_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_texture, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_subsurf_scatter_transmittance_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_feature, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_subsurf_scatter_transmittance_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_feature, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_subsurf_scatter_transmittance_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_texture, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_subsurf_scatter_transmittance_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_texture, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_backlight_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_feature, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_backlight_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_feature, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_backlight_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_texture, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_backlight_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_texture, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_refraction_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_feature, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_refraction_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_feature, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_refraction_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_texture, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_refraction_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_texture, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_detail_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_feature, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_detail_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_feature, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_detail_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_texture, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_detail_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_texture, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_detail_albedo(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_texture, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_detail_albedo(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_texture, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_detail_normal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_texture, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_detail_normal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_texture, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_uv1_triplanar(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_flag, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_uv1_triplanar(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_flag, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_uv1_world_triplanar(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_flag, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_uv1_world_triplanar(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_flag, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_uv2_triplanar(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_flag, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_uv2_triplanar(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_flag, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_uv2_world_triplanar(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_flag, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_uv2_world_triplanar(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_flag, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_texture_repeat(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_flag, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_texture_repeat(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_flag, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_disable_receive_shadows(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_flag, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_disable_receive_shadows(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_flag, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_shadow_to_opacity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_flag, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_shadow_to_opacity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_flag, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_billboard_keep_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_flag, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_billboard_keep_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_flag, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_fixed_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_flag, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_fixed_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_flag, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_use_point_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_flag, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_use_point_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_flag, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_use_particle_trails(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_flag, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_use_particle_trails(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_flag, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_use_z_clip_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_flag, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_use_z_clip_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_flag, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue base_material3d_class_get_use_fov_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&BaseMaterial3D::get_flag, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue base_material3d_class_set_use_fov_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&BaseMaterial3D::set_flag, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}


static const JSCFunctionListEntry base_material3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_albedo", 1, &base_material3d_class_set_albedo),
	JS_CFUNC_DEF("get_albedo", 0, &base_material3d_class_get_albedo),
	JS_CFUNC_DEF("set_transparency", 1, &base_material3d_class_set_transparency),
	JS_CFUNC_DEF("get_transparency", 0, &base_material3d_class_get_transparency),
	JS_CFUNC_DEF("set_alpha_antialiasing", 1, &base_material3d_class_set_alpha_antialiasing),
	JS_CFUNC_DEF("get_alpha_antialiasing", 0, &base_material3d_class_get_alpha_antialiasing),
	JS_CFUNC_DEF("set_alpha_antialiasing_edge", 1, &base_material3d_class_set_alpha_antialiasing_edge),
	JS_CFUNC_DEF("get_alpha_antialiasing_edge", 0, &base_material3d_class_get_alpha_antialiasing_edge),
	JS_CFUNC_DEF("set_shading_mode", 1, &base_material3d_class_set_shading_mode),
	JS_CFUNC_DEF("get_shading_mode", 0, &base_material3d_class_get_shading_mode),
	JS_CFUNC_DEF("set_specular", 1, &base_material3d_class_set_specular),
	JS_CFUNC_DEF("get_specular", 0, &base_material3d_class_get_specular),
	JS_CFUNC_DEF("set_metallic", 1, &base_material3d_class_set_metallic),
	JS_CFUNC_DEF("get_metallic", 0, &base_material3d_class_get_metallic),
	JS_CFUNC_DEF("set_roughness", 1, &base_material3d_class_set_roughness),
	JS_CFUNC_DEF("get_roughness", 0, &base_material3d_class_get_roughness),
	JS_CFUNC_DEF("set_emission", 1, &base_material3d_class_set_emission),
	JS_CFUNC_DEF("get_emission", 0, &base_material3d_class_get_emission),
	JS_CFUNC_DEF("set_emission_energy_multiplier", 1, &base_material3d_class_set_emission_energy_multiplier),
	JS_CFUNC_DEF("get_emission_energy_multiplier", 0, &base_material3d_class_get_emission_energy_multiplier),
	JS_CFUNC_DEF("set_emission_intensity", 1, &base_material3d_class_set_emission_intensity),
	JS_CFUNC_DEF("get_emission_intensity", 0, &base_material3d_class_get_emission_intensity),
	JS_CFUNC_DEF("set_normal_scale", 1, &base_material3d_class_set_normal_scale),
	JS_CFUNC_DEF("get_normal_scale", 0, &base_material3d_class_get_normal_scale),
	JS_CFUNC_DEF("set_rim", 1, &base_material3d_class_set_rim),
	JS_CFUNC_DEF("get_rim", 0, &base_material3d_class_get_rim),
	JS_CFUNC_DEF("set_rim_tint", 1, &base_material3d_class_set_rim_tint),
	JS_CFUNC_DEF("get_rim_tint", 0, &base_material3d_class_get_rim_tint),
	JS_CFUNC_DEF("set_clearcoat", 1, &base_material3d_class_set_clearcoat),
	JS_CFUNC_DEF("get_clearcoat", 0, &base_material3d_class_get_clearcoat),
	JS_CFUNC_DEF("set_clearcoat_roughness", 1, &base_material3d_class_set_clearcoat_roughness),
	JS_CFUNC_DEF("get_clearcoat_roughness", 0, &base_material3d_class_get_clearcoat_roughness),
	JS_CFUNC_DEF("set_anisotropy", 1, &base_material3d_class_set_anisotropy),
	JS_CFUNC_DEF("get_anisotropy", 0, &base_material3d_class_get_anisotropy),
	JS_CFUNC_DEF("set_heightmap_scale", 1, &base_material3d_class_set_heightmap_scale),
	JS_CFUNC_DEF("get_heightmap_scale", 0, &base_material3d_class_get_heightmap_scale),
	JS_CFUNC_DEF("set_subsurface_scattering_strength", 1, &base_material3d_class_set_subsurface_scattering_strength),
	JS_CFUNC_DEF("get_subsurface_scattering_strength", 0, &base_material3d_class_get_subsurface_scattering_strength),
	JS_CFUNC_DEF("set_transmittance_color", 1, &base_material3d_class_set_transmittance_color),
	JS_CFUNC_DEF("get_transmittance_color", 0, &base_material3d_class_get_transmittance_color),
	JS_CFUNC_DEF("set_transmittance_depth", 1, &base_material3d_class_set_transmittance_depth),
	JS_CFUNC_DEF("get_transmittance_depth", 0, &base_material3d_class_get_transmittance_depth),
	JS_CFUNC_DEF("set_transmittance_boost", 1, &base_material3d_class_set_transmittance_boost),
	JS_CFUNC_DEF("get_transmittance_boost", 0, &base_material3d_class_get_transmittance_boost),
	JS_CFUNC_DEF("set_backlight", 1, &base_material3d_class_set_backlight),
	JS_CFUNC_DEF("get_backlight", 0, &base_material3d_class_get_backlight),
	JS_CFUNC_DEF("set_refraction", 1, &base_material3d_class_set_refraction),
	JS_CFUNC_DEF("get_refraction", 0, &base_material3d_class_get_refraction),
	JS_CFUNC_DEF("set_point_size", 1, &base_material3d_class_set_point_size),
	JS_CFUNC_DEF("get_point_size", 0, &base_material3d_class_get_point_size),
	JS_CFUNC_DEF("set_detail_uv", 1, &base_material3d_class_set_detail_uv),
	JS_CFUNC_DEF("get_detail_uv", 0, &base_material3d_class_get_detail_uv),
	JS_CFUNC_DEF("set_blend_mode", 1, &base_material3d_class_set_blend_mode),
	JS_CFUNC_DEF("get_blend_mode", 0, &base_material3d_class_get_blend_mode),
	JS_CFUNC_DEF("set_depth_draw_mode", 1, &base_material3d_class_set_depth_draw_mode),
	JS_CFUNC_DEF("get_depth_draw_mode", 0, &base_material3d_class_get_depth_draw_mode),
	JS_CFUNC_DEF("set_depth_test", 1, &base_material3d_class_set_depth_test),
	JS_CFUNC_DEF("get_depth_test", 0, &base_material3d_class_get_depth_test),
	JS_CFUNC_DEF("set_cull_mode", 1, &base_material3d_class_set_cull_mode),
	JS_CFUNC_DEF("get_cull_mode", 0, &base_material3d_class_get_cull_mode),
	JS_CFUNC_DEF("set_diffuse_mode", 1, &base_material3d_class_set_diffuse_mode),
	JS_CFUNC_DEF("get_diffuse_mode", 0, &base_material3d_class_get_diffuse_mode),
	JS_CFUNC_DEF("set_specular_mode", 1, &base_material3d_class_set_specular_mode),
	JS_CFUNC_DEF("get_specular_mode", 0, &base_material3d_class_get_specular_mode),
	JS_CFUNC_DEF("set_flag", 2, &base_material3d_class_set_flag),
	JS_CFUNC_DEF("get_flag", 1, &base_material3d_class_get_flag),
	JS_CFUNC_DEF("set_texture_filter", 1, &base_material3d_class_set_texture_filter),
	JS_CFUNC_DEF("get_texture_filter", 0, &base_material3d_class_get_texture_filter),
	JS_CFUNC_DEF("set_feature", 2, &base_material3d_class_set_feature),
	JS_CFUNC_DEF("get_feature", 1, &base_material3d_class_get_feature),
	JS_CFUNC_DEF("set_texture", 2, &base_material3d_class_set_texture),
	JS_CFUNC_DEF("get_texture", 1, &base_material3d_class_get_texture),
	JS_CFUNC_DEF("set_detail_blend_mode", 1, &base_material3d_class_set_detail_blend_mode),
	JS_CFUNC_DEF("get_detail_blend_mode", 0, &base_material3d_class_get_detail_blend_mode),
	JS_CFUNC_DEF("set_uv1_scale", 1, &base_material3d_class_set_uv1_scale),
	JS_CFUNC_DEF("get_uv1_scale", 0, &base_material3d_class_get_uv1_scale),
	JS_CFUNC_DEF("set_uv1_offset", 1, &base_material3d_class_set_uv1_offset),
	JS_CFUNC_DEF("get_uv1_offset", 0, &base_material3d_class_get_uv1_offset),
	JS_CFUNC_DEF("set_uv1_triplanar_blend_sharpness", 1, &base_material3d_class_set_uv1_triplanar_blend_sharpness),
	JS_CFUNC_DEF("get_uv1_triplanar_blend_sharpness", 0, &base_material3d_class_get_uv1_triplanar_blend_sharpness),
	JS_CFUNC_DEF("set_uv2_scale", 1, &base_material3d_class_set_uv2_scale),
	JS_CFUNC_DEF("get_uv2_scale", 0, &base_material3d_class_get_uv2_scale),
	JS_CFUNC_DEF("set_uv2_offset", 1, &base_material3d_class_set_uv2_offset),
	JS_CFUNC_DEF("get_uv2_offset", 0, &base_material3d_class_get_uv2_offset),
	JS_CFUNC_DEF("set_uv2_triplanar_blend_sharpness", 1, &base_material3d_class_set_uv2_triplanar_blend_sharpness),
	JS_CFUNC_DEF("get_uv2_triplanar_blend_sharpness", 0, &base_material3d_class_get_uv2_triplanar_blend_sharpness),
	JS_CFUNC_DEF("set_billboard_mode", 1, &base_material3d_class_set_billboard_mode),
	JS_CFUNC_DEF("get_billboard_mode", 0, &base_material3d_class_get_billboard_mode),
	JS_CFUNC_DEF("set_particles_anim_h_frames", 1, &base_material3d_class_set_particles_anim_h_frames),
	JS_CFUNC_DEF("get_particles_anim_h_frames", 0, &base_material3d_class_get_particles_anim_h_frames),
	JS_CFUNC_DEF("set_particles_anim_v_frames", 1, &base_material3d_class_set_particles_anim_v_frames),
	JS_CFUNC_DEF("get_particles_anim_v_frames", 0, &base_material3d_class_get_particles_anim_v_frames),
	JS_CFUNC_DEF("set_particles_anim_loop", 1, &base_material3d_class_set_particles_anim_loop),
	JS_CFUNC_DEF("get_particles_anim_loop", 0, &base_material3d_class_get_particles_anim_loop),
	JS_CFUNC_DEF("set_heightmap_deep_parallax", 1, &base_material3d_class_set_heightmap_deep_parallax),
	JS_CFUNC_DEF("is_heightmap_deep_parallax_enabled", 0, &base_material3d_class_is_heightmap_deep_parallax_enabled),
	JS_CFUNC_DEF("set_heightmap_deep_parallax_min_layers", 1, &base_material3d_class_set_heightmap_deep_parallax_min_layers),
	JS_CFUNC_DEF("get_heightmap_deep_parallax_min_layers", 0, &base_material3d_class_get_heightmap_deep_parallax_min_layers),
	JS_CFUNC_DEF("set_heightmap_deep_parallax_max_layers", 1, &base_material3d_class_set_heightmap_deep_parallax_max_layers),
	JS_CFUNC_DEF("get_heightmap_deep_parallax_max_layers", 0, &base_material3d_class_get_heightmap_deep_parallax_max_layers),
	JS_CFUNC_DEF("set_heightmap_deep_parallax_flip_tangent", 1, &base_material3d_class_set_heightmap_deep_parallax_flip_tangent),
	JS_CFUNC_DEF("get_heightmap_deep_parallax_flip_tangent", 0, &base_material3d_class_get_heightmap_deep_parallax_flip_tangent),
	JS_CFUNC_DEF("set_heightmap_deep_parallax_flip_binormal", 1, &base_material3d_class_set_heightmap_deep_parallax_flip_binormal),
	JS_CFUNC_DEF("get_heightmap_deep_parallax_flip_binormal", 0, &base_material3d_class_get_heightmap_deep_parallax_flip_binormal),
	JS_CFUNC_DEF("set_grow", 1, &base_material3d_class_set_grow),
	JS_CFUNC_DEF("get_grow", 0, &base_material3d_class_get_grow),
	JS_CFUNC_DEF("set_emission_operator", 1, &base_material3d_class_set_emission_operator),
	JS_CFUNC_DEF("get_emission_operator", 0, &base_material3d_class_get_emission_operator),
	JS_CFUNC_DEF("set_ao_light_affect", 1, &base_material3d_class_set_ao_light_affect),
	JS_CFUNC_DEF("get_ao_light_affect", 0, &base_material3d_class_get_ao_light_affect),
	JS_CFUNC_DEF("set_alpha_scissor_threshold", 1, &base_material3d_class_set_alpha_scissor_threshold),
	JS_CFUNC_DEF("get_alpha_scissor_threshold", 0, &base_material3d_class_get_alpha_scissor_threshold),
	JS_CFUNC_DEF("set_alpha_hash_scale", 1, &base_material3d_class_set_alpha_hash_scale),
	JS_CFUNC_DEF("get_alpha_hash_scale", 0, &base_material3d_class_get_alpha_hash_scale),
	JS_CFUNC_DEF("set_grow_enabled", 1, &base_material3d_class_set_grow_enabled),
	JS_CFUNC_DEF("is_grow_enabled", 0, &base_material3d_class_is_grow_enabled),
	JS_CFUNC_DEF("set_metallic_texture_channel", 1, &base_material3d_class_set_metallic_texture_channel),
	JS_CFUNC_DEF("get_metallic_texture_channel", 0, &base_material3d_class_get_metallic_texture_channel),
	JS_CFUNC_DEF("set_roughness_texture_channel", 1, &base_material3d_class_set_roughness_texture_channel),
	JS_CFUNC_DEF("get_roughness_texture_channel", 0, &base_material3d_class_get_roughness_texture_channel),
	JS_CFUNC_DEF("set_ao_texture_channel", 1, &base_material3d_class_set_ao_texture_channel),
	JS_CFUNC_DEF("get_ao_texture_channel", 0, &base_material3d_class_get_ao_texture_channel),
	JS_CFUNC_DEF("set_refraction_texture_channel", 1, &base_material3d_class_set_refraction_texture_channel),
	JS_CFUNC_DEF("get_refraction_texture_channel", 0, &base_material3d_class_get_refraction_texture_channel),
	JS_CFUNC_DEF("set_proximity_fade_enabled", 1, &base_material3d_class_set_proximity_fade_enabled),
	JS_CFUNC_DEF("is_proximity_fade_enabled", 0, &base_material3d_class_is_proximity_fade_enabled),
	JS_CFUNC_DEF("set_proximity_fade_distance", 1, &base_material3d_class_set_proximity_fade_distance),
	JS_CFUNC_DEF("get_proximity_fade_distance", 0, &base_material3d_class_get_proximity_fade_distance),
	JS_CFUNC_DEF("set_msdf_pixel_range", 1, &base_material3d_class_set_msdf_pixel_range),
	JS_CFUNC_DEF("get_msdf_pixel_range", 0, &base_material3d_class_get_msdf_pixel_range),
	JS_CFUNC_DEF("set_msdf_outline_size", 1, &base_material3d_class_set_msdf_outline_size),
	JS_CFUNC_DEF("get_msdf_outline_size", 0, &base_material3d_class_get_msdf_outline_size),
	JS_CFUNC_DEF("set_distance_fade", 1, &base_material3d_class_set_distance_fade),
	JS_CFUNC_DEF("get_distance_fade", 0, &base_material3d_class_get_distance_fade),
	JS_CFUNC_DEF("set_distance_fade_max_distance", 1, &base_material3d_class_set_distance_fade_max_distance),
	JS_CFUNC_DEF("get_distance_fade_max_distance", 0, &base_material3d_class_get_distance_fade_max_distance),
	JS_CFUNC_DEF("set_distance_fade_min_distance", 1, &base_material3d_class_set_distance_fade_min_distance),
	JS_CFUNC_DEF("get_distance_fade_min_distance", 0, &base_material3d_class_get_distance_fade_min_distance),
	JS_CFUNC_DEF("set_z_clip_scale", 1, &base_material3d_class_set_z_clip_scale),
	JS_CFUNC_DEF("get_z_clip_scale", 0, &base_material3d_class_get_z_clip_scale),
	JS_CFUNC_DEF("set_fov_override", 1, &base_material3d_class_set_fov_override),
	JS_CFUNC_DEF("get_fov_override", 0, &base_material3d_class_get_fov_override),
	JS_CFUNC_DEF("set_stencil_mode", 1, &base_material3d_class_set_stencil_mode),
	JS_CFUNC_DEF("get_stencil_mode", 0, &base_material3d_class_get_stencil_mode),
	JS_CFUNC_DEF("set_stencil_flags", 1, &base_material3d_class_set_stencil_flags),
	JS_CFUNC_DEF("get_stencil_flags", 0, &base_material3d_class_get_stencil_flags),
	JS_CFUNC_DEF("set_stencil_compare", 1, &base_material3d_class_set_stencil_compare),
	JS_CFUNC_DEF("get_stencil_compare", 0, &base_material3d_class_get_stencil_compare),
	JS_CFUNC_DEF("set_stencil_reference", 1, &base_material3d_class_set_stencil_reference),
	JS_CFUNC_DEF("get_stencil_reference", 0, &base_material3d_class_get_stencil_reference),
	JS_CFUNC_DEF("set_stencil_effect_color", 1, &base_material3d_class_set_stencil_effect_color),
	JS_CFUNC_DEF("get_stencil_effect_color", 0, &base_material3d_class_get_stencil_effect_color),
	JS_CFUNC_DEF("set_stencil_effect_outline_thickness", 1, &base_material3d_class_set_stencil_effect_outline_thickness),
	JS_CFUNC_DEF("get_stencil_effect_outline_thickness", 0, &base_material3d_class_get_stencil_effect_outline_thickness),
    JS_CFUNC_MAGIC_DEF("get_disable_ambient_light", 0, &base_material3d_class_get_disable_ambient_light, 14),
    JS_CFUNC_MAGIC_DEF("set_disable_ambient_light", 1, &base_material3d_class_set_disable_ambient_light, 14),
    JS_CFUNC_MAGIC_DEF("get_disable_fog", 0, &base_material3d_class_get_disable_fog, 21),
    JS_CFUNC_MAGIC_DEF("set_disable_fog", 1, &base_material3d_class_set_disable_fog, 21),
    JS_CFUNC_MAGIC_DEF("get_disable_specular_occlusion", 0, &base_material3d_class_get_disable_specular_occlusion, 22),
    JS_CFUNC_MAGIC_DEF("set_disable_specular_occlusion", 1, &base_material3d_class_set_disable_specular_occlusion, 22),
    JS_CFUNC_MAGIC_DEF("get_vertex_color_use_as_albedo", 0, &base_material3d_class_get_vertex_color_use_as_albedo, 1),
    JS_CFUNC_MAGIC_DEF("set_vertex_color_use_as_albedo", 1, &base_material3d_class_set_vertex_color_use_as_albedo, 1),
    JS_CFUNC_MAGIC_DEF("get_vertex_color_is_srgb", 0, &base_material3d_class_get_vertex_color_is_srgb, 2),
    JS_CFUNC_MAGIC_DEF("set_vertex_color_is_srgb", 1, &base_material3d_class_set_vertex_color_is_srgb, 2),
    JS_CFUNC_MAGIC_DEF("get_albedo_texture_force_srgb", 0, &base_material3d_class_get_albedo_texture_force_srgb, 12),
    JS_CFUNC_MAGIC_DEF("set_albedo_texture_force_srgb", 1, &base_material3d_class_set_albedo_texture_force_srgb, 12),
    JS_CFUNC_MAGIC_DEF("get_albedo_texture_msdf", 0, &base_material3d_class_get_albedo_texture_msdf, 20),
    JS_CFUNC_MAGIC_DEF("set_albedo_texture_msdf", 1, &base_material3d_class_set_albedo_texture_msdf, 20),
    JS_CFUNC_MAGIC_DEF("get_orm_texture", 0, &base_material3d_class_get_orm_texture, 17),
    JS_CFUNC_MAGIC_DEF("set_orm_texture", 1, &base_material3d_class_set_orm_texture, 17),
    JS_CFUNC_MAGIC_DEF("get_metallic_texture", 0, &base_material3d_class_get_metallic_texture, 1),
    JS_CFUNC_MAGIC_DEF("set_metallic_texture", 1, &base_material3d_class_set_metallic_texture, 1),
    JS_CFUNC_MAGIC_DEF("get_roughness_texture", 0, &base_material3d_class_get_roughness_texture, 2),
    JS_CFUNC_MAGIC_DEF("set_roughness_texture", 1, &base_material3d_class_set_roughness_texture, 2),
    JS_CFUNC_MAGIC_DEF("get_emission_on_uv2", 0, &base_material3d_class_get_emission_on_uv2, 11),
    JS_CFUNC_MAGIC_DEF("set_emission_on_uv2", 1, &base_material3d_class_set_emission_on_uv2, 11),
    JS_CFUNC_MAGIC_DEF("get_emission_texture", 0, &base_material3d_class_get_emission_texture, 3),
    JS_CFUNC_MAGIC_DEF("set_emission_texture", 1, &base_material3d_class_set_emission_texture, 3),
    JS_CFUNC_MAGIC_DEF("get_normal_enabled", 0, &base_material3d_class_get_normal_enabled, 1),
    JS_CFUNC_MAGIC_DEF("set_normal_enabled", 1, &base_material3d_class_set_normal_enabled, 1),
    JS_CFUNC_MAGIC_DEF("get_normal_texture", 0, &base_material3d_class_get_normal_texture, 4),
    JS_CFUNC_MAGIC_DEF("set_normal_texture", 1, &base_material3d_class_set_normal_texture, 4),
    JS_CFUNC_MAGIC_DEF("get_bent_normal_enabled", 0, &base_material3d_class_get_bent_normal_enabled, 12),
    JS_CFUNC_MAGIC_DEF("set_bent_normal_enabled", 1, &base_material3d_class_set_bent_normal_enabled, 12),
    JS_CFUNC_MAGIC_DEF("get_bent_normal_texture", 0, &base_material3d_class_get_bent_normal_texture, 18),
    JS_CFUNC_MAGIC_DEF("set_bent_normal_texture", 1, &base_material3d_class_set_bent_normal_texture, 18),
    JS_CFUNC_MAGIC_DEF("get_rim_enabled", 0, &base_material3d_class_get_rim_enabled, 2),
    JS_CFUNC_MAGIC_DEF("set_rim_enabled", 1, &base_material3d_class_set_rim_enabled, 2),
    JS_CFUNC_MAGIC_DEF("get_rim_texture", 0, &base_material3d_class_get_rim_texture, 5),
    JS_CFUNC_MAGIC_DEF("set_rim_texture", 1, &base_material3d_class_set_rim_texture, 5),
    JS_CFUNC_MAGIC_DEF("get_clearcoat_enabled", 0, &base_material3d_class_get_clearcoat_enabled, 3),
    JS_CFUNC_MAGIC_DEF("set_clearcoat_enabled", 1, &base_material3d_class_set_clearcoat_enabled, 3),
    JS_CFUNC_MAGIC_DEF("get_clearcoat_texture", 0, &base_material3d_class_get_clearcoat_texture, 6),
    JS_CFUNC_MAGIC_DEF("set_clearcoat_texture", 1, &base_material3d_class_set_clearcoat_texture, 6),
    JS_CFUNC_MAGIC_DEF("get_anisotropy_enabled", 0, &base_material3d_class_get_anisotropy_enabled, 4),
    JS_CFUNC_MAGIC_DEF("set_anisotropy_enabled", 1, &base_material3d_class_set_anisotropy_enabled, 4),
    JS_CFUNC_MAGIC_DEF("get_anisotropy_flowmap", 0, &base_material3d_class_get_anisotropy_flowmap, 7),
    JS_CFUNC_MAGIC_DEF("set_anisotropy_flowmap", 1, &base_material3d_class_set_anisotropy_flowmap, 7),
    JS_CFUNC_MAGIC_DEF("get_ao_enabled", 0, &base_material3d_class_get_ao_enabled, 5),
    JS_CFUNC_MAGIC_DEF("set_ao_enabled", 1, &base_material3d_class_set_ao_enabled, 5),
    JS_CFUNC_MAGIC_DEF("get_ao_texture", 0, &base_material3d_class_get_ao_texture, 8),
    JS_CFUNC_MAGIC_DEF("set_ao_texture", 1, &base_material3d_class_set_ao_texture, 8),
    JS_CFUNC_MAGIC_DEF("get_ao_on_uv2", 0, &base_material3d_class_get_ao_on_uv2, 10),
    JS_CFUNC_MAGIC_DEF("set_ao_on_uv2", 1, &base_material3d_class_set_ao_on_uv2, 10),
    JS_CFUNC_MAGIC_DEF("get_heightmap_enabled", 0, &base_material3d_class_get_heightmap_enabled, 6),
    JS_CFUNC_MAGIC_DEF("set_heightmap_enabled", 1, &base_material3d_class_set_heightmap_enabled, 6),
    JS_CFUNC_MAGIC_DEF("get_heightmap_texture", 0, &base_material3d_class_get_heightmap_texture, 9),
    JS_CFUNC_MAGIC_DEF("set_heightmap_texture", 1, &base_material3d_class_set_heightmap_texture, 9),
    JS_CFUNC_MAGIC_DEF("get_heightmap_flip_texture", 0, &base_material3d_class_get_heightmap_flip_texture, 17),
    JS_CFUNC_MAGIC_DEF("set_heightmap_flip_texture", 1, &base_material3d_class_set_heightmap_flip_texture, 17),
    JS_CFUNC_MAGIC_DEF("get_subsurf_scatter_enabled", 0, &base_material3d_class_get_subsurf_scatter_enabled, 7),
    JS_CFUNC_MAGIC_DEF("set_subsurf_scatter_enabled", 1, &base_material3d_class_set_subsurf_scatter_enabled, 7),
    JS_CFUNC_MAGIC_DEF("get_subsurf_scatter_skin_mode", 0, &base_material3d_class_get_subsurf_scatter_skin_mode, 18),
    JS_CFUNC_MAGIC_DEF("set_subsurf_scatter_skin_mode", 1, &base_material3d_class_set_subsurf_scatter_skin_mode, 18),
    JS_CFUNC_MAGIC_DEF("get_subsurf_scatter_texture", 0, &base_material3d_class_get_subsurf_scatter_texture, 10),
    JS_CFUNC_MAGIC_DEF("set_subsurf_scatter_texture", 1, &base_material3d_class_set_subsurf_scatter_texture, 10),
    JS_CFUNC_MAGIC_DEF("get_subsurf_scatter_transmittance_enabled", 0, &base_material3d_class_get_subsurf_scatter_transmittance_enabled, 8),
    JS_CFUNC_MAGIC_DEF("set_subsurf_scatter_transmittance_enabled", 1, &base_material3d_class_set_subsurf_scatter_transmittance_enabled, 8),
    JS_CFUNC_MAGIC_DEF("get_subsurf_scatter_transmittance_texture", 0, &base_material3d_class_get_subsurf_scatter_transmittance_texture, 11),
    JS_CFUNC_MAGIC_DEF("set_subsurf_scatter_transmittance_texture", 1, &base_material3d_class_set_subsurf_scatter_transmittance_texture, 11),
    JS_CFUNC_MAGIC_DEF("get_backlight_enabled", 0, &base_material3d_class_get_backlight_enabled, 9),
    JS_CFUNC_MAGIC_DEF("set_backlight_enabled", 1, &base_material3d_class_set_backlight_enabled, 9),
    JS_CFUNC_MAGIC_DEF("get_backlight_texture", 0, &base_material3d_class_get_backlight_texture, 12),
    JS_CFUNC_MAGIC_DEF("set_backlight_texture", 1, &base_material3d_class_set_backlight_texture, 12),
    JS_CFUNC_MAGIC_DEF("get_refraction_enabled", 0, &base_material3d_class_get_refraction_enabled, 10),
    JS_CFUNC_MAGIC_DEF("set_refraction_enabled", 1, &base_material3d_class_set_refraction_enabled, 10),
    JS_CFUNC_MAGIC_DEF("get_refraction_texture", 0, &base_material3d_class_get_refraction_texture, 13),
    JS_CFUNC_MAGIC_DEF("set_refraction_texture", 1, &base_material3d_class_set_refraction_texture, 13),
    JS_CFUNC_MAGIC_DEF("get_detail_enabled", 0, &base_material3d_class_get_detail_enabled, 11),
    JS_CFUNC_MAGIC_DEF("set_detail_enabled", 1, &base_material3d_class_set_detail_enabled, 11),
    JS_CFUNC_MAGIC_DEF("get_detail_mask", 0, &base_material3d_class_get_detail_mask, 14),
    JS_CFUNC_MAGIC_DEF("set_detail_mask", 1, &base_material3d_class_set_detail_mask, 14),
    JS_CFUNC_MAGIC_DEF("get_detail_albedo", 0, &base_material3d_class_get_detail_albedo, 15),
    JS_CFUNC_MAGIC_DEF("set_detail_albedo", 1, &base_material3d_class_set_detail_albedo, 15),
    JS_CFUNC_MAGIC_DEF("get_detail_normal", 0, &base_material3d_class_get_detail_normal, 16),
    JS_CFUNC_MAGIC_DEF("set_detail_normal", 1, &base_material3d_class_set_detail_normal, 16),
    JS_CFUNC_MAGIC_DEF("get_uv1_triplanar", 0, &base_material3d_class_get_uv1_triplanar, 6),
    JS_CFUNC_MAGIC_DEF("set_uv1_triplanar", 1, &base_material3d_class_set_uv1_triplanar, 6),
    JS_CFUNC_MAGIC_DEF("get_uv1_world_triplanar", 0, &base_material3d_class_get_uv1_world_triplanar, 8),
    JS_CFUNC_MAGIC_DEF("set_uv1_world_triplanar", 1, &base_material3d_class_set_uv1_world_triplanar, 8),
    JS_CFUNC_MAGIC_DEF("get_uv2_triplanar", 0, &base_material3d_class_get_uv2_triplanar, 7),
    JS_CFUNC_MAGIC_DEF("set_uv2_triplanar", 1, &base_material3d_class_set_uv2_triplanar, 7),
    JS_CFUNC_MAGIC_DEF("get_uv2_world_triplanar", 0, &base_material3d_class_get_uv2_world_triplanar, 9),
    JS_CFUNC_MAGIC_DEF("set_uv2_world_triplanar", 1, &base_material3d_class_set_uv2_world_triplanar, 9),
    JS_CFUNC_MAGIC_DEF("get_texture_repeat", 0, &base_material3d_class_get_texture_repeat, 16),
    JS_CFUNC_MAGIC_DEF("set_texture_repeat", 1, &base_material3d_class_set_texture_repeat, 16),
    JS_CFUNC_MAGIC_DEF("get_disable_receive_shadows", 0, &base_material3d_class_get_disable_receive_shadows, 13),
    JS_CFUNC_MAGIC_DEF("set_disable_receive_shadows", 1, &base_material3d_class_set_disable_receive_shadows, 13),
    JS_CFUNC_MAGIC_DEF("get_shadow_to_opacity", 0, &base_material3d_class_get_shadow_to_opacity, 15),
    JS_CFUNC_MAGIC_DEF("set_shadow_to_opacity", 1, &base_material3d_class_set_shadow_to_opacity, 15),
    JS_CFUNC_MAGIC_DEF("get_billboard_keep_scale", 0, &base_material3d_class_get_billboard_keep_scale, 5),
    JS_CFUNC_MAGIC_DEF("set_billboard_keep_scale", 1, &base_material3d_class_set_billboard_keep_scale, 5),
    JS_CFUNC_MAGIC_DEF("get_fixed_size", 0, &base_material3d_class_get_fixed_size, 4),
    JS_CFUNC_MAGIC_DEF("set_fixed_size", 1, &base_material3d_class_set_fixed_size, 4),
    JS_CFUNC_MAGIC_DEF("get_use_point_size", 0, &base_material3d_class_get_use_point_size, 3),
    JS_CFUNC_MAGIC_DEF("set_use_point_size", 1, &base_material3d_class_set_use_point_size, 3),
    JS_CFUNC_MAGIC_DEF("get_use_particle_trails", 0, &base_material3d_class_get_use_particle_trails, 19),
    JS_CFUNC_MAGIC_DEF("set_use_particle_trails", 1, &base_material3d_class_set_use_particle_trails, 19),
    JS_CFUNC_MAGIC_DEF("get_use_z_clip_scale", 0, &base_material3d_class_get_use_z_clip_scale, 23),
    JS_CFUNC_MAGIC_DEF("set_use_z_clip_scale", 1, &base_material3d_class_set_use_z_clip_scale, 23),
    JS_CFUNC_MAGIC_DEF("get_use_fov_override", 0, &base_material3d_class_get_use_fov_override, 24),
    JS_CFUNC_MAGIC_DEF("set_use_fov_override", 1, &base_material3d_class_set_use_fov_override, 24),
};




static void define_base_material3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "transparency"),
        JS_NewCFunction(ctx, base_material3d_class_get_transparency, "get_transparency", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_transparency, "set_transparency", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "alpha_scissor_threshold"),
        JS_NewCFunction(ctx, base_material3d_class_get_alpha_scissor_threshold, "get_alpha_scissor_threshold", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_alpha_scissor_threshold, "set_alpha_scissor_threshold", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "alpha_hash_scale"),
        JS_NewCFunction(ctx, base_material3d_class_get_alpha_hash_scale, "get_alpha_hash_scale", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_alpha_hash_scale, "set_alpha_hash_scale", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "alpha_antialiasing_mode"),
        JS_NewCFunction(ctx, base_material3d_class_get_alpha_antialiasing, "get_alpha_antialiasing", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_alpha_antialiasing, "set_alpha_antialiasing", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "alpha_antialiasing_edge"),
        JS_NewCFunction(ctx, base_material3d_class_get_alpha_antialiasing_edge, "get_alpha_antialiasing_edge", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_alpha_antialiasing_edge, "set_alpha_antialiasing_edge", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "blend_mode"),
        JS_NewCFunction(ctx, base_material3d_class_get_blend_mode, "get_blend_mode", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_blend_mode, "set_blend_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "cull_mode"),
        JS_NewCFunction(ctx, base_material3d_class_get_cull_mode, "get_cull_mode", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_cull_mode, "set_cull_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "depth_draw_mode"),
        JS_NewCFunction(ctx, base_material3d_class_get_depth_draw_mode, "get_depth_draw_mode", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_depth_draw_mode, "set_depth_draw_mode", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "no_depth_test"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_no_depth_test, "get_no_depth_test", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 0),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_no_depth_test, "set_no_depth_test", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 0),
		JS_PROP_GETSET
	);
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "depth_test"),
        JS_NewCFunction(ctx, base_material3d_class_get_depth_test, "get_depth_test", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_depth_test, "set_depth_test", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "shading_mode"),
        JS_NewCFunction(ctx, base_material3d_class_get_shading_mode, "get_shading_mode", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_shading_mode, "set_shading_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "diffuse_mode"),
        JS_NewCFunction(ctx, base_material3d_class_get_diffuse_mode, "get_diffuse_mode", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_diffuse_mode, "set_diffuse_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "specular_mode"),
        JS_NewCFunction(ctx, base_material3d_class_get_specular_mode, "get_specular_mode", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_specular_mode, "set_specular_mode", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "disable_ambient_light"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_disable_ambient_light, "get_disable_ambient_light", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 14),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_disable_ambient_light, "set_disable_ambient_light", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 14),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "disable_fog"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_disable_fog, "get_disable_fog", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 21),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_disable_fog, "set_disable_fog", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 21),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "disable_specular_occlusion"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_disable_specular_occlusion, "get_disable_specular_occlusion", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 22),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_disable_specular_occlusion, "set_disable_specular_occlusion", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 22),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "vertex_color_use_as_albedo"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_vertex_color_use_as_albedo, "get_vertex_color_use_as_albedo", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 1),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_vertex_color_use_as_albedo, "set_vertex_color_use_as_albedo", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 1),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "vertex_color_is_srgb"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_vertex_color_is_srgb, "get_vertex_color_is_srgb", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 2),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_vertex_color_is_srgb, "set_vertex_color_is_srgb", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 2),
		JS_PROP_GETSET
	);
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "albedo_color"),
        JS_NewCFunction(ctx, base_material3d_class_get_albedo, "get_albedo", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_albedo, "set_albedo", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "albedo_texture"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_albedo_texture, "get_albedo_texture", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 0),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_albedo_texture, "set_albedo_texture", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 0),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "albedo_texture_force_srgb"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_albedo_texture_force_srgb, "get_albedo_texture_force_srgb", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 12),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_albedo_texture_force_srgb, "set_albedo_texture_force_srgb", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 12),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "albedo_texture_msdf"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_albedo_texture_msdf, "get_albedo_texture_msdf", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 20),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_albedo_texture_msdf, "set_albedo_texture_msdf", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 20),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "orm_texture"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_orm_texture, "get_orm_texture", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 17),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_orm_texture, "set_orm_texture", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 17),
		JS_PROP_GETSET
	);
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "metallic"),
        JS_NewCFunction(ctx, base_material3d_class_get_metallic, "get_metallic", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_metallic, "set_metallic", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "metallic_specular"),
        JS_NewCFunction(ctx, base_material3d_class_get_specular, "get_specular", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_specular, "set_specular", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "metallic_texture"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_metallic_texture, "get_metallic_texture", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 1),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_metallic_texture, "set_metallic_texture", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 1),
		JS_PROP_GETSET
	);
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "metallic_texture_channel"),
        JS_NewCFunction(ctx, base_material3d_class_get_metallic_texture_channel, "get_metallic_texture_channel", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_metallic_texture_channel, "set_metallic_texture_channel", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "roughness"),
        JS_NewCFunction(ctx, base_material3d_class_get_roughness, "get_roughness", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_roughness, "set_roughness", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "roughness_texture"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_roughness_texture, "get_roughness_texture", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 2),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_roughness_texture, "set_roughness_texture", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 2),
		JS_PROP_GETSET
	);
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "roughness_texture_channel"),
        JS_NewCFunction(ctx, base_material3d_class_get_roughness_texture_channel, "get_roughness_texture_channel", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_roughness_texture_channel, "set_roughness_texture_channel", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "emission_enabled"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_emission_enabled, "get_emission_enabled", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 0),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_emission_enabled, "set_emission_enabled", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 0),
		JS_PROP_GETSET
	);
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "emission"),
        JS_NewCFunction(ctx, base_material3d_class_get_emission, "get_emission", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_emission, "set_emission", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "emission_energy_multiplier"),
        JS_NewCFunction(ctx, base_material3d_class_get_emission_energy_multiplier, "get_emission_energy_multiplier", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_emission_energy_multiplier, "set_emission_energy_multiplier", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "emission_intensity"),
        JS_NewCFunction(ctx, base_material3d_class_get_emission_intensity, "get_emission_intensity", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_emission_intensity, "set_emission_intensity", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "emission_operator"),
        JS_NewCFunction(ctx, base_material3d_class_get_emission_operator, "get_emission_operator", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_emission_operator, "set_emission_operator", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "emission_on_uv2"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_emission_on_uv2, "get_emission_on_uv2", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 11),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_emission_on_uv2, "set_emission_on_uv2", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 11),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "emission_texture"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_emission_texture, "get_emission_texture", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 3),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_emission_texture, "set_emission_texture", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 3),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "normal_enabled"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_normal_enabled, "get_normal_enabled", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 1),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_normal_enabled, "set_normal_enabled", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 1),
		JS_PROP_GETSET
	);
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "normal_scale"),
        JS_NewCFunction(ctx, base_material3d_class_get_normal_scale, "get_normal_scale", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_normal_scale, "set_normal_scale", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "normal_texture"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_normal_texture, "get_normal_texture", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 4),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_normal_texture, "set_normal_texture", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 4),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "bent_normal_enabled"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_bent_normal_enabled, "get_bent_normal_enabled", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 12),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_bent_normal_enabled, "set_bent_normal_enabled", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 12),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "bent_normal_texture"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_bent_normal_texture, "get_bent_normal_texture", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 18),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_bent_normal_texture, "set_bent_normal_texture", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 18),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "rim_enabled"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_rim_enabled, "get_rim_enabled", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 2),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_rim_enabled, "set_rim_enabled", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 2),
		JS_PROP_GETSET
	);
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "rim"),
        JS_NewCFunction(ctx, base_material3d_class_get_rim, "get_rim", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_rim, "set_rim", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "rim_tint"),
        JS_NewCFunction(ctx, base_material3d_class_get_rim_tint, "get_rim_tint", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_rim_tint, "set_rim_tint", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "rim_texture"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_rim_texture, "get_rim_texture", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 5),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_rim_texture, "set_rim_texture", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 5),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "clearcoat_enabled"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_clearcoat_enabled, "get_clearcoat_enabled", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 3),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_clearcoat_enabled, "set_clearcoat_enabled", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 3),
		JS_PROP_GETSET
	);
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "clearcoat"),
        JS_NewCFunction(ctx, base_material3d_class_get_clearcoat, "get_clearcoat", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_clearcoat, "set_clearcoat", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "clearcoat_roughness"),
        JS_NewCFunction(ctx, base_material3d_class_get_clearcoat_roughness, "get_clearcoat_roughness", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_clearcoat_roughness, "set_clearcoat_roughness", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "clearcoat_texture"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_clearcoat_texture, "get_clearcoat_texture", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 6),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_clearcoat_texture, "set_clearcoat_texture", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 6),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "anisotropy_enabled"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_anisotropy_enabled, "get_anisotropy_enabled", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 4),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_anisotropy_enabled, "set_anisotropy_enabled", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 4),
		JS_PROP_GETSET
	);
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "anisotropy"),
        JS_NewCFunction(ctx, base_material3d_class_get_anisotropy, "get_anisotropy", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_anisotropy, "set_anisotropy", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "anisotropy_flowmap"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_anisotropy_flowmap, "get_anisotropy_flowmap", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 7),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_anisotropy_flowmap, "set_anisotropy_flowmap", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 7),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "ao_enabled"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_ao_enabled, "get_ao_enabled", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 5),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_ao_enabled, "set_ao_enabled", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 5),
		JS_PROP_GETSET
	);
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "ao_light_affect"),
        JS_NewCFunction(ctx, base_material3d_class_get_ao_light_affect, "get_ao_light_affect", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_ao_light_affect, "set_ao_light_affect", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "ao_texture"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_ao_texture, "get_ao_texture", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 8),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_ao_texture, "set_ao_texture", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 8),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "ao_on_uv2"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_ao_on_uv2, "get_ao_on_uv2", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 10),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_ao_on_uv2, "set_ao_on_uv2", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 10),
		JS_PROP_GETSET
	);
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "ao_texture_channel"),
        JS_NewCFunction(ctx, base_material3d_class_get_ao_texture_channel, "get_ao_texture_channel", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_ao_texture_channel, "set_ao_texture_channel", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "heightmap_enabled"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_heightmap_enabled, "get_heightmap_enabled", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 6),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_heightmap_enabled, "set_heightmap_enabled", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 6),
		JS_PROP_GETSET
	);
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "heightmap_scale"),
        JS_NewCFunction(ctx, base_material3d_class_get_heightmap_scale, "get_heightmap_scale", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_heightmap_scale, "set_heightmap_scale", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "heightmap_deep_parallax"),
        JS_NewCFunction(ctx, base_material3d_class_is_heightmap_deep_parallax_enabled, "is_heightmap_deep_parallax_enabled", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_heightmap_deep_parallax, "set_heightmap_deep_parallax", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "heightmap_min_layers"),
        JS_NewCFunction(ctx, base_material3d_class_get_heightmap_deep_parallax_min_layers, "get_heightmap_deep_parallax_min_layers", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_heightmap_deep_parallax_min_layers, "set_heightmap_deep_parallax_min_layers", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "heightmap_max_layers"),
        JS_NewCFunction(ctx, base_material3d_class_get_heightmap_deep_parallax_max_layers, "get_heightmap_deep_parallax_max_layers", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_heightmap_deep_parallax_max_layers, "set_heightmap_deep_parallax_max_layers", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "heightmap_flip_tangent"),
        JS_NewCFunction(ctx, base_material3d_class_get_heightmap_deep_parallax_flip_tangent, "get_heightmap_deep_parallax_flip_tangent", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_heightmap_deep_parallax_flip_tangent, "set_heightmap_deep_parallax_flip_tangent", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "heightmap_flip_binormal"),
        JS_NewCFunction(ctx, base_material3d_class_get_heightmap_deep_parallax_flip_binormal, "get_heightmap_deep_parallax_flip_binormal", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_heightmap_deep_parallax_flip_binormal, "set_heightmap_deep_parallax_flip_binormal", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "heightmap_texture"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_heightmap_texture, "get_heightmap_texture", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 9),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_heightmap_texture, "set_heightmap_texture", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 9),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "heightmap_flip_texture"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_heightmap_flip_texture, "get_heightmap_flip_texture", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 17),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_heightmap_flip_texture, "set_heightmap_flip_texture", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 17),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "subsurf_scatter_enabled"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_subsurf_scatter_enabled, "get_subsurf_scatter_enabled", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 7),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_subsurf_scatter_enabled, "set_subsurf_scatter_enabled", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 7),
		JS_PROP_GETSET
	);
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "subsurf_scatter_strength"),
        JS_NewCFunction(ctx, base_material3d_class_get_subsurface_scattering_strength, "get_subsurface_scattering_strength", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_subsurface_scattering_strength, "set_subsurface_scattering_strength", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "subsurf_scatter_skin_mode"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_subsurf_scatter_skin_mode, "get_subsurf_scatter_skin_mode", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 18),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_subsurf_scatter_skin_mode, "set_subsurf_scatter_skin_mode", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 18),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "subsurf_scatter_texture"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_subsurf_scatter_texture, "get_subsurf_scatter_texture", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 10),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_subsurf_scatter_texture, "set_subsurf_scatter_texture", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 10),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "subsurf_scatter_transmittance_enabled"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_subsurf_scatter_transmittance_enabled, "get_subsurf_scatter_transmittance_enabled", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 8),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_subsurf_scatter_transmittance_enabled, "set_subsurf_scatter_transmittance_enabled", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 8),
		JS_PROP_GETSET
	);
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "subsurf_scatter_transmittance_color"),
        JS_NewCFunction(ctx, base_material3d_class_get_transmittance_color, "get_transmittance_color", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_transmittance_color, "set_transmittance_color", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "subsurf_scatter_transmittance_texture"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_subsurf_scatter_transmittance_texture, "get_subsurf_scatter_transmittance_texture", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 11),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_subsurf_scatter_transmittance_texture, "set_subsurf_scatter_transmittance_texture", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 11),
		JS_PROP_GETSET
	);
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "subsurf_scatter_transmittance_depth"),
        JS_NewCFunction(ctx, base_material3d_class_get_transmittance_depth, "get_transmittance_depth", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_transmittance_depth, "set_transmittance_depth", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "subsurf_scatter_transmittance_boost"),
        JS_NewCFunction(ctx, base_material3d_class_get_transmittance_boost, "get_transmittance_boost", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_transmittance_boost, "set_transmittance_boost", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "backlight_enabled"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_backlight_enabled, "get_backlight_enabled", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 9),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_backlight_enabled, "set_backlight_enabled", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 9),
		JS_PROP_GETSET
	);
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "backlight"),
        JS_NewCFunction(ctx, base_material3d_class_get_backlight, "get_backlight", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_backlight, "set_backlight", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "backlight_texture"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_backlight_texture, "get_backlight_texture", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 12),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_backlight_texture, "set_backlight_texture", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 12),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "refraction_enabled"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_refraction_enabled, "get_refraction_enabled", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 10),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_refraction_enabled, "set_refraction_enabled", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 10),
		JS_PROP_GETSET
	);
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "refraction_scale"),
        JS_NewCFunction(ctx, base_material3d_class_get_refraction, "get_refraction", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_refraction, "set_refraction", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "refraction_texture"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_refraction_texture, "get_refraction_texture", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 13),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_refraction_texture, "set_refraction_texture", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 13),
		JS_PROP_GETSET
	);
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "refraction_texture_channel"),
        JS_NewCFunction(ctx, base_material3d_class_get_refraction_texture_channel, "get_refraction_texture_channel", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_refraction_texture_channel, "set_refraction_texture_channel", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "detail_enabled"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_detail_enabled, "get_detail_enabled", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 11),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_detail_enabled, "set_detail_enabled", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 11),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "detail_mask"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_detail_mask, "get_detail_mask", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 14),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_detail_mask, "set_detail_mask", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 14),
		JS_PROP_GETSET
	);
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "detail_blend_mode"),
        JS_NewCFunction(ctx, base_material3d_class_get_detail_blend_mode, "get_detail_blend_mode", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_detail_blend_mode, "set_detail_blend_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "detail_uv_layer"),
        JS_NewCFunction(ctx, base_material3d_class_get_detail_uv, "get_detail_uv", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_detail_uv, "set_detail_uv", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "detail_albedo"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_detail_albedo, "get_detail_albedo", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 15),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_detail_albedo, "set_detail_albedo", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 15),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "detail_normal"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_detail_normal, "get_detail_normal", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 16),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_detail_normal, "set_detail_normal", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 16),
		JS_PROP_GETSET
	);
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "uv1_scale"),
        JS_NewCFunction(ctx, base_material3d_class_get_uv1_scale, "get_uv1_scale", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_uv1_scale, "set_uv1_scale", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "uv1_offset"),
        JS_NewCFunction(ctx, base_material3d_class_get_uv1_offset, "get_uv1_offset", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_uv1_offset, "set_uv1_offset", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "uv1_triplanar"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_uv1_triplanar, "get_uv1_triplanar", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 6),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_uv1_triplanar, "set_uv1_triplanar", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 6),
		JS_PROP_GETSET
	);
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "uv1_triplanar_sharpness"),
        JS_NewCFunction(ctx, base_material3d_class_get_uv1_triplanar_blend_sharpness, "get_uv1_triplanar_blend_sharpness", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_uv1_triplanar_blend_sharpness, "set_uv1_triplanar_blend_sharpness", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "uv1_world_triplanar"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_uv1_world_triplanar, "get_uv1_world_triplanar", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 8),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_uv1_world_triplanar, "set_uv1_world_triplanar", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 8),
		JS_PROP_GETSET
	);
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "uv2_scale"),
        JS_NewCFunction(ctx, base_material3d_class_get_uv2_scale, "get_uv2_scale", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_uv2_scale, "set_uv2_scale", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "uv2_offset"),
        JS_NewCFunction(ctx, base_material3d_class_get_uv2_offset, "get_uv2_offset", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_uv2_offset, "set_uv2_offset", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "uv2_triplanar"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_uv2_triplanar, "get_uv2_triplanar", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 7),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_uv2_triplanar, "set_uv2_triplanar", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 7),
		JS_PROP_GETSET
	);
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "uv2_triplanar_sharpness"),
        JS_NewCFunction(ctx, base_material3d_class_get_uv2_triplanar_blend_sharpness, "get_uv2_triplanar_blend_sharpness", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_uv2_triplanar_blend_sharpness, "set_uv2_triplanar_blend_sharpness", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "uv2_world_triplanar"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_uv2_world_triplanar, "get_uv2_world_triplanar", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 9),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_uv2_world_triplanar, "set_uv2_world_triplanar", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 9),
		JS_PROP_GETSET
	);
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "texture_filter"),
        JS_NewCFunction(ctx, base_material3d_class_get_texture_filter, "get_texture_filter", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_texture_filter, "set_texture_filter", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "texture_repeat"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_texture_repeat, "get_texture_repeat", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 16),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_texture_repeat, "set_texture_repeat", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 16),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "disable_receive_shadows"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_disable_receive_shadows, "get_disable_receive_shadows", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 13),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_disable_receive_shadows, "set_disable_receive_shadows", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 13),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "shadow_to_opacity"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_shadow_to_opacity, "get_shadow_to_opacity", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 15),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_shadow_to_opacity, "set_shadow_to_opacity", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 15),
		JS_PROP_GETSET
	);
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "billboard_mode"),
        JS_NewCFunction(ctx, base_material3d_class_get_billboard_mode, "get_billboard_mode", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_billboard_mode, "set_billboard_mode", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "billboard_keep_scale"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_billboard_keep_scale, "get_billboard_keep_scale", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 5),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_billboard_keep_scale, "set_billboard_keep_scale", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 5),
		JS_PROP_GETSET
	);
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "particles_anim_h_frames"),
        JS_NewCFunction(ctx, base_material3d_class_get_particles_anim_h_frames, "get_particles_anim_h_frames", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_particles_anim_h_frames, "set_particles_anim_h_frames", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "particles_anim_v_frames"),
        JS_NewCFunction(ctx, base_material3d_class_get_particles_anim_v_frames, "get_particles_anim_v_frames", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_particles_anim_v_frames, "set_particles_anim_v_frames", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "particles_anim_loop"),
        JS_NewCFunction(ctx, base_material3d_class_get_particles_anim_loop, "get_particles_anim_loop", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_particles_anim_loop, "set_particles_anim_loop", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "grow"),
        JS_NewCFunction(ctx, base_material3d_class_is_grow_enabled, "is_grow_enabled", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_grow_enabled, "set_grow_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "grow_amount"),
        JS_NewCFunction(ctx, base_material3d_class_get_grow, "get_grow", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_grow, "set_grow", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "fixed_size"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_fixed_size, "get_fixed_size", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 4),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_fixed_size, "set_fixed_size", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 4),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "use_point_size"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_use_point_size, "get_use_point_size", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 3),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_use_point_size, "set_use_point_size", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 3),
		JS_PROP_GETSET
	);
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "point_size"),
        JS_NewCFunction(ctx, base_material3d_class_get_point_size, "get_point_size", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_point_size, "set_point_size", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "use_particle_trails"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_use_particle_trails, "get_use_particle_trails", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 19),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_use_particle_trails, "set_use_particle_trails", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 19),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "use_z_clip_scale"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_use_z_clip_scale, "get_use_z_clip_scale", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 23),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_use_z_clip_scale, "set_use_z_clip_scale", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 23),
		JS_PROP_GETSET
	);
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "z_clip_scale"),
        JS_NewCFunction(ctx, base_material3d_class_get_z_clip_scale, "get_z_clip_scale", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_z_clip_scale, "set_z_clip_scale", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "use_fov_override"),
		JS_NewCFunctionMagic(ctx, base_material3d_class_get_use_fov_override, "get_use_fov_override", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 24),
		JS_NewCFunctionMagic(ctx, base_material3d_class_set_use_fov_override, "set_use_fov_override", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 24),
		JS_PROP_GETSET
	);
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "fov_override"),
        JS_NewCFunction(ctx, base_material3d_class_get_fov_override, "get_fov_override", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_fov_override, "set_fov_override", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "proximity_fade_enabled"),
        JS_NewCFunction(ctx, base_material3d_class_is_proximity_fade_enabled, "is_proximity_fade_enabled", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_proximity_fade_enabled, "set_proximity_fade_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "proximity_fade_distance"),
        JS_NewCFunction(ctx, base_material3d_class_get_proximity_fade_distance, "get_proximity_fade_distance", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_proximity_fade_distance, "set_proximity_fade_distance", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "msdf_pixel_range"),
        JS_NewCFunction(ctx, base_material3d_class_get_msdf_pixel_range, "get_msdf_pixel_range", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_msdf_pixel_range, "set_msdf_pixel_range", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "msdf_outline_size"),
        JS_NewCFunction(ctx, base_material3d_class_get_msdf_outline_size, "get_msdf_outline_size", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_msdf_outline_size, "set_msdf_outline_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "distance_fade_mode"),
        JS_NewCFunction(ctx, base_material3d_class_get_distance_fade, "get_distance_fade", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_distance_fade, "set_distance_fade", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "distance_fade_min_distance"),
        JS_NewCFunction(ctx, base_material3d_class_get_distance_fade_min_distance, "get_distance_fade_min_distance", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_distance_fade_min_distance, "set_distance_fade_min_distance", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "distance_fade_max_distance"),
        JS_NewCFunction(ctx, base_material3d_class_get_distance_fade_max_distance, "get_distance_fade_max_distance", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_distance_fade_max_distance, "set_distance_fade_max_distance", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "stencil_mode"),
        JS_NewCFunction(ctx, base_material3d_class_get_stencil_mode, "get_stencil_mode", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_stencil_mode, "set_stencil_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "stencil_flags"),
        JS_NewCFunction(ctx, base_material3d_class_get_stencil_flags, "get_stencil_flags", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_stencil_flags, "set_stencil_flags", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "stencil_compare"),
        JS_NewCFunction(ctx, base_material3d_class_get_stencil_compare, "get_stencil_compare", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_stencil_compare, "set_stencil_compare", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "stencil_reference"),
        JS_NewCFunction(ctx, base_material3d_class_get_stencil_reference, "get_stencil_reference", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_stencil_reference, "set_stencil_reference", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "stencil_color"),
        JS_NewCFunction(ctx, base_material3d_class_get_stencil_effect_color, "get_stencil_effect_color", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_stencil_effect_color, "set_stencil_effect_color", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "stencil_outline_thickness"),
        JS_NewCFunction(ctx, base_material3d_class_get_stencil_effect_outline_thickness, "get_stencil_effect_outline_thickness", 0),
        JS_NewCFunction(ctx, base_material3d_class_set_stencil_effect_outline_thickness, "set_stencil_effect_outline_thickness", 1),
        JS_PROP_GETSET
    );
}

static void define_base_material3d_enum(JSContext *ctx, JSValue ctor) {
	JSValue TextureParam_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, TextureParam_obj, "TEXTURE_ALBEDO", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, TextureParam_obj, "TEXTURE_METALLIC", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, TextureParam_obj, "TEXTURE_ROUGHNESS", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, TextureParam_obj, "TEXTURE_EMISSION", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, TextureParam_obj, "TEXTURE_NORMAL", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, TextureParam_obj, "TEXTURE_BENT_NORMAL", JS_NewInt64(ctx, 18));
	JS_SetPropertyStr(ctx, TextureParam_obj, "TEXTURE_RIM", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, TextureParam_obj, "TEXTURE_CLEARCOAT", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, TextureParam_obj, "TEXTURE_FLOWMAP", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, TextureParam_obj, "TEXTURE_AMBIENT_OCCLUSION", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, TextureParam_obj, "TEXTURE_HEIGHTMAP", JS_NewInt64(ctx, 9));
	JS_SetPropertyStr(ctx, TextureParam_obj, "TEXTURE_SUBSURFACE_SCATTERING", JS_NewInt64(ctx, 10));
	JS_SetPropertyStr(ctx, TextureParam_obj, "TEXTURE_SUBSURFACE_TRANSMITTANCE", JS_NewInt64(ctx, 11));
	JS_SetPropertyStr(ctx, TextureParam_obj, "TEXTURE_BACKLIGHT", JS_NewInt64(ctx, 12));
	JS_SetPropertyStr(ctx, TextureParam_obj, "TEXTURE_REFRACTION", JS_NewInt64(ctx, 13));
	JS_SetPropertyStr(ctx, TextureParam_obj, "TEXTURE_DETAIL_MASK", JS_NewInt64(ctx, 14));
	JS_SetPropertyStr(ctx, TextureParam_obj, "TEXTURE_DETAIL_ALBEDO", JS_NewInt64(ctx, 15));
	JS_SetPropertyStr(ctx, TextureParam_obj, "TEXTURE_DETAIL_NORMAL", JS_NewInt64(ctx, 16));
	JS_SetPropertyStr(ctx, TextureParam_obj, "TEXTURE_ORM", JS_NewInt64(ctx, 17));
	JS_SetPropertyStr(ctx, TextureParam_obj, "TEXTURE_MAX", JS_NewInt64(ctx, 19));
	JS_SetPropertyStr(ctx, ctor, "TextureParam", TextureParam_obj);
	JSValue TextureFilter_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, TextureFilter_obj, "TEXTURE_FILTER_NEAREST", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, TextureFilter_obj, "TEXTURE_FILTER_LINEAR", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, TextureFilter_obj, "TEXTURE_FILTER_NEAREST_WITH_MIPMAPS", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, TextureFilter_obj, "TEXTURE_FILTER_LINEAR_WITH_MIPMAPS", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, TextureFilter_obj, "TEXTURE_FILTER_NEAREST_WITH_MIPMAPS_ANISOTROPIC", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, TextureFilter_obj, "TEXTURE_FILTER_LINEAR_WITH_MIPMAPS_ANISOTROPIC", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, TextureFilter_obj, "TEXTURE_FILTER_MAX", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, ctor, "TextureFilter", TextureFilter_obj);
	JSValue DetailUV_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, DetailUV_obj, "DETAIL_UV_1", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, DetailUV_obj, "DETAIL_UV_2", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ctor, "DetailUV", DetailUV_obj);
	JSValue Transparency_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, Transparency_obj, "TRANSPARENCY_DISABLED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, Transparency_obj, "TRANSPARENCY_ALPHA", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, Transparency_obj, "TRANSPARENCY_ALPHA_SCISSOR", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, Transparency_obj, "TRANSPARENCY_ALPHA_HASH", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, Transparency_obj, "TRANSPARENCY_ALPHA_DEPTH_PRE_PASS", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, Transparency_obj, "TRANSPARENCY_MAX", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, ctor, "Transparency", Transparency_obj);
	JSValue ShadingMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, ShadingMode_obj, "SHADING_MODE_UNSHADED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, ShadingMode_obj, "SHADING_MODE_PER_PIXEL", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ShadingMode_obj, "SHADING_MODE_PER_VERTEX", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ShadingMode_obj, "SHADING_MODE_MAX", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ctor, "ShadingMode", ShadingMode_obj);
	JSValue Feature_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, Feature_obj, "FEATURE_EMISSION", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, Feature_obj, "FEATURE_NORMAL_MAPPING", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, Feature_obj, "FEATURE_RIM", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, Feature_obj, "FEATURE_CLEARCOAT", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, Feature_obj, "FEATURE_ANISOTROPY", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, Feature_obj, "FEATURE_AMBIENT_OCCLUSION", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, Feature_obj, "FEATURE_HEIGHT_MAPPING", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, Feature_obj, "FEATURE_SUBSURFACE_SCATTERING", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, Feature_obj, "FEATURE_SUBSURFACE_TRANSMITTANCE", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, Feature_obj, "FEATURE_BACKLIGHT", JS_NewInt64(ctx, 9));
	JS_SetPropertyStr(ctx, Feature_obj, "FEATURE_REFRACTION", JS_NewInt64(ctx, 10));
	JS_SetPropertyStr(ctx, Feature_obj, "FEATURE_DETAIL", JS_NewInt64(ctx, 11));
	JS_SetPropertyStr(ctx, Feature_obj, "FEATURE_BENT_NORMAL_MAPPING", JS_NewInt64(ctx, 12));
	JS_SetPropertyStr(ctx, Feature_obj, "FEATURE_MAX", JS_NewInt64(ctx, 13));
	JS_SetPropertyStr(ctx, ctor, "Feature", Feature_obj);
	JSValue BlendMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, BlendMode_obj, "BLEND_MODE_MIX", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, BlendMode_obj, "BLEND_MODE_ADD", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, BlendMode_obj, "BLEND_MODE_SUB", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, BlendMode_obj, "BLEND_MODE_MUL", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, BlendMode_obj, "BLEND_MODE_PREMULT_ALPHA", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, ctor, "BlendMode", BlendMode_obj);
	JSValue AlphaAntiAliasing_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, AlphaAntiAliasing_obj, "ALPHA_ANTIALIASING_OFF", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, AlphaAntiAliasing_obj, "ALPHA_ANTIALIASING_ALPHA_TO_COVERAGE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, AlphaAntiAliasing_obj, "ALPHA_ANTIALIASING_ALPHA_TO_COVERAGE_AND_TO_ONE", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "AlphaAntiAliasing", AlphaAntiAliasing_obj);
	JSValue DepthDrawMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, DepthDrawMode_obj, "DEPTH_DRAW_OPAQUE_ONLY", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, DepthDrawMode_obj, "DEPTH_DRAW_ALWAYS", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, DepthDrawMode_obj, "DEPTH_DRAW_DISABLED", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "DepthDrawMode", DepthDrawMode_obj);
	JSValue DepthTest_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, DepthTest_obj, "DEPTH_TEST_DEFAULT", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, DepthTest_obj, "DEPTH_TEST_INVERTED", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ctor, "DepthTest", DepthTest_obj);
	JSValue CullMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, CullMode_obj, "CULL_BACK", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, CullMode_obj, "CULL_FRONT", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, CullMode_obj, "CULL_DISABLED", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "CullMode", CullMode_obj);
	JSValue Flags_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, Flags_obj, "FLAG_DISABLE_DEPTH_TEST", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, Flags_obj, "FLAG_ALBEDO_FROM_VERTEX_COLOR", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, Flags_obj, "FLAG_SRGB_VERTEX_COLOR", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, Flags_obj, "FLAG_USE_POINT_SIZE", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, Flags_obj, "FLAG_FIXED_SIZE", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, Flags_obj, "FLAG_BILLBOARD_KEEP_SCALE", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, Flags_obj, "FLAG_UV1_USE_TRIPLANAR", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, Flags_obj, "FLAG_UV2_USE_TRIPLANAR", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, Flags_obj, "FLAG_UV1_USE_WORLD_TRIPLANAR", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, Flags_obj, "FLAG_UV2_USE_WORLD_TRIPLANAR", JS_NewInt64(ctx, 9));
	JS_SetPropertyStr(ctx, Flags_obj, "FLAG_AO_ON_UV2", JS_NewInt64(ctx, 10));
	JS_SetPropertyStr(ctx, Flags_obj, "FLAG_EMISSION_ON_UV2", JS_NewInt64(ctx, 11));
	JS_SetPropertyStr(ctx, Flags_obj, "FLAG_ALBEDO_TEXTURE_FORCE_SRGB", JS_NewInt64(ctx, 12));
	JS_SetPropertyStr(ctx, Flags_obj, "FLAG_DONT_RECEIVE_SHADOWS", JS_NewInt64(ctx, 13));
	JS_SetPropertyStr(ctx, Flags_obj, "FLAG_DISABLE_AMBIENT_LIGHT", JS_NewInt64(ctx, 14));
	JS_SetPropertyStr(ctx, Flags_obj, "FLAG_USE_SHADOW_TO_OPACITY", JS_NewInt64(ctx, 15));
	JS_SetPropertyStr(ctx, Flags_obj, "FLAG_USE_TEXTURE_REPEAT", JS_NewInt64(ctx, 16));
	JS_SetPropertyStr(ctx, Flags_obj, "FLAG_INVERT_HEIGHTMAP", JS_NewInt64(ctx, 17));
	JS_SetPropertyStr(ctx, Flags_obj, "FLAG_SUBSURFACE_MODE_SKIN", JS_NewInt64(ctx, 18));
	JS_SetPropertyStr(ctx, Flags_obj, "FLAG_PARTICLE_TRAILS_MODE", JS_NewInt64(ctx, 19));
	JS_SetPropertyStr(ctx, Flags_obj, "FLAG_ALBEDO_TEXTURE_MSDF", JS_NewInt64(ctx, 20));
	JS_SetPropertyStr(ctx, Flags_obj, "FLAG_DISABLE_FOG", JS_NewInt64(ctx, 21));
	JS_SetPropertyStr(ctx, Flags_obj, "FLAG_DISABLE_SPECULAR_OCCLUSION", JS_NewInt64(ctx, 22));
	JS_SetPropertyStr(ctx, Flags_obj, "FLAG_USE_Z_CLIP_SCALE", JS_NewInt64(ctx, 23));
	JS_SetPropertyStr(ctx, Flags_obj, "FLAG_USE_FOV_OVERRIDE", JS_NewInt64(ctx, 24));
	JS_SetPropertyStr(ctx, Flags_obj, "FLAG_MAX", JS_NewInt64(ctx, 25));
	JS_SetPropertyStr(ctx, ctor, "Flags", Flags_obj);
	JSValue DiffuseMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, DiffuseMode_obj, "DIFFUSE_BURLEY", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, DiffuseMode_obj, "DIFFUSE_LAMBERT", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, DiffuseMode_obj, "DIFFUSE_LAMBERT_WRAP", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, DiffuseMode_obj, "DIFFUSE_TOON", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ctor, "DiffuseMode", DiffuseMode_obj);
	JSValue SpecularMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, SpecularMode_obj, "SPECULAR_SCHLICK_GGX", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, SpecularMode_obj, "SPECULAR_TOON", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, SpecularMode_obj, "SPECULAR_DISABLED", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "SpecularMode", SpecularMode_obj);
	JSValue BillboardMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, BillboardMode_obj, "BILLBOARD_DISABLED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, BillboardMode_obj, "BILLBOARD_ENABLED", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, BillboardMode_obj, "BILLBOARD_FIXED_Y", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, BillboardMode_obj, "BILLBOARD_PARTICLES", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ctor, "BillboardMode", BillboardMode_obj);
	JSValue TextureChannel_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, TextureChannel_obj, "TEXTURE_CHANNEL_RED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, TextureChannel_obj, "TEXTURE_CHANNEL_GREEN", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, TextureChannel_obj, "TEXTURE_CHANNEL_BLUE", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, TextureChannel_obj, "TEXTURE_CHANNEL_ALPHA", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, TextureChannel_obj, "TEXTURE_CHANNEL_GRAYSCALE", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, ctor, "TextureChannel", TextureChannel_obj);
	JSValue EmissionOperator_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, EmissionOperator_obj, "EMISSION_OP_ADD", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, EmissionOperator_obj, "EMISSION_OP_MULTIPLY", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ctor, "EmissionOperator", EmissionOperator_obj);
	JSValue DistanceFadeMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, DistanceFadeMode_obj, "DISTANCE_FADE_DISABLED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, DistanceFadeMode_obj, "DISTANCE_FADE_PIXEL_ALPHA", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, DistanceFadeMode_obj, "DISTANCE_FADE_PIXEL_DITHER", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, DistanceFadeMode_obj, "DISTANCE_FADE_OBJECT_DITHER", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ctor, "DistanceFadeMode", DistanceFadeMode_obj);
	JSValue StencilMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, StencilMode_obj, "STENCIL_MODE_DISABLED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, StencilMode_obj, "STENCIL_MODE_OUTLINE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, StencilMode_obj, "STENCIL_MODE_XRAY", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, StencilMode_obj, "STENCIL_MODE_CUSTOM", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ctor, "StencilMode", StencilMode_obj);
	JSValue StencilFlags_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, StencilFlags_obj, "STENCIL_FLAG_READ", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, StencilFlags_obj, "STENCIL_FLAG_WRITE", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, StencilFlags_obj, "STENCIL_FLAG_WRITE_DEPTH_FAIL", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, ctor, "StencilFlags", StencilFlags_obj);
	JSValue StencilCompare_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, StencilCompare_obj, "STENCIL_COMPARE_ALWAYS", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, StencilCompare_obj, "STENCIL_COMPARE_LESS", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, StencilCompare_obj, "STENCIL_COMPARE_EQUAL", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, StencilCompare_obj, "STENCIL_COMPARE_LESS_OR_EQUAL", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, StencilCompare_obj, "STENCIL_COMPARE_GREATER", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, StencilCompare_obj, "STENCIL_COMPARE_NOT_EQUAL", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, StencilCompare_obj, "STENCIL_COMPARE_GREATER_OR_EQUAL", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, ctor, "StencilCompare", StencilCompare_obj);
}

static int js_base_material3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["BaseMaterial3D"] = class_id;
	classes_by_id[class_id] = "BaseMaterial3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &base_material3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Material"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_base_material3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, base_material3d_class_proto_funcs, _countof(base_material3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, base_material3d_class_constructor, "BaseMaterial3D", 0, JS_CFUNC_constructor, 0);
	define_base_material3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "BaseMaterial3D", ctor);
	ctor_list["BaseMaterial3D"] = ctor;

	return 0;
}

JSModuleDef *_js_init_base_material3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/material';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_base_material3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "BaseMaterial3D");
	return m;
}

JSModuleDef *js_init_base_material3d_module(JSContext *ctx) {
	return _js_init_base_material3d_module(ctx, "@godot/classes/base_material3d");
}

void __register_base_material3d() {
	js_init_base_material3d_module(js_context());
}

void register_base_material3d() {
	__register_base_material3d();
}