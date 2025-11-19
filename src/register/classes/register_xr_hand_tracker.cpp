#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/xr_positional_tracker.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/xr_hand_tracker.hpp>
using namespace godot;

static void xr_hand_tracker_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["XRHandTracker"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
	}
}

static JSClassDef xr_hand_tracker_class_def = {
    "XRHandTracker",
    xr_hand_tracker_class_finalizer
};

static JSValue xr_hand_tracker_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["XRHandTracker"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    XRHandTracker *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<XRHandTracker *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(XRHandTracker);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue xr_hand_tracker_class_set_has_tracking_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&XRHandTracker::set_has_tracking_data, ctx, this_val, argc, argv);
};
static JSValue xr_hand_tracker_class_get_has_tracking_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XRHandTracker::get_has_tracking_data, ctx, this_val, argc, argv);
}
static JSValue xr_hand_tracker_class_set_hand_tracking_source(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&XRHandTracker::set_hand_tracking_source, ctx, this_val, argc, argv);
};
static JSValue xr_hand_tracker_class_get_hand_tracking_source(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XRHandTracker::get_hand_tracking_source, ctx, this_val, argc, argv);
}
static JSValue xr_hand_tracker_class_set_hand_joint_flags(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&XRHandTracker::set_hand_joint_flags, ctx, this_val, argc, argv);
};
static JSValue xr_hand_tracker_class_get_hand_joint_flags(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XRHandTracker::get_hand_joint_flags, ctx, this_val, argc, argv);
};
static JSValue xr_hand_tracker_class_set_hand_joint_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&XRHandTracker::set_hand_joint_transform, ctx, this_val, argc, argv);
};
static JSValue xr_hand_tracker_class_get_hand_joint_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XRHandTracker::get_hand_joint_transform, ctx, this_val, argc, argv);
};
static JSValue xr_hand_tracker_class_set_hand_joint_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&XRHandTracker::set_hand_joint_radius, ctx, this_val, argc, argv);
};
static JSValue xr_hand_tracker_class_get_hand_joint_radius(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XRHandTracker::get_hand_joint_radius, ctx, this_val, argc, argv);
};
static JSValue xr_hand_tracker_class_set_hand_joint_linear_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&XRHandTracker::set_hand_joint_linear_velocity, ctx, this_val, argc, argv);
};
static JSValue xr_hand_tracker_class_get_hand_joint_linear_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XRHandTracker::get_hand_joint_linear_velocity, ctx, this_val, argc, argv);
};
static JSValue xr_hand_tracker_class_set_hand_joint_angular_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&XRHandTracker::set_hand_joint_angular_velocity, ctx, this_val, argc, argv);
};
static JSValue xr_hand_tracker_class_get_hand_joint_angular_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XRHandTracker::get_hand_joint_angular_velocity, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry xr_hand_tracker_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_has_tracking_data", 1, &xr_hand_tracker_class_set_has_tracking_data),
	JS_CFUNC_DEF("get_has_tracking_data", 0, &xr_hand_tracker_class_get_has_tracking_data),
	JS_CFUNC_DEF("set_hand_tracking_source", 1, &xr_hand_tracker_class_set_hand_tracking_source),
	JS_CFUNC_DEF("get_hand_tracking_source", 0, &xr_hand_tracker_class_get_hand_tracking_source),
	JS_CFUNC_DEF("set_hand_joint_flags", 2, &xr_hand_tracker_class_set_hand_joint_flags),
	JS_CFUNC_DEF("get_hand_joint_flags", 1, &xr_hand_tracker_class_get_hand_joint_flags),
	JS_CFUNC_DEF("set_hand_joint_transform", 2, &xr_hand_tracker_class_set_hand_joint_transform),
	JS_CFUNC_DEF("get_hand_joint_transform", 1, &xr_hand_tracker_class_get_hand_joint_transform),
	JS_CFUNC_DEF("set_hand_joint_radius", 2, &xr_hand_tracker_class_set_hand_joint_radius),
	JS_CFUNC_DEF("get_hand_joint_radius", 1, &xr_hand_tracker_class_get_hand_joint_radius),
	JS_CFUNC_DEF("set_hand_joint_linear_velocity", 2, &xr_hand_tracker_class_set_hand_joint_linear_velocity),
	JS_CFUNC_DEF("get_hand_joint_linear_velocity", 1, &xr_hand_tracker_class_get_hand_joint_linear_velocity),
	JS_CFUNC_DEF("set_hand_joint_angular_velocity", 2, &xr_hand_tracker_class_set_hand_joint_angular_velocity),
	JS_CFUNC_DEF("get_hand_joint_angular_velocity", 1, &xr_hand_tracker_class_get_hand_joint_angular_velocity),
};




