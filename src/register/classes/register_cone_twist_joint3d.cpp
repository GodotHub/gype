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

    ConeTwistJoint3D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<ConeTwistJoint3D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(ConeTwistJoint3D);
	 	adapter = memnew(VariantAdapter(instance, true));
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

static const JSCFunctionListEntry cone_twist_joint3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_param", 2, &cone_twist_joint3d_class_set_param),
	JS_CFUNC_DEF("get_param", 1, &cone_twist_joint3d_class_get_param),
};




static void define_cone_twist_joint3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "swing_span"),
        JS_NewCFunction(ctx, cone_twist_joint3d_class_get_param, "get_param", 0),
        JS_NewCFunction(ctx, cone_twist_joint3d_class_set_param, "set_param", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "twist_span"),
        JS_NewCFunction(ctx, cone_twist_joint3d_class_get_param, "get_param", 0),
        JS_NewCFunction(ctx, cone_twist_joint3d_class_set_param, "set_param", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "bias"),
        JS_NewCFunction(ctx, cone_twist_joint3d_class_get_param, "get_param", 0),
        JS_NewCFunction(ctx, cone_twist_joint3d_class_set_param, "set_param", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "softness"),
        JS_NewCFunction(ctx, cone_twist_joint3d_class_get_param, "get_param", 0),
        JS_NewCFunction(ctx, cone_twist_joint3d_class_set_param, "set_param", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "relaxation"),
        JS_NewCFunction(ctx, cone_twist_joint3d_class_get_param, "get_param", 0),
        JS_NewCFunction(ctx, cone_twist_joint3d_class_set_param, "set_param", 1),
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