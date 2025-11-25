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
#include <godot_cpp/classes/generic6_dof_joint3d.hpp>
using namespace godot;

static void generic6_dof_joint3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["Generic6DOFJoint3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef generic6_dof_joint3d_class_def = {
    "Generic6DOFJoint3D",
    generic6_dof_joint3d_class_finalizer
};

static JSValue generic6_dof_joint3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["Generic6DOFJoint3D"];
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
        instance = memnew(Generic6DOFJoint3D);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue generic6_dof_joint3d_class_set_param_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Generic6DOFJoint3D::set_param_x, ctx, this_val, argc, argv);
};
static JSValue generic6_dof_joint3d_class_get_param_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Generic6DOFJoint3D::get_param_x, ctx, this_val, argc, argv);
};
static JSValue generic6_dof_joint3d_class_set_param_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Generic6DOFJoint3D::set_param_y, ctx, this_val, argc, argv);
};
static JSValue generic6_dof_joint3d_class_get_param_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Generic6DOFJoint3D::get_param_y, ctx, this_val, argc, argv);
};
static JSValue generic6_dof_joint3d_class_set_param_z(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Generic6DOFJoint3D::set_param_z, ctx, this_val, argc, argv);
};
static JSValue generic6_dof_joint3d_class_get_param_z(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Generic6DOFJoint3D::get_param_z, ctx, this_val, argc, argv);
};
static JSValue generic6_dof_joint3d_class_set_flag_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Generic6DOFJoint3D::set_flag_x, ctx, this_val, argc, argv);
};
static JSValue generic6_dof_joint3d_class_get_flag_x(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Generic6DOFJoint3D::get_flag_x, ctx, this_val, argc, argv);
};
static JSValue generic6_dof_joint3d_class_set_flag_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Generic6DOFJoint3D::set_flag_y, ctx, this_val, argc, argv);
};
static JSValue generic6_dof_joint3d_class_get_flag_y(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Generic6DOFJoint3D::get_flag_y, ctx, this_val, argc, argv);
};
static JSValue generic6_dof_joint3d_class_set_flag_z(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&Generic6DOFJoint3D::set_flag_z, ctx, this_val, argc, argv);
};
static JSValue generic6_dof_joint3d_class_get_flag_z(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&Generic6DOFJoint3D::get_flag_z, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry generic6_dof_joint3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_param_x", 2, &generic6_dof_joint3d_class_set_param_x),
	JS_CFUNC_DEF("get_param_x", 1, &generic6_dof_joint3d_class_get_param_x),
	JS_CFUNC_DEF("set_param_y", 2, &generic6_dof_joint3d_class_set_param_y),
	JS_CFUNC_DEF("get_param_y", 1, &generic6_dof_joint3d_class_get_param_y),
	JS_CFUNC_DEF("set_param_z", 2, &generic6_dof_joint3d_class_set_param_z),
	JS_CFUNC_DEF("get_param_z", 1, &generic6_dof_joint3d_class_get_param_z),
	JS_CFUNC_DEF("set_flag_x", 2, &generic6_dof_joint3d_class_set_flag_x),
	JS_CFUNC_DEF("get_flag_x", 1, &generic6_dof_joint3d_class_get_flag_x),
	JS_CFUNC_DEF("set_flag_y", 2, &generic6_dof_joint3d_class_set_flag_y),
	JS_CFUNC_DEF("get_flag_y", 1, &generic6_dof_joint3d_class_get_flag_y),
	JS_CFUNC_DEF("set_flag_z", 2, &generic6_dof_joint3d_class_set_flag_z),
	JS_CFUNC_DEF("get_flag_z", 1, &generic6_dof_joint3d_class_get_flag_z),
};




static void define_generic6_dof_joint3d_property(JSContext *ctx, JSValue proto) {
}

static void define_generic6_dof_joint3d_enum(JSContext *ctx, JSValue ctor) {
	JSValue Param_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_LINEAR_LOWER_LIMIT", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_LINEAR_UPPER_LIMIT", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_LINEAR_LIMIT_SOFTNESS", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_LINEAR_RESTITUTION", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_LINEAR_DAMPING", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_LINEAR_MOTOR_TARGET_VELOCITY", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_LINEAR_MOTOR_FORCE_LIMIT", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_LINEAR_SPRING_STIFFNESS", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_LINEAR_SPRING_DAMPING", JS_NewInt64(ctx, 8));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_LINEAR_SPRING_EQUILIBRIUM_POINT", JS_NewInt64(ctx, 9));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_ANGULAR_LOWER_LIMIT", JS_NewInt64(ctx, 10));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_ANGULAR_UPPER_LIMIT", JS_NewInt64(ctx, 11));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_ANGULAR_LIMIT_SOFTNESS", JS_NewInt64(ctx, 12));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_ANGULAR_DAMPING", JS_NewInt64(ctx, 13));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_ANGULAR_RESTITUTION", JS_NewInt64(ctx, 14));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_ANGULAR_FORCE_LIMIT", JS_NewInt64(ctx, 15));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_ANGULAR_ERP", JS_NewInt64(ctx, 16));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_ANGULAR_MOTOR_TARGET_VELOCITY", JS_NewInt64(ctx, 17));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_ANGULAR_MOTOR_FORCE_LIMIT", JS_NewInt64(ctx, 18));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_ANGULAR_SPRING_STIFFNESS", JS_NewInt64(ctx, 19));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_ANGULAR_SPRING_DAMPING", JS_NewInt64(ctx, 20));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_ANGULAR_SPRING_EQUILIBRIUM_POINT", JS_NewInt64(ctx, 21));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_MAX", JS_NewInt64(ctx, 22));
	JS_SetPropertyStr(ctx, ctor, "Param", Param_obj);
	JSValue Flag_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, Flag_obj, "FLAG_ENABLE_LINEAR_LIMIT", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, Flag_obj, "FLAG_ENABLE_ANGULAR_LIMIT", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, Flag_obj, "FLAG_ENABLE_LINEAR_SPRING", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, Flag_obj, "FLAG_ENABLE_ANGULAR_SPRING", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, Flag_obj, "FLAG_ENABLE_MOTOR", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, Flag_obj, "FLAG_ENABLE_LINEAR_MOTOR", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, Flag_obj, "FLAG_MAX", JS_NewInt64(ctx, 6));
	JS_SetPropertyStr(ctx, ctor, "Flag", Flag_obj);
}

static int js_generic6_dof_joint3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["Generic6DOFJoint3D"] = class_id;
	classes_by_id[class_id] = "Generic6DOFJoint3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &generic6_dof_joint3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Joint3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_generic6_dof_joint3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, generic6_dof_joint3d_class_proto_funcs, _countof(generic6_dof_joint3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, generic6_dof_joint3d_class_constructor, "Generic6DOFJoint3D", 0, JS_CFUNC_constructor, 0);
	define_generic6_dof_joint3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "Generic6DOFJoint3D", ctor);
	ctor_list["Generic6DOFJoint3D"] = ctor;

	return 0;
}

JSModuleDef *_js_init_generic6_dof_joint3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/joint3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_generic6_dof_joint3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "Generic6DOFJoint3D");
	return m;
}

JSModuleDef *js_init_generic6_dof_joint3d_module(JSContext *ctx) {
	return _js_init_generic6_dof_joint3d_module(ctx, "@godot/classes/generic6_dof_joint3d");
}

void __register_generic6_dof_joint3d() {
	js_init_generic6_dof_joint3d_module(js_context());
}

void register_generic6_dof_joint3d() {
	__register_generic6_dof_joint3d();
}