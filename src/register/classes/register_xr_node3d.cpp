#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/xr_pose.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/xr_node3d.hpp>
using namespace godot;

static void xr_node3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["XRNode3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef xr_node3d_class_def = {
    "XRNode3D",
    xr_node3d_class_finalizer
};

static JSValue xr_node3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["XRNode3D"];
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
        instance = memnew(XRNode3D);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue xr_node3d_class_set_tracker(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&XRNode3D::set_tracker, ctx, this_val, argc, argv);
};
static JSValue xr_node3d_class_get_tracker(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XRNode3D::get_tracker, ctx, this_val, argc, argv);
}
static JSValue xr_node3d_class_set_pose_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&XRNode3D::set_pose_name, ctx, this_val, argc, argv);
};
static JSValue xr_node3d_class_get_pose_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XRNode3D::get_pose_name, ctx, this_val, argc, argv);
}
static JSValue xr_node3d_class_set_show_when_tracked(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&XRNode3D::set_show_when_tracked, ctx, this_val, argc, argv);
};
static JSValue xr_node3d_class_get_show_when_tracked(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XRNode3D::get_show_when_tracked, ctx, this_val, argc, argv);
}
static JSValue xr_node3d_class_get_is_active(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XRNode3D::get_is_active, ctx, this_val, argc, argv);
};
static JSValue xr_node3d_class_get_has_tracking_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XRNode3D::get_has_tracking_data, ctx, this_val, argc, argv);
};
static JSValue xr_node3d_class_get_pose(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&XRNode3D::get_pose, ctx, this_val, argc, argv);
};
static JSValue xr_node3d_class_trigger_haptic_pulse(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&XRNode3D::trigger_haptic_pulse, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry xr_node3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_tracker", 1, &xr_node3d_class_set_tracker),
	JS_CFUNC_DEF("get_tracker", 0, &xr_node3d_class_get_tracker),
	JS_CFUNC_DEF("set_pose_name", 1, &xr_node3d_class_set_pose_name),
	JS_CFUNC_DEF("get_pose_name", 0, &xr_node3d_class_get_pose_name),
	JS_CFUNC_DEF("set_show_when_tracked", 1, &xr_node3d_class_set_show_when_tracked),
	JS_CFUNC_DEF("get_show_when_tracked", 0, &xr_node3d_class_get_show_when_tracked),
	JS_CFUNC_DEF("get_is_active", 0, &xr_node3d_class_get_is_active),
	JS_CFUNC_DEF("get_has_tracking_data", 0, &xr_node3d_class_get_has_tracking_data),
	JS_CFUNC_DEF("get_pose", 0, &xr_node3d_class_get_pose),
	JS_CFUNC_DEF("trigger_haptic_pulse", 5, &xr_node3d_class_trigger_haptic_pulse),
};


static JSValue xr_node3d_class_get_tracking_changed_signal(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	XRNode3D *opaque = static_cast<XRNode3D *>(reinterpret_cast<VariantAdapter *>(JS_GetOpaque(this_val, JS_GetClassID(this_val)))->get().operator Object*());
	JSValue js_signal = JS_GetPropertyStr(ctx, this_val, "tracking_changed_signal");
	if (JS_IsUndefined(js_signal)) {
		js_signal = VariantAdapter(Signal(opaque, "tracking_changed"));
		JS_DefinePropertyValueStr(ctx, this_val, "tracking_changed_signal", js_signal, JS_PROP_HAS_VALUE);
	}
	return js_signal;
}


static void define_xr_node3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "tracker"),
        JS_NewCFunction(ctx, xr_node3d_class_get_tracker, "get_tracker", 0),
        JS_NewCFunction(ctx, xr_node3d_class_set_tracker, "set_tracker", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "pose"),
        JS_NewCFunction(ctx, xr_node3d_class_get_pose_name, "get_pose_name", 0),
        JS_NewCFunction(ctx, xr_node3d_class_set_pose_name, "set_pose_name", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "show_when_tracked"),
        JS_NewCFunction(ctx, xr_node3d_class_get_show_when_tracked, "get_show_when_tracked", 0),
        JS_NewCFunction(ctx, xr_node3d_class_set_show_when_tracked, "set_show_when_tracked", 1),
        JS_PROP_GETSET
    );
	JS_DefinePropertyGetSet(
		ctx,
		proto,
		JS_NewAtom(ctx, "tracking_changed"),
		JS_NewCFunction(ctx, xr_node3d_class_get_tracking_changed_signal, "get_tracking_changed_signal", 0),
		JS_UNDEFINED,
		JS_PROP_GETSET);
}

static void define_xr_node3d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_xr_node3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["XRNode3D"] = class_id;
	classes_by_id[class_id] = "XRNode3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &xr_node3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_xr_node3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, xr_node3d_class_proto_funcs, _countof(xr_node3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, xr_node3d_class_constructor, "XRNode3D", 0, JS_CFUNC_constructor, 0);
	define_xr_node3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "XRNode3D", ctor);
	ctor_list["XRNode3D"] = ctor;

	return 0;
}

JSModuleDef *_js_init_xr_node3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_xr_node3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "XRNode3D");
	return m;
}

JSModuleDef *js_init_xr_node3d_module(JSContext *ctx) {
	return _js_init_xr_node3d_module(ctx, "@godot/classes/xr_node3d");
}

void __register_xr_node3d() {
	js_init_xr_node3d_module(js_context());
}

void register_xr_node3d() {
	__register_xr_node3d();
}