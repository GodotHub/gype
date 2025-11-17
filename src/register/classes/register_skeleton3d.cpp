#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/skin.hpp>
#include <godot_cpp/classes/skin_reference.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/skeleton3d.hpp>
using namespace godot;

static void skeleton3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Skeleton3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef skeleton3d_class_def = {
    "Skeleton3D",
    skeleton3d_class_finalizer
};

static JSValue skeleton3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["Skeleton3D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    Skeleton3D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<Skeleton3D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(Skeleton3D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue skeleton3d_class_add_bone(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Skeleton3D::add_bone, ctx, this_val, argc, argv);
};
static JSValue skeleton3d_class_find_bone(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Skeleton3D::find_bone, ctx, this_val, argc, argv);
};
static JSValue skeleton3d_class_get_bone_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Skeleton3D::get_bone_name, ctx, this_val, argc, argv);
};
static JSValue skeleton3d_class_set_bone_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Skeleton3D::set_bone_name, ctx, this_val, argc, argv);
};
static JSValue skeleton3d_class_get_bone_meta(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Skeleton3D::get_bone_meta, ctx, this_val, argc, argv);
};
static JSValue skeleton3d_class_get_bone_meta_list(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Skeleton3D::get_bone_meta_list, ctx, this_val, argc, argv);
};
static JSValue skeleton3d_class_has_bone_meta(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Skeleton3D::has_bone_meta, ctx, this_val, argc, argv);
};
static JSValue skeleton3d_class_set_bone_meta(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Skeleton3D::set_bone_meta, ctx, this_val, argc, argv);
};
static JSValue skeleton3d_class_get_concatenated_bone_names(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Skeleton3D::get_concatenated_bone_names, ctx, this_val, argc, argv);
};
static JSValue skeleton3d_class_get_bone_parent(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Skeleton3D::get_bone_parent, ctx, this_val, argc, argv);
};
static JSValue skeleton3d_class_set_bone_parent(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Skeleton3D::set_bone_parent, ctx, this_val, argc, argv);
};
static JSValue skeleton3d_class_get_bone_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Skeleton3D::get_bone_count, ctx, this_val, argc, argv);
};
static JSValue skeleton3d_class_get_version(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Skeleton3D::get_version, ctx, this_val, argc, argv);
};
static JSValue skeleton3d_class_unparent_bone_and_rest(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Skeleton3D::unparent_bone_and_rest, ctx, this_val, argc, argv);
};
static JSValue skeleton3d_class_get_bone_children(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Skeleton3D::get_bone_children, ctx, this_val, argc, argv);
};
static JSValue skeleton3d_class_get_parentless_bones(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Skeleton3D::get_parentless_bones, ctx, this_val, argc, argv);
};
static JSValue skeleton3d_class_get_bone_rest(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Skeleton3D::get_bone_rest, ctx, this_val, argc, argv);
};
static JSValue skeleton3d_class_set_bone_rest(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Skeleton3D::set_bone_rest, ctx, this_val, argc, argv);
};
static JSValue skeleton3d_class_get_bone_global_rest(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Skeleton3D::get_bone_global_rest, ctx, this_val, argc, argv);
};
static JSValue skeleton3d_class_create_skin_from_rest_transforms(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Skeleton3D::create_skin_from_rest_transforms, ctx, this_val, argc, argv);
};
static JSValue skeleton3d_class_register_skin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&Skeleton3D::register_skin, ctx, this_val, argc, argv);
};
static JSValue skeleton3d_class_localize_rests(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Skeleton3D::localize_rests, ctx, this_val, argc, argv);
};
static JSValue skeleton3d_class_clear_bones(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Skeleton3D::clear_bones, ctx, this_val, argc, argv);
};
static JSValue skeleton3d_class_get_bone_pose(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Skeleton3D::get_bone_pose, ctx, this_val, argc, argv);
};
static JSValue skeleton3d_class_set_bone_pose(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Skeleton3D::set_bone_pose, ctx, this_val, argc, argv);
};
static JSValue skeleton3d_class_set_bone_pose_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Skeleton3D::set_bone_pose_position, ctx, this_val, argc, argv);
};
static JSValue skeleton3d_class_set_bone_pose_rotation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Skeleton3D::set_bone_pose_rotation, ctx, this_val, argc, argv);
};
static JSValue skeleton3d_class_set_bone_pose_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Skeleton3D::set_bone_pose_scale, ctx, this_val, argc, argv);
};
static JSValue skeleton3d_class_get_bone_pose_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Skeleton3D::get_bone_pose_position, ctx, this_val, argc, argv);
};
static JSValue skeleton3d_class_get_bone_pose_rotation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Skeleton3D::get_bone_pose_rotation, ctx, this_val, argc, argv);
};
static JSValue skeleton3d_class_get_bone_pose_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Skeleton3D::get_bone_pose_scale, ctx, this_val, argc, argv);
};
static JSValue skeleton3d_class_reset_bone_pose(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Skeleton3D::reset_bone_pose, ctx, this_val, argc, argv);
};
static JSValue skeleton3d_class_reset_bone_poses(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Skeleton3D::reset_bone_poses, ctx, this_val, argc, argv);
};
static JSValue skeleton3d_class_is_bone_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Skeleton3D::is_bone_enabled, ctx, this_val, argc, argv);
};
static JSValue skeleton3d_class_set_bone_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Skeleton3D::set_bone_enabled, ctx, this_val, argc, argv);
};
static JSValue skeleton3d_class_get_bone_global_pose(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Skeleton3D::get_bone_global_pose, ctx, this_val, argc, argv);
};
static JSValue skeleton3d_class_set_bone_global_pose(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Skeleton3D::set_bone_global_pose, ctx, this_val, argc, argv);
};
static JSValue skeleton3d_class_force_update_all_bone_transforms(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Skeleton3D::force_update_all_bone_transforms, ctx, this_val, argc, argv);
};
static JSValue skeleton3d_class_force_update_bone_child_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Skeleton3D::force_update_bone_child_transform, ctx, this_val, argc, argv);
};
static JSValue skeleton3d_class_set_motion_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Skeleton3D::set_motion_scale, ctx, this_val, argc, argv);
};
static JSValue skeleton3d_class_get_motion_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Skeleton3D::get_motion_scale, ctx, this_val, argc, argv);
}
static JSValue skeleton3d_class_set_show_rest_only(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Skeleton3D::set_show_rest_only, ctx, this_val, argc, argv);
};
static JSValue skeleton3d_class_is_show_rest_only(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Skeleton3D::is_show_rest_only, ctx, this_val, argc, argv);
}
static JSValue skeleton3d_class_set_modifier_callback_mode_process(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Skeleton3D::set_modifier_callback_mode_process, ctx, this_val, argc, argv);
};
static JSValue skeleton3d_class_get_modifier_callback_mode_process(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Skeleton3D::get_modifier_callback_mode_process, ctx, this_val, argc, argv);
}
static JSValue skeleton3d_class_advance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Skeleton3D::advance, ctx, this_val, argc, argv);
};
static JSValue skeleton3d_class_clear_bones_global_pose_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Skeleton3D::clear_bones_global_pose_override, ctx, this_val, argc, argv);
};
static JSValue skeleton3d_class_set_bone_global_pose_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Skeleton3D::set_bone_global_pose_override, ctx, this_val, argc, argv);
};
static JSValue skeleton3d_class_get_bone_global_pose_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Skeleton3D::get_bone_global_pose_override, ctx, this_val, argc, argv);
};
static JSValue skeleton3d_class_get_bone_global_pose_no_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Skeleton3D::get_bone_global_pose_no_override, ctx, this_val, argc, argv);
};
static JSValue skeleton3d_class_set_animate_physical_bones(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Skeleton3D::set_animate_physical_bones, ctx, this_val, argc, argv);
};
static JSValue skeleton3d_class_get_animate_physical_bones(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Skeleton3D::get_animate_physical_bones, ctx, this_val, argc, argv);
}
static JSValue skeleton3d_class_physical_bones_stop_simulation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Skeleton3D::physical_bones_stop_simulation, ctx, this_val, argc, argv);
};
static JSValue skeleton3d_class_physical_bones_start_simulation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Skeleton3D::physical_bones_start_simulation, ctx, this_val, argc, argv);
};
static JSValue skeleton3d_class_physical_bones_add_collision_exception(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Skeleton3D::physical_bones_add_collision_exception, ctx, this_val, argc, argv);
};
static JSValue skeleton3d_class_physical_bones_remove_collision_exception(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Skeleton3D::physical_bones_remove_collision_exception, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry skeleton3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("add_bone", 1, &skeleton3d_class_add_bone),
	JS_CFUNC_DEF("find_bone", 1, &skeleton3d_class_find_bone),
	JS_CFUNC_DEF("get_bone_name", 1, &skeleton3d_class_get_bone_name),
	JS_CFUNC_DEF("set_bone_name", 2, &skeleton3d_class_set_bone_name),
	JS_CFUNC_DEF("get_bone_meta", 2, &skeleton3d_class_get_bone_meta),
	JS_CFUNC_DEF("get_bone_meta_list", 1, &skeleton3d_class_get_bone_meta_list),
	JS_CFUNC_DEF("has_bone_meta", 2, &skeleton3d_class_has_bone_meta),
	JS_CFUNC_DEF("set_bone_meta", 3, &skeleton3d_class_set_bone_meta),
	JS_CFUNC_DEF("get_concatenated_bone_names", 0, &skeleton3d_class_get_concatenated_bone_names),
	JS_CFUNC_DEF("get_bone_parent", 1, &skeleton3d_class_get_bone_parent),
	JS_CFUNC_DEF("set_bone_parent", 2, &skeleton3d_class_set_bone_parent),
	JS_CFUNC_DEF("get_bone_count", 0, &skeleton3d_class_get_bone_count),
	JS_CFUNC_DEF("get_version", 0, &skeleton3d_class_get_version),
	JS_CFUNC_DEF("unparent_bone_and_rest", 1, &skeleton3d_class_unparent_bone_and_rest),
	JS_CFUNC_DEF("get_bone_children", 1, &skeleton3d_class_get_bone_children),
	JS_CFUNC_DEF("get_parentless_bones", 0, &skeleton3d_class_get_parentless_bones),
	JS_CFUNC_DEF("get_bone_rest", 1, &skeleton3d_class_get_bone_rest),
	JS_CFUNC_DEF("set_bone_rest", 2, &skeleton3d_class_set_bone_rest),
	JS_CFUNC_DEF("get_bone_global_rest", 1, &skeleton3d_class_get_bone_global_rest),
	JS_CFUNC_DEF("create_skin_from_rest_transforms", 0, &skeleton3d_class_create_skin_from_rest_transforms),
	JS_CFUNC_DEF("register_skin", 1, &skeleton3d_class_register_skin),
	JS_CFUNC_DEF("localize_rests", 0, &skeleton3d_class_localize_rests),
	JS_CFUNC_DEF("clear_bones", 0, &skeleton3d_class_clear_bones),
	JS_CFUNC_DEF("get_bone_pose", 1, &skeleton3d_class_get_bone_pose),
	JS_CFUNC_DEF("set_bone_pose", 2, &skeleton3d_class_set_bone_pose),
	JS_CFUNC_DEF("set_bone_pose_position", 2, &skeleton3d_class_set_bone_pose_position),
	JS_CFUNC_DEF("set_bone_pose_rotation", 2, &skeleton3d_class_set_bone_pose_rotation),
	JS_CFUNC_DEF("set_bone_pose_scale", 2, &skeleton3d_class_set_bone_pose_scale),
	JS_CFUNC_DEF("get_bone_pose_position", 1, &skeleton3d_class_get_bone_pose_position),
	JS_CFUNC_DEF("get_bone_pose_rotation", 1, &skeleton3d_class_get_bone_pose_rotation),
	JS_CFUNC_DEF("get_bone_pose_scale", 1, &skeleton3d_class_get_bone_pose_scale),
	JS_CFUNC_DEF("reset_bone_pose", 1, &skeleton3d_class_reset_bone_pose),
	JS_CFUNC_DEF("reset_bone_poses", 0, &skeleton3d_class_reset_bone_poses),
	JS_CFUNC_DEF("is_bone_enabled", 1, &skeleton3d_class_is_bone_enabled),
	JS_CFUNC_DEF("set_bone_enabled", 2, &skeleton3d_class_set_bone_enabled),
	JS_CFUNC_DEF("get_bone_global_pose", 1, &skeleton3d_class_get_bone_global_pose),
	JS_CFUNC_DEF("set_bone_global_pose", 2, &skeleton3d_class_set_bone_global_pose),
	JS_CFUNC_DEF("force_update_all_bone_transforms", 0, &skeleton3d_class_force_update_all_bone_transforms),
	JS_CFUNC_DEF("force_update_bone_child_transform", 1, &skeleton3d_class_force_update_bone_child_transform),
	JS_CFUNC_DEF("set_motion_scale", 1, &skeleton3d_class_set_motion_scale),
	JS_CFUNC_DEF("get_motion_scale", 0, &skeleton3d_class_get_motion_scale),
	JS_CFUNC_DEF("set_show_rest_only", 1, &skeleton3d_class_set_show_rest_only),
	JS_CFUNC_DEF("is_show_rest_only", 0, &skeleton3d_class_is_show_rest_only),
	JS_CFUNC_DEF("set_modifier_callback_mode_process", 1, &skeleton3d_class_set_modifier_callback_mode_process),
	JS_CFUNC_DEF("get_modifier_callback_mode_process", 0, &skeleton3d_class_get_modifier_callback_mode_process),
	JS_CFUNC_DEF("advance", 1, &skeleton3d_class_advance),
	JS_CFUNC_DEF("clear_bones_global_pose_override", 0, &skeleton3d_class_clear_bones_global_pose_override),
	JS_CFUNC_DEF("set_bone_global_pose_override", 4, &skeleton3d_class_set_bone_global_pose_override),
	JS_CFUNC_DEF("get_bone_global_pose_override", 1, &skeleton3d_class_get_bone_global_pose_override),
	JS_CFUNC_DEF("get_bone_global_pose_no_override", 1, &skeleton3d_class_get_bone_global_pose_no_override),
	JS_CFUNC_DEF("set_animate_physical_bones", 1, &skeleton3d_class_set_animate_physical_bones),
	JS_CFUNC_DEF("get_animate_physical_bones", 0, &skeleton3d_class_get_animate_physical_bones),
	JS_CFUNC_DEF("physical_bones_stop_simulation", 0, &skeleton3d_class_physical_bones_stop_simulation),
	JS_CFUNC_DEF("physical_bones_start_simulation", 1, &skeleton3d_class_physical_bones_start_simulation),
	JS_CFUNC_DEF("physical_bones_add_collision_exception", 1, &skeleton3d_class_physical_bones_add_collision_exception),
	JS_CFUNC_DEF("physical_bones_remove_collision_exception", 1, &skeleton3d_class_physical_bones_remove_collision_exception),
};


