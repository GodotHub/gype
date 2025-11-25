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
#include <godot_cpp/classes/xr_pose.hpp>
using namespace godot;

static void xr_pose_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["XRPose"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef xr_pose_class_def = {
    "XRPose",
    xr_pose_class_finalizer
};

static JSValue xr_pose_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["XRPose"];
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
        instance = memnew(XRPose);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue xr_pose_class_set_has_tracking_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&XRPose::set_has_tracking_data, ctx, this_val, argc, argv);
};
static JSValue xr_pose_class_get_has_tracking_data(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XRPose::get_has_tracking_data, ctx, this_val, argc, argv);
}
static JSValue xr_pose_class_set_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&XRPose::set_name, ctx, this_val, argc, argv);
};
static JSValue xr_pose_class_get_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XRPose::get_name, ctx, this_val, argc, argv);
}
static JSValue xr_pose_class_set_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&XRPose::set_transform, ctx, this_val, argc, argv);
};
static JSValue xr_pose_class_get_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XRPose::get_transform, ctx, this_val, argc, argv);
}
static JSValue xr_pose_class_get_adjusted_transform(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XRPose::get_adjusted_transform, ctx, this_val, argc, argv);
};
static JSValue xr_pose_class_set_linear_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&XRPose::set_linear_velocity, ctx, this_val, argc, argv);
};
static JSValue xr_pose_class_get_linear_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XRPose::get_linear_velocity, ctx, this_val, argc, argv);
}
static JSValue xr_pose_class_set_angular_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&XRPose::set_angular_velocity, ctx, this_val, argc, argv);
};
static JSValue xr_pose_class_get_angular_velocity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XRPose::get_angular_velocity, ctx, this_val, argc, argv);
}
static JSValue xr_pose_class_set_tracking_confidence(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&XRPose::set_tracking_confidence, ctx, this_val, argc, argv);
};
static JSValue xr_pose_class_get_tracking_confidence(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&XRPose::get_tracking_confidence, ctx, this_val, argc, argv);
}



static const JSCFunctionListEntry xr_pose_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_has_tracking_data", 1, &xr_pose_class_set_has_tracking_data),
	JS_CFUNC_DEF("get_has_tracking_data", 0, &xr_pose_class_get_has_tracking_data),
	JS_CFUNC_DEF("set_name", 1, &xr_pose_class_set_name),
	JS_CFUNC_DEF("get_name", 0, &xr_pose_class_get_name),
	JS_CFUNC_DEF("set_transform", 1, &xr_pose_class_set_transform),
	JS_CFUNC_DEF("get_transform", 0, &xr_pose_class_get_transform),
	JS_CFUNC_DEF("get_adjusted_transform", 0, &xr_pose_class_get_adjusted_transform),
	JS_CFUNC_DEF("set_linear_velocity", 1, &xr_pose_class_set_linear_velocity),
	JS_CFUNC_DEF("get_linear_velocity", 0, &xr_pose_class_get_linear_velocity),
	JS_CFUNC_DEF("set_angular_velocity", 1, &xr_pose_class_set_angular_velocity),
	JS_CFUNC_DEF("get_angular_velocity", 0, &xr_pose_class_get_angular_velocity),
	JS_CFUNC_DEF("set_tracking_confidence", 1, &xr_pose_class_set_tracking_confidence),
	JS_CFUNC_DEF("get_tracking_confidence", 0, &xr_pose_class_get_tracking_confidence),
};




static void define_xr_pose_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "has_tracking_data"),
        JS_NewCFunction(ctx, xr_pose_class_get_has_tracking_data, "get_has_tracking_data", 0),
        JS_NewCFunction(ctx, xr_pose_class_set_has_tracking_data, "set_has_tracking_data", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "name"),
        JS_NewCFunction(ctx, xr_pose_class_get_name, "get_name", 0),
        JS_NewCFunction(ctx, xr_pose_class_set_name, "set_name", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "transform"),
        JS_NewCFunction(ctx, xr_pose_class_get_transform, "get_transform", 0),
        JS_NewCFunction(ctx, xr_pose_class_set_transform, "set_transform", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "linear_velocity"),
        JS_NewCFunction(ctx, xr_pose_class_get_linear_velocity, "get_linear_velocity", 0),
        JS_NewCFunction(ctx, xr_pose_class_set_linear_velocity, "set_linear_velocity", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "angular_velocity"),
        JS_NewCFunction(ctx, xr_pose_class_get_angular_velocity, "get_angular_velocity", 0),
        JS_NewCFunction(ctx, xr_pose_class_set_angular_velocity, "set_angular_velocity", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "tracking_confidence"),
        JS_NewCFunction(ctx, xr_pose_class_get_tracking_confidence, "get_tracking_confidence", 0),
        JS_NewCFunction(ctx, xr_pose_class_set_tracking_confidence, "set_tracking_confidence", 1),
        JS_PROP_GETSET
    );
}

static void define_xr_pose_enum(JSContext *ctx, JSValue ctor) {
	JSValue TrackingConfidence_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, TrackingConfidence_obj, "XR_TRACKING_CONFIDENCE_NONE", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, TrackingConfidence_obj, "XR_TRACKING_CONFIDENCE_LOW", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, TrackingConfidence_obj, "XR_TRACKING_CONFIDENCE_HIGH", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "TrackingConfidence", TrackingConfidence_obj);
}

static int js_xr_pose_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["XRPose"] = class_id;
	classes_by_id[class_id] = "XRPose";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &xr_pose_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["RefCounted"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_xr_pose_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, xr_pose_class_proto_funcs, _countof(xr_pose_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, xr_pose_class_constructor, "XRPose", 0, JS_CFUNC_constructor, 0);
	define_xr_pose_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "XRPose", ctor);
	ctor_list["XRPose"] = ctor;

	return 0;
}

JSModuleDef *_js_init_xr_pose_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/ref_counted';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_xr_pose_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "XRPose");
	return m;
}

JSModuleDef *js_init_xr_pose_module(JSContext *ctx) {
	return _js_init_xr_pose_module(ctx, "@godot/classes/xr_pose");
}

void __register_xr_pose() {
	js_init_xr_pose_module(js_context());
}

void register_xr_pose() {
	__register_xr_pose();
}