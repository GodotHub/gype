#include "register/classes/register_classes.hpp"
#include "register/object_proxy.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/variant_helper.hpp"
#include "utils/quickjs_helper.hpp"
#include "support/module_loader.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/open_xr_hand.hpp>
using namespace godot;

static void open_xr_hand_class_finalizer(JSRuntime *rt, JSValue val) {
	JSClassID class_id = classes["OpenXRHand"];
	VariantAdapter *opaque_ptr = static_cast<VariantAdapter *>(JS_GetOpaque(val, class_id));
	if (opaque_ptr) {
		memdelete(opaque_ptr);
	}
}

static JSClassDef open_xr_hand_class_def = {
    "OpenXRHand",
    open_xr_hand_class_finalizer
};

static JSValue open_xr_hand_class_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv) {
    JSClassID class_id = classes["OpenXRHand"];
    JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
    JSValue obj = JS_NewObjectProtoClass(ctx, proto, class_id);
	if (is_exception(ctx, obj)) {
		return obj;
	}

    OpenXRHand *instance;
	VariantAdapter *adapter;
	JSClassID opaque_id;
    // Allow constructing from an existing native pointer
    if (argc == 1 && VariantAdapter::can_cast(argv[0], Variant::Type::OBJECT)) {
		adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(*argv, &opaque_id));
		instance = static_cast<OpenXRHand *>(VariantAdapter(*argv).get().operator Object *());
    } else {
        instance = memnew(OpenXRHand);
	 	adapter = memnew(VariantAdapter(instance, true));
    }

    if (!instance) {
        JS_FreeValue(ctx, obj);
        return JS_EXCEPTION;
    }
    JS_SetOpaque(obj, adapter);
    return obj;
}

static JSValue open_xr_hand_class_set_hand(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRHand::set_hand, ctx, this_val, argc, argv);
};
static JSValue open_xr_hand_class_get_hand(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRHand::get_hand, ctx, this_val, argc, argv);
}
static JSValue open_xr_hand_class_set_hand_skeleton(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRHand::set_hand_skeleton, ctx, this_val, argc, argv);
};
static JSValue open_xr_hand_class_get_hand_skeleton(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	ObjectProxy<NodePath> *proxy = memnew(ObjectProxy<NodePath>);
	proxy->wrapped = VariantAdapter(this_val).get();
	proxy->getter = [this_val]() -> NodePath {
		OpenXRHand *obj = static_cast<OpenXRHand *>(VariantAdapter(this_val).get().operator Object*());
		return obj->get_hand_skeleton();
	};
	proxy->setter = [this_val](const NodePath &value) -> void {
		OpenXRHand *js_proxy = static_cast<OpenXRHand *>(VariantAdapter(this_val).get().operator Object *());
		js_proxy->set_hand_skeleton(value);
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
static JSValue open_xr_hand_class_set_motion_range(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRHand::set_motion_range, ctx, this_val, argc, argv);
};
static JSValue open_xr_hand_class_get_motion_range(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRHand::get_motion_range, ctx, this_val, argc, argv);
}
static JSValue open_xr_hand_class_set_skeleton_rig(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRHand::set_skeleton_rig, ctx, this_val, argc, argv);
};
static JSValue open_xr_hand_class_get_skeleton_rig(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRHand::get_skeleton_rig, ctx, this_val, argc, argv);
}
static JSValue open_xr_hand_class_set_bone_update(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
    return call_builtin_method_no_ret(&OpenXRHand::set_bone_update, ctx, this_val, argc, argv);
};
static JSValue open_xr_hand_class_get_bone_update(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	CHECK_INSTANCE_VALID_V(this_val);
	return call_builtin_const_method_ret(&OpenXRHand::get_bone_update, ctx, this_val, argc, argv);
}

static const JSCFunctionListEntry open_xr_hand_class_proto_funcs[] = {
	JS_CFUNC_DEF("set_hand", 1, &open_xr_hand_class_set_hand),
	JS_CFUNC_DEF("get_hand", 0, &open_xr_hand_class_get_hand),
	JS_CFUNC_DEF("set_hand_skeleton", 1, &open_xr_hand_class_set_hand_skeleton),
	JS_CFUNC_DEF("get_hand_skeleton", 0, &open_xr_hand_class_get_hand_skeleton),
	JS_CFUNC_DEF("set_motion_range", 1, &open_xr_hand_class_set_motion_range),
	JS_CFUNC_DEF("get_motion_range", 0, &open_xr_hand_class_get_motion_range),
	JS_CFUNC_DEF("set_skeleton_rig", 1, &open_xr_hand_class_set_skeleton_rig),
	JS_CFUNC_DEF("get_skeleton_rig", 0, &open_xr_hand_class_get_skeleton_rig),
	JS_CFUNC_DEF("set_bone_update", 1, &open_xr_hand_class_set_bone_update),
	JS_CFUNC_DEF("get_bone_update", 0, &open_xr_hand_class_get_bone_update),
};




