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
#include <godot_cpp/classes/skeleton_modification2dfabrik.hpp>
using namespace godot;

static void skeleton_modification2dfabrik_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["SkeletonModification2DFABRIK"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
        if (opaque_ptr->can_unref){
            static_cast<RefCounted *>(opaque_ptr->get().operator Object *())->unreference();
        }
		memdelete(opaque_ptr);
	}
}

static JSClassDef skeleton_modification2dfabrik_class_def = {
    "SkeletonModification2DFABRIK",
    skeleton_modification2dfabrik_class_finalizer
};

static JSValue skeleton_modification2dfabrik_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["SkeletonModification2DFABRIK"];
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
        instance = memnew(SkeletonModification2DFABRIK);
	 	adapter = memnew(VariantAdapter(instance));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue skeleton_modification2dfabrik_class_set_target_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModification2DFABRIK::set_target_node, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2dfabrik_class_get_target_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonModification2DFABRIK::get_target_node, ctx, this_val, argc, argv);
}
static JSValue skeleton_modification2dfabrik_class_set_fabrik_data_chain_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModification2DFABRIK::set_fabrik_data_chain_length, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2dfabrik_class_get_fabrik_data_chain_length(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_method_ret(&SkeletonModification2DFABRIK::get_fabrik_data_chain_length, ctx, this_val, argc, argv);
}
static JSValue skeleton_modification2dfabrik_class_set_fabrik_joint_bone2d_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModification2DFABRIK::set_fabrik_joint_bone2d_node, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2dfabrik_class_get_fabrik_joint_bone2d_node(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonModification2DFABRIK::get_fabrik_joint_bone2d_node, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2dfabrik_class_set_fabrik_joint_bone_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModification2DFABRIK::set_fabrik_joint_bone_index, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2dfabrik_class_get_fabrik_joint_bone_index(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonModification2DFABRIK::get_fabrik_joint_bone_index, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2dfabrik_class_set_fabrik_joint_magnet_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModification2DFABRIK::set_fabrik_joint_magnet_position, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2dfabrik_class_get_fabrik_joint_magnet_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonModification2DFABRIK::get_fabrik_joint_magnet_position, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2dfabrik_class_set_fabrik_joint_use_target_rotation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&SkeletonModification2DFABRIK::set_fabrik_joint_use_target_rotation, ctx, this_val, argc, argv);
};
static JSValue skeleton_modification2dfabrik_class_get_fabrik_joint_use_target_rotation(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&SkeletonModification2DFABRIK::get_fabrik_joint_use_target_rotation, ctx, this_val, argc, argv);
};



static const JSCFunctionListEntry skeleton_modification2dfabrik_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_target_node", 1, &skeleton_modification2dfabrik_class_set_target_node),
	JS_CFUNC_DEF("get_target_node", 0, &skeleton_modification2dfabrik_class_get_target_node),
	JS_CFUNC_DEF("set_fabrik_data_chain_length", 1, &skeleton_modification2dfabrik_class_set_fabrik_data_chain_length),
	JS_CFUNC_DEF("get_fabrik_data_chain_length", 0, &skeleton_modification2dfabrik_class_get_fabrik_data_chain_length),
	JS_CFUNC_DEF("set_fabrik_joint_bone2d_node", 2, &skeleton_modification2dfabrik_class_set_fabrik_joint_bone2d_node),
	JS_CFUNC_DEF("get_fabrik_joint_bone2d_node", 1, &skeleton_modification2dfabrik_class_get_fabrik_joint_bone2d_node),
	JS_CFUNC_DEF("set_fabrik_joint_bone_index", 2, &skeleton_modification2dfabrik_class_set_fabrik_joint_bone_index),
	JS_CFUNC_DEF("get_fabrik_joint_bone_index", 1, &skeleton_modification2dfabrik_class_get_fabrik_joint_bone_index),
	JS_CFUNC_DEF("set_fabrik_joint_magnet_position", 2, &skeleton_modification2dfabrik_class_set_fabrik_joint_magnet_position),
	JS_CFUNC_DEF("get_fabrik_joint_magnet_position", 1, &skeleton_modification2dfabrik_class_get_fabrik_joint_magnet_position),
	JS_CFUNC_DEF("set_fabrik_joint_use_target_rotation", 2, &skeleton_modification2dfabrik_class_set_fabrik_joint_use_target_rotation),
	JS_CFUNC_DEF("get_fabrik_joint_use_target_rotation", 1, &skeleton_modification2dfabrik_class_get_fabrik_joint_use_target_rotation),
};




static void define_skeleton_modification2dfabrik_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "target_nodepath"),
        JS_NewCFunction(ctx, skeleton_modification2dfabrik_class_get_target_node, "get_target_node", 0),
        JS_NewCFunction(ctx, skeleton_modification2dfabrik_class_set_target_node, "set_target_node", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "fabrik_data_chain_length"),
        JS_NewCFunction(ctx, skeleton_modification2dfabrik_class_get_fabrik_data_chain_length, "get_fabrik_data_chain_length", 0),
        JS_NewCFunction(ctx, skeleton_modification2dfabrik_class_set_fabrik_data_chain_length, "set_fabrik_data_chain_length", 1),
        JS_PROP_GETSET
    );
}

static void define_skeleton_modification2dfabrik_enum(JSContext *ctx, JSValue ctor) {
}

static int js_skeleton_modification2dfabrik_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["SkeletonModification2DFABRIK"] = class_id;
	classes_by_id[class_id] = "SkeletonModification2DFABRIK";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &skeleton_modification2dfabrik_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["SkeletonModification2D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_skeleton_modification2dfabrik_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, skeleton_modification2dfabrik_class_proto_funcs, _countof(skeleton_modification2dfabrik_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, skeleton_modification2dfabrik_class_constructor, "SkeletonModification2DFABRIK", 0, JS_CFUNC_constructor, 0);
	define_skeleton_modification2dfabrik_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "SkeletonModification2DFABRIK", ctor);
	ctor_list["SkeletonModification2DFABRIK"] = ctor;

	return 0;
}

JSModuleDef *_js_init_skeleton_modification2dfabrik_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/skeleton_modification2d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_skeleton_modification2dfabrik_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "SkeletonModification2DFABRIK");
	return m;
}

JSModuleDef *js_init_skeleton_modification2dfabrik_module(JSContext *ctx) {
	return _js_init_skeleton_modification2dfabrik_module(ctx, "@godot/classes/skeleton_modification2dfabrik");
}

void __register_skeleton_modification2dfabrik() {
	js_init_skeleton_modification2dfabrik_module(js_context());
}

void register_skeleton_modification2dfabrik() {
	__register_skeleton_modification2dfabrik();
}