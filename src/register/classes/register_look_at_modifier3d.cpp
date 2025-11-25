#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/skeleton_modifier3d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/look_at_modifier3d.hpp>
using namespace godot;

static void look_at_modifier3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["LookAtModifier3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef look_at_modifier3d_class_def = {
    "LookAtModifier3D",
    look_at_modifier3d_class_finalizer
};

static JSValue look_at_modifier3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["LookAtModifier3D"];
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
        instance = memnew(LookAtModifier3D);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue look_at_modifier3d_class_set_target_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LookAtModifier3D::set_target_node, ctx, this_val, argc, argv);
};
static JSValue look_at_modifier3d_class_get_target_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LookAtModifier3D::get_target_node, ctx, this_val, argc, argv);
}
static JSValue look_at_modifier3d_class_set_bone_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LookAtModifier3D::set_bone_name, ctx, this_val, argc, argv);
};
static JSValue look_at_modifier3d_class_get_bone_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LookAtModifier3D::get_bone_name, ctx, this_val, argc, argv);
}
static JSValue look_at_modifier3d_class_set_bone(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LookAtModifier3D::set_bone, ctx, this_val, argc, argv);
};
static JSValue look_at_modifier3d_class_get_bone(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LookAtModifier3D::get_bone, ctx, this_val, argc, argv);
}
static JSValue look_at_modifier3d_class_set_forward_axis(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LookAtModifier3D::set_forward_axis, ctx, this_val, argc, argv);
};
static JSValue look_at_modifier3d_class_get_forward_axis(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LookAtModifier3D::get_forward_axis, ctx, this_val, argc, argv);
}
static JSValue look_at_modifier3d_class_set_primary_rotation_axis(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LookAtModifier3D::set_primary_rotation_axis, ctx, this_val, argc, argv);
};
static JSValue look_at_modifier3d_class_get_primary_rotation_axis(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LookAtModifier3D::get_primary_rotation_axis, ctx, this_val, argc, argv);
}
static JSValue look_at_modifier3d_class_set_use_secondary_rotation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LookAtModifier3D::set_use_secondary_rotation, ctx, this_val, argc, argv);
};
static JSValue look_at_modifier3d_class_is_using_secondary_rotation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LookAtModifier3D::is_using_secondary_rotation, ctx, this_val, argc, argv);
}
static JSValue look_at_modifier3d_class_set_origin_safe_margin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LookAtModifier3D::set_origin_safe_margin, ctx, this_val, argc, argv);
};
static JSValue look_at_modifier3d_class_get_origin_safe_margin(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LookAtModifier3D::get_origin_safe_margin, ctx, this_val, argc, argv);
}
static JSValue look_at_modifier3d_class_set_origin_from(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LookAtModifier3D::set_origin_from, ctx, this_val, argc, argv);
};
static JSValue look_at_modifier3d_class_get_origin_from(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LookAtModifier3D::get_origin_from, ctx, this_val, argc, argv);
}
static JSValue look_at_modifier3d_class_set_origin_bone_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LookAtModifier3D::set_origin_bone_name, ctx, this_val, argc, argv);
};
static JSValue look_at_modifier3d_class_get_origin_bone_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LookAtModifier3D::get_origin_bone_name, ctx, this_val, argc, argv);
}
static JSValue look_at_modifier3d_class_set_origin_bone(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LookAtModifier3D::set_origin_bone, ctx, this_val, argc, argv);
};
static JSValue look_at_modifier3d_class_get_origin_bone(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LookAtModifier3D::get_origin_bone, ctx, this_val, argc, argv);
}
static JSValue look_at_modifier3d_class_set_origin_external_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LookAtModifier3D::set_origin_external_node, ctx, this_val, argc, argv);
};
static JSValue look_at_modifier3d_class_get_origin_external_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LookAtModifier3D::get_origin_external_node, ctx, this_val, argc, argv);
}
static JSValue look_at_modifier3d_class_set_origin_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LookAtModifier3D::set_origin_offset, ctx, this_val, argc, argv);
};
static JSValue look_at_modifier3d_class_get_origin_offset(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector3> *proxy = memnew(ObjectProxy<Vector3>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector3 {
		LookAtModifier3D *obj = static_cast<LookAtModifier3D *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_origin_offset();
	};
	proxy->setter = [this_val](const Vector3 &value) -> void {
		LookAtModifier3D *js_proxy = static_cast<LookAtModifier3D *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_origin_offset(value);
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
static JSValue look_at_modifier3d_class_set_duration(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LookAtModifier3D::set_duration, ctx, this_val, argc, argv);
};
static JSValue look_at_modifier3d_class_get_duration(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LookAtModifier3D::get_duration, ctx, this_val, argc, argv);
}
static JSValue look_at_modifier3d_class_set_transition_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LookAtModifier3D::set_transition_type, ctx, this_val, argc, argv);
};
static JSValue look_at_modifier3d_class_get_transition_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LookAtModifier3D::get_transition_type, ctx, this_val, argc, argv);
}
static JSValue look_at_modifier3d_class_set_ease_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LookAtModifier3D::set_ease_type, ctx, this_val, argc, argv);
};
static JSValue look_at_modifier3d_class_get_ease_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LookAtModifier3D::get_ease_type, ctx, this_val, argc, argv);
}
static JSValue look_at_modifier3d_class_set_use_angle_limitation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LookAtModifier3D::set_use_angle_limitation, ctx, this_val, argc, argv);
};
static JSValue look_at_modifier3d_class_is_using_angle_limitation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LookAtModifier3D::is_using_angle_limitation, ctx, this_val, argc, argv);
}
static JSValue look_at_modifier3d_class_set_symmetry_limitation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LookAtModifier3D::set_symmetry_limitation, ctx, this_val, argc, argv);
};
static JSValue look_at_modifier3d_class_is_limitation_symmetry(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LookAtModifier3D::is_limitation_symmetry, ctx, this_val, argc, argv);
}
static JSValue look_at_modifier3d_class_set_primary_limit_angle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LookAtModifier3D::set_primary_limit_angle, ctx, this_val, argc, argv);
};
static JSValue look_at_modifier3d_class_get_primary_limit_angle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LookAtModifier3D::get_primary_limit_angle, ctx, this_val, argc, argv);
}
static JSValue look_at_modifier3d_class_set_primary_damp_threshold(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LookAtModifier3D::set_primary_damp_threshold, ctx, this_val, argc, argv);
};
static JSValue look_at_modifier3d_class_get_primary_damp_threshold(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LookAtModifier3D::get_primary_damp_threshold, ctx, this_val, argc, argv);
}
static JSValue look_at_modifier3d_class_set_primary_positive_limit_angle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LookAtModifier3D::set_primary_positive_limit_angle, ctx, this_val, argc, argv);
};
static JSValue look_at_modifier3d_class_get_primary_positive_limit_angle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LookAtModifier3D::get_primary_positive_limit_angle, ctx, this_val, argc, argv);
}
static JSValue look_at_modifier3d_class_set_primary_positive_damp_threshold(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LookAtModifier3D::set_primary_positive_damp_threshold, ctx, this_val, argc, argv);
};
static JSValue look_at_modifier3d_class_get_primary_positive_damp_threshold(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LookAtModifier3D::get_primary_positive_damp_threshold, ctx, this_val, argc, argv);
}
static JSValue look_at_modifier3d_class_set_primary_negative_limit_angle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LookAtModifier3D::set_primary_negative_limit_angle, ctx, this_val, argc, argv);
};
static JSValue look_at_modifier3d_class_get_primary_negative_limit_angle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LookAtModifier3D::get_primary_negative_limit_angle, ctx, this_val, argc, argv);
}
static JSValue look_at_modifier3d_class_set_primary_negative_damp_threshold(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LookAtModifier3D::set_primary_negative_damp_threshold, ctx, this_val, argc, argv);
};
static JSValue look_at_modifier3d_class_get_primary_negative_damp_threshold(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LookAtModifier3D::get_primary_negative_damp_threshold, ctx, this_val, argc, argv);
}
static JSValue look_at_modifier3d_class_set_secondary_limit_angle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LookAtModifier3D::set_secondary_limit_angle, ctx, this_val, argc, argv);
};
static JSValue look_at_modifier3d_class_get_secondary_limit_angle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LookAtModifier3D::get_secondary_limit_angle, ctx, this_val, argc, argv);
}
static JSValue look_at_modifier3d_class_set_secondary_damp_threshold(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LookAtModifier3D::set_secondary_damp_threshold, ctx, this_val, argc, argv);
};
static JSValue look_at_modifier3d_class_get_secondary_damp_threshold(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LookAtModifier3D::get_secondary_damp_threshold, ctx, this_val, argc, argv);
}
static JSValue look_at_modifier3d_class_set_secondary_positive_limit_angle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LookAtModifier3D::set_secondary_positive_limit_angle, ctx, this_val, argc, argv);
};
static JSValue look_at_modifier3d_class_get_secondary_positive_limit_angle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LookAtModifier3D::get_secondary_positive_limit_angle, ctx, this_val, argc, argv);
}
static JSValue look_at_modifier3d_class_set_secondary_positive_damp_threshold(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LookAtModifier3D::set_secondary_positive_damp_threshold, ctx, this_val, argc, argv);
};
static JSValue look_at_modifier3d_class_get_secondary_positive_damp_threshold(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LookAtModifier3D::get_secondary_positive_damp_threshold, ctx, this_val, argc, argv);
}
static JSValue look_at_modifier3d_class_set_secondary_negative_limit_angle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LookAtModifier3D::set_secondary_negative_limit_angle, ctx, this_val, argc, argv);
};
static JSValue look_at_modifier3d_class_get_secondary_negative_limit_angle(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LookAtModifier3D::get_secondary_negative_limit_angle, ctx, this_val, argc, argv);
}
static JSValue look_at_modifier3d_class_set_secondary_negative_damp_threshold(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&LookAtModifier3D::set_secondary_negative_damp_threshold, ctx, this_val, argc, argv);
};
static JSValue look_at_modifier3d_class_get_secondary_negative_damp_threshold(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LookAtModifier3D::get_secondary_negative_damp_threshold, ctx, this_val, argc, argv);
}
static JSValue look_at_modifier3d_class_get_interpolation_remaining(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LookAtModifier3D::get_interpolation_remaining, ctx, this_val, argc, argv);
};
static JSValue look_at_modifier3d_class_is_interpolating(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LookAtModifier3D::is_interpolating, ctx, this_val, argc, argv);
};
static JSValue look_at_modifier3d_class_is_target_within_limitation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&LookAtModifier3D::is_target_within_limitation, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry look_at_modifier3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_target_node", 1, &look_at_modifier3d_class_set_target_node),
	JS_CFUNC_DEF("get_target_node", 0, &look_at_modifier3d_class_get_target_node),
	JS_CFUNC_DEF("set_bone_name", 1, &look_at_modifier3d_class_set_bone_name),
	JS_CFUNC_DEF("get_bone_name", 0, &look_at_modifier3d_class_get_bone_name),
	JS_CFUNC_DEF("set_bone", 1, &look_at_modifier3d_class_set_bone),
	JS_CFUNC_DEF("get_bone", 0, &look_at_modifier3d_class_get_bone),
	JS_CFUNC_DEF("set_forward_axis", 1, &look_at_modifier3d_class_set_forward_axis),
	JS_CFUNC_DEF("get_forward_axis", 0, &look_at_modifier3d_class_get_forward_axis),
	JS_CFUNC_DEF("set_primary_rotation_axis", 1, &look_at_modifier3d_class_set_primary_rotation_axis),
	JS_CFUNC_DEF("get_primary_rotation_axis", 0, &look_at_modifier3d_class_get_primary_rotation_axis),
	JS_CFUNC_DEF("set_use_secondary_rotation", 1, &look_at_modifier3d_class_set_use_secondary_rotation),
	JS_CFUNC_DEF("is_using_secondary_rotation", 0, &look_at_modifier3d_class_is_using_secondary_rotation),
	JS_CFUNC_DEF("set_origin_safe_margin", 1, &look_at_modifier3d_class_set_origin_safe_margin),
	JS_CFUNC_DEF("get_origin_safe_margin", 0, &look_at_modifier3d_class_get_origin_safe_margin),
	JS_CFUNC_DEF("set_origin_from", 1, &look_at_modifier3d_class_set_origin_from),
	JS_CFUNC_DEF("get_origin_from", 0, &look_at_modifier3d_class_get_origin_from),
	JS_CFUNC_DEF("set_origin_bone_name", 1, &look_at_modifier3d_class_set_origin_bone_name),
	JS_CFUNC_DEF("get_origin_bone_name", 0, &look_at_modifier3d_class_get_origin_bone_name),
	JS_CFUNC_DEF("set_origin_bone", 1, &look_at_modifier3d_class_set_origin_bone),
	JS_CFUNC_DEF("get_origin_bone", 0, &look_at_modifier3d_class_get_origin_bone),
	JS_CFUNC_DEF("set_origin_external_node", 1, &look_at_modifier3d_class_set_origin_external_node),
	JS_CFUNC_DEF("get_origin_external_node", 0, &look_at_modifier3d_class_get_origin_external_node),
	JS_CFUNC_DEF("set_origin_offset", 1, &look_at_modifier3d_class_set_origin_offset),
	JS_CFUNC_DEF("get_origin_offset", 0, &look_at_modifier3d_class_get_origin_offset),
	JS_CFUNC_DEF("set_duration", 1, &look_at_modifier3d_class_set_duration),
	JS_CFUNC_DEF("get_duration", 0, &look_at_modifier3d_class_get_duration),
	JS_CFUNC_DEF("set_transition_type", 1, &look_at_modifier3d_class_set_transition_type),
	JS_CFUNC_DEF("get_transition_type", 0, &look_at_modifier3d_class_get_transition_type),
	JS_CFUNC_DEF("set_ease_type", 1, &look_at_modifier3d_class_set_ease_type),
	JS_CFUNC_DEF("get_ease_type", 0, &look_at_modifier3d_class_get_ease_type),
	JS_CFUNC_DEF("set_use_angle_limitation", 1, &look_at_modifier3d_class_set_use_angle_limitation),
	JS_CFUNC_DEF("is_using_angle_limitation", 0, &look_at_modifier3d_class_is_using_angle_limitation),
	JS_CFUNC_DEF("set_symmetry_limitation", 1, &look_at_modifier3d_class_set_symmetry_limitation),
	JS_CFUNC_DEF("is_limitation_symmetry", 0, &look_at_modifier3d_class_is_limitation_symmetry),
	JS_CFUNC_DEF("set_primary_limit_angle", 1, &look_at_modifier3d_class_set_primary_limit_angle),
	JS_CFUNC_DEF("get_primary_limit_angle", 0, &look_at_modifier3d_class_get_primary_limit_angle),
	JS_CFUNC_DEF("set_primary_damp_threshold", 1, &look_at_modifier3d_class_set_primary_damp_threshold),
	JS_CFUNC_DEF("get_primary_damp_threshold", 0, &look_at_modifier3d_class_get_primary_damp_threshold),
	JS_CFUNC_DEF("set_primary_positive_limit_angle", 1, &look_at_modifier3d_class_set_primary_positive_limit_angle),
	JS_CFUNC_DEF("get_primary_positive_limit_angle", 0, &look_at_modifier3d_class_get_primary_positive_limit_angle),
	JS_CFUNC_DEF("set_primary_positive_damp_threshold", 1, &look_at_modifier3d_class_set_primary_positive_damp_threshold),
	JS_CFUNC_DEF("get_primary_positive_damp_threshold", 0, &look_at_modifier3d_class_get_primary_positive_damp_threshold),
	JS_CFUNC_DEF("set_primary_negative_limit_angle", 1, &look_at_modifier3d_class_set_primary_negative_limit_angle),
	JS_CFUNC_DEF("get_primary_negative_limit_angle", 0, &look_at_modifier3d_class_get_primary_negative_limit_angle),
	JS_CFUNC_DEF("set_primary_negative_damp_threshold", 1, &look_at_modifier3d_class_set_primary_negative_damp_threshold),
	JS_CFUNC_DEF("get_primary_negative_damp_threshold", 0, &look_at_modifier3d_class_get_primary_negative_damp_threshold),
	JS_CFUNC_DEF("set_secondary_limit_angle", 1, &look_at_modifier3d_class_set_secondary_limit_angle),
	JS_CFUNC_DEF("get_secondary_limit_angle", 0, &look_at_modifier3d_class_get_secondary_limit_angle),
	JS_CFUNC_DEF("set_secondary_damp_threshold", 1, &look_at_modifier3d_class_set_secondary_damp_threshold),
	JS_CFUNC_DEF("get_secondary_damp_threshold", 0, &look_at_modifier3d_class_get_secondary_damp_threshold),
	JS_CFUNC_DEF("set_secondary_positive_limit_angle", 1, &look_at_modifier3d_class_set_secondary_positive_limit_angle),
	JS_CFUNC_DEF("get_secondary_positive_limit_angle", 0, &look_at_modifier3d_class_get_secondary_positive_limit_angle),
	JS_CFUNC_DEF("set_secondary_positive_damp_threshold", 1, &look_at_modifier3d_class_set_secondary_positive_damp_threshold),
	JS_CFUNC_DEF("get_secondary_positive_damp_threshold", 0, &look_at_modifier3d_class_get_secondary_positive_damp_threshold),
	JS_CFUNC_DEF("set_secondary_negative_limit_angle", 1, &look_at_modifier3d_class_set_secondary_negative_limit_angle),
	JS_CFUNC_DEF("get_secondary_negative_limit_angle", 0, &look_at_modifier3d_class_get_secondary_negative_limit_angle),
	JS_CFUNC_DEF("set_secondary_negative_damp_threshold", 1, &look_at_modifier3d_class_set_secondary_negative_damp_threshold),
	JS_CFUNC_DEF("get_secondary_negative_damp_threshold", 0, &look_at_modifier3d_class_get_secondary_negative_damp_threshold),
	JS_CFUNC_DEF("get_interpolation_remaining", 0, &look_at_modifier3d_class_get_interpolation_remaining),
	JS_CFUNC_DEF("is_interpolating", 0, &look_at_modifier3d_class_is_interpolating),
	JS_CFUNC_DEF("is_target_within_limitation", 0, &look_at_modifier3d_class_is_target_within_limitation),
};




