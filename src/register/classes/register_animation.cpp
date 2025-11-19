#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/animation.hpp>
using namespace godot;

static void animation_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Animation"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef animation_class_def = {
    "Animation",
    animation_class_finalizer
};

static JSValue animation_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["Animation"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    Animation *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<Animation *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(Animation);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue animation_class_add_track(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Animation::add_track, ctx, this_val, argc, argv);
};
static JSValue animation_class_remove_track(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Animation::remove_track, ctx, this_val, argc, argv);
};
static JSValue animation_class_get_track_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Animation::get_track_count, ctx, this_val, argc, argv);
};
static JSValue animation_class_track_get_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Animation::track_get_type, ctx, this_val, argc, argv);
};
static JSValue animation_class_track_get_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Animation::track_get_path, ctx, this_val, argc, argv);
};
static JSValue animation_class_track_set_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Animation::track_set_path, ctx, this_val, argc, argv);
};
static JSValue animation_class_find_track(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Animation::find_track, ctx, this_val, argc, argv);
};
static JSValue animation_class_track_move_up(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Animation::track_move_up, ctx, this_val, argc, argv);
};
static JSValue animation_class_track_move_down(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Animation::track_move_down, ctx, this_val, argc, argv);
};
static JSValue animation_class_track_move_to(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Animation::track_move_to, ctx, this_val, argc, argv);
};
static JSValue animation_class_track_swap(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Animation::track_swap, ctx, this_val, argc, argv);
};
static JSValue animation_class_track_set_imported(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Animation::track_set_imported, ctx, this_val, argc, argv);
};
static JSValue animation_class_track_is_imported(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Animation::track_is_imported, ctx, this_val, argc, argv);
};
static JSValue animation_class_track_set_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Animation::track_set_enabled, ctx, this_val, argc, argv);
};
static JSValue animation_class_track_is_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Animation::track_is_enabled, ctx, this_val, argc, argv);
};
static JSValue animation_class_position_track_insert_key(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Animation::position_track_insert_key, ctx, this_val, argc, argv);
};
static JSValue animation_class_rotation_track_insert_key(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Animation::rotation_track_insert_key, ctx, this_val, argc, argv);
};
static JSValue animation_class_scale_track_insert_key(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Animation::scale_track_insert_key, ctx, this_val, argc, argv);
};
static JSValue animation_class_blend_shape_track_insert_key(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Animation::blend_shape_track_insert_key, ctx, this_val, argc, argv);
};
static JSValue animation_class_position_track_interpolate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Animation::position_track_interpolate, ctx, this_val, argc, argv);
};
static JSValue animation_class_rotation_track_interpolate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Animation::rotation_track_interpolate, ctx, this_val, argc, argv);
};
static JSValue animation_class_scale_track_interpolate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Animation::scale_track_interpolate, ctx, this_val, argc, argv);
};
static JSValue animation_class_blend_shape_track_interpolate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Animation::blend_shape_track_interpolate, ctx, this_val, argc, argv);
};
static JSValue animation_class_track_insert_key(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Animation::track_insert_key, ctx, this_val, argc, argv);
};
static JSValue animation_class_track_remove_key(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Animation::track_remove_key, ctx, this_val, argc, argv);
};
static JSValue animation_class_track_remove_key_at_time(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Animation::track_remove_key_at_time, ctx, this_val, argc, argv);
};
static JSValue animation_class_track_set_key_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Animation::track_set_key_value, ctx, this_val, argc, argv);
};
static JSValue animation_class_track_set_key_transition(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Animation::track_set_key_transition, ctx, this_val, argc, argv);
};
static JSValue animation_class_track_set_key_time(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Animation::track_set_key_time, ctx, this_val, argc, argv);
};
static JSValue animation_class_track_get_key_transition(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Animation::track_get_key_transition, ctx, this_val, argc, argv);
};
static JSValue animation_class_track_get_key_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Animation::track_get_key_count, ctx, this_val, argc, argv);
};
static JSValue animation_class_track_get_key_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Animation::track_get_key_value, ctx, this_val, argc, argv);
};
static JSValue animation_class_track_get_key_time(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Animation::track_get_key_time, ctx, this_val, argc, argv);
};
static JSValue animation_class_track_find_key(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Animation::track_find_key, ctx, this_val, argc, argv);
};
static JSValue animation_class_track_set_interpolation_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Animation::track_set_interpolation_type, ctx, this_val, argc, argv);
};
static JSValue animation_class_track_get_interpolation_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Animation::track_get_interpolation_type, ctx, this_val, argc, argv);
};
static JSValue animation_class_track_set_interpolation_loop_wrap(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Animation::track_set_interpolation_loop_wrap, ctx, this_val, argc, argv);
};
static JSValue animation_class_track_get_interpolation_loop_wrap(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Animation::track_get_interpolation_loop_wrap, ctx, this_val, argc, argv);
};
static JSValue animation_class_track_is_compressed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Animation::track_is_compressed, ctx, this_val, argc, argv);
};
static JSValue animation_class_value_track_set_update_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Animation::value_track_set_update_mode, ctx, this_val, argc, argv);
};
static JSValue animation_class_value_track_get_update_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Animation::value_track_get_update_mode, ctx, this_val, argc, argv);
};
static JSValue animation_class_value_track_interpolate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Animation::value_track_interpolate, ctx, this_val, argc, argv);
};
static JSValue animation_class_method_track_get_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Animation::method_track_get_name, ctx, this_val, argc, argv);
};
static JSValue animation_class_method_track_get_params(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Animation::method_track_get_params, ctx, this_val, argc, argv);
};
static JSValue animation_class_bezier_track_insert_key(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Animation::bezier_track_insert_key, ctx, this_val, argc, argv);
};
static JSValue animation_class_bezier_track_set_key_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Animation::bezier_track_set_key_value, ctx, this_val, argc, argv);
};
static JSValue animation_class_bezier_track_set_key_in_handle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Animation::bezier_track_set_key_in_handle, ctx, this_val, argc, argv);
};
static JSValue animation_class_bezier_track_set_key_out_handle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Animation::bezier_track_set_key_out_handle, ctx, this_val, argc, argv);
};
static JSValue animation_class_bezier_track_get_key_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Animation::bezier_track_get_key_value, ctx, this_val, argc, argv);
};
static JSValue animation_class_bezier_track_get_key_in_handle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Animation::bezier_track_get_key_in_handle, ctx, this_val, argc, argv);
};
static JSValue animation_class_bezier_track_get_key_out_handle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Animation::bezier_track_get_key_out_handle, ctx, this_val, argc, argv);
};
static JSValue animation_class_bezier_track_interpolate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Animation::bezier_track_interpolate, ctx, this_val, argc, argv);
};
static JSValue animation_class_audio_track_insert_key(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Animation::audio_track_insert_key, ctx, this_val, argc, argv);
};
static JSValue animation_class_audio_track_set_key_stream(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Animation::audio_track_set_key_stream, ctx, this_val, argc, argv);
};
static JSValue animation_class_audio_track_set_key_start_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Animation::audio_track_set_key_start_offset, ctx, this_val, argc, argv);
};
static JSValue animation_class_audio_track_set_key_end_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Animation::audio_track_set_key_end_offset, ctx, this_val, argc, argv);
};
static JSValue animation_class_audio_track_get_key_stream(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Animation::audio_track_get_key_stream, ctx, this_val, argc, argv);
};
static JSValue animation_class_audio_track_get_key_start_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Animation::audio_track_get_key_start_offset, ctx, this_val, argc, argv);
};
static JSValue animation_class_audio_track_get_key_end_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Animation::audio_track_get_key_end_offset, ctx, this_val, argc, argv);
};
static JSValue animation_class_audio_track_set_use_blend(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Animation::audio_track_set_use_blend, ctx, this_val, argc, argv);
};
static JSValue animation_class_audio_track_is_use_blend(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Animation::audio_track_is_use_blend, ctx, this_val, argc, argv);
};
static JSValue animation_class_animation_track_insert_key(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Animation::animation_track_insert_key, ctx, this_val, argc, argv);
};
static JSValue animation_class_animation_track_set_key_animation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Animation::animation_track_set_key_animation, ctx, this_val, argc, argv);
};
static JSValue animation_class_animation_track_get_key_animation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Animation::animation_track_get_key_animation, ctx, this_val, argc, argv);
};
static JSValue animation_class_add_marker(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Animation::add_marker, ctx, this_val, argc, argv);
};
static JSValue animation_class_remove_marker(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Animation::remove_marker, ctx, this_val, argc, argv);
};
static JSValue animation_class_has_marker(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Animation::has_marker, ctx, this_val, argc, argv);
};
static JSValue animation_class_get_marker_at_time(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Animation::get_marker_at_time, ctx, this_val, argc, argv);
};
static JSValue animation_class_get_next_marker(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Animation::get_next_marker, ctx, this_val, argc, argv);
};
static JSValue animation_class_get_prev_marker(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Animation::get_prev_marker, ctx, this_val, argc, argv);
};
static JSValue animation_class_get_marker_time(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Animation::get_marker_time, ctx, this_val, argc, argv);
};
static JSValue animation_class_get_marker_names(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Animation::get_marker_names, ctx, this_val, argc, argv);
};
static JSValue animation_class_get_marker_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Animation::get_marker_color, ctx, this_val, argc, argv);
};
static JSValue animation_class_set_marker_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Animation::set_marker_color, ctx, this_val, argc, argv);
};
static JSValue animation_class_set_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Animation::set_length, ctx, this_val, argc, argv);
};
static JSValue animation_class_get_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Animation::get_length, ctx, this_val, argc, argv);
}
static JSValue animation_class_set_loop_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Animation::set_loop_mode, ctx, this_val, argc, argv);
};
static JSValue animation_class_get_loop_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Animation::get_loop_mode, ctx, this_val, argc, argv);
}
static JSValue animation_class_set_step(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Animation::set_step, ctx, this_val, argc, argv);
};
static JSValue animation_class_get_step(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Animation::get_step, ctx, this_val, argc, argv);
}
static JSValue animation_class_clear(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Animation::clear, ctx, this_val, argc, argv);
};
static JSValue animation_class_copy_track(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Animation::copy_track, ctx, this_val, argc, argv);
};
static JSValue animation_class_optimize(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Animation::optimize, ctx, this_val, argc, argv);
};
static JSValue animation_class_compress(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Animation::compress, ctx, this_val, argc, argv);
};
static JSValue animation_class_is_capture_included(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Animation::is_capture_included, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry animation_class_proto_funcs[] = {
	JS_CFUNC_DEF("add_track", 2, &animation_class_add_track),
	JS_CFUNC_DEF("remove_track", 1, &animation_class_remove_track),
	JS_CFUNC_DEF("get_track_count", 0, &animation_class_get_track_count),
	JS_CFUNC_DEF("track_get_type", 1, &animation_class_track_get_type),
	JS_CFUNC_DEF("track_get_path", 1, &animation_class_track_get_path),
	JS_CFUNC_DEF("track_set_path", 2, &animation_class_track_set_path),
	JS_CFUNC_DEF("find_track", 2, &animation_class_find_track),
	JS_CFUNC_DEF("track_move_up", 1, &animation_class_track_move_up),
	JS_CFUNC_DEF("track_move_down", 1, &animation_class_track_move_down),
	JS_CFUNC_DEF("track_move_to", 2, &animation_class_track_move_to),
	JS_CFUNC_DEF("track_swap", 2, &animation_class_track_swap),
	JS_CFUNC_DEF("track_set_imported", 2, &animation_class_track_set_imported),
	JS_CFUNC_DEF("track_is_imported", 1, &animation_class_track_is_imported),
	JS_CFUNC_DEF("track_set_enabled", 2, &animation_class_track_set_enabled),
	JS_CFUNC_DEF("track_is_enabled", 1, &animation_class_track_is_enabled),
	JS_CFUNC_DEF("position_track_insert_key", 3, &animation_class_position_track_insert_key),
	JS_CFUNC_DEF("rotation_track_insert_key", 3, &animation_class_rotation_track_insert_key),
	JS_CFUNC_DEF("scale_track_insert_key", 3, &animation_class_scale_track_insert_key),
	JS_CFUNC_DEF("blend_shape_track_insert_key", 3, &animation_class_blend_shape_track_insert_key),
	JS_CFUNC_DEF("position_track_interpolate", 3, &animation_class_position_track_interpolate),
	JS_CFUNC_DEF("rotation_track_interpolate", 3, &animation_class_rotation_track_interpolate),
	JS_CFUNC_DEF("scale_track_interpolate", 3, &animation_class_scale_track_interpolate),
	JS_CFUNC_DEF("blend_shape_track_interpolate", 3, &animation_class_blend_shape_track_interpolate),
	JS_CFUNC_DEF("track_insert_key", 4, &animation_class_track_insert_key),
	JS_CFUNC_DEF("track_remove_key", 2, &animation_class_track_remove_key),
	JS_CFUNC_DEF("track_remove_key_at_time", 2, &animation_class_track_remove_key_at_time),
	JS_CFUNC_DEF("track_set_key_value", 3, &animation_class_track_set_key_value),
	JS_CFUNC_DEF("track_set_key_transition", 3, &animation_class_track_set_key_transition),
	JS_CFUNC_DEF("track_set_key_time", 3, &animation_class_track_set_key_time),
	JS_CFUNC_DEF("track_get_key_transition", 2, &animation_class_track_get_key_transition),
	JS_CFUNC_DEF("track_get_key_count", 1, &animation_class_track_get_key_count),
	JS_CFUNC_DEF("track_get_key_value", 2, &animation_class_track_get_key_value),
	JS_CFUNC_DEF("track_get_key_time", 2, &animation_class_track_get_key_time),
	JS_CFUNC_DEF("track_find_key", 5, &animation_class_track_find_key),
	JS_CFUNC_DEF("track_set_interpolation_type", 2, &animation_class_track_set_interpolation_type),
	JS_CFUNC_DEF("track_get_interpolation_type", 1, &animation_class_track_get_interpolation_type),
	JS_CFUNC_DEF("track_set_interpolation_loop_wrap", 2, &animation_class_track_set_interpolation_loop_wrap),
	JS_CFUNC_DEF("track_get_interpolation_loop_wrap", 1, &animation_class_track_get_interpolation_loop_wrap),
	JS_CFUNC_DEF("track_is_compressed", 1, &animation_class_track_is_compressed),
	JS_CFUNC_DEF("value_track_set_update_mode", 2, &animation_class_value_track_set_update_mode),
	JS_CFUNC_DEF("value_track_get_update_mode", 1, &animation_class_value_track_get_update_mode),
	JS_CFUNC_DEF("value_track_interpolate", 3, &animation_class_value_track_interpolate),
	JS_CFUNC_DEF("method_track_get_name", 2, &animation_class_method_track_get_name),
	JS_CFUNC_DEF("method_track_get_params", 2, &animation_class_method_track_get_params),
	JS_CFUNC_DEF("bezier_track_insert_key", 5, &animation_class_bezier_track_insert_key),
	JS_CFUNC_DEF("bezier_track_set_key_value", 3, &animation_class_bezier_track_set_key_value),
	JS_CFUNC_DEF("bezier_track_set_key_in_handle", 4, &animation_class_bezier_track_set_key_in_handle),
	JS_CFUNC_DEF("bezier_track_set_key_out_handle", 4, &animation_class_bezier_track_set_key_out_handle),
	JS_CFUNC_DEF("bezier_track_get_key_value", 2, &animation_class_bezier_track_get_key_value),
	JS_CFUNC_DEF("bezier_track_get_key_in_handle", 2, &animation_class_bezier_track_get_key_in_handle),
	JS_CFUNC_DEF("bezier_track_get_key_out_handle", 2, &animation_class_bezier_track_get_key_out_handle),
	JS_CFUNC_DEF("bezier_track_interpolate", 2, &animation_class_bezier_track_interpolate),
	JS_CFUNC_DEF("audio_track_insert_key", 5, &animation_class_audio_track_insert_key),
	JS_CFUNC_DEF("audio_track_set_key_stream", 3, &animation_class_audio_track_set_key_stream),
	JS_CFUNC_DEF("audio_track_set_key_start_offset", 3, &animation_class_audio_track_set_key_start_offset),
	JS_CFUNC_DEF("audio_track_set_key_end_offset", 3, &animation_class_audio_track_set_key_end_offset),
	JS_CFUNC_DEF("audio_track_get_key_stream", 2, &animation_class_audio_track_get_key_stream),
	JS_CFUNC_DEF("audio_track_get_key_start_offset", 2, &animation_class_audio_track_get_key_start_offset),
	JS_CFUNC_DEF("audio_track_get_key_end_offset", 2, &animation_class_audio_track_get_key_end_offset),
	JS_CFUNC_DEF("audio_track_set_use_blend", 2, &animation_class_audio_track_set_use_blend),
	JS_CFUNC_DEF("audio_track_is_use_blend", 1, &animation_class_audio_track_is_use_blend),
	JS_CFUNC_DEF("animation_track_insert_key", 3, &animation_class_animation_track_insert_key),
	JS_CFUNC_DEF("animation_track_set_key_animation", 3, &animation_class_animation_track_set_key_animation),
	JS_CFUNC_DEF("animation_track_get_key_animation", 2, &animation_class_animation_track_get_key_animation),
	JS_CFUNC_DEF("add_marker", 2, &animation_class_add_marker),
	JS_CFUNC_DEF("remove_marker", 1, &animation_class_remove_marker),
	JS_CFUNC_DEF("has_marker", 1, &animation_class_has_marker),
	JS_CFUNC_DEF("get_marker_at_time", 1, &animation_class_get_marker_at_time),
	JS_CFUNC_DEF("get_next_marker", 1, &animation_class_get_next_marker),
	JS_CFUNC_DEF("get_prev_marker", 1, &animation_class_get_prev_marker),
	JS_CFUNC_DEF("get_marker_time", 1, &animation_class_get_marker_time),
	JS_CFUNC_DEF("get_marker_names", 0, &animation_class_get_marker_names),
	JS_CFUNC_DEF("get_marker_color", 1, &animation_class_get_marker_color),
	JS_CFUNC_DEF("set_marker_color", 2, &animation_class_set_marker_color),
	JS_CFUNC_DEF("set_length", 1, &animation_class_set_length),
	JS_CFUNC_DEF("get_length", 0, &animation_class_get_length),
	JS_CFUNC_DEF("set_loop_mode", 1, &animation_class_set_loop_mode),
	JS_CFUNC_DEF("get_loop_mode", 0, &animation_class_get_loop_mode),
	JS_CFUNC_DEF("set_step", 1, &animation_class_set_step),
	JS_CFUNC_DEF("get_step", 0, &animation_class_get_step),
	JS_CFUNC_DEF("clear", 0, &animation_class_clear),
	JS_CFUNC_DEF("copy_track", 2, &animation_class_copy_track),
	JS_CFUNC_DEF("optimize", 3, &animation_class_optimize),
	JS_CFUNC_DEF("compress", 3, &animation_class_compress),
	JS_CFUNC_DEF("is_capture_included", 0, &animation_class_is_capture_included),
};




static void define_animation_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "length"),
        JS_NewCFunction(ctx, animation_class_get_length, "get_length", 0),
        JS_NewCFunction(ctx, animation_class_set_length, "set_length", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "loop_mode"),
        JS_NewCFunction(ctx, animation_class_get_loop_mode, "get_loop_mode", 0),
        JS_NewCFunction(ctx, animation_class_set_loop_mode, "set_loop_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "step"),
        JS_NewCFunction(ctx, animation_class_get_step, "get_step", 0),
        JS_NewCFunction(ctx, animation_class_set_step, "set_step", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "capture_included"),
        JS_NewCFunction(ctx, animation_class_is_capture_included, "is_capture_included", 0),
        JS_UNDEFINED,
        JS_PROP_GETSET
    );
}

