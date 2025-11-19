#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/xr_controller_tracker.hpp>
#include <godot_cpp/classes/xr_interface.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/web_xr_interface.hpp>
using namespace godot;

static void web_xr_interface_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["WebXRInterface"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef web_xr_interface_class_def = {
    "WebXRInterface",
    web_xr_interface_class_finalizer
};

static JSValue web_xr_interface_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["WebXRInterface"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    WebXRInterface *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<WebXRInterface *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(WebXRInterface);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue web_xr_interface_class_is_session_supported(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&WebXRInterface::is_session_supported, ctx, this_val, argc, argv);
};
static JSValue web_xr_interface_class_set_session_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&WebXRInterface::set_session_mode, ctx, this_val, argc, argv);
};
static JSValue web_xr_interface_class_get_session_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&WebXRInterface::get_session_mode, ctx, this_val, argc, argv);
}
static JSValue web_xr_interface_class_set_required_features(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&WebXRInterface::set_required_features, ctx, this_val, argc, argv);
};
static JSValue web_xr_interface_class_get_required_features(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&WebXRInterface::get_required_features, ctx, this_val, argc, argv);
}
static JSValue web_xr_interface_class_set_optional_features(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&WebXRInterface::set_optional_features, ctx, this_val, argc, argv);
};
static JSValue web_xr_interface_class_get_optional_features(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&WebXRInterface::get_optional_features, ctx, this_val, argc, argv);
}
static JSValue web_xr_interface_class_get_reference_space_type(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&WebXRInterface::get_reference_space_type, ctx, this_val, argc, argv);
}
static JSValue web_xr_interface_class_get_enabled_features(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&WebXRInterface::get_enabled_features, ctx, this_val, argc, argv);
}
static JSValue web_xr_interface_class_set_requested_reference_space_types(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&WebXRInterface::set_requested_reference_space_types, ctx, this_val, argc, argv);
};
static JSValue web_xr_interface_class_get_requested_reference_space_types(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&WebXRInterface::get_requested_reference_space_types, ctx, this_val, argc, argv);
}
static JSValue web_xr_interface_class_is_input_source_active(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&WebXRInterface::is_input_source_active, ctx, this_val, argc, argv);
};
static JSValue web_xr_interface_class_get_input_source_tracker(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&WebXRInterface::get_input_source_tracker, ctx, this_val, argc, argv);
};
static JSValue web_xr_interface_class_get_input_source_target_ray_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&WebXRInterface::get_input_source_target_ray_mode, ctx, this_val, argc, argv);
};
static JSValue web_xr_interface_class_get_visibility_state(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&WebXRInterface::get_visibility_state, ctx, this_val, argc, argv);
}
static JSValue web_xr_interface_class_get_display_refresh_rate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&WebXRInterface::get_display_refresh_rate, ctx, this_val, argc, argv);
};
static JSValue web_xr_interface_class_set_display_refresh_rate(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&WebXRInterface::set_display_refresh_rate, ctx, this_val, argc, argv);
};
static JSValue web_xr_interface_class_get_available_display_refresh_rates(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&WebXRInterface::get_available_display_refresh_rates, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry web_xr_interface_class_proto_funcs[] = {
	JS_CFUNC_DEF("is_session_supported", 1, &web_xr_interface_class_is_session_supported),
	JS_CFUNC_DEF("set_session_mode", 1, &web_xr_interface_class_set_session_mode),
	JS_CFUNC_DEF("get_session_mode", 0, &web_xr_interface_class_get_session_mode),
	JS_CFUNC_DEF("set_required_features", 1, &web_xr_interface_class_set_required_features),
	JS_CFUNC_DEF("get_required_features", 0, &web_xr_interface_class_get_required_features),
	JS_CFUNC_DEF("set_optional_features", 1, &web_xr_interface_class_set_optional_features),
	JS_CFUNC_DEF("get_optional_features", 0, &web_xr_interface_class_get_optional_features),
	JS_CFUNC_DEF("get_reference_space_type", 0, &web_xr_interface_class_get_reference_space_type),
	JS_CFUNC_DEF("get_enabled_features", 0, &web_xr_interface_class_get_enabled_features),
	JS_CFUNC_DEF("set_requested_reference_space_types", 1, &web_xr_interface_class_set_requested_reference_space_types),
	JS_CFUNC_DEF("get_requested_reference_space_types", 0, &web_xr_interface_class_get_requested_reference_space_types),
	JS_CFUNC_DEF("is_input_source_active", 1, &web_xr_interface_class_is_input_source_active),
	JS_CFUNC_DEF("get_input_source_tracker", 1, &web_xr_interface_class_get_input_source_tracker),
	JS_CFUNC_DEF("get_input_source_target_ray_mode", 1, &web_xr_interface_class_get_input_source_target_ray_mode),
	JS_CFUNC_DEF("get_visibility_state", 0, &web_xr_interface_class_get_visibility_state),
	JS_CFUNC_DEF("get_display_refresh_rate", 0, &web_xr_interface_class_get_display_refresh_rate),
	JS_CFUNC_DEF("set_display_refresh_rate", 1, &web_xr_interface_class_set_display_refresh_rate),
	JS_CFUNC_DEF("get_available_display_refresh_rates", 0, &web_xr_interface_class_get_available_display_refresh_rates),
};


static JSValue web_xr_interface_class_get_session_supported_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	WebXRInterface *opaque = static_cast<WebXRInterface *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "session_supported_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "session_supported"));
		JS_DefinePropertyValueStr(ctx, this_val, "session_supported_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue web_xr_interface_class_get_session_started_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	WebXRInterface *opaque = static_cast<WebXRInterface *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "session_started_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "session_started"));
		JS_DefinePropertyValueStr(ctx, this_val, "session_started_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue web_xr_interface_class_get_session_ended_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	WebXRInterface *opaque = static_cast<WebXRInterface *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "session_ended_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "session_ended"));
		JS_DefinePropertyValueStr(ctx, this_val, "session_ended_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue web_xr_interface_class_get_session_failed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	WebXRInterface *opaque = static_cast<WebXRInterface *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "session_failed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "session_failed"));
		JS_DefinePropertyValueStr(ctx, this_val, "session_failed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue web_xr_interface_class_get_selectstart_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	WebXRInterface *opaque = static_cast<WebXRInterface *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "selectstart_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "selectstart"));
		JS_DefinePropertyValueStr(ctx, this_val, "selectstart_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue web_xr_interface_class_get_select_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	WebXRInterface *opaque = static_cast<WebXRInterface *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "select_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "select"));
		JS_DefinePropertyValueStr(ctx, this_val, "select_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue web_xr_interface_class_get_selectend_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	WebXRInterface *opaque = static_cast<WebXRInterface *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "selectend_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "selectend"));
		JS_DefinePropertyValueStr(ctx, this_val, "selectend_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue web_xr_interface_class_get_squeezestart_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	WebXRInterface *opaque = static_cast<WebXRInterface *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "squeezestart_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "squeezestart"));
		JS_DefinePropertyValueStr(ctx, this_val, "squeezestart_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue web_xr_interface_class_get_squeeze_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	WebXRInterface *opaque = static_cast<WebXRInterface *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "squeeze_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "squeeze"));
		JS_DefinePropertyValueStr(ctx, this_val, "squeeze_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue web_xr_interface_class_get_squeezeend_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	WebXRInterface *opaque = static_cast<WebXRInterface *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "squeezeend_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "squeezeend"));
		JS_DefinePropertyValueStr(ctx, this_val, "squeezeend_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue web_xr_interface_class_get_visibility_state_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	WebXRInterface *opaque = static_cast<WebXRInterface *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "visibility_state_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "visibility_state_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "visibility_state_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue web_xr_interface_class_get_reference_space_reset_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	WebXRInterface *opaque = static_cast<WebXRInterface *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "reference_space_reset_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "reference_space_reset"));
		JS_DefinePropertyValueStr(ctx, this_val, "reference_space_reset_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}
static JSValue web_xr_interface_class_get_display_refresh_rate_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	WebXRInterface *opaque = static_cast<WebXRInterface *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "display_refresh_rate_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "display_refresh_rate_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "display_refresh_rate_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_web_xr_interface_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "session_mode"),
        JS_NewCFunction(ctx, web_xr_interface_class_get_session_mode, "get_session_mode", 0),
        JS_NewCFunction(ctx, web_xr_interface_class_set_session_mode, "set_session_mode", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "required_features"),
        JS_NewCFunction(ctx, web_xr_interface_class_get_required_features, "get_required_features", 0),
        JS_NewCFunction(ctx, web_xr_interface_class_set_required_features, "set_required_features", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "optional_features"),
        JS_NewCFunction(ctx, web_xr_interface_class_get_optional_features, "get_optional_features", 0),
        JS_NewCFunction(ctx, web_xr_interface_class_set_optional_features, "set_optional_features", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "requested_reference_space_types"),
        JS_NewCFunction(ctx, web_xr_interface_class_get_requested_reference_space_types, "get_requested_reference_space_types", 0),
        JS_NewCFunction(ctx, web_xr_interface_class_set_requested_reference_space_types, "set_requested_reference_space_types", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "reference_space_type"),
        JS_NewCFunction(ctx, web_xr_interface_class_get_reference_space_type, "get_reference_space_type", 0),
        JS_UNDEFINED,
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "enabled_features"),
        JS_NewCFunction(ctx, web_xr_interface_class_get_enabled_features, "get_enabled_features", 0),
        JS_UNDEFINED,
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "visibility_state"),
        JS_NewCFunction(ctx, web_xr_interface_class_get_visibility_state, "get_visibility_state", 0),
        JS_UNDEFINED,
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "session_supported"),
		JS_NewCFunction(ctx, web_xr_interface_class_get_session_supported_signal, "get_session_supported_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "session_started"),
		JS_NewCFunction(ctx, web_xr_interface_class_get_session_started_signal, "get_session_started_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "session_ended"),
		JS_NewCFunction(ctx, web_xr_interface_class_get_session_ended_signal, "get_session_ended_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "session_failed"),
		JS_NewCFunction(ctx, web_xr_interface_class_get_session_failed_signal, "get_session_failed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "selectstart"),
		JS_NewCFunction(ctx, web_xr_interface_class_get_selectstart_signal, "get_selectstart_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "select"),
		JS_NewCFunction(ctx, web_xr_interface_class_get_select_signal, "get_select_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "selectend"),
		JS_NewCFunction(ctx, web_xr_interface_class_get_selectend_signal, "get_selectend_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "squeezestart"),
		JS_NewCFunction(ctx, web_xr_interface_class_get_squeezestart_signal, "get_squeezestart_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "squeeze"),
		JS_NewCFunction(ctx, web_xr_interface_class_get_squeeze_signal, "get_squeeze_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "squeezeend"),
		JS_NewCFunction(ctx, web_xr_interface_class_get_squeezeend_signal, "get_squeezeend_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "visibility_state_changed"),
		JS_NewCFunction(ctx, web_xr_interface_class_get_visibility_state_changed_signal, "get_visibility_state_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "reference_space_reset"),
		JS_NewCFunction(ctx, web_xr_interface_class_get_reference_space_reset_signal, "get_reference_space_reset_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "display_refresh_rate_changed"),
		JS_NewCFunction(ctx, web_xr_interface_class_get_display_refresh_rate_changed_signal, "get_display_refresh_rate_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_web_xr_interface_enum(JSContext *ctx, JSValue ctor) {
	JSValue TargetRayMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, TargetRayMode_obj, "TARGET_RAY_MODE_UNKNOWN", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, TargetRayMode_obj, "TARGET_RAY_MODE_GAZE", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, TargetRayMode_obj, "TARGET_RAY_MODE_TRACKED_POINTER", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, TargetRayMode_obj, "TARGET_RAY_MODE_SCREEN", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, ctor, "TargetRayMode", TargetRayMode_obj);
}

static int js_web_xr_interface_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["WebXRInterface"] = class_id;
	classes_by_id[class_id] = "WebXRInterface";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &web_xr_interface_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["XRInterface"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_web_xr_interface_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, web_xr_interface_class_proto_funcs, _countof(web_xr_interface_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, web_xr_interface_class_constructor, "WebXRInterface", 0, JS_CFUNC_constructor, 0);
	define_web_xr_interface_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "WebXRInterface", ctor);

	return 0;
}

JSModuleDef *_js_init_web_xr_interface_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/xr_interface';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_web_xr_interface_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "WebXRInterface");
	return m;
}

JSModuleDef *js_init_web_xr_interface_module(JSContext *ctx) {
	return _js_init_web_xr_interface_module(ctx, "@godot/classes/web_xr_interface");
}

void __register_web_xr_interface() {
	js_init_web_xr_interface_module(js_context());
}

void register_web_xr_interface() {
	__register_web_xr_interface();
}