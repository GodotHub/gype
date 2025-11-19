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
#include <godot_cpp/classes/skeleton_modification2dccdik.hpp>
using namespace godot;

static void skeleton_modification2dccdik_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["SkeletonModification2DCCDIK"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
		static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
	}
}

static JSClassDef skeleton_modification2dccdik_class_def = {
    "SkeletonModification2DCCDIK",
    skeleton_modification2dccdik_class_finalizer
};

static JSValue skeleton_modification2dccdik_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["SkeletonModification2DCCDIK"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    SkeletonModification2DCCDIK *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<SkeletonModification2DCCDIK *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(SkeletonModification2DCCDIK);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue skeleton_modification2dccdik_class_set_target_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModification2DCCDIK::set_target_node, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2dccdik_class_get_target_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<NodePath> *proxy = memnew(ObjectProxy<NodePath>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> NodePath {
		SkeletonModification2DCCDIK *obj = static_cast<SkeletonModification2DCCDIK *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_target_node();
	};
	proxy->setter = [this_val](const NodePath &value) -> void {
		SkeletonModification2DCCDIK *js_proxy = static_cast<SkeletonModification2DCCDIK *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_target_node(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["NodePathProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "NodePathProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue skeleton_modification2dccdik_class_set_tip_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModification2DCCDIK::set_tip_node, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2dccdik_class_get_tip_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<NodePath> *proxy = memnew(ObjectProxy<NodePath>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> NodePath {
		SkeletonModification2DCCDIK *obj = static_cast<SkeletonModification2DCCDIK *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_tip_node();
	};
	proxy->setter = [this_val](const NodePath &value) -> void {
		SkeletonModification2DCCDIK *js_proxy = static_cast<SkeletonModification2DCCDIK *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_tip_node(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["NodePathProxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "NodePathProxy");
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &obj);
    return js_proxy;
}
static JSValue skeleton_modification2dccdik_class_set_ccdik_data_chain_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModification2DCCDIK::set_ccdik_data_chain_length, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2dccdik_class_get_ccdik_data_chain_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&SkeletonModification2DCCDIK::get_ccdik_data_chain_length, ctx, this_val, argc, argv);
}
static JSValue skeleton_modification2dccdik_class_set_ccdik_joint_bone2d_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModification2DCCDIK::set_ccdik_joint_bone2d_node, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2dccdik_class_get_ccdik_joint_bone2d_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonModification2DCCDIK::get_ccdik_joint_bone2d_node, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2dccdik_class_set_ccdik_joint_bone_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModification2DCCDIK::set_ccdik_joint_bone_index, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2dccdik_class_get_ccdik_joint_bone_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonModification2DCCDIK::get_ccdik_joint_bone_index, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2dccdik_class_set_ccdik_joint_rotate_from_joint(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModification2DCCDIK::set_ccdik_joint_rotate_from_joint, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2dccdik_class_get_ccdik_joint_rotate_from_joint(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonModification2DCCDIK::get_ccdik_joint_rotate_from_joint, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2dccdik_class_set_ccdik_joint_enable_constraint(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModification2DCCDIK::set_ccdik_joint_enable_constraint, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2dccdik_class_get_ccdik_joint_enable_constraint(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonModification2DCCDIK::get_ccdik_joint_enable_constraint, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2dccdik_class_set_ccdik_joint_constraint_angle_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModification2DCCDIK::set_ccdik_joint_constraint_angle_min, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2dccdik_class_get_ccdik_joint_constraint_angle_min(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonModification2DCCDIK::get_ccdik_joint_constraint_angle_min, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2dccdik_class_set_ccdik_joint_constraint_angle_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModification2DCCDIK::set_ccdik_joint_constraint_angle_max, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2dccdik_class_get_ccdik_joint_constraint_angle_max(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonModification2DCCDIK::get_ccdik_joint_constraint_angle_max, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2dccdik_class_set_ccdik_joint_constraint_angle_invert(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModification2DCCDIK::set_ccdik_joint_constraint_angle_invert, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2dccdik_class_get_ccdik_joint_constraint_angle_invert(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonModification2DCCDIK::get_ccdik_joint_constraint_angle_invert, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry skeleton_modification2dccdik_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_target_node", 1, &skeleton_modification2dccdik_class_set_target_node),
	JS_CFUNC_DEF("get_target_node", 0, &skeleton_modification2dccdik_class_get_target_node),
	JS_CFUNC_DEF("set_tip_node", 1, &skeleton_modification2dccdik_class_set_tip_node),
	JS_CFUNC_DEF("get_tip_node", 0, &skeleton_modification2dccdik_class_get_tip_node),
	JS_CFUNC_DEF("set_ccdik_data_chain_length", 1, &skeleton_modification2dccdik_class_set_ccdik_data_chain_length),
	JS_CFUNC_DEF("get_ccdik_data_chain_length", 0, &skeleton_modification2dccdik_class_get_ccdik_data_chain_length),
	JS_CFUNC_DEF("set_ccdik_joint_bone2d_node", 2, &skeleton_modification2dccdik_class_set_ccdik_joint_bone2d_node),
	JS_CFUNC_DEF("get_ccdik_joint_bone2d_node", 1, &skeleton_modification2dccdik_class_get_ccdik_joint_bone2d_node),
	JS_CFUNC_DEF("set_ccdik_joint_bone_index", 2, &skeleton_modification2dccdik_class_set_ccdik_joint_bone_index),
	JS_CFUNC_DEF("get_ccdik_joint_bone_index", 1, &skeleton_modification2dccdik_class_get_ccdik_joint_bone_index),
	JS_CFUNC_DEF("set_ccdik_joint_rotate_from_joint", 2, &skeleton_modification2dccdik_class_set_ccdik_joint_rotate_from_joint),
	JS_CFUNC_DEF("get_ccdik_joint_rotate_from_joint", 1, &skeleton_modification2dccdik_class_get_ccdik_joint_rotate_from_joint),
	JS_CFUNC_DEF("set_ccdik_joint_enable_constraint", 2, &skeleton_modification2dccdik_class_set_ccdik_joint_enable_constraint),
	JS_CFUNC_DEF("get_ccdik_joint_enable_constraint", 1, &skeleton_modification2dccdik_class_get_ccdik_joint_enable_constraint),
	JS_CFUNC_DEF("set_ccdik_joint_constraint_angle_min", 2, &skeleton_modification2dccdik_class_set_ccdik_joint_constraint_angle_min),
	JS_CFUNC_DEF("get_ccdik_joint_constraint_angle_min", 1, &skeleton_modification2dccdik_class_get_ccdik_joint_constraint_angle_min),
	JS_CFUNC_DEF("set_ccdik_joint_constraint_angle_max", 2, &skeleton_modification2dccdik_class_set_ccdik_joint_constraint_angle_max),
	JS_CFUNC_DEF("get_ccdik_joint_constraint_angle_max", 1, &skeleton_modification2dccdik_class_get_ccdik_joint_constraint_angle_max),
	JS_CFUNC_DEF("set_ccdik_joint_constraint_angle_invert", 2, &skeleton_modification2dccdik_class_set_ccdik_joint_constraint_angle_invert),
	JS_CFUNC_DEF("get_ccdik_joint_constraint_angle_invert", 1, &skeleton_modification2dccdik_class_get_ccdik_joint_constraint_angle_invert),
};




static void define_skeleton_modification2dccdik_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "target_nodepath"),
        JS_NewCFunction(ctx, skeleton_modification2dccdik_class_get_target_node, "get_target_node", 0),
        JS_NewCFunction(ctx, skeleton_modification2dccdik_class_set_target_node, "set_target_node", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "tip_nodepath"),
        JS_NewCFunction(ctx, skeleton_modification2dccdik_class_get_tip_node, "get_tip_node", 0),
        JS_NewCFunction(ctx, skeleton_modification2dccdik_class_set_tip_node, "set_tip_node", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "ccdik_data_chain_length"),
        JS_NewCFunction(ctx, skeleton_modification2dccdik_class_get_ccdik_data_chain_length, "get_ccdik_data_chain_length", 0),
        JS_NewCFunction(ctx, skeleton_modification2dccdik_class_set_ccdik_data_chain_length, "set_ccdik_data_chain_length", 1),
        JS_PROP_GETSET
    );
}

static void define_skeleton_modification2dccdik_enum(JSContext *ctx, JSValue ctor) {
}

static int js_skeleton_modification2dccdik_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["SkeletonModification2DCCDIK"] = class_id;
	classes_by_id[class_id] = "SkeletonModification2DCCDIK";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &skeleton_modification2dccdik_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["SkeletonModification2D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_skeleton_modification2dccdik_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, skeleton_modification2dccdik_class_proto_funcs, _countof(skeleton_modification2dccdik_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, skeleton_modification2dccdik_class_constructor, "SkeletonModification2DCCDIK", 0, JS_CFUNC_constructor, 0);
	define_skeleton_modification2dccdik_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "SkeletonModification2DCCDIK", ctor);

	return 0;
}

JSModuleDef *_js_init_skeleton_modification2dccdik_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/skeleton_modification2d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_skeleton_modification2dccdik_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "SkeletonModification2DCCDIK");
	return m;
}

JSModuleDef *js_init_skeleton_modification2dccdik_module(JSContext *ctx) {
	return _js_init_skeleton_modification2dccdik_module(ctx, "@godot/classes/skeleton_modification2dccdik");
}

void __register_skeleton_modification2dccdik() {
	js_init_skeleton_modification2dccdik_module(js_context());
}

void register_skeleton_modification2dccdik() {
	__register_skeleton_modification2dccdik();
}