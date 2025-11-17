#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/classes/sky.hpp>
#include <godot_cpp/classes/texture.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/environment.hpp>
using namespace godot;

static void environment_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Environment"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef environment_class_def = {
    "Environment",
    environment_class_finalizer
};

static JSValue environment_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["Environment"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    Environment *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<Environment *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(Environment);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue environment_class_set_background(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_background, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_background(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_background, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_sky(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_sky, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_sky(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_sky, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_sky_custom_fov(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_sky_custom_fov, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_sky_custom_fov(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_sky_custom_fov, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_sky_rotation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_sky_rotation, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_sky_rotation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector3> *proxy = memnew(ObjectProxy<Vector3>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector3 {
		Environment *obj = static_cast<Environment *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_sky_rotation();
	};
	proxy->setter = [this_val](const Vector3 &value) -> void {
		Environment *js_proxy = static_cast<Environment *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_sky_rotation(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector3Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector3Proxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue environment_class_set_bg_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_bg_color, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_bg_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		Environment *obj = static_cast<Environment *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_bg_color();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		Environment *js_proxy = static_cast<Environment *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_bg_color(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["ColorProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "ColorProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue environment_class_set_bg_energy_multiplier(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_bg_energy_multiplier, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_bg_energy_multiplier(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_bg_energy_multiplier, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_bg_intensity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_bg_intensity, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_bg_intensity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_bg_intensity, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_canvas_max_layer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_canvas_max_layer, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_canvas_max_layer(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_canvas_max_layer, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_camera_feed_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_camera_feed_id, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_camera_feed_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_camera_feed_id, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_ambient_light_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_ambient_light_color, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_ambient_light_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		Environment *obj = static_cast<Environment *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_ambient_light_color();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		Environment *js_proxy = static_cast<Environment *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_ambient_light_color(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["ColorProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "ColorProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue environment_class_set_ambient_source(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_ambient_source, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_ambient_source(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_ambient_source, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_ambient_light_energy(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_ambient_light_energy, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_ambient_light_energy(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_ambient_light_energy, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_ambient_light_sky_contribution(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_ambient_light_sky_contribution, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_ambient_light_sky_contribution(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_ambient_light_sky_contribution, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_reflection_source(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_reflection_source, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_reflection_source(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_reflection_source, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_tonemapper(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_tonemapper, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_tonemapper(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_tonemapper, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_tonemap_exposure(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_tonemap_exposure, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_tonemap_exposure(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_tonemap_exposure, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_tonemap_white(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_tonemap_white, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_tonemap_white(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_tonemap_white, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_ssr_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_ssr_enabled, ctx, this_val, argc, argv);
};
static JSValue environment_class_is_ssr_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::is_ssr_enabled, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_ssr_max_steps(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_ssr_max_steps, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_ssr_max_steps(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_ssr_max_steps, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_ssr_fade_in(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_ssr_fade_in, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_ssr_fade_in(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_ssr_fade_in, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_ssr_fade_out(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_ssr_fade_out, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_ssr_fade_out(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_ssr_fade_out, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_ssr_depth_tolerance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_ssr_depth_tolerance, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_ssr_depth_tolerance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_ssr_depth_tolerance, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_ssao_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_ssao_enabled, ctx, this_val, argc, argv);
};
static JSValue environment_class_is_ssao_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::is_ssao_enabled, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_ssao_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_ssao_radius, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_ssao_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_ssao_radius, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_ssao_intensity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_ssao_intensity, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_ssao_intensity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_ssao_intensity, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_ssao_power(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_ssao_power, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_ssao_power(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_ssao_power, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_ssao_detail(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_ssao_detail, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_ssao_detail(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_ssao_detail, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_ssao_horizon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_ssao_horizon, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_ssao_horizon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_ssao_horizon, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_ssao_sharpness(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_ssao_sharpness, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_ssao_sharpness(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_ssao_sharpness, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_ssao_direct_light_affect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_ssao_direct_light_affect, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_ssao_direct_light_affect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_ssao_direct_light_affect, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_ssao_ao_channel_affect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_ssao_ao_channel_affect, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_ssao_ao_channel_affect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_ssao_ao_channel_affect, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_ssil_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_ssil_enabled, ctx, this_val, argc, argv);
};
static JSValue environment_class_is_ssil_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::is_ssil_enabled, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_ssil_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_ssil_radius, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_ssil_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_ssil_radius, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_ssil_intensity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_ssil_intensity, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_ssil_intensity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_ssil_intensity, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_ssil_sharpness(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_ssil_sharpness, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_ssil_sharpness(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_ssil_sharpness, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_ssil_normal_rejection(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_ssil_normal_rejection, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_ssil_normal_rejection(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_ssil_normal_rejection, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_sdfgi_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_sdfgi_enabled, ctx, this_val, argc, argv);
};
static JSValue environment_class_is_sdfgi_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::is_sdfgi_enabled, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_sdfgi_cascades(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_sdfgi_cascades, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_sdfgi_cascades(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_sdfgi_cascades, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_sdfgi_min_cell_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_sdfgi_min_cell_size, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_sdfgi_min_cell_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_sdfgi_min_cell_size, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_sdfgi_max_distance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_sdfgi_max_distance, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_sdfgi_max_distance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_sdfgi_max_distance, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_sdfgi_cascade0_distance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_sdfgi_cascade0_distance, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_sdfgi_cascade0_distance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_sdfgi_cascade0_distance, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_sdfgi_y_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_sdfgi_y_scale, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_sdfgi_y_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_sdfgi_y_scale, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_sdfgi_use_occlusion(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_sdfgi_use_occlusion, ctx, this_val, argc, argv);
};
static JSValue environment_class_is_sdfgi_using_occlusion(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::is_sdfgi_using_occlusion, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_sdfgi_bounce_feedback(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_sdfgi_bounce_feedback, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_sdfgi_bounce_feedback(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_sdfgi_bounce_feedback, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_sdfgi_read_sky_light(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_sdfgi_read_sky_light, ctx, this_val, argc, argv);
};
static JSValue environment_class_is_sdfgi_reading_sky_light(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::is_sdfgi_reading_sky_light, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_sdfgi_energy(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_sdfgi_energy, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_sdfgi_energy(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_sdfgi_energy, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_sdfgi_normal_bias(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_sdfgi_normal_bias, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_sdfgi_normal_bias(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_sdfgi_normal_bias, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_sdfgi_probe_bias(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_sdfgi_probe_bias, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_sdfgi_probe_bias(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_sdfgi_probe_bias, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_glow_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_glow_enabled, ctx, this_val, argc, argv);
};
static JSValue environment_class_is_glow_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::is_glow_enabled, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_glow_level(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_glow_level, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_glow_level(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_glow_level, ctx, this_val, argc, argv);
};
static JSValue environment_class_set_glow_normalized(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_glow_normalized, ctx, this_val, argc, argv);
};
static JSValue environment_class_is_glow_normalized(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::is_glow_normalized, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_glow_intensity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_glow_intensity, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_glow_intensity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_glow_intensity, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_glow_strength(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_glow_strength, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_glow_strength(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_glow_strength, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_glow_mix(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_glow_mix, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_glow_mix(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_glow_mix, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_glow_bloom(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_glow_bloom, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_glow_bloom(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_glow_bloom, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_glow_blend_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_glow_blend_mode, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_glow_blend_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_glow_blend_mode, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_glow_hdr_bleed_threshold(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_glow_hdr_bleed_threshold, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_glow_hdr_bleed_threshold(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_glow_hdr_bleed_threshold, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_glow_hdr_bleed_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_glow_hdr_bleed_scale, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_glow_hdr_bleed_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_glow_hdr_bleed_scale, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_glow_hdr_luminance_cap(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_glow_hdr_luminance_cap, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_glow_hdr_luminance_cap(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_glow_hdr_luminance_cap, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_glow_map_strength(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_glow_map_strength, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_glow_map_strength(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_glow_map_strength, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_glow_map(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_glow_map, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_glow_map(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_glow_map, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_fog_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_fog_enabled, ctx, this_val, argc, argv);
};
static JSValue environment_class_is_fog_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::is_fog_enabled, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_fog_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_fog_mode, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_fog_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_fog_mode, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_fog_light_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_fog_light_color, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_fog_light_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		Environment *obj = static_cast<Environment *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_fog_light_color();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		Environment *js_proxy = static_cast<Environment *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_fog_light_color(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["ColorProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "ColorProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue environment_class_set_fog_light_energy(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_fog_light_energy, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_fog_light_energy(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_fog_light_energy, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_fog_sun_scatter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_fog_sun_scatter, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_fog_sun_scatter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_fog_sun_scatter, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_fog_density(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_fog_density, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_fog_density(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_fog_density, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_fog_height(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_fog_height, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_fog_height(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_fog_height, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_fog_height_density(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_fog_height_density, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_fog_height_density(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_fog_height_density, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_fog_aerial_perspective(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_fog_aerial_perspective, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_fog_aerial_perspective(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_fog_aerial_perspective, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_fog_sky_affect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_fog_sky_affect, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_fog_sky_affect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_fog_sky_affect, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_fog_depth_curve(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_fog_depth_curve, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_fog_depth_curve(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_fog_depth_curve, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_fog_depth_begin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_fog_depth_begin, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_fog_depth_begin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_fog_depth_begin, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_fog_depth_end(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_fog_depth_end, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_fog_depth_end(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_fog_depth_end, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_volumetric_fog_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_volumetric_fog_enabled, ctx, this_val, argc, argv);
};
static JSValue environment_class_is_volumetric_fog_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::is_volumetric_fog_enabled, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_volumetric_fog_emission(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_volumetric_fog_emission, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_volumetric_fog_emission(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		Environment *obj = static_cast<Environment *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_volumetric_fog_emission();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		Environment *js_proxy = static_cast<Environment *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_volumetric_fog_emission(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["ColorProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "ColorProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue environment_class_set_volumetric_fog_albedo(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_volumetric_fog_albedo, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_volumetric_fog_albedo(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		Environment *obj = static_cast<Environment *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_volumetric_fog_albedo();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		Environment *js_proxy = static_cast<Environment *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_volumetric_fog_albedo(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["ColorProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "ColorProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue environment_class_set_volumetric_fog_density(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_volumetric_fog_density, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_volumetric_fog_density(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_volumetric_fog_density, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_volumetric_fog_emission_energy(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_volumetric_fog_emission_energy, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_volumetric_fog_emission_energy(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_volumetric_fog_emission_energy, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_volumetric_fog_anisotropy(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_volumetric_fog_anisotropy, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_volumetric_fog_anisotropy(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_volumetric_fog_anisotropy, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_volumetric_fog_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_volumetric_fog_length, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_volumetric_fog_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_volumetric_fog_length, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_volumetric_fog_detail_spread(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_volumetric_fog_detail_spread, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_volumetric_fog_detail_spread(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_volumetric_fog_detail_spread, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_volumetric_fog_gi_inject(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_volumetric_fog_gi_inject, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_volumetric_fog_gi_inject(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_volumetric_fog_gi_inject, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_volumetric_fog_ambient_inject(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_volumetric_fog_ambient_inject, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_volumetric_fog_ambient_inject(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_volumetric_fog_ambient_inject, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_volumetric_fog_sky_affect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_volumetric_fog_sky_affect, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_volumetric_fog_sky_affect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_volumetric_fog_sky_affect, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_volumetric_fog_temporal_reprojection_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_volumetric_fog_temporal_reprojection_enabled, ctx, this_val, argc, argv);
};
static JSValue environment_class_is_volumetric_fog_temporal_reprojection_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::is_volumetric_fog_temporal_reprojection_enabled, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_volumetric_fog_temporal_reprojection_amount(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_volumetric_fog_temporal_reprojection_amount, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_volumetric_fog_temporal_reprojection_amount(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_volumetric_fog_temporal_reprojection_amount, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_adjustment_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_adjustment_enabled, ctx, this_val, argc, argv);
};
static JSValue environment_class_is_adjustment_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::is_adjustment_enabled, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_adjustment_brightness(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_adjustment_brightness, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_adjustment_brightness(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_adjustment_brightness, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_adjustment_contrast(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_adjustment_contrast, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_adjustment_contrast(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_adjustment_contrast, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_adjustment_saturation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_adjustment_saturation, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_adjustment_saturation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_adjustment_saturation, ctx, this_val, argc, argv);
}
static JSValue environment_class_set_adjustment_color_correction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Environment::set_adjustment_color_correction, ctx, this_val, argc, argv);
};
static JSValue environment_class_get_adjustment_color_correction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Environment::get_adjustment_color_correction, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry environment_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_background", 1, &environment_class_set_background),
	JS_CFUNC_DEF("get_background", 0, &environment_class_get_background),
	JS_CFUNC_DEF("set_sky", 1, &environment_class_set_sky),
	JS_CFUNC_DEF("get_sky", 0, &environment_class_get_sky),
	JS_CFUNC_DEF("set_sky_custom_fov", 1, &environment_class_set_sky_custom_fov),
	JS_CFUNC_DEF("get_sky_custom_fov", 0, &environment_class_get_sky_custom_fov),
	JS_CFUNC_DEF("set_sky_rotation", 1, &environment_class_set_sky_rotation),
	JS_CFUNC_DEF("get_sky_rotation", 0, &environment_class_get_sky_rotation),
	JS_CFUNC_DEF("set_bg_color", 1, &environment_class_set_bg_color),
	JS_CFUNC_DEF("get_bg_color", 0, &environment_class_get_bg_color),
	JS_CFUNC_DEF("set_bg_energy_multiplier", 1, &environment_class_set_bg_energy_multiplier),
	JS_CFUNC_DEF("get_bg_energy_multiplier", 0, &environment_class_get_bg_energy_multiplier),
	JS_CFUNC_DEF("set_bg_intensity", 1, &environment_class_set_bg_intensity),
	JS_CFUNC_DEF("get_bg_intensity", 0, &environment_class_get_bg_intensity),
	JS_CFUNC_DEF("set_canvas_max_layer", 1, &environment_class_set_canvas_max_layer),
	JS_CFUNC_DEF("get_canvas_max_layer", 0, &environment_class_get_canvas_max_layer),
	JS_CFUNC_DEF("set_camera_feed_id", 1, &environment_class_set_camera_feed_id),
	JS_CFUNC_DEF("get_camera_feed_id", 0, &environment_class_get_camera_feed_id),
	JS_CFUNC_DEF("set_ambient_light_color", 1, &environment_class_set_ambient_light_color),
	JS_CFUNC_DEF("get_ambient_light_color", 0, &environment_class_get_ambient_light_color),
	JS_CFUNC_DEF("set_ambient_source", 1, &environment_class_set_ambient_source),
	JS_CFUNC_DEF("get_ambient_source", 0, &environment_class_get_ambient_source),
	JS_CFUNC_DEF("set_ambient_light_energy", 1, &environment_class_set_ambient_light_energy),
	JS_CFUNC_DEF("get_ambient_light_energy", 0, &environment_class_get_ambient_light_energy),
	JS_CFUNC_DEF("set_ambient_light_sky_contribution", 1, &environment_class_set_ambient_light_sky_contribution),
	JS_CFUNC_DEF("get_ambient_light_sky_contribution", 0, &environment_class_get_ambient_light_sky_contribution),
	JS_CFUNC_DEF("set_reflection_source", 1, &environment_class_set_reflection_source),
	JS_CFUNC_DEF("get_reflection_source", 0, &environment_class_get_reflection_source),
	JS_CFUNC_DEF("set_tonemapper", 1, &environment_class_set_tonemapper),
	JS_CFUNC_DEF("get_tonemapper", 0, &environment_class_get_tonemapper),
	JS_CFUNC_DEF("set_tonemap_exposure", 1, &environment_class_set_tonemap_exposure),
	JS_CFUNC_DEF("get_tonemap_exposure", 0, &environment_class_get_tonemap_exposure),
	JS_CFUNC_DEF("set_tonemap_white", 1, &environment_class_set_tonemap_white),
	JS_CFUNC_DEF("get_tonemap_white", 0, &environment_class_get_tonemap_white),
	JS_CFUNC_DEF("set_ssr_enabled", 1, &environment_class_set_ssr_enabled),
	JS_CFUNC_DEF("is_ssr_enabled", 0, &environment_class_is_ssr_enabled),
	JS_CFUNC_DEF("set_ssr_max_steps", 1, &environment_class_set_ssr_max_steps),
	JS_CFUNC_DEF("get_ssr_max_steps", 0, &environment_class_get_ssr_max_steps),
	JS_CFUNC_DEF("set_ssr_fade_in", 1, &environment_class_set_ssr_fade_in),
	JS_CFUNC_DEF("get_ssr_fade_in", 0, &environment_class_get_ssr_fade_in),
	JS_CFUNC_DEF("set_ssr_fade_out", 1, &environment_class_set_ssr_fade_out),
	JS_CFUNC_DEF("get_ssr_fade_out", 0, &environment_class_get_ssr_fade_out),
	JS_CFUNC_DEF("set_ssr_depth_tolerance", 1, &environment_class_set_ssr_depth_tolerance),
	JS_CFUNC_DEF("get_ssr_depth_tolerance", 0, &environment_class_get_ssr_depth_tolerance),
	JS_CFUNC_DEF("set_ssao_enabled", 1, &environment_class_set_ssao_enabled),
	JS_CFUNC_DEF("is_ssao_enabled", 0, &environment_class_is_ssao_enabled),
	JS_CFUNC_DEF("set_ssao_radius", 1, &environment_class_set_ssao_radius),
	JS_CFUNC_DEF("get_ssao_radius", 0, &environment_class_get_ssao_radius),
	JS_CFUNC_DEF("set_ssao_intensity", 1, &environment_class_set_ssao_intensity),
	JS_CFUNC_DEF("get_ssao_intensity", 0, &environment_class_get_ssao_intensity),
	JS_CFUNC_DEF("set_ssao_power", 1, &environment_class_set_ssao_power),
	JS_CFUNC_DEF("get_ssao_power", 0, &environment_class_get_ssao_power),
	JS_CFUNC_DEF("set_ssao_detail", 1, &environment_class_set_ssao_detail),
	JS_CFUNC_DEF("get_ssao_detail", 0, &environment_class_get_ssao_detail),
	JS_CFUNC_DEF("set_ssao_horizon", 1, &environment_class_set_ssao_horizon),
	JS_CFUNC_DEF("get_ssao_horizon", 0, &environment_class_get_ssao_horizon),
	JS_CFUNC_DEF("set_ssao_sharpness", 1, &environment_class_set_ssao_sharpness),
	JS_CFUNC_DEF("get_ssao_sharpness", 0, &environment_class_get_ssao_sharpness),
	JS_CFUNC_DEF("set_ssao_direct_light_affect", 1, &environment_class_set_ssao_direct_light_affect),
	JS_CFUNC_DEF("get_ssao_direct_light_affect", 0, &environment_class_get_ssao_direct_light_affect),
	JS_CFUNC_DEF("set_ssao_ao_channel_affect", 1, &environment_class_set_ssao_ao_channel_affect),
	JS_CFUNC_DEF("get_ssao_ao_channel_affect", 0, &environment_class_get_ssao_ao_channel_affect),
	JS_CFUNC_DEF("set_ssil_enabled", 1, &environment_class_set_ssil_enabled),
	JS_CFUNC_DEF("is_ssil_enabled", 0, &environment_class_is_ssil_enabled),
	JS_CFUNC_DEF("set_ssil_radius", 1, &environment_class_set_ssil_radius),
	JS_CFUNC_DEF("get_ssil_radius", 0, &environment_class_get_ssil_radius),
	JS_CFUNC_DEF("set_ssil_intensity", 1, &environment_class_set_ssil_intensity),
	JS_CFUNC_DEF("get_ssil_intensity", 0, &environment_class_get_ssil_intensity),
	JS_CFUNC_DEF("set_ssil_sharpness", 1, &environment_class_set_ssil_sharpness),
	JS_CFUNC_DEF("get_ssil_sharpness", 0, &environment_class_get_ssil_sharpness),
	JS_CFUNC_DEF("set_ssil_normal_rejection", 1, &environment_class_set_ssil_normal_rejection),
	JS_CFUNC_DEF("get_ssil_normal_rejection", 0, &environment_class_get_ssil_normal_rejection),
	JS_CFUNC_DEF("set_sdfgi_enabled", 1, &environment_class_set_sdfgi_enabled),
	JS_CFUNC_DEF("is_sdfgi_enabled", 0, &environment_class_is_sdfgi_enabled),
	JS_CFUNC_DEF("set_sdfgi_cascades", 1, &environment_class_set_sdfgi_cascades),
	JS_CFUNC_DEF("get_sdfgi_cascades", 0, &environment_class_get_sdfgi_cascades),
	JS_CFUNC_DEF("set_sdfgi_min_cell_size", 1, &environment_class_set_sdfgi_min_cell_size),
	JS_CFUNC_DEF("get_sdfgi_min_cell_size", 0, &environment_class_get_sdfgi_min_cell_size),
	JS_CFUNC_DEF("set_sdfgi_max_distance", 1, &environment_class_set_sdfgi_max_distance),
	JS_CFUNC_DEF("get_sdfgi_max_distance", 0, &environment_class_get_sdfgi_max_distance),
	JS_CFUNC_DEF("set_sdfgi_cascade0_distance", 1, &environment_class_set_sdfgi_cascade0_distance),
	JS_CFUNC_DEF("get_sdfgi_cascade0_distance", 0, &environment_class_get_sdfgi_cascade0_distance),
	JS_CFUNC_DEF("set_sdfgi_y_scale", 1, &environment_class_set_sdfgi_y_scale),
	JS_CFUNC_DEF("get_sdfgi_y_scale", 0, &environment_class_get_sdfgi_y_scale),
	JS_CFUNC_DEF("set_sdfgi_use_occlusion", 1, &environment_class_set_sdfgi_use_occlusion),
	JS_CFUNC_DEF("is_sdfgi_using_occlusion", 0, &environment_class_is_sdfgi_using_occlusion),
	JS_CFUNC_DEF("set_sdfgi_bounce_feedback", 1, &environment_class_set_sdfgi_bounce_feedback),
	JS_CFUNC_DEF("get_sdfgi_bounce_feedback", 0, &environment_class_get_sdfgi_bounce_feedback),
	JS_CFUNC_DEF("set_sdfgi_read_sky_light", 1, &environment_class_set_sdfgi_read_sky_light),
	JS_CFUNC_DEF("is_sdfgi_reading_sky_light", 0, &environment_class_is_sdfgi_reading_sky_light),
	JS_CFUNC_DEF("set_sdfgi_energy", 1, &environment_class_set_sdfgi_energy),
	JS_CFUNC_DEF("get_sdfgi_energy", 0, &environment_class_get_sdfgi_energy),
	JS_CFUNC_DEF("set_sdfgi_normal_bias", 1, &environment_class_set_sdfgi_normal_bias),
	JS_CFUNC_DEF("get_sdfgi_normal_bias", 0, &environment_class_get_sdfgi_normal_bias),
	JS_CFUNC_DEF("set_sdfgi_probe_bias", 1, &environment_class_set_sdfgi_probe_bias),
	JS_CFUNC_DEF("get_sdfgi_probe_bias", 0, &environment_class_get_sdfgi_probe_bias),
	JS_CFUNC_DEF("set_glow_enabled", 1, &environment_class_set_glow_enabled),
	JS_CFUNC_DEF("is_glow_enabled", 0, &environment_class_is_glow_enabled),
	JS_CFUNC_DEF("set_glow_level", 2, &environment_class_set_glow_level),
	JS_CFUNC_DEF("get_glow_level", 1, &environment_class_get_glow_level),
	JS_CFUNC_DEF("set_glow_normalized", 1, &environment_class_set_glow_normalized),
	JS_CFUNC_DEF("is_glow_normalized", 0, &environment_class_is_glow_normalized),
	JS_CFUNC_DEF("set_glow_intensity", 1, &environment_class_set_glow_intensity),
	JS_CFUNC_DEF("get_glow_intensity", 0, &environment_class_get_glow_intensity),
	JS_CFUNC_DEF("set_glow_strength", 1, &environment_class_set_glow_strength),
	JS_CFUNC_DEF("get_glow_strength", 0, &environment_class_get_glow_strength),
	JS_CFUNC_DEF("set_glow_mix", 1, &environment_class_set_glow_mix),
	JS_CFUNC_DEF("get_glow_mix", 0, &environment_class_get_glow_mix),
	JS_CFUNC_DEF("set_glow_bloom", 1, &environment_class_set_glow_bloom),
	JS_CFUNC_DEF("get_glow_bloom", 0, &environment_class_get_glow_bloom),
	JS_CFUNC_DEF("set_glow_blend_mode", 1, &environment_class_set_glow_blend_mode),
	JS_CFUNC_DEF("get_glow_blend_mode", 0, &environment_class_get_glow_blend_mode),
	JS_CFUNC_DEF("set_glow_hdr_bleed_threshold", 1, &environment_class_set_glow_hdr_bleed_threshold),
	JS_CFUNC_DEF("get_glow_hdr_bleed_threshold", 0, &environment_class_get_glow_hdr_bleed_threshold),
	JS_CFUNC_DEF("set_glow_hdr_bleed_scale", 1, &environment_class_set_glow_hdr_bleed_scale),
	JS_CFUNC_DEF("get_glow_hdr_bleed_scale", 0, &environment_class_get_glow_hdr_bleed_scale),
	JS_CFUNC_DEF("set_glow_hdr_luminance_cap", 1, &environment_class_set_glow_hdr_luminance_cap),
	JS_CFUNC_DEF("get_glow_hdr_luminance_cap", 0, &environment_class_get_glow_hdr_luminance_cap),
	JS_CFUNC_DEF("set_glow_map_strength", 1, &environment_class_set_glow_map_strength),
	JS_CFUNC_DEF("get_glow_map_strength", 0, &environment_class_get_glow_map_strength),
	JS_CFUNC_DEF("set_glow_map", 1, &environment_class_set_glow_map),
	JS_CFUNC_DEF("get_glow_map", 0, &environment_class_get_glow_map),
	JS_CFUNC_DEF("set_fog_enabled", 1, &environment_class_set_fog_enabled),
	JS_CFUNC_DEF("is_fog_enabled", 0, &environment_class_is_fog_enabled),
	JS_CFUNC_DEF("set_fog_mode", 1, &environment_class_set_fog_mode),
	JS_CFUNC_DEF("get_fog_mode", 0, &environment_class_get_fog_mode),
	JS_CFUNC_DEF("set_fog_light_color", 1, &environment_class_set_fog_light_color),
	JS_CFUNC_DEF("get_fog_light_color", 0, &environment_class_get_fog_light_color),
	JS_CFUNC_DEF("set_fog_light_energy", 1, &environment_class_set_fog_light_energy),
	JS_CFUNC_DEF("get_fog_light_energy", 0, &environment_class_get_fog_light_energy),
	JS_CFUNC_DEF("set_fog_sun_scatter", 1, &environment_class_set_fog_sun_scatter),
	JS_CFUNC_DEF("get_fog_sun_scatter", 0, &environment_class_get_fog_sun_scatter),
	JS_CFUNC_DEF("set_fog_density", 1, &environment_class_set_fog_density),
	JS_CFUNC_DEF("get_fog_density", 0, &environment_class_get_fog_density),
	JS_CFUNC_DEF("set_fog_height", 1, &environment_class_set_fog_height),
	JS_CFUNC_DEF("get_fog_height", 0, &environment_class_get_fog_height),
	JS_CFUNC_DEF("set_fog_height_density", 1, &environment_class_set_fog_height_density),
	JS_CFUNC_DEF("get_fog_height_density", 0, &environment_class_get_fog_height_density),
	JS_CFUNC_DEF("set_fog_aerial_perspective", 1, &environment_class_set_fog_aerial_perspective),
	JS_CFUNC_DEF("get_fog_aerial_perspective", 0, &environment_class_get_fog_aerial_perspective),
	JS_CFUNC_DEF("set_fog_sky_affect", 1, &environment_class_set_fog_sky_affect),
	JS_CFUNC_DEF("get_fog_sky_affect", 0, &environment_class_get_fog_sky_affect),
	JS_CFUNC_DEF("set_fog_depth_curve", 1, &environment_class_set_fog_depth_curve),
	JS_CFUNC_DEF("get_fog_depth_curve", 0, &environment_class_get_fog_depth_curve),
	JS_CFUNC_DEF("set_fog_depth_begin", 1, &environment_class_set_fog_depth_begin),
	JS_CFUNC_DEF("get_fog_depth_begin", 0, &environment_class_get_fog_depth_begin),
	JS_CFUNC_DEF("set_fog_depth_end", 1, &environment_class_set_fog_depth_end),
	JS_CFUNC_DEF("get_fog_depth_end", 0, &environment_class_get_fog_depth_end),
	JS_CFUNC_DEF("set_volumetric_fog_enabled", 1, &environment_class_set_volumetric_fog_enabled),
	JS_CFUNC_DEF("is_volumetric_fog_enabled", 0, &environment_class_is_volumetric_fog_enabled),
	JS_CFUNC_DEF("set_volumetric_fog_emission", 1, &environment_class_set_volumetric_fog_emission),
	JS_CFUNC_DEF("get_volumetric_fog_emission", 0, &environment_class_get_volumetric_fog_emission),
	JS_CFUNC_DEF("set_volumetric_fog_albedo", 1, &environment_class_set_volumetric_fog_albedo),
	JS_CFUNC_DEF("get_volumetric_fog_albedo", 0, &environment_class_get_volumetric_fog_albedo),
	JS_CFUNC_DEF("set_volumetric_fog_density", 1, &environment_class_set_volumetric_fog_density),
	JS_CFUNC_DEF("get_volumetric_fog_density", 0, &environment_class_get_volumetric_fog_density),
	JS_CFUNC_DEF("set_volumetric_fog_emission_energy", 1, &environment_class_set_volumetric_fog_emission_energy),
	JS_CFUNC_DEF("get_volumetric_fog_emission_energy", 0, &environment_class_get_volumetric_fog_emission_energy),
	JS_CFUNC_DEF("set_volumetric_fog_anisotropy", 1, &environment_class_set_volumetric_fog_anisotropy),
	JS_CFUNC_DEF("get_volumetric_fog_anisotropy", 0, &environment_class_get_volumetric_fog_anisotropy),
	JS_CFUNC_DEF("set_volumetric_fog_length", 1, &environment_class_set_volumetric_fog_length),
	JS_CFUNC_DEF("get_volumetric_fog_length", 0, &environment_class_get_volumetric_fog_length),
	JS_CFUNC_DEF("set_volumetric_fog_detail_spread", 1, &environment_class_set_volumetric_fog_detail_spread),
	JS_CFUNC_DEF("get_volumetric_fog_detail_spread", 0, &environment_class_get_volumetric_fog_detail_spread),
	JS_CFUNC_DEF("set_volumetric_fog_gi_inject", 1, &environment_class_set_volumetric_fog_gi_inject),
	JS_CFUNC_DEF("get_volumetric_fog_gi_inject", 0, &environment_class_get_volumetric_fog_gi_inject),
	JS_CFUNC_DEF("set_volumetric_fog_ambient_inject", 1, &environment_class_set_volumetric_fog_ambient_inject),
	JS_CFUNC_DEF("get_volumetric_fog_ambient_inject", 0, &environment_class_get_volumetric_fog_ambient_inject),
	JS_CFUNC_DEF("set_volumetric_fog_sky_affect", 1, &environment_class_set_volumetric_fog_sky_affect),
	JS_CFUNC_DEF("get_volumetric_fog_sky_affect", 0, &environment_class_get_volumetric_fog_sky_affect),
	JS_CFUNC_DEF("set_volumetric_fog_temporal_reprojection_enabled", 1, &environment_class_set_volumetric_fog_temporal_reprojection_enabled),
	JS_CFUNC_DEF("is_volumetric_fog_temporal_reprojection_enabled", 0, &environment_class_is_volumetric_fog_temporal_reprojection_enabled),
	JS_CFUNC_DEF("set_volumetric_fog_temporal_reprojection_amount", 1, &environment_class_set_volumetric_fog_temporal_reprojection_amount),
	JS_CFUNC_DEF("get_volumetric_fog_temporal_reprojection_amount", 0, &environment_class_get_volumetric_fog_temporal_reprojection_amount),
	JS_CFUNC_DEF("set_adjustment_enabled", 1, &environment_class_set_adjustment_enabled),
	JS_CFUNC_DEF("is_adjustment_enabled", 0, &environment_class_is_adjustment_enabled),
	JS_CFUNC_DEF("set_adjustment_brightness", 1, &environment_class_set_adjustment_brightness),
	JS_CFUNC_DEF("get_adjustment_brightness", 0, &environment_class_get_adjustment_brightness),
	JS_CFUNC_DEF("set_adjustment_contrast", 1, &environment_class_set_adjustment_contrast),
	JS_CFUNC_DEF("get_adjustment_contrast", 0, &environment_class_get_adjustment_contrast),
	JS_CFUNC_DEF("set_adjustment_saturation", 1, &environment_class_set_adjustment_saturation),
	JS_CFUNC_DEF("get_adjustment_saturation", 0, &environment_class_get_adjustment_saturation),
	JS_CFUNC_DEF("set_adjustment_color_correction", 1, &environment_class_set_adjustment_color_correction),
	JS_CFUNC_DEF("get_adjustment_color_correction", 0, &environment_class_get_adjustment_color_correction),
};




static void define_environment_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "background_mode"),
        JS_NewCFunction(ctx, environment_class_get_background, "get_background", 0),
        JS_NewCFunction(ctx, environment_class_set_background, "set_background", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "background_color"),
        JS_NewCFunction(ctx, environment_class_get_bg_color, "get_bg_color", 0),
        JS_NewCFunction(ctx, environment_class_set_bg_color, "set_bg_color", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "background_energy_multiplier"),
        JS_NewCFunction(ctx, environment_class_get_bg_energy_multiplier, "get_bg_energy_multiplier", 0),
        JS_NewCFunction(ctx, environment_class_set_bg_energy_multiplier, "set_bg_energy_multiplier", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "background_intensity"),
        JS_NewCFunction(ctx, environment_class_get_bg_intensity, "get_bg_intensity", 0),
        JS_NewCFunction(ctx, environment_class_set_bg_intensity, "set_bg_intensity", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "background_canvas_max_layer"),
        JS_NewCFunction(ctx, environment_class_get_canvas_max_layer, "get_canvas_max_layer", 0),
        JS_NewCFunction(ctx, environment_class_set_canvas_max_layer, "set_canvas_max_layer", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "background_camera_feed_id"),
        JS_NewCFunction(ctx, environment_class_get_camera_feed_id, "get_camera_feed_id", 0),
        JS_NewCFunction(ctx, environment_class_set_camera_feed_id, "set_camera_feed_id", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "sky"),
        JS_NewCFunction(ctx, environment_class_get_sky, "get_sky", 0),
        JS_NewCFunction(ctx, environment_class_set_sky, "set_sky", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "sky_custom_fov"),
        JS_NewCFunction(ctx, environment_class_get_sky_custom_fov, "get_sky_custom_fov", 0),
        JS_NewCFunction(ctx, environment_class_set_sky_custom_fov, "set_sky_custom_fov", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "sky_rotation"),
        JS_NewCFunction(ctx, environment_class_get_sky_rotation, "get_sky_rotation", 0),
        JS_NewCFunction(ctx, environment_class_set_sky_rotation, "set_sky_rotation", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "ambient_light_source"),
        JS_NewCFunction(ctx, environment_class_get_ambient_source, "get_ambient_source", 0),
        JS_NewCFunction(ctx, environment_class_set_ambient_source, "set_ambient_source", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "ambient_light_color"),
        JS_NewCFunction(ctx, environment_class_get_ambient_light_color, "get_ambient_light_color", 0),
        JS_NewCFunction(ctx, environment_class_set_ambient_light_color, "set_ambient_light_color", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "ambient_light_sky_contribution"),
        JS_NewCFunction(ctx, environment_class_get_ambient_light_sky_contribution, "get_ambient_light_sky_contribution", 0),
        JS_NewCFunction(ctx, environment_class_set_ambient_light_sky_contribution, "set_ambient_light_sky_contribution", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "ambient_light_energy"),
        JS_NewCFunction(ctx, environment_class_get_ambient_light_energy, "get_ambient_light_energy", 0),
        JS_NewCFunction(ctx, environment_class_set_ambient_light_energy, "set_ambient_light_energy", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "reflected_light_source"),
        JS_NewCFunction(ctx, environment_class_get_reflection_source, "get_reflection_source", 0),
        JS_NewCFunction(ctx, environment_class_set_reflection_source, "set_reflection_source", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "tonemap_mode"),
        JS_NewCFunction(ctx, environment_class_get_tonemapper, "get_tonemapper", 0),
        JS_NewCFunction(ctx, environment_class_set_tonemapper, "set_tonemapper", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "tonemap_exposure"),
        JS_NewCFunction(ctx, environment_class_get_tonemap_exposure, "get_tonemap_exposure", 0),
        JS_NewCFunction(ctx, environment_class_set_tonemap_exposure, "set_tonemap_exposure", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "tonemap_white"),
        JS_NewCFunction(ctx, environment_class_get_tonemap_white, "get_tonemap_white", 0),
        JS_NewCFunction(ctx, environment_class_set_tonemap_white, "set_tonemap_white", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "ssr_enabled"),
        JS_NewCFunction(ctx, environment_class_is_ssr_enabled, "is_ssr_enabled", 0),
        JS_NewCFunction(ctx, environment_class_set_ssr_enabled, "set_ssr_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "ssr_max_steps"),
        JS_NewCFunction(ctx, environment_class_get_ssr_max_steps, "get_ssr_max_steps", 0),
        JS_NewCFunction(ctx, environment_class_set_ssr_max_steps, "set_ssr_max_steps", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "ssr_fade_in"),
        JS_NewCFunction(ctx, environment_class_get_ssr_fade_in, "get_ssr_fade_in", 0),
        JS_NewCFunction(ctx, environment_class_set_ssr_fade_in, "set_ssr_fade_in", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "ssr_fade_out"),
        JS_NewCFunction(ctx, environment_class_get_ssr_fade_out, "get_ssr_fade_out", 0),
        JS_NewCFunction(ctx, environment_class_set_ssr_fade_out, "set_ssr_fade_out", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "ssr_depth_tolerance"),
        JS_NewCFunction(ctx, environment_class_get_ssr_depth_tolerance, "get_ssr_depth_tolerance", 0),
        JS_NewCFunction(ctx, environment_class_set_ssr_depth_tolerance, "set_ssr_depth_tolerance", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "ssao_enabled"),
        JS_NewCFunction(ctx, environment_class_is_ssao_enabled, "is_ssao_enabled", 0),
        JS_NewCFunction(ctx, environment_class_set_ssao_enabled, "set_ssao_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "ssao_radius"),
        JS_NewCFunction(ctx, environment_class_get_ssao_radius, "get_ssao_radius", 0),
        JS_NewCFunction(ctx, environment_class_set_ssao_radius, "set_ssao_radius", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "ssao_intensity"),
        JS_NewCFunction(ctx, environment_class_get_ssao_intensity, "get_ssao_intensity", 0),
        JS_NewCFunction(ctx, environment_class_set_ssao_intensity, "set_ssao_intensity", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "ssao_power"),
        JS_NewCFunction(ctx, environment_class_get_ssao_power, "get_ssao_power", 0),
        JS_NewCFunction(ctx, environment_class_set_ssao_power, "set_ssao_power", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "ssao_detail"),
        JS_NewCFunction(ctx, environment_class_get_ssao_detail, "get_ssao_detail", 0),
        JS_NewCFunction(ctx, environment_class_set_ssao_detail, "set_ssao_detail", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "ssao_horizon"),
        JS_NewCFunction(ctx, environment_class_get_ssao_horizon, "get_ssao_horizon", 0),
        JS_NewCFunction(ctx, environment_class_set_ssao_horizon, "set_ssao_horizon", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "ssao_sharpness"),
        JS_NewCFunction(ctx, environment_class_get_ssao_sharpness, "get_ssao_sharpness", 0),
        JS_NewCFunction(ctx, environment_class_set_ssao_sharpness, "set_ssao_sharpness", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "ssao_light_affect"),
        JS_NewCFunction(ctx, environment_class_get_ssao_direct_light_affect, "get_ssao_direct_light_affect", 0),
        JS_NewCFunction(ctx, environment_class_set_ssao_direct_light_affect, "set_ssao_direct_light_affect", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "ssao_ao_channel_affect"),
        JS_NewCFunction(ctx, environment_class_get_ssao_ao_channel_affect, "get_ssao_ao_channel_affect", 0),
        JS_NewCFunction(ctx, environment_class_set_ssao_ao_channel_affect, "set_ssao_ao_channel_affect", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "ssil_enabled"),
        JS_NewCFunction(ctx, environment_class_is_ssil_enabled, "is_ssil_enabled", 0),
        JS_NewCFunction(ctx, environment_class_set_ssil_enabled, "set_ssil_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "ssil_radius"),
        JS_NewCFunction(ctx, environment_class_get_ssil_radius, "get_ssil_radius", 0),
        JS_NewCFunction(ctx, environment_class_set_ssil_radius, "set_ssil_radius", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "ssil_intensity"),
        JS_NewCFunction(ctx, environment_class_get_ssil_intensity, "get_ssil_intensity", 0),
        JS_NewCFunction(ctx, environment_class_set_ssil_intensity, "set_ssil_intensity", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "ssil_sharpness"),
        JS_NewCFunction(ctx, environment_class_get_ssil_sharpness, "get_ssil_sharpness", 0),
        JS_NewCFunction(ctx, environment_class_set_ssil_sharpness, "set_ssil_sharpness", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "ssil_normal_rejection"),
        JS_NewCFunction(ctx, environment_class_get_ssil_normal_rejection, "get_ssil_normal_rejection", 0),
        JS_NewCFunction(ctx, environment_class_set_ssil_normal_rejection, "set_ssil_normal_rejection", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "sdfgi_enabled"),
        JS_NewCFunction(ctx, environment_class_is_sdfgi_enabled, "is_sdfgi_enabled", 0),
        JS_NewCFunction(ctx, environment_class_set_sdfgi_enabled, "set_sdfgi_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "sdfgi_use_occlusion"),
        JS_NewCFunction(ctx, environment_class_is_sdfgi_using_occlusion, "is_sdfgi_using_occlusion", 0),
        JS_NewCFunction(ctx, environment_class_set_sdfgi_use_occlusion, "set_sdfgi_use_occlusion", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "sdfgi_read_sky_light"),
        JS_NewCFunction(ctx, environment_class_is_sdfgi_reading_sky_light, "is_sdfgi_reading_sky_light", 0),
        JS_NewCFunction(ctx, environment_class_set_sdfgi_read_sky_light, "set_sdfgi_read_sky_light", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "sdfgi_bounce_feedback"),
        JS_NewCFunction(ctx, environment_class_get_sdfgi_bounce_feedback, "get_sdfgi_bounce_feedback", 0),
        JS_NewCFunction(ctx, environment_class_set_sdfgi_bounce_feedback, "set_sdfgi_bounce_feedback", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "sdfgi_cascades"),
        JS_NewCFunction(ctx, environment_class_get_sdfgi_cascades, "get_sdfgi_cascades", 0),
        JS_NewCFunction(ctx, environment_class_set_sdfgi_cascades, "set_sdfgi_cascades", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "sdfgi_min_cell_size"),
        JS_NewCFunction(ctx, environment_class_get_sdfgi_min_cell_size, "get_sdfgi_min_cell_size", 0),
        JS_NewCFunction(ctx, environment_class_set_sdfgi_min_cell_size, "set_sdfgi_min_cell_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "sdfgi_cascade0_distance"),
        JS_NewCFunction(ctx, environment_class_get_sdfgi_cascade0_distance, "get_sdfgi_cascade0_distance", 0),
        JS_NewCFunction(ctx, environment_class_set_sdfgi_cascade0_distance, "set_sdfgi_cascade0_distance", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "sdfgi_max_distance"),
        JS_NewCFunction(ctx, environment_class_get_sdfgi_max_distance, "get_sdfgi_max_distance", 0),
        JS_NewCFunction(ctx, environment_class_set_sdfgi_max_distance, "set_sdfgi_max_distance", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "sdfgi_y_scale"),
        JS_NewCFunction(ctx, environment_class_get_sdfgi_y_scale, "get_sdfgi_y_scale", 0),
        JS_NewCFunction(ctx, environment_class_set_sdfgi_y_scale, "set_sdfgi_y_scale", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "sdfgi_energy"),
        JS_NewCFunction(ctx, environment_class_get_sdfgi_energy, "get_sdfgi_energy", 0),
        JS_NewCFunction(ctx, environment_class_set_sdfgi_energy, "set_sdfgi_energy", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "sdfgi_normal_bias"),
        JS_NewCFunction(ctx, environment_class_get_sdfgi_normal_bias, "get_sdfgi_normal_bias", 0),
        JS_NewCFunction(ctx, environment_class_set_sdfgi_normal_bias, "set_sdfgi_normal_bias", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "sdfgi_probe_bias"),
        JS_NewCFunction(ctx, environment_class_get_sdfgi_probe_bias, "get_sdfgi_probe_bias", 0),
        JS_NewCFunction(ctx, environment_class_set_sdfgi_probe_bias, "set_sdfgi_probe_bias", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "glow_enabled"),
        JS_NewCFunction(ctx, environment_class_is_glow_enabled, "is_glow_enabled", 0),
        JS_NewCFunction(ctx, environment_class_set_glow_enabled, "set_glow_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "glow_normalized"),
        JS_NewCFunction(ctx, environment_class_is_glow_normalized, "is_glow_normalized", 0),
        JS_NewCFunction(ctx, environment_class_set_glow_normalized, "set_glow_normalized", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "glow_intensity"),
        JS_NewCFunction(ctx, environment_class_get_glow_intensity, "get_glow_intensity", 0),
        JS_NewCFunction(ctx, environment_class_set_glow_intensity, "set_glow_intensity", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "glow_strength"),
        JS_NewCFunction(ctx, environment_class_get_glow_strength, "get_glow_strength", 0),
        JS_NewCFunction(ctx, environment_class_set_glow_strength, "set_glow_strength", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "glow_mix"),
        JS_NewCFunction(ctx, environment_class_get_glow_mix, "get_glow_mix", 0),
        JS_NewCFunction(ctx, environment_class_set_glow_mix, "set_glow_mix", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "glow_bloom"),
        JS_NewCFunction(ctx, environment_class_get_glow_bloom, "get_glow_bloom", 0),
        JS_NewCFunction(ctx, environment_class_set_glow_bloom, "set_glow_bloom", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "glow_blend_mode"),
        JS_NewCFunction(ctx, environment_class_get_glow_blend_mode, "get_glow_blend_mode", 0),
        JS_NewCFunction(ctx, environment_class_set_glow_blend_mode, "set_glow_blend_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "glow_hdr_threshold"),
        JS_NewCFunction(ctx, environment_class_get_glow_hdr_bleed_threshold, "get_glow_hdr_bleed_threshold", 0),
        JS_NewCFunction(ctx, environment_class_set_glow_hdr_bleed_threshold, "set_glow_hdr_bleed_threshold", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "glow_hdr_scale"),
        JS_NewCFunction(ctx, environment_class_get_glow_hdr_bleed_scale, "get_glow_hdr_bleed_scale", 0),
        JS_NewCFunction(ctx, environment_class_set_glow_hdr_bleed_scale, "set_glow_hdr_bleed_scale", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "glow_hdr_luminance_cap"),
        JS_NewCFunction(ctx, environment_class_get_glow_hdr_luminance_cap, "get_glow_hdr_luminance_cap", 0),
        JS_NewCFunction(ctx, environment_class_set_glow_hdr_luminance_cap, "set_glow_hdr_luminance_cap", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "glow_map_strength"),
        JS_NewCFunction(ctx, environment_class_get_glow_map_strength, "get_glow_map_strength", 0),
        JS_NewCFunction(ctx, environment_class_set_glow_map_strength, "set_glow_map_strength", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "glow_map"),
        JS_NewCFunction(ctx, environment_class_get_glow_map, "get_glow_map", 0),
        JS_NewCFunction(ctx, environment_class_set_glow_map, "set_glow_map", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "fog_enabled"),
        JS_NewCFunction(ctx, environment_class_is_fog_enabled, "is_fog_enabled", 0),
        JS_NewCFunction(ctx, environment_class_set_fog_enabled, "set_fog_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "fog_mode"),
        JS_NewCFunction(ctx, environment_class_get_fog_mode, "get_fog_mode", 0),
        JS_NewCFunction(ctx, environment_class_set_fog_mode, "set_fog_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "fog_light_color"),
        JS_NewCFunction(ctx, environment_class_get_fog_light_color, "get_fog_light_color", 0),
        JS_NewCFunction(ctx, environment_class_set_fog_light_color, "set_fog_light_color", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "fog_light_energy"),
        JS_NewCFunction(ctx, environment_class_get_fog_light_energy, "get_fog_light_energy", 0),
        JS_NewCFunction(ctx, environment_class_set_fog_light_energy, "set_fog_light_energy", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "fog_sun_scatter"),
        JS_NewCFunction(ctx, environment_class_get_fog_sun_scatter, "get_fog_sun_scatter", 0),
        JS_NewCFunction(ctx, environment_class_set_fog_sun_scatter, "set_fog_sun_scatter", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "fog_density"),
        JS_NewCFunction(ctx, environment_class_get_fog_density, "get_fog_density", 0),
        JS_NewCFunction(ctx, environment_class_set_fog_density, "set_fog_density", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "fog_aerial_perspective"),
        JS_NewCFunction(ctx, environment_class_get_fog_aerial_perspective, "get_fog_aerial_perspective", 0),
        JS_NewCFunction(ctx, environment_class_set_fog_aerial_perspective, "set_fog_aerial_perspective", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "fog_sky_affect"),
        JS_NewCFunction(ctx, environment_class_get_fog_sky_affect, "get_fog_sky_affect", 0),
        JS_NewCFunction(ctx, environment_class_set_fog_sky_affect, "set_fog_sky_affect", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "fog_height"),
        JS_NewCFunction(ctx, environment_class_get_fog_height, "get_fog_height", 0),
        JS_NewCFunction(ctx, environment_class_set_fog_height, "set_fog_height", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "fog_height_density"),
        JS_NewCFunction(ctx, environment_class_get_fog_height_density, "get_fog_height_density", 0),
        JS_NewCFunction(ctx, environment_class_set_fog_height_density, "set_fog_height_density", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "fog_depth_curve"),
        JS_NewCFunction(ctx, environment_class_get_fog_depth_curve, "get_fog_depth_curve", 0),
        JS_NewCFunction(ctx, environment_class_set_fog_depth_curve, "set_fog_depth_curve", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "fog_depth_begin"),
        JS_NewCFunction(ctx, environment_class_get_fog_depth_begin, "get_fog_depth_begin", 0),
        JS_NewCFunction(ctx, environment_class_set_fog_depth_begin, "set_fog_depth_begin", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "fog_depth_end"),
        JS_NewCFunction(ctx, environment_class_get_fog_depth_end, "get_fog_depth_end", 0),
        JS_NewCFunction(ctx, environment_class_set_fog_depth_end, "set_fog_depth_end", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "volumetric_fog_enabled"),
        JS_NewCFunction(ctx, environment_class_is_volumetric_fog_enabled, "is_volumetric_fog_enabled", 0),
        JS_NewCFunction(ctx, environment_class_set_volumetric_fog_enabled, "set_volumetric_fog_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "volumetric_fog_density"),
        JS_NewCFunction(ctx, environment_class_get_volumetric_fog_density, "get_volumetric_fog_density", 0),
        JS_NewCFunction(ctx, environment_class_set_volumetric_fog_density, "set_volumetric_fog_density", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "volumetric_fog_albedo"),
        JS_NewCFunction(ctx, environment_class_get_volumetric_fog_albedo, "get_volumetric_fog_albedo", 0),
        JS_NewCFunction(ctx, environment_class_set_volumetric_fog_albedo, "set_volumetric_fog_albedo", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "volumetric_fog_emission"),
        JS_NewCFunction(ctx, environment_class_get_volumetric_fog_emission, "get_volumetric_fog_emission", 0),
        JS_NewCFunction(ctx, environment_class_set_volumetric_fog_emission, "set_volumetric_fog_emission", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "volumetric_fog_emission_energy"),
        JS_NewCFunction(ctx, environment_class_get_volumetric_fog_emission_energy, "get_volumetric_fog_emission_energy", 0),
        JS_NewCFunction(ctx, environment_class_set_volumetric_fog_emission_energy, "set_volumetric_fog_emission_energy", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "volumetric_fog_gi_inject"),
        JS_NewCFunction(ctx, environment_class_get_volumetric_fog_gi_inject, "get_volumetric_fog_gi_inject", 0),
        JS_NewCFunction(ctx, environment_class_set_volumetric_fog_gi_inject, "set_volumetric_fog_gi_inject", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "volumetric_fog_anisotropy"),
        JS_NewCFunction(ctx, environment_class_get_volumetric_fog_anisotropy, "get_volumetric_fog_anisotropy", 0),
        JS_NewCFunction(ctx, environment_class_set_volumetric_fog_anisotropy, "set_volumetric_fog_anisotropy", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "volumetric_fog_length"),
        JS_NewCFunction(ctx, environment_class_get_volumetric_fog_length, "get_volumetric_fog_length", 0),
        JS_NewCFunction(ctx, environment_class_set_volumetric_fog_length, "set_volumetric_fog_length", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "volumetric_fog_detail_spread"),
        JS_NewCFunction(ctx, environment_class_get_volumetric_fog_detail_spread, "get_volumetric_fog_detail_spread", 0),
        JS_NewCFunction(ctx, environment_class_set_volumetric_fog_detail_spread, "set_volumetric_fog_detail_spread", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "volumetric_fog_ambient_inject"),
        JS_NewCFunction(ctx, environment_class_get_volumetric_fog_ambient_inject, "get_volumetric_fog_ambient_inject", 0),
        JS_NewCFunction(ctx, environment_class_set_volumetric_fog_ambient_inject, "set_volumetric_fog_ambient_inject", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "volumetric_fog_sky_affect"),
        JS_NewCFunction(ctx, environment_class_get_volumetric_fog_sky_affect, "get_volumetric_fog_sky_affect", 0),
        JS_NewCFunction(ctx, environment_class_set_volumetric_fog_sky_affect, "set_volumetric_fog_sky_affect", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "volumetric_fog_temporal_reprojection_enabled"),
        JS_NewCFunction(ctx, environment_class_is_volumetric_fog_temporal_reprojection_enabled, "is_volumetric_fog_temporal_reprojection_enabled", 0),
        JS_NewCFunction(ctx, environment_class_set_volumetric_fog_temporal_reprojection_enabled, "set_volumetric_fog_temporal_reprojection_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "volumetric_fog_temporal_reprojection_amount"),
        JS_NewCFunction(ctx, environment_class_get_volumetric_fog_temporal_reprojection_amount, "get_volumetric_fog_temporal_reprojection_amount", 0),
        JS_NewCFunction(ctx, environment_class_set_volumetric_fog_temporal_reprojection_amount, "set_volumetric_fog_temporal_reprojection_amount", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "adjustment_enabled"),
        JS_NewCFunction(ctx, environment_class_is_adjustment_enabled, "is_adjustment_enabled", 0),
        JS_NewCFunction(ctx, environment_class_set_adjustment_enabled, "set_adjustment_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "adjustment_brightness"),
        JS_NewCFunction(ctx, environment_class_get_adjustment_brightness, "get_adjustment_brightness", 0),
        JS_NewCFunction(ctx, environment_class_set_adjustment_brightness, "set_adjustment_brightness", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "adjustment_contrast"),
        JS_NewCFunction(ctx, environment_class_get_adjustment_contrast, "get_adjustment_contrast", 0),
        JS_NewCFunction(ctx, environment_class_set_adjustment_contrast, "set_adjustment_contrast", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "adjustment_saturation"),
        JS_NewCFunction(ctx, environment_class_get_adjustment_saturation, "get_adjustment_saturation", 0),
        JS_NewCFunction(ctx, environment_class_set_adjustment_saturation, "set_adjustment_saturation", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "adjustment_color_correction"),
        JS_NewCFunction(ctx, environment_class_get_adjustment_color_correction, "get_adjustment_color_correction", 0),
        JS_NewCFunction(ctx, environment_class_set_adjustment_color_correction, "set_adjustment_color_correction", 1),
        JS_PROP_GETSET
    );
}

static void define_environment_enum(JSContext *ctx, JSValue ctor) {
	JSValue BGMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, BGMode_obj, "BG_CLEAR_COLOR", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, BGMode_obj, "BG_COLOR", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, BGMode_obj, "BG_SKY", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, BGMode_obj, "BG_CANVAS", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, BGMode_obj, "BG_KEEP", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, BGMode_obj, "BG_CAMERA_FEED", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, BGMode_obj, "BG_MAX", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, ctor, "BGMode", BGMode_obj);
	JSValue AmbientSource_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, AmbientSource_obj, "AMBIENT_SOURCE_BG", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, AmbientSource_obj, "AMBIENT_SOURCE_DISABLED", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, AmbientSource_obj, "AMBIENT_SOURCE_COLOR", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, AmbientSource_obj, "AMBIENT_SOURCE_SKY", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ctor, "AmbientSource", AmbientSource_obj);
	JSValue ReflectionSource_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, ReflectionSource_obj, "REFLECTION_SOURCE_BG", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, ReflectionSource_obj, "REFLECTION_SOURCE_DISABLED", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ReflectionSource_obj, "REFLECTION_SOURCE_SKY", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "ReflectionSource", ReflectionSource_obj);
	JSValue ToneMapper_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, ToneMapper_obj, "TONE_MAPPER_LINEAR", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, ToneMapper_obj, "TONE_MAPPER_REINHARDT", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ToneMapper_obj, "TONE_MAPPER_FILMIC", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ToneMapper_obj, "TONE_MAPPER_ACES", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ToneMapper_obj, "TONE_MAPPER_AGX", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, ctor, "ToneMapper", ToneMapper_obj);
	JSValue GlowBlendMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, GlowBlendMode_obj, "GLOW_BLEND_MODE_ADDITIVE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, GlowBlendMode_obj, "GLOW_BLEND_MODE_SCREEN", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, GlowBlendMode_obj, "GLOW_BLEND_MODE_SOFTLIGHT", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, GlowBlendMode_obj, "GLOW_BLEND_MODE_REPLACE", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, GlowBlendMode_obj, "GLOW_BLEND_MODE_MIX", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, ctor, "GlowBlendMode", GlowBlendMode_obj);
	JSValue FogMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, FogMode_obj, "FOG_MODE_EXPONENTIAL", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, FogMode_obj, "FOG_MODE_DEPTH", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ctor, "FogMode", FogMode_obj);
	JSValue SDFGIYScale_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, SDFGIYScale_obj, "SDFGI_Y_SCALE_50_PERCENT", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, SDFGIYScale_obj, "SDFGI_Y_SCALE_75_PERCENT", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, SDFGIYScale_obj, "SDFGI_Y_SCALE_100_PERCENT", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "SDFGIYScale", SDFGIYScale_obj);
}

static int js_environment_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["Environment"] = class_id;
	classes_by_id[class_id] = "Environment";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &environment_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_environment_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, environment_class_proto_funcs, _countof(environment_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, environment_class_constructor, "Environment", 0, JS_CFUNC_constructor, 0);
	define_environment_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "Environment", ctor);

	return 0;
}

JSModuleDef *_js_init_environment_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_environment_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Environment");
	return m;
}

JSModuleDef *js_init_environment_module(JSContext *ctx) {
	return _js_init_environment_module(ctx, "@godot/classes/environment");
}

void __register_environment() {
	js_init_environment_module(js_context());
}

void register_environment() {
	__register_environment();
}