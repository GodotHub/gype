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
#include <godot_cpp/classes/skeleton_modification2d_jiggle.hpp>
using namespace godot;

static void skeleton_modification2d_jiggle_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["SkeletonModification2DJiggle"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef skeleton_modification2d_jiggle_class_def = {
    "SkeletonModification2DJiggle",
    skeleton_modification2d_jiggle_class_finalizer
};

static JSValue skeleton_modification2d_jiggle_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["SkeletonModification2DJiggle"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    SkeletonModification2DJiggle *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<SkeletonModification2DJiggle *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(SkeletonModification2DJiggle);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue skeleton_modification2d_jiggle_class_set_target_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModification2DJiggle::set_target_node, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2d_jiggle_class_get_target_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<NodePath> *proxy = memnew(ObjectProxy<NodePath>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> NodePath {
		SkeletonModification2DJiggle *obj = static_cast<SkeletonModification2DJiggle *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_target_node();
	};
	proxy->setter = [this_val](const NodePath &value) -> void {
		SkeletonModification2DJiggle *js_proxy = static_cast<SkeletonModification2DJiggle *>(VariantAdapter(this_val).get().operator Object *());
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
static JSValue skeleton_modification2d_jiggle_class_set_jiggle_data_chain_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModification2DJiggle::set_jiggle_data_chain_length, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2d_jiggle_class_get_jiggle_data_chain_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&SkeletonModification2DJiggle::get_jiggle_data_chain_length, ctx, this_val, argc, argv);
}
static JSValue skeleton_modification2d_jiggle_class_set_stiffness(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModification2DJiggle::set_stiffness, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2d_jiggle_class_get_stiffness(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonModification2DJiggle::get_stiffness, ctx, this_val, argc, argv);
}
static JSValue skeleton_modification2d_jiggle_class_set_mass(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModification2DJiggle::set_mass, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2d_jiggle_class_get_mass(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonModification2DJiggle::get_mass, ctx, this_val, argc, argv);
}
static JSValue skeleton_modification2d_jiggle_class_set_damping(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModification2DJiggle::set_damping, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2d_jiggle_class_get_damping(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonModification2DJiggle::get_damping, ctx, this_val, argc, argv);
}
static JSValue skeleton_modification2d_jiggle_class_set_use_gravity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModification2DJiggle::set_use_gravity, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2d_jiggle_class_get_use_gravity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonModification2DJiggle::get_use_gravity, ctx, this_val, argc, argv);
}
static JSValue skeleton_modification2d_jiggle_class_set_gravity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModification2DJiggle::set_gravity, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2d_jiggle_class_get_gravity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<Vector2> *proxy = memnew(ObjectProxy<Vector2>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> Vector2 {
		SkeletonModification2DJiggle *obj = static_cast<SkeletonModification2DJiggle *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_gravity();
	};
	proxy->setter = [this_val](const Vector2 &value) -> void {
		SkeletonModification2DJiggle *js_proxy = static_cast<SkeletonModification2DJiggle *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_gravity(value);
	};
	JSValue obj = JS_NewObjectClass(ctx, classes["Vector2Proxy"]);
	if (is_exception(ctx, obj)) {
		return JS_EXCEPTION;
	}
	JS_SetOpaque(obj, &proxy);
	JSValue global = JS_GetGlobalObject(ctx);
	JSValue obj_constructor = JS_GetPropertyStr(ctx, global, "Vector2Proxy");
	JSValue construct_arg = JS_NewObject(ctx);
	JS_SetOpaque(construct_arg, proxy);
	JSValue js_proxy = JS_CallConstructor(ctx, obj_constructor, 1, &construct_arg);
    return js_proxy;
}
static JSValue skeleton_modification2d_jiggle_class_set_use_colliders(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModification2DJiggle::set_use_colliders, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2d_jiggle_class_get_use_colliders(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonModification2DJiggle::get_use_colliders, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2d_jiggle_class_set_collision_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModification2DJiggle::set_collision_mask, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2d_jiggle_class_get_collision_mask(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonModification2DJiggle::get_collision_mask, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2d_jiggle_class_set_jiggle_joint_bone2d_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModification2DJiggle::set_jiggle_joint_bone2d_node, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2d_jiggle_class_get_jiggle_joint_bone2d_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonModification2DJiggle::get_jiggle_joint_bone2d_node, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2d_jiggle_class_set_jiggle_joint_bone_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModification2DJiggle::set_jiggle_joint_bone_index, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2d_jiggle_class_get_jiggle_joint_bone_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonModification2DJiggle::get_jiggle_joint_bone_index, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2d_jiggle_class_set_jiggle_joint_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModification2DJiggle::set_jiggle_joint_override, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2d_jiggle_class_get_jiggle_joint_override(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonModification2DJiggle::get_jiggle_joint_override, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2d_jiggle_class_set_jiggle_joint_stiffness(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModification2DJiggle::set_jiggle_joint_stiffness, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2d_jiggle_class_get_jiggle_joint_stiffness(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonModification2DJiggle::get_jiggle_joint_stiffness, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2d_jiggle_class_set_jiggle_joint_mass(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModification2DJiggle::set_jiggle_joint_mass, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2d_jiggle_class_get_jiggle_joint_mass(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonModification2DJiggle::get_jiggle_joint_mass, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2d_jiggle_class_set_jiggle_joint_damping(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModification2DJiggle::set_jiggle_joint_damping, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2d_jiggle_class_get_jiggle_joint_damping(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonModification2DJiggle::get_jiggle_joint_damping, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2d_jiggle_class_set_jiggle_joint_use_gravity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModification2DJiggle::set_jiggle_joint_use_gravity, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2d_jiggle_class_get_jiggle_joint_use_gravity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonModification2DJiggle::get_jiggle_joint_use_gravity, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2d_jiggle_class_set_jiggle_joint_gravity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModification2DJiggle::set_jiggle_joint_gravity, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2d_jiggle_class_get_jiggle_joint_gravity(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonModification2DJiggle::get_jiggle_joint_gravity, ctx, this_val, argc, argv);
};

static const JSCFunctionListEntry skeleton_modification2d_jiggle_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_target_node", 1, &skeleton_modification2d_jiggle_class_set_target_node),
	JS_CFUNC_DEF("get_target_node", 0, &skeleton_modification2d_jiggle_class_get_target_node),
	JS_CFUNC_DEF("set_jiggle_data_chain_length", 1, &skeleton_modification2d_jiggle_class_set_jiggle_data_chain_length),
	JS_CFUNC_DEF("get_jiggle_data_chain_length", 0, &skeleton_modification2d_jiggle_class_get_jiggle_data_chain_length),
	JS_CFUNC_DEF("set_stiffness", 1, &skeleton_modification2d_jiggle_class_set_stiffness),
	JS_CFUNC_DEF("get_stiffness", 0, &skeleton_modification2d_jiggle_class_get_stiffness),
	JS_CFUNC_DEF("set_mass", 1, &skeleton_modification2d_jiggle_class_set_mass),
	JS_CFUNC_DEF("get_mass", 0, &skeleton_modification2d_jiggle_class_get_mass),
	JS_CFUNC_DEF("set_damping", 1, &skeleton_modification2d_jiggle_class_set_damping),
	JS_CFUNC_DEF("get_damping", 0, &skeleton_modification2d_jiggle_class_get_damping),
	JS_CFUNC_DEF("set_use_gravity", 1, &skeleton_modification2d_jiggle_class_set_use_gravity),
	JS_CFUNC_DEF("get_use_gravity", 0, &skeleton_modification2d_jiggle_class_get_use_gravity),
	JS_CFUNC_DEF("set_gravity", 1, &skeleton_modification2d_jiggle_class_set_gravity),
	JS_CFUNC_DEF("get_gravity", 0, &skeleton_modification2d_jiggle_class_get_gravity),
	JS_CFUNC_DEF("set_use_colliders", 1, &skeleton_modification2d_jiggle_class_set_use_colliders),
	JS_CFUNC_DEF("get_use_colliders", 0, &skeleton_modification2d_jiggle_class_get_use_colliders),
	JS_CFUNC_DEF("set_collision_mask", 1, &skeleton_modification2d_jiggle_class_set_collision_mask),
	JS_CFUNC_DEF("get_collision_mask", 0, &skeleton_modification2d_jiggle_class_get_collision_mask),
	JS_CFUNC_DEF("set_jiggle_joint_bone2d_node", 2, &skeleton_modification2d_jiggle_class_set_jiggle_joint_bone2d_node),
	JS_CFUNC_DEF("get_jiggle_joint_bone2d_node", 1, &skeleton_modification2d_jiggle_class_get_jiggle_joint_bone2d_node),
	JS_CFUNC_DEF("set_jiggle_joint_bone_index", 2, &skeleton_modification2d_jiggle_class_set_jiggle_joint_bone_index),
	JS_CFUNC_DEF("get_jiggle_joint_bone_index", 1, &skeleton_modification2d_jiggle_class_get_jiggle_joint_bone_index),
	JS_CFUNC_DEF("set_jiggle_joint_override", 2, &skeleton_modification2d_jiggle_class_set_jiggle_joint_override),
	JS_CFUNC_DEF("get_jiggle_joint_override", 1, &skeleton_modification2d_jiggle_class_get_jiggle_joint_override),
	JS_CFUNC_DEF("set_jiggle_joint_stiffness", 2, &skeleton_modification2d_jiggle_class_set_jiggle_joint_stiffness),
	JS_CFUNC_DEF("get_jiggle_joint_stiffness", 1, &skeleton_modification2d_jiggle_class_get_jiggle_joint_stiffness),
	JS_CFUNC_DEF("set_jiggle_joint_mass", 2, &skeleton_modification2d_jiggle_class_set_jiggle_joint_mass),
	JS_CFUNC_DEF("get_jiggle_joint_mass", 1, &skeleton_modification2d_jiggle_class_get_jiggle_joint_mass),
	JS_CFUNC_DEF("set_jiggle_joint_damping", 2, &skeleton_modification2d_jiggle_class_set_jiggle_joint_damping),
	JS_CFUNC_DEF("get_jiggle_joint_damping", 1, &skeleton_modification2d_jiggle_class_get_jiggle_joint_damping),
	JS_CFUNC_DEF("set_jiggle_joint_use_gravity", 2, &skeleton_modification2d_jiggle_class_set_jiggle_joint_use_gravity),
	JS_CFUNC_DEF("get_jiggle_joint_use_gravity", 1, &skeleton_modification2d_jiggle_class_get_jiggle_joint_use_gravity),
	JS_CFUNC_DEF("set_jiggle_joint_gravity", 2, &skeleton_modification2d_jiggle_class_set_jiggle_joint_gravity),
	JS_CFUNC_DEF("get_jiggle_joint_gravity", 1, &skeleton_modification2d_jiggle_class_get_jiggle_joint_gravity),
};




static void define_skeleton_modification2d_jiggle_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "target_nodepath"),
        JS_NewCFunction(ctx, skeleton_modification2d_jiggle_class_get_target_node, "get_target_node", 0),
        JS_NewCFunction(ctx, skeleton_modification2d_jiggle_class_set_target_node, "set_target_node", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "jiggle_data_chain_length"),
        JS_NewCFunction(ctx, skeleton_modification2d_jiggle_class_get_jiggle_data_chain_length, "get_jiggle_data_chain_length", 0),
        JS_NewCFunction(ctx, skeleton_modification2d_jiggle_class_set_jiggle_data_chain_length, "set_jiggle_data_chain_length", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "stiffness"),
        JS_NewCFunction(ctx, skeleton_modification2d_jiggle_class_get_stiffness, "get_stiffness", 0),
        JS_NewCFunction(ctx, skeleton_modification2d_jiggle_class_set_stiffness, "set_stiffness", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "mass"),
        JS_NewCFunction(ctx, skeleton_modification2d_jiggle_class_get_mass, "get_mass", 0),
        JS_NewCFunction(ctx, skeleton_modification2d_jiggle_class_set_mass, "set_mass", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "damping"),
        JS_NewCFunction(ctx, skeleton_modification2d_jiggle_class_get_damping, "get_damping", 0),
        JS_NewCFunction(ctx, skeleton_modification2d_jiggle_class_set_damping, "set_damping", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "use_gravity"),
        JS_NewCFunction(ctx, skeleton_modification2d_jiggle_class_get_use_gravity, "get_use_gravity", 0),
        JS_NewCFunction(ctx, skeleton_modification2d_jiggle_class_set_use_gravity, "set_use_gravity", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "gravity"),
        JS_NewCFunction(ctx, skeleton_modification2d_jiggle_class_get_gravity, "get_gravity", 0),
        JS_NewCFunction(ctx, skeleton_modification2d_jiggle_class_set_gravity, "set_gravity", 1),
        JS_PROP_GETSET
    );
}

static void define_skeleton_modification2d_jiggle_enum(JSContext *ctx, JSValue proto) {
}

static int js_skeleton_modification2d_jiggle_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["SkeletonModification2DJiggle"] = class_id;
	classes_by_id[class_id] = "SkeletonModification2DJiggle";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &skeleton_modification2d_jiggle_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["SkeletonModification2D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_skeleton_modification2d_jiggle_property(ctx, proto);
	define_skeleton_modification2d_jiggle_enum(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, skeleton_modification2d_jiggle_class_proto_funcs, _countof(skeleton_modification2d_jiggle_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, skeleton_modification2d_jiggle_class_constructor, "SkeletonModification2DJiggle", 0, JS_CFUNC_constructor, 0);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "SkeletonModification2DJiggle", ctor);

	return 0;
}

JSModuleDef *_js_init_skeleton_modification2d_jiggle_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/skeleton_modification2d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_skeleton_modification2d_jiggle_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "SkeletonModification2DJiggle");
	return m;
}

JSModuleDef *js_init_skeleton_modification2d_jiggle_module(JSContext *ctx) {
	return _js_init_skeleton_modification2d_jiggle_module(ctx, "@godot/classes/skeleton_modification2d_jiggle");
}

void __register_skeleton_modification2d_jiggle() {
	js_init_skeleton_modification2d_jiggle_module(js_context());
}

void register_skeleton_modification2d_jiggle() {
	__register_skeleton_modification2d_jiggle();
}