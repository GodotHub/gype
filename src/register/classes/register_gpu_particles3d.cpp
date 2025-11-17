#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/geometry_instance3d.hpp>
#include <godot_cpp/classes/material.hpp>
#include <godot_cpp/classes/mesh.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/skin.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/gpu_particles3d.hpp>
using namespace godot;

static void gpu_particles3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["GPUParticles3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef gpu_particles3d_class_def = {
    "GPUParticles3D",
    gpu_particles3d_class_finalizer
};

static JSValue gpu_particles3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["GPUParticles3D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    GPUParticles3D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<GPUParticles3D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(GPUParticles3D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue gpu_particles3d_class_set_emitting(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GPUParticles3D::set_emitting, ctx, this_val, argc, argv);
};
static JSValue gpu_particles3d_class_set_amount(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GPUParticles3D::set_amount, ctx, this_val, argc, argv);
};
static JSValue gpu_particles3d_class_set_lifetime(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GPUParticles3D::set_lifetime, ctx, this_val, argc, argv);
};
static JSValue gpu_particles3d_class_set_one_shot(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GPUParticles3D::set_one_shot, ctx, this_val, argc, argv);
};
static JSValue gpu_particles3d_class_set_pre_process_time(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GPUParticles3D::set_pre_process_time, ctx, this_val, argc, argv);
};
static JSValue gpu_particles3d_class_set_explosiveness_ratio(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GPUParticles3D::set_explosiveness_ratio, ctx, this_val, argc, argv);
};
static JSValue gpu_particles3d_class_set_randomness_ratio(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GPUParticles3D::set_randomness_ratio, ctx, this_val, argc, argv);
};
static JSValue gpu_particles3d_class_set_visibility_aabb(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GPUParticles3D::set_visibility_aabb, ctx, this_val, argc, argv);
};
static JSValue gpu_particles3d_class_set_use_local_coordinates(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GPUParticles3D::set_use_local_coordinates, ctx, this_val, argc, argv);
};
static JSValue gpu_particles3d_class_set_fixed_fps(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GPUParticles3D::set_fixed_fps, ctx, this_val, argc, argv);
};
static JSValue gpu_particles3d_class_set_fractional_delta(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GPUParticles3D::set_fractional_delta, ctx, this_val, argc, argv);
};
static JSValue gpu_particles3d_class_set_interpolate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GPUParticles3D::set_interpolate, ctx, this_val, argc, argv);
};
static JSValue gpu_particles3d_class_set_process_material(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GPUParticles3D::set_process_material, ctx, this_val, argc, argv);
};
static JSValue gpu_particles3d_class_set_speed_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GPUParticles3D::set_speed_scale, ctx, this_val, argc, argv);
};
static JSValue gpu_particles3d_class_set_collision_base_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GPUParticles3D::set_collision_base_size, ctx, this_val, argc, argv);
};
static JSValue gpu_particles3d_class_set_interp_to_end(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GPUParticles3D::set_interp_to_end, ctx, this_val, argc, argv);
};
static JSValue gpu_particles3d_class_is_emitting(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GPUParticles3D::is_emitting, ctx, this_val, argc, argv);
}
static JSValue gpu_particles3d_class_get_amount(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GPUParticles3D::get_amount, ctx, this_val, argc, argv);
}
static JSValue gpu_particles3d_class_get_lifetime(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GPUParticles3D::get_lifetime, ctx, this_val, argc, argv);
}
static JSValue gpu_particles3d_class_get_one_shot(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GPUParticles3D::get_one_shot, ctx, this_val, argc, argv);
}
static JSValue gpu_particles3d_class_get_pre_process_time(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GPUParticles3D::get_pre_process_time, ctx, this_val, argc, argv);
}
static JSValue gpu_particles3d_class_get_explosiveness_ratio(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GPUParticles3D::get_explosiveness_ratio, ctx, this_val, argc, argv);
}
static JSValue gpu_particles3d_class_get_randomness_ratio(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GPUParticles3D::get_randomness_ratio, ctx, this_val, argc, argv);
}
static JSValue gpu_particles3d_class_get_visibility_aabb(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<AABB> *proxy = memnew(ObjectProxy<AABB>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> AABB {
		GPUParticles3D *obj = static_cast<GPUParticles3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_visibility_aabb();
	};
	proxy->setter = [this_val](const AABB &value) -> void {
		GPUParticles3D *js_proxy = static_cast<GPUParticles3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_visibility_aabb(value);
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
static JSValue gpu_particles3d_class_get_use_local_coordinates(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GPUParticles3D::get_use_local_coordinates, ctx, this_val, argc, argv);
}
static JSValue gpu_particles3d_class_get_fixed_fps(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GPUParticles3D::get_fixed_fps, ctx, this_val, argc, argv);
}
static JSValue gpu_particles3d_class_get_fractional_delta(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GPUParticles3D::get_fractional_delta, ctx, this_val, argc, argv);
}
static JSValue gpu_particles3d_class_get_interpolate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GPUParticles3D::get_interpolate, ctx, this_val, argc, argv);
}
static JSValue gpu_particles3d_class_get_process_material(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GPUParticles3D::get_process_material, ctx, this_val, argc, argv);
}
static JSValue gpu_particles3d_class_get_speed_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GPUParticles3D::get_speed_scale, ctx, this_val, argc, argv);
}
static JSValue gpu_particles3d_class_get_collision_base_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GPUParticles3D::get_collision_base_size, ctx, this_val, argc, argv);
}
static JSValue gpu_particles3d_class_get_interp_to_end(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GPUParticles3D::get_interp_to_end, ctx, this_val, argc, argv);
}
static JSValue gpu_particles3d_class_set_use_fixed_seed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GPUParticles3D::set_use_fixed_seed, ctx, this_val, argc, argv);
};
static JSValue gpu_particles3d_class_get_use_fixed_seed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GPUParticles3D::get_use_fixed_seed, ctx, this_val, argc, argv);
}
static JSValue gpu_particles3d_class_set_seed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GPUParticles3D::set_seed, ctx, this_val, argc, argv);
};
static JSValue gpu_particles3d_class_get_seed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GPUParticles3D::get_seed, ctx, this_val, argc, argv);
}
static JSValue gpu_particles3d_class_set_draw_order(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GPUParticles3D::set_draw_order, ctx, this_val, argc, argv);
};
static JSValue gpu_particles3d_class_get_draw_order(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GPUParticles3D::get_draw_order, ctx, this_val, argc, argv);
}
static JSValue gpu_particles3d_class_set_draw_passes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GPUParticles3D::set_draw_passes, ctx, this_val, argc, argv);
};
static JSValue gpu_particles3d_class_set_draw_pass_mesh(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GPUParticles3D::set_draw_pass_mesh, ctx, this_val, argc, argv);
};
static JSValue gpu_particles3d_class_get_draw_passes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GPUParticles3D::get_draw_passes, ctx, this_val, argc, argv);
}
static JSValue gpu_particles3d_class_get_draw_pass_mesh(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GPUParticles3D::get_draw_pass_mesh, ctx, this_val, argc, argv);
}
static JSValue gpu_particles3d_class_set_skin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GPUParticles3D::set_skin, ctx, this_val, argc, argv);
};
static JSValue gpu_particles3d_class_get_skin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GPUParticles3D::get_skin, ctx, this_val, argc, argv);
}
static JSValue gpu_particles3d_class_restart(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GPUParticles3D::restart, ctx, this_val, argc, argv);
};
static JSValue gpu_particles3d_class_capture_aabb(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GPUParticles3D::capture_aabb, ctx, this_val, argc, argv);
};
static JSValue gpu_particles3d_class_set_sub_emitter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GPUParticles3D::set_sub_emitter, ctx, this_val, argc, argv);
};
static JSValue gpu_particles3d_class_get_sub_emitter(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<NodePath> *proxy = memnew(ObjectProxy<NodePath>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> NodePath {
		GPUParticles3D *obj = static_cast<GPUParticles3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_sub_emitter();
	};
	proxy->setter = [this_val](const NodePath &value) -> void {
		GPUParticles3D *js_proxy = static_cast<GPUParticles3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_sub_emitter(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["NodePathProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "NodePathProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue gpu_particles3d_class_emit_particle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GPUParticles3D::emit_particle, ctx, this_val, argc, argv);
};
static JSValue gpu_particles3d_class_set_trail_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GPUParticles3D::set_trail_enabled, ctx, this_val, argc, argv);
};
static JSValue gpu_particles3d_class_set_trail_lifetime(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GPUParticles3D::set_trail_lifetime, ctx, this_val, argc, argv);
};
static JSValue gpu_particles3d_class_is_trail_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GPUParticles3D::is_trail_enabled, ctx, this_val, argc, argv);
}
static JSValue gpu_particles3d_class_get_trail_lifetime(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GPUParticles3D::get_trail_lifetime, ctx, this_val, argc, argv);
}
static JSValue gpu_particles3d_class_set_transform_align(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GPUParticles3D::set_transform_align, ctx, this_val, argc, argv);
};
static JSValue gpu_particles3d_class_get_transform_align(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GPUParticles3D::get_transform_align, ctx, this_val, argc, argv);
}
static JSValue gpu_particles3d_class_convert_from_particles(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GPUParticles3D::convert_from_particles, ctx, this_val, argc, argv);
};
static JSValue gpu_particles3d_class_set_amount_ratio(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GPUParticles3D::set_amount_ratio, ctx, this_val, argc, argv);
};
static JSValue gpu_particles3d_class_get_amount_ratio(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&GPUParticles3D::get_amount_ratio, ctx, this_val, argc, argv);
}
static JSValue gpu_particles3d_class_request_particles_process(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&GPUParticles3D::request_particles_process, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry gpu_particles3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_emitting", 1, &gpu_particles3d_class_set_emitting),
	JS_CFUNC_DEF("set_amount", 1, &gpu_particles3d_class_set_amount),
	JS_CFUNC_DEF("set_lifetime", 1, &gpu_particles3d_class_set_lifetime),
	JS_CFUNC_DEF("set_one_shot", 1, &gpu_particles3d_class_set_one_shot),
	JS_CFUNC_DEF("set_pre_process_time", 1, &gpu_particles3d_class_set_pre_process_time),
	JS_CFUNC_DEF("set_explosiveness_ratio", 1, &gpu_particles3d_class_set_explosiveness_ratio),
	JS_CFUNC_DEF("set_randomness_ratio", 1, &gpu_particles3d_class_set_randomness_ratio),
	JS_CFUNC_DEF("set_visibility_aabb", 1, &gpu_particles3d_class_set_visibility_aabb),
	JS_CFUNC_DEF("set_use_local_coordinates", 1, &gpu_particles3d_class_set_use_local_coordinates),
	JS_CFUNC_DEF("set_fixed_fps", 1, &gpu_particles3d_class_set_fixed_fps),
	JS_CFUNC_DEF("set_fractional_delta", 1, &gpu_particles3d_class_set_fractional_delta),
	JS_CFUNC_DEF("set_interpolate", 1, &gpu_particles3d_class_set_interpolate),
	JS_CFUNC_DEF("set_process_material", 1, &gpu_particles3d_class_set_process_material),
	JS_CFUNC_DEF("set_speed_scale", 1, &gpu_particles3d_class_set_speed_scale),
	JS_CFUNC_DEF("set_collision_base_size", 1, &gpu_particles3d_class_set_collision_base_size),
	JS_CFUNC_DEF("set_interp_to_end", 1, &gpu_particles3d_class_set_interp_to_end),
	JS_CFUNC_DEF("is_emitting", 0, &gpu_particles3d_class_is_emitting),
	JS_CFUNC_DEF("get_amount", 0, &gpu_particles3d_class_get_amount),
	JS_CFUNC_DEF("get_lifetime", 0, &gpu_particles3d_class_get_lifetime),
	JS_CFUNC_DEF("get_one_shot", 0, &gpu_particles3d_class_get_one_shot),
	JS_CFUNC_DEF("get_pre_process_time", 0, &gpu_particles3d_class_get_pre_process_time),
	JS_CFUNC_DEF("get_explosiveness_ratio", 0, &gpu_particles3d_class_get_explosiveness_ratio),
	JS_CFUNC_DEF("get_randomness_ratio", 0, &gpu_particles3d_class_get_randomness_ratio),
	JS_CFUNC_DEF("get_visibility_aabb", 0, &gpu_particles3d_class_get_visibility_aabb),
	JS_CFUNC_DEF("get_use_local_coordinates", 0, &gpu_particles3d_class_get_use_local_coordinates),
	JS_CFUNC_DEF("get_fixed_fps", 0, &gpu_particles3d_class_get_fixed_fps),
	JS_CFUNC_DEF("get_fractional_delta", 0, &gpu_particles3d_class_get_fractional_delta),
	JS_CFUNC_DEF("get_interpolate", 0, &gpu_particles3d_class_get_interpolate),
	JS_CFUNC_DEF("get_process_material", 0, &gpu_particles3d_class_get_process_material),
	JS_CFUNC_DEF("get_speed_scale", 0, &gpu_particles3d_class_get_speed_scale),
	JS_CFUNC_DEF("get_collision_base_size", 0, &gpu_particles3d_class_get_collision_base_size),
	JS_CFUNC_DEF("get_interp_to_end", 0, &gpu_particles3d_class_get_interp_to_end),
	JS_CFUNC_DEF("set_use_fixed_seed", 1, &gpu_particles3d_class_set_use_fixed_seed),
	JS_CFUNC_DEF("get_use_fixed_seed", 0, &gpu_particles3d_class_get_use_fixed_seed),
	JS_CFUNC_DEF("set_seed", 1, &gpu_particles3d_class_set_seed),
	JS_CFUNC_DEF("get_seed", 0, &gpu_particles3d_class_get_seed),
	JS_CFUNC_DEF("set_draw_order", 1, &gpu_particles3d_class_set_draw_order),
	JS_CFUNC_DEF("get_draw_order", 0, &gpu_particles3d_class_get_draw_order),
	JS_CFUNC_DEF("set_draw_passes", 1, &gpu_particles3d_class_set_draw_passes),
	JS_CFUNC_DEF("set_draw_pass_mesh", 2, &gpu_particles3d_class_set_draw_pass_mesh),
	JS_CFUNC_DEF("get_draw_passes", 0, &gpu_particles3d_class_get_draw_passes),
	JS_CFUNC_DEF("get_draw_pass_mesh", 1, &gpu_particles3d_class_get_draw_pass_mesh),
	JS_CFUNC_DEF("set_skin", 1, &gpu_particles3d_class_set_skin),
	JS_CFUNC_DEF("get_skin", 0, &gpu_particles3d_class_get_skin),
	JS_CFUNC_DEF("restart", 1, &gpu_particles3d_class_restart),
	JS_CFUNC_DEF("capture_aabb", 0, &gpu_particles3d_class_capture_aabb),
	JS_CFUNC_DEF("set_sub_emitter", 1, &gpu_particles3d_class_set_sub_emitter),
	JS_CFUNC_DEF("get_sub_emitter", 0, &gpu_particles3d_class_get_sub_emitter),
	JS_CFUNC_DEF("emit_particle", 5, &gpu_particles3d_class_emit_particle),
	JS_CFUNC_DEF("set_trail_enabled", 1, &gpu_particles3d_class_set_trail_enabled),
	JS_CFUNC_DEF("set_trail_lifetime", 1, &gpu_particles3d_class_set_trail_lifetime),
	JS_CFUNC_DEF("is_trail_enabled", 0, &gpu_particles3d_class_is_trail_enabled),
	JS_CFUNC_DEF("get_trail_lifetime", 0, &gpu_particles3d_class_get_trail_lifetime),
	JS_CFUNC_DEF("set_transform_align", 1, &gpu_particles3d_class_set_transform_align),
	JS_CFUNC_DEF("get_transform_align", 0, &gpu_particles3d_class_get_transform_align),
	JS_CFUNC_DEF("convert_from_particles", 1, &gpu_particles3d_class_convert_from_particles),
	JS_CFUNC_DEF("set_amount_ratio", 1, &gpu_particles3d_class_set_amount_ratio),
	JS_CFUNC_DEF("get_amount_ratio", 0, &gpu_particles3d_class_get_amount_ratio),
	JS_CFUNC_DEF("request_particles_process", 1, &gpu_particles3d_class_request_particles_process),
};