static JSValue skeleton3d_class_get_rest_updated_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	Skeleton3D *opaque = static_cast<Skeleton3D *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "rest_updated_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "rest_updated"));
		JS_DefinePropertyValueStr(ctx, this_val, "rest_updated_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue skeleton3d_class_get_pose_updated_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	Skeleton3D *opaque = static_cast<Skeleton3D *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "pose_updated_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "pose_updated"));
		JS_DefinePropertyValueStr(ctx, this_val, "pose_updated_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue skeleton3d_class_get_skeleton_updated_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	Skeleton3D *opaque = static_cast<Skeleton3D *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "skeleton_updated_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "skeleton_updated"));
		JS_DefinePropertyValueStr(ctx, this_val, "skeleton_updated_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue skeleton3d_class_get_bone_enabled_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	Skeleton3D *opaque = static_cast<Skeleton3D *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "bone_enabled_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "bone_enabled_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "bone_enabled_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue skeleton3d_class_get_bone_list_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	Skeleton3D *opaque = static_cast<Skeleton3D *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "bone_list_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "bone_list_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "bone_list_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue skeleton3d_class_get_show_rest_only_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	Skeleton3D *opaque = static_cast<Skeleton3D *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "show_rest_only_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "show_rest_only_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "show_rest_only_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_skeleton3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "motion_scale"),
        JS_NewCFunction(ctx, skeleton3d_class_get_motion_scale, "get_motion_scale", 0),
        JS_NewCFunction(ctx, skeleton3d_class_set_motion_scale, "set_motion_scale", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "show_rest_only"),
        JS_NewCFunction(ctx, skeleton3d_class_is_show_rest_only, "is_show_rest_only", 0),
        JS_NewCFunction(ctx, skeleton3d_class_set_show_rest_only, "set_show_rest_only", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "modifier_callback_mode_process"),
        JS_NewCFunction(ctx, skeleton3d_class_get_modifier_callback_mode_process, "get_modifier_callback_mode_process", 0),
        JS_NewCFunction(ctx, skeleton3d_class_set_modifier_callback_mode_process, "set_modifier_callback_mode_process", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "animate_physical_bones"),
        JS_NewCFunction(ctx, skeleton3d_class_get_animate_physical_bones, "get_animate_physical_bones", 0),
        JS_NewCFunction(ctx, skeleton3d_class_set_animate_physical_bones, "set_animate_physical_bones", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "rest_updated"),
		JS_NewCFunction(ctx, skeleton3d_class_get_rest_updated_signal, "get_rest_updated_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "pose_updated"),
		JS_NewCFunction(ctx, skeleton3d_class_get_pose_updated_signal, "get_pose_updated_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "skeleton_updated"),
		JS_NewCFunction(ctx, skeleton3d_class_get_skeleton_updated_signal, "get_skeleton_updated_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "bone_enabled_changed"),
		JS_NewCFunction(ctx, skeleton3d_class_get_bone_enabled_changed_signal, "get_bone_enabled_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "bone_list_changed"),
		JS_NewCFunction(ctx, skeleton3d_class_get_bone_list_changed_signal, "get_bone_list_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "show_rest_only_changed"),
		JS_NewCFunction(ctx, skeleton3d_class_get_show_rest_only_changed_signal, "get_show_rest_only_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_skeleton3d_enum(JSContext *ctx, JSValue ctor) {
	JSValue ModifierCallbackModeProcess_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, ModifierCallbackModeProcess_obj, "MODIFIER_CALLBACK_MODE_PROCESS_PHYSICS", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, ModifierCallbackModeProcess_obj, "MODIFIER_CALLBACK_MODE_PROCESS_IDLE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, ModifierCallbackModeProcess_obj, "MODIFIER_CALLBACK_MODE_PROCESS_MANUAL", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "ModifierCallbackModeProcess", ModifierCallbackModeProcess_obj);
}

static int js_skeleton3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["Skeleton3D"] = class_id;
	classes_by_id[class_id] = "Skeleton3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &skeleton3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_skeleton3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, skeleton3d_class_proto_funcs, _countof(skeleton3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, skeleton3d_class_constructor, "Skeleton3D", 0, JS_CFUNC_constructor, 0);
	define_skeleton3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "Skeleton3D", ctor);

	return 0;
}

JSModuleDef *_js_init_skeleton3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_skeleton3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Skeleton3D");
	return m;
}

JSModuleDef *js_init_skeleton3d_module(JSContext *ctx) {
	return _js_init_skeleton3d_module(ctx, "@godot/classes/skeleton3d");
}

void __register_skeleton3d() {
	js_init_skeleton3d_module(js_context());
}

void register_skeleton3d() {
	__register_skeleton3d();
}