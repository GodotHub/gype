#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/curve.hpp>
#include <godot_cpp/classes/gradient.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/cpu_particles2d.hpp>
using namespace godot;

static void cpu_particles2d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["CPUParticles2D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef cpu_particles2d_class_def = {
    "CPUParticles2D",
    cpu_particles2d_class_finalizer
};

static JSValue cpu_particles2d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["CPUParticles2D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    CPUParticles2D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<CPUParticles2D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(CPUParticles2D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue cpu_particles2d_class_set_emitting(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CPUParticles2D::set_emitting, ctx, this_val, argc, argv);
};
static JSValue cpu_particles2d_class_set_amount(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CPUParticles2D::set_amount, ctx, this_val, argc, argv);
};
static JSValue cpu_particles2d_class_set_lifetime(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CPUParticles2D::set_lifetime, ctx, this_val, argc, argv);
};
static JSValue cpu_particles2d_class_set_one_shot(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CPUParticles2D::set_one_shot, ctx, this_val, argc, argv);
};
static JSValue cpu_particles2d_class_set_pre_process_time(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CPUParticles2D::set_pre_process_time, ctx, this_val, argc, argv);
};
static JSValue cpu_particles2d_class_set_explosiveness_ratio(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CPUParticles2D::set_explosiveness_ratio, ctx, this_val, argc, argv);
};
static JSValue cpu_particles2d_class_set_randomness_ratio(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CPUParticles2D::set_randomness_ratio, ctx, this_val, argc, argv);
};
static JSValue cpu_particles2d_class_set_lifetime_randomness(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CPUParticles2D::set_lifetime_randomness, ctx, this_val, argc, argv);
};
static JSValue cpu_particles2d_class_set_use_local_coordinates(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CPUParticles2D::set_use_local_coordinates, ctx, this_val, argc, argv);
};
static JSValue cpu_particles2d_class_set_fixed_fps(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CPUParticles2D::set_fixed_fps, ctx, this_val, argc, argv);
};
static JSValue cpu_particles2d_class_set_fractional_delta(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CPUParticles2D::set_fractional_delta, ctx, this_val, argc, argv);
};
static JSValue cpu_particles2d_class_set_speed_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CPUParticles2D::set_speed_scale, ctx, this_val, argc, argv);
};
static JSValue cpu_particles2d_class_request_particles_process(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CPUParticles2D::request_particles_process, ctx, this_val, argc, argv);
};
static JSValue cpu_particles2d_class_is_emitting(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CPUParticles2D::is_emitting, ctx, this_val, argc, argv);
}
static JSValue cpu_particles2d_class_get_amount(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CPUParticles2D::get_amount, ctx, this_val, argc, argv);
}
static JSValue cpu_particles2d_class_get_lifetime(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CPUParticles2D::get_lifetime, ctx, this_val, argc, argv);
}
static JSValue cpu_particles2d_class_get_one_shot(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CPUParticles2D::get_one_shot, ctx, this_val, argc, argv);
}
static JSValue cpu_particles2d_class_get_pre_process_time(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CPUParticles2D::get_pre_process_time, ctx, this_val, argc, argv);
}
static JSValue cpu_particles2d_class_get_explosiveness_ratio(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CPUParticles2D::get_explosiveness_ratio, ctx, this_val, argc, argv);
}
static JSValue cpu_particles2d_class_get_randomness_ratio(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CPUParticles2D::get_randomness_ratio, ctx, this_val, argc, argv);
}
static JSValue cpu_particles2d_class_get_lifetime_randomness(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CPUParticles2D::get_lifetime_randomness, ctx, this_val, argc, argv);
}
static JSValue cpu_particles2d_class_get_use_local_coordinates(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CPUParticles2D::get_use_local_coordinates, ctx, this_val, argc, argv);
}
static JSValue cpu_particles2d_class_get_fixed_fps(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CPUParticles2D::get_fixed_fps, ctx, this_val, argc, argv);
}
static JSValue cpu_particles2d_class_get_fractional_delta(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CPUParticles2D::get_fractional_delta, ctx, this_val, argc, argv);
}
static JSValue cpu_particles2d_class_get_speed_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CPUParticles2D::get_speed_scale, ctx, this_val, argc, argv);
}
static JSValue cpu_particles2d_class_set_use_fixed_seed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CPUParticles2D::set_use_fixed_seed, ctx, this_val, argc, argv);
};
static JSValue cpu_particles2d_class_get_use_fixed_seed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CPUParticles2D::get_use_fixed_seed, ctx, this_val, argc, argv);
}
static JSValue cpu_particles2d_class_set_seed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CPUParticles2D::set_seed, ctx, this_val, argc, argv);
};
static JSValue cpu_particles2d_class_get_seed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CPUParticles2D::get_seed, ctx, this_val, argc, argv);
}
static JSValue cpu_particles2d_class_set_draw_order(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CPUParticles2D::set_draw_order, ctx, this_val, argc, argv);
};
static JSValue cpu_particles2d_class_get_draw_order(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CPUParticles2D::get_draw_order, ctx, this_val, argc, argv);
}
static JSValue cpu_particles2d_class_set_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CPUParticles2D::set_texture, ctx, this_val, argc, argv);
};
static JSValue cpu_particles2d_class_get_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CPUParticles2D::get_texture, ctx, this_val, argc, argv);
}
static JSValue cpu_particles2d_class_restart(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CPUParticles2D::restart, ctx, this_val, argc, argv);
};
static JSValue cpu_particles2d_class_set_direction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CPUParticles2D::set_direction, ctx, this_val, argc, argv);
};
static JSValue cpu_particles2d_class_get_direction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		CPUParticles2D *obj = static_cast<CPUParticles2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_direction();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		CPUParticles2D *js_proxy = static_cast<CPUParticles2D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_direction(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2Proxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue cpu_particles2d_class_set_spread(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CPUParticles2D::set_spread, ctx, this_val, argc, argv);
};
static JSValue cpu_particles2d_class_get_spread(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CPUParticles2D::get_spread, ctx, this_val, argc, argv);
}
static JSValue cpu_particles2d_class_set_param_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CPUParticles2D::set_param_min, ctx, this_val, argc, argv);
};
static JSValue cpu_particles2d_class_get_param_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CPUParticles2D::get_param_min, ctx, this_val, argc, argv);
}
static JSValue cpu_particles2d_class_set_param_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CPUParticles2D::set_param_max, ctx, this_val, argc, argv);
};
static JSValue cpu_particles2d_class_get_param_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CPUParticles2D::get_param_max, ctx, this_val, argc, argv);
}
static JSValue cpu_particles2d_class_set_param_curve(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CPUParticles2D::set_param_curve, ctx, this_val, argc, argv);
};
static JSValue cpu_particles2d_class_get_param_curve(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CPUParticles2D::get_param_curve, ctx, this_val, argc, argv);
}
static JSValue cpu_particles2d_class_set_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CPUParticles2D::set_color, ctx, this_val, argc, argv);
};
static JSValue cpu_particles2d_class_get_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Color> *proxy = memnew(ObjectProxy<Color>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Color {
		CPUParticles2D *obj = static_cast<CPUParticles2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_color();
	};
	proxy->setter = [this_val](const Color &value) -> void {
		CPUParticles2D *js_proxy = static_cast<CPUParticles2D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_color(value);
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
static JSValue cpu_particles2d_class_set_color_ramp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CPUParticles2D::set_color_ramp, ctx, this_val, argc, argv);
};
static JSValue cpu_particles2d_class_get_color_ramp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CPUParticles2D::get_color_ramp, ctx, this_val, argc, argv);
}
static JSValue cpu_particles2d_class_set_color_initial_ramp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CPUParticles2D::set_color_initial_ramp, ctx, this_val, argc, argv);
};
static JSValue cpu_particles2d_class_get_color_initial_ramp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CPUParticles2D::get_color_initial_ramp, ctx, this_val, argc, argv);
}
static JSValue cpu_particles2d_class_set_particle_flag(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CPUParticles2D::set_particle_flag, ctx, this_val, argc, argv);
};
static JSValue cpu_particles2d_class_get_particle_flag(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CPUParticles2D::get_particle_flag, ctx, this_val, argc, argv);
}
static JSValue cpu_particles2d_class_set_emission_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CPUParticles2D::set_emission_shape, ctx, this_val, argc, argv);
};
static JSValue cpu_particles2d_class_get_emission_shape(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CPUParticles2D::get_emission_shape, ctx, this_val, argc, argv);
}
static JSValue cpu_particles2d_class_set_emission_sphere_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CPUParticles2D::set_emission_sphere_radius, ctx, this_val, argc, argv);
};
static JSValue cpu_particles2d_class_get_emission_sphere_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CPUParticles2D::get_emission_sphere_radius, ctx, this_val, argc, argv);
}
static JSValue cpu_particles2d_class_set_emission_rect_extents(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CPUParticles2D::set_emission_rect_extents, ctx, this_val, argc, argv);
};
static JSValue cpu_particles2d_class_get_emission_rect_extents(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		CPUParticles2D *obj = static_cast<CPUParticles2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_emission_rect_extents();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		CPUParticles2D *js_proxy = static_cast<CPUParticles2D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_emission_rect_extents(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2Proxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue cpu_particles2d_class_set_emission_points(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CPUParticles2D::set_emission_points, ctx, this_val, argc, argv);
};
static JSValue cpu_particles2d_class_get_emission_points(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedVector2Array> *proxy = memnew(ObjectProxy<PackedVector2Array>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedVector2Array {
		CPUParticles2D *obj = static_cast<CPUParticles2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_emission_points();
	};
	proxy->setter = [this_val](const PackedVector2Array &value) -> void {
		CPUParticles2D *js_proxy = static_cast<CPUParticles2D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_emission_points(PackedVector2Array
(Array(value)));
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["PackedVector2ArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "PackedVector2ArrayProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue cpu_particles2d_class_set_emission_normals(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CPUParticles2D::set_emission_normals, ctx, this_val, argc, argv);
};
static JSValue cpu_particles2d_class_get_emission_normals(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedVector2Array> *proxy = memnew(ObjectProxy<PackedVector2Array>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedVector2Array {
		CPUParticles2D *obj = static_cast<CPUParticles2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_emission_normals();
	};
	proxy->setter = [this_val](const PackedVector2Array &value) -> void {
		CPUParticles2D *js_proxy = static_cast<CPUParticles2D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_emission_normals(PackedVector2Array
(Array(value)));
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["PackedVector2ArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "PackedVector2ArrayProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue cpu_particles2d_class_set_emission_colors(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CPUParticles2D::set_emission_colors, ctx, this_val, argc, argv);
};
static JSValue cpu_particles2d_class_get_emission_colors(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<PackedColorArray> *proxy = memnew(ObjectProxy<PackedColorArray>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> PackedColorArray {
		CPUParticles2D *obj = static_cast<CPUParticles2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_emission_colors();
	};
	proxy->setter = [this_val](const PackedColorArray &value) -> void {
		CPUParticles2D *js_proxy = static_cast<CPUParticles2D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_emission_colors(PackedColorArray
(Array(value)));
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["PackedColorArrayProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "PackedColorArrayProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue cpu_particles2d_class_get_gravity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		CPUParticles2D *obj = static_cast<CPUParticles2D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_gravity();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		CPUParticles2D *js_proxy = static_cast<CPUParticles2D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_gravity(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2Proxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue cpu_particles2d_class_set_gravity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CPUParticles2D::set_gravity, ctx, this_val, argc, argv);
};
static JSValue cpu_particles2d_class_get_split_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&CPUParticles2D::get_split_scale, ctx, this_val, argc, argv);
}
static JSValue cpu_particles2d_class_set_split_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CPUParticles2D::set_split_scale, ctx, this_val, argc, argv);
};
static JSValue cpu_particles2d_class_get_scale_curve_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CPUParticles2D::get_scale_curve_x, ctx, this_val, argc, argv);
}
static JSValue cpu_particles2d_class_set_scale_curve_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CPUParticles2D::set_scale_curve_x, ctx, this_val, argc, argv);
};
static JSValue cpu_particles2d_class_get_scale_curve_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CPUParticles2D::get_scale_curve_y, ctx, this_val, argc, argv);
}
static JSValue cpu_particles2d_class_set_scale_curve_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CPUParticles2D::set_scale_curve_y, ctx, this_val, argc, argv);
};
static JSValue cpu_particles2d_class_convert_from_particles(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CPUParticles2D::convert_from_particles, ctx, this_val, argc, argv);
};

