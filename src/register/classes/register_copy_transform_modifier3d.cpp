#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/bone_constraint3d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/copy_transform_modifier3d.hpp>
using namespace godot;

static void copy_transform_modifier3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["CopyTransformModifier3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef copy_transform_modifier3d_class_def = {
    "CopyTransformModifier3D",
    copy_transform_modifier3d_class_finalizer
};

static JSValue copy_transform_modifier3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["CopyTransformModifier3D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    CopyTransformModifier3D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<CopyTransformModifier3D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(CopyTransformModifier3D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue copy_transform_modifier3d_class_set_copy_flags(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CopyTransformModifier3D::set_copy_flags, ctx, this_val, argc, argv);
};
static JSValue copy_transform_modifier3d_class_get_copy_flags(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CopyTransformModifier3D::get_copy_flags, ctx, this_val, argc, argv);
};
static JSValue copy_transform_modifier3d_class_set_axis_flags(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CopyTransformModifier3D::set_axis_flags, ctx, this_val, argc, argv);
};
static JSValue copy_transform_modifier3d_class_get_axis_flags(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CopyTransformModifier3D::get_axis_flags, ctx, this_val, argc, argv);
};
static JSValue copy_transform_modifier3d_class_set_invert_flags(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CopyTransformModifier3D::set_invert_flags, ctx, this_val, argc, argv);
};
static JSValue copy_transform_modifier3d_class_get_invert_flags(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CopyTransformModifier3D::get_invert_flags, ctx, this_val, argc, argv);
};
static JSValue copy_transform_modifier3d_class_set_copy_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CopyTransformModifier3D::set_copy_position, ctx, this_val, argc, argv);
};
static JSValue copy_transform_modifier3d_class_is_position_copying(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CopyTransformModifier3D::is_position_copying, ctx, this_val, argc, argv);
};
static JSValue copy_transform_modifier3d_class_set_copy_rotation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CopyTransformModifier3D::set_copy_rotation, ctx, this_val, argc, argv);
};
static JSValue copy_transform_modifier3d_class_is_rotation_copying(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CopyTransformModifier3D::is_rotation_copying, ctx, this_val, argc, argv);
};
static JSValue copy_transform_modifier3d_class_set_copy_scale(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CopyTransformModifier3D::set_copy_scale, ctx, this_val, argc, argv);
};
static JSValue copy_transform_modifier3d_class_is_scale_copying(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CopyTransformModifier3D::is_scale_copying, ctx, this_val, argc, argv);
};
static JSValue copy_transform_modifier3d_class_set_axis_x_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CopyTransformModifier3D::set_axis_x_enabled, ctx, this_val, argc, argv);
};
static JSValue copy_transform_modifier3d_class_is_axis_x_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CopyTransformModifier3D::is_axis_x_enabled, ctx, this_val, argc, argv);
};
static JSValue copy_transform_modifier3d_class_set_axis_y_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CopyTransformModifier3D::set_axis_y_enabled, ctx, this_val, argc, argv);
};
static JSValue copy_transform_modifier3d_class_is_axis_y_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CopyTransformModifier3D::is_axis_y_enabled, ctx, this_val, argc, argv);
};
static JSValue copy_transform_modifier3d_class_set_axis_z_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CopyTransformModifier3D::set_axis_z_enabled, ctx, this_val, argc, argv);
};
static JSValue copy_transform_modifier3d_class_is_axis_z_enabled(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CopyTransformModifier3D::is_axis_z_enabled, ctx, this_val, argc, argv);
};
static JSValue copy_transform_modifier3d_class_set_axis_x_inverted(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CopyTransformModifier3D::set_axis_x_inverted, ctx, this_val, argc, argv);
};
static JSValue copy_transform_modifier3d_class_is_axis_x_inverted(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CopyTransformModifier3D::is_axis_x_inverted, ctx, this_val, argc, argv);
};
static JSValue copy_transform_modifier3d_class_set_axis_y_inverted(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CopyTransformModifier3D::set_axis_y_inverted, ctx, this_val, argc, argv);
};
static JSValue copy_transform_modifier3d_class_is_axis_y_inverted(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CopyTransformModifier3D::is_axis_y_inverted, ctx, this_val, argc, argv);
};
static JSValue copy_transform_modifier3d_class_set_axis_z_inverted(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CopyTransformModifier3D::set_axis_z_inverted, ctx, this_val, argc, argv);
};
static JSValue copy_transform_modifier3d_class_is_axis_z_inverted(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CopyTransformModifier3D::is_axis_z_inverted, ctx, this_val, argc, argv);
};
static JSValue copy_transform_modifier3d_class_set_relative(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CopyTransformModifier3D::set_relative, ctx, this_val, argc, argv);
};
static JSValue copy_transform_modifier3d_class_is_relative(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CopyTransformModifier3D::is_relative, ctx, this_val, argc, argv);
};
static JSValue copy_transform_modifier3d_class_set_additive(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&CopyTransformModifier3D::set_additive, ctx, this_val, argc, argv);
};
static JSValue copy_transform_modifier3d_class_is_additive(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&CopyTransformModifier3D::is_additive, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry copy_transform_modifier3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_copy_flags", 2, &copy_transform_modifier3d_class_set_copy_flags),
	JS_CFUNC_DEF("get_copy_flags", 1, &copy_transform_modifier3d_class_get_copy_flags),
	JS_CFUNC_DEF("set_axis_flags", 2, &copy_transform_modifier3d_class_set_axis_flags),
	JS_CFUNC_DEF("get_axis_flags", 1, &copy_transform_modifier3d_class_get_axis_flags),
	JS_CFUNC_DEF("set_invert_flags", 2, &copy_transform_modifier3d_class_set_invert_flags),
	JS_CFUNC_DEF("get_invert_flags", 1, &copy_transform_modifier3d_class_get_invert_flags),
	JS_CFUNC_DEF("set_copy_position", 2, &copy_transform_modifier3d_class_set_copy_position),
	JS_CFUNC_DEF("is_position_copying", 1, &copy_transform_modifier3d_class_is_position_copying),
	JS_CFUNC_DEF("set_copy_rotation", 2, &copy_transform_modifier3d_class_set_copy_rotation),
	JS_CFUNC_DEF("is_rotation_copying", 1, &copy_transform_modifier3d_class_is_rotation_copying),
	JS_CFUNC_DEF("set_copy_scale", 2, &copy_transform_modifier3d_class_set_copy_scale),
	JS_CFUNC_DEF("is_scale_copying", 1, &copy_transform_modifier3d_class_is_scale_copying),
	JS_CFUNC_DEF("set_axis_x_enabled", 2, &copy_transform_modifier3d_class_set_axis_x_enabled),
	JS_CFUNC_DEF("is_axis_x_enabled", 1, &copy_transform_modifier3d_class_is_axis_x_enabled),
	JS_CFUNC_DEF("set_axis_y_enabled", 2, &copy_transform_modifier3d_class_set_axis_y_enabled),
	JS_CFUNC_DEF("is_axis_y_enabled", 1, &copy_transform_modifier3d_class_is_axis_y_enabled),
	JS_CFUNC_DEF("set_axis_z_enabled", 2, &copy_transform_modifier3d_class_set_axis_z_enabled),
	JS_CFUNC_DEF("is_axis_z_enabled", 1, &copy_transform_modifier3d_class_is_axis_z_enabled),
	JS_CFUNC_DEF("set_axis_x_inverted", 2, &copy_transform_modifier3d_class_set_axis_x_inverted),
	JS_CFUNC_DEF("is_axis_x_inverted", 1, &copy_transform_modifier3d_class_is_axis_x_inverted),
	JS_CFUNC_DEF("set_axis_y_inverted", 2, &copy_transform_modifier3d_class_set_axis_y_inverted),
	JS_CFUNC_DEF("is_axis_y_inverted", 1, &copy_transform_modifier3d_class_is_axis_y_inverted),
	JS_CFUNC_DEF("set_axis_z_inverted", 2, &copy_transform_modifier3d_class_set_axis_z_inverted),
	JS_CFUNC_DEF("is_axis_z_inverted", 1, &copy_transform_modifier3d_class_is_axis_z_inverted),
	JS_CFUNC_DEF("set_relative", 2, &copy_transform_modifier3d_class_set_relative),
	JS_CFUNC_DEF("is_relative", 1, &copy_transform_modifier3d_class_is_relative),
	JS_CFUNC_DEF("set_additive", 2, &copy_transform_modifier3d_class_set_additive),
	JS_CFUNC_DEF("is_additive", 1, &copy_transform_modifier3d_class_is_additive),
};




