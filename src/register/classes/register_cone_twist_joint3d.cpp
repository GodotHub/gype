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
#include <godot_cpp/classes/cone_twist_joint3d.hpp>
using namespace godot;

static void cone_twist_joint3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["ConeTwistJoint3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef cone_twist_joint3d_class_def = {
    "ConeTwistJoint3D",
    cone_twist_joint3d_class_finalizer
};

static JSValue cone_twist_joint3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["ConeTwistJoint3D"];
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
        instance = memnew(ConeTwistJoint3D);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue cone_twist_joint3d_class_set_param(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ConeTwistJoint3D::set_param, ctx, this_val, argc, argv);
};
static JSValue cone_twist_joint3d_class_get_param(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ConeTwistJoint3D::get_param, ctx, this_val, argc, argv);
}

static JSValue cone_twist_joint3d_class_get_swing_span(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&ConeTwistJoint3D::get_param, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue cone_twist_joint3d_class_set_swing_span(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&ConeTwistJoint3D::set_param, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue cone_twist_joint3d_class_get_twist_span(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&ConeTwistJoint3D::get_param, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue cone_twist_joint3d_class_set_twist_span(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&ConeTwistJoint3D::set_param, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue cone_twist_joint3d_class_get_bias(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&ConeTwistJoint3D::get_param, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue cone_twist_joint3d_class_set_bias(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&ConeTwistJoint3D::set_param, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue cone_twist_joint3d_class_get_softness(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&ConeTwistJoint3D::get_param, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue cone_twist_joint3d_class_set_softness(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&ConeTwistJoint3D::set_param, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}
static JSValue cone_twist_joint3d_class_get_relaxation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	JSValue ret = call_builtin_const_method_ret(&ConeTwistJoint3D::get_param, ctx, this_val, argc, &index);
	JS_FreeValue(ctx, index);
	return ret;
}
static JSValue cone_twist_joint3d_class_set_relaxation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, int magic) {
	CHECK_INSTANCE_VALID_V(this_val);
	JSValue index = JS_NewInt64(ctx, magic);
	std::vector<JSValueConst> vec_arg;
	vec_arg.push_back(index);
	vec_arg.reserve(argc + 1);
	vec_arg.insert(vec_arg.end(), argv, argv + argc);
	call_builtin_method_no_ret(&ConeTwistJoint3D::set_param, ctx, this_val, argc, vec_arg.data());
	return JS_UNDEFINED;
}


static const JSCFunctionListEntry cone_twist_joint3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_param", 2, &cone_twist_joint3d_class_set_param),
	JS_CFUNC_DEF("get_param", 1, &cone_twist_joint3d_class_get_param),
    JS_CFUNC_MAGIC_DEF("get_twist_span", 0, &cone_twist_joint3d_class_get_twist_span, 1),
    JS_CFUNC_MAGIC_DEF("set_twist_span", 1, &cone_twist_joint3d_class_set_twist_span, 1),
    JS_CFUNC_MAGIC_DEF("get_bias", 0, &cone_twist_joint3d_class_get_bias, 2),
    JS_CFUNC_MAGIC_DEF("set_bias", 1, &cone_twist_joint3d_class_set_bias, 2),
    JS_CFUNC_MAGIC_DEF("get_softness", 0, &cone_twist_joint3d_class_get_softness, 3),
    JS_CFUNC_MAGIC_DEF("set_softness", 1, &cone_twist_joint3d_class_set_softness, 3),
    JS_CFUNC_MAGIC_DEF("get_relaxation", 0, &cone_twist_joint3d_class_get_relaxation, 4),
    JS_CFUNC_MAGIC_DEF("set_relaxation", 1, &cone_twist_joint3d_class_set_relaxation, 4),
};




static void define_cone_twist_joint3d_property(JSContext *ctx, JSValue proto) {
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "swing_span"),
		JS_NewCFunctionMagic(ctx, cone_twist_joint3d_class_get_swing_span, "get_swing_span", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 0),
		JS_NewCFunctionMagic(ctx, cone_twist_joint3d_class_set_swing_span, "set_swing_span", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 0),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "twist_span"),
		JS_NewCFunctionMagic(ctx, cone_twist_joint3d_class_get_twist_span, "get_twist_span", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 1),
		JS_NewCFunctionMagic(ctx, cone_twist_joint3d_class_set_twist_span, "set_twist_span", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 1),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "bias"),
		JS_NewCFunctionMagic(ctx, cone_twist_joint3d_class_get_bias, "get_bias", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 2),
		JS_NewCFunctionMagic(ctx, cone_twist_joint3d_class_set_bias, "set_bias", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 2),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "softness"),
		JS_NewCFunctionMagic(ctx, cone_twist_joint3d_class_get_softness, "get_softness", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 3),
		JS_NewCFunctionMagic(ctx, cone_twist_joint3d_class_set_softness, "set_softness", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 3),
		JS_PROP_GETSET
	);
	JS_DefinePropertyGetSet(
		ctx,
        proto,
        JS_NewAtom(ctx, "relaxation"),
		JS_NewCFunctionMagic(ctx, cone_twist_joint3d_class_get_relaxation, "get_relaxation", 0, JSCFunctionEnum::JS_CFUNC_generic_magic, 4),
		JS_NewCFunctionMagic(ctx, cone_twist_joint3d_class_set_relaxation, "set_relaxation", 1, JSCFunctionEnum::JS_CFUNC_generic_magic, 4),
		JS_PROP_GETSET
	);
}

static void define_cone_twist_joint3d_enum(JSContext *ctx, JSValue ctor) {
	JSValue Param_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_SWING_SPAN", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_TWIST_SPAN", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_BIAS", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_SOFTNESS", JS_NewInt64(ctx, 3));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_RELAXATION", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, Param_obj, "PARAM_MAX", JS_NewInt64(ctx, 5));
	JS_SetPropertyStr(ctx, ctor, "Param", Param_obj);
}

static int js_cone_twist_joint3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["ConeTwistJoint3D"] = class_id;
	classes_by_id[class_id] = "ConeTwistJoint3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &cone_twist_joint3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Joint3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_cone_twist_joint3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, cone_twist_joint3d_class_proto_funcs, _countof(cone_twist_joint3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, cone_twist_joint3d_class_constructor, "ConeTwistJoint3D", 0, JS_CFUNC_constructor, 0);
	define_cone_twist_joint3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "ConeTwistJoint3D", ctor);
	ctor_list["ConeTwistJoint3D"] = ctor;

	return 0;
}

JSModuleDef *_js_init_cone_twist_joint3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/joint3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_cone_twist_joint3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "ConeTwistJoint3D");
	return m;
}

JSModuleDef *js_init_cone_twist_joint3d_module(JSContext *ctx) {
	return _js_init_cone_twist_joint3d_module(ctx, "@godot/classes/cone_twist_joint3d");
}

void __register_cone_twist_joint3d() {
	js_init_cone_twist_joint3d_module(js_context());
}

void register_cone_twist_joint3d() {
	__register_cone_twist_joint3d();
}