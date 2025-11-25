#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/collision_object3d.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/area3d.hpp>
using namespace godot;

static void area3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Area3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef area3d_class_def = {
    "Area3D",
    area3d_class_finalizer
};

static JSValue area3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["Area3D"];
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
        instance = memnew(Area3D);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue area3d_class_set_gravity_space_override_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Area3D::set_gravity_space_override_mode, ctx, this_val, argc, argv);
};
static JSValue area3d_class_get_gravity_space_override_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Area3D::get_gravity_space_override_mode, ctx, this_val, argc, argv);
}
static JSValue area3d_class_set_gravity_is_point(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Area3D::set_gravity_is_point, ctx, this_val, argc, argv);
};
static JSValue area3d_class_is_gravity_a_point(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Area3D::is_gravity_a_point, ctx, this_val, argc, argv);
}
static JSValue area3d_class_set_gravity_point_unit_distance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Area3D::set_gravity_point_unit_distance, ctx, this_val, argc, argv);
};
static JSValue area3d_class_get_gravity_point_unit_distance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Area3D::get_gravity_point_unit_distance, ctx, this_val, argc, argv);
}
static JSValue area3d_class_set_gravity_point_center(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Area3D::set_gravity_point_center, ctx, this_val, argc, argv);
};
static JSValue area3d_class_get_gravity_point_center(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector3> *proxy = memnew(ObjectProxy<Vector3>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector3 {
		Area3D *obj = static_cast<Area3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_gravity_point_center();
	};
	proxy->setter = [this_val](const Vector3 &value) -> void {
		Area3D *js_proxy = static_cast<Area3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_gravity_point_center(value);
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
static JSValue area3d_class_set_gravity_direction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Area3D::set_gravity_direction, ctx, this_val, argc, argv);
};
static JSValue area3d_class_get_gravity_direction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector3> *proxy = memnew(ObjectProxy<Vector3>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector3 {
		Area3D *obj = static_cast<Area3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_gravity_direction();
	};
	proxy->setter = [this_val](const Vector3 &value) -> void {
		Area3D *js_proxy = static_cast<Area3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_gravity_direction(value);
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
static JSValue area3d_class_set_gravity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Area3D::set_gravity, ctx, this_val, argc, argv);
};
static JSValue area3d_class_get_gravity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Area3D::get_gravity, ctx, this_val, argc, argv);
}
static JSValue area3d_class_set_linear_damp_space_override_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Area3D::set_linear_damp_space_override_mode, ctx, this_val, argc, argv);
};
static JSValue area3d_class_get_linear_damp_space_override_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Area3D::get_linear_damp_space_override_mode, ctx, this_val, argc, argv);
}
static JSValue area3d_class_set_angular_damp_space_override_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Area3D::set_angular_damp_space_override_mode, ctx, this_val, argc, argv);
};
static JSValue area3d_class_get_angular_damp_space_override_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Area3D::get_angular_damp_space_override_mode, ctx, this_val, argc, argv);
}
static JSValue area3d_class_set_angular_damp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Area3D::set_angular_damp, ctx, this_val, argc, argv);
};
static JSValue area3d_class_get_angular_damp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Area3D::get_angular_damp, ctx, this_val, argc, argv);
}
static JSValue area3d_class_set_linear_damp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Area3D::set_linear_damp, ctx, this_val, argc, argv);
};
static JSValue area3d_class_get_linear_damp(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Area3D::get_linear_damp, ctx, this_val, argc, argv);
}
static JSValue area3d_class_set_priority(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Area3D::set_priority, ctx, this_val, argc, argv);
};
static JSValue area3d_class_get_priority(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Area3D::get_priority, ctx, this_val, argc, argv);
}
static JSValue area3d_class_set_wind_force_magnitude(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Area3D::set_wind_force_magnitude, ctx, this_val, argc, argv);
};
static JSValue area3d_class_get_wind_force_magnitude(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Area3D::get_wind_force_magnitude, ctx, this_val, argc, argv);
}
static JSValue area3d_class_set_wind_attenuation_factor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Area3D::set_wind_attenuation_factor, ctx, this_val, argc, argv);
};
static JSValue area3d_class_get_wind_attenuation_factor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Area3D::get_wind_attenuation_factor, ctx, this_val, argc, argv);
}
static JSValue area3d_class_set_wind_source_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Area3D::set_wind_source_path, ctx, this_val, argc, argv);
};
static JSValue area3d_class_get_wind_source_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Area3D::get_wind_source_path, ctx, this_val, argc, argv);
}
static JSValue area3d_class_set_monitorable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Area3D::set_monitorable, ctx, this_val, argc, argv);
};
static JSValue area3d_class_is_monitorable(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Area3D::is_monitorable, ctx, this_val, argc, argv);
}
static JSValue area3d_class_set_monitoring(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Area3D::set_monitoring, ctx, this_val, argc, argv);
};
static JSValue area3d_class_is_monitoring(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Area3D::is_monitoring, ctx, this_val, argc, argv);
}
static JSValue area3d_class_get_overlapping_bodies(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Area3D::get_overlapping_bodies, ctx, this_val, argc, argv);
};
static JSValue area3d_class_get_overlapping_areas(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Area3D::get_overlapping_areas, ctx, this_val, argc, argv);
};
static JSValue area3d_class_has_overlapping_bodies(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Area3D::has_overlapping_bodies, ctx, this_val, argc, argv);
};
static JSValue area3d_class_has_overlapping_areas(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Area3D::has_overlapping_areas, ctx, this_val, argc, argv);
};
static JSValue area3d_class_overlaps_body(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Area3D::overlaps_body, ctx, this_val, argc, argv);
};
static JSValue area3d_class_overlaps_area(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Area3D::overlaps_area, ctx, this_val, argc, argv);
};
static JSValue area3d_class_set_audio_bus_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Area3D::set_audio_bus_override, ctx, this_val, argc, argv);
};
static JSValue area3d_class_is_overriding_audio_bus(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Area3D::is_overriding_audio_bus, ctx, this_val, argc, argv);
}
static JSValue area3d_class_set_audio_bus_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Area3D::set_audio_bus_name, ctx, this_val, argc, argv);
};
static JSValue area3d_class_get_audio_bus_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Area3D::get_audio_bus_name, ctx, this_val, argc, argv);
}
static JSValue area3d_class_set_use_reverb_bus(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Area3D::set_use_reverb_bus, ctx, this_val, argc, argv);
};
static JSValue area3d_class_is_using_reverb_bus(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Area3D::is_using_reverb_bus, ctx, this_val, argc, argv);
}
static JSValue area3d_class_set_reverb_bus_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Area3D::set_reverb_bus_name, ctx, this_val, argc, argv);
};
static JSValue area3d_class_get_reverb_bus_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Area3D::get_reverb_bus_name, ctx, this_val, argc, argv);
}
static JSValue area3d_class_set_reverb_amount(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Area3D::set_reverb_amount, ctx, this_val, argc, argv);
};
static JSValue area3d_class_get_reverb_amount(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Area3D::get_reverb_amount, ctx, this_val, argc, argv);
}
static JSValue area3d_class_set_reverb_uniformity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Area3D::set_reverb_uniformity, ctx, this_val, argc, argv);
};
static JSValue area3d_class_get_reverb_uniformity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Area3D::get_reverb_uniformity, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry area3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_gravity_space_override_mode", 1, &area3d_class_set_gravity_space_override_mode),
	JS_CFUNC_DEF("get_gravity_space_override_mode", 0, &area3d_class_get_gravity_space_override_mode),
	JS_CFUNC_DEF("set_gravity_is_point", 1, &area3d_class_set_gravity_is_point),
	JS_CFUNC_DEF("is_gravity_a_point", 0, &area3d_class_is_gravity_a_point),
	JS_CFUNC_DEF("set_gravity_point_unit_distance", 1, &area3d_class_set_gravity_point_unit_distance),
	JS_CFUNC_DEF("get_gravity_point_unit_distance", 0, &area3d_class_get_gravity_point_unit_distance),
	JS_CFUNC_DEF("set_gravity_point_center", 1, &area3d_class_set_gravity_point_center),
	JS_CFUNC_DEF("get_gravity_point_center", 0, &area3d_class_get_gravity_point_center),
	JS_CFUNC_DEF("set_gravity_direction", 1, &area3d_class_set_gravity_direction),
	JS_CFUNC_DEF("get_gravity_direction", 0, &area3d_class_get_gravity_direction),
	JS_CFUNC_DEF("set_gravity", 1, &area3d_class_set_gravity),
	JS_CFUNC_DEF("get_gravity", 0, &area3d_class_get_gravity),
	JS_CFUNC_DEF("set_linear_damp_space_override_mode", 1, &area3d_class_set_linear_damp_space_override_mode),
	JS_CFUNC_DEF("get_linear_damp_space_override_mode", 0, &area3d_class_get_linear_damp_space_override_mode),
	JS_CFUNC_DEF("set_angular_damp_space_override_mode", 1, &area3d_class_set_angular_damp_space_override_mode),
	JS_CFUNC_DEF("get_angular_damp_space_override_mode", 0, &area3d_class_get_angular_damp_space_override_mode),
	JS_CFUNC_DEF("set_angular_damp", 1, &area3d_class_set_angular_damp),
	JS_CFUNC_DEF("get_angular_damp", 0, &area3d_class_get_angular_damp),
	JS_CFUNC_DEF("set_linear_damp", 1, &area3d_class_set_linear_damp),
	JS_CFUNC_DEF("get_linear_damp", 0, &area3d_class_get_linear_damp),
	JS_CFUNC_DEF("set_priority", 1, &area3d_class_set_priority),
	JS_CFUNC_DEF("get_priority", 0, &area3d_class_get_priority),
	JS_CFUNC_DEF("set_wind_force_magnitude", 1, &area3d_class_set_wind_force_magnitude),
	JS_CFUNC_DEF("get_wind_force_magnitude", 0, &area3d_class_get_wind_force_magnitude),
	JS_CFUNC_DEF("set_wind_attenuation_factor", 1, &area3d_class_set_wind_attenuation_factor),
	JS_CFUNC_DEF("get_wind_attenuation_factor", 0, &area3d_class_get_wind_attenuation_factor),
	JS_CFUNC_DEF("set_wind_source_path", 1, &area3d_class_set_wind_source_path),
	JS_CFUNC_DEF("get_wind_source_path", 0, &area3d_class_get_wind_source_path),
	JS_CFUNC_DEF("set_monitorable", 1, &area3d_class_set_monitorable),
	JS_CFUNC_DEF("is_monitorable", 0, &area3d_class_is_monitorable),
	JS_CFUNC_DEF("set_monitoring", 1, &area3d_class_set_monitoring),
	JS_CFUNC_DEF("is_monitoring", 0, &area3d_class_is_monitoring),
	JS_CFUNC_DEF("get_overlapping_bodies", 0, &area3d_class_get_overlapping_bodies),
	JS_CFUNC_DEF("get_overlapping_areas", 0, &area3d_class_get_overlapping_areas),
	JS_CFUNC_DEF("has_overlapping_bodies", 0, &area3d_class_has_overlapping_bodies),
	JS_CFUNC_DEF("has_overlapping_areas", 0, &area3d_class_has_overlapping_areas),
	JS_CFUNC_DEF("overlaps_body", 1, &area3d_class_overlaps_body),
	JS_CFUNC_DEF("overlaps_area", 1, &area3d_class_overlaps_area),
	JS_CFUNC_DEF("set_audio_bus_override", 1, &area3d_class_set_audio_bus_override),
	JS_CFUNC_DEF("is_overriding_audio_bus", 0, &area3d_class_is_overriding_audio_bus),
	JS_CFUNC_DEF("set_audio_bus_name", 1, &area3d_class_set_audio_bus_name),
	JS_CFUNC_DEF("get_audio_bus_name", 0, &area3d_class_get_audio_bus_name),
	JS_CFUNC_DEF("set_use_reverb_bus", 1, &area3d_class_set_use_reverb_bus),
	JS_CFUNC_DEF("is_using_reverb_bus", 0, &area3d_class_is_using_reverb_bus),
	JS_CFUNC_DEF("set_reverb_bus_name", 1, &area3d_class_set_reverb_bus_name),
	JS_CFUNC_DEF("get_reverb_bus_name", 0, &area3d_class_get_reverb_bus_name),
	JS_CFUNC_DEF("set_reverb_amount", 1, &area3d_class_set_reverb_amount),
	JS_CFUNC_DEF("get_reverb_amount", 0, &area3d_class_get_reverb_amount),
	JS_CFUNC_DEF("set_reverb_uniformity", 1, &area3d_class_set_reverb_uniformity),
	JS_CFUNC_DEF("get_reverb_uniformity", 0, &area3d_class_get_reverb_uniformity),
};


