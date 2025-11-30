#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/xr_interface.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/open_xr_interface.hpp>
using namespace godot;

static void open_xr_interface_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["OpenXRInterface"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef open_xr_interface_class_def = {
    "OpenXRInterface",
    open_xr_interface_class_finalizer
};

static JSValue open_xr_interface_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["OpenXRInterface"];
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
        instance = memnew(OpenXRInterface);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue open_xr_interface_class_get_session_state(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&OpenXRInterface::get_session_state, ctx, this_val, argc, argv);
};
static JSValue open_xr_interface_class_get_display_refresh_rate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRInterface::get_display_refresh_rate, ctx, this_val, argc, argv);
}
static JSValue open_xr_interface_class_set_display_refresh_rate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRInterface::set_display_refresh_rate, ctx, this_val, argc, argv);
};
static JSValue open_xr_interface_class_get_render_target_size_multiplier(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRInterface::get_render_target_size_multiplier, ctx, this_val, argc, argv);
}
static JSValue open_xr_interface_class_set_render_target_size_multiplier(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRInterface::set_render_target_size_multiplier, ctx, this_val, argc, argv);
};
static JSValue open_xr_interface_class_is_foveation_supported(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRInterface::is_foveation_supported, ctx, this_val, argc, argv);
};
static JSValue open_xr_interface_class_get_foveation_level(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRInterface::get_foveation_level, ctx, this_val, argc, argv);
}
static JSValue open_xr_interface_class_set_foveation_level(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRInterface::set_foveation_level, ctx, this_val, argc, argv);
};
static JSValue open_xr_interface_class_get_foveation_dynamic(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRInterface::get_foveation_dynamic, ctx, this_val, argc, argv);
}
static JSValue open_xr_interface_class_set_foveation_dynamic(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRInterface::set_foveation_dynamic, ctx, this_val, argc, argv);
};
static JSValue open_xr_interface_class_is_action_set_active(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRInterface::is_action_set_active, ctx, this_val, argc, argv);
};
static JSValue open_xr_interface_class_set_action_set_active(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRInterface::set_action_set_active, ctx, this_val, argc, argv);
};
static JSValue open_xr_interface_class_get_action_sets(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRInterface::get_action_sets, ctx, this_val, argc, argv);
};
static JSValue open_xr_interface_class_get_available_display_refresh_rates(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRInterface::get_available_display_refresh_rates, ctx, this_val, argc, argv);
};
static JSValue open_xr_interface_class_set_motion_range(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRInterface::set_motion_range, ctx, this_val, argc, argv);
};
static JSValue open_xr_interface_class_get_motion_range(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRInterface::get_motion_range, ctx, this_val, argc, argv);
};
static JSValue open_xr_interface_class_get_hand_tracking_source(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRInterface::get_hand_tracking_source, ctx, this_val, argc, argv);
};
static JSValue open_xr_interface_class_get_hand_joint_flags(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRInterface::get_hand_joint_flags, ctx, this_val, argc, argv);
};
static JSValue open_xr_interface_class_get_hand_joint_rotation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRInterface::get_hand_joint_rotation, ctx, this_val, argc, argv);
};
static JSValue open_xr_interface_class_get_hand_joint_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRInterface::get_hand_joint_position, ctx, this_val, argc, argv);
};
static JSValue open_xr_interface_class_get_hand_joint_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRInterface::get_hand_joint_radius, ctx, this_val, argc, argv);
};
static JSValue open_xr_interface_class_get_hand_joint_linear_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRInterface::get_hand_joint_linear_velocity, ctx, this_val, argc, argv);
};
static JSValue open_xr_interface_class_get_hand_joint_angular_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRInterface::get_hand_joint_angular_velocity, ctx, this_val, argc, argv);
};
static JSValue open_xr_interface_class_is_hand_tracking_supported(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&OpenXRInterface::is_hand_tracking_supported, ctx, this_val, argc, argv);
};
static JSValue open_xr_interface_class_is_hand_interaction_supported(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRInterface::is_hand_interaction_supported, ctx, this_val, argc, argv);
};
static JSValue open_xr_interface_class_is_eye_gaze_interaction_supported(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&OpenXRInterface::is_eye_gaze_interaction_supported, ctx, this_val, argc, argv);
};
static JSValue open_xr_interface_class_get_vrs_min_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRInterface::get_vrs_min_radius, ctx, this_val, argc, argv);
}
static JSValue open_xr_interface_class_set_vrs_min_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRInterface::set_vrs_min_radius, ctx, this_val, argc, argv);
};
static JSValue open_xr_interface_class_get_vrs_strength(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRInterface::get_vrs_strength, ctx, this_val, argc, argv);
}
static JSValue open_xr_interface_class_set_vrs_strength(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRInterface::set_vrs_strength, ctx, this_val, argc, argv);
};
static JSValue open_xr_interface_class_set_cpu_level(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRInterface::set_cpu_level, ctx, this_val, argc, argv);
};
static JSValue open_xr_interface_class_set_gpu_level(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRInterface::set_gpu_level, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry open_xr_interface_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_session_state", 0, &open_xr_interface_class_get_session_state),
	JS_CFUNC_DEF("get_display_refresh_rate", 0, &open_xr_interface_class_get_display_refresh_rate),
	JS_CFUNC_DEF("set_display_refresh_rate", 1, &open_xr_interface_class_set_display_refresh_rate),
	JS_CFUNC_DEF("get_render_target_size_multiplier", 0, &open_xr_interface_class_get_render_target_size_multiplier),
	JS_CFUNC_DEF("set_render_target_size_multiplier", 1, &open_xr_interface_class_set_render_target_size_multiplier),
	JS_CFUNC_DEF("is_foveation_supported", 0, &open_xr_interface_class_is_foveation_supported),
	JS_CFUNC_DEF("get_foveation_level", 0, &open_xr_interface_class_get_foveation_level),
	JS_CFUNC_DEF("set_foveation_level", 1, &open_xr_interface_class_set_foveation_level),
	JS_CFUNC_DEF("get_foveation_dynamic", 0, &open_xr_interface_class_get_foveation_dynamic),
	JS_CFUNC_DEF("set_foveation_dynamic", 1, &open_xr_interface_class_set_foveation_dynamic),
	JS_CFUNC_DEF("is_action_set_active", 1, &open_xr_interface_class_is_action_set_active),
	JS_CFUNC_DEF("set_action_set_active", 2, &open_xr_interface_class_set_action_set_active),
	JS_CFUNC_DEF("get_action_sets", 0, &open_xr_interface_class_get_action_sets),
	JS_CFUNC_DEF("get_available_display_refresh_rates", 0, &open_xr_interface_class_get_available_display_refresh_rates),
	JS_CFUNC_DEF("set_motion_range", 2, &open_xr_interface_class_set_motion_range),
	JS_CFUNC_DEF("get_motion_range", 1, &open_xr_interface_class_get_motion_range),
	JS_CFUNC_DEF("get_hand_tracking_source", 1, &open_xr_interface_class_get_hand_tracking_source),
	JS_CFUNC_DEF("get_hand_joint_flags", 2, &open_xr_interface_class_get_hand_joint_flags),
	JS_CFUNC_DEF("get_hand_joint_rotation", 2, &open_xr_interface_class_get_hand_joint_rotation),
	JS_CFUNC_DEF("get_hand_joint_position", 2, &open_xr_interface_class_get_hand_joint_position),
	JS_CFUNC_DEF("get_hand_joint_radius", 2, &open_xr_interface_class_get_hand_joint_radius),
	JS_CFUNC_DEF("get_hand_joint_linear_velocity", 2, &open_xr_interface_class_get_hand_joint_linear_velocity),
	JS_CFUNC_DEF("get_hand_joint_angular_velocity", 2, &open_xr_interface_class_get_hand_joint_angular_velocity),
	JS_CFUNC_DEF("is_hand_tracking_supported", 0, &open_xr_interface_class_is_hand_tracking_supported),
	JS_CFUNC_DEF("is_hand_interaction_supported", 0, &open_xr_interface_class_is_hand_interaction_supported),
	JS_CFUNC_DEF("is_eye_gaze_interaction_supported", 0, &open_xr_interface_class_is_eye_gaze_interaction_supported),
	JS_CFUNC_DEF("get_vrs_min_radius", 0, &open_xr_interface_class_get_vrs_min_radius),
	JS_CFUNC_DEF("set_vrs_min_radius", 1, &open_xr_interface_class_set_vrs_min_radius),
	JS_CFUNC_DEF("get_vrs_strength", 0, &open_xr_interface_class_get_vrs_strength),
	JS_CFUNC_DEF("set_vrs_strength", 1, &open_xr_interface_class_set_vrs_strength),
	JS_CFUNC_DEF("set_cpu_level", 1, &open_xr_interface_class_set_cpu_level),
	JS_CFUNC_DEF("set_gpu_level", 1, &open_xr_interface_class_set_gpu_level),
};


