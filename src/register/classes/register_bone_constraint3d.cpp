#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/skeleton_modifier3d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/bone_constraint3d.hpp>
using namespace godot;

static void bone_constraint3d_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["BoneConstraint3D"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef bone_constraint3d_class_def = {
    "BoneConstraint3D",
    bone_constraint3d_class_finalizer
};

static JSValue bone_constraint3d_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["BoneConstraint3D"];
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
        instance = memnew(BoneConstraint3D);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue bone_constraint3d_class_set_amount(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BoneConstraint3D::set_amount, ctx, this_val, argc, argv);
};
static JSValue bone_constraint3d_class_get_amount(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BoneConstraint3D::get_amount, ctx, this_val, argc, argv);
};
static JSValue bone_constraint3d_class_set_apply_bone_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BoneConstraint3D::set_apply_bone_name, ctx, this_val, argc, argv);
};
static JSValue bone_constraint3d_class_get_apply_bone_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BoneConstraint3D::get_apply_bone_name, ctx, this_val, argc, argv);
};
static JSValue bone_constraint3d_class_set_apply_bone(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BoneConstraint3D::set_apply_bone, ctx, this_val, argc, argv);
};
static JSValue bone_constraint3d_class_get_apply_bone(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BoneConstraint3D::get_apply_bone, ctx, this_val, argc, argv);
};
static JSValue bone_constraint3d_class_set_reference_bone_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BoneConstraint3D::set_reference_bone_name, ctx, this_val, argc, argv);
};
static JSValue bone_constraint3d_class_get_reference_bone_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BoneConstraint3D::get_reference_bone_name, ctx, this_val, argc, argv);
};
static JSValue bone_constraint3d_class_set_reference_bone(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BoneConstraint3D::set_reference_bone, ctx, this_val, argc, argv);
};
static JSValue bone_constraint3d_class_get_reference_bone(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BoneConstraint3D::get_reference_bone, ctx, this_val, argc, argv);
};
static JSValue bone_constraint3d_class_set_setting_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BoneConstraint3D::set_setting_count, ctx, this_val, argc, argv);
};
static JSValue bone_constraint3d_class_get_setting_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&BoneConstraint3D::get_setting_count, ctx, this_val, argc, argv);
};
static JSValue bone_constraint3d_class_clear_setting(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&BoneConstraint3D::clear_setting, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry bone_constraint3d_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_amount", 2, &bone_constraint3d_class_set_amount),
	JS_CFUNC_DEF("get_amount", 1, &bone_constraint3d_class_get_amount),
	JS_CFUNC_DEF("set_apply_bone_name", 2, &bone_constraint3d_class_set_apply_bone_name),
	JS_CFUNC_DEF("get_apply_bone_name", 1, &bone_constraint3d_class_get_apply_bone_name),
	JS_CFUNC_DEF("set_apply_bone", 2, &bone_constraint3d_class_set_apply_bone),
	JS_CFUNC_DEF("get_apply_bone", 1, &bone_constraint3d_class_get_apply_bone),
	JS_CFUNC_DEF("set_reference_bone_name", 2, &bone_constraint3d_class_set_reference_bone_name),
	JS_CFUNC_DEF("get_reference_bone_name", 1, &bone_constraint3d_class_get_reference_bone_name),
	JS_CFUNC_DEF("set_reference_bone", 2, &bone_constraint3d_class_set_reference_bone),
	JS_CFUNC_DEF("get_reference_bone", 1, &bone_constraint3d_class_get_reference_bone),
	JS_CFUNC_DEF("set_setting_count", 1, &bone_constraint3d_class_set_setting_count),
	JS_CFUNC_DEF("get_setting_count", 0, &bone_constraint3d_class_get_setting_count),
	JS_CFUNC_DEF("clear_setting", 0, &bone_constraint3d_class_clear_setting),
};




static void define_bone_constraint3d_property(JSContext *ctx, JSValue proto) {
}

static void define_bone_constraint3d_enum(JSContext *ctx, JSValue ctor) {
}

static int js_bone_constraint3d_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["BoneConstraint3D"] = class_id;
	classes_by_id[class_id] = "BoneConstraint3D";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &bone_constraint3d_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["SkeletonModifier3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_bone_constraint3d_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, bone_constraint3d_class_proto_funcs, _countof(bone_constraint3d_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, bone_constraint3d_class_constructor, "BoneConstraint3D", 0, JS_CFUNC_constructor, 0);
	define_bone_constraint3d_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "BoneConstraint3D", ctor);
	ctor_list["BoneConstraint3D"] = ctor;

	return 0;
}

JSModuleDef *_js_init_bone_constraint3d_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/skeleton_modifier3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_bone_constraint3d_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "BoneConstraint3D");
	return m;
}

JSModuleDef *js_init_bone_constraint3d_module(JSContext *ctx) {
	return _js_init_bone_constraint3d_module(ctx, "@godot/classes/bone_constraint3d");
}

void __register_bone_constraint3d() {
	js_init_bone_constraint3d_module(js_context());
}

void register_bone_constraint3d() {
	__register_bone_constraint3d();
}