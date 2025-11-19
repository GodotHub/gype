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
#include <godot_cpp/classes/convert_transform_modifier3d.hpp>
using namespace godot;

static void convert_transform_modifier3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["ConvertTransformModifier3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef convert_transform_modifier3d_class_def = {
    "ConvertTransformModifier3D",
    convert_transform_modifier3d_class_finalizer
};

static JSValue convert_transform_modifier3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["ConvertTransformModifier3D"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    ConvertTransformModifier3D *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<ConvertTransformModifier3D *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(ConvertTransformModifier3D);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue convert_transform_modifier3d_class_set_apply_transform_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ConvertTransformModifier3D::set_apply_transform_mode, ctx, this_val, argc, argv);
};
static JSValue convert_transform_modifier3d_class_get_apply_transform_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ConvertTransformModifier3D::get_apply_transform_mode, ctx, this_val, argc, argv);
};
static JSValue convert_transform_modifier3d_class_set_apply_axis(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ConvertTransformModifier3D::set_apply_axis, ctx, this_val, argc, argv);
};
static JSValue convert_transform_modifier3d_class_get_apply_axis(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ConvertTransformModifier3D::get_apply_axis, ctx, this_val, argc, argv);
};
static JSValue convert_transform_modifier3d_class_set_apply_range_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ConvertTransformModifier3D::set_apply_range_min, ctx, this_val, argc, argv);
};
static JSValue convert_transform_modifier3d_class_get_apply_range_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ConvertTransformModifier3D::get_apply_range_min, ctx, this_val, argc, argv);
};
static JSValue convert_transform_modifier3d_class_set_apply_range_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ConvertTransformModifier3D::set_apply_range_max, ctx, this_val, argc, argv);
};
static JSValue convert_transform_modifier3d_class_get_apply_range_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ConvertTransformModifier3D::get_apply_range_max, ctx, this_val, argc, argv);
};
static JSValue convert_transform_modifier3d_class_set_reference_transform_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ConvertTransformModifier3D::set_reference_transform_mode, ctx, this_val, argc, argv);
};
static JSValue convert_transform_modifier3d_class_get_reference_transform_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ConvertTransformModifier3D::get_reference_transform_mode, ctx, this_val, argc, argv);
};
static JSValue convert_transform_modifier3d_class_set_reference_axis(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ConvertTransformModifier3D::set_reference_axis, ctx, this_val, argc, argv);
};
static JSValue convert_transform_modifier3d_class_get_reference_axis(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ConvertTransformModifier3D::get_reference_axis, ctx, this_val, argc, argv);
};
static JSValue convert_transform_modifier3d_class_set_reference_range_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ConvertTransformModifier3D::set_reference_range_min, ctx, this_val, argc, argv);
};
static JSValue convert_transform_modifier3d_class_get_reference_range_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ConvertTransformModifier3D::get_reference_range_min, ctx, this_val, argc, argv);
};
static JSValue convert_transform_modifier3d_class_set_reference_range_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ConvertTransformModifier3D::set_reference_range_max, ctx, this_val, argc, argv);
};
static JSValue convert_transform_modifier3d_class_get_reference_range_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ConvertTransformModifier3D::get_reference_range_max, ctx, this_val, argc, argv);
};
static JSValue convert_transform_modifier3d_class_set_relative(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ConvertTransformModifier3D::set_relative, ctx, this_val, argc, argv);
};
static JSValue convert_transform_modifier3d_class_is_relative(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ConvertTransformModifier3D::is_relative, ctx, this_val, argc, argv);
};
static JSValue convert_transform_modifier3d_class_set_additive(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&ConvertTransformModifier3D::set_additive, ctx, this_val, argc, argv);
};
static JSValue convert_transform_modifier3d_class_is_additive(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&ConvertTransformModifier3D::is_additive, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry convert_transform_modifier3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_apply_transform_mode", 2, &convert_transform_modifier3d_class_set_apply_transform_mode),
	JS_CFUNC_DEF("get_apply_transform_mode", 1, &convert_transform_modifier3d_class_get_apply_transform_mode),
	JS_CFUNC_DEF("set_apply_axis", 2, &convert_transform_modifier3d_class_set_apply_axis),
	JS_CFUNC_DEF("get_apply_axis", 1, &convert_transform_modifier3d_class_get_apply_axis),
	JS_CFUNC_DEF("set_apply_range_min", 2, &convert_transform_modifier3d_class_set_apply_range_min),
	JS_CFUNC_DEF("get_apply_range_min", 1, &convert_transform_modifier3d_class_get_apply_range_min),
	JS_CFUNC_DEF("set_apply_range_max", 2, &convert_transform_modifier3d_class_set_apply_range_max),
	JS_CFUNC_DEF("get_apply_range_max", 1, &convert_transform_modifier3d_class_get_apply_range_max),
	JS_CFUNC_DEF("set_reference_transform_mode", 2, &convert_transform_modifier3d_class_set_reference_transform_mode),
	JS_CFUNC_DEF("get_reference_transform_mode", 1, &convert_transform_modifier3d_class_get_reference_transform_mode),
	JS_CFUNC_DEF("set_reference_axis", 2, &convert_transform_modifier3d_class_set_reference_axis),
	JS_CFUNC_DEF("get_reference_axis", 1, &convert_transform_modifier3d_class_get_reference_axis),
	JS_CFUNC_DEF("set_reference_range_min", 2, &convert_transform_modifier3d_class_set_reference_range_min),
	JS_CFUNC_DEF("get_reference_range_min", 1, &convert_transform_modifier3d_class_get_reference_range_min),
	JS_CFUNC_DEF("set_reference_range_max", 2, &convert_transform_modifier3d_class_set_reference_range_max),
	JS_CFUNC_DEF("get_reference_range_max", 1, &convert_transform_modifier3d_class_get_reference_range_max),
	JS_CFUNC_DEF("set_relative", 2, &convert_transform_modifier3d_class_set_relative),
	JS_CFUNC_DEF("is_relative", 1, &convert_transform_modifier3d_class_is_relative),
	JS_CFUNC_DEF("set_additive", 2, &convert_transform_modifier3d_class_set_additive),
	JS_CFUNC_DEF("is_additive", 1, &convert_transform_modifier3d_class_is_additive),
};




