#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/joint3d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/slider_joint3d.hpp>
using namespace godot;

static void slider_joint3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["SliderJoint3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef slider_joint3d_class_def = {
    "SliderJoint3D",
    slider_joint3d_class_finalizer
};

static JSValue slider_joint3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["SliderJoint3D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    SliderJoint3D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<SliderJoint3D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(SliderJoint3D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue slider_joint3d_class_set_param(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SliderJoint3D::set_param, ctx, this_val, argc, argv);
};
static JSValue slider_joint3d_class_get_param(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SliderJoint3D::get_param, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry slider_joint3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_param", 2, &slider_joint3d_class_set_param),
	JS_CFUNC_DEF("get_param", 1, &slider_joint3d_class_get_param),
};




static void define_slider_joint3d_property(JSContext *ctx, JSValue proto) {
}

static void define_slider_joint3d_enum(JSContext *ctx, JSValue ctor) {
	JSValue Param_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_LINEAR_LIMIT_UPPER", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_LINEAR_LIMIT_LOWER", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_LINEAR_LIMIT_SOFTNESS", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_LINEAR_LIMIT_RESTITUTION", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_LINEAR_LIMIT_DAMPING", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_LINEAR_MOTION_SOFTNESS", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_LINEAR_MOTION_RESTITUTION", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_LINEAR_MOTION_DAMPING", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_LINEAR_ORTHOGONAL_SOFTNESS", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_LINEAR_ORTHOGONAL_RESTITUTION", JS_NewInt64(ctx, 9));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_LINEAR_ORTHOGONAL_DAMPING", JS_NewInt64(ctx, 10));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_ANGULAR_LIMIT_UPPER", JS_NewInt64(ctx, 11));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_ANGULAR_LIMIT_LOWER", JS_NewInt64(ctx, 12));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_ANGULAR_LIMIT_SOFTNESS", JS_NewInt64(ctx, 13));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_ANGULAR_LIMIT_RESTITUTION", JS_NewInt64(ctx, 14));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_ANGULAR_LIMIT_DAMPING", JS_NewInt64(ctx, 15));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_ANGULAR_MOTION_SOFTNESS", JS_NewInt64(ctx, 16));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_ANGULAR_MOTION_RESTITUTION", JS_NewInt64(ctx, 17));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_ANGULAR_MOTION_DAMPING", JS_NewInt64(ctx, 18));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_ANGULAR_ORTHOGONAL_SOFTNESS", JS_NewInt64(ctx, 19));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_ANGULAR_ORTHOGONAL_RESTITUTION", JS_NewInt64(ctx, 20));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_ANGULAR_ORTHOGONAL_DAMPING", JS_NewInt64(ctx, 21));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_MAX", JS_NewInt64(ctx, 22));
	JS_SetPropertyStr(ctx, ctor, "Param", Param_obj);
}

static int js_slider_joint3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["SliderJoint3D"] = class_id;
	classes_by_id[class_id] = "SliderJoint3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &slider_joint3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Joint3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_slider_joint3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, slider_joint3d_class_proto_funcs, _countof(slider_joint3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, slider_joint3d_class_constructor, "SliderJoint3D", 0, JS_CFUNC_constructor, 0);
	define_slider_joint3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "SliderJoint3D", ctor);

	return 0;
}

JSModuleDef *_js_init_slider_joint3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/joint3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_slider_joint3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "SliderJoint3D");
	return m;
}

JSModuleDef *js_init_slider_joint3d_module(JSContext *ctx) {
	return _js_init_slider_joint3d_module(ctx, "@godot/classes/slider_joint3d");
}

void __register_slider_joint3d() {
	js_init_slider_joint3d_module(js_context());
}

void register_slider_joint3d() {
	__register_slider_joint3d();
}