static JSValue area3d_class_get_body_shape_entered_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	Area3D *opaque = static_cast<Area3D *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "body_shape_entered_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "body_shape_entered"));
		JS_DefinePropertyValueStr(ctx, this_val, "body_shape_entered_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue area3d_class_get_body_shape_exited_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	Area3D *opaque = static_cast<Area3D *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "body_shape_exited_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "body_shape_exited"));
		JS_DefinePropertyValueStr(ctx, this_val, "body_shape_exited_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue area3d_class_get_body_entered_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	Area3D *opaque = static_cast<Area3D *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "body_entered_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "body_entered"));
		JS_DefinePropertyValueStr(ctx, this_val, "body_entered_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue area3d_class_get_body_exited_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	Area3D *opaque = static_cast<Area3D *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "body_exited_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "body_exited"));
		JS_DefinePropertyValueStr(ctx, this_val, "body_exited_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue area3d_class_get_area_shape_entered_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	Area3D *opaque = static_cast<Area3D *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "area_shape_entered_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "area_shape_entered"));
		JS_DefinePropertyValueStr(ctx, this_val, "area_shape_entered_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue area3d_class_get_area_shape_exited_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	Area3D *opaque = static_cast<Area3D *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "area_shape_exited_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "area_shape_exited"));
		JS_DefinePropertyValueStr(ctx, this_val, "area_shape_exited_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue area3d_class_get_area_entered_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	Area3D *opaque = static_cast<Area3D *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "area_entered_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "area_entered"));
		JS_DefinePropertyValueStr(ctx, this_val, "area_entered_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue area3d_class_get_area_exited_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	Area3D *opaque = static_cast<Area3D *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "area_exited_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "area_exited"));
		JS_DefinePropertyValueStr(ctx, this_val, "area_exited_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_area3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "monitoring"),
        JS_NewCFunction(ctx, area3d_class_is_monitoring, "is_monitoring", 0),
        JS_NewCFunction(ctx, area3d_class_set_monitoring, "set_monitoring", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "monitorable"),
        JS_NewCFunction(ctx, area3d_class_is_monitorable, "is_monitorable", 0),
        JS_NewCFunction(ctx, area3d_class_set_monitorable, "set_monitorable", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "priority"),
        JS_NewCFunction(ctx, area3d_class_get_priority, "get_priority", 0),
        JS_NewCFunction(ctx, area3d_class_set_priority, "set_priority", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "gravity_space_override"),
        JS_NewCFunction(ctx, area3d_class_get_gravity_space_override_mode, "get_gravity_space_override_mode", 0),
        JS_NewCFunction(ctx, area3d_class_set_gravity_space_override_mode, "set_gravity_space_override_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "gravity_point"),
        JS_NewCFunction(ctx, area3d_class_is_gravity_a_point, "is_gravity_a_point", 0),
        JS_NewCFunction(ctx, area3d_class_set_gravity_is_point, "set_gravity_is_point", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "gravity_point_unit_distance"),
        JS_NewCFunction(ctx, area3d_class_get_gravity_point_unit_distance, "get_gravity_point_unit_distance", 0),
        JS_NewCFunction(ctx, area3d_class_set_gravity_point_unit_distance, "set_gravity_point_unit_distance", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "gravity_point_center"),
        JS_NewCFunction(ctx, area3d_class_get_gravity_point_center, "get_gravity_point_center", 0),
        JS_NewCFunction(ctx, area3d_class_set_gravity_point_center, "set_gravity_point_center", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "gravity_direction"),
        JS_NewCFunction(ctx, area3d_class_get_gravity_direction, "get_gravity_direction", 0),
        JS_NewCFunction(ctx, area3d_class_set_gravity_direction, "set_gravity_direction", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "gravity"),
        JS_NewCFunction(ctx, area3d_class_get_gravity, "get_gravity", 0),
        JS_NewCFunction(ctx, area3d_class_set_gravity, "set_gravity", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "linear_damp_space_override"),
        JS_NewCFunction(ctx, area3d_class_get_linear_damp_space_override_mode, "get_linear_damp_space_override_mode", 0),
        JS_NewCFunction(ctx, area3d_class_set_linear_damp_space_override_mode, "set_linear_damp_space_override_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "linear_damp"),
        JS_NewCFunction(ctx, area3d_class_get_linear_damp, "get_linear_damp", 0),
        JS_NewCFunction(ctx, area3d_class_set_linear_damp, "set_linear_damp", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "angular_damp_space_override"),
        JS_NewCFunction(ctx, area3d_class_get_angular_damp_space_override_mode, "get_angular_damp_space_override_mode", 0),
        JS_NewCFunction(ctx, area3d_class_set_angular_damp_space_override_mode, "set_angular_damp_space_override_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "angular_damp"),
        JS_NewCFunction(ctx, area3d_class_get_angular_damp, "get_angular_damp", 0),
        JS_NewCFunction(ctx, area3d_class_set_angular_damp, "set_angular_damp", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "wind_force_magnitude"),
        JS_NewCFunction(ctx, area3d_class_get_wind_force_magnitude, "get_wind_force_magnitude", 0),
        JS_NewCFunction(ctx, area3d_class_set_wind_force_magnitude, "set_wind_force_magnitude", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "wind_attenuation_factor"),
        JS_NewCFunction(ctx, area3d_class_get_wind_attenuation_factor, "get_wind_attenuation_factor", 0),
        JS_NewCFunction(ctx, area3d_class_set_wind_attenuation_factor, "set_wind_attenuation_factor", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "wind_source_path"),
        JS_NewCFunction(ctx, area3d_class_get_wind_source_path, "get_wind_source_path", 0),
        JS_NewCFunction(ctx, area3d_class_set_wind_source_path, "set_wind_source_path", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "audio_bus_override"),
        JS_NewCFunction(ctx, area3d_class_is_overriding_audio_bus, "is_overriding_audio_bus", 0),
        JS_NewCFunction(ctx, area3d_class_set_audio_bus_override, "set_audio_bus_override", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "audio_bus_name"),
        JS_NewCFunction(ctx, area3d_class_get_audio_bus_name, "get_audio_bus_name", 0),
        JS_NewCFunction(ctx, area3d_class_set_audio_bus_name, "set_audio_bus_name", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "reverb_bus_enabled"),
        JS_NewCFunction(ctx, area3d_class_is_using_reverb_bus, "is_using_reverb_bus", 0),
        JS_NewCFunction(ctx, area3d_class_set_use_reverb_bus, "set_use_reverb_bus", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "reverb_bus_name"),
        JS_NewCFunction(ctx, area3d_class_get_reverb_bus_name, "get_reverb_bus_name", 0),
        JS_NewCFunction(ctx, area3d_class_set_reverb_bus_name, "set_reverb_bus_name", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "reverb_bus_amount"),
        JS_NewCFunction(ctx, area3d_class_get_reverb_amount, "get_reverb_amount", 0),
        JS_NewCFunction(ctx, area3d_class_set_reverb_amount, "set_reverb_amount", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "reverb_bus_uniformity"),
        JS_NewCFunction(ctx, area3d_class_get_reverb_uniformity, "get_reverb_uniformity", 0),
        JS_NewCFunction(ctx, area3d_class_set_reverb_uniformity, "set_reverb_uniformity", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "body_shape_entered"),
		JS_NewCFunction(ctx, area3d_class_get_body_shape_entered_signal, "get_body_shape_entered_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "body_shape_exited"),
		JS_NewCFunction(ctx, area3d_class_get_body_shape_exited_signal, "get_body_shape_exited_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "body_entered"),
		JS_NewCFunction(ctx, area3d_class_get_body_entered_signal, "get_body_entered_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "body_exited"),
		JS_NewCFunction(ctx, area3d_class_get_body_exited_signal, "get_body_exited_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "area_shape_entered"),
		JS_NewCFunction(ctx, area3d_class_get_area_shape_entered_signal, "get_area_shape_entered_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "area_shape_exited"),
		JS_NewCFunction(ctx, area3d_class_get_area_shape_exited_signal, "get_area_shape_exited_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "area_entered"),
		JS_NewCFunction(ctx, area3d_class_get_area_entered_signal, "get_area_entered_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "area_exited"),
		JS_NewCFunction(ctx, area3d_class_get_area_exited_signal, "get_area_exited_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_area3d_enum(JSContext *ctx, JSValue ctor) {
	JSValue SpaceOverride_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, SpaceOverride_obj, "SPACE_OVERRIDE_DISABLED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, SpaceOverride_obj, "SPACE_OVERRIDE_COMBINE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, SpaceOverride_obj, "SPACE_OVERRIDE_COMBINE_REPLACE", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, SpaceOverride_obj, "SPACE_OVERRIDE_REPLACE", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, SpaceOverride_obj, "SPACE_OVERRIDE_REPLACE_COMBINE", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, ctor, "SpaceOverride", SpaceOverride_obj);
}

static int js_area3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["Area3D"] = class_id;
	classes_by_id[class_id] = "Area3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &area3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["CollisionObject3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_area3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, area3d_class_proto_funcs, _countof(area3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, area3d_class_constructor, "Area3D", 0, JS_CFUNC_constructor, 0);
	define_area3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "Area3D", ctor);
	ctor_list["Area3D"] = ctor;

	return 0;
}

JSModuleDef *_js_init_area3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/collision_object3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_area3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Area3D");
	return m;
}

JSModuleDef *js_init_area3d_module(JSContext *ctx) {
	return _js_init_area3d_module(ctx, "@godot/classes/area3d");
}

void __register_area3d() {
	js_init_area3d_module(js_context());
}

void register_area3d() {
	__register_area3d();
}