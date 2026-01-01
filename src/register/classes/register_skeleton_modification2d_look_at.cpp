#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/skeleton_modification2d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/skeleton_modification2d_look_at.hpp>
using namespace godot;

static void skeleton_modification2d_look_at_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["SkeletonModification2DLookAt"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
		memdelete(opaque_ptr);
	}
}

static JSClassDef skeleton_modification2d_look_at_class_def = {
    "SkeletonModification2DLookAt",
    skeleton_modification2d_look_at_class_finalizer
};

static JSValue skeleton_modification2d_look_at_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["SkeletonModification2DLookAt"];
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
        instance = memnew(SkeletonModification2DLookAt);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue skeleton_modification2d_look_at_class_set_bone2d_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModification2DLookAt::set_bone2d_node, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2d_look_at_class_get_bone2d_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonModification2DLookAt::get_bone2d_node, ctx, this_val, argc, argv);
}
static JSValue skeleton_modification2d_look_at_class_set_bone_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModification2DLookAt::set_bone_index, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2d_look_at_class_get_bone_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonModification2DLookAt::get_bone_index, ctx, this_val, argc, argv);
}
static JSValue skeleton_modification2d_look_at_class_set_target_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModification2DLookAt::set_target_node, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2d_look_at_class_get_target_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonModification2DLookAt::get_target_node, ctx, this_val, argc, argv);
}
static JSValue skeleton_modification2d_look_at_class_set_additional_rotation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModification2DLookAt::set_additional_rotation, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2d_look_at_class_get_additional_rotation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonModification2DLookAt::get_additional_rotation, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2d_look_at_class_set_enable_constraint(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModification2DLookAt::set_enable_constraint, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2d_look_at_class_get_enable_constraint(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonModification2DLookAt::get_enable_constraint, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2d_look_at_class_set_constraint_angle_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModification2DLookAt::set_constraint_angle_min, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2d_look_at_class_get_constraint_angle_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonModification2DLookAt::get_constraint_angle_min, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2d_look_at_class_set_constraint_angle_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModification2DLookAt::set_constraint_angle_max, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2d_look_at_class_get_constraint_angle_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonModification2DLookAt::get_constraint_angle_max, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2d_look_at_class_set_constraint_angle_invert(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModification2DLookAt::set_constraint_angle_invert, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2d_look_at_class_get_constraint_angle_invert(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonModification2DLookAt::get_constraint_angle_invert, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry skeleton_modification2d_look_at_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_bone2d_node", 1, &skeleton_modification2d_look_at_class_set_bone2d_node),
	JS_CFUNC_DEF("get_bone2d_node", 0, &skeleton_modification2d_look_at_class_get_bone2d_node),
	JS_CFUNC_DEF("set_bone_index", 1, &skeleton_modification2d_look_at_class_set_bone_index),
	JS_CFUNC_DEF("get_bone_index", 0, &skeleton_modification2d_look_at_class_get_bone_index),
	JS_CFUNC_DEF("set_target_node", 1, &skeleton_modification2d_look_at_class_set_target_node),
	JS_CFUNC_DEF("get_target_node", 0, &skeleton_modification2d_look_at_class_get_target_node),
	JS_CFUNC_DEF("set_additional_rotation", 1, &skeleton_modification2d_look_at_class_set_additional_rotation),
	JS_CFUNC_DEF("get_additional_rotation", 0, &skeleton_modification2d_look_at_class_get_additional_rotation),
	JS_CFUNC_DEF("set_enable_constraint", 1, &skeleton_modification2d_look_at_class_set_enable_constraint),
	JS_CFUNC_DEF("get_enable_constraint", 0, &skeleton_modification2d_look_at_class_get_enable_constraint),
	JS_CFUNC_DEF("set_constraint_angle_min", 1, &skeleton_modification2d_look_at_class_set_constraint_angle_min),
	JS_CFUNC_DEF("get_constraint_angle_min", 0, &skeleton_modification2d_look_at_class_get_constraint_angle_min),
	JS_CFUNC_DEF("set_constraint_angle_max", 1, &skeleton_modification2d_look_at_class_set_constraint_angle_max),
	JS_CFUNC_DEF("get_constraint_angle_max", 0, &skeleton_modification2d_look_at_class_get_constraint_angle_max),
	JS_CFUNC_DEF("set_constraint_angle_invert", 1, &skeleton_modification2d_look_at_class_set_constraint_angle_invert),
	JS_CFUNC_DEF("get_constraint_angle_invert", 0, &skeleton_modification2d_look_at_class_get_constraint_angle_invert),
};




static void define_skeleton_modification2d_look_at_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "bone_index"),
        JS_NewCFunction(ctx, skeleton_modification2d_look_at_class_get_bone_index, "get_bone_index", 0),
        JS_NewCFunction(ctx, skeleton_modification2d_look_at_class_set_bone_index, "set_bone_index", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "bone2d_node"),
        JS_NewCFunction(ctx, skeleton_modification2d_look_at_class_get_bone2d_node, "get_bone2d_node", 0),
        JS_NewCFunction(ctx, skeleton_modification2d_look_at_class_set_bone2d_node, "set_bone2d_node", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "target_nodepath"),
        JS_NewCFunction(ctx, skeleton_modification2d_look_at_class_get_target_node, "get_target_node", 0),
        JS_NewCFunction(ctx, skeleton_modification2d_look_at_class_set_target_node, "set_target_node", 1),
        JS_PROP_GETSET
    );
}

static void define_skeleton_modification2d_look_at_enum(JSContext *ctx, JSValue ctor) {
}

static int js_skeleton_modification2d_look_at_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["SkeletonModification2DLookAt"] = class_id;
	classes_by_id[class_id] = "SkeletonModification2DLookAt";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &skeleton_modification2d_look_at_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["SkeletonModification2D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_skeleton_modification2d_look_at_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, skeleton_modification2d_look_at_class_proto_funcs, _countof(skeleton_modification2d_look_at_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, skeleton_modification2d_look_at_class_constructor, "SkeletonModification2DLookAt", 0, JS_CFUNC_constructor, 0);
	define_skeleton_modification2d_look_at_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "SkeletonModification2DLookAt", ctor);
	ctor_list["SkeletonModification2DLookAt"] = ctor;

	return 0;
}

JSModuleDef *_js_init_skeleton_modification2d_look_at_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/skeleton_modification2d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_skeleton_modification2d_look_at_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "SkeletonModification2DLookAt");
	return m;
}

JSModuleDef *js_init_skeleton_modification2d_look_at_module(JSContext *ctx) {
	return _js_init_skeleton_modification2d_look_at_module(ctx, "@godot/classes/skeleton_modification2d_look_at");
}

void __register_skeleton_modification2d_look_at() {
	js_init_skeleton_modification2d_look_at_module(js_context());
}

void register_skeleton_modification2d_look_at() {
	__register_skeleton_modification2d_look_at();
}