static JSValue open_xr_interface_class_get_session_begun_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "session_begun");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue open_xr_interface_class_get_session_stopping_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "session_stopping");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue open_xr_interface_class_get_session_synchronized_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "session_synchronized");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue open_xr_interface_class_get_session_focussed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "session_focussed");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue open_xr_interface_class_get_session_visible_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "session_visible");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue open_xr_interface_class_get_session_loss_pending_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "session_loss_pending");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue open_xr_interface_class_get_instance_exiting_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "instance_exiting");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue open_xr_interface_class_get_pose_recentered_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "pose_recentered");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue open_xr_interface_class_get_refresh_rate_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "refresh_rate_changed");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue open_xr_interface_class_get_cpu_level_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "cpu_level_changed");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue open_xr_interface_class_get_gpu_level_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "gpu_level_changed");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}


static void define_open_xr_interface_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "display_refresh_rate"),
        JS_NewCFunction(ctx, open_xr_interface_class_get_display_refresh_rate, "get_display_refresh_rate", 0),
        JS_NewCFunction(ctx, open_xr_interface_class_set_display_refresh_rate, "set_display_refresh_rate", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "render_target_size_multiplier"),
        JS_NewCFunction(ctx, open_xr_interface_class_get_render_target_size_multiplier, "get_render_target_size_multiplier", 0),
        JS_NewCFunction(ctx, open_xr_interface_class_set_render_target_size_multiplier, "set_render_target_size_multiplier", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "foveation_level"),
        JS_NewCFunction(ctx, open_xr_interface_class_get_foveation_level, "get_foveation_level", 0),
        JS_NewCFunction(ctx, open_xr_interface_class_set_foveation_level, "set_foveation_level", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "foveation_dynamic"),
        JS_NewCFunction(ctx, open_xr_interface_class_get_foveation_dynamic, "get_foveation_dynamic", 0),
        JS_NewCFunction(ctx, open_xr_interface_class_set_foveation_dynamic, "set_foveation_dynamic", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "vrs_min_radius"),
        JS_NewCFunction(ctx, open_xr_interface_class_get_vrs_min_radius, "get_vrs_min_radius", 0),
        JS_NewCFunction(ctx, open_xr_interface_class_set_vrs_min_radius, "set_vrs_min_radius", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "vrs_strength"),
        JS_NewCFunction(ctx, open_xr_interface_class_get_vrs_strength, "get_vrs_strength", 0),
        JS_NewCFunction(ctx, open_xr_interface_class_set_vrs_strength, "set_vrs_strength", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "session_begun"),
		JS_NewCFunction(ctx, open_xr_interface_class_get_session_begun_signal, "get_session_begun_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "session_stopping"),
		JS_NewCFunction(ctx, open_xr_interface_class_get_session_stopping_signal, "get_session_stopping_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "session_synchronized"),
		JS_NewCFunction(ctx, open_xr_interface_class_get_session_synchronized_signal, "get_session_synchronized_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "session_focussed"),
		JS_NewCFunction(ctx, open_xr_interface_class_get_session_focussed_signal, "get_session_focussed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "session_visible"),
		JS_NewCFunction(ctx, open_xr_interface_class_get_session_visible_signal, "get_session_visible_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "session_loss_pending"),
		JS_NewCFunction(ctx, open_xr_interface_class_get_session_loss_pending_signal, "get_session_loss_pending_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "instance_exiting"),
		JS_NewCFunction(ctx, open_xr_interface_class_get_instance_exiting_signal, "get_instance_exiting_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "pose_recentered"),
		JS_NewCFunction(ctx, open_xr_interface_class_get_pose_recentered_signal, "get_pose_recentered_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "refresh_rate_changed"),
		JS_NewCFunction(ctx, open_xr_interface_class_get_refresh_rate_changed_signal, "get_refresh_rate_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "cpu_level_changed"),
		JS_NewCFunction(ctx, open_xr_interface_class_get_cpu_level_changed_signal, "get_cpu_level_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "gpu_level_changed"),
		JS_NewCFunction(ctx, open_xr_interface_class_get_gpu_level_changed_signal, "get_gpu_level_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_open_xr_interface_enum(JSContext *ctx, JSValue ctor) {
	JSValue SessionState_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, SessionState_obj, "SESSION_STATE_UNKNOWN", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, SessionState_obj, "SESSION_STATE_IDLE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, SessionState_obj, "SESSION_STATE_READY", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, SessionState_obj, "SESSION_STATE_SYNCHRONIZED", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, SessionState_obj, "SESSION_STATE_VISIBLE", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, SessionState_obj, "SESSION_STATE_FOCUSED", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, SessionState_obj, "SESSION_STATE_STOPPING", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, SessionState_obj, "SESSION_STATE_LOSS_PENDING", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, SessionState_obj, "SESSION_STATE_EXITING", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, ctor, "SessionState", SessionState_obj);
	JSValue Hand_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, Hand_obj, "HAND_LEFT", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, Hand_obj, "HAND_RIGHT", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, Hand_obj, "HAND_MAX", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "Hand", Hand_obj);
	JSValue HandMotionRange_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, HandMotionRange_obj, "HAND_MOTION_RANGE_UNOBSTRUCTED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, HandMotionRange_obj, "HAND_MOTION_RANGE_CONFORM_TO_CONTROLLER", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, HandMotionRange_obj, "HAND_MOTION_RANGE_MAX", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "HandMotionRange", HandMotionRange_obj);
	JSValue HandTrackedSource_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, HandTrackedSource_obj, "HAND_TRACKED_SOURCE_UNKNOWN", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, HandTrackedSource_obj, "HAND_TRACKED_SOURCE_UNOBSTRUCTED", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, HandTrackedSource_obj, "HAND_TRACKED_SOURCE_CONTROLLER", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, HandTrackedSource_obj, "HAND_TRACKED_SOURCE_MAX", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ctor, "HandTrackedSource", HandTrackedSource_obj);
	JSValue HandJoints_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, HandJoints_obj, "HAND_JOINT_PALM", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, HandJoints_obj, "HAND_JOINT_WRIST", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, HandJoints_obj, "HAND_JOINT_THUMB_METACARPAL", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, HandJoints_obj, "HAND_JOINT_THUMB_PROXIMAL", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, HandJoints_obj, "HAND_JOINT_THUMB_DISTAL", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, HandJoints_obj, "HAND_JOINT_THUMB_TIP", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, HandJoints_obj, "HAND_JOINT_INDEX_METACARPAL", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, HandJoints_obj, "HAND_JOINT_INDEX_PROXIMAL", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, HandJoints_obj, "HAND_JOINT_INDEX_INTERMEDIATE", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, HandJoints_obj, "HAND_JOINT_INDEX_DISTAL", JS_NewInt64(ctx, 9));
	JS_SetPropertyStr(ctx, HandJoints_obj, "HAND_JOINT_INDEX_TIP", JS_NewInt64(ctx, 10));
	JS_SetPropertyStr(ctx, HandJoints_obj, "HAND_JOINT_MIDDLE_METACARPAL", JS_NewInt64(ctx, 11));
	JS_SetPropertyStr(ctx, HandJoints_obj, "HAND_JOINT_MIDDLE_PROXIMAL", JS_NewInt64(ctx, 12));
	JS_SetPropertyStr(ctx, HandJoints_obj, "HAND_JOINT_MIDDLE_INTERMEDIATE", JS_NewInt64(ctx, 13));
	JS_SetPropertyStr(ctx, HandJoints_obj, "HAND_JOINT_MIDDLE_DISTAL", JS_NewInt64(ctx, 14));
	JS_SetPropertyStr(ctx, HandJoints_obj, "HAND_JOINT_MIDDLE_TIP", JS_NewInt64(ctx, 15));
	JS_SetPropertyStr(ctx, HandJoints_obj, "HAND_JOINT_RING_METACARPAL", JS_NewInt64(ctx, 16));
	JS_SetPropertyStr(ctx, HandJoints_obj, "HAND_JOINT_RING_PROXIMAL", JS_NewInt64(ctx, 17));
	JS_SetPropertyStr(ctx, HandJoints_obj, "HAND_JOINT_RING_INTERMEDIATE", JS_NewInt64(ctx, 18));
	JS_SetPropertyStr(ctx, HandJoints_obj, "HAND_JOINT_RING_DISTAL", JS_NewInt64(ctx, 19));
	JS_SetPropertyStr(ctx, HandJoints_obj, "HAND_JOINT_RING_TIP", JS_NewInt64(ctx, 20));
	JS_SetPropertyStr(ctx, HandJoints_obj, "HAND_JOINT_LITTLE_METACARPAL", JS_NewInt64(ctx, 21));
	JS_SetPropertyStr(ctx, HandJoints_obj, "HAND_JOINT_LITTLE_PROXIMAL", JS_NewInt64(ctx, 22));
	JS_SetPropertyStr(ctx, HandJoints_obj, "HAND_JOINT_LITTLE_INTERMEDIATE", JS_NewInt64(ctx, 23));
	JS_SetPropertyStr(ctx, HandJoints_obj, "HAND_JOINT_LITTLE_DISTAL", JS_NewInt64(ctx, 24));
	JS_SetPropertyStr(ctx, HandJoints_obj, "HAND_JOINT_LITTLE_TIP", JS_NewInt64(ctx, 25));
	JS_SetPropertyStr(ctx, HandJoints_obj, "HAND_JOINT_MAX", JS_NewInt64(ctx, 26));
	JS_SetPropertyStr(ctx, ctor, "HandJoints", HandJoints_obj);
	JSValue PerfSettingsLevel_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, PerfSettingsLevel_obj, "PERF_SETTINGS_LEVEL_POWER_SAVINGS", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, PerfSettingsLevel_obj, "PERF_SETTINGS_LEVEL_SUSTAINED_LOW", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, PerfSettingsLevel_obj, "PERF_SETTINGS_LEVEL_SUSTAINED_HIGH", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, PerfSettingsLevel_obj, "PERF_SETTINGS_LEVEL_BOOST", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ctor, "PerfSettingsLevel", PerfSettingsLevel_obj);
	JSValue PerfSettingsSubDomain_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, PerfSettingsSubDomain_obj, "PERF_SETTINGS_SUB_DOMAIN_COMPOSITING", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, PerfSettingsSubDomain_obj, "PERF_SETTINGS_SUB_DOMAIN_RENDERING", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, PerfSettingsSubDomain_obj, "PERF_SETTINGS_SUB_DOMAIN_THERMAL", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "PerfSettingsSubDomain", PerfSettingsSubDomain_obj);
	JSValue PerfSettingsNotificationLevel_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, PerfSettingsNotificationLevel_obj, "PERF_SETTINGS_NOTIF_LEVEL_NORMAL", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, PerfSettingsNotificationLevel_obj, "PERF_SETTINGS_NOTIF_LEVEL_WARNING", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, PerfSettingsNotificationLevel_obj, "PERF_SETTINGS_NOTIF_LEVEL_IMPAIRED", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "PerfSettingsNotificationLevel", PerfSettingsNotificationLevel_obj);
	JSValue HandJointFlags_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, HandJointFlags_obj, "HAND_JOINT_NONE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, HandJointFlags_obj, "HAND_JOINT_ORIENTATION_VALID", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, HandJointFlags_obj, "HAND_JOINT_ORIENTATION_TRACKED", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, HandJointFlags_obj, "HAND_JOINT_POSITION_VALID", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, HandJointFlags_obj, "HAND_JOINT_POSITION_TRACKED", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, HandJointFlags_obj, "HAND_JOINT_LINEAR_VELOCITY_VALID", JS_NewInt64(ctx, 16));
	JS_SetPropertyStr(ctx, HandJointFlags_obj, "HAND_JOINT_ANGULAR_VELOCITY_VALID", JS_NewInt64(ctx, 32));
	JS_SetPropertyStr(ctx, ctor, "HandJointFlags", HandJointFlags_obj);
}

static int js_open_xr_interface_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["OpenXRInterface"] = class_id;
	classes_by_id[class_id] = "OpenXRInterface";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &open_xr_interface_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["XRInterface"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_open_xr_interface_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, open_xr_interface_class_proto_funcs, _countof(open_xr_interface_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, open_xr_interface_class_constructor, "OpenXRInterface", 0, JS_CFUNC_constructor, 0);
	define_open_xr_interface_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "OpenXRInterface", ctor);
	ctor_list["OpenXRInterface"] = ctor;

	return 0;
}

JSModuleDef *_js_init_open_xr_interface_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/xr_interface';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_open_xr_interface_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "OpenXRInterface");
	return m;
}

JSModuleDef *js_init_open_xr_interface_module(JSContext *ctx) {
	return _js_init_open_xr_interface_module(ctx, "@godot/classes/open_xr_interface");
}

void __register_open_xr_interface() {
	js_init_open_xr_interface_module(js_context());
}

void register_open_xr_interface() {
	__register_open_xr_interface();
}