#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/xr_interface.hpp>
using namespace godot;

static void xr_interface_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["XRInterface"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef xr_interface_class_def = {
    "XRInterface",
    xr_interface_class_finalizer
};

static JSValue xr_interface_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["XRInterface"];
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
        instance = memnew(XRInterface);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue xr_interface_class_get_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XRInterface::get_name, ctx, this_val, argc, argv);
};
static JSValue xr_interface_class_get_capabilities(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XRInterface::get_capabilities, ctx, this_val, argc, argv);
};
static JSValue xr_interface_class_is_primary(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&XRInterface::is_primary, ctx, this_val, argc, argv);
}
static JSValue xr_interface_class_set_primary(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&XRInterface::set_primary, ctx, this_val, argc, argv);
};
static JSValue xr_interface_class_is_initialized(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XRInterface::is_initialized, ctx, this_val, argc, argv);
};
static JSValue xr_interface_class_initialize(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&XRInterface::initialize, ctx, this_val, argc, argv);
};
static JSValue xr_interface_class_uninitialize(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&XRInterface::uninitialize, ctx, this_val, argc, argv);
};
static JSValue xr_interface_class_get_system_info(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&XRInterface::get_system_info, ctx, this_val, argc, argv);
};
static JSValue xr_interface_class_get_tracking_status(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XRInterface::get_tracking_status, ctx, this_val, argc, argv);
};
static JSValue xr_interface_class_get_render_target_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&XRInterface::get_render_target_size, ctx, this_val, argc, argv);
};
static JSValue xr_interface_class_get_view_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&XRInterface::get_view_count, ctx, this_val, argc, argv);
};
static JSValue xr_interface_class_trigger_haptic_pulse(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&XRInterface::trigger_haptic_pulse, ctx, this_val, argc, argv);
};
static JSValue xr_interface_class_supports_play_area_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&XRInterface::supports_play_area_mode, ctx, this_val, argc, argv);
};
static JSValue xr_interface_class_get_play_area_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XRInterface::get_play_area_mode, ctx, this_val, argc, argv);
}
static JSValue xr_interface_class_set_play_area_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&XRInterface::set_play_area_mode, ctx, this_val, argc, argv);
};
static JSValue xr_interface_class_get_play_area(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XRInterface::get_play_area, ctx, this_val, argc, argv);
};
static JSValue xr_interface_class_get_anchor_detection_is_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XRInterface::get_anchor_detection_is_enabled, ctx, this_val, argc, argv);
}
static JSValue xr_interface_class_set_anchor_detection_is_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&XRInterface::set_anchor_detection_is_enabled, ctx, this_val, argc, argv);
};
static JSValue xr_interface_class_get_camera_feed_id(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&XRInterface::get_camera_feed_id, ctx, this_val, argc, argv);
};
static JSValue xr_interface_class_is_passthrough_supported(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&XRInterface::is_passthrough_supported, ctx, this_val, argc, argv);
};
static JSValue xr_interface_class_is_passthrough_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&XRInterface::is_passthrough_enabled, ctx, this_val, argc, argv);
};
static JSValue xr_interface_class_start_passthrough(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&XRInterface::start_passthrough, ctx, this_val, argc, argv);
};
static JSValue xr_interface_class_stop_passthrough(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&XRInterface::stop_passthrough, ctx, this_val, argc, argv);
};
static JSValue xr_interface_class_get_transform_for_view(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&XRInterface::get_transform_for_view, ctx, this_val, argc, argv);
};
static JSValue xr_interface_class_get_projection_for_view(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&XRInterface::get_projection_for_view, ctx, this_val, argc, argv);
};
static JSValue xr_interface_class_get_supported_environment_blend_modes(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&XRInterface::get_supported_environment_blend_modes, ctx, this_val, argc, argv);
};
static JSValue xr_interface_class_set_environment_blend_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&XRInterface::set_environment_blend_mode, ctx, this_val, argc, argv);
};
static JSValue xr_interface_class_get_environment_blend_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XRInterface::get_environment_blend_mode, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry xr_interface_class_proto_funcs[] = {
	JS_CFUNC_DEF("get_name", 0, &xr_interface_class_get_name),
	JS_CFUNC_DEF("get_capabilities", 0, &xr_interface_class_get_capabilities),
	JS_CFUNC_DEF("is_primary", 0, &xr_interface_class_is_primary),
	JS_CFUNC_DEF("set_primary", 1, &xr_interface_class_set_primary),
	JS_CFUNC_DEF("is_initialized", 0, &xr_interface_class_is_initialized),
	JS_CFUNC_DEF("initialize", 0, &xr_interface_class_initialize),
	JS_CFUNC_DEF("uninitialize", 0, &xr_interface_class_uninitialize),
	JS_CFUNC_DEF("get_system_info", 0, &xr_interface_class_get_system_info),
	JS_CFUNC_DEF("get_tracking_status", 0, &xr_interface_class_get_tracking_status),
	JS_CFUNC_DEF("get_render_target_size", 0, &xr_interface_class_get_render_target_size),
	JS_CFUNC_DEF("get_view_count", 0, &xr_interface_class_get_view_count),
	JS_CFUNC_DEF("trigger_haptic_pulse", 6, &xr_interface_class_trigger_haptic_pulse),
	JS_CFUNC_DEF("supports_play_area_mode", 1, &xr_interface_class_supports_play_area_mode),
	JS_CFUNC_DEF("get_play_area_mode", 0, &xr_interface_class_get_play_area_mode),
	JS_CFUNC_DEF("set_play_area_mode", 1, &xr_interface_class_set_play_area_mode),
	JS_CFUNC_DEF("get_play_area", 0, &xr_interface_class_get_play_area),
	JS_CFUNC_DEF("get_anchor_detection_is_enabled", 0, &xr_interface_class_get_anchor_detection_is_enabled),
	JS_CFUNC_DEF("set_anchor_detection_is_enabled", 1, &xr_interface_class_set_anchor_detection_is_enabled),
	JS_CFUNC_DEF("get_camera_feed_id", 0, &xr_interface_class_get_camera_feed_id),
	JS_CFUNC_DEF("is_passthrough_supported", 0, &xr_interface_class_is_passthrough_supported),
	JS_CFUNC_DEF("is_passthrough_enabled", 0, &xr_interface_class_is_passthrough_enabled),
	JS_CFUNC_DEF("start_passthrough", 0, &xr_interface_class_start_passthrough),
	JS_CFUNC_DEF("stop_passthrough", 0, &xr_interface_class_stop_passthrough),
	JS_CFUNC_DEF("get_transform_for_view", 2, &xr_interface_class_get_transform_for_view),
	JS_CFUNC_DEF("get_projection_for_view", 4, &xr_interface_class_get_projection_for_view),
	JS_CFUNC_DEF("get_supported_environment_blend_modes", 0, &xr_interface_class_get_supported_environment_blend_modes),
	JS_CFUNC_DEF("set_environment_blend_mode", 1, &xr_interface_class_set_environment_blend_mode),
	JS_CFUNC_DEF("get_environment_blend_mode", 0, &xr_interface_class_get_environment_blend_mode),
};