static void define_xr_hand_tracker_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "has_tracking_data"),
        JS_NewCFunction(ctx, xr_hand_tracker_class_get_has_tracking_data, "get_has_tracking_data", 0),
        JS_NewCFunction(ctx, xr_hand_tracker_class_set_has_tracking_data, "set_has_tracking_data", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "hand_tracking_source"),
        JS_NewCFunction(ctx, xr_hand_tracker_class_get_hand_tracking_source, "get_hand_tracking_source", 0),
        JS_NewCFunction(ctx, xr_hand_tracker_class_set_hand_tracking_source, "set_hand_tracking_source", 1),
        JS_PROP_GETSET
    );
}

static void define_xr_hand_tracker_enum(JSContext *ctx, JSValue ctor) {
	JSValue HandTrackingSource_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, HandTrackingSource_obj, "HAND_TRACKING_SOURCE_UNKNOWN", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, HandTrackingSource_obj, "HAND_TRACKING_SOURCE_UNOBSTRUCTED", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, HandTrackingSource_obj, "HAND_TRACKING_SOURCE_CONTROLLER", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, HandTrackingSource_obj, "HAND_TRACKING_SOURCE_NOT_TRACKED", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, HandTrackingSource_obj, "HAND_TRACKING_SOURCE_MAX", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, ctor, "HandTrackingSource", HandTrackingSource_obj);
	JSValue HandJoint_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, HandJoint_obj, "HAND_JOINT_PALM", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, HandJoint_obj, "HAND_JOINT_WRIST", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, HandJoint_obj, "HAND_JOINT_THUMB_METACARPAL", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, HandJoint_obj, "HAND_JOINT_THUMB_PHALANX_PROXIMAL", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, HandJoint_obj, "HAND_JOINT_THUMB_PHALANX_DISTAL", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, HandJoint_obj, "HAND_JOINT_THUMB_TIP", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, HandJoint_obj, "HAND_JOINT_INDEX_FINGER_METACARPAL", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, HandJoint_obj, "HAND_JOINT_INDEX_FINGER_PHALANX_PROXIMAL", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, HandJoint_obj, "HAND_JOINT_INDEX_FINGER_PHALANX_INTERMEDIATE", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, HandJoint_obj, "HAND_JOINT_INDEX_FINGER_PHALANX_DISTAL", JS_NewInt64(ctx, 9));
	JS_SetPropertyStr(ctx, HandJoint_obj, "HAND_JOINT_INDEX_FINGER_TIP", JS_NewInt64(ctx, 10));
	JS_SetPropertyStr(ctx, HandJoint_obj, "HAND_JOINT_MIDDLE_FINGER_METACARPAL", JS_NewInt64(ctx, 11));
	JS_SetPropertyStr(ctx, HandJoint_obj, "HAND_JOINT_MIDDLE_FINGER_PHALANX_PROXIMAL", JS_NewInt64(ctx, 12));
	JS_SetPropertyStr(ctx, HandJoint_obj, "HAND_JOINT_MIDDLE_FINGER_PHALANX_INTERMEDIATE", JS_NewInt64(ctx, 13));
	JS_SetPropertyStr(ctx, HandJoint_obj, "HAND_JOINT_MIDDLE_FINGER_PHALANX_DISTAL", JS_NewInt64(ctx, 14));
	JS_SetPropertyStr(ctx, HandJoint_obj, "HAND_JOINT_MIDDLE_FINGER_TIP", JS_NewInt64(ctx, 15));
	JS_SetPropertyStr(ctx, HandJoint_obj, "HAND_JOINT_RING_FINGER_METACARPAL", JS_NewInt64(ctx, 16));
	JS_SetPropertyStr(ctx, HandJoint_obj, "HAND_JOINT_RING_FINGER_PHALANX_PROXIMAL", JS_NewInt64(ctx, 17));
	JS_SetPropertyStr(ctx, HandJoint_obj, "HAND_JOINT_RING_FINGER_PHALANX_INTERMEDIATE", JS_NewInt64(ctx, 18));
	JS_SetPropertyStr(ctx, HandJoint_obj, "HAND_JOINT_RING_FINGER_PHALANX_DISTAL", JS_NewInt64(ctx, 19));
	JS_SetPropertyStr(ctx, HandJoint_obj, "HAND_JOINT_RING_FINGER_TIP", JS_NewInt64(ctx, 20));
	JS_SetPropertyStr(ctx, HandJoint_obj, "HAND_JOINT_PINKY_FINGER_METACARPAL", JS_NewInt64(ctx, 21));
	JS_SetPropertyStr(ctx, HandJoint_obj, "HAND_JOINT_PINKY_FINGER_PHALANX_PROXIMAL", JS_NewInt64(ctx, 22));
	JS_SetPropertyStr(ctx, HandJoint_obj, "HAND_JOINT_PINKY_FINGER_PHALANX_INTERMEDIATE", JS_NewInt64(ctx, 23));
	JS_SetPropertyStr(ctx, HandJoint_obj, "HAND_JOINT_PINKY_FINGER_PHALANX_DISTAL", JS_NewInt64(ctx, 24));
	JS_SetPropertyStr(ctx, HandJoint_obj, "HAND_JOINT_PINKY_FINGER_TIP", JS_NewInt64(ctx, 25));
	JS_SetPropertyStr(ctx, HandJoint_obj, "HAND_JOINT_MAX", JS_NewInt64(ctx, 26));
	JS_SetPropertyStr(ctx, ctor, "HandJoint", HandJoint_obj);
	JSValue HandJointFlags_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, HandJointFlags_obj, "HAND_JOINT_FLAG_ORIENTATION_VALID", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, HandJointFlags_obj, "HAND_JOINT_FLAG_ORIENTATION_TRACKED", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, HandJointFlags_obj, "HAND_JOINT_FLAG_POSITION_VALID", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, HandJointFlags_obj, "HAND_JOINT_FLAG_POSITION_TRACKED", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, HandJointFlags_obj, "HAND_JOINT_FLAG_LINEAR_VELOCITY_VALID", JS_NewInt64(ctx, 16));
	JS_SetPropertyStr(ctx, HandJointFlags_obj, "HAND_JOINT_FLAG_ANGULAR_VELOCITY_VALID", JS_NewInt64(ctx, 32));
	JS_SetPropertyStr(ctx, ctor, "HandJointFlags", HandJointFlags_obj);
}

static int js_xr_hand_tracker_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["XRHandTracker"] = class_id;
	classes_by_id[class_id] = "XRHandTracker";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &xr_hand_tracker_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["XRPositionalTracker"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_xr_hand_tracker_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, xr_hand_tracker_class_proto_funcs, _countof(xr_hand_tracker_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, xr_hand_tracker_class_constructor, "XRHandTracker", 0, JS_CFUNC_constructor, 0);
	define_xr_hand_tracker_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "XRHandTracker", ctor);

	return 0;
}

JSModuleDef *_js_init_xr_hand_tracker_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/xr_positional_tracker';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_xr_hand_tracker_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "XRHandTracker");
	return m;
}

JSModuleDef *js_init_xr_hand_tracker_module(JSContext *ctx) {
	return _js_init_xr_hand_tracker_module(ctx, "@godot/classes/xr_hand_tracker");
}

void __register_xr_hand_tracker() {
	js_init_xr_hand_tracker_module(js_context());
}

void register_xr_hand_tracker() {
	__register_xr_hand_tracker();
}