static void define_open_xr_hand_property(JSContext *ctx, JSValue proto) {
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "hand"),
        JS_NewCFunction(ctx, open_xr_hand_class_get_hand, "get_hand", 0),
        JS_NewCFunction(ctx, open_xr_hand_class_set_hand, "set_hand", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "motion_range"),
        JS_NewCFunction(ctx, open_xr_hand_class_get_motion_range, "get_motion_range", 0),
        JS_NewCFunction(ctx, open_xr_hand_class_set_motion_range, "set_motion_range", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "hand_skeleton"),
        JS_NewCFunction(ctx, open_xr_hand_class_get_hand_skeleton, "get_hand_skeleton", 0),
        JS_NewCFunction(ctx, open_xr_hand_class_set_hand_skeleton, "set_hand_skeleton", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "skeleton_rig"),
        JS_NewCFunction(ctx, open_xr_hand_class_get_skeleton_rig, "get_skeleton_rig", 0),
        JS_NewCFunction(ctx, open_xr_hand_class_set_skeleton_rig, "set_skeleton_rig", 1),
        JS_PROP_GETSET
    );
    JS_DefinePropertyGetSet(
        ctx,
        proto,
        JS_NewAtom(ctx, "bone_update"),
        JS_NewCFunction(ctx, open_xr_hand_class_get_bone_update, "get_bone_update", 0),
        JS_NewCFunction(ctx, open_xr_hand_class_set_bone_update, "set_bone_update", 1),
        JS_PROP_GETSET
    );
}

static void define_open_xr_hand_enum(JSContext *ctx, JSValue ctor) {
	JSValue Hands_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, Hands_obj, "HAND_LEFT", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, Hands_obj, "HAND_RIGHT", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, Hands_obj, "HAND_MAX", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "Hands", Hands_obj);
	JSValue MotionRange_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, MotionRange_obj, "MOTION_RANGE_UNOBSTRUCTED", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, MotionRange_obj, "MOTION_RANGE_CONFORM_TO_CONTROLLER", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, MotionRange_obj, "MOTION_RANGE_MAX", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "MotionRange", MotionRange_obj);
	JSValue SkeletonRig_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, SkeletonRig_obj, "SKELETON_RIG_OPENXR", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, SkeletonRig_obj, "SKELETON_RIG_HUMANOID", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, SkeletonRig_obj, "SKELETON_RIG_MAX", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "SkeletonRig", SkeletonRig_obj);
	JSValue BoneUpdate_obj = JS_NewObject(ctx);
	JS_SetPropertyStr(ctx, BoneUpdate_obj, "BONE_UPDATE_FULL", JS_NewInt64(ctx, 0));
	JS_SetPropertyStr(ctx, BoneUpdate_obj, "BONE_UPDATE_ROTATION_ONLY", JS_NewInt64(ctx, 1));
	JS_SetPropertyStr(ctx, BoneUpdate_obj, "BONE_UPDATE_MAX", JS_NewInt64(ctx, 2));
	JS_SetPropertyStr(ctx, ctor, "BoneUpdate", BoneUpdate_obj);
}

static int js_open_xr_hand_class_init(JSContext *ctx, JSModuleDef *m) {	
	JSClassID class_id = 0;
	class_id = JS_NewClassID(js_runtime(), &class_id);
	classes["OpenXRHand"] = class_id;
	classes_by_id[class_id] = "OpenXRHand";
	JS_NewClass(JS_GetRuntime(ctx), class_id, &open_xr_hand_class_def);

	JSValue proto = JS_NewObjectClass(ctx, class_id);
	JSValue base_class = JS_GetClassProto(ctx, classes["Node3D"]);
	JS_SetPrototype(ctx, proto, base_class);
	JS_SetClassProto(ctx, class_id, proto);

	define_open_xr_hand_property(ctx, proto);
	JS_SetPropertyFunctionList(ctx, proto, open_xr_hand_class_proto_funcs, _countof(open_xr_hand_class_proto_funcs));
	JSValue ctor = JS_NewCFunction2(ctx, open_xr_hand_class_constructor, "OpenXRHand", 0, JS_CFUNC_constructor, 0);
	define_open_xr_hand_enum(ctx, ctor);
	JS_SetConstructor(ctx, ctor, proto);
	JS_SetModuleExport(ctx, m, "OpenXRHand", ctor);

	return 0;
}

JSModuleDef *_js_init_open_xr_hand_module(JSContext *ctx, const char *module_name) {
	// 需要提前完成import依赖
	const char *code = "import * as _ from '@godot/classes/node3d';";
	JSValue module = JS_Eval(ctx, code, strlen(code), "<eval>", JS_EVAL_TYPE_MODULE);
	if (JS_IsException(module))
		return NULL;
	JSModuleDef *m = JS_NewCModule(ctx, module_name, js_open_xr_hand_class_init);
	if (!m)
		return NULL;
	JS_AddModuleExport(ctx, m, "OpenXRHand");
	return m;
}

JSModuleDef *js_init_open_xr_hand_module(JSContext *ctx) {
	return _js_init_open_xr_hand_module(ctx, "@godot/classes/open_xr_hand");
}

void __register_open_xr_hand() {
	js_init_open_xr_hand_module(js_context());
}

void register_open_xr_hand() {
	__register_open_xr_hand();
}