static void define_animation_enum(JSContext *ctx, JSValue ctor) {
	JSValue TrackType_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, TrackType_obj, "TYPE_VALUE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, TrackType_obj, "TYPE_POSITION_3D", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, TrackType_obj, "TYPE_ROTATION_3D", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, TrackType_obj, "TYPE_SCALE_3D", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, TrackType_obj, "TYPE_BLEND_SHAPE", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, TrackType_obj, "TYPE_METHOD", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, TrackType_obj, "TYPE_BEZIER", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, TrackType_obj, "TYPE_AUDIO", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, TrackType_obj, "TYPE_ANIMATION", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, ctor, "TrackType", TrackType_obj);
	JSValue InterpolationType_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, InterpolationType_obj, "INTERPOLATION_NEAREST", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, InterpolationType_obj, "INTERPOLATION_LINEAR", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, InterpolationType_obj, "INTERPOLATION_CUBIC", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, InterpolationType_obj, "INTERPOLATION_LINEAR_ANGLE", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, InterpolationType_obj, "INTERPOLATION_CUBIC_ANGLE", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, ctor, "InterpolationType", InterpolationType_obj);
	JSValue UpdateMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, UpdateMode_obj, "UPDATE_CONTINUOUS", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, UpdateMode_obj, "UPDATE_DISCRETE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, UpdateMode_obj, "UPDATE_CAPTURE", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "UpdateMode", UpdateMode_obj);
	JSValue LoopMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, LoopMode_obj, "LOOP_NONE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, LoopMode_obj, "LOOP_LINEAR", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, LoopMode_obj, "LOOP_PINGPONG", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "LoopMode", LoopMode_obj);
	JSValue LoopedFlag_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, LoopedFlag_obj, "LOOPED_FLAG_NONE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, LoopedFlag_obj, "LOOPED_FLAG_END", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, LoopedFlag_obj, "LOOPED_FLAG_START", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "LoopedFlag", LoopedFlag_obj);
	JSValue FindMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, FindMode_obj, "FIND_MODE_NEAREST", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, FindMode_obj, "FIND_MODE_APPROX", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, FindMode_obj, "FIND_MODE_EXACT", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "FindMode", FindMode_obj);
}

static int js_animation_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["Animation"] = class_id;
	classes_by_id[class_id] = "Animation";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &animation_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Resource"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_animation_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, animation_class_proto_funcs, _countof(animation_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, animation_class_constructor, "Animation", 0, JS_CFUNC_constructor, 0);
	define_animation_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "Animation", ctor);

	return 0;
}

JSModuleDef *_js_init_animation_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/resource';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_animation_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Animation");
	return m;
}

JSModuleDef *js_init_animation_module(JSContext *ctx) {
	return _js_init_animation_module(ctx, "@godot/classes/animation");
}

void __register_animation() {
	js_init_animation_module(js_context());
}

void register_animation() {
	__register_animation();
}