static JSValue xr_interface_class_get_play_area_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	XRInterface *opaque = static_cast<XRInterface *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "play_area_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "play_area_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "play_area_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_xr_interface_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "interface_is_primary"),
        JS_NewCFunction(ctx, xr_interface_class_is_primary, "is_primary", 0),
        JS_NewCFunction(ctx, xr_interface_class_set_primary, "set_primary", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "xr_play_area_mode"),
        JS_NewCFunction(ctx, xr_interface_class_get_play_area_mode, "get_play_area_mode", 0),
        JS_NewCFunction(ctx, xr_interface_class_set_play_area_mode, "set_play_area_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "environment_blend_mode"),
        JS_NewCFunction(ctx, xr_interface_class_get_environment_blend_mode, "get_environment_blend_mode", 0),
        JS_NewCFunction(ctx, xr_interface_class_set_environment_blend_mode, "set_environment_blend_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "ar_is_anchor_detection_enabled"),
        JS_NewCFunction(ctx, xr_interface_class_get_anchor_detection_is_enabled, "get_anchor_detection_is_enabled", 0),
        JS_NewCFunction(ctx, xr_interface_class_set_anchor_detection_is_enabled, "set_anchor_detection_is_enabled", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "play_area_changed"),
		JS_NewCFunction(ctx, xr_interface_class_get_play_area_changed_signal, "get_play_area_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_xr_interface_enum(JSContext *ctx, JSValue ctor) {
	JSValue Capabilities_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, Capabilities_obj, "XR_NONE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, Capabilities_obj, "XR_MONO", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, Capabilities_obj, "XR_STEREO", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, Capabilities_obj, "XR_QUAD", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, Capabilities_obj, "XR_VR", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, Capabilities_obj, "XR_AR", JS_NewInt64(ctx, 16));
	JS_SetPropertyStr(ctx, Capabilities_obj, "XR_EXTERNAL", JS_NewInt64(ctx, 32));
	JS_SetPropertyStr(ctx, ctor, "Capabilities", Capabilities_obj);
	JSValue TrackingStatus_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, TrackingStatus_obj, "XR_NORMAL_TRACKING", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, TrackingStatus_obj, "XR_EXCESSIVE_MOTION", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, TrackingStatus_obj, "XR_INSUFFICIENT_FEATURES", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, TrackingStatus_obj, "XR_UNKNOWN_TRACKING", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, TrackingStatus_obj, "XR_NOT_TRACKING", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, ctor, "TrackingStatus", TrackingStatus_obj);
	JSValue PlayAreaMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, PlayAreaMode_obj, "XR_PLAY_AREA_UNKNOWN", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, PlayAreaMode_obj, "XR_PLAY_AREA_3DOF", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, PlayAreaMode_obj, "XR_PLAY_AREA_SITTING", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, PlayAreaMode_obj, "XR_PLAY_AREA_ROOMSCALE", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, PlayAreaMode_obj, "XR_PLAY_AREA_STAGE", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, PlayAreaMode_obj, "XR_PLAY_AREA_CUSTOM", JS_NewInt64(ctx, 2147483647));
	JS_SetPropertyStr(ctx, ctor, "PlayAreaMode", PlayAreaMode_obj);
	JSValue EnvironmentBlendMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, EnvironmentBlendMode_obj, "XR_ENV_BLEND_MODE_OPAQUE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, EnvironmentBlendMode_obj, "XR_ENV_BLEND_MODE_ADDITIVE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, EnvironmentBlendMode_obj, "XR_ENV_BLEND_MODE_ALPHA_BLEND", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "EnvironmentBlendMode", EnvironmentBlendMode_obj);
	JSValue VRSTextureFormat_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, VRSTextureFormat_obj, "XR_VRS_TEXTURE_FORMAT_UNIFIED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, VRSTextureFormat_obj, "XR_VRS_TEXTURE_FORMAT_FRAGMENT_SHADING_RATE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, VRSTextureFormat_obj, "XR_VRS_TEXTURE_FORMAT_FRAGMENT_DENSITY_MAP", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "VRSTextureFormat", VRSTextureFormat_obj);
}

static int js_xr_interface_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["XRInterface"] = class_id;
	classes_by_id[class_id] = "XRInterface";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &xr_interface_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_xr_interface_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, xr_interface_class_proto_funcs, _countof(xr_interface_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, xr_interface_class_constructor, "XRInterface", 0, JS_CFUNC_constructor, 0);
	define_xr_interface_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "XRInterface", ctor);
	ctor_list["XRInterface"] = ctor;

	return 0;
}

JSModuleDef *_js_init_xr_interface_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_xr_interface_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "XRInterface");
	return m;
}

JSModuleDef *js_init_xr_interface_module(JSContext *ctx) {
	return _js_init_xr_interface_module(ctx, "@godot/classes/xr_interface");
}

void __register_xr_interface() {
	js_init_xr_interface_module(js_context());
}

void register_xr_interface() {
	__register_xr_interface();
}