static void define_look_at_modifier3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "target_node"),
        JS_NewCFunction(ctx, look_at_modifier3d_class_get_target_node, "get_target_node", 0),
        JS_NewCFunction(ctx, look_at_modifier3d_class_set_target_node, "set_target_node", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "bone_name"),
        JS_NewCFunction(ctx, look_at_modifier3d_class_get_bone_name, "get_bone_name", 0),
        JS_NewCFunction(ctx, look_at_modifier3d_class_set_bone_name, "set_bone_name", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "bone"),
        JS_NewCFunction(ctx, look_at_modifier3d_class_get_bone, "get_bone", 0),
        JS_NewCFunction(ctx, look_at_modifier3d_class_set_bone, "set_bone", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "forward_axis"),
        JS_NewCFunction(ctx, look_at_modifier3d_class_get_forward_axis, "get_forward_axis", 0),
        JS_NewCFunction(ctx, look_at_modifier3d_class_set_forward_axis, "set_forward_axis", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "primary_rotation_axis"),
        JS_NewCFunction(ctx, look_at_modifier3d_class_get_primary_rotation_axis, "get_primary_rotation_axis", 0),
        JS_NewCFunction(ctx, look_at_modifier3d_class_set_primary_rotation_axis, "set_primary_rotation_axis", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "use_secondary_rotation"),
        JS_NewCFunction(ctx, look_at_modifier3d_class_is_using_secondary_rotation, "is_using_secondary_rotation", 0),
        JS_NewCFunction(ctx, look_at_modifier3d_class_set_use_secondary_rotation, "set_use_secondary_rotation", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "origin_from"),
        JS_NewCFunction(ctx, look_at_modifier3d_class_get_origin_from, "get_origin_from", 0),
        JS_NewCFunction(ctx, look_at_modifier3d_class_set_origin_from, "set_origin_from", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "origin_bone_name"),
        JS_NewCFunction(ctx, look_at_modifier3d_class_get_origin_bone_name, "get_origin_bone_name", 0),
        JS_NewCFunction(ctx, look_at_modifier3d_class_set_origin_bone_name, "set_origin_bone_name", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "origin_bone"),
        JS_NewCFunction(ctx, look_at_modifier3d_class_get_origin_bone, "get_origin_bone", 0),
        JS_NewCFunction(ctx, look_at_modifier3d_class_set_origin_bone, "set_origin_bone", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "origin_external_node"),
        JS_NewCFunction(ctx, look_at_modifier3d_class_get_origin_external_node, "get_origin_external_node", 0),
        JS_NewCFunction(ctx, look_at_modifier3d_class_set_origin_external_node, "set_origin_external_node", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "origin_offset"),
        JS_NewCFunction(ctx, look_at_modifier3d_class_get_origin_offset, "get_origin_offset", 0),
        JS_NewCFunction(ctx, look_at_modifier3d_class_set_origin_offset, "set_origin_offset", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "origin_safe_margin"),
        JS_NewCFunction(ctx, look_at_modifier3d_class_get_origin_safe_margin, "get_origin_safe_margin", 0),
        JS_NewCFunction(ctx, look_at_modifier3d_class_set_origin_safe_margin, "set_origin_safe_margin", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "duration"),
        JS_NewCFunction(ctx, look_at_modifier3d_class_get_duration, "get_duration", 0),
        JS_NewCFunction(ctx, look_at_modifier3d_class_set_duration, "set_duration", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "transition_type"),
        JS_NewCFunction(ctx, look_at_modifier3d_class_get_transition_type, "get_transition_type", 0),
        JS_NewCFunction(ctx, look_at_modifier3d_class_set_transition_type, "set_transition_type", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "ease_type"),
        JS_NewCFunction(ctx, look_at_modifier3d_class_get_ease_type, "get_ease_type", 0),
        JS_NewCFunction(ctx, look_at_modifier3d_class_set_ease_type, "set_ease_type", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "use_angle_limitation"),
        JS_NewCFunction(ctx, look_at_modifier3d_class_is_using_angle_limitation, "is_using_angle_limitation", 0),
        JS_NewCFunction(ctx, look_at_modifier3d_class_set_use_angle_limitation, "set_use_angle_limitation", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "symmetry_limitation"),
        JS_NewCFunction(ctx, look_at_modifier3d_class_is_limitation_symmetry, "is_limitation_symmetry", 0),
        JS_NewCFunction(ctx, look_at_modifier3d_class_set_symmetry_limitation, "set_symmetry_limitation", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "primary_limit_angle"),
        JS_NewCFunction(ctx, look_at_modifier3d_class_get_primary_limit_angle, "get_primary_limit_angle", 0),
        JS_NewCFunction(ctx, look_at_modifier3d_class_set_primary_limit_angle, "set_primary_limit_angle", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "primary_damp_threshold"),
        JS_NewCFunction(ctx, look_at_modifier3d_class_get_primary_damp_threshold, "get_primary_damp_threshold", 0),
        JS_NewCFunction(ctx, look_at_modifier3d_class_set_primary_damp_threshold, "set_primary_damp_threshold", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "primary_positive_limit_angle"),
        JS_NewCFunction(ctx, look_at_modifier3d_class_get_primary_positive_limit_angle, "get_primary_positive_limit_angle", 0),
        JS_NewCFunction(ctx, look_at_modifier3d_class_set_primary_positive_limit_angle, "set_primary_positive_limit_angle", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "primary_positive_damp_threshold"),
        JS_NewCFunction(ctx, look_at_modifier3d_class_get_primary_positive_damp_threshold, "get_primary_positive_damp_threshold", 0),
        JS_NewCFunction(ctx, look_at_modifier3d_class_set_primary_positive_damp_threshold, "set_primary_positive_damp_threshold", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "primary_negative_limit_angle"),
        JS_NewCFunction(ctx, look_at_modifier3d_class_get_primary_negative_limit_angle, "get_primary_negative_limit_angle", 0),
        JS_NewCFunction(ctx, look_at_modifier3d_class_set_primary_negative_limit_angle, "set_primary_negative_limit_angle", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "primary_negative_damp_threshold"),
        JS_NewCFunction(ctx, look_at_modifier3d_class_get_primary_negative_damp_threshold, "get_primary_negative_damp_threshold", 0),
        JS_NewCFunction(ctx, look_at_modifier3d_class_set_primary_negative_damp_threshold, "set_primary_negative_damp_threshold", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "secondary_limit_angle"),
        JS_NewCFunction(ctx, look_at_modifier3d_class_get_secondary_limit_angle, "get_secondary_limit_angle", 0),
        JS_NewCFunction(ctx, look_at_modifier3d_class_set_secondary_limit_angle, "set_secondary_limit_angle", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "secondary_damp_threshold"),
        JS_NewCFunction(ctx, look_at_modifier3d_class_get_secondary_damp_threshold, "get_secondary_damp_threshold", 0),
        JS_NewCFunction(ctx, look_at_modifier3d_class_set_secondary_damp_threshold, "set_secondary_damp_threshold", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "secondary_positive_limit_angle"),
        JS_NewCFunction(ctx, look_at_modifier3d_class_get_secondary_positive_limit_angle, "get_secondary_positive_limit_angle", 0),
        JS_NewCFunction(ctx, look_at_modifier3d_class_set_secondary_positive_limit_angle, "set_secondary_positive_limit_angle", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "secondary_positive_damp_threshold"),
        JS_NewCFunction(ctx, look_at_modifier3d_class_get_secondary_positive_damp_threshold, "get_secondary_positive_damp_threshold", 0),
        JS_NewCFunction(ctx, look_at_modifier3d_class_set_secondary_positive_damp_threshold, "set_secondary_positive_damp_threshold", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "secondary_negative_limit_angle"),
        JS_NewCFunction(ctx, look_at_modifier3d_class_get_secondary_negative_limit_angle, "get_secondary_negative_limit_angle", 0),
        JS_NewCFunction(ctx, look_at_modifier3d_class_set_secondary_negative_limit_angle, "set_secondary_negative_limit_angle", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "secondary_negative_damp_threshold"),
        JS_NewCFunction(ctx, look_at_modifier3d_class_get_secondary_negative_damp_threshold, "get_secondary_negative_damp_threshold", 0),
        JS_NewCFunction(ctx, look_at_modifier3d_class_set_secondary_negative_damp_threshold, "set_secondary_negative_damp_threshold", 1),
        JS_PROP_GETSET
    );
}

