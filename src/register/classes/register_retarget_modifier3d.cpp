#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/skeleton_modifier3d.hpp>
#include <godot_cpp/classes/skeleton_profile.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/retarget_modifier3d.hpp>
using namespace godot;

static void retarget_modifier3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["RetargetModifier3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef retarget_modifier3d_class_def = {
    "RetargetModifier3D",
    retarget_modifier3d_class_finalizer
};

static JSValue retarget_modifier3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["RetargetModifier3D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    RetargetModifier3D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<RetargetModifier3D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(RetargetModifier3D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue retarget_modifier3d_class_set_profile(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RetargetModifier3D::set_profile, ctx, this_val, argc, argv);
};
static JSValue retarget_modifier3d_class_get_profile(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RetargetModifier3D::get_profile, ctx, this_val, argc, argv);
}
static JSValue retarget_modifier3d_class_set_use_global_pose(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RetargetModifier3D::set_use_global_pose, ctx, this_val, argc, argv);
};
static JSValue retarget_modifier3d_class_is_using_global_pose(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RetargetModifier3D::is_using_global_pose, ctx, this_val, argc, argv);
}
static JSValue retarget_modifier3d_class_set_enable_flags(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RetargetModifier3D::set_enable_flags, ctx, this_val, argc, argv);
};
static JSValue retarget_modifier3d_class_get_enable_flags(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RetargetModifier3D::get_enable_flags, ctx, this_val, argc, argv);
}
static JSValue retarget_modifier3d_class_set_position_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RetargetModifier3D::set_position_enabled, ctx, this_val, argc, argv);
};
static JSValue retarget_modifier3d_class_is_position_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RetargetModifier3D::is_position_enabled, ctx, this_val, argc, argv);
};
static JSValue retarget_modifier3d_class_set_rotation_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RetargetModifier3D::set_rotation_enabled, ctx, this_val, argc, argv);
};
static JSValue retarget_modifier3d_class_is_rotation_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RetargetModifier3D::is_rotation_enabled, ctx, this_val, argc, argv);
};
static JSValue retarget_modifier3d_class_set_scale_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&RetargetModifier3D::set_scale_enabled, ctx, this_val, argc, argv);
};
static JSValue retarget_modifier3d_class_is_scale_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&RetargetModifier3D::is_scale_enabled, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry retarget_modifier3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_profile", 1, &retarget_modifier3d_class_set_profile),
	JS_CFUNC_DEF("get_profile", 0, &retarget_modifier3d_class_get_profile),
	JS_CFUNC_DEF("set_use_global_pose", 1, &retarget_modifier3d_class_set_use_global_pose),
	JS_CFUNC_DEF("is_using_global_pose", 0, &retarget_modifier3d_class_is_using_global_pose),
	JS_CFUNC_DEF("set_enable_flags", 1, &retarget_modifier3d_class_set_enable_flags),
	JS_CFUNC_DEF("get_enable_flags", 0, &retarget_modifier3d_class_get_enable_flags),
	JS_CFUNC_DEF("set_position_enabled", 1, &retarget_modifier3d_class_set_position_enabled),
	JS_CFUNC_DEF("is_position_enabled", 0, &retarget_modifier3d_class_is_position_enabled),
	JS_CFUNC_DEF("set_rotation_enabled", 1, &retarget_modifier3d_class_set_rotation_enabled),
	JS_CFUNC_DEF("is_rotation_enabled", 0, &retarget_modifier3d_class_is_rotation_enabled),
	JS_CFUNC_DEF("set_scale_enabled", 1, &retarget_modifier3d_class_set_scale_enabled),
	JS_CFUNC_DEF("is_scale_enabled", 0, &retarget_modifier3d_class_is_scale_enabled),
};




static void define_retarget_modifier3d_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "profile"),
        JS_NewCFunction(ctx, retarget_modifier3d_class_get_profile, "get_profile", 0),
        JS_NewCFunction(ctx, retarget_modifier3d_class_set_profile, "set_profile", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "use_global_pose"),
        JS_NewCFunction(ctx, retarget_modifier3d_class_is_using_global_pose, "is_using_global_pose", 0),
        JS_NewCFunction(ctx, retarget_modifier3d_class_set_use_global_pose, "set_use_global_pose", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "enable"),
        JS_NewCFunction(ctx, retarget_modifier3d_class_get_enable_flags, "get_enable_flags", 0),
        JS_NewCFunction(ctx, retarget_modifier3d_class_set_enable_flags, "set_enable_flags", 1),
        JS_PROP_GETSET
    );
}

static void define_retarget_modifier3d_enum(JSContext *ctx, JSValue ctor) {
	JSValue TransformFlag_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, TransformFlag_obj, "TRANSFORM_FLAG_POSITION", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, TransformFlag_obj, "TRANSFORM_FLAG_ROTATION", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, TransformFlag_obj, "TRANSFORM_FLAG_SCALE", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, TransformFlag_obj, "TRANSFORM_FLAG_ALL", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, ctor, "TransformFlag", TransformFlag_obj);
}

static int js_retarget_modifier3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["RetargetModifier3D"] = class_id;
	classes_by_id[class_id] = "RetargetModifier3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &retarget_modifier3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["SkeletonModifier3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_retarget_modifier3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, retarget_modifier3d_class_proto_funcs, _countof(retarget_modifier3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, retarget_modifier3d_class_constructor, "RetargetModifier3D", 0, JS_CFUNC_constructor, 0);
	define_retarget_modifier3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "RetargetModifier3D", ctor);

	return 0;
}

JSModuleDef *_js_init_retarget_modifier3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/skeleton_modifier3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_retarget_modifier3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "RetargetModifier3D");
	return m;
}

JSModuleDef *js_init_retarget_modifier3d_module(JSContext *ctx) {
	return _js_init_retarget_modifier3d_module(ctx, "@godot/classes/retarget_modifier3d");
}

void __register_retarget_modifier3d() {
	js_init_retarget_modifier3d_module(js_context());
}

void register_retarget_modifier3d() {
	__register_retarget_modifier3d();
}