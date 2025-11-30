#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/xr_node3d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/xr_controller3d.hpp>
using namespace godot;

static void xr_controller3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["XRController3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef xr_controller3d_class_def = {
    "XRController3D",
    xr_controller3d_class_finalizer
};

static JSValue xr_controller3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["XRController3D"];
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
        instance = memnew(XRController3D);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue xr_controller3d_class_is_button_pressed(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XRController3D::is_button_pressed, ctx, this_val, argc, argv);
};
static JSValue xr_controller3d_class_get_input(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XRController3D::get_input, ctx, this_val, argc, argv);
};
static JSValue xr_controller3d_class_get_float(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XRController3D::get_float, ctx, this_val, argc, argv);
};
static JSValue xr_controller3d_class_get_vector2(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XRController3D::get_vector2, ctx, this_val, argc, argv);
};
static JSValue xr_controller3d_class_get_tracker_hand(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XRController3D::get_tracker_hand, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry xr_controller3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("is_button_pressed", 1, &xr_controller3d_class_is_button_pressed),
	JS_CFUNC_DEF("get_input", 1, &xr_controller3d_class_get_input),
	JS_CFUNC_DEF("get_float", 1, &xr_controller3d_class_get_float),
	JS_CFUNC_DEF("get_vector2", 1, &xr_controller3d_class_get_vector2),
	JS_CFUNC_DEF("get_tracker_hand", 0, &xr_controller3d_class_get_tracker_hand),
};


static JSValue xr_controller3d_class_get_button_pressed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "button_pressed");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue xr_controller3d_class_get_button_released_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "button_released");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue xr_controller3d_class_get_input_float_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "input_float_changed");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue xr_controller3d_class_get_input_vector2_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "input_vector2_changed");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}
static JSValue xr_controller3d_class_get_profile_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue signal_ctor = JS_GetPropertyStr(ctx, global, "Signal");
	JSValue signal_name = JS_NewString(ctx, "profile_changed");
	JSValue args[] = { this_val, signal_name };
	JS_FreeValue(ctx, global);
	return JS_CallConstructor(ctx, signal_ctor, 2, args);
}


static void define_xr_controller3d_property(JSContext *ctx, JSValue proto) {
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "button_pressed"),
		JS_NewCFunction(ctx, xr_controller3d_class_get_button_pressed_signal, "get_button_pressed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "button_released"),
		JS_NewCFunction(ctx, xr_controller3d_class_get_button_released_signal, "get_button_released_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "input_float_changed"),
		JS_NewCFunction(ctx, xr_controller3d_class_get_input_float_changed_signal, "get_input_float_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "input_vector2_changed"),
		JS_NewCFunction(ctx, xr_controller3d_class_get_input_vector2_changed_signal, "get_input_vector2_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "profile_changed"),
		JS_NewCFunction(ctx, xr_controller3d_class_get_profile_changed_signal, "get_profile_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_xr_controller3d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_xr_controller3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["XRController3D"] = class_id;
	classes_by_id[class_id] = "XRController3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &xr_controller3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["XRNode3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_xr_controller3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, xr_controller3d_class_proto_funcs, _countof(xr_controller3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, xr_controller3d_class_constructor, "XRController3D", 0, JS_CFUNC_constructor, 0);
	define_xr_controller3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "XRController3D", ctor);
	ctor_list["XRController3D"] = ctor;

	return 0;
}

JSModuleDef *_js_init_xr_controller3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/xr_node3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_xr_controller3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "XRController3D");
	return m;
}

JSModuleDef *js_init_xr_controller3d_module(JSContext *ctx) {
	return _js_init_xr_controller3d_module(ctx, "@godot/classes/xr_controller3d");
}

void __register_xr_controller3d() {
	js_init_xr_controller3d_module(js_context());
}

void register_xr_controller3d() {
	__register_xr_controller3d();
}