static void define_convert_transform_modifier3d_property(JSContext *ctx, JSValue proto) {
}

static void define_convert_transform_modifier3d_enum(JSContext *ctx, JSValue ctor) {
	JSValue TransformMode_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, TransformMode_obj, "TRANSFORM_MODE_POSITION", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, TransformMode_obj, "TRANSFORM_MODE_ROTATION", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, TransformMode_obj, "TRANSFORM_MODE_SCALE", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "TransformMode", TransformMode_obj);
}

static int js_convert_transform_modifier3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["ConvertTransformModifier3D"] = class_id;
	classes_by_id[class_id] = "ConvertTransformModifier3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &convert_transform_modifier3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["BoneConstraint3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_convert_transform_modifier3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, convert_transform_modifier3d_class_proto_funcs, _countof(convert_transform_modifier3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, convert_transform_modifier3d_class_constructor, "ConvertTransformModifier3D", 0, JS_CFUNC_constructor, 0);
	define_convert_transform_modifier3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "ConvertTransformModifier3D", ctor);

	return 0;
}

JSModuleDef *_js_init_convert_transform_modifier3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/bone_constraint3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_convert_transform_modifier3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "ConvertTransformModifier3D");
	return m;
}

JSModuleDef *js_init_convert_transform_modifier3d_module(JSContext *ctx) {
	return _js_init_convert_transform_modifier3d_module(ctx, "@godot/classes/convert_transform_modifier3d");
}

void __register_convert_transform_modifier3d() {
	js_init_convert_transform_modifier3d_module(js_context());
}

void register_convert_transform_modifier3d() {
	__register_convert_transform_modifier3d();
}