static JSValue cpu_particles2d_class_get_particle_flag_align_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&CPUParticles2D::get_particle_flag, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue cpu_particles2d_class_set_particle_flag_align_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&CPUParticles2D::set_particle_flag, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue cpu_particles2d_class_get_initial_velocity_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&CPUParticles2D::get_param_min, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue cpu_particles2d_class_set_initial_velocity_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&CPUParticles2D::set_param_min, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue cpu_particles2d_class_get_initial_velocity_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&CPUParticles2D::get_param_max, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue cpu_particles2d_class_set_initial_velocity_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&CPUParticles2D::set_param_max, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue cpu_particles2d_class_get_angular_velocity_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&CPUParticles2D::get_param_min, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue cpu_particles2d_class_set_angular_velocity_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&CPUParticles2D::set_param_min, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue cpu_particles2d_class_get_angular_velocity_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&CPUParticles2D::get_param_max, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue cpu_particles2d_class_set_angular_velocity_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&CPUParticles2D::set_param_max, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue cpu_particles2d_class_get_angular_velocity_curve(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&CPUParticles2D::get_param_curve, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue cpu_particles2d_class_set_angular_velocity_curve(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&CPUParticles2D::set_param_curve, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue cpu_particles2d_class_get_orbit_velocity_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&CPUParticles2D::get_param_min, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue cpu_particles2d_class_set_orbit_velocity_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&CPUParticles2D::set_param_min, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue cpu_particles2d_class_get_orbit_velocity_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&CPUParticles2D::get_param_max, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue cpu_particles2d_class_set_orbit_velocity_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&CPUParticles2D::set_param_max, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue cpu_particles2d_class_get_orbit_velocity_curve(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&CPUParticles2D::get_param_curve, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue cpu_particles2d_class_set_orbit_velocity_curve(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&CPUParticles2D::set_param_curve, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue cpu_particles2d_class_get_linear_accel_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&CPUParticles2D::get_param_min, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue cpu_particles2d_class_set_linear_accel_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&CPUParticles2D::set_param_min, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue cpu_particles2d_class_get_linear_accel_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&CPUParticles2D::get_param_max, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue cpu_particles2d_class_set_linear_accel_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&CPUParticles2D::set_param_max, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue cpu_particles2d_class_get_linear_accel_curve(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&CPUParticles2D::get_param_curve, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue cpu_particles2d_class_set_linear_accel_curve(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&CPUParticles2D::set_param_curve, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue cpu_particles2d_class_get_radial_accel_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&CPUParticles2D::get_param_min, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue cpu_particles2d_class_set_radial_accel_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&CPUParticles2D::set_param_min, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue cpu_particles2d_class_get_radial_accel_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&CPUParticles2D::get_param_max, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue cpu_particles2d_class_set_radial_accel_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&CPUParticles2D::set_param_max, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue cpu_particles2d_class_get_radial_accel_curve(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&CPUParticles2D::get_param_curve, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue cpu_particles2d_class_set_radial_accel_curve(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&CPUParticles2D::set_param_curve, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue cpu_particles2d_class_get_tangential_accel_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&CPUParticles2D::get_param_min, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue cpu_particles2d_class_set_tangential_accel_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&CPUParticles2D::set_param_min, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue cpu_particles2d_class_get_tangential_accel_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&CPUParticles2D::get_param_max, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue cpu_particles2d_class_set_tangential_accel_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&CPUParticles2D::set_param_max, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue cpu_particles2d_class_get_tangential_accel_curve(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&CPUParticles2D::get_param_curve, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue cpu_particles2d_class_set_tangential_accel_curve(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&CPUParticles2D::set_param_curve, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue cpu_particles2d_class_get_damping_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&CPUParticles2D::get_param_min, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue cpu_particles2d_class_set_damping_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&CPUParticles2D::set_param_min, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue cpu_particles2d_class_get_damping_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&CPUParticles2D::get_param_max, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue cpu_particles2d_class_set_damping_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&CPUParticles2D::set_param_max, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue cpu_particles2d_class_get_damping_curve(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&CPUParticles2D::get_param_curve, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue cpu_particles2d_class_set_damping_curve(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&CPUParticles2D::set_param_curve, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue cpu_particles2d_class_get_angle_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&CPUParticles2D::get_param_min, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue cpu_particles2d_class_set_angle_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&CPUParticles2D::set_param_min, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue cpu_particles2d_class_get_angle_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&CPUParticles2D::get_param_max, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue cpu_particles2d_class_set_angle_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&CPUParticles2D::set_param_max, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue cpu_particles2d_class_get_angle_curve(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&CPUParticles2D::get_param_curve, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue cpu_particles2d_class_set_angle_curve(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&CPUParticles2D::set_param_curve, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue cpu_particles2d_class_get_scale_amount_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&CPUParticles2D::get_param_min, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue cpu_particles2d_class_set_scale_amount_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&CPUParticles2D::set_param_min, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue cpu_particles2d_class_get_scale_amount_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&CPUParticles2D::get_param_max, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue cpu_particles2d_class_set_scale_amount_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&CPUParticles2D::set_param_max, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue cpu_particles2d_class_get_scale_amount_curve(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&CPUParticles2D::get_param_curve, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue cpu_particles2d_class_set_scale_amount_curve(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&CPUParticles2D::set_param_curve, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue cpu_particles2d_class_get_hue_variation_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&CPUParticles2D::get_param_min, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue cpu_particles2d_class_set_hue_variation_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&CPUParticles2D::set_param_min, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue cpu_particles2d_class_get_hue_variation_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&CPUParticles2D::get_param_max, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue cpu_particles2d_class_set_hue_variation_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&CPUParticles2D::set_param_max, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue cpu_particles2d_class_get_hue_variation_curve(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&CPUParticles2D::get_param_curve, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue cpu_particles2d_class_set_hue_variation_curve(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&CPUParticles2D::set_param_curve, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue cpu_particles2d_class_get_anim_speed_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&CPUParticles2D::get_param_min, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue cpu_particles2d_class_set_anim_speed_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&CPUParticles2D::set_param_min, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue cpu_particles2d_class_get_anim_speed_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&CPUParticles2D::get_param_max, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue cpu_particles2d_class_set_anim_speed_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&CPUParticles2D::set_param_max, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue cpu_particles2d_class_get_anim_speed_curve(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&CPUParticles2D::get_param_curve, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue cpu_particles2d_class_set_anim_speed_curve(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&CPUParticles2D::set_param_curve, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue cpu_particles2d_class_get_anim_offset_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&CPUParticles2D::get_param_min, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue cpu_particles2d_class_set_anim_offset_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&CPUParticles2D::set_param_min, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue cpu_particles2d_class_get_anim_offset_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&CPUParticles2D::get_param_max, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue cpu_particles2d_class_set_anim_offset_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&CPUParticles2D::set_param_max, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue cpu_particles2d_class_get_anim_offset_curve(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&CPUParticles2D::get_param_curve, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue cpu_particles2d_class_set_anim_offset_curve(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&CPUParticles2D::set_param_curve, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}


static const JSCFunctionListEntry cpu_particles2d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_emitting", 1, &cpu_particles2d_class_set_emitting),
	JS_CFUNC_DEF("set_amount", 1, &cpu_particles2d_class_set_amount),
	JS_CFUNC_DEF("set_lifetime", 1, &cpu_particles2d_class_set_lifetime),
	JS_CFUNC_DEF("set_one_shot", 1, &cpu_particles2d_class_set_one_shot),
	JS_CFUNC_DEF("set_pre_process_time", 1, &cpu_particles2d_class_set_pre_process_time),
	JS_CFUNC_DEF("set_explosiveness_ratio", 1, &cpu_particles2d_class_set_explosiveness_ratio),
	JS_CFUNC_DEF("set_randomness_ratio", 1, &cpu_particles2d_class_set_randomness_ratio),
	JS_CFUNC_DEF("set_lifetime_randomness", 1, &cpu_particles2d_class_set_lifetime_randomness),
	JS_CFUNC_DEF("set_use_local_coordinates", 1, &cpu_particles2d_class_set_use_local_coordinates),
	JS_CFUNC_DEF("set_fixed_fps", 1, &cpu_particles2d_class_set_fixed_fps),
	JS_CFUNC_DEF("set_fractional_delta", 1, &cpu_particles2d_class_set_fractional_delta),
	JS_CFUNC_DEF("set_speed_scale", 1, &cpu_particles2d_class_set_speed_scale),
	JS_CFUNC_DEF("request_particles_process", 1, &cpu_particles2d_class_request_particles_process),
	JS_CFUNC_DEF("is_emitting", 0, &cpu_particles2d_class_is_emitting),
	JS_CFUNC_DEF("get_amount", 0, &cpu_particles2d_class_get_amount),
	JS_CFUNC_DEF("get_lifetime", 0, &cpu_particles2d_class_get_lifetime),
	JS_CFUNC_DEF("get_one_shot", 0, &cpu_particles2d_class_get_one_shot),
	JS_CFUNC_DEF("get_pre_process_time", 0, &cpu_particles2d_class_get_pre_process_time),
	JS_CFUNC_DEF("get_explosiveness_ratio", 0, &cpu_particles2d_class_get_explosiveness_ratio),
	JS_CFUNC_DEF("get_randomness_ratio", 0, &cpu_particles2d_class_get_randomness_ratio),
	JS_CFUNC_DEF("get_lifetime_randomness", 0, &cpu_particles2d_class_get_lifetime_randomness),
	JS_CFUNC_DEF("get_use_local_coordinates", 0, &cpu_particles2d_class_get_use_local_coordinates),
	JS_CFUNC_DEF("get_fixed_fps", 0, &cpu_particles2d_class_get_fixed_fps),
	JS_CFUNC_DEF("get_fractional_delta", 0, &cpu_particles2d_class_get_fractional_delta),
	JS_CFUNC_DEF("get_speed_scale", 0, &cpu_particles2d_class_get_speed_scale),
	JS_CFUNC_DEF("set_use_fixed_seed", 1, &cpu_particles2d_class_set_use_fixed_seed),
	JS_CFUNC_DEF("get_use_fixed_seed", 0, &cpu_particles2d_class_get_use_fixed_seed),
	JS_CFUNC_DEF("set_seed", 1, &cpu_particles2d_class_set_seed),
	JS_CFUNC_DEF("get_seed", 0, &cpu_particles2d_class_get_seed),
	JS_CFUNC_DEF("set_draw_order", 1, &cpu_particles2d_class_set_draw_order),
	JS_CFUNC_DEF("get_draw_order", 0, &cpu_particles2d_class_get_draw_order),
	JS_CFUNC_DEF("set_texture", 1, &cpu_particles2d_class_set_texture),
	JS_CFUNC_DEF("get_texture", 0, &cpu_particles2d_class_get_texture),
	JS_CFUNC_DEF("restart", 1, &cpu_particles2d_class_restart),
	JS_CFUNC_DEF("set_direction", 1, &cpu_particles2d_class_set_direction),
	JS_CFUNC_DEF("get_direction", 0, &cpu_particles2d_class_get_direction),
	JS_CFUNC_DEF("set_spread", 1, &cpu_particles2d_class_set_spread),
	JS_CFUNC_DEF("get_spread", 0, &cpu_particles2d_class_get_spread),
	JS_CFUNC_DEF("set_param_min", 2, &cpu_particles2d_class_set_param_min),
	JS_CFUNC_DEF("get_param_min", 1, &cpu_particles2d_class_get_param_min),
	JS_CFUNC_DEF("set_param_max", 2, &cpu_particles2d_class_set_param_max),
	JS_CFUNC_DEF("get_param_max", 1, &cpu_particles2d_class_get_param_max),
	JS_CFUNC_DEF("set_param_curve", 2, &cpu_particles2d_class_set_param_curve),
	JS_CFUNC_DEF("get_param_curve", 1, &cpu_particles2d_class_get_param_curve),
	JS_CFUNC_DEF("set_color", 1, &cpu_particles2d_class_set_color),
	JS_CFUNC_DEF("get_color", 0, &cpu_particles2d_class_get_color),
	JS_CFUNC_DEF("set_color_ramp", 1, &cpu_particles2d_class_set_color_ramp),
	JS_CFUNC_DEF("get_color_ramp", 0, &cpu_particles2d_class_get_color_ramp),
	JS_CFUNC_DEF("set_color_initial_ramp", 1, &cpu_particles2d_class_set_color_initial_ramp),
	JS_CFUNC_DEF("get_color_initial_ramp", 0, &cpu_particles2d_class_get_color_initial_ramp),
	JS_CFUNC_DEF("set_particle_flag", 2, &cpu_particles2d_class_set_particle_flag),
	JS_CFUNC_DEF("get_particle_flag", 1, &cpu_particles2d_class_get_particle_flag),
	JS_CFUNC_DEF("set_emission_shape", 1, &cpu_particles2d_class_set_emission_shape),
	JS_CFUNC_DEF("get_emission_shape", 0, &cpu_particles2d_class_get_emission_shape),
	JS_CFUNC_DEF("set_emission_sphere_radius", 1, &cpu_particles2d_class_set_emission_sphere_radius),
	JS_CFUNC_DEF("get_emission_sphere_radius", 0, &cpu_particles2d_class_get_emission_sphere_radius),
	JS_CFUNC_DEF("set_emission_rect_extents", 1, &cpu_particles2d_class_set_emission_rect_extents),
	JS_CFUNC_DEF("get_emission_rect_extents", 0, &cpu_particles2d_class_get_emission_rect_extents),
	JS_CFUNC_DEF("set_emission_points", 1, &cpu_particles2d_class_set_emission_points),
	JS_CFUNC_DEF("get_emission_points", 0, &cpu_particles2d_class_get_emission_points),
	JS_CFUNC_DEF("set_emission_normals", 1, &cpu_particles2d_class_set_emission_normals),
	JS_CFUNC_DEF("get_emission_normals", 0, &cpu_particles2d_class_get_emission_normals),
	JS_CFUNC_DEF("set_emission_colors", 1, &cpu_particles2d_class_set_emission_colors),
	JS_CFUNC_DEF("get_emission_colors", 0, &cpu_particles2d_class_get_emission_colors),
	JS_CFUNC_DEF("get_gravity", 0, &cpu_particles2d_class_get_gravity),
	JS_CFUNC_DEF("set_gravity", 1, &cpu_particles2d_class_set_gravity),
	JS_CFUNC_DEF("get_split_scale", 0, &cpu_particles2d_class_get_split_scale),
	JS_CFUNC_DEF("set_split_scale", 1, &cpu_particles2d_class_set_split_scale),
	JS_CFUNC_DEF("get_scale_curve_x", 0, &cpu_particles2d_class_get_scale_curve_x),
	JS_CFUNC_DEF("set_scale_curve_x", 1, &cpu_particles2d_class_set_scale_curve_x),
	JS_CFUNC_DEF("get_scale_curve_y", 0, &cpu_particles2d_class_get_scale_curve_y),
	JS_CFUNC_DEF("set_scale_curve_y", 1, &cpu_particles2d_class_set_scale_curve_y),
	JS_CFUNC_DEF("convert_from_particles", 1, &cpu_particles2d_class_convert_from_particles),
    JS_CFUNC_MAGIC_DEF("get_angular_velocity_min", 0, &cpu_particles2d_class_get_angular_velocity_min, 1),
    JS_CFUNC_MAGIC_DEF("set_angular_velocity_min", 1, &cpu_particles2d_class_set_angular_velocity_min, 1),
    JS_CFUNC_MAGIC_DEF("get_angular_velocity_max", 0, &cpu_particles2d_class_get_angular_velocity_max, 1),
    JS_CFUNC_MAGIC_DEF("set_angular_velocity_max", 1, &cpu_particles2d_class_set_angular_velocity_max, 1),
    JS_CFUNC_MAGIC_DEF("get_angular_velocity_curve", 0, &cpu_particles2d_class_get_angular_velocity_curve, 1),
    JS_CFUNC_MAGIC_DEF("set_angular_velocity_curve", 1, &cpu_particles2d_class_set_angular_velocity_curve, 1),
    JS_CFUNC_MAGIC_DEF("get_orbit_velocity_min", 0, &cpu_particles2d_class_get_orbit_velocity_min, 2),
    JS_CFUNC_MAGIC_DEF("set_orbit_velocity_min", 1, &cpu_particles2d_class_set_orbit_velocity_min, 2),
    JS_CFUNC_MAGIC_DEF("get_orbit_velocity_max", 0, &cpu_particles2d_class_get_orbit_velocity_max, 2),
    JS_CFUNC_MAGIC_DEF("set_orbit_velocity_max", 1, &cpu_particles2d_class_set_orbit_velocity_max, 2),
    JS_CFUNC_MAGIC_DEF("get_orbit_velocity_curve", 0, &cpu_particles2d_class_get_orbit_velocity_curve, 2),
    JS_CFUNC_MAGIC_DEF("set_orbit_velocity_curve", 1, &cpu_particles2d_class_set_orbit_velocity_curve, 2),
    JS_CFUNC_MAGIC_DEF("get_linear_accel_min", 0, &cpu_particles2d_class_get_linear_accel_min, 3),
    JS_CFUNC_MAGIC_DEF("set_linear_accel_min", 1, &cpu_particles2d_class_set_linear_accel_min, 3),
    JS_CFUNC_MAGIC_DEF("get_linear_accel_max", 0, &cpu_particles2d_class_get_linear_accel_max, 3),
    JS_CFUNC_MAGIC_DEF("set_linear_accel_max", 1, &cpu_particles2d_class_set_linear_accel_max, 3),
    JS_CFUNC_MAGIC_DEF("get_linear_accel_curve", 0, &cpu_particles2d_class_get_linear_accel_curve, 3),
    JS_CFUNC_MAGIC_DEF("set_linear_accel_curve", 1, &cpu_particles2d_class_set_linear_accel_curve, 3),
    JS_CFUNC_MAGIC_DEF("get_radial_accel_min", 0, &cpu_particles2d_class_get_radial_accel_min, 4),
    JS_CFUNC_MAGIC_DEF("set_radial_accel_min", 1, &cpu_particles2d_class_set_radial_accel_min, 4),
    JS_CFUNC_MAGIC_DEF("get_radial_accel_max", 0, &cpu_particles2d_class_get_radial_accel_max, 4),
    JS_CFUNC_MAGIC_DEF("set_radial_accel_max", 1, &cpu_particles2d_class_set_radial_accel_max, 4),
    JS_CFUNC_MAGIC_DEF("get_radial_accel_curve", 0, &cpu_particles2d_class_get_radial_accel_curve, 4),
    JS_CFUNC_MAGIC_DEF("set_radial_accel_curve", 1, &cpu_particles2d_class_set_radial_accel_curve, 4),
    JS_CFUNC_MAGIC_DEF("get_tangential_accel_min", 0, &cpu_particles2d_class_get_tangential_accel_min, 5),
    JS_CFUNC_MAGIC_DEF("set_tangential_accel_min", 1, &cpu_particles2d_class_set_tangential_accel_min, 5),
    JS_CFUNC_MAGIC_DEF("get_tangential_accel_max", 0, &cpu_particles2d_class_get_tangential_accel_max, 5),
    JS_CFUNC_MAGIC_DEF("set_tangential_accel_max", 1, &cpu_particles2d_class_set_tangential_accel_max, 5),
    JS_CFUNC_MAGIC_DEF("get_tangential_accel_curve", 0, &cpu_particles2d_class_get_tangential_accel_curve, 5),
    JS_CFUNC_MAGIC_DEF("set_tangential_accel_curve", 1, &cpu_particles2d_class_set_tangential_accel_curve, 5),
    JS_CFUNC_MAGIC_DEF("get_damping_min", 0, &cpu_particles2d_class_get_damping_min, 6),
    JS_CFUNC_MAGIC_DEF("set_damping_min", 1, &cpu_particles2d_class_set_damping_min, 6),
    JS_CFUNC_MAGIC_DEF("get_damping_max", 0, &cpu_particles2d_class_get_damping_max, 6),
    JS_CFUNC_MAGIC_DEF("set_damping_max", 1, &cpu_particles2d_class_set_damping_max, 6),
    JS_CFUNC_MAGIC_DEF("get_damping_curve", 0, &cpu_particles2d_class_get_damping_curve, 6),
    JS_CFUNC_MAGIC_DEF("set_damping_curve", 1, &cpu_particles2d_class_set_damping_curve, 6),
    JS_CFUNC_MAGIC_DEF("get_angle_min", 0, &cpu_particles2d_class_get_angle_min, 7),
    JS_CFUNC_MAGIC_DEF("set_angle_min", 1, &cpu_particles2d_class_set_angle_min, 7),
    JS_CFUNC_MAGIC_DEF("get_angle_max", 0, &cpu_particles2d_class_get_angle_max, 7),
    JS_CFUNC_MAGIC_DEF("set_angle_max", 1, &cpu_particles2d_class_set_angle_max, 7),
    JS_CFUNC_MAGIC_DEF("get_angle_curve", 0, &cpu_particles2d_class_get_angle_curve, 7),
    JS_CFUNC_MAGIC_DEF("set_angle_curve", 1, &cpu_particles2d_class_set_angle_curve, 7),
    JS_CFUNC_MAGIC_DEF("get_scale_amount_min", 0, &cpu_particles2d_class_get_scale_amount_min, 8),
    JS_CFUNC_MAGIC_DEF("set_scale_amount_min", 1, &cpu_particles2d_class_set_scale_amount_min, 8),
    JS_CFUNC_MAGIC_DEF("get_scale_amount_max", 0, &cpu_particles2d_class_get_scale_amount_max, 8),
    JS_CFUNC_MAGIC_DEF("set_scale_amount_max", 1, &cpu_particles2d_class_set_scale_amount_max, 8),
    JS_CFUNC_MAGIC_DEF("get_scale_amount_curve", 0, &cpu_particles2d_class_get_scale_amount_curve, 8),
    JS_CFUNC_MAGIC_DEF("set_scale_amount_curve", 1, &cpu_particles2d_class_set_scale_amount_curve, 8),
    JS_CFUNC_MAGIC_DEF("get_hue_variation_min", 0, &cpu_particles2d_class_get_hue_variation_min, 9),
    JS_CFUNC_MAGIC_DEF("set_hue_variation_min", 1, &cpu_particles2d_class_set_hue_variation_min, 9),
    JS_CFUNC_MAGIC_DEF("get_hue_variation_max", 0, &cpu_particles2d_class_get_hue_variation_max, 9),
    JS_CFUNC_MAGIC_DEF("set_hue_variation_max", 1, &cpu_particles2d_class_set_hue_variation_max, 9),
    JS_CFUNC_MAGIC_DEF("get_hue_variation_curve", 0, &cpu_particles2d_class_get_hue_variation_curve, 9),
    JS_CFUNC_MAGIC_DEF("set_hue_variation_curve", 1, &cpu_particles2d_class_set_hue_variation_curve, 9),
    JS_CFUNC_MAGIC_DEF("get_anim_speed_min", 0, &cpu_particles2d_class_get_anim_speed_min, 10),
    JS_CFUNC_MAGIC_DEF("set_anim_speed_min", 1, &cpu_particles2d_class_set_anim_speed_min, 10),
    JS_CFUNC_MAGIC_DEF("get_anim_speed_max", 0, &cpu_particles2d_class_get_anim_speed_max, 10),
    JS_CFUNC_MAGIC_DEF("set_anim_speed_max", 1, &cpu_particles2d_class_set_anim_speed_max, 10),
    JS_CFUNC_MAGIC_DEF("get_anim_speed_curve", 0, &cpu_particles2d_class_get_anim_speed_curve, 10),
    JS_CFUNC_MAGIC_DEF("set_anim_speed_curve", 1, &cpu_particles2d_class_set_anim_speed_curve, 10),
    JS_CFUNC_MAGIC_DEF("get_anim_offset_min", 0, &cpu_particles2d_class_get_anim_offset_min, 11),
    JS_CFUNC_MAGIC_DEF("set_anim_offset_min", 1, &cpu_particles2d_class_set_anim_offset_min, 11),
    JS_CFUNC_MAGIC_DEF("get_anim_offset_max", 0, &cpu_particles2d_class_get_anim_offset_max, 11),
    JS_CFUNC_MAGIC_DEF("set_anim_offset_max", 1, &cpu_particles2d_class_set_anim_offset_max, 11),
    JS_CFUNC_MAGIC_DEF("get_anim_offset_curve", 0, &cpu_particles2d_class_get_anim_offset_curve, 11),
    JS_CFUNC_MAGIC_DEF("set_anim_offset_curve", 1, &cpu_particles2d_class_set_anim_offset_curve, 11),
};


static JSValue cpu_particles2d_class_get_finished_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	CPUParticles2D *opaque = static_cast<CPUParticles2D *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "finished_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "finished"));
		JS_DefinePropertyValueStr(ctx, this_val, "finished_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_cpu_particles2d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "emitting"),
        JS_NewCFunction(ctx, cpu_particles2d_class_is_emitting, "is_emitting", 0),
        JS_NewCFunction(ctx, cpu_particles2d_class_set_emitting, "set_emitting", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "amount"),
        JS_NewCFunction(ctx, cpu_particles2d_class_get_amount, "get_amount", 0),
        JS_NewCFunction(ctx, cpu_particles2d_class_set_amount, "set_amount", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "texture"),
        JS_NewCFunction(ctx, cpu_particles2d_class_get_texture, "get_texture", 0),
        JS_NewCFunction(ctx, cpu_particles2d_class_set_texture, "set_texture", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "lifetime"),
        JS_NewCFunction(ctx, cpu_particles2d_class_get_lifetime, "get_lifetime", 0),
        JS_NewCFunction(ctx, cpu_particles2d_class_set_lifetime, "set_lifetime", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "one_shot"),
        JS_NewCFunction(ctx, cpu_particles2d_class_get_one_shot, "get_one_shot", 0),
        JS_NewCFunction(ctx, cpu_particles2d_class_set_one_shot, "set_one_shot", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "preprocess"),
        JS_NewCFunction(ctx, cpu_particles2d_class_get_pre_process_time, "get_pre_process_time", 0),
        JS_NewCFunction(ctx, cpu_particles2d_class_set_pre_process_time, "set_pre_process_time", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "speed_scale"),
        JS_NewCFunction(ctx, cpu_particles2d_class_get_speed_scale, "get_speed_scale", 0),
        JS_NewCFunction(ctx, cpu_particles2d_class_set_speed_scale, "set_speed_scale", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "explosiveness"),
        JS_NewCFunction(ctx, cpu_particles2d_class_get_explosiveness_ratio, "get_explosiveness_ratio", 0),
        JS_NewCFunction(ctx, cpu_particles2d_class_set_explosiveness_ratio, "set_explosiveness_ratio", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "randomness"),
        JS_NewCFunction(ctx, cpu_particles2d_class_get_randomness_ratio, "get_randomness_ratio", 0),
        JS_NewCFunction(ctx, cpu_particles2d_class_set_randomness_ratio, "set_randomness_ratio", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "use_fixed_seed"),
        JS_NewCFunction(ctx, cpu_particles2d_class_get_use_fixed_seed, "get_use_fixed_seed", 0),
        JS_NewCFunction(ctx, cpu_particles2d_class_set_use_fixed_seed, "set_use_fixed_seed", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "seed"),
        JS_NewCFunction(ctx, cpu_particles2d_class_get_seed, "get_seed", 0),
        JS_NewCFunction(ctx, cpu_particles2d_class_set_seed, "set_seed", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "lifetime_randomness"),
        JS_NewCFunction(ctx, cpu_particles2d_class_get_lifetime_randomness, "get_lifetime_randomness", 0),
        JS_NewCFunction(ctx, cpu_particles2d_class_set_lifetime_randomness, "set_lifetime_randomness", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "fixed_fps"),
        JS_NewCFunction(ctx, cpu_particles2d_class_get_fixed_fps, "get_fixed_fps", 0),
        JS_NewCFunction(ctx, cpu_particles2d_class_set_fixed_fps, "set_fixed_fps", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "fract_delta"),
        JS_NewCFunction(ctx, cpu_particles2d_class_get_fractional_delta, "get_fractional_delta", 0),
        JS_NewCFunction(ctx, cpu_particles2d_class_set_fractional_delta, "set_fractional_delta", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "local_coords"),
        JS_NewCFunction(ctx, cpu_particles2d_class_get_use_local_coordinates, "get_use_local_coordinates", 0),
        JS_NewCFunction(ctx, cpu_particles2d_class_set_use_local_coordinates, "set_use_local_coordinates", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "draw_order"),
        JS_NewCFunction(ctx, cpu_particles2d_class_get_draw_order, "get_draw_order", 0),
        JS_NewCFunction(ctx, cpu_particles2d_class_set_draw_order, "set_draw_order", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "emission_shape"),
        JS_NewCFunction(ctx, cpu_particles2d_class_get_emission_shape, "get_emission_shape", 0),
        JS_NewCFunction(ctx, cpu_particles2d_class_set_emission_shape, "set_emission_shape", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "emission_sphere_radius"),
        JS_NewCFunction(ctx, cpu_particles2d_class_get_emission_sphere_radius, "get_emission_sphere_radius", 0),
        JS_NewCFunction(ctx, cpu_particles2d_class_set_emission_sphere_radius, "set_emission_sphere_radius", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "emission_rect_extents"),
        JS_NewCFunction(ctx, cpu_particles2d_class_get_emission_rect_extents, "get_emission_rect_extents", 0),
        JS_NewCFunction(ctx, cpu_particles2d_class_set_emission_rect_extents, "set_emission_rect_extents", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "emission_points"),
        JS_NewCFunction(ctx, cpu_particles2d_class_get_emission_points, "get_emission_points", 0),
        JS_NewCFunction(ctx, cpu_particles2d_class_set_emission_points, "set_emission_points", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "emission_normals"),
        JS_NewCFunction(ctx, cpu_particles2d_class_get_emission_normals, "get_emission_normals", 0),
        JS_NewCFunction(ctx, cpu_particles2d_class_set_emission_normals, "set_emission_normals", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "emission_colors"),
        JS_NewCFunction(ctx, cpu_particles2d_class_get_emission_colors, "get_emission_colors", 0),
        JS_NewCFunction(ctx, cpu_particles2d_class_set_emission_colors, "set_emission_colors", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "particle_flag_align_y"),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_get_particle_flag_align_y, "get_particle_flag_align_y", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 0),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_set_particle_flag_align_y, "set_particle_flag_align_y", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 0),
		JS_PROP_GETSET
	);
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "direction"),
        JS_NewCFunction(ctx, cpu_particles2d_class_get_direction, "get_direction", 0),
        JS_NewCFunction(ctx, cpu_particles2d_class_set_direction, "set_direction", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "spread"),
        JS_NewCFunction(ctx, cpu_particles2d_class_get_spread, "get_spread", 0),
        JS_NewCFunction(ctx, cpu_particles2d_class_set_spread, "set_spread", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "gravity"),
        JS_NewCFunction(ctx, cpu_particles2d_class_get_gravity, "get_gravity", 0),
        JS_NewCFunction(ctx, cpu_particles2d_class_set_gravity, "set_gravity", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "initial_velocity_min"),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_get_initial_velocity_min, "get_initial_velocity_min", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 0),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_set_initial_velocity_min, "set_initial_velocity_min", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 0),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "initial_velocity_max"),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_get_initial_velocity_max, "get_initial_velocity_max", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 0),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_set_initial_velocity_max, "set_initial_velocity_max", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 0),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "angular_velocity_min"),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_get_angular_velocity_min, "get_angular_velocity_min", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 1),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_set_angular_velocity_min, "set_angular_velocity_min", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 1),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "angular_velocity_max"),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_get_angular_velocity_max, "get_angular_velocity_max", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 1),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_set_angular_velocity_max, "set_angular_velocity_max", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 1),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "angular_velocity_curve"),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_get_angular_velocity_curve, "get_angular_velocity_curve", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 1),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_set_angular_velocity_curve, "set_angular_velocity_curve", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 1),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "orbit_velocity_min"),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_get_orbit_velocity_min, "get_orbit_velocity_min", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 2),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_set_orbit_velocity_min, "set_orbit_velocity_min", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 2),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "orbit_velocity_max"),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_get_orbit_velocity_max, "get_orbit_velocity_max", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 2),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_set_orbit_velocity_max, "set_orbit_velocity_max", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 2),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "orbit_velocity_curve"),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_get_orbit_velocity_curve, "get_orbit_velocity_curve", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 2),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_set_orbit_velocity_curve, "set_orbit_velocity_curve", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 2),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "linear_accel_min"),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_get_linear_accel_min, "get_linear_accel_min", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 3),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_set_linear_accel_min, "set_linear_accel_min", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 3),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "linear_accel_max"),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_get_linear_accel_max, "get_linear_accel_max", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 3),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_set_linear_accel_max, "set_linear_accel_max", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 3),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "linear_accel_curve"),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_get_linear_accel_curve, "get_linear_accel_curve", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 3),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_set_linear_accel_curve, "set_linear_accel_curve", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 3),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "radial_accel_min"),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_get_radial_accel_min, "get_radial_accel_min", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 4),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_set_radial_accel_min, "set_radial_accel_min", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 4),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "radial_accel_max"),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_get_radial_accel_max, "get_radial_accel_max", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 4),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_set_radial_accel_max, "set_radial_accel_max", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 4),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "radial_accel_curve"),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_get_radial_accel_curve, "get_radial_accel_curve", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 4),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_set_radial_accel_curve, "set_radial_accel_curve", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 4),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "tangential_accel_min"),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_get_tangential_accel_min, "get_tangential_accel_min", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 5),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_set_tangential_accel_min, "set_tangential_accel_min", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 5),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "tangential_accel_max"),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_get_tangential_accel_max, "get_tangential_accel_max", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 5),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_set_tangential_accel_max, "set_tangential_accel_max", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 5),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "tangential_accel_curve"),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_get_tangential_accel_curve, "get_tangential_accel_curve", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 5),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_set_tangential_accel_curve, "set_tangential_accel_curve", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 5),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "damping_min"),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_get_damping_min, "get_damping_min", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 6),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_set_damping_min, "set_damping_min", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 6),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "damping_max"),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_get_damping_max, "get_damping_max", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 6),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_set_damping_max, "set_damping_max", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 6),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "damping_curve"),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_get_damping_curve, "get_damping_curve", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 6),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_set_damping_curve, "set_damping_curve", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 6),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "angle_min"),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_get_angle_min, "get_angle_min", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 7),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_set_angle_min, "set_angle_min", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 7),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "angle_max"),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_get_angle_max, "get_angle_max", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 7),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_set_angle_max, "set_angle_max", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 7),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "angle_curve"),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_get_angle_curve, "get_angle_curve", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 7),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_set_angle_curve, "set_angle_curve", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 7),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "scale_amount_min"),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_get_scale_amount_min, "get_scale_amount_min", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 8),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_set_scale_amount_min, "set_scale_amount_min", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 8),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "scale_amount_max"),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_get_scale_amount_max, "get_scale_amount_max", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 8),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_set_scale_amount_max, "set_scale_amount_max", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 8),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "scale_amount_curve"),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_get_scale_amount_curve, "get_scale_amount_curve", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 8),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_set_scale_amount_curve, "set_scale_amount_curve", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 8),
		JS_PROP_GETSET
	);
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "split_scale"),
        JS_NewCFunction(ctx, cpu_particles2d_class_get_split_scale, "get_split_scale", 0),
        JS_NewCFunction(ctx, cpu_particles2d_class_set_split_scale, "set_split_scale", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "scale_curve_x"),
        JS_NewCFunction(ctx, cpu_particles2d_class_get_scale_curve_x, "get_scale_curve_x", 0),
        JS_NewCFunction(ctx, cpu_particles2d_class_set_scale_curve_x, "set_scale_curve_x", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "scale_curve_y"),
        JS_NewCFunction(ctx, cpu_particles2d_class_get_scale_curve_y, "get_scale_curve_y", 0),
        JS_NewCFunction(ctx, cpu_particles2d_class_set_scale_curve_y, "set_scale_curve_y", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "color"),
        JS_NewCFunction(ctx, cpu_particles2d_class_get_color, "get_color", 0),
        JS_NewCFunction(ctx, cpu_particles2d_class_set_color, "set_color", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "color_ramp"),
        JS_NewCFunction(ctx, cpu_particles2d_class_get_color_ramp, "get_color_ramp", 0),
        JS_NewCFunction(ctx, cpu_particles2d_class_set_color_ramp, "set_color_ramp", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "color_initial_ramp"),
        JS_NewCFunction(ctx, cpu_particles2d_class_get_color_initial_ramp, "get_color_initial_ramp", 0),
        JS_NewCFunction(ctx, cpu_particles2d_class_set_color_initial_ramp, "set_color_initial_ramp", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "hue_variation_min"),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_get_hue_variation_min, "get_hue_variation_min", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 9),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_set_hue_variation_min, "set_hue_variation_min", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 9),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "hue_variation_max"),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_get_hue_variation_max, "get_hue_variation_max", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 9),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_set_hue_variation_max, "set_hue_variation_max", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 9),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "hue_variation_curve"),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_get_hue_variation_curve, "get_hue_variation_curve", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 9),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_set_hue_variation_curve, "set_hue_variation_curve", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 9),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "anim_speed_min"),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_get_anim_speed_min, "get_anim_speed_min", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 10),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_set_anim_speed_min, "set_anim_speed_min", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 10),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "anim_speed_max"),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_get_anim_speed_max, "get_anim_speed_max", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 10),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_set_anim_speed_max, "set_anim_speed_max", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 10),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "anim_speed_curve"),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_get_anim_speed_curve, "get_anim_speed_curve", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 10),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_set_anim_speed_curve, "set_anim_speed_curve", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 10),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "anim_offset_min"),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_get_anim_offset_min, "get_anim_offset_min", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 11),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_set_anim_offset_min, "set_anim_offset_min", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 11),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "anim_offset_max"),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_get_anim_offset_max, "get_anim_offset_max", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 11),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_set_anim_offset_max, "set_anim_offset_max", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 11),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "anim_offset_curve"),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_get_anim_offset_curve, "get_anim_offset_curve", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 11),
		JS_NewCFunctionMagic(ctx, cpu_particles2d_class_set_anim_offset_curve, "set_anim_offset_curve", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 11),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "finished"),
		JS_NewCFunction(ctx, cpu_particles2d_class_get_finished_signal, "get_finished_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_cpu_particles2d_enum(JSContext *ctx, JSValue ctor) {
	JSValue DrawOrder_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, DrawOrder_obj, "DRAW_ORDER_INDEX", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, DrawOrder_obj, "DRAW_ORDER_LIFETIME", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ctor, "DrawOrder", DrawOrder_obj);
	JSValue Parameter_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, Parameter_obj, "PARAM_INITIAL_LINEAR_VELOCITY", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, Parameter_obj, "PARAM_ANGULAR_VELOCITY", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, Parameter_obj, "PARAM_ORBIT_VELOCITY", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, Parameter_obj, "PARAM_LINEAR_ACCEL", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, Parameter_obj, "PARAM_RADIAL_ACCEL", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, Parameter_obj, "PARAM_TANGENTIAL_ACCEL", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, Parameter_obj, "PARAM_DAMPING", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, Parameter_obj, "PARAM_ANGLE", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, Parameter_obj, "PARAM_SCALE", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, Parameter_obj, "PARAM_HUE_VARIATION", JS_NewInt64(ctx, 9));
	JS_SetPropertyStr(ctx, Parameter_obj, "PARAM_ANIM_SPEED", JS_NewInt64(ctx, 10));
	JS_SetPropertyStr(ctx, Parameter_obj, "PARAM_ANIM_OFFSET", JS_NewInt64(ctx, 11));
	JS_SetPropertyStr(ctx, Parameter_obj, "PARAM_MAX", JS_NewInt64(ctx, 12));
	JS_SetPropertyStr(ctx, ctor, "Parameter", Parameter_obj);
	JSValue ParticleFlags_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, ParticleFlags_obj, "PARTICLE_FLAG_ALIGN_Y_TO_VELOCITY", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, ParticleFlags_obj, "PARTICLE_FLAG_ROTATE_Y", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ParticleFlags_obj, "PARTICLE_FLAG_DISABLE_Z", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ParticleFlags_obj, "PARTICLE_FLAG_MAX", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ctor, "ParticleFlags", ParticleFlags_obj);
	JSValue EmissionShape_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, EmissionShape_obj, "EMISSION_SHAPE_POINT", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, EmissionShape_obj, "EMISSION_SHAPE_SPHERE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, EmissionShape_obj, "EMISSION_SHAPE_SPHERE_SURFACE", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, EmissionShape_obj, "EMISSION_SHAPE_RECTANGLE", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, EmissionShape_obj, "EMISSION_SHAPE_POINTS", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, EmissionShape_obj, "EMISSION_SHAPE_DIRECTED_POINTS", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, EmissionShape_obj, "EMISSION_SHAPE_MAX", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, ctor, "EmissionShape", EmissionShape_obj);
}

static int js_cpu_particles2d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["CPUParticles2D"] = class_id;
	classes_by_id[class_id] = "CPUParticles2D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &cpu_particles2d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node2D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_cpu_particles2d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, cpu_particles2d_class_proto_funcs, _countof(cpu_particles2d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, cpu_particles2d_class_constructor, "CPUParticles2D", 0, JS_CFUNC_constructor, 0);
	define_cpu_particles2d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "CPUParticles2D", ctor);

	return 0;
}

JSModuleDef *_js_init_cpu_particles2d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node2d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_cpu_particles2d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "CPUParticles2D");
	return m;
}

JSModuleDef *js_init_cpu_particles2d_module(JSContext *ctx) {
	return _js_init_cpu_particles2d_module(ctx, "@godot/classes/cpu_particles2d");
}

void __register_cpu_particles2d() {
	js_init_cpu_particles2d_module(js_context());
}

void register_cpu_particles2d() {
	__register_cpu_particles2d();
}