static JSValue gpu_particles3d_class_get_finished_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	GPUParticles3D *opaque = static_cast<GPUParticles3D *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "finished_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "finished"));
		JS_DefinePropertyValueStr(ctx, this_val, "finished_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_gpu_particles3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "emitting"),
        JS_NewCFunction(ctx, gpu_particles3d_class_is_emitting, "is_emitting", 0),
        JS_NewCFunction(ctx, gpu_particles3d_class_set_emitting, "set_emitting", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "amount"),
        JS_NewCFunction(ctx, gpu_particles3d_class_get_amount, "get_amount", 0),
        JS_NewCFunction(ctx, gpu_particles3d_class_set_amount, "set_amount", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "amount_ratio"),
        JS_NewCFunction(ctx, gpu_particles3d_class_get_amount_ratio, "get_amount_ratio", 0),
        JS_NewCFunction(ctx, gpu_particles3d_class_set_amount_ratio, "set_amount_ratio", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "sub_emitter"),
        JS_NewCFunction(ctx, gpu_particles3d_class_get_sub_emitter, "get_sub_emitter", 0),
        JS_NewCFunction(ctx, gpu_particles3d_class_set_sub_emitter, "set_sub_emitter", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "lifetime"),
        JS_NewCFunction(ctx, gpu_particles3d_class_get_lifetime, "get_lifetime", 0),
        JS_NewCFunction(ctx, gpu_particles3d_class_set_lifetime, "set_lifetime", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "interp_to_end"),
        JS_NewCFunction(ctx, gpu_particles3d_class_get_interp_to_end, "get_interp_to_end", 0),
        JS_NewCFunction(ctx, gpu_particles3d_class_set_interp_to_end, "set_interp_to_end", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "one_shot"),
        JS_NewCFunction(ctx, gpu_particles3d_class_get_one_shot, "get_one_shot", 0),
        JS_NewCFunction(ctx, gpu_particles3d_class_set_one_shot, "set_one_shot", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "preprocess"),
        JS_NewCFunction(ctx, gpu_particles3d_class_get_pre_process_time, "get_pre_process_time", 0),
        JS_NewCFunction(ctx, gpu_particles3d_class_set_pre_process_time, "set_pre_process_time", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "speed_scale"),
        JS_NewCFunction(ctx, gpu_particles3d_class_get_speed_scale, "get_speed_scale", 0),
        JS_NewCFunction(ctx, gpu_particles3d_class_set_speed_scale, "set_speed_scale", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "explosiveness"),
        JS_NewCFunction(ctx, gpu_particles3d_class_get_explosiveness_ratio, "get_explosiveness_ratio", 0),
        JS_NewCFunction(ctx, gpu_particles3d_class_set_explosiveness_ratio, "set_explosiveness_ratio", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "randomness"),
        JS_NewCFunction(ctx, gpu_particles3d_class_get_randomness_ratio, "get_randomness_ratio", 0),
        JS_NewCFunction(ctx, gpu_particles3d_class_set_randomness_ratio, "set_randomness_ratio", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "use_fixed_seed"),
        JS_NewCFunction(ctx, gpu_particles3d_class_get_use_fixed_seed, "get_use_fixed_seed", 0),
        JS_NewCFunction(ctx, gpu_particles3d_class_set_use_fixed_seed, "set_use_fixed_seed", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "seed"),
        JS_NewCFunction(ctx, gpu_particles3d_class_get_seed, "get_seed", 0),
        JS_NewCFunction(ctx, gpu_particles3d_class_set_seed, "set_seed", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "fixed_fps"),
        JS_NewCFunction(ctx, gpu_particles3d_class_get_fixed_fps, "get_fixed_fps", 0),
        JS_NewCFunction(ctx, gpu_particles3d_class_set_fixed_fps, "set_fixed_fps", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "interpolate"),
        JS_NewCFunction(ctx, gpu_particles3d_class_get_interpolate, "get_interpolate", 0),
        JS_NewCFunction(ctx, gpu_particles3d_class_set_interpolate, "set_interpolate", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "fract_delta"),
        JS_NewCFunction(ctx, gpu_particles3d_class_get_fractional_delta, "get_fractional_delta", 0),
        JS_NewCFunction(ctx, gpu_particles3d_class_set_fractional_delta, "set_fractional_delta", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "collision_base_size"),
        JS_NewCFunction(ctx, gpu_particles3d_class_get_collision_base_size, "get_collision_base_size", 0),
        JS_NewCFunction(ctx, gpu_particles3d_class_set_collision_base_size, "set_collision_base_size", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "visibility_aabb"),
        JS_NewCFunction(ctx, gpu_particles3d_class_get_visibility_aabb, "get_visibility_aabb", 0),
        JS_NewCFunction(ctx, gpu_particles3d_class_set_visibility_aabb, "set_visibility_aabb", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "local_coords"),
        JS_NewCFunction(ctx, gpu_particles3d_class_get_use_local_coordinates, "get_use_local_coordinates", 0),
        JS_NewCFunction(ctx, gpu_particles3d_class_set_use_local_coordinates, "set_use_local_coordinates", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "draw_order"),
        JS_NewCFunction(ctx, gpu_particles3d_class_get_draw_order, "get_draw_order", 0),
        JS_NewCFunction(ctx, gpu_particles3d_class_set_draw_order, "set_draw_order", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "transform_align"),
        JS_NewCFunction(ctx, gpu_particles3d_class_get_transform_align, "get_transform_align", 0),
        JS_NewCFunction(ctx, gpu_particles3d_class_set_transform_align, "set_transform_align", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "trail_enabled"),
        JS_NewCFunction(ctx, gpu_particles3d_class_is_trail_enabled, "is_trail_enabled", 0),
        JS_NewCFunction(ctx, gpu_particles3d_class_set_trail_enabled, "set_trail_enabled", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "trail_lifetime"),
        JS_NewCFunction(ctx, gpu_particles3d_class_get_trail_lifetime, "get_trail_lifetime", 0),
        JS_NewCFunction(ctx, gpu_particles3d_class_set_trail_lifetime, "set_trail_lifetime", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "process_material"),
        JS_NewCFunction(ctx, gpu_particles3d_class_get_process_material, "get_process_material", 0),
        JS_NewCFunction(ctx, gpu_particles3d_class_set_process_material, "set_process_material", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "draw_passes"),
        JS_NewCFunction(ctx, gpu_particles3d_class_get_draw_passes, "get_draw_passes", 0),
        JS_NewCFunction(ctx, gpu_particles3d_class_set_draw_passes, "set_draw_passes", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "draw_pass_1"),
        JS_NewCFunction(ctx, gpu_particles3d_class_get_draw_pass_mesh, "get_draw_pass_mesh", 0),
        JS_NewCFunction(ctx, gpu_particles3d_class_set_draw_pass_mesh, "set_draw_pass_mesh", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "draw_pass_2"),
        JS_NewCFunction(ctx, gpu_particles3d_class_get_draw_pass_mesh, "get_draw_pass_mesh", 0),
        JS_NewCFunction(ctx, gpu_particles3d_class_set_draw_pass_mesh, "set_draw_pass_mesh", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "draw_pass_3"),
        JS_NewCFunction(ctx, gpu_particles3d_class_get_draw_pass_mesh, "get_draw_pass_mesh", 0),
        JS_NewCFunction(ctx, gpu_particles3d_class_set_draw_pass_mesh, "set_draw_pass_mesh", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "draw_pass_4"),
        JS_NewCFunction(ctx, gpu_particles3d_class_get_draw_pass_mesh, "get_draw_pass_mesh", 0),
        JS_NewCFunction(ctx, gpu_particles3d_class_set_draw_pass_mesh, "set_draw_pass_mesh", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "draw_skin"),
        JS_NewCFunction(ctx, gpu_particles3d_class_get_skin, "get_skin", 0),
        JS_NewCFunction(ctx, gpu_particles3d_class_set_skin, "set_skin", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "finished"),
		JS_NewCFunction(ctx, gpu_particles3d_class_get_finished_signal, "get_finished_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_gpu_particles3d_enum(JSContext *ctx, JSValue ctor) {
	JSValue DrawOrder_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, DrawOrder_obj, "DRAW_ORDER_INDEX", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, DrawOrder_obj, "DRAW_ORDER_LIFETIME", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, DrawOrder_obj, "DRAW_ORDER_REVERSE_LIFETIME", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, DrawOrder_obj, "DRAW_ORDER_VIEW_DEPTH", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ctor, "DrawOrder", DrawOrder_obj);
	JSValue EmitFlags_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, EmitFlags_obj, "EMIT_FLAG_POSITION", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, EmitFlags_obj, "EMIT_FLAG_ROTATION_SCALE", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, EmitFlags_obj, "EMIT_FLAG_VELOCITY", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, EmitFlags_obj, "EMIT_FLAG_COLOR", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, EmitFlags_obj, "EMIT_FLAG_CUSTOM", JS_NewInt64(ctx, 16));
	JS_SetPropertyStr(ctx, ctor, "EmitFlags", EmitFlags_obj);
	JSValue TransformAlign_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, TransformAlign_obj, "TRANSFORM_ALIGN_DISABLED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, TransformAlign_obj, "TRANSFORM_ALIGN_Z_BILLBOARD", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, TransformAlign_obj, "TRANSFORM_ALIGN_Y_TO_VELOCITY", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, TransformAlign_obj, "TRANSFORM_ALIGN_Z_BILLBOARD_Y_TO_VELOCITY", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ctor, "TransformAlign", TransformAlign_obj);
}

static int js_gpu_particles3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["GPUParticles3D"] = class_id;
	classes_by_id[class_id] = "GPUParticles3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &gpu_particles3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["GeometryInstance3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_gpu_particles3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, gpu_particles3d_class_proto_funcs, _countof(gpu_particles3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, gpu_particles3d_class_constructor, "GPUParticles3D", 0, JS_CFUNC_constructor, 0);
	define_gpu_particles3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "GPUParticles3D", ctor);

	return 0;
}

JSModuleDef *_js_init_gpu_particles3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/geometry_instance3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_gpu_particles3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "GPUParticles3D");
	return m;
}

JSModuleDef *js_init_gpu_particles3d_module(JSContext *ctx) {
	return _js_init_gpu_particles3d_module(ctx, "@godot/classes/gpu_particles3d");
}

void __register_gpu_particles3d() {
	js_init_gpu_particles3d_module(js_context());
}

void register_gpu_particles3d() {
	__register_gpu_particles3d();
}