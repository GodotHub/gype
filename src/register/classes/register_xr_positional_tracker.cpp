#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/xr_pose.hpp>
#include <godot_cpp/classes/xr_tracker.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/xr_positional_tracker.hpp>
using namespace godot;

static void xr_positional_tracker_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["XRPositionalTracker"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef xr_positional_tracker_class_def = {
    "XRPositionalTracker",
    xr_positional_tracker_class_finalizer
};

static JSValue xr_positional_tracker_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["XRPositionalTracker"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    XRPositionalTracker *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<XRPositionalTracker *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(XRPositionalTracker);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue xr_positional_tracker_class_get_tracker_profile(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XRPositionalTracker::get_tracker_profile, ctx, this_val, argc, argv);
}
static JSValue xr_positional_tracker_class_set_tracker_profile(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&XRPositionalTracker::set_tracker_profile, ctx, this_val, argc, argv);
};
static JSValue xr_positional_tracker_class_get_tracker_hand(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XRPositionalTracker::get_tracker_hand, ctx, this_val, argc, argv);
}
static JSValue xr_positional_tracker_class_set_tracker_hand(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&XRPositionalTracker::set_tracker_hand, ctx, this_val, argc, argv);
};
static JSValue xr_positional_tracker_class_has_pose(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XRPositionalTracker::has_pose, ctx, this_val, argc, argv);
};
static JSValue xr_positional_tracker_class_get_pose(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XRPositionalTracker::get_pose, ctx, this_val, argc, argv);
};
static JSValue xr_positional_tracker_class_invalidate_pose(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&XRPositionalTracker::invalidate_pose, ctx, this_val, argc, argv);
};
static JSValue xr_positional_tracker_class_set_pose(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&XRPositionalTracker::set_pose, ctx, this_val, argc, argv);
};
static JSValue xr_positional_tracker_class_get_input(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XRPositionalTracker::get_input, ctx, this_val, argc, argv);
};
static JSValue xr_positional_tracker_class_set_input(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&XRPositionalTracker::set_input, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry xr_positional_tracker_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_tracker_profile", 0, &xr_positional_tracker_class_get_tracker_profile),
	JS_CFUNC_DEF("set_tracker_profile", 1, &xr_positional_tracker_class_set_tracker_profile),
	JS_CFUNC_DEF("get_tracker_hand", 0, &xr_positional_tracker_class_get_tracker_hand),
	JS_CFUNC_DEF("set_tracker_hand", 1, &xr_positional_tracker_class_set_tracker_hand),
	JS_CFUNC_DEF("has_pose", 1, &xr_positional_tracker_class_has_pose),
	JS_CFUNC_DEF("get_pose", 1, &xr_positional_tracker_class_get_pose),
	JS_CFUNC_DEF("invalidate_pose", 1, &xr_positional_tracker_class_invalidate_pose),
	JS_CFUNC_DEF("set_pose", 5, &xr_positional_tracker_class_set_pose),
	JS_CFUNC_DEF("get_input", 1, &xr_positional_tracker_class_get_input),
	JS_CFUNC_DEF("set_input", 2, &xr_positional_tracker_class_set_input),
};


static JSValue xr_positional_tracker_class_get_pose_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	XRPositionalTracker *opaque = static_cast<XRPositionalTracker *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "pose_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "pose_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "pose_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue xr_positional_tracker_class_get_pose_lost_tracking_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	XRPositionalTracker *opaque = static_cast<XRPositionalTracker *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "pose_lost_tracking_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "pose_lost_tracking"));
		JS_DefinePropertyValueStr(ctx, this_val, "pose_lost_tracking_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue xr_positional_tracker_class_get_button_pressed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	XRPositionalTracker *opaque = static_cast<XRPositionalTracker *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "button_pressed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "button_pressed"));
		JS_DefinePropertyValueStr(ctx, this_val, "button_pressed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue xr_positional_tracker_class_get_button_released_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	XRPositionalTracker *opaque = static_cast<XRPositionalTracker *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "button_released_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "button_released"));
		JS_DefinePropertyValueStr(ctx, this_val, "button_released_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue xr_positional_tracker_class_get_input_float_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	XRPositionalTracker *opaque = static_cast<XRPositionalTracker *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "input_float_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "input_float_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "input_float_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue xr_positional_tracker_class_get_input_vector2_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	XRPositionalTracker *opaque = static_cast<XRPositionalTracker *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "input_vector2_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "input_vector2_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "input_vector2_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue xr_positional_tracker_class_get_profile_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	XRPositionalTracker *opaque = static_cast<XRPositionalTracker *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "profile_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "profile_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "profile_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_xr_positional_tracker_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "profile"),
        JS_NewCFunction(ctx, xr_positional_tracker_class_get_tracker_profile, "get_tracker_profile", 0),
        JS_NewCFunction(ctx, xr_positional_tracker_class_set_tracker_profile, "set_tracker_profile", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "hand"),
        JS_NewCFunction(ctx, xr_positional_tracker_class_get_tracker_hand, "get_tracker_hand", 0),
        JS_NewCFunction(ctx, xr_positional_tracker_class_set_tracker_hand, "set_tracker_hand", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "pose_changed"),
		JS_NewCFunction(ctx, xr_positional_tracker_class_get_pose_changed_signal, "get_pose_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "pose_lost_tracking"),
		JS_NewCFunction(ctx, xr_positional_tracker_class_get_pose_lost_tracking_signal, "get_pose_lost_tracking_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "button_pressed"),
		JS_NewCFunction(ctx, xr_positional_tracker_class_get_button_pressed_signal, "get_button_pressed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "button_released"),
		JS_NewCFunction(ctx, xr_positional_tracker_class_get_button_released_signal, "get_button_released_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "input_float_changed"),
		JS_NewCFunction(ctx, xr_positional_tracker_class_get_input_float_changed_signal, "get_input_float_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "input_vector2_changed"),
		JS_NewCFunction(ctx, xr_positional_tracker_class_get_input_vector2_changed_signal, "get_input_vector2_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "profile_changed"),
		JS_NewCFunction(ctx, xr_positional_tracker_class_get_profile_changed_signal, "get_profile_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_xr_positional_tracker_enum(JSContext *ctx, JSValue ctor) {
	JSValue TrackerHand_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, TrackerHand_obj, "TRACKER_HAND_UNKNOWN", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, TrackerHand_obj, "TRACKER_HAND_LEFT", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, TrackerHand_obj, "TRACKER_HAND_RIGHT", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, TrackerHand_obj, "TRACKER_HAND_MAX", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ctor, "TrackerHand", TrackerHand_obj);
}

static int js_xr_positional_tracker_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["XRPositionalTracker"] = class_id;
	classes_by_id[class_id] = "XRPositionalTracker";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &xr_positional_tracker_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["XRTracker"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_xr_positional_tracker_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, xr_positional_tracker_class_proto_funcs, _countof(xr_positional_tracker_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, xr_positional_tracker_class_constructor, "XRPositionalTracker", 0, JS_CFUNC_constructor, 0);
	define_xr_positional_tracker_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "XRPositionalTracker", ctor);

	return 0;
}

JSModuleDef *_js_init_xr_positional_tracker_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/xr_tracker';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_xr_positional_tracker_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "XRPositionalTracker");
	return m;
}

JSModuleDef *js_init_xr_positional_tracker_module(JSContext *ctx) {
	return _js_init_xr_positional_tracker_module(ctx, "@godot/classes/xr_positional_tracker");
}

void __register_xr_positional_tracker() {
	js_init_xr_positional_tracker_module(js_context());
}

void register_xr_positional_tracker() {
	__register_xr_positional_tracker();
}