static void define_copy_transform_modifier3d_property(JSContext *ctx, JSValue proto) {
}

static void define_copy_transform_modifier3d_enum(JSContext *ctx, JSValue ctor) {
	JSValue TransformFlag_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, TransformFlag_obj, "TRANSFORM_FLAG_POSITION", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, TransformFlag_obj, "TRANSFORM_FLAG_ROTATION", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, TransformFlag_obj, "TRANSFORM_FLAG_SCALE", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, TransformFlag_obj, "TRANSFORM_FLAG_ALL", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, ctor, "TransformFlag", TransformFlag_obj);
	JSValue AxisFlag_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, AxisFlag_obj, "AXIS_FLAG_X", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, AxisFlag_obj, "AXIS_FLAG_Y", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, AxisFlag_obj, "AXIS_FLAG_Z", JS_NewInt64(ctx, 4));
	JS_SetPropertyStr(ctx, AxisFlag_obj, "AXIS_FLAG_ALL", JS_NewInt64(ctx, 7));
	JS_SetPropertyStr(ctx, ctor, "AxisFlag", AxisFlag_obj);
}

static int js_copy_transform_modifier3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["CopyTransformModifier3D"] = class_id;
	classes_by_id[class_id] = "CopyTransformModifier3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &copy_transform_modifier3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["BoneConstraint3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_copy_transform_modifier3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, copy_transform_modifier3d_class_proto_funcs, _countof(copy_transform_modifier3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, copy_transform_modifier3d_class_constructor, "CopyTransformModifier3D", 0, JS_CFUNC_constructor, 0);
	define_copy_transform_modifier3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "CopyTransformModifier3D", ctor);

	return 0;
}

JSModuleDef *_js_init_copy_transform_modifier3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/bone_constraint3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_copy_transform_modifier3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "CopyTransformModifier3D");
	return m;
}

JSModuleDef *js_init_copy_transform_modifier3d_module(JSContext *ctx) {
	return _js_init_copy_transform_modifier3d_module(ctx, "@godot/classes/copy_transform_modifier3d");
}

void __register_copy_transform_modifier3d() {
	js_init_copy_transform_modifier3d_module(js_context());
}

void register_copy_transform_modifier3d() {
	__register_copy_transform_modifier3d();
}