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
#include <godot_cpp/classes/skeleton_modification2d_two_bone_ik.hpp>
using namespace godot;

static void skeleton_modification2d_two_bone_ik_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["SkeletonModification2DTwoBoneIK"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef skeleton_modification2d_two_bone_ik_class_def = {
    "SkeletonModification2DTwoBoneIK",
    skeleton_modification2d_two_bone_ik_class_finalizer
};

static JSValue skeleton_modification2d_two_bone_ik_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["SkeletonModification2DTwoBoneIK"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    SkeletonModification2DTwoBoneIK *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<SkeletonModification2DTwoBoneIK *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(SkeletonModification2DTwoBoneIK);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue skeleton_modification2d_two_bone_ik_class_set_target_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModification2DTwoBoneIK::set_target_node, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2d_two_bone_ik_class_get_target_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<NodePath> *proxy = memnew(ObjectProxy<NodePath>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> NodePath {
		SkeletonModification2DTwoBoneIK *obj = static_cast<SkeletonModification2DTwoBoneIK *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_target_node();
	};
	proxy->setter = [this_val](const NodePath &value) -> void {
		SkeletonModification2DTwoBoneIK *js_proxy = static_cast<SkeletonModification2DTwoBoneIK *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_target_node(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["NodePathProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "NodePathProxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue skeleton_modification2d_two_bone_ik_class_set_target_minimum_distance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModification2DTwoBoneIK::set_target_minimum_distance, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2d_two_bone_ik_class_get_target_minimum_distance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonModification2DTwoBoneIK::get_target_minimum_distance, ctx, this_val, argc, argv);
}
static JSValue skeleton_modification2d_two_bone_ik_class_set_target_maximum_distance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModification2DTwoBoneIK::set_target_maximum_distance, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2d_two_bone_ik_class_get_target_maximum_distance(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonModification2DTwoBoneIK::get_target_maximum_distance, ctx, this_val, argc, argv);
}
static JSValue skeleton_modification2d_two_bone_ik_class_set_flip_bend_direction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModification2DTwoBoneIK::set_flip_bend_direction, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2d_two_bone_ik_class_get_flip_bend_direction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonModification2DTwoBoneIK::get_flip_bend_direction, ctx, this_val, argc, argv);
}
static JSValue skeleton_modification2d_two_bone_ik_class_set_joint_one_bone2d_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModification2DTwoBoneIK::set_joint_one_bone2d_node, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2d_two_bone_ik_class_get_joint_one_bone2d_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonModification2DTwoBoneIK::get_joint_one_bone2d_node, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2d_two_bone_ik_class_set_joint_one_bone_idx(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModification2DTwoBoneIK::set_joint_one_bone_idx, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2d_two_bone_ik_class_get_joint_one_bone_idx(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonModification2DTwoBoneIK::get_joint_one_bone_idx, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2d_two_bone_ik_class_set_joint_two_bone2d_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModification2DTwoBoneIK::set_joint_two_bone2d_node, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2d_two_bone_ik_class_get_joint_two_bone2d_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonModification2DTwoBoneIK::get_joint_two_bone2d_node, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2d_two_bone_ik_class_set_joint_two_bone_idx(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModification2DTwoBoneIK::set_joint_two_bone_idx, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2d_two_bone_ik_class_get_joint_two_bone_idx(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonModification2DTwoBoneIK::get_joint_two_bone_idx, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry skeleton_modification2d_two_bone_ik_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_target_node", 1, &skeleton_modification2d_two_bone_ik_class_set_target_node),
	JS_CFUNC_DEF("get_target_node", 0, &skeleton_modification2d_two_bone_ik_class_get_target_node),
	JS_CFUNC_DEF("set_target_minimum_distance", 1, &skeleton_modification2d_two_bone_ik_class_set_target_minimum_distance),
	JS_CFUNC_DEF("get_target_minimum_distance", 0, &skeleton_modification2d_two_bone_ik_class_get_target_minimum_distance),
	JS_CFUNC_DEF("set_target_maximum_distance", 1, &skeleton_modification2d_two_bone_ik_class_set_target_maximum_distance),
	JS_CFUNC_DEF("get_target_maximum_distance", 0, &skeleton_modification2d_two_bone_ik_class_get_target_maximum_distance),
	JS_CFUNC_DEF("set_flip_bend_direction", 1, &skeleton_modification2d_two_bone_ik_class_set_flip_bend_direction),
	JS_CFUNC_DEF("get_flip_bend_direction", 0, &skeleton_modification2d_two_bone_ik_class_get_flip_bend_direction),
	JS_CFUNC_DEF("set_joint_one_bone2d_node", 1, &skeleton_modification2d_two_bone_ik_class_set_joint_one_bone2d_node),
	JS_CFUNC_DEF("get_joint_one_bone2d_node", 0, &skeleton_modification2d_two_bone_ik_class_get_joint_one_bone2d_node),
	JS_CFUNC_DEF("set_joint_one_bone_idx", 1, &skeleton_modification2d_two_bone_ik_class_set_joint_one_bone_idx),
	JS_CFUNC_DEF("get_joint_one_bone_idx", 0, &skeleton_modification2d_two_bone_ik_class_get_joint_one_bone_idx),
	JS_CFUNC_DEF("set_joint_two_bone2d_node", 1, &skeleton_modification2d_two_bone_ik_class_set_joint_two_bone2d_node),
	JS_CFUNC_DEF("get_joint_two_bone2d_node", 0, &skeleton_modification2d_two_bone_ik_class_get_joint_two_bone2d_node),
	JS_CFUNC_DEF("set_joint_two_bone_idx", 1, &skeleton_modification2d_two_bone_ik_class_set_joint_two_bone_idx),
	JS_CFUNC_DEF("get_joint_two_bone_idx", 0, &skeleton_modification2d_two_bone_ik_class_get_joint_two_bone_idx),
};




static void define_skeleton_modification2d_two_bone_ik_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "target_nodepath"),
        JS_NewCFunction(ctx, skeleton_modification2d_two_bone_ik_class_get_target_node, "get_target_node", 0),
        JS_NewCFunction(ctx, skeleton_modification2d_two_bone_ik_class_set_target_node, "set_target_node", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "target_minimum_distance"),
        JS_NewCFunction(ctx, skeleton_modification2d_two_bone_ik_class_get_target_minimum_distance, "get_target_minimum_distance", 0),
        JS_NewCFunction(ctx, skeleton_modification2d_two_bone_ik_class_set_target_minimum_distance, "set_target_minimum_distance", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "target_maximum_distance"),
        JS_NewCFunction(ctx, skeleton_modification2d_two_bone_ik_class_get_target_maximum_distance, "get_target_maximum_distance", 0),
        JS_NewCFunction(ctx, skeleton_modification2d_two_bone_ik_class_set_target_maximum_distance, "set_target_maximum_distance", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "flip_bend_direction"),
        JS_NewCFunction(ctx, skeleton_modification2d_two_bone_ik_class_get_flip_bend_direction, "get_flip_bend_direction", 0),
        JS_NewCFunction(ctx, skeleton_modification2d_two_bone_ik_class_set_flip_bend_direction, "set_flip_bend_direction", 1),
        JS_PROP_GETSET
    );
}

static void define_skeleton_modification2d_two_bone_ik_enum(JSContext *ctx, JSValue proto) {
}

static int js_skeleton_modification2d_two_bone_ik_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["SkeletonModification2DTwoBoneIK"] = class_id;
	classes_by_id[class_id] = "SkeletonModification2DTwoBoneIK";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &skeleton_modification2d_two_bone_ik_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["SkeletonModification2D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_skeleton_modification2d_two_bone_ik_property(ctx, proto);
	define_skeleton_modification2d_two_bone_ik_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, skeleton_modification2d_two_bone_ik_class_proto_funcs, _countof(skeleton_modification2d_two_bone_ik_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, skeleton_modification2d_two_bone_ik_class_constructor, "SkeletonModification2DTwoBoneIK", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "SkeletonModification2DTwoBoneIK", ctor);

	return 0;
}

JSModuleDef *_js_init_skeleton_modification2d_two_bone_ik_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/skeleton_modification2d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_skeleton_modification2d_two_bone_ik_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "SkeletonModification2DTwoBoneIK");
	return m;
}

JSModuleDef *js_init_skeleton_modification2d_two_bone_ik_module(JSContext *ctx) {
	return _js_init_skeleton_modification2d_two_bone_ik_module(ctx, "@godot/classes/skeleton_modification2d_two_bone_ik");
}

void __register_skeleton_modification2d_two_bone_ik() {
	js_init_skeleton_modification2d_two_bone_ik_module(js_context());
}

void register_skeleton_modification2d_two_bone_ik() {
	__register_skeleton_modification2d_two_bone_ik();
}