static void define_look_at_modifier3d_enum(JSContext *ctx, JSValue ctor) {
	JSValue OriginFrom_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, OriginFrom_obj, "ORIGIN_FROM_SELF", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, OriginFrom_obj, "ORIGIN_FROM_SPECIFIC_BONE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, OriginFrom_obj, "ORIGIN_FROM_EXTERNAL_NODE", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "OriginFrom", OriginFrom_obj);
}

static int js_look_at_modifier3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["LookAtModifier3D"] = class_id;
	classes_by_id[class_id] = "LookAtModifier3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &look_at_modifier3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["SkeletonModifier3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_look_at_modifier3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, look_at_modifier3d_class_proto_funcs, _countof(look_at_modifier3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, look_at_modifier3d_class_constructor, "LookAtModifier3D", 0, JS_CFUNC_constructor, 0);
	define_look_at_modifier3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "LookAtModifier3D", ctor);
	ctor_list["LookAtModifier3D"] = ctor;

	return 0;
}

JSModuleDef *_js_init_look_at_modifier3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/skeleton_modifier3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_look_at_modifier3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "LookAtModifier3D");
	return m;
}

JSModuleDef *js_init_look_at_modifier3d_module(JSContext *ctx) {
	return _js_init_look_at_modifier3d_module(ctx, "@godot/classes/look_at_modifier3d");
}

void __register_look_at_modifier3d() {
	js_init_look_at_modifier3d_module(js_context());
}

void register_look_at_modifier3d() {
	__register_look_at_modifier3d();
}